
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "test_dirk_GBK.pc"
};


static unsigned int sqlctx = 5249587;


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
#include "dbutility.h"

#include "SystemParameter.h"

OBJPTR(DB);
OBJPTR(BO);
char    cDebug = 'Y';

int     parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{

	int     iRet = SUCCESS;

	FILE    *fp;
	char	*csTmp;

	if(iRet==PD_OK) {
		fp = fopen("/home/phuser/tmpfile_GBK.txt", "w");
		if (fp == NULL) {
			iRet=1000;
		}
	}

	//hash_t *hTmp = (hash_t*) malloc (sizeof(hash_t));
	//hash_init(hTmp,0);
	hash_t *hTmp;

	recordset_t *rRS = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRS,0);

	DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileDT","GetDetailByGenId");
	if ((unsigned long)((*DBObjPtr)("P000000000572711",rRS)) == PD_OK) {

		hTmp = RecordSet_GetFirst(rRS);

		if (iRet==PD_OK) {
			fprintf(fp, code_convert("utf-8","gb2312","注意:1、代付数据从第3行(包含)开始；2、数据之间以\"|\"分割 3、一条记录占一行，否则无效 4、请勿删除该模板原有的这两行文字，否则您的转账数据会缺失前两条记录\n"));
			fprintf(fp, code_convert("utf-8","gb2312","*收款方姓名|*收款方银行账号|*开户行所在省|*开户行所在市|*开户行名称|*收款方银行名称|*金额(元为单位)|*商户订单号(以日期开头)|*用途(不超过20字)|\n"));

/*
			if (GetField_CString(hTmp,"name",&csTmp)) {
				fprintf(fp, "1)%s\n", csTmp);
				fprintf(fp, "2)%s\n", code_convert("utf-8","gb2312",csTmp));
				fprintf(fp, "3)%s\n", code_convert("utf-8","gb2312","陳大文6"));
			}
*/

			PutField_CString(hTmp,"name","陈大文6");
			PutField_CString(hTmp,"test","由 Google 提供");

			while (hTmp) {

				if(GetField_CString(hTmp,"account_name",&csTmp)) {
					fprintf(fp, "1)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk",csTmp));
					fprintf(fp, "2)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk//IGNORE",csTmp));
					fprintf(fp, "3)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312",csTmp));
					fprintf(fp, "4)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312//IGNORE",csTmp));
				}

				if(GetField_CString(hTmp,"bank_name",&csTmp)) {
					fprintf(fp, "1)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk",csTmp));
					fprintf(fp, "2)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk//IGNORE",csTmp));
					fprintf(fp, "3)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312",csTmp));
					fprintf(fp, "4)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312//IGNORE",csTmp));
				}

				if (GetField_CString(hTmp,"name",&csTmp)) {
					fprintf(fp, "1)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk",csTmp));
					fprintf(fp, "2)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk//IGNORE",csTmp));
					fprintf(fp, "3)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312",csTmp));
					fprintf(fp, "4)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312//IGNORE",csTmp));
				}

				if (GetField_CString(hTmp,"test",&csTmp)) {
					fprintf(fp, "1)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk",csTmp));
					fprintf(fp, "2)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gbk//IGNORE",csTmp));
					fprintf(fp, "3)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312",csTmp));
					fprintf(fp, "4)%.*s\n", (int)strlen(csTmp), code_convert("utf-8","gb2312//IGNORE",csTmp));
				}

				hTmp = RecordSet_GetNext(rRS);
			}

		}

	}

	fclose(fp);

//	hash_destroy(hTmp);
	recordset_destroy(rRS);
//	FREE_ME(hTmp);
	FREE_ME(rRS);

DEBUGLOG(("batch_proc Normal Exit() iRet = [%d]\n",iRet));
        return iRet;

}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        return SUCCESS;
}
