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
#include "NbxMsg.h"
#include "common.h"
#include "utilitys.h"
#include "b64.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include "utilitys.h"
#include "blowfishp.h"
#define	KEY_PREFIX	"HIBRfhyjwehyfyu83u6y"
char	cDebug;

OBJPTR(Msg);

void	NbxMsg(char cdebug)
{
	cDebug = cdebug;
}

static char hexchar[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'
    };
int DeBlockWTBData(hash_t *hOut,const char* inMsg);
char*   AppendParam(const char* csID, const char* csValue)
{

        char    *csBuf;
        csBuf = (char*) malloc (1024 +1);
        if (csValue == NULL)
                sprintf(csBuf, "%s000",csID);
        else
                sprintf(csBuf, "%s%03d%s",csID,(int)strlen(csValue),csValue);
              return csBuf;
}


int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
        int     iRet = PD_OK;
        char*   csPtr = NULL;
        char*   csMerchantKey = NULL;
	char	csKey[256 +1];;
	int	iCnt =0;

        memset(outMsg,0,sizeof(outMsg));


       	if (GetField_CString(hIn,"merchant_key",&csMerchantKey)) {
		
DEBUGLOG(("merchant key = [%d]\n",csMerchantKey));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("FormatEnMsg: merchant key is missing!!!\n"));
	}

/* 001 */
/* messageID */
	strcat((char*)outMsg,AppendParam("001","0100"));
	iCnt++;

/* 002 */
/* session_id */
       	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)outMsg,AppendParam("002",csPtr));
		iCnt++;
DEBUGLOG(("FormatMsg:: txn_seq = [%s]\n",csPtr));
       	}
       	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** txn_seq is missing\n"));
      	}
/* 008 */
/* merchant_id */
       	if (GetField_CString(hIn,"merchant_id",&csPtr)) {
		strcat((char*)outMsg,AppendParam("008",csPtr));
		iCnt++;
/* format key */
		sprintf(csKey,"%sQNE%s%s",KEY_PREFIX,csPtr,csMerchantKey);
DEBUGLOG(("FormatEnMsg:: KEY = [%s]\n",csKey));
		
DEBUGLOG(("FormatMsg:: merchant_id = [%s]\n",csPtr));
       	}
       	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** merchant_id is missing\n"));
      	}

/* 003 */
/* txn_seq */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)outMsg,AppendParam("003",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg:: txn_seq = [%s]\n",csPtr));
	}
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** txn_seq is missing\n"));
	}


/* 004 */
/* merchant_ref */
	if (GetField_CString(hIn,"merchant_ref",&csPtr)) {
		strcat((char*)outMsg,AppendParam("004",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg:: merchant_ref = [%s]\n",csPtr));
	}
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** merchant_ref is missing\n"));
	}

/* 006 */
/* server_ip */
	if (GetField_CString(hIn,"server_ip",&csPtr)) {
		strcat((char*)outMsg,AppendParam("006",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg: server_ip = [%s]\n",csPtr));
	}
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** server_ip is missing\n"));
	}

/* 007 */
/* txn_datetime */
	if (GetField_CString(hIn,"transmission_datetime",&csPtr)) {
		strcat((char*)outMsg,AppendParam("007",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg: transmission_datetime = [%s]\n",csPtr));
	}
/* 009 */
/* language */
         if (GetField_CString(hIn,"language",&csPtr)) {
		char* csLang;
		csLang = (char*) malloc (strlen(csPtr) + 1 );
		L2U(csPtr,strlen(csPtr),csLang);
		strcat((char*)outMsg,AppendParam("009",csLang));
		iCnt++;
DEBUGLOG(("FormatEnMsg:: language = [%s]\n",csLang));
        }
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** language is missing\n"));
	}
/* 010 */
/* currency */
	if (GetField_CString(hIn,"txn_ccy",&csPtr)) {
DEBUGLOG(("FormatEnMsg:: currency = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("010",csPtr));
		iCnt++;
	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** currency is missing\n"));
	}

/* 011 */
/* NULL */
	strcat((char*)outMsg,AppendParam("011",NULL));
	iCnt++;

/* 012 */
/* NULL */
	strcat((char*)outMsg,AppendParam("012",NULL));
	iCnt++;

/* 014 */
/* success_url */
	if (GetField_CString(hIn,"success_url",&csPtr)) {
DEBUGLOG(("FormatEnMsg: success_url = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("014",csPtr));
		iCnt++;
	}
	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** success_url is missing\n"));
	}

/* 015 */
/* failure_url */
	if (GetField_CString(hIn,"failure_url",&csPtr)) {
DEBUGLOG(("FormatEnMsg: failure_url = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("015",csPtr));
		iCnt++;
	}
	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** failure_url is missing\n"));
	}

/* 016 */
	if (GetField_CString(hIn,"txn_msg",&csPtr)) {
DEBUGLOG(("FormatEnMsg: txn_msg = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("016",csPtr));
		iCnt++;
	}
	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** txn_msg is missing\n"));
	}
/* 026 */
/* paymentmethod */
	strcat((char*)outMsg,AppendParam("026","02"));
	iCnt++;

/* 028 */
/* NULL */
	strcat((char*)outMsg,AppendParam("028",NULL));
	iCnt++;

/* 029 */
/* NULL */
	strcat((char*)outMsg,AppendParam("029",NULL));
	iCnt++;

/* 030 */
/* NULL */
	strcat((char*)outMsg,AppendParam("030",NULL));
	iCnt++;
/* 031 */
/* NULL */
	strcat((char*)outMsg,AppendParam("031",NULL));
	iCnt++;

/* 032 */
/* NULL */
	strcat((char*)outMsg,AppendParam("032",NULL));
	iCnt++;

/* 022 */
/* txn_amt */
        if (GetField_CString(hIn,"txn_amt",&csPtr)) {
DEBUGLOG(("FormatEnMsg:: totCash  = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("022",csPtr));
		iCnt++;
        }
        else {
		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** totCash is missing\n"));
	}

/* 023 */
/* tot_token */

	if (GetField_CString(hIn,"tot_token",&csPtr)) {
DEBUGLOG(("FormatEnMsg: tot_token = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("023",csPtr));
		iCnt++;
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** tot_token is missing\n"));
	}


/* 017 */
/* NULL */
	strcat((char*)outMsg,AppendParam("017","0"));
	iCnt++;
	
	unsigned char* csBuf;
	unsigned char* csBuf2;
	csBuf = (unsigned char*) malloc (strlen((const char*)outMsg) * 2+ 1);
	csBuf2 = (unsigned char*) malloc (strlen((const char*)outMsg) * 2+ 1);
	sprintf((char*)csBuf,"%03d%s",iCnt,outMsg);
DEBUGLOG(("FormatEnMsg: msg   = [%d][%s]\n",strlen((char*)csBuf),csBuf));

	strcpy((char*)csBuf2,(char*)attachMsgLenAndCheckSum(csBuf));
DEBUGLOG(("FormatEnMsg: Final = [%d][%s]\n",strlen((char*)csBuf2),csBuf2));

	iRet =  Encrypt((unsigned char*)csKey,strlen(csKey),csBuf2, strlen((char*)csBuf2),outMsg);
	*outLen = strlen((char *)outMsg);
DEBUGLOG(("FormatEnMsg:: outmsg = [%d][%s]\n",*outLen,outMsg));

	FREE_ME(csBuf);
	FREE_ME(csBuf2);

DEBUGLOG(("FormatEnMsg:: iRet = [%d]\n",iRet));
        return  iRet;
}



int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
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
	//if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
//DEBUGLOG(("initReplyFromRequest: txn_ccy = [%s]\n",csPtr));
//		PutField_CString(hResponse,"txn_ccy",csPtr);
//	}
	if (GetField_CString(hRequest,"pay_method",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: pay_method = [%s]\n",csPtr));
		PutField_CString(hResponse,"pay_method",csPtr);
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
	if (GetField_CString(hRequest,"txn_amt",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: txn_amt = [%s]\n",csPtr));
		PutField_CString(hResponse,"txn_amt",csPtr);
	}



DEBUGLOG(("initReplyFromRequest() Exit\n"));
	return iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;

	char	*csMerchantId;
	char	*csTag;
	char	*csPtr;
	hash_t	*hRec;
	

	
	hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

	csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

 	if (Str2Cls(hRec,(const char *)inMsg,MY_NBX_TOKEN, MY_NBX_FIELD_TOKEN) == PD_OK) {

/* merchant_id */
		if (GetField_CString(hRec,"merchantid",&csMerchantId)) {
			strcpy(csTag,"merchant_id");
			PutField_CString(hOut,csTag,csMerchantId);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csMerchantId));
		}
		else {
DEBUGLOG(("BreakDownMsg: merchantid is missing!!!\n"));
		}
/* process type */
		if (GetField_CString(hRec,"process_type",&csPtr)) {
			strcpy(csTag,"process_type");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* process code */
		if (GetField_CString(hRec,"process_code",&csPtr)) {
			strcpy(csTag,"process_code");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* message */
		if (GetField_CString(hRec,"message",&csPtr)) {
			strcpy(csTag,"DATA");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));

			char	KEY[] = "1234567890235834";
			char    csMsg  [ 1024 * 2 +1 ];
                	char    csMsg2 [ 1024 * 2 +1 ];
			char	csKey[128];
                	char    csChkSum[2 + 1];
			sprintf(csKey,"%sQNE%s%s",KEY_PREFIX,csMerchantId,KEY);
			iRet = Decrypt(csKey,strlen(csKey),csPtr,strlen(csPtr),csMsg);
			if (iRet == PD_OK) {
DEBUGLOG(("BreakDownMsg: decrypted message = [%s]\n",csMsg));
                		strcpy(csChkSum,(char*)genChecksum((unsigned char*)csMsg,strlen(csMsg) -2));
DEBUGLOG(("BreakDownAckMsg: clear text = [%d][%s]\n",strlen(csMsg),csMsg));
DEBUGLOG(("BreakDownAckMsg: checksum = [%s]\n",csChkSum));

                		memcpy(csMsg2,&csMsg[4],strlen(csMsg) - 6);
                		csMsg2[strlen(csMsg) - 6] = '\0';
DEBUGLOG(("BreakDownAckMsg: real text = [%d][%s]\n",strlen(csMsg2),csMsg2));
                		DeBlockParam(hOut,(const unsigned char*)csMsg2,strlen(csMsg2));
			}
			else {
ERRLOG("NbxMsg:BreakDown decrypt [%s] message error\n",csMerchantId);
			}
		}
		else {
DEBUGLOG(("BreakDownMsg: message is missing!!!\n"));
		}
	
/* ip_addr */
		if (GetField_CString(hRec,"ip_addr",&csPtr)) {
                        strcpy(csTag,"ip_addr");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }
/* uagent */
		if (GetField_CString(hRec,"uagent",&csPtr)) {
                        strcpy(csTag,"uagent");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }

/* service_code */
		if (GetField_CString(hRec,"service_code",&csPtr)) {
                        strcpy(csTag,"service_code");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }
	
	}

	FREE_ME(csTag);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg = [%d]\n",iRet));;
	return iRet;
}




int DeBlockWebBounceBackData(hash_t *hOut,const char* inMsg, const int inLen)
{
	int 	iRet = PD_OK;
	char*	csBuf;

//	unsigned char buf[PD_MAX_BUFFER + 1]={0};

	csBuf = (char*) malloc (1024 +1);
	memcpy(csBuf,inMsg,inLen);
	csBuf[inLen] = '\0';

DEBUGLOG(("DeBlockBounceBackDATA () [%s]\n",csBuf));

DEBUGLOG(("DeBlockBounceBackData Exit = [%d]\n",iRet));
	return iRet;
}




int Encrypt(unsigned char* csKey,int iKeyLen,unsigned char* inBuf, int iBuffLen,unsigned char* outBuf) {

        blowfishp_context_t *ctx = (blowfishp_context_t *)malloc(sizeof(blowfishp_context_t));
        if(!ctx) {
ERRLOG("NbxMsg:Encrypt Could not allocate enough memory!\n");
DEBUGLOG(("Encrypt() Could not allocate enough memory!\n"));
                return INT_ERR;
        }
        if(blowfishp_initiate(ctx, (unsigned char *)csKey, iKeyLen) == 0) {
DEBUGLOG(("Encrypt() Keys initiated\n"));
                int iLen = iBuffLen;
                iLen = ((iLen + 7 ) /8) * 2;

                char*   csTmp;
                csTmp = (char*) malloc (iLen * 4 +1);

                unsigned int hi = 1, lo = 2;
                int i = 0;
                int j = 0;
                int k = 0;

                for (; i < iLen; i +=2 ) {
                        unsigned int d = 0;
                        if (j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 0;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 8;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 16;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 24;
                        hi = d;

                        if(j < iBuffLen)
                                d = (inBuf[j++] & 0xff) << 0;
                        else
                                d = 0;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 24;
                        lo = d;

                        blowfishp_encryptblock(ctx, &hi, &lo);

                        d = hi;
                        csTmp[k++] = (unsigned char)(d >> 0 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 8 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 16 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 24 & 0xff);

                        d = lo;
                        csTmp[k++] = (unsigned char)(d >> 0 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 8 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 16 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 24 & 0xff);
                }

		memset(outBuf,0,sizeof(outBuf));
                uxencode((char*)outBuf, (unsigned char*)csTmp, k);
		outBuf[k*2] = '\0';
                free(csTmp);

        }else {
ERRLOG("NbxMsg:Encrypt() Error initiating keys\n");
DEBUGLOG(("Encrypt() Error initiating keys\n"));
	}

DEBUGLOG(("Encrypt() Done!\n"));
        free(ctx);
        return 0;
}

int Decrypt(const char* csKey,int iKeyLen,const char* inBuf, int iBuffLen,char* outBuf) {
        blowfishp_context_t *ctx = (blowfishp_context_t *)malloc(sizeof(blowfishp_context_t));
        if(!ctx) {
ERRLOG("NbxMsg:Decrypt Could not allocate enough memory!\n");
DEBUGLOG(("Decrypt Could not allocate enough memory!\n"));
                return PD_ERR;
        }
        if(blowfishp_initiate(ctx, (unsigned char *)csKey, iKeyLen) == 0) {
DEBUGLOG(("Decrypt:Keys initiated\n"));
                int iLen = iBuffLen;
                iLen = ((iLen + 7 ) /8) * 2;

                char*   csTmp;
                csTmp = (char*) malloc (iLen * 4 +1);


                uxdecode(csTmp, (unsigned char*)inBuf, iBuffLen);

                unsigned int hi = 1, lo = 2;
                int i = 0;
                int j = 0;
                int k = 0;

                for (; i < iLen; i +=2 ) {
                        int d = 0;
                        if (j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 0;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 24;
                        hi = d;
                        if(j < iBuffLen)
                                d = ((unsigned int)csTmp[j++] & 0xff) << 0;
                        else
                                d = 0;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 24;
                        lo = d;

                        blowfishp_decryptblock(ctx, &hi, &lo);

                        d = hi;
                        outBuf[k++] = ((unsigned int)d >> 0 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 8 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 16 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 24 & 0xff);
                        d = lo;
                        outBuf[k++] = ((unsigned int)d >> 0 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 8 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 16 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 24 & 0xff);
                }

                free(csTmp);

        }else  {
ERRLOG("NbxMsg:Decrypt Error initiating keys\n");
DEBUGLOG(("Decrypt Error initiating keys\n"));
	}

        free(ctx);
DEBUGLOG(("Decrypt: Done!\n"));
        return PD_OK; 
}


unsigned char* calcMsgCheckSum(unsigned char* MsgLen, unsigned char* MsgBody, int seed)
{
        int i;
        for(i = 0; i < strlen((const char*) MsgLen);)
            seed ^= MsgLen[i++];

        for(i = 0; i < strlen((const char*)MsgBody);)
            seed ^= MsgBody[i++];

        seed &= 0xff;
        unsigned char* csResult;
        csResult = (unsigned char*) malloc (2 +1);
        csResult[0] = hexchar[(unsigned int)(seed & 0xf0) >> 4];
        csResult[1] = hexchar[seed & 0xf];
	csResult[2] = '\0';
        return csResult;
}


unsigned char* attachMsgLenAndCheckSum(const unsigned char* inBuf)
{
        unsigned char msgLen[] = "0000";
        unsigned char msgCheckSum[] = "00";
        sprintf((char*)msgLen,"%04d",(int)strlen((const char*)inBuf));
        strcpy((char*)msgCheckSum,(const char*)calcMsgCheckSum(msgLen, (unsigned char*) inBuf, 0));

        unsigned char* csTmp;
        csTmp = (unsigned char*) malloc (1024 +1 );
        sprintf((char*)csTmp,"%s%s%s",msgLen,inBuf,msgCheckSum);
        return csTmp;
}
unsigned char* genChecksum(unsigned char* inBuf, int len)
{
        int i = 0;
        int j = 0;
        unsigned char*  csResult;

        csResult = (unsigned char*) malloc ( 2 +1);
        memset(csResult,0,sizeof(csResult));

        for(j = 0; j < len;)
            i ^= inBuf[j++];

        i &= 0xff;

        csResult[0] = hexchar[(unsigned int)(i & 0xf0) >> 4];
        csResult[1] = hexchar[i & 0xf];

        return csResult;
}

void DeBlockParam(hash_t *hOut,const unsigned char* inBuf, int iLen)
{
DEBUGLOG(("DeBlockParam()\n"));
        char    csCnt[3 + 1];
        int     iCnt = 0,i = 0;
        unsigned char* csBuf;
        csBuf = (unsigned char*) malloc (iLen + 1);
        memcpy(csCnt,&inBuf[0],3);
        csCnt[3] = '\0';
        iCnt = atoi(csCnt);
DEBUGLOG(("DeBlockParam: total param = [%d]\n",iCnt));
        memcpy(csBuf,&inBuf[3],iLen -3 );
        printf("buf = [%s]\n",csBuf);
        unsigned char* p;
        p = csBuf;
        for (i = 0; i< iCnt; i++)
                p = ParseIt(hOut,p);


        free(csBuf);
DEBUGLOG(("DeBlockParam() exit\n"));
}

unsigned char* ParseIt(hash_t *hOut,unsigned char* inBuf)
{
        char    csF[3 +1];
        char    csL[3 +1];
        char    *csV;
        int     iLen = 0;
        int     iTotal = 0;
        memcpy(csF,&inBuf[0],3);
        csF[3] = '\0';

        memcpy(csL,&inBuf[3],3);
        csL[3] = '\0';
        iLen = atoi(csL);
        csV = (char*) malloc (iLen +1);
        memcpy(csV,&inBuf[3+3],iLen);
        csV[iLen] = '\0';

DEBUGLOG(("[%s] = [%s]\n",csF,csV));
	if (!strcmp(csF,"004")) {
		PutField_CString(hOut,"merchant_ref",csV);
DEBUGLOG(("ParseIt merchant_ref = [%s]\n",csV));
	}
	if (!strcmp(csF,"009")) { 
		if (!strcmp(csV,"CHS"))
			strcpy(csV,"GB");
		else if (!strcmp(csV,"CHT"))
			strcpy(csV,"ZH");
		else if (!strcmp(csV,"ENG"))
			strcpy(csV,"EN");
		PutField_CString(hOut,"language",csV);
DEBUGLOG(("ParseIt language = [%s]\n",csV));
	}
	if (!strcmp(csF,"010")) {
		PutField_CString(hOut,"txn_ccy",csV);
DEBUGLOG(("ParseIt txn_ccy = [%s]\n",csV));
	}
	if (!strcmp(csF,"014")) {
		PutField_CString(hOut,"success_url",csV);
DEBUGLOG(("ParseIt success_url = [%s]\n",csV));
	}
	if (!strcmp(csF,"015")) {
		PutField_CString(hOut,"failure_url",csV);
DEBUGLOG(("ParseIt language = [%s]\n",csV));
	}
	if (!strcmp(csF,"016")) {
		PutField_CString(hOut,"remark",csV);
DEBUGLOG(("ParseIt remark = [%s]\n",csV));
	}
	if (!strcmp(csF,"022")) {
		PutField_CString(hOut,"txn_amt",csV);
DEBUGLOG(("ParseIt txn_amt = [%s]\n",csV));
	}
	if (!strcmp(csF,"026")) {
		PutField_CString(hOut,"pay_method",csV);
DEBUGLOG(("ParseIt pay_method = [%s]\n",csV));
	}
        iTotal = 3 + 3 + iLen;
        inBuf += iTotal;
        return inBuf;
}

int	GetResult(const unsigned char* inBuf, int iLen,unsigned char* outBuf,int* oLen)
{
	char	csResult[] = "SUCCESS";
	char	*p;
	int	iRet = PD_OK;
	char	*csBuf;
DEBUGLOG(("GetResult [%d][%s]\n",iLen,inBuf));

	csBuf = (char*) malloc (iLen + 1);
	strcpy(csBuf,(const char*)inBuf);

	p = strtok(csBuf,"|");
	if (p != NULL)
        {
		if (!memcmp(p,csResult,strlen(csResult))) {
			p = strtok(NULL,"|");
			strcpy((char*)outBuf,p);
			*oLen = strlen((char*)outBuf);
DEBUGLOG(("p = [%d][%s]\n",*oLen,outBuf));
		}
		else {
			iRet = INT_ERR;
		}
	}

	FREE_ME(csBuf);
	return	iRet;
}
