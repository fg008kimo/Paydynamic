
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
    "TestCreate.pc"
};


static unsigned int sqlctx = 649827;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
5,0,0,1,145,0,4,60,0,0,6,1,0,1,0,2,9,0,0,2,3,0,0,2,4,0,0,2,9,0,0,2,1,0,0,1,1,0,
0,
44,0,0,2,203,0,6,194,0,0,7,7,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,4,0,0,1,3,0,0,1,9,
0,0,1,9,0,0,
87,0,0,3,0,0,17,301,0,0,1,1,0,1,0,1,9,0,0,
106,0,0,3,0,0,21,302,0,0,0,0,0,1,0,
121,0,0,0,0,0,56,387,0,0,1,1,0,1,0,3,102,0,0,
140,0,0,4,184,0,6,389,0,0,7,7,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
4,0,0,2,102,0,0,
183,0,0,0,0,0,13,407,0,0,5,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,4,0,0,
218,0,0,0,0,0,15,448,0,0,1,1,0,1,0,1,102,0,0,
237,0,0,0,0,0,78,449,0,0,1,1,0,1,0,3,102,0,0,
256,0,0,0,0,0,15,460,0,0,1,1,0,1,0,1,102,0,0,
275,0,0,0,0,0,78,461,0,0,1,1,0,1,0,3,102,0,0,
};


/*
PDProTech(c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/11/14              Caroline Yeh
update UpdateWithGet				   2020/02/19		   MSN
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TestCreate.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;


void TestCreate(char cdebug){
	cDebug = cdebug;
}

int Get(const char cKey,   hash_t * myHash)
{


	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char            hv_key;
		char            v_key;
		/* varchar         v_field[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_field;

		int             v_disabled;
		double          v_amount;
		/* varchar         v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		
		short		ind_key = -1;
		short		ind_field = -1;
    		short		ind_amount = -1;
    		short		ind_disabled = -1;
    		short		ind_ccy = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_key = cKey;
DEBUGLOG(("Get key = [%c]\n",hv_key));

	/* EXEC SQL
		select	tc_field,
			tc_disabled,
			tc_amount,
			tc_ccy,
			tc_key
        into	:v_field:ind_field,
                    :v_disabled:ind_disabled,
                    :v_amount:ind_amount,
                    :v_ccy:ind_ccy,
                    :v_key:ind_key
		from	test_create
		where	tc_key =:hv_key; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select tc_field , tc_disabled , tc_amount , tc_ccy , tc_key\
 into :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 , :b8:b9 from test_create where tc_ke\
y = :b10 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_field;
 sqlstm.sqhstl[0] = (unsigned long )22;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_field;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&v_amount;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_amount;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_key;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_key;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_key;
 sqlstm.sqhstl[5] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto get_error;
}



	if(ind_key>=0){

	/*field*/
		if(ind_field>=0){
			v_field.arr[v_field.len]='\0';
			PutField_CString(myHash,"field",(const char*)v_field.arr);
DEBUGLOG(("Get field=[%s]\n",v_field.arr));
		}
	/*disabled*/
		if(ind_disabled>=0){
			PutField_Int(myHash,"disabled",v_disabled);
DEBUGLOG(("Get disabled = [%d]\n",v_disabled));
		}

	/*amount*/
		if(ind_amount>=0){
			PutField_Double(myHash,"amount",v_amount);
DEBUGLOG(("Get amount= [%lf]\n",v_amount));
		}

	/*currency id*/
		if(ind_ccy>=0){
			v_ccy.arr[v_ccy.len]='\0';
			PutField_CString(myHash,"currency_id",(const char*)v_ccy.arr);
DEBUGLOG(("Get currency id=[%s]\n",v_ccy.arr));
		}

		iRet = PD_FOUND;
	}

DEBUGLOG(("Get: Finished iRet = [%d]\n",iRet));
	return iRet;

	
get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TestCreate_Get: SP_INTERNAL_ERR\n");
/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}




int     Add(const hash_t *hRls)
{
        char            cTmp;
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_key;
                /* varchar         hv_field[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_field;

                int             hv_disabled;
                double          hv_amount;
                /* varchar         hv_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_user;

                /* varchar         hv_currency_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;


		short           ind_key = -1;
		short		ind_field = -1;
		short		ind_amount = -1;
		short		ind_disabled = -1;
		short		ind_user = -1;
		short		ind_currency_id = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	/*key*/
        if(GetField_Char(hRls,"key",&cTmp)){
                hv_key=cTmp;
                ind_key = 0;
	DEBUGLOG(("Add: key = [%c]\n", hv_key));
        }

	/*field*/
        if(GetField_CString(hRls,"field",&csTmp)){
                hv_field.len = strlen(csTmp);
                memcpy(hv_field.arr, csTmp, hv_field.len);
                ind_field= 0;
		DEBUGLOG(("Add:field = [%.*s]\n",hv_field.len,hv_field.arr));
        }

	/*disabled*/
        if (GetField_Int(hRls,"disabled",&iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
		DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
        }

	/*amount*/
        if (GetField_Double(hRls,"amount",&dTmp)) {
                hv_amount= dTmp;
                ind_amount= 0;
		DEBUGLOG(("Add:amount = [%lf]\n",hv_amount));
        }

	/*user*/
        if(GetField_CString(hRls,"add_user",&csTmp)){
                hv_user.len = strlen(csTmp);
                memcpy(hv_user.arr, csTmp, hv_user.len);
                ind_user= 0;
		DEBUGLOG(("Add:user = [%.*s]\n",hv_user.len,hv_user.arr));
        }
	/*currency_id*/
        if(GetField_CString(hRls,"currency_id",&csTmp)){
                hv_currency_id.len = strlen(csTmp);
                memcpy(hv_currency_id.arr, csTmp, hv_currency_id.len);
                ind_currency_id= 0;
		DEBUGLOG(("Add:currency_id = [%.*s]\n",hv_currency_id.len,hv_currency_id.arr));
        }
	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_test_create_insert(
                                        :hv_key:ind_key,
                                        :hv_field:ind_field,
                                        :hv_amount:ind_amount,
                                        :hv_disabled:ind_disabled,
                                        :hv_user:ind_user,
                                        :hv_currency_id:ind_currency_id
                                        );
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_test_create_insert ( :hv_key:i\
nd_key , :hv_field:ind_field , :hv_amount:ind_amount , :hv_disabled:ind_disab\
led , :hv_user:ind_user , :hv_currency_id:ind_currency_id ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_key;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_key;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_field;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_field;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_amount;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_disabled;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[5] = (unsigned long )23;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_user;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_currency_id;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_currency_id;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("TestCreate_Add: SP_OTHER_ERR \n");
                DEBUGLOG(("Add: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("TestCreate_Add: SP_ERR \n");
                DEBUGLOG(("Add: SP_ERR \n"));
                return PD_ERR;
        }

	add_error:
		DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
		DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
		ERRLOG("TestCreate_Add: SP_INTERNAL_ERR \n");
        	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        	return PD_ERR;

}


int UpdateByKey(const char cKey,const hash_t *hRls)
{
	char*   csBuf;
	int	iTmp = 0;
	double	dTmp = 0.0;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update test_create set tc_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if(GetField_CString(hRls,"field",&csBuf)){
		DEBUGLOG(("Update:field = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",tc_field = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
	}

	if(GetField_Int(hRls,"disabled",&iTmp)){
		DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",tc_disabled =");
		strcat((char*)hv_dynstmt.arr, csBuf);
	}

	if(GetField_Double(hRls,"amount",&dTmp)){
		DEBUGLOG(("Update:amount = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tc_amount =");
		strcat((char*)hv_dynstmt.arr, csBuf);
	}

	if(GetField_CString(hRls,"currency_id",&csBuf)){
		DEBUGLOG(("Update:currency_id = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",tc_ccy = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
	}

	if(GetField_CString(hRls,"update_user",&csBuf)){
		DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",tc_update_user= '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
	}

	sprintf(csBuf,"%c",cKey);
	strcat((char*)hv_dynstmt.arr, " WHERE tc_key = '");
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )87;
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
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

	DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

	update_error:
		DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
		DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
		ERRLOG("Test_Create_Update: SP_INTERNAL_ERR\n");
	        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        	return PD_INTERNAL_ERR;
}


int UpdateWithGet(hash_t *hIn,   hash_t *hOut)
{
	int	iRet = PD_ERR;
	char	cPtr;
	int	iPtr;
	double	dPtr;
	char	*csPtr;

	/* EXEC SQL WHENEVER SQLERROR GOTO upd_get; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		char            hv_key;
		/* varchar         hv_field[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_field;

		/* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		int             hv_disabled;
		double          hv_amount;
		/* varchar         v_out_field[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_out_field;

		/* varchar         v_out_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_out_ccy;

		int             v_out_disabled;
		double          v_out_amount;
		
		short		ind_key = -1;
		short		ind_field = -1;
    		short		ind_ccy = -1;
    		short		ind_amount = -1;
    		short		ind_disabled = -1;
		short		ind_out_field = -1;
    		short		ind_out_ccy = -1;
    		short		ind_out_amount = -1;
    		short		ind_out_disabled = -1;

		SQL_CURSOR	c_cursor_dt;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_Char(hIn, "key", &cPtr)){
		hv_key = cPtr;
		ind_key = 0;
DEBUGLOG(("UpdateWithGet:key = [%c]\n",hv_key));
	}

	if(GetField_CString(hIn, "field", &csPtr)){
		hv_field.len = strlen(csPtr);
		strncpy((char *)hv_field.arr, csPtr, hv_field.len);
		ind_field = 0;
DEBUGLOG(("UpdateWithGet:field = [%.*s]\n",hv_field.len,hv_field.arr));
	}

	if(GetField_CString(hIn, "currency_id", &csPtr)){
		hv_ccy.len = strlen(csPtr);
		strncpy((char *)hv_ccy.arr, csPtr, hv_ccy.len);
		ind_ccy = 0;
DEBUGLOG(("UpdateWithGet:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
	}

	if(GetField_Int(hIn, "disabled", &iPtr)){
		hv_disabled = iPtr;
		ind_disabled = 0;
DEBUGLOG(("UpdateWithGet:disabled = [%d]\n",hv_disabled));
	}
	if(GetField_Double(hIn, "amount", &dPtr)){
		hv_amount = dPtr;
		ind_amount = 0;
DEBUGLOG(("UpdateWithGet:amount = [%lf]\n",hv_amount));
	}

	/* EXEC SQL ALLOCATE	:c_cursor_dt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )121;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
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
 if (sqlca.sqlcode < 0) goto upd_get;
}



        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_test_update_with_get(
				:hv_key:ind_key,
				:hv_field:ind_field,
				:hv_ccy:ind_ccy,
				:hv_disabled:ind_disabled,
				:hv_amount:ind_amount,
                                :c_cursor_dt);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_test_update_with_get ( \
:hv_key:ind_key , :hv_field:ind_field , :hv_ccy:ind_ccy , :hv_disabled:ind_di\
sabled , :hv_amount:ind_amount , :c_cursor_dt ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_key;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_key;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_field;
        sqlstm.sqhstl[2] = (unsigned long )22;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_field;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_amount;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_dt;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto upd_get;
}




DEBUGLOG(("UpdateWithGet return_value = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
	{
		/* EXEC SQL FETCH :c_cursor_dt
			INTO   
				:v_out_field:ind_out_field,
                                :v_out_ccy:ind_out_ccy,
                                :v_out_disabled:ind_out_disabled,
                                :v_out_amount:ind_out_amount; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )183;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_out_field;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_out_field;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_out_ccy;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_out_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_out_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_out_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_out_amount;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_out_amount;
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
  if (sqlca.sqlcode < 0) goto upd_get;
}




		/*field*/
		if(ind_out_field >= 0){
			v_out_field.arr[v_out_field.len]='\0';
			PutField_CString(hOut, "field", (const char*)v_out_field.arr);
DEBUGLOG(("UpdateWithGet out_field = [%s]\n",v_out_field.arr));
		}

		/*currency id*/
		if(ind_out_ccy >= 0){
			v_out_ccy.arr[v_out_ccy.len]='\0';
			PutField_CString(hOut, "ccy", (const char*)v_out_ccy.arr);
DEBUGLOG(("UpdateWithGet out_ccy = [%s]\n",v_out_ccy.arr));
		}

		/*disabled*/
		if(ind_out_disabled >= 0){
			PutField_Int(hOut, "disabled", v_out_disabled);
DEBUGLOG(("UpdateWithGet out_disabled = [%d]\n",v_out_disabled));
		}

		/*amount*/
		if(ind_out_amount >= 0){
			PutField_Double(hOut, "amount", v_out_amount);
DEBUGLOG(("UpdateWithGet out_amount = [%lf]\n",v_out_amount));
		}

		iRet = PD_OK;
	}
	else{
DEBUGLOG(("UpdateWithGet Failed!!\n"));
	}


	/* EXEC SQL CLOSE :c_cursor_dt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )218;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
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
 if (sqlca.sqlcode < 0) goto upd_get;
}


	/* EXEC SQL FREE :c_cursor_dt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )237;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
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
 if (sqlca.sqlcode < 0) goto upd_get;
}



DEBUGLOG(("UpdateWithGet: Finished iRet = [%d]\n",iRet));
	return iRet;

	
upd_get:
DEBUGLOG(("upd_get code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TestCreate_UpdateWithGet: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )256;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
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


	/* EXEC SQL FREE :c_cursor_dt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )275;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt;
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

