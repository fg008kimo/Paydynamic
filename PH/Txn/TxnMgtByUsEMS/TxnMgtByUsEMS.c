/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/13              Elvis Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsEMS.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMgtByUsEMS(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	
	char	*csEmailAddr;
	char	*csEmailAddrCode;
	
	int	iEmailAddrCodeLen = 0;
	int 	iTotalEmailNum = 0;
	int     i = 0;

	char	*csTmp;
	char	cTmp;
	int	iTmp = 0;
	
	char    csTag[PD_TAG_LEN + 1];

	csEmailAddr = (char*) malloc (1024);
        csEmailAddrCode = (char*) malloc (1024);

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cTmp = csTmp[0];
DEBUGLOG(("Authorize() action = [%c]\n", cTmp));
                PutField_Char(hContext,"action",cTmp);
        } else {
                iRet = INT_ACTION_NOT_FOUND;
DEBUGLOG(("Authorize() action NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS:: Authorize() action NOT FOUND!!!\n");
        }

/* funct */
        if (GetField_CString(hRequest, "funct", &csTmp)) {
DEBUGLOG(("Authorize() funct = [%s]\n", csTmp));
                PutField_CString(hContext,"funct",csTmp);
        } else {
                iRet = INT_EML_FUNCT_NOT_FOUND;
DEBUGLOG(("Authorize() funct NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS:: Authorize() funct NOT FOUND!!!\n");
        }

/* party_type */
        if (GetField_CString(hRequest, "party_type", &csTmp)) {
                cTmp = csTmp[0];
DEBUGLOG(("Authorize() party_type = [%c]\n", cTmp));
                PutField_Char(hContext,"party_type",cTmp);
        } else {
                iRet = INT_PARTY_TYPE_NOT_FOUND;
DEBUGLOG(("Authorize() party_type NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS:: Authorize() party_type NOT FOUND!!!\n");
        }

/* party_id */
        if (GetField_CString(hRequest, "party_id", &csTmp)) {
DEBUGLOG(("Authorize() party_id = [%s]\n", csTmp));
                PutField_CString(hContext,"party_id",csTmp);
        } else {
                iRet = INT_PARTY_ID_NOT_FOUND;
DEBUGLOG(("Authorize() party_id NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS:: Authorize() party_id NOT FOUND!!!\n");
        }

/* total_email_num */
	if (GetField_CString(hRequest, "total_email_num", &csTmp)) {
                iTotalEmailNum = atoi(csTmp);
DEBUGLOG(("Authorize() total_email_num = [%d]\n", iTotalEmailNum));
                PutField_Int(hContext,"total_email_num",iTotalEmailNum);
        }

/* email_addr */	
       	if (GetField_CString(hRequest, "email_addr", &csEmailAddr)) {
DEBUGLOG(("Authorize() email_addr = [%s]\n", csEmailAddr));
                PutField_CString(hContext,"email_addr",csEmailAddr);

                iEmailAddrCodeLen = 0; 

		for (i=0; i<iTotalEmailNum; i++) {
			sprintf(csEmailAddrCode,"%s",&csEmailAddr[iEmailAddrCodeLen]);
                     	if (csEmailAddrCode[0] == PD_EMAIL_ADDR_DELIMIT_SYMBOL_CHECK) {
                      		iEmailAddrCodeLen++;

                            	sprintf(csEmailAddrCode,"%s","\0");

                             	sprintf(csTag, "email_addr_%d", i+1);
                   	} else {
                            	strtok(csEmailAddrCode,PD_EMAIL_ADDR_DELIMIT_SYMBOL);
                              	iEmailAddrCodeLen += (strlen(csEmailAddrCode) + 1);

                             	sprintf(csTag, "email_addr_%d", i+1);
                            	PutField_CString(hContext,csTag,csEmailAddrCode);
                     	}
DEBUGLOG(("Authorize() [%s] = [%s]\n",csTag,csEmailAddrCode));
			
		}
       	}

/* default */
        if (GetField_CString(hRequest, "default", &csTmp)) {
                iTmp = atoi(csTmp);
DEBUGLOG(("Authorize() default = [%d]\n", iTmp));
                PutField_Int(hContext,"default",iTmp);
        } else {
                iRet = INT_ERR;
DEBUGLOG(("Authorize() default NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS::Authorize() default NOT FOUND!!!\n");
        }

/* user */
        if (GetField_CString(hRequest, "add_user", &csTmp)) {
DEBUGLOG(("Authorize() user = [%s]\n", csTmp));
                PutField_CString(hContext,"create_user",csTmp);
                PutField_CString(hContext,"update_user",csTmp);
        } else {
                iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsEMS::Authorize() user NOT FOUND!!!\n");
        }

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::call BOEmailSetting::ProcessTpl()\n"));
		BOObjPtr = CreateObj(BOPtr,"BOEmailSetting","ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hContext,hRequest,hResponse));
        	if(iRet != PD_OK){
DEBUGLOG(("Authorize::call BOEmailSetting::ProcessTpl() Failed\n"));
ERRLOG("TxnMgtByUsEMS::Authorize::call BOEmailSetting::ProcessTpl Failed, iRet=%d\n", iRet);
                } else {
DEBUGLOG(("Authorize::call BOEmailSetting::ProcessTpl() Success\n"));
                }	
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	}

	FREE_ME(csEmailAddr);
	FREE_ME(csEmailAddrCode);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}
