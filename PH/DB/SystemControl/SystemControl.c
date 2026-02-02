
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
    "SystemControl.pc"
};


static unsigned int sqlctx = 5496875;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
"SELECT sys_code , sys_val FROM SYSTEM_CONTROL            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,57,0,9,53,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,55,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,81,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,91,0,0,0,0,0,1,0,
73,0,0,2,68,0,4,113,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
96,0,0,3,101,0,6,158,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
127,0,0,4,79,0,4,214,0,0,1,0,0,1,0,2,9,0,0,
146,0,0,5,121,0,4,224,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
169,0,0,6,75,0,4,237,0,0,1,0,0,1,0,2,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/07/19              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "SystemControl.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void SystemControl(char    cdebug)
{
	cDebug = cdebug;
}

int GetAllCodes(recordset_t* myRec)
{

	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getallcodes_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
	
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_code[PD_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_code;

		/* varchar	v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


		short	ind_code = -1;
		short	ind_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("SystemControl::GetAllCoes()\n"));

	/* EXEC SQL DECLARE c_cursor_getallcodes CURSOR FOR
		SELECT 	sys_code,
			sys_val	
                FROM 	SYSTEM_CONTROL; */ 



	/* EXEC SQL OPEN c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
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
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallcodes_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_getallcodes
              	INTO
			:v_code:ind_code,
			:v_value:ind_value; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 2;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )20;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_code;
         sqlstm.sqhstl[0] = (unsigned long )13;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_code;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_value;
         sqlstm.sqhstl[1] = (unsigned long )53;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_value;
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
         if (sqlca.sqlcode < 0) goto getallcodes_error;
}



		if (SQLCODE == SQL_NOT_FOUND) { 
                	break;
             	}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_code >= 0) {
			v_code.arr[v_code.len] ='\0';
			PutField_CString(myHash,"code",(const char*)v_code.arr);
//DEBUGLOG(("GetAllCodes Code = [%s]\n",v_code.arr)); 
		}
		if (ind_value >= 0) {
			v_value.arr[v_value.len] ='\0';
			PutField_CString(myHash,"value",(const char*)v_value.arr);
//DEBUGLOG(("GetAllCodes value = [%s]\n",v_value.arr)); 
		}
		RecordSet_Add(myRec,myHash);
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallcodes_error;
}




/* DEBUGLOG(("GetAllCode Normal Exit\n")); */
	return  PD_OK;

getallcodes_error:
//DEBUGLOG(("getallodes_error code %d\n", sqlca.sqlcode));
//DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )58;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int FindCode(const char* code,
                unsigned char* value)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_code[PD_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_code;


                /* varchar v_value[PD_VALUE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;

                short   ind_value = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_code.len = strlen(code);
        memcpy(hv_code.arr,code,hv_code.len);
/* DEBUGLOG(("FindCode: code = [%.*s]\n",hv_code.len,hv_code.arr)); */

       	/* EXEC SQL SELECT sys_val
             	    INTO :v_value:ind_value
                FROM SYSTEM_CONTROL
                WHERE SYS_CODE = :hv_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select sys_val INTO :b0:b1 FROM SYSTEM_CONTROL WHERE\
 SYS_CODE = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )73;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_value;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
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



        if (ind_value >= 0) {
                v_value.arr[v_value.len] = '\0';
                strcpy((char*)value,(const char*)v_value.arr);
/* DEBUGLOG(("value = [%s]\n",value)); */
                return FOUND;
        }
/* DEBUGLOG(("Code  NOT FOUND\n")); */
        return NOT_FOUND;
find_error:
//DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
//DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

int Update(const unsigned char* code,
		const unsigned char* value)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short   hv_return_value;
                /* varchar hv_code[PD_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_code;

                /* varchar hv_value[PD_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_value;

		/* varchar	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_code.len = strlen((const char*)code);
        memcpy(hv_code.arr,code,hv_code.len);
/* DEBUGLOG(("update: code = [%.*s]\n",hv_code.len,hv_code.arr)); */

        hv_value.len = strlen((const char*)value);
        memcpy(hv_value.arr,value,hv_value.len);
/* DEBUGLOG(("update: value = [%.*s]\n",hv_value.len,hv_value.arr)); */

	hv_update_user.len = strlen(PD_UPDATE_USER);
        memcpy(hv_update_user.arr,PD_UPDATE_USER,hv_update_user.len);
/* DEBUGLOG(("update: update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr)); */
	/* EXEC SQL EXECUTE
                BEGIN
                :hv_return_value := sp_system_control_update(
					:hv_code,
					:hv_value,
					:hv_update_user);

                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_system_control_update ( :hv_co\
de , :hv_value , :hv_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )96;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



/* DEBUGLOG(("Update: RET = [%d]\n",hv_return_value)); */
        if (hv_return_value == SP_OK) {
                return PD_OK;
        }

        
        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("System_Control:update: SP_OTHER_ERR TxnAbort\n");
//DEBUGLOG(("Update: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }


        if (hv_return_value == SP_ERR) {
ERRLOG("System_Control:update: SP_ERR TxnAbort\n");
//DEBUGLOG(("Update: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

        return PD_OK;

update_error:
//DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
//DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetApprovalDT(hash_t* hContext)
{
	char	cUseAppDate = 'N';
        /* EXEC SQL WHENEVER SQLERROR GOTO GetApprovalDT_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_use_app_date[PD_SP_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_use_app_date;

                /* varchar v_approval_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

                /* varchar v_approval_timestamp[PD_TIMESTAMP_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;


                short   ind_use_app_date = -1;
                short   ind_approval_date = -1;
                short   ind_approval_timestamp = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL SELECT SP_VAL
                   INTO :v_use_app_date:ind_use_app_date
                   FROM system_parameter
                  WHERE SP_CODE = 'USE_APP_DATE'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select SP_VAL INTO :b0:b1 FROM system_parameter WHERE SP_CO\
DE = 'USE_APP_DATE' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )127;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_use_app_date;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_use_app_date;
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
 if (sqlca.sqlcode < 0) goto GetApprovalDT_error;
}



	if (ind_use_app_date >=0 ) {
		if (v_use_app_date.arr[0] == 'Y') 
			cUseAppDate = 'Y';
	}

       	/* EXEC SQL SELECT to_char(sysdate,'YYYYMMDD'),
                        to_char(systimestamp,'YYYYMMDDHH24MISSFF')
             	    INTO :v_approval_date:ind_approval_date,
			:v_approval_timestamp:ind_approval_timestamp
                FROM DUAL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select to_char ( sysdate , 'YYYYMMDD' ) , to_char ( \
systimestamp , 'YYYYMMDDHH24MISSFF' ) INTO :b0:b1 , :b2:b3 FROM DUAL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )146;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_approval_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_approval_date;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_approval_timestamp;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_approval_timestamp;
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
        if (sqlca.sqlcode < 0) goto GetApprovalDT_error;
}



DEBUGLOG(("GetApprovalDT use application date = [%c]\n",cUseAppDate));
        if (ind_approval_date>= 0 && ind_approval_timestamp >=0 ) {
        	v_approval_date.arr[v_approval_date.len] = '\0';
               	v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';

		if (cUseAppDate == 'Y') {
			ind_approval_date = -1;
			/* EXEC SQL SELECT SYS_VAL
                   		INTO :v_approval_date:ind_approval_date
                   		FROM system_control
                  		WHERE SYS_CODE = 'CTPHDATE'; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select SYS_VAL INTO :b0:b1 FROM system_control WHERE SYS_\
CODE = 'CTPHDATE' ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )169;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_approval_date;
   sqlstm.sqhstl[0] = (unsigned long )11;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_approval_date;
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
   if (sqlca.sqlcode < 0) goto GetApprovalDT_error;
}


        		if (ind_approval_date>= 0) {
        			v_approval_date.arr[v_approval_date.len] = '\0';
			}
		}
		PutField_CString(hContext,"approval_date",(const char*)v_approval_date.arr);
		PutField_CString(hContext,"approval_timestamp",(const char*)v_approval_timestamp.arr);
DEBUGLOG(("GetApprovalDT approval_date = [%s]\n",v_approval_date.arr));
DEBUGLOG(("GetApprovalDT approval_timestamp = [%s]\n",v_approval_timestamp.arr));
               	return FOUND;
        }
	else {
DEBUGLOG(("GetApprovalDT get approval_date error\n"));
	}
        return NOT_FOUND;
GetApprovalDT_error:
ERRLOG("GetApprovalDT_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

