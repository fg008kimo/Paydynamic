/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/16              Dirk Wong
Remove Country, Modify Error Handling              2015/07/28              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsEBA.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(BO);

void TxnMmmByUsEBA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iTmpRet = PD_OK;
	char*	csBuf;
	char*	csTmp;
	int	iBalCnt;
	hash_t	*hData;


DEBUGLOG(("Authorize()\n"));
	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	csBuf = (char *)malloc(PD_TMP_BUF_LEN + 1);


// entity_id
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"entity_id",&csTmp)) {
DEBUGLOG(("Authorize: entity_id = [%s]\n",csTmp));
			PutField_CString(hData,"entity_id",csTmp);
		} else {
DEBUGLOG(("Authorize:: eid missing!!\n"));
ERRLOG("TxnMmmByUsEBA:: Authorize:: eid missing!!\n");
			iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
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

// bal_cnt
	if (iRet == PD_OK) {
	 	if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("Authorize: bal_cnt = [%d]\n",iBalCnt));
		} else {
DEBUGLOG(("Authorize:: bal_cnt missing!!\n"));
ERRLOG("TxnMmmByUsEBA:: Authorize:: bal_cnt missing!!\n");
			iRet = INT_MMS_BAL_CNT_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	int i=1;

//Loop to check if bal acct already exists
	if (iRet == PD_OK) {

		for (i=1; i<=iBalCnt; i++) 
		{
			if (iRet == PD_OK) {
				// ccy
				sprintf(csBuf,"txn_data.bal.%d.ccy",i);
				if (GetField_CString(hRequest,csBuf,&csTmp)) {
DEBUGLOG(("Authorize: ccy = [%s]\n",csTmp));
					PutField_CString(hData,"txn_ccy",csTmp);
				} else {
DEBUGLOG(("Authorize:: ccy missing!!\n"));
ERRLOG("TxnMmmByUsEBA:: Authorize:: ccy missing!!\n");
					iRet = INT_CURRENCY_CODE_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
					break;
				}

				//Call BO
				if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call BOMMSEntityBalAcct::CheckEntityBalAcct\n"));
					BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalAcct","CheckEntityBalAcct");
					iTmpRet = (unsigned long)(*BOObjPtr)(hContext,hData);
					if (iTmpRet != INT_MMS_ENTITY_BAL_ACCT_NOT_FOUND) {
DEBUGLOG(("Authorize: Entity Balance Account Exists\n"));
						iRet = INT_MMS_ENTITY_BAL_ACCT_EXISTS;
						PutField_Int(hContext,"internal_error",iRet);
						break;
					}
				}
			}
		}
	}


//Loop to add record
	if (iRet == PD_OK) {

		for (i=1; i<=iBalCnt; i++) 
		{
			// ccy
			sprintf(csBuf,"txn_data.bal.%d.ccy",i);
			if (GetField_CString(hRequest,csBuf,&csTmp)) {
DEBUGLOG(("Authorize: ccy = [%s]\n",csTmp));
				PutField_CString(hData,"ccy",csTmp);
			} else {
DEBUGLOG(("Authorize:: ccy missing!!\n"));
ERRLOG("TxnMmmByUsEBA:: Authorize:: ccy missing!!\n");
				iRet = INT_CURRENCY_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
				break;
			}

			//Call BO
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize: Call BOMMSEntityBalAcct::AddRecord\n"));
				BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalAcct","AddRecord");
				iRet = (unsigned long)(*BOObjPtr)(hData);
DEBUGLOG(("Authorize: BOMMSEntityBalAcct:: AddRecord iRet = [%d]\n",iRet));
				if (iRet != PD_OK) {
					PutField_Int(hContext,"internal_error",iRet);
					break;
				}
	
			}
		}
	}


	FREE_ME(hData);
DEBUGLOG(("TxnMmmByUsEBA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
