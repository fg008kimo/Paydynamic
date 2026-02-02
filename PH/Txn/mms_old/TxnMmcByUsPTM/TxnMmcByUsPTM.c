/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/28              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsPTM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsPTM(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  hash_t* hRequest,
                  hash_t* hResponse)
{

	int	iRet = PD_OK;

        char    *csTmp;
	char	cTmp;
	char	cIsd_ind;

	double  dTmp ;

	char	*csNodeId = NULL;
        char	*csServerNode = NULL;

	char	*csToNodeId = NULL;

	hash_t *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t *hRec;
	recordset_t *rRecordSet;
	rRecordSet = (recordset_t *) malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);


/* txn_seq */
        if(GetField_CString(hRequest,"txn_seq",&csTmp)){
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
                PutField_CString(hTxn,"org_txn_seq",csTmp);

        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;

		PutField_Int(hContext,"internal_error",iRet);
        }


/* dtl_txn_seq */ 
        if(GetField_CString(hContext,"dtl_txn_seq",&csTmp)){
DEBUGLOG(("Authorize::dtl_txn_seq= [%s]\n",csTmp));
                PutField_CString(hTxn,"org_dtl_txn_seq",csTmp);
        }
        else{
DEBUGLOG(("Authorize::dtl_txnid not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::dtl_txnid not found!!\n");
                iRet=INT_INVALID_TXN;

		PutField_Int(hContext,"internal_error",iRet);
        }

        if (GetField_CString(hRequest, "host_ref", &csTmp)) {
DEBUGLOG(("Authorize::host_ref = [%s]\n",csTmp));
                PutField_CString(hTxn,"host_ref",csTmp);
        }
        else{
DEBUGLOG(("Authorize::host_ref not found!!\n"));
ERRLOG("TxnMmcByUsCTB::Authorize::host_ref not found!!\n");
                iRet=INT_INVALID_TXN;

                PutField_Int(hContext,"internal_error",iRet);
        }

        if (GetField_CString(hRequest, "host_dtl_ref", &csTmp)) {
DEBUGLOG(("Authorize::host_dtl_ref = [%s]\n",csTmp));
                PutField_CString(hTxn,"host_dtl_ref",csTmp);
        }
        else{
DEBUGLOG(("Authorize::host_dtl_ref not found!!\n"));
ERRLOG("TxnMmcByUsCTB::Authorize::host_dtl_ref not found!!\n");
                iRet=INT_INVALID_TXN;

                PutField_Int(hContext,"internal_error",iRet);
        }



/* add_user */
        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
                PutField_CString(hTxn,"add_user",csTmp);
                PutField_CString(hTxn,"update_user",csTmp);
        }

/* psp_id */
        if(GetField_CString(hContext,"psp_id",&csTmp)){
DEBUGLOG(("Authorize::psp_id = [%s]\n",csTmp));
                PutField_CString(hTxn,"psp_id",csTmp);
                PutField_CString(hTxn,"src_party_type",PD_MMS_PARTY_PSP);
        }

/* mb_id  */
        if(GetField_CString(hContext,"mb_id",&csTmp)){
DEBUGLOG(("Authorize::mb_id = [%s]\n",csTmp));
                PutField_CString(hTxn,"mb_id",csTmp);
                PutField_CString(hTxn,"dst_party_type",PD_MMS_PARTY_MB);
        }

/* isd_ind  */
        if(GetField_Char(hContext,"isd_ind",&cIsd_ind)){
DEBUGLOG(("Authorize::isd_ind = [%c]\n",cIsd_ind));
                PutField_Char(hTxn,"isd_ind",cIsd_ind);
        }

/* txn_amt */
       if(GetField_Double(hContext,"txn_amt",&dTmp)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dTmp));
                PutField_Double(hTxn,"txn_amt",dTmp);
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_ccy */
	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_ccy",csTmp);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* adjustment*/
/*
       if(GetField_Double(hContext,"adjustment",&dTmp)){
DEBUGLOG(("Authorize::adjustment = [%f]\n",dTmp));
                PutField_Double(hTxn,"adjustment",dTmp);
        }
        else{
DEBUGLOG(("Authorize::adjustment not found!!\n"));
        }
*/

/* rate */
/*
       if(GetField_Double(hContext,"exchange_rate",&dTmp)){
DEBUGLOG(("Authorize::rate = [%f]\n",dTmp));
                PutField_Double(hTxn,"exchange_rate",dTmp);
        }
        else{
DEBUGLOG(("Authorize::rate not found!!\n"));
        }
*/

/* processing_cost */
       if(GetField_Double(hContext,"processing_cost",&dTmp)){
DEBUGLOG(("Authorize::processing_cost = [%f]\n",dTmp));
                PutField_Double(hTxn,"processing_cost",dTmp);
        }
        else{
DEBUGLOG(("Authorize::processing_cost not found!!\n"));
        }

/* bank_charge */
       if(GetField_Double(hContext,"bank_charge",&dTmp)){
DEBUGLOG(("Authorize::bank_charge = [%f]\n",dTmp));
                PutField_Double(hTxn,"bank_charge",dTmp);
        }
        else{
DEBUGLOG(("Authorize::bank_charge not found!!\n"));
        }

/* bank_charge_refund */
/*
       if(GetField_Double(hConext,"bank_charge_refund",&dTmp)){
DEBUGLOG(("Authorize::bank_charge_refund = [%f]\n",dTmp));
                PutField_Double(hTxn,"bank_charge_refund",dTmp);
        }
        else{
DEBUGLOG(("Authorize::bank_charge_refund not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::bank_charge_refund not found!!\n");
        }
*/

/* txn_country */
/*
       if(GetField_CString(hRequest,"txn_country",&csTmp)){
DEBUGLOG(("Authorize::txn_country = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_country",csTmp);
        }
        else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
        }
*/

	if (GetField_Char(hRequest, "cal_amt_ind", &cTmp)) {
DEBUGLOG(("Authorize::cal_amt_ind = [%c]\n",cTmp));
		PutField_Char(hTxn, "cal_amt_ind", cTmp);
	}


	if (cIsd_ind == PD_SOURCE) {
		if (GetField_CString(hContext, "from_node", &csNodeId)) {
DEBUGLOG(("Authorize::from node_id = [%s]\n",csNodeId));
		}
		else {
DEBUGLOG(("Authorize::from_node not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::from_node not found!!\n");
		iRet = PD_ERR;
		PutField_Int(hContext,"internal_error",iRet);
		}
	} 
	else if (cIsd_ind == PD_DESTINATION) {
                if (GetField_CString(hContext, "to_node", &csNodeId)) {
DEBUGLOG(("Authorize::to node_id = [%s]\n",csNodeId));
                }
                else {
DEBUGLOG(("Authorize::to_node not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::to_node not found!!\n");
                iRet = PD_ERR;
                PutField_Int(hContext,"internal_error",iRet);
                }
	}

	if (iRet == PD_OK) {
		PutField_CString(hTxn, "mms_node_id", csNodeId);
	}	

        if (GetField_CString(hContext, "server_node", &csServerNode)) {
DEBUGLOG(("Authorize::server node_id = [%s]\n",csServerNode));
        }
        else {
DEBUGLOG(("Authorize::server node_id not found!!\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::server node_id not found!!\n");
                iRet = INT_ERR;

                PutField_Int(hContext, "internal_error", iRet);
        }

	if(GetField_CString(hRequest,"transmission_datetime",&csTmp)){
		PutField_CString(hTxn, "transmission_datetime", csTmp);
	}




/**************************************/
/* Call BO for Cal PSP or MB Bal      */
/**************************************/
/* ??????????????
If isd_ind == SOURCE 
	Debit(-) PSP Balance : processing_cost
	Debit(-) PSP Balance : txn_amt 
   else 
	Credit(+) MB Balance : txn_amt 
	Debit (-) MB Balance : bank_charge
	Debit (-) MB Balance : processing_cost
*/
/**************************************/


	if (iRet == PD_OK) {
		if (strcmp(csServerNode, csNodeId) == 0) {
DEBUGLOG(("Authorize::party_node is same with server_node\n"));

DEBUGLOG(("Authorize::Call BOMmsBalance: TxnTypeHandler\n"));
			BOObjPtr = CreateObj(BOPtr,"BOMmsBalance","TxnTypeHandler");
			iRet = (unsigned long)((*BOObjPtr)(hTxn));

			if (iRet != PD_OK) {
DEBUGLOG(("Authorize::TxnTypeHandler Failed\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::TxnTypeHandler Failed\n");
                	}
			else {

				if (GetField_CString(hTxn, "org_txn_seq", &csTmp)) {
					PutField_CString(hResponse, "txn_seq", csTmp);
				}

				if (GetField_CString(hTxn, "org_dtl_txn_seq", &csTmp)) {
					PutField_CString(hResponse, "dtl_txn_seq", csTmp);
				}
			}
		} 
		else {

			PutField_CString(hTxn,"process_type", PD_MMS_PROCESS_TYPE);
			PutField_CString(hTxn, "process_code", PD_MMS_TRANSFER_FR_PSP);

DEBUGLOG(("Authorize::need to send 2Nodes [%s]\n", csNodeId));
			DBObjPtr = CreateObj(DBPtr, "DBMmxNodes", "GetAllNodesByType");
			if((unsigned long)(*DBObjPtr)(PD_MMS_CLIENT,rRecordSet)==PD_FOUND){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {

					if(GetField_CString(hRec,"node_id",&csToNodeId)){
						if (strcmp(csNodeId, csToNodeId) == 0) {

							if (GetField_CString(hRec, "mms_key", &csTmp)) {
								PutField_CString(hTxn, "mms_key", csTmp);
							}

DEBUGLOG(("Authorize::TxnMmsByUs2Node: node_id [%s]\n",csNodeId));

DEBUGLOG(("Authorize::Call TxnMmsByUs2Node: Authorize\n"));
							TxnObjPtr = CreateObj(TxnPtr, "TxnMmsByUs2Node","Authorize");
							iRet = (unsigned long)(*TxnObjPtr)(hContext,hTxn,hResponse);
DEBUGLOG(("Authorize::Call TxnMmsByUs2Node iRet=[%d]\n",iRet));

							if (iRet != PD_OK) {
DEBUGLOG(("Authorize::TxnMmsByUs2Node Failed\n"));
ERRLOG("TxnMmcByUsPTM::Authorize::TxnMmsByUs2Node Failed\n");
							}
							else {
								if (GetField_CString(hResponse, "org_txn_seq", &csTmp)) {
									PutField_CString(hResponse, "txn_seq", csTmp);
									RemoveField_CString(hResponse,"org_txn_seq");
								}

								if (GetField_CString(hResponse, "org_dtl_txn_seq", &csTmp)) {
									PutField_CString(hResponse, "dtl_txn_seq", csTmp);
									RemoveField_CString(hResponse,"org_dtl_txn_seq");
								}
							}
						}
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}

		}
	}


	hash_destroy(hTxn);
	FREE_ME(hTxn);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);	

DEBUGLOG(("TxnMmcByUsPTM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
