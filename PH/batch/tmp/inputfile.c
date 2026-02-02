
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "inputfile.pc"
};


static unsigned int sqlctx = 311843;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "batchcommon.h"
#include "inputfile.h"
#include "TxnSeq.h"

OBJPTR(BO);
OBJPTR(DB);
char    cDebug;

#define MY_FIELD_TOKEN  "|"

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int insertPayoutHeader(rData *oOutput)
{
	int iResult = FAILURE;

////Insert PayoutRecord Header

	hash_t *hHeader;
	hHeader = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hHeader,0);

	PutField_CString(hHeader,"merchant_id",oOutput->csMerchId);
	PutField_CString(hHeader,"checksum",oOutput->csHeaderChecksum);
	PutField_Int(hHeader,"num_of_record",oOutput->iNumOfRec);

	memcpy(oOutput->csDate, getdatetime(), PD_DATE_LEN);
//TODO: heard code
	PutField_CString(hHeader,"txn_date",oOutput->csDate);
	PutField_CString(hHeader,"batch_id","1");

	DBObjPtr = CreateObj(DBPtr,"DBPayoutHeader","Add");
	if((unsigned long int)(*DBObjPtr)(hHeader) == PD_OK){
DEBUGLOG(("Add Payout Header Success\n"));
	}
	else
DEBUGLOG(("Add Payout Header Failed\n"));

	hash_destroy(hHeader);
	FREE_ME(hHeader);
	return iResult;
}

int insertPayoutDetails(rData *oOutput)
{
	int iResult = FAILURE;

////Insert PayoutRecord Details

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);


	//PutField_CString(hRec,"batch_id",oOutput->csBatchId);
	PutField_CString(hRec,"batch_id","111");
	PutField_CString(hRec,"seq_num",oOutput->csSeqNum);
	PutField_CString(hRec,"merchant_id",oOutput->csMerchId);
	PutField_CString(hRec,"merchant_ref",oOutput->csMerchRef);
	PutField_CString(hRec,"country",oOutput->csCountry);
	PutField_CString(hRec,"identity_id",oOutput->csIdNo);
	PutField_CString(hRec,"account_num",oOutput->csAccountNum);
	PutField_CString(hRec,"account_name",oOutput->csAccountName);
	PutField_CString(hRec,"bank_name",oOutput->csBankName);
	PutField_CString(hRec,"bank_code",oOutput->csBankCode);
	PutField_CString(hRec,"branch",oOutput->csBranch);
	PutField_CString(hRec,"phone_num",oOutput->csMobileNo);
	PutField_CString(hRec,"province",oOutput->csProvince);
	PutField_CString(hRec,"city",oOutput->csCity);
	PutField_CString(hRec,"payout_currency",oOutput->csPayoutCurr);
	PutField_CString(hRec,"dest_currency",oOutput->csDestCurr);
	PutField_CString(hRec,"checksum",oOutput->csChecksum);
	PutField_CString(hRec,"amount",oOutput->csAmount);


	DBObjPtr = CreateObj(DBPtr,"DBPayoutRecord","Add");
	if ((unsigned long int)(*DBObjPtr)(hRec) == PD_OK) {

DEBUGLOG(("Add PayoutDetails Success:[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n",oOutput->csBatchId,oOutput->csSeqNum,oOutput->csMerchRef,oOutput->csCountry,oOutput->csIdNo,oOutput->csAccountNum,oOutput->csAccountName,oOutput->csBankName,oOutput->csBankCode,oOutput->csBranch,oOutput->csMobileNo,oOutput->csProvince,oOutput->csCity,oOutput->csAmount,oOutput->csPayoutCurr,oOutput->csDestCurr,oOutput->csChecksum));

		iResult = SUCCESS;
	}
	else {
DEBUGLOG(("Add PayoutDetails Failed:[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n",oOutput->csBatchId,oOutput->csSeqNum,oOutput->csMerchRef,oOutput->csCountry,oOutput->csIdNo,oOutput->csAccountNum,oOutput->csAccountName,oOutput->csBankName,oOutput->csBankCode,oOutput->csBranch,oOutput->csMobileNo,oOutput->csProvince,oOutput->csCity,oOutput->csAmount,oOutput->csPayoutCurr,oOutput->csDestCurr,oOutput->csChecksum));
	}

	hash_destroy(hRec);
	FREE_ME(hRec);
	return iResult;
}



int getBankCode(rData *oOutput)
{
	DBObjPtr = CreateObj(DBPtr,"DBTwvBanks","GetBankCode_CH");
	if ((unsigned long int)(*DBObjPtr)(oOutput->csBankName,oOutput->csBankCode) == PD_OK) {
DEBUGLOG(("getBankCode: BankName[%s] -> BankCode[%s]\n",oOutput->csBankName,oOutput->csBankCode));
		return SUCCESS;
	}

DEBUGLOG(("getBankCode failed: BankName[%s]\n",oOutput->csBankName));
	strcpy(oOutput->csBankCode,"999");
	return FAILURE;
}


int convertFirstDigit(const char cIdentity)
{
	char cFirstDigit = toupper(cIdentity);

	if(cFirstDigit=='A')		return (1+0*9);
	else if(cFirstDigit=='B')	return (1+1*9);
	else if(cFirstDigit=='C')	return (1+2*9);
	else if(cFirstDigit=='D')	return (1+3*9);
	else if(cFirstDigit=='E')	return (1+4*9);
	else if(cFirstDigit=='F')	return (1+5*9);
	else if(cFirstDigit=='G')	return (1+6*9);
	else if(cFirstDigit=='H')	return (1+7*9);
	else if(cFirstDigit=='I')	return (3+4*9);
	else if(cFirstDigit=='J')	return (1+8*9);
	else if(cFirstDigit=='K')	return (1+9*9);
	else if(cFirstDigit=='L')	return (2+0*9);
	else if(cFirstDigit=='M')	return (2+1*9);
	else if(cFirstDigit=='N')	return (2+2*9);
	else if(cFirstDigit=='O')	return (3+5*9);
	else if(cFirstDigit=='P')	return (2+3*9);
	else if(cFirstDigit=='Q')	return (2+4*9);
	else if(cFirstDigit=='R')	return (2+5*9);
	else if(cFirstDigit=='S')	return (2+6*9);
	else if(cFirstDigit=='T')	return (2+7*9);
	else if(cFirstDigit=='U')	return (2+8*9);
	else if(cFirstDigit=='V')	return (2+9*9);
	else if(cFirstDigit=='W')	return (3+2*9);
	else if(cFirstDigit=='X')	return (3+0*9);
	else if(cFirstDigit=='Y')	return (3+1*9);
	else if(cFirstDigit=='Z')	return (3+3*9);

	else return -100;
}

int isIdentityIdValid(const char* csIdentityId)
{
	int iFirstDigit =0;
	int iSum = 0;
	int iCheck = 0;
	int iSex = 0;
	int iResult = INVALID_ID;
	char * csNumericPart = (char*)malloc(IDENTITY_ID_LEN);

	//check length (11 digit)
	if(strlen(csIdentityId)==IDENTITY_ID_LEN){

		//check 1st digit, between A-Z
		if(isalpha(csIdentityId[0])){

			//check 2-10 digits, numeric
			strncpy(csNumericPart,&csIdentityId[1],IDENTITY_ID_LEN-1);
			csNumericPart[IDENTITY_ID_LEN-1]='\0';
			if(is_numeric(csNumericPart)==PD_TRUE){
				
				//check 2nd digit, 1 or 2
				iSex = atoi(csNumericPart)/100000000;
				if(iSex<=2){
					
					iFirstDigit = convertFirstDigit(csIdentityId[0]);
					iSum = iFirstDigit + iSex*8 + (atoi(&csNumericPart[1])/10000000)*7 + (atoi(&csNumericPart[2])/1000000)*6 + (atoi(&csNumericPart[3])/100000)*5 + (atoi(&csNumericPart[4])/10000)*4 + (atoi(&csNumericPart[5])/1000)*3 +  (atoi(&csNumericPart[6])/100)*2 + (atoi(&csNumericPart[7])/10)*1;

					iCheck = (10-(iSum%10))%10;

					if(atoi(&csNumericPart[8])==iCheck){
						iResult = VALID_ID;
					}
				}
			}
		}
	}

	free(csNumericPart);
	return iResult;
}

int checkAmount(char *csAmount)
{
	int iResult = INVALID_AMOUNT;

	if(is_numeric(csAmount)==PD_TRUE)
		iResult = VALID_AMOUNT;

	return iResult;
}

int parse_field(const char *csInput, rData *oOutput)
{
	char csBuffer[BUFFER_LEN];
	char csData[BUFFER_LEN];
	int iResult = FAILURE;

	strncpy(csBuffer,csInput, BUFFER_LEN);

	char *pComma;
	int iCurrentPos = 0;
	int iPastPos = 0;
	int iDataCnt = 0;
	csData[0]='\0';

////find out the position of comma(s)
	pComma = strchr(csBuffer,',');
	while(pComma!=NULL){
		iCurrentPos = (int)(pComma - csBuffer);
		if(iCurrentPos==(iPastPos+1)){ 
//no data between two commas = empty field
			if((iDataCnt==3)||((iDataCnt==8))||(iDataCnt==9)||(iDataCnt==10)){
				if(iDataCnt==3){ 
					if(strncmp(oOutput->csCountry,"TW",2)==0){
//if country is "TW", identity_id should exists
DEBUGLOG(("parse_field failed (IdentityId missing in record[%s])\n",csBuffer));
						iResult = REJECT;
						//return FAILURE;
					}
					else
						oOutput->csIdNo[0]='\0';
				}
//optional field:phone num,province,city
				else if(iDataCnt==8)
					oOutput->csMobileNo[0]='\0';
				else if(iDataCnt==9)
					oOutput->csProvince[0]='\0';
				else if(iDataCnt==10)
					oOutput->csCity[0]='\0';
			}
			else{
//other than field 3,8,9 and 10, all are mandatory fields
DEBUGLOG(("parse_field failed (Mandatory field missing in record[%s])\n",csBuffer));
				iResult = REJECT;
				//return FAILURE;
			}
		}
		else{
//parse existing fields
			if(iDataCnt==0){
//SeqNum
				strncpy(oOutput->csSeqNum,&csBuffer[iPastPos],PD_SEQ_NUM_LEN);
				oOutput->csSeqNum[iCurrentPos-iPastPos]='\0';
				strcat(csData,oOutput->csSeqNum);
				strcat(csData,MY_FIELD_TOKEN);
			}
			else if(iDataCnt==1){
//MerchRef
				strncpy(oOutput->csMerchRef,&csBuffer[iPastPos+1],PD_MERCHANT_REF_LEN);
				oOutput->csMerchRef[iCurrentPos-iPastPos-1]='\0';
				strcat(csData,oOutput->csMerchRef);
				strcat(csData,MY_FIELD_TOKEN);
			}
			else if(iDataCnt==2){
//Country
				strncpy(oOutput->csCountry,&csBuffer[iPastPos+1],PD_COUNTRY_LEN);
				oOutput->csCountry[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==3){
//IdNo
				strncpy(oOutput->csIdNo,&csBuffer[iPastPos+1],PD_IDENTITY_ID_LEN);
				oOutput->csIdNo[iCurrentPos-iPastPos-1]='\0';
				if(isIdentityIdValid(oOutput->csIdNo)!=VALID_ID){
DEBUGLOG(("parse_field failed (Invalid IdentityId in record[%s])\n",csBuffer));
					iResult = REJECT;
					//return FAILURE;
				}
				strcat(csData,oOutput->csIdNo);
				strcat(csData,MY_FIELD_TOKEN);
			}
			else if(iDataCnt==4){
//AccountNum
				strncpy(oOutput->csAccountNum,&csBuffer[iPastPos+1],PD_AC_NO_LEN);
				oOutput->csAccountNum[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==5){
//AccountName
				strncpy(oOutput->csAccountName,&csBuffer[iPastPos+1],PD_ACC_NAME_LEN);
				oOutput->csAccountName[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==6){
//BankName->BankCode
				strncpy(oOutput->csBankName,&csBuffer[iPastPos+1],PD_BANK_NAME_LEN);
				oOutput->csBankName[iCurrentPos-iPastPos-1]='\0';

				if(getBankCode(oOutput)!=SUCCESS){
DEBUGLOG(("parse_field failed (Invalid BankName in record[%s])\n",csBuffer));
					iResult = REJECT;
					//return FAILURE;
}
			}
			else if(iDataCnt==7){
//Branch
				strncpy(oOutput->csBranch,&csBuffer[iPastPos+1],PD_BANK_BRANCH_LEN);
				oOutput->csBranch[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==8){
//MobileNo
				strncpy(oOutput->csMobileNo,&csBuffer[iPastPos+1],PD_MOBILE_NO_LEN);
				oOutput->csMobileNo[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==9){
//Province
				strncpy(oOutput->csProvince,&csBuffer[iPastPos+1],PD_PROVINCE_LEN);
				oOutput->csProvince[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==10){
//City
				strncpy(oOutput->csCity,&csBuffer[iPastPos+1],PD_CITY_LEN);
				oOutput->csCity[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==11){
//Amount
				strncpy(oOutput->csAmount,&csBuffer[iPastPos+1],AMOUNT_LEN);
				oOutput->csAmount[iCurrentPos-iPastPos-1]='\0';

				if(strncmp(oOutput->csCountry,"TW",2)==0){
					if(checkAmount(oOutput->csAmount)!=VALID_AMOUNT){
DEBUGLOG(("parse_field failed (Invalid Amount in record[%s])\n",csBuffer));
						iResult = REJECT;
					}
				}

				
			}
			else if(iDataCnt==12){
//PayoutCurr
				strncpy(oOutput->csPayoutCurr,&csBuffer[iPastPos+1],PD_CCY_ID_LEN);
				oOutput->csPayoutCurr[iCurrentPos-iPastPos-1]='\0';
			}
			else if(iDataCnt==13){
//DestCurr
				strncpy(oOutput->csDestCurr,&csBuffer[iPastPos+1],PD_CCY_ID_LEN);
				oOutput->csDestCurr[iCurrentPos-iPastPos-1]='\0';
			}

		}
		pComma = strchr(pComma + 1, ',');
		iDataCnt++;
		iPastPos = iCurrentPos;
	}
//check the last parameter, checksum
	if(iPastPos!=strlen(csBuffer)){
		strncpy(oOutput->csChecksum,&csBuffer[iPastPos+1],PD_CHECKSUM_LEN);
		oOutput->csChecksum[iCurrentPos-iPastPos-1]='\0';
	}
	else{
DEBUGLOG(("parse_field failed (Checksum is missing)\n"));
		return FAILURE;
	}

	strcat(csData,oOutput->csCountry);
	strcat(csData,MY_FIELD_TOKEN);
	strcat(csData,oOutput->csAmount);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyMac");
	if ((unsigned long int)(*BOObjPtr)(oOutput->csChecksum,oOutput->csShaKey,csData,strlen(csData)) == PD_OK){

DEBUGLOG(("parse_field success:[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n",oOutput->csSeqNum,oOutput->csMerchRef,oOutput->csCountry,oOutput->csIdNo,oOutput->csAccountNum,oOutput->csAccountName,oOutput->csBankName,oOutput->csBranch,oOutput->csMobileNo,oOutput->csProvince,oOutput->csCity,oOutput->csAmount,oOutput->csPayoutCurr,oOutput->csDestCurr,oOutput->csChecksum));

	}
	else{

DEBUGLOG(("parse_field failed (invalid checksum):[%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s] [%s]\n",oOutput->csSeqNum,oOutput->csMerchRef,oOutput->csCountry,oOutput->csIdNo,oOutput->csAccountNum,oOutput->csAccountName,oOutput->csBankName,oOutput->csBranch,oOutput->csMobileNo,oOutput->csProvince,oOutput->csCity,oOutput->csAmount,oOutput->csPayoutCurr,oOutput->csDestCurr,oOutput->csChecksum));
		iResult = REJECT;//return FAILURE;
	}

	
	return iResult;//SUCCESS;
}

int checkMerchId(const char* csMerchId, char* csShaKey)
{
	char *csTmp = NULL;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
	DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchant");
	if ((*DBObjPtr)(csMerchId,rRecordSet) != PD_OK) {
DEBUGLOG(("checkMerchId: Merchant Id[%s] not found\n",csMerchId));
		return FAILURE;
	}
	else{
		hash_t  *hRec;
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"sha_key",&csTmp)){
				strncpy(csShaKey,csTmp,PD_SHA_KEY_LEN);
				csShaKey[PD_SHA_KEY_LEN]='\0';
DEBUGLOG(("checkMerchId: Sha Key found [%s]\n",csShaKey));
			}

			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	return SUCCESS;
}

int parse_header(const char *csInput, rData *oOutput)
{
	char *pField;
	char csBuffer[BUFFER_LEN];
	int iData = 0;
	int iNumofRec = 0;
	char csFormattedStr[BUFFER_LEN];
	char csCheckSum[PD_CHECKSUM_LEN+1];

	strncpy(csBuffer,csInput, BUFFER_LEN);

	pField = strtok(csBuffer,",");
	while(pField){
		if(iData==0){
//check the merchant id exist or not, if exist, get the sha key
			if(checkMerchId(pField,oOutput->csShaKey)==SUCCESS){
				strncpy(oOutput->csMerchId,pField,PD_MERCHANT_ID_LEN);
				strncpy(csFormattedStr,pField,PD_MERCHANT_ID_LEN);
				strcat(csFormattedStr,MY_FIELD_TOKEN);
			}
			else{
DEBUGLOG(("parse_header: Invalid merchant id[%s]\n",pField));
				return -1;
			}
		}
		else if(iData==1){
			if(is_numeric(pField)!=PD_TRUE){
//check the num of record
DEBUGLOG(("parse_header: Invalid no. of record[%s]\n",pField));
				return -1;
			}
			iNumofRec = atoi(pField);
			strcat(csFormattedStr,pField);
			csFormattedStr[strlen(csFormattedStr)]='\0';;
			oOutput->iNumOfRec = iNumofRec;
		}
		else if(iData==2){ 
//verify the checksum
			strncpy(csCheckSum,pField,PD_CHECKSUM_LEN);
			csCheckSum[PD_CHECKSUM_LEN]='\0';
			BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyMac");
			if((unsigned long int)(*BOObjPtr)(csCheckSum,oOutput->csShaKey,csFormattedStr,strlen(csFormattedStr)) == PD_OK){
				strncpy(oOutput->csHeaderChecksum,csCheckSum,PD_CHECKSUM_LEN+1);
			}
			else{
DEBUGLOG(("parse_header: Invalid checksum [%s]\n",pField));
				return -1;
			}
		}
		else{
DEBUGLOG(("parse_header error: More than 3 fields\n"));
			return -1;
		}

		pField = strtok(NULL,",");
		iData++;
	}


DEBUGLOG(("parse_header finished:[%s] [%d] [%s]\n",oOutput->csMerchId,oOutput->iNumOfRec,oOutput->csHeaderChecksum));

	return iNumofRec;
}

int checkHeader(const char * csFileName, rData *oOutput)
{
	char csBuffer[BUFFER_LEN]={0};
	int iNumOfLine = 0;
	int iNumofRec = 0;

	FILE *pFile;
	pFile = fopen(csFileName,"r");
	if(!pFile){
DEBUGLOG(("cannot open file:[%s]\n",csFileName));
		return FAILURE;
	}

	while( fgets(csBuffer, BUFFER_LEN, pFile) != NULL ){
		if(iNumOfLine==0){
			//The 1st line is header, get the merchant_id and num of record in this batch
			iNumofRec = parse_header(csBuffer, oOutput);
		}
		if(strlen(csBuffer)>1)	iNumOfLine++;  //count the num of data, ignore the last empty line.
	}

	fclose(pFile);

	if((iNumOfLine==1)||(iNumofRec==0)){
DEBUGLOG(("checkHeader: This file only contains Header record[%d][%d]\n",iNumOfLine,iNumofRec));
		return FAILURE;
	}
	else if(iNumofRec<0){ 
DEBUGLOG(("checkHeader: parse header failed\n"));
		return FAILURE;
	}
	else if((iNumOfLine-1)!=iNumofRec){ //match the num of record except header.
DEBUGLOG(("checkHeader: No. of record not match: Count[%d], Header[%d]\n",iNumOfLine-1,iNumofRec));
		return FAILURE;
	}

	return SUCCESS;
}


int sendWithdraw(rData *oOutput)
{
	int iResult = SUCCESS;
	hash_t *hReq;
	hReq = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hReq,0);
/*  process_type */
	PutField_CString(hReq,"process_type","0200");

/*  process_code */
	PutField_CString(hReq,"process_code","220001");

/* merchant_id */
        PutField_CString(hReq,"merchant_id",oOutput->csMerchId);

/* merchant_ref */
        PutField_CString(hReq,"reference",oOutput->csMerchRef);

/* transaction_datetime */
        PutField_CString(hReq,"transaction_datetime",oOutput->csDate);

/* pay_amount $13.21*/
        PutField_CString(hReq,"pay_amount",oOutput->csAmount);

/* currency_code */
        PutField_CString(hReq,"currency_code","TWD");

/* country */
        PutField_CString(hReq,"country",oOutput->csCountry);

/* bank_code */
        PutField_CString(hReq,"bank_code",oOutput->csBankCode);

/* bank_name */
        PutField_CString(hReq,"branch_name",oOutput->csBranch);

/* account_id */
        PutField_CString(hReq,"account_id",oOutput->csAccountNum);

/* account_name */
        PutField_CString(hReq,"account_name",oOutput->csAccountName);

/* identity_id */
        PutField_CString(hReq,"identity_id",oOutput->csIdNo);

/* batch_id */
        PutField_CString(hReq,"batch_id","1");

/* mac */
        PutField_CString(hReq,"mac","1");

        iResult = BatchOnelineWithdraw(hReq);

DEBUGLOG(("RET = [%d]\n",iResult));
        FREE_ME(hReq);
	return iResult;
}

void updatePayoutStatus(const char cStatus)
{
//:TODO	
}

int read_file(const char *csFileName)
{
	FILE *pFile;
	char csBuffer[BUFFER_LEN]={0};
	int iFirstLineChecked = 0;
	int iResult = FAILURE;
	int iRet = FAILURE;

	rData oOutput;

	pFile = fopen(csFileName,"r");
	if(!pFile){
		FREE_ME(csFileName);
DEBUGLOG(("pFile = NULL\n"));
		return FAILURE;
	}

	while( fgets(csBuffer, BUFFER_LEN, pFile) != NULL ){
		if(iFirstLineChecked==0){
			if(checkHeader(csFileName,&oOutput)!=SUCCESS){
DEBUGLOG(("Invalid file header. Stop update.\n"));
				break;
			}
			else{
				insertPayoutHeader(&oOutput);
			}
		}
		else{
			if(strlen(csBuffer)>1){
				iRet = parse_field(csBuffer,&oOutput);
				if(iRet!=FAILURE){
					if(insertPayoutDetails(&oOutput)==SUCCESS){
						sendWithdraw(&oOutput);
						iResult = SUCCESS;
					}
					if(iRet==REJECT){
						updatePayoutStatus(REJECT);
					}
				}
			}
		}
		iFirstLineChecked=1;
	}

	fclose(pFile);
	FREE_ME(csFileName);

	return iResult;
}



int batch_proc(int argc, char* argv[])
{
	char *csFileName = strdup("");
	strcpy(csFileName,argv[1]);
	
	//rData oResult;
DEBUGLOG(("Start reading file\n"));
	if(read_file(csFileName)!=SUCCESS)
		return FAILURE;

DEBUGLOG(("process end\n"));
	return SUCCESS;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
