
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "test_sha256rsa_sign.pc"
};


static unsigned int sqlctx = 336266459;


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
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "curl/curl.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "myhash.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode
#define MAX_MSG_SIZE 4096
#define RSA_PKCS1_PADDING       1
#define RSA_SSLV23_PADDING      2
#define RSA_NO_PADDING          3
#define RSA_PKCS1_OAEP_PADDING  4
#define RSA_X931_PADDING        5
/* EVP_PKEY_ only */
#define RSA_PKCS1_PSS_PADDING   6

OBJPTR(BO);

char	cDebug='Y';

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
	int iRet;
	
	char *csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput, 0, sizeof(csOutput));

	char *csPriKeyFile = "oup_ylpe010_pri.pem";
	char *csPassphrase = "112236";

	char *csInput = "accessType=0&bizType=000000&certId=77417877657&encoding=UTF-8&merId=302510173720027&orderId=0000000641469430&signMethod=01&txnSubType=00&txnTime=20181220145434&txnType=00&version=5.1.0";

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hOut;
	hOut = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOut, 0);

printf("Start\n");

printf("csInput [%s]\n",csInput);

	PutField_CString(hOut, "auth_data", csInput);
	PutField_CString(hContext, "psp_privatepem", csPriKeyFile);
	PutField_CString(hContext, "psp_passphrase", csPassphrase);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateOUPSign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hOut);

	if (iRet == PD_OK) {
		if (GetField_CString(hOut, "sign", &csOutput)) {
printf("csOutput [%s]\n",csOutput);
		} else {
printf("no csOutput\n");
		}
	}

printf("\n==========\n\n");
printf("Verify\n");
	
	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

/*

	char *csInputStr = "accNo=6226********0048&accessType=0&bizType=000201&currencyCode=156&encoding=utf-8&exchangeRate=0&merId=777290058110048&orderId=20180421165508&payCardType=01&payType=0001&queryId=211804211655083399028&respCode=00&respMsg=success&settleAmt=1000&settleCurrencyCode=156&settleDate=0421&signMethod=01&signPubKeyCert=-----BEGIN CERTIFICATE----- MIIEQzCCAyugAwIBAgIFEBJJZVgwDQYJKoZIhvcNAQEFBQAwWDELMAkGA1UEBhMC Q04xMDAuBgNVBAoTJ0NoaW5hIEZpbmFuY2lhbCBDZXJ0aWZpY2F0aW9uIEF1dGhv cml0eTEXMBUGA1UEAxMOQ0ZDQSBURVNUIE9DQTEwHhcNMTcxMTAxMDcyNDA4WhcN MjAxMTAxMDcyNDA4WjB3MQswCQYDVQQGEwJjbjESMBAGA1UEChMJQ0ZDQSBPQ0Ex MQ4wDAYDVQQLEwVDVVBSQTEUMBIGA1UECxMLRW50ZXJwcmlzZXMxLjAsBgNVBAMU JTA0MUBaMjAxNy0xMS0xQDAwMDQwMDAwOlNJR05AMDAwMDAwMDEwggEiMA0GCSqG SIb3DQEBAQUAA4IBDwAwggEKAoIBAQDDIWO6AESrg+34HgbU9mSpgef0sl6avr1d bD/IjjZYM63SoQi3CZHZUyoyzBKodRzowJrwXmd+hCmdcIfavdvfwi6x+ptJNp9d EtpfEAnJk+4quriQFj1dNiv6uP8ARgn07UMhgdYB7D8aA1j77Yk1ROx7+LFeo7rZ Ddde2U1opPxjIqOPqiPno78JMXpFn7LiGPXu75bwY2rYIGEEImnypgiYuW1vo9UO G47NMWTnsIdy68FquPSw5FKp5foL825GNX3oJSZui8d2UDkMLBasf06Jz0JKz5AV blaI+s24/iCfo8r+6WaCs8e6BDkaijJkR/bvRCQeQpbX3V8WoTLVAgMBAAGjgfQw gfEwHwYDVR0jBBgwFoAUz3CdYeudfC6498sCQPcJnf4zdIAwSAYDVR0gBEEwPzA9 BghggRyG7yoBATAxMC8GCCsGAQUFBwIBFiNodHRwOi8vd3d3LmNmY2EuY29tLmNu L3VzL3VzLTE0Lmh0bTA5BgNVHR8EMjAwMC6gLKAqhihodHRwOi8vdWNybC5jZmNh LmNvbS5jbi9SU0EvY3JsMjQ4NzIuY3JsMAsGA1UdDwQEAwID6DAdBgNVHQ4EFgQU mQQLyuqYjES7qKO+zOkzEbvdFwgwHQYDVR0lBBYwFAYIKwYBBQUHAwIGCCsGAQUF BwMEMA0GCSqGSIb3DQEBBQUAA4IBAQAujhBuOcuxA+VzoUH84uoFt5aaBM3vGlpW KVMz6BUsLbIpp1ho5h+LaMnxMs6jdXXDh/du8X5SKMaIddiLw7ujZy1LibKy2jYi YYfs3tbZ0ffCKQtv78vCgC+IxUUurALY4w58fRLLdu8u8p9jyRFHsQEwSq+W5+bP MTh2w7cDd9h+6KoCN6AMI1Ly7MxRIhCbNBL9bzaxF9B5GK86ARY7ixkuDCEl4XCF JGxeoye9R46NqZ6AA/k97mJun//gmUjStmb9PUXA59fR5suAB5o/5lBySZ8UXkrI pp/iLT8vIl1hNgLh0Ghs7DBSx99I+S3VuUzjHNxL6fGRhlix7Rb8 -----END CERTIFICATE-----&traceNo=339902&traceTime=0421165508&txnAmt=1000&txnSubType=01&txnTime=20180421165508&txnType=01&version=5.1.0";

	char *csInputSign = "dnyGly9N+/vI9t2Fg/rt/FIQvGGjNzIIxFZyShc8ovHidT4q9U/3I4xlQT5HwsoaQqQYca6k3nGQAoaoZX9bIEbiA/4e3lVJHgWJCnyekbTZI9rue6UBKMcgkjKaGUa4YyY0fECmuaf/KWN7opkA7XRcy3bkYq82eOYQ/EnpU4PSvInSrMjYXBKtTMepGiyCrX9vrGiS2ZGJLLbHZ7Bf0C+FgeB5fEK2jL2Ycoq1vZiKQaMkHB8IgpzeXSwYEqqwcat43kXPX6/ask4eHz2Fuat63MpNoJ6weDbkgDeqXVvVia55Fts9yxW50lh6CsqjM4DYr12Gu933cWDh9Zww4g==";
	char *csPubKeyFile = "plk_oupe001_pub.cer";

	PutField_CString(hRequest, "auth_data", csInputStr);
	PutField_CString(hRequest, "sign", csInputSign);
	PutField_CString(hContext, "psp_publiccert", csPubKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyOUPSign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
printf("iRet = [%d]\n", iRet);

*/

	hash_destroy(hContext);
	hash_destroy(hOut);
	hash_destroy(hRequest);
	FREE_ME(hContext);
	FREE_ME(hOut);
	FREE_ME(hRequest);
	FREE_ME(csOutput);

printf("End\n");
	return 0;
}


/*
int batch_proc(int argc, char* argv[])
{
	int iRet;

	char *csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput, 0, sizeof(csOutput));

	char *csPriKeyFile = "dd_test_pri.pem";
	char *csInput = "bgUrl=https://apidev.systest.site/be/hxv/&curCode=CNY&merchantNo=CX0003001&orderAmount=9876&orderNo=0000000002813328&orderSource=1&orderTime=20180302172051&pageUrl=https://pagedev.systest.site/pay208/return.php?sessionid=5476BACBFD45A4D95B7ADABD9DC2163B&payChannelCode=ABC&payChannelType=1&service=bankPay&signType=2&version=V2.0";

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hOut;
	hOut = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOut, 0);

printf("Start\n");

printf("csInput [%s]\n",csInput);

	PutField_CString(hOut, "auth_data", csInput);
	PutField_CString(hContext, "rsa_key", csPriKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateHXPaySign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hOut);

	if (iRet == PD_OK) {
		if (GetField_CString(hOut, "sign", &csOutput)) {
printf("csOutput [%s]\n",csOutput);
		} else {
printf("no csOutput\n");
		}
	}

printf("\n==========\n\n");

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	//char *csInput2 = "curCode=CNY&cxOrderNo=test0000000001&dealCode=10000&dealMsg=成功&dealTime=20180212184801&fee=111&merchantNo=CX0003001&orderAmount=1234&orderNo=0000000002809978&orderTime=20180212184340&payChannelCode=ABC&signType=2&version=V2.0";
	char *csInput2 = "codeUrl=https://qpay.qq.com/qr/50200d7a&dealCode=10000&dealMsg=交易成功&merchantNo=CX0003001";
	//char *csSign = "Rmj0nPGDvP1ofxTIl7JRrB2r9C3sSmwYctwls4exWzpJgtyQa4P7OANxHEqQ9WtvSf1H3V/vRT1Se7RteAKaDJnadqN2IKy56PCdDewJR3R0EAGwRV3qnSAChKEMQE1PWgbxf4Cjdvb5JxoNjDR1ZpZjglLfF1LFi+P/6k5DQvY=";
	char *csSign = "MfYmslUd8eqn%2BzluzuNfQ%2BskGweSn8dTJwCIbSEVItkY9plAWD6dsuebhSd1JIMzpXUxMANI7aPfWAIzz%2FJaSUPqC50xIxrqgPS949DEIFp6h48ejpETkFIkqQ0kKxQJBms7IbajnuW0lNTX6KaLecw09j78CerysnVHBdAiXEI%3D";
	char *csPubKeyFile = "lm_test_pub.pem";

printf("csInput2 = [%s]\n",csInput2);

	int iLen = 0;
	char csDeSign[PD_TMP_MSG_BUF_LEN];
	urldecode((const unsigned char*)csSign, strlen(csSign), (unsigned char*)csDeSign, &iLen);
	csDeSign[iLen] = '\0';

printf("urldecode(csSign) = [%s]\n",csDeSign);
	PutField_CString(hRequest, "auth_data", csInput2);
	PutField_CString(hRequest, "sign", csDeSign);
	PutField_CString(hContext, "rsa_privatepem", csPubKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyHXPaySign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
printf("iRet = [%d]\n", iRet);

	hash_destroy(hContext);
	hash_destroy(hOut);
	hash_destroy(hRequest);
	FREE_ME(hContext);
	FREE_ME(hOut);
	FREE_ME(hRequest);
	FREE_ME(csOutput);

printf("End\n");
	return 0;
}
*/


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

