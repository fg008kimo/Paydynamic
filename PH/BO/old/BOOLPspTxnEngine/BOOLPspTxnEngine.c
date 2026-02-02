/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/14              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"
#include "BOOLPspTxnEngine.h"
#include "myrecordset.h"
#include "myhash.h"
#include "math.h"
#include <time.h>

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);


void BOOLPspTxnEngine(char cdebug)
{
	cDebug = cdebug;
}


int	DoAction(hash_t* hContext);
int	GetTxnDetail(const char* csLevel, const char* csTxnId, hash_t* hTxn, const int iIsPostedTxn);
void	ConvertHash(const hash_t* hIn, hash_t* hOut, const int iIdx, const char* csMode);
int	RunSpecialAction(const char* csAction, hash_t* hTxn);
int	DoPostTxn(hash_t* hContext,hash_t* hRequest);
int	DoUpdateTxn(hash_t* hContext,hash_t* hRequest);


int	DoAction(hash_t* hContext)
{
	int iRet = PD_OK;

	int  i = 0;
	int  iTxnCnt = 0;
	int  iPostedTxnCnt = 0;
	int  iBaidTxnCnt = 0;
	int  iPostedBaidTxnCnt = 0;
	int  iLoopCnt = 0;
	int  iRunRule = PD_FALSE;
	int  iTotalCnt = 0;
	int  iNextAction = PD_FALSE;
	int  iTmp = 0;
	int  iTxnAction = 0;
	char *csTmp= NULL;
	char  csTag[PD_TAG_LEN+1];
	char  cInBaidTxn;
	char  cInPostBaidTxn;
	char  cInTxn;
	char  cInPostTxn;

	hash_t          *hRec;
	hash_t          *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	hash_t          *hDetail;
	hDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDetail,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	//get action (classify,reconcile,etc...)
	if(GetField_CString(hContext,"action",&csTmp)){
		PutField_CString(hTxn,"next_action",csTmp);
DEBUGLOG(("DoAction:: action = [%s]\n", csTmp));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("DoAction:: action is missing!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: action is missing!!!\n");
	}
	
	//get trigger_type (auto, manual)
	if(GetField_CString(hContext,"trigger_type",&csTmp)){
		PutField_CString(hTxn,"trigger_type",csTmp);
DEBUGLOG(("DoAction:: trigger_type = [%s]\n", csTmp));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("DoAction:: trigger_type is missing!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: trigger_type is missing!!!\n");
	}

	//input_channel (SMS,OMT)
	if(GetField_CString(hContext,"input_channel",&csTmp)){
		PutField_CString(hTxn,"input_channel",csTmp);
DEBUGLOG(("DoAction:: input_channel = [%s]\n", csTmp));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("DoAction:: input_channel is missing!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: input_channel is missing!!!\n");
	}

	if(GetField_CString(hContext,"add_user",&csTmp)){
		PutField_CString(hTxn,"add_user",csTmp);
	}
	else{
		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	}

	if (iRet == PD_OK) {
		//get txn details for all input txn_id, baid_id and post txn ids
		if(GetField_Int(hContext, "txn_cnt", &iTxnCnt)) {
			PutField_Int(hTxn,"txn_cnt",iTxnCnt);
DEBUGLOG(("DoAction:: txn_cnt = [%d]\n", iTxnCnt));
		}
		if(GetField_Int(hContext, "baid_txn_cnt", &iBaidTxnCnt)) {
			PutField_Int(hTxn,"baid_txn_cnt",iBaidTxnCnt);
DEBUGLOG(("DoAction:: baid_txn_cnt = [%d]\n", iBaidTxnCnt));
		}
		if(GetField_Int(hContext, "posted_txn_cnt", &iPostedTxnCnt)){
DEBUGLOG(("DoAction:: posted_txn_cnt = [%d]\n", iPostedTxnCnt));
		}
		if(GetField_Int(hContext, "posted_baid_txn_cnt", &iPostedBaidTxnCnt)){
DEBUGLOG(("DoAction:: posted_baid_txn_cnt = [%d]\n", iPostedBaidTxnCnt));
		}

		if(iBaidTxnCnt>iTxnCnt)
			iTotalCnt = iBaidTxnCnt;
		else
			iTotalCnt = iTxnCnt;

		for(i=0; i<iTxnCnt; i++){
			hash_init(hDetail,0);
			sprintf(csTag,"txn_id_%d",i);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_TXN_HEADER_LEVEL,csTmp,hDetail,PD_FALSE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,i,PD_SINGLE_TO_MULTIPLE);
					ConvertHash(hDetail,hContext,i,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);
		}

		for(i=0; i<iBaidTxnCnt; i++){
			hash_init(hDetail,0);
			sprintf(csTag,"baid_txn_id_%d",i);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_BAID_TXN_LEVEL,csTmp,hDetail,PD_FALSE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,i,PD_SINGLE_TO_MULTIPLE);
					ConvertHash(hDetail,hContext,i,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);
		}

		if(iPostedTxnCnt>0){
			hash_init(hDetail,0);
			if(GetField_CString(hContext,"posted_txn_id",&csTmp)){
				PutField_CString(hTxn,"posted_txn_id",csTmp);
				if(GetTxnDetail(PD_TXN_HEADER_LEVEL,csTmp,hDetail,PD_TRUE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
					ConvertHash(hDetail,hContext,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);
		}
		if(iPostedBaidTxnCnt>0){
			hash_init(hDetail,0);
			if(GetField_CString(hContext,"posted_baid_txn_id",&csTmp)){
				PutField_CString(hTxn,"posted_baid_txn_id",csTmp);
				if(GetTxnDetail(PD_BAID_TXN_LEVEL,csTmp,hDetail,PD_TRUE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
					ConvertHash(hDetail,hContext,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);
		}


		//if current txn exist, override the original records
		if(iRet == PD_OK && GetField_Int(hContext,"current_idx",&iTmp)){
			iTotalCnt = 1;

			hash_init(hDetail,0);
			sprintf(csTag,"current_txn_id_%d",iTmp);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_TXN_HEADER_LEVEL,csTmp,hDetail,PD_FALSE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);

			hash_init(hDetail,0);
			sprintf(csTag,"current_baid_txn_id_%d",iTmp);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_BAID_TXN_LEVEL,csTmp,hDetail,PD_FALSE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);

			hash_init(hDetail,0);
			sprintf(csTag,"current_posted_txn_id_%d",iTmp);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_TXN_HEADER_LEVEL,csTmp,hDetail,PD_TRUE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);

			hash_init(hDetail,0);
			sprintf(csTag,"current_posted_baid_txn_id_%d",iTmp);
			if(GetField_CString(hContext,csTag,&csTmp)){
				if(GetTxnDetail(PD_BAID_TXN_LEVEL,csTmp,hDetail,PD_TRUE)!=PD_OK){
					iRet = INT_ERR;
				}
				else{
					ConvertHash(hDetail,hTxn,0,PD_SINGLE_TO_MULTIPLE);
				}
			}
			hash_destroy(hDetail);
		}

	}

	if (iRet == PD_OK) {
		iNextAction = PD_TRUE;
	}

	//start loop
	iLoopCnt = 0;
	while(iNextAction){
		if(iLoopCnt<iTotalCnt){
DEBUGLOG(("DoAction:: ===========Loop #[%d]===========\n",iLoopCnt));

			RemoveField_CString(hTxn,"txn_code");
			RemoveField_CString(hTxn,"bank_acct_type");

			ConvertHash(hTxn,hTxn,iLoopCnt,PD_MULTIPLE_TO_SINGLE);

			PutField_Int(hTxn,"current_idx",iLoopCnt);
			if(GetField_CString(hTxn,"txn_id",&csTmp)){
				sprintf(csTag,"current_txn_id_%d",iLoopCnt);
				PutField_CString(hTxn,csTag,csTmp);
DEBUGLOG(("DoAction::txn_id[%s]\n",csTmp));
			}
			if(GetField_CString(hTxn,"baid_txn_id",&csTmp)){
				sprintf(csTag,"current_baid_txn_id_%d",iLoopCnt);
				PutField_CString(hTxn,csTag,csTmp);
DEBUGLOG(("DoAction::baid_txn_id[%s]\n",csTmp));
			}
			if(GetField_CString(hTxn,"posted_txn_id",&csTmp)){
				sprintf(csTag,"current_posted_txn_id_%d",iLoopCnt);
				PutField_CString(hTxn,csTag,csTmp);
DEBUGLOG(("DoAction::posted_txn_id[%s]\n",csTmp));
			}
			if(GetField_CString(hTxn,"posted_baid_txn_id",&csTmp)){
				sprintf(csTag,"current_posted_baid_txn_id_%d",iLoopCnt);
				PutField_CString(hTxn,csTag,csTmp);
DEBUGLOG(("DoAction::posted_baid_txn_id[%s]\n",csTmp));
			}

			//next action
			if(!GetField_CString(hTxn,"next_action",&csTmp)){
DEBUGLOG(("DoAction:: next_action not found!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: next_action not found!!!\n");
				TxnAbort();
				break;
			}
			else{
DEBUGLOG(("DoAction:: action [%s]\n",csTmp));
				PutField_CString(hTxn,"action",csTmp);
			}

			//txn_code 
			if(!GetField_CString(hTxn,"txn_code",&csTmp)){
DEBUGLOG(("DoAction:: txn_code not found!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: txn_code not found!!!\n");
				TxnAbort();
				break;
			}
DEBUGLOG(("DoAction:: txn_code = [%s]\n", csTmp));

			//bank_acct_type
			if(!GetField_CString(hTxn,"bank_acct_type",&csTmp)){
DEBUGLOG(("DoAction:: bank_acct_type not found!!!\n"));
ERRLOG("BOOLPspTxnEngine: DoAction:: bank_acct_type not found!!!\n");
				TxnAbort();
				break;
			}
DEBUGLOG(("DoAction:: bank_acct_type = [%s]\n", csTmp));

			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBOLPspTxnEngine","GetPspTxnEngine");
			if ((*DBObjPtr)(hTxn,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {

					iRunRule = PD_TRUE;

					//get special rule and run it
					if(GetField_CString(hRec,"spc_action",&csTmp)){
						iRunRule = RunSpecialAction(csTmp,hTxn);
					}

					//if no special action or special action result = TRUE, get rule parameters and run the rule
					if(iRunRule){
						if(GetField_Int(hRec,"exec_seq",&iTmp)){
DEBUGLOG(("DoAction() GetPspTxnEngine: Exec Seq [%d]\n",iTmp));
						}
						
						//having input txn?baid txn?post txn?
						/*
 						if(GetField_Char(hRec,"in_baid_txn",&cInBaidTxn)){
						}
						if(GetField_Char(hRec,"in_post_baid_txn",&cInPostBaidTxn)){
						}
						if(GetField_Char(hRec,"in_txn",&cInTxn)){
						}
						if(GetField_Char(hRec,"in_post_txn",&cInPostTxn)){
						}
						*/

						iTxnAction = 0;
						GetField_Int(hRec,"txn_action",&iTxnAction);

						if(iTxnAction==PD_ENGINE_ACTION_POST_TXN){
							if(DoPostTxn(hTxn,hRec)!=PD_OK){
								iRet = PD_ERR;
DEBUGLOG(("DoAction() DoPostTxn Failed!!!\n"));
							}
						}
						else if(iTxnAction==PD_ENGINE_ACTION_UPDATE_TXN){
							if(DoUpdateTxn(hTxn,hRec)!=PD_OK){
								iRet = PD_ERR;
DEBUGLOG(("DoAction() DoUpdateTxn Failed!!!\n"));
							}
						}

						if(iRet==PD_OK){
						//run next action if any
							if(GetField_CString(hRec,"next_action",&csTmp)){
DEBUGLOG(("DoAction() Do Next Action [%s]\n",csTmp));
								PutField_CString(hTxn,"action",csTmp);
								if(DoAction(hTxn)!=PD_OK){
									iRet = PD_ERR;
DEBUGLOG(("DoAction() Do Next Action Failed!!!!\n"));
								}
							}
						}

						if(iRet!=PD_OK){
							TxnAbort();
							iNextAction = PD_FALSE;
							break;
						}

					}
					else{
						//(continue next rule) or (quit job and TxnAbort)
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}

DEBUGLOG(("DoAction:: ===========End Loop #[%d]===========\n",iLoopCnt));
			iLoopCnt ++;
		}
		else{
			iNextAction = PD_FALSE;
DEBUGLOG(("DoAction() Loop End\n"));
		}

	}//while iNextAction

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(hTxn);
	FREE_ME(hDetail);

DEBUGLOG(("DoAction() exit iRet = [%d]\n", iRet));
	return iRet;
}


void	ConvertHash(const hash_t* hIn, hash_t* hOut, const int iIdx, const char* csMode)
{
	char	csTag[PD_TAG_LEN+1];
	char	*csTmp = NULL;
	double	dTmp = 0.0;

	//txn_id, txn_code, CR/DR, acct type, baid_type, txn_amt
	if(!strcmp(csMode,PD_MULTIPLE_TO_SINGLE)){
		sprintf(csTag,"txn_id_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"txn_id",csTmp);
		}

		sprintf(csTag,"baid_txn_id_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_txn_id",csTmp);
		}

		sprintf(csTag,"posted_txn_id_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_txn_id",csTmp);
		}

		sprintf(csTag,"posted_baid_txn_id_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_txn_id",csTmp);
		}

		sprintf(csTag,"baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid",csTmp);
		}

		sprintf(csTag,"posted_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid",csTmp);
		}

		sprintf(csTag,"baid_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_baid",csTmp);
		}

		sprintf(csTag,"posted_baid_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_baid",csTmp);
		}

		sprintf(csTag,"txn_code_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"org_txn_code",csTmp);
			PutField_CString(hOut,"txn_code",csTmp);
		}

		sprintf(csTag,"baid_txn_code_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_txn_code",csTmp);
			PutField_CString(hOut,"txn_code",csTmp); //override txn_code
		}

		sprintf(csTag,"posted_txn_code_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_txn_code",csTmp);
		}

		sprintf(csTag,"posted_baid_txn_code_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_txn_code",csTmp);
		}

		sprintf(csTag,"txn_country_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"txn_country",csTmp);
		}

		sprintf(csTag,"posted_txn_country_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_txn_country",csTmp);
		}

		sprintf(csTag,"baid_txn_country_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_txn_country",csTmp);
		}

		sprintf(csTag,"posted_baid_txn_country_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_txn_country",csTmp);
		}

		sprintf(csTag,"txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"txn_ccy",csTmp);
		}

		sprintf(csTag,"posted_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_txn_ccy",csTmp);
		}

		sprintf(csTag,"baid_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_txn_ccy",csTmp);
		}

		sprintf(csTag,"posted_baid_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_txn_ccy",csTmp);
		}

		sprintf(csTag,"cr_dr_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"cr_dr",csTmp);
		}

		sprintf(csTag,"bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"org_bank_acct_type",csTmp);
			PutField_CString(hOut,"bank_acct_type",csTmp);
		}

		sprintf(csTag,"baid_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_bank_acct_type",csTmp);
			PutField_CString(hOut,"bank_acct_type",csTmp); //override bank_acct_type
		}

		sprintf(csTag,"posted_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_bank_acct_type",csTmp);
		}

		sprintf(csTag,"posted_baid_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_bank_acct_type",csTmp);
		}

		sprintf(csTag,"baid_type_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_type",csTmp);
		}

		sprintf(csTag,"txn_amt_%d",iIdx);
		if(GetField_Double(hIn,csTag,&dTmp)){
			PutField_Double(hOut,"txn_amt",dTmp);
		}

		sprintf(csTag,"baid_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,csTag,&dTmp)){
			PutField_Double(hOut,"baid_txn_amt",dTmp);
		}

		sprintf(csTag,"posted_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,csTag,&dTmp)){
			PutField_Double(hOut,"posted_txn_amt",dTmp);
		}

		sprintf(csTag,"posted_baid_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,csTag,&dTmp)){
			PutField_Double(hOut,"posted_baid_txn_amt",dTmp);
		}
	}

	else if(!strcmp(csMode,PD_SINGLE_TO_MULTIPLE)){
		sprintf(csTag,"txn_id_%d",iIdx);
		if(GetField_CString(hIn,"txn_id",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_txn_id_%d",iIdx);
		if(GetField_CString(hIn,"baid_txn_id",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_txn_id_%d",iIdx);
		if(GetField_CString(hIn,"posted_txn_id",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_baid_txn_id_%d",iIdx);
		if(GetField_CString(hIn,"posted_baid_txn_id",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid",csTmp);
		}

		sprintf(csTag,"baid_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"baid_baid",csTmp);
		}

		sprintf(csTag,"posted_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid",csTmp);
		}

		sprintf(csTag,"posted_baid_baid_%d",iIdx);
		if(GetField_CString(hIn,csTag,&csTmp)){
			PutField_CString(hOut,"posted_baid_baid",csTmp);
		}

		sprintf(csTag,"txn_code_%d",iIdx);
		if(GetField_CString(hIn,"txn_code",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_txn_code_%d",iIdx);
		if(GetField_CString(hIn,"baid_txn_code",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_txn_code_%d",iIdx);
		if(GetField_CString(hIn,"posted_txn_code",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_baid_txn_code_%d",iIdx);
		if(GetField_CString(hIn,"posted_baid_txn_code",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"txn_country_%d",iIdx);
		if(GetField_CString(hIn,"txn_country",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_txn_country_%d",iIdx);
		if(GetField_CString(hIn,"baid_txn_country",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_txn_country_%d",iIdx);
		if(GetField_CString(hIn,"posted_txn_country",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_baid_txn_country_%d",iIdx);
		if(GetField_CString(hIn,"posted_baid_txn_country",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,"txn_ccy",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,"baid_txn_ccy",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,"posted_txn_ccy",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_baid_txn_ccy_%d",iIdx);
		if(GetField_CString(hIn,"posted_baid_txn_ccy",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"cr_dr_%d",iIdx);
		if(GetField_CString(hIn,"cr_dr",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,"bank_acct_type",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,"baid_bank_acct_type",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,"posted_bank_acct_type",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"posted_baid_bank_acct_type_%d",iIdx);
		if(GetField_CString(hIn,"posted_baid_bank_acct_type",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"baid_type_%d",iIdx);
		if(GetField_CString(hIn,"baid_type",&csTmp)){
			PutField_CString(hOut,csTag,csTmp);
		}

		sprintf(csTag,"txn_amt_%d",iIdx);
		if(GetField_Double(hIn,"txn_amt",&dTmp)){
			PutField_Double(hOut,csTag,dTmp);
		}

		sprintf(csTag,"baid_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,"baid_txn_amt",&dTmp)){
			PutField_Double(hOut,csTag,dTmp);
		}

		sprintf(csTag,"posted_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,"posted_txn_amt",&dTmp)){
			PutField_Double(hOut,csTag,dTmp);
		}

		sprintf(csTag,"posted_baid_txn_amt_%d",iIdx);
		if(GetField_Double(hIn,"posted_baid_txn_amt",&dTmp)){
			PutField_Double(hOut,csTag,dTmp);
		}
	}

	else{
		//do nothing
	}

}



int	GetTxnDetail(const char* csLevel, const char* csTxnId, hash_t* hTxn, const int iIsPostedTxn)
{
	int	iRet = PD_OK;
	char	*csTmp;
	double	dTmp = 0.0;

	hash_t	*hRec;
	recordset_t	*rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hash_t	*hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);

	hash_t	*hBaidTxn;
	hBaidTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBaidTxn, 0);

DEBUGLOG(("GetTxnDetail:: in [%s] Level\n",csLevel));
	if(!strcmp(csLevel,PD_TXN_HEADER_LEVEL)){

		if(iIsPostedTxn) PutField_CString(hTxn,"posted_txn_id",csTxnId);
		else             PutField_CString(hTxn,"txn_id",csTxnId);

		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csTxnId,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"txn_code",&csTmp)){
					if(iIsPostedTxn) PutField_CString(hTxn,"posted_txn_code",csTmp);
					else		 PutField_CString(hTxn,"txn_code",csTmp);
DEBUGLOG(("GetTxnDetail:: txn_code [%s]\n",csTmp));
				}
				if(GetField_Double(hRec,"txn_amt",&dTmp)){
					if(iIsPostedTxn) PutField_Double(hTxn,"posted_txn_amt",dTmp);
					else		 PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("GetTxnDetail:: txn_amt [%lf]\n",dTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
		if ((*DBObjPtr)(csTxnId,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"txn_country",&csTmp)){
					if(iIsPostedTxn) PutField_CString(hTxn,"posted_txn_country",csTmp);
					else		 PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("GetTxnDetail:: txn_country [%s]\n",csTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","GetTxnPspDetail");
		if ((*DBObjPtr)(csTxnId,hTmp) == PD_OK) {
			if(GetField_CString(hTmp,"psp_id",&csTmp)){
DEBUGLOG(("GetTxnDetail:: psp_id [%s]\n",csTmp));
				DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
				if((unsigned long)(*DBObjPtr)(csTmp, hTmp)==PD_OK){
					if(GetField_CString(hTmp,"bank_acct_type",&csTmp)){
						if(iIsPostedTxn) PutField_CString(hTxn,"posted_bank_acct_type",csTmp);
						else		 PutField_CString(hTxn,"bank_acct_type",csTmp);
DEBUGLOG(("GetTxnDetail:: bank_acct_type [%s]\n",csTmp));
					}
				}
			}
			if(GetField_CString(hTmp,"baid",&csTmp)){
				if(iIsPostedTxn) PutField_CString(hTxn,"posted_baid",csTmp);
				else		 PutField_CString(hTxn,"baid",csTmp);
DEBUGLOG(("GetTxnDetail:: baid [%s]\n",csTmp));
			}
			if(GetField_CString(hTmp,"txn_ccy",&csTmp)){
				if(iIsPostedTxn) PutField_CString(hTxn,"posted_txn_ccy",csTmp);
				else		 PutField_CString(hTxn,"txn_ccy",csTmp);
DEBUGLOG(("GetTxnDetail:: txn_ccy [%s]\n",csTmp));
			}
		}

	}

	else if(!strcmp(csLevel,PD_BAID_TXN_LEVEL)){

		if(iIsPostedTxn) PutField_CString(hTxn,"posted_baid_txn_id",csTxnId);
		else             PutField_CString(hTxn,"baid_txn_id",csTxnId);

		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
                if((unsigned long)(*DBObjPtr)(csTxnId, hBaidTxn)==PD_OK){
			if(GetField_CString(hBaidTxn,"txn_code",&csTmp)){
				if(iIsPostedTxn) PutField_CString(hTxn,"posted_baid_txn_code",csTmp);
				else		 PutField_CString(hTxn,"baid_txn_code",csTmp);
DEBUGLOG(("GetTxnDetail:: baid_txn_code [%s]\n",csTmp));
			}
			if(GetField_CString(hBaidTxn,"pid",&csTmp)){
				hash_init(hTmp, 0);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
				if((unsigned long)(*DBObjPtr)(csTmp, hTmp)==PD_OK){
					if(GetField_CString(hTmp,"bank_acct_type",&csTmp)){
						if(iIsPostedTxn) PutField_CString(hTxn,"posted_baid_bank_acct_type",csTmp);
						else		 PutField_CString(hTxn,"baid_bank_acct_type",csTmp);
DEBUGLOG(("GetTxnDetail:: baid_bank_acct_type [%s]\n",csTmp));
					}
				}
			}
			if(GetField_CString(hBaidTxn,"baid",&csTmp)){
				if(iIsPostedTxn) PutField_CString(hTxn,"posted_baid_baid",csTmp);
				else		 PutField_CString(hTxn,"baid_baid",csTmp);
DEBUGLOG(("GetTxnDetail:: baid_baid [%s]\n",csTmp));
			}
		}
	}

	else{
		iRet = PD_ERR;
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(hBaidTxn);
        FREE_ME(hTmp);
DEBUGLOG(("GetTxnDetail() exit iRet = [%d]\n", iRet));
	return iRet;
}


int	RunSpecialAction(const char* csAction, hash_t* hTxn)
{
	int	iRet = PD_TRUE;

	hash_t          *hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	PutField_CString(hTxn,"spc_action",csAction);
DEBUGLOG(("RunSpecialAction:: [%s]\n",csAction));

	DBObjPtr = CreateObj(DBPtr,"DBOLPspTxnSpcAction","GetPspTxnSpcAction");
	if ((*DBObjPtr)(hTxn,rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
DEBUGLOG(("RunSpecialAction() exit iRet = [%d]\n", iRet));
	return iRet;
}


int	DoPostTxn(hash_t* hContext,hash_t* hRequest)
{
	int iRet = PD_OK;
	int iOrgBaidTxn = 0;
	int iPostBaidTxn = 0;
	int iOrgTxn = 0;
	int iPostTxn = 0;
	int iTmp = 0;
	char *csTmp;
	char *csToPostLevel;
	char *csToPostTxnCode;
	char *csUser;

	unsigned char csTmpTxnSeq[PD_TXN_SEQ_LEN +1];
	char csLocalTxnDateTime[PD_DATETIME_LEN+1];
	char csTmDate[PD_DATE_LEN+1];
	char csTmTime[PD_TIME_LEN+1];
	char csTmpDate[PD_DATETIME_LEN +1];

	hash_t          *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("DoPostTxn()\n"));

	//use the org txn?baid txn?post txn?
	if(GetField_Int(hRequest,"org_baid_txn",&iOrgBaidTxn)){
	}
	if(GetField_Int(hRequest,"org_txn",&iOrgTxn)){
	}
	if(GetField_Int(hRequest,"post_baid_txn",&iPostBaidTxn)){
	}
	if(GetField_Int(hRequest,"post_txn",&iPostTxn)){
	}
	
	if(GetField_CString(hRequest,"baid_category",&csTmp)){
	}
	if(GetField_Int(hRequest,"bal_rule_id",&iTmp)){
	}
	if(GetField_Int(hRequest,"af_status_rule_id",&iTmp)){
	}

	if(GetField_CString(hRequest,"to_post_txn_level",&csToPostLevel)){
DEBUGLOG(("DoPostTxn() To post level [%s]\n",csToPostLevel));
	}
	if(GetField_CString(hRequest,"to_post_txn_code",&csToPostTxnCode)){
		PutField_CString(hTxn,"txn_code",csToPostTxnCode);
DEBUGLOG(("DoPostTxn() To post txn_code [%s]\n",csToPostTxnCode));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("DoPostTxn() To post txn_code is missing!!!!!\n"));
	}

	if(GetField_CString(hContext,"add_user",&csUser)){
		PutField_CString(hTxn,"add_user",csUser);
	}

	if(iRet == PD_OK){
		if(!strcmp(csToPostLevel,PD_TXN_HEADER_LEVEL)){
/* Editing*/
/*
			csTmpTxnSeq[0]='\0';
			csLocalTxnDateTime[0]='\0';
			DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
			strcpy((char*)csTmpTxnSeq,(*DBObjPtr)());
			PutField_CString(hTxn,"txn_seq", (const char*)csTmpTxnSeq);
			PutField_Int(hTxn,"do_logging",PD_ADD_LOG);
			PutField_CString(hTxn,"process_code","000000");
			PutField_CString(hTxn,"process_type","0000");
			
			DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");
			if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
				PutField_CString(hTxn,"PHDATE",csTmpDate);
			}
			else{
				iRet = PD_ERR;
			}

			strcpy(csLocalTxnDateTime,getdatetime());
			sprintf(csTmDate,"%.*s",PD_DATE_LEN,csLocalTxnDateTime);
			PutField_CString(hTxn,"local_tm_date",csTmDate);
			sprintf(csTmTime,"%.*s",PD_TIME_LEN,&csLocalTxnDateTime[PD_DATE_LEN]);
			PutField_CString(hTxn,"local_tm_time",csTmTime);

			if(iRet==PD_OK){
				ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
				iRet = (unsigned long)(*ChannelObjPtr)(hTxn,hTxn);
			}

*/
/*
			if(iRet==PD_OK && GetField_Int(hRequest,"af_status_rule_id",&iTmp)){
DEBUGLOG(("DoPostTxn() do update status\n"));
				//get status rule
				hash_init(hTxn,0);
				PutField_CString(hTxn,"txn_seq",csTmpTxnSeq);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnStatusRule", "GetStatusRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do update status
					DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
					if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
						iRet = PD_ERR;
DEBUGLOG(("DoPostTxn() update status failed\n"));
					}
				}
				else{
					iRet = PD_ERR;
DEBUGLOG(("DoPostTxn() status rule not found\n"));
				}
			}
*/
/*

			if(iRet==PD_OK && GetField_Int(hRequest,"bal_rule_id",&iTmp)){
DEBUGLOG(("DoPostTxn() do update balance\n"));
				//get balance rule
				hash_init(hTxn,0);
				PutField_CString(hTxn,"txn_seq",csTmpTxnSeq);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnBalRule", "GetBalRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do update balance
					if(GetField_CString(hTxn,"balance_type",&csBalType) &&
					   GetField_CString(hTxn,"element_type",&csElmType) &&
					   GetField_CString(hTxn,"amt_type",&csAmtType)){
						if(!strcmp(csAmtType,PD_CR))
							cAmtType = PD_IND_CREDIT;
						else
							cAmtType = PD_IND_DEBIT;

						PutField_Cchar(hTxn,"amt_type",cAmtType);
						PutField_CString(hTxn,"pool",csBalType);
						PutField_CString(hTxn,"baid",csBAID);
						PutField_CString(hTxn,"txn_ccy",csCcy);
						PutField_CString(hTxn,"txn_country",csCountry);
						BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
						iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("DoPostTxn() BOOLBalance:UpdateAmount iRet=[%d]\n",iRet));
						if(iRet == PD_OK){
							//update ol_txn_psp_detail
							DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Update");
							iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("DoPostTxn() DBOLTxnPspDetail:Update iRet=[%d]\n",iRet));
						}
						if(iRet == PD_OK){
							//update ol_txn_elements
							PutField_Double(hTxn,"txn_amt",dAmt);
							PutField_CString(hTxn,"txn_element_type",csElmType);
							PutField_CString(hTxn,"amount_type",csAmtType);
							BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddPspTxnElement");
							iRet = (unsigned long)(*BOObjPtr)(hTxn);
DEBUGLOG(("DoPostTxn() DBOLTxnElements:AddPspTxnElement iRet=[%d]\n",iRet));
						}
					}
				}
			}
*/

/*testing*/		PutField_Int(hContext,"posted_txn_cnt",1);
/*testing*/		PutField_CString(hContext,"posted_txn_id","T000000000060342");


		}

		else if(!strcmp(csToPostLevel,PD_BAID_TXN_LEVEL)){


/*testing*/		PutField_Int(hContext,"posted_baid_txn_cnt",1);
/*testing*/		PutField_CString(hContext,"posted_baid_txn_id","A000000000028062");


		}
	}


	FREE_ME(hTxn);
DEBUGLOG(("DoPostTxn() exit iRet = [%d]\n", iRet));
	return iRet; 
}


int	DoUpdateTxn(hash_t* hContext,hash_t* hRequest)
{
	int iRet = PD_OK;
	int iOrgBaidTxn = 0;
	int iPostBaidTxn = 0;
	int iOrgTxn = 0;
	int iPostTxn = 0;
	int iTmp = 0;
	char *csTxnId;
	char *csUser;
	char csLevel[PD_ENGINE_TYPE_LEN+1];

	char *csBAID = NULL;
	char *csCcy = NULL;
	char *csCountry = NULL;
	double dAmt = 0.0;

	char *csBalType;
	char *csElmType;
	char *csAmtType;
	char  cAmtType;

	char cRuleStatus;
	char cRuleArInd;
	char cRuleReconStatus;
	char cRuleClassifiedStatus;
	char *csRuleSubStatus;
	char cStatus = PD_DEFAULT_STATUS;
	char cArInd = PD_DEFAULT_STATUS;
	char cReconStatus = PD_DEFAULT_STATUS;
	char cClassifiedStatus = PD_DEFAULT_STATUS;
	char csSubStatus[PD_SUB_STATUS_LEN];
	sprintf(csSubStatus,PD_DEFAULT_SUB_STATUS);

	hash_t          *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	hash_t          *hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("DoUpdateTxn()\n"));

	//use the org txn?baid txn?post txn?
	GetField_Int(hRequest,"org_baid_txn",&iOrgBaidTxn);
	GetField_Int(hRequest,"org_txn",&iOrgTxn);
	GetField_Int(hRequest,"post_baid_txn",&iPostBaidTxn);
	GetField_Int(hRequest,"post_txn",&iPostTxn);

	if(iOrgBaidTxn){
		if(GetField_CString(hContext,"baid_txn_id",&csTxnId)){
			sprintf(csLevel,"%s",PD_BAID_TXN_LEVEL);
			GetField_Double(hContext,"baid_amt",&dAmt);
			GetField_CString(hContext,"baid_baid",&csBAID);
			GetField_CString(hContext,"baid_txn_ccy",&csCcy);
			GetField_CString(hContext,"baid_txn_ccountry",&csCountry);
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() baid_txn_id id missing!!!!!!\n"));
		}
	}
	else if(iOrgTxn){
		if(GetField_CString(hContext,"txn_id",&csTxnId)){
			sprintf(csLevel,"%s",PD_TXN_HEADER_LEVEL);
			GetField_Double(hContext,"amt",&dAmt);
			GetField_CString(hContext,"baid",&csBAID);
			GetField_CString(hContext,"txn_ccy",&csCcy);
			GetField_CString(hContext,"txn_ccountry",&csCountry);
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() txn_id id missing!!!!!!\n"));
		}
	}
	else if(iPostBaidTxn){
		if(GetField_CString(hContext,"posted_baid_txn_id",&csTxnId)){
			sprintf(csLevel,"%s",PD_BAID_TXN_LEVEL);
			GetField_Double(hContext,"posted_baid_amt",&dAmt);
			GetField_CString(hContext,"posted_baid_baid",&csBAID);
			GetField_CString(hContext,"posted_baid_txn_ccy",&csCcy);
			GetField_CString(hContext,"posted_baid_txn_ccountry",&csCountry);
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() posted_baid_txn_id id missing!!!!!!\n"));
		}
	}
	else if(iPostTxn){
		if(GetField_CString(hContext,"posted_txn_id",&csTxnId)){
			sprintf(csLevel,"%s",PD_TXN_HEADER_LEVEL);
			GetField_Double(hContext,"posted_amt",&dAmt);
			GetField_CString(hContext,"posted_baid",&csBAID);
			GetField_CString(hContext,"posted_txn_ccy",&csCcy);
			GetField_CString(hContext,"posted_txn_ccountry",&csCountry);
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() posted_txn_id id missing!!!!!!\n"));
		}
	}
	else{
DEBUGLOG(("DoUpdateTxn() do nothing\n"));
		iRet = PD_SKIP_OK;
	}
	if(GetField_CString(hContext,"add_user",&csUser)){
		PutField_CString(hTxn,"update_user",csUser);
	}

	//start update (balance, status) if any rule defined
	if(iRet==PD_OK){
		if(!strcmp(csLevel,PD_TXN_HEADER_LEVEL)){
DEBUGLOG(("DoUpdateTxn() [%s][%s]\n",csLevel,csTxnId));
			PutField_CString(hTxn,"org_txn_seq",csTxnId);

			if(GetField_Int(hRequest,"bf_status_rule_id",&iTmp)){
DEBUGLOG(("DoUpdateTxn() do check status\n"));
				//get status rule
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnStatusRule", "GetStatusRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do check status
					DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
					if((unsigned long)(*DBObjPtr)(csTxnId, rRecordSet)==PD_OK){
						hRec = RecordSet_GetFirst(rRecordSet);
						while (hRec) {
							if(GetField_Char(hTxn,"status",&cRuleStatus)){
								GetField_Char(hRec,"status",&cStatus);
								if(cRuleStatus!=cStatus)
									iRet = INT_RECORD_MISMATCH;
							}
							if(GetField_Char(hTxn,"ar_ind",&cRuleArInd)){
								GetField_Char(hRec,"ar_ind",&cArInd);
								if(cRuleArInd!=cArInd)
									iRet = INT_RECORD_MISMATCH;
							}
							if(GetField_CString(hTxn,"sub_status",&csRuleSubStatus)){
								GetField_CString(hRec,"sub_status",&csSubStatus);
								if(strcmp(csRuleSubStatus,csSubStatus))
									iRet = INT_RECORD_MISMATCH;
							}
							if(GetField_Char(hTxn,"recon_status",&cRuleReconStatus)){
								GetField_Char(hRec,"recon_status",&cReconStatus);
								if(cRuleReconStatus!=cReconStatus)
									iRet = INT_RECORD_MISMATCH;
							}
							if(GetField_Char(hTxn,"classified_status",&cRuleClassifiedStatus)){
								GetField_Char(hRec,"classified_status",&cClassifiedStatus);
								if(cRuleClassifiedStatus!=cClassifiedStatus)
									iRet = INT_RECORD_MISMATCH;
							}
							hRec = RecordSet_GetNext(rRecordSet);
						}
						
					}
				}
				else{
					iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() status rule not found\n"));
				}
			}

			if(iRet==PD_OK && GetField_Int(hRequest,"af_status_rule_id",&iTmp)){
DEBUGLOG(("DoUpdateTxn() do update status\n"));
				//get status rule
				hash_init(hTxn,0);
				PutField_CString(hTxn,"txn_seq",csTxnId);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnStatusRule", "GetStatusRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do update status
					DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
					if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
						iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() update status failed\n"));
					}
				}
				else{
					iRet = PD_ERR;
DEBUGLOG(("DoUpdateTxn() status rule not found\n"));
				}
			}

			if(iRet==PD_OK && GetField_Int(hRequest,"bal_rule_id",&iTmp)){
DEBUGLOG(("DoUpdateTxn() do update balance\n"));
				//get balance rule
				hash_init(hTxn,0);
				PutField_CString(hTxn,"txn_seq",csTxnId);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnBalRule", "GetBalRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do update balance
					if(GetField_CString(hTxn,"balance_type",&csBalType) &&
					   GetField_CString(hTxn,"element_type",&csElmType) &&
					   GetField_CString(hTxn,"amt_type",&csAmtType)){
						if(!strcmp(csAmtType,PD_CR))
							cAmtType = PD_IND_CREDIT;
						else
							cAmtType = PD_IND_DEBIT;

						PutField_Char(hTxn,"amt_type",cAmtType);
						PutField_CString(hTxn,"pool",csBalType);
						PutField_CString(hTxn,"baid",csBAID);
						PutField_CString(hTxn,"txn_ccy",csCcy);
						PutField_CString(hTxn,"txn_country",csCountry);
						BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
						iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("DoUpdateTxn() BOOLBalance:UpdateAmount iRet=[%d]\n",iRet));
						if(iRet == PD_OK){
							//update ol_txn_psp_detail
							DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Update");
							iRet = (unsigned long)(*DBObjPtr)(hTxn);
DEBUGLOG(("DoUpdateTxn() DBOLTxnPspDetail:Update iRet=[%d]\n",iRet));
						}
						if(iRet == PD_OK){
							//update ol_txn_elements
							PutField_Double(hTxn,"txn_amt",dAmt);
							PutField_CString(hTxn,"txn_element_type",csElmType);
							PutField_CString(hTxn,"amount_type",csAmtType);
							BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddPspTxnElement");
							iRet = (unsigned long)(*BOObjPtr)(hTxn);
DEBUGLOG(("DoUpdateTxn() DBOLTxnElements:AddPspTxnElement iRet=[%d]\n",iRet));
						}
					}
				}
			}


		}
		else{ //BAID_TXN_LEVEL
DEBUGLOG(("DoUpdateTxn() [%s][%s]\n",csLevel,csTxnId));
			PutField_CString(hTxn,"txn_seq",csTxnId);

			if(GetField_Int(hRequest,"bf_status_rule_id",&iTmp)){
DEBUGLOG(("DoUpdateTxn() do check status\n"));
				//get status rule
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnStatusRule", "GetStatusRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do check status
				}
			}

			if(iRet==PD_OK && GetField_Int(hRequest,"af_status_rule_id",&iTmp)){
DEBUGLOG(("DoUpdateTxn() do update status\n"));
				//get status rule
				hash_init(hTxn,0);
				DBObjPtr = CreateObj(DBPtr, "DBOLPspTxnStatusRule", "GetStatusRule");
				if((unsigned long)(*DBObjPtr)(iTmp, hTxn)==PD_OK){
					//do update status
				}
			}
		}
	}

	if(iRet==PD_SKIP_OK)
		iRet = PD_OK;

	FREE_ME(hTxn);

DEBUGLOG(("DoUpdateTxn() exit iRet = [%d]\n", iRet));
	return iRet; 
}
