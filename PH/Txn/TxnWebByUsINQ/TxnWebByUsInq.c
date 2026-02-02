/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/09/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsINQ.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);
void TxnWebByUsINQ(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iTmp;
	double	dTmp;
        char    *csValue = strdup("");
        char    *csChannelCode = strdup("");
	char*	csPtr = NULL;
	char*	csOrgTxnSeq;
	char	cPtr;
	char*	csBatchTxnSeq;
	char	*csPayMethod;
	hash_t  *hRec;
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("TxnWebByUsINQ Authorize()\n"));
	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {

		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnWebByUsINQ org_txn_seq = [%s]\n",csOrgTxnSeq));
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnWebByUsINQ found record = [%s]\n",csOrgTxnSeq));
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                       	 	if (GetField_CString(hRec,"process_type",&csPtr)) {
DEBUGLOG(("TxnWebByUsINQ:process_type= [%s]\n",csPtr));
					PutField_CString(hResponse,"process_type",csPtr);
				}
                       	 	if (GetField_CString(hRec,"process_code",&csPtr)) {
DEBUGLOG(("TxnWebByUsINQ:process_code= [%s]\n",csPtr));
					PutField_CString(hResponse,"process_code",csPtr);
				}
                       	 	if (GetField_Char(hRec,"status",&cPtr)) {
DEBUGLOG(("TxnWebByUsINQ:status= [%c]\n",cPtr));
					PutField_Char(hResponse,"status",cPtr);
				}
                       	 	if (GetField_Char(hRec,"ar_ind",&cPtr)) {
DEBUGLOG(("TxnWebByUsINQ:ar_ind= [%c]\n",cPtr));
					PutField_Char(hResponse,"ar_ind",cPtr);
				}
                       	 	if (GetField_CString(hRec,"merchant_id",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:merchant_id= [%s]\n",csValue));
					PutField_CString(hResponse,"merchant_id",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"merchant_ref",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:merchant_id= [%s]\n",csValue));
					PutField_CString(hResponse,"merchant_ref",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"transmission_datetime",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:transmission_datetime= [%s]\n",csValue));
					PutField_CString(hResponse,"transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"local_transmission_datetime",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:local_transmission_datetime= [%s]\n",csValue));
					PutField_CString(hResponse,"local_transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"channel_code",&csChannelCode)) {
DEBUGLOG(("TxnWebByUsINQ:channel_code= [%s]\n",csChannelCode));
                        	}
                       	 	if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("TxnWebByUsINQ:net_amt= [%f]\n",dTmp));
					PutField_Double(hResponse,"net_amt",dTmp);
                        	}
                       	 	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnWebByUsINQ:txn_amt= [%f]\n",dTmp));
					PutField_Double(hResponse,"txn_amt",dTmp);
                        	}
                       	 	if (GetField_Int(hRec,"internal_error",&iTmp)) {
DEBUGLOG(("TxnWebByUsINQ:internal_error= [%d]\n",iTmp));
					PutField_Int(hResponse,"internal_error",iTmp);
                        	}
                        	hRec = RecordSet_GetNext(rRecordSet);
                	}
        	}
		else {
DEBUGLOG(("TxnWebByUsINQ not found record for [%s]\n",csOrgTxnSeq));
			iRet = INT_ORG_TXN_NOT_FOUND;
		}

/* fee charge detail */
		if (iRet == PD_OK) {
                	recordset_init(rRecordSet,0);
        		DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
        		if ((*DBObjPtr)(csOrgTxnSeq,PD_ELEMENT_TXN_FEE,PD_TYPE_MERCHANT,rRecordSet) == PD_OK) {
               			hRec = RecordSet_GetFirst(rRecordSet);
                		while (hRec) {
                       	 		if (GetField_Double(hRec,"amount",&dTmp)) {
DEBUGLOG(("TxnWebByUsINQ:service fee= [%f]\n",dTmp));
						PutField_Double(hResponse,"service_fee",dTmp);
					}
					if(GetField_CString(hRec,"ccy",&csPtr)){
DEBUGLOG(("TxnWebByUsINQ:service fee ccy= [%s]\n",csPtr));
						PutField_CString(hResponse,"service_fee_ccy",csPtr);
					}

                        		hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
	}
	else 	
		iRet = INT_ERR;
	
        if ( iRet == PD_OK) {
/* Check Merchant */
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hResponse);
DEBUGLOG(("BOMerchant->GetMerchantDetail = [%d]\n",iRet));

        }
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"merchant_key",&csPtr)) {
DEBUGLOG(("BPMerchant: GetMerchantDetail - merchant_key = [%s]\n",csPtr));
                	PutField_CString(hResponse,"merchant_key",csPtr);
                 }
	}
	if (iRet == PD_OK ) {
        	recordset_init(rRecordSet,0);
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                       	 	if (GetField_CString(hRec,"echo_msg_1",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:echo_msg_1 = [%s]\n",csValue));
					PutField_CString(hResponse,"echo_msg_1",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"echo_msg_2",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:echo_msg_2 = [%s]\n",csValue));
					PutField_CString(hResponse,"echo_msg_2",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"echo_msg_3",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:echo_msg_3 = [%s]\n",csValue));
					PutField_CString(hResponse,"echo_msg_3",csValue);
                        	}
				if(GetField_CString(hRec,"encrypt_type",&csValue)){
DEBUGLOG(("TxnWebByUsINQ:encrypt_type= [%s]\n",csValue));
                                        PutField_CString(hResponse,"encrypt_type",csValue);
                                }
                                else{
DEBUGLOG(("TxnWebByUsINQ:use default encrypt_type= [01]\n"));
                                        PutField_CString(hResponse,"encrypt_type","01");
                                }
/* remark */
                       	 	if (GetField_CString(hRec,"remark",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:remark= [%s]\n",csValue));
					PutField_CString(hResponse,"remark",csValue);
                        	}
/* txn_ccy */
                       	 	if (GetField_CString(hRec,"txn_ccy",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:txn_ccy= [%s]\n",csValue));
					PutField_CString(hResponse,"txn_ccy",csValue);
					PutField_CString(hResponse,"net_ccy",csValue);
                        	}
/* pay_method */
                       	 	if (GetField_CString(hRec,"selected_pay_method",&csPayMethod)) {
DEBUGLOG(("TxnWebByUsINQ:pay_method= [%s]\n",csPayMethod));
					PutField_CString(hResponse,"pay_method",csPayMethod);
                        	}
                       	 	else if (GetField_CString(hRec,"pay_method",&csPayMethod)) {
DEBUGLOG(("TxnWebByUsINQ:pay_method= [%s]\n",csPayMethod));
					PutField_CString(hResponse,"pay_method",csPayMethod);
                        	}
				else {
DEBUGLOG(("TxnWebByUsINQ:pay_method is missing!!!\n"));
				}
/* bank code */
				if (GetField_CString(hRec,"bank_code",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:bank_code= [%s]\n",csValue));
					PutField_CString(hResponse,"bank_code",csValue);
				}
                       		hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK ) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"convenience_store",&csValue)) {
DEBUGLOG(("TxnWebByUsINQ:convenience store= [%s]\n",csValue));
                                        PutField_CString(hResponse,"convenience_store",csValue);
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        }
/*
	if (iRet == PD_OK) {
		if (!strcmp(csChannelCode,PD_CHANNEL_XPAY)) {
	 		MsgObjPtr = CreateObj(MsgPtr,"XpyMsg","BuildData");
        		if ((*MsgObjPtr)(hResponse) == PD_OK) {
                                if (GetField_CString(hResponse,"plainttext_data",&csPtr)) {
DEBUGLOG(("TxnWebByUsINQ:BUILD plainttext_data= [%s]\n",csPtr));
				}
			}
			else 
				iRet = PD_ERR;
		}
		else {
DEBUGLOG(("TxnWebByUsINQ:BUILD AckAuthData\n"));
	 		MsgObjPtr = CreateObj(MsgPtr,"WebMsg","BuildAckAuthData");
        		iRet = (unsigned long)(*MsgObjPtr)(hResponse);
		}
	}

	if (iRet == PD_OK) {
		if (!strcmp(csChannelCode,PD_CHANNEL_XPAY)) {
                	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateXpaySign");
                	iRet = (unsigned long)(*BOObjPtr)(hContext,hResponse);
DEBUGLOG(("BOSecurity->GenerateXpaySign = [%d]\n",iRet));
		}
		else {
                	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMac");
                	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("BOSecurity->GenerateMac = [%d]\n",iRet));
		}
	}
*/

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	FREE_ME(csPtr);
        FREE_ME(csValue);

DEBUGLOG(("TxnWebByUsINQ Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
