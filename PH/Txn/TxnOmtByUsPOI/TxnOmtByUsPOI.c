/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/09              LokMan Chow
Add Duplicated File Name Checking		   2017/09/19		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsPOI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	GRP_COUNT 4

char    csCharSet[GRP_COUNT]={'A','B','C','D'};

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnOmtByUsPOI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	char	*csFileName;
	char	*csMerchantId;
	char	csPayoutFile[PD_MAX_FILE_LEN+1];
	char	csFileRename[PD_TMP_BUF_LEN+1];
	char	csNewPath[PD_MAX_FILE_LEN+1];
	FILE    *fp;
	int	iTmp;
	int	iRemove = -1;
	int	iRename = -1;
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

DEBUGLOG(("Authorize\n"));

/* merchant_id */
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
		PutField_CString(hTxn,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize: merchant_id[%s]\n",csMerchantId));
	}
	else{
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: merchant_id is missing!!!!\n"));
	}

/* service_code */
	if(GetField_CString(hRequest,"service_code",&csTmp)){
		PutField_CString(hTxn,"service_code",csTmp);
DEBUGLOG(("Authorize: service_code[%s]\n",csTmp));
	}
	else{
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: service_code is missing!!!!\n"));
	}

/* country */
	if(GetField_CString(hRequest,"txn_country",&csTmp)){
		PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("Authorize: txn_country[%s]\n",csTmp));
	}
	else{
		iRet = INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: txn_country is missing!!!!\n"));
	}

/* currency */
	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
		PutField_CString(hTxn,"txn_ccy",csTmp);
DEBUGLOG(("Authorize: txn_ccy[%s]\n",csTmp));
	}
	else{
		iRet = INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: txn_ccy is missing!!!!\n"));
	}

/* file_name */
	if(GetField_CString(hRequest,"filename",&csFileName)){
		PutField_CString(hTxn,"filename",csFileName);
DEBUGLOG(("Authorize: filename[%s]\n",csFileName));
	}
	else{
                iRet = INT_FILE_NAME_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: filename is missing!!!!\n"));
        }

/* user */
        if(GetField_CString(hRequest,"add_user",&csTmp)){
                PutField_CString(hTxn,"add_user",csTmp);
DEBUGLOG(("Authorize: add_user[%s]\n",csTmp));
        }
        else{
                iRet = INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: add_user is missing!!!!\n"));
        }

/* PHDATE */
        if(GetField_CString(hContext,"PHDATE",&csTmp)){
                PutField_CString(hTxn,"posting_date",csTmp);
                PutField_Int(hTxn,"day_of_week",day_of_week((const unsigned char *)csTmp));
DEBUGLOG(("Authorize: posting_date[%s]\n",csTmp));
        }

	// Process Payout File
	if (iRet != INT_FILE_NAME_NOT_FOUND) {
		char *s;
		int iLoop = PD_TRUE;
		int pos = 0;
		while(iLoop){
			s = strrchr(csFileName,csCharSet[pos]);
			if(s==NULL){
				pos++;
				if(pos>=GRP_COUNT)
					iLoop = PD_FALSE;
			}
			else{
				PutField_Char(hTxn,"merchant_group",csCharSet[pos]);
DEBUGLOG(("Authorize: merchant_group = [%c]\n",csCharSet[pos]));
				break;
			}
		}

		sprintf(csPayoutFile,"%s/input/off/%s",getenv("OUTPUT_PAYOUT"),csFileName);
		PutField_CString(hTxn,"payout_file_fullpath",csPayoutFile);

		// Check Duplicated File Name
DEBUGLOG(("Authorize:: Call DBOLMerchantUploadFileHeader:: CheckDuplicateFileName \n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLMerchantUploadFileHeader", "CheckDuplicateFileName");
                if ((unsigned long)(*DBObjPtr)(csFileName,csMerchantId) == PD_FOUND) {
               		iRet = INT_FILE_NAME_ALREADY_EXIST;
                	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: filename is duplicated!!!!\n"));
		}
	}

	// Process Payout Records
	if(iRet == PD_OK){
		fp = fopen(csPayoutFile, "r");
                if (fp == NULL) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: payout file cannot be opened!!!!\n"));
		}
		else{
			fclose(fp);
DEBUGLOG(("Authorize:: Process payout file\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLPayout","ProcessPayoutRecords");
			iRet = (unsigned long)(*BOObjPtr)(fp,hContext,hRequest,hTxn);
DEBUGLOG(("Authorize:: Process payout file result = [%d]\n",iRet));
		}
	}

	// Rename File
	if(iRet == PD_OK){
		iTmp = 0;
		GetField_Int(hTxn,"total_txn_cnt",&iTmp);
		PutField_Int(hResponse,"success_cnt",iTmp);
		iTmp = 0;
		GetField_Int(hTxn,"total_fail_cnt",&iTmp);
		PutField_Int(hResponse,"fail_cnt",iTmp);
		iTmp = 0;
		GetField_Int(hTxn,"detail_count",&iTmp);
		PutField_Int(hResponse,"upload_cnt",iTmp);

		if(GetField_CString(hTxn,"batch_id",&csTmp)){
			PutField_CString(hResponse,"batch_id",csTmp);

			sprintf(csFileRename,"%s_%s",csTmp,csFileName);
			sprintf(csNewPath,"%s/input/off/%s",getenv("OUTPUT_PAYOUT"),csFileRename);
			iRename = rename(csPayoutFile,csNewPath);
			if(!iRename){
DEBUGLOG(("Authorize:: payout file renamed\n"));
			}
			else{
DEBUGLOG(("Authorize:: payout file cannot be renamed!!!!\n"));
			}
		}
	}
	// Remove File
	else{
		if (iRet != INT_FILE_NAME_NOT_FOUND) {
			iRemove = remove(csPayoutFile);
			if(!iRemove){
DEBUGLOG(("Authorize:: payout file removed\n"));
			}
			else{
DEBUGLOG(("Authorize:: payout file cannot be removed!!!!\n"));
			}
		}
	}
	
	FREE_ME(hTxn);
DEBUGLOG(("TxnOmtByUsPOI Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
