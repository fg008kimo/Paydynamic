/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/05/14              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRSC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

OBJPTR(DB);
char cDebug;

void TxnMgtByUsRSC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iCheckBank = PD_FALSE;
	int	iCheckPsp = PD_FALSE;
	int	i = 0;
	int	iPspCnt = 0;
	char	*csPspId;
	char    *csPspIdList;
	char    *csBankCode;
	char    *csUser;
	char    *csType;
	char    *csResult;
	char    csCmd[PD_TMP_BUF_LEN*2 + 1];
	char    csTmpPspId[PD_PSP_ID_LEN+1];
	char    csTag[PD_TAG_LEN + 1];
	hash_t*	hRec;
	hash_t*	hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("Authorize\n"));


//psp_id (optional)
        if(GetField_CString(hRequest,"psp_id",&csPspIdList)){
		iCheckPsp = PD_TRUE;
		PutField_CString(hTxn,"reset_type","PSP");

		char *p;
		iPspCnt = 0;
		p = strtok (csPspIdList,",");
		while (p != NULL)
		{
			strcpy(csTmpPspId,p);
			csTmpPspId[strlen(p)]='\0';
			sprintf(csTag,"psp_id_%d",iPspCnt);
			PutField_CString(hTxn,csTag,csTmpPspId);
DEBUGLOG(("Authorize::psp_id = [%s]\n",csTmpPspId));

			p = strtok (NULL,",");
			iPspCnt++;
		}
        }

//bank_code (optional)
        if(GetField_CString(hRequest,"bank_code",&csBankCode)){
		if(strlen(csBankCode)>0){
			iCheckBank = PD_TRUE;
			PutField_CString(hTxn,"reset_type","Bank");
DEBUGLOG(("Authorize::bank_code = [%s]\n",csBankCode));
		}
        }

//user
        if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
        }
	else{
		iRet = INT_INVALID_TXN;
	}

	if(iRet==PD_OK){
		PutField_CString(hTxn,"result","Success");
		if(iCheckPsp){
			for(i = 0; i < iPspCnt; i++){
				sprintf(csTag,"psp_id_%d",i);
				if(GetField_CString(hTxn,csTag,&csPspId)){
					if(!iCheckBank){
						sprintf(csCmd,"reset_checkpsp_cutoff.sh %s",csPspId);
DEBUGLOG(("Authorize::call reset check psp cut-off [%s]\n",csCmd));
					}
					else{
						sprintf(csCmd,"reset_checkbank_cutoff.sh %s %s",csPspId,csBankCode);
DEBUGLOG(("Authorize::call reset check bank cut-off [%s]\n",csCmd));
					}
					iRet = system(csCmd);
					if(iRet!=PD_OK){
						iRet = INT_ERR;
						PutField_CString(hTxn,"result","Failed");
						PutField_Int(hContext,"internal_error",iRet);
						break;
					}
				}
			}
		}
		else{
			recordset_t     *rRecordSet;
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

			if(!iCheckBank){
				PutField_CString(hTxn,"reset_type","All");
				///reset all psp and all bank cut-off time
				recordset_init(rRecordSet,0);
				DBObjPtr = CreateObj(DBPtr,"DBPspTxnCheck","GetAll");
				if ((DBObjPtr)(rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						if(GetField_CString(hRec,"party_id",&csPspId)){
							sprintf(csCmd,"reset_checkpsp_cutoff.sh %s",csPspId);
DEBUGLOG(("Authorize::call reset check psp cut-off [%s]\n",csCmd));
							iRet = system(csCmd);
							if(iRet!=PD_OK){
								iRet = INT_ERR;
								PutField_CString(hTxn,"result","Failed");
								PutField_Int(hContext,"internal_error",iRet);
								break;
							}
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}

				recordset_init(rRecordSet,0);
				DBObjPtr = CreateObj(DBPtr,"DBBankTxnCheck","GetAllBankCheck");
				if ((DBObjPtr)(rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						if(GetField_CString(hRec,"party_id",&csPspId) &&
						   GetField_CString(hRec,"bank_code",&csBankCode)){
							sprintf(csCmd,"reset_checkbank_cutoff.sh %s %s",csPspId,csBankCode);
DEBUGLOG(("Authorize::call reset check bank cut-off [%s]\n",csCmd));
							iRet = system(csCmd);
							if(iRet!=PD_OK){
								iRet = INT_ERR;
								PutField_CString(hTxn,"result","Failed");
								PutField_Int(hContext,"internal_error",iRet);
								break;
							}
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}
			}
			else{
				//reset specified bank(with all psp) cut-off time
				recordset_init(rRecordSet,0);
				DBObjPtr = CreateObj(DBPtr,"DBBankTxnCheck","GetAllBankCheckByBank");
				if ((DBObjPtr)(rRecordSet,csBankCode) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						if(GetField_CString(hRec,"party_id",&csPspId)){
							sprintf(csCmd,"reset_checkbank_cutoff.sh %s %s",csPspId,csBankCode);
DEBUGLOG(("Authorize::call reset check bank cut-off [%s]\n",csCmd));
							iRet = system(csCmd);
							if(iRet!=PD_OK){
								iRet = INT_ERR;
								PutField_CString(hTxn,"result","Failed");
								PutField_Int(hContext,"internal_error",iRet);
								break;
							}
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}
			}
			RecordSet_Destroy(rRecordSet);
			FREE_ME(rRecordSet);
		}
	}

	if(GetField_CString(hTxn,"reset_type",&csType) &&
	   GetField_CString(hTxn,"result",&csResult)){
		sprintf(csCmd,"reset_cutoff_result.sh %s %s %s",csType,csResult,csUser);
		system(csCmd);
DEBUGLOG(("Authorize::call reset cut-off result[%s]\n",csCmd));
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsRSC Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
