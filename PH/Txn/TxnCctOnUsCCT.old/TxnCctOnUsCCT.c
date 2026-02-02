/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/30              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnCctOnUsCCT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
void TxnCctOnUsCCT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	
DEBUGLOG(("TxnCctOnUsCCT()\n"));
//	PutField_CString(hRequest,"redirect_url","https://mcon.ectfr.net/test/encrypt.jsp");
PutField_CString(hResponse,"redirect_url","https://mcon.ectfr.net/ectfr/netapi/pay10/");
//	PutField_CString(hRequest,"redirect_url","https://abc_test.1-pay.com/test/encrypt.jsp");
//	PutField_CString(hResponse,"redirect_url","https://abc_test.1-pay.com/vnetcar/netapi/pay04/?");

/*post method*/
	PutField_CString(hResponse,"url_method",PD_GET_METHOD);
DEBUGLOG(("TxnCctOnUsCCT() exit = [%d]\n",iRet));

/*merchant id */
//	PutField_CString(hRequest,"merchant_id","TESTMERCH");
//	PutField_CString(hResponse,"merchant_id","TESTMERCH");
//	PutField_CString(hRequest,"txn_ccy","RMB");
//PutField_CString(hRequest,"psp_url","https://abc_test.1-pay.com");
//PutField_CString(hRequest,"request_function","test/encrypt2.jsp");
	PutField_CString(hRequest,"psp_url","https://mcon.ectfr.net");
	PutField_CString(hRequest,"request_function","test/encrypt.jsp");
	PutField_CString(hRequest,"tot_token","0");
	PutField_CString(hRequest,"server_ip","202.175.89.123");
	PutField_CString(hRequest,"txn_msg","TESTING");

        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2CCT","Authorize");
        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("TxnWebOnUsCCT::Authorize() iRet = [%d]\n",iRet));
	
	return	iRet;
}

int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char*	csPtr;
	
DEBUGLOG(("TxnCctOnUsCCT() Decrypt\n"));
	PutField_CString(hRequest,"psp_url","https://mcon.ectfr.net");
	PutField_CString(hRequest,"request_function","test/decrypt.jsp");

        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2CCT","Decrypt");
        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("TxnWebOnUsCCT::Decrypt() iRet = [%d]\n",iRet));
	if (iRet == PD_OK) {
		if (GetField_CString(hResponse,"merchant_ref",&csPtr)) {
			PutField_CString(hContext,"merchant_ref",csPtr);
        		TxnObjPtr = CreateObj(TxnPtr,"TxnCctOnUsACK","Authorize");
        		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		}
	}
	return	iRet;
}
