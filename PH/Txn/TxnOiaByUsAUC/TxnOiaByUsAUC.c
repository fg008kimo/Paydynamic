/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/03/19              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaByUsAUC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOiaByUsAUC(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iAutoUploadInd = PD_TRUE;

	char	*csBAID = NULL; 
	char    *csTmp = NULL;

DEBUGLOG(("TxnOiaByUsAUC::Authorize\n"));

/* baid */
	if (GetField_CString(hRequest, "baid", &csBAID)) {
DEBUGLOG(("Authorize::baid [%s]\n", csBAID));
	} else {
DEBUGLOG(("Authorize::baid not found!!\n"));
ERRLOG("TxnOiaByUsAUC::Authorize::baid not found!!\n");
                iRet=INT_BANK_ACCT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* auto_upload_ind */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "auto_upload_ind", &csTmp)) {
			iAutoUploadInd = atoi(csTmp);
DEBUGLOG(("Authorize::auto_upload_ind [%d]\n", iAutoUploadInd));
        	} else {
DEBUGLOG(("Authorize::auto_upload_ind not found!!\n"));
ERRLOG("TxnOiaByUsAUC::Authorize::auto_upload_ind not found!!\n");
                	iRet=INT_AUTO_UPLOAD_IND_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Deposit Bank Statement Auto Upload Control
	if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBaid","BankStmtAutoUploadControl");
                iRet = (unsigned long)(BOObjPtr)(csBAID,iAutoUploadInd);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBaid::BankStmtAutoUploadControl Success!!\n"));

			// BAID
                       	PutField_CString(hResponse, "baid", csBAID);	

        	} else {
DEBUGLOG(("Call BOOLBaid::BankStmtAutoUploadControl Failure!!\n"));
ERRLOG("TxnOiaByUsAUC::Authorize::Call BOOLBaid::BankStmtAutoUploadControl Failure!!\n");
			PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Not Update TxnReqRef
	PutField_Int(hContext,"not_update_log",PD_TRUE);

DEBUGLOG(("TxnOiaByUsAUC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

