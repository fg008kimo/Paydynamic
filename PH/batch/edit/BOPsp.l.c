/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/16              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOPsp.h"

char    cDebug;

void BOPsp(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(DB);


int GetTxnPsp(hash_t *hContext,
                const hash_t* hRequest)
{
        int     iRet = PD_OK;
	char*	csTxnCountry = NULL;
	char*	csPspId = NULL;
	char*	csTxnCode = NULL;
	char*	csTmp = NULL;
	char	cTmp = PD_OFFLINE;
	//char	cOnline = PD_OFFLINE;
	int	iTmp;
	int	iTotalCnt=0;

	hash_t  *hRec;	
	hash_t  *hPsp;	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	GetField_CString(hContext,"txn_code",&csTxnCode);

DEBUGLOG(("BOPsp: TxnCode = [%s]\n",csTxnCode));

	if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("BOPsp: GetMerchatDetail- txn_country = [%s]\n",csTxnCountry));
	}
	else  {
DEBUGLOG(("BOPsp: GetMerchatDetail- txn_country not found\n"));
ERRLOG("BOPsp: GetMerchatDetail- txn_country not found\n");
		iRet = INT_ERR;
	}

	if (iRet == PD_OK ) {
		DBObjPtr = CreateObj(DBPtr,"DBPsp","GetCountryPsp");
         	if ((*DBObjPtr)(csTxnCountry,
       	                 rRecordSet) != PD_OK) {
               	 	iRet = INT_TXN_COUNTRY_NOT_FOUND;
ERRLOG("BOPsp: txn country [%s] not found\n",csTxnCountry);
DEBUGLOG(("BOPsp: txn country [%s] not found\n",csTxnCountry));
               	}               
		else {
DEBUGLOG(("BOPsp:  else \n"));
               	 	iRet = INT_TXN_COUNTRY_NOT_FOUND;
                	hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Int(hRec,"disabled",&iTmp)) {
DEBUGLOG(("BOPsp: GetTxnPsp - disabled = [%d]\n",iTmp));

					if (iTmp != PD_DISPABLED) {
						iRet = PD_OK;
						if (GetField_CString(hRec,"psp_id",&csTmp)) {
DEBUGLOG(("BOPsp: GetTxnPsp - psp_id = [%s]\n",csPspId));
							sprintf(csTag,"psp_id_%d",iTotalCnt);
							PutField_CString(hContext,csTag,csPspId);
						}
						if (GetField_CString(hRec,"psp_client_id",&csTmp)) {
DEBUGLOG(("BOPsp: GetTxnPsp - psp_client_id = [%s]\n",csTmp));
							sprintf(csTag,"psp_client_id_%d",iTotalCnt);
							PutField_CString(hContext,csTag,csTmp);
						}
						if (GetField_Char(hRec,"online",&cTmp)) {
DEBUGLOG(("BOPsp: GetTxnPsp - online = [%c]\n",cTmp));
							sprintf(csTag,"online_%d",iTotalCnt);
							PutField_Char(hContext,csTag,cTmp);
						}
						
						iTotalCnt++;
					}
					else {
ERRLOG("BOPsp: psp [%s] disabled\n",csTxnCountry);
						if(!iTotalCnt)
							iRet = INT_ACCOUNT_DISABLED;
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
/*
		if (cOnline == PD_OFFLINE) {
			iRet = INT_COUNTRY_PSP_NOT_AVABILE;
DEBUGLOG(("BOPsp: all PSPs for [%s] are not avablie\n",csTxnCountry));
ERRLOG("BOPsp: all PSPs for [%s] are not avablie\n",csTxnCountry);
		}
*/
	}

/* Get PSP Detail */
	hPsp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPsp,0);
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
         	if (!(*DBObjPtr)(csPspId, hPsp)) {

			if (GetField_CString(hPsp,"psp_name",&csTmp)) {
				PutField_CString(hContext,"psp_name",csTmp);
DEBUGLOG(("BOPsp: GetTxnPsp - PSP NAME = [%s]\n",csTmp));
			}

			if (GetField_CString(hPsp,"key",&csTmp)) {
				PutField_CString(hContext,"psp_key",csTmp);
DEBUGLOG(("BOPsp: GetTxnPsp - PSP KEY = [%s]\n",csTmp));
			}
		
		}
	}
/* Get PSP URL */
	 if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBPspUrl","GetPspUrl");
                if (!(*DBObjPtr)(csPspId,hPsp)) {
                        if (GetField_CString(hPsp,"url",&csTmp)) {
                                PutField_CString(hContext,"psp_url",csTmp);
DEBUGLOG(("BOPsp: GetTxnPsp - psp_url = [%s]\n",csTmp));
                        }
                        else {
ERRLOG("BOPsp: GetTxnPSP - no such for [%s]\n",csPspId);
                                iRet = INT_ERR;
                        }
                }
        }


/* Get PSP Reqest Txn URL */
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBPspRequestTxnUrl","GetPspRequestTxnUrl");
         	if (!(*DBObjPtr)(csPspId,csTxnCode, hPsp)) {
			if (GetField_CString(hPsp,"request_function",&csTmp)) {
				PutField_CString(hContext,"request_function",csTmp);
DEBUGLOG(("BOPsp: GetTxnPsp - request_function = [%s]\n",csTmp));
			}
			else {
ERRLOG("BOPsp: GetTxnPSP - no such function url for [%s] [%s]\n",csPspId,csTxnCode);
				iRet = INT_ERR;
			}
			if (GetField_CString(hPsp,"action",&csTmp)) {
				PutField_CString(hContext,"action",csTmp);
DEBUGLOG(("BOPsp: GetTxnPsp - action = [%s]\n",csTmp));
			}
		}
	}


	if (iRet != PD_OK) {
		PutField_Int(hContext,"internal_error",iRet);
	}
	hash_destroy(hPsp);
        FREE_ME(hPsp);

	FREE_ME(csTxnCountry);
	FREE_ME(csPspId);
	FREE_ME(csTxnCode);
	FREE_ME(csTmp);
DEBUGLOG(("BOPsp: Normal exit = [%d]\n",iRet));
	return iRet;
}
