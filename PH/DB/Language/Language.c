
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "Language.pc"
};


static unsigned int sqlctx = 149779;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
5,0,0,1,214,0,6,103,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,
0,0,
44,0,0,2,70,0,6,160,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/29              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "Language.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void Language(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hLang)
{
	char            *csTmp;
	char		cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_lang_code[PD_LANGUAGE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_lang_code;

		/* varchar		hv_description[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_description;

		char		hv_disabled;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;



		short 		ind_lang_code = -1;
		short 		ind_description = -1;
		short 		ind_disabled = -1;
		short 		ind_create_user = -1;
		short 		ind_update_user = -1;

		short 		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hLang,"lang_code", &csTmp))
	{
		hv_lang_code.len = strlen(csTmp);
		strncpy((char*)hv_lang_code.arr, csTmp, hv_lang_code.len);
		ind_lang_code = 0;
	}
DEBUGLOG(("Add:lang_code = [%.*s]\n",hv_lang_code.len,hv_lang_code.arr));

	if(GetField_CString(hLang,"description", &csTmp))
	{
		hv_description.len = strlen(csTmp);
		strncpy((char*)hv_description.arr, csTmp, hv_description.len);
		ind_description = 0;
	}
DEBUGLOG(("Add:description = [%.*s]\n",hv_description.len,hv_description.arr));

	if(GetField_Char(hLang,"disabled", &cTmp))
	{
		hv_disabled = cTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%c]\n",hv_disabled));
	
	if(GetField_CString(hLang,"update_user", &csTmp))
	{
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
	}
DEBUGLOG(("Add:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));

	if(GetField_CString(hLang,"create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN
		:hv_return_value := sp_language_insert(
				:hv_lang_code:ind_lang_code,
				:hv_description:ind_description,
				:hv_disabled:ind_disabled,
				:hv_create_user:ind_create_user,
				:hv_update_user:ind_update_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_language_insert ( :hv_lang_cod\
e:ind_lang_code , :hv_description:ind_description , :hv_disabled:ind_disabled\
 , :hv_create_user:ind_create_user , :hv_update_user:ind_update_user ) ; END \
;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_lang_code;
 sqlstm.sqhstl[1] = (unsigned long )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_lang_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_description;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_description;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_disabled;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_update_user;
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
		ERRLOG("Language_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("Language_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int Delete(const unsigned char* lang_code)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_lang_code[PD_LANGUAGE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_lang_code;


		short   hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_lang_code.len = strlen((const char*)lang_code);
	memcpy(hv_lang_code.arr,lang_code,hv_lang_code.len);

	DEBUGLOG(("Delete: lang_code = [%.*s]\n",hv_lang_code.len,hv_lang_code.arr));

	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_language_delete(
				:hv_lang_code);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_language_delete ( :hv_lang_cod\
e ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_lang_code;
 sqlstm.sqhstl[1] = (unsigned long )4;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




	DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Delete:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("Language_Delete: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("Language_Delete: SP_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
	DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

/*
int FindLanguage(const char* lang_code, char * disabled)
{
	EXEC SQL WHENEVER SQLERROR GOTO find_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                varchar hv_lang_code[PD_LANGUAGE_LEN];

                char	v_disabled;
                short   ind_disabled = -1;

        EXEC SQL END DECLARE SECTION;

        hv_lang_code.len = strlen((const char*)lang_code);
        memcpy(hv_lang_code.arr,lang_code,hv_lang_code.len);
DEBUGLOG(("FindCode: lang_code = [%.*s]\n",hv_lang_code.len,hv_lang_code.arr));

        EXEC SQL SELECT disabled
                   INTO :v_disabled:ind_disabled
                FROM language
                WHERE lang_code = :hv_lang_code;

        if (ind_disabled >= 0) {
		if(v_disabled=='0'){
DEBUGLOG(("disabled = [%c]\n",v_disabled));
                	return FOUND;
		}
		else{
DEBUGLOG(("disabled = [%c]\n",v_disabled));
                	return NOT_FOUND;
		}
        }
DEBUGLOG(("Code NOT FOUND\n"));
        return NOT_FOUND;
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    return NOT_FOUND;
}
*/
