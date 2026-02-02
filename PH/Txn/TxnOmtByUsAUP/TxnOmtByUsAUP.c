/*
PDProTech(c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/08/06              Elvis Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsAUP.h"
#include "myrecordset.h"

#define       PD_DETAIL_TAG   "dt"

static char cDebug;

OBJPTR(DB);

void TxnOmtByUsAUP(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int     iRet = PD_OK;

	int	i = 0;
	int	iTotalCnt = 0;
	int	iTmp = 0;
	
	char    cAction;

	char    *csUser = NULL;        
	char	*csTmp = NULL;
	char 	csTag[PD_TMP_BUF_LEN];

DEBUGLOG(("Authorize() Begin\n"));

	cAction = ' ';

/* user */
        if (GetField_CString(hRequest, "add_user", &csUser))
	{
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
                PutField_CString(hContext, "update_user", csUser);
        } 
	else
	{
DEBUGLOG(("Authorize() update_user is missing, assign to default user SYSTEM\n"));
//ERRLOG("TxnOmtByUsAUP:: Authorize() update_user is missing!\n");
                PutField_CString(hContext, "update_user", PD_UPDATE_USER);
        }

/* total_cnt */
        if (GetField_CString(hRequest, "total_cnt", &csTmp)) {
                iTotalCnt = atoi(csTmp);
DEBUGLOG(("Authorize() total_cnt = [%d]\n", iTotalCnt));
        } else {
DEBUGLOG(("Authorize() total_cnt is missing!\n"));
ERRLOG("TxnOmtByUsAUP:: Authorize() total_cnt is missing!\n");
                iRet = INT_ERR;
        }

	if (iRet == PD_OK) {

                for (i=0;i<iTotalCnt;i++) {

/* action */
                        sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
                                cAction = csTmp[0];
                                if (cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize() [%d][%s] = [%c]\n", i, csTag, cAction));
                                } else {
DEBUGLOG(("Authorize() [%d][%s] is only allow 'U'\n", i, csTag));
                                        iRet = INT_ERR;
                                        break;
                                }
                        } else {
DEBUGLOG(("Authorize() [%d][%s] not found\n", i, csTag));
ERRLOG("TxnOmtByUsAUP:: Authorize() [%s] not found\n", csTag);
                                iRet = INT_ERR;
                                break;
                        }

/* nature */
                        sprintf(csTag, "%s_nature_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize() [%d][%s] = [%s]\n", i, csTag, csTmp));
				PutField_CString(hContext, "nature", csTmp);
                        } else {
DEBUGLOG(("Authorize() [%d][%s] not found\n", i, csTag));
ERRLOG("TxnOmtByUsAUP:: Authorize() [%s] not found\n", csTag);
                                iRet = INT_ERR;
                                break;
                        }

/* provider_id */
                        sprintf(csTag, "%s_provider_id_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize() [%d][%s] = [%s]\n", i, csTag, csTmp));
                                PutField_CString(hContext, "provider_id", csTmp);
                        } else {
DEBUGLOG(("Authorize() [%d][%s] not found\n", i, csTag));
ERRLOG("TxnOmtByUsAUP:: Authorize() [%s] not found\n", csTag);
                                iRet = INT_ERR;
                                break;
                        }

/* disabled */
                        sprintf(csTag, "%s_disabled_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
				iTmp = atoi(csTmp);
DEBUGLOG(("Authorize() [%d][%s] = [%d]\n", i, csTag, iTmp));
                                PutField_Int(hContext, "disabled", iTmp);
                        } else {
DEBUGLOG(("Authorize() [%d][%s] not found\n", i, csTag));
ERRLOG("TxnOmtByUsAUP:: Authorize() [%s] not found\n", csTag);
                                iRet = INT_ERR;
                                break;
                        }

			// Update OL_AUTO_UPLOAD_STMT_SETTINGS
                    	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() [%d]Call DBOLAutoUploadStmtSetting: UpdateDisabledByProviderId\n", i));
                            	DBObjPtr = CreateObj(DBPtr, "DBOLAutoUploadStmtSetting", "UpdateDisabledByProviderId");
                             	if ((unsigned long)(*DBObjPtr)(hContext) != PD_OK) {
DEBUGLOG(("Authorize() [%d]Call DBOLAutoUploadStmtSetting: UpdateDisabledByProviderId Failed!!!\n", i));
ERRLOG("TxnOmtByUsAUP:: Authorize()  Call DBOLAutoUploadStmtSetting: UpdateDisabledByProviderId Failed!!!\n");
                                      	iRet = INT_ERR;
                            	}
                      	}
		}
	}

	if (iRet != PD_OK)
        {
                PutField_Int(hContext, "internal_error", iRet);
        }

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;
}
