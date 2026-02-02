/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/12              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRDB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsRDB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csTmp = NULL;
	char	cPartyType;
	char	cAction;
	int 	iTmp; 



/*
        int     iTmp =  PD_NOT_FOUND;

        hash_t  *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
*/


DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"action",&csTmp)){
                cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));
        }
        else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::action not found!!\n");
                iRet=INT_ACTION_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }


/* bank_code */
	if(GetField_CString(hRequest,"bank_code",&csTmp)){
DEBUGLOG(("Authorize::bank_code= [%s]\n",csTmp));
		PutField_CString(hContext,"bank_code",csTmp);
	}
        else{
DEBUGLOG(("Authorize::bank_code not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::bank_code not found!!\n");
		iRet=INT_BANK_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* party_type */
        if(GetField_CString(hRequest,"party_type",&csTmp)){
		cPartyType = csTmp[0];
DEBUGLOG(("Authorize::party_type = [%c]\n",cPartyType));
                PutField_Char(hContext,"party_type",cPartyType);
        }
        else{
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::party_type not found!!\n");
                iRet=INT_PARTY_TYPE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

	if (cPartyType == PD_TYPE_GLOBAL) {
/* channel_code */
	        if(GetField_CString(hRequest,"ch_code",&csTmp)){
DEBUGLOG(("Authorize::channel_code = [%s]\n",csTmp));
			PutField_CString(hContext,"ch_code",csTmp);
		}
		else{
DEBUGLOG(("Authorize::channel_code not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::channel_code not found!!\n");
			iRet=INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		
		PutField_CString(hContext, "party_id", "0000000000");


	} else if ((cPartyType == PD_TYPE_PSP) || (cPartyType == PD_TYPE_CLIENT)) {
/* party_id */
                if(GetField_CString(hRequest,"party_id",&csTmp)){
DEBUGLOG(("Authorize::party_id = [%s]\n",csTmp));
                        PutField_CString(hContext,"party_id",csTmp);
                }
                else{
DEBUGLOG(("Authorize::party_id not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::party_id not found!!\n");
                        iRet=INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
                }

		PutField_CString(hContext, "ch_code", PD_CHANNEL_WEB);

	} else {
		iRet = INT_INVALID_PARTY_TYPE;
		PutField_Int(hContext,"internal_error",iRet);
	} 

/* scheduler_id */
        if(GetField_CString(hRequest,"scheduler_id",&csTmp)){
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::scheduler_id= [%d]\n",iTmp));
                PutField_Int(hContext,"scheduler_id",iTmp);
        }
        else{
DEBUGLOG(("Authorize::scheduler_id not found!!\n"));
ERRLOG("TxnMgtByUsRDB::Authorize::scheduler_id not found!!\n");
                iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        }
	
/* note_id */
	if (GetField_CString(hRequest, "note_id", &csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::note_id = [%d]\n",iTmp));
                PutField_Int(hContext,"note_id",iTmp);
	}
	else {
DEBUGLOG(("Authorize::note_id not found!!\n"));
	}

/* disabled */
        if(GetField_CString(hRequest,"disabled",&csTmp)){
                iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::disabled = [%d]\n",iTmp));
                PutField_Int(hContext,"disabled",iTmp);
        }
        else{
DEBUGLOG(("Authorize::disabled not found!!\n"));
        }

/* user */
	
	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
		PutField_CString(hContext,"create_user",csTmp);
		PutField_CString(hContext,"update_user",csTmp);
	}


	if (iRet == PD_OK) {

		if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::Call DBRuleDisabledBank:ChkRuleExists\n"));
			DBObjPtr = CreateObj(DBPtr, "DBRuleDisabledBank", "ChkRuleExists");
                        if ((unsigned long)(*DBObjPtr)(hContext) == PD_FOUND) {
DEBUGLOG(("Authorize::RuleDisabledBank:ChkRuleExists FOUND\n"));
				iRet = INT_PROCESS_VALIDATE_ERROR;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if (!GetField_Int(hContext, "disabled", &iTmp)) {
				PutField_Int(hContext,"disabled",PD_FALSE);
			}
		

			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBRuleDisabledBank:Add\n"));
				DBObjPtr = CreateObj(DBPtr,"DBRuleDisabledBank","Add");
				if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleDisabledBank:Add Succ\n"));
				}
				else {
DEBUGLOG(("Authorize::RuleDisabledBank:Add FAIL\n"));
					iRet = INT_ERR;
				}
			}

		}
		else if (cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::Call DBRuleDisabledBank:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBRuleDisabledBank","Update");
                        if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleDisabledBank:Update Succ\n"));
			}
			else {
DEBUGLOG(("Authorize::RuleDisabledBank:Update FAIL\n"));
				iRet = INT_ERR;
			}
		}
		else if (cAction == PD_ACTION_DELETE) {

DEBUGLOG(("Authorize::Call DBRuleDisabledBank:Delete\n"));
			DBObjPtr = CreateObj(DBPtr,"DBRuleDisabledBank","Delete");
                        if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleDisabledBank:Delete Succ\n"));
			}
			else {
DEBUGLOG(("Authorize::RuleDisabledBank:Delete FAIL\n"));
				iRet = INT_ERR;
			}
		} else {
			iRet = INT_ACTION_NOT_FOUND;
		}

	}

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMgtByUsRDB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
