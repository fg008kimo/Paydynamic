
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
    "PspParamCheck.pc"
};


static unsigned int sqlctx = 5251907;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
5,0,0,1,188,0,4,61,0,0,6,1,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,9,0,
0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/03/09              [CLY]
add 2 new fields				   2020/06/16		   [MSN]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PspParamCheck.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void PspParamCheck(char cdebug){
	cDebug = cdebug;
}

int GetDetail(const char* csPspChannel, hash_t *hOut)
{

	int iRet = PD_NOT_FOUND;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO get_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_psp_channel[PD_PSP_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_channel;

		int             v_amt_in_dec;
		int             v_txn_date_present;
		int		v_verify_sign;
		int		v_init_req;
		int		v_qr_code;
	
		short		ind_amt_in_dec = -1;
		short		ind_txn_date_present = -1;
		short		ind_verify_sign = -1;
		short		ind_init_req = -1;
		short		ind_qr_code = -1;
	/* EXEC SQL END DECLARE SECTION; */ 



/* psp_channel */
	hv_psp_channel.len = strlen(csPspChannel);
	memcpy(hv_psp_channel.arr, csPspChannel, hv_psp_channel.len);
DEBUGLOG(("GetDetail: csPspChannel = [%.*s]\n", hv_psp_channel.len, hv_psp_channel.arr));

	/* EXEC SQL SELECT pc_amt_in_decimal, 
			pc_txn_date_present, 
			pc_verify_sign,
			pc_init_req,
			pc_qr_code
 		INTO	:v_amt_in_dec:ind_amt_in_dec,
			:v_txn_date_present:ind_txn_date_present,
			:v_verify_sign:ind_verify_sign,
			:v_init_req:ind_init_req,
			:v_qr_code:ind_qr_code 
		FROM psp_param_check
		WHERE pc_psp_channel = :hv_psp_channel; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select pc_amt_in_decimal , pc_txn_date_present , pc_verify_\
sign , pc_init_req , pc_qr_code INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 , :b8:\
b9 FROM psp_param_check WHERE pc_psp_channel = :b10 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_amt_in_dec;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_amt_in_dec;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_date_present;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_date_present;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_verify_sign;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_verify_sign;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_init_req;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_init_req;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_qr_code;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_qr_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_channel;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto get_detail_error;
}



	

/* amt_in_dec */
	if (ind_amt_in_dec >= 0)
	{
DEBUGLOG(("amt_in_decimal = [%d]\n", v_amt_in_dec));
		PutField_Int(hOut, "amt_in_dec", v_amt_in_dec);
		iRet = PD_FOUND;
	}

/* txn_date_present */
	if (ind_txn_date_present >= 0)
	{
DEBUGLOG(("txn_date_present = [%d]\n", v_txn_date_present));
		PutField_Int(hOut, "txn_date_present", v_txn_date_present);
                iRet = PD_FOUND;
        }

/* verify_sign */	
	if (ind_verify_sign >= 0)
	{
DEBUGLOG(("verify_sign = [%d]\n", v_verify_sign));
		PutField_Int(hOut, "verify_sign", v_verify_sign);
                iRet = PD_FOUND;
        }

/* init_req */	
	if (ind_init_req >= 0)
	{
DEBUGLOG(("init_req = [%d]\n", v_init_req));
		PutField_Int(hOut, "init_req", v_init_req);
                iRet = PD_FOUND;
        }

/* qr_code */	
	if (ind_qr_code >= 0)
	{
DEBUGLOG(("qr_code = [%d]\n", v_qr_code));
		PutField_Int(hOut, "qr_code", v_qr_code);
                iRet = PD_FOUND;
        }

DEBUGLOG(("GetDetail Normal Exit\n"));
	return iRet;


get_detail_error:
DEBUGLOG(("get_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspParamCheck_GetDetail: SP_INTERNAL_ERR\n");
/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}





