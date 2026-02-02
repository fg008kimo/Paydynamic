
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "alp_download.pc"
};


static unsigned int sqlctx = 2361515;


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
#include "alp_download.h"
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"


OBJPTR(DB);
OBJPTR(BO);

char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_txn(const char* csDate, FILE *fp);
int process_CURL(const char *csPspMerchId, const char *csDate, const char *csMac, FILE *fp);
struct string
{
	char *ptr;
	size_t len;
};

void init_string(struct string *s)
{
	s->len = 0;
	s->ptr = malloc(s->len+1);
	if (s->ptr == NULL)
	{
		fprintf(stderr, "malloc() failed\n");
		exit(EXIT_FAILURE);
	}
	s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
	size_t new_len = s->len + size*nmemb;
	s->ptr = realloc(s->ptr, new_len+1);
	if (s->ptr == NULL)
	{
		fprintf(stderr, "realloc() failed\n");
		exit(EXIT_FAILURE);
	}
	memcpy(s->ptr+s->len, ptr, size*nmemb);
	s->ptr[new_len] = '\0';
	s->len = new_len;

	return size*nmemb;
}

int process_CURL(const char *csPspMerchId, const char *csDate, const char *csMac, FILE *fp)
{
	int	iRet=PD_OK;
        CURL *curl;
        //CURLcode res;
	char csReq[REQ_STRING_LEN];
	char csBuf[1024];
	char	*csDomain;
	hash_t	*hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec,0);

	DBObjPtr = CreateObj(DBPtr,"DBPspUrl","GetPspUrl");
	if (!(*DBObjPtr)(cs_psp_id,hRec)) {
		if (GetField_CString(hRec,"url",&csDomain)) {
DEBUGLOG(("process_CURL: get psp_url = [%s]\n",csDomain));
		}
	}

	FREE_ME(hRec);
	/*testing*/
        snprintf(csReq, REQ_STRING_LEN, "%s%s",REQ_DOMAIN,REQ_DETAIL);
        //snprintf(csReq, REQ_STRING_LEN, "%s%s",csDomain,REQ_DETAIL);
DEBUGLOG(("process_CURL: URL string [%s]\n",csReq));
	sprintf(csBuf,"mchtCd=%s&settleDate=%s&signMsg=%s",csPspMerchId,csDate,csMac);
DEBUGLOG(("process_CURL: post string [%s]\n",csBuf));

	curl = curl_easy_init();
        if(curl)
        {
                struct string sBuffer;
                init_string(&sBuffer);

                curl_easy_setopt(curl, CURLOPT_URL,csReq);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sBuffer);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS,csBuf);
                iRet = curl_easy_perform(curl);
DEBUGLOG(("Send DATA  Result = [%d]\n",iRet));
                if (iRet == PD_OK) {
DEBUGLOG(("Receive DATA= [%s]\n", sBuffer.ptr));
			fprintf(fp,"%s",sBuffer.ptr);
                }
                curl_easy_cleanup(curl);

		free(sBuffer.ptr);
	}
	else
	{
		DEBUGLOG(("Init CURL failed\n"));
		return FAILURE;
	}

	return SUCCESS;
}


int batch_init(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: -d Date -o Output File -p PspID\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet;
	FILE    *fp;
	char	csDate[PD_DATE_LEN+3];

	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
		printf("usage:  -o Output File -d Date -p PspID\n");
		return (iRet);
	}

	fp = fopen(cs_outputfile,"w");
	if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outputfile));
		return FAILURE;
	}

	sprintf(csDate,"%.*s-%.*s-%.*s",PD_YYYY_LEN,cs_date,PD_MM_LEN,&cs_date[PD_YYYY_LEN],PD_DD_LEN,&cs_date[PD_YYYYMM_LEN]);

	iRet = process_txn(csDate,fp);
	fclose(fp);
	return iRet;


}

int process_txn(const char* csDate, FILE *fp)
{
	int	iRet = PD_OK;
	hash_t	*hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec,0);
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
	char	*csPspMerchId; 
	char	*csKey;
	char	*csData;
	char    *csMac;
	csMac = (char*) malloc (PD_TMP_MSG_BUF_LEN  +1);
	csData= (char*) malloc (PD_VALUE_LEN  +1);

	csData[0]='\0';
DEBUGLOG(("process_txn\n"));
	
	DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
	if ((*DBObjPtr)(cs_psp_id,hRec) == PD_OK) {
		if(GetField_CString(hRec,"psp_merchant_id",&csPspMerchId)){
DEBUGLOG(("process_txn: get psp_merchant_id [%s]\n",csPspMerchId));
			/*testing*/
			strcpy(csPspMerchId,"100020091218001");
			strcat(csData,(char*)csPspMerchId);
		}
	}
	else{
DEBUGLOG(("process_txn: get psp_merchant_id failed!!!\n"));
		iRet =PD_ERR;
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBPspKeys","GetPspKey");
		if (!(*DBObjPtr)(cs_psp_id,PD_PTK_KEY_NAME,rRecordSet)) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if(GetField_CString(hRec,"key_value",&csKey)){
DEBUGLOG(("process_txn: get psp_key [%s]\n",csKey));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
DEBUGLOG(("process_txn: get psp_key failed!!!\n"));
			iRet =PD_ERR;
		}
	}

	if(iRet==PD_OK){
		strcat(csData,(char*)csDate);
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMD5Mac");
		iRet = (unsigned long)(*BOObjPtr)((const unsigned char*)csKey,(const unsigned char*)csData,strlen(csData),(unsigned char*)csMac);
	}

	if(iRet==PD_OK){
		iRet = process_CURL(csPspMerchId,csDate,csMac,fp);
	}

	FREE_ME(csData);
	FREE_ME(csMac);
	FREE_ME(hRec);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_outputfile,"");
        strcpy(cs_psp_id,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"o:p:d:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_outputfile,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}
