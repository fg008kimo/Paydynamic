/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   20110221                LokMan Chow
bug fix						   20110222	 	   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "GpyMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"

char	cDebug;

void	GpyMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csTmp = NULL;
	char*   csPtr = NULL;
	char*   csBuf;
	char*   csMethod = NULL;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"?");


/* merchant_id */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"LP_MERID");
			strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_GOPAY_TOKEN);
DEBUGLOG(("FormatMsg:: LP_MERID = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_merchant_id is missing\n"));
		}


/* enctype */
        	if (GetField_CString(hIn,"encrypt_type",&csTmp)) {
			strcat((char*)outMsg,"LP_ENCTYPE");
                        strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,MY_GOPAY_TOKEN);
DEBUGLOG(("FormatMsg:: LP_ENCTYPE = [%s]\n",csTmp));
		}
		else{
			strcat((char*)outMsg,"LP_ENCTYPE");
			strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
			strcat((char*)outMsg,"01");
			strcat((char*)outMsg,MY_GOPAY_TOKEN);
DEBUGLOG(("FormatMsg:: default LP_ENCTYPE = [01]\n"));
		}


/* data */
		if (GetField_CString(hIn,"plainttext_data",&csTmp)) {
DEBUGLOG(("FormatMsg:: plainttext_data = [%s]\n",csTmp));
			csBuf[0]='\0';
			base64_encode((unsigned char *)csTmp,strlen((const char*)csTmp),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: DATA = [%s]\n",csBuf));
                        strcat((char*)outMsg,"LP_DATA");
                        strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
                        strcat((char*)outMsg,csBuf);
                        strcat((char*)outMsg,MY_GOPAY_TOKEN);
                }


/* sign */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"LP_SIGN");
			strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_GOPAY_TOKEN);
DEBUGLOG(("FormatMsg:: SIGN = [%s]\n",csTmp));
		}

/* bank_id */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"LP_BANKID");
			strcat((char*)outMsg,MY_GOPAY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
DEBUGLOG(("FormatMsg:: LP_BANKID = [%s]\n",csTmp));
		}


// url_method
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
		}


DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));

		base64_encode((unsigned char *)outMsg,strlen((const char*)outMsg),csBuf,PD_MAX_BUFFER);
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
		strcat((char*)outMsg,MY_GOPAY_TOKEN);
		strcat((char*)outMsg,"url_method");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csMethod);
		strcat((char*)outMsg,MY_GOPAY_TOKEN);
                strcat((char*)outMsg,"ret_status=0");

DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));


		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}


	FREE_ME(csBuf);
	return 	iRet;
}



int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
        hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(const char *)inMsg,MY_GOPAY_TOKEN, MY_GOPAY_FIELD_TOKEN) == PD_OK) {

/*merchant id */
		if (GetField_CString(hRec,"LP_MerId",&csPtr)) {
                	PutField_CString(hOut,"merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg merchant_id = [%s]\n",csPtr));
        	}
		else{
DEBUGLOG(("BreakDownMsg merchant_id not found\n"));
		}

/*encrypt_type */
		if (GetField_CString(hRec,"LP_EncType",&csPtr)) {
                	PutField_CString(hOut,"encrypt_type",csPtr);
DEBUGLOG(("BreakDownMsg encrypt_type = [%s]\n",csPtr));
        	}
		else{
DEBUGLOG(("BreakDownMsg encrypt_type not found\n"));
		}

/* data */
		if (GetField_CString(hRec,"LP_Data",&csPtr)) {
                	iRet = DEBlockLKpayData(hOut,(const unsigned char *)csPtr,strlen(csPtr));
        	}
		else{
DEBUGLOG(("BreakDownMsg data not found\n"));
		}

/* SIGN */
		if (GetField_CString(hRec,"LP_Sign",&csPtr)) {
                	PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg sign = [%s]\n",csPtr));
        	}
		else{
DEBUGLOG(("BreakDownMsg sign not found\n"));
		}
	
	}
	else{
DEBUGLOG(("BreakDownMsg() Error\n"));
                iRet = PD_ERR;
	}

	hash_destroy(hRec);
        FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return	iRet;
}


int BuildData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr,*csDATA;
        char*   csTmp[PD_MAX_BUFFER + 1];
	char*	csBuf;
        double  dTmp;
        csDATA = (char*) malloc (1024 * 2 +1);
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 ); 

DEBUGLOG(("BuildData()\n"));

        memset(csDATA,0,sizeof(csDATA));
        
// Merchant Ref
        if (GetField_CString(hIn,"txn_seq",&csPtr)) {
DEBUGLOG(("BuildData:: LP_MERORDERID = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

// transmission_datetime
        if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildData:: LP_MERDATE = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }


// psp_txn_amt
        if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("BuildData:: AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildData:: LP_AMOUNT = [%s]\n",csTmp));
                strcat((char*)csDATA,(char*)csTmp);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

// currency_code
        if (GetField_CString(hIn,"psp_txn_ccy",&csPtr)) {
DEBUGLOG(("BuildData:: LP_CURTYPE = [%s]\n",csPtr));
		if(!strcmp(csPtr,PD_CCY_ISO_CNY)) {
                	strcat((char*)csDATA,PD_CCY_RMB_HPAY);
                	strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
		}
		else {
ERRLOG("GpyMsg:BuildData unsupport CCY ISO to GOPAY\n");
		}
        }

// tradeway
        //hardcode
        strcat((char*)csDATA,"1");
        strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
DEBUGLOG(("BuildData:: LP_TRADWAY = [%s]\n","1"));

/* recvenctype */
        if (GetField_CString(hIn,"recvenctype",&csPtr)) {
DEBUGLOG(("BuildData:: LP_RECVENCTYPE = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

/* success_callback_url */
        if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("BuildData:: LP_RETURNURL = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

/* failure_url */
        if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("BuildData:: LP_FAILEDURL = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

/* success_url */
        if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("BuildData:: LP_SUCCESSURL = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }

// language
//        if (GetField_CString(hIn,"language",&csPtr)) {
DEBUGLOG(("BuildData:: LP_LANG = [%s]\n","GB"));
                strcat((char*)csDATA,"GB");
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
 //       }

/* show_paypage */
        if (GetField_CString(hIn,"show_paypage",&csPtr)) {
DEBUGLOG(("BuildData:: show_paypage = [%s]\n",csPtr));
		csBuf[0]='\0';
                base64_encode((unsigned char *)csPtr,strlen((const char*)csPtr),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: LP_SHOWNAMOUNT = [%s]\n",csBuf));
                strcat((char*)csDATA,csBuf);
                strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
        }
	else{
		strcat((char*)csDATA,MY_GOPAY_DATA_TOKEN);
	}

/* remark */
        if (GetField_CString(hIn,"remark",&csPtr)) {
DEBUGLOG(("BuildData:: remark = [%s]\n",csPtr));
                csBuf[0]='\0';
                base64_encode((unsigned char *)csPtr,strlen((const char*)csPtr),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("BuildData:: LP_REMARK = [%s]\n",csBuf));
                strcat((char*)csDATA,csPtr);
        }


        PutField_CString(hIn,"plainttext_data",csDATA);

DEBUGLOG(("BuildData:: DATA = [%s]\n",csDATA));

        FREE_ME(csDATA);
DEBUGLOG(("BuildData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}

int DEBlockLKpayData(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
        int     iRet = PD_OK;
        char    *csTmp=NULL;
        char    *csBuf;
        char    *csDATA;
        char    *p;
        int     iLen;

        csBuf = (char*) malloc (PD_MAX_BUFFER +1);
        csDATA = (char*) malloc (PD_MAX_BUFFER +1);

        memcpy(csBuf,inMsg,inLen);
        csBuf[inLen] = '\0';
DEBUGLOG(("\n\nDEBlockData data=[%s]\n\n",csBuf));
        iLen = base64_decode((char *)csBuf,(unsigned char*)csDATA,PD_MAX_BUFFER);
        csDATA[iLen] = '\0';
        if (iLen > 0 ) {
DEBUGLOG(("\n\nDEBlockData data=[%s]\n\n",csDATA));
DEBUGLOG(("iRet = [%d] DATA = [%s]\n",iRet,csDATA));
                PutField_CString(hOut,"plainttext_data",csDATA);

/* tid */
                p = strtok(csDATA,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"tid",p);
DEBUGLOG(("DEBlockData tid = [%s]\n",p));
                }

/* txn_id */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_seq",p);
DEBUGLOG(("DEBlockData txn_seq = [%s]\n",p));
                }

/* transmission_datetime */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_date",p);
DEBUGLOG(("DEBlockData txn_date[transmission_datetime] = [%s]\n",p));
                }

/* bank_bail_no */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"bank_bail_no",p);
DEBUGLOG(("DEBlockData bank_bail_no = [%s]\n",p));
                }

/* fundin_date */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"fundin_date",p);
DEBUGLOG(("DEBlockData fundin_date = [%s]\n",p));
                }

/* net_amt */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_amt",p);
DEBUGLOG(("DEBlockData txn_amt = [%s]\n",p));
                }


/* currency_code */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        if(strncmp(p,PD_CCY_RMB_HPAY,PD_CCY_ID_LEN)==0){
                                PutField_CString(hOut,"txn_ccy",PD_CCY_ISO_CNY);
                        }
                        else{
                                iRet = PD_ERR;
DEBUGLOG(("DEBlockData invalid currency code [%s]\n",p));
                        }
DEBUGLOG(("DEBlockData currency_code = [%s]\n",p));
                }

/* language */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"language",p);
DEBUGLOG(("DEBlockData language = [%s]\n",p));
                }

/* issucc */
		p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
		if (p) {
			PutField_CString(hOut,"status",p);
DEBUGLOG(("DEBlockData status = [%s]\n",p));
		}

/* remark */
                p = strtok(NULL,MY_GOPAY_DATA_TOKEN);
                if (p) {
                        csTmp = (char*) malloc (PD_MAX_BUFFER +1);
			iLen = base64_decode(p,(unsigned char *)csTmp,PD_MAX_BUFFER);
			if(iLen>0){
                                csTmp[iLen] = '\0';
                        	PutField_CString(hOut,"remark",csTmp);
DEBUGLOG(("DEBlockData remark = [%s]\n",csTmp));
			}
			else {
DEBUGLOG(("DEBlockData remark = [%s]\n",p));
				FREE_ME(csTmp);
			}
                }
                else {
                        PutField_CString(hOut,"remark","");
                }
        }


        FREE_ME(csBuf);
        FREE_ME(csDATA);
DEBUGLOG(("DBlockData Exit\n"));
        return  iRet;
}




int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}


