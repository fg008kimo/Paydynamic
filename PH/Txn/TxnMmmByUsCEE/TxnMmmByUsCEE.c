/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/16              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsCEE.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(BO);

void TxnMmmByUsCEE(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csBuf;
	char*	csTmp;
	char	cTmp;
	hash_t	*hData;

	char	cAction;
	char*	csAction;
	char*	csEType = NULL;
	int	iUpdateEntityName = PD_TRUE;

DEBUGLOG(("Authorize()\n"));
	csBuf = (char *)malloc(PD_TMP_BUF_LEN +1);
	csAction = (char *)malloc(PD_TMP_BUF_LEN +1);

	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

// action
	if (iRet == PD_OK) {
		if (GetField_Char(hRequest, "action", &cAction)) {
DEBUGLOG(("Authorize: action = [%c]\n",cAction));
			if (cAction == PD_ACTION_ADD) {
				sprintf(csAction,"%s","AddRecord");
			} else if (cAction == PD_ACTION_UPDATE) {
				sprintf(csAction,"%s","UpdateRecord");
			} else {
DEBUGLOG(("Authorize:: action [%d] not accepted!!\n", cAction));
ERRLOG("TxnMmsByUsCEE:: Authorize:: action not accepted!!\n");
				iRet = INT_MMS_INVALID_ACTION;
				PutField_Int(hContext,"internal_error",iRet);
			}
		} else {
DEBUGLOG(("Authorize:: action not found!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: action not found!!\n");
			iRet = INT_ACTION_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// entity_name (desc) [OPTIONAL]
	if (iRet == PD_OK) {
	 	if (GetField_CString(hRequest,"txn_data.entity_name",&csTmp)) {
DEBUGLOG(("Authorize: entity_name = [%s]\n",csTmp));
			PutField_CString(hData,"desc",csTmp);
		} else {
			iUpdateEntityName = PD_FALSE;
		}
	}

// status
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"txn_data.status",&csTmp)) {
			cTmp = csTmp[0];
DEBUGLOG(("Authorize: status = [%c]\n",cTmp));
			PutField_Char(hData,"status",cTmp);
		} else {
DEBUGLOG(("Authorize:: status missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: status missing!!\n");
			iRet = INT_STATUS_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// create_user
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"user",&csTmp)) {
DEBUGLOG(("Authorize: create_user = [%s]\n",csTmp));
			PutField_CString(hData,"create_user",csTmp);
		}
	}


	if (cAction == PD_ACTION_ADD) {
		// client_id
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.client_id",&csTmp)) {
DEBUGLOG(("Authorize: client_id = [%s]\n",csTmp));
				PutField_CString(hData,"client_id",csTmp);
			} else {
DEBUGLOG(("Authorize:: client_id missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: client_id missing!!\n");
				iRet = INT_MMS_CLIENT_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// etype (entity_type)
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.etype",&csEType)) {
DEBUGLOG(("Authorize: etype = [%s]\n",csEType));
				PutField_CString(hData,"entity_type",csEType);
			} else {
DEBUGLOG(("Authorize:: etype missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: etype missing!!\n");
				iRet = INT_MMS_ENTITY_TYPE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// id (rsp_id / opb_id)
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.id",&csTmp)) {
DEBUGLOG(("Authorize: id = [%s]\n",csTmp));
				PutField_CString(hData,"id",csTmp);
			} else {
DEBUGLOG(("Authorize:: id missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: id missing!!\n");
				iRet = INT_MMS_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

	} else if (cAction == PD_ACTION_UPDATE) {
		// entity_id
		if (iRet == PD_OK) {
			if (GetField_CString(hContext,"entity_id",&csTmp)) {
DEBUGLOG(("Authorize: entity_id = [%s]\n",csTmp));
				PutField_CString(hData,"entity_id",csTmp);
			} else {
DEBUGLOG(("Authorize:: eid missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: eid missing!!\n");
				iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// entity_type
		if (iRet == PD_OK) {
			if (GetField_CString(hContext,"entity_type",&csEType)) {
DEBUGLOG(("Authorize: entity_type = [%s]\n",csEType));
				PutField_CString(hData,"entity_type",csEType);
			} else {
DEBUGLOG(("Authorize:: entity_type NOT FOUND!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: entity_type NOT FOUND!!\n");
				iRet = INT_MMS_ENTITY_TYPE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}


	if (!strcmp(csEType, PD_MMS_ENTITY_RSP)) {
		// node_id
		if (iRet == PD_OK) {

			if (GetField_CString(hRequest,"txn_data.node_id",&csTmp)) {
DEBUGLOG(("Authorize: node_id = [%s]\n",csTmp));
				PutField_CString(hData,"node_id",csTmp);
			} else {
DEBUGLOG(("Authorize:: node_id missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: node_id missing!!\n");
				iRet = INT_MMS_NODE_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// acct_type
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.acct_type",&csTmp)) {
				cTmp = csTmp[0];
DEBUGLOG(("Authorize: acct_type = [%c]\n",cTmp));
				PutField_Char(hData,"acct_type",cTmp);
			} else {
DEBUGLOG(("Authorize:: acct_type missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: acct_type missing!!\n");
				iRet = INT_MMS_ACCT_TYPE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// relate_grp
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.relate_grp",&csTmp)) {
DEBUGLOG(("Authorize: relate_grp = [%s]\n",csTmp));
				PutField_CString(hData,"relate_grp",csTmp);
			} else {
DEBUGLOG(("Authorize:: relate_grp missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: relate_grp missing!!\n");
				iRet = INT_MMS_RELATE_GRP_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

	} else if (!strcmp(csEType, PD_MMS_ENTITY_OP_BANK)) {
		// acct_name
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.acct_name",&csTmp)) {
DEBUGLOG(("Authorize: acct_name = [%s]\n",csTmp));
				PutField_CString(hData,"acct_name",csTmp);
			} else {
DEBUGLOG(("Authorize:: acct_name missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: acct_name missing!!\n");
				iRet = INT_MMS_ACCT_NAME_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// acct_num
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.acct_num",&csTmp)) {
DEBUGLOG(("Authorize: acct_num = [%s]\n",csTmp));
				PutField_CString(hData,"acct_num",csTmp);
			} else {
DEBUGLOG(("Authorize:: acct_num missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: acct_num missing!!\n");
				iRet = INT_MMS_ACCT_NUM_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// acct_holder
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.acct_holder",&csTmp)) {
DEBUGLOG(("Authorize: acct_holder = [%s]\n",csTmp));
				PutField_CString(hData,"acct_holder",csTmp);
			} else {
DEBUGLOG(("Authorize:: acct_holder missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: acct_holder missing!!\n");
				iRet = INT_MMS_ACCT_HOLDER_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}

		// base_ccy
		if (iRet == PD_OK) {
			if (GetField_CString(hRequest,"txn_data.base_ccy",&csTmp)) {
DEBUGLOG(("Authorize: base_ccy = [%s]\n",csTmp));
				PutField_CString(hData,"base_ccy",csTmp);
			} else {
DEBUGLOG(("Authorize:: base_ccy missing!!\n"));
ERRLOG("TxnMmsByUsCEE:: Authorize:: base_ccy missing!!\n");
				iRet = INT_MMS_BASE_CCY_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}


// call BO
	//(1) Check exists
	if (iRet == PD_OK) {
		sprintf(csBuf,"BOMMSEntity%s",csEType);
DEBUGLOG(("Authorize: Call %s::FindRecordExists\n",csBuf));
		BOObjPtr = CreateObj(BOPtr,csBuf,"FindRecordExists");
		iRet = (unsigned long)(*BOObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from %s::FindRecordExists\n",iRet, csBuf));
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	//(2) MmsEntity
	if (iRet == PD_OK) {
		if (iUpdateEntityName) {
DEBUGLOG(("Authorize: Call BOMMSEntity::%s\n",csAction));
			BOObjPtr = CreateObj(BOPtr,"BOMMSEntity",csAction);
			iRet = (unsigned long)(*BOObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from BOMMSEntity::%s\n",iRet,csAction));
			if (iRet != PD_OK) {
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}

	//(3) MmsEntityRsp/MmsEntityOpb
	if (iRet == PD_OK) {
		sprintf(csBuf,"BOMMSEntity%s",csEType);
DEBUGLOG(("Authorize: Call %s::%s\n",csBuf,csAction));
		BOObjPtr = CreateObj(BOPtr,csBuf,csAction);
		iRet = (unsigned long)(*BOObjPtr)(hData);
DEBUGLOG(("Authorize: iRet = [%d] return from %s::%s\n",iRet, csBuf,csAction));
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hData,"entity_id",&csTmp)) {
			PutField_CString(hResponse,"eid",csTmp);
DEBUGLOG(("Authorize: response: eid = [%s]\n",csTmp));
		}
	}

	FREE_ME(hData);
DEBUGLOG(("TxnMmsByUsCEE Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
