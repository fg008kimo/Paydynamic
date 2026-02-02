/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/05              Dirk Wong
Add map_txn_element				   2015/12/14		   Dirk Wong
*/	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsEAT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

int ActionMapTxnElement(hash_t *hTmp, char *csTagAction);

void TxnMgtByUsEAT(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	char	*csTmp = NULL;	
	char	*csUser = NULL;
	char	cTmp;
	int	iTmp;

	char	cBalType;
	char	*csTxnCode;

	int	iCurrentCode = -1;

	char	csRtnTxnCode[PD_TXN_CODE_LEN + 1];
	char	csTagAction[PD_TAG_LEN + 1];

	char	csDesc[PD_DESC_LEN + 1];

	char	*csEntityType;
	char	cAction;

	int	iTmpCnt;

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	hash_t  *hStatusMap;
	hStatusMap = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hStatusMap, 0);

	hash_t  *hMapTxnElement;
	hMapTxnElement = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hMapTxnElement, 0);


DEBUGLOG(("TxnMgtByUsEAT::Authorize\n"));

/* entity_type */
	if(GetField_CString(hRequest,"ent_party_type",&csEntityType)){
DEBUGLOG(("Authorize::entity_type = [%s]\n",csEntityType));
		PutField_CString(hTxn, "entity_type", csEntityType);
	}
	else {
DEBUGLOG(("Authorize::entity_type not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::entity_type not found!!\n");
		iRet=INT_MI_ENTITY_TYPE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* amt_type */
	if (GetField_CString(hRequest, "amt_type", &csTmp)) {
DEBUGLOG(("Authorize::amt_type = [%s]\n",csTmp));
		PutField_CString(hTxn, "amt_type", csTmp);
	}
	else {
DEBUGLOG(("Authorize::amt_type not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::amt_type not found!!\n");
		iRet=INT_AMT_TYPE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* desc */
	if (GetField_CString(hRequest, "desc", &csTmp)) {
DEBUGLOG(("Authorize::desc = [%s]\n",csTmp));
		PutField_CString(hTxn, "desc", csTmp);
	}
	else {
DEBUGLOG(("Authorize::desc not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::desc not found!!\n");
		iRet=INT_DESC_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* nature */
	if (GetField_CString(hRequest, "nature", &csTmp)) {
		cTmp = csTmp[0];
DEBUGLOG(("Authorize::nature = [%c]\n",cTmp));
		PutField_Char(hTxn, "nature", cTmp);
	}
	else {
DEBUGLOG(("Authorize::nature not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::nature not found!!\n");
		iRet=INT_NATURE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* bal_type */
	if (GetField_CString(hRequest, "bal_type", &csTmp)) {
		cBalType = csTmp[0];
DEBUGLOG(("Authorize::bal_type = [%c]\n",cBalType));
		PutField_Char(hTxn, "bal_type", cBalType);
	}
	else {
DEBUGLOG(("Authorize::bal_type not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::bal_type not found!!\n");
		iRet=INT_MI_BAL_TYPE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* is_prorata */
	if (GetField_CString(hRequest, "is_prorata", &csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::is_prorata = [%d]\n",iTmp));
		PutField_Int(hTxn, "is_prorata", iTmp);
	}
	else {
DEBUGLOG(("Authorize::is_prorata not found!!\n"));
	}

/* disabled */
	if (GetField_CString(hRequest, "disabled", &csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::disabled = [%d]\n",iTmp));
		PutField_Int(hTxn, "disabled", iTmp);
	}
	else {
DEBUGLOG(("Authorize::disabled not found!!\n"));
	}



/* add_user */
        if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
                PutField_CString(hTxn,"create_user",csUser);
                PutField_CString(hTxn,"update_user",csUser);
                PutField_CString(hMapTxnElement,"create_user",csUser);
        }


/* action - A or U or D */
	if(GetField_CString(hRequest,"action",&csTmp)){
		cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));
		PutField_Char(hTxn, "action", cAction);
	}
	else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::action not found!!\n");
		iRet=INT_ACTION_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}


	PutField_Int(hTxn,"mi_fe_display",PD_TRUE);

/* code */
	if (GetField_CString(hRequest, "code", &csTmp)) {
DEBUGLOG(("Authorize::code = [%s]\n",csTmp));
		PutField_CString(hTxn, "code", csTmp);

		iCurrentCode = atoi(csTmp + 1);
		PutField_Int(hTxn, "code_in_num", iCurrentCode);

DEBUGLOG(("Authorize::CodeInNum = [%d]\n",iCurrentCode));
	}
	else {
DEBUGLOG(("Authorize::Call BOMiAdjustment:GetCurrentCode\n"));
		BOObjPtr = CreateObj(BOPtr,"BOMiAdjustment","GetCurrentCode");
		if((unsigned long)((*BOObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::GetCurrentCode Failed\n"));
ERRLOG("TxnMgtByUsEAT::Authorize::GetCurrentCode Failed\n");
                        iRet=INT_CODE_ERROR;

			PutField_Int(hContext,"internal_error",iRet);
                }

		if (iRet == PD_OK) {
			if (GetField_Int(hTxn, "code_in_num", &iCurrentCode)) {
DEBUGLOG(("Authorize::CurrentCodeInNum [%d]\n", iCurrentCode));

				char*   csEntTypeTmp;
				char*   csValueTmp;

				csEntTypeTmp = (char*) malloc (128);
				csValueTmp = (char*) malloc (128);

				if (!strcmp(csEntityType,PD_MI_ENTITY_RSP)) {
					strcpy(csEntTypeTmp,PD_MI_RSP_ADJ_CODE_PREFIX);
				} else if (!strcmp(csEntityType,PD_MI_ENTITY_OPBANK)) {
					strcpy(csEntTypeTmp,PD_MI_OPB_ADJ_CODE_PREFIX);
				} else if (!strcmp(csEntityType,PD_MI_ENTITY_PSP_INTR)) {
					strcpy(csEntTypeTmp,PD_MI_PIT_ADJ_CODE_PREFIX);
				}

DEBUGLOG(("Authorize:: call SystemParameter:FindCode prefix\n"));
				DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
				if ((unsigned long)(DBObjPtr)(csEntTypeTmp,csValueTmp) == FOUND) {
					cTmp = csValueTmp[0];
DEBUGLOG(("FindCode prefix = [%c]\n",cTmp));
				}

				FREE_ME(csEntTypeTmp);
				FREE_ME(csValueTmp);

				sprintf(csRtnTxnCode, "%c%02d", tolower(cTmp), iCurrentCode);
DEBUGLOG(("Authorize::CurrentCode [%s]\n", csRtnTxnCode));
				PutField_CString(hTxn, "code", csRtnTxnCode);

			}
		}
	}





/* Validate to process while update or delete */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOMiAdjustment:ValidateProcess\n"));
                BOObjPtr = CreateObj(BOPtr,"BOMiAdjustment","ValidateProcess");	
                if((unsigned long)((*BOObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::validateProcess Failed\n"));
/*ERRLOG("TxnMgtByUsEAT::Authorize::ValidateProcess Failed\n");*/
			iRet = INT_PROCESS_VALIDATE_ERROR;

			PutField_Int(hContext,"internal_error",iRet);
		}
	}

/* desc prefix */
	if(cAction == PD_ACTION_ADD){
		if (GetField_CString(hRequest, "desc", &csTmp)) {
			if (strlen(PD_ADJ_DESC_PREFIX) + strlen(csTmp) > PD_DESC_LEN){
				iRet = INT_ADJUSTMENT_PROCESS_ERROR;
				PutField_Int(hContext,"internal_error",iRet);
			}else{
				memset(csDesc, 0, sizeof(csDesc));
				strcpy(csDesc, PD_ADJ_DESC_PREFIX); // "Adjustment - " 
				strncpy(&csDesc[strlen(PD_ADJ_DESC_PREFIX)], csTmp, PD_DESC_LEN - strlen(PD_ADJ_DESC_PREFIX));
				PutField_CString(hTxn, "desc", csDesc);
			}
		}
	}


/* call Add or Update or Delete*/
	if (iRet == PD_OK) {
		memset(csTagAction, 0, sizeof(csTagAction));
		switch (cAction) {
			case PD_ACTION_ADD:
				sprintf(csTagAction, "%s", "Add");
				break;
			case PD_ACTION_UPDATE:
				sprintf(csTagAction, "%s", "Update");
				break;
			case PD_ACTION_DELETE:
				sprintf(csTagAction, "%s", "Delete");
				break;
			default:
				iRet = INT_ERR;
				break;
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::TagAction = [%s]\n", csTagAction));
	                DBObjPtr = CreateObj(DBPtr,"DBMiAdjustmentType", csTagAction);
			if((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize:: FAIL to [%s]\n", csTagAction));
				iRet = INT_ADJUSTMENT_PROCESS_ERROR;
                	} else {
DEBUGLOG(("Authorize:: SUCC to [%s]\n", csTagAction));
			}
		}
	}

	/********************************************/
	/* Include TxnCode, ChannelTxnMap - Normal*/
	if (iRet == PD_OK) {

		/* txn_code */
		if (GetField_CString(hTxn, "code", &csTmp)) {
DEBUGLOG(("Authorize::TxnCode: Txn code = [%s]\n",csTmp));
			PutField_CString(hTxn, "txn_code", csTmp);
			PutField_CString(hMapTxnElement, "txn_code", csTmp);
		}

		/* desc */
		if (GetField_CString(hTxn, "desc", &csTmp)) {
DEBUGLOG(("Authorize::TxnCode: Desc = [%s]\n",csTmp));
		}

		if (cAction == PD_ACTION_ADD) {
			PutField_CString(hTxn, "process_type", "0000");
			PutField_CString(hTxn, "process_code", "000000");

			PutField_Int(hTxn, "apply_fee", PD_FALSE);
			PutField_Int(hTxn, "voidable", PD_TRUE);
			PutField_Int(hTxn, "apply_limit", PD_FALSE);
                        PutField_Int(hTxn, "apply_ex_markup", PD_FALSE);
		}

		// because of foreign key, add and delete is on diff. seq.
                if (iRet == PD_OK) {
			if (cAction == PD_ACTION_ADD || cAction == PD_ACTION_UPDATE)  {
DEBUGLOG(("Authorize::TxnCode: TagAction = [%s]\n", csTagAction));
				DBObjPtr = CreateObj(DBPtr,"DBTxnCode", csTagAction);
				if((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize::TxnCode FAIL to [%s]\n", csTagAction));
					iRet = INT_ADJUSTMENT_PROCESS_ERROR;
				} else {
DEBUGLOG(("Authorize::TxnCode SUCC to [%s]\n", csTagAction));
                		}
			}
		}

                if (iRet == PD_OK) {
                        /* channel_code */
                        PutField_CString(hTxn, "channel_code", PD_CHANNEL_MGT);

                        /* apply_reserved */
                        PutField_Int(hTxn, "apply_reserve", PD_FALSE);

DEBUGLOG(("Authorize::ChannelTxnMap [%s]\n", csTagAction));

                        DBObjPtr = CreateObj(DBPtr,"DBChannelTxnMap", csTagAction);
                        if((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize::ChannelTxnMap FAILED to [%s]\n", csTagAction));
                                iRet = INT_ADJUSTMENT_PROCESS_ERROR;
                        } else {
DEBUGLOG(("Authorize::ChannelTxnMap SUCC to [%s]\n", csTagAction));
                        }

                }

		if (iRet == PD_OK) {
			/*map_txn_element*/
			PutField_CString(hMapTxnElement,"desc","Transaction Amount");

			if (cBalType == PD_MI_ENTITY_POOL_AR_BAL && cAction != PD_ACTION_UPDATE) {
				//Add Overpaid
				PutField_CString(hMapTxnElement,"element",PD_MI_ELEMENT_OVERPAID);
				iRet = ActionMapTxnElement(hMapTxnElement,csTagAction);

				//Add Underpaid
				PutField_CString(hMapTxnElement,"element",PD_MI_ELEMENT_UNDERPAID);
				iRet = ActionMapTxnElement(hMapTxnElement,csTagAction);
			} else if (cBalType == PD_MI_ENTITY_POOL_INTRANSIT && cAction != PD_ACTION_UPDATE) {
				//Add InTransit
				PutField_CString(hMapTxnElement,"element",PD_ELEMENT_IN_TRANSIT);
				iRet = ActionMapTxnElement(hMapTxnElement,csTagAction);
			}
		}
		
		if (iRet == PD_OK) {
			if (cAction == PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::TxnCode: TagAction = [%s]\n", csTagAction));
				DBObjPtr = CreateObj(DBPtr,"DBTxnCode", csTagAction);
				if((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize::TxnCode FAIL to [%s]\n", csTagAction));
					iRet = INT_ADJUSTMENT_PROCESS_ERROR;
				} else {
DEBUGLOG(("Authorize::TxnCode SUCC to [%s]\n", csTagAction));
                		}
			}
		}

	}

	/********************************************/

	if (iRet == PD_OK) {
		// def_txn_status_map

		// Admin / Merchant : txn_code, status, ar_ind, status_desc
		// 1,2) (m/p/y/x)99, C, A, Approved
		// 3,4) (m/p/y/x)99, C, R, Declined
		// 5) (m/p)99, R, A, Approved
		  
		if (cAction == PD_ACTION_ADD) {
			if (GetField_CString(hTxn, "code", &csTxnCode)) {
DEBUGLOG(("Authorize::Prepare TxnStatusMap txn_code [%s]\n", csTxnCode));
			}

			for (iTmpCnt = 0; iTmpCnt < 2; iTmpCnt++) { 
				if (iTmpCnt == 0) {
					PutField_Char(hStatusMap, "type", PD_STATUS_MAP_TYPE_ADMIN);
				} else {
					PutField_Char(hStatusMap, "type", PD_STATUS_MAP_TYPE_MERCH);
				}

				PutField_CString(hStatusMap, "txn_code", csTxnCode);
				PutField_Char(hStatusMap, "status", PD_COMPLETE);
				PutField_Char(hStatusMap, "ar_ind", PD_ACCEPT);


				PutField_CString(hStatusMap, "status_desc", PD_STATUS_MAP_DESC_ACCEPT);
       		         	PutField_CString(hStatusMap,"create_user",csUser);

DEBUGLOG(("Authorize::TxnStatusMap [%d] (1) call Add\n", iTmpCnt));
	                	DBObjPtr = CreateObj(DBPtr,"DBDefTxnStatusMap", "Add");
		                if((unsigned long)((*DBObjPtr)(hStatusMap)) != PD_OK) {
DEBUGLOG(("Authorize::TxnStatusMap [%d] (1) FAIL to Add\n", iTmpCnt)); 
		                        iRet = INT_ADJUSTMENT_PROCESS_ERROR;
					break;
		                } 

				//PutField_CString(hStatusMap, "txn_code", csTxnCode);
				PutField_Char(hStatusMap, "ar_ind", PD_REJECT);
				PutField_CString(hStatusMap, "status_desc", PD_STATUS_MAP_DESC_DECLINED);

DEBUGLOG(("Authorize::TxnStatusMap [%d] (3) call Add\n", iTmpCnt));
                		DBObjPtr = CreateObj(DBPtr,"DBDefTxnStatusMap", "Add");
		                if((unsigned long)((*DBObjPtr)(hStatusMap)) != PD_OK) {
DEBUGLOG(("Authorize::TxnStatusMap [%d] (3) FAIL to Add\n", iTmpCnt));
		                        iRet = INT_ADJUSTMENT_PROCESS_ERROR;
					break;
		                } 

				//PutField_CString(hStatusMap, "txn_code", csTxnCode);
				PutField_Char(hStatusMap, "status", PD_REVERSED);
				PutField_Char(hStatusMap, "ar_ind", PD_ACCEPT);
				PutField_CString(hStatusMap, "status_desc", PD_STATUS_MAP_DESC_ACCEPT);

DEBUGLOG(("Authorize::TxnStatusMap [%d] (5) call Add\n", iTmpCnt));
                		DBObjPtr = CreateObj(DBPtr,"DBDefTxnStatusMap", "Add");
		                if((unsigned long)((*DBObjPtr)(hStatusMap)) != PD_OK) {
DEBUGLOG(("Authorize::TxnStatusMap [%d] (5) FAIL to Add\n", iTmpCnt)); 
		                        iRet = INT_ADJUSTMENT_PROCESS_ERROR;
					break;
		                } 
				
			}
		}
		else if (cAction == PD_ACTION_DELETE) {

			if (GetField_CString(hTxn, "code", &csTxnCode)) {
DEBUGLOG(("Authorize::Prepare TxnStatusMap (delete) txn_code [%s]\n", csTxnCode));
				PutField_CString(hStatusMap, "txn_code", csTxnCode);
			}

DEBUGLOG(("Authorize::TxnStatusMap call Delete txn_code [%s]\n", csTxnCode));
			DBObjPtr = CreateObj(DBPtr,"DBDefTxnStatusMap", "Delete");
			if((unsigned long)((*DBObjPtr)(hStatusMap)) != PD_OK) {
DEBUGLOG(("Authorize::TxnStatusMap FAIL to Delete txn_code[%s]\n", csTxnCode)); 
				iRet = INT_ADJUSTMENT_PROCESS_ERROR;
			} 
		}	
	}

	/********************************************/

/* rtn code */
	if (iRet == PD_OK) {
		if (GetField_CString(hTxn, "code", &csTmp)) {
DEBUGLOG(("Authorize::Rtn Txn code = [%s]\n",csTmp));
			PutField_CString(hResponse, "rtn_code", csTmp);
		}
	}


	hash_destroy(hTxn);
	FREE_ME(hTxn);

	hash_destroy(hStatusMap);
	FREE_ME(hStatusMap);

	hash_destroy(hMapTxnElement);
	FREE_ME(hMapTxnElement);

DEBUGLOG(("TxnMgtByUsEAT Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int ActionMapTxnElement(hash_t *hTmp, char *csTagAction)
{
	int iRet = PD_OK;

DEBUGLOG(("ActionMapTxnElement::Call DBMapTxnElement::[%s]\n", csTagAction));
	DBObjPtr = CreateObj(DBPtr,"DBMapTxnElement", csTagAction);
	if((unsigned long)((*DBObjPtr)(hTmp)) != PD_OK) {
DEBUGLOG(("ActionMapTxnElement:: FAIL to [%s]\n", csTagAction));
		iRet = INT_ERR;
              	} else {
DEBUGLOG(("ActionMapTxnElement:: SUCC to [%s]\n", csTagAction));
	}

	return iRet;
}
