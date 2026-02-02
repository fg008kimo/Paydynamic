/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/27              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnP2xOnUsP2X.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
OBJPTR(Msg);
OBJPTR(BO);
void TxnP2xOnUsP2X(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char*	csMerchantId;
	char	*csKey;
	char	*csServiceCode;
	char	*csTxnCode;
	char	*csPspId;
	char	*csLang;
	char	*csPtr;
	hash_t		*hRec;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
DEBUGLOG(("TxnP2xOnUsP2X()\n"));
	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Authorize::GetMerchantTxnInfo() merchant_id = [%s]\n",csMerchantId));
        }
        else
                iRet = INT_MERCHANT_ID_NOT_FOUND;
	
	if (iRet == PD_OK) {
                char*   csValueTmp;
                csValueTmp = (char*) malloc (128);
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
/* redirect url */
                if ((unsigned long)(DBObjPtr)("S_7X24_URL",csValueTmp) == FOUND) {
DEBUGLOG(("Authorize::S_REDIRECT_URL  = [%s]\n",csValueTmp));
        		PutField_CString(hResponse,"redirect_url",csValueTmp);
                }
                else {
ERRLOG("Authorize::Unable to find S_7X24_URL\n");
                }
		FREE_ME(csValueTmp);

        }


	if (iRet == PD_OK ) {
                DBObjPtr = CreateObj(DBPtr,"DBMerchKeys","GetMerchantKey");
                if ((*DBObjPtr)(csMerchantId,"P2X",rRecordSet) != PD_OK) {
                        iRet = INT_ERR;
ERRLOG("Authorize::GetMerchantTxnInfo() Merchant Key for Account[%s] not found\n",csMerchantId);
DEBUGLOG(("Authorize::GetMerchantTxnInfo() Merchant key for Account[%s] not found\n",csMerchantId));
                }
                else{
                        iRet = INT_ERR;
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                if (GetField_CString(hRec,"key_value",&csKey)) {
DEBUGLOG(("Authorize::GetMerchantTxnInfo() GetMerchantKey - merchant_key_value = [%s]\n",csKey));
					PutField_CString(hRequest,"merchant_key",csKey);
                                        iRet = PD_OK;
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        }
/* urls */
	if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
DEBUGLOG(("Authoriz: service_code = [%s]\n",csServiceCode));
	}
	else {
DEBUGLOG(("Authoriz: service_code is missing\n"));
	}

/* txn code */
	if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("Authoriz: txn_code = [%s]\n",csTxnCode));
	}
	else {
DEBUGLOG(("Authoriz: txn_code is missing\n"));
	}

/* psp id should be the default one */
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("Authoriz: psp_id = [%s]\n",csPspId));
	}
	else {
DEBUGLOG(("Authoriz: psp_id is missing\n"));
	}

/*language */
	if (GetField_CString(hRequest,"language",&csLang)) {
DEBUGLOG(("Authoriz: language = [%s]\n",csLang));
	}
	else {
DEBUGLOG(("Authoriz: language is missing\n"));
	}

	if (iRet == PD_OK) {
		recordset_t     *rRes;
        	rRes = (recordset_t*) malloc (sizeof(recordset_t));
        	recordset_init(rRes,0);

                DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl");
                if ((unsigned long)(DBObjPtr)(csTxnCode,csServiceCode,csPspId,csLang,PD_TXN_RESPONSE,rRes) == PD_OK) {
DEBUGLOG(("Authoriz: found record\n"));
			hash_t	*hRec;
			hRec = RecordSet_GetFirst(rRes);
                	while (hRec) {	
				char* csURL;
				if (GetField_CString(hRec,"fe_url",&csURL)) {
					PutField_CString(hResponse,"fe_url_only",csURL);
DEBUGLOG(("Authoriz: fe_url = [%s]\n",csURL));
					char* csBuf;
					csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
                                        if (GetField_CString(hContext,"txn_seq",&csPtr)) {
                                        	char*   csTmpBuf;
                                                csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
                                                BOObjPtr = CreateObj(BOPtr,"BOSecurity","Encrypt3DESTxnSeq");
                                                (BOObjPtr)(csPtr,csTmpBuf);
DEBUGLOG(("Authroize tmpbuf = [%s]\n",csTmpBuf));
                                                sprintf(csBuf,"%s?sessionid=%s",csURL,csTmpBuf);
                                                PutField_CString(hResponse,"fe_url",csBuf);
                                                FREE_ME(csTmpBuf);
DEBUGLOG(("Authorize() GetFeUrl - url = [%s]\n",csBuf));
                                        }
                                       FREE_ME(csBuf);
				}
				hRec = RecordSet_GetNext(rRes);
			}
		}

		RecordSet_Destroy(rRes);
        	FREE_ME(rRes);
	}
/* encrypt url */
	PutField_CString(hRequest,"tot_token","0");
	PutField_CString(hRequest,"server_ip","202.175.89.123");
	PutField_CString(hRequest,"txn_msg","TESTING");

	if (iRet == PD_OK) {
		TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2P2X","Encrypt");
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("TxnP2xOnUsP2X::Encrypt() iRet = [%d] from TxnWebOnUs2P2X:Encrypt\n",iRet));
	}
	
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
DEBUGLOG(("Authorize:: iRet = [%d]\n",iRet));
	return	iRet;
}

int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char*	csPtr;
	char*	csMerchantId;
	char*	csKey;
	hash_t		*hRec;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
DEBUGLOG(("TxnP2xOnUsP2X() Decrypt\n"));
	if (GetField_CString(hRequest,"merchantid",&csMerchantId)) {
DEBUGLOG(("Decrypt:: merchantid = [%s]\n",csMerchantId));
		PutField_CString(hRequest,"merchant_id",csMerchantId);
        }
        else {
DEBUGLOG(("Decrypt::merchant id is missing!!!\n"));
                iRet = INT_MERCHANT_ID_NOT_FOUND;
	}

	if (iRet == PD_OK ) {
                DBObjPtr = CreateObj(DBPtr,"DBMerchKeys","GetMerchantKey");
                if ((*DBObjPtr)(csMerchantId,"PTK",rRecordSet) != PD_OK) {
                        iRet = INT_ERR;
ERRLOG("Decrypt::GetMerchantTxnInfo() Merchant Key for Account[%s] not found\n",csMerchantId);
DEBUGLOG(("Decrypt::GetMerchantTxnInfo() Merchant key for Account[%s] not found\n",csMerchantId));
                }
                else{
                        iRet = INT_ERR;
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                if (GetField_CString(hRec,"key_value",&csKey)) {
DEBUGLOG(("Decrypt::GetMerchantTxnInfo() GetMerchantKey - merchant_key_value = [%s]\n",csKey));
					PutField_CString(hRequest,"merchant_key",csKey);
                                        iRet = PD_OK;
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        }
	

        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2P2X","Decrypt");
        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("Decrypt::Decrypt() iRet = [%d]\n",iRet));
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"merchant_ref",&csPtr)) {
			PutField_CString(hContext,"merchant_ref",csPtr);
        		TxnObjPtr = CreateObj(TxnPtr,"TxnP2xOnUsACK","Authorize");
        		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		}
	}
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	return	iRet;
}
