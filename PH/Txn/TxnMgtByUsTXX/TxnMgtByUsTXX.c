/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/30              Virginia Yun
Revised for testing new DB session		   2019/11/21		   Lokman Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTXX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

#define	PD_TEST_SUCCESS 0

int     TestNewSession(const hash_t *hIn);

void TxnMgtByUsTXX(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csPspId = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;
	char	cType;
	char	*csPtr = NULL;
	double	dAmt = 0.0;
	int 	iOption = PD_TEST_SUCCESS;

	hash_t *hRec;
	hRec = (hash_t *)malloc(sizeof(hash_t));

	
	if(GetField_CString(hRequest,"psp_id",&csPspId)){
		PutField_CString(hRec, "psp_id", csPspId);
DEBUGLOG(("Authorize:: psp_id = [%s]\n", csPspId));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" psp_id is missing!!\n"));
	}

	if(GetField_CString(hRequest,"txn_country",&csCountry)){
		PutField_CString(hRec, "country", csCountry);
DEBUGLOG(("Authorize:: = [%s]\n",csCountry));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" country is missing!!\n"));
	}

	if(GetField_CString(hRequest,"ccy_id",&csCcy)){
		PutField_CString(hRec, "ccy_id", csCcy);
DEBUGLOG(("Authorize:: = [%s]\n",csCcy));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" ccy_id is missing!!\n"));
	}

	if(GetField_CString(hRequest,"type",&csPtr)){
		cType = csPtr[0];
		PutField_Char(hRec, "type", cType);
DEBUGLOG(("Authorize:: type = [%c]\n", cType));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" type is missing!!\n"));
	}

	if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize:: txn_amt = [%lf]\n", dAmt));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" txn_amt is missing!!\n"));
	}

	if(GetField_CString(hRequest,"add_user",&csUser)){
		PutField_CString(hRec, "add_user", csUser);
DEBUGLOG(("Authorize::add_user = [%s]\n",csUser));
	}


	if(GetField_CString(hRequest,"option",&csPtr)){
		iOption = atoi(csPtr);
		PutField_Int(hRec, "option", iOption);
DEBUGLOG(("Authorize:: option = [%d]\n", iOption));
	}
	else{
		iOption = PD_TEST_SUCCESS;
		PutField_Int(hRec, "option", iOption);
DEBUGLOG((" option (default)\n"));
	}

	if(iOption == PD_TEST_SUCCESS){
DEBUGLOG((" test commit new session\n"));
	}
	else{
		iRet = INT_INVALID_TXN;
DEBUGLOG((" test rollback new session\n"));
	}



	//insert data
	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
	if ((unsigned long)(DBObjPtr)(csPspId, csCountry, csCcy, cType, dAmt, csUser) == PD_OK) {
DEBUGLOG(("PspBalance:CreditBalance success\n"));
	}
	else{
DEBUGLOG(("PspBalance:CreditBalance failed!!\n"));
	}

	TestNewSession(hRec); 


	FREE_ME(hRec);

DEBUGLOG(("TxnMgtByUsTXX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}



int	TestNewSession(const hash_t *hIn)
{
	int	iRet = PD_OK;

        char    *csUser = NULL;
	char	csPspId[PD_PSP_ID_LEN +1];
	char	*csCountry = NULL;
	char	*csCcy = NULL;
	char	cType;
	char	*csPtr = NULL;
	double	dAmt = 100000.0;
	int 	iOption = PD_TEST_SUCCESS;

DEBUGLOG((" TestNewSession start \n"));
	ConnectDB();


	if(GetField_CString(hIn,"psp_id",&csPtr)){
		sprintf(csPspId, "%s_N", csPtr);
DEBUGLOG(("Authorize:: psp_id = [%s]\n", csPspId));
	}

	if(GetField_CString(hIn,"country",&csCountry)){
DEBUGLOG(("Authorize:: = [%s]\n",csCountry));
	}

	if(GetField_CString(hIn,"ccy_id",&csCcy)){
DEBUGLOG(("Authorize:: = [%s]\n",csCcy));
	}

	if(GetField_Char(hIn,"type",&cType)){
DEBUGLOG(("Authorize:: type = [%c]\n", cType));
	}

	if(GetField_CString(hIn,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user = [%s]\n",csUser));
	}


	if(GetField_Int(hIn,"option",&iOption)){
DEBUGLOG(("Authorize::option = [%d]\n",iOption));
	}



	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
	if ((unsigned long)(DBObjPtr)(csPspId, csCountry, csCcy, cType, dAmt, csUser) == PD_OK) {
DEBUGLOG(("PspBalance:CreditBalance success\n"));
	}
	else{
DEBUGLOG(("PspBalance:CreditBalance failed!!\n"));
	}

	if(iOption){
		TxnCommit();
	}
	else{
		TxnAbort();
	}

	DisconnectDB();
DEBUGLOG((" TestNewSession end \n"));
	return	iRet;
}
