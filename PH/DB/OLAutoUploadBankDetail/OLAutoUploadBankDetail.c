
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
           char  filnam[26];
};
static struct sqlcxp sqlfpn =
{
    25,
    "OLAutoUploadBankDetail.pc"
};


static unsigned int sqlctx = 1709129173;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
5,0,0,0,0,0,56,144,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,203,0,6,145,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,
0,0,2,102,0,0,
67,0,0,0,0,0,13,181,0,0,17,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,2,3,0,0,
150,0,0,0,0,0,15,340,0,0,1,1,0,1,0,1,102,0,0,
169,0,0,0,0,0,78,341,0,0,1,1,0,1,0,3,102,0,0,
188,0,0,0,0,0,15,348,0,0,1,1,0,1,0,1,102,0,0,
207,0,0,0,0,0,78,349,0,0,1,1,0,1,0,3,102,0,0,
226,0,0,2,228,0,6,456,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/10/12              Elvis Wong
Add BANK/ACCT_DISABLED table update function  	   2018/01/25		   Ethan Yip
Add status_type in GetAutoUploadBankAccts	   2019/03/06	   	   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "OLAutoUploadBankDetail.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void OLAutoUploadBankDetail(char    cdebug)
{
        cDebug = cdebug;
}


int GetAutoUploadBankAccts(const hash_t* hRec, recordset_t* myRec)
{
	int     iCnt = 0;
	int     iBankCodeExclude = 0;
        char*   csAcctType = NULL;
        char*   csClientId = NULL;
        char*   csBankCodeList = NULL;
	char	csAllBankCode[PD_BANK_CODE_LEN + 1];
	hash_t 	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getautobankacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

                /* varchar   	hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_int_bank_code_list[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_int_bank_code_list;

		int		hv_int_bank_code_exist;
		int		hv_int_bank_code_exclude;

		short   	hv_return_value;

		/* varchar		v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_psp_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar         v_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_baid_name;

		/* varchar       	v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar 	v_bank_abbrev_name[PD_EXT_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_abbrev_name;

		/* varchar 	v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar 	v_bank_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_country;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_bank_acct_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_ccy;

		/* varchar         v_bank_acct_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_name;

                /* varchar         v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

		/* varchar         v_status_type[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_status_type;

		int		v_bank_disabled;
		int		v_bank_acct_disabled;

		short		ind_client_name= -1;
		short		ind_psp_id = -1;
		short		ind_psp_name = -1;
		short		ind_baid = -1;
		short		ind_baid_name = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_abbrev_name = -1;
		short		ind_bank_name = -1;
		short		ind_bank_country = -1;
		short		ind_bank_acct_num = -1;
		short		ind_bank_acct_ccy	= -1;
		short 		ind_bank_acct_name = -1;
		short		ind_bank_acct_short_name = -1;
		short		ind_status_type = -1;
		short		ind_bank_disabled = -1;
		short		ind_bank_acct_disabled = -1;
       
		SQL_CURSOR      c_cursor_getautobankacct;
	 
/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAutoUploadBankAccts: Begin\n"));

/* acct_type */
        if(GetField_CString(hRec,"acct_type",&csAcctType)){
                hv_acct_type.len = strlen(csAcctType);
                memcpy(hv_acct_type.arr,csAcctType,hv_acct_type.len);
DEBUGLOG(("acct_type = [%.*s]\n",hv_acct_type.len,hv_acct_type.arr));
        }else{
                return INT_ERR;
DEBUGLOG(("acct_type is missing\n"));
        }

/* client_id */
	if(GetField_CString(hRec,"client_id",&csClientId)){
		hv_client_id.len = strlen(csClientId);
        	memcpy(hv_client_id.arr,csClientId,hv_client_id.len);
DEBUGLOG(("client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }else{
                return INT_ERR;
DEBUGLOG(("client_id is missing\n"));
        }

/* int_bank_code_list */
        if(GetField_CString(hRec,"int_bank_code_list",&csBankCodeList)){
		hv_int_bank_code_exist = 1;
DEBUGLOG(("hv_int_bank_code_exist = [%d]\n",hv_int_bank_code_exist));

		hv_int_bank_code_list.len = strlen(csBankCodeList);
                memcpy(hv_int_bank_code_list.arr,csBankCodeList,hv_int_bank_code_list.len);
DEBUGLOG(("int_bank_code_list = [%.*s]\n",hv_int_bank_code_list.len,hv_int_bank_code_list.arr));

/* int_bank_code_exclude */
		if(GetField_Int(hRec,"int_bank_code_exclude",&iBankCodeExclude)){
			hv_int_bank_code_exclude = iBankCodeExclude;
DEBUGLOG(("int_bank_code_exclude = [%d]\n",hv_int_bank_code_exclude));
		}else{
			return INT_ERR;
DEBUGLOG(("int_bank_code_exclude is missing\n"));
		}
        }else{
		hv_int_bank_code_exist = 0;

		memset(csAllBankCode, 0, strlen(csAllBankCode));
		sprintf(csAllBankCode, "086000");
		hv_int_bank_code_list.len = strlen(csAllBankCode);
                memcpy(hv_int_bank_code_list.arr,csAllBankCode,hv_int_bank_code_list.len);
DEBUGLOG(("int_bank_code_list is missing\n"));
        }
	
	/* EXEC SQL ALLOCATE       :c_cursor_getautobankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
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
 if (sqlca.sqlcode < 0) goto getautobankacct_error;
}


	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_auto_upl_get_bank_acct(:hv_acct_type,
                                                                         :hv_client_id,
                                                                         :hv_int_bank_code_list,
									 :hv_int_bank_code_exist,
									 :hv_int_bank_code_exclude,
									 :c_cursor_getautobankacct);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_get_bank_acct ( :h\
v_acct_type , :hv_client_id , :hv_int_bank_code_list , :hv_int_bank_code_exis\
t , :hv_int_bank_code_exclude , :c_cursor_getautobankacct ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code_list;
 sqlstm.sqhstl[3] = (unsigned long )258;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_int_bank_code_exist;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code_exclude;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_getautobankacct;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getautobankacct_error;
}



DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
		for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_client_name= -1;
               		ind_psp_id = -1;
                	ind_psp_name = -1;
                	ind_baid = -1;
                	ind_baid_name = -1;
                	ind_int_bank_code = -1;
                	ind_bank_abbrev_name = -1;
               		ind_bank_name = -1;
            		ind_bank_country = -1;
              		ind_bank_acct_num = -1;
               		ind_bank_acct_ccy       = -1;
               		ind_bank_acct_name = -1;
              		ind_bank_acct_short_name = -1;
			ind_status_type = -1;			
			ind_bank_disabled = -1;			
               		ind_bank_acct_disabled = -1;			

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getautobankacct

			INTO
                        	:v_client_name:ind_client_name,
                        	:v_psp_id:ind_psp_id,
                        	:v_psp_name:ind_psp_name,
                        	:v_baid:ind_baid,
                        	:v_baid_name:ind_baid_name,
                        	:v_int_bank_code:ind_int_bank_code,
                        	:v_bank_abbrev_name:ind_bank_abbrev_name,
                        	:v_bank_name:ind_bank_name,
                        	:v_bank_country:ind_bank_country,
                        	:v_bank_acct_num:ind_bank_acct_num,
                        	:v_bank_acct_ccy:ind_bank_acct_ccy,
                        	:v_bank_acct_name:ind_bank_acct_name,
                        	:v_bank_acct_short_name:ind_bank_acct_short_name,
				:v_status_type:ind_status_type,
				:v_bank_disabled:ind_bank_disabled,
                        	:v_bank_acct_disabled:ind_bank_acct_disabled; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )67;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_client_name;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_client_name;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
                        sqlstm.sqhstl[3] = (unsigned long )53;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_psp_name;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_baid;
                        sqlstm.sqhstl[4] = (unsigned long )23;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_baid;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_baid_name;
                        sqlstm.sqhstl[5] = (unsigned long )153;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_baid_name;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_int_bank_code;
                        sqlstm.sqhstl[6] = (unsigned long )13;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_int_bank_code;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_abbrev_name;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_abbrev_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[8] = (unsigned long )153;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_country;
                        sqlstm.sqhstl[9] = (unsigned long )5;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_country;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[10] = (unsigned long )53;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_bank_acct_ccy;
                        sqlstm.sqhstl[11] = (unsigned long )6;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_bank_acct_ccy;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_bank_acct_name;
                        sqlstm.sqhstl[12] = (unsigned long )53;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_bank_acct_name;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_bank_acct_short_name;
                        sqlstm.sqhstl[13] = (unsigned long )23;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_bank_acct_short_name;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_status_type;
                        sqlstm.sqhstl[14] = (unsigned long )4;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_status_type;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_bank_disabled;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_bank_disabled;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_bank_acct_disabled;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_bank_acct_disabled;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getautobankacct_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* acct_type */
	                PutField_CString(myHash,"acct_type",csAcctType);
DEBUGLOG((" acct_type = [%s]\n",csAcctType));

/* client_id */
       	         PutField_CString(myHash,"client_id",csClientId);
DEBUGLOG((" client_id = [%s]\n",csClientId));

/* int_bank_code */
                	if(ind_int_bank_code>=0){
                	   	v_int_bank_code.arr[v_int_bank_code.len]='\0';
                	    	PutField_CString(myHash,"int_bank_code",(const char*)v_int_bank_code.arr);
DEBUGLOG((" int_bank_code = [%s]\n",v_int_bank_code.arr));
              		}

/* client_name */
                	if(ind_client_name>=0){
                	        v_client_name.arr[v_client_name.len]='\0';
                	        PutField_CString(myHash,"client_name",(const char*)v_client_name.arr);
DEBUGLOG((" client_name = [%s]\n",v_client_name.arr));
                	}

/* psp_id */
                	if(ind_psp_id>=0){
                	        v_psp_id.arr[v_psp_id.len]='\0';
                	        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG((" psp_id = [%s]\n",v_psp_id.arr));
                	}

/* psp_name */
                	if(ind_psp_name>=0){
                	        v_psp_name.arr[v_psp_name.len]='\0';
                	        PutField_CString(myHash,"psp_name",(const char*)v_psp_name.arr);
DEBUGLOG((" psp_name = [%s]\n",v_psp_name.arr));
                	}	

/* baid */
                	if(ind_baid>=0){
                	        v_baid.arr[v_baid.len]='\0';
                	        PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG((" baid = [%s]\n",v_baid.arr));
                	}

/* baid_name */
                	if(ind_baid_name>=0){
                	        v_baid_name.arr[v_baid_name.len]='\0';
                	        PutField_CString(myHash,"baid_name",(const char*)v_baid_name.arr);
DEBUGLOG((" baid_name = [%s]\n",v_baid_name.arr));
                	}

/* bank_abbrev_name */
                	if(ind_bank_abbrev_name>=0){
                	        v_bank_abbrev_name.arr[v_bank_abbrev_name.len]='\0';
                	        PutField_CString(myHash,"bank_abbrev_name",(const char*)v_bank_abbrev_name.arr);
DEBUGLOG((" bank_abbrev_name = [%s]\n",v_bank_abbrev_name.arr));
                	}

/* bank_name */
                	if(ind_bank_name>=0){
                	        v_bank_name.arr[v_bank_name.len]='\0';
                	        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" bank_name = [%s]\n",v_bank_name.arr));
                	}

/* bank_country */
                	if(ind_bank_country>=0){
                	        v_bank_country.arr[v_bank_country.len]='\0';
                	        PutField_CString(myHash,"bank_country",(const char*)v_bank_country.arr);
DEBUGLOG((" bank_country = [%s]\n",v_bank_country.arr));
                	}

/* bank_acct_num */
                	if(ind_bank_acct_num>=0){
                	        v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                	        PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                	}

/* bank_acct_name */
                	if(ind_bank_acct_name>=0){
                	        v_bank_acct_name.arr[v_bank_acct_name.len]='\0';
               		        PutField_CString(myHash,"bank_acct_name",(const char*)v_bank_acct_name.arr);
DEBUGLOG((" bank_acct_name = [%s]\n",v_bank_acct_name.arr));
               	 	}

/* bank_acct_short_name */
                	if(ind_bank_acct_short_name>=0){
                	        v_bank_acct_short_name.arr[v_bank_acct_short_name.len]='\0';
                	        PutField_CString(myHash,"bank_acct_short_name",(const char*)v_bank_acct_short_name.arr);
DEBUGLOG((" bank_acct_short_name = [%s]\n",v_bank_acct_short_name.arr));
                	}

/* status_type */
                        if(ind_status_type>=0){
                                v_status_type.arr[v_status_type.len]='\0';
                                PutField_CString(myHash,"status_type",(const char*)v_status_type.arr);
DEBUGLOG((" status_type = [%s]\n",v_status_type.arr));
                        }

/* bank_disabled */
                        if(ind_bank_disabled>=0){
                                PutField_Int(myHash,"bank_disabled",v_bank_disabled);
DEBUGLOG((" bank_disabled = [%d]\n",v_bank_disabled));
                        }

/* bank_acct_disabled */
                	if(ind_bank_acct_disabled>=0){
                       	 	PutField_Int(myHash,"bank_acct_disabled",v_bank_acct_disabled);
DEBUGLOG((" bank_acct_disabled = [%d]\n",v_bank_acct_disabled));
               	 	}

			RecordSet_Add(myRec,myHash);
                        iCnt++;
		}
	
DEBUGLOG(("GetAutoUploadBankAccts: Normal Exit\n"));
		return PD_FOUND;
	}
	else if (hv_return_value == SP_NOT_FOUND)
        {
                return PD_NOT_FOUND;
        } 
	else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetAutoUploadBankAccts: SP_OTHER_ERR\n"));
ERRLOG("OLAutoUploadBankDetail::GetAutoUploadBankAccts: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
ERRLOG("OLAutoUploadBankDetail::GetAutoUploadBankAccts: SP_ERR\n");
DEBUGLOG(("GetAutoUploadBankAccts: SP_ERR\n"));
                return PD_ERR;
        }

	/* EXEC SQL CLOSE :c_cursor_getautobankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
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
 if (sqlca.sqlcode < 0) goto getautobankacct_error;
}


        /* EXEC SQL FREE :c_cursor_getautobankacct; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )169;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
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
        if (sqlca.sqlcode < 0) goto getautobankacct_error;
}



getautobankacct_error:
DEBUGLOG(("getautobankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadBankDetail_Get: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_getautobankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )188;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
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
}


	/* EXEC SQL FREE :c_cursor_getautobankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )207;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautobankacct;
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
}


    	return PD_ERR;
}

int UpdateDisabled(const hash_t *hDisabled)
{
	char *csTmp;
	int iDisabled = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getupdatedisabled_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

		/* varchar hv_update_user[PD_UPDATE_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		int	hv_disabled;
		
		short	ind_int_bank_code = -1;
		short 	ind_bank_acct_num = -1;
		short 	ind_acct_type = -1;
		short	ind_update_user = -1;
		short	ind_disabled = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDisabled: Begin\n"));
	
/* bank_code */
	if (GetField_CString(hDisabled, "int_bank_code", &csTmp))
	{
		hv_int_bank_code.len = strlen(csTmp);
		memcpy(hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%s]\n", csTmp));
		ind_int_bank_code = 0;
	}
	else
	{
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: int_bank_code is missing\n");
DEBUGLOG(("int_bank_code is missing\n"));
		return PD_ERR;
	}

/* bank_acct_num */
	if (GetField_CString(hDisabled, "bank_acct_num", &csTmp))
	{
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
DEBUGLOG(("bank_acct_num = [%s]\n", csTmp));
		ind_bank_acct_num = 0;
	}
	else
	{
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: bank_acct_num is missing\n");
DEBUGLOG(("bank_acct_num is missing\n"));
		return PD_ERR;
	}

/* acct_type */
	if (GetField_CString(hDisabled, "acct_type", &csTmp))
        {
                hv_acct_type.len = strlen(csTmp);
                memcpy(hv_acct_type.arr, csTmp, hv_acct_type.len);
DEBUGLOG(("acct_type = [%s]\n", csTmp));
                ind_acct_type = 0;
        }
        else
        {
		sprintf(csTmp, PD_NATURE_DEPOSIT);
		hv_acct_type.len = strlen(csTmp);
                memcpy(hv_acct_type.arr, csTmp, hv_acct_type.len);
DEBUGLOG(("acct_type (default) = [%s]\n", csTmp));
                ind_acct_type = 0;
        }

/* disabled */
	if (GetField_Int(hDisabled, "disabled", &iDisabled))
	{
		hv_disabled = iDisabled;
DEBUGLOG(("disabled = [%d]\n", iDisabled));
		ind_disabled = 0;
	}
	else
	{
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: disabled is missing\n");
DEBUGLOG(("disabled is missing\n"));
		return PD_ERR;
	}

/* update_user */	
	if (GetField_CString(hDisabled, "update_user", &csTmp))
	{			
		hv_update_user.len = strlen(csTmp);	
		memcpy(hv_update_user.arr, csTmp, hv_update_user.len);
DEBUGLOG(("update_user = [%s]\n", csTmp));
		ind_update_user = 0;
	}
	else
	{
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: update_user is missing\n");
DEBUGLOG(("update_user is missing\n"));
		return PD_ERR;
	}

/* update table: OL_AUTO_UPLOAD_BANK_DETAIL */
	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_oaubd_update_disabled(:hv_int_bank_code:ind_int_bank_code,
								     :hv_bank_acct_num:ind_bank_acct_num,
								     :hv_acct_type:ind_acct_type,
								     :hv_disabled:ind_disabled,
								     :hv_update_user:ind_update_user
								     );
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_oaubd_update_disabled ( :hv_in\
t_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_acc\
t_type:ind_acct_type , :hv_disabled:ind_disabled , :hv_update_user:ind_update\
_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_acct_type;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_disabled;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto getupdatedisabled_error;
}


		
DEBUGLOG(("Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateDisabled: Normal Exit\n"));
		return PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
DEBUGLOG(("UpdateDisabled: SP_OTHER_ERR\n"));
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: SP_OTHER_ERR\n");
		return PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: SP_ERR\n");
DEBUGLOG(("UpdateDisabled: SP_ERR\n"));
		return PD_ERR;
	}

getupdatedisabled_error:
DEBUGLOG(("getuploaddisabled_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadBankDetail::UpdateDisabled: Update Error Occurr unexpectedly!\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
