
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
    "get_promote.pc"
};


static unsigned int sqlctx = 1215395;


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
"lect * from ( select cgl_promote_dat\
e qua_date , cgl_promote_date pro_date , 0 cust_cnt , count ( cgl_cust_id ) p\
ro_cnt , add_date from ( select cgl_cust_id , add_date , to_char ( cgl_create\
_timestamp , 'YYYYMMDD' ) qualify_date , cgl_promote_date from customer_group\
_promo_list , customer_group_detail , ( select td_customer_tag , to_char ( mi\
n ( th_create_timestamp ) , 'YYYYMMDD' ) add_date from txn_header , txn_detai\
l where th_txn_id = td_txn_id and td_customer_group = 'GRP_N' and th_merchant\
_id = 'M8000016' and th_txn_code = 'DSI' group by td_customer_tag ) where cgd\
_cust_id = cgl_cust_id and cgd_cust_id = td_customer_tag ) where cgl_promote_\
date > '20140513' group by cgl_promote_date , add_date order by cgl_promote_d\
ate , add_date ) ) where qua_date < '20141027' group by qua_date , pro_date ,\
 add_date )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1853,0,9,151,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,153,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,9,0,0,
63,0,0,1,0,0,15,172,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,179,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,180,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/10/27              LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cDebug;

int batch_init(int argc, char* argv[])
{
/*
    if (argc < 2)
        return FAILURE;
    else
*/
        return SUCCESS;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         v_qua_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_qua_date;

		/* varchar         v_pro_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_pro_date;

		int		v_qua_total;
		int		v_qua_count;
		int		v_pro_total;
		int		v_pro_count;
		/* varchar         v_add_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_add_date;


		short           ind_qua_total = -1;
		short           ind_qua_count = -1;
		short           ind_pro_total = -1;
		short           ind_pro_count = -1;
		short           ind_qua_date = -1;
		short           ind_pro_date = -1;
		short           ind_add_date = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getmerchantid CURSOR FOR
select qua_date,pro_date,
       sum(cust_cnt) over (partition by qua_date) qua_total,
       cust_cnt,
       sum(pro_cnt) over (partition by qua_date) pro_total,
       pro_cnt,
       add_date
from(

select qua_date,pro_date,
       sum(cust_cnt) cust_cnt,
       sum(pro_cnt) pro_cnt,
       add_date
from(
select * from(
select qualify_date qua_date,
        qualify_date pro_date,
        count(cgl_cust_id) cust_cnt,
        0 pro_cnt,
        add_date
from(
select  cgl_cust_id,
        add_date,
        to_char(cgl_create_timestamp,'YYYYMMDD') qualify_date,
        cgl_promote_date
from customer_group_promo_list,
     customer_group_detail,
     (select td_customer_tag,
             to_char (min(th_create_timestamp), 'YYYYMMDD') add_date
        from txn_header, txn_detail
        where th_txn_id = td_txn_id
        and td_customer_group = 'GRP_N'
        and th_merchant_id = 'M8000016'
        and th_txn_code = 'DSI'
        group by td_customer_tag)
where cgd_cust_id = cgl_cust_id
and cgd_cust_id = td_customer_tag
)
where qualify_date > '20140513'
group by qualify_date,
        add_date
order by qualify_date, 
        add_date
)
union all 

select * from(
select  cgl_promote_date qua_date,
        cgl_promote_date pro_date,
        0 cust_cnt,
        count(cgl_cust_id) pro_cnt,
        add_date
from(
select  cgl_cust_id,
        add_date,
        to_char(cgl_create_timestamp,'YYYYMMDD') qualify_date,
        cgl_promote_date
from customer_group_promo_list,
     customer_group_detail,
     (select td_customer_tag,
             to_char (min(th_create_timestamp), 'YYYYMMDD') add_date
        from txn_header, txn_detail
        where th_txn_id = td_txn_id
        and td_customer_group = 'GRP_N'
        and th_merchant_id = 'M8000016'
        and th_txn_code = 'DSI'
        group by td_customer_tag)
where cgd_cust_id = cgl_cust_id
and cgd_cust_id = td_customer_tag
)
where cgl_promote_date > '20140513'
group by 
        cgl_promote_date,
        add_date
order by 
         cgl_promote_date, 
        add_date 
        )
)
where qua_date < '20141027'
group by qua_date,pro_date,add_date
); */ 



	/* EXEC SQL OPEN c_cursor_getmerchantid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select qua_date , pro_date , sum ( cust_cnt ) over ( partition by qua_da\
te ) qua_total , cust_cnt , sum ( pro_cnt ) over ( partition by qua_date ) p\
ro_total , pro_cnt , add_date from ( select qua_date , pro_date , sum ( cust\
_cnt ) cust_cnt , sum ( pro_cnt ) pro_cnt , add_date from ( select * from ( \
select qualify_date qua_date , qualify_date pro_date , count ( cgl_cust_id )\
 cust_cnt , 0 pro_cnt , add_date from ( select cgl_cust_id , add_date , to_c\
har ( cgl_create_timestamp , 'YYYYMMDD' ) qualify_date , cgl_promote_date fr\
om customer_group_promo_list , customer_group_detail , ( select td_customer_\
tag , to_char ( min ( th_create_timestamp ) , 'YYYYMMDD' ) add_date from txn\
_header , txn_detail where th_txn_id = td_txn_id and td_customer_group = 'GR\
P_N' and th_merchant_id = 'M8000016' and th_txn_code = 'DSI' group by td_cus\
tomer_tag ) where cgd_cust_id = cgl_cust_id and cgd_cust_id = td_customer_ta\
g ) where qualify_date > '20140513' group by qualify_date , add_date order b\
y qualify_date , add_date ) union all se");
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getmerchantid
			INTO    :v_qua_date:ind_qua_date,
				:v_pro_date:ind_pro_date,
				:v_qua_total:ind_qua_total,
				:v_qua_count:ind_qua_count,
				:v_pro_total:ind_pro_total,
				:v_pro_count:ind_pro_count,
				:v_add_date:ind_add_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_qua_date;
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_qua_date;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_pro_date;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_pro_date;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_qua_total;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_qua_total;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_qua_count;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_qua_count;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_pro_total;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_pro_total;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_pro_count;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_pro_count;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_add_date;
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_add_date;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		printf("%.*s-%.*s-%.*s,%d,%d,%d,%d,%.*s-%.*s-%.*s\n",4,v_pro_date.arr,2,&v_pro_date.arr[4],2,&v_pro_date.arr[6],v_qua_total,v_qua_count,v_pro_total,v_pro_count,4,v_add_date.arr,2,&v_add_date.arr[4],2,&v_add_date.arr[6]);

	}while(PD_TRUE);


        /* EXEC SQL CLOSE c_cursor_getmerchantid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )63;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



        return SUCCESS;
sql_error:
    DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getmerchantid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )93;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
