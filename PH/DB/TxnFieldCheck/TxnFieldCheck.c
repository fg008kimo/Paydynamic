
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
    "TxnFieldCheck.pc"
};


static unsigned int sqlctx = 5413955;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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

 static char *sq0001 = 
"select tfc_field_tag , tfc_mandatory , tfc_only_digit , tfc_min_len , tfc_m\
ax_len , tfc_ref_def_table , tfc_ref_def_field from txn_field_check Where tfc\
_channel_code = :b0 And tfc_txn_code = :b1            ";

 static char *sq0002 = 
"select tfc_mandatory , tfc_only_digit , tfc_min_len , tfc_max_len , tfc_ref\
_def_table , tfc_ref_def_field from txn_field_check Where tfc_channel_code = \
:b0 And tfc_txn_code = :b1 And tfc_field_tag = :b2            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,206,0,9,84,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,86,0,0,7,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,
71,0,0,1,0,0,15,145,0,0,0,0,0,1,0,
86,0,0,1,0,0,15,154,0,0,0,0,0,1,0,
101,0,0,2,214,0,9,213,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
128,0,0,2,0,0,13,215,0,0,6,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,
167,0,0,2,0,0,15,262,0,0,0,0,0,1,0,
182,0,0,2,0,0,15,271,0,0,0,0,0,1,0,
197,0,0,3,0,0,17,307,0,0,1,1,0,1,0,1,9,0,0,
216,0,0,3,0,0,45,310,0,0,1,1,0,1,0,1,9,0,0,
235,0,0,3,0,0,13,316,0,0,1,0,0,1,0,2,3,0,0,
254,0,0,3,0,0,15,323,0,0,0,0,0,1,0,
269,0,0,3,0,0,15,332,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/11/21              LokMan Chow
Add FindParamByFieldTag				   2019/04/24		   Elvis Wong	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "TxnFieldCheck.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void TxnFieldCheck(char    cdebug)
{
        cDebug = cdebug;
}


int FindParam(const char* csChannelCode,
              const char* csTxnCode,
	      recordset_t* myRec)
{
	int iRet = PD_OK;
	hash_t *myHash;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;


		/* varchar v_field_tag[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_field_tag;

		/* varchar v_ref_def_table[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_ref_def_table;

		/* varchar v_ref_def_field[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_ref_def_field;

		int	v_mandatory;
		int	v_only_digit;
		int	v_min_len;
		int	v_max_len;

                short   ind_field_tag = -1;
                short   ind_ref_def_table = -1;
                short   ind_ref_def_field = -1;
                short   ind_mandatory = -1;
                short   ind_only_digit = -1;
                short   ind_min_len = -1;
                short   ind_max_len = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("FindParam: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("FindParam: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 


	/* EXEC SQL DECLARE c_cursor_find CURSOR FOR
		 select tfc_field_tag,
			tfc_mandatory,
			tfc_only_digit,
			tfc_min_len,
			tfc_max_len,
			tfc_ref_def_table,
			tfc_ref_def_field
                   from txn_field_check
                  Where tfc_channel_code = :hv_channel_code
                    And tfc_txn_code = :hv_txn_code; */ 


	/* EXEC SQL OPEN c_cursor_find; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_find
                INTO
                        :v_field_tag:ind_field_tag,
			:v_mandatory:ind_mandatory,
			:v_only_digit:ind_only_digit,
			:v_min_len:ind_min_len,
			:v_max_len:ind_max_len,
			:v_ref_def_table:ind_ref_def_table,
			:v_ref_def_field:ind_ref_def_field; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )28;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_field_tag;
                sqlstm.sqhstl[0] = (unsigned long )28;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_field_tag;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_mandatory;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_mandatory;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_only_digit;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_only_digit;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_min_len;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_min_len;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_max_len;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_max_len;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ref_def_table;
                sqlstm.sqhstl[5] = (unsigned long )259;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ref_def_table;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_ref_def_field;
                sqlstm.sqhstl[6] = (unsigned long )259;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_ref_def_field;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto find_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

		if (ind_field_tag >= 0) {
                        v_field_tag.arr[v_field_tag.len] ='\0';
                        PutField_CString(myHash,"field_tag",(const char*)v_field_tag.arr);
DEBUGLOG((" field_tag = [%s]\n",v_field_tag.arr));
                }

		if (ind_mandatory >= 0) {
                        PutField_Int(myHash,"mandatory",v_mandatory);
DEBUGLOG((" mandatory = [%d]\n",v_mandatory));
                }

		if (ind_only_digit >= 0) {
                        PutField_Int(myHash,"only_digit",v_only_digit);
DEBUGLOG((" only_digit = [%d]\n",v_only_digit));
                }

		if (ind_min_len >= 0) {
                        PutField_Int(myHash,"min_len",v_min_len);
DEBUGLOG((" min_len = [%d]\n",v_min_len));
                }

		if (ind_max_len >= 0) {
                        PutField_Int(myHash,"max_len",v_max_len);
DEBUGLOG((" max_len = [%d]\n",v_max_len));
                }

		if (ind_ref_def_table >= 0) {
                        v_ref_def_table.arr[v_ref_def_table.len] ='\0';
                        PutField_CString(myHash,"ref_def_table",(const char*)v_ref_def_table.arr);
DEBUGLOG((" ref_def_table = [%s]\n",v_ref_def_table.arr));
                }

		if (ind_ref_def_field >= 0) {
                        v_ref_def_field.arr[v_ref_def_field.len] ='\0';
                        PutField_CString(myHash,"ref_def_field",(const char*)v_ref_def_field.arr);
DEBUGLOG((" ref_def_field = [%s]\n",v_ref_def_field.arr));
                }

                RecordSet_Add(myRec,myHash);
	
	}while(PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_find; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )71;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



DEBUGLOG(("FindParam Normal Exit iRet[%d]\n",iRet));
        return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_find; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )86;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int FindParamByFieldTag(const char* csChannelCode,
              		const char* csTxnCode,
			const char* csFieldTag,
	      		hash_t* hRec)
{
	int iRet = PD_OK;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO findbyfield_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;

		/* varchar hv_field_tag[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } hv_field_tag;


		/* varchar v_ref_def_table[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_ref_def_table;

		/* varchar v_ref_def_field[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_ref_def_field;

		int	v_mandatory;
		int	v_only_digit;
		int	v_min_len;
		int	v_max_len;

                short   ind_ref_def_table = -1;
                short   ind_ref_def_field = -1;
                short   ind_mandatory = -1;
                short   ind_only_digit = -1;
                short   ind_min_len = -1;
                short   ind_max_len = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("FindParamByFieldTag: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("FindParamByFieldTag: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 

	hv_field_tag.len = strlen(csFieldTag);
        memcpy(hv_field_tag.arr,csFieldTag,hv_field_tag.len);
DEBUGLOG(("FindParamByFieldTag: field tag = [%.*s][%d]\n",hv_field_tag.len,hv_field_tag.arr,hv_field_tag.len));

	/* EXEC SQL DECLARE c_cursor_findbyfield CURSOR FOR
		 select tfc_mandatory,
			tfc_only_digit,
			tfc_min_len,
			tfc_max_len,
			tfc_ref_def_table,
			tfc_ref_def_field
                   from txn_field_check
                  Where tfc_channel_code = :hv_channel_code
                    And tfc_txn_code = :hv_txn_code
                    And tfc_field_tag = :hv_field_tag; */ 


	/* EXEC SQL OPEN c_cursor_findbyfield; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )101;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_field_tag;
 sqlstm.sqhstl[2] = (unsigned long )28;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto findbyfield_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_findbyfield
                INTO
			:v_mandatory:ind_mandatory,
			:v_only_digit:ind_only_digit,
			:v_min_len:ind_min_len,
			:v_max_len:ind_max_len,
			:v_ref_def_table:ind_ref_def_table,
			:v_ref_def_field:ind_ref_def_field; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )128;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_mandatory;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_mandatory;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_only_digit;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_only_digit;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_min_len;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_min_len;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_max_len;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_max_len;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_ref_def_table;
                sqlstm.sqhstl[4] = (unsigned long )259;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_ref_def_table;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ref_def_field;
                sqlstm.sqhstl[5] = (unsigned long )259;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ref_def_field;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto findbyfield_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_mandatory >= 0) {
                        PutField_Int(hRec,"mandatory",v_mandatory);
DEBUGLOG((" mandatory = [%d]\n",v_mandatory));
                }

		if (ind_only_digit >= 0) {
                        PutField_Int(hRec,"only_digit",v_only_digit);
DEBUGLOG((" only_digit = [%d]\n",v_only_digit));
                }

		if (ind_min_len >= 0) {
                        PutField_Int(hRec,"min_len",v_min_len);
DEBUGLOG((" min_len = [%d]\n",v_min_len));
                }

		if (ind_max_len >= 0) {
                        PutField_Int(hRec,"max_len",v_max_len);
DEBUGLOG((" max_len = [%d]\n",v_max_len));
                }

		if (ind_ref_def_table >= 0) {
                        v_ref_def_table.arr[v_ref_def_table.len] ='\0';
                        PutField_CString(hRec,"ref_def_table",(const char*)v_ref_def_table.arr);
DEBUGLOG((" ref_def_table = [%s]\n",v_ref_def_table.arr));
                }

		if (ind_ref_def_field >= 0) {
                        v_ref_def_field.arr[v_ref_def_field.len] ='\0';
                        PutField_CString(hRec,"ref_def_field",(const char*)v_ref_def_field.arr);
DEBUGLOG((" ref_def_field = [%s]\n",v_ref_def_field.arr));
                }

	}while(PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_findbyfield; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )167;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findbyfield_error;
}



DEBUGLOG(("FindParamByFieldTag Normal Exit iRet[%d]\n",iRet));
        return iRet;

findbyfield_error:
DEBUGLOG(("findbyfield_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_findbyfield; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )182;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int ChkDefReference(const char* csParam, const char* csRefTable, const char* csRefField)
{
        int     iRet = PD_OK;
	char*   csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO check_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

		/* varchar		hv_param[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_param;


		int	v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("ChkDefReference\n"));

	hv_param.len = strlen(csParam);
	memcpy(hv_param.arr, csParam, hv_param.len);

	csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"select count(1) from ");
	strcat((char*)hv_dynstmt.arr, csRefTable);
	strcat((char*)hv_dynstmt.arr, " where ");
	strcat((char*)hv_dynstmt.arr, csRefField);
	strcat((char*)hv_dynstmt.arr, " = :v1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len, hv_dynstmt.arr));
	
	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )197;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto check_error;
}


        /* EXEC SQL DECLARE C CURSOR FOR PS; */ 


	/* EXEC SQL OPEN C USING :hv_param; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )216;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_param;
 sqlstm.sqhstl[0] = (unsigned long )258;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto check_error;
}


DEBUGLOG((" v1 = [%.*s]\n", hv_param.len, hv_param.arr));

	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

	for (;;)
	{
		/* EXEC SQL FETCH C INTO :v_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )235;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto check_error;
}


	}

	if(v_cnt <= 0){
		iRet = PD_ERR;
	}

	/* EXEC SQL CLOSE C; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )254;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto check_error;
}



DEBUGLOG(("ChkDefReference Normal Exit[%d]\n",iRet));
        return iRet;

check_error:
DEBUGLOG(("check_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE C; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )269;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

