
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
    "check_merchant_txn_ew.pc"
};


static unsigned int sqlctx = 1162802691;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
"select count ( * ) from txn_header where th_txn_code in ( 'DSP' , 'DSI' ) a\
nd th_merchant_id = :b0 and th_create_timestamp between sysdate - ( :b1 / 144\
0 ) and sysdate            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,179,0,9,168,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
28,0,0,1,0,0,13,170,0,0,1,0,0,1,0,2,3,0,0,
47,0,0,1,0,0,15,186,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,210,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/16              LokMan Chow
Use Email Alert Template                           2014/07/22              Elvis Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define MAIL_ALERT_TPL_PATH  "/home/php3dev/src/batch/check_merchant_txn_ew.tpl"
#define MAIL_TITLE "No Transaction for Merchant"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char 	cs_merchant_id[PD_MERCHANT_ID_LEN+1];
char    cs_merchant_name[PD_NAME_LEN+1];
char 	cs_period[PD_DATE_LEN+1];
char    cs_Tag[PD_TAG_LEN+1];
char    cDebug;
int     i_tpl_init;
int     i_tpl_type;

OBJPTR(DB);
int parse_arg(int argc,char **argv);
int process_txn(tpl_t *tpl);

int batch_init(int argc, char* argv[])
{
//printf("batch_init: argc = %d argv[0] = %s argv[1] = %s argv[2] = %s\n", argc, argv[0], argv[1], argv[2]);
	if (argc < 4) {
		//printf("batch_init: usage: -i merchant_id -n merchant_name -p period [minutes] -t table_type\n")
		return FAILURE;
	}
	else
		return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;
	tpl_t   *tpl = tpl_alloc();
        char    *csContent;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
		//printf("batch_proc: usage: -i merchant_id -n merchant_name -p period [minutes] -t table_type\n")
                return SUCCESS;
        }
	
	if(iRet == SUCCESS){
		//tpl_t   *tpl = tpl_alloc();
        	//char    *csContent;

        	// Load template
        	if (tpl_load(tpl, MAIL_ALERT_TPL_PATH) == TPL_OK)
        	{
                	i_tpl_init = 0;
        	}
        	else
        	{
               		(void)puts("Error loading template file!");
               		return SUCCESS;
        	}

        	iRet = process_txn(tpl);

		if (i_tpl_init == 1)
        	{
                	// Table (Template Type)
//printf("batch_proc: Table(Template type = %d)\n", i_tpl_type);
                	{
                        	tpl_select_section(tpl, "TABLE_START");
                        	sprintf(cs_Tag, "tpl%d", i_tpl_type);
                        	tpl_set_field_fmt(tpl, "TPL_NUM", "%s", cs_Tag);
                        	tpl_append_section(tpl);
                        	tpl_deselect_section(tpl);
                	}

                	// Table (Title)
                	{
//printf("batch_proc: Table(Title)\n");
                        	tpl_select_section(tpl, "TITLE");
                        	tpl_set_field_fmt(tpl, "tpl_Title", "%s", MAIL_TITLE);
                        	tpl_append_section(tpl);
                        	tpl_deselect_section(tpl);
                	}

                	// Table (Timestamp)
                	{
//printf("batch_proc: Table(Timestamp)\n");
                        	tpl_select_section(tpl, "TIMESTAMP");
                        	tpl_set_field_fmt(tpl, "tpl_Timestamp", write_tpl_timestamp());
                        	tpl_append_section(tpl);
                        	tpl_deselect_section(tpl);
                	}
        	}

        	// Unload templete
        	{
                	i_tpl_init = 0;
                	csContent = malloc(tpl_length(tpl) + 1);
                	tpl_get_content(tpl, csContent);
                	(void)puts(csContent);
                	tpl_free(tpl);
        	}
	}

//printf("merchant_batch_proc: iRet=%d\n", iRet);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_txn(tpl_t *tpl)
{               
 
        int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		int	hv_period;

		int	v_cnt;

		short	ind_cnt = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(cs_merchant_id);
        memcpy(hv_merchant_id.arr,cs_merchant_id,hv_merchant_id.len);

	hv_period = atoi(cs_period);

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select  count(*)
		from	txn_header
		where	th_txn_code in ('DSP','DSI')
		and	th_merchant_id = :hv_merchant_id 
		and	th_create_timestamp  between sysdate-(:hv_period/1440) and sysdate; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_period;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
		 	:v_cnt:ind_cnt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )28;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_cnt;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if(ind_cnt<0)
			v_cnt = 0;

		if(v_cnt==0){
			iRet = FAILURE;
		}
 	}
        while(PD_TRUE && iRet == SUCCESS);
        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )47;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	// EW Test
	//iRet = FAILURE;

	//if(iRet == FAILURE)
	{
		iRet = FAILURE;	

		i_tpl_init = 1;

              	// Table (ROW)
               	tpl_select_section(tpl, "ROW");
               	tpl_set_field_fmt(tpl, "tpl_Merchant", "No Transaction from [%s (%s)] for more than %s minutes", cs_merchant_name, cs_merchant_id, cs_period);
              	tpl_append_section(tpl);
		tpl_deselect_section(tpl);
	}

//printf("process_txn: iRet=%d\n", iRet);
        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )62;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int parse_arg(int argc,char **argv)
{
	char    c;

	strcpy(cs_merchant_id,"");
	strcpy(cs_merchant_name,"");
	strcpy(cs_period,"5");
	i_tpl_type = 0;

	while ((c = getopt(argc,argv,"i:n:p:t:")) != EOF) {
//printf("parse_arg: c = %c \n", c);
		switch (c) {
			case 'i':
//printf("parse_arg: case i, optarg = %s \n", optarg);
				strcpy(cs_merchant_id, optarg);
				break;
			case 'n':
//printf("parse_arg: case n, optarg = %s \n", optarg);
				strcpy(cs_merchant_name, optarg);
				break;
			case 'p':
//printf("parse_arg: case p, optarg = %s \n", optarg);
				strcpy(cs_period, optarg);
				break;
			case 't':
//printf("parse_arg: case t, atoi(optarg) = %d \n", atoi(optarg));
                                i_tpl_type = atoi(optarg);				
				break;
			default:
//printf("parse_arg: Error (Not Option)! \n");
				return FAILURE;
		}
	}

	if (!strcmp(cs_merchant_id,""))
		return FAILURE;

	cs_merchant_id[strlen(cs_merchant_id)]='\0';
	cs_merchant_name[strlen(cs_merchant_name)]='\0';
	cs_period[strlen(cs_period)]='\0';

	return SUCCESS;
}
