/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/10/07              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsSCR.h"
#include "myrecordset.h"

#define       PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsSCR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	int	iCnt = 0;
	int	i = 0;
	int	k = 0;
	char	*csTmp;
	int	iTmp;
	char    csTag[PD_TAG_LEN+1];

	char	cAction;
	char    *csBankCode = NULL;
	char    *csBankAcct = NULL;
	char	*csOldMobile = NULL;
	char	*csNewMobile = NULL;
	char	*csUser = NULL;

/* old_mobile */
	if (GetField_CString(hRequest, "old_mobile", &csOldMobile)) {
DEBUGLOG(("Authorize::old_mobile = [%s]\n", csOldMobile));
		PutField_CString(hContext,"old_mobile",csOldMobile);
	} else {
DEBUGLOG(("Authorize:: old_mobile not found!!\n"));
ERRLOG("TxnOmtByUsSCR:: Authorize:: old_mobile not found!!\n");
		iRet = INT_MOBILE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* new_mobile */
	if (GetField_CString(hRequest, "new_mobile", &csNewMobile)) {
DEBUGLOG(("Authorize::new_mobile = [%s]\n", csNewMobile));
	} else {
DEBUGLOG(("Authorize:: new_mobile not found!!\n"));
ERRLOG("TxnOmtByUsSCR:: Authorize:: new_mobile not found!!\n");
		iRet = INT_MOBILE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* total cnt */
	if (GetField_CString(hRequest, "total_cnt", &csTmp)) {
		iCnt = atoi(csTmp);
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
	} else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnOmtByUsSCR::Authorize::total_cnt not found\n");
		iRet = INT_ERR;
	}

/* user */
        if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
                PutField_CString(hContext,"update_user",csUser);
        } else {
                iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsSCR::Authorize() user NOT FOUND!!!\n");
        }

	if (iRet == PD_OK) {
		for (i = 0; i < iCnt; i++) {
/* Action */
			sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
				cAction = csTmp[0];
				if (cAction == PD_ACTION_UPDATE || cAction == PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::() [%s] = [%c]\n", csTag, cAction));
				} else {
DEBUGLOG(("Authorize::() [%s] is only allow 'U' or 'D'\n", csTag));
					iDtlRet = INT_ERR;
					break;
				}
			} else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsSCR::Authorize::[%s] not found\n", csTag);
				iDtlRet = INT_ERR;
				break;
			}

/* Bank Code */
			sprintf(csTag, "%s_bank_code_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csBankCode)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csBankCode));
			} else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsSCR::Authorize::[%s] not found\n", csTag);
				iDtlRet = INT_ERR;
				break;
			}

/* Bank Acct */
			sprintf(csTag, "%s_acct_num_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csBankAcct)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csBankAcct));
			} else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsSCR::Authorize::[%s] not found\n", csTag);
				iDtlRet = INT_ERR;
				break;
			}

			/* check bank code exist before */
			for (k=0; k<i; k++) {
				sprintf(csTag,"%s_bank_code_%d", PD_DETAIL_TAG, k);
				GetField_CString(hRequest,csTag,&csTmp);
				if (strcmp(csBankCode,csTmp) == 0) {
DEBUGLOG(("Authorize::Same bank code [%s] found, action terminate!\n",csBankCode));
ERRLOG("TxnOmtByUsSCR::Authorize::Same bank code [%s] found, action terminate!\n",csBankCode);
					iDtlRet = INT_ERR;
					break;
				}
			}

			/* Check Bank Acct Exists or not */
			hash_t *hBankAcctRec;
			hBankAcctRec = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hBankAcctRec,0);

			DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "GetBankAccts");
			iRet = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcct,hBankAcctRec);
			if (iRet != PD_OK) {
DEBUGLOG(("Authorize::bank acct [%s][%s] not found\n",csBankCode,csBankAcct));
ERRLOG("TxnOmtByUsSCR::Authorize::bank acct not found\n");
				iRet = INT_BANK_ACCT_NOT_FOUND;
				break;
			}

			if (iRet == PD_OK && cAction != PD_ACTION_DELETE) {
				DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "ChkMobileNumByBank");
				iTmp = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcct,csNewMobile);
				if (iTmp == PD_FOUND) {
DEBUGLOG(("Authorize::DBOLBankAccts:ChkMobileNumByBank FOUND\n"));
ERRLOG("TxnOmtByUsSCR::Authorize::DBOLBankAccts:ChkMobileNumByBank FOUND\n");
					iRet = INT_MOBILE_USED_IN_SAME_BANK;
					break;
				} else {
DEBUGLOG(("Authorize::Mobile ready to add\n"));
				}
			}

			FREE_ME(hBankAcctRec);
		} //End for loop

		if(iDtlRet!=PD_OK){
			iRet = INT_ERR;
		}
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	} else {
DEBUGLOG(("Authorize::Start to replace/remove mobile number\n"));
		for (i=0; i<iCnt; i++) {
			sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
			GetField_CString(hRequest, csTag, &csTmp);
			cAction = csTmp[0];
DEBUGLOG(("Authorize::[%s]=[%c]\n",csTag,cAction));

			sprintf(csTag, "%s_bank_code_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csBankCode)) {
DEBUGLOG(("Authorize::[%s]=[%s]\n",csTag,csBankCode));
				PutField_CString(hContext, "bank_code", csBankCode);
			} else {
DEBUGLOG(("Authorize::Update fail, bank_code not found\n"));
				iRet = INT_ERR;
				break;
			}

			sprintf(csTag, "%s_acct_num_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csBankAcct)) {
				PutField_CString(hContext, "bank_acct", csBankAcct);
DEBUGLOG(("Authorize::[%s]=[%s]\n",csTag,csBankAcct));
			} else {
DEBUGLOG(("Authorize::Update fail, bank_acct not found\n"));
				iRet = INT_ERR;
				break;
			}

			if (cAction == PD_ACTION_ADD || cAction == PD_ACTION_UPDATE) {
				PutField_CString(hContext, "mobile", csNewMobile);
DEBUGLOG(("Authorize::Action=[%c], mobile=[%s]\n",cAction,csNewMobile));
			} else if (cAction == PD_ACTION_DELETE) {
				RemoveField_CString(hContext, "mobile");
DEBUGLOG(("Authorize::Action=[%c], mobile remove from hash\n",cAction));
			} else iRet = INT_ERR;

			DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "UpdateMobileNum");
			iRet = (unsigned long)(*DBObjPtr)(hContext);
			if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Update mobile number to bank acct return error\n"));
ERRLOG("TxnOmtByUsSCR::Authorize::update mobile return error\n");
			} else {
				if (cAction == PD_ACTION_ADD || cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::Update mobile number [%s] to bank acct [%s][%s] success\n", csNewMobile, csBankCode, csBankAcct));
				} else if (cAction == PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::Mobile number in bank acct [%s][%s] remove success\n", csBankCode, csBankAcct));
				}
			}
		}
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	} else {
		DBObjPtr = CreateObj(DBPtr, "DBOLSimCards", "DisposeSimCard");
		iRet = (unsigned long)(*DBObjPtr)(hContext);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Dispose Sim Card return error\n"));
ERRLOG("TxnOmyByUsSCR::Authorize::dispose sim card return error\n");
		} else {
DEBUGLOG(("Authorize::Dispose sim card [%s] success\n",csOldMobile));
		}
	}


DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}
