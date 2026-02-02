
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "ClientMagic.pc"
};


static unsigned int sqlctx = 1160163;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,262,0,6,126,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,
0,0,1,3,0,0,1,9,0,0,
52,0,0,2,142,0,6,215,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
83,0,0,3,130,0,4,292,0,0,5,4,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
118,0,0,4,90,0,4,352,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,
145,0,0,5,239,0,6,507,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,
188,0,0,6,0,0,17,528,0,0,1,1,0,1,0,1,9,0,0,
207,0,0,6,0,0,21,529,0,0,0,0,0,1,0,
222,0,0,7,383,0,4,604,0,0,8,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,
269,0,0,8,155,0,4,683,0,0,6,3,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/20              LokMan Chow
Add log                                            2013/08/23              Stan Poon
Add GetTotalMatchRec                               2013/09/23              Virginia Yun
Exclude update Magic Num                           2013/09/24              Stan Poon
Cater Txn Group ID                                 2013/10/16              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "ClientMagic.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void ClientMagic(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hClientMagic)
{
	char    *csTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_client[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_magic_num[PD_MAGIC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_magic_num;

		/* varchar 	hv_magic_word[PD_MAGIC_WORD_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_magic_word;

		/* varchar		hv_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cust_id;

		int		hv_txn_gp_id;
		int		hv_disabled;

		short		ind_client = -1;
		short		ind_cust_id = -1;
		short		ind_magic_num= -1;
		short		ind_magic_word = -1;
		short		ind_create_user = -1;
		short		ind_txn_gp_id = -1;
		short		ind_disabled = -1;
		
		short	   hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hClientMagic,"client_id",&csTmp))
	{
		hv_client.len = strlen(csTmp);
		strncpy((char*)hv_client.arr,csTmp, hv_client.len);
		ind_client = 0;
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client.len,hv_client.arr));
	}

	if(GetField_CString(hClientMagic,"customer_id",&csTmp))
	{
		hv_cust_id.len = strlen(csTmp);
		strncpy((char*)hv_cust_id.arr, csTmp, hv_cust_id.len);
		ind_cust_id = 0;
DEBUGLOG(("Add:customer_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}

	if(GetField_CString(hClientMagic,"magic_num",&csTmp))
	{
		hv_magic_num.len = strlen(csTmp);
		strncpy((char*)hv_magic_num.arr, csTmp, hv_magic_num.len);
		ind_magic_num = 0;
DEBUGLOG(("Add:magic_num = [%.*s]\n",hv_magic_num.len,hv_magic_num.arr));
	}

	if(GetField_CString(hClientMagic,"magic_word",&csTmp))
	{
		hv_magic_word.len = strlen(csTmp);
		strncpy((char*)hv_magic_word.arr, csTmp, hv_magic_word.len);
		ind_magic_word = 0;
DEBUGLOG(("Add:magic_word = [%.*s]\n",hv_magic_word.len,hv_magic_word.arr));
	}

	if (GetField_Int(hClientMagic,"txn_gp_id",&iTmp)) 
	{
		hv_txn_gp_id = iTmp;
		ind_txn_gp_id = 0;
DEBUGLOG(("Add:txn_gp_id = [%d]\n",hv_txn_gp_id));
	} 

	if (GetField_Int(hClientMagic,"disabled",&iTmp)) 
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	} else {
		hv_disabled = 0;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled(default) = [%d]\n",hv_disabled));
	}


	if(GetField_CString(hClientMagic,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_client_magic_insert(
				:hv_client:ind_client,
				:hv_cust_id:ind_cust_id,
				:hv_magic_num:ind_magic_num,
				:hv_magic_word:ind_magic_word,
				:hv_txn_gp_id:ind_txn_gp_id,
				:hv_disabled:ind_disabled,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_client_magic_insert ( :hv_clie\
nt:ind_client , :hv_cust_id:ind_cust_id , :hv_magic_num:ind_magic_num , :hv_m\
agic_word:ind_magic_word , :hv_txn_gp_id:ind_txn_gp_id , :hv_disabled:ind_dis\
abled , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_client;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_cust_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_magic_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_magic_word;
 sqlstm.sqhstl[4] = (unsigned long )152;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_magic_word;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_gp_id;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_gp_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_disabled;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("ClientMagic_Add: SP_OTHER_ERR \n");
DEBUGLOG(("Add: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("ClientMagic_Add: SP_ERR \n");
DEBUGLOG(("Add: SP_ERR \n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}



int Delete(const hash_t *hClientMagic)
{
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_client[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client;

		/* varchar	hv_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cust_id;

		/* varchar	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short	ind_client = -1;
		short	ind_cust_id = -1;
		short	ind_update_user = -1;
		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hClientMagic,"client_id",&csTmp))
	{
		hv_client.len = strlen(csTmp);
		strncpy((char*)hv_client.arr,csTmp, hv_client.len);
		ind_client = 0;
DEBUGLOG(("Delete:client_id = [%.*s]\n",hv_client.len,hv_client.arr));
	}

	if(GetField_CString(hClientMagic,"customer_id",&csTmp))
	{
		hv_cust_id.len = strlen(csTmp);
		strncpy((char*)hv_cust_id.arr, csTmp, hv_cust_id.len);
		ind_cust_id = 0;
DEBUGLOG(("Delete:customer_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}

	if(GetField_CString(hClientMagic,"update_user",&csTmp))
	{
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("Add:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
	    BEGIN
		
		:hv_return_value := sp_client_magic_delete(
				:hv_client:ind_client,
				:hv_cust_id:ind_cust_id,
				:hv_update_user:ind_update_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_client_magic_delete ( :hv_clie\
nt:ind_client , :hv_cust_id:ind_cust_id , :hv_update_user:ind_update_user ) ;\
 END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )52;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_client;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_cust_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Delete:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("ClientMagic_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("ClientMagic_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
	DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int GetCustomerIdByMagic(const char* csClientId, 
			 const char* csMagicNumber,
			 const char* csMagicWord,
			 unsigned char* csCustomerId)
{
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getcust_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

		       
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar 	hv_magic_num[PD_MAGIC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_magic_num;

		/* varchar 	hv_magic_word[PD_MAGIC_WORD_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_magic_word;

		int		hv_disabled;
	
		/* varchar		v_cust_id[PD_MAGIC_CUST_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cust_id;


		short		ind_cust_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_disabled = 0;

	hv_client_id.len = strlen(csClientId);
	memcpy(hv_client_id.arr,csClientId,hv_client_id.len);
DEBUGLOG(("GetCustomerIdByMagic client_id = [%d][%.*s]\n",hv_client_id.len,hv_client_id.len,hv_client_id.arr));

	hv_magic_num.len = strlen(csMagicNumber);
	memcpy(hv_magic_num.arr,csMagicNumber,hv_magic_num.len);
DEBUGLOG(("GetCustomerIdByMagic magic_num = [%d][%.*s]\n",hv_magic_num.len,hv_magic_num.len,hv_magic_num.arr));

	hv_magic_word.len = strlen(csMagicWord);
	memcpy(hv_magic_word.arr,csMagicWord,hv_magic_word.len);
DEBUGLOG(("GetCustomerIdByMagic magic_word = [%d][%.*s]\n",hv_magic_word.len,hv_magic_word.len,hv_magic_word.arr));

	
	/* EXEC SQL 
		select  CM_CUST_ID
		INTO    :v_cust_id:ind_cust_id
		from	client_magic
		where	cm_client_id = :hv_client_id
		and	cm_num = :hv_magic_num
		and	cm_word = :hv_magic_word
		and 	cm_disabled = :hv_disabled; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CM_CUST_ID INTO :b0:b1 from client_magic where cm_cl\
ient_id = :b2 and cm_num = :b3 and cm_word = :b4 and cm_disabled = :b5 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )83;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cust_id;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cust_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_magic_word;
 sqlstm.sqhstl[3] = (unsigned long )152;
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
 if (sqlca.sqlcode < 0) goto getcust_error;
}



/* customer id */
		if (ind_cust_id >= 0) {
			v_cust_id.arr[v_cust_id.len] = '\0';
			strcpy((char*)csCustomerId,(const char*)v_cust_id.arr);
DEBUGLOG(("GetCustomerIdByMagic customer id = [%s]\n",csCustomerId));
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("GetCustomerIdByMagic customer id Not Found\n"));
		}

DEBUGLOG(("GetCustomerIdByMagic Normal Exit\n"));
	return  iRet;

getcust_error:
DEBUGLOG(("getcust_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ClientMagic_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int GetMagicNumById(const char* csClientId, 
			 const char* csCustomerId,
			 char* csMagicNum)
{
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getcust_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

		       
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cust_id;

	
		/* varchar 	v_magic_num[PD_MAGIC_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_magic_num;


		short		ind_magic_num= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_client_id.len = strlen(csClientId);
	memcpy(hv_client_id.arr,csClientId,hv_client_id.len);
DEBUGLOG(("GetMagicNumById client_id = [%d][%.*s]\n",hv_client_id.len,hv_client_id.len,hv_client_id.arr));

	hv_cust_id.len = strlen(csCustomerId);
	memcpy(hv_cust_id.arr,csCustomerId,hv_cust_id.len);
DEBUGLOG(("GetMagicNumById cust_id = [%d][%.*s]\n",hv_cust_id.len,hv_cust_id.len,hv_cust_id.arr));
	
	/* EXEC SQL 
		select  CM_NUM
		INTO    :v_magic_num:ind_magic_num
		from	client_magic
		where	cm_client_id = :hv_client_id
		and 	cm_cust_id= :hv_cust_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CM_NUM INTO :b0:b1 from client_magic where cm_client\
_id = :b2 and cm_cust_id = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )118;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_magic_num;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_magic_num;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto getcust_error;
}



/* magic num */
	if (ind_magic_num >= 0) {
		v_magic_num.arr[v_magic_num.len] = '\0';
		strcpy((char*)csMagicNum,(const char*)v_magic_num.arr);
DEBUGLOG(("GetMagicNumById magic num = [%s]\n",csMagicNum));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetMagicNumById magic num Not Found\n"));
	}

DEBUGLOG(("GetMagicNumById Normal Exit\n"));
	return  iRet;

getcust_error:
DEBUGLOG(("getcust_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ClientMagic_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int Update(const hash_t *hRls)
{
	char*   csTmp;
	char*   csClientId;
	char*   csCustId;
	int	iTmp;
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_client[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client;

		/* varchar		hv_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cust_id;

		/* varchar 	hv_magic_num[PD_MAGIC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_magic_num;

		/* varchar 	hv_magic_word[PD_MAGIC_WORD_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_magic_word;

		int		hv_disabled;
		int		hv_txn_gp_id;
		/* varchar 	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short		ind_client = -1;
		short		ind_cust_id = -1;
		short		ind_magic_num= -1;
		short		ind_magic_word = -1;
		short		ind_disabled = -1;
		short		ind_txn_gp_id = -1;
		short		ind_update_user = -1;

		short		hv_return_value = -1;

		/* varchar	 hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update client_magic set cm_update_timestamp  = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"client_id",&csClientId);
DEBUGLOG(("Update:client_id = [%s]\n",csClientId));
	hv_client.len = strlen(csClientId);
	strncpy((char*)hv_client.arr,csClientId, hv_client.len);
	ind_client = 0;

	GetField_CString(hRls,"customer_id",&csCustId);
DEBUGLOG(("Update:customer_id = [%s]\n",csCustId));
	hv_cust_id.len = strlen(csCustId);
	strncpy((char*)hv_cust_id.arr,csCustId, hv_cust_id.len);
	ind_cust_id = 0;


/*magic_num 
	if (GetField_CString(hRls,"magic_num",&csTmp)) {
DEBUGLOG(("Update:magic_num = [%s]\n",csTmp));
		hv_magic_num.len = strlen(csTmp);
		strncpy((char*)hv_magic_num.arr,csTmp, hv_magic_num.len);
		ind_magic_num = 0;

		strcat((char*)hv_dynstmt.arr, ",cm_num = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
*/

/* magic_word*/
	if (GetField_CString(hRls,"magic_word",&csTmp)) {
DEBUGLOG(("Update:magic_word = [%s]\n",csTmp));
		hv_magic_word.len = strlen(csTmp);
		strncpy((char*)hv_magic_word.arr,csTmp, hv_magic_word.len);
		ind_magic_word = 0;

		strcat((char*)hv_dynstmt.arr, ",cm_word = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_gp_id */
	if (GetField_Int(hRls,"txn_gp_id",&iTmp)) {
DEBUGLOG(("Update:txn_gp_id = [%d]\n",iTmp));
		hv_txn_gp_id = iTmp;
		ind_txn_gp_id = 0;

		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ", cm_txn_gp_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* disabled */
	if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		hv_disabled = iTmp;
		ind_disabled = 0;

		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ", cm_disabled = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
	if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr,csTmp, hv_update_user.len);
		ind_update_user = 0;

		strcat((char*)hv_dynstmt.arr, ",cm_update_user= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE cm_client_id = '");
	strcat((char *)hv_dynstmt.arr, csClientId);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " and cm_cust_id = '");
	strcat((char *)hv_dynstmt.arr, csCustId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_client_magic_update_on_log(
				:hv_client:ind_client,
				:hv_cust_id:ind_cust_id,
				:hv_magic_num:ind_magic_num,
				:hv_magic_word:ind_magic_word,
				:hv_disabled:ind_disabled,
				:hv_update_user:ind_update_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_client_magic_update_on_log ( :\
hv_client:ind_client , :hv_cust_id:ind_cust_id , :hv_magic_num:ind_magic_num \
, :hv_magic_word:ind_magic_word , :hv_disabled:ind_disabled , :hv_update_user\
:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )145;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_client;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_cust_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_magic_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_magic_word;
 sqlstm.sqhstl[4] = (unsigned long )152;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_magic_word;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto update_error;
}




DEBUGLOG(("Update: add_log::Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Update: add_log::Normal Exit\n"));
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )188;
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
 sqlstm.offset = (unsigned int  )207;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}


	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("ClientMagic_Update: add_log:: SP_OTHER_ERR \n");
DEBUGLOG(("Update: add_log:: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("ClientMagic_Update: add_log:: SP_ERR \n");
DEBUGLOG(("Update: add_log:: SP_ERR \n"));
		return PD_ERR;
	}

	FREE_ME(csBuf);
DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("ClientMagic_Update: SP_INTERNAL_ERR\n");
	return PD_INTERNAL_ERR;
}

int	GetTotalMatchRec(const hash_t *hClientMagic, int *iTotalCount)
{
	int	iRet = PD_OK;

	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettotalmatchrec_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_client[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client;

		/* varchar		hv_magic_num[PD_MAGIC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_magic_num;

		/* varchar		hv_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cust_id;


		short		ind_client = -1;
		short		ind_magic_num = -1;
		short		ind_cust_id = -1;

		int	     v_no_of_record;
		short	   ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hClientMagic,"client_id",&csTmp))
	{
		hv_client.len = strlen(csTmp);
		strncpy((char*)hv_client.arr,csTmp, hv_client.len);
		ind_client = 0;
DEBUGLOG(("GetTotalMatchRec:client_id = [%.*s]\n",hv_client.len,hv_client.arr));
	}

	if(GetField_CString(hClientMagic,"customer_id",&csTmp))
	{
		hv_cust_id.len = strlen(csTmp);
		strncpy((char*)hv_cust_id.arr, csTmp, hv_cust_id.len);
		ind_cust_id = 0;
DEBUGLOG(("GetTotalMatchRec:customer_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}

	if(GetField_CString(hClientMagic,"magic_num",&csTmp))
	{
		hv_magic_num.len = strlen(csTmp);
		strncpy((char*)hv_magic_num.arr, csTmp, hv_magic_num.len);
		ind_magic_num = 0;
DEBUGLOG(("GetTotalMatchRec:magic_num = [%.*s]\n",hv_magic_num.len,hv_magic_num.arr));
	}


	/* EXEC SQL
		SELECT sum(rec_cnt)
		INTO :v_no_of_record:ind_no_of_record
		FROM (
			SELECT count(1) as rec_cnt
			FROM client_magic 
			WHERE cm_client_id = :hv_client:ind_client
			AND cm_num = :hv_magic_num:ind_magic_num
			UNION ALL
			SELECT count(1) as rec_cnt
			FROM client_magic 
			WHERE cm_client_id = :hv_client:ind_client
			AND cm_cust_id = :hv_cust_id:ind_cust_id
			UNION ALL
			SELECT count(1) as rec_cnt
			FROM client_magic 
			WHERE cm_client_id = :hv_client:ind_client
			AND cm_num = :hv_magic_num:ind_magic_num
			AND cm_cust_id = :hv_cust_id:ind_cust_id
		); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sum ( rec_cnt ) INTO :b0:b1 FROM ( SELECT count ( 1 \
) as rec_cnt FROM client_magic WHERE cm_client_id = :b2:b3 AND cm_num = :b4:b\
5 UNION ALL SELECT count ( 1 ) as rec_cnt FROM client_magic WHERE cm_client_i\
d = :b2:b7 AND cm_cust_id = :b8:b9 UNION ALL SELECT count ( 1 ) as rec_cnt FR\
OM client_magic WHERE cm_client_id = :b2:b11 AND cm_num = :b4:b13 AND cm_cust\
_id = :b8:b15 ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )222;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_client;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_magic_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_client;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_cust_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_client;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_client;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_magic_num;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_cust_id;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_cust_id;
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
 if (sqlca.sqlcode < 0) goto gettotalmatchrec_error;
}



	if (ind_no_of_record >= 0) {
DEBUGLOG(("GetTotalMatchRec: FOUND\n"));
		*iTotalCount = v_no_of_record;
DEBUGLOG(("GetTotalMatchRec: Total Record [%d]\n", *iTotalCount));
	} else {
DEBUGLOG(("GetTotalMatchRec ERR\n"));
		iRet = PD_ERR;
	}
		
	return iRet;

gettotalmatchrec_error:
DEBUGLOG(("GetTotalMatchRec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
	
}

int GetClientMagic(const char* csClientId, 
			const char* csMagicNumber,
			const char* csMagicWord,
			hash_t *hClientMagic)
{
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getclientmagic_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

		       
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar 	hv_magic_num[PD_MAGIC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_magic_num;

		/* varchar 	hv_magic_word[PD_MAGIC_WORD_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_magic_word;

	
		/* varchar		v_cust_id[PD_MAGIC_CUST_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cust_id;

		int		v_txn_gp_id;
		int		v_disabled;

		short		ind_cust_id = -1;
		short		ind_txn_gp_id = -1;
		short		ind_disabled = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_client_id.len = strlen(csClientId);
	memcpy(hv_client_id.arr,csClientId,hv_client_id.len);
DEBUGLOG(("GetClientMagic client_id = [%d][%.*s]\n",hv_client_id.len,hv_client_id.len,hv_client_id.arr));

	hv_magic_num.len = strlen(csMagicNumber);
	memcpy(hv_magic_num.arr,csMagicNumber,hv_magic_num.len);
DEBUGLOG(("GetClientMagic magic_num = [%d][%.*s]\n",hv_magic_num.len,hv_magic_num.len,hv_magic_num.arr));

	hv_magic_word.len = strlen(csMagicWord);
	memcpy(hv_magic_word.arr,csMagicWord,hv_magic_word.len);
DEBUGLOG(("GetClientMagic magic_word = [%d][%.*s]\n",hv_magic_word.len,hv_magic_word.len,hv_magic_word.arr));

	
	/* EXEC SQL 
		select  CM_CUST_ID, CM_DISABLED, CM_TXN_GP_ID
		INTO    :v_cust_id:ind_cust_id,
                        :v_disabled:ind_disabled,
                        :v_txn_gp_id:ind_txn_gp_id
		from	client_magic
		where	cm_client_id = :hv_client_id
		and	cm_num = :hv_magic_num
		and	cm_word = :hv_magic_word; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CM_CUST_ID , CM_DISABLED , CM_TXN_GP_ID INTO :b0:b1 \
, :b2:b3 , :b4:b5 from client_magic where cm_client_id = :b6 and cm_num = :b7\
 and cm_word = :b8 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )269;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cust_id;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cust_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_disabled;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_gp_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_gp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_magic_num;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_magic_word;
 sqlstm.sqhstl[5] = (unsigned long )152;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getclientmagic_error;
}



/* customer id */
		if (ind_cust_id >= 0) {
			v_cust_id.arr[v_cust_id.len] = '\0';
 			PutField_CString(hClientMagic, "customer_id",(const char*)v_cust_id.arr);
DEBUGLOG(("GetClientMagic customer id = [%s]\n", v_cust_id.arr));
		}
		else{
			iRet = PD_ERR;
DEBUGLOG(("GetClientMagic customer id Not Found\n"));
		}

/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(hClientMagic, "magic_disabled", v_disabled);
DEBUGLOG(("GetClientMagic disabled = [%d]\n", v_disabled)); 
		}

/* txn_gp_id */
		if (ind_txn_gp_id >= 0) {
			PutField_Int(hClientMagic, "txn_gp_id", v_txn_gp_id);
DEBUGLOG(("GetClientMagic txn_gp_id = [%d]\n", v_txn_gp_id)); 
		}


DEBUGLOG(("GetClientMagic Normal Exit\n"));
	return  iRet;

getclientmagic_error:
DEBUGLOG(("getclientmagic_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ClientMagic_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}
