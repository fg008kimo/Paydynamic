
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
    "HoldAmount.pc"
};


static unsigned int sqlctx = 605947;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"select hv_type ,hv_total_hold ,hv_holded_amt ,hv_hold_remain  from hold_amo\
unt where ((((hv_state<>'C' and hv_merchant_id=:b0) and hv_currency_id=:b1) a\
nd hv_country_id=:b2) and hv_service_code=:b3) order by hv_type            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,227,0,9,93,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,1,0,0,13,95,0,0,4,0,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
67,0,0,1,0,0,15,136,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,152,0,0,0,0,0,1,0,
97,0,0,2,211,0,4,208,0,0,7,5,0,1,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
140,0,0,3,252,0,6,323,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,4,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/08              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "HoldAmount.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void HoldAmount(char    cdebug)
{
        cDebug = cdebug;
}


int GetAllHold(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_all_error; */ 

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


                /* varchar         v_type[PD_HOLD_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_type;
                
		double		v_total_hold;
		double		v_holded;
		double		v_remain;

		short		ind_type= -1;
		short		ind_total_hold= -1;
		short		ind_holded= -1;
		short		ind_remain= -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetAllHold:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
DEBUGLOG(("GetAllHold:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
        
        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
DEBUGLOG(("GetAllHold:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("GetAllHold:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


	/* EXEC SQL DECLARE c_cursor_getall CURSOR FOR
		select	hv_type,
			hv_total_hold,
			hv_holded_amt,
			hv_hold_remain
		from	hold_amount
		where	hv_state != 'C'
		and	hv_merchant_id = :hv_merchant_id
                and	hv_currency_id = :hv_ccy_id
                and	hv_country_id = :hv_country_id
                and	hv_service_code = :hv_service_code
		order by hv_type; */ 


	/* EXEC SQL OPEN c_cursor_getall; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
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
 if (sqlca.sqlcode < 0) goto get_all_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getall
		INTO
			:v_type:ind_type,
			:v_total_hold:ind_total_hold,
			:v_holded:ind_holded,
			:v_remain:ind_remain; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )36;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_type;
  sqlstm.sqhstl[0] = (unsigned long )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_type;
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
  sqlstm.sqhstv[2] = (unsigned char  *)&v_holded;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_holded;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_remain;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_remain;
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
  if (sqlca.sqlcode < 0) goto get_all_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if(ind_type>=0){
			v_type.arr[v_type.len]='\0';
			PutField_CString(myHash,"hold_type",(const char *)v_type.arr);
DEBUGLOG(("GetAllHold hold_type = [%s]\n",v_type.arr));
		}
		
		if(ind_total_hold<0)
			v_total_hold = 0.0;
		PutField_Double(myHash,"total_hold",v_total_hold);
DEBUGLOG(("GetAllHold total_hold = [%f]\n",v_total_hold));

		if(ind_holded<0)
			v_holded = 0.0;
		PutField_Double(myHash,"holded_amt",v_holded);
DEBUGLOG(("GetAllHold holded_amt = [%f]\n",v_holded));

		if(ind_remain<0)
			v_remain = 0.0;
		PutField_Double(myHash,"hold_remain",v_remain);
DEBUGLOG(("GetAllHold hold_remain = [%f]\n",v_remain));

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getall; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_all_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetAllHold Normal Exit\n"));
	}
	else {
DEBUGLOG(("GetAllHold Normal Exit, Not Found\n"));
		iRet = PD_ERR;
	}

	return iRet;

get_all_error:
DEBUGLOG(("get_all_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getall; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetHoldByType(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		const char* csType,
		double  *dHoldedAmt,
		double	*dHoldRemain)
{
	int iRet = PD_OK;
	*dHoldedAmt = 0.0;
	*dHoldRemain = 0.0;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_holdbytype_error; */ 

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

                /* varchar         hv_type[PD_HOLD_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_type;

                
		double		v_holded_amt;
		double		v_hold_remain;

		short		ind_holded_amt= -1;
		short		ind_hold_remain= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetHoldByType:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
DEBUGLOG(("GetHoldByType:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
        
        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
DEBUGLOG(("GetHoldByType:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("GetHoldByType:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));        

        hv_type.len = strlen(csType);
        memcpy(hv_type.arr,csType,hv_type.len);
DEBUGLOG(("GetHoldByType type = [%.*s]\n",hv_type.len,hv_type.arr));
        
        /* EXEC SQL 
                select	hv_holded_amt,
			hv_hold_remain
		into	:v_holded_amt:ind_holded_amt,
			:v_hold_remain:ind_hold_remain
                from	hold_amount
		where	hv_type = :hv_type
		and	hv_state != 'C'
		and     hv_merchant_id = :hv_merchant_id
                and     hv_currency_id = :hv_ccy_id
                and     hv_country_id = :hv_country_id
                and     hv_service_code = :hv_service_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select hv_holded_amt ,hv_hold_remain into :b0:b1,:b2\
:b3  from hold_amount where (((((hv_type=:b4 and hv_state<>'C') and hv_mercha\
nt_id=:b5) and hv_currency_id=:b6) and hv_country_id=:b7) and hv_service_code\
=:b8)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )97;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_holded_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_holded_amt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_hold_remain;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_hold_remain;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_type;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[3] = (unsigned long )17;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[5] = (unsigned long )4;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[6] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto get_holdbytype_error;
}



	if(ind_holded_amt>=0){
		*dHoldedAmt = v_holded_amt;
	}
	else{
DEBUGLOG(("GetHoldByType Holed Amt Not Found\n"));
		iRet = PD_ERR;
	}
DEBUGLOG(("GetHoldByType holded_amt = [%f]\n",*dHoldedAmt));

	if(ind_hold_remain>=0){
		*dHoldRemain = v_hold_remain;
	}
	else{
DEBUGLOG(("GetHoldByType Hole Remain Not Found\n"));
		iRet = PD_ERR;
	}
DEBUGLOG(("GetHoldByType hold_remain = [%f]\n",*dHoldRemain));

	
DEBUGLOG(("GetHoldByType iRet = [%i]\n",iRet));
	return iRet;

get_holdbytype_error:
DEBUGLOG(("get_holdbytype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int UpdateHoldAmount(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		const char* csType,
                double  dAmt,
		const char* csUser)

{

	/* EXEC SQL WHENEVER SQLERROR GOTO updatehold_error; */ 

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

		/* varchar		hv_type[PD_HOLD_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_type;

		double		hv_amt;
		/* varchar 	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
		short		ind_type = -1;
		short		ind_amt = -1;
		short		ind_update_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateHoldAmount: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("UpdateHoldAmount:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("UpdateHoldAmount:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
        
        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("UpdateHoldAmount:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("UpdateHoldAmount:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_type.len = strlen(csType);
	strncpy((char *)hv_type.arr, csType, hv_type.len);
	ind_type = 0;
DEBUGLOG(("UpdateHoldAmount: hold type = [%.*s]\n",hv_type.len,hv_type.arr));

	hv_amt= dAmt;
	ind_amt= 0;
DEBUGLOG(("UpdatIntransit:amt = [%f]\n",hv_amt));

	hv_update_user.len = strlen(csUser);
	strncpy((char *)hv_update_user.arr, csUser, hv_update_user.len);
	ind_update_user = 0;
DEBUGLOG(("UpdateHoldAmount:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_hold_amt_update(
				:hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
				:hv_type:ind_type,
				:hv_amt:ind_amt,
				:hv_update_user:ind_update_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_hold_amt_update ( :hv_merchant\
_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id ,\
 :hv_service_code:ind_service_code , :hv_type:ind_type , :hv_amt:ind_amt , :h\
v_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_amt;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_amt;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto updatehold_error;
}




DEBUGLOG(("UpdateHoldAmount:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateHoldAmount:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("HoldAmount::UpdateHoldAmount: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldAmount: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("HoldAmount::UpdateHoldAmount: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldAmount: SP_ERR TxnAbort\n"));
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
