/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/10              Virginia Yun
Amend to include update action			   2012/06/13              Virginia Yun
Include allow_reserved, release_reserved_period
        allow_payout_dup_merch_ref                 2012/08/16              Virginia Yun
Include settlement_process_period		   2012/08/30		   Virginia Yun
Add aupport auto-settlement and sett_id
	and Call RuelAutoSettlement Add/Update	   2012/11/06		   LokMan Chow
Add short_name					   2012/12/06		   Stan Poon
Remove merchant_type				   2012/12/11		   LokMan Chow
Handle merchant level reserve rate		   2012/12/12		   Stan Poon
Chk Merchent ID Exists or not for Add              2012/12/28              Virginia Yun
Add ignore_nack					   2013/01/30		   LokMan Chow
Remove support auto-settlement and sett_id
	and Call RuelAutoSettlement Add/Update	   2013/05/30		   Stan Poon
Add payout_fe_display				   2013/08/23		   David Wong
Add success/fail callback url			   2013/08/30		   Stan Poon
Add brand_name                                     2013/09/05              Virginia Yun
Add daily_cap_fe_display			   2014/09/10		   Elvis Wong
Add address					   2014/09/30		   Dirk Wong
Add enable_card_type		   		   2016/09/29		   Elvis Wong
	and Call MerchDetail 
	UpdateMerchCardTypeEnable	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMCR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#include "sha1.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsMCR(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;

	char	*csTmp = NULL;	
	char	*csKeyType = strdup(""); 
	char	csKeyValue[PD_MD5_KEY_LEN + 1];

        SHA1Context sha;
        char csDateTime[PD_DATETIME_LEN + 1];

	int	iTmp, i ;
	double	dTmp = 0.0;

	char	*csMid = strdup("");
	//char	cType;
	char	cAction;
	char	cUpdateType = '0';

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	memset(csKeyValue, 0, sizeof(csKeyValue));
	memset(csDateTime, 0, sizeof(csDateTime));


DEBUGLOG(("TxnMgtByUsMCR::Authorize\n"));

/* Action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
		// not support delete
		if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::action [%d] not accepted!!\n", cAction));
ERRLOG("TxnMgtByUsMCR::Authorize::action not found!!\n");
			iRet=INT_ACTION_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	} 
	else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::action not found!!\n");
                iRet=INT_ACTION_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

	// Merchant ID is expected input also!
	if (GetField_CString(hRequest, "newmid", &csMid)){
		PutField_CString(hTxn, "merchant_id", csMid);
		PutField_Char(hTxn, "party_type", 'M');
		PutField_CString(hTxn, "party_id", csMid);
DEBUGLOG(("Authorize::merhant_id = [%s]\n",csMid));
DEBUGLOG(("Authorize::party_type = [%c]\n",'M'));
DEBUGLOG(("Authorize::party_id = [%s]\n",csMid));
	}
	else {
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::merchant_id not found!!\n");
		iRet=INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* add_user */
        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
                PutField_CString(hTxn,"create_user",csTmp);
		PutField_CString(hTxn, "update_user", csTmp);
        }


	if (iRet == PD_OK) {
		if (cAction == PD_ACTION_UPDATE) {
			if (GetField_CString(hRequest, "update_type", &csTmp)) {
				cUpdateType = csTmp[0];
			}
			else {
DEBUGLOG(("Authorize::update_type not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::update_type not found!!\n");
		                iRet=INT_ERR;
               			 PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}


	if (iRet == PD_OK) {
		if (cAction == PD_ACTION_ADD) {

DEBUGLOG(("Authorize::Call DBMerchDetail:ChkMerchIDExist\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","ChkMerchIDExist");
			if ((unsigned long)(*DBObjPtr)(csMid) != PD_FOUND) {
DEBUGLOG(("Authorize::DBMerchDetail:ChkMerchIDExist NOT FOUND (OK for add)\n"));
			} else {
DEBUGLOG(("Authorize::DBMerchDetail:ChkMerchIDExist FOUND\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchDetail:ChkMerchIDExist FOUND for action Add\n");
				iRet = INT_INVALID_MERCH_ID;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}




	if (iRet == PD_OK) {
		if (cAction == PD_ACTION_ADD || 
			(cAction == PD_ACTION_UPDATE && (cUpdateType == PD_UPDATE_MERCH_INFO || cUpdateType == PD_UPDATE_ALL))) {
			/* name */
			if(GetField_CString(hRequest,"name",&csTmp)){
				PutField_CString(hTxn, "name", csTmp);
DEBUGLOG(("Authorize::name = [%s]\n",csTmp));
			}
			else {
DEBUGLOG(("Authorize::name not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::name not found!!\n");
				iRet=INT_MERCHANT_NAME_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
			}

			/*short_name*/
			if(GetField_CString(hRequest, "short_name", &csTmp)) {
				PutField_CString(hTxn, "short_name",csTmp);
DEBUGLOG(("Authorize::short_name = [%s]\n",csTmp));
			}

                        /* approximate_fee_rate */
                        if(GetField_CString(hRequest,"fee_rate",&csTmp)){
                                dTmp = string2double((const unsigned char *)csTmp);
                                PutField_Double(hTxn,"approximate_fee_rate",dTmp);
DEBUGLOG(("Authorize() approximate_fee_rate = [%f]\n",dTmp));
                        }
                        else {
                                dTmp = 0.0;
DEBUGLOG(("Authorize() approximate_fee_rate (default) = [%f]\n",dTmp));
                                PutField_Double(hTxn, "approximate_fee_rate", dTmp);
                        }

			/* status */
			if (GetField_CString(hRequest, "status", &csTmp)) {
DEBUGLOG(("Authorize() status = [%s]\n",csTmp));
				PutField_CString(hTxn, "status", csTmp);

			} else {
DEBUGLOG(("Authorize() status (default) = [%s]\n",PD_ACC_OPEN));
				PutField_CString(hTxn, "status", PD_ACC_OPEN);
			}

			/* allow_reserved */
			if (GetField_CString(hRequest, "allow_reserved", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "allow_reserved", iTmp);
DEBUGLOG(("Authorize() allow_reserved = [%d]\n",iTmp));

			} else {
				if (GetField_CString(hRequest, "ind_reserve", &csTmp)){
					iTmp = atoi(csTmp);
					PutField_Int(hTxn, "allow_reserved", iTmp);
DEBUGLOG(("Authorize() allow_reserved = [%d]\n",iTmp));
				}
			}

			/* release_reserved_period */
			if (GetField_CString(hRequest, "release_period", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "release_reserved_period", iTmp);
DEBUGLOG(("Authorize() release_reserved_period = [%d]\n",iTmp));
			} else {
				PutField_Int(hTxn, "release_reserved_period", PD_DEF_RELEASE_PERIOD);
DEBUGLOG(("Authorize() release_reserved_period (default) = [%d]\n",PD_DEF_RELEASE_PERIOD));
			}

			/* allow_payout_dup_merch_ref */
			if (GetField_CString(hRequest, "allow_po_dup_merch_ref", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "allow_payout_dup_merch_ref", iTmp);
DEBUGLOG(("Authorize() allow_po_dup_merch_ref = [%d]\n",iTmp));

			} else {
				PutField_Int(hTxn, "allow_payout_dup_merch_ref", PD_TRUE);
DEBUGLOG(("Authorize() allow_po_dup_merch_ref (default) = [%d]\n",PD_TRUE));
			}

			/* settlement_process_period */
			if (GetField_CString(hRequest, "sett_proc_period", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "settlement_process_period", iTmp);
DEBUGLOG(("Authorize() settlement_process_period = [%d]\n",iTmp));

			} else {
				PutField_Int(hTxn, "settlement_process_period", 0);
DEBUGLOG(("Authorize() settlement_process_period (default) = [%d]\n", 0));

			}

			/* ind_reserve  +  reserve_rate */
			char *csIndRes = NULL, *csResRate = NULL;	
			if (GetField_CString(hRequest, "ind_reserve", &csIndRes)){ 
				iTmp = atoi(csIndRes);
				PutField_Int(hTxn, "ind_reserve", iTmp);
DEBUGLOG(("Authorize() ind_reserve = [%d]\n",iTmp));
				if (GetField_CString(hRequest,"reserve_rate",&csResRate)){
					dTmp = string2double((const unsigned char *)csResRate);
					PutField_Double(hTxn,"reserve_rate",dTmp);
DEBUGLOG(("Authorize() reserve_rate = [%f]\n",dTmp));
				} else if (iTmp == 1){
						iRet = INT_MERCHANT_RESERVE_NOT_FOUND;
						PutField_Int(hContext,"internal_error",iRet);
				}
			} else {
				iRet = INT_MERCHANT_RESERVE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}

			/* ignore_nack */
			if (GetField_CString(hRequest, "ignore_nack", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "ignore_nack", iTmp);
DEBUGLOG(("Authorize() ignore_nack = [%d]\n",iTmp));

			} else {
				PutField_Int(hTxn, "ignore_nack", PD_FALSE);
DEBUGLOG(("Authorize() ignore_nack (default) = [%d]\n",PD_FALSE));
			}

			/* payout_fe_display */
			if (GetField_CString(hRequest, "payout_fe_display", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "payout_fe_display", iTmp);
DEBUGLOG(("Authorize() payout_fe_display = [%d]\n", iTmp));
			} else {
				PutField_Int(hTxn, "payout_fe_display", PD_FALSE);
DEBUGLOG(("Authorize() payout_fe_display (default) = [%d]\n", PD_FALSE));
			}

			/* success_callback_url */
			if (GetField_CString(hRequest, "success_callback_url", &csTmp)) {
				PutField_CString(hTxn, "success_callback_url", csTmp);
DEBUGLOG(("Authorize() success_callback_url = [%s]\n", csTmp));
			}

			/* failure_callback_url */
			if (GetField_CString(hRequest, "failure_callback_url", &csTmp)) {
				PutField_CString(hTxn, "failure_callback_url", csTmp);
DEBUGLOG(("Authorize() failure_callback_url = [%s]\n", csTmp));
			}

			/* brand_name */
			if (GetField_CString(hRequest, "brand_name", &csTmp)) {
				PutField_CString(hTxn, "brand_name", csTmp);
DEBUGLOG(("Authorize() brand_name = [%s]\n", csTmp));
			}
			
			/* daily_cap_fe_display */
			if (GetField_CString(hRequest, "daily_cap_fe_display", &csTmp)) {
				iTmp = atoi(csTmp);
				PutField_Int(hTxn, "daily_cap_fe_display", iTmp);
DEBUGLOG(("Authorize() daily_cap_fe_display = [%d]\n", iTmp));
			} else {
				PutField_Int(hTxn, "daily_cap_fe_display", PD_FALSE);
DEBUGLOG(("Authorize() daily_cap_fe_display (default) = [%d]\n", PD_FALSE));
			}

			/* address */
			if (GetField_CString(hRequest, "address", &csTmp)) {
				PutField_CString(hTxn, "address", csTmp);
DEBUGLOG(("Authorize() address = [%s]\n", csTmp));
			}

			/* enable_card_type */
			if (GetField_CString(hRequest, "enable_card_type", &csTmp)) {
                                iTmp = atoi(csTmp);
                                PutField_Int(hTxn, "enable_card_type", iTmp);
DEBUGLOG(("Authorize() enable_card_type = [%d]\n", iTmp));
                        } else {
                                PutField_Int(hTxn, "enable_card_type", PD_FALSE);
DEBUGLOG(("Authorize() enable_card_type (default) = [%d]\n", PD_FALSE));
                        }
		}

		if (cAction == PD_ACTION_ADD) {
			/* business_type */
/*
			if (GetField_CString(hRequest, "type", &csTmp)) {
				cType = csTmp[0];
DEBUGLOG(("Authorize::type = [%c]\n",cType));
				PutField_Char(hTxn, "merchant_type", cType);
			}
			else {
DEBUGLOG(("Authorize::business_type not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::business_type not found!!\n");
				iRet=INT_BUSINESS_TYPE_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
			}
*/
			/* client_id */
			if(GetField_CString(hRequest,"client_id",&csTmp)){
				PutField_CString(hTxn, "client_id", csTmp);
DEBUGLOG(("Authorize::client_id = [%s]\n",csTmp));
			}
			else {
DEBUGLOG(("Authorize::client_id not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::client_id not found!!\n");
				iRet=INT_CLIENT_ID_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
			}

			/* disabled */
			if (GetField_CString(hRequest, "disabled", &csTmp)) {
				iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::disabled = [%d]\n",iTmp));
				PutField_Int(hTxn, "disabled", iTmp);
			}
			else {
DEBUGLOG(("Authorize::disabled not found!!\n"));
				PutField_Int(hTxn, "disabled", PD_FALSE);
			}

			/* status */
			/*
			PutField_CString(hTxn, "status", PD_ACC_OPEN);
			*/

		}

		if (cAction == PD_ACTION_ADD || 
			(cAction == PD_ACTION_UPDATE && (cUpdateType == PD_UPDATE_KEY || cUpdateType == PD_UPDATE_ALL))) {
			/* effect_date */
			if (GetField_CString(hRequest, "effect_date", &csTmp)) {
				PutField_CString(hTxn,"effect_date",csTmp);
DEBUGLOG(("Authorize:: effect_date = [%s]\n",csTmp));
			}
			else {
				if (GetField_CString(hContext, "PHDATE", &csTmp)) {
DEBUGLOG(("Authorize::effect_date (phdate) = [%s]\n",csTmp));
					PutField_CString(hTxn,"effect_date",csTmp);

				} else {

DEBUGLOG(("Authorize::effect_date not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::effect_date not found!!\n");
					iRet=INT_ERR;
	
					PutField_Int(hContext,"internal_error",iRet);
				}
			}

			/* key_type */
			if(GetField_CString(hRequest,"key_type",&csKeyType)){
       	         		PutField_CString(hTxn, "key", csKeyType);
DEBUGLOG(("Authorize::key type = [%s]\n",csKeyType));
			}
			else {
				strcpy(csKeyType, PD_PTK_KEY_NAME);
       	         		PutField_CString(hTxn, "key", PD_PTK_KEY_NAME);
DEBUGLOG(("Authorize::key type (default) [%s]\n", PD_PTK_KEY_NAME));

/*
DEBUGLOG(("Authorize::key type not found!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::key type not found!!\n");
                		iRet=INT_KEY_TYPE_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
*/
        		}

			/* Gen key_value */
			if (iRet == PD_OK) {
				if (!strcmp(csKeyType, PD_PTK_KEY_NAME)) {
DEBUGLOG(("Authorize::gen [%s]\n", csKeyType));

					// len 128
					strcpy(csKeyValue, random_gen(PD_MD5_KEY_LEN));
					csKeyValue[PD_MD5_KEY_LEN]='\0';


					PutField_CString(hTxn, "key_value", csKeyValue);
					///////*hard code*//////////TODO:
					PutField_CString(hTxn, "key_value", "9zfYgBtKA8MZNT2715DtrsoFZeuWfYUgqt8qORyQiVfL918Ttm9cHO5qk0YcrxFCEFJ4ulJAgNkwm3f860DSzRy1NrgySw9Lp3gUHe8h3YVUDjdHu06QKMnMrrGdfvHK");
				} else if ((!strcmp(csKeyType, PD_SHA1_KEY_NAME)) || (!strcmp(csKeyType, PD_POK_KEY_NAME))) {

					// len 32
					strcpy(csDateTime,getdatetime());
					csDateTime[PD_DATETIME_LEN]='\0';

					SHA1Reset(&sha);
					SHA1Input(&sha, (const unsigned char *)csDateTime, strlen(csDateTime));

					if (SHA1Result(&sha)) {
						for(i = 0; i < 4 ; i++) {
							sprintf(&csKeyValue[i*8], "%08X", sha.Message_Digest[i]);
						}
						csKeyValue[PD_SHA_KEY_LEN]='\0';
						PutField_CString(hTxn, "key_value", csKeyValue);
						///////*hard code*//////////TODO:
						PutField_CString(hTxn, "key_value", "9zfYgBtKA8MZNT2715DtrsoFZeuWfYUgqt8qORyQiVfL918Ttm9cHO5qk0YcrxFCEFJ4ulJAgNkwm3f860DSzRy1NrgySw9Lp3gUHe8h3YVUDjdHu06QKMnMrrGdfvHK");
					}
				} else {
DEBUGLOG(("Authorize::key type invalid!!\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::key type invalid !!\n");

					iRet = INT_KEY_TYPE_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
				}
DEBUGLOG(("Authorize::key_value = [%s]\n",csKeyValue));
			}
		}
	}

	/* Merch Detail */
        if (iRet == PD_OK) {
 		if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::Call DBMerchDetail:Add\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","Add");
	                if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchDetail:Add Failed\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchDetail:Add Failed\n");
       	                 iRet = INT_ERR;
			}
			else {
DEBUGLOG(("Authorize::DBMerchDetail:Add Succ\n"));
			}

			if (iRet == PD_OK) { 
DEBUGLOG(("Authorize::Call DBMerchDetail:UpdateMerchCardTypeEnable\n"));
                                DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","UpdateMerchCardTypeEnable");
                                if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchDetail:UpdateMerchCardTypeEnable Failed\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchDetail:UpdateMerchCardTypeEnable Failed\n");
                                         iRet = INT_ERR;
                                }
                                else {
DEBUGLOG(("Authorize::DBMerchDetail:UpdateMerchCardTypeEnable Succ\n"));
                                }
			}

		} else if (cAction == PD_ACTION_UPDATE) {
			if (cUpdateType == PD_UPDATE_MERCH_INFO || cUpdateType == PD_UPDATE_ALL) {
DEBUGLOG(("Authorize::Call DBMerchDetail:UpdateMerchantStatus\n"));
	                	DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","UpdateMerchantStatus");
		                if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchDetail:UpdateMerchantStatus Failed\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchDetail:UpdateMerchantStatus Failed\n");
		       	                 iRet = INT_ERR;
				}
				else {
DEBUGLOG(("Authorize::DBMerchDetail:UpdateMerchantStatus Succ\n"));
				}	
			}
		}

		if (iRet == PD_OK) {
			if (cAction == PD_ACTION_ADD || 
				(cAction == PD_ACTION_UPDATE && (cUpdateType == PD_UPDATE_MERCH_INFO || cUpdateType == PD_UPDATE_ALL))) {
DEBUGLOG(("Authorize::Call BOReserve:HandleReserveAmount\n"));
					DBObjPtr = CreateObj(DBPtr,"BOReserve","HandleReserveAmount");
					if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::BOReserve:HandleReserveAmount Failed\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::BOReserve:HandleReserveAmount Failed\n");
						iRet = INT_ERR;
					}
					else {
DEBUGLOG(("Authorize::BOReserve:HandleReserveAmount Succ\n"));
					}	        	
			}
		}
	}

	/* Merch Keys */
        if (iRet == PD_OK) {
		if (cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::Call DBMerchDetail:GetMerchant\n"));
	                DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchant");
			if((unsigned long)((*DBObjPtr)(csMid, rRecordSet) != PD_OK)){
DEBUGLOG(("Authorize::Call DBMerchDetail:GetMerchant Fail\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchDetail:GetMerchant Failed\n");
				iRet = INT_MERCHANT_ID_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		if (iRet == PD_OK) {
			if (cAction == PD_ACTION_ADD||		
			    (cAction == PD_ACTION_UPDATE && (cUpdateType == PD_UPDATE_KEY || cUpdateType == PD_UPDATE_ALL))) {

DEBUGLOG(("Authorize::Call DBMerchKeys:Add\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMerchKeys","Add");
				if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchKeys:Add Failed\n"));
ERRLOG("TxnMgtByUsMCR::Authorize::DBMerchKeys:Add Failed\n");
					iRet = INT_ERR;
                		}
	                	else {
DEBUGLOG(("Authorize::DBMerchKeys:Add Succ\n"));
				}
        		}
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hResponse, "merchant_id", csMid);
		//PutField_CString(hResponse, "key_value", csKeyValue);
	}

	FREE_ME(csMid);
	FREE_ME(csKeyType);

	hash_destroy(hTxn);
	FREE_ME(hTxn);

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("TxnMgtByUsMCR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

