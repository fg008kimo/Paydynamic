
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
    "TxnBalanceLog.pc"
};


static unsigned int sqlctx = 5385475;


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
5,0,0,1,196,0,6,90,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,0,0,
40,0,0,2,109,0,4,149,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,
67,0,0,3,123,0,6,213,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,
94,0,0,4,105,0,4,277,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,
};


/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/03/10              [CLY]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnBalanceLog.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void TxnBalanceLog(char cdebug){
	cDebug = cdebug;
}

int UpdateBalLog(hash_t *hIn)
{


	int	iTmp = 0;
	char* 	csTmp;
	char	cTmp;

	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_bal_log_error; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		char		hv_party_type;
		int             hv_is_completed;
		/* varchar		hv_update_user[PD_UPDATE_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		
		short		ind_txn_aprv_date = -1;
		short		ind_party_type = -1;
		short		ind_is_completed = -1;
		short		ind_update_user = -1;
		
		short		hv_return_value;


	/* EXEC SQL END DECLARE SECTION; */ 


	/*txn_aprv_date*/
        if(GetField_CString(hIn,"txn_aprv_date",&csTmp)){
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
DEBUGLOG(("Add:txn_aprv_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
		ind_txn_aprv_date = 0;
        }

	/*is_completed*/
        if (GetField_Int(hIn,"is_completed",&iTmp)) {
                hv_is_completed = iTmp;
DEBUGLOG(("Add:is_completed = [%d]\n",hv_is_completed));
        	ind_is_completed = 0;
	}


	/*party_type*/
        if (GetField_Char(hIn,"party_type",&cTmp)) {
                hv_party_type = cTmp;
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));
        	ind_party_type = 0;
	}

	/*update_user*/
        if(GetField_CString(hIn,"update_user",&csTmp)){
                hv_update_user.len = strlen(csTmp);
                memcpy(hv_update_user.arr, csTmp, hv_update_user.len);
DEBUGLOG(("Add:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        	ind_update_user = 0;
	}

	/* EXEC SQL EXECUTE
		BEGIN

			:hv_return_value := sp_update_txn_balance_log(
				:hv_txn_date:ind_txn_aprv_date,
				:hv_party_type:ind_party_type,
				:hv_is_completed:ind_is_completed,
				:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_update_txn_balance_log ( :hv_t\
xn_date:ind_txn_aprv_date , :hv_party_type:ind_party_type , :hv_is_completed:\
ind_is_completed , :hv_update_user:ind_update_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_aprv_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_party_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_is_completed;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_is_completed;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto update_bal_log_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateBalLog Normal Exit\n"));
		iRet = PD_OK;
	}else if (hv_return_value == SP_OTHER_ERR)
	{
DEBUGLOG(("TxnBalanceLog_UpdateBalLog SP_OTHER_ERR \n"));
ERRLOG("TxnBalanceLog_UpdateBalLog: SP_OTHER_ERR \n");
		iRet = PD_ERR;
	}else if (hv_return_value == SP_ERR)
	{
ERRLOG("TxnBalanceLog_UpdateBalLog: SP_ERR \n");
DEBUGLOG(("TxnBalanceLog_UpdateBalLog SP_ERR \n"));
		iRet = PD_ERR;
	}


	return iRet;

update_bal_log_error:
DEBUGLOG(("update_bal_log_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnBalanceLog_UpdateBalLog: SP_INTERNAL_ERR\n");
/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}



int IsCompleted(const char* csDate, const char cParty)
{

	int	iRet = PD_FALSE;
 
	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

                char            hv_party_type;
                int             v_is_completed;
                short           ind_is_completed = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_date.len = strlen(csDate);
        memcpy(hv_txn_date.arr, csDate, hv_txn_date.len);
        hv_party_type = cParty;

        /* EXEC SQL SELECT tb_is_completed
                 INTO   :v_is_completed:ind_is_completed
                 FROM	TXN_BALANCE_LOG
                 WHERE tb_txn_aprv_date = :hv_txn_date
                   AND     tb_party_type = :hv_party_type; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select tb_is_completed INTO :b0:b1 FROM TXN_BALANCE_\
LOG WHERE tb_txn_aprv_date = :b2 AND tb_party_type = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )40;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_is_completed;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_is_completed;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto get_error;
}





        if(ind_is_completed >=0 )
	{
DEBUGLOG(("TxnBalanceLog_IsCompleted: is_completed = %d\n",v_is_completed));
		if(v_is_completed == 1)
		{
			iRet = PD_TRUE;
		}
	}
	return iRet;

get_error:
DEBUGLOG(("is_completed_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnBalanceLog_UpdateBalLog: SP_INTERNAL_ERR\n");
/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}



int IsPrevCompleted(hash_t *hRec)
{
	int     iRet = PD_TRUE;

        char 	cTmp;

        char 	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO isprevcompleted_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

                char            hv_party_type;

		short   	ind_txn_date = -1;
                short   	ind_party_type = -1;

		short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_aprv_date */
        if (GetField_CString(hRec,"txn_aprv_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("IsPrevCompleted: txn_aprv_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));
        }

/* party_type */
        if (GetField_Char(hRec,"party_type",&cTmp)) {
                hv_party_type = cTmp;
		ind_party_type = 0;
DEBUGLOG(("IsPrevCompleted: party_type = [%c]\n", hv_party_type));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_chk_txn_bal_log_prev_cpl(:hv_txn_date:ind_txn_date,
                                                                        :hv_party_type:ind_party_type);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_chk_txn_bal_log_prev_cpl ( :hv\
_txn_date:ind_txn_date , :hv_party_type:ind_party_type ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_party_type;
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
 if (sqlca.sqlcode < 0) goto isprevcompleted_error;
}


	
        if (hv_return_value == SP_OK) {
DEBUGLOG(("IsPrevCompleted: True!!\n"));
		iRet = PD_TRUE;
	} else if (hv_return_value == SP_ERR) {
DEBUGLOG(("IsPrevCompleted: False!!\n"));
		iRet = PD_FALSE;
        } else if (hv_return_value == SP_OTHER_ERR) {
DEBUGLOG(("IsPrevCompleted: Other Error\n"));
ERRLOG("TxnBalanceLog: IsPrevCompleted: Other Error\n");
                iRet = PD_ERR;
        }

	return iRet;

isprevcompleted_error:
DEBUGLOG(("isprevcompleted_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnBalanceLog_Check: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int IsExisted(hash_t *hRec)
{
	int     iRet = PD_FALSE;

        char 	cTmp;

        char 	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO isexisted_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

                char            hv_party_type;

                int             v_no_of_record;

                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_aprv_date */
        if (GetField_CString(hRec,"txn_aprv_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
DEBUGLOG(("IsExisted: txn_aprv_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));
        }

/* party_type */
        if (GetField_Char(hRec,"party_type",&cTmp)) {
                hv_party_type = cTmp;
DEBUGLOG(("IsExisted: party_type = [%c]\n", hv_party_type));
        }

        /* EXEC SQL SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM txn_balance_log
                  WHERE tb_txn_aprv_date = :hv_txn_date
                    AND tb_party_type = :hv_party_type; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_balance_log \
WHERE tb_txn_aprv_date = :b2 AND tb_party_type = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )94;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto isexisted_error;
}



        if(ind_no_of_record >= 0){
                if(v_no_of_record > 0){
                        iRet = PD_TRUE;
                }
        }

        if (iRet == PD_TRUE){
DEBUGLOG(("IsExisted: True!!\n"));
        } else {
DEBUGLOG(("IsExisted: False!!\n"));
        }
	
	return iRet;

isexisted_error:
DEBUGLOG(("isexisted_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnBalanceLog_Check: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

