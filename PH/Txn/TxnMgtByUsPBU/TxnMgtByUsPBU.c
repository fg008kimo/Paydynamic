/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/26              [MSN]
insert to recon history table			   2012/01/17		   [MSN]
Add field paid_amt			           2020/11/18              [WMC]
Update paid_amount in TxnPspDetail		   2021/03/10		   [WMC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPBU.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsPBU(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{

        int     iRet = PD_OK;

	char	*csPspId;
	char	*csTxnSeq;
        char	*csTxnCountry;
	char	*csTxnCcy;
	char	*csDate;
	char	*csPhDate;
	char	*csReportDate;
        char    *csTmp;
	char	csUser[PD_CREATE_USER_LEN+1];
	//char	csTag[PD_TAG_LEN +1];
	int	iTxn=0;
	double	dInputAmt=0.0;
	double	dInputFee=0.0;
	double	dTotalAmt=0.0;
	double	dOrgTxnAmt=0.0;
	double	dPaidAmt=0.0;
	double	dOrgCost=0.0;
	double	dAdjAmt=0.0;
	double	dTmp;

	hash_t  *hRec, *hPsp, *hDetail, *hHis;
	hHis = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hHis,0);
	hDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDetail,0);
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
		PutField_CString(hHis,"txn_seq",csTxnSeq);
		PutField_CString(hContext,"from_txn_seq",csTxnSeq);
DEBUGLOG(("Authorize::txn_id= [%s]\n",csTxnSeq));
	}

	if(GetField_CString(hRequest,"psp_id",&csPspId)){
		PutField_CString(hContext,"psp_id",csPspId);
		PutField_CString(hResponse,"psp_id",csPspId);
		PutField_CString(hHis,"psp_id",csPspId);
DEBUGLOG(("Authorize::psp_id= [%s]\n",csPspId));
	}
	else{
DEBUGLOG(("Authorize::psp_id not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::psp_id not found!!\n");
		iRet=INT_PSP_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
		PutField_CString(hContext,"net_ccy",csTxnCcy);
		PutField_CString(hContext,"org_txn_ccy",csTxnCcy);
		PutField_CString(hHis,"txn_ccy",csTxnCcy);
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
		PutField_CString(hDetail,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
	}
	else{
		DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
		if((unsigned long) ((*DBObjPtr)(csPspId,rRecordSet))==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"country",&csTxnCountry)) {
					PutField_CString(hDetail,"txn_country",csTxnCountry);
					PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::txn_country not found!!\n");
			iRet=INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		//RecordSet_Destroy(rRecordSet);
	}
	PutField_CString(hHis,"txn_country",csTxnCountry);

	if(GetField_CString(hRequest,"select_date",&csDate)){
		PutField_CString(hHis,"psp_txn_date",csDate);
DEBUGLOG(("Authorize::select_date= [%s]\n",csDate));
	}
        else{
DEBUGLOG(("Authorize::select_date not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::select_date not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        } 
	if(GetField_CString(hRequest,"report_date",&csReportDate)){
		PutField_CString(hHis,"report_date",csReportDate);
DEBUGLOG(("Authorize::report_date= [%s]\n",csReportDate));
	}
        else{
DEBUGLOG(("Authorize::report_date not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::report_date not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        } 


	if(GetField_Double(hContext,"txn_amt",&dInputAmt)){
DEBUGLOG(("Authorize::txn_amt= [%lf]\n",dInputAmt));
		PutField_Double(hHis,"input_amt",dInputAmt);
	}
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::txn_amt not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        }

	if(GetField_Double(hContext,"paid_amt",&dInputAmt)){
DEBUGLOG(("Authorize::paid_amt= [%lf]\n",dInputAmt));
                PutField_Double(hHis,"input_amt",dInputAmt);
        }
        else{
DEBUGLOG(("Authorize::paid_amt not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::paid_amt not found!!\n");
                iRet=INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }

	if(GetField_Double(hContext,"service_fee",&dInputFee)){
		PutField_Double(hHis,"input_fee",dInputFee);
DEBUGLOG(("Authorize::service_fee= [%lf]\n",dInputFee));
	}

	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
		strcpy(csUser,csTmp);
	}
	else{
		strcpy(csUser,PD_UPDATE_USER);
	}
	csUser[strlen(csUser)]='\0';
	PutField_CString(hHis,"add_user",csUser);


	if(GetField_CString(hRequest,"total_cnt",&csTmp)){
		iTxn = atoi(csTmp);
		PutField_Int(hContext,"total_cnt",iTxn);
		PutField_Int(hHis,"input_count",iTxn);
DEBUGLOG(("Authorize::total_cnt = [%d]\n",iTxn));
	}
        else{
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::total_cnt not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        }


	if(iRet == PD_OK){
        	recordset_init(rRecordSet,0);
DEBUGLOG(("Authorize::Call DBPspReconHistory:GetReconHistoryByDate\n"));
		BOObjPtr = CreateObj(BOPtr,"DBPspReconHistory","GetReconHistoryByDate");
		if((unsigned long)(*BOObjPtr)(csPspId,csTxnCcy,csTxnCountry,csDate,rRecordSet)==PD_FOUND){
DEBUGLOG(("Authorize::Reconciliation already done!!\n"));
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call BOPsp:GetPspReconTxnDetail\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPsp","GetPspReconTxnDetail");
		if((unsigned long) ((*BOObjPtr)(hContext,hRequest,hResponse)!=PD_OK)){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}


	if(iRet == PD_OK){
		if(GetField_Int(hContext,"total_txn_cnt",&iTxn)){
			PutField_Int(hHis,"txn_count",iTxn);
DEBUGLOG(("Authorize::total_cnt = [%d]\n",iTxn));
		}
		if(GetField_Double(hContext,"total_txn_amt",&dOrgTxnAmt)){
			PutField_Double(hHis,"txn_amt",dOrgTxnAmt);
			PutField_Double(hContext,"txn_amt",dOrgTxnAmt);
			PutField_Double(hContext,"net_amt",dOrgTxnAmt);
DEBUGLOG(("Authorize::total_txn_amt = [%lf]\n",dOrgTxnAmt));
		}
		if(GetField_Double(hContext,"total_paid_amt",&dPaidAmt)){
                        PutField_Double(hHis,"paid_amt",dPaidAmt);
                        PutField_Double(hContext,"paid_amt",dPaidAmt);
                       	PutField_Double(hContext,"paid_amount",dPaidAmt);
DEBUGLOG(("Authorize::total_paid_amt = [%lf]\n",dPaidAmt));
                }
		if(GetField_Double(hContext,"total_txn_fee",&dOrgCost)){
			PutField_Double(hHis,"txn_fee",dOrgCost);
DEBUGLOG(("Authorize::total_txn_fee = [%lf]\n",dOrgCost));
		}
		hPsp = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hPsp,0);
DEBUGLOG(("Authorize::Call BOBalance:TransferPspBalance\n"));
		PutField_CString(hPsp,"txn_ccy",csTxnCcy);
		PutField_CString(hPsp,"txn_country",csTxnCountry);
		PutField_CString(hPsp,"psp_id",csPspId);

DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
		if(GetField_CString(hContext,"PHDATE",&csPhDate)){
			PutField_CString(hHis,"recon_date",csPhDate);
			PutField_CString(hContext,"txn_date",csPhDate);
			//PutField_CString(hContext,"report_date",csReportDate);
			//PutField_CString(hContext,"recon_date",csTmp);
			//PutField_Int(hContext,"recon_ind",PD_TRUE);

			if(GetField_CString(hContext,"txn_seq",&csTmp)){
				//PutField_CString(hPsp,"recon_id",csTmp);
				PutField_CString(hDetail,"txn_seq",csTmp);
			}
			PutField_Char(hPsp,"transfer_from",PD_PSP_FLOAT);
			if(GetField_Double(hContext,"paid_amt",&dTmp)){
                                PutField_Double(hPsp,"txn_amt",dTmp);
                                dTotalAmt += dTmp;
                        }else{
				if(GetField_Double(hContext,"txn_amt",&dTmp)){
                                	PutField_Double(hPsp,"txn_amt",dTmp);
                                	dTotalAmt += dTmp;
                        	}			
			}
			if(GetField_Double(hHis,"txn_fee",&dTmp)){
				PutField_Double(hPsp,"service_fee",dTmp);
				PutField_Double(hContext,"service_fee",dTmp);
				dTotalAmt = dTotalAmt - dTmp;
			}
			PutField_Double(hContext,"transfer_amt",dTotalAmt);

			BOObjPtr = CreateObj(BOPtr,"BOBalance","TransferPspBalance");
			if((unsigned long) ((*BOObjPtr)(hPsp,hRequest))!=PD_OK){
				iRet = INT_ERR;
			}
			else{
				if (GetField_Double(hPsp,"psp_balance",&dTmp)) {
					PutField_Double(hContext,"bal",dTmp);
DEBUGLOG(("TxnPspDetail::Update: psp_balance = [%f]\n",dTmp));
				}
				if (GetField_Double(hPsp,"psp_total_float",&dTmp)) {
					PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG(("TxnPspDetail::Update: psp_total_float = [%f]\n",dTmp));
				}
				if (GetField_Double(hPsp,"psp_total_hold",&dTmp)) {
					PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("TxnPspDetail::Update: psp_total_hold = [%f]\n",dTmp));
				}
			}

			if(iRet==PD_OK){
				DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","UpdateReconedTxnPspDetail");
				if((unsigned long) ((*DBObjPtr)(csPspId,csTxnCcy,csDate,csPhDate,csReportDate))!=PD_OK){
DEBUGLOG(("TxnPspDetail:UpdateReconedTxnPspDetail Failed[%s]\n"));
				}
/*				int i;
				for(i=1; i<=iTxn; i++){
					hash_init(hPsp,0);
					sprintf(csTag,"txn_seq_%d",i);
                                        if(GetField_CString(hContext,csTag,&csTmp)){
                                                PutField_CString(hPsp,"txn_seq",csTmp);
					}
					
					PutField_CString(hPsp,"recon_date",csPhDate);
					PutField_Int(hPsp,"recon_ind",PD_TRUE);

					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
					if((unsigned long) ((*DBObjPtr)(hPsp))!=PD_OK){
DEBUGLOG(("TxnPspDetail:Update Failed[%s]\n",csTmp));
					}
				}
*/
			}

		}
		else{
DEBUGLOG(("TxnPspDetail:PHDATE not found!!!!!\n"));
ERRLOG("TxnMgtByUsPBU:Authorize::PHDATE not found!!!!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		FREE_ME(hPsp);
	}

	if(iRet == PD_OK){
		PutField_CString(hContext,"desc","Psp Balance Transfer");

		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("TxnPspDetail:Add Failed\n"));
		}
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("TxnPspDetail:Update Failed\n"));
		}
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("Transaction:UpdateDetail Failed\n"));
		}
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBPspReconHistory","Add");
                if((unsigned long) ((*DBObjPtr)(hHis))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("PspReconHistory:Add Failed\n"));
                }
	}

	if(iRet==PD_OK){
		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTransferAmtElement");
		if((unsigned long)(*BOObjPtr)(hContext)!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("AddTransferAmtElement :Add Failed\n"));
		}
	}



////////////////////Call the adjustment automatically
	if(iRet==PD_OK && dInputFee!=dOrgCost){
		char    csNewTxnSeq[PD_TXN_SEQ_LEN +1];
		int	iChk = PD_NOT_FOUND;
		char	*csRemark;
		char	*csCode;
		csCode = (char*) malloc (PD_SP_LONG_VALUE_LEN);
		csRemark = (char*) malloc (PD_TMP_BUF_LEN +1 );
		sprintf(csRemark,"Recon. Transaction ID: %s",csTxnSeq);

		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMgtTxnSeq");
		strcpy(csNewTxnSeq,(*DBObjPtr)());


		DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
		if(dInputFee>dOrgCost){
			dAdjAmt = dInputFee-dOrgCost;
			iChk = (unsigned long)(DBObjPtr)("DEBIT_ADJ_FOR_RECON",csCode);
		}
		else if(dInputFee<dOrgCost){
			dAdjAmt = dOrgCost-dInputFee;
			iChk = (unsigned long)(DBObjPtr)("CREDIT_ADJ_FOR_RECON",csCode);
		}

		if(iChk == PD_FOUND){
			//new txn_seq
			PutField_CString(hContext, "txn_seq", csNewTxnSeq);

			//adj txn code
			PutField_CString(hRequest, "txn_code", PD_PSP_ADJUSTMENT);

			//new txn_code
			PutField_CString(hRequest, "code", csCode);

			//adj amount
			PutField_Double(hContext,"txn_amt",dAdjAmt);
			PutField_Double(hContext,"paid_amt",dAdjAmt);
			PutField_Double(hContext,"paid_amount",dAdjAmt);

			//report_date
			PutField_CString(hRequest,"report_date",csDate);

			//remark
			PutField_CString(hRequest,"remark",csRemark);

			RemoveField_Double(hContext,"service_fee");

			ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","AddTxnLog");
			iChk = (unsigned long) ((*ChannelObjPtr)(hContext,hRequest));

			if(iChk==PD_OK){
DEBUGLOG(("Authorize::Call TxnMgtByUsPAD [%s][%s][%.2f][%s][%s]\n",csNewTxnSeq,csCode,dAdjAmt,csDate,csRemark));
				TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsPAD","Authorize");
				iChk = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
				if(iChk != PD_OK){
					PutField_Char(hContext,"ar_ind",PD_REJECT);
					PutField_Char(hContext,"status",PD_COMPLETE);
					RemoveField_CString(hContext,"approval_date");
					RemoveField_CString(hContext,"approval_timestamp");
DEBUGLOG(("Authorize::TxnMgtByUsPAD Failed!!!!!\n"));
ERRLOG("TxnMgtByUsPBU::Authorize::TxnMgtByUsPAD Failed!!!!!\n");
				}
				else{
					PutField_Char(hContext,"ar_ind",PD_ACCEPT);
					PutField_Char(hContext,"status",PD_COMPLETE);
					PutField_CString(hResponse,"adj_txn_seq",csNewTxnSeq);
				}

				ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","UpdateTxnLog");
				iChk = (unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse));
			}
		}
		else{
DEBUGLOG(("Authorize::No transaction code defined. The PSP adjustment is skipped.\n"));
		}

		FREE_ME(csCode);
		FREE_ME(csRemark);
	}

	PutField_CString(hContext,"txn_seq",csTxnSeq);
	PutField_CString(hContext,"txn_code",PD_PSP_BAL_TRANSFER);
	PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
	PutField_Double(hContext,"txn_amt",dOrgTxnAmt);
	PutField_Double(hContext,"net_amt",dOrgTxnAmt);
	PutField_Double(hContext,"paid_amt",dPaidAmt);
	PutField_Double(hContext,"paid_amount",dPaidAmt);
	RemoveField_Char(hContext,"ar_ind");
	RemoveField_Char(hContext,"status");
	RemoveField_CString(hContext,"new_txn_code");

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet); 
        FREE_ME(hDetail); 
        FREE_ME(hHis); 

DEBUGLOG(("TxnMgtByUsPBU Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
