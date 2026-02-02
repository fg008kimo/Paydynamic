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
#include "TxnMmcByUsIMI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMmcByUsIMI(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int     iNextMid = PD_FOUND;

	char	*csTmp=NULL;
	char    *csTxnCode = NULL;
	char    *csLastMid=NULL;
	char	cType;

	int	iTmp=0;
        char    csTag[PD_TAG_LEN +1];
	char    csMid[PD_MERCHANT_ID_LEN + 1];
	int     iNumOfRtnRecord = 0;

	hash_t *hRec;
	recordset_t	*rRecordSet;

	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	memset(csMid, 0, sizeof(csMid));

DEBUGLOG(("TxnMmcByUsIMI::Authorize\n"));


        if(GetField_CString(hContext,"txn_code",&csTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csTxnCode));
        }
        else {
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;
        }


/*
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
	}
*/

	if(GetField_CString(hRequest,"type",&csTmp)){
DEBUGLOG(("Authorize::type= [%s]\n",csTmp));
		cType = csTmp[0];
	}
	else{
DEBUGLOG(("Authorize::type not found!!\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::type not found!!\n");
		iRet=INT_ERR;
	}



        if(GetField_CString(hRequest,"last_mid",&csLastMid)){
DEBUGLOG(("Authorize::last_mid = [%s]\n",csLastMid));

DEBUGLOG(("Authorize::Call DBMerchDetail: GetNextMid\n"));
                DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetNextMid");
                if((unsigned long)((*DBObjPtr)(cType, csLastMid, &csMid))==PD_OK) {
DEBUGLOG(("Authorize::GetNextMid Succ [%s]\n", csMid));
                }
                else {
DEBUGLOG(("Authorize::GetNextMid Fail - no more mid\n"));
                        iNextMid = PD_NOT_FOUND;
                }
        }
        else{
DEBUGLOG(("Authorize::last_mid not found - Get all merchant\n"));
                sprintf(csMid, "%s", "<NULL>");
        }

DEBUGLOG(("Authorize::csMid = [%s]\n", csMid));


	if(iRet==PD_OK && iNextMid == PD_FOUND){

DEBUGLOG(("Authorize::Call DBMmsTxnCode: GetNumRtnRecordByCode\n"));
                DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCode","GetNumRtnRecordByCode");
                if((unsigned long)((*DBObjPtr)(csTxnCode, &iNumOfRtnRecord))!= FOUND) {
DEBUGLOG(("Authorize::Call DBMmsTxnCode: iNumOfRtnRecord Default Value\n"));
                        iNumOfRtnRecord = PD_TXN_IMI_MAX_RECORD;
                }
DEBUGLOG(("Authorize::Call DBMmsTxnCode: iNumOfRtnRecord = [%d]\n", iNumOfRtnRecord));


DEBUGLOG(("Authorize::Call DBMerchDetail: GetMerchantByType\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchantByType");

		if((unsigned long)((*DBObjPtr)(cType, csMid, iNumOfRtnRecord, rRecordSet))!=PD_OK) {
DEBUGLOG(("Authorize::GetMerchantByType Failed\n"));
ERRLOG("TxnMmcByUsIMI::Authorize::GetMerchantByType Failed\n");
			iRet=INT_ERR;
		}
                else {
			hRec =RecordSet_GetFirst(rRecordSet);

			while (hRec) {

				iTmp++;

				/* merchant_id */
				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "mid_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMerchantByType [%d] merchant_id = [%s]\n", iTmp, csTmp));
				}

				/* client_id */
				if (GetField_CString(hRec, "merchant_client_id", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "client_id_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMerchantByType [%d] client_id = [%s]\n", iTmp, csTmp));
				}

				/* name */
				if (GetField_CString(hRec, "merchant_name", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "name_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMerchantByType [%d] name = [%s]\n", iTmp, csTmp));
				}

				/* status */
				if (GetField_CString(hRec, "status", &csTmp)) {
					memset(csTag, 0, sizeof(csTag));
					sprintf(csTag, "status_%d", iTmp);
					PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetMerchantByType [%d] status = [%s]\n", iTmp, csTmp));
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


DEBUGLOG(("TxnMmcByUsIMI Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
