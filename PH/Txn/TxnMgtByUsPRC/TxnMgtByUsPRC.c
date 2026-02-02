/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/26              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPRC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsPRC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{

        int     iRet = PD_OK;

	char	*csPspId;
        char	*csTxnCountry;
	char	*csTxnCcy;
	char	*csDate;
	hash_t* hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	if(GetField_CString(hRequest,"psp_id",&csPspId)){
		PutField_CString(hContext,"psp_id",csPspId);
		PutField_CString(hResponse,"psp_id",csPspId);
DEBUGLOG(("Authorize::psp_id= [%s]\n",csPspId));
	}
	else{
DEBUGLOG(("Authorize::psp_id not found!!\n"));
ERRLOG("TxnMgtByUsPRC::Authorize::psp_id not found!!\n");
		iRet=INT_ERR;
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsPRC::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
		PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
	}
	else{
		DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
		if((unsigned long) ((*DBObjPtr)(csPspId,rRecordSet))==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"country",&csTxnCountry)) {
					PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMgtByUsPRC::Authorize::txn_country not found!!\n");
			iRet=INT_ERR;
		}
		RecordSet_Destroy(rRecordSet);
	}

	if(GetField_CString(hRequest,"select_date",&csDate)){
DEBUGLOG(("Authorize::select_date= [%s]\n",csDate));
	}
        else{
DEBUGLOG(("Authorize::select_date not found!!\n"));
ERRLOG("TxnMgtByUsPRC::Authorize::select_date not found!!\n");
		iRet=INT_ERR;
        } 


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOPsp:GetPspReconTxnDetail\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPsp","GetPspReconTxnDetail");
		if((unsigned long) ((*BOObjPtr)(hContext,hRequest,hResponse)!=PD_OK)){
			iRet = INT_ERR;
		}
	}


/*
 	if(iRet==PD_OK){
		iCnt=0;
DEBUGLOG(("Authorize::Call DBTxnPspDetail:GetTxnPspDetailForRecon\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetailForRecon");
		if((unsigned long) ((*DBObjPtr)(csPspId,
						csTxnCcy,
                                                csDate,
						rRecordSet))==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
				iCnt++;
				if(GetField_CString(hRec,"txn_seq",&csTmp)){
DEBUGLOG(("GetTxnPspDetailForRecon: txn_seq = [%s]\n",csTmp));
					sprintf(csTag,"txnid_%d",iCnt);
					PutField_CString(hResponse,csTag,csTmp);
				}
				if(GetField_CString(hRec,"fundin_date",&csTmp)){
DEBUGLOG(("GetTxnPspDetailForRecon: fundin_date = [%s]\n",csTmp));
					sprintf(csTag,"fundin_date_%d",iCnt);
					PutField_CString(hResponse,csTag,csTmp);
				}
				if(GetField_Double(hRec,"txn_amt",&dTmp)){
DEBUGLOG(("GetTxnPspDetailForRecon: txn_amt = [%lf]\n",dTmp));
					dPspAmt += dTmp;
				}
				if(GetField_Double(hRec,"service_fee",&dTmp)){
DEBUGLOG(("GetTxnPspDetailForRecon: service_fee = [%lf]\n",dTmp));
					dPspFee +=dTmp;
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}

			PutField_Int(hResponse,"total_cnt",iCnt);
			PutField_Double(hResponse,"txn_amt",dPspAmt);
			PutField_Double(hResponse,"service_fee",dPspFee);
			PutField_Double(hResponse,"psp_balance",dPspAmt-dPspFee);
		}
		else{
			iRet = INT_ERR;
DEBUGLOG(("Authorize::Call DBTxnPspDetail:GetTxnPspDetailForRecon Failed\n"));
		}

	}
*/
/*
	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call BOBalance:TransferPspBalance\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","TransferPspBalance");
		if((unsigned long) ((*BOObjPtr)(hContext,hRequest))!=PD_OK){
			iRet = INT_ERR;
		}
		
	}


	if(iRet == PD_OK){
		hPsp = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hPsp,0);
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
		if(GetField_CString(hContext,"PHDATE",&csTmp)){
			PutField_CString(hPsp,"recon_date",csTmp);

			int i;
			for(i=0; i<iCnt; i++){
				sprintf(csTag,"txn_seq_%d",i);
				if(GetField_CString(hContext,csTag,&csTmp)){
					PutField_CString(hPsp,"txn_seq",csTmp);

					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
					if((unsigned long) ((*DBObjPtr)(hPsp))!=PD_OK){
DEBUGLOG(("DBTxnPspDetail:Update Failed[%s]\n",csTmp));
					}
				}
			}
		}
		else{
DEBUGLOG(("DBTxnPspDetail:PHDATE not found!!!!!\n"));
ERRLOG("TxnMgtByUsPRC:Authorize::PHDATE not found!!!!!\n");
			iRet = INT_ERR;
		}
		FREE_ME(hPsp);
	}
*/
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet); 

DEBUGLOG(("TxnMgtByUsPRC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
