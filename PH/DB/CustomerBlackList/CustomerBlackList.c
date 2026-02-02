
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "CustomerBlackList.pc"
};


static unsigned int sqlctx = 78827531;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
5,0,0,1,212,0,4,65,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
32,0,0,2,90,0,4,110,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
55,0,0,3,194,0,6,194,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/04/06              [MSN]
Add GetMerchBlklstCtl(),			   2021/07/28		   [ANC]
	MerchBlklstCtlAdd(),
	CustBlklstAdd()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "CustomerBlackList.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void CustomerBlackList(char    cdebug)
{
        cDebug = cdebug;
}


int IsBlacklisted(const unsigned char* csMerchantId,
		  const unsigned char* csCustomerTag)
{
	int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO blacklist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

	
		int	v_cnt;

                short   ind_merchant_id = -1;
                short   ind_customer_tag= -1;
                short   ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen((const char*)csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("IsBlacklisted: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        ind_merchant_id = 0;

	hv_customer_tag.len = strlen((const char*)csCustomerTag);
        memcpy(hv_customer_tag.arr,csCustomerTag,hv_customer_tag.len);
DEBUGLOG(("IsBlacklisted: customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));
        ind_customer_tag = 0;


	/* EXEC SQL SELECT count(1)
		INTO	:v_cnt:ind_cnt
		FROM	CUSTOMER_BLACK_LIST, MERCH_BLACKLIST_CTL
		WHERE	UR_MERCHANT_ID = :hv_merchant_id
		AND	UR_CHECK_BLACKLIST = 1
		AND	CBL_MERCHANT_ID = UR_MERCHANT_ID
		AND	CBL_CUST_ID = :hv_customer_tag
		AND	CBL_DISABLED = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM CUSTOMER_BLACK_LIST , M\
ERCH_BLACKLIST_CTL WHERE UR_MERCHANT_ID = :b2 AND UR_CHECK_BLACKLIST = 1 AND \
CBL_MERCHANT_ID = UR_MERCHANT_ID AND CBL_CUST_ID = :b3 AND CBL_DISABLED = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 if (sqlca.sqlcode < 0) goto blacklist_error;
}



	if(ind_cnt<0)
		v_cnt = 0;

	if(v_cnt>0){
		iRet = PD_TRUE;
	}

DEBUGLOG(("IsBlacklisted = [%d]\n",iRet));
	return iRet;

blacklist_error:
DEBUGLOG(("blacklist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    	return PD_FALSE;
}

int GetMerchBlklstCtl(const unsigned char* csMerchantId)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO getblacklistctl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

	
		int	v_checkblklst;
        short   ind_checkblklst = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


		hv_merchant_id.len = strlen((const char*)csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetMerchBlklstCtl: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


	/* EXEC SQL SELECT UR_CHECK_BLACKLIST
		INTO	:v_checkblklst:ind_checkblklst
		FROM	MERCH_BLACKLIST_CTL
		WHERE	UR_MERCHANT_ID = :hv_merchant_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select UR_CHECK_BLACKLIST INTO :b0:b1 FROM MERCH_BLACKLIST_\
CTL WHERE UR_MERCHANT_ID = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )32;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_checkblklst;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_checkblklst;
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
 if (sqlca.sqlcode < 0) goto getblacklistctl_error;
}



        if (ind_checkblklst>= 0) {
DEBUGLOG(("GetMerchBlklstCtl: Ctl [%d]\n",v_checkblklst));
			return v_checkblklst;
        }
DEBUGLOG(("GetMerchBlklstCtl:Not Found\n"));
			return PD_NOT_FOUND;

getblacklistctl_error:
DEBUGLOG(("getblacklistctl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    	return NOT_FOUND;
}


int CustBlklstAdd(const hash_t *hRec)
{
	char            *csTmp;
	int				iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO custblklstadd_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_customer_tag[PD_CUSTOM_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_customer_tag;

		int			hv_disabled;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_merchant_id = -1;
		short		ind_customer_tag = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
		
		short       hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Cust Blacklist Add: Begin\n"));


	if(GetField_CString(hRec,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char*)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
	}
DEBUGLOG(("Cust Blacklist Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


	if(GetField_CString(hRec,"customer_tag",&csTmp))
	{
		hv_customer_tag.len = strlen(csTmp);
		strncpy((char*)hv_customer_tag.arr, csTmp, hv_customer_tag.len);
		ind_customer_tag = 0;
	}
DEBUGLOG(("Cust Blacklist Add:customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));


	if(GetField_Int(hRec,"disabled",&iTmp))
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Cust Blacklist Add:disabled = [%d]\n",hv_disabled));


	if(GetField_CString(hRec,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Cust Blacklist Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_customer_blklist_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_customer_tag:ind_customer_tag,
				:hv_disabled:ind_disabled,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_customer_blklist_insert ( :hv_\
merchant_id:ind_merchant_id , :hv_customer_tag:ind_customer_tag , :hv_disable\
d:ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
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
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_customer_tag;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto custblklstadd_error;
}




	DEBUGLOG(("Cust Blacklist Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Merch Blacklist Ctl Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("Cust Blacklist Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Cust Blacklist Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("Cust Blacklist Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Cust Blacklist Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

custblklstadd_error:
	DEBUGLOG(("custblklstadd_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}
