
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "ClientSettBank.pc"
};


static unsigned int sqlctx = 9295219;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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
"select bank_ac_name , bank_ac_nmb , bank_name , address , swift_code , iban\
 , currency_id , country_subdivision , city , country from client_sett_bank w\
here client_sett_bank_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,194,0,9,86,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,88,0,0,10,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
79,0,0,1,0,0,15,180,0,0,0,0,0,1,0,
94,0,0,1,0,0,15,190,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/10/03              Elvis Wong
Add 3 fields for GetClientSettBank		   2015/03/02		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "ClientSettBank.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void ClientSettBank(char    cdebug)
{
        cDebug = cdebug;
}


int GetClientSettBank(int iClientSettBankId, hash_t* hRec)
{
	int	iRet = PD_NOT_FOUND;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO getclientsettbank_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                       
        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		int		hv_client_sett_bank_id;
	
		/* varchar		v_bank_ac_name[PD_BENEFICIARY_BANK_AC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_bank_ac_name;

		/* varchar		v_bank_ac_num[PD_BENEFICIARY_BANK_AC_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_ac_num;

		/* varchar		v_bank_name[PD_BENEFICIARY_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_bank_name;

		/* varchar		v_address[PD_COMPANY_ADDR_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_address;

		/* varchar		v_swift_code[PD_COMPANY_SWIFT_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[81]; } v_swift_code;

		/* varchar		v_iban[PD_COMPANY_IBAN_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[81]; } v_iban;

		/* varchar		v_bank_ac_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ac_ccy;

		/* varchar		v_country_subdivision[PD_CLIENT_COUNTRY_SUBDIVISION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_country_subdivision;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_country[PD_CLIENT_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country;


		short		ind_bank_ac_name = -1;
		short		ind_bank_ac_num = -1;
		short		ind_bank_name = -1;
		short		ind_address = -1;
		short		ind_swift_code = -1;
		short		ind_iban = -1;
		short		ind_bank_ac_ccy = -1;
		short		ind_country_subdivision = -1;
		short		ind_city = -1;
		short		ind_country = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


// client_sett_bank_id
	hv_client_sett_bank_id = iClientSettBankId;
DEBUGLOG(("GetClientSettBank: client_sett_bank_id = [%d]\n",hv_client_sett_bank_id));

	/* EXEC SQL DECLARE c_cursor_getclientsettbank CURSOR FOR
                select
			bank_ac_name,
			bank_ac_nmb,
			bank_name,
			address,
			swift_code,
			iban,
			currency_id,
			country_subdivision,
			city,
			country
		from	client_sett_bank
		where	client_sett_bank_id = :hv_client_sett_bank_id; */ 


	/* EXEC SQL OPEN c_cursor_getclientsettbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_client_sett_bank_id;
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
 if (sqlca.sqlcode < 0) goto getclientsettbank_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getclientsettbank
                INTO	:v_bank_ac_name:ind_bank_ac_name,
			:v_bank_ac_num:ind_bank_ac_num,
			:v_bank_name:ind_bank_name,
			:v_address:ind_address,
			:v_swift_code:ind_swift_code,
			:v_iban:ind_iban,
			:v_bank_ac_ccy:ind_bank_ac_ccy,
			:v_country_subdivision:ind_country_subdivision,
			:v_city:ind_city,
			:v_country:ind_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )24;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_ac_name;
                sqlstm.sqhstl[0] = (unsigned long )103;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_ac_name;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_ac_num;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_ac_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[2] = (unsigned long )103;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_address;
                sqlstm.sqhstl[3] = (unsigned long )203;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_address;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_swift_code;
                sqlstm.sqhstl[4] = (unsigned long )83;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_swift_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_iban;
                sqlstm.sqhstl[5] = (unsigned long )83;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_iban;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_ac_ccy;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_bank_ac_ccy;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_country_subdivision;
                sqlstm.sqhstl[7] = (unsigned long )103;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_country_subdivision;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[8] = (unsigned long )103;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_city;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_country;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getclientsettbank_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetClientSettBank: found record\n"));

/* bank_ac_name */
                if (ind_bank_ac_name >= 0) {
                        v_bank_ac_name.arr[v_bank_ac_name.len] = '\0';
                        PutField_CString(hRec,"bank_ac_name",(const char*)v_bank_ac_name.arr);
DEBUGLOG(("GetClientSettBank: bank_ac_name = [%s]\n",v_bank_ac_name.arr));
                }

/* bank_ac_num */
                if (ind_bank_ac_num >= 0) {
                        v_bank_ac_num.arr[v_bank_ac_num.len] = '\0';
                        PutField_CString(hRec,"bank_ac_num",(const char*)v_bank_ac_num.arr);
DEBUGLOG(("GetClientSettBank: bank_ac_num = [%s]\n",v_bank_ac_num.arr));
                }

/* bank_name */
                if (ind_bank_name >= 0) {
                        v_bank_name.arr[v_bank_name.len] = '\0';
                        PutField_CString(hRec,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetClientSettBank: bank_name = [%s]\n",v_bank_name.arr));
                }

/* address */
                if (ind_address >= 0) {
                        v_address.arr[v_address.len] = '\0';
                        PutField_CString(hRec,"address",(const char*)v_address.arr);
DEBUGLOG(("GetClientSettBank: address = [%s]\n",v_address.arr));
                }

/* swift_code */
                if (ind_swift_code >= 0) {
                        v_swift_code.arr[v_swift_code.len] = '\0';
                        PutField_CString(hRec,"swift_code",(const char*)v_swift_code.arr);
DEBUGLOG(("GetClientSettBank: swift_code = [%s]\n",v_swift_code.arr));
                }

/* iban */
                if (ind_iban >= 0) {
                        v_iban.arr[v_iban.len] = '\0';
                        PutField_CString(hRec,"iban",(const char*)v_iban.arr);
DEBUGLOG(("GetClientSettBank: iban = [%s]\n",v_iban.arr));
                }

/* bank_ac_ccy */
                if (ind_bank_ac_ccy >= 0) {
                        v_bank_ac_ccy.arr[v_bank_ac_ccy.len] = '\0';
                        PutField_CString(hRec,"bank_ac_ccy",(const char*)v_bank_ac_ccy.arr);
DEBUGLOG(("GetClientSettBank: bank_ac_ccy = [%s]\n",v_bank_ac_ccy.arr));
                }

/* country_subdivision */
                if (ind_country_subdivision >= 0) {
                        v_country_subdivision.arr[v_country_subdivision.len] = '\0';
                        PutField_CString(hRec,"country_subdivision",(const char*)v_country_subdivision.arr);
DEBUGLOG(("GetClientSettBank: country_subdivision = [%s]\n",v_country_subdivision.arr));
                }

/* city */
                if (ind_city >= 0) {
                        v_city.arr[v_city.len] = '\0';
                        PutField_CString(hRec,"city",(const char*)v_city.arr);
DEBUGLOG(("GetClientSettBank: city = [%s]\n",v_city.arr));
                }

/* country */
                if (ind_country >= 0) {
                        v_country.arr[v_country.len] = '\0';
                        PutField_CString(hRec,"country",(const char*)v_country.arr);
DEBUGLOG(("GetClientSettBank: country = [%s]\n",v_country.arr));
                }

		iRet = PD_FOUND;
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getclientsettbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )79;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getclientsettbank_error;
}



DEBUGLOG(("GetClientSettBank: Normal Exit, iRet = [%d]\n", iRet));
       	return  iRet;

getclientsettbank_error:
DEBUGLOG(("getclientsettbank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ClientSettBank_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getclientsettbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )94;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

