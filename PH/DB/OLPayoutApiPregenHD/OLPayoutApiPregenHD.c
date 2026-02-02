
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "OLPayoutApiPregenHD.pc"
};


static unsigned int sqlctx = 326522811;


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

 static char *sq0002 = 
"select oap_batch_id , oap_payout_group , oap_status , oap_pregen_ret_code ,\
 oap_gen_ret_code from ol_payout_api_pregen_hd where oap_action_id = :b0     \
       ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,290,0,6,115,0,0,8,8,0,1,0,2,3,0,0,1,68,0,0,1,68,0,0,1,9,0,0,1,1,0,0,1,
3,0,0,1,3,0,0,1,9,0,0,
52,0,0,2,159,0,9,200,0,2049,1,1,0,1,0,1,68,0,0,
71,0,0,2,0,0,13,203,0,0,5,0,0,1,0,2,68,0,0,2,9,0,0,2,1,0,0,2,3,0,0,2,3,0,0,
106,0,0,2,0,0,15,254,0,0,0,0,0,1,0,
121,0,0,2,0,0,15,264,0,0,0,0,0,1,0,
136,0,0,3,64,0,4,281,0,0,1,0,0,1,0,2,68,0,0,
155,0,0,4,0,0,17,384,0,0,1,1,0,1,0,1,9,0,0,
174,0,0,4,0,0,21,385,0,0,0,0,0,1,0,
189,0,0,5,120,0,6,441,0,0,3,3,0,1,0,2,3,0,0,1,68,0,0,1,1,0,0,
216,0,0,0,0,0,56,527,0,0,1,1,0,1,0,3,102,0,0,
235,0,0,6,166,0,6,529,0,0,5,5,0,1,0,2,3,0,0,1,68,0,0,1,1,0,0,1,3,0,0,2,102,0,0,
270,0,0,0,0,0,13,544,0,0,2,1,0,1,0,1,102,0,0,2,68,0,0,
293,0,0,0,0,0,15,564,0,0,1,1,0,1,0,1,102,0,0,
312,0,0,0,0,0,78,565,0,0,1,1,0,1,0,3,102,0,0,
331,0,0,0,0,0,15,581,0,0,1,1,0,1,0,1,102,0,0,
350,0,0,0,0,0,78,582,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/13              Dirk Wong
Get pregen info by action_id                       2017/07/06              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPayoutApiPregenHD.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLPayoutApiPregenHD(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRec)
{
	char            *csTmp;
	char		cTmp;
        int             iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_action_id;
                unsigned long   hv_batch_id;
		/* varchar		hv_payout_group[PD_OFL_PAYOUT_GROUP_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_payout_group;

		char		hv_status;
		int		hv_pregen_ret_code;
		int		hv_gen_ret_code;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

                
                short           ind_action_id= -1;
                short           ind_batch_id= -1;
                short           ind_payout_group= -1;
                short           ind_status= -1;
                short           ind_pregen_ret_code= -1;
                short           ind_gen_ret_code= -1;
                short           ind_add_user= -1;
                
                short           hv_return_value;
                /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

//action_id
        if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id = ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_action_id= 0;
DEBUGLOG(("Add:action_id= [%ld]\n",hv_action_id));
        }

//batch_id
        if(GetField_CString(hRec,"batch_id",&csTmp)){
                hv_batch_id = ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%ld]\n",hv_batch_id));
        }

//payout_group
        if(GetField_CString(hRec,"payout_group",&csTmp)){
                hv_payout_group.len = strlen(csTmp);
                memcpy(hv_payout_group.arr, csTmp, hv_payout_group.len);
                ind_payout_group= 0;
DEBUGLOG(("Add:payout_group= [%.*s]\n",hv_payout_group.len,hv_payout_group.arr));
        }

//status
        if(GetField_Char(hRec,"status",&cTmp)){
                hv_status = cTmp;
                ind_status= 0;
DEBUGLOG(("Add:status= [%.c]\n",hv_status));
        }

//pregen_ret_code
        if(GetField_Int(hRec,"pregen_ret_code",&iTmp)){
                hv_pregen_ret_code = iTmp;
                ind_pregen_ret_code= 0;
DEBUGLOG(("Add:pregen_ret_code= [%d]\n",hv_pregen_ret_code));
        }

//gen_ret_code
        if(GetField_Int(hRec,"gen_ret_code",&iTmp)){
                hv_gen_ret_code = iTmp;
                ind_gen_ret_code= 0;
DEBUGLOG(("Add:gen_ret_code= [%d]\n",hv_gen_ret_code));
        }

//user
        if(GetField_CString(hRec,"add_user",&csTmp)){
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_payout_api_pregen_hd_add(
                                        :hv_action_id:ind_action_id,
                                        :hv_batch_id:ind_batch_id,
                                        :hv_payout_group:ind_payout_group,
                                        :hv_status:ind_status,
					:hv_pregen_ret_code:ind_pregen_ret_code,
					:hv_gen_ret_code:ind_gen_ret_code,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_api_pregen_hd_add ( \
:hv_action_id:ind_action_id , :hv_batch_id:ind_batch_id , :hv_payout_group:in\
d_payout_group , :hv_status:ind_status , :hv_pregen_ret_code:ind_pregen_ret_c\
ode , :hv_gen_ret_code:ind_gen_ret_code , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_action_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_batch_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_payout_group;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_payout_group;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_status;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_pregen_ret_code;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_pregen_ret_code;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_gen_ret_code;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_gen_ret_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}


                
DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }
                
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLPayoutApiPregenHD_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiPregenHD_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenHD_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetHeader(const hash_t* hRec,recordset_t* myRec)
{
	hash_t *myHash;
	char*	csTmp;
	char    csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_action_id;

		unsigned long   v_batch_id;
		/* varchar		v_payout_group[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_payout_group;

		char		v_status;
		int        	v_pregen_ret_code;
		int        	v_gen_ret_code;

		short		ind_batch_id = -1;
		short		ind_payout_group = -1;
		short           ind_status= -1;
                short           ind_pregen_ret_code= -1;
                short           ind_gen_ret_code= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	//action_id
       	if (GetField_CString(hRec,"action_id",&csTmp)) {
             	hv_action_id= (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("GetHeader action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("GetHeader action_id not found\n"));
               	return INT_ERR;
	}

	/* EXEC SQL DECLARE c_cursor_getheader CURSOR FOR
		select
                      	oap_batch_id,
                       	oap_payout_group,
                      	oap_status,
                       	oap_pregen_ret_code,
                       	oap_gen_ret_code
             	from    ol_payout_api_pregen_hd
              	where   oap_action_id =:hv_action_id; */ 

        /* EXEC SQL OPEN  c_cursor_getheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )52;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_action_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto getheader_error;
}



	do{
		/* EXEC SQL FETCH c_cursor_getheader
		INTO
			:v_batch_id:ind_batch_id,
			:v_payout_group:ind_payout_group,
                        :v_status:ind_status,
			:v_pregen_ret_code:ind_pregen_ret_code,
			:v_gen_ret_code:ind_gen_ret_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )71;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_payout_group;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_payout_group;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_pregen_ret_code;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_pregen_ret_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_gen_ret_code;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_gen_ret_code;
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
  if (sqlca.sqlcode < 0) goto getheader_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

//batch_id
           	if(ind_batch_id>=0){
                      	sprintf(csBatchId, "%ld", v_batch_id);
                    	PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetHeader batch_id= [%s]\n",csBatchId));
               	}

//payout_group
		if(ind_payout_group>=0){
			v_payout_group.arr[v_payout_group.len]='\0';
			PutField_CString(myHash,"payout_group",(const char*)v_payout_group.arr);
DEBUGLOG(("GetHeader payout_group = [%s]\n",v_payout_group.arr));
		}

//status
                if(ind_status>=0){
                        PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetHeader status = [%c]\n",v_status));
                }

//pregen_ret_code
                if(ind_pregen_ret_code>=0){
                        PutField_Int(myHash,"pregen_ret_code",v_pregen_ret_code);
DEBUGLOG(("GetHeader pregen_ret_code = [%d]\n",v_pregen_ret_code));
        	}

//gen_ret_code
                if(ind_gen_ret_code>=0){
                        PutField_Int(myHash,"gen_ret_code",v_gen_ret_code);
DEBUGLOG(("GetHeader gen_ret_code = [%d]\n",v_gen_ret_code));
        	}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getheader_error;
}



DEBUGLOG(("GetHeader Normal Exit\n"));
	return  PD_OK;

getheader_error:
DEBUGLOG(("getheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenHD_Get: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )121;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetNextSeq()
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO GetNextSeq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_next_seq;
                short		ind_next_seq = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL
		SELECT	ol_payout_api_pregen_seq.nextval
                INTO    :hv_next_seq:ind_next_seq
                FROM    dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ol_payout_api_pregen_seq . nextval INTO :b0:b\
1 FROM dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )136;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_next_seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_next_seq;
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
        if (sqlca.sqlcode < 0) goto GetNextSeq_error;
}



        if(ind_next_seq>=0){
DEBUGLOG(("GetNextSeq Found\n"));
                return hv_next_seq;
        }
        else {
DEBUGLOG(("GetNextSeq ERROR\n"));
        }

	return iRet;

GetNextSeq_error:
DEBUGLOG(("GetNextSeq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRec)
{
        char*   csBuf;
        char*   csTmp;
	char	cTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_payout_api_pregen_hd set oap_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if(GetField_CString(hRec,"payout_group",&csBuf)){
DEBUGLOG(("Update: payout_group = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oap_payout_group= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRec,"status",&cTmp)){
DEBUGLOG(("Update: status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oap_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRec,"pregen_ret_code",&iTmp)){
DEBUGLOG(("Update: pregen_ret_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oap_pregen_ret_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRec,"gen_ret_code",&iTmp)){
DEBUGLOG(("Update: gen_ret_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oap_gen_ret_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oap_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_CString(hRec,"action_id",&csTmp)) {
		strcat((char*)hv_dynstmt.arr, " WHERE oap_action_id= ");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
	} else {
		if (GetField_CString(hRec,"batch_id",&csTmp)) {
                	strcat((char*)hv_dynstmt.arr, " WHERE oap_batch_id= ");
                	strcat((char*)hv_dynstmt.arr, csTmp);
                	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
		} else {
                        FREE_ME(csBuf);
                        return INT_ERR;
DEBUGLOG(("Update: action_id and batch_id not found\n"));
                }
	}

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )155;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )174;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateStatus Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenHD_Update: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int MatchPregenStatus(const hash_t *hRec)
{
	int	iRet = PD_FOUND;

	char	*csTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO MatchPregenStatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long   hv_action_id;
                char 		hv_status;

		short 		ind_action_id = -1;
                short 		ind_status = -1;

		short   	hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


	// action_id
	if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id= (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("MatchPregenStatus action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("MatchPregenStatus action_id  not found\n"));
          	return INT_ERR;
        }

	// status
	if (GetField_Char(hRec,"status",&cTmp)) {
		hv_status = cTmp;
                ind_status= 0;
DEBUGLOG(("MatchPregenStatus status = [%.c]\n",hv_status));
	} else {
DEBUGLOG(("MatchPregenStatus status not found\n"));
        	return INT_ERR;		
	}

        /* EXEC SQL EXECUTE
       		BEGIN
        	    	:hv_return_value := sp_ol_po_api_match_pgen_status(:hv_action_id:ind_action_id,
        	                                                           :hv_status:ind_status);
       		END;
       	END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_match_pgen_st\
atus ( :hv_action_id:ind_action_id , :hv_status:ind_status ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )189;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_action_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_status;
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
        if (sqlca.sqlcode < 0) goto MatchPregenStatus_error;
}



	if (hv_return_value == 0) {
DEBUGLOG(("MatchPregenStatus: No Records Found!!\n"));
                iRet = PD_NOT_FOUND;
	} 
		
DEBUGLOG(("MatchPregenStatus: iRet = [%d]\n",iRet));
        return iRet;

MatchPregenStatus_error:
DEBUGLOG(("MatchPregenStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int MatchPregenStatus_ForUpdate(const hash_t *hRec)
{
        int     iRet = PD_FOUND;

	int	iCheckStatus = PD_TRUE;
	int	iCnt = 0;
        char    *csTmp;
        char    cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO MatchPregenStatus_ForUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_action_id;
		char            hv_status;
		int            	hv_check_status;

		short 		ind_action_id = -1;
		short 		ind_status = -1;
		short 		ind_check_status = -1;

                short   	hv_return_value;

                unsigned long   v_batch_id;

		short 		ind_batch_id = -1;
                
		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


        // action_id
        if (GetField_CString(hRec,"action_id",&csTmp)) {
                hv_action_id= (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("MatchPregenStatus_ForUpdate action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("MatchPregenStatus_ForUpdate action_id not found\n"));
           	return INT_ERR;
	}

	// check_status
        if (GetField_Int(hRec,"check_status",&iCheckStatus)) {
                hv_check_status = iCheckStatus;
                ind_check_status= 0;
DEBUGLOG(("MatchPregenStatus_ForUpdate check_status = [%d]\n",hv_check_status));
        } else {
		hv_check_status = iCheckStatus;
                ind_check_status= 0;
DEBUGLOG(("MatchPregenStatus_ForUpdate check_status = [%d]\n",hv_check_status));
	}

	// status
	if (iCheckStatus == PD_TRUE) {
        	if (GetField_Char(hRec,"status",&cTmp)) {
                	hv_status = cTmp;
                	ind_status= 0;
DEBUGLOG(("MatchPregenStatus_ForUpdate status = [%.c]\n",hv_status));
        	} else {
DEBUGLOG(("MatchPregenStatus_ForUpdate status not found\n"));
                	return INT_ERR;
        	}
	}

       	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )216;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto MatchPregenStatus_ForUpdate_error;
}


	
      	/* EXEC SQL EXECUTE
            	BEGIN
                   	:hv_return_value := sp_ol_po_api_sel_upd_pgen(:hv_action_id:ind_action_id,
									:hv_status:ind_status,
									:hv_check_status:ind_check_status,
                                                                        :c_cursor_id);
             	END;
      	END-EXEC; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 8;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_sel_upd_pgen (\
 :hv_action_id:ind_action_id , :hv_status:ind_status , :hv_check_status:ind_c\
heck_status , :c_cursor_id ) ; END ;";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )235;
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
       sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)&ind_action_id;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
       sqlstm.sqhstl[2] = (unsigned long )1;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)&ind_status;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&hv_check_status;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)&ind_check_status;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_id;
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
       if (sqlca.sqlcode < 0) goto MatchPregenStatus_ForUpdate_error;
}



DEBUGLOG(("MatchPregenStatus_ForUpdate: hv_return_value = [%d]\n",hv_return_value));
        if (hv_return_value > 0) {
                for (;;) {
                        ind_batch_id = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO
                                :v_batch_id:ind_batch_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 8;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )270;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto MatchPregenStatus_ForUpdate_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* batch_id */
                        if (ind_batch_id >= 0) {
DEBUGLOG(("MatchPregenStatus_ForUpdate: batch_id_%d = [%ld]\n",iCnt,v_batch_id));
                        } else {
                                iRet = PD_NOT_FOUND;
                                break;
                        }

                        iCnt++;
                }
	}

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )293;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto MatchPregenStatus_ForUpdate_error;
}


        /* EXEC SQL FREE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )312;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto MatchPregenStatus_ForUpdate_error;
}



        if (iCnt > 0) {
DEBUGLOG(("MatchPregenStatus_ForUpdate: [%d] Records Found\n", iCnt));
	} else {
DEBUGLOG(("MatchPregenStatus_ForUpdate: No Records Found!!\n"));
                iRet = PD_NOT_FOUND;
        }

DEBUGLOG(("MatchPregenStatus_ForUpdate: iRet = [%d]\n",iRet));
        return iRet;

MatchPregenStatus_ForUpdate_error:
DEBUGLOG(("MatchPregenStatus_ForUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )331;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


        /* EXEC SQL FREE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )350;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


/*
int Delete(const unsigned char* file_id)
{
        EXEC SQL WHENEVER SQLERROR GOTO delete_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                varchar hv_file_id[PD_TXN_SEQ_LEN];

                short   hv_return_value;
        EXEC SQL END DECLARE SECTION;

        hv_file_id.len = strlen((const char*)file_id);
        memcpy(hv_file_id.arr,file_id,hv_file_id.len);
DEBUGLOG(("Delete: file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

        EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_payout_gen_hd_delete(
                                :hv_file_id);

            END;
        END-EXEC;


DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLPayoutApiPregenHD_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiPregenHD_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenHD_Delete: SP_INTERNAL_ERR TxnAbort\n");
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;

}
*/
