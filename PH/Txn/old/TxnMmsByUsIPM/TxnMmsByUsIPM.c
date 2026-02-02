/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUsIPM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmsByUsIPM(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;

	char	cQueryType;
	char	cBusinessType;
	char	cPartyType;
	char	*csPartyType;

	char	*csPartyId = NULL;
	char	*csLastId = NULL;
	char	*csMmcId = strdup("");

	int	iMaxRtn = PD_TXN_IPY_MAX_RECORD;
	int	iRefreshInterval = PD_REFRESH_INTERVAL;
	
	char	*csTmp = NULL;
	int	iTmp = 0;

	char	csStartPartyId[PD_MMS_PARTY_ID_LEN  + 1];
        char    csTag[PD_TAG_LEN +1];

        hash_t *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hash_t *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t *hFromNodes;
	hFromNodes = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hFromNodes,0);

	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::user = [%s]\n",csTmp));


		PutField_CString(hTxn, "update_user", csTmp);
		PutField_CString(hTxn, "add_user", csTmp);
	}

/*
	if (GetField_CString(hContext, "node_id", &csTmp)) {
DEBUGLOG(("Authorize::node_id = [%s]\n",csTmp));
		PutField_CString(hTxn, "node_id", csTmp);
	}
	if (GetField_CString(hContext, "mms_key", &csTmp)) {
DEBUGLOG(("Authorize::mms_key = [%s]\n",csTmp));
		PutField_CString(hTxn, "mms_key", csTmp);
	}

*/
	if (GetField_Char(hRequest, "query_type", &cQueryType)) {
DEBUGLOG(("Authorize::query_type = [%c]\n",cQueryType));

		PutField_Char(hTxn, "query_type", cQueryType);
	}
	else {
DEBUGLOG(("Authorize::query_type not found!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::query_type not found!!\n");
		iRet = INT_ERR;
	}
/*
	if (GetField_CString(hRequest, "req_mmc_id", &csMmcId)) {
DEBUGLOG(("Authorize::req_mmc_id = [%s]\n",csMmcId));
		PutField_CString(hTxn, "mmc_id", csMmcId);
	}
*/
	if (GetField_Char(hRequest, "business_type", &cBusinessType)) {
DEBUGLOG(("Authorize::business_type = [%c]\n",cBusinessType));
		PutField_Char(hTxn, "business_type", cBusinessType);
	}
	else {
DEBUGLOG(("Authorize::business_type not found!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::business_type not found!!\n");
		iRet = INT_ERR;
	}

	if (GetField_CString(hRequest, "party_type", &csPartyType)) {
DEBUGLOG(("Authorize::party_type = [%s]\n",csPartyType));

		if(!strcmp(csPartyType,PD_MMS_PARTY_MERCH))
			cPartyType=PD_TYPE_MERCHANT;
		else
			cPartyType=PD_TYPE_PSP;

		PutField_Char(hTxn, "party_type", cPartyType);
	}
	else {
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::party_type not found!!\n");
		iRet = INT_ERR;
	}

	if (GetField_Int(hRequest, "refresh_interval", &iRefreshInterval)) {
DEBUGLOG(("Authorize::refresh_interval = [%d]\n",iRefreshInterval));
		PutField_Int(hTxn, "refresh_interval", iRefreshInterval);
	}
	else {
DEBUGLOG(("Authorize::refresh_interval not found!!\n"));
		PutField_Int(hTxn, "refresh_interval", PD_REFRESH_INTERVAL);
	}


	if (iRet == PD_OK) {
		if (cQueryType == PD_MMS_SINGLE_QUERY) {
			if (GetField_CString(hRequest, "party_id", &csPartyId)) {
DEBUGLOG(("Authorize::party_id = [%s]\n",csPartyId));
				PutField_CString(hTxn, "party_id",csPartyId);
			}
			else {
DEBUGLOG(("Authorize::party_id not found!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::party_id not found!!\n");
				iRet = INT_ERR;
			}
		} 
		else {
			if (GetField_Int(hRequest, "max_rtn", &iMaxRtn)) {
				PutField_Int(hTxn, "max_rtn",iMaxRtn);
DEBUGLOG(("Authorize::max_rtn = [%d]\n",iMaxRtn));
			}
		}
	}


//if request with last id, only search from table, and return the record
	if(!GetField_CString(hRequest,"last_id",&csLastId)){
//else check cache record valid or not
		PutField_Char(hTxn, "status",  PD_COMPLETE);
DEBUGLOG(("Authorize::Call BMmsInstantPMAcctHd: ChkValidHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctHd","ChkValidHeader");
		if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_FOUND) {
DEBUGLOG(("Authorize::Call BMmsInstantPMAcctHd: ChkValidHeader - No Valid Header\n"));
//record not up-to-date

			//-******** Update Header or insert header, status = 'P' ********
			PutField_Char(hTxn, "status", PD_PROCESSING);
			PutField_CString(hTxn, "update_user", PD_UPDATE_USER);

DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctHd: UpdateRec\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctHd","UpdateRec");
			if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {

DEBUGLOG(("Authorize::DBMmsIntantPMAcctHd:UpdateRec Failed!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::DBMmsInstantPMAcctHd:UpdateRec Failed!!\n");
				iRet = INT_ERR;
			}
			else {
DEBUGLOG(("Authorize::DBMmsIntantPMAcctHd:UpdateRec Succ!!\n"));
			}


			//.******** Delete Detail ********
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt: Delete\n"));
                        	DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","Delete");
	                        if ((unsigned long)((*DBObjPtr)(cPartyType, cBusinessType)) != PD_OK) {

DEBUGLOG(("Authorize::DBMmsIntantPMAcctDt:Delete Failed!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::DBMmsInstantPMAcctDt:Delete Failed!!\n");
					iRet = INT_ERR;
       	                 	}
	                        else {
DEBUGLOG(("Authorize::DBMmsIntantPMAcctDt:Delete Succ!!\n"));
				}
			}

			if(iRet==PD_OK){
//request from client nodes

				if(!strcmp(csPartyType,PD_MMS_PARTY_MERCH)){
					PutField_CString(hTxn,"txn_code", "ICI");
DEBUGLOG(("Authorize:: set txn_code = [%s]\n","ICI"));
				}
				else if(!strcmp(csPartyType,PD_MMS_PARTY_PSP)){
					PutField_CString(hTxn,"txn_code", "IPI");
DEBUGLOG(("Authorize:: set txn_code = [%s]\n","IPI"));
				}

DEBUGLOG(("Authorize::Call TxnMmsByUs2Node: Authorize\n"));
				TxnObjPtr = CreateObj(TxnPtr, "TxnMmsByUs2Node","Authorize");
				iRet = (unsigned long)(*TxnObjPtr)(hTxn,hRequest,hFromNodes);
DEBUGLOG(("Authorize::Call TxnMmsByUs2Node iRet=[%d]\n",iRet));

///////////////////////////

				//***testing, Assume client nodes return the following***//
/*				PutField_Int(hFromNodes,"total_cnt",3);
				PutField_CString(hFromNodes,"party_id_1","ABC");
				PutField_CString(hFromNodes,"party_id_2","DEF");
				PutField_CString(hFromNodes,"party_id_3","XYZ");
				PutField_CString(hFromNodes,"party_name_1","TEST-ABC");
				PutField_CString(hFromNodes,"party_name_2","TEST-DEF");
				PutField_CString(hFromNodes,"party_name_3","TEST-XYZ");
				PutField_CString(hFromNodes,"mms_node_id_1","001");
				PutField_CString(hFromNodes,"mms_node_id_2","001");
				PutField_CString(hFromNodes,"mms_node_id_3","002");
*/
				//.***testing data end***///
			}


//update the cache tables
			if(iRet==PD_OK){
				int iCnt=0;
				int i=0;
				hash_t *hDt;
        			hDt = (hash_t*)  malloc (sizeof(hash_t));
        			hash_init(hDt,0);

				if(GetField_Int(hFromNodes,"total_cnt",&iCnt)){
DEBUGLOG(("Authorize::Total record count from nodes = [%d]\n",iCnt));
					for(i=1; i<=iCnt; i++){
						//.********Insert Detail ********//
						PutField_Char(hDt,"party_type",cPartyType);
						PutField_Char(hDt,"business_type",cBusinessType);
						PutField_CString(hDt,"add_user",PD_UPDATE_USER);

						//party_id
						sprintf(csTag,"party_id_%d",i);
						if(GetField_CString(hFromNodes,csTag,&csTmp)){
							PutField_CString(hDt,"party_id",csTmp);
						}
						//party_name
						sprintf(csTag,"party_name_%d",i);
						if(GetField_CString(hFromNodes,csTag,&csTmp)){
							PutField_CString(hDt,"party_name",csTmp);
						}
						//mms_node_id
						sprintf(csTag,"mms_node_id_%d",i);
						if(GetField_CString(hFromNodes,csTag,&csTmp)){
							PutField_CString(hDt,"mms_node_id",csTmp);
						}

						DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","Add");
						if ((unsigned long)((*DBObjPtr)(hDt)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsIntantPMAcctDt:Add Failed!!Stopped!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::DBMmsInstantPMAcctDt:Add Failed!!\n");
							iRet = INT_ERR;
							break;
						}
					}

				}

				//.******** Update Header status to 'C' ********
	                        PutField_Char(hTxn, "status", PD_COMPLETE);

DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctHd: UpdateRec\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctHd","UpdateRec");
				if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {

DEBUGLOG(("Authorize::DBMmsIntantPMAcctHd:UpdateRec Failed!!\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::DBMmsInstantPMAcctHd:UpdateRec Failed!!\n");
                                	iRet = INT_ERR;
                        	}
                        	else {
DEBUGLOG(("Authorize::DBMmsIntantPMAcctHd:UpdateRec Succ!!\n"));
				}

				FREE_ME(hDt);
			}

		}
	}

	if(iRet == PD_OK){
//return record
/*search from MmsInstantPMAcct tables*/
		if (cQueryType == PD_MMS_SINGLE_QUERY) {    // Single
DEBUGLOG(("Authorize::Call BMmsInstantPMAcctDt: GetSingleDetail\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","GetSingleDetail");
			iRet = (unsigned long)((*DBObjPtr)(cPartyType, cBusinessType, csPartyId, hContext));
			if (iRet == PD_OK) {

				iTmp++;

				sprintf(csTag, "party_id_%d", iTmp);
				PutField_CString(hResponse, csTag, csPartyId);
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt [%d] party_id = [%s]\n", iTmp, csPartyId));

				if (GetField_CString(hContext, "party_name", &csTmp)) {
					sprintf(csTag, "party_name_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt [%d] party_name = [%s]\n", iTmp, csTmp));
				}

				if (GetField_CString(hContext, "mms_node_id", &csTmp)) {
					sprintf(csTag, "mms_node_id_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt [%d] mms_node_id = [%s]\n", iTmp, csTmp));
				}

				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
			} 
			else if(iRet == PD_NOT_FOUND){
DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt : GetSingleDetail Not Found\n"));
				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
				iRet = PD_OK;
			}
			else{
DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt : GetSingleDetail Fail\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::Call DBMmsInstantPMAcctDt: GetSingleDetail Fail!!\n");
				iRet = PD_ERR;
			}
		
		}
		else {  // Multiple

		        if (GetField_CString(hRequest,"last_id", &csLastId)) {
DEBUGLOG(("Authorize::last_id = [%s]\n", csLastId));

				memset(csStartPartyId, 0, sizeof(csStartPartyId));

DEBUGLOG(("Authorize::Call MmsInstantPMAcctDt: GetNextPartyId\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","GetNextPartyId");
				iTmpRet = (unsigned long)((*DBObjPtr)(cPartyType, cBusinessType, csLastId, csMmcId, &csStartPartyId));

				if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize::GetNextPartyId Succ [%s]\n", csStartPartyId));
				} 
				else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("Authorize::GetNextPartyId Fail - no more psp id\n"));
				}
				else {
DEBUGLOG(("Authorize::GetNextPartyId Fail\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::GetNextPartyId Fail!!\n");
					iRet = INT_ERR;
				}
			}
			else {
DEBUGLOG(("Authorize::last_id not found and assign default NULL value\n"));
				strcpy(csStartPartyId, PD_MMS_SP_NULL_VALUE);
DEBUGLOG(("Authorize::Assigned Start PartyId [%s]\n", csStartPartyId));
        		}
			PutField_CString(hTxn,"start_party_id",csStartPartyId);


			if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt: GetDetailbyRange\n"));
                                DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","GetDetailbyRange");
                                if ((unsigned long)((*DBObjPtr)(hTxn, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt:GetDetailbyRange Failed\n"));
ERRLOG("TxnMmsByUsIPM::Authorize::DBMmsInstantPMAcctDt:GetDetailbyRange Failed\n");
                                        iRet=INT_ERR;
                                }
                                else {

                                        PutField_Int(hResponse, "total_cnt", iTmp);
                                        PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);

                                        hRec = RecordSet_GetFirst(rRecordSet);
                                        while (hRec) {
						iTmp++;

						if (iTmp <= iMaxRtn) {

							if (GetField_CString(hRec, "party_id", &csTmp)) {
								sprintf(csTag, "party_id_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailRec [%d] party_id = [%s]\n", iTmp, csTmp));
							}

							if (GetField_CString(hRec, "party_name", &csTmp)) {
								sprintf(csTag, "party_name_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailRec [%d] party_name = [%s]\n", iTmp, csTmp));
							}

							if (GetField_CString(hRec, "mms_node_id", &csTmp)) {
								sprintf(csTag, "mms_node_id_%d", iTmp);
								PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailRec [%d] mms_node_id = [%s]\n", iTmp, csTmp));
							}
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
	FREE_ME(csMmcId);
	FREE_ME(hFromNodes);
        FREE_ME(hTxn);



DEBUGLOG(("TxnMmsByUsIPM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
