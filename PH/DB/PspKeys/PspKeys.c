
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "PspKeys.pc"
};


static unsigned int sqlctx = 81955;


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

 static char *sq0004 = 
"select key_value , key_id , key_uid , privatepem , publiccert , passphrase \
from psp_keys where psp_id = :b0 and key = :b1 AND effect_date = ( SELECT max\
 ( effect_date ) FROM psp_keys WHERE psp_id = :b0 AND key = :b1 AND effect_da\
te <= sysdate )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,197,0,6,102,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,365,0,6,283,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
99,0,0,3,77,0,6,354,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
126,0,0,4,256,0,9,451,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
157,0,0,4,0,0,13,453,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
196,0,0,4,0,0,15,515,0,0,0,0,0,1,0,
211,0,0,4,0,0,15,527,0,0,0,0,0,1,0,
226,0,0,5,0,0,17,611,0,0,1,1,0,1,0,1,9,0,0,
245,0,0,5,0,0,21,612,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/01/07              [MSN]
Add key_id                                         2011/05/27              [GOD]
Add UID,PrivatePem,PublicCert and PassPhrse        2011/11/11              [GOD]
PRD332
 - Add UpdatePspKey                                2021/07/29              [ZBL]
 - Add Replicate                                                           [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PspKeys.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void PspKeys(char    cdebug)
{
        cDebug = cdebug;
}




int Replicate(const hash_t *hRec)
{
	char            *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO replicate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar         hv_replicate_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_replicate_psp_id;

		/* varchar         hv_create_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_create_psp_id;

		/* varchar		    hv_key_value[PD_MD5_KEY_LEN]; */ 
struct { unsigned short len; unsigned char arr[500]; } hv_key_value;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_replicate_psp_id = -1;
		short		ind_create_psp_id = -1;
		short		ind_key_value = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Replicate: Begin\n"));


	if(GetField_CString(hRec,"replicate_psp_id",&csTmp))
	{
		hv_replicate_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_replicate_psp_id.arr, csTmp, hv_replicate_psp_id.len);
		ind_replicate_psp_id = 0;
	}
DEBUGLOG(("Replicate:replicate_psp_id = [%.*s]\n",hv_replicate_psp_id.len,hv_replicate_psp_id.arr));

	if(GetField_CString(hRec,"create_psp_id",&csTmp))
	{
		hv_create_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_create_psp_id.arr, csTmp, hv_create_psp_id.len);
		ind_create_psp_id = 0;
	}
DEBUGLOG(("Replicate:create_psp_id = [%.*s]\n",hv_create_psp_id.len,hv_create_psp_id.arr));


	if(GetField_CString(hRec,"key_value",&csTmp))
	{
		hv_key_value.len = strlen(csTmp);
		strncpy((char*)hv_key_value.arr, csTmp, hv_key_value.len);
		ind_key_value = 0;
	}
DEBUGLOG(("Replicate:key_value = [%.*s]\n",hv_key_value.len,hv_key_value.arr));

	if(GetField_CString(hRec,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Replicate:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));



	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_psp_keys_rpl(
				:hv_replicate_psp_id:ind_replicate_psp_id,
				:hv_create_psp_id:ind_create_psp_id,
				:hv_key_value:ind_key_value,
				:hv_create_user:ind_create_user
				);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_keys_rpl ( :hv_replicate_p\
sp_id:ind_replicate_psp_id , :hv_create_psp_id:ind_create_psp_id , :hv_key_va\
lue:ind_key_value , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_replicate_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_replicate_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_create_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_create_psp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_key_value;
 sqlstm.sqhstl[3] = (unsigned long )502;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_key_value;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto replicate_error;
}




	DEBUGLOG(("Replicate:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Replicate:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspKeys_Replicate: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspKeys_Replicate: SP_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

	if (hv_return_value == SP_NOT_FOUND)  {
		ERRLOG("PspKeys_Replicate: SP_NOT_FOUND TxnAbort\n");
		DEBUGLOG(("Replicate: SP_NOT_FOUND TxnAbort\n"));
		return PD_NOT_FOUND;
	}

replicate_error:
DEBUGLOG(("replicate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspKeys_Replicate: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}










int Add(const hash_t *hPspKeys)
{
	char            *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_key_value[PD_MD5_KEY_LEN]; */ 
struct { unsigned short len; unsigned char arr[500]; } hv_key_value;

		/* varchar		hv_key[PD_MD5_KEY_LEN]; */ 
struct { unsigned short len; unsigned char arr[500]; } hv_key;

		/* varchar		hv_key_id[PD_KEY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[32]; } hv_key_id;

		/* varchar		hv_key_uid[PD_KEY_UID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_key_uid;

		/* varchar		hv_privatepem[PD_PRIVATEPEM_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_privatepem;

		/* varchar		hv_publiccert[PD_PUBLICCERT_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_publiccert;

		/* varchar		hv_passphrase[PD_PASSPHRASE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_passphrase;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_effect_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effect_date;



		short		ind_psp_id = -1;
		short		ind_key_value = -1;
		short		ind_key = -1;
		short		ind_key_id = -1;
		short		ind_key_uid = -1;
		short		ind_privatepem = -1;
		short		ind_publiccert = -1;
		short		ind_passphrase = -1;
		short		ind_create_user = -1;
		short		ind_effect_date = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));


	if(GetField_CString(hPspKeys,"psp_id",&csTmp))
	{
		hv_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
	}
DEBUGLOG(("Add:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));


	if(GetField_CString(hPspKeys,"key_value",&csTmp))
	{
		hv_key_value.len = strlen(csTmp);
		strncpy((char*)hv_key_value.arr, csTmp, hv_key_value.len);
		ind_key_value = 0;
	}
DEBUGLOG(("Add:key_value = [%.*s]\n",hv_key_value.len,hv_key_value.arr));

	if(GetField_CString(hPspKeys,"key",&csTmp))
	{
		hv_key.len = strlen(csTmp);
		strncpy((char*)hv_key.arr, csTmp, hv_key.len);
		ind_key = 0;
	}
DEBUGLOG(("Add:key = [%.*s]\n",hv_key.len,hv_key.arr));

	if(GetField_CString(hPspKeys,"key_id",&csTmp))
	{
		hv_key_id.len = strlen(csTmp);
		strncpy((char*)hv_key_id.arr, csTmp, hv_key_id.len);
		ind_key_id = 0;
	}
DEBUGLOG(("Add:key_id = [%.*s]\n",hv_key_id.len,hv_key_id.arr));

	if(GetField_CString(hPspKeys,"key_uid",&csTmp))
	{
		hv_key_uid.len = strlen(csTmp);
		strncpy((char*)hv_key_uid.arr, csTmp, hv_key_uid.len);
		ind_key_uid = 0;
	}
DEBUGLOG(("Add:key_uid = [%.*s]\n",hv_key_uid.len,hv_key_uid.arr));

	if(GetField_CString(hPspKeys,"privatepem",&csTmp))
	{
		hv_privatepem.len = strlen(csTmp);
		strncpy((char*)hv_privatepem.arr, csTmp, hv_privatepem.len);
		ind_privatepem = 0;
	}
DEBUGLOG(("Add:privatepem = [%.*s]\n",hv_privatepem.len,hv_privatepem.arr));

	if(GetField_CString(hPspKeys,"publiccert",&csTmp))
	{
		hv_publiccert.len = strlen(csTmp);
		strncpy((char*)hv_publiccert.arr, csTmp, hv_publiccert.len);
		ind_publiccert = 0;
	}
DEBUGLOG(("Add:publiccert = [%.*s]\n",hv_publiccert.len,hv_publiccert.arr));

	if(GetField_CString(hPspKeys,"passphrase",&csTmp))
	{
		hv_passphrase.len = strlen(csTmp);
		strncpy((char*)hv_passphrase.arr, csTmp, hv_passphrase.len);
		ind_passphrase = 0;
	}
DEBUGLOG(("Add:passphrase = [%.*s]\n",hv_passphrase.len,hv_passphrase.arr));

	if(GetField_CString(hPspKeys,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	if(GetField_CString(hPspKeys,"effect_date",&csTmp))
	{
		hv_effect_date.len = strlen(csTmp);
		strncpy((char*)hv_effect_date.arr, csTmp, hv_effect_date.len);
		ind_effect_date= 0;
	}
DEBUGLOG(("Add:effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));


	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_psp_keys_insert(
				:hv_psp_id:ind_psp_id,
				:hv_key:ind_key,
				:hv_key_value:ind_key_value,
				:hv_key_id:ind_key_id,
				:hv_key_uid:ind_key_uid,
				:hv_privatepem:ind_privatepem,
				:hv_publiccert:ind_publiccert,
				:hv_passphrase:ind_passphrase,
				:hv_create_user:ind_create_user,
				to_date(:hv_effect_date:ind_effect_date,'yyyymmdd'));

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_keys_insert ( :hv_psp_id:i\
nd_psp_id , :hv_key:ind_key , :hv_key_value:ind_key_value , :hv_key_id:ind_ke\
y_id , :hv_key_uid:ind_key_uid , :hv_privatepem:ind_privatepem , :hv_publicce\
rt:ind_publiccert , :hv_passphrase:ind_passphrase , :hv_create_user:ind_creat\
e_user , to_date ( :hv_effect_date:ind_effect_date , 'yyyymmdd' ) ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_key;
 sqlstm.sqhstl[2] = (unsigned long )502;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_key;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_key_value;
 sqlstm.sqhstl[3] = (unsigned long )502;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_key_value;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_key_id;
 sqlstm.sqhstl[4] = (unsigned long )34;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_key_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_key_uid;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_key_uid;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_privatepem;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_privatepem;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_publiccert;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_publiccert;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_passphrase;
 sqlstm.sqhstl[8] = (unsigned long )102;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_passphrase;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_create_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[10] = (unsigned long )10;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_effect_date;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspKeys_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspKeys_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}




int Delete(const char* psp_id, const char* key)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	        /* varchar	hv_key[PD_KEY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_key;

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	hv_key.len = strlen((const char*)key);
	memcpy(hv_key.arr,key,hv_key.len);
DEBUGLOG(("Delete: key = [%.*s]\n",hv_key.len,hv_key.arr));

	hv_psp_id.len = strlen((const char*)psp_id);
	memcpy(hv_psp_id.arr,psp_id,hv_psp_id.len);
DEBUGLOG(("Delete: psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	/* EXEC SQL EXECUTE
	    BEGIN
		
		:hv_return_value := sp_psp_keys_delete(
				:hv_psp_id,
				:hv_key);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_keys_delete ( :hv_psp_id ,\
 :hv_key ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_key;
 sqlstm.sqhstl[2] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




	DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Delete:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspKeys_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspKeys_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
	DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int GetPspKey(const char* csPspId,const char* csKey,
                recordset_t* myRec)
{
	int iRet = 0;
                
        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getpspkey_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_key[PD_KEY_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_key;

                
		/* varchar		v_key_value[PD_MD5_KEY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_key_value;

		/* varchar		v_key_id[PD_KEY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[33]; } v_key_id;

		/* varchar		v_key_uid[PD_KEY_UID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_key_uid;

		/* varchar		v_privatepem[PD_PRIVATEPEM_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_privatepem;

		/* varchar		v_publiccert[PD_PUBLICCERT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_publiccert;

		/* varchar		v_passphrase[PD_PASSPHRASE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_passphrase;


		short		ind_key_value = -1;
		short		ind_key_id = -1;
		short		ind_key_uid = -1;
		short		ind_privatepem = -1;
		short		ind_publiccert = -1;
		short		ind_passphrase = -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetPspKey psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        
        hv_key.len = strlen(csKey);
        memcpy(hv_key.arr,csKey,hv_key.len);
DEBUGLOG(("GetPspKey key = [%.*s]\n",hv_key.len,hv_key.arr));
        
        /* EXEC SQL DECLARE c_cursor_getpspkey CURSOR FOR
                select 
		       	key_value,
		       	key_id,
		        key_uid,
		       	privatepem,
			publiccert,
			passphrase
                  from psp_keys
		 where psp_id = :hv_psp_id
		 and   key = :hv_key
		 AND   effect_date  =
                        (SELECT max(effect_date)
                           FROM psp_keys
                          WHERE psp_id = :hv_psp_id
                            AND key = :hv_key
                            AND effect_date <= sysdate); */ 




        /* EXEC SQL OPEN c_cursor_getpspkey; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )126;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_key;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_key;
        sqlstm.sqhstl[3] = (unsigned long )6;
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
        if (sqlca.sqlcode < 0) goto getpspkey_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpspkey
                INTO
			:v_key_value:ind_key_value,
			:v_key_id:ind_key_id,
			:v_key_uid:ind_key_uid,
			:v_privatepem:ind_privatepem,
			:v_publiccert:ind_publiccert,
			:v_passphrase:ind_passphrase; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )157;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_key_value;
                sqlstm.sqhstl[0] = (unsigned long )503;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_key_value;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_key_id;
                sqlstm.sqhstl[1] = (unsigned long )35;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_key_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_key_uid;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_key_uid;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_privatepem;
                sqlstm.sqhstl[3] = (unsigned long )23;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_privatepem;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_publiccert;
                sqlstm.sqhstl[4] = (unsigned long )23;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_publiccert;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_passphrase;
                sqlstm.sqhstl[5] = (unsigned long )103;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_passphrase;
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
                if (sqlca.sqlcode < 0) goto getpspkey_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
			iRet = SQL_NOT_FOUND;
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);


/* key */
                if (ind_key_value >= 0) {
                        v_key_value.arr[v_key_value.len] = '\0';
                        PutField_CString(myHash,"key_value",(const char*)v_key_value.arr);
DEBUGLOG(("GetPspKey key_value = [%s]\n",v_key_value.arr));
                }
/* key_id */
                if (ind_key_id >= 0) {
                        v_key_id.arr[v_key_id.len] = '\0';
                        PutField_CString(myHash,"key_id",(const char*)v_key_id.arr);
DEBUGLOG(("GetPspKey key_id = [%s]\n",v_key_id.arr));
                }
/* key_uid */
                if (ind_key_uid >= 0) {
                        v_key_uid.arr[v_key_uid.len] = '\0';
                        PutField_CString(myHash,"key_uid",(const char*)v_key_uid.arr);
DEBUGLOG(("GetPspKey key_uid = [%s]\n",v_key_uid.arr));
                }
/* privatepem */
                if (ind_privatepem >= 0) {
                        v_privatepem.arr[v_privatepem.len] = '\0';
                        PutField_CString(myHash,"privatepem",(const char*)v_privatepem.arr);
DEBUGLOG(("GetPspKey privatepem = [%s]\n",v_privatepem.arr));
                }
/* publiccert */
                if (ind_publiccert >= 0) {
                        v_publiccert.arr[v_publiccert.len] = '\0';
                        PutField_CString(myHash,"publiccert",(const char*)v_publiccert.arr);
DEBUGLOG(("GetPspKey publiccert = [%s]\n",v_publiccert.arr));
                }
/* passphrase */
                if (ind_passphrase >= 0) {
                        v_passphrase.arr[v_passphrase.len] = '\0';
                        PutField_CString(myHash,"passphrase",(const char*)v_passphrase.arr);
DEBUGLOG(("GetPspKey passphrase = [%s]\n",v_passphrase.arr));
                }



                RecordSet_Add(myRec,myHash);
		break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpspkey; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )196;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspkey_error;
}



	

DEBUGLOG(("GetPspKey Normal Exit\n"));
        if(iRet==0) return  PD_OK;
	else	return iRet;

getpspkey_error:
DEBUGLOG(("getpspkey_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpspkey; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )211;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdatePspKey(const hash_t *hPspKeys)
{
	char	*csBuf;
	char	*csKey;
	char	*csPspId;
	char	*csTmp;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_psp_key_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdatePspKey: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE psp_keys SET update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* psp_id */
	if (GetField_CString(hPspKeys, "psp_id", &csPspId))
	{
DEBUGLOG(("- psp_id = [%s]\n", csPspId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdatePspKey: psp_id not found\n"));

		return PD_ERR;
	}

	/* key */
	if (GetField_CString(hPspKeys, "key", &csKey))
	{
DEBUGLOG(("- key = [%s]\n", csKey));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdatePspKey: key not found\n"));

		return PD_ERR;
	}

	/* key_value */
	if (GetField_CString(hPspKeys, "key_value", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", key_value = '");
		strcat((char*)hv_dynstmt.arr, ora_ESC_string(csTmp));
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- key_value = [%s]\n", csTmp));
	}

	/* update_user */
	if (GetField_CString(hPspKeys, "update_user", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", update_user = '");
		strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csTmp));
	}

	/* psp_id / key */
	strcat((char*)hv_dynstmt.arr, " WHERE psp_id = '");
	strcat((char*)hv_dynstmt.arr, ESC_string(csPspId));
	strcat((char*)hv_dynstmt.arr, "' AND key = '");
	strcat((char*)hv_dynstmt.arr, csKey);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_psp_key_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )245;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_psp_key_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdatePspKey: Normal Exit\n"));
	return iRet;

update_psp_key_error:
DEBUGLOG(("update_psp_key_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("PspKeys_UpdatePspKey: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdatePspKey: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
