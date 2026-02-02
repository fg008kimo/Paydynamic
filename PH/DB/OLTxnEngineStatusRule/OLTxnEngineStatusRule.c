
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "OLTxnEngineStatusRule.pc"
};


static unsigned int sqlctx = 1328661027;


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

 static char *sq0001 = 
"SELECT ESR_STATUS , ESR_AR_IND , ESR_SUB_STATUS , ESR_RECON_STATUS , ESR_CL\
ASSIFIED_STATUS FROM OL_TXN_ENGINE_STATUS_RULE WHERE ESR_RULE_ID = :b0       \
     ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,157,0,9,73,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,76,0,0,5,0,0,1,0,2,1,0,0,2,1,0,0,2,9,0,0,2,1,0,0,2,1,0,0,
59,0,0,1,0,0,15,126,0,0,0,0,0,1,0,
74,0,0,1,0,0,15,144,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/03              [WWK]
Reduce log					   2021/04/30		   [MSN]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "dbutility.h"
#include "OLTxnEngineStatusRule.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void OLTxnEngineStatusRule(char cdebug)
{
        cDebug = cdebug;
}

int GetStatusRule(const int iRuleId, hash_t* hRec)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char*   csBuf = (char*) malloc (PD_TMP_BUF_LEN +1);
	memset(csBuf, 0, sizeof(csBuf));

	/* EXEC SQL WHENEVER SQLERROR GOTO getstatusrule_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_rule_id;

		char	v_status;
		char	v_ar_ind;
		/* varchar	v_sub_status[PD_SUB_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		char	v_recon_status;
		char	v_classified_status;

		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_sub_status = -1;
		short	ind_recon_status = -1;
		short	ind_classified_status = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_rule_id = iRuleId;
DEBUGLOG(("GetStatusRule rule_id = [%d]\n", hv_rule_id));

	/* EXEC SQL DECLARE c_getstatusrule CURSOR FOR
		SELECT	ESR_STATUS,
			ESR_AR_IND,
			ESR_SUB_STATUS,
			ESR_RECON_STATUS,
			ESR_CLASSIFIED_STATUS
		FROM	OL_TXN_ENGINE_STATUS_RULE
		WHERE	ESR_RULE_ID = :hv_rule_id; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getstatusrule; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_id;
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
  if (sqlca.sqlcode < 0) goto getstatusrule_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getstatusrule
			INTO	
				:v_status:ind_status,
				:v_ar_ind:ind_ar_ind,
				:v_sub_status:ind_sub_status,
				:v_recon_status:ind_recon_status,
				:v_classified_status:ind_classified_status; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 5;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_status;
   sqlstm.sqhstl[0] = (unsigned long )1;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_status;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_ar_ind;
   sqlstm.sqhstl[1] = (unsigned long )1;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_ar_ind;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_sub_status;
   sqlstm.sqhstl[2] = (unsigned long )6;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_sub_status;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_recon_status;
   sqlstm.sqhstl[3] = (unsigned long )1;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_recon_status;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_classified_status;
   sqlstm.sqhstl[4] = (unsigned long )1;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_classified_status;
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
   if (sqlca.sqlcode < 0) goto getstatusrule_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			sprintf(csBuf, "[%d]:", hv_rule_id);
			if (ind_status >= 0) {
				PutField_Char(hRec, "status", v_status);
				sprintf(csBuf, "%s status[%c]", csBuf, v_status);
//DEBUGLOG(("GetStatusRule status = [%c]\n", v_status));
			}

			if (ind_ar_ind >= 0) {
				PutField_Char(hRec, "ar_ind", v_ar_ind);
				sprintf(csBuf, "%s ar_ind[%c]", csBuf, v_ar_ind);
//DEBUGLOG(("GetStatusRule ar_ind = [%c]\n", v_ar_ind));
			}

			if (ind_sub_status >= 0) {
				v_sub_status.arr[v_sub_status.len] = '\0';
				PutField_CString(hRec, "sub_status", (const char*)v_sub_status.arr);
				sprintf(csBuf, "%s sub_status[%s]", csBuf, v_sub_status.arr);
//DEBUGLOG(("GetStatusRule sub_status = [%s]\n", v_sub_status.arr));
			}

			if (ind_recon_status >= 0) {
				PutField_Char(hRec, "recon_status", v_recon_status);
				sprintf(csBuf, "%s recon_status[%c]", csBuf, v_recon_status);
//DEBUGLOG(("GetStatusRule recon_status = [%c]\n", v_recon_status));
			}

			if (ind_classified_status >= 0) {
				PutField_Char(hRec, "classified_status", v_classified_status);
				sprintf(csBuf, "%s classified_status[%c]", csBuf, v_classified_status);
//DEBUGLOG(("GetStatusRule classified_status = [%c]\n", v_classified_status));
			}

DEBUGLOG((" %s\n", csBuf));
			break;

		}
		/* EXEC SQL CLOSE c_getstatusrule; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getstatusrule_error;
}



		if (iCnt <= 0) {
DEBUGLOG((" no rule found\n"));
ERRLOG("OLPspTxnStatusRule: GetStatusRule no rule found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetStatusRule Normal Exit! iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;

getstatusrule_error:
DEBUGLOG(("getstatusrule_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPspTxnStatusRule getstatusrule_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getstatusrule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstatusrule_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

