/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/21              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsVOR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

int GetTxnInfo(const unsigned char *csTxnSeq,
		hash_t * hContext,
		hash_t * hRequest);

void TxnOmtByUsVOR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTxnSeq;
	char	*csTxnSeqOpt;
	char	*csTmp;
	char	*csTxnCode;
	char	*csHandler;
	char    *csPHDate = NULL;
        char    *csOrgPostDate = NULL;
	//int	iTmp;
	//int	iReturnPspFee=PD_FALSE;
	//int	iFound;
	int	iPayoutTxn = PD_FALSE;
	//double  dTmp;
        //char    *p;
	hash_t	*hRec;// , *hOptContext;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
	//hOptContext = (hash_t*)  malloc (sizeof(hash_t));
        //hash_init(hOptContext,0);

DEBUGLOG(("Authorize\n"));


	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hContext,"from_txn_seq",csTmp);
		//PutField_CString(hOptContext,"txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"org_txn_seq",&csTxnSeq)){
		PutField_CString(hContext,"org_txn_seq",csTxnSeq);
DEBUGLOG(("Authorize::org_txn_seq= [%s]\n",csTxnSeq));
	}
	else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnOmtByUsVOR:Authorize::txnid not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"org_txn_seq_to",&csTxnSeqOpt)){
		PutField_CString(hContext,"to_txn_seq",csTxnSeqOpt);
		//PutField_CString(hOptContext,"org_txn_seq",csTxnSeqOpt);
DEBUGLOG(("Authorize::org_txn_seq (optional) = [%s]\n",csTxnSeqOpt));
	}
	
	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hContext,"update_user",csTmp);
DEBUGLOG(("Authorize::update_user= [%s]\n",csTmp));
	}
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark= [%s]\n",csTmp));
	}

	PutField_Int(hRequest,"return_mfee",PD_TRUE);
DEBUGLOG(("Authorize::return_merchantfee (default)= [%d]\n",PD_TRUE));

/*
	if(GetField_CString(hRequest,"return_pspfee",&csTmp)){
                iReturnPspFee = atoi(csTmp);
		PutField_Int(hRequest,"return_pspfee",iReturnPspFee);
DEBUGLOG(("Authorize::return_pspfee = [%s]\n",csTmp));
        }
	else{
		PutField_Int(hRequest,"return_pspfee",PD_FALSE);
DEBUGLOG(("Authorize::return_pspfee (default)= [%d]\n",PD_FALSE));
	}

	if(iReturnPspFee==PD_TRUE){
                if(GetField_CString(hRequest,"actual_fee",&csTmp)){
                        int iCheck = PD_FALSE;
                        p = (char*)strchr(csTmp, '.');
                        if (p == NULL){
                                iCheck = is_numeric(csTmp);
                                if(iCheck!=PD_FALSE){
                                        if(sscanf(csTmp,"%lf",&dTmp)==1){
                                                PutField_Double(hContext,"actual_psp_fee",dTmp);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTmp));
                                        }
                                }
                        }
                        else{
                                if(sscanf(csTmp,"%lf",&dTmp)==1){
                                        PutField_Double(hContext,"actual_psp_fee",dTmp);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTmp));
                                        iCheck = PD_TRUE;
                                }
                        }
                        if(iCheck==PD_FALSE){
                                iRet =  INT_INVALID_PAY_AMOUNT;
                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnOmtByUsVOR::Authorize() txn_amt Invalid\n");
                        }
                }
        }
*/

	if(iRet==PD_OK){
		iRet = GetTxnInfo((const unsigned char*)csTxnSeq,hContext,hRequest);
DEBUGLOG(("Authorize::GetTxnInfo iRet = [%d]\n",iRet));

		if(iRet == PD_OK){
			GetField_CString(hRequest,"org_txn_code",&csTxnCode);

//////*******only void Adjustment/Settlement with mms mode OFF
			char    *csMmsMode = strdup("");
			int	iMmsMode = PD_FALSE;
			DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
			if ((unsigned long)(DBObjPtr)(PD_MMSMODE,csMmsMode) == FOUND) {
DEBUGLOG(("FindCode MMs Mode  = [%s]\n",csMmsMode));
				if(!strcmp(csMmsMode, PD_ENABLE_MMSMODE)){
					iMmsMode = PD_TRUE;
					if(!strcmp(csTxnCode,PD_SETTLEMENT_REQUEST)||
					   !strcmp(csTxnCode,PD_PSP_SETTLEMENT) ||
					   !strcmp(csTxnCode,PD_MERCH_BAL_TRF_OTH_SYS) ||
					   !strcmp(csTxnCode,PD_PSP_BAL_TRF_OTH_SYS)){
DEBUGLOG(("Authorize:: MMS Mode is ON, Txn unvoidable!!!!!!!!\n"));
ERRLOG("TxnOmtByUsVOR::Authorize: MMS Mode is ON, Txn unvoidable!!!!!!!!\n");
						iRet=INT_ERR;
					}
				}
			}
			FREE_ME(csMmsMode);

			// for adjustment
			char    cPartyType;
                        int     iCheck= PD_TRUE;

                        if(toupper(csTxnCode[0])==PD_TYPE_MERCHANT)
                        	cPartyType = PD_TYPE_MERCHANT;
                        else if(toupper(csTxnCode[0])==PD_TYPE_PSP)
                        	cPartyType = PD_TYPE_PSP;
                        else
                        	iCheck = PD_FALSE;

			if (iCheck == PD_TRUE && islower(csTxnCode[0])) {
				PutField_Int(hContext, "is_adj_txn_code", PD_TRUE);
				if(iMmsMode==PD_TRUE){
DEBUGLOG(("Authorize:: MMS Mode is ON, Txn unvoidable!!!!!!!!\n"));
ERRLOG("TxnOmtByUsVOR::Authorize: MMS Mode is ON, Txn unvoidable!!!!!!!!\n");
					iRet=INT_ERR;
				}					
			}

/*Check the two txn_seq is in a pair (TFT&TFF)*/
			if (iRet == PD_OK) {
				if(!strcmp(csTxnCode,PD_MERCHANT_BAL_TFF)){
DEBUGLOG(("Authorize::Call DBOLTransaction:GetTxnHeader\n"));
					int iMatch = PD_FALSE;
        				recordset_init(rRecordSet,0);
					DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
					if ((*DBObjPtr)(csTxnSeqOpt,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csTxnSeqOpt));
						hRec = RecordSet_GetFirst(rRecordSet);
						while (hRec) {
							if(GetField_CString(hRec,"org_txn_id",&csTmp)){
								if(!strcmp(csTmp,csTxnSeq)){
									iMatch = PD_TRUE;
								}
							}
							hRec = RecordSet_GetNext(rRecordSet);
						}
					}
					if(iMatch!=PD_TRUE){
						iRet = INT_INVALID_TXN;
DEBUGLOG(("Authorize:: The two txn_seq are not in a pair!!!!!!!\n"));
ERRLOG("TxnOmtByUsVOR::Authorize: The two txn_seq are not in a pair!!!!!!!!\n");
					}
				}
			}

			if (iRet == PD_OK) {
/*call BOTxnElement*/

				if(!strcmp(csTxnCode,PD_PAYOUT_APPROVE)){
                                        if(GetField_CString(hContext,"org_sub_status",&csTmp)){
                                                if(!strcmp(csTmp,PD_APPROVED_FOR_GENERATED)){
                                                        GetField_CString(hContext,"PHDATE",&csPHDate);
                                                        if(GetField_CString(hContext,"org_posting_date",&csOrgPostDate)){
                                                                if(!strcmp(csPHDate,csOrgPostDate))
                                                                        PutField_Int(hContext,"same_date_cancel",PD_TRUE);
                                                        }
                                                }
                                        }
                                }

				if(!strcmp(csTxnCode,PD_OL_PAYOUT_APPROVE)){
                                        //always put back to ava po
					PutField_Int(hContext,"same_date_cancel",PD_TRUE);
				}
				BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","VoidOrgTxnElements");
				iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize:: BOOLTxnElements:VoidOrgTxnElements iRet = [%d]\n",iRet));

			}
/////////////////////
			if (iRet == PD_OK) {
				csHandler = (char*) malloc (20);
/*Void Deposit*/
/*				if(!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE)||
         	                    !strcmp(csTxnCode,PD_INITIAL_TXN_CODE)||
         	                    !strcmp(csTxnCode,PD_MOBILE_DSP_CODE)){
					PutField_CString(hContext,"new_txn_code",PD_DEPOSIT_VOID_WITH_FEE);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_DEPOSIT_VOID_WITH_FEE);
				}
*/
/*Payout*/
				if(!strcmp(csTxnCode,PD_OL_PAYOUT_APPROVE)){
					iPayoutTxn = PD_TRUE;
					PutField_CString(hContext,"txn_code",PD_OL_PAYOUT_VOID_MERCHANT_WITH_FEE);
					PutField_Int(hContext,"do_logging",PD_NO_LOG);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_PAYOUT_VOID);
				}
/*Void Merchant Settlement*/
/*				else if(!strcmp(csTxnCode,PD_SETTLEMENT_REQUEST)){
					PutField_CString(hContext,"new_txn_code",PD_SETTLEMENT_VOID);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_SETTLEMENT_VOID);
				}
*/
/*Void PSP Settlement*/
/*				else if(!strcmp(csTxnCode,PD_PSP_SETTLEMENT)){
					PutField_CString(hContext,"new_txn_code",PD_PSP_SETTLEMENT_VOID);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_PSP_SETTLEMENT_VOID);
				}
*/
/*Void Merchant Bal Transfer To Other System */
/*				else if (!strcmp(csTxnCode, PD_MERCH_BAL_TRF_OTH_SYS)) {
					PutField_CString(hContext, "new_txn_code", PD_MERCH_VOID_BAL_TRF_OTH_SYS);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_MERCH_VOID_BAL_TRF_OTH_SYS);
				}
*/
/*Void PSP Bal Transfer To Other System */
/*				else if (!strcmp(csTxnCode, PD_PSP_BAL_TRF_OTH_SYS)) {
					PutField_CString(hContext, "new_txn_code", PD_PSP_VOID_BAL_TRF_OTH_SYS);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_PSP_VOID_BAL_TRF_OTH_SYS);
				}
*/
/*Void Intra Merchant Bal Transfer*/
/*				else if(!strcmp(csTxnCode,PD_MERCHANT_BAL_TFF)){
					PutField_CString(hContext,"new_txn_code",PD_MERCHANT_BAL_TFF_VOID);
                			sprintf(csHandler,"TxnOmtByUs%s",PD_MERCHANT_BAL_TFF_VOID);
				}
*/
/*Void Psp Bal Transfer*/
/*				else if(!strcmp(csTxnCode,"PBU")){
					PutField_CString(hContext,"new_txn_code","PBR");
                			sprintf(csHandler,"TxnOmtByUs%s","PBR");
				}
*/
/* Fund-in Payout for Merchant */
/*				else if (!strcmp(csTxnCode, PD_FUND_IN_PAYOUT_MERCHANT)) {
					PutField_CString(hContext,"new_txn_code",PD_FUND_IN_PAYOUT_MERCHANT_VOID);
                			sprintf(csHandler,"TxnOmtByUs%s", PD_FUND_IN_PAYOUT_MERCHANT_VOID);
				}
*/
/* Fund-in Payout for PSP */
/*				else if (!strcmp(csTxnCode, PD_FUND_IN_PAYOUT_PSP)) {
					PutField_CString(hContext,"new_txn_code",PD_FUND_IN_PAYOUT_PSP_VOID);
                			sprintf(csHandler,"TxnOmtByUs%s", PD_FUND_IN_PAYOUT_PSP_VOID);
				}
*/
				else{
/*Void Adjustment*/
/*					if (GetField_Int(hContext, "is_adj_txn_code", &iTmp)) {
						if (iTmp == PD_TRUE) {
                					sprintf(csHandler,"TxnOmtByUs%s","VAD");
						}
					}
*/				}
DEBUGLOG(("TxnOmtByUsVOR Create Txn Object [%s]\n",csHandler));
                		TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
				iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
				FREE_ME(csHandler);
			}
		}
	}


	if(iRet==PD_OK){
		if(iPayoutTxn)	
			PutField_CString(hContext,"sub_status",PD_REFUND_APPROVED);
		else
			PutField_CString(hContext,"sub_status",PD_APPROVED);
	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	//FREE_ME(hOptContext);
DEBUGLOG(("TxnOmtByUsVOR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int GetTxnInfo(const unsigned char *csTxnSeq,
		hash_t * hContext,
		hash_t * hRequest)
{
	int iRet = PD_OK;
	char	*csTxnCode;
	char	*csProcessCode;
	char	*csProcessType;
	char	*csSubStatus;
	char	*csTmp;
	char	cTmp;
	double  dTmp = 0.0;
	int	iReleased = PD_FALSE;
	hash_t	*hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize::Call DBOLTransaction:GetTxnHeader\n"));
	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
	if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csTxnSeq));
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"host_posting_date",&csTmp)) {
                                PutField_CString(hContext,"org_posting_date",csTmp);
DEBUGLOG(("GetTxnHeader::host_posting_date = [%s]\n",csTmp));
                        }
			if (GetField_CString(hRec,"txn_code",&csTxnCode)) {
				PutField_CString(hRequest,"org_txn_code",csTxnCode);
DEBUGLOG(("GetTxnHeader::txn_code = [%s]\n",csTxnCode));
			}
			if (GetField_CString(hRec,"process_code",&csProcessCode)) {
DEBUGLOG(("GetTxnHeader::process_code = [%s]\n",csProcessCode));
			}
			if (GetField_CString(hRec,"process_type",&csProcessType)) {
DEBUGLOG(("GetTxnHeader::process_type = [%s]\n",csProcessType));
			}
			if (GetField_CString(hRec,"merchant_id",&csTmp)) {
				PutField_CString(hRequest,"merchant_id",csTmp);
DEBUGLOG(("GetTxnHeader::merchant_id = [%s]\n",csTmp));
			}
			if (GetField_CString(hRec,"service_code",&csTmp)) {
				PutField_CString(hRequest,"service_code",csTmp);
				PutField_CString(hContext,"service_code",csTmp);
DEBUGLOG(("GetTxnHeader::service_code= [%s]\n",csTmp));
			}

			/* for VAD only */
                        if (GetField_Double(hRec, "txn_amt", &dTmp)) {
                                PutField_Double(hRequest,"adj_txn_amt",dTmp);
DEBUGLOG(("GetTxnHeader::txn_amt = [%lf]\n",dTmp));
                        }
			if (GetField_Double(hRec, "net_amt", &dTmp)) {
                                PutField_Double(hRequest,"adj_net_amt",dTmp);
DEBUGLOG(("GetTxnHeader::net_amt = [%lf]\n",dTmp));
			}

			if (GetField_Char(hRec,"status",&cTmp)) {
DEBUGLOG(("GetTxnHeader::status = [%c]\n",cTmp));
				if(cTmp!=PD_COMPLETE){
					iRet=INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader::Invalid status[%c]\n",cTmp));
ERRLOG("TxnOmtByUsVOR:GetTxnHeader::Invalid status!!\n");
				}
				else{
					if (GetField_Char(hRec,"ar_ind",&cTmp)) {
DEBUGLOG(("GetTxnHeader::ar_ind = [%c]\n",cTmp));
						if(cTmp!=PD_ACCEPT){
							iRet=INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader::Invalid ar_ind[%c]\n",cTmp));
ERRLOG("TxnOmtByUsVOR:Authorize::GetTxnHeader::Invalid ar_ind!!\n");
						}
					}
				}
			}
			if(GetField_CString(hRec,"sub_status",&csSubStatus)){
				PutField_CString(hContext,"org_sub_status",csSubStatus);
DEBUGLOG(("GetTxnHeader::sub_status = [%s]\n",csSubStatus));
			}
			if(!strcmp(csSubStatus,PD_RESERVE_RELEASED)){
				if (GetField_CString(hRec,"reserved_release_date",&csTmp)) {
					iReleased = PD_TRUE;
DEBUGLOG(("GetTxnHeader::reserved_release_date = [%s]\n",csTmp));
				}
			}
			PutField_Int(hContext,"reserve_released",iReleased);
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}
	else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csTxnSeq));
//ERRLOG("TxnOmtByUsVOR:Authorize::GetTxnHeader::not found record!!\n");
		iRet=INT_NOT_RECORD;
		//PutField_Int(hContext,"internal_error",iRet);
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTxnCode:IsVoidable\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnCode","IsVoidable");
		if ((unsigned long)(*DBObjPtr)(csTxnCode,csProcessType,csProcessCode) != PD_TRUE) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("IsVoidable:: un-voidable for [%s][%s][%s]\n",csTxnCode,csProcessCode,csProcessType));
ERRLOG("TxnOmtByUsVOR:Authorize::un-voidable txn!!\n");
		}
	}

	if(iRet==PD_OK){
//////get merchant_client_id
		if(GetField_CString(hRequest,"merchant_id",&csTmp)){
DEBUGLOG(("Authorize::Call BOOLMerchant:GetMerchantDetail\n"));
               		BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantDetail");
               		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
       		}
	}
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}
