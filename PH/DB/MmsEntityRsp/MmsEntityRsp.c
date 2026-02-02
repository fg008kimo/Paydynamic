
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "MmsEntityRsp.pc"
};


static unsigned int sqlctx = 2536651;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
5,0,0,1,280,0,6,123,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,
0,0,1,1,0,0,1,9,0,0,1,9,0,0,
56,0,0,2,0,0,17,265,0,0,1,1,0,1,0,1,9,0,0,
75,0,0,2,0,0,21,266,0,0,0,0,0,1,0,
90,0,0,3,74,0,4,303,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init version					   2015/06/17		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"
#include "MmsEntityRsp.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsEntityRsp(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char	*csTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO sync_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		/* varchar		hv_rsp_id[PD_MMS_RSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_rsp_id;

		/* varchar		hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		char		hv_status;
		/* varchar		hv_node_id[PD_MMS_NODE_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_node_id;

		char		hv_acct_type;
		/* varchar		hv_relate_grp[PD_MMS_RELATE_GRP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_relate_grp;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_entity_id = -1;
		short		ind_rsp_id = -1;
		short		ind_desc = -1;
		short		ind_status = -1;
		short		ind_node_id = -1;
		short		ind_acct_type = -1;
		short		ind_relate_grp = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


        if(GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                strncpy((char*)hv_entity_id.arr, csTmp, hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Add:entity_id = [%.*s]\n",hv_entity_id.len, hv_entity_id.arr));
        }

        if(GetField_CString(hRls,"rsp_id",&csTmp)) {
                hv_rsp_id.len = strlen(csTmp);
                strncpy((char*)hv_rsp_id.arr, csTmp, hv_rsp_id.len);
                ind_rsp_id = 0;
DEBUGLOG(("Add:rsp_id = [%.*s]\n",hv_rsp_id.len, hv_rsp_id.arr));
        }

        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));
        }

        if(GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
        }

        if(GetField_CString(hRls,"node_id",&csTmp)) {
                hv_node_id.len = strlen(csTmp);
                strncpy((char*)hv_node_id.arr, csTmp, hv_node_id.len);
                ind_node_id = 0;
DEBUGLOG(("Add:node_id = [%.*s]\n",hv_node_id.len, hv_node_id.arr));
        }

        if(GetField_Char(hRls,"acct_type",&cTmp)) {
                hv_acct_type = cTmp;
                ind_acct_type = 0;
DEBUGLOG(("Add:acct_type = [%c]\n",hv_acct_type));
        }

        if(GetField_CString(hRls,"relate_grp",&csTmp)) {
                hv_relate_grp.len = strlen(csTmp);
                strncpy((char*)hv_relate_grp.arr, csTmp, hv_relate_grp.len);
                ind_relate_grp = 0;
DEBUGLOG(("Add:relate_grp = [%.*s]\n",hv_relate_grp.len, hv_relate_grp.arr));
        }

        if(GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_entity_rsp_insert(
								:hv_entity_id:ind_entity_id,
								:hv_rsp_id:ind_rsp_id,
								:hv_desc:ind_desc,
								:hv_status:ind_status,
								:hv_node_id:ind_node_id,
								:hv_acct_type:ind_acct_type,
								:hv_relate_grp:ind_relate_grp,
								:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_entity_rsp_insert ( :hv_en\
tity_id:ind_entity_id , :hv_rsp_id:ind_rsp_id , :hv_desc:ind_desc , :hv_statu\
s:ind_status , :hv_node_id:ind_node_id , :hv_acct_type:ind_acct_type , :hv_re\
late_grp:ind_relate_grp , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_entity_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_rsp_id;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_rsp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_desc;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_node_id;
 sqlstm.sqhstl[5] = (unsigned long )7;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_node_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_acct_type;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_relate_grp;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_relate_grp;
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
 if (sqlca.sqlcode < 0) goto sync_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsEntityRsp_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsEntityRsp_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


sync_error:
DEBUGLOG(("sync_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntity_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRls)
{
	char	*csBuf;
	char	*csTmp;
	char	cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


		/* varchar hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;


		short ind_entity_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	csBuf = (char *)malloc(PD_TMP_BUF_LEN + 1);

        strcpy((char*)hv_dynstmt.arr,"update mms_entity_rsp set mer_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*desc*/
        if (GetField_CString(hRls,"desc",&csTmp)) {
DEBUGLOG(("Update:update_desc = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mer_desc = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*status*/
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:update_status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mer_status_ref = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*node_id*/
        if (GetField_CString(hRls,"node_id",&csTmp)) {
DEBUGLOG(("Update:update_node_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mer_node_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*acct_type*/
        if (GetField_Char(hRls,"acct_type",&cTmp)) {
DEBUGLOG(("Update:update_acct_type = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mer_acct_type = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*relate_grp*/
        if (GetField_CString(hRls,"relate_grp",&csTmp)) {
DEBUGLOG(("Update:update_relate_grp = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mer_relate_grp = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
        if (GetField_CString(hRls,"create_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mer_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Key: eid*/
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
DEBUGLOG(("Update: entity_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE mer_entity_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		hv_entity_id.len = strlen(csTmp);
		strncpy((char*)hv_entity_id.arr, csTmp, hv_entity_id.len);
		ind_entity_id = 0;
	} else {

	}

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )56;
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )75;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsEntityRsp:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int FindRecordExists(hash_t* hRec)
{
	int iRet = PD_NOT_FOUND;
DEBUGLOG(("FindRecordExists()\n"));

	char* csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_rsp_id[PD_MMS_RSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_rsp_id;


		int	v_cnt;
		short	ind_cnt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec,"rsp_id",&csTmp)) {
		hv_rsp_id.len = strlen(csTmp);
		memcpy(hv_rsp_id.arr,csTmp,hv_rsp_id.len);
DEBUGLOG(("FindRecordExists rsp_id = [%.*s]\n",hv_rsp_id.len,hv_rsp_id.arr));
	}

	/* EXEC SQL	SELECT	count(*)
			  INTO	:v_cnt:ind_cnt
		  	  FROM	mms_entity_rsp
		 	 WHERE	mer_rsp_id = :hv_rsp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0:b1 FROM mms_entity_rsp WHERE me\
r_rsp_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cnt;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_rsp_id;
 sqlstm.sqhstl[1] = (unsigned long )23;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



	if (ind_cnt>=0) {
		if (v_cnt > 0) {
DEBUGLOG(("FindRecordExists record found!\n"));
			iRet = PD_FOUND;
		} else {
DEBUGLOG(("FindRecordExists no record found!\n"));
		}
	}

	return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
