/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/06              LokMan Chow
Add record locking                                 2015/08/06              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsREC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnOmtByUsREC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	double	dTmp = 0.0;
	int	iTmp = 0;
	int	iCheck = 0;
	int	iCnt = 0;
	int	i = 0;
	char	csTag[PD_TAG_LEN+1];
	char	*p;
	int	iTmpRet = PD_OK;

	hash_t  *hTxn;
	hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);


DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"activity",&csTmp)){
		PutField_CString(hContext,"activity",csTmp);
DEBUGLOG(("Authorize::activity = [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::activity is missing!!!!!!!!\n"));
ERRLOG("Authorize::activity is missing!!!!!!!!\n");
	}

        if(GetField_CString(hRequest,"bank_stmt_type",&csTmp)){
		PutField_CString(hContext,"bank_stmt_type",csTmp);
DEBUGLOG(("Authorize::bank_stmt_type = [%s]\n",csTmp));
        }
	else{
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::bank_stmt_type is missing!!!!!!!!\n"));
ERRLOG("Authorize::bank_stmt_type is missing!!!!!!!!\n");
	}


        if(GetField_CString(hRequest,"trigger_type",&csTmp)){
		PutField_CString(hContext,"trigger_type",csTmp);
DEBUGLOG(("Authorize::trigger_type = [%s]\n",csTmp));
        }
	else{
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::trigger_type is missing!!!!!!!!\n"));
ERRLOG("Authorize::trigger_type is missing!!!!!!!!\n");
	}


        if(GetField_CString(hRequest,"input_channel",&csTmp)){
		PutField_CString(hContext,"input_channel",csTmp);
DEBUGLOG(("Authorize::input_channel = [%s]\n",csTmp));
        }
	else{
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::input_channel is missing!!!!!!!!\n"));
ERRLOG("Authorize::input_channel is missing!!!!!!!!\n");
	}


        if(GetField_CString(hRequest,"recon_type",&csTmp)){
		PutField_CString(hContext,"recon_type",csTmp);
DEBUGLOG(("Authorize::recon_type = [%s]\n",csTmp));
        }
	else{
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::recon_type is missing!!!!!!!!\n"));
ERRLOG("Authorize::recon_type is missing!!!!!!!!\n");
	}

        if(GetField_CString(hRequest,"use_pf",&csTmp)){
		iTmp = atoi(csTmp);
                PutField_Int(hContext,"use_pending_fund",iTmp);
DEBUGLOG(("Authorize::use_pf = [%d]\n",iTmp));
	}

        if(GetField_CString(hRequest,"have_charge",&csTmp)){
		iTmp = atoi(csTmp);
		PutField_Int(hContext,"include_bank_charge",iTmp);
DEBUGLOG(("Authorize::have_charge = [%d]\n",iTmp));

		if(iTmp){
			if(GetField_CString(hRequest,"bank_charge",&csTmp)){
				iCheck = PD_FALSE;
				p = (char*)strchr(csTmp, '.');
				if (p == NULL){
					iCheck = is_numeric(csTmp);
					if(iCheck!=PD_FALSE){
						if(sscanf(csTmp,"%lf",&dTmp)==1){
							PutField_Double(hContext,"bank_charge",dTmp);
DEBUGLOG(("Authorize() bank_charge = [%lf]\n",dTmp));
						}
					}
				}
				else{
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,"bank_charge",dTmp);
DEBUGLOG(("Authorize() bank_charge = [%lf]\n",dTmp));
                                        	iCheck = PD_TRUE;
					}
				}
				if(dTmp<=0.0){
					iCheck=PD_FALSE;
				}
				if(iCheck==PD_FALSE){
					iRet =  INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_charge Invalid[%s]\n",csTmp));
ERRLOG("TxnOmtByUsREC::Authorize() bank_charge Invalid\n");
				}
			}
			else{
				iRet = INT_ERR;
DEBUGLOG(("Authorize::bank_charge is missing!!!!!!!!\n"));
ERRLOG("Authorize::bank_charge is missing!!!!!!!!\n");
			}
		}
        }

        if(GetField_CString(hRequest,"have_interest",&csTmp)){
		iTmp = atoi(csTmp);
		PutField_Int(hContext,"include_interest",iTmp);
DEBUGLOG(("Authorize::have_interest = [%d]\n",iTmp));

		if(iTmp){
			if(GetField_CString(hRequest,"interest",&csTmp)){
				iCheck = PD_FALSE;
				p = (char*)strchr(csTmp, '.');
				if (p == NULL){
					iCheck = is_numeric(csTmp);
					if(iCheck!=PD_FALSE){
						if(sscanf(csTmp,"%lf",&dTmp)==1){
							PutField_Double(hContext,"interest",dTmp);
DEBUGLOG(("Authorize() interest = [%lf]\n",dTmp));
						}
					}
				}
				else{
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,"interest",dTmp);
DEBUGLOG(("Authorize() interest = [%lf]\n",dTmp));
                                        	iCheck = PD_TRUE;
					}
				}
				if(dTmp<=0.0){
					iCheck=PD_FALSE;
				}
				if(iCheck==PD_FALSE){
					iRet =  INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() interest Invalid[%s]\n",csTmp));
ERRLOG("TxnOmtByUsREC::Authorize() interest Invalid\n");
				}
			}
			else{
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::interest is missing!!!!!!!!\n"));
ERRLOG("Authorize::interest is missing!!!!!!!!\n");
			}
		}
        }

        if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hContext,"add_user",csTmp);
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }

	if(GetField_CString(hRequest,"txn_cnt",&csTmp)){
		iCnt = atoi(csTmp);

		PutField_Int(hContext,"txn_cnt",iCnt);

		for(i=1; i<=iCnt; i++){
			sprintf(csTag,"txnid_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				sprintf(csTag,"txn_id_%d",i-1);
				PutField_CString(hContext,csTag,csTmp);
DEBUGLOG(("Authorize::txn_id[%d] = [%s]\n",i,csTmp));

				// lock txn log
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnIdForUpdateNoWait()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnIdForUpdateNoWait");
				iTmpRet = (unsigned long)(*DBObjPtr)(csTmp);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnIdForUpdateNoWait() failed\n"));
					iRet = INT_RECON_IN_ANOTHER_PROCESS;
					PutField_Int(hContext, "internal_error", iRet);
					break;
				}
			}
			else{
				iRet = INT_TXN_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::txn_id[#%d] is missing!!!!!!!!\n",i));
ERRLOG("Authorize::txn_id[#%d] is missing!!!!!!!!\n",i);
				break;
			}
		}
	}

	if(GetField_CString(hRequest,"stmt_cnt",&csTmp)){
		iCnt = atoi(csTmp);

		PutField_Int(hContext,"baid_txn_cnt",iCnt);

		for(i=1; i<=iCnt; i++){
			sprintf(csTag,"stmt_txnid_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				sprintf(csTag,"baid_txn_id_%d",i-1);
				PutField_CString(hContext,csTag,csTmp);
DEBUGLOG(("Authorize::baid_txn_id[%d] = [%s]\n",i,csTmp));

				// lock baid txn
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::MatchRespTxnNoWait()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "MatchRespTxnNoWait");
				iTmpRet = (unsigned long)(*DBObjPtr)(csTmp, PD_COMPLETE);
				if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::MatchRespTxnNoWait() failed\n"));
					iRet = INT_RECON_IN_ANOTHER_PROCESS;
					PutField_Int(hContext, "internal_error", iRet);
					break;
				}
			}
			else{
				iRet = INT_TXN_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::baid_txn_id[#%d] is missing!!!!!!!!\n",i));
ERRLOG("Authorize::baid_txn_id[#%d] is missing!!!!!!!!\n",i);
				break;
			}
		}
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOOLTxnEngine:DoAction\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLTxnEngine","DoAction");
		iRet = (unsigned long)(*BOObjPtr)(hContext);
		
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"act_batch_id",&csTmp))
			PutField_CString(hResponse,"action_id",csTmp);
	}

        FREE_ME(hTxn);
DEBUGLOG(("TxnOmtByUsREC Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
