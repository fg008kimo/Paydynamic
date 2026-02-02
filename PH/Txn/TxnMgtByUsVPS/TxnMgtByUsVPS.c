/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVPS.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsVPS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	hash_t  *hRec;
	hash_t  *hOrgTxn;
	char    *csOrgTxnSeq;
        char    *csOrgPostDate;
        //char    *csMerchantId;
        //char    *csServiceCode;
        char    *csCountry;
        char    *csCcy;
        char    *csTmp;
	char	*csUpdateUser;
	char	*csPspId;
	char	cStatus;
	char	cArInd;
	char	*csSubStatus;
        //double  dFee = 0.0;
        //double  dPreFee = 0.0;
        //double  dTxnAmt= 0.0;
        //double  dNetAmt= 0.0;
        //double  dReserveAmt= 0.0;
        double  dPspTxnAmt= 0.0;
        double  dServiceFee= 0.0;
        double  dTmp = 0.0;
        //int     iTmp;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        hOrgTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);

DEBUGLOG(("TxnMgtByUsVPS: Authroize()\n"));
	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("TxnMgtByUsVPS: org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hOrgTxn,"txn_seq",csOrgTxnSeq);
                PutField_Char(hOrgTxn,"status",PD_REVERSED);
                PutField_CString(hOrgTxn,"sub_status",PD_UNDO);
	}
	if (GetField_CString(hContext,"add_user",&csUpdateUser)) {
DEBUGLOG(("TxnMgtByUsVPS: update_user = [%s]\n",csUpdateUser));
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnHeader\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("GetTxnHeader::status = [%c]\n",cStatus));
                                }
                                if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("GetTxnHeader::ar_ind = [%c]\n",cArInd));
                                }
                                if (GetField_CString(hRec,"sub_status",&csSubStatus)) {
DEBUGLOG(("GetTxnHeader::sub_status = [%s]\n",csSubStatus));
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }

			if(cStatus==PD_COMPLETE &&
			   cArInd==PD_ACCEPT &&
			   !strcmp(csSubStatus,PD_APPROVED)){
DEBUGLOG(("Authorize::Valid txn[%s]: [%c][%c][%s]\n",csOrgTxnSeq,cStatus,cArInd,csSubStatus));
			}
			else{
DEBUGLOG(("Authorize::Invalid txn[%s]: [%c][%c][%s]\n",csOrgTxnSeq,cStatus,cArInd,csSubStatus));
				iRet=INT_INVALID_TXN;
                        	PutField_Int(hContext,"internal_error",iRet);
			}
                }
                else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVPS:Authorize::GetTxnHeader::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                        PutField_Int(hContext,"internal_error",iRet);
                }
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnDetail\n"));
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnDetail::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"txn_country",&csCountry)) {
                                        //PutField_CString(hContext,"org_txn_country",csCountry);
                                        PutField_CString(hContext,"txn_country",csCountry);
                                        //PutField_CString(hRequest,"txn_country",csCountry);
DEBUGLOG(("GetTxnDetail::txn_country = [%s]\n",csCountry));
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("GetTxnDetail:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVPS:Authorize::GetTxnDetail:: not found record!!\n");
                        iRet = INT_NOT_RECORD;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnPspDetail\n"));
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnPspDetail::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("GetTxnPspDetail::psp_id = [%s]\n",csPspId));
                                        //PutField_CString(hContext,"org_psp_id",csTmp);
                                        PutField_CString(hContext,"psp_id",csPspId);
                                }
                                if (GetField_CString(hRec,"txn_ccy",&csCcy)) {
DEBUGLOG(("GetTxnPspDetail::psp_txn_ccy = [%s]\n",csCcy));
                                        //PutField_CString(hContext,"org_dst_txn_ccy",csTmp);
                                        PutField_CString(hContext,"txn_ccy",csCcy);
                                }
                                if (GetField_Double(hRec,"txn_amt",&dPspTxnAmt)) {
                                        //PutField_Double(hContext,"org_dst_net_amt",dPspTxnAmt);
                                        PutField_Double(hContext,"txn_amt",dPspTxnAmt);
DEBUGLOG(("GetTxnPspDetail::txn_amt = [%lf]\n",dPspTxnAmt));
                                }
                                if (GetField_Double(hRec,"service_fee",&dServiceFee)) {
                                        PutField_Double(hContext,"precal_fee",dServiceFee);
                                        PutField_Double(hContext,"service_fee",dServiceFee);
DEBUGLOG(("GetTxnPspDetail::service_fee = [%lf]\n",dServiceFee));
                                }
                                if (GetField_CString(hRec,"txn_date",&csOrgPostDate)) {
DEBUGLOG(("GetTxnPspDetail::txn_date = [%s]\n",csOrgPostDate));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("GetTxnPspDetail:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVPS:Authorize::GetTxnDetail:: not found record!!\n");
                        iRet = INT_NOT_RECORD;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBPspBalance:CreditBalance\n"));
                DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
                if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dPspTxnAmt+dServiceFee, csUpdateUser) != PD_OK) {
DEBUGLOG(("Authorize::DBPspBalance:CreditBalance Failed\n"));
                        iRet = INT_ERR;
                }
        }

	if(iRet==PD_OK){
DEBUGLOG(("Call Update Org Transaction\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                if((unsigned long) ((*DBObjPtr)(hOrgTxn))!=PD_OK)
                        iRet = INT_ERR;
        }

        if(iRet==PD_OK){
DEBUGLOG(("Call Add Transaction Detail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
        }

/*
        if(iRet==PD_OK){
DEBUGLOG(("Call Update Transaction Detail\n"));
                if(GetField_Double(hContext,"merchant_open_bal",&dTmp)){
                        PutField_Double(hContext,"open_bal",dTmp);
                }
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
        }
*/
        if(iRet==PD_OK){
DEBUGLOG(("Call Add TxnPspDetail\n"));
                if(GetField_CString(hContext,"PHDATE",&csTmp)){
                        PutField_CString(hContext,"txn_date",csTmp);
                }
                PutField_CString(hContext,"desc","Void Psp Settlement");
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
        }

	if(iRet==PD_OK){
		hash_t *hTxn;
		hTxn = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hTxn,0);
DEBUGLOG(("Authorize::Call DBPspBalance:GetBalance\n"));
                DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetBalance");
                if ((*DBObjPtr)(csPspId, csCountry, csCcy, hTxn) == PD_OK) {

                        if (GetField_Double(hTxn, "balance", &dTmp)) {
DEBUGLOG(("GetBalance::balance = [%f]\n",dTmp));
                                PutField_Double(hContext, "bal", dTmp);
                        }

                        if (GetField_Double(hTxn, "total_float", &dTmp)) {
DEBUGLOG(("GetBalance::total_float = [%f]\n",dTmp));
                                PutField_Double(hContext, "total_float", dTmp);
                        }

                        if (GetField_Double(hTxn, "total_hold", &dTmp)) {
DEBUGLOG(("GetBalance::total_hold = [%f]\n",dTmp));
                                PutField_Double(hContext, "total_hold", dTmp);
                        }


                	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
                	if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        	iRet = INT_ERR;
		}
		FREE_ME(hTxn);
        }

	RecordSet_Destroy(rRecordSet);
	FREE_ME(hOrgTxn);
	FREE_ME(rRecordSet);


DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}
