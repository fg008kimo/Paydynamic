/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/30              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPPU.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define IMPORT_MAX_FIELD                20
#define IMPORT_FIELD_LEN                50

#define HDR_IDX_REF_NUM			0
#define HDR_IDX_FILENAME		1
#define HDR_IDX_FILENAME_PREFIX         2
#define HDR_IDX_MERCHANT_ID             5
#define HDR_IDX_SERVICE_CODE		6
#define HDR_IDX_TXN_CNT                 3
#define HDR_IDX_TXN_AMOUNT              4

#define IDX_REF_NUM			0
#define IDX_SEQ_NUM			1
#define IDX_MERCHANT_REF		2
#define IDX_ACCOUNT_NUM			3
#define IDX_ACCAOUNT_NAME		4
#define IDX_BANK_NAME			5
#define IDX_BRANCH			6
#define IDX_PROVINCE			7
#define IDX_CITY			8
#define IDX_PAYOUT_AMOUNT		9
#define IDX_REQ_AMOUNT			10
#define IDX_REQ_CCY			11
#define IDX_MEMBER_FEE			12
#define IDX_MERCHANT_FEE		13
#define IDX_MARKUP			14
#define IDX_EX_RATE			15
#define IDX_COUNTRY			16
#define IDX_PAYOUT_CCY			17
#define IDX_IDENTITY_ID			18     
#define IDX_PHONE_NUM			19
#define IDX_BANK_CODE			20


#define PD_MY_DELIMITOR ","
#define PD_FILE_DELIMITOR ","


#define PD_FILE_PREFIX "testpayout"

#define PD_CHAR         0x0D

char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Msg);

int AddTxnLog(hash_t *hContext);
int UpdateTxnLog(hash_t *hContext);
int ReadMerchantFile(hash_t *hContext,hash_t *hRequest);
int handle_PayoutApprove(const unsigned long lBatchId,
                         hash_t *hContext,
                         hash_t* hRequest);

void TxnMgtByUsPPU(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	char	*csBatchId = strdup("");
	char    *csTxnSeq = strdup("");
	unsigned long	lBatchId = 0l;
	double	dTmp;
	double	dSrcFee=0;
	double	dDstFee=0;
	double	dMarkUp=0;
	double	dNetAmt=0;
	int	i=0;
	int	iCnt=0;
	int	iTmp=0;
	int	iDayOfWeek=0;
	char	csTag[PD_TAG_LEN+1];
	//char	csPath[PD_TMP_BUF_LEN+1];
	char	csFileName[PD_TMP_BUF_LEN+1];

	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn, 0);


DEBUGLOG(("Authorize\n"));
	/*
	sprintf(csPath, "%s/", getenv("REPORT_DATA"));
	PutField_CString(hContext,"file_path",csPath);
	*/
	if(GetField_CString(hRequest,"txn_seq_id",&csTmp)){
		sprintf(csFileName, "%s/%s%s.txt", getenv("REPORT_DATA"),PD_FILE_PREFIX,csTmp);
		PutField_CString(hContext,"in_filename",csFileName);
	}

	iRet = ReadMerchantFile(hContext,hRequest);
DEBUGLOG(("Authorize: ReadMerchantFile iRet[%d]\n",iRet));

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hTxn,"txn_id",csTmp);
DEBUGLOG(("Authorize: txn_id [%s]\n",csTmp));
	}
/*
	if(GetField_CString(hRequest,"batch_id",&csTmp)){
		PutField_CString(hTxn,"batch_id",csTmp);
		lBatchId = ctol((const unsigned char *)csTmp,strlen(csTmp));
DEBUGLOG(("Authorize: batch_id [%s]\n",csTmp));
	}
*/
	if(GetField_CString(hRequest,"merchant_id",&csTmp)){
		PutField_CString(hTxn,"merchant_id",csTmp);
		PutField_CString(hContext,"merchant_id",csTmp);
		PutField_CString(hContext,"org_merchant_id",csTmp);
DEBUGLOG(("Authorize: merchant_id [%s]\n",csTmp));
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
                if((unsigned long)(*BOObjPtr)(hContext,hRequest)!=PD_OK){
			iRet=INT_ERR;
		}
	}

	if(GetField_CString(hRequest,"service_code",&csTmp)){
		PutField_CString(hTxn,"service_code",csTmp);
		PutField_CString(hContext,"service_code",csTmp);
		PutField_CString(hContext,"org_service_code",csTmp);
DEBUGLOG(("Authorize: service_code [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"posting_date",&csTmp)){
		PutField_CString(hTxn,"posting_date",csTmp);

		iDayOfWeek=day_of_week((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::day_of_week= [%d]\n",iDayOfWeek));
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
DEBUGLOG(("Authorize: posting_date [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"filename",&csTmp)){
		PutField_CString(hTxn,"filename",csTmp);
DEBUGLOG(("Authorize: filename [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"filename_prefix",&csTmp)){
		PutField_CString(hTxn,"filename_prefix",csTmp);
DEBUGLOG(("Authorize: filename_prefix [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"txn_count",&csTmp)){
		iCnt = atoi(csTmp);
		PutField_Int(hTxn,"txn_count",iCnt);
		PutField_Int(hRequest,"total_count",iCnt);
DEBUGLOG(("Authorize: txn_count [%d]\n",iCnt));
	}

	if(GetField_CString(hRequest,"total_txn_amt",&csTmp)){
		if(sscanf(csTmp,"%lf",&dTmp)==1){
			PutField_Double(hTxn,"txn_amt",dTmp);
			PutField_Double(hContext,"txn_amt",dTmp);
DEBUGLOG(("Authorize: total_txn_amt [%lf]\n",dTmp));
		}
	}

	if(iRet==PD_OK){
		//Generate BatchId
DEBUGLOG(("Authorize::Call DBMerchantUploadFileHeader:GenBatchId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","GenBatchId");
		if((unsigned long)((*DBObjPtr)(csBatchId) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantUploadFileHeader:GenBatchId Failed\n"));
ERRLOG("TxnMgtByUsPPU::Authorize::DBMerchantUploadFileHeader:GenBatchId Failed\n");
			iRet = PD_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else {
DEBUGLOG(("Authorize::DBMerchantUploadFileHeader:GenBatchId batch_id = [%s]\n", csBatchId));
			PutField_CString(hTxn, "batch_id", csBatchId);
			PutField_CString(hRequest, "batch_id", csBatchId);
			lBatchId = ctol((const unsigned char *)csBatchId,strlen(csBatchId));
DEBUGLOG(("Authorize::DBMerchantUploadFileHeader:GenBatchId batch_id = [%ld]\n", lBatchId));
		}
	}
	
	if(iRet==PD_OK){
		PutField_Int(hTxn,"status",PD_PAYOUTFILE_UPLOADED);
DEBUGLOG(("Authorize::Call DBMerchantUploadFileHeader:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","Add");
		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantUploadFileHeader:Add Failed\n"));
ERRLOG("TxnMgtByUsPPU::Authorize::DBMerchantUploadFileHeader:Add Failed\n");
			iRet = PD_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	RemoveField_CString(hTxn,"txn_id");
	if(iRet==PD_OK){
		for (i=0;i<iCnt;i++){
			DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextBatchTxnSeq");
                        csTxnSeq  = strdup((*DBObjPtr)());
DEBUGLOG(("GenerateBatchSeq: [%d]=[%s]\n",i,csTxnSeq));
			sprintf(csTag,"txn_id_%d",i);
                        PutField_CString(hRequest,csTag,csTxnSeq);
                        PutField_CString(hTxn,"txn_id",csTxnSeq);
/*
			sprintf(csTag,"aux_txn_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"aux_txn_id",csTmp);
			}
*/
			sprintf(csTag,"seq_num_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				iTmp = atoi(csTmp);
				PutField_Int(hTxn,"seq_num",iTmp);
			}
			sprintf(csTag,"merchant_ref_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"merchant_ref",csTmp);
			}
			sprintf(csTag,"country_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"country",csTmp);
				PutField_CString(hContext,"txn_country",csTmp);
				PutField_CString(hContext,"org_txn_country",csTmp);
			}
			sprintf(csTag,"identity_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"identity_id",csTmp);
			}
			sprintf(csTag,"account_num_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"account_num",csTmp);
			}
			sprintf(csTag,"account_name_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"account_name",csTmp);
			}
			sprintf(csTag,"bank_name_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"bank_name",csTmp);
			}
			sprintf(csTag,"bank_code_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"bank_code",csTmp);
			}
			sprintf(csTag,"branch_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"branch",csTmp);
			}
			sprintf(csTag,"phone_num_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"phone_num",csTmp);
			}
			sprintf(csTag,"province_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"province",csTmp);
			}
			sprintf(csTag,"city_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"city",csTmp);
			}
			sprintf(csTag,"payout_currency_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"payout_currency",csTmp);
				PutField_CString(hTxn,"member_fee_ccy",csTmp);
				PutField_CString(hTxn,"markup_ccy",csTmp);
				PutField_CString(hContext,"dst_txn_fee_ccy",csTmp);
			}
			sprintf(csTag,"payout_amount_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1)
					PutField_Double(hTxn,"payout_amount",dTmp);
			}
			sprintf(csTag,"request_currency_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hTxn,"request_currency",csTmp);
				PutField_CString(hTxn,"merchant_fee_ccy",csTmp);
				PutField_CString(hContext,"txn_ccy",csTmp);
				PutField_CString(hContext,"org_txn_ccy",csTmp);
				PutField_CString(hContext,"src_txn_fee_ccy",csTmp);
			}
			sprintf(csTag,"request_amount_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hTxn,"request_amount",dTmp);

					dNetAmt += dTmp;
					PutField_Double(hContext,"net_amt",dNetAmt);
				}
			}
			sprintf(csTag,"merchant_fee_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hTxn,"merchant_fee",dTmp);

					dSrcFee += dTmp;
					PutField_Double(hContext,"src_txn_fee",dSrcFee);

					dNetAmt += dTmp;
					PutField_Double(hContext,"net_amt",dNetAmt);
				}
			}
			sprintf(csTag,"member_fee_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hTxn,"member_fee",dTmp);

					dDstFee += dTmp;
					PutField_Double(hContext,"dst_txn_fee",dDstFee);
				}
			}
			sprintf(csTag,"markup_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hTxn,"markup_amt",dTmp);

					dMarkUp += dTmp;
					if(dMarkUp>0.0)
						PutField_Double(hContext,"markup_amt",dMarkUp);
				}
			}
			sprintf(csTag,"ex_rate_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				if(sscanf(csTmp,"%lf",&dTmp)==1)
					PutField_Double(hTxn,"ex_rate",dTmp);
			}
			
			PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_UPLOADED);
DEBUGLOG(("Authorize::Call DBMerchantUploadFileDetail:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","Add");
			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantUploadFileDetail:Add Failed\n"));
ERRLOG("TxnMgtByUsPPU::Authorize::DBMerchantUploadFileDetail:Add Failed\n");
				iRet = PD_ERR;
				PutField_Int(hContext,"internal_error",iRet);
				break;
			}
			
		}
	}
	if(iRet==PD_OK){
		//TxnCommit();
	}

	if(iRet==PD_OK){
		PutField_CString(hContext,"new_txn_code",PD_PAYOUT_UPLOAD);
        	PutField_Char(hContext,"party_type",PD_TYPE_MERCHANT);
		iRet = AddTxnLog(hContext);
	}

//////Payout Upload
	if(iRet==PD_OK){
		PutField_Int(hRequest,"succ_ind",PD_TRUE);
DEBUGLOG(("Authorize::call BOPayout->handle_PayoutUpload\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","handle_PayoutUpload");
		iRet = (unsigned long)(*BOObjPtr)(lBatchId,hContext,hRequest);
	}
	if(iRet==PD_OK){
		iRet = UpdateTxnLog(hContext);
	}

//////Payout Confirm 
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOPayout->handle_PayoutConfirm\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","handle_PayoutConfirm");
		iRet = (unsigned long)(*BOObjPtr)(lBatchId,hContext,hRequest);
	}
	if(iRet==PD_OK){
		iRet = UpdateTxnLog(hContext);
	}

//////Payout Approved
	if(iRet==PD_OK){
		iRet = handle_PayoutApprove(lBatchId,hContext,hRequest);
	}
	if(iRet==PD_OK){
		iRet = UpdateTxnLog(hContext);
	}


DEBUGLOG(("TxnMgtByUsPPU Normal Exit() iRet = [%d]\n",iRet));

	FREE_ME(csBatchId);
	FREE_ME(csTxnSeq);
	FREE_ME(hTxn);
        return iRet;
}

int ReadMerchantFile(hash_t *hContext, hash_t *hRequest)
{
	int iRet= PD_OK;
	//char	*csPath;
	char	*csName;
	FILE    *fin;
	int     iCount=0;
	int     i=0;

	char	csTag[PD_TAG_LEN+1];	
	char	csTmpCcy[PD_CCY_ID_LEN+1];	
        char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    csHeader[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];
        //char    csFile[PD_MAX_FILE_LEN+1];
        char    *p;

	//csFile[0]='\0';

	//if(GetField_CString(hContext,"file_path",&csPath)){
	//	strcat(csFile,csPath);
		if(GetField_CString(hContext,"in_filename",&csName)){
			//strcat(csFile,csName);
DEBUGLOG(("ReadMerchantFile : Read file [%s]\n",csName));
			fin = fopen(csName,"r");
			if (fin == NULL) {
DEBUGLOG(("ReadMerchantFile : Error Opening file\n"));
                		iRet = INT_ERR;;
			}
		}
		else{
DEBUGLOG(("ReadMerchantFile : file name not found\n"));
			iRet = INT_ERR;
		}
//	}
	//else{
//DEBUGLOG(("ReadMerchantFile : file path not found\n"));
	//	iRet = INT_ERR;
	//}

	if(iRet==PD_OK){
/*Header*/
		fgets(cs_input_buf,PD_MAX_BUFFER,fin);
		if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
DEBUGLOG(("ReadMerchantFile: Header[%s]\n",cs_input_buf));

		p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
		if (p != NULL){
			strcpy(csHeader[i],p);
			i++;

			while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
				strcpy(csHeader[i],p);
				i++;
			}
		}
		else{
DEBUGLOG(("ReadMerchantFile: Read Header Error\n"));
			iRet = INT_ERR;
		}
	}

	if(iRet==PD_OK){
		for(iCount=0;iCount<i;iCount++){
			if(iCount==HDR_IDX_REF_NUM)
				sprintf(csTag,"ref_num");
			else if(iCount==HDR_IDX_MERCHANT_ID)
				sprintf(csTag,"merchant_id");
			else if(iCount==HDR_IDX_SERVICE_CODE)
				sprintf(csTag,"service_code");
			else if(iCount==HDR_IDX_FILENAME)
				sprintf(csTag,"filename");
			else if(iCount==HDR_IDX_FILENAME_PREFIX)
				sprintf(csTag,"filename_prefix");
			else if(iCount==HDR_IDX_TXN_CNT)
				sprintf(csTag,"txn_count");
			else if(iCount==HDR_IDX_TXN_AMOUNT)
				sprintf(csTag,"total_txn_amt");

			PutField_CString(hRequest,csTag,csHeader[iCount]);
DEBUGLOG(("ReadMerchantFile: Tag[%s]: [%s]\n",csTag,csHeader[iCount]));
		}

		/*hard code first*/
		PutField_CString(hRequest,"merchant_id","8000000101");
		PutField_CString(hRequest,"service_code","CLN");
DEBUGLOG(("ReadMerchantFile: Tag[%s]: [%s]\n","merchant_id","8000000101"));
DEBUGLOG(("ReadMerchantFile: Tag[%s]: [%s]\n","service_code","CLN"));
		/*****************/
	}


	if(iRet==PD_OK){
/*Content*/
		int iRec=0;
		while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

			int i=0;
			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
				cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
			strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("ReadMerchantFile: Content[%s]\n",cs_input_buf));

			p = mystrtok(cs_input_buf,PD_FILE_DELIMITOR);
			if (p != NULL){
				strcpy(csList[i],p);
				i++;

				while ( (p = mystrtok(NULL,PD_FILE_DELIMITOR)) != NULL) {
					strcpy(csList[i],p);
					i++;
				}
			}
			else{
				iRet=INT_ERR;
DEBUGLOG(("ReadMerchantFile: Read Content Error\n"));
			}

			for(iCount=0;iCount<i;iCount++){
			
				if(iCount==IDX_REF_NUM)
					sprintf(csTag,"ref_num_%d",iRec);
				else if(iCount==IDX_MERCHANT_REF)
					sprintf(csTag,"merchant_ref_%d",iRec);
				else if(iCount==IDX_SEQ_NUM)
					sprintf(csTag,"seq_num_%d",iRec);
				else if(iCount==IDX_COUNTRY)
					sprintf(csTag,"country_%d",iRec);
				else if(iCount==IDX_IDENTITY_ID)
					sprintf(csTag,"identity_id_%d",iRec);
				else if(iCount==IDX_ACCOUNT_NUM)
					sprintf(csTag,"account_num_%d",iRec);
				else if(iCount==IDX_ACCAOUNT_NAME)
					sprintf(csTag,"account_name_%d",iRec);
				else if(iCount==IDX_BANK_NAME)
					sprintf(csTag,"bank_name_%d",iRec);
				else if(iCount==IDX_BANK_CODE)
					sprintf(csTag,"bank_code_%d",iRec);
				else if(iCount==IDX_BRANCH)
					sprintf(csTag,"branch_%d",iRec);
				else if(iCount==IDX_PHONE_NUM)
					sprintf(csTag,"phone_num_%d",iRec);
				else if(iCount==IDX_PROVINCE)
					sprintf(csTag,"province_%d",iRec);
				else if(iCount==IDX_CITY)
					sprintf(csTag,"city_%d",iRec);
				else if(iCount==IDX_REQ_AMOUNT)
					sprintf(csTag,"request_amount_%d",iRec);
				else if(iCount==IDX_PAYOUT_AMOUNT)
					sprintf(csTag,"payout_amount_%d",iRec);
				else if(iCount==IDX_REQ_CCY)
					sprintf(csTag,"request_currency_%d",iRec);
				else if(iCount==IDX_PAYOUT_CCY)
					sprintf(csTag,"payout_currency_%d",iRec);
				else if(iCount==IDX_MEMBER_FEE)
					sprintf(csTag,"member_fee_%d",iRec);
				else if(iCount==IDX_MERCHANT_FEE)
					sprintf(csTag,"merchant_fee_%d",iRec);
				else if(iCount==IDX_MARKUP)
					sprintf(csTag,"markup_%d",iRec);
				else if(iCount==IDX_EX_RATE)
					sprintf(csTag,"ex_rate_%d",iRec);

				if(strlen(csList[iCount])){
					if(iCount==IDX_REQ_CCY ||iCount==IDX_PAYOUT_CCY){
						if(!strcmp(csList[iCount],PD_CCY_ISO_RMB)){
							sprintf(csTmpCcy,"%s",PD_CCY_ISO_CNY);
						}
						else{
							sprintf(csTmpCcy,"%s",csList[iCount]);
						}
						PutField_CString(hRequest,csTag,csTmpCcy);
DEBUGLOG(("ReadMerchantFile: Tag[%s]: [%s]\n",csTag,csTmpCcy));
					}
					else{	
						PutField_CString(hRequest,csTag,csList[iCount]);
DEBUGLOG(("ReadMerchantFile: Tag[%s]: [%s]\n",csTag,csList[iCount]));
					}
				}
			}
			iRec++;
		}
	}

	fclose(fin);
	return iRet;
}

int AddTxnLog(hash_t *hContext)
{
        int iRet= PD_OK;
        char    *csTmp;
        double  dTmp;
        char    cPartyType;
        hash_t  *hTxn;
        hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        if (GetField_Char(hContext,"party_type",&cPartyType)) {
DEBUGLOG(("AddTxnLog:: party_type = [%c]\n",cPartyType));
        }
        if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_seq",csTmp);
        }
/*
        if (GetField_CString(hContext,"org_txn_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: org_txn_seq = [%s]\n",csTmp));
                PutField_CString(hTxn,"org_txn_seq",csTmp);
        }
*/
        if (GetField_CString(hContext,"channel_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: channel_code = [%s]\n",csTmp));
                PutField_CString(hTxn,"channel_code",csTmp);
        }
        if (GetField_CString(hContext,"new_txn_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_code = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_code",csTmp);
        }
        if (GetField_CString(hContext,"desc",&csTmp)) {
DEBUGLOG(("AddTxnLog:: desc = [%s]\n",csTmp));
                PutField_CString(hTxn,"desc",csTmp);
        }

	if (GetField_CString(hContext,"PHDATE",&csTmp)) {
DEBUGLOG(("AddTxnLog:: host_posting_date = [%s]\n",csTmp));
                PutField_CString(hTxn,"host_posting_date",csTmp);
                PutField_CString(hTxn,"transmission_datetime",csTmp);
                PutField_CString(hTxn,"tm_date",csTmp);
                PutField_CString(hTxn,"txn_date",csTmp);
        }
        if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_date = [%s]\n",csTmp));
                PutField_CString(hTxn,"local_tm_date",csTmp);
        }
        if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_time = [%s]\n",csTmp));
                PutField_CString(hTxn,"local_tm_time",csTmp);
        }
        if (GetField_CString(hContext,"approval_date",&csTmp)) {
DEBUGLOG(("AddTxnLog:: approval_date = [%s]\n",csTmp));
                PutField_CString(hTxn,"approval_date",csTmp);
        }
        if (GetField_CString(hContext,"add_user",&csTmp)) {
DEBUGLOG(("AddTxnLog:: add_user = [%s]\n",csTmp));
                PutField_CString(hTxn,"add_user",csTmp);
        }
        else{
                PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
        }

	PutField_CString(hTxn,"process_type","0000");
        PutField_CString(hTxn,"process_code","000000");

//Txn Detail
	if (GetField_CString(hContext,"merchant_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: merchant_id = [%s]\n",csTmp));
                PutField_CString(hTxn,"merchant_id",csTmp);
        }

        if (GetField_CString(hContext,"service_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: service_code = [%s]\n",csTmp));
                PutField_CString(hTxn,"service_code",csTmp);
        }

        if(GetField_CString(hContext,"merchant_client_id",&csTmp)){
                PutField_CString(hTxn,"client_id",csTmp);
        }

        if (GetField_CString(hContext,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_ccy",csTmp);
        }
        if (GetField_CString(hContext,"txn_country",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_country = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_country",csTmp);
        }
        if(GetField_Double(hContext,"merchant_open_bal",&dTmp)){
                PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("AddTxnLog:: open_bal= [%f]\n",dTmp));
        }
        if(GetField_Double(hContext,"current_bal",&dTmp)){
                PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal= [%f]\n",dTmp));
        }
        if(GetField_Double(hContext,"total_float",&dTmp)){
                PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("AddTxnLog:: total_float= [%f]\n",dTmp));
        }
        if(GetField_Double(hContext,"total_reserved_amount",&dTmp)){
                PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("AddTxnLog:: total_reserved_amount= [%f]\n",dTmp));
        }
	if(GetField_Double(hContext,"total_hold",&dTmp)){
                PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("AddTxnLog:: total_hold= [%f]\n",dTmp));
        }
        if(GetField_Double(hContext,"settlement_in_transit",&dTmp)){
                PutField_Double(hTxn,"settlement_in_transit",dTmp);
DEBUGLOG(("AddTxnLog:: settlement_in_transit= [%f]\n",dTmp));
        }

	if(GetField_Double(hContext,"txn_amt",&dTmp)){
		PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("AddTxnLog:: txn_amt = [%lf]\n",dTmp));
	}
	/*
        if(cPartyType==PD_TYPE_MERCHANT){
                if(GetField_Double(hContext,"org_net_amt",&dTmp)){
                        PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("AddTxnLog:: txn_amt = [%lf]\n",dTmp));
                }
        }
	*/

//Txn Psp Detail
	if (GetField_CString(hContext,"org_psp_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: psp_id = [%s]\n",csTmp));
                PutField_CString(hTxn,"psp_id",csTmp);
        }

        if (GetField_CString(hContext,"org_psp_txn_ccy",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_ccy",csTmp);
        }

        if(GetField_Double(hContext,"org_dst_net_amt",&dTmp)){
                PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("AddTxnLog:: txn_amt = [%lf]\n",dTmp));
        }

	if (GetField_Double(hContext,"psp_balance",&dTmp)) {
                PutField_Double(hTxn,"bal",dTmp);
DEBUGLOG(("AddTxnLog:: psp_balance = [%f]\n",dTmp));
        }
	if (GetField_Double(hContext,"psp_total_float",&dTmp)) {
                PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("AddTxnLog:: psp_total_float = [%f]\n",dTmp));
        }
	if (GetField_Double(hContext,"psp_total_hold",&dTmp)) {
                PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("AddTxnLog:: psp_total_hold = [%f]\n",dTmp));
        }

        PutField_Char(hTxn,"status",PD_TO_PSP);
        //PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
        PutField_Int(hTxn,"internal_code",PD_OK);
        PutField_CString(hTxn,"response_code","0");

        DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
        iRet = (unsigned long) ((*DBObjPtr)(hTxn));

        if(iRet == PD_OK){
DEBUGLOG(("AddTxnLog::Call DBTransaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("AddTxnLog::DBTransaction:AddDetail Failed\n"));
                }
        }

        if(iRet==PD_OK){
DEBUGLOG(("AddTxnLog::Call DBTransaction:UpdateDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("AddTxnLog::DBTransaction:UpdateDetail Failed\n"));
                }
        }

        if(iRet == PD_OK && cPartyType!=PD_TYPE_MERCHANT){
DEBUGLOG(("AddTxnLog::Call DBTxnPspDetail:Add\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("AddTxnLog::DBTxnPspDetail:Add Failed\n"));
                }
        }
	if(iRet==PD_OK && cPartyType!=PD_TYPE_MERCHANT){
DEBUGLOG(("AddTxnLog::Call DBTxnPspDetail:Update\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("AddTxnLog::DBTxnPspDetail:Update Failed\n"));
                }
        }

        FREE_ME(hTxn);
        return iRet;
}

int UpdateTxnLog(hash_t *hContext)
{
        int iRet= PD_OK;
        char    cTmp;
        char    *csTmp;
        hash_t  *hTxn;
        hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hTxn,"txn_seq",csTmp);
        }

        if (GetField_CString(hContext,"sub_status",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: sub_status = [%s]\n",csTmp));
                PutField_CString(hTxn,"sub_status",csTmp);
        }
        if (GetField_Char(hContext,"status",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: status = [%c]\n",cTmp));
                PutField_Char(hTxn,"status",cTmp);
        }
        if (GetField_Char(hContext,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: ar_ind = [%c]\n",cTmp));
                PutField_Char(hTxn,"ar_ind",cTmp);
        }

        if (GetField_CString(hContext,"approval_date",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: approval_date = [%s]\n",csTmp));
                PutField_CString(hTxn,"approval_date",csTmp);
        }

DEBUGLOG(("UpdateTxnLog::Call DBTransaction:Update\n"));
        DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
        iRet = (unsigned long) ((*DBObjPtr)(hTxn));

	FREE_ME(hTxn);
        return iRet;
}


int handle_PayoutApprove(const unsigned long lBatchId,
                         hash_t *hContext,
                         hash_t* hRequest)
{
        int     iRet = PD_OK;
        double  dTmp;
        char    *csTmp;
        char    *csBatchId;
	int	iSeqNum = 0;
	int	i = 0;
	int	iCnt = 0;
	char	csTag[PD_TAG_LEN+1];	
        hash_t  *hRec;
        hash_t  *hTxn;
        hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("handle_PayoutApprove()\n"));
	if(GetField_CString(hRequest,"batch_id",&csBatchId)){
		PutField_CString(hTxn,"batch_id",csBatchId);
DEBUGLOG(("UpdateDetail for batch[%s]\n",csBatchId));
	}

	GetField_Int(hRequest,"total_count", &iCnt);
        for(i=0; i<iCnt; i++){
                sprintf(csTag,"seq_num_%d",i);
                if(GetField_Int(hRequest,csTag,&iSeqNum)){
DEBUGLOG(("UpdateDetail seq_num[%d]\n",iSeqNum));
                }
                else{
DEBUGLOG(("UpdateDetail seq_num is missing!!!\n"));
                        continue;
                }
		PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_APPROVED);

		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByBatchId");
                if ((*DBObjPtr)(csBatchId,iSeqNum,hTxn) != PD_OK) {
                        iRet = INT_ERR;
			break;
DEBUGLOG(("DBMerchantUploadFileDetail:UpdateDetailByBatchId Failed\n"));
                }
	}
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","GetHeader");
                if ((*DBObjPtr)((unsigned long)lBatchId,rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if(GetField_Double(hRec,"txn_amt",&dTmp)){
					PutField_Double(hTxn,"remain_amt",dTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		PutField_Int(hTxn,"status",PD_PAYOUTFILE_APPROVED);
DEBUGLOG(("UpdateHeader::DBMerchantUploadFileHeader:UpdateHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","UpdateHeader");
		if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("UpdateHeader::DBMerchantUploadFileHeader:UpdateHeader Failed\n"));
		}
	}

        if(iRet==PD_OK){
                if(GetField_Double(hContext,"total_src_txn_fee",&dTmp)){
                        PutField_Double(hContext,"src_txn_fee",dTmp);
                }
                if(GetField_Double(hContext,"total_dst_txn_fee",&dTmp)){
                        PutField_Double(hContext,"dst_txn_fee",dTmp);
                }

                /*Add log to TxnElement*/
                if(GetField_CString(hContext,"txn_seq",&csTmp)){
                        PutField_CString(hContext,"from_txn_seq",csTmp);
                }

                if(GetField_Double(hRequest,"total_txn_amt",&dTmp)){
                        PutField_Double(hContext,"org_txn_amt",dTmp);
                }
                PutField_CString(hContext,"amount_type",PD_DR);
DEBUGLOG(("handle_PayoutApprove::Call BOTxnElements:AddTxnAmtElement\n"));
                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                iRet = (unsigned long)(*BOObjPtr)(hContext);

		if(iRet==PD_OK){
DEBUGLOG(("handle_PayoutApprove::Call BOTxnElements:AddTxnFeeElements\n"));
                	BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
                	iRet = (unsigned long)(*BOObjPtr)(hContext);
		}
		if(iRet==PD_OK){
DEBUGLOG(("handle_PayoutApprove::Call BOTxnElements:AddMarkupAmtElement\n"));
                	BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddMarkupAmtElement");
                	iRet = (unsigned long)(*BOObjPtr)(hContext);
		}
        }

        if(iRet == PD_OK){
DEBUGLOG(("handle_PayoutApprove::Call BOBalance:UpdatePayoutAmount (Merchant)\n"));
                PutField_Char(hContext,"response_mode",PD_ACCEPT);
                PutField_Char(hContext,"party_type",PD_TYPE_MERCHANT);

                BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdatePayoutAmount");
                if((unsigned long)(*BOObjPtr)(hContext)!=PD_OK){
DEBUGLOG(("handle_PayoutApprove::BOBalance:UpdatePayoutAmount Failed\n"));
                        iRet = INT_ERR;
                }
                else{
                        if(GetField_Double(hContext,"merchant_open_bal",&dTmp)){
                                PutField_Double(hContext,"open_bal",dTmp);
                        }
                }
        }

	if(iRet==PD_OK){
DEBUGLOG(("handle_PayoutApprove::Call DBTransaction:UpdateDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("handle_PayoutApprove::DBTransaction:UpdateDetail Failed\n"));
                }
        }

	if(iRet==PD_OK){
		PutField_CString(hContext,"sub_status",PD_APPROVED_FOR_GENERATED);
		PutField_Char(hContext,"status",PD_COMPLETE);
		PutField_Char(hContext,"ar_ind",PD_ACCEPT);

		if(GetField_CString(hContext,"PHDATE",&csTmp)){
			PutField_CString(hContext,"approval_date",csTmp);
		}
	}

	FREE_ME(hTxn);
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        return iRet;
}

