/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/29              Dirk Wong
Support 4 txn type				   2015/07/24		   Dirk Wong
Update API
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsBCN.h"
#include "myrecordset.h"
#include <math.h>

char cDebug;

OBJPTR(DB);
OBJPTR(BO);

int ProcessToTxn(char *csFromTxnSeq,hash_t *hToTxn);

void TxnMmmByUsBCN(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	i = 0;

	char*	csTmp = NULL;
	char*	csPtr;
	char    csTag[PD_TAG_LEN + 1];
	char	cTmp;
	int	iTmp = 0;
	double	dTmp = 0.0;

	char*	csTxnCcy;
	double	dTxnAmt;

	char*	csTxnEntityId;
	char*	csTxnNatureId;
	char	cTxnAmtType;
	int	iTxnBalCnt;

	char*	csDstEntityId;
	char*	csDstNatureId;
	char	cDstAmtType;
	int	iDstBalCnt;

//	int	iTxnAction, iDstAction;

	hash_t 	*hFromTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hFromTxn,0);

	hash_t *hToTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hToTxn,0);


DEBUGLOG(("Authorize()\n"));

// txn_ccy
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"txn_ccy",&csTxnCcy)) {
			PutField_CString(hFromTxn,"from_ccy",csTxnCcy);
			PutField_CString(hFromTxn,"ccy",csTxnCcy);
			PutField_CString(hToTxn,"from_ccy",csTxnCcy);
			PutField_CString(hToTxn,"ccy",csTxnCcy);
DEBUGLOG(("Authorize: txn_ccy = [%s]\n",csTxnCcy));
		} else {
DEBUGLOG(("Authorize:: txn_ccy missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_ccy missing!!\n");
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// txn_amt
	if (iRet == PD_OK) {
		if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
			PutField_Double(hFromTxn,"txn_amt",dTxnAmt);
			PutField_Double(hToTxn,"txn_amt",dTxnAmt);
DEBUGLOG(("Authorize: txn_amt = [%f]\n",dTxnAmt));
		} else {
DEBUGLOG(("Authorize:: txn_amt missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_amt missing!!\n");
			iRet = INT_TXN_AMT_MISSING;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// create_user 
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"user",&csTmp)) {
			PutField_CString(hFromTxn,"user",csTmp);
			PutField_CString(hFromTxn,"add_user",csTmp);
			PutField_CString(hFromTxn,"update_user",csTmp);
			PutField_CString(hToTxn,"user",csTmp);
			PutField_CString(hToTxn,"add_user",csTmp);
			PutField_CString(hToTxn,"update_user",csTmp);
			PutField_CString(hContext,"update_user",csTmp);
DEBUGLOG(("Authorize: create_user = [%s]\n",csTmp));
		} else {
DEBUGLOG(("Authorize:: user missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: user missing!!\n");
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// txn_data.eid (entity_id) 
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"entity_id",&csTxnEntityId)) {
DEBUGLOG(("Authorize: txn_data.eid = [%s]\n",csTxnEntityId));
		} else {
DEBUGLOG(("Authorize:: txn_data.eid missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_data.eid missing!!\n");
			iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// txn_data.bal_cnt
	if (iRet == PD_OK) {
		if (GetField_Int(hContext,"bal_cnt",&iTxnBalCnt)) {
DEBUGLOG(("Authorize: txn_data.bal_cnt = [%d]\n",iTxnBalCnt));
		} else {
DEBUGLOG(("Authorize:: txn_data.bal_cnt missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_data.bal_cnt missing!!\n");
			iRet = INT_MMS_BAL_CNT_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// dst_data.eid (entity_id) 
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"dst_data.entity_id",&csDstEntityId)) {
DEBUGLOG(("Authorize: dst_data.eid = [%s]\n",csDstEntityId));
		} else {
DEBUGLOG(("Authorize:: dst_data.eid missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: dst_data.eid missing!!\n");
			iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// dst_data.bal_cnt 
	if (iRet == PD_OK) {
	        if (GetField_CString(hRequest,"dst_data.bal_cnt",&csTmp)) {
	                iDstBalCnt = atoi(csTmp);
DEBUGLOG(("Authorize: dst_data.bal_cnt = [%d]\n",iDstBalCnt));
	        } else {
DEBUGLOG(("Authorize:: dst_data.bal_cnt missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: dst_data.bal_cnt missing!!\n");
	                iRet = INT_MMS_BAL_CNT_NOT_FOUND;
	                PutField_Int(hContext,"internal_error",iRet);
	        }
	}

	if (iRet == PD_OK) {
		if (strcmp(csTxnEntityId,csDstEntityId) != 0) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} else if (iTxnBalCnt != iDstBalCnt) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// get txn_data.nature_id
	if (iRet == PD_OK) {
                for (i=1; i<=iTxnBalCnt; i++) {
			sprintf(csTag,"bal.%d.nature_id",i);
                        if (GetField_CString(hContext,csTag,&csTxnNatureId)) {
				PutField_CString(hContext,"nature_id",csTxnNatureId);
DEBUGLOG(("Authorize: txn_data.nature_id = [%s]\n",csTxnNatureId));
			} else {
DEBUGLOG(("Authorize:: txn_data.nature_id missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_data.nature_id missing!!\n");
         		       	iRet = INT_MMS_NATURE_ID_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
				break;
        		}

			//amt_type
			if (iRet == PD_OK) {
				sprintf(csTag,"txn_data.bal.%d.amt_type",i);
				if (GetField_CString(hRequest,csTag,&csTmp)) {
					cTxnAmtType = csTmp[0];
DEBUGLOG(("Authorize:: txn_data.bal.amt_type = [%c]\n",cTxnAmtType));
				} else {
DEBUGLOG(("Authorize:: txn_data.bal.amt_type missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: txn_data.bal.amt_type missing!!\n");
					iRet = INT_AMT_TYPE_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
					break;
				}
			}
		}
	}

// get dst_data.nature_id
	if (iRet == PD_OK) {
		hash_t  *hTmpData;
		hTmpData = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTmpData,0);

		int j=0;

		PutField_Int(hTmpData,"bal_cnt",iDstBalCnt);

                for (i=1; i<=iDstBalCnt; i++) {
			sprintf(csTag,"dst_data.bal.%d.nat_cnt",i);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				iTmp = atoi(csTmp);

				sprintf(csTag,"bal.%d.nat_cnt",i);
				PutField_Int(hTmpData,csTag,iTmp);

				for (j=0; j<iTmp; j++) {
					sprintf(csTag,"dst_data.bal.%d.nat.%d.grp",i,j+1);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
						sprintf(csTag,"bal.%d.nat.%d.grp",i,j+1);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						PutField_CString(hTmpData,csTag,csPtr);
					}

					sprintf(csTag,"dst_data.bal.%d.nat.%d.val",i,j+1);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
						sprintf(csTag,"bal.%d.nat.%d.val",i,j+1);
DEBUGLOG(("GetSrcNatureId() [%s] = [%s]\n",csTag,csPtr));
						PutField_CString(hTmpData,csTag,csPtr);
					}
				}

/* this call will return an new nature id if not found */
				BOObjPtr = CreateObj(BOPtr,"BOMMSEntityNature","FindEntityNatureId");
				iRet =  (unsigned long)(*BOObjPtr)(hTmpData);
				if (iRet != PD_OK) {
DEBUGLOG(("GetSrcNatureId() return from BOMMSEntityNature iRet = [%d] \n",iRet));
					break;
				}
			}


			sprintf(csTag,"bal.%d.nature_id",i);
                        if (GetField_CString(hTmpData,csTag,&csDstNatureId)) {
DEBUGLOG(("Authorize: dst_data.nature_id = [%s]\n",csDstNatureId));
			} else {
DEBUGLOG(("Authorize:: dst_data.nature_id missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: dst_data.nature_id missing!!\n");
         		       	iRet = INT_MMS_NATURE_ID_NOT_FOUND;
                		PutField_Int(hContext,"internal_error",iRet);
				break;
			}

			//amt_type
			if (iRet == PD_OK) {
				sprintf(csTag,"dst_data.bal.%d.amt_type",i);
				if (GetField_CString(hRequest,csTag,&csTmp)) {
					cDstAmtType = csTmp[0];
DEBUGLOG(("Authorize:: dst_data.bal.amt_type = [%c]\n",cDstAmtType));
				} else {
DEBUGLOG(("Authorize:: dst_data.bal.amt_type missing!!\n"));
ERRLOG("TxnMmsByUsBCN:: Authorize:: dst_data.bal.amt_type missing!!\n");
					iRet = INT_AMT_TYPE_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
					break;
				}
			}
	}

		hash_destroy(hTmpData);
		FREE_ME(hTmpData);
	}


//Get Acct Balance for nature(from-side)
	if (iRet == PD_OK) {
		hash_t* hTmp;
		hTmp = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hTmp,0);

		if (GetField_CString(hContext,"entity_id",&csTmp)) {
			PutField_CString(hTmp,"entity_id",csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

		if (GetField_CString(hContext,"nature_id",&csTmp)) {
			PutField_CString(hTmp,"nature_id",csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

		if (GetField_CString(hContext,"txn_ccy",&csTmp)) {
			PutField_CString(hTmp,"ccy",csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

DEBUGLOG(("Authorize:: Call BOMMSEntityBalance::SelectNatureBalanceForUpdate\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMMSEntityBalance","SelectNatureBalanceForUpdate");
		iRet = (unsigned long)(*BOObjPtr)(hTmp);
DEBUGLOG(("Authorize:: iRet [%d] from Call BOMMSEntityBalance::SelectNatureBalanceForUpdate\n",iRet));
		if (iRet == PD_OK) {
			int iDtlRet = PD_FALSE;

			//Check txn amt <= acct_bal
			if (GetField_Double(hTmp,"open_acct_bal",&dTmp)) {
				if (dTmp > 0) {
					if (cTxnAmtType == PD_IND_CREDIT && cDstAmtType == PD_IND_DEBIT) {
						if (dTxnAmt <= dTmp) {
							iDtlRet = PD_TRUE;
						}
					}
				} else if (dTmp < 0) {
					if (cTxnAmtType == PD_IND_DEBIT && cDstAmtType == PD_IND_CREDIT) {
						if (dTxnAmt <= fabs(dTmp)) {
							iDtlRet = PD_TRUE;
						}
					}
				}
			}

			if (iDtlRet == PD_FALSE) {
DEBUGLOG(("Authorize:: INT_ERR: amt_type ERROR or txn_amt ERROR\n"));
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

		FREE_ME(hTmp);
	}


//txn_data natureID Action
	if (iRet == PD_OK) {
		PutField_CString(hFromTxn,"nature_id",csTxnNatureId);

		if (cTxnAmtType == PD_IND_DEBIT) {
			sprintf(csTmp, "%s", "CreditAcctBal");
		} else {
			sprintf(csTmp, "%s", "DebitAcctBal");
		}

DEBUGLOG(("Authorize:: Call BOMMSEntityBalance::%s\n",csTmp));
		BOObjPtr = CreateObj(BOPtr, "BOMMSEntityBalance",csTmp);
		iRet = (unsigned long)(*BOObjPtr)(hContext,hFromTxn);
DEBUGLOG(("Authroize:: iRet [%d] from Call BOMMSEntityBalance::%s\n",iRet,csTmp))
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}



//Add new txn log
	char csNewTxnSeq[PD_TXN_SEQ_LEN +1];

	if (iRet == PD_OK) {
		PutField_Int(hToTxn,"do_logging",PD_ADD_LOG);

		//Get new txn_seq
DEBUGLOG(("Authorize() Call DBTxnSeq::GetNextMmmTxnSeq()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
		strcpy(csNewTxnSeq,(*DBObjPtr)());
		PutField_CString(hToTxn,"txn_seq",csNewTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csNewTxnSeq));

		//fill hToTxn
		if (GetField_CString(hContext,"txn_seq",&csTmp)) {
			PutField_CString(hToTxn,"related_txn_id",csTmp);
		}
		if (GetField_CString(hContext,"channel_code",&csTmp)) {
			PutField_CString(hToTxn,"channel_code",csTmp);
		}
		if (GetField_CString(hContext,"PHDATE",&csTmp)) {
			PutField_CString(hToTxn,"PHDATE",csTmp);
		}
		if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
			PutField_CString(hToTxn,"local_tm_date",csTmp);
		}
		if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
			PutField_CString(hToTxn,"local_tm_time",csTmp);
		}
		if (GetField_CString(hContext,"process_type",&csTmp)) {
			PutField_CString(hToTxn,"process_type",csTmp);
		}
		if (GetField_CString(hContext,"process_code",&csTmp)) {
			PutField_CString(hToTxn,"process_code",csTmp);
		}
		if (GetField_CString(hContext,"req_node_id",&csTmp)) {
			PutField_CString(hToTxn,"req_node_id",csTmp);
		}
		if (GetField_CString(hRequest,"node_ref",&csTmp)) {
			PutField_CString(hToTxn,"node_ref",csTmp);
		}
		if (GetField_CString(hRequest,"transmission_datetime",&csTmp)) {
			PutField_CString(hToTxn,"transmission_datetime",csTmp);
		} else if (GetField_CString(hContext,"transmission_datetime",&csTmp )) {
			PutField_CString(hToTxn,"transmission_datetime",csTmp);
		}
		if (GetField_CString(hRequest,"tm_date",&csTmp)) {
			PutField_CString(hToTxn,"tm_date",csTmp);
		} else if (GetField_CString(hContext,"tm_date",&csTmp)) {
			PutField_CString(hToTxn,"tm_date",csTmp);
		}
		if (GetField_CString(hRequest,"tm_time",&csTmp)) {
			PutField_CString(hToTxn,"tm_time",csTmp);
		} else if (GetField_CString(hContext,"tm_time",&csTmp)) {
			PutField_CString(hToTxn,"tm_time",csTmp);
		}
		if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
			PutField_CString(hToTxn,"txn_ccy",csTmp);
		}
		if (GetField_CString(hRequest,"txn_country",&csTmp)) {
			PutField_CString(hToTxn,"txn_country",csTmp);
		}
		if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
			PutField_CString(hToTxn,"ip_addr",csTmp);
		}
		if (GetField_CString(hRequest,"remark",&csTmp)) {
			PutField_CString(hToTxn,"remark",csTmp);
		}
		if (GetField_Char(hRequest,"action",&cTmp)) {
			PutField_Char(hToTxn,"action",cTmp);
		}
		if (GetField_CString(hContext,"entity_id",&csTmp)) {
			PutField_CString(hToTxn,"entity_id",csTmp);
		}
		if (GetField_Int(hContext,"bal_cnt",&iTmp)) {
			PutField_Int(hToTxn,"bal_cnt",iTmp);
		}
		for (i = 0 ; i < iTxnBalCnt; i++) {
			sprintf(csTag,"bal.%d.nature_id",i+1);
			PutField_CString(hToTxn,csTag,csDstNatureId);
			sprintf(csTag,"bal.%d.amt",i+1);
			PutField_Double(hToTxn,csTag,dTxnAmt);
		}
			

		//Call BOMMSTransaction::AddTxnLog
DEBUGLOG(("Authorize:: Call BOMMSTransaction::AddTxnLog\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMMSTransaction","AddTxnLog");
		iRet = (unsigned long)(*BOObjPtr)(hToTxn,hToTxn);
DEBUGLOG(("Authroize:: iRet [%d] from Call BOMMSTransaction::AddTxnLog\n",iRet))
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}


	//Credit dst_data natureID
	if (iRet == PD_OK) {

		if (cDstAmtType == PD_IND_CREDIT) {
			sprintf(csTmp, "%s","DebitAcctBal");
		} else {
			sprintf(csTmp, "%s","CreditAcctBal");
		}

DEBUGLOG(("Authorize:: Call BOMMSEntityBalance::%s\n",csTmp));
		BOObjPtr = CreateObj(BOPtr, "BOMMSEntityBalance",csTmp);
		iRet = (unsigned long)(*BOObjPtr)(hToTxn,hToTxn);
DEBUGLOG(("Authroize:: iRet [%d] from Call BOMMSEntityBalance::%s\n",iRet,csTmp))
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}


	//Call BOMMSTransaction::UpdateTxnLog
	if (iRet == PD_OK) {
		PutField_CString(hToTxn,"nature_id",csDstNatureId);

		if (cDstAmtType == PD_IND_CREDIT)
			PutField_CString(hToTxn,"txn_code",PD_TXN_CODE_MMS_NATURE_BAL_IN_DR);
		else
			PutField_CString(hToTxn,"txn_code",PD_TXN_CODE_MMS_NATURE_BAL_IN_CR);

		PutField_Char(hToTxn, "status", PD_COMPLETE);
		PutField_Char(hToTxn, "ar_ind", PD_ACCEPT);
		PutField_CString(hToTxn, "sub_status", PD_COMPLETED);

		if (GetField_Double(hContext,"txn_amt",&dTmp)) {
			PutField_Double(hToTxn,"txn_amt",dTmp);
		}
		if (GetField_Double(hContext,"remaining_amt",&dTmp)) {
			PutField_Double(hToTxn,"remaining_amt",dTmp);
		}
		if (GetField_Double(hContext,"net_amt",&dTmp)) {
			PutField_Double(hToTxn,"net_amt",dTmp);
		}
		if (GetField_CString(hContext,"net_ccy",&csTmp)) {
			PutField_CString(hToTxn,"net_ccy",csTmp);
		}
		if (GetField_Double(hContext,"cost_rate",&dTmp)) {
			PutField_Double(hToTxn,"cost_rate",dTmp);
		}
		if (GetField_Double(hContext,"cost_flat_rate",&dTmp)) {
			PutField_Double(hToTxn,"cost_flat_rate",dTmp);
		}
		if (GetField_Double(hContext,"cost_amt",&dTmp)) {
			PutField_Double(hToTxn,"cost_amt",dTmp);
		}
		sprintf(csTmp, "%d", PD_OK);
		PutField_CString(hToTxn,"response_code",csTmp);
		PutField_Int(hToTxn,"internal_error",PD_OK);

		//Call BOMMSTransaction::UpdateTxnLog
DEBUGLOG(("Authorize:: Call BOMMSTransaction::UpdateTxnLog\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMMSTransaction","UpdateTxnLog");
		iRet = (unsigned long)(*BOObjPtr)(hToTxn,hToTxn);
DEBUGLOG(("Authroize:: iRet [%d] from Call BOMMSTransaction::UpdateTxnLog\n",iRet))
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {
		if (cTxnAmtType == PD_IND_DEBIT)
			PutField_CString(hContext,"txn_code",PD_TXN_CODE_MMS_NATURE_BAL_OUT_CR);
		else
			PutField_CString(hContext,"txn_code",PD_TXN_CODE_MMS_NATURE_BAL_OUT_DR);

		PutField_CString(hContext,"sub_status",PD_COMPLETED);
		PutField_CString(hContext,"related_txn_id",csNewTxnSeq);
	}

	// Response
        PutField_Int(hResponse,"ret",iRet);
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"txn_seq",&csTmp)) {
			PutField_CString(hResponse,"txn_seq",csTmp);
			PutField_CString(hResponse,"related_txn_seq",csNewTxnSeq);
		}
	}

	hash_destroy(hFromTxn);
	hash_destroy(hToTxn);
	FREE_ME(hToTxn);
	FREE_ME(hFromTxn);

DEBUGLOG(("TxnMmsByUsBCN Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

