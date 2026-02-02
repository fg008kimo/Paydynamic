/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/02              Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OlcMsg.h"
#include "common.h"
#include "utilitys.h"
#include "b64.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"

char	cDebug;

OBJPTR(Msg);
OBJPTR(DB);

void	OlcMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csPtr;
	char	cStatus;

DEBUGLOG(("FormatMsg()\n"));

	outMsg[0]= '\0';
        *outLen = 0;

	
	if (GetField_Char(hIn,"status",&cStatus)) {
DEBUGLOG(("FormatMsg :: status = [%c]\n",cStatus));
		if (GetField_CString(hIn,"process_type",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: process_type = [%s]\n",csPtr));
                                strcat((char*)outMsg,"process_type");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }
                        if (GetField_CString(hIn,"process_code",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: process_code = [%s]\n",csPtr));
                                strcat((char*)outMsg,"process_code");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }
                        if (GetField_CString(hIn,"response_code",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: response_code = [%s]\n",csPtr));
                                strcat((char*)outMsg,"status");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }
                        if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: url = [%s]\n",csPtr));
                                strcat((char*)outMsg,"txn_url");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                char* csBuf;
                                csBuf = (char*) malloc (PD_MAX_BUFFER +1);
                                base64_encode((unsigned char*)csPtr,strlen(csPtr),csBuf,PD_MAX_BUFFER);
                                strcat((char*)outMsg,csBuf);
DEBUGLOG(("FormatMsg (INI):: url = [%s] base64\n",csBuf));
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                                FREE_ME(csBuf);
                        }
                        else {
                                strcat((char*)outMsg,"txn_url");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }	
		
			if (GetField_CString(hIn,"merchant_ref",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: merchant_ref = [%s]\n",csPtr));
                                strcat((char*)outMsg,"mer_ref");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }
                        if (GetField_CString(hIn,"merchant_id",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: merchant_id = [%s]\n",csPtr));
                                strcat((char*)outMsg,"mer_id");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }
                        if (GetField_CString(hIn,"encrypt_type",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: encrypt_type = [%s]\n",csPtr));
                                strcat((char*)outMsg,"enctype");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                                strcat((char*)outMsg,MY_OLC_TOKEN);
                        }

			if (GetField_CString(hIn,"mac",&csPtr)) {
DEBUGLOG(("FormatMsg (INI):: mac = [%s]\n",csPtr));
                                strcat((char*)outMsg,"signature");
                                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                                strcat((char*)outMsg,csPtr);
                        }
DEBUGLOG(("FormatMsg (INI):: outmsg = [%s]\n",outMsg));
                                *outLen = strlen((const char*)outMsg);
                        return iRet;	
	}

DEBUGLOG(("FormatMsg() Exit\n"));

	return iRet;
}


int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	
	char    *csPtr;
	char    *csTag;
	char    *csTmp;
        hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

        if (Str2Cls(hRec,(char*)inMsg,MY_OLC_TOKEN, MY_OLC_FIELD_TOKEN) == PD_OK) {	
		csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
		csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);
/* process type */
		if (GetField_CString(hRec,"process_type",&csPtr)) {
                        PutField_CString(hOut,"process_type",csPtr);
DEBUGLOG(("BreakDownMsg:: process_type = [%s]\n",csPtr));
                }

/* process code */
		if (GetField_CString(hRec,"process_code",&csPtr)) {
                        PutField_CString(hOut,"process_code",csPtr);
DEBUGLOG(("BreakDownMsg:: process_code = [%s]\n",csPtr));
                }
/* txn_amt */
		if (GetField_CString(hRec,"txn_amt",&csPtr)) {
                        PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
                }
/* ccy */
		if (GetField_CString(hRec,"ccy",&csPtr)) {
                        PutField_CString(hOut,"txn_ccy",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_ccy = [%s]\n",csPtr));
                }
/* mer_id */
		if (GetField_CString(hRec,"mer_id",&csPtr)) {
                        PutField_CString(hOut,"merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg:: merchant_id = [%s]\n",csPtr));
                }
/* mer_ref */
		if (GetField_CString(hRec,"mer_ref",&csPtr)) {
                        PutField_CString(hOut,"merchant_ref",csPtr);
DEBUGLOG(("BreakDownMsg:: merchant_id = [%s]\n",csPtr));
                }
/* mer_txn_date */
		if (GetField_CString(hRec,"mer_txn_date",&csPtr)) {
			strcpy(csTag,"transmission_datetime");
                        PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));

                        memcpy(csTmp,csPtr,PD_DATE_LEN);
                        csTmp[PD_DATE_LEN] = '\0';
                        strcpy(csTag,"tm_date");
                        PutField_CString(hOut,csTag,csTmp);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csTmp));
                        memcpy(csTmp,&csPtr[PD_DATE_LEN],PD_TIME_LEN);
                        csTmp[PD_TIME_LEN] = '\0';
                        strcpy(csTag,"tm_time");
                        PutField_CString(hOut,csTag,csTmp);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csTmp));
                }
/* language */
		if (GetField_CString(hRec,"lang",&csPtr)) {
                        PutField_CString(hOut,"language",csPtr);
DEBUGLOG(("BreakDownMsg:: language = [%s]\n",csPtr));
                }
/* success_url */
		if (GetField_CString(hRec,"success_url",&csPtr)) {
                        PutField_CString(hOut,"success_url",csPtr);
DEBUGLOG(("BreakDownMsg:: success_url = [%s]\n",csPtr));
                }

/* failure_url */
		if (GetField_CString(hRec,"failure_url",&csPtr)) {
                        PutField_CString(hOut,"failure_url",csPtr);
DEBUGLOG(("BreakDownMsg:: failure_url = [%s]\n",csPtr));
                }

/* success_s2s_url */
		if (GetField_CString(hRec,"success_s2s_url",&csPtr)) {
                        PutField_CString(hOut,"success_callback_url",csPtr);
DEBUGLOG(("BreakDownMsg:: success_s2s_url = [%s]\n",csPtr));
                }

/* failure_s2s_url */
		if (GetField_CString(hRec,"failure_s2s_url",&csPtr)) {
                        PutField_CString(hOut,"failure_callback_url",csPtr);
DEBUGLOG(("BreakDownMsg:: failure_s2s_url = [%s]\n",csPtr));
                }
/* encrypt_type */
		if (GetField_CString(hRec,"enctype",&csPtr)) {
                        PutField_CString(hOut,"encrypt_type",csPtr);
DEBUGLOG(("BreakDownMsg:: enctype = [%s]\n",csPtr));
                }
/* signature */
		if (GetField_CString(hRec,"signature",&csPtr)) {
                        PutField_CString(hOut,"mac",csPtr);
DEBUGLOG(("BreakDownMsg:: mac = [%s]\n",csPtr));
                }
/* verno */
		if (GetField_CString(hRec,"verno",&csPtr)) {
			strcpy(csTag,"version_no");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        int iVer;
                        iVer = ctos((const unsigned char*)csPtr,strlen(csPtr));
                        PutField_Int(hOut,csTag,iVer);
		}
/* service_code */
		if (GetField_CString(hRec,"service_code",&csPtr)) {
                        PutField_CString(hOut,"service_code",csPtr);
DEBUGLOG(("BreakDownMsg:: service_code = [%s]\n",csPtr));
                }
/* country */
		if (GetField_CString(hRec,"country",&csPtr)) {
                        PutField_CString(hOut,"txn_country",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_country = [%s]\n",csPtr));
                }
/* deposit_datetime */
		if (GetField_CString(hRec,"deposit_datetime",&csPtr)) {
                        PutField_CString(hOut,"deposit_datetime",csPtr);
DEBUGLOG(("BreakDownMsg:: deposit_datetime = [%s]\n",csPtr));
                }

/* bank_acct_num */
		if (GetField_CString(hRec,"bank_acct_num",&csPtr)) {
                        PutField_CString(hOut,"bank_acct_num",csPtr);
DEBUGLOG(("BreakDownMsg:: bank_acct_num = [%s]\n",csPtr));
                }

/* deposit_bank */
		if (GetField_CString(hRec,"deposit_bank",&csPtr)) {
                        PutField_CString(hOut,"deposit_bank",csPtr);
DEBUGLOG(("BreakDownMsg:: deposit_bank = [%s]\n",csPtr));
                }

/* deposit_ref */
		if (GetField_CString(hRec,"deposit_ref",&csPtr)) {
                        PutField_CString(hOut,"deposit_ref",csPtr);
DEBUGLOG(("BreakDownMsg:: deposit_ref = [%s]\n",csPtr));
                }

/* banner_logo */
		if (GetField_CString(hRec,"banner_logo",&csPtr)) {
                        PutField_CString(hOut,"banner_logo",csPtr);
DEBUGLOG(("BreakDownMsg:: banner_logo = [%s]\n",csPtr));
                }

/* echo_msg_1 */
		if (GetField_CString(hRec,"echo_msg_1",&csPtr)) {
                        PutField_CString(hOut,"echo_msg_1",csPtr);
DEBUGLOG(("BreakDownMsg:: echo_msg_1 = [%s]\n",csPtr));
                }

/* echo_msg_2 */
		if (GetField_CString(hRec,"echo_msg_2",&csPtr)) {
                        PutField_CString(hOut,"echo_msg_2",csPtr);
DEBUGLOG(("BreakDownMsg:: echo_msg_2 = [%s]\n",csPtr));
                }
/* echo_msg_3 */
		if (GetField_CString(hRec,"echo_msg_3",&csPtr)) {
                        PutField_CString(hOut,"echo_msg_3",csPtr);
DEBUGLOG(("BreakDownMsg:: echo_msg_3 = [%s]\n",csPtr));
                }

/* opt_1 */
		if (GetField_CString(hRec,"opt_1",&csPtr)) {
                        PutField_CString(hOut,"opt_1",csPtr);
DEBUGLOG(("BreakDownMsg:: opt_1 = [%s]\n",csPtr));
                }

/* opt_2 */
		if (GetField_CString(hRec,"opt_2",&csPtr)) {
                        PutField_CString(hOut,"opt_2",csPtr);
DEBUGLOG(("BreakDownMsg:: opt_2 = [%s]\n",csPtr));
                }

/* opt_3 */
		if (GetField_CString(hRec,"opt_3",&csPtr)) {
                        PutField_CString(hOut,"opt_3",csPtr);
DEBUGLOG(("BreakDownMsg:: opt_3 = [%s]\n",csPtr));
                }

/* remark */
		if (GetField_CString(hRec,"remark",&csPtr)) {
                        PutField_CString(hOut,"remark",csPtr);
DEBUGLOG(("BreakDownMsg:: remark = [%s]\n",csPtr));
		}

		iRet = BuildAuthData(hOut);

		FREE_ME(csTag);
		FREE_ME(csTmp);
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
                iRet = PD_ERR;
        }

        hash_destroy(hRec);
        FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));

	return iRet;
}

int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csPtr = NULL;
DEBUGLOG(("initReplyFromRequest()\n"));


        if (GetField_CString(hRequest,"success_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: success_url = [%s]\n",csPtr));
                PutField_CString(hResponse,"success_url",csPtr);
        }

        if (GetField_CString(hRequest,"failure_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: failure_url = [%s]\n",csPtr));
                PutField_CString(hResponse,"failure_url",csPtr);
        }

        if (GetField_CString(hRequest,"success_callback_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: success_callback_url = [%s]\n",csPtr));
                PutField_CString(hResponse,"success_callback_url",csPtr);
        }

        if (GetField_CString(hRequest,"failure_callback_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: failure_callback_url = [%s]\n",csPtr));
                PutField_CString(hResponse,"failure_callback_url",csPtr);
        }

        if (GetField_CString(hRequest,"transmission_datetime",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: transmission_datetime = [%s]\n",csPtr));
                PutField_CString(hResponse,"transmission_datetime",csPtr);
        }
        if (GetField_CString(hRequest,"merchant_id",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: merchant_id = [%s]\n",csPtr));
                PutField_CString(hResponse,"merchant_id",csPtr);
        }
        if (GetField_CString(hRequest,"remark",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: remark = [%s]\n",csPtr));
                PutField_CString(hResponse,"remark",csPtr);
        }
        if (GetField_CString(hRequest,"merchant_ref",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: merchant_ref = [%s]\n",csPtr));
                PutField_CString(hResponse,"merchant_ref",csPtr);
        }

        if (GetField_CString(hRequest,"txn_country",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: txn_country = [%s]\n",csPtr));
                PutField_CString(hResponse,"txn_country",csPtr);
        }
        if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: txn_ccy = [%s]\n",csPtr));
                PutField_CString(hResponse,"txn_ccy",csPtr);
        }

        if (GetField_CString(hRequest,"language",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: language = [%s]\n",csPtr));
                PutField_CString(hResponse,"language",csPtr);
        }
        if (GetField_CString(hRequest,"process_code",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: proces_code = [%s]\n",csPtr));
                PutField_CString(hResponse,"process_code",csPtr);
        }
        if (GetField_CString(hRequest,"encrypt_type",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: encrypt_type = [%s]\n",csPtr));
                PutField_CString(hResponse,"encrypt_type",csPtr);
        }


DEBUGLOG(("initReplyFromRequest() Exit\n"));
        return iRet;
}



int BuildAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char    *csVal;
        char    *csData;

        csData = (char*) malloc (PD_TMP_BUF_LEN +1);
        csData[0] = '\0';

        if (GetField_CString(hIn,"txn_amt",&csVal)) {
DEBUGLOG(("BuildAuthData txn_amt = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"txn_ccy",&csVal)) {
DEBUGLOG(("BuildAuthData txn_ccy = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_ref",&csVal)) {
DEBUGLOG(("BuildAuthData merchant_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_id",&csVal)) {
DEBUGLOG(("BuildAuthData merchant_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"transmission_datetime",&csVal)) {
DEBUGLOG(("BuildAuthData transmission_datetime = [%s]\n",csVal));
                strcat(csData,csVal);
        }

DEBUGLOG(("BuildAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

        FREE_ME(csData);
        return iRet;
}


int BuildRespAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char    *csVal;
        char    *csData;

        csData = (char*) malloc (PD_TMP_BUF_LEN * 4+1);
        csData[0] = '\0';

        if (GetField_CString(hIn,"response_code",&csVal)) {
DEBUGLOG(("BuildRespAuthData response_code = [%s]\n",csVal));
                strcat(csData,csVal);
        }

        if (GetField_CString(hIn,"merchant_ref",&csVal)) {
DEBUGLOG(("BuildRespAuthData merchant_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_id",&csVal)) {
DEBUGLOG(("BuildRespAuthData merchant_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }
DEBUGLOG(("BuildRespAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

DEBUGLOG(("BuildRespAuthData iRet = [%d]\n",iRet));
        FREE_ME(csData);
        return iRet;
}



int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{   
        int     iRet = PD_OK;
        char*   csBuf;
        char*   csPtr;
        char    cStatus;
        char    csTmp[PD_TMP_BUF_LEN + 1];
        double  dTmp;
        char*   csTxnSeq;
        char    csTxnSeqVal[PD_TXN_SEQ_LEN * 2 +1];
    
DEBUGLOG(("FormatAckMsg()\n"));
        outMsg[0]= '\0';
        *outLen = 0;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
    
    
        memset(csBuf,0,sizeof(csBuf));
        strcat((char*)csBuf,"url");
        strcat((char*)csBuf,MY_OLC_FIELD_TOKEN);

        if (GetField_CString(hIn,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("FormatAckMsg txn_seq = [%s]\n",csTxnSeq));
                sprintf(csTxnSeqVal,"txn_id=%s",csTxnSeq);
        }
        else {
DEBUGLOG(("FormatAckMsg txn_seq is missing!!!\n"));
                sprintf(csTxnSeqVal,"txn_id=");
        }

	if (GetField_Char(hIn,"ar_ind",&cStatus)) {
DEBUGLOG(("FormatAckMsg txn_status = [%c]\n",cStatus));
        }
        if (cStatus == PD_ACCEPT) {
                if (GetField_CString(hIn,"success_callback_url",&csPtr)) {
                        strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatAckMsg success_callback_url = [%s]\n",csPtr));
                }

        }
        else {
                if (GetField_CString(hIn,"failure_callback_url",&csPtr)) {
                        strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatAckMsg failure_callback_url = [%s]\n",csPtr));
                }
        }
        strcat((char*)csBuf,MY_OLC_TOKEN);
        strcat((char*)csBuf,csTxnSeqVal);
        strcat((char*)csBuf,MY_OLC_TOKEN);

        sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
        strcat((char*)outMsg,csBuf);

/*process_type*/
        if (GetField_CString(hIn,"process_type",&csPtr)){
DEBUGLOG(("FormatAckMsg:: process_type = [%s]\n",csPtr));
                strcat((char*)outMsg,"process_type");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: process_type is missing!!!\n"));
        }

/*process_code*/
        if (GetField_CString(hIn,"process_code",&csPtr)){
DEBUGLOG(("FormatAckMsg:: process_code = [%s]\n",csPtr));
                strcat((char*)outMsg,"process_code");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: process_type is missing!!!\n"));
        }

/* status */
        if (GetField_CString(hIn,"response_code",&csPtr)){
DEBUGLOG(("FormatAckMsg:: response code  = [%s]\n",csPtr));
                strcat((char*)outMsg,"status");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: response code is missing!!!\n"));
        }

/*txn_seq*/
        if (GetField_CString(hIn,"txn_seq",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_seq = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_id");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: txn_seq is missing!!!\n"));
        }

/*txn_date*/
        if (GetField_CString(hIn,"local_transmission_datetime",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_date = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_date");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: txn_date is missing!!!\n"));
        }

/*net_ccy*/
        if (GetField_CString(hIn,"net_ccy",&csPtr)){
DEBUGLOG(("FormatAckMsg:: net_ccy = [%s]\n",csPtr));
                strcat((char*)outMsg,"paid_ccy");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: net_ccy is missing!!!\n"));
        }

/* net_amt */
        if (GetField_Double(hIn,"net_amt",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: NET AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: AMOUNT = [%s]\n",csTmp));
                strcat((char*)outMsg,"paid_amt");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }

/* service_fee */
        if (GetField_Double(hIn,"service_fee",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: service_fee AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: service_fee = [%s]\n",csTmp));
                strcat((char*)outMsg,"service_fee");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_OLC_TOKEN);

                if (GetField_CString(hIn,"service_fee_ccy",&csPtr)) {
DEBUGLOG(("FormatAckMsg:: service_fee_ccy = [%s]\n",csPtr));
                        strcat((char*)outMsg,"service_fee_ccy");
                        strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                        strcat((char*)outMsg,csPtr);
                        strcat((char*)outMsg,MY_OLC_TOKEN);
                }
                else {
DEBUGLOG(("FormatAckMsg:: service_fee_ccy is missing!!!\n"));
                }
        }

/* txn_amt */
        if (GetField_Double(hIn,"txn_amt",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: txn amt = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: txn amt = [%s]\n",csTmp));
                strcat((char*)outMsg,"txn_amt");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: txn_amt is missing!!!\n"));
        }

/* txn_ccy */
        if (GetField_CString(hIn,"txn_ccy",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_ccy = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_ccy");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: txn_ccy is missing!!!\n"));
        }



/*merchant_ref*/
        if (GetField_CString(hIn,"merchant_ref",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_ref = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_ref");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: merchant_ref is missing!!!\n"));
        }

/*mer_txn_date*/
        if (GetField_CString(hIn,"transmission_datetime",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_txn_date = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_txn_date");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: mer_txn_date is missing!!!\n"));
        }


/*merchant_id*/
        if (GetField_CString(hIn,"merchant_id",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_id = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_id");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: merchant_id is missing!!!\n"));
        }

/*encrypt_type*/
        if (GetField_CString(hIn,"encrypt_type",&csPtr)){
DEBUGLOG(("FormatAckMsg:: enctype = [%s]\n",csPtr));
                strcat((char*)outMsg,"enctype");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: enctype is missing!!!\n"));
        }

/*sign*/
        if (GetField_CString(hIn,"mac",&csPtr)){
DEBUGLOG(("FormatAckMsg:: SIGN = [%s]\n",csPtr));
                strcat((char*)outMsg,"signature");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: sign is missing!!!\n"));
        }

/* remark */
        if (GetField_CString(hIn,"remark",&csPtr)){
DEBUGLOG(("FormatAckMsg:: remark = [%s]\n",csPtr));
                strcat((char*)outMsg,"remark");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: remark is missing!!!\n"));
        }

/* bank_acct_num */
        if (GetField_CString(hIn,"bank_acct_num",&csPtr)){
DEBUGLOG(("FormatAckMsg:: bank_acct_num = [%s]\n",csPtr));
                strcat((char*)outMsg,"bank_acct_num");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: bank_acct_num is missing!!!\n"));
        }

/* deposit_datetime */
        if (GetField_CString(hIn,"deposit_datetime",&csPtr)){
DEBUGLOG(("FormatAckMsg:: deposit_datetime = [%s]\n",csPtr));
                strcat((char*)outMsg,"deposit_datetime");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }

/* echo_msg_1 */
        if (GetField_CString(hIn,"echo_msg_1",&csPtr)){
DEBUGLOG(("FormatAckMsg:: echo_msg_1 = [%s]\n",csPtr));
                strcat((char*)outMsg,"echo_msg_1");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: echo_msg_1 is missing!!!\n"));
        }

/* echo_msg_2 */
        if (GetField_CString(hIn,"echo_msg_2",&csPtr)){
DEBUGLOG(("FormatAckMsg:: echo_msg_2 = [%s]\n",csPtr));
                strcat((char*)outMsg,"echo_msg_2");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: echo_msg_2 is missing!!!\n"));
        }

/* echo_msg_3 */
        if (GetField_CString(hIn,"echo_msg_3",&csPtr)){
DEBUGLOG(("FormatAckMsg:: echo_msg_3 = [%s]\n",csPtr));
                strcat((char*)outMsg,"echo_msg_3");
                strcat((char*)outMsg,MY_OLC_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_OLC_TOKEN);
        }
        else {
DEBUGLOG(("FormatAckMsg:: echo_msg_3 is missing!!!\n"));
        }




	*outLen = strlen((const char*)outMsg);

        FREE_ME(csBuf);
DEBUGLOG(("FormatAckMsg:: outMsg = [%s]\n",outMsg));
DEBUGLOG(("FormatAckMsg() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
