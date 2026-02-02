
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
    "test_andy.pc"
};


static unsigned int sqlctx = 327715;


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
#include <sqlca.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char     cDebug = 'Y';
char            cType;
char            csFunc[PD_TAG_LEN] = "";
char            csRemark[PD_REMARK_LEN] = "";
char            csBankCode[PD_BANK_CODE_LEN] = "";
double          dMin_amt = 0.0;
int             iSupport_po = -1;
int		bool_m = 0,bool_s = 0,bool_t = 0;

OBJPTR(DB);

int getByBankCode(){
printf("Call TestAndy: GetByBankCode [%s]\n", csBankCode);

        char    cTmp;
        char    * csTmp = NULL;
        double  dTmp = 0.0;
        int     iTmp = 0;
        hash_t  * hOut;
        hOut = (hash_t *)malloc(sizeof(hash_t));
        hash_init(hOut, 0);

        DBObjPtr = CreateObj(DBPtr, "DBTestAndy", "GetByBankCode");

        if ((unsigned long)(DBObjPtr)(csBankCode, hOut) == PD_FOUND){
                if (GetField_Char(hOut, "type", &cTmp))
printf("Type = [%c]\n", cTmp);

                if (GetField_Int(hOut, "support_po", &iTmp))
printf("Support_po = [%d]\n", iTmp);

                if (GetField_Double(hOut, "min_amt", &dTmp))
printf("Min_amt = [%lf]\n", dTmp);

                if (GetField_CString(hOut, "remark", &csTmp))
printf("Remark = [%s]\n", csTmp);

                FREE_ME(hOut);
                return PD_OK;
        }

        FREE_ME(hOut);
        return PD_NOT_FOUND;

}

static int parse_arg(int argc, char ** argv)
{
printf("BANK_CODE [%s], TYPE [%c], SUPPORT_PO [%d], MIN_AMT [%lf], REMARK [%s], FUNCTION [%s]\n", csBankCode, cType, iSupport_po, dMin_amt, csRemark, csFunc);
        char c;

        while ((c = getopt(argc, argv, "b:t:s:m:r:f:")) != EOF)
        {
                switch (c)
                {
                        case 'b':
                                strcpy(csBankCode, optarg);
                                break;

                        case 't':
                                cType = optarg[0];
                                bool_t = 1;
				break;

                        case 's':
                                iSupport_po = atoi(optarg);
				bool_s = 1;
                                break;

                        case 'm':
                                sscanf(optarg, "%lf", &dMin_amt);
				bool_m = 1;
                                break;

                        case 'r':
                                strcpy(csRemark, optarg);
                                break;

                        case 'f':
                                strcpy(csFunc, optarg);
                                break;

                        default:
                                return PD_ERR;
                }
        }
        if(!strcmp(csFunc, "")){
printf("Fail in parsing arguments\n");
		return PD_ERR;
        }else if( (!strcmp(csFunc,"GetByBankCode") || !strcmp(csFunc,"Update") ) && !strcmp(csBankCode, "")){
printf("Fail in parsing arguments\n");
		return PD_ERR;
        }else if(!strcmp(csFunc,"GetByType") && !bool_t){
printf("Fail in parsing arguments\n");
		return PD_ERR;
        }


        return PD_OK;
}

int batch_init(int argc, char * argv[])
{
/*        if (argc < 7)
        {
printf("Usage: %s -b <BANK_CODE> -t <TYPE> -s <SUPPORT_PO> -m <MIN_AMT> -r <REMARK> -f <FUNCTION>\n", argv[0]);
                return FAILURE;
        }
        else    */
                return SUCCESS;
}

int batch_proc(int argc, char * argv[])
{
        if (parse_arg(argc, argv) != PD_OK)
        {
                exit(1);
        }
        int     iRet = PD_OK;
        hash_t  * hIn;

        hIn = (hash_t *)malloc(sizeof(hash_t));
        hash_init(hIn, 0);


        PutField_CString(hIn, "bank_code", csBankCode);
	if(bool_t)
        	PutField_Char(hIn, "type", cType);
	if(iSupport_po>=0){
		if(bool_s)
			PutField_Int(hIn, "support_po", iSupport_po);
	}
	if(dMin_amt>=0){
		if(bool_m)
			PutField_Double(hIn, "min_amt", dMin_amt);
	}
	if(strcmp(csRemark,""))
		PutField_CString(hIn, "remark", csRemark);
        PutField_CString(hIn, "create_user", PD_UPDATE_USER);

	printf("Call TestAndy: %s\n", csFunc);

        DBObjPtr = CreateObj(DBPtr, "DBTestAndy", csFunc);


    if (!strcmp(csFunc, "Add") || !strcmp(csFunc, "Update")){
                iRet = (unsigned long)(DBObjPtr)(hIn);
        	getByBankCode();
	}else if(!strcmp(csFunc, "GetByBankCode")){
                iRet = getByBankCode();
        }else if(!strcmp(csFunc, "GetByType")){
printf("Call TestAndy: GetByType [%c]\n", cType);

                int             iCnt = 0;
                hash_t          * hRec;
                recordset_t     * rInfoSet;

                rInfoSet = (recordset_t *)malloc(sizeof(recordset_t));
                recordset_init(rInfoSet, 0);

                DBObjPtr = CreateObj(DBPtr, "DBTestAndy", "GetByType");

                if ((unsigned long)(DBObjPtr)(cType, rInfoSet) == PD_FOUND)
                {

                        char    * csTmp = NULL;
                        double  dTmp = 0.0;
                        int     iTmp = 0;
                        hRec = RecordSet_GetFirst(rInfoSet);

                        while (hRec)
                        {
                                if (GetField_CString(hRec, "bank_code", &csTmp))
printf("[%d] Bank_Code = [%s]\n", iCnt, csTmp);

                                if (GetField_Int(hRec, "support_po", &iTmp))
printf("[%d] Flag = [%d]\n", iCnt, iTmp);

                                if (GetField_Double(hRec, "min_amt", &dTmp))
printf("[%d] Min_amt = [%lf]\n", iCnt, dTmp);

                                if (GetField_CString(hRec, "remark", &csTmp))
printf("[%d] Remark = [%s]\n", iCnt, csTmp);

                                iCnt++;
                                hRec = RecordSet_GetNext(rInfoSet);
                        }
                }

                RecordSet_Destroy(rInfoSet);
                FREE_ME(rInfoSet);
        }
        else
        {
                iRet = PD_ERR;
printf("Invalid Function!!\n");
        }

printf("TestAndy: %s iRet = [%d]\n", csFunc, iRet);


        FREE_ME(hIn);


printf("batch_proc end\n");
        return iRet;
}

int batch_terminate(int argc, char * argv[])
{
        return SUCCESS;
}

