
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "OLSimCards.pc"
};


static unsigned int sqlctx = 638835;


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
5,0,0,1,568,0,6,201,0,0,17,17,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,
88,0,0,2,77,0,4,433,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
111,0,0,3,86,0,6,439,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
134,0,0,4,0,0,17,466,0,0,1,1,0,1,0,1,9,0,0,
153,0,0,4,0,0,21,467,0,0,0,0,0,1,0,
168,0,0,5,86,0,6,472,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
191,0,0,6,77,0,4,560,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
214,0,0,7,86,0,6,566,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
237,0,0,4,0,0,17,592,0,0,1,1,0,1,0,1,9,0,0,
256,0,0,4,0,0,21,593,0,0,0,0,0,1,0,
271,0,0,8,86,0,6,598,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
294,0,0,9,105,0,6,652,0,0,2,2,0,1,0,2,1,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/12/18              Stan Poon
Revised version for update spec, add log	   2014/09/03		   Dirk Wong
Modify sim_package to varchar                      2015/02/03              Dirk Wong
Add GetSimCardDtl				   2015/02/03		   Dirk Wong
Add Expired Date for sim card			   2015/02/26		   Dirk Wong
Add Sim Nature					   2015/08/18		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLSimCards.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLSimCards(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char	*csTmp;
	char 	cTmp;
	int	iTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile;

		/* varchar		hv_carriers[PD_MOBILE_CARRIERS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_carriers;

		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_owner_name[PD_OWNER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_owner_name;

		double		hv_sim_credit;
		/* varchar		hv_sim_package[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_sim_package;

		/* varchar		hv_sim_currency[PD_CURRENCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sim_currency;

		int		hv_billed_date;
		/* varchar		hv_last_topup_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_last_topup_date;

		/* varchar		hv_next_topup_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_next_topup_date;

		/* varchar		hv_expired_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_expired_date;

		/* varchar		hv_password[PD_PASSWD_LEN]; */ 
struct { unsigned short len; unsigned char arr[40]; } hv_password;

		char		hv_status;
		/* varchar		hv_remarks[PD_SIM_CARDS_REMARKS_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_remarks;

		/* varchar		hv_sim_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sim_nature;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_mobile = -1;
		short		ind_carriers = -1;
		short		ind_country = -1;
		short		ind_owner_name = -1;
		short		ind_sim_credit = -1;
		short		ind_sim_package = -1;
		short		ind_sim_currency = -1;
		short		ind_billed_date = -1;
		short		ind_last_topup_date = -1;
		short		ind_next_topup_date = -1;
		short		ind_expired_date = -1;
		short		ind_password = -1;
		short		ind_status = -1;
		short		ind_remarks = -1;
		short		ind_sim_nature = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hRls,"mob_num",&csTmp)) {
                hv_mobile.len = strlen(csTmp);
                strncpy((char*)hv_mobile.arr, csTmp, hv_mobile.len);
                ind_mobile = 0;
        }
DEBUGLOG(("Add:mobile = [%.*s]\n",hv_mobile.len, hv_mobile.arr));

        if(GetField_CString(hRls,"carriers",&csTmp)) {
                hv_carriers.len = strlen(csTmp);
                strncpy((char*)hv_carriers.arr, csTmp, hv_carriers.len);
                ind_carriers = 0;
DEBUGLOG(("Add:carriers = [%.*s]\n",hv_carriers.len, hv_carriers.arr));
        }

        if(GetField_CString(hRls,"country",&csTmp)) {
                hv_country.len = strlen(csTmp);
                strncpy((char*)hv_country.arr, csTmp, hv_country.len);
                ind_country = 0;
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len, hv_country.arr));
        }

        if(GetField_CString(hRls,"owner_name",&csTmp)) {
                hv_owner_name.len = strlen(csTmp);
                strncpy((char*)hv_owner_name.arr, csTmp, hv_owner_name.len);
                ind_owner_name = 0;
DEBUGLOG(("AddO:owner_name = [%.*s]\n",hv_owner_name.len, hv_owner_name.arr));
        }

        if(GetField_Double(hRls, "sim_credit", &dTmp)) {
                hv_sim_credit = dTmp;
                ind_sim_credit = 0;
DEBUGLOG(("Add:sim_credit = [%.2f]\n",hv_sim_credit));
        }

        if(GetField_CString(hRls, "sim_package", &csTmp)) {
                hv_sim_package.len = strlen(csTmp);
		strncpy((char*)hv_sim_package.arr, csTmp, hv_sim_package.len);
                ind_sim_package = 0;
DEBUGLOG(("Add:sim_package = [%.*sf]\n",hv_sim_package.len, hv_sim_package.arr));
        }

        if(GetField_CString(hRls,"currency",&csTmp)) {
                hv_sim_currency.len = strlen(csTmp);
                strncpy((char*)hv_sim_currency.arr, csTmp, hv_sim_currency.len);
                ind_sim_currency = 0;
DEBUGLOG(("Add:sim_currency = [%.*s]\n",hv_sim_currency.len, hv_sim_currency.arr));
        }

        if(GetField_Int(hRls, "billed_date", &iTmp)) {
                hv_billed_date = iTmp;
                ind_billed_date = 0;
DEBUGLOG(("Add:billed_date = [%d]\n",hv_billed_date));
        }

        if(GetField_CString(hRls,"last_topup_date",&csTmp)) {
                hv_last_topup_date.len = strlen(csTmp);
                strncpy((char*)hv_last_topup_date.arr, csTmp, hv_last_topup_date.len);
                ind_last_topup_date = 0;
DEBUGLOG(("Add:last_topup_date = [%.*s]\n",hv_last_topup_date.len, hv_last_topup_date.arr));
        }

        if(GetField_CString(hRls,"next_topup_date",&csTmp)) {
                hv_next_topup_date.len = strlen(csTmp);
                strncpy((char*)hv_next_topup_date.arr, csTmp, hv_next_topup_date.len);
                ind_next_topup_date = 0;
DEBUGLOG(("Add:next_topup_date = [%.*s]\n",hv_next_topup_date.len, hv_next_topup_date.arr));
        }

        if(GetField_CString(hRls,"expired_date",&csTmp)) {
                hv_expired_date.len = strlen(csTmp);
                strncpy((char*)hv_expired_date.arr, csTmp, hv_expired_date.len);
                ind_expired_date = 0;
DEBUGLOG(("Add:expired_date = [%.*s]\n",hv_expired_date.len, hv_expired_date.arr));
        }

        if(GetField_CString(hRls,"password",&csTmp)) {
                hv_password.len = strlen(csTmp);
                strncpy((char*)hv_password.arr, csTmp, hv_password.len);
                ind_password = 0;
DEBUGLOG(("Add:password = [%.*s]\n",hv_password.len, hv_password.arr));
        }

        if(GetField_Char(hRls, "status", &cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
        }

        if(GetField_CString(hRls,"remark",&csTmp)) {
                hv_remarks.len = strlen(csTmp);
                strncpy((char*)hv_remarks.arr, csTmp, hv_remarks.len);
                ind_remarks = 0;
DEBUGLOG(("Add:remarks = [%.*s]\n",hv_remarks.len, hv_remarks.arr));
        }

	if(GetField_CString(hRls,"sim_nature",&csTmp)) {
		hv_sim_nature.len = strlen(csTmp);
		strncpy((char*)hv_sim_nature.arr, csTmp, hv_sim_nature.len);
		ind_sim_nature = 0;
DEBUGLOG(("Add:sim_nature = [%.*s]\n",hv_sim_nature.len, hv_sim_nature.arr));
	}

        if(GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        } else if(GetField_CString(hRls,"update_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_sim_cards_insert(
						:hv_mobile:ind_mobile,
						:hv_carriers:ind_carriers,
						:hv_country:ind_country,
						:hv_owner_name:ind_owner_name,
						:hv_sim_credit:ind_sim_credit,
						:hv_sim_package:ind_sim_package,
						:hv_sim_currency:ind_sim_currency,
						:hv_billed_date:ind_billed_date,
						:hv_last_topup_date:ind_last_topup_date,
						:hv_next_topup_date:ind_next_topup_date,
						:hv_expired_date:ind_expired_date,
						:hv_password:ind_password,
						:hv_status:ind_status,
						:hv_remarks:ind_remarks,
						:hv_sim_nature:ind_sim_nature,
						:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_sim_cards_insert ( :hv_mobi\
le:ind_mobile , :hv_carriers:ind_carriers , :hv_country:ind_country , :hv_own\
er_name:ind_owner_name , :hv_sim_credit:ind_sim_credit , :hv_sim_package:ind_\
sim_package , :hv_sim_currency:ind_sim_currency , :hv_billed_date:ind_billed_\
date , :hv_last_topup_date:ind_last_topup_date , :hv_next_topup_date:ind_next\
_topup_date , :hv_expired_date:ind_expired_date , :hv_password:ind_password ,\
 :hv_status:ind_status , :hv_remarks:ind_remarks , :hv_sim_nature:ind_sim_nat\
ure , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_mobile;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_carriers;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_carriers;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_owner_name;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_owner_name;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_sim_credit;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_sim_credit;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sim_package;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_sim_package;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_sim_currency;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_sim_currency;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_billed_date;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_billed_date;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_last_topup_date;
 sqlstm.sqhstl[9] = (unsigned long )10;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_last_topup_date;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_next_topup_date;
 sqlstm.sqhstl[10] = (unsigned long )10;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_next_topup_date;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_expired_date;
 sqlstm.sqhstl[11] = (unsigned long )10;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_expired_date;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_password;
 sqlstm.sqhstl[12] = (unsigned long )42;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_password;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[13] = (unsigned long )1;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_status;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_remarks;
 sqlstm.sqhstl[14] = (unsigned long )102;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_remarks;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_sim_nature;
 sqlstm.sqhstl[15] = (unsigned long )5;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_sim_nature;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[16] = (unsigned long )22;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLSimCards_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLSimCards_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLSimCards_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRls)
{
        char    *csBuf;
	char*	csTmp;
	char	cTmp;
	int	iTmp;
	double	dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


		/* varchar hv_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile;

		int v_cnt;

		short ind_mobile = -1;
		short hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update ol_sim_cards set osc_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*carriers*/
        if (GetField_CString(hRls,"carriers",&csTmp)) {
DEBUGLOG(("Update:update_carriers = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_carriers = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*owner_name*/
        if (GetField_CString(hRls,"owner_name",&csTmp)) {
DEBUGLOG(("Update:update_owner_name = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_owner_name = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        } else {	
DEBUGLOG(("Update:update_owner_name = null\n"));	
                strcat((char*)hv_dynstmt.arr, ",osc_owner_name = null");	
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*sim_credit*/
        if (GetField_Double(hRls,"sim_credit",&dTmp)) {
DEBUGLOG(("Update:update_sim_credit = [%lf]\n",dTmp));
                sprintf(csBuf,"%lf",dTmp);
                strcat((char*)hv_dynstmt.arr, ",osc_sim_credit = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*sim_package*/
        if (GetField_CString(hRls,"sim_package",&csTmp)) {
DEBUGLOG(("Update:update_sim_package = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_sim_package = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*billed_date*/
        if (GetField_Int(hRls,"billed_date",&iTmp)) {
DEBUGLOG(("Update:update_billed_date = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",osc_billed_date = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        } else {	
DEBUGLOG(("Update:update_billed_date = null\n"));	
                strcat((char*)hv_dynstmt.arr, ",osc_billed_date = null");	
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*last_topup_date*/
        if (GetField_CString(hRls,"last_topup_date",&csTmp)) {
DEBUGLOG(("Update:update_last_topup_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_last_topup_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*next_topup_date*/
        if (GetField_CString(hRls,"next_topup_date",&csTmp)) {
DEBUGLOG(("Update:update_next_topup_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_next_topup_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*expired_date*/
        if (GetField_CString(hRls,"expired_date",&csTmp)) {
DEBUGLOG(("Update:update_expired_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_expired_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*password*/
        if (GetField_CString(hRls,"password",&csTmp)) {
DEBUGLOG(("Update:update_password = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_password = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr); 
        } else {	
DEBUGLOG(("Update:update_password = null\n"));	
                strcat((char*)hv_dynstmt.arr, ",osc_password = null");	
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*status*/
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:update_status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",osc_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*remarks*/
        if (GetField_CString(hRls,"remark",&csTmp)) {
DEBUGLOG(("Update:update_remarks = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_remarks = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        } else {	
DEBUGLOG(("Update:update_remarks = null\n"));	
                strcat((char*)hv_dynstmt.arr, ",osc_remarks = null");	
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*sim_nature*/
        if (GetField_CString(hRls,"sim_nature",&csTmp)) {
DEBUGLOG(("Update:update_sim_nature = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_sim_nature = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        } else {	
DEBUGLOG(("Update:update_sim_nature = null\n"));	
                strcat((char*)hv_dynstmt.arr, ",osc_sim_nature = null");	
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",osc_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Primary Key: mobile*/
        if (GetField_CString(hRls,"mob_num",&csTmp)) {
DEBUGLOG(("Update: mobile = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE osc_mobile = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		hv_mobile.len = strlen(csTmp);
		strncpy((char*)hv_mobile.arr, csTmp, hv_mobile.len);
		ind_mobile = 0;
	}

/* add into log */
	/* EXEC SQL SELECT count(*)
		INTO :v_cnt
		FROM ol_sim_cards_log
		WHERE oscl_mobile = :hv_mobile:ind_mobile; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_sim_cards_log WHERE osc\
l_mobile = :b1:b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )88;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



	if (v_cnt == 0) {
		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_sim_cards_log_insert(
					:hv_mobile:ind_mobile);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_sim_cards_log_insert ( :hv\
_mobile:ind_mobile ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )111;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
  if (sqlca.sqlcode < 0) goto update_error;
}



		if (hv_return_value == SP_OK)
		{
DEBUGLOG(("Add Orig Log: Normal Exit\n"));
		}

		if (hv_return_value == SP_OTHER_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
			return PD_OTHER_ERR;
		}

		if (hv_return_value == SP_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_ERR\n"));
			return PD_ERR;
		}
	}

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )134;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )153;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);
	
/* update log */
	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_sim_cards_log_insert(
					:hv_mobile:ind_mobile);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_sim_cards_log_insert ( :hv_\
mobile:ind_mobile ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )168;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Update: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
DEBUGLOG(("Update: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
DEBUGLOG(("Update: SP_ERR\n"));
		return PD_ERR;
	}

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLSimCards:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int DisposeSimCard(const hash_t *hRls)
{
	char    *csBuf;
	char*   csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO disposesimcard_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

		int v_cnt;

		/* varchar	hv_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile;

		short	ind_mobile = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DisposeSimCard: Begin\n"));
	csBuf = (char *)malloc(128);

	strcpy((char*)hv_dynstmt.arr,"update ol_sim_cards set osc_update_timestamp  = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/*status*/
	strcat((char*)hv_dynstmt.arr, ",osc_status = 'D'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/*update_user*/
	if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",osc_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	/*Primary Key: mobile*/
	if (GetField_CString(hRls,"old_mobile",&csTmp)) {
DEBUGLOG(("Update: mobile = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE osc_mobile = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		hv_mobile.len = strlen(csTmp);
		strncpy((char*)hv_mobile.arr, csTmp, hv_mobile.len);
		ind_mobile = 0;
	}

/* add into log */
	/* EXEC SQL SELECT count(*)
		INTO :v_cnt
		FROM ol_sim_cards_log
		WHERE oscl_mobile = :hv_mobile:ind_mobile; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_sim_cards_log WHERE osc\
l_mobile = :b1:b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )191;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
 if (sqlca.sqlcode < 0) goto disposesimcard_error;
}



	if (v_cnt == 0) {
		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_sim_cards_log_insert(
					:hv_mobile:ind_mobile);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_sim_cards_log_insert ( :hv\
_mobile:ind_mobile ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )214;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
  if (sqlca.sqlcode < 0) goto disposesimcard_error;
}



		if (hv_return_value == SP_OK)
		{
DEBUGLOG(("Add Orig Log: Normal Exit\n"));
		}

		if (hv_return_value == SP_OTHER_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
			return PD_OTHER_ERR;
		}

		if (hv_return_value == SP_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_ERR\n"));
			return PD_ERR;
		}
	}

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )237;
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
 if (sqlca.sqlcode < 0) goto disposesimcard_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )256;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto disposesimcard_error;
}



	FREE_ME(csBuf);

/* update log */
	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_sim_cards_log_insert(
					:hv_mobile:ind_mobile);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_sim_cards_log_insert ( :hv_\
mobile:ind_mobile ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )271;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_mobile;
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
 if (sqlca.sqlcode < 0) goto disposesimcard_error;
}



	if (hv_return_value == SP_OK) {
DEBUGLOG(("Update: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
DEBUGLOG(("Update: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
DEBUGLOG(("Update: SP_ERR\n"));
		return PD_ERR;
	}

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

disposesimcard_error:
DEBUGLOG(("DisposeSimCard_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchDetail_DisposeSimCard: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetSimCardStatus(const char* csMobile, char* cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO GetSimCardStatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar         hv_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile;

	char            v_status;
	short           ind_status = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetSimCardStatus: Begin\n"));

	//mobile
	hv_mobile.len = strlen(csMobile);
	memcpy(hv_mobile.arr,csMobile,hv_mobile.len);
	DEBUGLOG(("GetSimCardStatus:mobile = [%.*s]\n",hv_mobile.len,hv_mobile.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			SELECT OSC_STATUS INTO :v_status:ind_status
			FROM OL_SIM_CARDS
			WHERE OSC_MOBILE = :hv_mobile;
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin SELECT OSC_STATUS INTO :v_status:ind_status FROM OL_S\
IM_CARDS WHERE OSC_MOBILE = :hv_mobile ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )294;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_status;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile;
 sqlstm.sqhstl[1] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto GetSimCardStatus_error;
}


    
	if (ind_status == -1) {
		v_status = ' ';
	}

	*cStatus = (char) v_status;

DEBUGLOG(("GetSimCardStatus:status = [%c]\n",v_status));

	return PD_OK;

GetSimCardStatus_error:
DEBUGLOG(("GetSimCardStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("OLSimCards::GetSimCardStatus : SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}
