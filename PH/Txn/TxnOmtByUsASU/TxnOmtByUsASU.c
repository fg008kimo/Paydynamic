/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/27              Stan Poon
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsASU.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsASU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	char *csInFileName, *csInFilePath;
	char *csIntBankCode, *csAcctNum;
	char *csUser;
	char csFileName[PD_TMP_BUF_LEN];
	FILE *fin;
	//char cs_err_buf[PD_TMP_BUF_LEN];

	recordset_t *rRecordFormat;
	rRecordFormat = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordFormat, 0);

/* in_file_name */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "in_file_name", &csInFileName)) {
			PutField_CString(hContext, "in_file_name", csInFileName);
DEBUGLOG(("Authorize() in_file_name = [%s]\n", csInFileName));
		} else {
			iRet = INT_FILE_NOT_FOUND;
DEBUGLOG(("Authorize() in_file_name is missing!!!\n"));
ERRLOG("TxnOmtByUsASU::Authorize() in_file_name is missing!!!\n");
		}
	}

/* in_file_path */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "in_file_path", &csInFilePath)) {
			if (csInFilePath[strlen(csInFilePath)-1] == '/')
				csInFilePath[strlen(csInFilePath)-1] = '\0';
			PutField_CString(hContext, "in_file_path", csInFilePath);
DEBUGLOG(("Authorize() in_file_path = [%s]\n", csInFilePath));
		} else {
			iRet = INT_FILE_NOT_FOUND;
DEBUGLOG(("Authorize() in_file_path is missing!!!\n"));
ERRLOG("TxnOmtByUsASU::Authorize() in_file_path is missing!!!\n");
		}
	}

/* int_bank_code */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "int_bank_code", &csIntBankCode)) {
			PutField_CString(hContext, "int_bank_code", csIntBankCode);
DEBUGLOG(("Authorize() int_bank_code = [%s]\n", csIntBankCode));
		} else {
			iRet = INT_BANK_CODE_NOT_FOUND;
//			snprintf(cs_err_buf, sizeof(cs_err_buf), "Bank Code Not Found");
//			PutField_Int(hContext, "record_cnt", 1);
//			PutField_CString(hContext, "result_1", cs_err_buf);
DEBUGLOG(("Authorize() int_bank_code is missing!!!\n"));
ERRLOG("TxnOmtByUsBSU::Authorize() int_bank_code is missing!!!\n");
		}
	}

/* bank_acct_num */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "bank_acct_num", &csAcctNum)) {
			PutField_CString(hContext, "bank_acct_num", csAcctNum);
DEBUGLOG(("Authorize() bank_acct_num = [%s]\n", csAcctNum));
		} else {
			iRet = INT_BANK_ID_NOT_FOUND;
//			snprintf(cs_err_buf, sizeof(cs_err_buf), "Bank Acct Not Found");
//			PutField_Int(hContext, "record_cnt", 1);
//			PutField_CString(hContext, "result_1", cs_err_buf);
DEBUGLOG(("Authorize() bank_acct_num is missing!!!\n"));
ERRLOG("TxnOmtByUsBSU::Authorize() bank_acct_num is missing!!!\n");
		}
	}

/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
			PutField_CString(hContext, "create_user", csUser);
			PutField_CString(hContext, "update_user", csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize() user is missing!!!\n"));
ERRLOG("TxnOmtByUsASU::Authorize() user is missing!!!\n");
		}
	}

/* file */
	if (iRet == PD_OK) {
		snprintf(csFileName, sizeof(csFileName), "%s/%s", csInFilePath, csInFileName);
		fin = fopen(csFileName, "r");
		if (fin == NULL) {
			iRet = INT_FILE_NOT_FOUND;
DEBUGLOG(("Authorize(): cannot open file [%s]!!!\n", csInFileName));
ERRLOG("TxnOmtByUsASU::Authorize(): cannot open file [%s]!!!\n", csInFileName);
		} else {
			PutField_CString(hContext, "in_full_file_name", csFileName);
			fclose(fin);
		}
	}

/* get stmt file format */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLStmtFormat::GetFormat()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLStmtFormat","GetFormat");
		iRet = (unsigned long)(*DBObjPtr)(csIntBankCode, rRecordFormat);

		if (iRet != PD_OK) {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
//			snprintf(cs_err_buf, sizeof(cs_err_buf), "File Format Error");
//			PutField_Int(hContext, "result_cnt", 1);
//			PutField_CString(hContext, "result_1", cs_err_buf);
DEBUGLOG(("Authorize() call DBOLStmtFormat::GetFormat() FAILURE!!!\n"));
//ERRLOG("TxnOmtByUsBSU::Authorize() call DBOLStmtFormat::GetFormat() FAILURE!!!\n");
		}
	}

/* Deposit Request */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call BOOLBankStmt::ProcessAuxStmtFile()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBankStmt", "ProcessAuxStmtFile");
		if ((unsigned long)(*BOObjPtr)(hContext, hRequest, rRecordFormat) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call BOOLBankStmt::ProcessAuxStmtFile() FAILURE!!!\n"));
		}
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	}

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

