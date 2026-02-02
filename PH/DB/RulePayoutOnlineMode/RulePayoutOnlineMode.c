
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
    "RulePayoutOnlineMode.pc"
};


static unsigned int sqlctx = 678688675;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
5,0,0,1,150,0,4,63,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
36,0,0,2,133,0,4,125,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
67,0,0,3,193,0,4,184,0,0,5,3,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
102,0,0,4,124,0,4,244,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/21              LokManChow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "RulePayoutOnlineMode.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void RulePayoutOnlineMode(char    cdebug)
{
        cDebug = cdebug;
}


int ChkRuleExists(const unsigned char* csMerchantId,
                 const unsigned char* csServiceCode)
{
        int     iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkruleexists_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                int             hv_disabled;

                int             v_no_of_record;
                short           ind_no_of_record = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("ChkRuleExists: Begin\n"));

	hv_merchant_id.len = strlen((const char *)csMerchantId);
	strncpy((char*)hv_merchant_id.arr, (const char *)csMerchantId, hv_merchant_id.len);
DEBUGLOG(("ChkRuleExists:merchant_id = [%.*s]\n",hv_merchant_id.len, hv_merchant_id.arr));

	hv_service_code.len = strlen((const char *)csServiceCode);
	strncpy((char*)hv_service_code.arr, (const char *)csServiceCode, hv_service_code.len);
DEBUGLOG(("ChkRuleExists:service_code = [%.*s]\n",hv_service_code.len, hv_service_code.arr));

	hv_disabled = 0;
DEBUGLOG(("ChkRuleExists:disabled = [%d]\n",hv_disabled));

	        /* EXEC SQL
                	SELECT count(1)
			INTO :v_no_of_record:ind_no_of_record
			FROM rule_payout_online_mode
			WHERE rp_merchant_id = :hv_merchant_id
			AND   rp_service_code = :hv_service_code
			AND   rp_disabled = :hv_disabled
			and rownum = 1; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 4;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM rule_payout_onl\
ine_mode WHERE rp_merchant_id = :b2 AND rp_service_code = :b3 AND rp_disabled\
 = :b4 and rownum = 1 ";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )5;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
         sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
         sqlstm.sqhstl[1] = (unsigned long )17;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)0;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
         if (sqlca.sqlcode < 0) goto chkruleexists_error;
}




        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("ChkRuleExists FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkRuleExists NOT FOUND\n"));
        }


        return iRet;

chkruleexists_error:
DEBUGLOG(("ChkRuleExists_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int FindPsp(const unsigned char* csMerchantId,
	    const unsigned char* csServiceCode,
            unsigned char* csPspId)
{
        int iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                int     hv_disabled;

                /* varchar v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


                short   ind_psp_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen((const char*)csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("FindPsp: merchant_id= [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_service_code.len = strlen((const char*)csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindPsp: ServiceCode = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_disabled=0;

	/* EXEC SQL
		SELECT rp_psp_id
		INTO :v_psp_id:ind_psp_id
		FROM rule_payout_online_mode
		WHERE rp_merchant_id = :hv_merchant_id
		AND   rp_service_code = :hv_service_code
		AND   rp_disabled = :hv_disabled; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select rp_psp_id INTO :b0:b1 FROM rule_payout_online_mode W\
HERE rp_merchant_id = :b2 AND rp_service_code = :b3 AND rp_disabled = :b4 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_psp_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto find_error;
}



	if(ind_psp_id>=0){
		v_psp_id.arr[v_psp_id.len] = '\0';
                strcpy((char*)csPspId,(const char*)v_psp_id.arr);
DEBUGLOG(("psp_id = [%s]\n",csPspId));
                iRet = PD_FOUND;
	}

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("FindPsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int FindPspInfo(const unsigned char* csMerchantId,
	    const unsigned char* csServiceCode,
            hash_t *hTxn)
{
        int iRet = PD_NOT_FOUND;

DEBUGLOG(("FindPspInfo\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO findinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                int     hv_disabled;

                /* varchar v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar v_psp_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_psp_ccy;


                short   ind_psp_id = -1;
                short   ind_psp_ccy = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen((const char*)csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("FindPspInfo: merchant_id= [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_service_code.len = strlen((const char*)csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindPspInfo: ServiceCode = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_disabled=0;

	/* EXEC SQL
		SELECT rp_psp_id,
		       currency_id
		INTO :v_psp_id:ind_psp_id,
		     :v_psp_ccy:ind_psp_ccy
		FROM rule_payout_online_mode, psp_country
		WHERE rp_merchant_id = :hv_merchant_id
		AND   rp_service_code = :hv_service_code
		AND   rp_disabled = :hv_disabled
		AND   rp_psp_id = psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select rp_psp_id , currency_id INTO :b0:b1 , :b2:b3 FROM ru\
le_payout_online_mode , psp_country WHERE rp_merchant_id = :b4 AND rp_service\
_code = :b5 AND rp_disabled = :b6 AND rp_psp_id = psp_id ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_psp_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_ccy;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_ccy;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto findinfo_error;
}



	if(ind_psp_id>=0 && ind_psp_ccy>=0){
		v_psp_id.arr[v_psp_id.len] = '\0';
                PutField_CString(hTxn,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("psp_id = [%s]\n",v_psp_id.arr));

		v_psp_ccy.arr[v_psp_ccy.len] = '\0';
                PutField_CString(hTxn,"psp_ccy",(const char*)v_psp_ccy.arr);
DEBUGLOG(("psp_ccy = [%s]\n",v_psp_ccy.arr));

                iRet = PD_FOUND;
	}

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;

findinfo_error:
DEBUGLOG(("FindPspInfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int ChkRuleExistsByMerchant(const unsigned char* csMerchantId)
{
        int     iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkruleexistsm_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                int             hv_disabled;

                int             v_no_of_record;
                short           ind_no_of_record = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("ChkRuleExistsByMerchant: Begin\n"));

	hv_merchant_id.len = strlen((const char *)csMerchantId);
	strncpy((char*)hv_merchant_id.arr, (const char *)csMerchantId, hv_merchant_id.len);
DEBUGLOG(("ChkRuleExistsByMerchant:merchant_id = [%.*s]\n",hv_merchant_id.len, hv_merchant_id.arr));

	hv_disabled = 0;
DEBUGLOG(("ChkRuleExistsByMerchant:disabled = [%d]\n",hv_disabled));

	        /* EXEC SQL
                	SELECT count(1)
			INTO :v_no_of_record:ind_no_of_record
			FROM rule_payout_online_mode
			WHERE rp_merchant_id = :hv_merchant_id
			AND   rp_disabled = :hv_disabled
			and rownum = 1; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 5;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM rule_payout_onl\
ine_mode WHERE rp_merchant_id = :b2 AND rp_disabled = :b3 and rownum = 1 ";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )102;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
         sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
         sqlstm.sqhstl[1] = (unsigned long )17;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
         if (sqlca.sqlcode < 0) goto chkruleexistsm_error;
}




        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("ChkRuleExistsByMerchant FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkRuleExistsByMerchant NOT FOUND\n"));
        }


        return iRet;

chkruleexistsm_error:
DEBUGLOG(("ChkRuleExistsByMerchant_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
