
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "BankDesc.pc"
};


static unsigned int sqlctx = 139267;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
"select internal_bank_code from bank_desc where country = :b0 and bank_name \
like :b1            ";

 static char *sq0003 = 
"select bank_name , country , bank_url from bank_desc where internal_bank_co\
de = :b0            ";

 static char *sq0005 = 
"select internal_bank_code from bank_desc where bank_abbrev_name = :b0      \
      ";

 static char *sq0006 = 
"select internal_bank_code from bank_desc where bank_abbrev_name = :b0 and o\
ffline_support = 1            ";

 static char *sq0007 = 
"select internal_bank_code , offline_support , system_support from bank_desc\
 , country where country = country_code and bank_name = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,95,0,9,74,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,76,0,0,1,0,0,1,0,2,9,0,0,
47,0,0,1,0,0,15,95,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,113,0,0,0,0,0,1,0,
77,0,0,2,82,0,4,140,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
100,0,0,3,95,0,9,200,0,2049,1,1,0,1,0,1,9,0,0,
119,0,0,3,0,0,13,202,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
146,0,0,3,0,0,15,237,0,0,0,0,0,1,0,
161,0,0,3,0,0,15,247,0,0,0,0,0,1,0,
176,0,0,4,82,0,4,274,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
199,0,0,5,81,0,9,331,0,2049,1,1,0,1,0,1,9,0,0,
218,0,0,5,0,0,13,333,0,0,1,0,0,1,0,2,9,0,0,
237,0,0,5,0,0,15,352,0,0,0,0,0,1,0,
252,0,0,5,0,0,15,368,0,0,0,0,0,1,0,
267,0,0,6,105,0,9,399,0,2049,1,1,0,1,0,1,9,0,0,
286,0,0,6,0,0,13,401,0,0,1,0,0,1,0,2,9,0,0,
305,0,0,6,0,0,15,420,0,0,0,0,0,1,0,
320,0,0,6,0,0,15,436,0,0,0,0,0,1,0,
335,0,0,7,146,0,9,476,0,2049,1,1,0,1,0,1,9,0,0,
354,0,0,7,0,0,13,478,0,0,3,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,
381,0,0,7,0,0,15,519,0,0,0,0,0,1,0,
396,0,0,7,0,0,15,537,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/10/07              [MSN]
Get Bank Detail by BankCode                        2014/08/27              [SWK]
Add GetBankAbbrevName				   2015/02/27		   [WMC]
Add FindBankCodeByAbbrevName		 	   2015/03/12		   [WMC]
Add FindOfflineBankByBankAbbrevName		   2018/01/23		   [WMC]
Add GetBankByBankName				   2020/06/08		   [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "BankDesc.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void BankDesc(char    cdebug)
{
        cDebug = cdebug;
}

int FindBankCode(const unsigned char* csBankName,
		const unsigned char* csCountry,
		char* csBankCode)
{

	int	iRet = NOT_FOUND;
	char	*csName;

        /* EXEC SQL WHENEVER SQLERROR GOTO code_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_name[PD_BANK_NAME_LEN+2]; */ 
struct { unsigned short len; unsigned char arr[152]; } hv_name;

                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;


                /* varchar v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;


                short   ind_bank_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	csName = (char*) malloc (128);
	strcpy((char*)hv_name.arr, "%");
	strcat((char*)hv_name.arr, (const char *)csBankName);
	strcat((char*)hv_name.arr, "%");
	hv_name.len = strlen((const char*)hv_name.arr);
	hv_name.len = strlen((char*)hv_name.arr);
DEBUGLOG(("FindBankCode: bank_name like [%.*s]\n",hv_name.len,hv_name.arr)); 

        hv_country.len = strlen((const char *) csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("FindBankCode: country = [%.*s]\n",hv_country.len,hv_country.arr)); 


	/* EXEC SQL DECLARE c_cursor_code CURSOR FOR
        	select  internal_bank_code
                from	bank_desc
                where country=:hv_country
		and   bank_name like :hv_name; */ 


	/* EXEC SQL OPEN c_cursor_code; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[0] = (unsigned long )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_name;
 sqlstm.sqhstl[1] = (unsigned long )154;
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
 if (sqlca.sqlcode < 0) goto code_error;
}


	do{	
		/* EXEC SQL FETCH c_cursor_code
                INTO
			:v_bank_code:ind_bank_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_code;
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
  if (sqlca.sqlcode < 0) goto code_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

        	if (ind_bank_code >= 0) {
                	v_bank_code.arr[v_bank_code.len] = '\0';
			strcpy(csBankCode,(const char*)v_bank_code.arr);
DEBUGLOG(("bank_code = [%s]\n",csBankCode));
			iRet = FOUND;
		}

		break;/////only one 

        }while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )47;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto code_error;
}



	if(iRet == FOUND){
DEBUGLOG(("FindBankCode success [%d]\n",iRet));
	}
	else{
DEBUGLOG(("FindBankCode failed [%d]\n",iRet));
	}

	FREE_ME(csName);

	return iRet;

code_error:
DEBUGLOG(("code_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::code_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_code; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )62;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return NOT_FOUND;
}


int GetBankCountry(const unsigned char* csBankCode,
		   unsigned char* csCountry)
{

	int	iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO country_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


                /* varchar v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


                short   ind_country = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_bank_code.len = strlen((const char *) csBankCode);
        memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetBankCountry:bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr)); 


	/* EXEC SQL
        	select  distinct country
		into	:v_country:ind_country
                from	bank_desc
                where	internal_bank_code=:hv_bank_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select distinct country into :b0:b1 from bank_desc where in\
ternal_bank_code = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_country;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto country_error;
}




        if (ind_country>= 0) {
               	v_country.arr[v_country.len] = '\0';
		strcpy((char*)csCountry,(const char*)v_country.arr);
DEBUGLOG(("country = [%s]\n",csCountry));
		iRet = FOUND;
	}

	if(iRet == FOUND){
DEBUGLOG(("GetBankCountry success [%d]\n",iRet));
	}
	else{
DEBUGLOG(("GetBankCountry failed [%d]\n",iRet));
	}

	return iRet;

country_error:
DEBUGLOG(("country_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::country_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

int GetBankDetail(const unsigned char* csBankCode,
			hash_t* hRec)
{
	int     iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO bankdt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar v_bank_url[PD_URL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_bank_url;


		short	ind_bank_name = -1;
		short   ind_country = -1;
		short	ind_bank_url = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_code.len = strlen((const char *) csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetBankCountry:bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

	/* EXEC SQL DECLARE c_cursor_getbankdetail CURSOR FOR
		select bank_name, country, bank_url
		from   bank_desc
		where  internal_bank_code = :hv_bank_code; */ 


	/* EXEC SQL OPEN c_cursor_getbankdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )100;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto bankdt_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbankdetail
		INTO 	
			:v_bank_name:ind_bank_name,
			:v_country:ind_country,
			:v_bank_url:ind_bank_url; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )119;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[0] = (unsigned long )153;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_country;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_url;
  sqlstm.sqhstl[2] = (unsigned long )258;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_url;
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
  if (sqlca.sqlcode < 0) goto bankdt_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

DEBUGLOG(("GetBankDetail found record\n"));
		iRet = PD_OK;

/* bank_name */
		if (ind_bank_name >= 0) {
			v_bank_name.arr[v_bank_name.len] = '\0';
			PutField_CString(hRec, "bank_name", (const char*)v_bank_name.arr);
DEBUGLOG(("GetBankDetail bank_name = [%s]\n", v_bank_name.arr));
		}

/* country */
		if (ind_country>= 0) {
			v_country.arr[v_country.len] = '\0';
			PutField_CString(hRec, "bank_country", (const char*)v_country.arr);
DEBUGLOG(("GetBankDetail country = [%s]\n", v_country.arr));
		}
		
/* bank_url */
		if (ind_bank_url >= 0) {
			v_bank_url.arr[v_bank_url.len] = '\0';
			PutField_CString(hRec, "bank_url", (const char*)v_bank_url.arr);
DEBUGLOG(("GetBankDetail bank_url = [%s]\n", v_bank_url.arr));
		}
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbankdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )146;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto bankdt_error;
}



DEBUGLOG(("GetBankDetail Exit [%d]\n", iRet));
	return iRet;

bankdt_error:
DEBUGLOG(("bankdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::bankdt_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbankdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )161;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return PD_ERR;
}

int GetBankAbbrevName(const unsigned char* csBankCode,
                   	hash_t *hRec)
{

        int     iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO bankabbrevname_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


                /* varchar v_bank_abbrev_name[PD_EXT_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_abbrev_name;


                short   ind_bank_abbrev_name = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_bank_code.len = strlen((const char *) csBankCode);
        memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetBankAbbrevName:bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));


        /* EXEC SQL
                select  bank_abbrev_name
                into    :v_bank_abbrev_name:ind_bank_abbrev_name
                from    bank_desc
                where   internal_bank_code=:hv_bank_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select bank_abbrev_name into :b0:b1 from bank_desc w\
here internal_bank_code = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )176;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_abbrev_name;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_bank_abbrev_name;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto bankabbrevname_error;
}




        if (ind_bank_abbrev_name>= 0) {
                v_bank_abbrev_name.arr[v_bank_abbrev_name.len] = '\0';
               	PutField_CString(hRec, "bank_abbrev_name", (const char*)v_bank_abbrev_name.arr);
DEBUGLOG(("GetBankAbbrevName:bank_abbrev_name = [%s]\n", v_bank_abbrev_name.arr));
                iRet = FOUND;
        }

        if(iRet == FOUND){
DEBUGLOG(("GetBankAbbrevName success [%d]\n",iRet));
        }
        else{
DEBUGLOG(("GetBankAbbrevName failed [%d]\n",iRet));
        }

        return iRet;

bankabbrevname_error:
DEBUGLOG(("bankabbrevname_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::bankabbrevname_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

int FindBankCodeByBankAbbrevName(const unsigned char* csAbbrevName,
               		char* csBankCode)
{
        int     iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO bankcode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_bank_abbrev_name[PD_EXT_BANK_CODE_LEN+2]; */ 
struct { unsigned short len; unsigned char arr[52]; } hv_bank_abbrev_name;


                /* varchar v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;


                short   ind_bank_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_bank_abbrev_name.len = strlen((const char *) csAbbrevName);
        memcpy(hv_bank_abbrev_name.arr,csAbbrevName,hv_bank_abbrev_name.len);
DEBUGLOG(("FindBankCodeByBankAbbrevName: bank_abbrev_name = [%.*s]\n",hv_bank_abbrev_name.len,hv_bank_abbrev_name.arr));


        /* EXEC SQL DECLARE c_cursor_bankcode CURSOR FOR
                select  internal_bank_code
                from    bank_desc
                where bank_abbrev_name=:hv_bank_abbrev_name; */ 


        /* EXEC SQL OPEN c_cursor_bankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )199;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_abbrev_name;
        sqlstm.sqhstl[0] = (unsigned long )54;
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
        if (sqlca.sqlcode < 0) goto bankcode_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_bankcode
                INTO
                        :v_bank_code:ind_bank_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )218;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_code;
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
                if (sqlca.sqlcode < 0) goto bankcode_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_bank_code >= 0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
                        strcpy(csBankCode,(const char*)v_bank_code.arr);
DEBUGLOG(("FindBankCodeByBankAbbrevName: bank_code = [%s]\n",csBankCode));
                        iRet = FOUND;
                }

                break;/////only one

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_bankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )237;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto bankcode_error;
}



        if(iRet == FOUND){
DEBUGLOG(("FindBankCodeByBankAbbrevName success [%d]\n",iRet));
        }
        else{
DEBUGLOG(("FindBankCodeByBankAbbrevName failed [%d]\n",iRet));
        }

        return iRet;

bankcode_error:
DEBUGLOG(("bankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::bankcode_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_bankcode; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )252;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return NOT_FOUND;
}

int FindOfflineBankByBankAbbrevName(const unsigned char* csAbbrevName,
               			char* csBankCode)
{
        int     iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO offlinebankcode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_bank_abbrev_name[PD_EXT_BANK_CODE_LEN+2]; */ 
struct { unsigned short len; unsigned char arr[52]; } hv_bank_abbrev_name;


                /* varchar v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;


                short   ind_bank_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_bank_abbrev_name.len = strlen((const char *) csAbbrevName);
        memcpy(hv_bank_abbrev_name.arr,csAbbrevName,hv_bank_abbrev_name.len);
DEBUGLOG(("FindOfflineBankByBankAbbrevName: bank_abbrev_name = [%.*s]\n",hv_bank_abbrev_name.len,hv_bank_abbrev_name.arr));


        /* EXEC SQL DECLARE c_cursor_offlinebankcode CURSOR FOR
                select  internal_bank_code
                from    bank_desc
                where 	bank_abbrev_name=:hv_bank_abbrev_name
		and 	offline_support = 1; */ 


        /* EXEC SQL OPEN c_cursor_offlinebankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )267;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_abbrev_name;
        sqlstm.sqhstl[0] = (unsigned long )54;
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
        if (sqlca.sqlcode < 0) goto offlinebankcode_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_offlinebankcode
                INTO
                        :v_bank_code:ind_bank_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )286;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_code;
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
                if (sqlca.sqlcode < 0) goto offlinebankcode_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_bank_code >= 0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
                        strcpy(csBankCode,(const char*)v_bank_code.arr);
DEBUGLOG(("FindOfflineBankByBankAbbrevName: bank_code = [%s]\n",csBankCode));
                        iRet = FOUND;
                }

                break;/////only one

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_offlinebankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )305;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto offlinebankcode_error;
}



        if(iRet == FOUND){
DEBUGLOG(("FindOfflineBankByBankAbbrevName success [%d]\n",iRet));
        }
        else{
DEBUGLOG(("FindOfflineBankByBankAbbrevName failed [%d]\n",iRet));
        }

        return iRet;

offlinebankcode_error:
DEBUGLOG(("offlinebankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("BankDesc::offlinebankcode_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_offlinebankcode; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )320;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return NOT_FOUND;
}


int GetBankByBankName(const char* csBankName, hash_t* hRec)
{
	int iRet = PD_NOT_FOUND;
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getintbank_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		
		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		int		v_offline_support;
		int		v_system_support;
		
		short		ind_bank_code = -1;
		short		ind_offline_support = -1;
		short		ind_system_support = -1;
		
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_name.len = strlen(csBankName);
	memcpy(hv_bank_name.arr, csBankName, hv_bank_name.len);
DEBUGLOG(("GetBankByBankName bank_name = [%.*s]\n", hv_bank_name.len, hv_bank_name.arr));



	/* EXEC SQL DECLARE c_cursor_getintbank CURSOR FOR
		select	internal_bank_code,
			offline_support,
			system_support
		from bank_desc, country
		where country = country_code
		and bank_name = :hv_bank_name; */ 


	/* EXEC SQL OPEN c_cursor_getintbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )335;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[0] = (unsigned long )152;
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
 if (sqlca.sqlcode < 0) goto getintbank_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getintbank
		INTO	:v_bank_code:ind_bank_code,
			:v_offline_support:ind_offline_support,
			:v_system_support:ind_system_support
		; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )354;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_offline_support;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_offline_support;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_system_support;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_system_support;
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
  if (sqlca.sqlcode < 0) goto getintbank_error;
}


	
		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
DEBUGLOG(("GetBankByBankName found record\n"));
		
		if(iCnt >= 1){
DEBUGLOG(("GetBankByBankName found duplicate record\n"));
			iRet = PD_NOT_FOUND;
			break;
		}

/* int_bank_code */
		if (ind_bank_code >= 0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			PutField_CString(hRec,"int_bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetBankByBankName int_bank_code = [%s]\n",v_bank_code.arr));
		}
/*offline_support*/
		if (ind_offline_support >= 0) {
			PutField_Int(hRec,"offline_support",v_offline_support);
DEBUGLOG(("GetBankByBankName offline_support = [%d]\n",v_offline_support));
		}
/*system_support*/
		if (ind_system_support >= 0) {
			PutField_Int(hRec,"system_support",v_system_support);
DEBUGLOG(("GetBankByBankName system_support = [%d]\n",v_system_support));
		}
		

		iCnt++;
		iRet = PD_FOUND;
	
	}
	while(PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getintbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )381;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getintbank_error;
}


	
	

	if (iRet == PD_FOUND) {
DEBUGLOG(("GetBankByBankName found unique record\n"));
	}
	else{
DEBUGLOG(("GetBankByBankName found duplicate or No record\n"));
	}

DEBUGLOG(("GetBankByBankName: Normal Exit\n"));
	return iRet;

getintbank_error:
DEBUGLOG(("getintbank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getintbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )396;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}




