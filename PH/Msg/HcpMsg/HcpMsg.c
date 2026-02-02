/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   20111021                Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "HcpMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"

char	cDebug;

void	HcpMsg(char cdebug)
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
			strcat((char*)outMsg,"MerID");
			strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HCP_TOKEN);
DEBUGLOG(("FormatMsg:: MERID = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_merchant_id is missing\n"));
		}
/* api version */
		strcat((char*)outMsg,"APIVersion");
		strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
		strcat((char*)outMsg,"01");
		strcat((char*)outMsg,MY_HCP_TOKEN);


/* enctype */
/*
        	if (GetField_CString(hIn,"encrypt_type",&csTmp)) {
			strcat((char*)outMsg,"ENCTYPE");
                        strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,MY_HCP_TOKEN);
DEBUGLOG(("FormatMsg:: ENCTYPE = [%s]\n",csTmp));
		}
		else{
			strcat((char*)outMsg,"ENCTYPE");
			strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
			strcat((char*)outMsg,"01");
			strcat((char*)outMsg,MY_HCP_TOKEN);
DEBUGLOG(("FormatMsg:: default ENCTYPE = [01]\n"));
		}
*/


/* data */
		if (GetField_CString(hIn,"plainttext_data",&csTmp)) {
DEBUGLOG(("FormatMsg:: plainttext_data = [%s]\n",csTmp));
			csBuf[0]='\0';
			base64_encode((unsigned char *)csTmp,strlen(csTmp),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: DATA = [%s]\n",csBuf));
                        strcat((char*)outMsg,"MerReqData");
                        strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
                        strcat((char*)outMsg,csBuf);
                        strcat((char*)outMsg,MY_HCP_TOKEN);
                }


/* sign */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"MerSign");
			strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_HCP_TOKEN);
DEBUGLOG(("FormatMsg:: SIGN = [%s]\n",csTmp));
		}

/* bank_id */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"BankID");
			strcat((char*)outMsg,MY_HCP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
DEBUGLOG(("FormatMsg:: BANKID = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: BANKID is missing\n"));
		}


/* url_method */
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
		}

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));

		base64_encode((unsigned char *)outMsg,strlen((const char*)outMsg),csBuf,PD_MAX_BUFFER);
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
		strcat((char*)outMsg,MY_HCP_TOKEN);
		strcat((char*)outMsg,"url_method");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csMethod);
		strcat((char*)outMsg,MY_HCP_TOKEN);
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

	if (Str2Cls(hRec,(const char *)inMsg,MY_HCP_TOKEN, MY_HCP_FIELD_TOKEN) == PD_OK) {

/*merchant id */
		if (GetField_CString(hRec,"MerID",&csPtr)) {
               		PutField_CString(hOut,"merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg merchant_id = [%s]\n",csPtr));
        	}
		else {
			if (GetField_CString(hRec,"MERID",&csPtr)) {
                		PutField_CString(hOut,"merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg merchant_id = [%s]\n",csPtr));
        		}
			else{
DEBUGLOG(("BreakDownMsg merchant_id not found\n"));
			}

		}

/* APIVersion */
		PutField_CString(hOut,"APIVersion","01");

/*encrypt_type */
		if (GetField_CString(hRec,"EncType",&csPtr)) {
                	PutField_CString(hOut,"encrypt_type",csPtr);
DEBUGLOG(("BreakDownMsg encrypt_type = [%s]\n",csPtr));
        	}
		else {
			if (GetField_CString(hRec,"ENCTYPE",&csPtr)) {
                		PutField_CString(hOut,"encrypt_type",csPtr);
DEBUGLOG(("BreakDownMsg encrypt_type = [%s]\n",csPtr));
        		}
			else{
DEBUGLOG(("BreakDownMsg encrypt_type not found\n"));
			}
		}

/* data */
		if (GetField_CString(hRec,"MerReqData",&csPtr)) {
                	iRet = DEBlockHcpData(hOut,(const unsigned char *)csPtr,strlen(csPtr));
        	}
		else {
			if (GetField_CString(hRec,"MERREQDATA",&csPtr)) {
                		iRet = DEBlockHcpData(hOut,(const unsigned char *)csPtr,strlen(csPtr));
        		}
			else{
DEBUGLOG(("BreakDownMsg data not found\n"));
			}
		}

/* SIGN */
		if (GetField_CString(hRec,"MerSign",&csPtr)) {
                	PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg sign = [%s]\n",csPtr));
        	}
		else {	
			if (GetField_CString(hRec,"Sign",&csPtr)) {
                		PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg sign = [%s]\n",csPtr));
        		}
			else{
DEBUGLOG(("BreakDownMsg Sign not found\n"));
			}
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
DEBUGLOG(("BuildData:: TransID = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }
	else {
DEBUGLOG(("BuildData:: txn_seq is missing!!!\n"));
	}

// transmission_datetime
        if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildData:: TransDate = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }
	else {
DEBUGLOG(("BuildData:: local_tm_date is missing!!!\n"));
	}


// psp_txn_amt
        if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("BuildData:: TransMoney = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildData:: TransMoney = [%s]\n",csTmp));
                strcat((char*)csDATA,(char*)csTmp);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }
	else {
DEBUGLOG(("BuildData:: psp_txn_amt is missing\n"));
	}

// currency_code
        if (GetField_CString(hIn,"psp_txn_ccy",&csPtr)) {
DEBUGLOG(("BuildData:: TransCur = [%s]\n",csPtr));
		if(!strcmp(csPtr,PD_CCY_ISO_CNY)) {
                	strcat((char*)csDATA,PD_CCY_RMB_HCP);
                	strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
		}
		else {
ERRLOG("HcpMsg:BuildData unsupport CCY ISO to HIPAY\n");
		}
        }
	else {
DEBUGLOG(("BuildData:: psp_txn_ccy is missing!!!\n"));
	}

// tradeway
        //hardcode
        strcat((char*)csDATA,"01");
        strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
DEBUGLOG(("BuildData:: PayID = [%s]\n","01"));

/* recvenctype */
        if (GetField_CString(hIn,"recvenctype",&csPtr)) {
DEBUGLOG(("BuildData:: RecvencSign = [%s]\n",csPtr));
        	strcat((char*)csDATA,csPtr);
        	strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
	}

/* success_callback_url */
        if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("BuildData:: Return_url = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }

/* failure_url */
        if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("BuildData:: Merchant_url_F = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }

/* success_url */
        if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("BuildData:: Merchant_url_S = [%s]\n",csPtr));
                strcat((char*)csDATA,csPtr);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }

// language
//        if (GetField_CString(hIn,"language",&csPtr)) {
DEBUGLOG(("BuildData:: Lang = [%s]\n","GB"));
                strcat((char*)csDATA,"GB");
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
 //       }

/* show_paypage */
        if (GetField_CString(hIn,"show_paypage",&csPtr)) {
DEBUGLOG(("BuildData:: show_paypage = [%s]\n",csPtr));
		csBuf[0]='\0';
                base64_encode((unsigned char *)csPtr,strlen(csPtr),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: SHOWNAMOUNT = [%s]\n",csBuf));
                strcat((char*)csDATA,csBuf);
                strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
        }
	else{
		strcat((char*)csDATA,MY_HCP_DATA_TOKEN);
	}

/* remark */
        if (GetField_CString(hIn,"remark",&csPtr)) {
DEBUGLOG(("BuildData:: remark = [%s]\n",csPtr));
                csBuf[0]='\0';
                base64_encode((unsigned char *)csPtr,strlen(csPtr),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("BuildData:: REMARK = [%s]\n",csBuf));
                strcat((char*)csDATA,csPtr);
        }


        PutField_CString(hIn,"plainttext_data",csDATA);

DEBUGLOG(("BuildData:: DATA = [%s]\n",csDATA));

        FREE_ME(csDATA);
DEBUGLOG(("BuildData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}

int DEBlockHcpData(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
        int     iRet = PD_OK;
        char    *csBuf;
        char    *csDATA;
        char    *p;
        int     iLen;
	int	iWithOrderId = PD_TRUE;

        csBuf = (char*) malloc (PD_MAX_BUFFER +1);
        csDATA = (char*) malloc (PD_MAX_BUFFER +1);

        memcpy(csBuf,inMsg,inLen);
        csBuf[inLen] = '\0';
DEBUGLOG(("\n\nDEBlockData data=[%s]\n\n",csBuf));
        iLen = base64_decode((char *)csBuf,(unsigned char *)csDATA,PD_MAX_BUFFER);
        csDATA[iLen] = '\0';
        if (iLen > 0 ) {
DEBUGLOG(("\n\nDEBlockData data=[%s]\n\n",csDATA));
DEBUGLOG(("iRet = [%d] DATA = [%s]\n",iRet,csDATA));
                PutField_CString(hOut,"plainttext_data",csDATA);

		if (!strncmp(csDATA,MY_HCP_DATA_TOKEN,1))
			iWithOrderId = PD_FALSE;
/* order_id */
		if (iWithOrderId == PD_TRUE) {
                	p = strtok(csDATA,MY_HCP_DATA_TOKEN);
                	if (p) {
                        	PutField_CString(hOut,"tid",p);
DEBUGLOG(("DEBlockData order_id = [%s]\n",p));
                	}
		}

/* txn_id */
		if (iWithOrderId == PD_TRUE)
               		p = strtok(NULL,MY_HCP_DATA_TOKEN);
		else
               		p = strtok(csDATA,MY_HCP_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_seq",p);
DEBUGLOG(("DEBlockData txn_seq = [%s]\n",p));
                }

/* transmission_datetime */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_date",p);
DEBUGLOG(("DEBlockData txn_date[transmission_datetime] = [%s]\n",p));
                }

/* bankbillno */
		if (iWithOrderId == PD_TRUE) {
                	p = strtok(NULL,MY_HCP_DATA_TOKEN);
                	if (p) {
                        	PutField_CString(hOut,"bank_bill_no",p);
DEBUGLOG(("DEBlockData bank_bill_no = [%s]\n",p));
                	}
		}

/* fundin_date */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"fundin_date",p);
DEBUGLOG(("DEBlockData fundin_date = [%s]\n",p));
                }

/* net_amt */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"txn_amt",p);
DEBUGLOG(("DEBlockData txn_amt = [%s]\n",p));
                }


/* currency_code */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
                        if(strncmp(p,PD_CCY_RMB_HCP,PD_CCY_ID_LEN)==0){
                                PutField_CString(hOut,"txn_ccy",PD_CCY_ISO_CNY);
                        }
                        else{
                                iRet = PD_ERR;
DEBUGLOG(("DEBlockData invalid currency code [%s]\n",p));
                        }
DEBUGLOG(("DEBlockData currency_code = [%s]\n",p));
                }

/* language */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
                        PutField_CString(hOut,"language",p);
DEBUGLOG(("DEBlockData language = [%s]\n",p));
                }

/* issucc */
		p = strtok(NULL,MY_HCP_DATA_TOKEN);
		if (p) {
			PutField_CString(hOut,"status",p);
DEBUGLOG(("DEBlockData status = [%s]\n",p));
		}

/* remark */
                p = strtok(NULL,MY_HCP_DATA_TOKEN);
                if (p) {
DEBUGLOG(("DEBlockData undecoded remark = [%s]\n",p));
			iLen = base64_decode((char *)p,(unsigned char *)csBuf,PD_MAX_BUFFER);
			if(iLen>0){
				csBuf[iLen] = '\0';
                        	PutField_CString(hOut,"remark",csBuf);
DEBUGLOG(("DEBlockData remark = [%s]\n",csBuf));
			}
			else
DEBUGLOG(("DEBlockData remark = [%s]\n",p));
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


