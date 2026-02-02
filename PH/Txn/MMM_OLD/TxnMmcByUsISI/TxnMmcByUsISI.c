/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/03/05              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsISI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsISI(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iHasNextStlBankId = PD_OK;

	char	cQueryType;
	char	*csStlBankId = NULL;
	char	*csLastId = NULL;
	char	*csMmcId = NULL;
	int	iMaxRtn = PD_TXN_IPY_MAX_RECORD;
	
	char	*csTmp = NULL;
	int	iTmp = 0;

        char    csTag[PD_TAG_LEN +1];
	char	csStartStlBankId[PD_BANK_ID_LEN  + 1];

        hash_t *hRec;
        recordset_t     *rRecordSet;

        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	/* single or multiple */
	if (GetField_Char(hContext, "query_type", &cQueryType)) {
DEBUGLOG(("Authorize::query_type = [%c]\n",cQueryType));
	}
	else {
DEBUGLOG(("Authorize::query_type not found!!\n"));
ERRLOG("TxnMmcByUsISI::Authorize::query_type not found!!\n");
		iRet = INT_ERR;

		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hContext, "server_node", &csMmcId)) {
DEBUGLOG(("Authorize::server node_id = [%s]\n",csMmcId));
	}
	else {
DEBUGLOG(("Authorize::server node_id not found!!\n"));
ERRLOG("TxnMmcByUsISI::Authorize::server node_id not found!!\n");
		iRet = INT_ERR;

		PutField_Int(hContext, "internal_error", iRet);
	}


	if (GetField_CString(hRequest,"last_id", &csLastId)) {
DEBUGLOG(("Authorize::last_id = [%s]\n", csLastId));

DEBUGLOG(("Authorize::Call DBMmsStlBankDetail: GetNextStlBankId\n"));

		memset(csStartStlBankId, 0, sizeof(csStartStlBankId));

                DBObjPtr = CreateObj(DBPtr,"DBMmsStlBankDetail","GetNextStlBankId");
		iHasNextStlBankId = (unsigned long)((*DBObjPtr)(csLastId, &csStartStlBankId));

		if (iHasNextStlBankId == PD_OK) {
DEBUGLOG(("Authorize::GetNextStlBankId Succ [%s]\n", csStartStlBankId));
			PutField_CString(hContext, "start_stl_bank_id", csStartStlBankId);
                }
                else if (iHasNextStlBankId == PD_NOT_FOUND) {
DEBUGLOG(("Authorize::GetNextStlBankId Fail - no more Stl Bank id\n"));
		}
		else {
DEBUGLOG(("Authorize::GetNextStlBankId Fail\n"));
ERRLOG("TxnMmcByUsISI::Authorize::GetNextStlBankId Fail!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	if (iRet == PD_OK) {
		if (cQueryType == PD_MMS_SINGLE_QUERY) {
			if (GetField_CString(hContext, "stl_bank_id", &csStlBankId)) {
DEBUGLOG(("Authorize::bank_id = [%s]\n",csStlBankId));
			}
			else {
DEBUGLOG(("Authorize::bank_id not found!!\n"));
ERRLOG("TxnMmcByUsISI::Authorize::bank_id not found!!\n");
				iRet = INT_BANK_ID_NOT_FOUND;

				PutField_Int(hContext, "internal_error", iRet);
			}
		} 
		else {
			if (GetField_Int(hContext, "max_rtn", &iMaxRtn)) {
DEBUGLOG(("Authorize::max_rtn = [%d]\n",iMaxRtn));
			}
		}
	}

	if (iRet == PD_OK) {

		if (cQueryType == PD_MMS_SINGLE_QUERY) {    // Single
DEBUGLOG(("Authorize::Call DBMmsStlBankDetail: GetStlBankDetail\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMmsStlBankDetail","GetStlBankDetail");
			if ((unsigned long)((*DBObjPtr)(csStlBankId, hContext)) == PD_OK) {

				iTmp++;

				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "party_id_%d", iTmp);
				PutField_CString(hResponse, csTag, csStlBankId);
DEBUGLOG(("Authorize::GetStlBankDetail [%d] party_id = [%s]\n", iTmp, csStlBankId));

				if (GetField_CString(hContext, "stl_bank_name", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "party_name_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetStlBankDetail [%d] party_name = [%s]\n", iTmp, csTmp));
				}

				if (GetField_CString(hContext, "stl_bank_acct", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "bank_acct_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetStlBankDetail [%d] bank_acct = [%s]\n", iTmp, csTmp));
				}
				
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "mms_node_id_%d", iTmp);
				PutField_CString(hResponse, csTag, csMmcId);
DEBUGLOG(("Authorize::GetStlBankDetail [%d] mms_node_id= [%s]\n", iTmp, csMmcId));

				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
			} 
			else {
DEBUGLOG(("Authorize::Call DBMmsStlBankDetail: GetStlBankDetail Fail\n"));
ERRLOG("TxnMmcByUsISI::Authorize::Call DBMmsStlBankDetail: GetStlBankDetail Fail!!\n");
				iRet = PD_ERR;

				PutField_Int(hContext, "internal_error", iRet);
			}
		
		}
		else {  // Multiple

			if (iHasNextStlBankId == PD_OK) {

DEBUGLOG(("Authorize::Call DBMmsStlBankDetail: GetStlBankDetailbyRange\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsStlBankDetail","GetStlBankDetailbyRange");

				if ((unsigned long)((*DBObjPtr)(hContext, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsStlBankDetail:GetStlBankDetailbyRange Failed\n"));
ERRLOG("TxnMmcByUsISI::Authorize::DBMmsStlBankDetail:GetStlBankDetailbyRange Failed\n");
					iRet=INT_ERR;

					PutField_Int(hContext, "internal_error", iRet);
				}	
				else {

					PutField_Int(hResponse, "total_cnt", iTmp);
					PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);

					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						iTmp++;

						if (iTmp <= iMaxRtn) {

							if (GetField_CString(hRec, "stl_bank_id", &csTmp)) {
								memset(csTag, 0, sizeof(csTag));
								sprintf(csTag, "party_id_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetStlBankDetailbyRange [%d] party_id = [%s]\n", iTmp, csTmp));
							}

							if (GetField_CString(hRec, "stl_bank_name", &csTmp)) {
								memset(csTag, 0, sizeof(csTag));
								sprintf(csTag, "party_name_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetStlBankDetailbyRange [%d] party_name = [%s]\n", iTmp, csTmp));
							}

							if (GetField_CString(hRec, "stl_bank_acct", &csTmp)) {
								memset(csTag, 0, sizeof(csTag));
								sprintf(csTag, "bank_acct_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetStlBankDetailbyRange [%d] bank_acct = [%s]\n", iTmp, csTmp));
							}

							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "mms_node_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csMmcId);
DEBUGLOG(("Authorize::GetStlBankDetailbyRange [%d] mms_node_id= [%s]\n", iTmp, csMmcId));

							PutField_Int(hResponse, "total_cnt", iTmp);
						}
						else {
							PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_PENDING);
							break;
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}
			}
			else {
DEBUGLOG(("Authorize::No More Record to fetch\n"));
				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
			}
		} 
	}
		
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


DEBUGLOG(("TxnMmcByUsISI Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
