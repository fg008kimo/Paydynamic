/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCHK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsCHK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
        int	iRet = PD_OK;

	int	iIsProrata = PD_FALSE;
	int	iIsACRBank = PD_FALSE;
	char	*csTmp = NULL;

	char	*csEntityId = NULL;
	char	*csEntityType = NULL;
	char	*csFrCcy = NULL;
	char	*csBankCcy = NULL;
	double	dFrAmt=0.0;
	double	dAmt=0.0;
	double  dDefOandaThreshold=5.0;
	double  dDefThreshold=5.0;
	double  dOandaThreshold=5.0;
	double  dThreshold=5.0;
	double  dOandaRate=0.0;
	double  dOrgRate=0.0;
	double  dDiff = 0.0;
	double  dRate= 0.0;


	hash_t  *hDetail;
	hDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDetail,0);

DEBUGLOG(("Authorize::Start\n"));


/* is_prorata */
	if(GetField_CString(hRequest,"is_prorata",&csTmp)){
		iIsProrata = atoi(csTmp);
DEBUGLOG(("Authorize::is_prorata = [%d]\n",iIsProrata));
	}

/* entity_id */
        if(GetField_CString(hRequest,"entity_id",&csEntityId)){
DEBUGLOG(("Authorize::entity_id = [%s]\n",csEntityId));
		//get entity_type and is_acr_bank
		DBObjPtr = CreateObj(DBPtr,"DBMiEntityDetail","GetEntityType");
		if((unsigned long)((DBObjPtr)(csEntityId,hDetail)) == PD_FOUND){
			if(GetField_CString(hDetail,"entity_type",&csEntityType)){
DEBUGLOG(("Authorize::entity_type = [%s]\n",csEntityType));

				if(!strcmp(csEntityType,PD_MI_ENTITY_OPBANK)){
					DBObjPtr = CreateObj(DBPtr,"DBMiEntityOpb","GetOPBInfoByEntityId");
					iRet = (unsigned long)(*DBObjPtr)(csEntityId,hDetail);
					if(iRet == PD_OK){
						if(GetField_Int(hDetail,"is_acr_bank",&iIsACRBank)){
DEBUGLOG(("Authorize::is_acr_bank = [%d]\n",iIsACRBank));
						}
					}
					else{
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBMiEntityOpb:GetOPBInfoByEntityId Failed!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize() DBMiEntityOpb:GetOPBInfoByEntityId Failed!!\n");
					}
				}
			}
		}
		else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::entity_type not found\n"));
ERRLOG("TxnMgtByUsCHK::Authorize() entity_type not found\n");
		}
        }
	else {
		iRet = INT_MI_ENTITY_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::entity_id not found!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize::entity_id not found!!\n");
	}


	//only check the ACR bank and not prorata transaction
	if(strcmp(csEntityType,PD_MI_ENTITY_OPBANK) || iIsProrata || !iIsACRBank){
DEBUGLOG(("Authorize:: entity_type[%s], is_prorata[%d], is_acr_bank[%d]. Skip the checking...\n",csEntityType,iIsProrata,iIsACRBank));
		iRet = PD_SKIP_OK;
	}

	///get the input currency and amount pairs
	if(iRet == PD_OK){
/* fr_ccy */
		if(GetField_CString(hRequest,"fr_ccy",&csFrCcy)){
			PutField_CString(hContext,"from_ccy",csFrCcy);
DEBUGLOG(("Authorize::fr_ccy= [%s]\n",csFrCcy));
		}
		else{
			iRet=INT_CURRENCY_CODE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::fr_ccy not found!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize::fr_ccy not found!!\n");
		}

/* fr_txnamt */
		if(GetField_CString(hRequest,"fr_txnamt",&csTmp)){
			dFrAmt = string2double((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::fr_txnamt = [%f]\n",dFrAmt));
		}
		else{
			if(GetField_Double(hContext,"fr_txnamt",&dFrAmt)){
DEBUGLOG(("Authorize::fr_txnamt= [%f]\n",dFrAmt));
			} else {
				iRet=INT_PAY_AMOUNT_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::fr_txnamt not found!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize::fr_txnamt not found!!\n");
			}
		}

/* txn_ccy */
		if(GetField_CString(hRequest,"txn_ccy",&csBankCcy)){
			PutField_CString(hContext,"bank_ccy",csBankCcy);
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csBankCcy));
		}
		else{
			iRet=INT_CURRENCY_CODE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize::ccy not found!!\n");
		}

/* txn_amt */
		if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
		}
		else{
			iRet=INT_PAY_AMOUNT_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsCHK::Authorize::txn_amt not found!!\n");
		}

		if(dAmt<=0.0 || dFrAmt<=0.0){
			iRet= INT_INVALID_PAY_AMOUNT;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::invalid amount From[%s], To[%f]\n",csTmp,dAmt));
ERRLOG("TxnMgtByUsCHK::Authorize::invalid amount From[%s], To[%f]\n",csTmp,dAmt);
		}

	}

	if(iRet == PD_OK){
		char*   csValueTmp;
		csValueTmp = (char*) malloc (128);
		DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
		if ((unsigned long)(DBObjPtr)(PD_AVFX_OANDA_RATE_ALLOW_DIFF,csValueTmp) == FOUND) {
			sscanf(csValueTmp, "%lf",&dDefOandaThreshold);
DEBUGLOG(("Authorize::Default Input Rate & Oanda Rate difference threshold = [%lf]\n",dDefOandaThreshold));
		}
		if ((unsigned long)(DBObjPtr)(PD_AVFXRATE_ALLOW_DIFF,csValueTmp) == FOUND) {
			sscanf(csValueTmp, "%lf",&dDefThreshold);
DEBUGLOG(("Authorize::Default Input Rate & Org Rate difference threshold = [%lf]\n",dDefThreshold));
		}
		FREE_ME(csValueTmp);
	}

	if(iRet == PD_OK){
		//find override tolerance
		DBObjPtr = CreateObj(DBPtr,"DBACRThreshold","FindTolerance");
		if ((unsigned long)(DBObjPtr)("OANDA",csBankCcy,&dOandaThreshold) != PD_FOUND) {
			dOandaThreshold = dDefOandaThreshold;
		}
		if ((unsigned long)(DBObjPtr)("ORG_ACR",csBankCcy,&dThreshold) != PD_FOUND) {
			dThreshold = dDefThreshold;
		}
DEBUGLOG(("Authorize::OandaThreshold [%lf], dThreshold [%lf]\n",dOandaThreshold,dThreshold));
	}


	//compare the input rate with Original ACR and Oanda Rate
	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Check Input rate with Oanda Rate\n"));
		//get oanda rate
		hash_t *hOanda;
		hOanda = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hOanda,0);
		DBObjPtr = CreateObj(DBPtr,"DBExchangeRate","GetExchangeRate");
		if((unsigned long)(*DBObjPtr)(csBankCcy,csFrCcy,hOanda)==PD_OK){
			if(GetField_Double(hOanda,"rate",&dOandaRate)){
DEBUGLOG(("Authorize::Oanda rate [%lf]\n",dOandaRate));
				dDiff = 0.0;
				dRate = newround((dFrAmt/dAmt),PD_ROUND_UP_DEC);
				if(dRate>dOandaRate){
					dDiff = (dRate-dOandaRate)/dOandaRate;
DEBUGLOG(("Authorize::Input rate [%lf] & Oanda Rate with difference 1[%lf]\n",dRate,dDiff));
				}
				else{
					dDiff = (dOandaRate-dRate)/dOandaRate;
DEBUGLOG(("Authorize::Input rate [%lf] & Oanda Rate with difference 2 [%lf]\n",dRate,dDiff));
				}
				if(newround(dDiff*100,PD_DECIMAL_LEN) >dOandaThreshold){
					iRet = INT_LARGE_DIFF_OANDA_NEW_RATE;
					PutField_Int(hContext,"internal_error",iRet);

					PutField_Double(hResponse,"acr_tol_threshold",dOandaThreshold);
					PutField_Double(hResponse,"acr_input_diff",newround(dDiff*100,PD_DECIMAL_LEN));
DEBUGLOG(("Authorize::Input rate & Oanda Rate with difference [%.2f\%] > [%.2f\%]!!!!\n",newround(dDiff*100,PD_DECIMAL_LEN),dOandaThreshold));
				}
			}
			else{
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
		else{
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		FREE_ME(hOanda);
	}

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Check Input rate with Original ACR\n"));
		//get org ACR
		hash_t *hOrg;
		hOrg= (hash_t*) malloc (sizeof(hash_t));
		hash_init(hOrg,0);
		DBObjPtr = CreateObj(DBPtr,"DBMiAcrBal","GetOwnAcrBal");
		if ((unsigned long)(*DBObjPtr)(hContext, hOrg) == PD_FOUND) {
			if(GetField_Double(hOrg,"rate",&dOrgRate)){
DEBUGLOG(("Authorize::Original ACR [%lf]\n",dOrgRate));
				dDiff = 0.0;
				dRate = newround((dFrAmt/dAmt),PD_ROUND_UP_DEC);
				if(dRate>dOrgRate){
					dDiff = (dRate-dOrgRate)/dOrgRate;
DEBUGLOG(("Authorize::Input rate [%lf] & Org Rate with difference 1[%lf]\n",dRate,dDiff));
				}
				else{
					dDiff = (dOrgRate-dRate)/dOrgRate;
DEBUGLOG(("Authorize::Input rate [%lf] & Org Rate with difference 2 [%lf]\n",dRate,dDiff));
				}
				if(newround(dDiff*100,PD_DECIMAL_LEN) >dThreshold){
					iRet = INT_LARGE_DIFF_NEW_RATE;
					PutField_Int(hContext,"internal_error",iRet);

					PutField_Double(hResponse,"acr_tol_threshold",dThreshold);
					PutField_Double(hResponse,"acr_input_diff",newround(dDiff*100,PD_DECIMAL_LEN));
DEBUGLOG(("Authorize::Input rate & Org Rate with difference [%.2f\%] > [%.2f\%]!!!!\n",newround(dDiff*100,PD_DECIMAL_LEN),dThreshold));
                                }
                        }
			else{
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
		FREE_ME(hOrg);
	}

	if(iRet == PD_SKIP_OK)
		iRet = PD_OK;


	FREE_ME(hDetail);
DEBUGLOG(("TxnMgtByUsCHK Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
