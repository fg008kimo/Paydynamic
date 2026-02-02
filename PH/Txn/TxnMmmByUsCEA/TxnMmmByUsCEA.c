/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/23              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsCEA.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(BO);

void TxnMmmByUsCEA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iEtypeCnt = 0;
	int	i = 0;
	int	iTmp = 0;

	char	cAction;
	char	cTmp;

	char*   csCode = NULL;
	char*   csUser = NULL;
	char*   csTmp = NULL;

	char    csTag[PD_TAG_LEN + 1];

	hash_t  *hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	cAction = ' ';
	cTmp = ' ';

DEBUGLOG(("Authorize()\n"));

/* action */
	if (GetField_Char(hRequest,"action",&cAction)) {
		PutField_Char(hData,"action",cAction);
DEBUGLOG(("Authorize: action = [%c]\n",cAction));
	} else {
DEBUGLOG(("Authorize:: action missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: action missing!!\n");
		iRet = INT_ACTION_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* code */
        if (GetField_CString(hRequest,"type_data.code",&csCode)) {
		PutField_CString(hData,"code",csCode);
DEBUGLOG(("Authorize: code = [%s]\n",csCode));
        } else {
		if (cAction != PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: code missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: code missing!!\n");
                	iRet = INT_MMS_TXN_CODE_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* name */
	if (GetField_CString(hRequest,"type_data.name",&csTmp)) {
		PutField_CString(hData,"desc",csTmp);
DEBUGLOG(("Authorize: name = [%s]\n",csTmp));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: name missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: name missing!!\n");
                	iRet = INT_MMS_TXN_CODE_DESC_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* etype_cnt */
	if (GetField_CString(hRequest,"type_data.etype_cnt",&csTmp)) {
                //iEtypeCnt = atoi(csTmp);
		iEtypeCnt = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
		PutField_Int(hData,"etype_cnt",iEtypeCnt);
DEBUGLOG(("Authorize: etype_cnt = [%d]\n",iEtypeCnt));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: etype_cnt missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: etype_cnt missing!!\n");
                	iRet = INT_MMS_ADJ_ETYPE_CNT_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

	if (iRet == PD_OK) {

                // Get Adj Etype and Adj Etype Action 
               	for (i=1; i<=iEtypeCnt; i++)
                {
/* et */
			sprintf(csTag,"type_data.etype.%d.et",i);
                        if (GetField_CString(hRequest,csTag,&csTmp)) {
				sprintf(csTag,"etype.%d.et",i);
				PutField_CString(hData,csTag,csTmp);
DEBUGLOG(("Authorize: et_%d = [%s]\n",i,csTmp));
			} else {
				if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: et missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: et missing!!\n");
                			iRet = INT_MMS_ADJ_ETYPE_NOT_FOUND;
                			PutField_Int(hContext,"internal_error",iRet);
				}
			}

/* et_action */
			sprintf(csTag,"type_data.etype.%d.et_action",i);
                        if (GetField_CString(hRequest,csTag,&csTmp)) {
                                sprintf(csTag,"etype.%d.et_action",i);
				cTmp = csTmp[0];
                                PutField_Char(hData,csTag,cTmp);
DEBUGLOG(("Authorize: et_action_%d = [%c]\n",i,cTmp));
                        } else {
                                if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: et_action missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: et_action missing!!\n");
                                        iRet = INT_MMS_ADJ_ETYPE_ACTION_NOT_FOUND;
                                        PutField_Int(hContext,"internal_error",iRet);
                                }
                        }
		}
	}

/* amt_type */
	if (GetField_CString(hRequest,"type_data.amt_type",&csTmp)) {
		PutField_CString(hData,"amt_type",csTmp);
DEBUGLOG(("Authorize: amt_type = [%s]\n",csTmp));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: amt_type missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: amt_type missing!!\n");
               	 	iRet = INT_AMT_TYPE_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }	

/* bal_type */
	if (GetField_CString(hRequest,"type_data.bal_type",&csTmp)) {
		cTmp = csTmp[0];
		PutField_Char(hData,"bal_type",cTmp);
DEBUGLOG(("Authorize: bal_type = [%c]\n",cTmp));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: bal_type missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: bal_type missing!!\n");
                	iRet = INT_MMS_BAL_TYPE_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* adj_nat */
	if (GetField_CString(hRequest,"type_data.adj_nat",&csTmp)) {
		cTmp = csTmp[0];
		PutField_Char(hData,"adj_nat",cTmp);
DEBUGLOG(("Authorize: adj_nat = [%c]\n",cTmp));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: adj_nat missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: adj_nat missing!!\n");
                	iRet = INT_MMS_ADJ_NAT_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* disabled */
	if (GetField_CString(hRequest,"type_data.disabled",&csTmp)) {
                //iTmp = atoi(csTmp);
                iTmp = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
		PutField_Int(hData,"disabled",iTmp);
DEBUGLOG(("Authorize: disabled = [%d]\n",iTmp));
        } else {
		if (cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize:: disabled missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: disabled missing!!\n");
                	iRet = INT_DISABLED_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* user */
	if (GetField_CString(hRequest,"user",&csUser)) {
		PutField_CString(hData,"user",csUser);
DEBUGLOG(("Authorize: user = [%s]\n",csUser));
	} else {
DEBUGLOG(("Authorize:: user missing!!\n"));
ERRLOG("TxnMmsByUsCEA:: Authorize:: user missing!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	// Action: Add/Update/Delete
	if (iRet == PD_OK) {

		memset(csTag, 0, sizeof(csTag));
                switch (cAction) {
                        case PD_ACTION_ADD:
                                sprintf(csTag, "%s", "AddAdjustmentType");
                                break;
                        case PD_ACTION_UPDATE:
                                sprintf(csTag, "%s", "UpdateAdjustmentType");
                                break;
                        case PD_ACTION_DELETE:
                                sprintf(csTag, "%s", "DeleteAdjustmentType");
                                break;
                        default:
                                iRet = INT_MMS_INVALID_ACTION;
                             	PutField_Int(hContext,"internal_error",iRet);
                                break;
                }

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize: %s()\n", csTag));
	
DEBUGLOG(("Authorize:: Call BOMMSAdjustment %s\n", csTag));
                    	BOObjPtr = CreateObj(BOPtr, "BOMMSAdjustment",csTag);
                      	iRet = (unsigned long)(*BOObjPtr)(hContext,hData);
                       	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call BOMMSAdjustment:: Success!!!\n"));
                      	} else {
                             	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call BOMMSAdjustment:: Failure!!!\n"));
ERRLOG("TxnOmtByUsCEA::Authorize::Call BOMMSAdjustment:: Failure!!!\n");
                     	}
		}
	}

	// Update Entity Transaction
	if (iRet == PD_OK) {

/* sub_status */
		PutField_CString(hContext,"sub_status",PD_APPROVED);		

/* user */
               	PutField_CString(hContext,"add_user",csUser);
               	PutField_CString(hContext,"create_user",csUser);
                PutField_CString(hContext,"update_user",csUser);
	}
	
	// Response
	PutField_CString(hResponse,"reply_txn_code",PD_TXN_CODE_MMS_ADJUSTMENT_TYPE);
  	if (GetField_CString(hData,"code",&csCode)) {
		PutField_CString(hResponse,"code",csCode);
	}
	PutField_Int(hResponse,"ret",iRet);
	
	hash_destroy(hData);
        FREE_ME(hData);

DEBUGLOG(("TxnMmsByUsCEA Normal Exit() reply_txn_code = [%s], code = [%s], iRet = [%d]\n",PD_TXN_CODE_MMS_ADJUSTMENT_TYPE,csCode,iRet));
	return iRet;
}
