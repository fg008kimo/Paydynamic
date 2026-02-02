/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/21              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsIPI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMmcByUsIPI(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iNextPsp = PD_FOUND;

	char	*csTmp=NULL;
	char	*csTxnCode = NULL;
	char	*csLastPspId=NULL;
	char	cType;
        char    cTmp;

	int	iTmp=0;
        char    csTag[PD_TAG_LEN +1];
	char	csPspId[PD_PSP_ID_LEN + 1];
	int	iNumOfRtnRecord = 0;

	hash_t *hRec;
	recordset_t	*rRecordSet;

	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	memset(csPspId, 0, sizeof(csPspId));

DEBUGLOG(("TxnMmcByUsIPI::Authorize\n"));

	if(GetField_CString(hContext,"txn_code",&csTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csTxnCode));
	}
	else {
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnMmcByUsIPI::Authorize::txn_code not found!!\n");
		iRet=INT_ERR;
	}

	if(GetField_CString(hRequest,"type",&csTmp)){
DEBUGLOG(("Authorize::type= [%s]\n",csTmp));
		cType = csTmp[0];
	}
	else{
DEBUGLOG(("Authorize::type not found!!\n"));
ERRLOG("TxnMmcByUsIPI::Authorize::type not found!!\n");
		iRet=INT_ERR;
	}

	if(GetField_CString(hRequest,"last_psp_id",&csLastPspId)){
DEBUGLOG(("Authorize::last_psp_id = [%s]\n",csLastPspId));

DEBUGLOG(("Authorize::Call DBPspDetail: GetNextPspId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetNextPspId");
		if((unsigned long)((*DBObjPtr)(cType, csLastPspId, &csPspId))==PD_OK) {
DEBUGLOG(("Authorize::GetNextPspId Succ [%s]\n", csPspId));
		}
		else { 
DEBUGLOG(("Authorize::GetNextPspId Fail - no more psp id\n"));
			iNextPsp = PD_NOT_FOUND;
		}
	}
	else{
DEBUGLOG(("Authorize::last_psp_id not found - Get all Psp\n"));
		sprintf(csPspId, "%s", "<NULL>");
	}

DEBUGLOG(("Authorize::csPspid = [%s]\n", csPspId));


	if(iRet==PD_OK && iNextPsp == PD_FOUND){

DEBUGLOG(("Authorize::Call DBMmsTxnCode: GetNumRtnRecordByCode\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCode","GetNumRtnRecordByCode");
		if((unsigned long)((*DBObjPtr)(csTxnCode, &iNumOfRtnRecord))!= FOUND) {
DEBUGLOG(("Authorize::Call DBMmsTxnCode: iNumOfRtnRecord Default Value\n"));
			iNumOfRtnRecord = PD_TXN_IPI_MAX_RECORD;
		}
DEBUGLOG(("Authorize::Call DBMmsTxnCode: iNumOfRtnRecord = [%d]\n", iNumOfRtnRecord));


DEBUGLOG(("Authorize::Call DBPspDetail: GetPspDetailByType\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetailByType");

		if((unsigned long)((*DBObjPtr)(cType, csPspId, iNumOfRtnRecord, rRecordSet))!=PD_OK) {
DEBUGLOG(("Authorize::GetPspDetailByType Failed\n"));
ERRLOG("TxnMmcByUsIPI::Authorize::GetPspDetailByType Failed\n");
			iRet=INT_ERR;
		}
                else {
			hRec =RecordSet_GetFirst(rRecordSet);

			while (hRec) {

				iTmp++;

				/* psp_id */
				if (GetField_CString(hRec, "psp_id", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "psp_id_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] psp_id = [%s]\n", iTmp, csTmp));
				}

				/* name */
				if (GetField_CString(hRec, "psp_name", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "name_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] name = [%s]\n", iTmp, csTmp));
				}

				/* psp_merchant_id */
				if (GetField_CString(hRec, "psp_merchant_id", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "psp_merchant_id_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] psp_merchant_id = [%s]\n", iTmp, csTmp));
				}

				/* psp_channel_code */

				if (GetField_CString(hRec, "psp_channel_code", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "psp_channel_code_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] psp_channel_code = [%s]\n", iTmp, csTmp));
				}


				/* client_id */
				if (GetField_CString(hRec, "client_id", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "client_id_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] client_id = [%s]\n", iTmp, csTmp));
				}

				/* txn_type */
				if (GetField_Char(hRec, "txn_type", &cTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "txn_type_%d", iTmp);
					PutField_Char(hResponse, csTag, cTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] txn_type = [%c]\n", iTmp, cTmp));
				}

				/* status */
				if (GetField_CString(hRec, "status", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "status_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetPspDetailByType [%d] status = [%s]\n", iTmp, csTmp));
				}


				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

        PutField_Int(hResponse, "total_cnt", iTmp);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}


DEBUGLOG(("TxnMmcByUsIPI Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
