/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/23              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsIMI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsIMI(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iHasNextMBId = PD_OK;

	char	cQueryType;
	char	*csMBId = NULL;
	char	*csLastId = NULL;
	char	*csMmcId = NULL;
	int	iMaxRtn = PD_TXN_IPY_MAX_RECORD;
	
	char	*csTmp = NULL;
	int	iTmp = 0;

        char    csTag[PD_TAG_LEN +1];
	char	csStartMBId[PD_MB_ID_LEN  + 1];

        hash_t *hRec;
        recordset_t     *rRecordSet;

        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);



	if (GetField_Char(hContext, "query_type", &cQueryType)) {
DEBUGLOG(("Authorize::query_type = [%c]\n",cQueryType));
	}
	else {
DEBUGLOG(("Authorize::query_type not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::query_type not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hContext, "server_node", &csMmcId)) {
DEBUGLOG(("Authorize::server node_id = [%s]\n",csMmcId));
	}
	else {
DEBUGLOG(("Authorize::server node_id not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::server node_id not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest,"last_id", &csLastId)) {
DEBUGLOG(("Authorize::last_id = [%s]\n", csLastId));

DEBUGLOG(("Authorize::Call DBMmsMBDetail: GetNextMBId\n"));

		memset(csStartMBId, 0, sizeof(csStartMBId));

                DBObjPtr = CreateObj(DBPtr,"DBMmsMBDetail","GetNextMBId");
		iHasNextMBId = (unsigned long)((*DBObjPtr)(csLastId, &csStartMBId));

		if (iHasNextMBId == PD_OK) {
DEBUGLOG(("Authorize::GetNextMBId Succ [%s]\n", csStartMBId));
			PutField_CString(hContext, "start_mb_id", csStartMBId);
                }
                else if (iHasNextMBId == PD_NOT_FOUND) {
DEBUGLOG(("Authorize::GetNextMBId Fail - no more MB id\n"));
		}
		else {
DEBUGLOG(("Authorize::GetNextMBId Fail\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::GetNextMBId Fail!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {
		if (cQueryType == PD_MMS_SINGLE_QUERY) {
			if (GetField_CString(hContext, "mb_id", &csMBId)) {
DEBUGLOG(("Authorize::mb_id = [%s]\n",csMBId));
			}
			else {
DEBUGLOG(("Authorize::mb_id not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::mb_id not found!!\n");
				iRet = INT_MB_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
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
DEBUGLOG(("Authorize::Call DBMmsMBDetail: GetMBDetail\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMmsMBDetail","GetMBDetail");
			if ((unsigned long)((*DBObjPtr)(csMBId, hContext)) == PD_OK) {

				iTmp++;

				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "party_id_%d", iTmp);
				PutField_CString(hResponse, csTag, csMBId);
DEBUGLOG(("Authorize::GetMBDetail [%d] party_id = [%s]\n", iTmp, csMBId));

				if (GetField_CString(hContext, "mb_name", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "party_name_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMBDetail [%d] party_name = [%s]\n", iTmp, csTmp));
				}

				
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "mms_node_id_%d", iTmp);
				PutField_CString(hResponse, csTag, csMmcId);
DEBUGLOG(("Authorize::GetMBDetail [%d] mms_node_id= [%s]\n", iTmp, csMmcId));

				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
			} 
			else {
DEBUGLOG(("Authorize::Call DBMmsMBDetail: GetMBDetail Fail\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::Call DBMmsMBDetail: GetMBDetail Fail!!\n");
				iRet = PD_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
		
		}
		else {  // Multiple

			if (iHasNextMBId == PD_OK) {

DEBUGLOG(("Authorize::Call DBMmsMBDetail: GetMBDetailbyRange\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsMBDetail","GetMBDetailbyRange");

				if ((unsigned long)((*DBObjPtr)(hContext, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsMBDetail:GetMBDetailbyRange Failed\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::DBMmsMBDetail:GetMBDetailbyRange Failed\n");
					iRet=INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
				}	
				else {

					PutField_Int(hResponse, "total_cnt", iTmp);
					PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);

					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						iTmp++;

						if (iTmp <= iMaxRtn) {

							if (GetField_CString(hRec, "mb_id", &csTmp)) {
								memset(csTag, 0, sizeof(csTag));
								sprintf(csTag, "party_id_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMBDetailbyRange [%d] party_id = [%s]\n", iTmp, csTmp));
							}

							if (GetField_CString(hRec, "mb_name", &csTmp)) {
								memset(csTag, 0, sizeof(csTag));
								sprintf(csTag, "party_name_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMBDetailbyRange [%d] party_name = [%s]\n", iTmp, csTmp));
							}


							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "mms_node_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csMmcId);
DEBUGLOG(("Authorize::GetMBDetailbyRange [%d] mms_node_id= [%s]\n", iTmp, csMmcId));

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

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMmcByUsIMI Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
