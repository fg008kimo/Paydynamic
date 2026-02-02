/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/29              Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MmcMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"

#define	THIS_VER	"0"

char	cDebug;


void	MmcMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int iRet = PD_OK;
	char*   csBuf;
	char*	csPtr;
	//char	cPtr;
	char*   csTmp;
	double	dTmp;

DEBUGLOG(("FormatMsg()\n"));
	csBuf = (char*) malloc (PD_TMP_BUF_LEN * 2 + 1 );
	csTmp = (char*) malloc (PD_TMP_BUF_LEN + 1 );

        outMsg[0]='\0';
        *outLen = 0;

/* process_type */
        if (GetField_CString(hIn,"process_type",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"process_type");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: process_type = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** process_type is missing\n"));
        }

/* process_code */
        if (GetField_CString(hIn,"process_code",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"process_code");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: process_code = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** process_code is missing\n"));
        }

/* req_node_id */
        if (GetField_CString(hIn,"req_node_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"req_node_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: req_node_id = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** req_node_id is missing\n"));
        }

/* client_id */
        if (GetField_CString(hIn,"client_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"client_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: client_id = [%s]\n",csPtr));
        }


/* psp_id */
        if (GetField_CString(hIn,"psp_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"psp_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: psp_id = [%s]\n",csPtr));
        }

/* baid */
        if (GetField_CString(hIn,"baid",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"baid");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: baid = [%s]\n",csPtr));
        }

/* txn_amt */
	if (GetField_Double(hIn,"txn_amt",&dTmp) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg Txn Amt = [%f]\n",dTmp));
		sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatMsg Txn Amt = [%s]\n",csTmp));
                strcat((char*)outMsg,"txn_amt");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN );
                strcat((char*)outMsg,csTmp);
                strcat((char*)outMsg,MY_MMC_TOKEN);
        }
        else if (GetField_CString(hIn,"txn_amt",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"txn_amt");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: txn_amt = [%s]\n",csPtr));
        }
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** txn_amt is missing\n"));
	}

/* txn_ccy */
        if (GetField_CString(hIn,"txn_ccy",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"txn_ccy");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: txn_ccy = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** txn_ccy is missing\n"));
        }

/* txn_country */
        if (GetField_CString(hIn,"txn_country",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"txn_country");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: txn_country = [%s]\n",csPtr));
        }
	else {
DEBUGLOG(("FormatMsg:: **- txn_country is missing\n"));
        }

/* status */
        if (GetField_CString(hIn,"response_code",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"status");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: status = [%s]\n",csPtr));
        }

/* node_txn_code */
        if (GetField_CString(hIn,"node_txn_code",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"node_txn_code");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: node_txn_code = [%s]\n",csPtr));
        }
        else {
DEBUGLOG(("FormatMsg:: **- node_txn_code is missing\n"));
        }

/* node_ref */
        if (GetField_CString(hIn,"node_ref",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"node_ref");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: node_ref = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** node_ref is missing\n"));
        }

/* node_txn_date */
        if (GetField_CString(hIn,"node_txn_date",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"node_txn_date");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: node_txn_date = [%s]\n",csPtr));
        }

/* node_approval_date */
        if (GetField_CString(hIn,"node_approval_date",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"node_approval_date");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: node_approval_date = [%s]\n",csPtr));
        }

/* enctype */
        if (GetField_CString(hIn,"enctype",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"enctype");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: enctype = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** enctype is missing\n"));
        }

/* signature */
        if (GetField_CString(hIn,"mac",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"signature");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: mac = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** mac is missing\n"));
        }

/* verno */
        strcat((char*)outMsg,"verno");
        strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
        strcat((char*)outMsg,THIS_VER);
        strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatMsg:: verno = [%s]\n",THIS_VER));

 	if (iRet == PD_OK) 
                *outLen = strlen((char*)outMsg);
	else
        	*outLen = 0;
DEBUGLOG(("FormatMsg() [%s][%d]\n",outMsg,*outLen));

	FREE_ME(csBuf);
	FREE_ME(csTmp);
DEBUGLOG(("FormatMsg() ret = [%d]\n",iRet));
	return iRet;
}

int FormatNetworkMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int iRet = PD_OK;
	char*   csBuf;
	char*	csPtr;
	//char	cPtr;
	char*   csTmp;

DEBUGLOG(("FormatNetworkMsg()\n"));
	csBuf = (char*) malloc (PD_TMP_BUF_LEN * 2 + 1 );
	csTmp = (char*) malloc (PD_TMP_BUF_LEN + 1 );

        outMsg[0]='\0';
        *outLen = 0;

/* process_type */
        if (GetField_CString(hIn,"process_type",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"process_type");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: process_type = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** process_type is missing\n"));
        }

/* process_code */
        if (GetField_CString(hIn,"process_code",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"process_code");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: process_code = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** process_code is missing\n"));
        }

/* req_node_id */
        if (GetField_CString(hIn,"req_node_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"req_node_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: req_node_id = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** req_node_id is missing\n"));
        }

/* client_id */
        if (GetField_CString(hIn,"client_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"client_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: client_id = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** client_id is missing\n"));
        }


/* psp_id */
        if (GetField_CString(hIn,"psp_id",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"psp_id");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: psp_id = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** psp_id is missing\n"));
        }

/* client_name */
        if (GetField_CString(hIn,"client_name",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"client_name");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: client_name = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** client_name is missing\n"));
        }


/* psp_name */
        if (GetField_CString(hIn,"psp_name",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"psp_name");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: psp_name = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** psp_name is missing\n"));
        }


/* baid */
        if (GetField_CString(hIn,"baid",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"baid");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: baid = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** baid is missing\n"));
        }

/* baid_name */
        if (GetField_CString(hIn,"baid_name",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"baid_name");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: baid_name = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** baid_name is missing\n"));
        }

/* country */
        if (GetField_CString(hIn,"country",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"country");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: country = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** country is missing\n"));
        }

/* enctype */
        if (GetField_CString(hIn,"enctype",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"enctype");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: enctype = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** enctype is missing\n"));
        }

/* signature */
        if (GetField_CString(hIn,"mac",&csPtr) && iRet == PD_OK) {
                strcat((char*)outMsg,"signature");
                strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: mac = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatNetworkMsg:: *** mac is missing\n"));
        }

/* verno */
        strcat((char*)outMsg,"verno");
        strcat((char*)outMsg,MY_MMC_FIELD_TOKEN);
        strcat((char*)outMsg,THIS_VER);
        strcat((char*)outMsg,MY_MMC_TOKEN);
DEBUGLOG(("FormatNetworkMsg:: verno = [%s]\n",THIS_VER));

 	if (iRet == PD_OK) 
                *outLen = strlen((char*)outMsg);
	else
        	*outLen = 0;
DEBUGLOG(("FormatNetworkMsg() [%s][%d]\n",outMsg,*outLen));

	FREE_ME(csBuf);
	FREE_ME(csTmp);
DEBUGLOG(("FormatNetworkMsg() ret = [%d]\n",iRet));
	return iRet;
}
int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t  *hRec;
	char    *csTmpBuf;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));

	csTmpBuf = (char*) malloc(PD_TMP_BUF_LEN +1);

	if (Str2Cls(hRec,(char *)inMsg,MY_MMC_TOKEN, MY_MMC_FIELD_TOKEN) == PD_OK) {

/* process_type */
                if (GetField_CString(hRec,"process_type",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: process_type = [%s]\n",csPtr));
                        PutField_CString(hOut,"process_type",csPtr);
/* auth data  */
			if (!strcmp(csPtr,PD_PROCESS_TYPE_NETWORK))  {
				iRet = BuildNetworkAuthData(hRec);
                		if (GetField_CString(hRec,"auth_data",&csPtr)) {
                        		PutField_CString(hOut,"auth_data",csPtr);
				}
			}
			else {
				iRet = BuildAuthData(hRec);
                		if (GetField_CString(hRec,"auth_data",&csPtr)) {
                        		PutField_CString(hOut,"auth_data",csPtr);
				}
			}
                }

/* process_code */
                if (GetField_CString(hRec,"process_code",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: process_code = [%s]\n",csPtr));
                        PutField_CString(hOut,"process_code",csPtr);
                }

/* req_node_id */
                if (GetField_CString(hRec,"req_node_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: req_node_id = [%s]\n",csPtr));
                        PutField_CString(hOut,"req_node_id",csPtr);
                }

/* client_id */
                if (GetField_CString(hRec,"client_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: client_id = [%s]\n",csPtr));
                        PutField_CString(hOut,"client_id",csPtr);
                }

/* client_name */
                if (GetField_CString(hRec,"client_name",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: client_name = [%s]\n",csPtr));
                        PutField_CString(hOut,"client_name",csPtr);
                }


/* psp_id */
                if (GetField_CString(hRec,"psp_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: psp_id = [%s]\n",csPtr));
                        PutField_CString(hOut,"psp_id",csPtr);
                }
/* psp_name */
                if (GetField_CString(hRec,"psp_name",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: psp_name = [%s]\n",csPtr));
                        PutField_CString(hOut,"psp_name",csPtr);
                }

/* baid */
                if (GetField_CString(hRec,"baid",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: baid = [%s]\n",csPtr));
                        PutField_CString(hOut,"baid",csPtr);
                }

/* baid_name */
                if (GetField_CString(hRec,"baid_name",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: baid_name = [%s]\n",csPtr));
                        PutField_CString(hOut,"baid_name",csPtr);
                }

/* txn_amt */
                if (GetField_CString(hRec,"txn_amt",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
                        PutField_CString(hOut,"txn_amt",csPtr);
                }
/* txn_ccy */
                if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_ccy = [%s]\n",csPtr));
                        PutField_CString(hOut,"txn_ccy",csPtr);
                }
/* txn_country */
                if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_country = [%s]\n",csPtr));
                        PutField_CString(hOut,"txn_country",csPtr);
                }
/* country info image sync*/
                if (GetField_CString(hRec,"country",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: country = [%s]\n",csPtr));
                        PutField_CString(hOut,"country",csPtr);
                }


/* node_txn_code */
                if (GetField_CString(hRec,"node_txn_code",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: node_txn_code = [%s]\n",csPtr));
                        PutField_CString(hOut,"node_txn_code",csPtr);
                }


/* node_ref */
                if (GetField_CString(hRec,"node_ref",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: node_ref = [%s]\n",csPtr));
                        PutField_CString(hOut,"node_ref",csPtr);
                }

/* node_txn_date */
                if (GetField_CString(hRec,"node_txn_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: node_txn_date = [%s]\n",csPtr));
                        PutField_CString(hOut,"node_txn_date",csPtr);
                        PutField_CString(hOut,"transmission_datetime",csPtr);

			memcpy(csTmpBuf,csPtr,PD_DATE_LEN);
                        csTmpBuf[PD_DATE_LEN] = '\0';
                        PutField_CString(hOut,"tm_date",csTmpBuf);
DEBUGLOG(("BreakDownMsg:: tm_date = [%s]\n",csTmpBuf));
                        memcpy(csTmpBuf,&csPtr[PD_DATE_LEN],PD_TIME_LEN);
                        csTmpBuf[PD_TIME_LEN] = '\0';
                        PutField_CString(hOut,"tm_time",csTmpBuf);
                }

/* node_approval_date */
                if (GetField_CString(hRec,"node_approval_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: node_approval_date = [%s]\n",csPtr));
                        PutField_CString(hOut,"node_approval_date",csPtr);
                }


/* enctype */
                if (GetField_CString(hRec,"enctype",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: enctype = [%s]\n",csPtr));
                        PutField_CString(hOut,"enctype",csPtr);
                }

/* signature */
                if (GetField_CString(hRec,"signature",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: signature = [%s]\n",csPtr));
                        PutField_CString(hOut,"mac",csPtr);
                }
/* verno */
                if (GetField_CString(hRec,"verno",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: verno = [%s]\n",csPtr));
                        PutField_CString(hOut,"verno",csPtr);
                }

	}
	else {
DEBUGLOG(("BreakDownMsg error\n"));
		iRet = PD_ERR;
	}

	FREE_ME(csTmpBuf);
	hash_destroy(hRec);
        FREE_ME(hRec);
DEBUGLOG(("BreakDownMsg() ret = [%d]\n",iRet));
	return iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csPtr;

DEBUGLOG(("initReplyFromRequest()\n"));
/* process code */
	if (GetField_CString(hRequest,"process_code",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() process_code  =[%s]\n",csPtr));
		PutField_CString(hResponse,"process_code",csPtr);
	}

/* req_node_id */
	if (GetField_CString(hRequest,"req_node_id",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() req_node_id  =[%s]\n",csPtr));
		PutField_CString(hResponse,"req_node_id",csPtr);
	}

/* client_id */
	if (GetField_CString(hRequest,"client_id",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() client_id  =[%s]\n",csPtr));
		PutField_CString(hResponse,"client_id",csPtr);
	}

/* psp_id */
	if (GetField_CString(hRequest,"psp_id",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() psp_id  =[%s]\n",csPtr));
		PutField_CString(hResponse,"psp_id",csPtr);
	}

/* baid */
	if (GetField_CString(hRequest,"baid",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() baid  =[%s]\n",csPtr));
		PutField_CString(hResponse,"baid",csPtr);
	}


/* txn_amt */
	if (GetField_CString(hRequest,"txn_amt",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() txn_amt  =[%s]\n",csPtr));
		PutField_CString(hResponse,"txn_amt",csPtr);
	}

/* txn_ccy */
	if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() txn_ccy  =[%s]\n",csPtr));
		PutField_CString(hResponse,"txn_ccy",csPtr);
	}

/* node_ref */
	if (GetField_CString(hRequest,"node_ref",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() node_ref  =[%s]\n",csPtr));
		PutField_CString(hResponse,"node_ref",csPtr);
	}


/* enctype */
	if (GetField_CString(hRequest,"enctype",&csPtr)) {
DEBUGLOG(("initReplyFromRequest() enctype  =[%s]\n",csPtr));
		PutField_CString(hResponse,"enctype",csPtr);
	}


DEBUGLOG(("initReplyFromRequest() ret = [%d]\n",iRet));
	return iRet;
}

int BuildAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char    *csVal;
        char    *csData;
	char	*csTmp;
	double	dTmp;

	csTmp = (char*) malloc (PD_TMP_BUF_LEN + 1 );
        csData = (char*) malloc (PD_TMP_BUF_LEN * 4+1);
        csData[0] = '\0';

DEBUGLOG(("BuildAuthData()\n"));
/* req_node_id */
         if (GetField_CString(hIn,"req_node_id",&csVal)) {
DEBUGLOG(("BuildAuthData req_node_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* client_id */
         if (GetField_CString(hIn,"client_id",&csVal)) {
DEBUGLOG(("BuildAuthData client_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* psp_id */
         if (GetField_CString(hIn,"psp_id",&csVal)) {
DEBUGLOG(("BuildAuthData psp_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* baid */
         if (GetField_CString(hIn,"baid",&csVal)) {
DEBUGLOG(("BuildAuthData baid = [%s]\n",csVal));
                strcat(csData,csVal);
        }
/* txn amt */

	if (GetField_Double(hIn,"txn_amt",&dTmp)) {
		sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildAuthData txn_amt = [%s]\n",csTmp));
                strcat(csData,csTmp);
        }
        else if (GetField_CString(hIn,"txn_amt",&csVal)) {
DEBUGLOG(("BuildAuthData txn_amt = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* status */
        if (GetField_CString(hIn,"response_code",&csVal)){
DEBUGLOG(("BuildAuthData:: response code  = [%s]\n",csVal));
                strcat((char*)csData,csVal);
        }

/* node_ref */
         if (GetField_CString(hIn,"node_ref",&csVal)) {
DEBUGLOG(("BuildAuthData node_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* remote_node_ref */
         if (GetField_CString(hIn,"remote_node_ref",&csVal)) {
DEBUGLOG(("BuildAuthData remote_node_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }


DEBUGLOG(("BuildAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);
DEBUGLOG(("BuildAuthData() ret = [%d]\n",iRet));

	FREE_ME(csTmp);

	return iRet;
}

int BuildNetworkAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char    *csVal;
        char    *csData;

        csData = (char*) malloc (PD_TMP_BUF_LEN * 4+1);
        csData[0] = '\0';

DEBUGLOG(("BuildNetworkAuthData()\n"));

/* req_node_id */
         if (GetField_CString(hIn,"req_node_id",&csVal)) {
DEBUGLOG(("BuildNetworkAuthData req_node_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* client_id */
         if (GetField_CString(hIn,"client_id",&csVal)) {
DEBUGLOG(("BuildNetworkAuthData client_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* psp_id */
         if (GetField_CString(hIn,"psp_id",&csVal)) {
DEBUGLOG(("BuildNetworkAuthData psp_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }

/* baid */
         if (GetField_CString(hIn,"baid",&csVal)) {
DEBUGLOG(("BuildNetworkAuthData baid = [%s]\n",csVal));
                strcat(csData,csVal);
        }


DEBUGLOG(("BuildAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

	FREE_ME(csData);
DEBUGLOG(("BuildNetworkAuthData() ret = [%d]\n",iRet));
	return iRet;
}

