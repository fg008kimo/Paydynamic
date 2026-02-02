
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "CustomerGroupRules.pc"
};


static unsigned int sqlctx = 157713987;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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

 static char *sq0007 = 
"SELECT CGR_FROM_GROUP_CODE FROM CUSTOMER_GROUP_RULES WHERE CGR_MERCHANT_ID \
= :b0 AND CGR_FROM_GROUP_CODE is not null AND CGR_DISABLED = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,138,0,4,55,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
28,0,0,2,326,0,6,172,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,2,9,0,0,
79,0,0,3,360,0,6,317,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,9,0,0,
134,0,0,0,0,0,56,404,0,0,1,1,0,1,0,3,102,0,0,
153,0,0,4,150,0,6,405,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
184,0,0,0,0,0,13,419,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
207,0,0,5,167,0,4,480,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
234,0,0,6,131,0,4,536,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
261,0,0,7,149,0,9,592,0,2049,1,1,0,1,0,1,9,0,0,
280,0,0,7,0,0,13,594,0,0,1,0,0,1,0,2,9,0,0,
299,0,0,7,0,0,15,612,0,0,0,0,0,1,0,
314,0,0,7,0,0,15,622,0,0,0,0,0,1,0,
};


/*
Partnerdelight. (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/11              Cody Chan
Input pre-selected group list to PickGroup	   2013/09/12		   LokMan Chow
Add function GetAllPromoteSegment		   2016/11/01		   LokMan Chow
Add function 
	- IsPromoteGroup		
	- IsCurrentGroup 
	- GetFromGroup
Update function
	- FindGroupCnt				   2017/11/24              Elvis Wong
*/

#include <stdio.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "CustomerGroupRules.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
char    cDebug;

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode
#define MY_DELIMITER ","

void CustomerGroupRules(char    cdebug)
{
        cDebug = cdebug;
}


int FindGroupCnt(const char* csMerchantId)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		short	v_cnt;
                short   ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("FindGroupCnt: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr)); 

        /* EXEC SQL SELECT count(*)
                    INTO :v_cnt:ind_cnt
                FROM CUSTOMER_GROUP_RULES
                WHERE CGR_MERCHANT_ID = :hv_merchant_id
		  AND CGR_FROM_GROUP_CODE is null
		  AND CGR_DISABLED = 0; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0:b1 FROM CUSTOMER_GROUP_R\
ULES WHERE CGR_MERCHANT_ID = :b2 AND CGR_FROM_GROUP_CODE is null AND CGR_DISA\
BLED = 0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
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



        if (ind_cnt >= 0) {
		if (v_cnt > 0) { 
DEBUGLOG(("FindGroupCnt: Found [%d]\n",v_cnt));
                	return FOUND;
		}
		else {
DEBUGLOG(("FindGroupCnt:Not Found\n"));
			return NOT_FOUND;
		}
        }
DEBUGLOG(("FindGroupCnt:Not Found\n"));
        return NOT_FOUND;
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

int PickGroup(const char* csMerchantId,	
		const char* csCountryId,
		const char* csChannelCode,
		const char* csServiceCode,
		const char* csCurrencyId,
		const char* csDate,
		const hash_t* hTxn,
		char*	csCustomerGroup)
{
	int	iRet = NOT_FOUND;
	int	i = 0;
	int	iCnt = 0;
	char	*csTmp;
	char	csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO pickgroup_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_currency_id[PD_CURRENCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;

                /* varchar hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;

                /* varchar hv_group_list[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_group_list;


		/* varchar	v_customer_group[PD_CUSTOMER_GROUP_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_group;

                short   ind_customer_group = -1;

		short	ind_merchant_id = -1;
		short	ind_country_id = -1;
		short	ind_channel_code = -1;
		short	ind_service_code = -1;
		short	ind_currency_id = -1;
		short	ind_date = -1;
		short	ind_group_list = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("PickGroup: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr)); 
	ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("PickGroup: country_id  = [%.*s]\n",hv_country_id.len,hv_country_id.arr)); 
	ind_country_id = 0;

        hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("PickGroup: channel_code  = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr)); 
	ind_channel_code = 0;

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("PickGroup: service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr)); 
	ind_service_code = 0;

        hv_currency_id.len = strlen(csCurrencyId);
        memcpy(hv_currency_id.arr,csCurrencyId,hv_currency_id.len);
DEBUGLOG(("PickGroup: currency_id  = [%.*s]\n",hv_currency_id.len,hv_currency_id.arr)); 
	ind_currency_id = 0;

        hv_date.len = strlen(csDate);
        memcpy(hv_date.arr,csDate,hv_date.len);
DEBUGLOG(("PickGroup: date = [%.*s]\n",hv_date.len,hv_date.arr)); 
	ind_date = 0;

	if(GetField_Int(hTxn,"group_cnt",&iCnt)){
DEBUGLOG(("PickGroup: group_cnt = [%d]\n",iCnt)); 
	}

	hv_group_list.arr[0]='\0';

	for (i=0; i<iCnt; i++){
		sprintf(csTag,"customer_group_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
DEBUGLOG(("PickGroup: customer_group[%d] = [%s]\n",i,csTmp)); 
			if(i>0) strcat((char*)hv_group_list.arr,MY_DELIMITER);
			strcat((char*)hv_group_list.arr,csTmp);
			hv_group_list.len = strlen((char*)hv_group_list.arr);
		}
		ind_group_list = 0;
	}
DEBUGLOG(("PickGroup: group_list = [%.*s]\n",hv_group_list.len,hv_group_list.arr)); 


	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_customer_group_pickgroup(
						:hv_merchant_id:ind_merchant_id,
						:hv_country_id:ind_country_id,
						:hv_channel_code:ind_channel_code,
						:hv_service_code:ind_service_code,
						:hv_currency_id:ind_currency_id,
						:hv_date:ind_date,
						:hv_group_list:ind_group_list,
						:v_customer_group:ind_customer_group);
		END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_customer_group_pickgroup ( :hv\
_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_channel_co\
de:ind_channel_code , :hv_service_code:ind_service_code , :hv_currency_id:ind\
_currency_id , :hv_date:ind_date , :hv_group_list:ind_group_list , :v_custome\
r_group:ind_customer_group ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )28;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_channel_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_currency_id;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_currency_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_group_list;
 sqlstm.sqhstl[7] = (unsigned long )258;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_group_list;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&v_customer_group;
 sqlstm.sqhstl[8] = (unsigned long )13;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_customer_group;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto pickgroup_error;
}



	if (hv_return_value == SP_OK) {
		if (ind_customer_group >= 0) {
			v_customer_group.arr[v_customer_group.len] = '\0';
			strcpy(csCustomerGroup,(const char*)v_customer_group.arr);
DEBUGLOG(("PickGroup: customer group [%s] found\n",v_customer_group.arr));
			iRet = FOUND;
		}

	}
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("CustomerGroupRules_PickGroup: SP_OTHER_ERR\n");
DEBUGLOG(("PickGroup: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("CustomerGroupRules_PickGroup: SP_ERR\n");
DEBUGLOG(("PickGroup: SP_ERR\n"));
                return PD_ERR;
        }

DEBUGLOG(("PickGroup :iRet = [%d]\n",iRet));
        return iRet;

pickgroup_error:
DEBUGLOG(("pickgroup_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int PickPromoteGroup(const char* csMerchantId,	
		const char* csCountryId,
		const char* csChannelCode,
		const char* csServiceCode,
		const char* csCurrencyId,
		const char* csDate,
		const char* csFromGroup,
		const hash_t* hTxn,
		char*	csCustomerGroup)
{
	int	iRet = NOT_FOUND;
	int	i = 0;
	int	iCnt = 0;
	char	*csTmp;
	char	csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO pickpmgroup_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_currency_id[PD_CURRENCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;

                /* varchar hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;

		/* varchar	hv_from_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_from_group;

                /* varchar hv_group_list[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_group_list;


		/* varchar	v_customer_group[PD_CUSTOMER_GROUP_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_group;

                short   ind_customer_group = -1;

		short	ind_merchant_id = -1;
		short	ind_country_id = -1;
		short	ind_channel_code = -1;
		short	ind_service_code = -1;
		short	ind_currency_id = -1;
		short	ind_date = -1;
		short	ind_from_group = -1;
		short	ind_group_list = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("PickPromoteGroup: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr)); 
	ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("PickPromoteGroup: country_id  = [%.*s]\n",hv_country_id.len,hv_country_id.arr)); 
	ind_country_id = 0;

        hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("PickPromoteGroup: channel_code  = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr)); 
	ind_channel_code = 0;

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("PickPromoteGroup: service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr)); 
	ind_service_code = 0;

        hv_currency_id.len = strlen(csCurrencyId);
        memcpy(hv_currency_id.arr,csCurrencyId,hv_currency_id.len);
DEBUGLOG(("PickPromoteGroup: currency_id  = [%.*s]\n",hv_currency_id.len,hv_currency_id.arr)); 
	ind_currency_id = 0;

        hv_date.len = strlen(csDate);
        memcpy(hv_date.arr,csDate,hv_date.len);
DEBUGLOG(("PickPromoteGroup: date = [%.*s]\n",hv_date.len,hv_date.arr)); 
	ind_date = 0;

        hv_from_group.len = strlen(csFromGroup);
        memcpy(hv_from_group.arr,csFromGroup,hv_from_group.len);
DEBUGLOG(("PickPromoteGroup: from_group = [%.*s]\n",hv_from_group.len,hv_from_group.arr)); 
	ind_from_group = 0;

	if(GetField_Int(hTxn,"group_cnt",&iCnt)){
DEBUGLOG(("PickPromoteGroup: group_cnt = [%d]\n",iCnt)); 
	}

	hv_group_list.arr[0]='\0';

	for (i=0; i<iCnt; i++){
		sprintf(csTag,"customer_group_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
DEBUGLOG(("PickPromoteGroup: customer_group[%d] = [%s]\n",i,csTmp)); 
			if(i>0) strcat((char*)hv_group_list.arr,MY_DELIMITER);
			strcat((char*)hv_group_list.arr,csTmp);
			hv_group_list.len = strlen((char*)hv_group_list.arr);
		}
		ind_group_list = 0;
	}
DEBUGLOG(("PickPromoteGroup: group_list = [%.*s]\n",hv_group_list.len,hv_group_list.arr)); 


	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_customer_group_pickpmgroup(
						:hv_merchant_id:ind_merchant_id,
						:hv_country_id:ind_country_id,
						:hv_channel_code:ind_channel_code,
						:hv_service_code:ind_service_code,
						:hv_currency_id:ind_currency_id,
						:hv_date:ind_date,
						:hv_from_group:ind_from_group,
						:hv_group_list:ind_group_list,
						:v_customer_group:ind_customer_group);
		END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_customer_group_pickpmgroup ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_channel_\
code:ind_channel_code , :hv_service_code:ind_service_code , :hv_currency_id:i\
nd_currency_id , :hv_date:ind_date , :hv_from_group:ind_from_group , :hv_grou\
p_list:ind_group_list , :v_customer_group:ind_customer_group ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )79;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_channel_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_currency_id;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_currency_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_from_group;
 sqlstm.sqhstl[7] = (unsigned long )12;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_from_group;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_group_list;
 sqlstm.sqhstl[8] = (unsigned long )258;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_group_list;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&v_customer_group;
 sqlstm.sqhstl[9] = (unsigned long )13;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_customer_group;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto pickpmgroup_error;
}



	if (hv_return_value == SP_OK) {
		if (ind_customer_group >= 0) {
			v_customer_group.arr[v_customer_group.len] = '\0';
			strcpy(csCustomerGroup,(const char*)v_customer_group.arr);
DEBUGLOG(("PickPromoteGroup: customer group [%s] found\n",csCustomerGroup));
			iRet = FOUND;
		}

	}
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("CustomerGroupRules_PickPromoteGroup: SP_OTHER_ERR\n");
DEBUGLOG(("PickPromoteGroup: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("CustomerGroupRules_PickPromoteGroup: SP_ERR\n");
DEBUGLOG(("PickPromoteGroup: SP_ERR\n"));
                return PD_ERR;
        }

DEBUGLOG(("PickPromoteGroup :iRet = [%d]\n",iRet));
        return iRet;

pickpmgroup_error:
DEBUGLOG(("pickpmgroup_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int GetAllPromoteSegment(const char* csMerchantId,
                     const char* csCustomerGroup,
                     hash_t * hTxn)
{
        int iRet = PD_OK;
        int iCnt = 0;
        char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getproseg_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;


                /* varchar v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


                short   hv_return_value;

                short   ind_merchant_id = -1;
                short   ind_customer_group = -1;

                short   ind_group = -1;

                SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("GetAllPromoteSegment: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* customer_group */
        hv_customer_group.len = strlen(csCustomerGroup);
        memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
        ind_customer_group = 0;
DEBUGLOG(("GetAllPromoteSegment: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));

        /* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )134;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getproseg_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_getall_promote_segment(:hv_merchant_id:ind_merchant_id,
                                                                  :hv_customer_group:ind_customer_group,
                                                                  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_getall_promote_segment \
( :hv_merchant_id:ind_merchant_id , :hv_customer_group:ind_customer_group , :\
c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )153;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_customer_group;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getproseg_error;
}



        PutField_Int(hTxn,"group_cnt",iCnt);
        if (hv_return_value == 0 ) {
                for (;;) {
                        ind_group = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO
                                :v_group:ind_group; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 10;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )184;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
                        sqlstm.sqhstl[1] = (unsigned long )13;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_group;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getproseg_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

                        if (ind_group>= 0) {
                                v_group.arr[v_group.len] = '\0';
DEBUGLOG(("GetAllPromoteSegment: [%03d]group = [%s]\n",iCnt,v_group.arr));
                                sprintf(csTag,"customer_group_%d",iCnt);
                                PutField_CString(hTxn,csTag,(const char*)v_group.arr);
                        }

                        iCnt++;
                        PutField_Int(hTxn,"group_cnt",iCnt);
                }
        }
        else{
                iRet = PD_ERR;
DEBUGLOG(("GetAllPromoteSegment  Failed!!!\n"));
        }

DEBUGLOG(("GetAllPromoteSegment: Finished iRet = [%d]\n",iRet));
        return iRet;

getproseg_error:
DEBUGLOG(("getproseg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int IsPromoteGroup(const char* csMerchantId,
		   const char* csCustomerGroup)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO ispromotegrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;


                short   v_cnt;

                short   ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);	
DEBUGLOG(("IsPromoteGroup: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* customer_group */
        hv_customer_group.len = strlen(csCustomerGroup);
        memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
DEBUGLOG(("IsPromoteGroup: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));

        /* EXEC SQL SELECT count(*)
                    INTO :v_cnt:ind_cnt
                FROM CUSTOMER_GROUP_RULES
                WHERE CGR_MERCHANT_ID = :hv_merchant_id
		  AND CGR_GROUP_CODE = :hv_customer_group
                  AND CGR_FROM_GROUP_CODE is not null
		  AND CGR_DISABLED = 0; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0:b1 FROM CUSTOMER_GROUP_R\
ULES WHERE CGR_MERCHANT_ID = :b2 AND CGR_GROUP_CODE = :b3 AND CGR_FROM_GROUP_\
CODE is not null AND CGR_DISABLED = 0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )207;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_group;
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
        if (sqlca.sqlcode < 0) goto ispromotegrp_error;
}



        if (ind_cnt >= 0) {
                if (v_cnt > 0) {
DEBUGLOG(("IsPromoteGroup: Found [%d]\n",v_cnt));
                        return FOUND;
                }
                else {
DEBUGLOG(("IsPromoteGroup:Not Found\n"));
                        return NOT_FOUND;
                }
        }

DEBUGLOG(("IsPromoteGroup:Not Found\n"));
        return NOT_FOUND;

ispromotegrp_error:
DEBUGLOG(("ispromotegrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int IsCurrentGroup(const char* csMerchantId,
		   const char* csCustomerGroup)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO ismobgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;


                short   v_cnt;

                short   ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);	
DEBUGLOG(("IsCurrentGroup: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* customer_group */
        hv_customer_group.len = strlen(csCustomerGroup);
        memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
DEBUGLOG(("IsCurrentGroup: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));

        /* EXEC SQL SELECT count(*)
                    INTO :v_cnt:ind_cnt
                FROM CUSTOMER_GROUP_RULES
                WHERE CGR_MERCHANT_ID = :hv_merchant_id
		  AND CGR_GROUP_CODE = :hv_customer_group
		  AND CGR_DISABLED = 0; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0:b1 FROM CUSTOMER_GROUP_R\
ULES WHERE CGR_MERCHANT_ID = :b2 AND CGR_GROUP_CODE = :b3 AND CGR_DISABLED = \
0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )234;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_group;
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
        if (sqlca.sqlcode < 0) goto ismobgrp_error;
}

	

        if (ind_cnt >= 0) {
                if (v_cnt > 0) {
DEBUGLOG(("IsCurrentGroup: Found [%d]\n",v_cnt));
                        return FOUND;
                }
                else {
DEBUGLOG(("IsCurrentGroup:Not Found\n"));
                        return NOT_FOUND;
                }
        }

DEBUGLOG(("IsCurrentGroup:Not Found\n"));
        return NOT_FOUND;

ismobgrp_error:
DEBUGLOG(("ismobgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int GetFromGroup(const char* csMerchantId,
		 char* csCustomerGroup)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getfrgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		/* varchar v_from_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_from_group;


                short   ind_from_group = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetFromGroup: merchant ID = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL DECLARE c_cursor_getfrgrp CURSOR FOR
        	 SELECT CGR_FROM_GROUP_CODE
                 FROM CUSTOMER_GROUP_RULES
                 WHERE CGR_MERCHANT_ID = :hv_merchant_id
                 AND CGR_FROM_GROUP_CODE is not null
                 AND CGR_DISABLED = 0; */ 


	/* EXEC SQL OPEN c_cursor_getfrgrp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )261;
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
 if (sqlca.sqlcode < 0) goto getfrgrp_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_getfrgrp
                INTO
                        :v_from_group:ind_from_group; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )280;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_from_group;
                sqlstm.sqhstl[0] = (unsigned long )12;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_from_group;
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
                if (sqlca.sqlcode < 0) goto getfrgrp_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* from_group */
	        if (ind_from_group >= 0) {
			v_from_group.arr[v_from_group.len] = '\0';
			strcpy(csCustomerGroup,(const char*)v_from_group.arr);
DEBUGLOG(("GetFromGroup: from_group = [%s] found \n", v_from_group.arr));
        	        return FOUND;
        	}
	}
        while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getfrgrp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )299;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getfrgrp_error;
}



DEBUGLOG(("GetFromGroup:Not Found\n"));
        return NOT_FOUND;

getfrgrp_error:
DEBUGLOG(("getfrgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("CustomerGroupRules_GetFromGroup: SP_INTERNAL_ERR\n");
   	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

  	/* EXEC SQL CLOSE c_cursor_getfrgrp; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 10;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )314;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return NOT_FOUND;
}
