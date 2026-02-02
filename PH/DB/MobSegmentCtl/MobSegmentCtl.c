
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
    "MobSegmentCtl.pc"
};


static unsigned int sqlctx = 4989083;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,17,165,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,166,0,0,0,0,0,1,0,
39,0,0,2,160,0,6,235,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/08/24              LokMan Chow
Add GetControl                                     2016/12/01              LokMan Chow
Fallback:Remove GetControl			   2016/12/19		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "MobSegmentCtl.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

int AddCtlHistory(const hash_t *hRls);

void MobSegmentCtl(char    cdebug)
{
        cDebug = cdebug;
}

/*
int GetThreshold(const char* csGroup,
                 hash_t * hTxn)
{
	int iRet = PD_NOT_FOUND;

        EXEC SQL WHENEVER SQLERROR GOTO getthreshold_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

		varchar	hv_group[PD_CUSTOMER_GROUP_CODE_LEN];

		varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1];
		int	v_cust_cnt;
		int	v_exceed_cnt;
		double	v_amt_limit;
		int	v_exceed_amt;

		short	ind_group = -1;
		short	ind_cust_cnt = -1;
		short	ind_exceed_cnt = -1;
		short	ind_amt_limit = -1;
		short	ind_exceed_amt = -1;

        EXEC SQL END DECLARE SECTION;

// group 
	hv_group.len = strlen(csGroup);
	memcpy(hv_group.arr,csGroup,hv_group.len);
DEBUGLOG(("GetThreshold: group = [%.*s]\n",hv_group.len,hv_group.arr));


        EXEC SQL 
		SELECT	msc_cust_cnt,
			msc_is_exceed_cnt,
			msc_amt_limit,
			msc_is_exceed_amt,
			msc_group
		INTO	:v_cust_cnt:ind_cust_cnt,
			:v_exceed_cnt:ind_exceed_cnt,
			:v_amt_limit:ind_amt_limit,
			:v_exceed_amt:ind_exceed_amt,
			:v_group:ind_group
		FROM	mob_segment_threshold
		WHERE	msc_group = :hv_group;

	if(ind_group>=0){

		if(ind_cust_cnt<0)
			v_cust_cnt = 0;
		PutField_Int(hTxn,"cust_cnt",v_cust_cnt);
DEBUGLOG(("GetThreshold: cust_cnt = [%d]\n",v_cust_cnt));

		if(ind_exceed_cnt<0)
			v_exceed_cnt = 0;
		PutField_Int(hTxn,"is_exceed_cnt",v_exceed_cnt);
DEBUGLOG(("GetThreshold: is_exceed_cnt = [%d]\n",v_exceed_cnt));

		if(ind_amt_limit<0)
			v_amt_limit = 0.0;
		PutField_Double(hTxn,"amt_limit",v_amt_limit);
DEBUGLOG(("GetThreshold: amt_limit = [%lf]\n",v_amt_limit));

		if(ind_exceed_amt<0)
			v_exceed_amt = 0;
		PutField_Int(hTxn,"is_exceed_amt",v_exceed_amt);
DEBUGLOG(("GetThreshold: is_exceed_amt = [%d]\n",v_exceed_amt));

		iRet = PD_FOUND;
	}

DEBUGLOG(("GetThreshold: Finished iRet = [%d]\n",iRet));
	return iRet;

getthreshold_error:
DEBUGLOG(("getthreshold_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    return PD_ERR;
}
*/


int Update(const char* csGroup,const hash_t *hRls)
{
	int	iRet = PD_OK;
        char*   csTmp;
        int     iTmp;
        char*   csBuf;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update mob_segment_ctl set msc_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: group = [%s]\n",csGroup));

/* enable_new_cust */
        if (GetField_Int(hRls,"enable_new_cust",&iTmp)) {
DEBUGLOG(("Update:enable_new_cust = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",msc_enable_new_cust = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",msc_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE msc_group = '");
        strcat((char *)hv_dynstmt.arr, csGroup);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
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
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

//Add control history
	iRet = AddCtlHistory(hRls);

DEBUGLOG(("Update Normal Exit [%d]\n",iRet));
        return iRet;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MobSegmentCtl_Update: SP_INTERNAL_ERR \n");
DEBUGLOG(("Update: SP_INTERNAL_ERR \n"));
        return INT_ERR;
}


int AddCtlHistory(const hash_t *hRls)
{
	char	*csPtr;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_group;

		int		hv_enable_new_cust;
		/* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short           ind_group = -1;
		short           ind_enable_new_cust = -1;
		short           ind_update_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


/* group */
	if(GetField_CString(hRls,"group",&csPtr)){
		hv_group.len = strlen(csPtr);
		strncpy((char*)hv_group.arr, csPtr, hv_group.len);
		ind_group = 0;
	}
	else{
		hv_group.len = strlen("000");
		strncpy((char*)hv_group.arr, "000", hv_group.len);
		ind_group = 0;
	}
DEBUGLOG(("AddCtlHistory:group = [%.*s]\n",hv_group.len,hv_group.arr));

/* enable_new_cust */
	if (GetField_Int(hRls,"enable_new_cust",&iTmp)) {
		hv_enable_new_cust = iTmp;
		ind_enable_new_cust = 0;
DEBUGLOG(("AddCtlHistory:enable_new_cust = [%d]\n",hv_enable_new_cust));
	}

/* update user */
	if(GetField_CString(hRls,"update_user",&csPtr)){
		hv_update_user.len = strlen(csPtr);
		strncpy((char*)hv_update_user.arr, csPtr, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("AddCtlHistory:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}


	/* EXEC SQL EXECUTE
		BEGIN

		:hv_return_value := sp_mob_seg_ctl_hist_insert(
					:hv_group:ind_group,
					:hv_enable_new_cust:ind_enable_new_cust,
					:hv_update_user:ind_update_user);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mob_seg_ctl_hist_insert ( :hv_\
group:ind_group , :hv_enable_new_cust:ind_enable_new_cust , :hv_update_user:i\
nd_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_group;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_group;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_enable_new_cust;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_enable_new_cust;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




DEBUGLOG(("AddCtlHistory:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("AddCtlHistory:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MobSegmentCtl_AddCtlHistory: SP_OTHER_ERR \n");
DEBUGLOG(("AddCtlHistory: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }


        if (hv_return_value == SP_ERR)  {
ERRLOG("MobSegmentCtl_AddCtlHistory: SP_ERR \n");
DEBUGLOG(("AddCtlHistory: SP_ERR \n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

