/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/27              Stan Poon
Add Action Upload, Cancel, Approve		   2013/11/11		   Stan Poon
New File Format					   2014/03/07		   Stan Poon
Rescue Boat Logging                                2015/07/03              Virginia Yun
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsDRU.h"
#include "myrecordset.h"
#include "math.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnOmtByUsDRU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csInFileName = NULL, *csInFilePath = NULL;
	char	csNewFileName[PD_UPLOAD_FILENAME_LEN + 1];
	char	csFileId[PD_TXN_SEQ_LEN + 1] = "\0";
	char	*csMerchantId = NULL, *csUser = NULL;
	char	cParty;

	char	csInFullName[PD_TMP_BUF_LEN];
	char	csNewFullName[PD_TMP_BUF_LEN];

	int	iTotalCount=0, iAcceptCount=0;
	double	dAcceptAmt=0.0;

	char	*csTmp = NULL;
	int	iTmp;
	FILE	*fin = NULL;

	char csSysCmd[PD_TMP_BUF_LEN*3] = "\0";

	PutField_CString(hContext,"input_channel",PD_DEPOSIT_REQUEST_FILE);
	PutField_Char(hContext,"status",PD_DEPOSIT_FILE_PENDING);

/* merchant_id */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "merchant_id", &csMerchantId)) {
			PutField_CString(hContext, "merchant_id", csMerchantId);
DEBUGLOG(("Authorize() merchant_id = [%s]\n", csMerchantId));
		} else {
			iRet = INT_MERCHANT_ID_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() merchant_id is missing!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() merchant_id is missing!!!\n");
		}
	}
/* in_file_path */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "in_file_path", &csInFilePath)) {
			PutField_CString(hContext,"in_file_path",csInFilePath);
DEBUGLOG(("Authorize() in_file_path = [%s]\n", csInFilePath));

			/* security check for running system() in ConvertStmtFile */
			csTmp = csInFilePath;
			while (*csTmp) {
				if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				    !(*csTmp >= 'A' && *csTmp <= 'Z') &&
				    !(*csTmp >= '0' && *csTmp <= '9') &&
				    !(*csTmp == '/' || *csTmp == '-' || *csTmp == '_')) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize() in_file_path char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n",*csTmp));
ERRLOG("TxnOmtByUSBSU::Authorize() in_file_path char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n",*csTmp);
					break;
				} else {
// DEBUGLOG(("Authorize() in_file_path [%c]\n",*csTmp));
				}
				csTmp++;
			}
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() in_file_path is missing!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() in_file_path is missing!!!\n");
		}
	}
/* in_file_name */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "in_file_name", &csInFileName)) {
			PutField_CString(hContext,"in_file_name",csInFileName);
			PutField_CString(hContext,"filename",csInFileName);
DEBUGLOG(("Authorize() in_file_name = [%s]\n", csInFileName));

			/* security check for running system() in ConvertStmtFile */
			csTmp = csInFileName;
			while (*csTmp) {
				if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				    !(*csTmp >= 'A' && *csTmp <= 'Z') &&
				    !(*csTmp >= '0' && *csTmp <= '9') &&
				    !(*csTmp == '.' || *csTmp == '-' || *csTmp == '_')) {
					iRet = INT_INVALID_FILE_NAME;
DEBUGLOG(("Authorize() in_file_name [%c] NOT MATCH [a-zA-Z0-9.-_]!!!\n",*csTmp));
ERRLOG("TxnOmtByUSBSU::Authorize() in_file_name [%c] NOT MATCH [a-zA-Z0-9.-_]!!!\n",*csTmp);
					break;
				} else {
// DEBUGLOG(("Authorize() in_file_name [%c]\n",*csTmp));
				}
				csTmp++;
			}
		} else {
			iRet = INT_FILE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() in_file_name is missing!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() in_file_name is missing!!!\n");
		}
	}
/* Party */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "party", &csTmp)) {
			cParty = csTmp[0];
			PutField_Char(hContext,"party",cParty);
DEBUGLOG(("Authorize() party [%c]\n", cParty));
		} else {
			iRet = INT_PARTY_TYPE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() party is missing!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() party is missing!!!\n");
		}
	}
/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
			PutField_CString(hContext,"create_user",csUser);
			PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() user is missing!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() user is missing!!!\n");
		}
	}
/* ip_addr */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
			PutField_CString(hContext,"ip_addr",csTmp);
DEBUGLOG(("Authorize() ip_addr = [%s]\n", csTmp));
		}
	}



/* open org file */
	if (iRet == PD_OK) {
		snprintf(csInFullName,sizeof(csInFullName),"%s/%s",csInFilePath,csInFileName);
		fin = fopen(csInFullName, "r");
		if (fin == NULL) {
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() cannot open file [%s]!!!\n", csInFileName));
ERRLOG("TxnOmtByUsBSU::Authorize() cannot open file [%s]!!!\n", csInFileName);
		} else {
			fclose(fin);
			fin = NULL;
		}
		PutField_CString(hContext,"in_file",csInFullName);
		PutField_CString(hContext,"in_file_name",csInFileName);
DEBUGLOG(("Authorize() in_file [%s]\n", csInFullName));
	}
/* open new file */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTxnSeq::GetNextOdiFileSeq()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOdiFileSeq");
		strcpy(csFileId,(*DBObjPtr)());
		PutField_CString(hContext,"file_id",csFileId);
DEBUGLOG(("Authorize() call DBOLTxnSeq::GetNextOdiFileSeq() file_id = [%s]\n",csFileId));

		snprintf(csNewFileName,sizeof(csNewFileName),"DF%s",csFileId);
		snprintf(csNewFullName,sizeof(csNewFullName),"%s/%s",csInFilePath,csNewFileName);
		fin = fopen(csNewFullName, "r");
		if (fin == NULL) {
			snprintf(csSysCmd, sizeof(csSysCmd), "mv -- \"%s\" \"%s\"", csInFullName, csNewFullName);
DEBUGLOG(("Authorize() call system command [%s][%d]\n", csSysCmd, strlen(csSysCmd)));
			system(csSysCmd);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() file [%s] EXISTS!!!\n", csNewFileName));
ERRLOG("TxnOmtByUsBSU::Authorize() file [%s] EXISTS!!!\n", csNewFileName);

			fclose(fin);
			fin = NULL;
		}

		PutField_CString(hContext,"new_file",csNewFullName);
		PutField_CString(hContext,"new_file_name",csNewFileName);
DEBUGLOG(("Authorize() new_file [%s]\n", csNewFullName));
	}
/* check filename */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLDepositRequest:: CheckFileExist()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLDepositRequest", "CheckFileExist");
		if ((unsigned long)(*DBObjPtr)(csMerchantId, csInFileName) != NOT_FOUND) {
			// NO Add Header again !!!
			iRet = INT_FILE_ALREADY_EXIST;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLDepositRequest::CheckFileExist() [%s] file DUPLICATED!!!\n", csInFileName));
		}
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLDepositRequest::AddHeader()\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLDepositRequest","AddHeader");
			if ((*DBObjPtr)(hContext) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLDepositRequest::AddHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() call DBOLDepositRequest::AddHeader() FAILURE!!!\n");
			}
		}
	}



/* Process Deposit Request */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call BOOLDepositReq::ProcessDepositReq()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLDepositReq", "ProcessDepositReq");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
		PutField_Int(hContext,"message_code",iRet);
		if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iTmp)) {
DEBUGLOG(("Authorize() call BOOLDepositReq::ProcessDepositReq() SUCCESS\n"));
			if (GetField_Int(hContext,"total_count",&iTotalCount)) {
DEBUGLOG(("Authorize() result total_count = [%d]\n",iTotalCount));
			}
			if (GetField_Int(hContext,"accept_count",&iAcceptCount)) {
				if (iAcceptCount <= 0) {
					PutField_Char(hContext,"status",PD_DEPOSIT_FILE_DECLINED);
				}
DEBUGLOG(("Authorize() result accept_count = [%d]\n",iAcceptCount));
			}
			if (GetField_Double(hContext,"accept_amount",&dAcceptAmt)) {
				if (dAcceptAmt <= 1E-9) {
					PutField_Char(hContext,"status",PD_DEPOSIT_FILE_DECLINED);
				}
DEBUGLOG(("Authorize() result accept_amount = [%.2lf]\n",dAcceptAmt));
			}
DEBUGLOG(("Authorize() call DBOLDepositRequest::UpdateHeader()\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLDepositRequest","UpdateHeader");
			if ((*DBObjPtr)(hContext) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLDepositRequest::UpdateHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() DBOLDepositRequest::UpdateHeader() FAILURE!!!\n"); 
			}
		} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call BOOLDepositReq::ProcessDepositReq() FAILURE!!!\n"));
		}
	}




/* Add Error Log */
	if ((iRet == PD_OK || GetField_Int(hContext,"internal_error",&iTmp)) &&
		GetField_Int(hContext,"result_cnt",&iTmp)) {
DEBUGLOG(("Authorize() call DBOLUploadError::AddError()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLUploadError", "AddError");
		if ((unsigned long)(*DBObjPtr)(hContext) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLUploadError::AddError() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRU::Authorize() call DBOLUploadError::AddError() FAILURE!!!\n");
		} else {
			iRet = PD_OK;
			RemoveField_Int(hContext,"internal_error");
DEBUGLOG(("Authorize() call DBOLUploadError::AddError() Success\n"));
		}
	}


/* Rescue Boat Logging */
	if (iRet == PD_OK) {
		int	iErrorCnt = 0;
		int	iTmpLoop  = 0;
		char    csTmpStatus [PD_TMP_BUF_LEN];
		char    csTag [PD_TMP_BUF_LEN];

		char	*csDesc = NULL;
		char	*csLineBuff = NULL;

		GetField_Int(hContext,"result_cnt",&iErrorCnt);
		
		if (iTotalCount != iAcceptCount) {
			memset(csTmpStatus, 0, sizeof(csTmpStatus));

			if (iAcceptCount == 0) {
				sprintf(csTmpStatus, "%s", "Declined");
			} else {
				sprintf(csTmpStatus, "%s", "Partial");
			}
		} else {
			sprintf(csTmpStatus, "%s", "Completed");
		}


DEBUGLOG(("Authorize() Rescue Boat FileResult %s,%s,%s,%c,%s,%s,%s,%d,%d,%.2lf,%s,%d\n",
		csMerchantId, csInFilePath, csInFileName, cParty, csUser, csFileId, csNewFileName, iTotalCount, iAcceptCount, dAcceptAmt, csTmpStatus, iErrorCnt));

		if (iErrorCnt > 0) {
			
			for (iTmpLoop=1; iTmpLoop <= iErrorCnt; iTmpLoop++) {

				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "desc_%d", iTmpLoop);
				GetField_CString(hContext, csTag, &csDesc);
				
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag,"line_%d",iTmpLoop);
				GetField_CString(hContext, csTag, &csLineBuff);

DEBUGLOG(("Authorize() Rescue Boat ErrorResult %s,%s,%d,%d,%s,\"%s\"\n",
		csFileId, csNewFileName, iErrorCnt, iTmpLoop, csDesc, csLineBuff));
			}
		}
	}



	PutField_CString(hResponse,"batch_id",csFileId);
	iTotalCount=0;
	GetField_Int(hContext,"total_count",&iTotalCount);
	PutField_Int(hResponse,"total",iTotalCount);
	iAcceptCount=0;
	GetField_Int(hContext,"accept_count",&iAcceptCount);
	PutField_Int(hResponse,"accept",iAcceptCount);
	dAcceptAmt=0.0;
	GetField_Double(hContext,"accept_amount",&dAcceptAmt);
	PutField_Double(hResponse,"accept_amt",dAcceptAmt);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

