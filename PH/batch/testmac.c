
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "testmac.pc"
};


static unsigned int sqlctx = 81123;


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
#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "mymd5.h"

OBJPTR(BO);
char    cDebug;

int Verify51EpaySign(const unsigned char* csClearSig,const unsigned char* csAuthData);
int GenerateMD5Mac(const unsigned char* KEY,const unsigned char* DATA, const int DATA_LEN,unsigned char* OUT);

int batch_init(int argc, char* argv[])
{
/*	if(argc<2)
	{
		printf(("Please input enought arguments\n"));
		return FAILURE;
	}
	else  {
        	return SUCCESS;
	}
*/
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
    int iRet = SUCCESS;
    char *csKey = (char*) malloc (PD_TMP_BUF_LEN +1);
    char *csData = (char*) malloc (PD_TMP_BUF_LEN +1);
    char *csMac = (char*) malloc (PD_TMP_MSG_BUF_LEN+1);
//    char *csTmp;


    strcpy(csData,"business_id=APG-ALLINPAY-WC001&order_id=0000000001000008&amount=123&key=");
    csData[strlen(csData)]='\0';

    strcpy(csKey,"First@168");
    csKey[strlen(csKey)]='\0';

    printf("Data: [%s]\n",csData);
    printf("Key: [%s]\n",csKey);

    iRet = GenerateMD5Mac((const unsigned char*)csKey,(const unsigned char*)csData,strlen(csData),(unsigned char*)csMac);
    

/*
    //strcpy(csData,"OK000000003673574747392PAYPTOKNIL2013-07-11 12:01:44494.44TRANSACTION81b73f736aa8a49e7971f038a28d71a8bfafcd1f");
    strcpy(csData,"OK000000003726660056102PAYPTOKNIL2013-07-17 11:33:3290.00TRANSACTION7c905f5a048993508cf0985ddd9543519cbf1a5e");
    csData[strlen(csData)]='\0';

    strcpy(csKey,"aSaJ4z4C4wFCgSKBocVqaWw7nGXed5MWRo4HnXdBNYIU27htza1a1r2LxBpvo10YfXqWSwH775YAX6Cc4BBeFl5bIGHl/f/yC8IF4I/EPoP5IJgTb9GQSp3IEsaeggeQjY5NtqGdGspzsbzAHyvkZ1K5zRqRcrkGlQHdUCGOcN8=");

    printf("Input Data: [%s]\n",csData);
    printf("Input Key: [%s]\n\n",csKey);
    
    iRet = Verify51EpaySign((const unsigned char*)csKey,(const unsigned char*)csData);
*/
/*
    hash_t  *hTxn;
    hTxn = (hash_t*)  malloc (sizeof(hash_t));
    hash_init(hTxn,0);

    PutField_CString(hTxn,"psp_channel_code","TPM");
printf("Data: [%s]\n",argv[1]);
    PutField_CString(hTxn,"auth_data",argv[1]);
//printf("Key: [1ee1e4dae5a83c313789681214eff2ca]\n");
    //PutField_CString(hTxn,"psp_key","1ee1e4dae5a83c313789681214eff2ca");
printf("Key: [8934e7d15453e97507ef794cf7b0519d]\n");
    PutField_CString(hTxn,"psp_key","8934e7d15453e97507ef794cf7b0519d");

    BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMD5Sign");
    iRet = (unsigned long)(*BOObjPtr)(hTxn,hTxn);
printf("iRet = [%d],\n",iRet);

	if(GetField_CString(hTxn,"sign",&csTmp)){
printf("OutSign: [%s]\n",csTmp);
	}
*/
    FREE_ME(csKey);
    FREE_ME(csData);
    FREE_ME(csMac);
//    FREE_ME(hTxn);
    return SUCCESS;    

}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}


int GenerateMD5Mac(const unsigned char* KEY,const unsigned char* DATA, const int DATA_LEN,unsigned char* OUT)
{
        int             iRet = PD_OK;
        char            *csBuf;

        csBuf = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);

        OUT[0]='\0';
        csBuf[0]='\0';

        strcat((char*)OUT,(char*)DATA);
        strcat((char*)OUT,(char*)KEY);

printf("Msg = [%s]\n",OUT);
         md5sum((const char*)OUT,strlen((const char*)OUT),csBuf);
printf("md5sum = [%s]\n",csBuf);
        OUT[0] = '\0';

        U2L(csBuf,strlen(csBuf),(char*)OUT);
printf("U2L = [%s]\n",OUT);

        FREE_ME(csBuf);
        return iRet;
}


int Verify51EpaySign(const unsigned char* csClearSig,const unsigned char* csAuthData)
{
        int     iRet = PD_OK;
        char    csRsaPemPath[PD_MAX_FILE_LEN + 1];
        unsigned char   *csSig;
        int     iSigLen;
printf("BOSecurity:Verify51EpaySign()\n");

/* auth_data */
printf("Verify51EpaySign() auth_data= [%s]\n",csAuthData);

/* sign */
printf("Verify51EpaySign() sign= [%s]\n",csClearSig);

/* publiccert */
//printf("Verify51EpaySign publiccert = [%s]\n","00010415.crt.pem");
printf("Verify51EpaySign publiccert = [%s]\n","00010412.crt");
//	sprintf(csRsaPemPath,"%s/%s",getenv("CERT_PATH"),"00010415.crt.pem");
	sprintf(csRsaPemPath,"%s/%s",getenv("CERT_PATH"),"00010412.crt");
printf("Verify51EpaySign publiccertpath = [%s]\n",csRsaPemPath);


        if (iRet == PD_OK) {
printf("Verify51EpaySign() try to verify [%s]\n\n",csClearSig);
                csSig = (unsigned char*) malloc (PD_MAX_BUFFER);
                iSigLen = base64_decode((char*)csClearSig,csSig,PD_MAX_BUFFER);
printf("Verify51EpaySign() try to verify SignLen=[%d]\n",iSigLen);
                iRet = sha1rsa_verify(csRsaPemPath,(const char*)csAuthData,csSig,iSigLen);
                FREE_ME(csSig);
        }
printf("Verify51EpaySign() iRet = [%d]\n",iRet);

        return iRet;
}
