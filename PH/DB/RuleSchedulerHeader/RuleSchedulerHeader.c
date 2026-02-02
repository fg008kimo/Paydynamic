
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
    "RuleSchedulerHeader.pc"
};


static unsigned int sqlctx = 338998203;


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

 static char *sq0001 = 
"SELECT rs_schedule_mode , ro_start_datetime , ro_end_datetime , rt_start_ti\
me , rt_end_time , rt_day , to_char ( rs_effect_datetime , 'YYYYMMDDHH24MISS'\
 ) FROM ( SELECT * FROM rule_scheduler_header WHERE rowid = ( SELECT rowid FR\
OM rule_scheduler_header WHERE rs_disabled = 0 AND rs_scheduler_id = :b0 AND \
rs_effect_datetime <= sysdate ) ) LEFT join rule_schedule_once ON rs_schedule\
r_id = ro_scheduler_id AND ro_disabled = 0 LEFT join rule_schedule_recur ON r\
s_scheduler_id = rr_scheduler_id AND rr_disabled = 0 LEFT join rule_recur_typ\
e ON rr_recurring_id = rt_id AND rt_disabled = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,597,0,9,93,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,95,0,0,7,0,0,1,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,
0,2,9,0,0,
67,0,0,1,0,0,15,164,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,170,0,0,0,0,0,1,0,
97,0,0,2,0,0,17,254,0,0,1,1,0,1,0,1,9,0,0,
116,0,0,2,0,0,45,259,0,0,0,0,0,1,0,
131,0,0,2,0,0,13,261,0,0,1,0,0,1,0,2,3,0,0,
150,0,0,2,0,0,15,277,0,0,0,0,0,1,0,
165,0,0,2,0,0,15,285,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/04              LokMan Chow
Get ID Detail					   2012/01/09		   Cody Chan
FindMostUpdatedSchedule
	by 1. max effective datetime
	   2. max update timestamp		   2016/10/19		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "RuleSchedulerHeader.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void RuleSchedulerHeader(char    cdebug)
{
        cDebug = cdebug;
}


int GetIdDetail(int iId, recordset_t* myRec)
{
	hash_t *myHash;
	int	iRet = PD_NOT_FOUND;
	/* EXEC SQL WHENEVER SQLERROR GOTO getiddetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
	

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_id;
		
		char	v_schedule_mode;
		/* varchar	v_start_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_datetime;

		/* varchar	v_end_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_datetime;

		/* varchar	v_start_time[PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_start_time;

		/* varchar	v_end_time[PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_end_time;

		int	v_day;
		/* varchar	v_effect_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_effect_datetime;


		short	ind_schedule_mode = -1;
		short	ind_start_datetime = -1;
		short	ind_end_datetime = -1;
		short	ind_start_time = -1;
		short	ind_end_time = -1;
		short	ind_day = -1;
		short	ind_effect_datetime = -1;

		

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_id = iId;
DEBUGLOG(("GetIdDetail id = [%d]\n",iId));

	/* EXEC SQL DECLARE c_cursor_getiddetail CURSOR FOR
		 SELECT rs_schedule_mode,
                        ro_start_datetime,
                        ro_end_datetime,
                        rt_start_time,
                        rt_end_time,
                        rt_day,
			to_char(rs_effect_datetime,'YYYYMMDDHH24MISS')
 		  FROM (SELECT *
           		  FROM  rule_scheduler_header 
          		 WHERE rowid = 
           			(SELECT rowid
                    		   FROM rule_scheduler_header
                          	  WHERE rs_disabled = 0
                            	    AND rs_scheduler_id = :hv_id
                          	    AND rs_effect_datetime  <= sysdate) )
                  LEFT join rule_schedule_once
                     ON rs_scheduler_id = ro_scheduler_id
                    AND ro_disabled = 0
                  LEFT join rule_schedule_recur
                     ON rs_scheduler_id = rr_scheduler_id
                    AND rr_disabled = 0
                  LEFT join rule_recur_type
                     ON rr_recurring_id = rt_id
                    AND rt_disabled = 0; */ 


	/* EXEC SQL OPEN c_cursor_getiddetail; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
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
 if (sqlca.sqlcode < 0) goto getiddetail_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getiddetail 
		INTO
			:v_schedule_mode:ind_schedule_mode,
			:v_start_datetime:ind_start_datetime,
			:v_end_datetime:ind_end_datetime,
			:v_start_time:ind_start_time,
			:v_end_time:ind_end_time,
			:v_day:ind_day,
			:v_effect_datetime:ind_effect_datetime; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_schedule_mode;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_schedule_mode;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_datetime;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_datetime;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_datetime;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_datetime;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_start_time;
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_start_time;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_end_time;
  sqlstm.sqhstl[4] = (unsigned long )9;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_end_time;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_day;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_day;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_effect_datetime;
  sqlstm.sqhstl[6] = (unsigned long )17;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_effect_datetime;
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
  if (sqlca.sqlcode < 0) goto getiddetail_error;
}




		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		iRet = PD_FOUND;

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* schedule_mode */
		if (ind_schedule_mode >= 0) {
DEBUGLOG(("GetIdDetail schedule_mode = [%c]\n",v_schedule_mode));
			PutField_Char(myHash,"schedule_mode",v_schedule_mode);
		}		

/* start_datetime */
		if (ind_start_datetime >= 0) {
			v_start_datetime.arr[v_start_datetime.len] = '\0';
DEBUGLOG(("GetIdDetail start_datetime = [%s]\n",v_start_datetime.arr));
			PutField_CString(myHash,"start_datetime",(char*)v_start_datetime.arr);
		}		
/* end_datetime */
		if (ind_end_datetime >= 0) {
			v_end_datetime.arr[v_end_datetime.len] = '\0';
DEBUGLOG(("GetIdDetail end_datetime = [%s]\n",v_end_datetime.arr));
			PutField_CString(myHash,"end_datetime",(char*)v_end_datetime.arr);
		}		

/* start_time */
                if (ind_start_time >= 0) {
                        v_start_time.arr[v_start_time.len] = '\0';
DEBUGLOG(("GetIdDetail start_time = [%s]\n",v_start_time.arr));
                        PutField_CString(myHash,"start_time",(char*)v_start_time.arr);
                }
/* end_time */
                if (ind_end_time >= 0) {
                        v_end_time.arr[v_end_time.len] = '\0';
DEBUGLOG(("GetIdDetail end_time = [%s]\n",v_end_time.arr));
                        PutField_CString(myHash,"end_time",(char*)v_end_time.arr);
                }
/* day */
		if (ind_day >= 0) {
DEBUGLOG(("GetIdDetail day = [%d]\n",v_day));
			PutField_Int(myHash,"day",v_day);
		}

/* effect_datetime */
		if (ind_effect_datetime >= 0) {
			v_effect_datetime.arr[v_effect_datetime.len] = '\0';
DEBUGLOG(("GetIdDetail effect_datetime = [%s]\n",v_effect_datetime.arr));
			PutField_CString(myHash,"effect_datetime",(char*)v_effect_datetime.arr);
		}		


		RecordSet_Add(myRec,myHash);

	} 
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getiddetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getiddetail_error;
}


	return PD_FOUND;
getiddetail_error:
DEBUGLOG(("getiddetail code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getiddetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )82;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_NOT_FOUND;
}





int FindMostUpdatedSchedule(hash_t* hRls)
{
	int	iRet = PD_NOT_FOUND;
	char*   csBuf;
        char*   csIdList;
	int	iCnt = 0;
	int	iTmp= 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO mostupdsch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
	

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
		/* varchar hv_dynstmt[1024*4]; */ 
struct { unsigned short len; unsigned char arr[4096]; } hv_dynstmt;
	
		int	v_result_id;

		short	ind_result_id= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);
	csIdList = (char*) malloc (1024);
	csBuf[0] = '\0';
	csIdList[0] = '\0';


        if (GetField_Int(hRls,"id_cnt",&iCnt)) {
DEBUGLOG(("FindMostUpdatedSchedule: id_cnt = [%d]\n",iCnt));
                int i = 0;
                char    csTag[PD_TAG_LEN +1];
                for (i = 1; i <= iCnt; i++) {
                        sprintf(csTag,"id_%d",i);
                        if (GetField_Int(hRls,csTag,&iTmp)) {
DEBUGLOG(("FindMostUpdatedSchedule: [%s] = [%d]\n",csTag,iTmp));
                                if (i == 1)
                                        sprintf(csBuf,"%d",iTmp);
                                else
                                        sprintf(csBuf,",%d",iTmp);
                                strcat(csIdList,csBuf);
                        }
                }
        }
	
/*
select rs_scheduler_id
from(select rs_scheduler_id
     from rule_scheduler_header
     where rs_scheduler_id in (id_1, id_2, ..., id_n)
     and rs_disabled =0
     and rs_effect_datetime = (
			select max(rs_effect_datetime)
			from rule_scheduler_header
			where rs_scheduler_id in (id_1, id_2, ..., id_n)
			and rs_disabled =0)
     order by rs_update_timestamp desc)
where rownum =1;
*/

        strcpy((char*)hv_dynstmt.arr,"select rs_scheduler_id from ( ");
        strcat((char*)hv_dynstmt.arr,"select rs_scheduler_id from rule_scheduler_header ");
	strcat((char*)hv_dynstmt.arr,"where rs_disabled = 0 ");
        strcat((char*)hv_dynstmt.arr,"and rs_scheduler_id in ( ");
        strcat((char*)hv_dynstmt.arr,csIdList);
        strcat((char*)hv_dynstmt.arr," ) ");
        strcat((char*)hv_dynstmt.arr,"and rs_effect_datetime = ( ");
        strcat((char*)hv_dynstmt.arr,"select max(rs_effect_datetime) from rule_scheduler_header ");
	strcat((char*)hv_dynstmt.arr,"where rs_disabled = 0 ");
        strcat((char*)hv_dynstmt.arr,"and rs_scheduler_id in ( ");
        strcat((char*)hv_dynstmt.arr,csIdList);
        strcat((char*)hv_dynstmt.arr," )");
        strcat((char*)hv_dynstmt.arr,")");
        strcat((char*)hv_dynstmt.arr," order by rs_update_timestamp desc) where rownum = 1");

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
        sqlstm.offset = (unsigned int  )97;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )4098;
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
        if (sqlca.sqlcode < 0) goto mostupdsch_error;
}


        /* EXEC SQL DECLARE c_cursor_mostupdsch CURSOR FOR PS; */ 

        FREE_ME(csBuf);
        FREE_ME(csIdList);

        /* EXEC SQL OPEN c_cursor_mostupdsch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )116;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto mostupdsch_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_mostupdsch
                INTO
                        :v_result_id:ind_result_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )131;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_result_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_result_id;
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
                if (sqlca.sqlcode < 0) goto mostupdsch_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if(ind_result_id >= 0){
			PutField_Int(hRls,"result_id",v_result_id);
DEBUGLOG(("The Most updated Schedule = [%d]\n",v_result_id));
			iRet = PD_FOUND;
		}
        }
        while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_mostupdsch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )150;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto mostupdsch_error;
}


DEBUGLOG(("FindMostUpdatedSchedule iRet = [%d]\n",iRet));
        return iRet;

mostupdsch_error:
DEBUGLOG(("mostupdsch code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_mostupdsch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )165;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
