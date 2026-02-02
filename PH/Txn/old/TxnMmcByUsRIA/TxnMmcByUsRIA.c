/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/30              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsRIA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsRIA(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	cPartyType;
	char	cBusinessType;
	char	*csMmcId;
	char	*csUser;

	char	*csTmp;

        hash_t *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        hash_t *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));


        if (GetField_Char(hContext, "party_type", &cPartyType)) {
DEBUGLOG(("Authorize::party_type = [%c]\n",cPartyType));
        }
        else {
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::party_type not found!!\n");
                iRet = INT_ERR;
        }

        if (GetField_Char(hContext, "business_type", &cBusinessType)) {
DEBUGLOG(("Authorize::business_type = [%c]\n",cBusinessType));
        }
        else {
DEBUGLOG(("Authorize::business_type not found!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::business_type not found!!\n");
                iRet = INT_ERR;
        }

/* testing */
PutField_CString(hContext, "node_id", "00001");
/* testing */

        if (GetField_CString(hContext, "node_id", &csMmcId)) {
DEBUGLOG(("Authorize::node_id = [%s]\n",csMmcId));
        }
        else {
DEBUGLOG(("Authorize::node_id not found!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::node_id not found!!\n");
                iRet = INT_ERR;
        }

	if (GetField_CString(hContext, "add_user", &csUser)) {
DEBUGLOG(("Authorize::user = [%s]\n",csUser));
	}


	if (iRet == PD_OK) {
		if (cPartyType == PD_TYPE_PSP) {
		/* Psp */
DEBUGLOG(("Authorize::Call DBPspDetail: GetPspDetailByType\n"));
			DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetailByType");
			if ((unsigned long)((*DBObjPtr)(cBusinessType, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBPspDetail:GetPspDetailByType Failed!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::DBPspDeail:GetPspDetailByType Failed!!\n");
				iRet = INT_ERR;
			}
			else {

				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					hash_init(hTxn, 0);

					PutField_Char(hTxn, "party_type", cPartyType);
					PutField_Char(hTxn, "business_type", cBusinessType);

					if (GetField_CString(hRec, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize::DBPspDetail psp_id = [%s]\n", csTmp));

						PutField_CString(hTxn, "party_id", csTmp);
					}

					if (GetField_CString(hRec, "psp_name", &csTmp)) {
DEBUGLOG(("Authorize::DBPspDetail psp_name = [%s]\n", csTmp));
						PutField_CString(hTxn, "party_name", csTmp);
					}

					PutField_CString(hTxn, "mmc_id", csMmcId);
					PutField_CString(hTxn, "add_user", csUser);

DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt: Add\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","Add");
					if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt:Add Failed!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::DBMmsInstantPMAcctDt:Add Failed!!\n");
						iRet = INT_ERR;
						break;
					}
				
					hRec = RecordSet_GetNext(rRecordSet);
				} 
			}

		} else {
		/* Merchant */
DEBUGLOG(("Authorize::Call DBMerchDetail: GetMerchantByType\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchantByType");
                        if ((unsigned long)((*DBObjPtr)(cBusinessType, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBMerchDetail:GetMerchantByType Failed!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::DBMerchDetail:GetMerchantByType Failed!!\n");
                                iRet = INT_ERR;
                        }
                        else {
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        hash_init(hTxn, 0);

                                        PutField_Char(hTxn, "party_type", cPartyType);
                                        PutField_Char(hTxn, "business_type", cBusinessType);

                                        if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize::DBMerchDetail merchant_id = [%s]\n", csTmp));

                                                PutField_CString(hTxn, "party_id", csTmp);
                                        }

                                        if (GetField_CString(hRec, "merchant_name", &csTmp)) {
DEBUGLOG(("Authorize::DBMerchDetail merchant_name = [%s]\n", csTmp));
                                                PutField_CString(hTxn, "party_name", csTmp);
                                        }

                                        PutField_CString(hTxn, "mmc_id", csMmcId);
                                        PutField_CString(hTxn, "add_user", csUser);

DEBUGLOG(("Authorize::Call DBMmsInstantPMAcctDt: Add\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBMmsInstantPMAcctDt","Add");
                                        if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsInstantPMAcctDt:Add Failed!!\n"));
ERRLOG("TxnMmcByUsRIA::Authorize::DBMmsInstantPMAcctDt:Add Failed!!\n");
                                                iRet = INT_ERR;
                                                break;
                                        }

                                        hRec = RecordSet_GetNext(rRecordSet);
                                }

			}
		}

	}



        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	FREE_ME(hTxn);


	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}


DEBUGLOG(("TxnMmcByUsRIA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
