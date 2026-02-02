/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/18              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRON.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsRON(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csTmp = NULL;
	char	cAction;
	int	iNoteId = 0;



DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"action",&csTmp)){
                cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));
        }
        else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsRON::Authorize::action not found!!\n");
                iRet=INT_ACTION_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

	if (cAction == PD_ACTION_UPDATE || cAction == PD_ACTION_DELETE) {
        	if(GetField_CString(hRequest,"note_id",&csTmp)){
                	iNoteId = atoi(csTmp);
DEBUGLOG(("Authorize::note_id = [%d]\n",iNoteId));
			PutField_Int(hContext, "note_id", iNoteId);

			PutField_Int(hResponse, "note_id", iNoteId);
        	}
	        else {
DEBUGLOG(("Authorize::note_id not found!!\n"));
ERRLOG("TxnMgtByUsRON::Authorize::note_id not found!!\n");
			iRet=INT_ERR;

			PutField_Int(hContext,"internal_error",iRet);
        	}
	}

/* language */
	if(GetField_CString(hRequest,"language",&csTmp)){
DEBUGLOG(("Authorize::language = [%s]\n",csTmp));
		PutField_CString(hContext,"language",csTmp);
	}
        else{
DEBUGLOG(("Authorize::language not found!!\n"));
ERRLOG("TxnMgtByUsRON::Authorize::language not found!!\n");
		iRet=INT_ERR;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* note */
        if(GetField_CString(hRequest,"note",&csTmp)){
DEBUGLOG(("Authorize::note = [%s]\n",csTmp));
                PutField_CString(hContext,"note",csTmp);
        }
        else{
DEBUGLOG(("Authorize::note not found!!\n"));
ERRLOG("TxnMgtByUsRON::Authorize::note not found!!\n");
                iRet=INT_ERR;

		PutField_Int(hContext,"internal_error",iRet);
        }

	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
		PutField_CString(hContext,"create_user",csTmp);
		PutField_CString(hContext,"update_user",csTmp);
	}

	if (iRet == PD_OK) {

		if (cAction == PD_ACTION_ADD) {

			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBRuleOutageNote:Add\n"));
				DBObjPtr = CreateObj(DBPtr,"DBRuleOutageNote","Add");
				if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleOutageNote:Add Succ\n"));

					GetField_Int(hContext, "note_id", &iNoteId);
DEBUGLOG(("Authorize::Add:note_id =[%d]\n", iNoteId));
					PutField_Int(hResponse, "note_id", iNoteId);
				}
				else {
DEBUGLOG(("Authorize::RuleOutageNote:Add FAIL\n"));
					iRet = INT_ERR;
				}
			}
		}
		else if (cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::Call DBRuleOutageNote:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBRuleOutageNote","Update");
                        if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleOutageNote:Update Succ\n"));
			}
			else {
DEBUGLOG(("Authorize::RuleOutageNote:Update FAIL\n"));
				iRet = INT_ERR;
			}
		}
		else if (cAction == PD_ACTION_DELETE) {

DEBUGLOG(("Authorize::Call DBRuleOutageNote:Delete\n"));
			DBObjPtr = CreateObj(DBPtr,"DBRuleOutageNote","Delete");
                        if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::RuleOutageNote:Delete Succ\n"));
			}
			else {
DEBUGLOG(("Authorize::RuleOutageNote:Delete FAIL\n"));
				iRet = INT_ERR;
			}
		} else {
DEBUGLOG(("Authorize::action not valid!!\n"));
ERRLOG("TxnMgtByUsRON::Authorize::action not valid!!\n");

			iRet = INT_ACTION_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}

	}

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMgtByUsRON Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
