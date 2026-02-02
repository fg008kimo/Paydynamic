/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/05/29              [MIC]
Revise code upon change request                    2020/07/28              [MIC]
1. Revise to update bank account status to spare
2. Add Initial Balance to reject negative amount
3. Add Registered mobile number cannot be blank
Fix issue for empty SMS Stmt, empty Deposit Cost   2020/08/14              [MIC]
1. Add SMS Stmt Enable set as "No" if empty
2. Add Apply Deposit Cost set as "No" if empty
Fix issue for disposed bank account                2020/09/01              [MIC]
1. Add checking provider in database as same as file
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsAFU.h"
#include "myrecordset.h"
#include "math.h"


static char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

#define	PD_FIELD_SIZE		14
#define PD_FILE_DELIMITER	","

char *csDetailTagType[PD_FIELD_SIZE] = {
PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,
PD_STRING_TYPE,PD_DOUBLE_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE,PD_STRING_TYPE};

int  iDetailMaxLength[PD_FIELD_SIZE] = {
PD_CLIENT_NAME_LEN, PD_DESC_LEN  , PD_BANK_ACCT_NAME_LEN, PD_BANK_ACCT_NUM_LEN, PD_OWNER_NAME_LEN  , PD_PROVINCE_LENGTH        , PD_CITY_LENGTH, 
PD_BANK_BRANCH_LEN, PD_INIT_BAL_LEN, PD_SMS_STMT_LEN      , PD_CUSTOMER_TEL_LEN , PD_APL_DEP_COST_LEN, PD_MERCH_SHORT_NAME_LEN, PD_BANK_ACCT_SHORT_NAME_LEN};

int  iDetailMinLength[PD_FIELD_SIZE] = {
1, 1, 1, PD_MIN_ACCT_NUM_LEN, 1, 1, 1,
1, 1, 0, 0                  , 0, 0, 0};

char *csDetailField[PD_FIELD_SIZE] =   {
"Bank Account Provider", "Bank Account Nature", "Bank Name"           , "Bank Account Number"     , "Owner Name"        , "Province"           , "City", 
"Branch Name"          , "Initial Balance"    , "SMS Statement Enable", "Registered Mobile Number", "Apply Deposit Cost", "Merchant Short Name", "Bank Account Short Name"};

char *csDetailTagVerN[PD_FIELD_SIZE] = {
"prov_name", "acct_type", "int_bank_code", "new_acct_num", "owner"             , "province"   , "city",
"branch" , "init_bal" , "sms_stmt"     , "reg_mob_num" , "apply_deposit_cost", "merchant_name", "short_name"};

int iMaxLenErrMsg[PD_FIELD_SIZE] = {
INT_INVALID_FORMAT_PROVIDER      , INT_INVALID_FORMAT_NATURE     , INT_INVALID_FORMAT_BANK_NAME, 
INT_INVALID_FORMAT_BANK_ACCT_NUM , INT_INVALID_FORMAT_OWNER_NAME , INT_INVALID_FORMAT_PROVINCE, 
INT_INVALID_FORMAT_CITY          , INT_INVALID_FORMAT_BRANCH_NAME, INT_INVALID_FORMAT_INIT_BAL ,
INT_INVALID_FORMAT_SMS_STMT      , INT_INVALID_FORMAT_REG_MOB_NUM, INT_INVALID_FORMAT_DEP_COST,
INT_INVALID_FORMAT_MER_SHORT_NAME, INT_INVALID_FORMAT_BANK_ACCT_SHORT_NAME};


int iMinLenErrMsg[PD_FIELD_SIZE] = {
INT_BLANK_PROVIDER      , INT_BLANK_NATURE     , INT_BLANK_BANK_NAME, 
INT_INVALID_FORMAT_BANK_ACCT_NUM , INT_BLANK_OWNER_NAME , INT_BLANK_PROVINCE, 
INT_BLANK_CITY          , INT_BLANK_BRANCH_NAME, INT_BLANK_INIT_BAL ,
0, 0, 0,
0, 0};


int Verify_ProvName(const char* csProvName, hash_t* hRec);
int Verify_AcctNature(const char* csAcctNature);
int Verify_BankName(const char* csBankName, hash_t* hRec);
int Verify_AcctNum(const char* csAcctNum);
int Verify_ApplyDepCost(const char* csAcctNature, const char* csDepCost);
int Verify_MerchName(const char* csMerchName, hash_t* hRec);
int Verify_InitBal(const char* csInitBal);
int is_numeric_r2(const char *csStr);
int MapRetCode(int* iRetCode);

void TxnOmtByUsAFU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_ERR;
	int 	iUpdHdRet = PD_ERR;
	int	iCnt = 0;
	int 	iFieldSize = 0;
	int	iCurrLine = 0;
	int	iErrCnt = 0;
	int	iPspDisabled;
	unsigned long lFileId=0;
	char	*csInFilePath = NULL;
	char	csConvFileName[PD_UPLOAD_FILENAME_LEN + 1];
	char	*csRawFileName = NULL;
	char	*csFileId = NULL;
	char	*csUser = NULL;
	char	*csProvId = NULL;
	char	*csBankCode = NULL;
	char	*csPspId = NULL;
	char	*csMerchantId = NULL;
	char	*csTmDate = NULL;
	char	*csTmTime = NULL;
	char	*csChannelCode = NULL;
	char	*csInitProvId = NULL;
	char	*csStatusType = NULL;
	
	char	cStatus;
	char	cHeaderStatus;

	char	csInFullName[PD_TMP_BUF_LEN];
	char	csRawFilePath[PD_TMP_BUF_LEN];
	char	csNewFullName[PD_TMP_BUF_LEN];
	char	csConvFilePath[PD_TMP_BUF_LEN];
	
	char    cs_input_buf[PD_TMP_MSG_BUF_LEN];
	char    csTmpBuf[PD_TMP_MSG_BUF_LEN];

	char	*csBuf = (char*)malloc(64);

	char    *csHeader = NULL;
	char	*csTmp = NULL;
	char	*csPhdate = NULL;
	FILE	*fin = NULL;
	
	char csSysCmd[PD_TMP_BUF_LEN*3] = "\0";

	hash_t* hAcctHeader;
	hAcctHeader = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hAcctHeader,0);

DEBUGLOG(("TxnOmtByUsAFU:: Authorize\n"));

/* user */
	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("user = [%s]\n", csUser));
	}
	else {
DEBUGLOG(("user is missing!!!\n"));
ERRLOG("TxnOmtByUsAFU::Authorize() user is missing!!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}


/*Validate <in_file_path> for [a-zA-Z0-9/-_] characters*/
/* in_file_path */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "in_file_path", &csInFilePath)) {
DEBUGLOG(("in_file_path = [%s]\n", csInFilePath));
			/* security check for running system() in ConvertStmtFile */
			csTmp = csInFilePath;
			while (*csTmp) {
				if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
					!(*csTmp >= 'A' && *csTmp <= 'Z') &&
					!(*csTmp >= '0' && *csTmp <= '9') &&
					!(*csTmp == '/' || *csTmp == '-' || *csTmp == '_')) {
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() in_file_path char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n",*csTmp));
ERRLOG("TxnOmtByUsAFU::Authorize() in_file_path char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n",*csTmp);
					break;
				} else {
// DEBUGLOG(("Authorize() in_file_path [%c]\n",*csTmp));
				}
				csTmp++;
			}
		} 
		else {
DEBUGLOG(("Authorize() in_file_path is missing!!!\n"));
ERRLOG("TxnOmtByUsAFU::Authorize() in_file_path is missing!!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/*file_id*/
	if(iRet == PD_OK){
		if(GetField_CString(hRequest, "file_id", &csFileId)){
DEBUGLOG(("file_id = [%s]\n", csFileId));
			lFileId = (unsigned long)ctol((const unsigned char*)csFileId,strlen(csFileId));
		}
		else{
DEBUGLOG(("file_id not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: file_id not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	
/*host_posting_date*/
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"PHDATE",&csPhdate)) {
DEBUGLOG(("PHDATE = [%s]\n", csPhdate));
		}
		else{
DEBUGLOG(("PHDATE not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: PHDATE not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	
/*channel_code*/
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("channel_code = [%s]\n", csChannelCode));
		}
		else{
DEBUGLOG(("channel_code not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: channel_code not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
		
/*local_tm_date*/
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"local_tm_date",&csTmDate)) {
DEBUGLOG(("local_tm_date = [%s]\n", csTmDate));
		}
		else{
DEBUGLOG(("local_tm_date not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: local_tm_date not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	
/*local_tm_time*/
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"local_tm_time",&csTmTime)) {
DEBUGLOG(("local_tm_time = [%s]\n", csTmTime));
		}
		else{
DEBUGLOG(("local_tm_time not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: local_tm_time not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}



/*Get raw filename, file status by <file_id> in OL_ACCT_FILE_HEADER*/

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLAcctCreation","GetHeaderByFileId");
		iDtlRet = (unsigned long)(*DBObjPtr)(lFileId, hAcctHeader);
		if(iDtlRet == PD_OK){
DEBUGLOG(("call OLAcctCreation::GetHeaderByFileId Found!!\n"));
			if(GetField_Char(hAcctHeader, "status", &cStatus)){
DEBUGLOG((" status = [%c]\n", cStatus));
				if(cStatus != PD_ACCT_FILE_STATUS_INIT){
DEBUGLOG((" status not [I]!!\n"));
					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
			else{
DEBUGLOG((" status not found!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLAcctCreation::GetHeaderByFileId status not found!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
		else{
DEBUGLOG(("call OLAcctCreation::GetHeaderByFileId Error!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLAcctCreation::GetHeaderByFileId Error!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}	
	}



/*Validate raw filename for [a-zA-Z0-9/-_] characters*/

/* raw_filename */
	if (iRet == PD_OK) {
		if (GetField_CString(hAcctHeader, "raw_filename", &csRawFileName)) {
DEBUGLOG(("raw_filename = [%s]\n", csRawFileName));

			/* security check for running system() in ConvertStmtFile */
			csTmp = csRawFileName;
			while (*csTmp) {
				if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
					!(*csTmp >= 'A' && *csTmp <= 'Z') &&
					!(*csTmp >= '0' && *csTmp <= '9') &&
					!(*csTmp == '.' || *csTmp == '-' || *csTmp == '_')) {
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() raw_filename [%c] NOT MATCH [a-zA-Z0-9.-_]!!!\n",*csTmp));
ERRLOG("TxnOmtByUsAFU::Authorize() raw_filename [%c] NOT MATCH [a-zA-Z0-9.-_]!!!\n",*csTmp);
					break;
				} else {
// DEBUGLOG(("Authorize() in_file_name [%c]\n",*csTmp));
				}
				csTmp++;
			}
		}
		else {
DEBUGLOG(("Authorize() in_file_name is missing!!!\n"));
ERRLOG("TxnOmtByUsAFU::Authorize() in_file_name is missing!!!\n");
			iRet = INT_INVALID_FILE_FORMAT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/*Validate raw file can be opened using fopen function.*/
/* open org file */
	if (iRet == PD_OK) {
		snprintf(csRawFilePath,sizeof(csRawFilePath),"%s/%s",csInFilePath,PD_ACCT_FILE_RAW);
		snprintf(csInFullName,sizeof(csInFullName),"%s/%s",csRawFilePath,csRawFileName);
		fin = fopen(csInFullName, "r");
		if (fin == NULL) {
			iRet = INT_INVALID_FILE_FORMAT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() cannot open file [%s]!!!\n", csRawFileName));
ERRLOG("TxnOmtByUsAFU::Authorize() cannot open file [%s]!!!\n", csRawFileName);
		}
		else {
			fclose(fin);
			fin = NULL;
		}
DEBUGLOG(("raw_file [%s]\n", csInFullName));
	}
	

/*Execute script afu_init_convert.sh from raw file to convert file*/
	if (iRet == PD_OK) {
		sprintf(csTmpBuf, "%014lu", lFileId);
		snprintf(csConvFileName,sizeof(csConvFileName),"AF%s",csTmpBuf);
		snprintf(csConvFilePath,sizeof(csConvFilePath),"%s/%s",csInFilePath, PD_ACCT_FILE_CONVERTED);
		snprintf(csNewFullName,sizeof(csNewFullName),"%s/%s",csConvFilePath,csConvFileName);
		fin = fopen(csNewFullName, "r");
		if (fin == NULL) {
			snprintf(csSysCmd, sizeof(csSysCmd), 
				"afu_init_convert.sh \"%s\" \"%s\" \"%s\" \"%s\"", csRawFilePath, csConvFilePath, csRawFileName, csConvFileName);
DEBUGLOG(("call system command [%s][%d]\n", csSysCmd, strlen(csSysCmd)));
			system(csSysCmd);
		}
		else {
DEBUGLOG(("Authorize() file [%s] EXISTS!!!\n", csConvFileName));
ERRLOG("TxnOmtByUsAFU::Authorize() file [%s] EXISTS!!!\n", csConvFileName);
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			fclose(fin);
			fin = NULL;
		}
	}

/*check mandatory row header for upload files */
	if (iRet == PD_OK) {
DEBUGLOG(("csNewFullName = [%s]\n", csNewFullName));
		fin = fopen(csNewFullName, "r");
		if (fin != NULL){
			fgets(cs_input_buf, sizeof(cs_input_buf), fin);
DEBUGLOG(("header = [%s]\n", cs_input_buf));
			iFieldSize = (int)sizeof(csDetailTagVerN) / (int)sizeof(*csDetailTagVerN);
DEBUGLOG(("iFieldSize = [%d]\n", iFieldSize));
			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
			strcpy(csTmpBuf, cs_input_buf);
			csHeader = mystrtok(csTmpBuf, PD_FILE_DELIMITER);
			while (iCnt < iFieldSize) {
				if(csHeader != NULL){
					strcpy(csHeader, TrimAll((const unsigned char*)csHeader, strlen(csHeader)));
				}
				if(csHeader == NULL || strcmp(csHeader, csDetailField[iCnt])){
DEBUGLOG(("Invalid header %s = [%s]\n", csDetailField[iCnt], csHeader));
					iRet = INT_INVALID_FILE_FORMAT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
					break;
				}
				csHeader = mystrtok(NULL, PD_FILE_DELIMITER);
				iCnt++;
			}
		}
		else{
DEBUGLOG(("Authorize() converted file [%s] cannot be opened!!!\n", csConvFileName));
ERRLOG("TxnOmtByUsAFU::Authorize() converted file [%s] cannot be opened!!!\n", csConvFileName);
			iRet = INT_INVALID_FILE_FORMAT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			
		}
	}
	

	
/*Lock record on table ol_acct_file_header by fileid*/
	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr, "DBOLAcctCreation", "MatchHeaderStatusForUpdate");
		iDtlRet = (unsigned long)(*DBObjPtr)(lFileId, PD_ACCT_FILE_STATUS_INIT);
		if(iDtlRet == PD_FOUND){
DEBUGLOG(("call OLAcctCreation::MatchHeaderStatusForUpdate FileId[%s] Status[%c] Success!!\n", csFileId, PD_ACCT_FILE_STATUS_INIT));
		}
		else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("call OLAcctCreation::MatchHeaderStatusForUpdate FileId[%s] Status[%c] Not Found!!\n", csFileId, PD_ACCT_FILE_STATUS_INIT));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else{
DEBUGLOG(("call OLAcctCreation::MatchHeaderStatusForUpdate FileId[%s] Status[%c] Failure!!\n", csFileId, PD_ACCT_FILE_STATUS_INIT));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLAcctCreation::MatchHeaderStatusForUpdate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	

/*Update <OL_ACCT_FILE_HEADER.ACH_STATUS> to P */

	if(iRet == PD_OK){
		PutField_CString(hAcctHeader,"file_id",csFileId);
		PutField_Char(hAcctHeader, "status", PD_ACCT_FILE_STATUS_PROCESS); 

		DBObjPtr = CreateObj(DBPtr, "DBOLAcctCreation", "UpdateHeader");
		iUpdHdRet = (unsigned long)(*DBObjPtr)(hAcctHeader);
		if(iUpdHdRet == PD_OK){
DEBUGLOG(("call OLAcctCreation::UpdateHeader fileId[%s] status[%c] Success!!\n", csFileId, PD_ACCT_FILE_STATUS_PROCESS));
			TxnCommit();
		}
		else{
DEBUGLOG(("call OLAcctCreation::UpdateHeader fileId[%s] status[%c] Failure!!\n", csFileId, PD_ACCT_FILE_STATUS_PROCESS));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLAcctCreation::UpdateHeader Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
		
	}
	
	if(iRet == PD_OK){
		//verify record
		char    csTmpField[PD_TMP_MSG_BUF_LEN];
		char	csBankName[PD_BANK_ACCT_NAME_LEN + 1];
		char	csProvName[PD_CLIENT_NAME_LEN + 1];
		char	csAcctType[PD_ACCT_TYPE_LEN + 1];
		char	csAcctNature[PD_DESC_LEN + 1];
		char	csApplyDepCost[PD_APL_DEP_COST_LEN + 1];
		char	csSmsStmt[PD_SMS_STMT_LEN + 1];
		char	csRegMobNum[PD_CUSTOMER_TEL_LEN + 1];
		char	csRecDatetime[PD_REC_DATETIME_LEN + 1];
		char	csOwnerName[PD_OWNER_NAME_LEN+1];
		char	csBranchName[PD_BANK_BRANCH_LEN+1];
		char	csProvince[PD_PROVINCE_LEN+1];
		char	csCity[PD_CITY_LEN+1];
		char	csBankAcctNum[PD_BANK_ACCT_NUM_LEN + 1];
		char	csBankAcctShortName[PD_BANK_ACCT_SHORT_NAME_LEN + 1];
		char	csInitBal[PD_INIT_BAL_LEN + 1];
		char	csMerShortName[PD_MERCH_SHORT_NAME_LEN + 1];

		
		char    *csField = NULL;
		double	dInitBal = 0.0;
		int	iSmsStmt = 0;
		int	iApplyDepCost = 0;
		int	iRetCode = PD_OK;
		int	iIsInsertSucceed = PD_OK;

	

		fin = fopen(csNewFullName, "r");
		fgets(cs_input_buf, sizeof(cs_input_buf), fin);

		while (iIsInsertSucceed == PD_OK && fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
			
			hash_t* hGetAttribute;
			hGetAttribute = (hash_t*)malloc(sizeof(hash_t));
			hash_init(hGetAttribute,0);
			
			hash_t* hTxnBKAReq;
			hTxnBKAReq = (hash_t*)malloc(sizeof(hash_t));
			hash_init(hTxnBKAReq,0);

			hash_t* hTxnBAIReq;
			hTxnBAIReq = (hash_t*)malloc(sizeof(hash_t));
			hash_init(hTxnBAIReq,0);
			
			hash_t* hAcctLog;
			hAcctLog = (hash_t*)malloc(sizeof(hash_t));
			hash_init(hAcctLog,0);
			
			hash_t* hTxnMBAReq;
			hTxnMBAReq = (hash_t*)malloc(sizeof(hash_t));
			hash_init(hTxnMBAReq,0);
			
			
			recordset_t *rRecordSet;
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
			recordset_init(rRecordSet,0);
			
			hash_t* hGetMBA;

			iCurrLine++;
			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
DEBUGLOG(("[%d]cs_input_buf = [%s]\n",iCurrLine, cs_input_buf));
			if (!strcmp(cs_input_buf,"")){
				iCurrLine--;
				continue;
			}
			
			strcpy(csProvName, "");
			strcpy(csAcctType, "");
			strcpy(csBankName, "");
			strcpy(csBankAcctNum, "");
			strcpy(csOwnerName, "");
			strcpy(csProvince, "");
			strcpy(csCity, "");
			strcpy(csBranchName, "");
			strcpy(csInitBal, "");
			strcpy(csRegMobNum, "");
			strcpy(csBankAcctShortName, "");
			strcpy(csAcctNature, "");
			strcpy(csMerShortName, "");
			strcpy(csApplyDepCost, "");
			strcpy(csSmsStmt, "");
			csTmpBuf[0]='\0';
			csTmpField[0]='\0';
			iCnt = 0;
			iRetCode = PD_OK;
			csStatusType = NULL;
			csInitProvId = NULL;

			strcpy(csTmpBuf, cs_input_buf);
			csField = mystrtok(csTmpBuf, PD_FILE_DELIMITER);
			while (iRetCode == PD_OK && csField != NULL && iCnt<iFieldSize) {
				strcpy(csTmpField, TrimAll((const unsigned char*)csField, strlen(csField)));
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt],csTmpField));

				if(!strcmp(csDetailTagType[iCnt],PD_STRING_TYPE)){
					if(strlen(csTmpField)>iDetailMaxLength[iCnt]){
DEBUGLOG((" [%d]%s Field Error [%s] length [%d] exceed max length [%d]!!\n", iCnt, csDetailField[iCnt], csTmpField, strlen(csTmpField), iDetailMaxLength[iCnt]));
						iRetCode = iMaxLenErrMsg[iCnt];

					}
					else if(strlen(csTmpField)<iDetailMinLength[iCnt]){
DEBUGLOG((" [%d]%s Field Error [%s] length [%d] less than min length [%d]!!\n", iCnt, csDetailField[iCnt],csTmpField, strlen(csTmpField), iDetailMinLength[iCnt]));
						iRetCode = iMinLenErrMsg[iCnt];
						
						if(!strcmp(csDetailTagVerN[iCnt],"new_acct_num")){
							if(strlen(csTmpField) == 0){
DEBUGLOG((" [%d]%s Field Error cannot be blank [%s] length is [%d]!!\n", iCnt, csDetailField[iCnt],csTmpField, strlen(csTmpField)));
								iRetCode = INT_BLANK_BANK_ACCT_NUM;
							}
						}
					}
					else{
/*Bank Account Provider*/
						if(!strcmp(csDetailTagVerN[iCnt],"prov_name")){
							iRetCode = Verify_ProvName(csTmpField, hGetAttribute);
							if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Not Found!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_PROVIDER_NOT_FOUND;
							}
							
							strcpy(csProvName, csTmpField);
							
						}
/*Bank Account Nature*/
						else if(!strcmp(csDetailTagVerN[iCnt],"acct_type")){
							iRetCode = Verify_AcctNature(csTmpField);
							if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Not Found!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_ACCT_NATURE_NOT_FOUND;
							}
							strcpy(csAcctNature, csTmpField);
							
							if(!strcmp(csTmpField,PD_NATURE_INTERMEDIATE_NAME)){
								strcpy(csAcctType, PD_NATURE_INTERMEDIATE);
							}
							else if(!strcmp(csTmpField,PD_NATURE_PAYOUT_NAME)){
								strcpy(csAcctType, PD_NATURE_PAYOUT);
							}
							else{
								strcpy(csAcctType, PD_NATURE_DEPOSIT);
							}
							
						}
/*Bank Name*/
						else if(!strcmp(csDetailTagVerN[iCnt],"int_bank_code")){
							iRetCode = Verify_BankName(csTmpField, hGetAttribute);
							if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Not Found!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_BANK_NAME_IS_NOT_FOUND;
							}
							strcpy(csBankName, csTmpField);
							

						}
/*Bank Account Number*/
						else if(!strcmp(csDetailTagVerN[iCnt],"new_acct_num")){
							iRetCode = Verify_AcctNum(csTmpField);
							if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Invalid!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_INVALID_FORMAT_BANK_ACCT_NUM;
							}
							strcpy(csBankAcctNum, csTmpField);
							
						}
/*Owner Name*/
						else if(!strcmp(csDetailTagVerN[iCnt],"owner")){
							strcpy(csOwnerName, csTmpField);
						}
/*Province*/
						else if(!strcmp(csDetailTagVerN[iCnt],"province")){
							strcpy(csProvince, csTmpField);
						}
/*City*/
						else if(!strcmp(csDetailTagVerN[iCnt],"city")){
							strcpy(csCity, csTmpField);
						}
/*Branch Name*/
						else if(!strcmp(csDetailTagVerN[iCnt],"branch")){
							strcpy(csBranchName, csTmpField);
						}
/*SMS Statement Enable*/
						else if(!strcmp(csDetailTagVerN[iCnt],"sms_stmt")){
/*Convert No or empty into 0, Yes into 1*/
							if(!strcasecmp(csTmpField, PD_FIELD_NO) || !strcmp(csTmpField, "")){
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt], PD_FIELD_DISABLE));
								strcpy(csSmsStmt, PD_FIELD_DISABLE);
							}
							else if(!strcasecmp(csTmpField, PD_FIELD_YES)){
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt], PD_FIELD_ENABLE));
								strcpy(csSmsStmt, PD_FIELD_ENABLE);
							}
							else{
DEBUGLOG((" [%d]%s Field Error [%s] Invalid!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_INVALID_FORMAT_SMS_STMT;
							}
						}
/*Registered Mobile Number*/
						else if(!strcmp(csDetailTagVerN[iCnt],"reg_mob_num")){
							if(!strcmp(csSmsStmt, PD_FIELD_ENABLE) && !strcmp(csTmpField, "")){
DEBUGLOG((" [%d]%s Field Error [%s] cannot be blank for SMS Statement Enable is YES!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_BLANK_REG_MOB_NUM;
							}
							else{
								strcpy(csRegMobNum, csTmpField);
							}
						}
/*Apply Deposit Cost*/
						else if(!strcmp(csDetailTagVerN[iCnt],"apply_deposit_cost")){
							iRetCode = Verify_ApplyDepCost(csAcctNature, csTmpField);
							if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Invalid!!\n", iCnt, csDetailField[iCnt], csTmpField));
								iRetCode = INT_INVALID_FORMAT_DEP_COST;
								
							}
/*If Payout or Intermediate, convert No into 0*/
							if(!strcmp(csAcctNature, PD_NATURE_INTERMEDIATE_NAME)
								|| !strcmp(csAcctNature, PD_NATURE_PAYOUT_NAME)){
								if(!strcasecmp(csTmpField, PD_FIELD_NO) 
									|| !strcasecmp(csTmpField, PD_FIELD_YES)
									|| !strcmp(csTmpField, "")){
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt], PD_FIELD_DISABLE));
									strcpy(csApplyDepCost, PD_FIELD_DISABLE);
								}
							}
/*If Deposit, convert No or empty into 0, Yes into 1*/
							else if(!strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
								if(!strcmp(csTmpField, "") || !strcasecmp(csTmpField, PD_FIELD_NO)){
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt], PD_FIELD_DISABLE));
									strcpy(csApplyDepCost, PD_FIELD_DISABLE);
								}
								else if(!strcasecmp(csTmpField, PD_FIELD_YES)){
DEBUGLOG((" [%d][%s] = [%s]\n",iCnt, csDetailTagVerN[iCnt], PD_FIELD_ENABLE));
									strcpy(csApplyDepCost, PD_FIELD_ENABLE);
								}
							}
							
						}
/*Merchant Short Name*/
						else if(!strcmp(csDetailTagVerN[iCnt],"merchant_name")){
							if(!strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
/*Marchant Short Name cannot be blank for a deposit account*/
								if(!strcmp(csTmpField, "")){
DEBUGLOG((" [%d]%s Field Error [%s] cannot be blank for deposit account!!\n", iCnt, csDetailField[iCnt], csTmpField));
									iRetCode = INT_MER_SHORT_NAME_BLANK;
								}
								else{
									iRetCode = Verify_MerchName(csTmpField, hGetAttribute);
									if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Field Error [%s] Fail associate!!\n", iCnt, csDetailField[iCnt], csTmpField));
										iRetCode = INT_MER_SHORT_NAME_FAIL_ASSOCIATE;
									}
								}
							}
/*Empty for Payout and Intermediate*/
							else if(!strcmp(csAcctNature, PD_NATURE_INTERMEDIATE_NAME)
								|| !strcmp(csAcctNature, PD_NATURE_PAYOUT_NAME)){
									if(strcmp(csTmpField, "")){
DEBUGLOG((" [%d]%s Field Error [%s] Not Empty for %s account!!\n", iCnt, csDetailField[iCnt], csTmpField, csAcctNature));
										iRetCode = INT_MER_SHORT_NAME_NOT_EMPTY;
									}
							}
							strcpy(csMerShortName, csTmpField);
						}
/*Bank Account Short Name*/
						else if(!strcmp(csDetailTagVerN[iCnt],"short_name")){
							strcpy(csBankAcctShortName, csTmpField);
						}
					}
				}
				else if(!strcmp(csDetailTagType[iCnt],PD_DOUBLE_TYPE)){
					if(strlen(csTmpField)>iDetailMaxLength[iCnt]){
DEBUGLOG((" [%d]%s Field Error [%s] length [%d] exceed max length [%d]!!\n", iCnt, csDetailField[iCnt], csTmpField, strlen(csTmpField), iDetailMaxLength[iCnt]));
						iRetCode = iMaxLenErrMsg[iCnt];
						
					}
					else if(strlen(csTmpField)<iDetailMinLength[iCnt]){
DEBUGLOG((" [%d]%s Field Error [%s] length [%d] less than min length [%d]!!\n", iCnt, csDetailField[iCnt],csTmpField, strlen(csTmpField), iDetailMinLength[iCnt]));
						iRetCode = iMinLenErrMsg[iCnt];
					}
					else if(!strcmp(csDetailTagVerN[iCnt],"init_bal")){
						iRetCode = Verify_InitBal(csTmpField);
						if(iRetCode != PD_OK){
DEBUGLOG((" [%d]%s Invalid!!\n", iCnt, csDetailField[iCnt]));
								iRetCode = INT_INVALID_FORMAT_INIT_BAL;
						}
						strcpy(csInitBal, csTmpField);
					}
				}


				csField = mystrtok(NULL, PD_FILE_DELIMITER);
				iCnt++;
			}//end of fetching one row

/*Check blank mandatory field for incomplete row*/
			if(iRetCode == PD_OK){
				if(!strcmp(csMerShortName,"") && !strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
DEBUGLOG(("[%d]Merchant Short Name cannot be blank for a deposit account!!\n", iCurrLine));
					iRetCode = INT_MER_SHORT_NAME_BLANK;
				}
				if(!strcmp(csApplyDepCost,"")){
DEBUGLOG(("[%d]Empty Apply Deposit Cost is set to No!!\n", iCurrLine));
					strcpy(csApplyDepCost, PD_FIELD_DISABLE);
				}
				if(!strcmp(csSmsStmt,"")){
DEBUGLOG(("[%d]Empty SMS Statement Enable is set to No!!\n", iCurrLine));
					strcpy(csSmsStmt, PD_FIELD_DISABLE);
				}
				
				if(iCnt < (iFieldSize - PD_OPTL_FIELD_NUM)){
DEBUGLOG(("[%d]mandatory info is not enough!!\n", iCurrLine));
					if(!strcmp(csProvName,"")){
DEBUGLOG(("[%d]Bank Account Provider cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_PROVIDER;
					}
					else if(!strcmp(csAcctType,"")){
DEBUGLOG(("[%d]Bank Account Nature cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_NATURE;
					}
					else if(!strcmp(csBankName,"")){
DEBUGLOG(("[%d]Bank Name cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_BANK_NAME;
					}
					else if(!strcmp(csBankAcctNum,"")){
DEBUGLOG(("[%d]Bank Account Number cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_BANK_ACCT_NUM;
					}
					else if(!strcmp(csOwnerName,"")){
DEBUGLOG(("[%d]Owner Name cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_OWNER_NAME;
					}
					else if(!strcmp(csProvince,"")){
DEBUGLOG(("[%d]Province cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_PROVINCE;
					}
					else if(!strcmp(csCity,"")){
DEBUGLOG(("[%d]City cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_CITY;
					}
					else if(!strcmp(csBranchName,"")){
DEBUGLOG(("[%d]Branch Name cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_BRANCH_NAME;
					}
					else if(!strcmp(csInitBal,"")){
DEBUGLOG(("[%d]Initial Balance cannot be blank!!\n", iCurrLine));
						iRetCode = INT_BLANK_INIT_BAL;
					}
				}
			}


			
/*Check provider between database and account creation file whether it is the same*/
			if(iRetCode == PD_OK){
				if(GetField_CString(hGetAttribute, "int_bank_code", &csBankCode)){
DEBUGLOG(("[%d]int_bank_code = [%s]\n", iCurrLine, csBankCode));
				}
				else{
DEBUGLOG(("[%d]int_bank_code not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call BankDesc::GetBankByBankName int_bank_code not found!!\n");
					iRetCode = INT_BANK_NAME_IS_NOT_FOUND;
				}
				
				if(GetField_CString(hGetAttribute, "client_id", &csProvId)){
DEBUGLOG(("[%d]client_id = [%s]\n", iCurrLine, csProvId));
				}
				else{
DEBUGLOG(("[%d]client_id not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call PspMaster::GetClientByClientName client_id not found!!\n");
					iRetCode = INT_PROVIDER_NOT_FOUND;
				}
/*Get provider and status of bank account recreation*/
				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
					iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hGetAttribute);

					if(iDtlRet == PD_OK){
						if(GetField_CString(hGetAttribute, "init_provider_id", &csInitProvId)){
DEBUGLOG(("[%d]init_provider_id = [%s]\n", iCurrLine, csInitProvId));
						}
						else{
DEBUGLOG(("[%d]init_provider_id not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call DBOLBankAccts::GetBankAccts init_provider_id not found!!\n");
						}
						if(GetField_CString(hGetAttribute, "status_type", &csStatusType)){
DEBUGLOG(("[%d]status_type = [%s]\n", iCurrLine, csStatusType));
						}
						else{
DEBUGLOG(("[%d]status_type not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call DBOLBankAccts::GetBankAccts status_type not found!!\n");
						}
					}					
					
/*return error if different provider (db and acct file) for disposed bank acct, without open baid*/
					if(csInitProvId != NULL && csStatusType != NULL) {
						DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetDtlByBankAcct");
						iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hGetAttribute);
/*Not found any open baid*/
						if(iDtlRet != PD_OK){
							if(!strcmp(csStatusType, PD_BANK_ACCT_STATUS_DISPOSED) && strcmp(csInitProvId, csProvId)){
DEBUGLOG(("[%d]Provider id in file [%s] is different from database record [%s] !!\n", iCurrLine, csProvId, csInitProvId));
								iRetCode = INT_DISPOSED_BANK_ACCT_DIFF_PROVIDER;
							}
						}
					}
				}
			}
/* Create action on BKA*/

			if(iRetCode == PD_OK){
				sprintf(csBuf, "%c", PD_ACTION_ADD);
				PutField_CString(hTxnBKAReq, "action", csBuf);
				PutField_CString(hTxnBKAReq, "int_bank_code", csBankCode);
				PutField_CString(hTxnBKAReq, "new_acct_num", csBankAcctNum);
				PutField_CString(hTxnBKAReq, "add_user", csUser);
				PutField_CString(hTxnBKAReq, "txn_ccy", PD_CCY_ISO_CNY);
				PutField_CString(hTxnBKAReq, "acct_type", csAcctType);
				PutField_CString(hTxnBKAReq, "share", PD_FIELD_DISABLE);
				strcpy((char*)csRecDatetime, csPhdate);
				strcat((char*)csRecDatetime, PD_REC_TIME);
				PutField_CString(hTxnBKAReq, "rec_datetime", csRecDatetime);
				PutField_CString(hTxnBKAReq, "rec_by", csUser);
				if(strcmp(csRegMobNum,""))
					PutField_CString(hTxnBKAReq, "reg_mob_num", csRegMobNum);
				PutField_CString(hTxnBKAReq, "status_type", PD_BANK_ACCT_STATUS_NEW);
				PutField_CString(hTxnBKAReq, "prov_id", csProvId);
				PutField_CString(hTxnBKAReq, "owner", csOwnerName);
				PutField_CString(hTxnBKAReq, "branch", csBranchName);
				PutField_CString(hTxnBKAReq, "city", csCity);
				PutField_CString(hTxnBKAReq, "province", csProvince);

				PutField_CString(hTxnBKAReq, "sms_stmt", csSmsStmt);
				PutField_CString(hTxnBKAReq, "sys_switch", PD_FIELD_ENABLE);
				
				if(iRetCode == PD_OK){
					TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBKA","Authorize");
					iRetCode = (unsigned long)(*TxnObjPtr)(hTxnBKAReq,hTxnBKAReq,hTxnBKAReq);
					if(iRetCode == PD_OK){
DEBUGLOG(("[%d]call TxnOmtByUsBKA::Authorize Success - Add Action!!\n", iCurrLine)); 
					}
					else{
DEBUGLOG(("[%d]call TxnOmtByUsBKA::Authorize Failure - Add Action!!\n", iCurrLine));
						if(MapRetCode(&iRetCode) != PD_OK){
							iRetCode = INT_FAIL_CREATE_BANK_ACCT;
						}
DEBUGLOG(("[%d]iRetCode:[%d]\n", iCurrLine, iRetCode));
					}
				}
				
			}
			

			
/* Update action on BKA*/
			if(iRetCode == PD_OK){
				sprintf(csBuf, "%c", PD_ACTION_UPDATE);
				PutField_CString(hTxnBKAReq, "action", csBuf);
				
				PutField_CString(hTxnBKAReq, "status_type", PD_BANK_ACCT_STATUS_SPARE);
				
				if(strcmp(csBankAcctShortName,""))
					PutField_CString(hTxnBKAReq, "short_name", csBankAcctShortName);

				if(iRetCode == PD_OK){
					TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBKA","Authorize");
					iRetCode = (unsigned long)(*TxnObjPtr)(hTxnBKAReq,hTxnBKAReq,hTxnBKAReq);
					if(iRetCode == PD_OK){
DEBUGLOG(("[%d]call TxnOmtByUsBKA::Authorize Success - Update Action!!\n", iCurrLine));
					}
					else{
DEBUGLOG(("[%d]call TxnOmtByUsBKA::Authorize Failure - Update Action!!\n", iCurrLine));
						if(MapRetCode(&iRetCode) != PD_OK){
							iRetCode = INT_FAIL_CREATE_BANK_ACCT;
						}
DEBUGLOG(("[%d]iRetCode:[%d]\n", iCurrLine, iRetCode));
					}
				}
			}


/* Create action on BAI*/
			
			if(iRetCode == PD_OK){
				sprintf(csBuf, "%c", PD_ACTION_ADD);
				PutField_CString(hTxnBAIReq, "action", csBuf);
				PutField_CString(hTxnBAIReq, "int_bank_code", csBankCode);
				PutField_CString(hTxnBAIReq, "bank_acct_num", csBankAcctNum);
				
				DBObjPtr = CreateObj(DBPtr,"DBOLPspDetail","GetPspIdByClientId");
				iDtlRet = (unsigned long)(*DBObjPtr)(csProvId, csAcctType, PD_CCY_ISO_CNY, hGetAttribute);
				if(iDtlRet == PD_FOUND){
DEBUGLOG(("[%d]call OLPspDetail::GetPspIdByClientId Found!!\n", iCurrLine));
					if(GetField_Int(hGetAttribute, "psp_disabled", &iPspDisabled)){
DEBUGLOG(("[%d]psp_disabled = [%d]\n", iCurrLine, iPspDisabled));
						if(iPspDisabled == PD_DISABLED){
							iRetCode = INT_PROVIDER_NOT_FOUND;
						}
					}
					else{
DEBUGLOG(("[%d]psp_disabled not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLPspDetail::GetPspIdByClientId psp_disabled not found!!\n");
						iRetCode = INT_PROVIDER_NOT_FOUND;
					}

				}
				else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("[%d]call OLPspDetail::GetPspIdByClientId Not Found!!\n", iCurrLine));
					iRetCode = INT_PROVIDER_NOT_FOUND;
				}
				else{
DEBUGLOG(("[%d]call OLPspDetail::GetPspIdByClientId Error!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLPspDetail::GetPspIdByClientId Error!!\n");
					iRetCode = INT_PROVIDER_NOT_FOUND;
				}
				
				if(GetField_CString(hGetAttribute, "psp_id", &csPspId)){
DEBUGLOG(("[%d]psp_id = [%s]\n", iCurrLine, csPspId));
					PutField_CString(hTxnBAIReq, "psp_id", csPspId);
				}
				else{
DEBUGLOG(("[%d]psp_id not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLPspDetail::GetPspIdByClientId psp_id not found!!\n");
					iRetCode = INT_PROVIDER_NOT_FOUND;
				}
				PutField_CString(hTxnBAIReq, "status", PD_BAID_STATUS_OPEN);
				PutField_CString(hTxnBAIReq, "apply_deposit_cost", csApplyDepCost);
				PutField_CString(hTxnBAIReq, "init_bal", csInitBal);
				PutField_CString(hTxnBAIReq, "add_user", csUser);
				PutField_CString(hTxnBAIReq, "channel_code", csChannelCode);
				PutField_CString(hTxnBAIReq, "PHDATE", csPhdate);
				PutField_CString(hTxnBAIReq, "local_tm_date", csTmDate);
				PutField_CString(hTxnBAIReq, "local_tm_time", csTmTime);

				PutField_Int(hTxnBAIReq,"db_commit", PD_FALSE);
				
				if(iRetCode == PD_OK){
					TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBAI","Authorize");
					iRetCode = (unsigned long)(*TxnObjPtr)(hTxnBAIReq,hTxnBAIReq,hTxnBAIReq);
					if(iRetCode == PD_OK){
DEBUGLOG(("[%d]call TxnOmtByUsBAI::Authorize Success!!\n", iCurrLine));
					}
					else{
DEBUGLOG(("[%d]call TxnOmtByUsBAI::Authorize Failure!!\n", iCurrLine));
						iRetCode = INT_FAIL_CREATE_BAID;
DEBUGLOG(("[%d]iRetCode:[%d]\n", iCurrLine, iRetCode));
					}
				}

			}
			
			
/* Create action on MBA*/
			
			if(iRetCode == PD_OK){
				
/*Check bank account nature is deposit*/
				if(!strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
DEBUGLOG(("[%d]Begin create merchant bank account for [%s] deposit account!!\n", iCurrLine, csAcctNature));

					if(GetField_CString(hGetAttribute, "merchant_id", &csMerchantId)){
DEBUGLOG(("[%d]merchant_id = [%s]\n", iCurrLine, csMerchantId));
						PutField_CString(hTxnMBAReq, "merchant_id", csMerchantId);
					}
					else{
DEBUGLOG(("Authorize() [%d]merchant_id not found!!\n", iCurrLine));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLMerchDetail::ChkMerchNameExist merchant_id not found!!\n");
						iRetCode = INT_MER_SHORT_NAME_FAIL_ASSOCIATE;
					}
					
					if(iRetCode == PD_OK){
						DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBankAcct","FindDetailByBankAcct");
						iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, rRecordSet);
						if(iDtlRet == PD_OK){
DEBUGLOG(("[%d]call OLMerchantBankAcct::FindDetailByBankAcct Found!!\n", iCurrLine));
/*merchant bank account status open, return err*/
							hGetMBA = RecordSet_GetFirst(rRecordSet);
							while (hGetMBA) {
								if(GetField_CString(hGetMBA,"status",&csTmp)){
									if(!strcmp(PD_ACC_OPEN,csTmp)){
DEBUGLOG(("[%d]Bank acct num already associate to Merchant bank account and status open!!\n", iCurrLine));
										iRetCode = INT_BANK_ACCT_NUM_DUPLICATE;
									}
								}
/*merchant bank account status close, Associate to same merchant, update action*/
/*merchant bank account status close, Associate to different merchant, add action*/
								if(GetField_CString(hGetMBA,"merchant_id",&csTmp)){
									if(!strcmp(csMerchantId,csTmp)){
										sprintf(csBuf, "%c", PD_ACTION_UPDATE);
										break;
									}
									else{
										sprintf(csBuf, "%c", PD_ACTION_ADD);
									}
								}
								hGetMBA = RecordSet_GetNext(rRecordSet);
							}
						}
						else{
DEBUGLOG(("[%d]call OLMerchantBankAcct::FindDetailByBankAcct Not Found!!\n", iCurrLine));
							sprintf(csBuf, "%c", PD_ACTION_ADD);
						}
					}
					PutField_CString(hTxnMBAReq, "action", csBuf);
					PutField_CString(hTxnMBAReq, "add_user", csUser);
					PutField_CString(hTxnMBAReq, "int_bank_code", csBankCode);
					PutField_CString(hTxnMBAReq, "bank_acct_num", csBankAcctNum);
					PutField_CString(hTxnMBAReq, "service_code", PD_SERVICE_LOCAL_BANK_PAY);
					PutField_CString(hTxnMBAReq, "status", PD_ACC_OPEN);
					PutField_CString(hTxnMBAReq, "txn_type", PD_TXN_TYPE_DEPOSIT_ONLY);
					
					if(iRetCode == PD_OK){
						TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsMBA","Authorize");
						iRetCode = (unsigned long)(*TxnObjPtr)(hTxnMBAReq,hTxnMBAReq,hTxnMBAReq);
						if(iRetCode == PD_OK){
DEBUGLOG(("[%d]call TxnOmtByUsMBA::Authorize Success!!\n", iCurrLine));
						}
						else{
DEBUGLOG(("[%d]call TxnOmtByUsMBA::Authorize Failure!!\n", iCurrLine));
							if(MapRetCode(&iRetCode) != PD_OK)
								iRetCode = INT_FAIL_ASSOCIATE_MERCHANT;
DEBUGLOG(("[%d]iRetCode:[%d]\n", iCurrLine, iRetCode));
						}
					}
				}
				else{
DEBUGLOG(("[%d]Not create merchant bank account for [%s] Non-deposit account!!\n", iCurrLine, csAcctNature));					
				}
			}

			if(iRetCode == PD_OK){
				
				TxnCommit();
			}
			else{
				TxnAbort();
			}


			if(iRetCode == PD_OK){
				PutField_CString(hAcctLog, "file_id", csFileId);
				PutField_Int(hAcctLog, "seq", iCurrLine);
				PutField_CString(hAcctLog, "provider_name", csProvName);
				PutField_CString(hAcctLog, "provider_id", csProvId);
				PutField_CString(hAcctLog, "acct_type", csAcctType);
				PutField_CString(hAcctLog, "bank_name", csBankName);
				PutField_CString(hAcctLog, "int_bank_code", csBankCode);
				PutField_CString(hAcctLog, "bank_acct_num", csBankAcctNum);
				PutField_CString(hAcctLog, "bank_acct_short_name", csBankAcctShortName);
				PutField_CString(hAcctLog, "owner_name", csOwnerName);
				PutField_CString(hAcctLog, "province", csProvince);
				PutField_CString(hAcctLog, "city", csCity);
				PutField_CString(hAcctLog, "branch_name", csBranchName);
				dInitBal = string2doublewithsign((const unsigned char *)csInitBal);
				PutField_Double(hAcctLog, "init_bal", dInitBal);
				iSmsStmt = atoi(csSmsStmt);
				PutField_Int(hAcctLog, "support_sms_stmt", iSmsStmt);
				PutField_CString(hAcctLog, "registered_mobile", csRegMobNum);
				iApplyDepCost = atoi(csApplyDepCost);
				PutField_Int(hAcctLog, "apply_deposit_cost", iApplyDepCost);
				
				if(!strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
					PutField_CString(hAcctLog, "merchant_short_name", csMerShortName);
					PutField_CString(hAcctLog, "merchant_id", csMerchantId);
				}
				PutField_CString(hAcctLog, "create_user", csUser);

				DBObjPtr = CreateObj(DBPtr,"DBOLAcctCreation","AddDetail");
				if ((unsigned long)(*DBObjPtr)(hAcctLog) == PD_OK){
DEBUGLOG(("[%d]call DBOLAcctCreation::AddDetail file_id [%s] ret_code[%d] Success!!\n", iCurrLine, csFileId, iRetCode));
					TxnCommit();
				}
				else{
					iErrCnt++;
DEBUGLOG(("[%d]call DBOLAcctCreation::AddDetail file_id [%s] ret_code[%d] Failure!!\n", iCurrLine, csFileId, iRetCode));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call DBOLAcctCreation::AddDetail Failure!!\n");
					TxnAbort();
					iIsInsertSucceed = PD_ERR;
				}
				
			}
			else{
				PutField_CString(hAcctLog, "file_id", csFileId);
				PutField_Int(hAcctLog, "seq", iCurrLine);
				PutField_Int(hAcctLog, "msg_code", iRetCode);
				PutField_CString(hAcctLog, "line_content", cs_input_buf);
				PutField_CString(hAcctLog, "create_user", csUser);

				DBObjPtr = CreateObj(DBPtr,"DBOLAcctCreation","AddError");
				if ((unsigned long)(*DBObjPtr)(hAcctLog) == PD_OK){
					iErrCnt++;
DEBUGLOG(("[%d]call DBOLAcctCreation::AddError file_id [%s] ret_code[%d] Success!!\n", iCurrLine, csFileId, iRetCode));
					TxnCommit();
				}
				else{
					iErrCnt++;
DEBUGLOG(("[%d]call DBOLAcctCreation::AddError file_id [%s] ret_code[%d] Failure!!\n", iCurrLine, csFileId, iRetCode));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call DBOLAcctCreation::AddError Failure!!\n");
					TxnAbort();
					iIsInsertSucceed = PD_ERR;
				}
				
			}
			

			if(iIsInsertSucceed != PD_OK){
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
			
					
			hash_destroy(hTxnBKAReq);
			FREE_ME(hTxnBKAReq);
			
			hash_destroy(hTxnBAIReq);
			FREE_ME(hTxnBAIReq);
			
			hash_destroy(hGetAttribute);
			FREE_ME(hGetAttribute);
			
			hash_destroy(hAcctLog);
			FREE_ME(hAcctLog);
			
			hash_destroy(hTxnMBAReq);
			FREE_ME(hTxnMBAReq);
			
			
			RecordSet_Destroy(rRecordSet);

		}//end of fetching all rows

		
	}
	
	if(iRet != PD_OK){
		TxnAbort();
	}
			

	PutField_CString(hAcctHeader,"file_id",csFileId);
	PutField_CString(hAcctHeader, "update_user", csUser);
	PutField_CString(hAcctHeader, "convert_filename", csConvFileName);
	PutField_Int(hAcctHeader, "total_count", iCurrLine);
	PutField_Int(hAcctHeader, "accept_count", iCurrLine-iErrCnt);
	if(iCurrLine == 0 || iCurrLine == iErrCnt){
		cHeaderStatus = PD_ACCT_FILE_STATUS_DECLINED;
		PutField_Char(hAcctHeader, "status", PD_ACCT_FILE_STATUS_DECLINED);
		if(iRet != PD_OK){
/*Invalid file format, internal error*/
			PutField_Int(hAcctHeader, "msg_code", iRet);
		}
		else{
			PutField_Int(hAcctHeader, "msg_code", INT_ALL_REJECTED);
		}
	}
	else{
		cHeaderStatus = PD_ACCT_FILE_STATUS_APPROVED;
		PutField_Char(hAcctHeader, "status", PD_ACCT_FILE_STATUS_APPROVED);
		PutField_Int(hAcctHeader, "msg_code", iRet);
	}

	DBObjPtr = CreateObj(DBPtr, "DBOLAcctCreation", "UpdateHeader");
	iUpdHdRet = (unsigned long)(*DBObjPtr)(hAcctHeader);
	if(iUpdHdRet == PD_OK){
DEBUGLOG(("call OLAcctCreation::UpdateHeader status[%c] ret_code[%d] Success!!\n", cHeaderStatus, iRet));
	}
	else{
DEBUGLOG(("call OLAcctCreation::UpdateHeader status[%c] ret_code[%d] Failure!!\n", cHeaderStatus, iRet));
ERRLOG("TxnOmtByUsAFU:: Authorize:: call OLAcctCreation::UpdateHeader Failure!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);

	}

	
	hash_destroy(hAcctHeader);
	FREE_ME(hAcctHeader);

	FREE_ME(csBuf);


DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}


int Verify_ProvName(const char* csProvName, hash_t* hRec)
{
	int iRet = PD_ERR;
	int iDtlRet = PD_ERR;
	char* csClientStatus;
	char* csModeType;
	
	DBObjPtr = CreateObj(DBPtr,"DBPspMaster","GetClientByClientName");
	iDtlRet = (unsigned long)(*DBObjPtr)(csProvName, hRec);
	if (iDtlRet == PD_FOUND) {
DEBUGLOG(("  Verify_ProvName: call DBPspMaster::GetClientByClientName Found!!\n"));
		if(GetField_CString(hRec,"client_status", &csClientStatus)){
DEBUGLOG(("  Verify_ProvName: client_status = [%s]\n", csClientStatus));
			if(!strcmp(csClientStatus, PD_ACC_OPEN)){
				iRet = PD_OK;
			}
		}
		else{
DEBUGLOG(("  Verify_ProvName: client_status not found!!\n"));
			iRet = PD_ERR;
			
		}
		if(iRet == PD_OK){
			if(GetField_CString(hRec,"mode_type", &csModeType)){
DEBUGLOG(("  Verify_ProvName: mode_type = [%s]\n", csModeType));
				if(!strcmp(csModeType, PD_PSP_MASTER_MODE_OFFLINE) 
					|| !strcmp(csModeType, PD_PSP_MASTER_MODE_ALL)){
					iRet = PD_OK;
				}
				else{
					iRet = PD_ERR;
				}
			}
			else{
DEBUGLOG(("  Verify_ProvName: mode_type not found!!\n"));
				iRet = PD_ERR;
			}
		}
	}
	else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("  Verify_ProvName: call DBPspMaster::GetClientByClientName Not Found!!\n"));
		iRet = PD_ERR;
	}
	else{
DEBUGLOG(("  Verify_ProvName: call DBPspMaster::GetClientByClientName Error!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: Verify_ProvName:: call DBPspMaster::GetClientByClientName Error!!\n");
		iRet = INT_ERR;
	}

	return iRet;
}


int Verify_AcctNature(const char* csAcctNature)
{
	int iRet = PD_ERR;

	if(!strcmp(csAcctNature, PD_NATURE_INTERMEDIATE_NAME)
	|| !strcmp(csAcctNature, PD_NATURE_PAYOUT_NAME)
	|| !strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
DEBUGLOG(("  Verify_AcctNature [%s] Found\n",csAcctNature));

		iRet = PD_OK;
	}
	else{
DEBUGLOG(("  Verify_AcctNature [%s] Not Found\n",csAcctNature));
		iRet = PD_ERR;
	}


	return iRet;
}


int Verify_BankName(const char* csBankName, hash_t* hRec)
{
	int iRet = PD_ERR;
	int iDtlRet = PD_ERR;
	int iOfflSupport = 0;
	int iSysSupport = 0;

	DBObjPtr = CreateObj(DBPtr,"DBBankDesc","GetBankByBankName");
	iDtlRet = (unsigned long)(*DBObjPtr)(csBankName, hRec);
	if (iDtlRet == PD_FOUND) {
DEBUGLOG(("  Verify_BankName: call DBBankDesc::GetBankByBankName Found!!\n"));
		if(GetField_Int(hRec,"offline_support", &iOfflSupport)){
DEBUGLOG(("  Verify_BankName: offline_support = [%d]\n", iOfflSupport));
			if(iOfflSupport == PD_OFFL_SUPPORT_ENABLE){
				iRet = PD_OK;
			}
		}
		else{
DEBUGLOG(("  Verify_BankName: offline_support not found!!\n"));
			iRet = PD_ERR;
		}
		
		if(iRet == PD_OK){
			if(GetField_Int(hRec,"system_support", &iSysSupport)){
DEBUGLOG(("  Verify_BankName: system_support = [%d]\n", iSysSupport));
				if(iSysSupport == PD_SYS_SUPPORT_ENABLE){
					iRet = PD_OK;
				}
				else{
					iRet = PD_ERR;
				}
			}
			else{
DEBUGLOG(("  Verify_BankName: system_support not found!!\n"));
				iRet = PD_ERR;
			}
		}
	}
	else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("  Verify_BankName: call BankDesc::GetBankByBankName Not Found!!\n"));
		iRet = PD_ERR;
	}
	else{
DEBUGLOG(("  Verify_BankName: call BankDesc::GetBankByBankName Error!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: Verify_BankName:: call BankDesc::GetBankByBankName Error!!\n");
		iRet = INT_ERR;
	}
	
	return iRet;
	
}


int Verify_AcctNum(const char* csAcctNum)
{
	int iRet = PD_ERR;
	int iCheck = PD_FALSE;
	
	iCheck = is_numeric((char*)csAcctNum);
	if(iCheck == PD_TRUE){
DEBUGLOG(("  Verify_AcctNum [%s] Numeric\n",csAcctNum));
		iRet = PD_OK;
	}
	else{
DEBUGLOG(("  Verify_AcctNum [%s] is Non-Numeric\n",csAcctNum));
		iRet = PD_ERR;
	}

	return iRet;
	
}

int Verify_ApplyDepCost(const char* csAcctNature, const char* csDepCost)
{
	int iRet = PD_ERR;

	if(!strcmp(csAcctNature, PD_NATURE_INTERMEDIATE_NAME)
	|| !strcmp(csAcctNature, PD_NATURE_PAYOUT_NAME)
	|| !strcmp(csAcctNature, PD_NATURE_DEPOSIT_NAME)){
/*Payout, Intermediate, deposit account No, YES or blank*/
		if(!strcasecmp(csDepCost, PD_FIELD_NO) 
			|| !strcasecmp(csDepCost, PD_FIELD_YES)
			|| !strcmp(csDepCost, "")){
DEBUGLOG(("  Verify_ApplyDepCost: Valid Apply Deposit Cost:[%s] in [%s] account\n", csDepCost, csAcctNature));
				iRet = PD_OK;
		}
		else{
DEBUGLOG(("  Verify_ApplyDepCost: Invalid Apply Deposit Cost:[%s] in [%s] account\n", csDepCost, csAcctNature));
				iRet = PD_ERR;
		}

	}
	return iRet;
}
										




int Verify_MerchName(const char* csMerchName, hash_t* hRec)
{
	int iRet = PD_ERR;
	int iDtlRet = PD_ERR;
	int	iMerchDisabled;
	
	DBObjPtr = CreateObj(DBPtr,"DBOLMerchDetail","GetMerchByShortName");
	iDtlRet = (unsigned long)(*DBObjPtr)(csMerchName, hRec);
	if (iDtlRet == PD_FOUND) {
DEBUGLOG(("  Verify_MerchName: call OLMerchDetail::GetMerchByShortName Found!!\n"));

		if(GetField_Int(hRec,"merch_disabled", &iMerchDisabled)){
DEBUGLOG(("  Verify_MerchName: merch_disabled = [%d]\n", iMerchDisabled));
			if(iMerchDisabled != PD_DISABLED){
				iRet = PD_OK;
			}
		}
		else{
DEBUGLOG(("  Verify_MerchName: merch_disabled not found!!\n"));
			iRet = PD_ERR;
		}

	}
	else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("  Verify_MerchName: call OLMerchDetail::GetMerchByShortName Not Found!!\n"));
		iRet = PD_ERR;
	}
	else{
DEBUGLOG(("  Verify_MerchName: call OLMerchDetail::GetMerchByShortName Error!!\n"));
ERRLOG("TxnOmtByUsAFU:: Authorize:: Verify_MerchName:: call OLMerchDetail::GetMerchByShortName Error!!\n");
		iRet = INT_ERR;
	}
	

	return iRet;
	
}


int Verify_InitBal(const char* csInitBal)
{
	int iRet = PD_OK;
	int iCheck = PD_FALSE;
	

	char *csPos;
	char *p = (char*)strchr(csInitBal, '.');
DEBUGLOG(("  Verify_InitBal InitBal: [%s]\n",csInitBal));
/*reject negative amount*/
	if(csInitBal[0] == '-'){
		return PD_ERR;
	}
	
	csPos = (char *)csInitBal;

DEBUGLOG(("  Verify_InitBal Pos: [%c]\n", *csPos));
	if(p != NULL){
/*Prevent csInitBal is . */
		if(csInitBal[0] == '.'){
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}

		iCheck = is_numeric_r2(csPos);
		
		if (iCheck != PD_TRUE) {
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}
		
/*Prevent csInitBal is 1.*/
		if(*(p+1) == '\0'){
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}
		
		if(strlen(p+1) > 2){
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}
		
		iCheck = is_numeric(p+1);
		if (iCheck != PD_TRUE) {
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}
	}
	else{

		iCheck = is_numeric(csPos);
		if (iCheck != PD_TRUE) {
DEBUGLOG(("  Verify_InitBal [%s] Invalid\n",csInitBal));
			return PD_ERR;
		}
	}
DEBUGLOG(("  Verify_InitBal [%s] Valid\n",csInitBal));
	
	
	return iRet;
	
}



int is_numeric_r2(const char *csStr)
{
	while(*csStr != '.')
	{
DEBUGLOG(("  is_numeric_r2 [%c]\n",*csStr));
		if(*csStr < '0' || *csStr > '9'){
DEBUGLOG(("  is_numeric_r2 [%c] Invalid\n",*csStr));
			return PD_FALSE;
		}
		csStr++;
	}
	return PD_TRUE;
}




int MapRetCode(int* iRetCode)
{
	int iRet = PD_ERR;
DEBUGLOG(("  Before MapRetCode = [%d]\n",*iRetCode));
	if(*iRetCode == INT_BANK_ACCT_DUPLICATE){
		*iRetCode = INT_BANK_ACCT_NUM_DUPLICATE;
		iRet = PD_OK;
	}
	else if(*iRetCode == INT_EXISTING_ASSOCIATED_BAID_OPEN){
		*iRetCode = INT_EXISTING_ASSOCIATED_BAID_NOT_CLOSE;
		iRet = PD_OK;
	}
	else if(*iRetCode == INT_MOBILE_NUM_DUPLICATE){
		*iRetCode = INT_MOBILE_NUM_DUPLICATE;
		iRet = PD_OK;
	}

DEBUGLOG(("  After MapRetCode = [%d]\n", *iRetCode));
	return iRet;
}





