
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "MerchantBalance.pc"
};


static unsigned int sqlctx = 19569907;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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

 static char *sq0006 = 
"select m_current_bal_settlement , m_total_float_settlement , m_total_hold_s\
ettlement , m_total_reserved_amount , m_settlement_in_transit , m_current_bal\
 from merchant_balance where m_merchant_id = :b0 and m_currency_id = :b1 and \
m_country_id = :b2 and m_service_code = :b3 for update ";

 static char *sq0007 = 
"select m_current_bal , m_current_bal_settlement , m_total_hold , m_total_ho\
ld_settlement , m_total_reserved_amount from merchant_balance where m_merchan\
t_id = :b0 and m_currency_id = :b1 and m_country_id = :b2 and m_service_code \
= :b3 for update ";

 static char *sq0008 = 
"select current_bal , total_float , security_bal , m_fundin_payout , m_reser\
ved_payout , ava_po from merchant_balance_view where m_merchant_id = :b0 and \
m_currency_id = :b1 and m_country_id = :b2 and m_service_code = :b3          \
  ";

 static char *sq0009 = 
"select current_bal , total_float , security_bal , m_fundin_payout , m_reser\
ved_payout , ava_po , remaining_po_amount , remaining_po_amount_with_fee , me\
rchant_ava_po , appro_po_fee_rate from merchant_balance_view where m_merchant\
_id = :b0 and m_currency_id = :b1 and m_country_id = :b2 and m_service_code =\
 :b3            ";

 static char *sq0011 = 
"select m_total_float , m_current_bal , m_total_reserved_amount , m_total_ho\
ld , m_total_float_settlement , m_current_bal_settlement , m_total_hold_settl\
ement , m_total_float_after_payout , m_fundin_payout , m_reserved_payout from\
 merchant_balance where m_merchant_id = :b0 and m_currency_id = :b1 and m_cou\
ntry_id = :b2 and m_service_code = :b3            ";

 static char *sq0017 = 
"select m_current_bal , m_total_float , m_total_hold , m_current_bal_settlem\
ent , m_total_float_settlement , m_total_hold_settlement , m_total_float_afte\
r_payout , m_total_reserved_amount , m_fundin_payout , m_reserved_payout from\
 merchant_balance where m_merchant_id = :b0 and m_currency_id = :b1 and m_cou\
ntry_id = :b2 and m_service_code = :b3 for update ";

 static char *sq0027 = 
"select m_total_float , m_current_bal , m_total_reserved_amount , m_total_ho\
ld , m_total_float_settlement , m_current_bal_settlement , m_total_hold_settl\
ement , m_total_float_after_payout , m_fundin_payout , m_reserved_payout from\
 merchant_balance where m_merchant_id = :b0 and m_currency_id = :b1 and m_cou\
ntry_id = :b2 and m_service_code = :b3 for update ";

 static char *sq0032 = 
"select m_current_bal_settlement , m_total_float_settlement , m_total_hold_s\
ettlement , m_total_reserved_amount , m_settlement_in_transit , m_current_bal\
 from merchant_balance where m_merchant_id = :b0 and m_currency_id = :b1 and \
m_country_id = :b2 and m_service_code = :b3            ";

 static char *sq0033 = 
"select m_current_bal_settlement , m_total_float_settlement , m_total_hold_s\
ettlement , m_total_reserved_amount , m_current_bal from merchant_balance whe\
re m_merchant_id = :b0 and m_currency_id = :b1 and m_country_id = :b2 and m_s\
ervice_code = :b3            ";

 static char *sq0035 = 
"select m_settlement_in_transit from merchant_balance where m_merchant_id = \
:b0 and m_currency_id = :b1 and m_country_id = :b2 and m_service_code = :b3 f\
or update ";

 static char *sq0036 = 
"select m_current_bal , m_current_bal_settlement , m_total_hold , m_total_ho\
ld_settlement , m_total_reserved_amount from merchant_balance where m_merchan\
t_id = :b0 and m_currency_id = :b1 and m_country_id = :b2 and m_service_code \
= :b3            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,222,0,6,94,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,
44,0,0,2,287,0,6,210,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,
0,0,1,4,0,0,1,9,0,0,
91,0,0,3,248,0,6,321,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,
0,0,1,9,0,0,
134,0,0,4,241,0,6,431,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
177,0,0,5,242,0,6,541,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
220,0,0,6,284,0,9,652,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
251,0,0,6,0,0,13,654,0,0,6,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,
290,0,0,6,0,0,15,690,0,0,0,0,0,1,0,
305,0,0,6,0,0,15,699,0,0,0,0,0,1,0,
320,0,0,7,246,0,9,767,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
351,0,0,7,0,0,13,769,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
386,0,0,7,0,0,15,802,0,0,0,0,0,1,0,
401,0,0,7,0,0,15,811,0,0,0,0,0,1,0,
416,0,0,8,231,0,9,884,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
447,0,0,8,0,0,13,886,0,0,6,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,
486,0,0,8,0,0,15,922,0,0,0,0,0,1,0,
501,0,0,8,0,0,15,931,0,0,0,0,0,1,0,
516,0,0,9,322,0,9,1018,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
547,0,0,9,0,0,13,1020,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
602,0,0,9,0,0,15,1084,0,0,0,0,0,1,0,
617,0,0,9,0,0,15,1093,0,0,0,0,0,1,0,
632,0,0,10,247,0,6,1164,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
675,0,0,11,356,0,9,1289,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
706,0,0,11,0,0,13,1291,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
761,0,0,11,0,0,15,1374,0,0,0,0,0,1,0,
776,0,0,11,0,0,15,1383,0,0,0,0,0,1,0,
791,0,0,12,241,0,6,1454,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
834,0,0,13,243,0,6,1568,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
877,0,0,14,244,0,6,1582,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
920,0,0,15,242,0,6,1600,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
963,0,0,16,244,0,6,1614,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1006,0,0,17,356,0,9,1755,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1037,0,0,17,0,0,13,1757,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1092,0,0,17,0,0,15,1823,0,0,0,0,0,1,0,
1107,0,0,17,0,0,15,1857,0,0,0,0,0,1,0,
1122,0,0,18,228,0,6,1930,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1165,0,0,19,248,0,6,2035,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1208,0,0,20,244,0,6,2143,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1251,0,0,21,244,0,6,2251,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1294,0,0,22,244,0,6,2359,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1337,0,0,23,244,0,6,2468,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1380,0,0,24,237,0,6,2578,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1423,0,0,25,227,0,6,2689,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1466,0,0,26,243,0,6,2792,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1509,0,0,27,356,0,9,2915,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1540,0,0,27,0,0,13,2917,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1595,0,0,27,0,0,15,3000,0,0,0,0,0,1,0,
1610,0,0,27,0,0,15,3009,0,0,0,0,0,1,0,
1625,0,0,28,244,0,6,3078,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1668,0,0,29,241,0,6,3187,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1711,0,0,30,242,0,6,3296,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1754,0,0,31,295,0,6,3416,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
1805,0,0,32,284,0,9,3526,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1836,0,0,32,0,0,13,3528,0,0,6,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,
1875,0,0,32,0,0,15,3562,0,0,0,0,0,1,0,
1890,0,0,32,0,0,15,3571,0,0,0,0,0,1,0,
1905,0,0,33,258,0,9,3639,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1936,0,0,33,0,0,13,3641,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1971,0,0,33,0,0,15,3674,0,0,0,0,0,1,0,
1986,0,0,33,0,0,15,3683,0,0,0,0,0,1,0,
2001,0,0,34,229,0,6,3754,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
2044,0,0,35,162,0,9,3846,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
2075,0,0,35,0,0,13,3848,0,0,1,0,0,1,0,2,4,0,0,
2094,0,0,35,0,0,15,3866,0,0,0,0,0,1,0,
2109,0,0,35,0,0,15,3875,0,0,0,0,0,1,0,
2124,0,0,36,246,0,9,3941,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
2155,0,0,36,0,0,13,3943,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2190,0,0,36,0,0,15,3973,0,0,0,0,0,1,0,
2205,0,0,36,0,0,15,3982,0,0,0,0,0,1,0,
2220,0,0,0,0,0,56,4085,0,0,1,1,0,1,0,3,102,0,0,
2239,0,0,37,299,0,6,4087,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,9,0,0,2,102,0,0,
2290,0,0,0,0,0,13,4105,0,0,11,1,0,1,0,1,102,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2349,0,0,0,0,0,15,4207,0,0,1,1,0,1,0,1,102,0,0,
2368,0,0,0,0,0,78,4208,0,0,1,1,0,1,0,3,102,0,0,
2387,0,0,0,0,0,15,4216,0,0,1,1,0,1,0,1,102,0,0,
2406,0,0,0,0,0,78,4217,0,0,1,1,0,1,0,3,102,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/01/07              LokMan Chow
Add UpdateFloat					   2011/04/15		   Cody Chan
Split one bal into two				   2012/08/09		   Cody Chan
Add Add						   2012/12/07		   Stan Poon
Add GetCurrBalance for Deposit Refund		   2013/02/18		   Stan Poon
Add settlement_in_transit			   2013/08/06		   LokMan Chow
Add UpdateFloatRet function                        2020/03/06              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchantBalance.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void MerchantBalance(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("Add:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("Add:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("Add:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_country_id:ind_country_id,
				:hv_service_code:ind_service_code,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert ( :hv_\
merchant_id:ind_merchant_id , :hv_ccy_id:ind_ccy_id , :hv_country_id:ind_coun\
try_id , :hv_service_code:ind_service_code , :hv_create_user:ind_create_user \
) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		//TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		//TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	//TxnAbort();
	return PD_ERR;
}


int UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dNetAmt,
		double  dReservedAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatefloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_net_amt;
		double		hv_reserved_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_net_amt = -1;
		short		ind_reserved_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateFloat:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_net_amt= dNetAmt;
	ind_net_amt= 0;
DEBUGLOG(("UpdatFloat:net_amt = [%f]\n",hv_net_amt));

	hv_reserved_amt= dReservedAmt;
	ind_reserved_amt= 0;
DEBUGLOG(("UpdatFloat:resreved_amt = [%f]\n",hv_reserved_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_insert_fl(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_net_amt:ind_net_amt,
				:hv_reserved_amt:ind_reserved_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert_fl ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_net_amt:ind_net_amt , :hv\
_reserved_amt:ind_reserved_amt , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_net_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_reserved_amt;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_reserved_amt;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_create_user;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatefloat_error;
}




DEBUGLOG(("UpdateFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatefloat_error:
DEBUGLOG(("updatefloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;


}

int UpdateSettFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dFloat,
		const char* csUser)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatesettfloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_float;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_float= -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateSettFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateSettFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateSettFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateSettFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateSettFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_float= dFloat;
	ind_float= 0;
DEBUGLOG(("UpdatSettFloat:float = [%f]\n",hv_float));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateSettFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_sett_fl_in(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_float:ind_float,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_sett_fl_in ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_float:ind_float , :hv_cr\
eate_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )91;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_float;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_float;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatesettfloat_error;
}




DEBUGLOG(("UpdateSettFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateSettFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateSettFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateSettFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatesettfloat_error:
DEBUGLOG(("updatesettfloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int ReleaseFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dBal,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO releasefl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_bal;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_bal = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ReleaseFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("ReleaseFloat:merchant id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("ReleaseFloat:country_id = [%.*s][%d]\n",hv_country_id.len,hv_country_id.arr,hv_country_id.len));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("ReleaseFloat:ccy_id = [%.*s][%d]\n",hv_ccy_id.len,hv_ccy_id.arr,hv_ccy_id.len));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("ReleaseFloat:service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

	hv_bal= dBal;
	ind_bal= 0;
DEBUGLOG(("ReleaseFloat:aval bal = [%f]\n",hv_bal));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("ReleaseFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_release(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_bal:ind_bal,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_release ( :hv\
_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind\
_ccy_id , :hv_service_code:ind_service_code , :hv_bal:ind_bal , :hv_create_us\
er:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )134;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto releasefl_error;
}




DEBUGLOG(("ReleaseFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("ReleaseFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::ReleaseFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("ReleaseFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::ReleaseFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("ReleaseFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

releasefl_error:
DEBUGLOG(("releasefl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int ReleaseSettFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dBal,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO releasesettfl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_bal;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_bal = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ReleaseSettFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("ReleaseSettFloat:merchant id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("ReleaseSettFloat:country_id = [%.*s][%d]\n",hv_country_id.len,hv_country_id.arr,hv_country_id.len));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("ReleaseSettFloat:ccy_id = [%.*s][%d]\n",hv_ccy_id.len,hv_ccy_id.arr,hv_ccy_id.len));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("ReleaseSettFloat:service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

	hv_bal= dBal;
	ind_bal= 0;
DEBUGLOG(("ReleaseSettFloat:aval bal = [%f]\n",hv_bal));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("ReleaseSettFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_rls_stfl(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_bal:ind_bal,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_rls_stfl ( :h\
v_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:in\
d_ccy_id , :hv_service_code:ind_service_code , :hv_bal:ind_bal , :hv_create_u\
ser:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )177;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto releasesettfl_error;
}




DEBUGLOG(("ReleaseSettFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("ReleaseSettFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::ReleaseSettFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("ReleaseSettFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::ReleaseSettFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("ReleaseSettFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

releasesettfl_error:
DEBUGLOG(("releasesettfl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int GetSettAvalBalance(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getsettavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_current_bal_sett;
		double		v_total_float_sett;
		double		v_total_hold_sett;
		double		v_total_reserved_sett;
		double		v_sett_in_transit;

		short		ind_current_bal= -1;
		short		ind_current_bal_sett= -1;
		short		ind_total_float_sett= -1;
		short		ind_total_hold_sett= -1;
		short		ind_total_reserved_sett= -1;
		short		ind_sett_in_transit= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetSettAvalBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetSettAvalBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetSettAvalBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetSettAvalBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getsettavalbal CURSOR FOR
                select	m_current_bal_settlement,
			m_total_float_settlement,
			m_total_hold_settlement,
			m_total_reserved_amount,
			m_settlement_in_transit,
			m_current_bal
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code
		 for update; */ 


        /* EXEC SQL OPEN c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )220;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsettavalbal
                INTO
			:v_current_bal_sett:ind_current_bal_sett,
			:v_total_float_sett:ind_total_float_sett,
			:v_total_hold_sett:ind_total_hold_sett,
			:v_total_reserved_sett:ind_total_reserved_sett,
			:v_sett_in_transit:ind_sett_in_transit,
			:v_current_bal:ind_current_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )251;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_reserved_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_reserved_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_sett_in_transit;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_sett_in_transit;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal;
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
                if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal_sett<0)
			v_current_bal_sett = 0.0;
                if(ind_total_float_sett<0)
			v_total_float_sett= 0.0;
                if(ind_total_hold_sett<0)
			v_total_hold_sett= 0.0;
                if(ind_total_reserved_sett<0)
			v_total_reserved_sett= 0.0;
                if(ind_current_bal<0)
			v_current_bal= 0.0;
		if(ind_sett_in_transit<0)
			v_sett_in_transit=0.0;

		*dBal=v_current_bal_sett-v_total_float_sett-v_total_hold_sett-v_total_reserved_sett-v_sett_in_transit;
DEBUGLOG(("GetSettAvalBalance balance = [%f]\n",*dBal));

		PutField_Double(hContext,"merchant_open_bal",v_current_bal);
		PutField_Double(hContext,"merchant_open_bal_settlement",v_current_bal_sett);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )290;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}



DEBUGLOG(("GetSettAvalBalance Normal Exit\n"));
	return iRet;

getsettavalbal_error:
DEBUGLOG(("getsettavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )305;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetCurrBalance(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_current_bal_sett;
		double		v_total_hold;
		double		v_total_hold_sett;
		double		v_total_reserved_amt;

		short		ind_current_bal= -1;
		short		ind_current_bal_sett= -1;
		short		ind_total_hold= -1;
		short		ind_total_hold_sett= -1;
		short		ind_total_reserved_amt= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getcurrbal CURSOR FOR
                select	m_current_bal,
                	m_current_bal_settlement,
			m_total_hold,
			m_total_hold_settlement,
			m_total_reserved_amount
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code
		 for update; */ 


        /* EXEC SQL OPEN c_cursor_getcurrbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )320;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getcurrbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrbal
                INTO
			:v_current_bal:ind_current_bal,
			:v_current_bal_sett:ind_current_bal_sett,
			:v_total_hold:ind_total_hold,
			:v_total_hold_sett:ind_total_hold_sett,
			:v_total_reserved_amt:ind_total_reserved_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )351;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_reserved_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_reserved_amt;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getcurrbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal<0)
			v_current_bal= 0.0;
                if(ind_current_bal_sett<0)
			v_current_bal_sett = 0.0;
                if(ind_total_hold<0)
			v_total_hold= 0.0;
                if(ind_total_hold_sett<0)
			v_total_hold_sett= 0.0;
                if(ind_total_reserved_amt<0)
			v_total_reserved_amt= 0.0;

		*dBal=v_current_bal+v_current_bal_sett-v_total_hold-v_total_hold_sett-v_total_reserved_amt;
DEBUGLOG(("GetCurrBalance balance = [%f]\n",*dBal));

		PutField_Double(hContext,"merchant_open_bal",v_current_bal);
		PutField_Double(hContext,"merchant_open_bal_settlement",v_current_bal_sett);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )386;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrbal_error;
}



DEBUGLOG(("GetCurrBalance Normal Exit\n"));
	return iRet;

getcurrbal_error:
DEBUGLOG(("getcurrbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcurrbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )401;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	TxnAbort();
        return PD_ERR;
}


int GetPOAvalBalance(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getpoavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_reserved_po;
		double		v_total_float;
		double		v_ava_po;
		double		v_total_hold;
		double		v_fundin;

		short		ind_current_bal= -1;
		short		ind_reserved_po= -1;
		short		ind_total_float= -1;
		short		ind_ava_po= -1;
		short		ind_total_hold= -1;
		short		ind_fundin = -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetPOAvalBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetPOAvalBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetPOAvalBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetPOAvalBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


        /* EXEC SQL DECLARE c_cursor_getpoavalbal CURSOR FOR
                select	current_bal,
			total_float,
			security_bal,
			m_fundin_payout,
			m_reserved_payout,
			ava_po
                  from merchant_balance_view
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code; */ 



        /* EXEC SQL OPEN c_cursor_getpoavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )416;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getpoavalbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpoavalbal
                INTO
			:v_current_bal:ind_current_bal,
			:v_total_float:ind_total_float,
			:v_total_hold:ind_total_hold,
			:v_fundin:ind_fundin,
			:v_reserved_po:ind_reserved_po,
			:v_ava_po:ind_ava_po; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )447;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_fundin;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_fundin;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_reserved_po;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_reserved_po;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ava_po;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ava_po;
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
                if (sqlca.sqlcode < 0) goto getpoavalbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal<0)
			v_current_bal = 0.0;
		if(ind_total_float<0)
			v_total_float = 0.0;
		if(ind_reserved_po<0)
			v_reserved_po = 0.0;
		if(ind_total_hold<0)
			v_total_hold = 0.0;
		if(ind_ava_po)
			v_ava_po = 0.0;
		if(ind_fundin)
			v_fundin = 0.0;

		*dBal=v_ava_po;
DEBUGLOG(("GetPOAvalBalance balance = [%f]\n",*dBal));

		PutField_Double(hContext,"fundin_po",v_fundin);
DEBUGLOG(("GetPOAvalBalance FundIn = [%f]\n",v_fundin));

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpoavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )486;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpoavalbal_error;
}



DEBUGLOG(("GetPOAvalBalance Normal Exit\n"));
	return iRet;

getpoavalbal_error:
DEBUGLOG(("getpoavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpoavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )501;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	TxnAbort();
        return PD_ERR;
}


int GetRemainPOBalance(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getremainpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_reserved_po;
		double		v_total_float;
		double		v_ava_po;
		double		v_total_hold;
		double		v_fundin;
		double		v_remain_po;
		double		v_remain_po_with_fee;
		double		v_fee_rate;
		double          v_merchant_ava_po;
		//double		v_ava_po_percentage;

		short		ind_current_bal= -1;
		short		ind_reserved_po= -1;
		short		ind_total_float= -1;
		short		ind_ava_po= -1;
		short		ind_total_hold= -1;
		short		ind_fundin = -1;
		short		ind_remain_po = -1;
		short		ind_remain_po_with_fee = -1;
		short		ind_fee_rate = -1;
		short           ind_merchant_ava_po= -1;
		//short		ind_ava_po_percentage = -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetRemainPOBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetRemainPOBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetRemainPOBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetRemainPOBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


        /* EXEC SQL DECLARE c_cursor_getremainpo CURSOR FOR
                select	current_bal,
			total_float,
			security_bal,
			m_fundin_payout,
			m_reserved_payout,
			ava_po,
			remaining_po_amount,
			remaining_po_amount_with_fee,
			merchant_ava_po,
			appro_po_fee_rate
                  from merchant_balance_view
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code; */ 



        /* EXEC SQL OPEN c_cursor_getremainpo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )516;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getremainpo_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getremainpo
                INTO
			:v_current_bal:ind_current_bal,
			:v_total_float:ind_total_float,
			:v_total_hold:ind_total_hold,
			:v_fundin:ind_fundin,
			:v_reserved_po:ind_reserved_po,
			:v_ava_po:ind_ava_po,
			:v_remain_po:ind_remain_po,
			:v_remain_po_with_fee:ind_remain_po_with_fee,
			:v_merchant_ava_po:ind_merchant_ava_po,
			:v_fee_rate:ind_fee_rate; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )547;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_fundin;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_fundin;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_reserved_po;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_reserved_po;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ava_po;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ava_po;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_remain_po;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_remain_po;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_remain_po_with_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_remain_po_with_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_ava_po;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_merchant_ava_po;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_fee_rate;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_fee_rate;
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
                if (sqlca.sqlcode < 0) goto getremainpo_error;
}


			//:v_ava_po_percentage:ind_ava_po_percentage;

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal<0)
			v_current_bal = 0.0;
		if(ind_total_float<0)
			v_total_float = 0.0;
		if(ind_reserved_po<0)
			v_reserved_po = 0.0;
		if(ind_total_hold<0)
			v_total_hold = 0.0;
		if(ind_ava_po)
			v_ava_po = 0.0;
		if(ind_fundin)
			v_fundin = 0.0;
		if(ind_remain_po)
			v_remain_po = 0.0;
		if(ind_remain_po_with_fee)
			v_remain_po_with_fee = 0.0;
		if(ind_merchant_ava_po)
                        v_merchant_ava_po = 0.0;
		if(ind_fee_rate)
			v_fee_rate = 0.0;

		*dBal=v_remain_po;
DEBUGLOG(("GetRemainPOBalance remain payout balance = [%f]\n",*dBal));

		PutField_Double(hContext,"merchant_aval_po",v_ava_po);
DEBUGLOG(("GetRemainPOBalance merchant_aval_po = [%f]\n",v_ava_po));
		PutField_Double(hContext,"merchant_reserved_po",v_reserved_po);
DEBUGLOG(("GetRemainPOBalance merchant_reserved_po = [%f]\n",v_reserved_po));
		PutField_Double(hContext,"merchant_fundin_po",v_fundin);
DEBUGLOG(("GetRemainPOBalance merchant_fundin_po = [%f]\n",v_fundin));
		double dAmt = v_ava_po-v_reserved_po-v_fundin;
		if(dAmt < 0.0)
			dAmt = 0.0;
		PutField_Double(hContext,"merchant_net_float",dAmt);
DEBUGLOG(("GetRemainPOBalance merchant_net_float = [%f]\n",dAmt));

		PutField_Double(hContext,"merchant_remain_po_with_fee",v_remain_po_with_fee);
DEBUGLOG(("GetRemainPOBalance remain_po_with_fee = [%f]\n",v_remain_po_with_fee));
		PutField_Double(hContext,"approximate_fee_rate",v_fee_rate);
DEBUGLOG(("GetRemainPOBalance = [%f]\n",v_fee_rate));
		PutField_Double(hContext,"merchant_remain_aval_po",v_merchant_ava_po);
DEBUGLOG(("GetRemainPOBalance merchant_remain_aval_po = [%f]\n",v_merchant_ava_po));
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getremainpo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )602;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getremainpo_error;
}



DEBUGLOG(("GetRemainPOBalance Normal Exit\n"));
	return iRet;

getremainpo_error:
DEBUGLOG(("getremainpo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getremainpo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )617;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	TxnAbort();
        return PD_ERR;
}


int UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dFloat,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatereserved_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_float;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_float = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("UpdateReserved: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateReserved:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateReserved:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateReserved:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateReserved:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_float= dFloat;
	ind_float= 0;
DEBUGLOG(("UpdateReserved:float = [%f]\n",hv_float));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateReserved:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_insert_rs(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_float:ind_float,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert_rs ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_float:ind_float , :hv_cre\
ate_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )632;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_float;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_float;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatereserved_error;
}




DEBUGLOG(("UpdateReserved:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateReserved:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateReserved: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateReserved: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateReserved: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateReserved: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatereserved_error:
DEBUGLOG(("updatereserved_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;


}


int GetCurrentValues(const char* csMerchantID,
			const char* csCurrencyId, 
			const char* csCountryId,
			const char* csServiceCode,
			hash_t *hVal)
{
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrval_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_total_float;
		double		v_current_bal;
		double		v_total_reserved_amount;
		double		v_total_hold;

		double		v_total_float_settlement;
		double		v_current_bal_settlement;
		double		v_total_hold_settlement;

		double		v_fundin_payout;
		double		v_reserved_payout;
		double		v_total_float_after_payout;

		short		ind_total_float = -1;
		short		ind_current_bal= -1;
		short		ind_total_reserved_amount= -1;
		short		ind_total_hold= -1;

		short		ind_total_float_settlement = -1;
		short		ind_current_bal_settlement= -1;
		short		ind_total_hold_settlement= -1;

		short		ind_total_float_after_payout = -1;
		short		ind_fundin_payout = -1;
		short		ind_reserved_payout = -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrentValues merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrentValues ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrentValues country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrentValues service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        
        /* EXEC SQL DECLARE c_cursor_getcurrval CURSOR FOR
                select 	m_total_float,
			m_current_bal,
			m_total_reserved_amount,
			m_total_hold,
			m_total_float_settlement,
			m_current_bal_settlement,
			m_total_hold_settlement,
			m_total_float_after_payout,
			m_fundin_payout,
                        m_reserved_payout
                  from 	merchant_balance
		 where 	m_merchant_id = :hv_merchant_id
		   and 	m_currency_id = :hv_ccy_id
		   and	m_country_id = :hv_country_id
		   and	m_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0011;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )675;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrval
                INTO
			:v_total_float:ind_total_float,
			:v_current_bal:ind_current_bal,
			:v_total_reserved_amount:ind_total_reserved_amount,
			:v_total_hold:ind_total_hold,
			:v_total_float_settlement:ind_total_float_settlement,
			:v_current_bal_settlement:ind_current_bal_settlement,
			:v_total_hold_settlement:ind_total_hold_settlement,
			:v_total_float_after_payout:ind_total_float_after_payout,
			:v_fundin_payout:ind_fundin_payout,
			:v_reserved_payout:ind_reserved_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )706;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_total_float;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_current_bal;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_reserved_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_hold;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal_settlement;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_float_after_payout;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_reserved_payout;
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
                if (sqlca.sqlcode < 0) goto getcurrval_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

//total_float 
                if(ind_total_float<0)
			v_total_float = 0.0;
		PutField_Double(hVal,"total_float",v_total_float);
DEBUGLOG(("GetCurrentValues float = [%f]\n",v_total_float));
		
//current_bal
                if(ind_current_bal<0)
			v_current_bal = 0.0;
		PutField_Double(hVal,"current_bal",v_current_bal);
DEBUGLOG(("GetCurrentValues current_bal = [%f]\n",v_current_bal));


//total_reserved_amount
                if(ind_total_reserved_amount<0)
			v_total_reserved_amount= 0.0;
		PutField_Double(hVal,"total_reserved_amount",v_total_reserved_amount);
DEBUGLOG(("GetCurrentValues total_reserved_amount = [%f]\n",v_total_reserved_amount));

//total_hold
                if(ind_total_hold<0)
			v_total_hold= 0;
		PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetCurrentValues total_hold = [%f]\n",v_total_hold));


//total_float_settlement 
                if(ind_total_float_settlement<0)
			v_total_float_settlement = 0.0;
		PutField_Double(hVal,"total_float_settlement",v_total_float_settlement);
DEBUGLOG(("GetCurrentValues float_settlement = [%f]\n",v_total_float_settlement));

//current_bal_settlement
                if(ind_current_bal_settlement<0)
			v_current_bal_settlement = 0.0;
		PutField_Double(hVal,"current_bal_settlement",v_current_bal_settlement);
DEBUGLOG(("GetCurrentValues current_bal_settlement = [%f]\n",v_current_bal_settlement));

//total_hold_settlement
                if(ind_total_hold_settlement<0)
			v_total_hold_settlement= 0;
		PutField_Double(hVal,"total_hold_settlement",v_total_hold_settlement);
DEBUGLOG(("GetCurrentValues total_hold_settlement = [%f]\n",v_total_hold_settlement));

//total_float_after_payout 
                if(ind_total_float_after_payout<0)
			v_total_float_after_payout = 0.0;
		PutField_Double(hVal,"total_float_after_payout",v_total_float_after_payout);
DEBUGLOG(("GetCurrentValues float_after_payout = [%f]\n",v_total_float_after_payout));
		
//fundin payout
                if(ind_fundin_payout<0)
			v_fundin_payout= 0;
		PutField_Double(hVal,"fundin_payout",v_fundin_payout);
DEBUGLOG(("GetCurrentValues fundin_payout = [%f]\n",v_fundin_payout));

//reserved payout
                if(ind_reserved_payout<0)
			v_reserved_payout= 0;
		PutField_Double(hVal,"reserved_payout",v_reserved_payout);
DEBUGLOG(("GetCurrentValues reserved_payout = [%f]\n",v_reserved_payout));

        }

        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )761;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}



DEBUGLOG(("GetCurrentValues Normal Exit\n"));
	return iRet;

getcurrval_error:
DEBUGLOG(("getcurrval_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )776;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int UpdateCurrBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatecurrbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateCurrBal: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateCurrBal:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateCurrBal:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateCurrBal:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateCurrBal:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdateCurrBal:amt = [%f]\n",hv_amt));


	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateCurrBal:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_upd_bal(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_upd_bal ( :hv\
_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind\
_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create_us\
er:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )791;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatecurrbal_error;
}




DEBUGLOG(("UpdateCurrBal:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK){
DEBUGLOG(("UpdateCurrBal:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateCurrBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateCurrBal: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateCurrBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateCurrBal: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatecurrbal_error:
DEBUGLOG(("updatecurrbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int UpdateHoldBalance(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
		const char  cMHind,
		const char  cType,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatehold_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_hold;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_hold = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateHoldBalance: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateHoldBalance:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateHoldBalance:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateHoldBalance:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateHoldBalance:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_hold= dAmt;
	ind_hold= 0;
DEBUGLOG(("UpdateHoldBalance:hold = [%f]\n",hv_hold));
DEBUGLOG(("UpdateHoldBalance:hold_type = [%c]\n",cType));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateHoldBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	if(cType==PD_HOLD){

		if (cMHind == PD_TYPE_PAYOUT) {
			/* EXEC SQL EXECUTE
	    			BEGIN

				:hv_return_value := sp_merchant_bal_credit_hold(
					:hv_merchant_id:ind_merchant_id,
					:hv_country_id:ind_country_id,
					:hv_ccy_id:ind_ccy_id,
					:hv_service_code:ind_service_code,
					:hv_hold:ind_hold,
					:hv_create_user:ind_create_user);

	    			END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 10;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_credit_hold ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_creat\
e_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )834;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )17;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_service_code;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_hold;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[6] = (unsigned long )22;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto updatehold_error;
}


		} else {
			/* EXEC SQL EXECUTE
	    			BEGIN

				:hv_return_value := sp_merchant_bal_cr_hold_sett(
					:hv_merchant_id:ind_merchant_id,
					:hv_country_id:ind_country_id,
					:hv_ccy_id:ind_ccy_id,
					:hv_service_code:ind_service_code,
					:hv_hold:ind_hold,
					:hv_create_user:ind_create_user);

	    			END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 10;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_cr_hold_sett ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_crea\
te_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )877;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )17;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_service_code;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_hold;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[6] = (unsigned long )22;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto updatehold_error;
}


		}
	}
	else{

		if (cMHind == PD_TYPE_PAYOUT) {
			/* EXEC SQL EXECUTE
	    			BEGIN

				:hv_return_value := sp_merchant_bal_debit_hold(
					:hv_merchant_id:ind_merchant_id,
					:hv_country_id:ind_country_id,
					:hv_ccy_id:ind_ccy_id,
					:hv_service_code:ind_service_code,
					:hv_hold:ind_hold,
					:hv_create_user:ind_create_user);

	    			END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 10;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_debit_hold ( :h\
v_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:in\
d_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_create\
_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )920;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )17;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_service_code;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_hold;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[6] = (unsigned long )22;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto updatehold_error;
}


		} else {
			/* EXEC SQL EXECUTE
	    			BEGIN

				:hv_return_value := sp_merchant_bal_dr_hold_sett(
					:hv_merchant_id:ind_merchant_id,
					:hv_country_id:ind_country_id,
					:hv_ccy_id:ind_ccy_id,
					:hv_service_code:ind_service_code,
					:hv_hold:ind_hold,
					:hv_create_user:ind_create_user);

	    			END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 10;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_dr_hold_sett ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_crea\
te_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )963;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )17;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_service_code;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_hold;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[6] = (unsigned long )22;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto updatehold_error;
}


		}
		
	}


DEBUGLOG(("UpdateHoldBalance:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateHoldBalance:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateHoldBalance: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatehold_error:
DEBUGLOG(("updatehold_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;


}

int GetOpenBalanceForUpdate(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode)
{
	int iRet = PD_OK;
	double dBal = 0.0;
	double dFloat = 0.0;
	double dHold = 0.0;
	double dBalSettlement = 0.0;
	double dFloatSettlement = 0.0;
	double dHoldSettlement = 0.0;
	double dFloatAfterPayout = 0.0;
	double dReservedAmount = 0.0;
	double dFundInPayout = 0.0;
	double dReservedPayout = 0.0;

                
        /* EXEC SQL WHENEVER SQLERROR GOTO getopenbalforupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_total_float;
		double		v_total_hold;

		double		v_current_bal_settlement;
		double		v_total_float_settlement;
		double		v_total_hold_settlement;

		double		v_total_float_after_payout;
		double		v_total_reserved_amount;
		double		v_fundin_payout;
		double		v_reserved_payout;

		short		ind_current_bal= -1;
		short		ind_total_float= -1;
		short		ind_total_hold= -1;

		short		ind_current_bal_settlement= -1;
		short		ind_total_float_settlement= -1;
		short		ind_total_hold_settlement = -1;
        
		short		ind_total_float_after_payout = -1;
		short		ind_total_reserved_amount = -1;
		short 		ind_fundin_payout = -1;
		short 		ind_reserved_payout = -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetOpenBalanceForUpdate service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


        /* EXEC SQL DECLARE c_cursor_getopenbalforupdate CURSOR FOR
                select	m_current_bal,
			m_total_float,
                        m_total_hold,
                	m_current_bal_settlement,
			m_total_float_settlement,
                        m_total_hold_settlement,
			m_total_float_after_payout,
			m_total_reserved_amount,
			m_fundin_payout,
			m_reserved_payout
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code
		 for update; */ 



        /* EXEC SQL OPEN c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0017;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1006;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getopenbalforupdate
                INTO
			:v_current_bal:ind_current_bal,
			:v_total_float:ind_total_float,
			:v_total_hold:ind_total_hold,
			:v_current_bal_settlement:ind_current_bal_settlement,
			:v_total_float_settlement:ind_total_float_settlement,
			:v_total_hold_settlement:ind_total_hold_settlement,
			:v_total_float_after_payout:ind_total_float_after_payout,
			:v_total_reserved_amount:ind_total_reserved_amount,
			:v_fundin_payout:ind_fundin_payout,
			:v_reserved_payout:ind_reserved_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1037;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_current_bal_settlement;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_float_after_payout;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_reserved_amount;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_reserved_payout;
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
                if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if(ind_current_bal<0) {
			v_current_bal = 0.0;
		}
                if(ind_total_float<0) {
			v_total_float= 0.0;
		}
                if(ind_total_hold<0) {
			v_total_hold= 0.0;
		}

                if(ind_current_bal_settlement<0) {
			v_current_bal_settlement = 0.0;
		}
                if(ind_total_float_settlement<0) {
			v_total_float_settlement= 0.0;
		}
                if(ind_total_hold_settlement<0) {
			v_total_hold_settlement= 0.0;
		}

		if(ind_total_float_after_payout<0) {
			v_total_float_after_payout= 0.0;
		}
		if(ind_total_reserved_amount <0) {
			v_total_reserved_amount= 0.0;
		}
		if(ind_fundin_payout <0) {
			v_fundin_payout = 0.0;
		}
		if(ind_reserved_payout <0) {
			v_reserved_payout = 0.0;
		}


		dBal = v_current_bal;
		dFloat = v_total_float;
		dHold = v_total_hold;

		dBalSettlement = v_current_bal_settlement;
		dFloatSettlement = v_total_float_settlement;
		dHoldSettlement = v_total_hold_settlement;

		dFloatAfterPayout = v_total_float_after_payout;
		dReservedAmount = v_total_reserved_amount;
		dFundInPayout = v_fundin_payout;
		dReservedPayout = v_reserved_payout;
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1092;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}



DEBUGLOG(("GetOpenBalanceForUpdate open_bal = [%f]\n",dBal));
		PutField_Double(hContext,"merchant_open_bal",dBal);
DEBUGLOG(("GetOpenBalanceForUpdate total_float = [%f]\n",dFloat));
		PutField_Double(hContext,"total_float",dFloat);
DEBUGLOG(("GetOpenBalanceForUpdate total_hold = [%f]\n",dHold));
		PutField_Double(hContext,"total_hold",dHold);

DEBUGLOG(("GetOpenBalanceForUpdate open_bal_settlement = [%f]\n",dBalSettlement));
		PutField_Double(hContext,"merchant_open_bal_settlement",dBalSettlement);
DEBUGLOG(("GetOpenBalanceForUpdate total_float_settlement = [%f]\n",dFloatSettlement));
		PutField_Double(hContext,"total_float_settlement",dFloatSettlement);
DEBUGLOG(("GetOpenBalanceForUpdate total_hold_settlement = [%f]\n",dHoldSettlement));
		PutField_Double(hContext,"total_hold_settlement",dHoldSettlement);

DEBUGLOG(("GetOpenBalanceForUpdate total_float_after_payout = [%f]\n",dFloatAfterPayout));
		PutField_Double(hContext,"total_float_after_payout",dFloatAfterPayout);
DEBUGLOG(("GetOpenBalanceForUpdate total_reserved_amount = [%f]\n",dReservedAmount));
		PutField_Double(hContext,"reserved_amount",dReservedAmount);
DEBUGLOG(("GetOpenBalanceForUpdate fundin_payout = [%f]\n",dFundInPayout));
		PutField_Double(hContext,"fundin_payout",dFundInPayout);
DEBUGLOG(("GetOpenBalanceForUpdate reserved_payout = [%f]\n",dReservedPayout));
		PutField_Double(hContext,"reserved_payout",dReservedPayout);



DEBUGLOG(("GetOpenBalanceForUpdate Normal Exit\n"));
	return iRet;

getopenbalforupdate_error:
DEBUGLOG(("getopenbalforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1107;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	TxnAbort();
        return PD_ERR;
}

int UpdateSettBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cType,
                const char* csUser)
                
{

        /* EXEC SQL WHENEVER SQLERROR GOTO upd_sett_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateSettBal: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;

        if(cType==PD_IND_DEBIT){
        	hv_amt = (-1)*(dAmt + dFee);
        	ind_amt= 0;
	}
	else{
		hv_amt = dAmt - dFee;
        	ind_amt= 0;
	}
DEBUGLOG(("UpdateSettBal:amt = [%f]\n",dAmt));
DEBUGLOG(("UpdateSettBal:fee = [%f]\n",dFee));
DEBUGLOG(("UpdateSettBal:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateSettBal:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_bal_upd_sett_bal(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_up\
d_sett_bal ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id \
, :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt\
 , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1122;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto upd_sett_error;
}



        if (hv_return_value == SP_OK)        {
DEBUGLOG(("UpdateSettBal:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateSettBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettBal: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateSettBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettBal: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }
upd_sett_error:
DEBUGLOG(("upd_sett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        TxnAbort();
        return PD_ERR;
}


int UpdateAfterPayoutFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dFloat,
		const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO updateafterpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_float;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_float = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateAfterPayoutFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateAfterPayoutFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateAfterPayoutFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateAfterPayoutFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateAfterPayoutFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_float= dFloat;
	ind_float= 0;
DEBUGLOG(("UpdateAfterPayoutFloat:float = [%f]\n",hv_float));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateAfterPayoutFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_after_pofl(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_float:ind_float,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_after_pofl ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_float:ind_float , :hv_cr\
eate_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1165;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_float;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_float;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updateafterpo_error;
}




DEBUGLOG(("UpdateAfterPayoutFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateAfterPayoutFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateAfterPayoutFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateAfterPayoutFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateAfterPayoutFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateAfterPayoutFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updateafterpo_error:
DEBUGLOG(("updateafterpo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int SetFundInPayout(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO setfundinpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("SetFundInPayout: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("SetFundInPayout:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("SetFundInPayout:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("SetFundInPayout:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("SetFundInPayout:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("SetFundInPayout:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("SetFundInPayout:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_add_fin_po(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_add_fin_po ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create\
_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1208;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto setfundinpo_error;
}




DEBUGLOG(("SetFundInPayout:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("SetFundInPayout:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::SetFundInPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("SetFundInPayout: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::SetFundInPayout: SP_ERR TxnAbort\n");
DEBUGLOG(("SetFundInPayout: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

setfundinpo_error:
DEBUGLOG(("setfundinpo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int UpdateFundInPayout(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO updatefundinpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateFundInPayout: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateFundInPayout:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateFundInPayout:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateFundInPayout:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateFundInPayout:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdateFundInPayout:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateFundInPayout:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_upd_fin_po(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_upd_fin_po ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create\
_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1251;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatefundinpo_error;
}




DEBUGLOG(("UpdateFundInPayout:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateFundInPayout:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateFundInPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateFundInPayout: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateFundInPayout: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateFundInPayout: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatefundinpo_error:
DEBUGLOG(("updatefundinpo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int SetPayoutReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO setpores_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("SetPayoutReserved: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("SetPayoutReserved:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("SetPayoutReserved:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("SetPayoutReserved:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("SetPayoutReserved:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("SetPayoutReserved:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("SetPayoutReserved:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_set_po_res(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_set_po_res ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create\
_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1294;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto setpores_error;
}




DEBUGLOG(("SetPayoutReserved:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("SetPayoutReserved:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::SetPayoutReserved: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("SetPayoutReserved: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::SetPayoutReserved: SP_ERR TxnAbort\n");
DEBUGLOG(("SetPayoutReserved: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

setpores_error:
DEBUGLOG(("setpores_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int UpdatePayoutReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO updpores_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdatePayoutReserved: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdatePayoutReserved:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdatePayoutReserved:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdatePayoutReserved:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdatePayoutReserved:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdatePayoutReserved:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdatePayoutReserved:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_upd_po_res(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_upd_po_res ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create\
_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1337;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updpores_error;
}




DEBUGLOG(("UpdatePayoutReserved:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdatePayoutReserved:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdatePayoutReserved: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdatePayoutReserved: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdatePayoutReserved: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdatePayoutReserved: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updpores_error:
DEBUGLOG(("updpores_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int ReleaseReserve(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dBal,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO releaseres_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_bal;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_bal = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ReleaseReserve: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("ReleaseReserve:merchant id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("ReleaseReserve:country_id = [%.*s][%d]\n",hv_country_id.len,hv_country_id.arr,hv_country_id.len));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("ReleaseReserve:ccy_id = [%.*s][%d]\n",hv_ccy_id.len,hv_ccy_id.arr,hv_ccy_id.len));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("ReleaseReserve:service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

	hv_bal= dBal;
	ind_bal= 0;
DEBUGLOG(("ReleaseReserve:aval bal = [%f]\n",hv_bal));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("ReleaseReserve:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_release_res(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_bal:ind_bal,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_release_res ( :hv_mer\
chant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy\
_id , :hv_service_code:ind_service_code , :hv_bal:ind_bal , :hv_create_user:i\
nd_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1380;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto releaseres_error;
}




DEBUGLOG(("ReleaseReserve:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("ReleaseReserve:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::ReleaseReserve: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("ReleaseReserve: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::ReleaseReserve: SP_ERR TxnAbort\n");
DEBUGLOG(("ReleaseFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

releaseres_error:
DEBUGLOG(("releaseres_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int UpdateAdjBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dNetAmt,
                char    cType,
                const char* csUser)
                
{

        /* EXEC SQL WHENEVER SQLERROR GOTO upd_adj_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateAdjBal: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;

        if(cType==PD_IND_DEBIT){
        	hv_amt = (-1)*dNetAmt;
        	ind_amt= 0;
	}
	else{
		hv_amt = dNetAmt;
        	ind_amt= 0;
	}
DEBUGLOG(("UpdateAdjBal:Netamt = [%f]\n",dNetAmt));
DEBUGLOG(("UpdateAdjBal:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateAdjBal:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

//DEBUGLOG(("UpdateAdjBal:TESTIING\n"));

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_bal_upd_adj_bal(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_up\
d_adj_bal ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id ,\
 :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt \
, :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1423;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto upd_adj_error;
}



        if (hv_return_value == SP_OK)        {
DEBUGLOG(("UpdateAdjBal:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateAdjBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateAdjBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }
upd_adj_error:
DEBUGLOG(("upd_sett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int UpdateAfterPOFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updateafterpofloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateAfterPOFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateAfterPOFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateAfterPOFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateAfterPOFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateAfterPOFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdatAfterPOFloat:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateAfterPOFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_insert_af(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert_af ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create_\
user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1466;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updateafterpofloat_error;
}




DEBUGLOG(("UpdateAfterPOFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateAfterPOFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateAfterPOFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateAfterPOFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateAfterPOFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updateafterpofloat_error:
DEBUGLOG(("updateafterpofloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int GetCurrentValuesForUpdate(const char* csMerchantID,
			const char* csCurrencyId, 
			const char* csCountryId,
			const char* csServiceCode,
			hash_t *hVal)
{
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrval_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_total_float;
		double		v_current_bal;
		double		v_total_reserved_amount;
		double		v_total_hold;

		double		v_total_float_settlement;
		double		v_current_bal_settlement;
		double		v_total_hold_settlement;

		double		v_fundin_payout;
		double		v_reserved_payout;
		double		v_total_float_after_payout;

		short		ind_total_float = -1;
		short		ind_current_bal= -1;
		short		ind_total_reserved_amount= -1;
		short		ind_total_hold= -1;

		short		ind_total_float_settlement = -1;
		short		ind_current_bal_settlement= -1;
		short		ind_total_hold_settlement= -1;

		short		ind_total_float_after_payout = -1;
		short		ind_fundin_payout = -1;
		short		ind_reserved_payout = -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrentValuesForUpdate merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrentValuesForUpdate ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrentValuesForUpdate country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrentValuesForUpdate service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        
        /* EXEC SQL DECLARE c_cursor_getcurrvalforupdate CURSOR FOR
                select 	m_total_float,
			m_current_bal,
			m_total_reserved_amount,
			m_total_hold,
			m_total_float_settlement,
			m_current_bal_settlement,
			m_total_hold_settlement,
			m_total_float_after_payout,
			m_fundin_payout,
                        m_reserved_payout
                  from 	merchant_balance
		 where 	m_merchant_id = :hv_merchant_id
		   and 	m_currency_id = :hv_ccy_id
		   and	m_country_id = :hv_country_id
		   and	m_service_code = :hv_service_code
		   for update; */ 


        /* EXEC SQL OPEN c_cursor_getcurrvalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0027;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1509;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrvalforupdate
                INTO
			:v_total_float:ind_total_float,
			:v_current_bal:ind_current_bal,
			:v_total_reserved_amount:ind_total_reserved_amount,
			:v_total_hold:ind_total_hold,
			:v_total_float_settlement:ind_total_float_settlement,
			:v_current_bal_settlement:ind_current_bal_settlement,
			:v_total_hold_settlement:ind_total_hold_settlement,
			:v_total_float_after_payout:ind_total_float_after_payout,
			:v_fundin_payout:ind_fundin_payout,
			:v_reserved_payout:ind_reserved_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1540;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_total_float;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_current_bal;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_reserved_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_hold;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal_settlement;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_float_after_payout;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_reserved_payout;
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
                if (sqlca.sqlcode < 0) goto getcurrval_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

//total_float 
                if(ind_total_float<0)
			v_total_float = 0.0;
		PutField_Double(hVal,"total_float",v_total_float);
DEBUGLOG(("GetCurrentValuesForUpdate float = [%f]\n",v_total_float));
		
//current_bal
                if(ind_current_bal<0)
			v_current_bal = 0.0;
		PutField_Double(hVal,"current_bal",v_current_bal);
DEBUGLOG(("GetCurrentValuesForUpdate current_bal = [%f]\n",v_current_bal));


//total_reserved_amount
                if(ind_total_reserved_amount<0)
			v_total_reserved_amount= 0.0;
		PutField_Double(hVal,"total_reserved_amount",v_total_reserved_amount);
DEBUGLOG(("GetCurrentValuesForUpdate total_reserved_amount = [%f]\n",v_total_reserved_amount));

//total_hold
                if(ind_total_hold<0)
			v_total_hold= 0;
		PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetCurrentValuesForUpdate total_hold = [%f]\n",v_total_hold));


//total_float_settlement 
                if(ind_total_float_settlement<0)
			v_total_float_settlement = 0.0;
		PutField_Double(hVal,"total_float_settlement",v_total_float_settlement);
DEBUGLOG(("GetCurrentValuesForUpdate float_settlement = [%f]\n",v_total_float_settlement));

//current_bal_settlement
                if(ind_current_bal_settlement<0)
			v_current_bal_settlement = 0.0;
		PutField_Double(hVal,"current_bal_settlement",v_current_bal_settlement);
DEBUGLOG(("GetCurrentValuesForUpdate current_bal_settlement = [%f]\n",v_current_bal_settlement));

//total_hold_settlement
                if(ind_total_hold_settlement<0)
			v_total_hold_settlement= 0;
		PutField_Double(hVal,"total_hold_settlement",v_total_hold_settlement);
DEBUGLOG(("GetCurrentValuesForUpdate total_hold_settlement = [%f]\n",v_total_hold_settlement));

//total_float_after_payout 
                if(ind_total_float_after_payout<0)
			v_total_float_after_payout = 0.0;
		PutField_Double(hVal,"total_float_after_payout",v_total_float_after_payout);
DEBUGLOG(("GetCurrentValuesForUpdate float_after_payout = [%f]\n",v_total_float_after_payout));
		
//fundin payout
                if(ind_fundin_payout<0)
			v_fundin_payout= 0;
		PutField_Double(hVal,"fundin_payout",v_fundin_payout);
DEBUGLOG(("GetCurrentValuesForUpdate fundin_payout = [%f]\n",v_fundin_payout));

//reserved payout
                if(ind_reserved_payout<0)
			v_reserved_payout= 0;
		PutField_Double(hVal,"reserved_payout",v_reserved_payout);
DEBUGLOG(("GetCurrentValuesForUpdate reserved_payout = [%f]\n",v_reserved_payout));

        }

        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrvalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1595;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}



DEBUGLOG(("GetCurrentValuesForUpdate Normal Exit\n"));
	return iRet;

getcurrval_error:
DEBUGLOG(("getcurrvalforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcurrvalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1610;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdateReservedPO(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatereservedpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateReservedPO: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateReservedPO:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateReservedPO:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateReservedPO:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateReservedPO:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdateReservedPO:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateReservedPO:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_set_po_res(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_set_po_res ( \
:hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create\
_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1625;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatereservedpo_error;
}




DEBUGLOG(("UpdateReservedPO:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateReservedPO:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateReservedPO: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateReservedPO: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateReservedPO: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateReservedPO: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatereservedpo_error:
DEBUGLOG(("updatereservedpo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int RlsFloat2AfterPOFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatebothfloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("RlsFloat2AfterPOFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("RlsFloat2AfterPOFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_FT_2_AF(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_FT_2_AF ( :hv\
_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind\
_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create_us\
er:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1668;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatebothfloat_error;
}




DEBUGLOG(("RlsFloat2AfterPOFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("RlsFloat2AfterPOFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::RlsFloat2AfterPOFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("RlsFloat2AfterPOFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::RlsFloat2AfterPOFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("RlsFloat2AfterPOFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatebothfloat_error:
DEBUGLOG(("updatebothfloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int RlsAfterPOFloat2SettlementFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
		const char* csServiceCode,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatesettlefloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("RlsAfterPOFloat2SettlementFloat: Begin\n"));


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:amt = [%f]\n",hv_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_balance_AF_2_SFL(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_amt:ind_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_AF_2_SFL ( :h\
v_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:in\
d_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_create_u\
ser:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1711;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto updatesettlefloat_error;
}




DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::RlsAfterPOFloat2SettlementFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::RlsAfterPOFloat2SettlementFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

updatesettlefloat_error:
DEBUGLOG(("updatesettlefloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int TransferAvaPayout(const char* csMerchantId,
			const char* csCountryId,
			const char* csCcy,
			const char* csServiceCode,
			double  dFundin,
			double  dResvPO,	
			double	dNetAmt,
			const char* csUser)

{
	/* EXEC SQL WHENEVER SQLERROR GOTO transferavapayout_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_fundin;
		double		hv_resvpo;
		double		hv_net_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_fundin = -1;
		short		ind_resvpo = -1;
		short		ind_net_amt = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("TransferAvaPayout: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("TransferAvaPayout:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("TransferAvaPayout:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("TransferAvaPayout:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("TransferAvaPayout:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_fundin = dFundin;
	ind_fundin = 0;
DEBUGLOG(("TransferAvaPayout:fundin = [%f]\n",hv_fundin));

	hv_resvpo = dResvPO;
	ind_resvpo = 0;
DEBUGLOG(("TransferAvaPayout:resv_po = [%f]\n",hv_resvpo));

	hv_net_amt= dNetAmt;
	ind_net_amt= 0;
DEBUGLOG(("TransferAvaPayout:net_amt = [%f]\n",hv_net_amt));

	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("TransferAvaPayout:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merchant_bal_tr_ava_po(
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_service_code:ind_service_code,
				:hv_fundin:ind_fundin,
				:hv_resvpo:ind_resvpo,
				:hv_net_amt:ind_net_amt,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_tr_ava_po ( :hv_m\
erchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_c\
cy_id , :hv_service_code:ind_service_code , :hv_fundin:ind_fundin , :hv_resvp\
o:ind_resvpo , :hv_net_amt:ind_net_amt , :hv_create_user:ind_create_user ) ; \
END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1754;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_fundin;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_fundin;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_resvpo;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_resvpo;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_net_amt;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto transferavapayout_error;
}




DEBUGLOG(("TransferAvaPayout:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("TransferAvaPayout:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::TransferAvaPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("TransferAvaPayout: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::TransferAvaPayout: SP_ERR TxnAbort\n");
DEBUGLOG(("TransferAvaPayout: SP_ERR TxnAbort\n"));
		//TxnAbort();
		return PD_ERR;
	}

transferavapayout_error:
DEBUGLOG(("transferavapayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}

int GetSettAvalBalanceInq(const char* csMerchantID,
			const char* csCurrencyId,
			const char* csCountryId,
			const char* csServiceCode,
			double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getsettavalbalinq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_current_bal_sett;
		double		v_total_float_sett;
		double		v_total_hold_sett;
		double		v_total_reserved_sett;
		double		v_sett_in_transit;

		short		ind_current_bal= -1;
		short		ind_current_bal_sett= -1;
		short		ind_total_float_sett= -1;
		short		ind_total_hold_sett= -1;
		short		ind_total_reserved_sett= -1;
		short		ind_sett_in_transit= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetSettAvalBalanceInq merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetSettAvalBalanceInq ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetSettAvalBalanceInq country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetSettAvalBalanceInq service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getsettavalbalinq CURSOR FOR
                select	m_current_bal_settlement,
			m_total_float_settlement,
			m_total_hold_settlement,
			m_total_reserved_amount,
			m_settlement_in_transit,
			m_current_bal
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getsettavalbalinq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0032;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1805;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getsettavalbalinq_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsettavalbalinq
                INTO
			:v_current_bal_sett:ind_current_bal_sett,
			:v_total_float_sett:ind_total_float_sett,
			:v_total_hold_sett:ind_total_hold_sett,
			:v_total_reserved_sett:ind_total_reserved_sett,
			:v_sett_in_transit:ind_sett_in_transit,
			:v_current_bal:ind_current_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1836;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_reserved_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_reserved_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_sett_in_transit;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_sett_in_transit;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal;
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
                if (sqlca.sqlcode < 0) goto getsettavalbalinq_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal_sett<0)
			v_current_bal_sett = 0.0;
                if(ind_total_float_sett<0)
			v_total_float_sett= 0.0;
                if(ind_total_hold_sett<0)
			v_total_hold_sett= 0.0;
                if(ind_total_reserved_sett<0)
			v_total_reserved_sett= 0.0;
                if(ind_current_bal<0)
			v_current_bal= 0.0;
		if(ind_sett_in_transit<0)
			v_sett_in_transit=0.0;

		*dBal=v_current_bal_sett-v_total_float_sett-v_total_hold_sett-v_total_reserved_sett-v_sett_in_transit;
DEBUGLOG(("GetSettAvalBalanceInq balance = [%f]\n",*dBal));


        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsettavalbalinq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1875;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsettavalbalinq_error;
}



DEBUGLOG(("GetSettAvalBalanceInq Normal Exit\n"));
	return iRet;

getsettavalbalinq_error:
DEBUGLOG(("getsettavalbalinq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsettavalbalinq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1890;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int GetSettTotalAvalBalance(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getsetttotalavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_current_bal_sett;
		double		v_total_float_sett;
		double		v_total_hold_sett;
		double		v_total_reserved_sett;

		short		ind_current_bal= -1;
		short		ind_current_bal_sett= -1;
		short		ind_total_float_sett= -1;
		short		ind_total_hold_sett= -1;
		short		ind_total_reserved_sett= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetSettTotalAvalBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetSettTotalAvalBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetSettTotalAvalBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetSettTotalAvalBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getsetttotalavalbal CURSOR FOR
                select	m_current_bal_settlement,
			m_total_float_settlement,
			m_total_hold_settlement,
			m_total_reserved_amount,
			m_current_bal
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getsetttotalavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0033;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1905;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getsetttotalavalbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsetttotalavalbal
                INTO
			:v_current_bal_sett:ind_current_bal_sett,
			:v_total_float_sett:ind_total_float_sett,
			:v_total_hold_sett:ind_total_hold_sett,
			:v_total_reserved_sett:ind_total_reserved_sett,
			:v_current_bal:ind_current_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1936;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_reserved_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_reserved_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_current_bal;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getsetttotalavalbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal_sett<0)
			v_current_bal_sett = 0.0;
                if(ind_total_float_sett<0)
			v_total_float_sett= 0.0;
                if(ind_total_hold_sett<0)
			v_total_hold_sett= 0.0;
                if(ind_total_reserved_sett<0)
			v_total_reserved_sett= 0.0;
                if(ind_current_bal<0)
			v_current_bal= 0.0;

		*dBal=v_current_bal_sett-v_total_float_sett-v_total_hold_sett-v_total_reserved_sett;
DEBUGLOG(("GetSettTotalAvalBalance balance = [%f]\n",*dBal));

		PutField_Double(hContext,"merchant_open_bal",v_current_bal);
		PutField_Double(hContext,"merchant_open_bal_settlement",v_current_bal_sett);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsetttotalavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1971;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsetttotalavalbal_error;
}



DEBUGLOG(("GetSettTotalAvalBalance Normal Exit\n"));
	return iRet;

getsetttotalavalbal_error:
DEBUGLOG(("getsetttotalavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsetttotalavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1986;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdateSettInTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                char    cType,
                const char* csUser)
                
{

        /* EXEC SQL WHENEVER SQLERROR GOTO upd_sett_intransit_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateSettInTransit: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;

        if(cType==PD_IND_DEBIT){
        	hv_amt = (-1)*(dAmt);
        	ind_amt= 0;
	}
	else{
		hv_amt = dAmt;
        	ind_amt= 0;
	}
//DEBUGLOG(("UpdateSettInTransit:amt = [%f]\n",dAmt));
DEBUGLOG(("UpdateSettInTransit:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateSettInTransit:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merch_bal_upd_sett_intrans(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merch_bal_upd_s\
ett_intrans ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id\
 , :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_am\
t , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )2001;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto upd_sett_intransit_error;
}



        if (hv_return_value == SP_OK)        {
DEBUGLOG(("UpdateSettInTransit:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateSettInTransit: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettInTransit: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateSettInTransit: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettInTransit: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }
upd_sett_intransit_error:
DEBUGLOG(("upd_sett_intransit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        TxnAbort();
        return PD_ERR;
}

int GetSettInTransit(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getsettintran_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_sett_in_transit;

		short		ind_sett_in_transit= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetSettInTransit merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetSettInTransit ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetSettInTransit country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetSettInTransit service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getsettintran CURSOR FOR
                select	
			m_settlement_in_transit
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code
		 for update; */ 


        /* EXEC SQL OPEN c_cursor_getsettintran; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0035;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2044;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getsettintran_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsettintran
                INTO
			:v_sett_in_transit:ind_sett_in_transit; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )2075;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_sett_in_transit;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_sett_in_transit;
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
                if (sqlca.sqlcode < 0) goto getsettintran_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
		if(ind_sett_in_transit<0)
			v_sett_in_transit=0.0;

		*dBal=v_sett_in_transit;
DEBUGLOG(("GetSettInTransit balance = [%f]\n",*dBal));

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsettintran; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2094;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsettintran_error;
}



DEBUGLOG(("GetSettInTransit Normal Exit\n"));
	return iRet;

getsettintran_error:
DEBUGLOG(("getsettintran_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsettintran; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2109;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetCurrBalanceInq(hash_t* hContext,
		const char* csMerchantID,
		const char* csCurrencyId,
		const char* csCountryId,
		const char* csServiceCode,
		double	*dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrbali_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		double		v_current_bal;
		double		v_current_bal_sett;
		double		v_total_hold;
		double		v_total_hold_sett;
		double		v_total_reserved_amt;

		short		ind_current_bal= -1;
		short		ind_current_bal_sett= -1;
		short		ind_total_hold= -1;
		short		ind_total_hold_sett= -1;
		short		ind_total_reserved_amt= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrBalanceInq merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrBalanceInq ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrBalanceInq country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrBalanceInq service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getcurrbali CURSOR FOR
                select	m_current_bal,
                	m_current_bal_settlement,
			m_total_hold,
			m_total_hold_settlement,
			m_total_reserved_amount
                  from merchant_balance
		 where m_merchant_id = :hv_merchant_id
		   and m_currency_id = :hv_ccy_id
		   and m_country_id = :hv_country_id
		   and m_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrbali; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0036;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2124;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getcurrbali_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrbali
                INTO
			:v_current_bal:ind_current_bal,
			:v_current_bal_sett:ind_current_bal_sett,
			:v_total_hold:ind_total_hold,
			:v_total_hold_sett:ind_total_hold_sett,
			:v_total_reserved_amt:ind_total_reserved_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )2155;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_reserved_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_reserved_amt;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getcurrbali_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal<0)
			v_current_bal= 0.0;
                if(ind_current_bal_sett<0)
			v_current_bal_sett = 0.0;
                if(ind_total_hold<0)
			v_total_hold= 0.0;
                if(ind_total_hold_sett<0)
			v_total_hold_sett= 0.0;
                if(ind_total_reserved_amt<0)
			v_total_reserved_amt= 0.0;

		*dBal=v_current_bal+v_current_bal_sett-v_total_hold-v_total_hold_sett-v_total_reserved_amt;
DEBUGLOG(("GetCurrBalanceInq balance = [%f]\n",*dBal));

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrbali; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2190;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrbali_error;
}



DEBUGLOG(("GetCurrBalanceInq Normal Exit\n"));
	return iRet;

getcurrbali_error:
DEBUGLOG(("getcurrbali_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcurrbali; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2205;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdateFloatRet(const char * csMerchantId, 
		   const char * csCountryId, 
		   const char * csCcy, 
		   const char * csServiceCode, 
		   double dNetAmt, 
		   double dReservedAmt, 
		   const char * csUser, 
		   hash_t * hOut)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatefloatret_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_net_amt;
		double		hv_reserved_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		SQL_CURSOR	v_cursor;
		double		v_current_bal;
		double		v_current_bal_settlement;
		double		v_total_float;
		double		v_total_float_after_payout;
		double		v_total_float_settlement;
		double		v_total_reserved_amount;
		double		v_fundin_payout;
		double		v_reserved_payout;
		double		v_total_hold;
		double		v_total_hold_settlement;

		short		ind_merchant_id			= -1;
		short		ind_country_id			= -1;
		short		ind_ccy_id			= -1;
		short		ind_service_code		= -1;
		short		ind_net_amt			= -1;
		short		ind_reserved_amt		= -1;
		short		ind_current_bal			= -1;
		short		ind_current_bal_settlement	= -1;
		short		ind_total_float			= -1;
		short		ind_total_float_after_payout	= -1;
		short		ind_total_float_settlement	= -1;
		short		ind_total_reserved_amount	= -1;
		short		ind_fundin_payout		= -1;
		short		ind_reserved_payout		= -1;
		short		ind_total_hold			= -1;
		short		ind_total_hold_settlement	= -1;
		short		ind_create_user			= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateFloatRet: Begin\n"));

	/* Merchant ID */
	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("UpdateFloatRet: merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	/* Country */
	hv_country_id.len = strlen(csCountryId);
	strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateFloatRet: country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	/* Ccy */
	hv_ccy_id.len = strlen(csCcy);
	strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateFloatRet: ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	/* Service Code */
	hv_service_code.len = strlen(csServiceCode);
	strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("UpdateFloatRet: service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	/* Net Amount */
	hv_net_amt = dNetAmt;
	ind_net_amt = 0;
DEBUGLOG(("UpdateFloatRet: net_amt = [%f]\n", hv_net_amt));

	/* Reserved Amount */
	hv_reserved_amt = dReservedAmt;
	ind_reserved_amt = 0;
DEBUGLOG(("UpdateFloatRet: resreved_amt = [%f]\n", hv_reserved_amt));

	/* User */
	hv_create_user.len = strlen(csUser);
	strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateFloatRet: create_user = [%.*s]\n", hv_create_user.len,hv_create_user.arr));

	/* Allocate the cursor variable */
	/* EXEC SQL ALLOCATE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2220;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto updatefloatret_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_merchant_bal_insert_fl_ret(
				:hv_merchant_id:ind_merchant_id, 
				:hv_country_id:ind_country_id, 
				:hv_ccy_id:ind_ccy_id, 
				:hv_service_code:ind_service_code, 
				:hv_net_amt:ind_net_amt, 
				:hv_reserved_amt:ind_reserved_amt, 
				:hv_create_user:ind_create_user, 
				:v_cursor);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_insert_fl_ret ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_net_amt:ind_net_amt , :hv\
_reserved_amt:ind_reserved_amt , :hv_create_user:ind_create_user , :v_cursor \
) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2239;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_net_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_reserved_amt;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_reserved_amt;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_create_user;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&v_cursor;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatefloatret_error;
}



DEBUGLOG(("UpdateFloatRet: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
		/* EXEC SQL FETCH :v_cursor 
		INTO	:v_current_bal:ind_current_bal, 
			:v_current_bal_settlement:ind_current_bal_settlement, 
			:v_total_float:ind_total_float, 
			:v_total_float_after_payout:ind_total_float_after_payout, 
			:v_total_float_settlement:ind_total_float_settlement, 
			:v_total_reserved_amount:ind_total_reserved_amount, 
			:v_fundin_payout:ind_fundin_payout, 
			:v_reserved_payout:ind_reserved_payout, 
			:v_total_hold:ind_total_hold, 
			:v_total_hold_settlement:ind_total_hold_settlement; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2290;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_current_bal;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_current_bal_settlement;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_current_bal_settlement;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_total_float;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_total_float;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_after_payout;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_total_float_after_payout;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_total_float_settlement;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_total_float_settlement;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_total_reserved_amount;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_total_reserved_amount;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_fundin_payout;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_fundin_payout;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_reserved_payout;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_reserved_payout;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_total_hold;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_total_hold_settlement;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_total_hold_settlement;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto updatefloatret_error;
}



		/* Current Bal */
		if (ind_current_bal >= 0)
		{
DEBUGLOG(("UpdateFloatRet current_bal = [%lf]\n", v_current_bal));
			PutField_Double(hOut, "current_bal", v_current_bal);
		}

		/* Current Bal Settlement */
		if (ind_current_bal_settlement >= 0)
		{
DEBUGLOG(("UpdateFloatRet current_bal_settlement = [%lf]\n", v_current_bal_settlement));
			PutField_Double(hOut, "current_bal_settlement", v_current_bal_settlement);
		}

		/* Total Float */
		if (ind_total_float >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_float = [%lf]\n", v_total_float));
			PutField_Double(hOut, "total_float", v_total_float);
		}

		/* Total Float After Payout */
		if (ind_total_float_after_payout >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_float_after_payout = [%lf]\n", v_total_float_after_payout));
			PutField_Double(hOut, "total_float_after_payout", v_total_float_after_payout);
		}

		/* Total Float Settlement */
		if (ind_total_float_settlement >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_float_settlement = [%lf]\n", v_total_float_settlement));
			PutField_Double(hOut, "total_float_settlement", v_total_float_settlement);
		}

		/* Total Reserved Amount */
		if (ind_total_reserved_amount >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_reserved_amount = [%lf]\n", v_total_reserved_amount));
			PutField_Double(hOut, "total_reserved_amount", v_total_reserved_amount);
		}

		/* Fundin Payout */
		if (ind_fundin_payout >= 0)
		{
DEBUGLOG(("UpdateFloatRet fundin_payout = [%lf]\n", v_fundin_payout));
			PutField_Double(hOut, "fundin_payout", v_fundin_payout);
		}

		/* Reserved Payout */
		if (ind_reserved_payout >= 0)
		{
DEBUGLOG(("UpdateFloatRet reserved_payout = [%lf]\n", v_reserved_payout));
			PutField_Double(hOut, "reserved_payout", v_reserved_payout);
		}

		/* Total Hold */
		if (ind_total_hold >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_hold = [%lf]\n", v_total_hold));
			PutField_Double(hOut, "total_hold", v_total_hold);
		}

		/* Total Hold Settlement */
		if (ind_total_hold_settlement >= 0)
		{
DEBUGLOG(("UpdateFloatRet total_hold_settlement = [%lf]\n", v_total_hold_settlement));
			PutField_Double(hOut, "total_hold_settlement", v_total_hold_settlement);
		}

DEBUGLOG(("UpdateFloatRet: Normal Exit\n"));
		iRet = PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("MerchantBlance::UpdateFloatRet: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateFloatRet: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		iRet = PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("MerchantBlance::UpdateFloatRet: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateFloatRet: SP_ERR TxnAbort\n"));
		TxnAbort();
	}

	/* Close and free the cursor */
	/* EXEC SQL CLOSE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2349;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto updatefloatret_error;
}


	/* EXEC SQL FREE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2368;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto updatefloatret_error;
}



	return iRet;

updatefloatret_error:
DEBUGLOG(("updatefloatret_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2387;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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


	/* EXEC SQL FREE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2406;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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


	TxnAbort();
	return PD_ERR;
}

