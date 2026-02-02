/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/21              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCDB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsCDB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csTmp = NULL;
        char    *csUser = NULL;
	char	*csTxnCountry = NULL;
        char    *csPspId = NULL;
        char    *csBankCode = NULL;

        int     iTmp =  PD_NOT_FOUND;

        hash_t  *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


DEBUGLOG(("Authorize\n"));

	
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}


	if(GetField_CString(hRequest,"bank_code",&csBankCode)){
DEBUGLOG(("Authorize::bank_code= [%s]\n",csBankCode));
		PutField_CString(hContext,"bank_code",csBankCode);
	}
        else{
DEBUGLOG(("Authorize::bank_code not found!!\n"));
ERRLOG("TxnMgtByUsCDB::Authorize::bank_code not found!!\n");
		iRet=INT_BANK_CODE_NOT_FOUND;
	}


	if(GetField_CString(hRequest,"psp_id",&csTmp)){
DEBUGLOG(("Authorize::psp_id= [%s]\n",csTmp));
		PutField_CString(hContext,"psp_id",csTmp);
	}
        else{
	        if(GetField_CString(hRequest,"txn_country",&csTmp)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTmp));
		        PutField_CString(hContext,"country",csTmp);
	        }
                else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMgtByUsCDB::Authorize::txn_country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;;
                }
       
        }
       


	if(iRet==PD_OK){

                // by Psp_Id
                if(GetField_CString(hContext, "psp_id", &csPspId)){

DEBUGLOG(("Authorize::Call PspCountry:GetPspCountry\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
                        if ((*DBObjPtr)(csPspId, rRecordSet) == PD_OK) {
DEBUGLOG(("GetPspCountry::found record = [%s]\n", csPspId));
                            hRec = RecordSet_GetFirst(rRecordSet);
                            while (hRec) {

                                    if (GetField_CString(hRec,"country",&csTxnCountry)) {
DEBUGLOG(("GetPspCountry::country = [%s]\n",csTxnCountry));
                                        PutField_CString(hContext,"country",csTxnCountry);

DEBUGLOG(("Authorize::Call DisabledBank:Add\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBDisabledBank","Add");
                                        if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                                iRet = INT_ERR;

                                                break; // for return error 
                                        }
                                    }
                                    hRec = RecordSet_GetNext(rRecordSet); 
                            }

                        } 
                        else{
DEBUGLOG(("GetPspCountry:: not found record for [%s]\n",csPspId));
ERRLOG("TxnMgtByUsCDB:Authorize::GetPspCountry::not found record!!\n");
                                iRet = INT_NOT_RECORD;
                        }
                        RecordSet_Destroy(rRecordSet);
                }
                // by Country
                else if(GetField_CString(hContext, "country", &csTxnCountry)){

DEBUGLOG(("Authorize::Call PspCountry:GetPspByCountry\n"));
                        DBObjPtr = CreateObj(DBPtr, "DBPspCountry", "GetPspByCountry");
                        if ((*DBObjPtr)(csTxnCountry, rRecordSet) == PD_OK) {
DEBUGLOG(("GetPspByCountry::found record = [%s]\n", csTxnCountry));
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        if (GetField_CString(hRec, "psp_id", &csPspId)) {
DEBUGLOG(("GetPspByCountry::psp_id = [%s]\n", csPspId));
                                                PutField_CString(hContext, "psp_id", csPspId);
DEBUGLOG(("Authorize::Call DisabledBank:MatchDisabledBank\n"));
                                                DBObjPtr = CreateObj(DBPtr, "DBDisabledBank","MatchDisabledBank");
   
                                                iTmp = (unsigned long) ((*DBObjPtr)(csPspId, csBankCode));
                                                
                                                if (iTmp == PD_NOT_FOUND) {

DEBUGLOG(("Authorize::Call DisabledBank:Add\n"));

                                                        DBObjPtr = CreateObj(DBPtr, "DBDisabledBank", "Add");
                                                        if ((unsigned long) ((*DBObjPtr)(hContext)) !=  PD_OK) {
                                                                iRet = INT_ERR;
                                                                break; // for return error    
                                                        } 

                                                } 
                                                else if (iTmp == PD_FOUND) {
DEBUGLOG(("MatchDisbaledBank::found record psp_id = [%s] bank_code = [%s]\n", csPspId, csBankCode));
                                                } else {
DEBUGLOG(("MatchDisbaledBank::SQL Other Error"));
                                                        iRet = INT_ERR;
                                                        break; 
                                                }
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
                        }
                        else{
DEBUGLOG(("GetPspByCountry::not found record for [%s]\n", csTxnCountry));
ERRLOG("TxnMgtByUsCDB:Authorize::GetPspByCountry::not found record!!\n");
                                iRet = INT_NOT_RECORD;
                        }
                        RecordSet_Destroy(rRecordSet);

                }
        }


/*
// No need to add log
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
        }


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
			iRet = INT_ERR;
	}
*/

	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("TxnMgtByUsCDB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
