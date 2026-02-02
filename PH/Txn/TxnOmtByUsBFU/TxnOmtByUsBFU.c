/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/12/07              [ZBL]
PRD314
 - Revise the calculation of total counts          2021/03/19              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsBFU.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_FIELD_SIZE_DEFAULT	5
#define PD_FIELD_SIZE_OPTIONAL	3
#define PD_FILE_DELIMITER	","

static char cDebug;
OBJPTR(DB);

char *csHeaderFields[PD_FIELD_SIZE_DEFAULT] = {
	"Bank Name (Sender)", 
	"Bank Account Number (Sender)", 
	"Sweep Out Amount", 
	"Bank Name (Recipient)", 
	"Bank Account Number (Recipient)"
};

void TxnOmtByUsBFU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char		cStatus;
	char		csConvertFile[PD_TMP_BUF_LEN];
	char		csConvertFilePath[PD_TMP_BUF_LEN];
	char		csFullConvertFilePath[PD_TMP_BUF_LEN];
	char		csFullRawFilePath[PD_TMP_BUF_LEN];
	char		csInputBuf[PD_TMP_MSG_BUF_LEN];
	char		csRawFilePath[PD_TMP_BUF_LEN];
	char		csTmpBuf[PD_TMP_MSG_BUF_LEN];
	char		*csCmd = (char*)malloc(PD_TMP_MSG_BUF_LEN);
	char		*csFilePath = NULL;
	char		*csHeader = NULL;
	char		*csRawFile = NULL;
	char		*csTmp = NULL;
	char		*csUser = NULL;
	int		iCnt = 0;
	int		iDtlRet = PD_ERR;
	int		iHeaderField = 0;
	int		iRet = PD_OK;
	int		iUseDummyAcct = PD_FALSE;
	unsigned long	lFileId;
	FILE		*fFile = NULL;
	hash_t		*hBaidBTFHeader;

	hBaidBTFHeader = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBaidBTFHeader, 0);

DEBUGLOG(("TxnOmtByUsBFU::Authorize\n"));

	/* user */
	if (GetField_CString(hContext, "add_user", &csUser))
	{
DEBUGLOG(("- add_user = [%s]\n", csUser));
	}
	else
	{
DEBUGLOG(("- add_user not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: add_user not found!!\n");

		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// Check "in_file_path" Is Valid Or Not (Accept a-z, A-Z, 0-9. "/", "-" And "_" Characters Only)
	/* in_file_path */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "in_file_path", &csFilePath))
		{
DEBUGLOG(("- in_file_path = [%s]\n", csFilePath));

			if (IsValidPath(csFilePath, PD_TRUE) == PD_ERR)
			{
DEBUGLOG(("- in_file_path contain invalid characters!! Not match [ a-z | A-Z | 0-9 | / | - | _ ]!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: in_file_path contain invalid characters!! Not match [ a-z | A-Z | 0-9 | / | - | _ ]!!\n");

				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
		else
		{
DEBUGLOG(("- in_file_path not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: in_file_path not found!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	/* file_id */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "file_id", &csTmp))
		{
DEBUGLOG(("- file_id = [%s]\n", csTmp));

			PutField_CString(hBaidBTFHeader, "file_id", csTmp);
			lFileId = (unsigned long)ctol((const unsigned char*)csTmp, strlen(csTmp));
		}
		else
		{
DEBUGLOG(("- file_id not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: file_id not found!!\n");

			iRet = INT_FILE_ID_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Get Use Dummy Account, Status and Raw Filename By "file_id" From Offline Baid Bal Trf File
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::GetHeaderByFileId\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBaidBalTrfFile", "GetHeaderByFileId");
		iDtlRet = (unsigned long)(DBObjPtr)(lFileId, hBaidBTFHeader);

DEBUGLOG(("- DBOLBaidBalTrfFile::GetHeaderByFileId iRet = [%d]\n", iDtlRet));

		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::GetHeaderByFileId Found!!\n"));

			/* use_dummy_acct */
			if (GetField_Int(hBaidBTFHeader, "use_dummy_acct", &iUseDummyAcct))
			{
DEBUGLOG(("- use_dummy_acct = [%d]\n", iUseDummyAcct));
			}
			else
			{
DEBUGLOG(("- use_dummy_acct not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::GetHeaderByFileId use_dummy_acct not found!!\n");

				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// Check "receiver_baid" Exist Or Not If "use_dummy_acct" Is Enabled
			/* receiver_baid */
			if (iRet == PD_OK && iUseDummyAcct == PD_TRUE)
			{
				if (GetField_CString(hBaidBTFHeader, "receiver_baid", &csTmp))
				{
DEBUGLOG(("- receiver_baid = [%s]\n", csTmp));
					RemoveField_CString(hBaidBTFHeader, "receiver_baid");
				}
				else
				{
DEBUGLOG(("- receiver_baid not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::GetHeaderByFileId receiver_baid not found!!\n");

					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}

			// Check "raw_filename" Is Valid Or Not (Accept a-z, A-Z, 0-9, ".", "-" And "_" Characters Only)
			/* raw_filename */
			if (iRet == PD_OK)
			{
				if (GetField_CString(hBaidBTFHeader, "raw_filename", &csRawFile))
				{
DEBUGLOG(("- raw_filename = [%s]\n", csRawFile));
					RemoveField_CString(hBaidBTFHeader, "raw_filename");

					if (IsValidPath(csRawFile, PD_FALSE) == PD_ERR)
					{
DEBUGLOG(("- raw_filename contain invalid characters!! Not match [ a-z | A-Z | 0-9 | . | - | _ ]!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: raw_filename contain invalid characters!! Not match [ a-z | A-Z | 0-9 | . | - | _ ]!!\n");

						iRet = INT_INVALID_FILE_FORMAT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}
				else
				{
DEBUGLOG(("- raw_filename not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::GetHeaderByFileId raw_filename not found!!\n");

					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}

			// Check Status That Should Be Initialized
			/* status */
			if (iRet == PD_OK)
			{
				if (GetField_Char(hBaidBTFHeader, "status", &cStatus))
				{
DEBUGLOG(("- status = [%c]\n", cStatus));
					RemoveField_Char(hBaidBTFHeader, "status");

					if (cStatus != PD_BAID_BAL_TRF_FILE_STATUS_INIT)
					{
DEBUGLOG(("- Status is not expected value!!\n"));

						iRet = INT_INVALID_INIT_STATUS;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}
				else
				{
DEBUGLOG(("- status not found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::GetHeaderByFileId status not found!!\n");

					iRet = INT_ERR;	// INT_STATUS_NOT_FOUND
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
		}
		else
		{
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::GetHeaderByFileId Error!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::GetHeaderByFileId Error!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Check "raw_filename" Can Be Opened Or Not
	if (iRet == PD_OK)
	{
		memset(csRawFilePath, 0, PD_TMP_BUF_LEN);
		memset(csFullRawFilePath, 0, PD_TMP_BUF_LEN);

		snprintf(csRawFilePath, sizeof(csRawFilePath), "%s/%s", csFilePath, PD_BAID_BAL_TRF_FILE_RAW);
		snprintf(csFullRawFilePath, sizeof(csFullRawFilePath), "%s/%s", csRawFilePath, csRawFile);

DEBUGLOG(("- Full path of raw file = [%s]!!\n", csFullRawFilePath));

		fFile = fopen(csFullRawFilePath, "r");

		if (fFile == NULL)
		{
DEBUGLOG(("- Cannot open raw file [%s]!!\n", csRawFile));
ERRLOG("TxnOmtByUsBFU::Authorize:: Cannot open raw file [%s]!!\n", csRawFile);

			iRet = INT_FAIL_TO_READ_FILE;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else
		{
			fclose(fFile);
			fFile = NULL;
		}
	}

	// Convert Raw File By Script "bfu_init_convert.sh"
	if (iRet == PD_OK)
	{
		memset(csTmpBuf, 0, PD_TMP_MSG_BUF_LEN);
		memset(csConvertFile, 0, PD_TMP_BUF_LEN);
		memset(csConvertFilePath, 0, PD_TMP_BUF_LEN);
		memset(csFullConvertFilePath, 0, PD_TMP_BUF_LEN);

		sprintf(csTmpBuf, "%014lu", lFileId);
		snprintf(csConvertFile, sizeof(csConvertFile), "BF%s", csTmpBuf);
		snprintf(csConvertFilePath, sizeof(csConvertFilePath), "%s/%s", csFilePath, PD_BAID_BAL_TRF_FILE_CONVERTED);
		snprintf(csFullConvertFilePath, sizeof(csFullConvertFilePath), "%s/%s", csConvertFilePath, csConvertFile);

DEBUGLOG(("- Full path of converted file = [%s]!!\n", csFullConvertFilePath));

		fFile = fopen(csFullConvertFilePath, "r");

		if (fFile == NULL)
		{
			memset(csCmd, 0, PD_TMP_MSG_BUF_LEN);
			snprintf(csCmd, PD_TMP_MSG_BUF_LEN, "bfu_init_convert.sh \"%s\" \"%s\" \"%s\" \"%s\"", csRawFilePath, csConvertFilePath, csRawFile, csConvertFile);

DEBUGLOG(("- TxnOmtByUsBFU::Authorize Calling System Job [%s] To Convert BAID Balance Transfer File!!\n", csCmd));
			system(csCmd);
		}
		else
		{
			fclose(fFile);
			fFile = NULL;

DEBUGLOG(("- Converted file [%s] exists already!!\n", csConvertFile));
ERRLOG("TxnOmtByUsBFU::Authorize:: Converted file [%s] exists already!!\n", csConvertFile);

			iRet = INT_FILE_ALREADY_EXIST;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Check The Mandatory Raw Header And Calculate How Many Records In BAID Balance Transfer File
	if (iRet == PD_OK)
	{
		fFile = fopen(csFullConvertFilePath, "r");

		if (fFile == NULL)
		{
DEBUGLOG(("- Cannot open converted file [%s]!!\n", csConvertFile));
ERRLOG("TxnOmtByUsBFU::Authorize:: Cannot open converted file [%s]!!\n", csConvertFile);

			iRet = INT_FAIL_TO_READ_FILE;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else
		{
			/* convert_filename */
			PutField_CString(hBaidBTFHeader, "convert_filename", csConvertFile);

			// Check The Mandatory Raw Header
			memset(csInputBuf, 0, PD_TMP_MSG_BUF_LEN);
			memset(csTmpBuf, 0, PD_TMP_MSG_BUF_LEN);

			fgets(csInputBuf, sizeof(csInputBuf), fFile);

			// Replace LF (NL Line Feed) To '\0'
			if (csInputBuf[strlen(csInputBuf) - 1] == 0x0A)
				csInputBuf[strlen(csInputBuf) - 1] = '\0';

			// Replace CR (Carriage Return) To '\0'
			if (csInputBuf[strlen(csInputBuf) - 1] == 0x0D)
				csInputBuf[strlen(csInputBuf) - 1] = '\0';

DEBUGLOG(("- Header = [%s]\n", csInputBuf));

			// Check The Numbers Of Raw Header (Should be 5 Fields)
			// All Of Header Fields Must Be Matched No Matter "use_dummy_acct" Is Enabled Or Not
			strcpy(csTmpBuf, csInputBuf);
			csHeader = mystrtok(csTmpBuf, PD_FILE_DELIMITER);

			if (csHeader != NULL)
			{
				while (csHeader != NULL)
				{
					if (iCnt >= PD_FIELD_SIZE_DEFAULT)
					{
DEBUGLOG(("- Invalid Header Size!! Header size [%d+] is not equal to [%d]!!\n", iCnt, PD_FIELD_SIZE_DEFAULT));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header Size!! Header size [%d+] is not equal to [%d]!!\n", iCnt, PD_FIELD_SIZE_DEFAULT);

						iRet = INT_INVALID_FILE_FORMAT_ERR;
						PutField_Int(hContext, "internal_error", iRet);

						break;
					}

					// Trim Out All Of Leading And Trailing Whitespace
					strcpy(csHeader, TrimAll((const unsigned char*)csHeader, strlen(csHeader)));

					if (csHeader == NULL || strcmp(csHeader, csHeaderFields[iCnt]))
					{
DEBUGLOG(("- Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]);

						iRet = INT_INVALID_FILE_FORMAT_ERR;
						PutField_Int(hContext, "internal_error", iRet);

						break;
					}

					csHeader = mystrtok(NULL, PD_FILE_DELIMITER);
					iCnt++;
				}

				if (iRet == PD_OK && iCnt != PD_FIELD_SIZE_DEFAULT)
				{
DEBUGLOG(("- Invalid Header Size!! Header size [%d] is not equal to [%d]!!\n", iCnt, PD_FIELD_SIZE_DEFAULT));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header Size!! Header size [%d] is not equal to [%d]!!\n", iCnt, PD_FIELD_SIZE_DEFAULT);

					iRet = INT_INVALID_FILE_FORMAT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
			else
			{
DEBUGLOG(("- Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]);

				iRet = INT_INVALID_FILE_FORMAT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
/*
			// Parts Of Header Fields Must Be Matched (First 3 Fields) If "use_dummy_acct" Is Enabled
			// All Of Header Fields Must Be Matched
			if (iRet == PD_OK)
			{
				iCnt = 0;
				iHeaderField = (iUseDummyAcct == PD_TRUE) ? PD_FIELD_SIZE_OPTIONAL : PD_FIELD_SIZE_DEFAULT;
DEBUGLOG(("- Header Size = [%d], Use Dummy Account = [%d]\n", iHeaderField, iUseDummyAcct));

				memset(csTmpBuf, 0, PD_TMP_MSG_BUF_LEN);
				strcpy(csTmpBuf, csInputBuf);

				csHeader = mystrtok(csTmpBuf, PD_FILE_DELIMITER);

				while (iCnt < iHeaderField)
				{
					// Trim Out All Of Leading And Trailing Whitespace
					if (csHeader != NULL)
						strcpy(csHeader, TrimAll((const unsigned char*)csHeader, strlen(csHeader)));

					if (csHeader == NULL || strcmp(csHeader, csHeaderFields[iCnt]))
					{
DEBUGLOG(("- Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]);

						iRet = INT_INVALID_FILE_FORMAT_ERR;
						PutField_Int(hContext, "internal_error", iRet);

						break;
					}

					csHeader = mystrtok(NULL, PD_FILE_DELIMITER);
					iCnt++;
				}
			}
*/
/*
			// All Of Header Fields Must Be Matched No Matter "use_dummy_acct" Is Enabled Or Not
			if (iRet == PD_OK)
			{
				iCnt = 0;
				iHeaderField = PD_FIELD_SIZE_DEFAULT;

				memset(csTmpBuf, 0, PD_TMP_MSG_BUF_LEN);
				strcpy(csTmpBuf, csInputBuf);

				csHeader = mystrtok(csTmpBuf, PD_FILE_DELIMITER);

				while (iCnt < iHeaderField)
				{
					// Trim Out All Of Leading And Trailing Whitespace
					if (csHeader != NULL)
						strcpy(csHeader, TrimAll((const unsigned char*)csHeader, strlen(csHeader)));

					if (csHeader == NULL || strcmp(csHeader, csHeaderFields[iCnt]))
					{
DEBUGLOG(("- Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]));
ERRLOG("TxnOmtByUsBFU::Authorize:: Invalid Header!! [%s] not match [%s]!!\n", csHeader, csHeaderFields[iCnt]);

						iRet = INT_INVALID_FILE_FORMAT_ERR;
						PutField_Int(hContext, "internal_error", iRet);

						break;
					}

					csHeader = mystrtok(NULL, PD_FILE_DELIMITER);
					iCnt++;
				}
			}
*/
			// Calculate How Many Records In BAID Balance Transfer File
			if (iRet == PD_OK)
			{
				iCnt = 0;

				while (fgets(csInputBuf, sizeof(csInputBuf), fFile) != NULL)
				{
					// Replace LF (NL Line Feed) To '\0'
					if (csInputBuf[strlen(csInputBuf) - 1] == 0x0A)
						csInputBuf[strlen(csInputBuf) - 1] = '\0';

					// Replace CR (Carriage Return) To '\0'
					if (csInputBuf[strlen(csInputBuf) - 1] == 0x0D)
						csInputBuf[strlen(csInputBuf) - 1] = '\0';

					/* PRD3314 Enhance BAID Balance Transfer File Upload Function */
					// Sequence Must Match The Upload File Row Number So It Cannot Ignore The Blank
/*
					if (!strcmp(csInputBuf, ""))
						continue;
*/
					/* End - PRD314 Enhance BAID Balance Transfer File Upload Function */

					iCnt++;
				}

				/* total_count */
				if (iCnt > 0)
					PutField_Int(hBaidBTFHeader, "total_count", iCnt);
/*
				else
				{
DEBUGLOG(("- No Records Found!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: No Records Found!!\n");

					iRet = INT_ALL_REJECTED;
					PutField_Int(hContext, "internal_error", iRet);
				}
*/
			}

			fclose(fFile);
			fFile = NULL;
		}
	}

	// Prepare To Updating Balance Transfer File Header
	if (iRet != INT_FILE_ID_NOT_FOUND && GetField_CString(hBaidBTFHeader, "file_id", &csTmp))
	{
		/* status / msg_code */
		if (iRet != PD_OK)
		{
			PutField_Char(hBaidBTFHeader, "status", PD_BAID_BAL_TRF_FILE_STATUS_DECLINED);
			PutField_Int(hBaidBTFHeader, "msg_code", iRet);
		}

		// Update BAID Balance Transfer File Header
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::UpdateHeader\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBaidBalTrfFile", "UpdateHeader");
		iDtlRet = (unsigned long)(DBObjPtr)(hBaidBTFHeader);

		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::UpdateHeader Success!!\n"));
			TxnCommit();
		}
		else
		{
DEBUGLOG(("- Calling DBOLBaidBalTrfFile::UpdateHeader Failure!!\n"));
ERRLOG("TxnOmtByUsBFU::Authorize:: Calling DBOLBaidBalTrfFile::UpdateHeader Failure!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Call System Job To Run BAID Balance Transfer - Intra In Background
	if (iRet == PD_OK)
	{
		memset(csCmd, 0, PD_TMP_MSG_BUF_LEN);
		snprintf(csCmd, PD_TMP_MSG_BUF_LEN, "ol_baid_bt_file.sh %lu %s &", lFileId, csFilePath);

DEBUGLOG(("- TxnOmtByUsBFU::Authorize Calling System Job [%s] To Run BAID Balance Transfer File In Background!!\n", csCmd));
		system(csCmd);
	}

	FREE_ME(csCmd);

	hash_destroy(hBaidBTFHeader);
	FREE_ME(hBaidBTFHeader);

DEBUGLOG(("TxnOmtByUsBFU Normal Exit() iRet = [%d]\n", iRet));
	return iRet;	
}

int IsValidPath(char *csPath, int isPath)
{
	char *csTmp = NULL;

	csTmp = csPath;

	while (*csTmp)
	{
		if (isPath == PD_TRUE)
		{
			if (!(*csTmp >= 'a' && *csTmp <= 'z') && 
			    !(*csTmp >= 'A' && *csTmp <= 'Z') && 
			    !(*csTmp >= '0' && *csTmp <= '9') && 
			    !(*csTmp == '/' || *csTmp == '-' || *csTmp == '_'))
				return PD_ERR;
		}
		else
		{
			if (!(*csTmp >= 'a' && *csTmp <= 'z') && 
			    !(*csTmp >= 'A' && *csTmp <= 'Z') && 
			    !(*csTmp >= '0' && *csTmp <= '9') && 
			    !(*csTmp == '.' || *csTmp == '-' || *csTmp == '_'))
				return PD_ERR;
		}

		csTmp++;
	}

	return PD_OK;
}
