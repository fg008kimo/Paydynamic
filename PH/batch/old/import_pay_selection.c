
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "import_pay_selection.pc"
};


static unsigned int sqlctx = 636821915;


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
5,0,0,1,83,0,6,204,0,0,1,1,0,1,0,2,3,0,0,
24,0,0,2,0,0,32,221,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/12/15              LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "batchcommon.h"
#include "TxnSeq.h"
#include "import_pay_selection.h"
#include "internal.h"

char    cDebug;
char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char	csBatchId[PD_TXN_SEQ_LEN+1];

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *fin);
int	insertDetails(const int iSeqNum, char (*csDeList)[IMPORT_FIELD_LEN]);
int	GetSeqNum();

OBJPTR(DB);

int batch_init(int argc, char* argv[])
{
    if (argc < 2) {
        printf("usage:  -f inputfile\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
        FILE    *fin;
        int     iRet;
        
        iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS){
		printf("usage:  -f inputfile\n");
                return (iRet);
	}

        fin = fopen(cs_inputfile,"r");
        
        if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
                return FAILURE;
        }

        iRet = parse_file(fin);
        fclose(fin);

DEBUGLOG(("iRet = [%d]\n",iRet));

        return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int	parse_file(FILE *fin) 
{
	int	iSeqNum = 0;
	int	iRet = SUCCESS;
	char	csList[IMPORT_MAX_FILE][IMPORT_FIELD_LEN];
	char    cs_input_buf[PD_MAX_BUFFER +1];;
	char* p;
	int	iCount = 0;
	int	iRecord = 0;

	iSeqNum = GetSeqNum();

	while( fgets(cs_input_buf, PD_MAX_BUFFER, fin) != NULL ){

		if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

		if(cs_input_buf[strlen(cs_input_buf) - 1] == 0x00)
			continue;

		strcpy(cs_input_buf,TrimAllChar(cs_input_buf,strlen(cs_input_buf),0xEF));
		strcpy(cs_input_buf,TrimAllChar(cs_input_buf,strlen(cs_input_buf),0xBB));
		strcpy(cs_input_buf,TrimAllChar(cs_input_buf,strlen(cs_input_buf),0xBF));
		

		iCount = 0;

		p = mystrtok(cs_input_buf,",");
		if (p == NULL) {
			return FAILURE;
		}
		iRecord++;

		if(p[strlen(p) - 1] == 0x0D)
			p[strlen(p) - 1] = '\0';
		strcpy(csList[iCount],p);
		iCount++;

		while ( (p = mystrtok(NULL,",")) != NULL) {
			if(p[strlen(p) - 1] == 0x0D)
				p[strlen(p) - 1] = '\0';
			strcpy(csList[iCount],p);
			iCount++;
		}

		iSeqNum ++;

		iRet = insertDetails(iSeqNum,csList);

		//for (i=0; i < iCount; i++)
//DEBUGLOG(("Record [%d][%d] = [%s]\n",iRecord,i,csList[i]));


/*
DEBUGLOG(("Record [%d] seq_num = [%s]\n",iRecord,csList[IDX_DETAIL_SEQ_NUM]));
DEBUGLOG(("Record [%d] merchant_ref = [%s]\n",iRecord,csList[IDX_DETAIL_MERCHANT_REF]));
DEBUGLOG(("Record [%d] country = [%s]\n",iRecord,csList[IDX_DETAIL_COUNTRY]));
DEBUGLOG(("Record [%d] ID = [%s]\n",iRecord,csList[IDX_DETAIL_ID]));
DEBUGLOG(("Record [%d] acc no = [%s]\n",iRecord,csList[IDX_DETAIL_ACC_NO]));
DEBUGLOG(("Record [%d] acc name = [%s][%d]\n",iRecord,csList[IDX_DETAIL_ACC_NAME],strlen(csList[IDX_DETAIL_ACC_NAME])));
DEBUGLOG(("Record [%d] bank code = [%s]\n",iRecord,csList[IDX_DETAIL_BANK_CODE]));
DEBUGLOG(("Record [%d] bank name = [%s][%d]\n",iRecord,csList[IDX_DETAIL_BANK_NAME],strlen(csList[IDX_DETAIL_BANK_NAME])));
DEBUGLOG(("Record [%d] branch name = [%s][%d]\n",iRecord,csList[IDX_DETAIL_BRANCH_NAME],strlen(csList[IDX_DETAIL_BRANCH_NAME])));
DEBUGLOG(("Record [%d] phone no= [%s]\n",iRecord,csList[IDX_DETAIL_PHONE_NO]));
DEBUGLOG(("Record [%d] Province = [%s]\n",iRecord,csList[IDX_DETAIL_PROVINCE]));
DEBUGLOG(("Record [%d] city = [%s]\n",iRecord,csList[IDX_DETAIL_CITY]));
DEBUGLOG(("Record [%d] amount = [%s]\n",iRecord,csList[IDX_DETAIL_AMOUNT]));
DEBUGLOG(("Record [%d] PAYOUT_CCy = [%s]\n",iRecord,csList[IDX_DETAIL_PAYOUT_CCY]));
DEBUGLOG(("Record [%d] DST_CCY = [%s]\n",iRecord,csList[IDX_DETAIL_DST_CCY]));
DEBUGLOG(("Record [%d] MAC = [%s]\n",iRecord,csList[IDX_DETAIL_MAC]));
*/

	
	}

	
	return iRet;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_inputfile,"");

        //while ((c = getopt(argc,argv,"f:")) != EOF && c != 0xff) {
        while ((c = getopt(argc,argv,"f:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_inputfile,""))
                return FAILURE;

        return SUCCESS;
}

int GetSeqNum()
{
	int iResult = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int	v_seq_num;

                short	ind_seq_num=-1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL EXECUTE
                BEGIN
                        SELECT  max(seq_num) 
                        INTO    :v_seq_num:ind_seq_num
                        FROM    pay_selection;
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin SELECT max ( seq_num ) INTO :v_seq_num:ind_seq\
_num FROM pay_selection ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_seq_num;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if(ind_seq_num>=0)
		iResult = v_seq_num;

	return iResult;

sql_error:
    DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )24;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return 0;
}

int insertDetails(const int iSeqNum,char (*csDeList)[IMPORT_FIELD_LEN])
{
	int iRet = SUCCESS;

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);


	PutField_CString(hRec,"file_seq", csDeList[IDX_DETAIL_SEQ_NUM]);
	PutField_Int(hRec,"seq_num", iSeqNum);
	PutField_CString(hRec,"merchant_ref",csDeList[IDX_DETAIL_MERCHANT_REF]);
	PutField_CString(hRec,"account_num",csDeList[IDX_DETAIL_ACC_NO]);
	PutField_CString(hRec,"account_name",csDeList[IDX_DETAIL_ACC_NAME]);
	PutField_CString(hRec,"bank_name",csDeList[IDX_DETAIL_BANK_NAME]);
	PutField_CString(hRec,"branch",csDeList[IDX_DETAIL_BRANCH_NAME]);
	PutField_CString(hRec,"province",csDeList[IDX_DETAIL_PROVINCE]);
	PutField_CString(hRec,"city",csDeList[IDX_DETAIL_CITY]);
	PutField_CString(hRec,"payout_currency",csDeList[IDX_DETAIL_PAYOUT_CCY]);
	PutField_CString(hRec,"amount",csDeList[IDX_DETAIL_AMOUNT]);



	DBObjPtr = CreateObj(DBPtr,"DBPaySelection","Add");
	if ((unsigned long int)(*DBObjPtr)(hRec) == PD_OK){
	}
	else{
DEBUGLOG(("Add Pay Selection Failed [%s] [%s]\n",csDeList[IDX_DETAIL_SEQ_NUM],csDeList[IDX_DETAIL_MERCHANT_REF]));
		return FAILURE;
	}
	return iRet;
}
