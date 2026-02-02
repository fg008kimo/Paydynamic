#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TwvMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"

char	cDebug;

void	TwvMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;

	char*	csTxnCode = NULL;
	char*	csPtr = NULL;
	char*	csURL = NULL;
	char	csTmp[PD_TMP_BUF_LEN + 1];
	char* 	csBuf;
	double	dTmp;
	long	lTmp;


	//double	dTmp;
DEBUGLOG(("FormatMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
//txn code
	if (GetField_CString(hIn,"txn_code",&csTxnCode)) {
DEBUGLOG(("FormatMsg:: txn_code = [%s]\n",csTxnCode));
	}

	outMsg[0]= '\0';
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
//request_function
		strcpy((char*)csBuf,"TC");
		strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
		strcat((char*)csBuf,csTxnCode);
		strcat((char*)csBuf,MY_TWV_TOKEN);

		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcat((char*)csBuf,"url");
DEBUGLOG(("FormatMsg:: psp_url = [%s]\n",csURL));
			strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
			strcat((char*)csBuf,MY_TWV_TOKEN);
		}	
	

//action
		if (GetField_CString(hIn,"action",&csPtr)) {
				strcat((char*)csBuf,"action");
DEBUGLOG(("FormatMsg:: action = [%s]\n",csPtr));
				strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
				strcat((char*)csBuf,csURL);
				strcat((char*)csBuf,"/");
				strcat((char*)csBuf,csPtr);
		}	
		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
	}
	FREE_ME(csBuf);
//access_key
	if (GetField_CString(hIn,"psp_key",&csPtr)) {
DEBUGLOG(("FormatMsg:: access_key = [%s]\n",csPtr));
		strcat((char*)outMsg,"access_key");

		strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_TWV_TOKEN);
	}	
//order_num
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("FormatMsg:: order_num = [%s]\n",csPtr));
		strcat((char*)outMsg,"order_num");

		strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_TWV_TOKEN);
	}	
//amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		//lTmp = double2long(dTmp);
		lTmp = (long)dTmp;
		sprintf(csTmp,"%ld",lTmp);
DEBUGLOG(("FormatMsg:: amount = [%ld]\n",lTmp));
		strcat((char*)outMsg,"amount");

		strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
		strcat((char*)outMsg,csTmp);
		strcat((char*)outMsg,MY_TWV_TOKEN);

	}
/* DSP txn */
	if (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE)) {
//description
		if (GetField_CString(hIn,"txn_desc",&csPtr)) {
DEBUGLOG(("FormatMsg:: description = [%s]\n",csPtr));
			strcat((char*)outMsg,"description");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}	
//return_url
		if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: return_url = [%s]\n",csPtr));
			strcat((char*)outMsg,"return_url");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}	
		else {
DEBUGLOG(("FormatMsg:: fe_url not found!!!\n"));
		}
	}
	else if (!strcmp(csTxnCode,PD_WITHDRAW_TXN_CODE) || !strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)) {
//bank_code
		if (GetField_CString(hIn,"bank_code",&csPtr)) {
DEBUGLOG(("FormatMsg:: bank_code = [%s]\n",csPtr));
			strcat((char*)outMsg,"bank_code");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}	
//branch_name
		if (GetField_CString(hIn,"branch_name",&csPtr)) {
DEBUGLOG(("FormatMsg:: branch_name = [%s]\n",csPtr));
			strcat((char*)outMsg,"branch_name");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}

//account_id
		if (GetField_CString(hIn,"account_id",&csPtr)) {
DEBUGLOG(("FormatMsg:: account_id = [%s]\n",csPtr));
			strcat((char*)outMsg,"account_id");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}
//account_name
		if (GetField_CString(hIn,"account_name",&csPtr)) {
DEBUGLOG(("FormatMsg:: account_name = [%s]\n",csPtr));
			strcat((char*)outMsg,"account_name");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}
//identity_id
		if (GetField_CString(hIn,"identity_id",&csPtr)) {
DEBUGLOG(("FormatMsg:: identity_id = [%s]\n",csPtr));
			strcat((char*)outMsg,"identity_id");

			strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
			strcat((char*)outMsg,csPtr);
			strcat((char*)outMsg,MY_TWV_TOKEN);
		}
	}


DEBUGLOG(("outmsg = [%s]\n",outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatMsg() Exit\n"));
	FREE_ME(csTxnCode);
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return 	iRet;
}



int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	double	 dTmp;
	hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);
                
DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));
                                
        if (Str2Cls(hRec,(char*)inMsg,MY_TWV_TOKEN, MY_TWV_FIELD_TOKEN) == PD_OK) {

/* tid */
		if (GetField_CString(hRec,"tid",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
		}

/* txn_date */
		if (GetField_CString(hRec,"req_time",&csPtr)) {
			PutField_CString(hOut,"txn_date",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_date = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_date not found\n"));
		}

/* access_key */
		if (GetField_CString(hRec,"access_key",&csPtr)) {
			PutField_CString(hOut,"access_key",csPtr);
DEBUGLOG(("BreakDownMsg:: access_key = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: access_key not found\n"));
		}

/* order_num */
		if (GetField_CString(hRec,"order_num",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq[order_num] = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: order_num not found\n"));
		}

/* status */
		if (GetField_CString(hRec,"status",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}

/* error_code */
		if (GetField_CString(hRec,"error_code",&csPtr)) {
			PutField_CString(hOut,"error_code",csPtr);
DEBUGLOG(("BreakDownMsg:: error_code = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: error_code not found\n"));
		}

/* deposit_url */
		if (GetField_CString(hRec,"deposit_url",&csPtr)) {
			PutField_CString(hOut,"deposit_url",csPtr);
DEBUGLOG(("BreakDownMsg:: deposit_url = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: deposit_url not found\n"));
		}

/* amount */
		if (GetField_CString(hRec,"amount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: amount not found\n"));
		}

/* bank_code */
		if (GetField_CString(hRec,"bank_code",&csPtr)) {
			PutField_CString(hOut,"bank_code",csPtr);
DEBUGLOG(("BreakDownMsg:: bank_code = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: bank_code not found\n"));
		}

/* bank_branch */
		if (GetField_CString(hRec,"bank_branch",&csPtr)) {
			PutField_CString(hOut,"bank_branch",csPtr);
DEBUGLOG(("BreakDownMsg:: bank_branch = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: bank_branch not found\n"));
		}

/* acct_name */
		if (GetField_CString(hRec,"account_name",&csPtr)) {
			PutField_CString(hOut,"account_name",csPtr);
DEBUGLOG(("BreakDownMsg:: account_name = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: account_name not found\n"));
		}

/* acct_no */
		if (GetField_CString(hRec,"account_no",&csPtr)) {
			PutField_CString(hOut,"account_no",csPtr);
DEBUGLOG(("BreakDownMsg:: account_no = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: account_no not found\n"));
		}

/* own_id */
		if (GetField_CString(hRec,"own_id",&csPtr)) {
			PutField_CString(hOut,"own_id",csPtr);
DEBUGLOG(("BreakDownMsg:: own_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: own_id not found\n"));
		}

/* description */
		if (GetField_CString(hRec,"description",&csPtr)) {
			PutField_CString(hOut,"description",csPtr);
DEBUGLOG(("BreakDownMsg:: description = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: description not found\n"));
		}

/* batch_id */
		if (GetField_CString(hRec,"batch_id",&csPtr)) {
			PutField_CString(hOut,"batch_id",csPtr);
DEBUGLOG(("BreakDownMsg:: batch_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: batch_id not found\n"));
		}

/* fundin_date */
		if (GetField_CString(hRec,"fundin_date",&csPtr)) {
			PutField_CString(hOut,"fundin_date",csPtr);
DEBUGLOG(("BreakDownMsg:: fundin_date = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: fundin_date not found\n"));
		}

/* fundout_date */
		if (GetField_CString(hRec,"fundout_date",&csPtr)) {
			PutField_CString(hOut,"fundout_date",csPtr);
DEBUGLOG(("BreakDownMsg:: fundout_date = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: fundout_date not found\n"));
		}

/* service_fee */
		if (GetField_CString(hRec,"service_fee",&csPtr)) {
			dTmp = ctod((const unsigned char*)csPtr,strlen(csPtr),0);
			//dTmp = myctod(p,strlen(p) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
			PutField_Double(hOut,"service_fee",dTmp);
DEBUGLOG(("BreakDownMsg:: service_fee = [%f]\n",dTmp));
		}
		else{
DEBUGLOG(("BreakDownMsg:: service_fee not found\n"));
		}

/* FERESP */
		if (GetField_CString(hRec,"FERESP",&csPtr)) {
			PutField_Char(hOut,"FERESP",csPtr[0]);
DEBUGLOG(("BreakDownMsg:: FERESP = [%c]\n",csPtr[0]));
		}
		else{
DEBUGLOG(("BreakDownMsg:: FERESP not found\n"));
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

int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csTmp = NULL;
DEBUGLOG(("initReplyFromRequest()\n"));
	

/* order_num */
        if (GetField_CString(hRequest,"merchant_ref",&csTmp)) {
DEBUGLOG(("initReplyFromRequest: order_num = [%s]\n",csTmp));
                PutField_CString(hResponse,"order_num",csTmp);
        }


DEBUGLOG(("initReplyFromRequest() Exit\n"));
	FREE_ME(csTmp);
	return iRet;
}

int FormatBatchMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;

	char*	csTxnCode = NULL;
	char*	csPtr = NULL;
	char*	csURL = NULL;
	char	csTmp[PD_TMP_BUF_LEN + 1];
	char* 	csBuf;
	char	csTag[PD_TAG_LEN +1];

	double	dTmp;
	long	lTmp;
	int	iTotal = 0,i;


	unsigned char buf[PD_MAX_BUFFER + 1]={0};
        unsigned long bufLen=sizeof(buf);

	unsigned char tmpbuf[PD_MAX_BUFFER + 1]={0};

	//double	dTmp;
DEBUGLOG(("FormatBatchMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
//txn code
	if (GetField_CString(hIn,"txn_code",&csTxnCode)) {
DEBUGLOG(("FormatBatchMsg:: txn_code = [%s]\n",csTxnCode));
	}

	outMsg[0]= '\0';
DEBUGLOG(("outmsg = [%s]\n",outMsg));
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
//request_function
		strcpy((char*)csBuf,"TC");
		strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
		strcat((char*)csBuf,csTxnCode);
		strcat((char*)csBuf,MY_TWV_TOKEN);

		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcat((char*)csBuf,"url");
DEBUGLOG(("FormatBatchMsg:: psp_url = [%s]\n",csURL));
			strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
			strcat((char*)csBuf,MY_TWV_TOKEN);
		}	
	

//action
		if (GetField_CString(hIn,"action",&csPtr)) {
				strcat((char*)csBuf,"action");
DEBUGLOG(("FormatBatchMsg:: action = [%s]\n",csPtr));
				strcat((char*)csBuf,MY_TWV_FIELD_TOKEN);
				strcat((char*)csBuf,csURL);
				strcat((char*)csBuf,"/");
				strcat((char*)csBuf,csPtr);
		}	
		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatBatchMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
	}
	FREE_ME(csBuf);
//psp_key
	if (GetField_CString(hIn,"psp_key",&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: psp_key = [%s]\n",csPtr));
		strcat((char*)outMsg,"access_key");

		strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_TWV_TOKEN);
	}	
	GetField_Int(hIn,"total",&iTotal);
DEBUGLOG(("FormatBatchMsg: total = [%d]\n",iTotal));

	strcat((char*)outMsg,"total");
	strcat((char*)outMsg,MY_TWV_FIELD_TOKEN);
	sprintf(csTmp,"%d",iTotal);
	strcat((char*)outMsg,csTmp);
	strcat((char*)outMsg,MY_TWV_TOKEN);

	for (i = 0; i < iTotal; i++) {
//order_num
		sprintf(csTag,"order_num_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}	
//amount
		sprintf(csTag,"txn_amt_%d",i);
		if (GetField_Double(hIn,csTag,&dTmp)) {
			lTmp = (long) dTmp;
			sprintf(csTmp,"%ld",lTmp);
			sprintf(csTag,"amount_%d",i);
DEBUGLOG(("FormatBatchMsg:: %s = [%ld]\n",csTag,lTmp));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csTmp);
			strcat((char*)buf,MY_TWV_TOKEN);

		}
//bank_code
		sprintf(csTag,"bank_code_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}	
//branch_name
		sprintf(csTag,"branch_name_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}

//account_id
		sprintf(csTag,"account_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}
//account_name

		sprintf(csTag,"account_name_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatBatchMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}
//identity_id
		sprintf(csTag,"identity_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
DEBUGLOG(("FormatMsg:: %s = [%s]\n",csTag,csPtr));
			strcat((char*)buf,csTag);

			strcat((char*)buf,MY_TWV_FIELD_TOKEN);
			strcat((char*)buf,csPtr);
			strcat((char*)buf,MY_TWV_TOKEN);
		}

	}

	bufLen = strlen((const char*)buf);
DEBUGLOG(("outmsg = [%s]\n",outMsg));
DEBUGLOG(("buf = [%s]\n",buf));
        base64_encode(buf,bufLen,(char*)tmpbuf,PD_MAX_BUFFER);
                
DEBUGLOG(("[%d][%s]\n",strlen((const char*)tmpbuf),tmpbuf));
        strcat((char*)outMsg,(char*)buf);


	*outLen = strlen((char*)outMsg);
DEBUGLOG(("FormatMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatMsg() Exit\n"));
	FREE_ME(csTxnCode);
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return 	iRet;
}



int BreakDownBatchMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csBuf;
	char	*p;
	double	 dTmp;
	int	iTotal = 0,i;
	char	csTag[PD_TAG_LEN + 1];

	csBuf = (char*) malloc (1024 +1);

	memcpy(csBuf,inMsg,inLen);
	csBuf[inLen] = '\0';
DEBUGLOG(("BreakDownBatchMsg()\n"));
DEBUGLOG(("DATA = [%s]\n",inMsg));

/* total */
	p = GetField((const unsigned char*)csBuf,"total",MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
	if (p) {
		
		iTotal = ctos((unsigned char*)p,strlen(p));
		PutField_Int(hOut,"total",iTotal);
DEBUGLOG(("BreakDownBatchMsg:: total = [%d]\n",iTotal));
	}
	
	for (i = 0; i < iTotal; i ++) {
/* tid */
		sprintf(csTag,"tid_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}

/* txn_date */
		sprintf(csTag,"req_time_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}

/* access_key */
		sprintf(csTag,"access_key_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* order_num */
		sprintf(csTag,"order_num_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* status */
		sprintf(csTag,"status_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* error_code */
		sprintf(csTag,"error_code_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* deposit_url */
		sprintf(csTag,"deposit_url_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* amount */
		sprintf(csTag,"amount_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}

/* bank_code */
		sprintf(csTag,"bank_code_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* bank_branch */
		sprintf(csTag,"bank_branch_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* acct_name */
		sprintf(csTag,"account_name_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* acct_no */
		sprintf(csTag,"account_no_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* own_id */
		sprintf(csTag,"own_id_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* description */
		sprintf(csTag,"description_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* batch_id */
		sprintf(csTag,"batch_id_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* fundin_date */
		sprintf(csTag,"fundin_date_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* fundout_date */
		sprintf(csTag,"fundout_date_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			PutField_CString(hOut,csTag,p);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%s]\n",csTag,p));
		}
/* service_fee */
		sprintf(csTag,"service_fee_%d",i);
		p = GetField((const unsigned char*)csBuf,csTag,MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
		if (p) {
			dTmp = ctod((const unsigned char*)p,strlen(p),0);
		//dTmp = myctod(p,strlen(p) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
			PutField_Double(hOut,csTag,dTmp);
DEBUGLOG(("BreakDownBatchMsg:: %s = [%f]\n",csTag,dTmp));
		}
	}
/* FERESP */
	p = GetField((const unsigned char*)csBuf,"FERESP",MY_TWV_TOKEN,MY_TWV_FIELD_TOKEN);
	if (p) {
		PutField_Char(hOut,"FERESP",p[0]);
DEBUGLOG(("BreakDownMsg:: FERESP = [%c]\n",p[0]));
	}

	FREE_ME(csBuf);
DEBUGLOG(("BreakDownMsg Exit\n"));
	return	iRet;
}

