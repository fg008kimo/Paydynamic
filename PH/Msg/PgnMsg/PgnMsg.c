/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/17              Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PgnMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"


char	cDebug;

OBJPTR(DB);

void	PgnMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int iRet = PD_OK;
	char*	csPtr;
	char*	csURL;
	char*	csBuf;
	double	dTmp;
	long	lTmp;
	char*	csTKind;


	csBuf = (char*) malloc (PD_TMP_BUF_LEN * 2 + 1 );
	
	outMsg[0]='\0';
	*outLen = 0;


	//psp_url
        if (GetField_CString(hIn,"psp_url",&csURL) && iRet == PD_OK) {
//request_function
                if (GetField_CString(hIn,"request_function",&csPtr)) {
                        strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatMsg:: psp_url = [%s]\n",csURL));
                        strcat((char*)csBuf,MY_PGEN_FIELD_TOKEN);
                        strcat((char*)csBuf,csURL);
                        strcat((char*)csBuf,"/");
                        strcat((char*)csBuf,csPtr);
                        strcat((char*)csBuf,MY_PGEN_TOKEN);
                }

                sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));
                strcat((char*)outMsg,csBuf);
        }
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: psp_url not found\n"));
	}
        FREE_ME(csBuf);

/* merchant_id */
     	if (GetField_CString(hIn,"psp_merchant_id",&csPtr) && iRet == PD_OK) {
       		strcat((char*)outMsg,"merchant_id");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
DEBUGLOG(("FormatMsg:: psp_merchant_id = [%s]\n",csPtr));
     	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_merchant_id is missing\n"));
        }

/* psp_key_id */
     	if (GetField_CString(hIn,"psp_key_id",&csPtr) && iRet == PD_OK) {
       		strcat((char*)outMsg,"connect_id");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
DEBUGLOG(("FormatMsg:: psp_key_id = [%s]\n",csPtr));
     	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_key_id is missing\n"));
        }

/* psp_key */
     	if (GetField_CString(hIn,"psp_key",&csPtr) && iRet == PD_OK) {
       		strcat((char*)outMsg,"connect_password");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
DEBUGLOG(("FormatMsg:: psp_key = [%s]\n",csPtr));
     	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_key is missing\n"));
        }

/* telegram_kind */
    	if (GetField_CString(hIn,"telegram_kind",&csTKind) && iRet == PD_OK) {
       		strcat((char*)outMsg,"telegram_kind");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csTKind);
                strcat((char*)outMsg,MY_PGEN_TOKEN);

DEBUGLOG(("FormatMsg:: telegram_kind = [%s]\n",csTKind));
     	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** telegram_kind is missing\n"));
        }

/* telegram_version */
       	strcat((char*)outMsg,"telegram_version");
        strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
        strcat((char*)outMsg,"1.0");
        strcat((char*)outMsg,MY_PGEN_TOKEN);

//order_num
        if (GetField_CString(hIn,"order_num",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: order_num = [%s]\n",csPtr));
                strcat((char*)outMsg,"trading_id");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
        }
	else {
DEBUGLOG(("FormatMsg:: *** order_num is missing\n"));
	}

//amount
        if (GetField_Double(hIn,"psp_txn_amt",&dTmp) && iRet == PD_OK) {
		char*	csTmp;
DEBUGLOG(("FormatMsg:: amount = [%lf]\n",dTmp));
                lTmp = double2long(dTmp)/100;
		csTmp = (char*) malloc (PD_TMP_BUF_LEN + 1);
                sprintf(csTmp,"%ld",lTmp);
DEBUGLOG(("FormatMsg:: amount = [%ld]\n",lTmp));
		if (!strcmp(csTKind,"060")) 
               		strcat((char*)outMsg,"amount");
		else if (!strcmp(csTKind,"030") || !strcmp(csTKind,"010")) 
               		strcat((char*)outMsg,"payment_amount");
		
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csTmp);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
		FREE_ME(csTmp);

        }

/*claim_kana*/
    	if (GetField_CString(hIn,"claim_kana",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: claim_kana = [%s]\n",csPtr));
                strcat((char*)outMsg,"claim_kana");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
/*claim_kanji*/
    	if (GetField_CString(hIn,"claim_kanji",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: claim_kanji = [%s]\n",csPtr));
                strcat((char*)outMsg,"claim_kanji");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,code_convert(PD_HOST_CODE,PD_JAP_CODE,csPtr));
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
/*payment_detail_kana*/
    	if (GetField_CString(hIn,"payment_detail_kana",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: claim_kana = [%s]\n",csPtr));
                strcat((char*)outMsg,"payment_detail_kana");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
/*claim_kanji*/
    	if (GetField_CString(hIn,"payment_detail",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: payment_detail = [%s]\n",csPtr));
                strcat((char*)outMsg,"payment_detail");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,code_convert(PD_HOST_CODE,PD_JAP_CODE,csPtr));
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
	
/* return url*/
        if (GetField_CString(hIn,"fe_url",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg::fe_url = [%s]\n",csPtr));
                strcat((char*)outMsg,"return_url");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);

                strcat((char*)outMsg,"stop_return_url");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
        }
	else {
DEBUGLOG(("FormatMsg:: *fe_url is missing\n"));
	}

/* bank code */
/*
        strcat((char*)outMsg,"bank_code");
        strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
        strcat((char*)outMsg,"0001");
        strcat((char*)outMsg,MY_PGEN_TOKEN);
*/

/* pc_mobile_type */

/*
        strcat((char*)outMsg,"pc_mobile_type");
        strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
        strcat((char*)outMsg,"0");
        strcat((char*)outMsg,MY_PGEN_TOKEN);
*/
/* cvs type */
    	if (GetField_CString(hIn,"cvs_type",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: cvs_type = [%s]\n",csPtr));
                strcat((char*)outMsg,"cvs_type");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);

                strcat((char*)outMsg,"sales_type");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,"1"); // advance payment
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
/* cvs company_id */
    	if (GetField_CString(hIn,"cvs_company_id",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: cvs_company_id = [%s]\n",csPtr));
                strcat((char*)outMsg,"cvs_company_id");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}

/*customer_family_name*/
    	if (GetField_CString(hIn,"customer_family_name",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: customer_family_name = [%s]\n",csPtr));
                strcat((char*)outMsg,"customer_family_name");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,code_convert(PD_HOST_CODE,PD_JAP_CODE,csPtr));
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}

/*customer_name*/
    	if (GetField_CString(hIn,"customer_name",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: customer_name = [%s]\n",csPtr));
                strcat((char*)outMsg,"customer_name");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,code_convert(PD_HOST_CODE,PD_JAP_CODE,csPtr));
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}
/*customer_tel*/
    	if (GetField_CString(hIn,"customer_tel",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("FormatMsg:: customer_tel = [%s]\n",csPtr));
                strcat((char*)outMsg,"customer_tel");
                strcat((char*)outMsg,MY_PGEN_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_PGEN_TOKEN);
	}


	if (iRet == PD_OK) {
		*outLen = strlen((char*)outMsg);
	}
        *outLen = strlen((char*)outMsg);
	FREE_ME(csBuf);
DEBUGLOG(("FormatMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatMsg:: iRet = [%d]\n",iRet));
	return iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	char    MY_TOKEN[] =    "\n";
	int	iRet = PD_OK;
	char*	csPtr;
	hash_t	*hRec;

	hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);


DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char*)inMsg,MY_TOKEN, MY_PGEN_FIELD_TOKEN) == PD_OK) {
		
		
/* result */
        	if (GetField_CString(hRec,"result",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
               		PutField_CString(hOut,"status",csPtr);
        	}       
        	else {
DEBUGLOG(("BreakDownMsg:: status not found\n"));
        	}
/* success_code */
        	if (GetField_CString(hRec,"success_code",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: success_code = [%s]\n",csPtr));
               		PutField_CString(hOut,"success_code",csPtr);
        	}       
        	else {
DEBUGLOG(("BreakDownMsg:: success_code not found\n"));
        	}
/* payment_notice_id*/
        	if (GetField_CString(hRec,"payment_notice_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: payment_notice_id = [%s]\n",csPtr));
               		PutField_CString(hOut,"payment_notice_id",csPtr);
        	}       
        	else {
DEBUGLOG(("BreakDownMsg:: payment_notice_id not found\n"));
        	}
/* payment_type*/
        	if (GetField_CString(hRec,"payment_type",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: payment_type = [%s]\n",csPtr));
           		PutField_CString(hOut,"payment_type",csPtr);
        	}       
        	else {
DEBUGLOG(("BreakDownMsg:: payment_type not found\n"));
        	}

/* payment_status*/
        	if (GetField_CString(hRec,"payment_status",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: payment_status = [%s]\n",csPtr));
               		PutField_CString(hOut,"payment_status",csPtr);
        	}       
        	else {
DEBUGLOG(("BreakDownMsg:: payment_status not found\n"));
        	}
/* response_code */
        	if (GetField_CString(hRec,"response_code",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: error_code = [%s]\n",csPtr));
            		PutField_CString(hOut,"error_code",csPtr);
        	}       
/* trading_id */
        	if (GetField_CString(hRec,"trading_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
 	               PutField_CString(hOut,"txn_seq",csPtr);
       	 	}       
        	else {
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
        	}
        
/* asp_limit_date */
        	if (GetField_CString(hRec,"asp_limit_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: asp_limit_date = [%s]\n",csPtr));
 	               PutField_CString(hOut,"limit_date",csPtr);
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: asp_limit_date not found\n"));
        	}
        
/* asp_payment_limit_date */
        	if (GetField_CString(hRec,"asp_payment_limit_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: asp_payment_limit_date = [%s]\n",csPtr));
 	               PutField_CString(hOut,"payment_limit_date",csPtr);
        	}
        	else if (GetField_CString(hRec,"payment_limit_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: payment_limit_date = [%s]\n",csPtr));
 	               PutField_CString(hOut,"payment_limit_date",csPtr);
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: asp_payment_limit_date not found\n"));
        	}

/* deposit_url */
        	if (GetField_CString(hRec,"asp_url",&csPtr) || GetField_CString(hRec,"receipt_print_url",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: deposit_url = [%s]\n",csPtr));
                	PutField_CString(hOut,"deposit_url",csPtr);
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: deposit_url not found\n"));
        	}

/* amount */
        	if (GetField_CString(hRec,"amount",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
 	               PutField_CString(hOut,"txn_amt",csPtr);
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
        	}
/* payment amount */
        	if (GetField_CString(hRec,"paymount_amount",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: payment_amt = [%s]\n",csPtr));
 	               PutField_CString(hOut,"txn_amt",csPtr);
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: payment_amt not found\n"));
        	}

/* claim_kana */
        	if (GetField_CString(hRec,"claim_kana",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: claim_kana = [%s]\n",csPtr));
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: claim_kana not found\n"));
		}

/* claim_kanji */
        	if (GetField_CString(hRec,"claim_kanji",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: claim_kanji = [%s]\n",csPtr));
        	}
        	else {
DEBUGLOG(("BreakDownMsg:: claim_kanji not found\n"));
        	}

/* txn_date */
        	if (GetField_CString(hRec,"trade_generation_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_date = [%s]\n",csPtr));
	                PutField_CString(hOut,"txn_date",csPtr);
       	 	}
        	else {
DEBUGLOG(("BreakDownMsg:: txn_date not found\n"));
        	}
/* fundin_date */
        	if (GetField_CString(hRec,"payment_date",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: fundin_date = [%s]\n",csPtr));
	                PutField_CString(hOut,"fundin_date",csPtr);
		}
/* tid */
        	if (GetField_CString(hRec,"payment_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
	                PutField_CString(hOut,"tid",csPtr);
		}
/* bank_code */
        	if (GetField_CString(hRec,"bank_code",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: bank_code = [%s]\n",csPtr));
			char	csMyCode[PD_BANK_ID_LEN +1];
			DBObjPtr = CreateObj(DBPtr,"DBBankMapping","e2iBankCodeMapping");
                	if ((unsigned long)(DBObjPtr)(csPtr,PD_CHANNEL_PGEN,PD_JAPAN,csMyCode) == FOUND) {
                        	PutField_CString(hOut,"bank_code",csMyCode);
DEBUGLOG(("BreakDownMsg:: int bank_code = [%s]\n",csMyCode));
                	}
			else {
	                	PutField_CString(hOut,"bank_code",csPtr);
DEBUGLOG(("BreakDownMsg:: int bank_code = [%s]\n",csPtr));
			}
		}
/* pay_center_number */
        	if (GetField_CString(hRec,"pay_center_number",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: pay_center_number = [%s]\n",csPtr));
	                PutField_CString(hOut,"pay_center_number",csPtr);
		}
/* customer_number */
        	if (GetField_CString(hRec,"customer_number",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: customer_number = [%s]\n",csPtr));
	                PutField_CString(hOut,"customer_number",csPtr);
		}
/* conf_number */
        	if (GetField_CString(hRec,"conf_number",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: conf_number = [%s]\n",csPtr));
	                PutField_CString(hOut,"conf_number",csPtr);
		}

/* receipt_number */
        	if (GetField_CString(hRec,"receipt_number",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: receipt_number = [%s]\n",csPtr));
	                PutField_CString(hOut,"receipt_number",csPtr);
		}

/* store_id */
        	if (GetField_CString(hRec,"usable_cvs_company_id",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: store_id = [%s]\n",csPtr));
	                PutField_CString(hOut,"store_id",csPtr);
		}


	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
        FREE_ME(hRec);
DEBUGLOG(("BreakDownMsg:: exit iRet = [%d]\n",iRet));
        return iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
        int     iRet = PD_OK;

DEBUGLOG(("initReplyFromRequest() ret = [%d]\n",iRet));
	return iRet;
}
