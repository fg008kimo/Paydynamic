
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
           char  filnam[26];
};
static struct sqlcxp sqlfpn =
{
    25,
    "CustomerGroupPromoList.pc"
};


static unsigned int sqlctx = 1771544565;


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
5,0,0,1,201,0,6,82,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,217,0,6,190,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,
79,0,0,3,135,0,4,256,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight. (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/11/04              Cody Chan
*/

#include <stdio.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "CustomerGroupPromoList.h"
#include "common.h"
#include "utilitys.h"
char    cDebug;

void CustomerGroupPromoList(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRec)
{
        char            *csPtr;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

                /* varchar         hv_from_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_from_group;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_merchant_id = -1;
                short           ind_customer_tag = -1;
                short           ind_from_group = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        if(GetField_CString(hRec,"merchant_id",&csPtr))
        {
                hv_merchant_id.len = strlen(csPtr);
                strncpy((char*)hv_merchant_id.arr, csPtr, hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

/* customer_tag */
        if(GetField_CString(hRec,"customer_tag",&csPtr))
        {
                hv_customer_tag.len = strlen(csPtr);
                strncpy((char*)hv_customer_tag.arr, csPtr, hv_customer_tag.len);
                ind_customer_tag = 0;
DEBUGLOG(("Add:customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));
        }


/* from group */
        if(GetField_CString(hRec,"from_group",&csPtr))
        {
                hv_from_group.len = strlen(csPtr);
                strncpy((char*)hv_from_group.arr, csPtr, hv_from_group.len);
                ind_from_group = 0;
DEBUGLOG(("Add:from_group = [%.*s]\n",hv_from_group.len,hv_from_group.arr));
        }

/* create user */
        if(GetField_CString(hRec,"create_user",&csPtr))
        {
                hv_create_user.len = strlen(csPtr);
                strncpy((char*)hv_create_user.arr, csPtr, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_customer_grp_pmlist_insert(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_customer_tag:ind_customer_tag,
                                :hv_from_group:ind_from_group,
                                :hv_create_user:ind_create_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_customer_grp_pmlist_ins\
ert ( :hv_merchant_id:ind_merchant_id , :hv_customer_tag:ind_customer_tag , :\
hv_from_group:ind_from_group , :hv_create_user:ind_create_user ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_tag;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_customer_tag;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_from_group;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_from_group;
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
        if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("CustomerGroupPromoList_Add: SP_OTHER_ERR \n");
DEBUGLOG(("Add: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }


        if (hv_return_value == SP_ERR)  {
ERRLOG("CustomerGroupPromoList_Add: SP_ERR \n");
DEBUGLOG(("Add: SP_ERR \n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int UpdatePromteCustomer(const hash_t *hRec)
{
        char            *csPtr;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

                /* varchar         hv_to_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_to_group;

                /* varchar         hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;

                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


                short           ind_merchant_id = -1;
                short           ind_customer_tag = -1;
                short           ind_to_group = -1;
                short           ind_date = -1;
                short           ind_update_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        if(GetField_CString(hRec,"merchant_id",&csPtr))
        {
                hv_merchant_id.len = strlen(csPtr);
                strncpy((char*)hv_merchant_id.arr, csPtr, hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("UpdatePromteCustomer:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

/* customer_tag */
        if(GetField_CString(hRec,"customer_tag",&csPtr))
        {
                hv_customer_tag.len = strlen(csPtr);
                strncpy((char*)hv_customer_tag.arr, csPtr, hv_customer_tag.len);
                ind_customer_tag = 0;
DEBUGLOG(("UpdatePromteCustomer:customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));
        }

/* to group */
        if(GetField_CString(hRec,"to_customer_group",&csPtr))
        {
                hv_to_group.len = strlen(csPtr);
                strncpy((char*)hv_to_group.arr, csPtr, hv_to_group.len);
                ind_to_group = 0;
DEBUGLOG(("UpdatePromteCustomer:to_group = [%.*s]\n",hv_to_group.len,hv_to_group.arr));
        }

/* date */
        if(GetField_CString(hRec,"date",&csPtr))
        {
                hv_date.len = strlen(csPtr);
                strncpy((char*)hv_date.arr, csPtr, hv_date.len);
                ind_date= 0;
DEBUGLOG(("UpdatePromteCustomer:date = [%.*s]\n",hv_date.len,hv_date.arr));
        }

/* update_user */
        if(GetField_CString(hRec,"update_user",&csPtr))
        {
                hv_update_user.len = strlen(csPtr);
                strncpy((char*)hv_update_user.arr, csPtr, hv_update_user.len);
                ind_update_user= 0;
DEBUGLOG(("UpdatePromteCustomer:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        }

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_customer_grp_pmlist_update(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_customer_tag:ind_customer_tag,
                                :hv_to_group:ind_to_group,
                                :hv_date:ind_date,
                                :hv_update_user:ind_update_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_customer_grp_pmlist_upd\
ate ( :hv_merchant_id:ind_merchant_id , :hv_customer_tag:ind_customer_tag , :\
hv_to_group:ind_to_group , :hv_date:ind_date , :hv_update_user:ind_update_use\
r ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_tag;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_customer_tag;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_group;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_to_group;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_date;
        sqlstm.sqhstl[4] = (unsigned long )10;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_date;
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
        if (sqlca.sqlcode < 0) goto update_error;
}




DEBUGLOG(("UpdatePromteCustomer:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdatePromteCustomer:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("CustomerGroupPromoList_UpdatePromteCustomer: SP_OTHER_ERR \n");
DEBUGLOG(("UpdatePromteCustomer: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }


        if (hv_return_value == SP_ERR)  {
ERRLOG("CustomerGroupPromoList_UpdatePromteCustomer: SP_ERR \n");
DEBUGLOG(("UpdatePromteCustomer: SP_ERR \n"));
                return PD_ERR;
        }

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}

int FindPromoCustomer(const char* csMerchantId,
		const char* csCustomerTag)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO match_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;


		int	v_cnt;
                short   ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("FindPromoCustomer: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr)); 

        hv_customer_tag.len = strlen(csCustomerTag);
        memcpy(hv_customer_tag.arr,csCustomerTag,hv_customer_tag.len);
DEBUGLOG(("FindPromoCustomer: Customer Tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr)); 

        /* EXEC SQL
		SELECT count(1) 
		INTO  :v_cnt:ind_cnt
                FROM CUSTOMER_GROUP_PROMO_LIST
                WHERE CGL_MERCHANT_ID = :hv_merchant_id
		  AND CGL_CUST_ID = :hv_customer_tag
		  AND CGL_PROMOTED = 'N'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM CUSTOMER_GROUP_P\
ROMO_LIST WHERE CGL_MERCHANT_ID = :b2 AND CGL_CUST_ID = :b3 AND CGL_PROMOTED \
= 'N' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )79;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_tag;
        sqlstm.sqhstl[2] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto match_error;
}



        if (ind_cnt < 0) 
		v_cnt = 0;

	if(v_cnt >0){
DEBUGLOG(("FindPromoCustomer: customer[%s][%s] found\n",hv_merchant_id.arr,hv_customer_tag.arr));
		return FOUND;
	}

DEBUGLOG(("FindPromoCustomer:Not Found\n"));
        return NOT_FOUND;

match_error:
DEBUGLOG(("match_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}
