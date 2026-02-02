/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/05/12              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRPE.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#include "sha1.h"

#define PD_DETAIL_TAG   "dt"
#define TAG_BANK_NAME	'N'
#define TAG_BANK_ACCT	'A'

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsRPE(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	*csTmp;
	char	*csClientId;
	char	*csName;
	char	cParty;
	char	cAction;
	char	csTag[PD_TAG_LEN+1];
	int	i = 0;
	int	iCnt = 0;
	
	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

DEBUGLOG(("TxnMgtByUsRPE::Authorize\n"));

/* party */ 
        if (GetField_CString(hRequest, "party", &csTmp)) {
                cParty = csTmp[0];
DEBUGLOG(("Authorize::party = [%c]\n",cParty));
		//support add and delete
		if (cParty != TAG_BANK_NAME && cParty != TAG_BANK_ACCT) {
DEBUGLOG(("Authorize::party [%d] not support!!\n", cParty));
ERRLOG("TxnMgtByUsRPE::Authorize::party not support!!\n");
			iRet = INT_ERR;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }
        else {
DEBUGLOG(("Authorize::party not found!!\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::party not found!!\n");
                iRet=INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }

/*psp client id*/
        if (GetField_CString(hRequest, "client_id", &csClientId)) {
DEBUGLOG(("Authorize::client_id = [%s]\n",csClientId));
	}
	else {
DEBUGLOG(("Authorize::client_id not found\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::client_id not found\n");
                iRet = INT_FORMAT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }


/* total_cnt */
        if (GetField_Int(hContext, "total_cnt", &iCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
                PutField_Int(hResponse, "total_cnt", iCnt);
        }
        else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::total_cnt not found\n");
                iRet = INT_FORMAT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }

	if (iRet == PD_OK) {
                for (i = 0; i < iCnt; i++) {
                        hash_init(hTxn, 0);

			PutField_CString(hTxn, "client_id", csClientId);
                        memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
				cAction = csTmp[0];
DEBUGLOG(("Authorize::() [%s] = [%c]\n", csTag, cAction));
				if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::action [%c] not support!!\n", cAction));
ERRLOG("TxnMgtByUsRPE::Authorize::action not support!!\n");
					iDtlRet=INT_ACTION_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
				}
                        }
                        else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsRPE::Authorize::[%s] not found\n", csTag);
                                iDtlRet = INT_ERR;
                        }

			if(cParty==TAG_BANK_NAME){
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "%s_name_%d", PD_DETAIL_TAG, i+1);
				if (GetField_CString(hRequest, csTag, &csName)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csName));
					PutField_CString(hTxn, "bank_name", csName);
				}
				else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsRPE::Authorize::[%s] not found\n", csTag);
					iDtlRet = INT_ERR;
				}
			}
			else{
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "%s_acct_name_%d", PD_DETAIL_TAG, i+1);
				if (GetField_CString(hRequest, csTag, &csName)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csName));
					PutField_CString(hTxn, "acct_name", csName);
				}
				else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsRPE::Authorize::[%s] not found\n", csTag);
					iDtlRet = INT_ERR;
				}

				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "%s_acct_num_%d", PD_DETAIL_TAG, i+1);
				if (GetField_CString(hRequest, csTag, &csName)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csName));
					PutField_CString(hTxn, "acct_num", csName);
				}
				else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsRPE::Authorize::[%s] not found\n", csTag);
					iDtlRet = INT_ERR;
				}
			}
			
			if(GetField_CString(hRequest,"add_user",&csTmp)){
				PutField_CString(hTxn,"create_user",csTmp);
				PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("Authorize::update_user= [%s]\n",csTmp));
			}

			if(cParty==TAG_BANK_NAME){
				if(iDtlRet==PD_OK && cAction==PD_ACTION_ADD){
DEBUGLOG(("Authorize::Call DBRulePayoutExclude:Add\n"));
                			DBObjPtr = CreateObj(DBPtr,"DBRulePayoutExclude","Add");
					if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBRulePayoutExclude:Add Failed\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::DBRulePayoutExclude:Add Failed\n");
                        			iDtlRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iDtlRet);
					}
					else {
DEBUGLOG(("Authorize::DBRulePayoutExclude:Add Succ\n"));
					}
				}
				else if(iDtlRet==PD_OK && cAction==PD_ACTION_DELETE){
DEBUGLOG(("Authorize::Call DBRulePayoutExclude:Delete\n"));
                			DBObjPtr = CreateObj(DBPtr,"DBRulePayoutExclude","Delete");
                			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBRulePayoutExclude:Delete Failed\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::DBRulePayoutExclude:Delete Failed\n");
                        			iDtlRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iDtlRet);
					}
					else {
DEBUGLOG(("Authorize::DBRulePayoutExclude:Delete Succ\n"));
					}
				}
			}
			else{
				if(iDtlRet==PD_OK && cAction==PD_ACTION_ADD){
DEBUGLOG(("Authorize::Call DBRulePayoutExcludeBankAcct:Add\n"));
                			DBObjPtr = CreateObj(DBPtr,"DBRulePayoutExcludeBankAcct","Add");
					if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBRulePayoutExcludeBankAcct:Add Failed\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::DBRulePayoutExcludeBankAcct:Add Failed\n");
                        			iDtlRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iDtlRet);
					}
					else {
DEBUGLOG(("Authorize::DBRulePayoutExcludeBankAcct:Add Succ\n"));
					}
				}
				else if(iDtlRet==PD_OK && cAction==PD_ACTION_DELETE){
DEBUGLOG(("Authorize::Call DBRulePayoutExcludeBankAcct:Delete\n"));
                			DBObjPtr = CreateObj(DBPtr,"DBRulePayoutExcludeBankAcct","Delete");
                			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBRulePayoutExcludeBankAcct:Delete Failed\n"));
ERRLOG("TxnMgtByUsRPE::Authorize::DBRulePayoutExcludeBankAcct:Delete Failed\n");
                        			iDtlRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iDtlRet);
					}
					else {
DEBUGLOG(("Authorize::DBRulePayoutExcludeBankAcct:Delete Succ\n"));
					}
				}
			}

			memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "ret_%d", i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag, iDtlRet));
                        PutField_Int(hResponse, csTag ,iDtlRet);

                        if (iDtlRet != PD_OK) {
                                iRet = INT_ERR;
                        }
		}
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsRPE Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
