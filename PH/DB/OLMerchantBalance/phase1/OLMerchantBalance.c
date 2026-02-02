
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "OLMerchantBalance.pc"
};


static unsigned int sqlctx = 80911603;


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

 static char *sq0002 = 
"select om_current_bal , om_total_hold , om_total_reserved_amount , om_total\
_float_settlement , om_current_bal_settlement , om_total_hold_settlement , om\
_fundin_payout , om_reserved_payout , om_total_float_after_payout from ol_mer\
chant_balance where om_merchant_id = :b0 and om_currency_id = :b1 and om_coun\
try_id = :b2 and om_service_code = :b3            ";

 static char *sq0006 = 
"select om_current_bal , om_total_hold , om_current_bal_settlement , om_tota\
l_float_settlement , om_total_hold_settlement , om_total_float_after_payout ,\
 om_total_reserved_amount , om_fundin_payout from ol_merchant_balance where o\
m_merchant_id = :b0 and om_currency_id = :b1 and om_country_id = :b2 and om_s\
ervice_code = :b3 for update ";

 static char *sq0007 = 
"select om_current_bal , om_current_bal_settlement , om_total_hold , om_tota\
l_hold_settlement , om_total_reserved_amount from ol_merchant_balance where o\
m_merchant_id = :b0 and om_currency_id = :b1 and om_country_id = :b2 and om_s\
ervice_code = :b3            ";

 static char *sq0008 = 
"select current_bal , total_float , security_bal , fundin_payout , reserved_\
payout , ava_po , remaining_po_amount , remaining_po_amount_with_fee , mercha\
nt_ava_po , appro_po_fee_rate , merchant_ava_po_for_move from ol_merchant_bal\
ance_view where merchant_id = :b0 and currency_id = :b1 and country_id = :b2 \
and service_code = :b3            ";

 static char *sq0010 = 
"select om_current_bal_settlement , om_total_float_settlement , om_total_hol\
d_settlement , om_total_reserved_amount , om_settlement_in_transit , om_curre\
nt_bal from ol_merchant_balance where om_merchant_id = :b0 and om_currency_id\
 = :b1 and om_country_id = :b2 and om_service_code = :b3            ";

 static char *sq0011 = 
"select om_current_bal_settlement , om_total_float_settlement , om_total_hol\
d_settlement , om_total_reserved_amount , om_current_bal from ol_merchant_bal\
ance where om_merchant_id = :b0 and om_currency_id = :b1 and om_country_id = \
:b2 and om_service_code = :b3            ";

 static char *sq0013 = 
"select om_settlement_in_transit from ol_merchant_balance where om_merchant_\
id = :b0 and om_currency_id = :b1 and om_country_id = :b2 and om_service_code\
 = :b3 for update ";

 static char *sq0015 = 
"select om_current_bal , om_current_bal_settlement , om_total_hold , om_tota\
l_hold_settlement , om_total_reserved_amount from ol_merchant_balance where o\
m_merchant_id = :b0 and om_currency_id = :b1 and om_country_id = :b2 and om_s\
ervice_code = :b3            ";

 static char *sq0020 = 
"select om_current_bal_settlement , om_total_float_settlement , om_total_hol\
d_settlement , om_total_reserved_amount , om_settlement_in_transit , om_curre\
nt_bal from ol_merchant_balance where om_merchant_id = :b0 and om_currency_id\
 = :b1 and om_country_id = :b2 and om_service_code = :b3 for update ";

 static char *sq0021 = 
"select om_current_bal , om_current_bal_settlement , om_total_hold , om_tota\
l_hold_settlement , om_total_reserved_amount from ol_merchant_balance where o\
m_merchant_id = :b0 and om_currency_id = :b1 and om_country_id = :b2 and om_s\
ervice_code = :b3 for update ";

 static char *sq0022 = 
"select om_current_bal , om_total_reserved_amount , om_total_hold , om_total\
_float_settlement , om_current_bal_settlement , om_total_hold_settlement , om\
_total_float_after_payout , om_fundin_payout , om_reserved_payout from ol_mer\
chant_balance where om_merchant_id = :b0 and om_currency_id = :b1 and om_coun\
try_id = :b2 and om_service_code = :b3 for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,225,0,6,89,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,
44,0,0,2,356,0,9,208,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
75,0,0,2,0,0,13,210,0,0,9,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,
126,0,0,2,0,0,15,287,0,0,0,0,0,1,0,
141,0,0,2,0,0,15,296,0,0,0,0,0,1,0,
156,0,0,3,240,0,6,362,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
199,0,0,4,243,0,6,474,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
242,0,0,5,244,0,6,490,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
285,0,0,6,335,0,9,613,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
316,0,0,6,0,0,13,615,0,0,8,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,
363,0,0,6,0,0,15,669,0,0,0,0,0,1,0,
378,0,0,6,0,0,15,701,0,0,0,0,0,1,0,
393,0,0,7,258,0,9,767,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
424,0,0,7,0,0,13,769,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
459,0,0,7,0,0,15,800,0,0,0,0,0,1,0,
474,0,0,7,0,0,15,809,0,0,0,0,0,1,0,
489,0,0,8,340,0,9,895,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
520,0,0,8,0,0,13,897,0,0,11,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
579,0,0,8,0,0,15,967,0,0,0,0,0,1,0,
594,0,0,8,0,0,15,976,0,0,0,0,0,1,0,
609,0,0,9,244,0,6,1044,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
652,0,0,10,297,0,9,1153,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
683,0,0,10,0,0,13,1155,0,0,6,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,
722,0,0,10,0,0,15,1189,0,0,0,0,0,1,0,
737,0,0,10,0,0,15,1198,0,0,0,0,0,1,0,
752,0,0,11,270,0,9,1266,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
783,0,0,11,0,0,13,1268,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
818,0,0,11,0,0,15,1301,0,0,0,0,0,1,0,
833,0,0,11,0,0,15,1310,0,0,0,0,0,1,0,
848,0,0,12,229,0,6,1379,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
891,0,0,13,170,0,9,1471,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
922,0,0,13,0,0,13,1473,0,0,1,0,0,1,0,2,4,0,0,
941,0,0,13,0,0,15,1491,0,0,0,0,0,1,0,
956,0,0,13,0,0,15,1500,0,0,0,0,0,1,0,
971,0,0,14,228,0,6,1572,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1014,0,0,15,258,0,9,1674,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1045,0,0,15,0,0,13,1676,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1080,0,0,15,0,0,15,1706,0,0,0,0,0,1,0,
1095,0,0,15,0,0,15,1715,0,0,0,0,0,1,0,
1110,0,0,16,244,0,6,1783,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1153,0,0,17,244,0,6,1889,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1196,0,0,18,242,0,6,1998,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1239,0,0,19,227,0,6,2106,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1282,0,0,20,297,0,9,2208,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1313,0,0,20,0,0,13,2210,0,0,6,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,
1352,0,0,20,0,0,15,2245,0,0,0,0,0,1,0,
1367,0,0,20,0,0,15,2254,0,0,0,0,0,1,0,
1382,0,0,21,258,0,9,2323,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1413,0,0,21,0,0,13,2325,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1448,0,0,21,0,0,15,2358,0,0,0,0,0,1,0,
1463,0,0,21,0,0,15,2367,0,0,0,0,0,1,0,
1478,0,0,22,356,0,9,2448,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1509,0,0,22,0,0,13,2450,0,0,9,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1560,0,0,22,0,0,15,2524,0,0,0,0,0,1,0,
1575,0,0,22,0,0,15,2533,0,0,0,0,0,1,0,
1590,0,0,23,242,0,6,2601,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1633,0,0,24,242,0,6,2709,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
1676,0,0,25,298,0,6,2829,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
1727,0,0,26,244,0,6,2937,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/11              LokMan Chow
balance field follow online structure		   2014/01/07		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMerchantBalance.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLMerchantBalance(char    cdebug)
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

		:hv_return_value := sp_ol_merchant_balance_insert(
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
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_balance_insert ( :\
hv_merchant_id:ind_merchant_id , :hv_ccy_id:ind_ccy_id , :hv_country_id:ind_c\
ountry_id , :hv_service_code:ind_service_code , :hv_create_user:ind_create_us\
er ) ; END ;";
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
ERRLOG("OLOLOLMerchantBlance::Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		//TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLOLMerchantBlance::Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		//TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

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

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_total_reserved_amount;
                double          v_total_hold;

                double          v_total_float_settlement;
                double          v_current_bal_settlement;
                double          v_total_hold_settlement;

                double          v_fundin_payout;
                double          v_reserved_payout;
                double          v_total_float_after_payout;

                short           ind_current_bal= -1;
                short           ind_total_reserved_amount= -1;
                short           ind_total_hold= -1;

                short           ind_total_float_settlement = -1;
                short           ind_current_bal_settlement= -1;
                short           ind_total_hold_settlement= -1;

                short           ind_total_float_after_payout = -1;
                short           ind_fundin_payout = -1;
                short           ind_reserved_payout = -1;

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
                select  
                        om_current_bal,
                        om_total_hold,
                        om_total_reserved_amount,
                        om_total_float_settlement,
                        om_current_bal_settlement,
                        om_total_hold_settlement,
                        om_fundin_payout,
                        om_reserved_payout,
                        om_total_float_after_payout
                  from  ol_merchant_balance
                 where  om_merchant_id = :hv_merchant_id
                   and  om_currency_id = :hv_ccy_id
                   and  om_country_id = :hv_country_id
                   and  om_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )44;
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
			:v_current_bal:ind_current_bal,
                        :v_total_hold:ind_total_hold,
                        :v_total_reserved_amount:ind_total_reserved_amount,
                        :v_total_float_settlement:ind_total_float_settlement,
                        :v_current_bal_settlement:ind_current_bal_settlement,
                        :v_total_hold_settlement:ind_total_hold_settlement,
                        :v_fundin_payout:ind_fundin_payout,
                        :v_reserved_payout:ind_reserved_payout,
                        :v_total_float_after_payout:ind_total_float_after_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )75;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_hold;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_current_bal_settlement;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_reserved_payout;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_total_float_after_payout;
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
                if (sqlca.sqlcode < 0) goto getcurrval_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

//current_bal
                if(ind_current_bal<0)
                        v_current_bal = 0.0;
                PutField_Double(hVal,"current_bal",v_current_bal);
DEBUGLOG(("GetCurrentValues current_bal = [%f]\n",v_current_bal));


//total_hold
                if(ind_total_hold<0)
                        v_total_hold= 0;
                PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetCurrentValues total_hold = [%f]\n",v_total_hold));


//total_reserved_amount
                if(ind_total_reserved_amount<0)
                        v_total_reserved_amount= 0;
                PutField_Double(hVal,"total_reserved_amount",v_total_reserved_amount);
DEBUGLOG(("GetCurrentValues total_reserved_amount = [%f]\n",v_total_reserved_amount));

//total_float_settlement
                if(ind_total_float_settlement<0)
                        v_total_float_settlement= 0;
                PutField_Double(hVal,"total_float_settlement",v_total_float_settlement);
DEBUGLOG(("GetCurrentValues total_float_settlement= [%f]\n",v_total_float_settlement));

//current_bal_settlement
                if(ind_current_bal_settlement<0)
                        v_current_bal_settlement= 0;
                PutField_Double(hVal,"current_bal_settlement",v_current_bal_settlement);
DEBUGLOG(("GetCurrentValues current_bal_settlement= [%f]\n",v_current_bal_settlement));

//total_hold_settlement
                if(ind_total_hold_settlement<0)
                        v_total_hold_settlement= 0;
                PutField_Double(hVal,"total_hold_settlement",v_total_hold_settlement);
DEBUGLOG(("GetCurrentValues total_hold_settlement= [%f]\n",v_total_hold_settlement));

//fundin_payout
                if(ind_fundin_payout<0)
                        v_fundin_payout= 0;
                PutField_Double(hVal,"fundin_payout",v_fundin_payout);
DEBUGLOG(("GetCurrentValues fundin_payout= [%f]\n",v_fundin_payout));

//reserved_payout
                if(ind_reserved_payout<0)
                        v_reserved_payout= 0;
                PutField_Double(hVal,"reserved_payout",v_reserved_payout);
DEBUGLOG(("GetCurrentValues reserved_payout= [%f]\n",v_reserved_payout));

//total_float_after_payout
                if(ind_total_float_after_payout<0)
                        v_total_float_after_payout= 0;
                PutField_Double(hVal,"total_float_after_payout",v_total_float_after_payout);
DEBUGLOG(("GetCurrentValues total_float_after_payout= [%f]\n",v_total_float_after_payout));


        }

        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )126;
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )141;
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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

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
DEBUGLOG(("UpdateCurrBal:net amt = [%f]\n",hv_amt));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateCurrBal:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_merchant_bal_upd_bal(
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_bal_upd_bal\
 ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_\
id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_cre\
ate_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )156;
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
ERRLOG("OLOLOLMerchantBlance::UpdateCurrBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateCurrBal: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLOLMerchantBlance::UpdateCurrBal: SP_ERR TxnAbort\n");
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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_hold;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_hold = -1;
                short           ind_create_user = -1;

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

        if(cType==PD_HOLD)
        	hv_hold= dAmt;
	else
        	hv_hold= (-1)*dAmt;
        ind_hold= 0;
DEBUGLOG(("UpdateHoldBalance:net hold = [%f]\n",hv_hold));
DEBUGLOG(("UpdateHoldBalance:hold_type = [%c]\n",cType));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateHoldBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	if (cMHind == PD_TYPE_PAYOUT) {

		/* EXEC SQL EXECUTE
			BEGIN

			:hv_return_value := sp_ol_merchant_bal_upd_hold(
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
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_bal_upd_hold ( :h\
v_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:in\
d_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_create\
_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )199;
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

			:hv_return_value := sp_ol_merchant_bal_upd_shold(
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
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_bal_upd_shold ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_hold:ind_hold , :hv_creat\
e_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )242;
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

DEBUGLOG(("UpdateHoldBalance:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateHoldBalance:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLOLOLMerchantBlance::UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLOLMerchantBlance::UpdateHoldBalance: SP_ERR TxnAbort\n");
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
        double dHold = 0.0;
	double dBalSettlement = 0.0;
        double dFloatSettlement = 0.0;
        double dHoldSettlement = 0.0;
        double dFloatAfterPayout = 0.0;
        double dReservedAmount = 0.0;
        double dFundInPayout = 0.0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getopenbalforupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_total_hold;
                double          v_current_bal_settlement;
		double          v_total_float_settlement;
                double          v_total_hold_settlement;

		double          v_total_float_after_payout;
                double          v_total_reserved_amount;
                double          v_fundin_payout;

                short           ind_current_bal= -1;
                short           ind_total_hold= -1;
                short           ind_current_bal_settlement = -1;
                short           ind_total_hold_settlement = -1;
		short           ind_total_float_settlement= -1;

                short           ind_total_float_after_payout = -1;
                short           ind_total_reserved_amount = -1;
                short           ind_fundin_payout = -1;

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

        /* EXEC SQL DECLARE c_cursor_getopbal CURSOR FOR
                select  om_current_bal,
                        om_total_hold,
                        om_current_bal_settlement,
			om_total_float_settlement,
                        om_total_hold_settlement,
                        om_total_float_after_payout,
                        om_total_reserved_amount,
                        om_fundin_payout
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code
                 for update; */ 


        /* EXEC SQL OPEN c_cursor_getopbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )285;
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
                /* EXEC SQL FETCH c_cursor_getopbal
                INTO
                        :v_current_bal:ind_current_bal,
                        :v_total_hold:ind_total_hold,
                        :v_current_bal_settlement:ind_current_bal_settlement,
			:v_total_float_settlement:ind_total_float_settlement,
                        :v_total_hold_settlement:ind_total_hold_settlement,
                        :v_total_float_after_payout:ind_total_float_after_payout,
                        :v_total_reserved_amount:ind_total_reserved_amount,
                        :v_fundin_payout:ind_fundin_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )316;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_hold;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_total_float_after_payout;
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
                if(ind_total_hold<0) {
                        v_total_hold= 0.0;
                }
                if(ind_current_bal_settlement <0) {
                        v_current_bal_settlement = 0.0;
                }
                if(ind_total_hold_settlement <0) {
                        v_total_hold_settlement = 0.0;
                }
		if(ind_total_float_settlement<0) {
                        v_total_float_settlement= 0.0;
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


                dBal = v_current_bal;
                dHold = v_total_hold;
		dBalSettlement = v_current_bal_settlement;
                dFloatSettlement = v_total_float_settlement;
                dHoldSettlement = v_total_hold_settlement;

                dFloatAfterPayout = v_total_float_after_payout;
                dReservedAmount = v_total_reserved_amount;
                dFundInPayout = v_fundin_payout;
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getopbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )363;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}



DEBUGLOG(("GetOpenBalanceForUpdate open_bal = [%f]\n",dBal));
                PutField_Double(hContext,"merchant_open_bal",dBal);
DEBUGLOG(("GetOpenBalanceForUpdate total_hold = [%f]\n",dHold));
                PutField_Double(hContext,"total_hold",dHold);

DEBUGLOG(("GetOpenBalanceForUpdate current_bal_settlement = [%f]\n",dBalSettlement));
                PutField_Double(hContext,"current_bal_settlement",dBalSettlement);
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


DEBUGLOG(("GetOpenBalanceForUpdate Normal Exit\n"));
        return iRet;

getopenbalforupdate_error:
DEBUGLOG(("getopenbalforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getopbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )378;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetCurrBalance(const char* csMerchantID,
                   const char* csCurrencyId,
		   const char* csCountryId,
		   const char* csServiceCode,
		   double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
		double          v_current_bal_sett;
                double          v_total_hold;
                double          v_total_hold_sett;
                double          v_total_reserved_amt;

                short           ind_current_bal= -1;
		short           ind_current_bal_sett= -1;
                short           ind_total_hold= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_amt= -1;


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
                select  om_current_bal,
			om_current_bal_settlement,
                        om_total_hold,
                        om_total_hold_settlement,
                        om_total_reserved_amount
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )393;
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
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )424;
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


        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )459;
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )474;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetRemainPOBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getremainpo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_reserved_po;
                double          v_total_float;
                double          v_ava_po;
                double          v_total_hold;
                double          v_fundin;
                double          v_remain_po;
                double          v_remain_po_with_fee;
                double          v_merchant_ava_po;
                double          v_fee_rate;
		double		v_merchant_ava_po_move;

                short           ind_current_bal= -1;
                short           ind_reserved_po= -1;
                short           ind_total_float= -1;
                short           ind_ava_po= -1;
                short           ind_total_hold= -1;
                short           ind_fundin = -1;
                short           ind_remain_po = -1;
                short           ind_remain_po_with_fee = -1;
                short           ind_merchant_ava_po= -1;
                short           ind_fee_rate = -1;
		short		ind_merchant_ava_po_move = -1;


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
                select  current_bal,
                        total_float,
                        security_bal,
                        fundin_payout,
                        reserved_payout,
                        ava_po,
                        remaining_po_amount,
                        remaining_po_amount_with_fee,
                        merchant_ava_po,
                        appro_po_fee_rate,
			merchant_ava_po_for_move
                  from ol_merchant_balance_view
                 where merchant_id = :hv_merchant_id
                   and currency_id = :hv_ccy_id
                   and country_id = :hv_country_id
                   and service_code = :hv_service_code; */ 



        /* EXEC SQL OPEN c_cursor_getremainpo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )489;
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
                        :v_fee_rate:ind_fee_rate,
			:v_merchant_ava_po_move:ind_merchant_ava_po_move; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )520;
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
                sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_ava_po_move;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_merchant_ava_po_move;
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
                if (sqlca.sqlcode < 0) goto getremainpo_error;
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
                if(ind_remain_po)
                        v_remain_po = 0.0;
                if(ind_remain_po_with_fee)
                        v_remain_po_with_fee = 0.0;
                if(ind_merchant_ava_po)
                        v_merchant_ava_po = 0.0;
                if(ind_fee_rate)
                        v_fee_rate = 0.0;
		if(ind_merchant_ava_po_move) 
			v_merchant_ava_po_move = 0.0;

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

                PutField_Double(hContext,"merchant_ava_po_move",v_merchant_ava_po_move);
DEBUGLOG(("GetRemainPOBalance merchant_ava_po_move = [%f]\n", v_merchant_ava_po_move));
		
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getremainpo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )579;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )594;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merch_balance_upd_po_res(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_upd_po\
_res ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_\
ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv\
_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )609;
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
ERRLOG("OLOLOLMerchantBlance::UpdatePayoutReserved: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdatePayoutReserved: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLOLMerchantBlance::UpdatePayoutReserved: SP_ERR TxnAbort\n");
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


int GetSettAvalBalanceInq(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getsettavalbalinq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_float_sett;
                double          v_total_hold_sett;
                double          v_total_reserved_sett;
                double          v_sett_in_transit;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_float_sett= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_sett= -1;
                short           ind_sett_in_transit= -1;


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
                select  om_current_bal_settlement,
                        om_total_float_settlement,
                        om_total_hold_settlement,
                        om_total_reserved_amount,
                        om_settlement_in_transit,
                        om_current_bal
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getsettavalbalinq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )652;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )683;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )722;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )737;
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
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getsetttotalavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_float_sett;
                double          v_total_hold_sett;
                double          v_total_reserved_sett;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_float_sett= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_sett= -1;


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
                select  om_current_bal_settlement,
                        om_total_float_settlement,
                        om_total_hold_settlement,
                        om_total_reserved_amount,
                        om_current_bal
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getsetttotalavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0011;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )752;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )783;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )818;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )833;
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
DEBUGLOG(("UpdateSettInTransit:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateSettInTransit:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_ol_merch_bal_upd_sett_inst(
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_bal_up\
d_sett_inst ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id\
 , :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_am\
t , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )848;
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
ERRLOG("OLOLMerchantBlance::UpdateSettInTransit: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettInTransit: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLMerchantBlance::UpdateSettInTransit: SP_ERR TxnAbort\n");
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
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getsettintran_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_sett_in_transit;

                short           ind_sett_in_transit= -1;


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
                        om_settlement_in_transit
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code
                 for update; */ 


        /* EXEC SQL OPEN c_cursor_getsettintran; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0013;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )891;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )922;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )941;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )956;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


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

                        :hv_return_value := sp_ol_merch_bal_upd_sett_bal(
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_bal_up\
d_sett_bal ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id \
, :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt\
 , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )971;
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
ERRLOG("OLOLMerchantBlance::UpdateSettBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettBal: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLMerchantBlance::UpdateSettBal: SP_ERR TxnAbort\n");
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

int GetCurrBalanceInq(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;
    
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrbali_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

    
                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_hold;
                double          v_total_hold_sett;
                double          v_total_reserved_amt;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_hold= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_amt= -1;


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
                select  om_current_bal,
                        om_current_bal_settlement,
                        om_total_hold,
                        om_total_hold_settlement,
                        om_total_reserved_amount
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrbali; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0015;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1014;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1045;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1080;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1095;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merch_balance_add_fin_po(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_add_fi\
n_po ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_\
ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv\
_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1110;
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
ERRLOG("OLOLMerchantBlance::SetFundInPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("SetFundInPayout: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLMerchantBlance::SetFundInPayout: SP_ERR TxnAbort\n");
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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;
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

                :hv_return_value := sp_ol_merch_balance_upd_fin_po(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_upd_fi\
n_po ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_\
ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv\
_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1153;
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
ERRLOG("OLOLMerchantBlance::UpdateFundInPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateFundInPayout: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLOLMerchantBlance::UpdateFundInPayout: SP_ERR TxnAbort\n");
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


int Rls2AfterPOFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebothfloat_error; */ 

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
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Rls2AfterPOFloat: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("Rls2AfterPOFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("Rls2AfterPOFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("Rls2AfterPOFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("Rls2AfterPOFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_amt= dAmt;
        ind_amt= 0;
DEBUGLOG(("Rls2AfterPOFloat:amt = [%f]\n",hv_amt));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("Rls2AfterPOFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_merch_balance_APO_2_AF(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_APO_2_\
AF ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_c\
reate_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1196;
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




DEBUGLOG(("Rls2AfterPOFloat:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Rls2AfterPOFloat:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLMerchantBlance::Rls2AfterPOFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Rls2AfterPOFloat: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantBlance::Rls2AfterPOFloat: SP_ERR TxnAbort\n");
DEBUGLOG(("Rls2AfterPOFloat: SP_ERR TxnAbort\n"));
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

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_amt;
		/* varchar		hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_service_code = -1;
		short		ind_amt = -1;
		short		ind_user = -1;

		short		hv_return_value;
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

	/* EXEC SQL EXECUTE
		BEGIN

			:hv_return_value := sp_ol_merch_bal_upd_adj_bal(
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
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_bal_upd_adj_bal ( :hv\
_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind\
_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_user:ind_\
user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1239;
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
ERRLOG("OLMerchantBlance::UpdateAdjBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantBlance::UpdateAdjBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}
upd_adj_error:
DEBUGLOG(("upd_sett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetSettAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;
    
        /* EXEC SQL WHENEVER SQLERROR GOTO getsettavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

    
                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_float_sett;
                double          v_total_hold_sett;
                double          v_total_reserved_sett;
                double          v_sett_in_transit;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_float_sett= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_sett= -1;
                short           ind_sett_in_transit= -1;

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
                select  om_current_bal_settlement,
                        om_total_float_settlement,
                        om_total_hold_settlement,
                        om_total_reserved_amount,
                        om_settlement_in_transit,
                        om_current_bal
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code
                 for update; */ 


        /* EXEC SQL OPEN c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0020;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1282;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1313;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1352;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1367;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetCurrBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getcurrbalforupdate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_hold;
                double          v_total_hold_sett;
                double          v_total_reserved_amt;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_hold= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_amt= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


    
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrBalanceForUpdate merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrBalanceForUpdate ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrBalanceForUpdate country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrBalanceForUpdate service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_gtcurbalforupd CURSOR FOR
                select  om_current_bal,
                        om_current_bal_settlement,
                        om_total_hold,
                        om_total_hold_settlement,
                        om_total_reserved_amount
                  from ol_merchant_balance
                 where om_merchant_id = :hv_merchant_id
                   and om_currency_id = :hv_ccy_id
                   and om_country_id = :hv_country_id
                   and om_service_code = :hv_service_code
                 for update; */ 



        /* EXEC SQL OPEN c_cursor_gtcurbalforupd; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0021;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1382;
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
        if (sqlca.sqlcode < 0) goto getcurrbalforupdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gtcurbalforupd
                INTO
                        :v_current_bal:ind_current_bal,
                        :v_current_bal_sett:ind_current_bal_sett,
                        :v_total_hold:ind_total_hold,
                        :v_total_hold_sett:ind_total_hold_sett,
                        :v_total_reserved_amt:ind_total_reserved_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1413;
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
                if (sqlca.sqlcode < 0) goto getcurrbalforupdate_error;
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
DEBUGLOG(("GetCurrBalanceForUpdate balance = [%f]\n",*dBal));

                PutField_Double(hContext,"merchant_open_bal",v_current_bal);
                PutField_Double(hContext,"merchant_open_bal_settlement",v_current_bal_sett);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gtcurbalforupd; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1448;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrbalforupdate_error;
}



DEBUGLOG(("GetCurrBalanceForUpdate Normal Exit\n"));
        return iRet;

getcurrbalforupdate_error:
DEBUGLOG(("getcurrbalforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gtcurbalforupd; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1463;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


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

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_total_reserved_amount;
                double          v_total_hold;

                double          v_total_float_settlement;
                double          v_current_bal_settlement;
                double          v_total_hold_settlement;

                double          v_fundin_payout;
                double          v_reserved_payout;
                double          v_total_float_after_payout;

                short           ind_current_bal= -1;
                short           ind_total_reserved_amount= -1;
                short           ind_total_hold= -1;
                short           ind_total_float_settlement = -1;
                short           ind_current_bal_settlement= -1;
                short           ind_total_hold_settlement= -1;

                short           ind_total_float_after_payout = -1;
                short           ind_fundin_payout = -1;
                short           ind_reserved_payout = -1;

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
                select  
                        om_current_bal,
                        om_total_reserved_amount,
                        om_total_hold,
                        om_total_float_settlement,
                        om_current_bal_settlement,
                        om_total_hold_settlement,
                        om_total_float_after_payout,
                        om_fundin_payout,
                        om_reserved_payout
                  from  ol_merchant_balance
                 where  om_merchant_id = :hv_merchant_id
                   and  om_currency_id = :hv_ccy_id
                   and  om_country_id = :hv_country_id
                   and  om_service_code = :hv_service_code
                   for update; */ 


        /* EXEC SQL OPEN c_cursor_getcurrvalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0022;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1478;
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
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1509;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_reserved_amount;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_current_bal_settlement;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1560;
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1575;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merch_balance_AF_2_SFL(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_AF_2_S\
FL ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_c\
reate_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1590;
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
ERRLOG("OLMerchantBlance::RlsAfterPOFloat2SettlementFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("RlsAfterPOFloat2SettlementFloat: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantBlance::RlsAfterPOFloat2SettlementFloat: SP_ERR TxnAbort\n");
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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_bal;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_bal = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merch_balance_rls_stfl(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_balance_rls_st\
fl ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_bal:ind_bal , :hv_c\
reate_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1633;
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
ERRLOG("OLMerchantBlance::ReleaseSettFloat: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("ReleaseSettFloat: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantBlance::ReleaseSettFloat: SP_ERR TxnAbort\n");
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

int TransferAvaPayout(const char* csMerchantId,
                        const char* csCountryId,
                        const char* csCcy,
                        const char* csServiceCode,
                        double  dFundin,
                        double  dResvPO,
                        double  dNetAmt,
                        const char* csUser)

{
        /* EXEC SQL WHENEVER SQLERROR GOTO transferavapayout_error; */ 

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

                double          hv_fundin;
                double          hv_resvpo;
                double          hv_net_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_fundin = -1;
                short           ind_resvpo = -1;
                short           ind_net_amt = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merchant_bal_tr_ava_po(
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_bal_tr_ava_\
po ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_fundin:ind_fundin ,\
 :hv_resvpo:ind_resvpo , :hv_net_amt:ind_net_amt , :hv_create_user:ind_create\
_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1676;
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
ERRLOG("OLMerchantBlance::TransferAvaPayout: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("TransferAvaPayout: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantBlance::TransferAvaPayout: SP_ERR TxnAbort\n");
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

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_float;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_float = -1;
                short           ind_create_user = -1;

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

                :hv_return_value := sp_ol_merch_bal_after_pofl (
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
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_bal_after_pofl\
 ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_\
id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_float:ind_float , :hv\
_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1727;
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
ERRLOG("OLMerchantBlance::UpdateAfterPayoutFloat: SP_ERR TxnAbort\n");
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
