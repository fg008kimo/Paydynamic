/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/22		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"
#include "BOOLBankAccts.h"
#include "myrecordset.h"
#include "myhash.h"
#include "math.h"
#define __USE_XOPEN
#include <time.h>

static char cDebug;
OBJPTR(DB);

void BOOLBankAccts(char cdebug)
{
	cDebug = cdebug;
}

int GetLastUpdBankAcctsDetails(const char* csReqDatetime, 
			       const char* csBankCode, 
			       const char* csBankAcctNum,
			       int iMaxBankAcctCnt, 
			       recordset_t* rBankAcctsDetails)
{       
        int     iRet = PD_OK;
        int     iDtlRet = PD_FOUND;

	hash_t  *hRec = NULL;
    	recordset_t *rRecordset;
     	rRecordset = (recordset_t*) malloc (sizeof(recordset_t));
     	recordset_init(rRecordset, 0);

DEBUGLOG(("GetLastUpdBankAcctsDetails() Start\n"));
       
DEBUGLOG(("req_datetime = [%s]\n", csReqDatetime));
DEBUGLOG(("bank_code = [%s]\n", csBankCode));
DEBUGLOG(("bank_acct_num = [%s]\n", csBankAcctNum));
DEBUGLOG(("max_bank_acct_cnt = [%d]\n", iMaxBankAcctCnt));

	// Either bank_code and acct_num is NULL
       	if (((csBankCode == NULL) && (csBankAcctNum != NULL))
            || ((csBankCode != NULL) && (csBankAcctNum == NULL))
     	)
    	{
DEBUGLOG(("data request error!!\n"));
ERRLOG("TxnOiaByUsLUA::Authorize::data request error!!\n");
             	iRet=INT_DATA_REQUEST_ERROR;
    	} 
	// Both bank_code and acct_num are Not NULL
	else if ((csBankCode != NULL) && (csBankAcctNum != NULL)) 
	{

		// Check if System Bank Code
		if ((!strcmp(csBankCode, PD_SYS_BANK_CODE))
            	    || (!strcmp(csBankCode, PD_TW_SYS_BANK_CODE))
        	)
		{
DEBUGLOG(("[%s] is a system bank code!!\n", csBankCode));
     			iRet = INT_UNSUPPORTED_BANK_CODE;
		}
		
		// Check Bank Acct Exists
        	if (iRet == PD_OK) {
        	        DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","ChkBankAcctExists");
        	        iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum);
        	        if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("Call DBOLBankAccts::ChkBankAcctExists::Bank Acct Not Found!!\n"));
        	                iRet = INT_BANK_ACCT_NOT_FOUND;
        	        } else if (iDtlRet == 1) {
DEBUGLOG(("Call DBOLBankAccts::ChkBankAcctExists::Bank Acct Exists!!\n"));
        	        } else {
DEBUGLOG(("Call DBOLBankAccts::ChkBankAcctExists::Bank Acct Duplicated!!\n"));
ERRLOG("BOOLBankAccts::GetLastUpdBankAcctsDetails() Call DBOLBankAccts::ChkBankAcctExists:: Bank Acct Duplicated!!\n");
        	                iRet = INT_BANK_ACCT_DUPLICATE;
        	        }
        	}
	}

        // Get Details
        if (iRet == PD_OK) {

                DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetLastUpdBankAcctsDetails");                   
                iDtlRet = (unsigned long)(*DBObjPtr)(csReqDatetime, csBankCode, csBankAcctNum, iMaxBankAcctCnt, rRecordset);          
                if (iDtlRet == PD_FOUND) {                                                                                 
DEBUGLOG(("Call DBOLBankAccts::GetLastUpdBankAcctsDetails::Record(s) found!!\n")); 

			int     iBankAcctCnt = 0;

                        hash_t  *hBankAcctsDetails;

			hRec = RecordSet_GetFirst(rRecordset);
                        while ((hRec) && (iRet == PD_OK)) {

				char cTmp = ' ';
                                char *csTmp = NULL;
                                char *csRecEndInd = (char*) malloc (64);

				hBankAcctsDetails = (hash_t*) malloc (sizeof(hash_t));
                                hash_init(hBankAcctsDetails,0);

/* provider_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"provider_name",&csTmp)) {
DEBUGLOG((" [%d]provider_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"provider_name",csTmp);
                                        }
                                }

/* provider_id */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"provider_id",&csTmp)) {
DEBUGLOG((" [%d]provider_id = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"provider_id",csTmp);
                                        }
                                }

/* int_bank_code */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"int_bank_code",&csTmp)) {
DEBUGLOG((" [%d]int_bank_code = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"int_bank_code",csTmp);
                                        }
                                } else {
DEBUGLOG((" [%d]int_bank_code not found!!\n"));
ERRLOG("BOOLBankAccts::GetLastUpdBankAcctsDetails() Call DBOLBankAccts::GetLastUpdBankAcctsDetails::int_bank_code not found!!\n");
                                        iRet = INT_ERR;
                                }

/* bank_acct_num */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_acct_num",&csTmp)) {
DEBUGLOG((" [%d]bank_acct_num = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_acct_num",csTmp);
                                        }
                                } else {
DEBUGLOG((" [%d]bank_acct_num not found!!\n"));
ERRLOG("BOOLBankAccts::GetLastUpdBankAcctsDetails() Call DBOLBankAccts::GetLastUpdBankAcctsDetails::bank_acct_num not found!!\n");
                                        iRet = INT_ERR;
                                }

/* bank_acct_status */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_acct_status",&csTmp)) {
DEBUGLOG((" [%d]bank_acct_status = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_acct_status",csTmp);
                                        }
                                }

/* baid */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"baid",&csTmp)) {
DEBUGLOG((" [%d]baid = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"baid",csTmp);
                                        }
                                }

/* baid_status */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"baid_status",&csTmp)) {
DEBUGLOG((" [%d]baid_status = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"baid_status",csTmp);
                                        }
                                }

/* bank_acct_nature */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_acct_nature",&csTmp)) {
DEBUGLOG((" [%d]bank_acct_nature = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_acct_nature",csTmp);
                                        }
                                }

/* bank_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_name",&csTmp)) {
DEBUGLOG((" [%d]bank_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_name",csTmp);
                                        }
                                }

/* bank_abbrev_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_abbrev_name",&csTmp)) {
DEBUGLOG((" [%d]bank_abbrev_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_abbrev_name",csTmp);
                                        }
                                }

/* owner_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"owner_name",&csTmp)) {
DEBUGLOG((" [%d]owner_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"owner_name",csTmp);
                                        }
                                }

/* province */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"province",&csTmp)) {
DEBUGLOG((" [%d]province = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"province",csTmp);
                                        }
                                }

/* city */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"city",&csTmp)) {
DEBUGLOG((" [%d]city = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"city",csTmp);
                                        }
                                }

/* branch_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"branch_name",&csTmp)) {
DEBUGLOG((" [%d]branch_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"branch_name",csTmp);
                                        }
                                }

/* reg_mob_num */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"reg_mob_num",&csTmp)) {
DEBUGLOG((" [%d]reg_mob_num = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"reg_mob_num",csTmp);
                                        }
                                }

/* bank_acct_short_name */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_acct_short_name",&csTmp)) {
DEBUGLOG((" [%d]bank_acct_short_name = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_acct_short_name",csTmp);
                                        }
                                }

/* merchant_id */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"merchant_id",&csTmp)) {
DEBUGLOG((" [%d]merchant_id = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"merchant_id",csTmp);
                                        }
                                }

/* pid_bank_nature */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"pid_bank_nature",&csTmp)) {
DEBUGLOG((" [%d]pid_bank_nature = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"pid_bank_nature",csTmp);
                                        }
                                }

/* bank_upd_ts */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"bank_upd_ts",&csTmp)) {
DEBUGLOG((" [%d]bank_upd_ts = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"bank_upd_ts",csTmp);
                                        }
                                }

/* baid_upd_ts */
                                if (iRet == PD_OK) {
                                        if (GetField_CString(hRec,"baid_upd_ts",&csTmp)) {
DEBUGLOG((" [%d]baid_upd_ts = [%s]\n", iBankAcctCnt, csTmp));
                                                PutField_CString(hBankAcctsDetails,"baid_upd_ts",csTmp);
                                        }
                                }

/* rec_end_ind */
				if (iRet == PD_OK) {
					if (GetField_Char(hRec,"rec_end_ind",&cTmp)) {
                                                sprintf(csRecEndInd, "%c", cTmp);
DEBUGLOG((" [%d]rec_end_ind = [%s]\n", iBankAcctCnt, csRecEndInd));
                                                PutField_CString(hBankAcctsDetails,"rec_end_ind",csRecEndInd);
                                        } else {
DEBUGLOG((" [%d]rec_end_ind not found!!\n"));
ERRLOG("BOOLBankAccts::GetLastUpdBankAcctsDetails() Call DBOLBankAccts::GetLastUpdBankAcctsDetails::rec_end_ind not found!!\n");
                                                iRet = INT_ERR;
                                        }
				}

				RecordSet_Add(rBankAcctsDetails,hBankAcctsDetails);
                                iBankAcctCnt++;
                                
				FREE_ME(csRecEndInd);

                                hRec = RecordSet_GetNext(rRecordset);
			}
                                            
                } else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("Call DBOLBankAccts::GetLastUpdBankAcctsDetails::Record(s) not found!!\n"));                                                                 
                        iRet = INT_RECORD_NOT_FOUND;                                                                                                              
                } else {                                                                                                                                           
DEBUGLOG(("Call DBOLBankAccts::GetLastUpdBankAcctsDetails Failure!!\n"));
ERRLOG("BOOLBankAccts::GetLastUpdBankAcctsDetails() Call DBOLBankAccts::GetLastUpdBankAcctsDetails Failure!!\n");                                                          
                        iRet = INT_ERR;
                }                                                                                                                                                                          
        }

	RecordSet_Destroy(rRecordset);
       	FREE_ME(rRecordset);
        
DEBUGLOG(("GetLastUpdBankAcctsDetails() Exit iRet = [%d]\n", iRet));
        return iRet;                                                                                                                                                                        }

int GetBankAcctLatestDetails(const char* csBankCode, 
			     const char* csBankAcctNum, 
			     hash_t* hBankAcctDetails)
{
        int     iRet = PD_OK;
        int     iDtlRet = PD_FOUND;

DEBUGLOG(("GetBankAcctLatestDetails() Start\n"));

DEBUGLOG(("bank_code = [%s]\n", csBankCode));
DEBUGLOG(("bank_acct_num = [%s]\n", csBankAcctNum));

	// Check if System Bank Code
	if ((!strcmp(csBankCode, PD_SYS_BANK_CODE))
	    || (!strcmp(csBankCode, PD_TW_SYS_BANK_CODE))
	)
	{
DEBUGLOG(("[%s] is a system bank code!!\n", csBankCode));
        	iRet = INT_UNSUPPORTED_BANK_CODE;
	}

	// Check Bank Acct Exists
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","ChkBankAcctExists");
                iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum);
		if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("Call DBOLBankAccts::ChkBankAcctExists::Bank Acct Not Found!!\n"));
			iRet = INT_BANK_ACCT_NOT_FOUND;
              	} else if (iDtlRet == 1) {
DEBUGLOG(("Call DBOLBankAccts::ChkBankAcctExists::Bank Acct Exists!!\n"));
             	} else {
DEBUGLOG(("CALL DBOLBankAccts::ChkBankAcctExists::Bank Acct Duplicated!!\n"));
ERRLOG("BOOLBankAccts::GetBankAcctLatestDetails() Call DBOLBankAccts::ChkBankAcctExists:: Bank Acct Duplicated!!\n");
                   	iRet = INT_BANK_ACCT_DUPLICATE;
            	}
	}	

	// Get Details
	if (iRet == PD_OK) {
        	DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAcctLatestDetails");
        	iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hBankAcctDetails);
        	if (iDtlRet == PD_FOUND) {
DEBUGLOG(("Call DBOLBankAccts::GetBankAcctLatestDetails::Record found!!\n"));
        	} else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("Call DBOLBankAccts::GetBankAcctLatestDetails::Record not found!!\n"));
			iRet = INT_RECORD_NOT_FOUND;
       	 	} else {
DEBUGLOG(("Call DBOLBankAccts::GetBankAcctLatestDetails Failure!!\n"));
ERRLOG("BOOLBankAccts::GetBankAcctLatestDetails() Call DBOLBankAccts::GetBankAcctLatestDetails Failure!!\n");
			iRet = INT_ERR;
        	}
	}

DEBUGLOG(("GetBankAcctLatestDetails() Exit iRet = [%d]\n", iRet));
        return iRet;
}

