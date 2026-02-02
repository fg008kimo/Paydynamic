
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
    "OLBankAccts.pc"
};


static unsigned int sqlctx = 1236499;


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
   unsigned char  *sqhstv[28];
   unsigned long  sqhstl[28];
            int   sqhsts[28];
            short *sqindv[28];
            int   sqinds[28];
   unsigned long  sqharm[28];
   unsigned long  *sqharc[28];
   unsigned short  sqadto[28];
   unsigned short  sqtdso[28];
} sqlstm = {12,28};

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

 static char *sq0002 = 
"select ob_bank_acct_num , ob_bank_acct_name , ob_bank_acct_short_name , ob_\
acct_ccy , ob_shared_acct , to_char ( ob_received_datetime , 'YYYYMMDDHH24MIS\
S' ) , ob_received_by , ob_support_sms_stmt , ob_registered_mobile , ob_statu\
s_type , ob_init_provider_id , ob_owner_id , ob_owner_name , ob_branch_code ,\
 ob_branch_name , ob_swift_code , ob_province , ob_city , ob_remark , ob_sys_\
switch_enabled , ob_acct_type , ob_is_virtual , ob_bank_acct_source , ob_sub_\
provider , ob_bank_acct_short_name_seq , to_char ( ob_key_expired_datetime , \
'YYYYMMDDHH24MISS' ) from ol_bank_accts where ob_int_bank_code = :b0 and ob_b\
ank_acct_num = :b1            ";

 static char *sq0019 = 
"select ob_bank_acct_num , ob_bank_acct_name , ob_bank_acct_short_name , ob_\
acct_ccy , ob_shared_acct , to_char ( ob_received_datetime , 'YYYYMMDDHH24MIS\
S' ) , ob_received_by , ob_support_sms_stmt , ob_registered_mobile , ob_statu\
s_type , ob_init_provider_id , ob_owner_id , ob_owner_name , ob_branch_code ,\
 ob_branch_name , ob_swift_code , ob_province , ob_city , ob_remark , ob_sys_\
switch_enabled , ob_acct_type , ob_is_virtual , ob_bank_acct_source , ob_sub_\
provider , ob_bank_acct_short_name_seq , to_char ( ob_key_expired_datetime , \
'YYYYMMDDHH24MISS' ) from ol_bank_accts where ob_int_bank_code = :b0 and ( ( \
ob_bank_acct_num = :b1 ) or ( ob_acct_type = 'DSI' and ( ob_bank_acct_num lik\
e '%' || substr ( :b1 , :b3 , :b4 ) ) ) ) order by decode ( ob_status_type , \
'A' , 0 , 'D' , 2 , 1 ) , ob_update_timestamp desc            ";

 static char *sq0021 = 
"select max ( ob_bank_acct_short_name_seq ) from ol_bank_accts where ob_int_\
bank_code = :b0            ";

 static char *sq0023 = 
"SELECT ob_int_bank_code , ob_bank_acct_num FROM ol_bank_accts WHERE ob_is_v\
irtual = :b0 AND ob_acct_ccy = :b1            ";

 static char *sq0025 = 
"ent_id , pm_status from bank_desc , \
ol_bank_accts , ol_bank_acct_id , ol_psp_detail , psp_master where ( ob_bank_\
acct_num like '%' || substr ( :b0 , - 6 , 6 ) ) and ob_int_bank_code = obai_i\
nt_bank_code and internal_bank_code = ob_int_bank_code and ob_bank_acct_num =\
 obai_bank_acct_num and obai_psp_id = opd_psp_id and opd_client_id = pm_clien\
t_id and opd_bank_acct_type = ob_acct_type and offline_support = 1 and opd_di\
sabled = 0 and pm_mode_type = 'OFL' ) b on b . ob_int_bank_code = a . ob_int_\
bank_code and b . ob_bank_acct_num = a . ob_bank_acct_num ) group by int_bank\
_code , bank_acct_num , acct_type , acct_status , acct_sys_switch_enabled , b\
aid , baid_status , psp_id , pid_status , client_id , client_status order by \
int_bank_code , bank_acct_num , acct_type , acct_status , acct_sys_switch_ena\
bled , baid , baid_status , psp_id , pid_status , client_id , client_status  \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1046,0,6,351,0,0,28,28,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,
0,1,3,0,0,1,9,0,0,1,9,0,0,
132,0,0,2,644,0,9,527,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
155,0,0,2,0,0,13,529,0,0,26,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,
9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,
0,2,9,0,0,
274,0,0,2,0,0,15,756,0,0,0,0,0,1,0,
289,0,0,2,0,0,15,766,0,0,0,0,0,1,0,
304,0,0,3,115,0,4,814,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
331,0,0,4,139,0,6,821,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
358,0,0,5,0,0,17,1111,0,0,1,1,0,1,0,1,9,0,0,
377,0,0,5,0,0,21,1113,0,0,0,0,0,1,0,
392,0,0,6,139,0,6,1115,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
419,0,0,7,137,0,4,1178,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
446,0,0,8,115,0,4,1244,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
473,0,0,9,139,0,6,1251,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
500,0,0,5,0,0,17,1298,0,0,1,1,0,1,0,1,9,0,0,
519,0,0,5,0,0,21,1299,0,0,0,0,0,1,0,
534,0,0,10,139,0,6,1301,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
561,0,0,11,138,0,4,1367,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
592,0,0,12,133,0,4,1418,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
619,0,0,13,0,0,17,1484,0,0,1,1,0,1,0,1,9,0,0,
638,0,0,13,0,0,45,1488,0,0,0,0,0,1,0,
653,0,0,13,0,0,13,1490,0,0,1,0,0,1,0,2,9,0,0,
672,0,0,13,0,0,15,1512,0,0,0,0,0,1,0,
687,0,0,13,0,0,15,1522,0,0,0,0,0,1,0,
702,0,0,14,115,0,4,1568,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
729,0,0,15,139,0,6,1575,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
756,0,0,5,0,0,17,1645,0,0,1,1,0,1,0,1,9,0,0,
775,0,0,5,0,0,21,1646,0,0,0,0,0,1,0,
790,0,0,16,139,0,6,1652,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
817,0,0,17,132,0,4,1714,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
844,0,0,18,132,0,4,1771,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
871,0,0,19,830,0,9,1923,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,
0,
906,0,0,19,0,0,13,1925,0,0,26,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,
0,0,2,9,0,0,
1025,0,0,19,0,0,15,2145,0,0,0,0,0,1,0,
1040,0,0,19,0,0,15,2155,0,0,0,0,0,1,0,
1055,0,0,20,106,0,4,2183,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
1082,0,0,21,102,0,9,2242,0,2049,1,1,0,1,0,1,9,0,0,
1101,0,0,21,0,0,13,2244,0,0,1,0,0,1,0,2,3,0,0,
1120,0,0,21,0,0,15,2268,0,0,0,0,0,1,0,
1135,0,0,21,0,0,15,2282,0,0,0,0,0,1,0,
1150,0,0,22,172,0,4,2307,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1173,0,0,23,121,0,9,2366,0,2049,2,2,0,1,0,1,3,0,0,1,9,0,0,
1196,0,0,23,0,0,13,2368,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
1219,0,0,23,0,0,15,2391,0,0,0,0,0,1,0,
1234,0,0,23,0,0,15,2400,0,0,0,0,0,1,0,
1249,0,0,24,195,0,4,2428,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
1276,0,0,25,1917,0,9,2595,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1303,0,0,25,0,0,13,2597,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1362,0,0,25,0,0,15,2700,0,0,0,0,0,1,0,
1377,0,0,25,0,0,15,2717,0,0,0,0,0,1,0,
1392,0,0,0,0,0,56,2820,0,0,1,1,0,1,0,3,102,0,0,
1411,0,0,26,214,0,6,2821,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
2,102,0,0,
1450,0,0,0,0,0,13,2859,0,0,22,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,
1553,0,0,0,0,0,15,3063,0,0,1,1,0,1,0,1,102,0,0,
1572,0,0,0,0,0,78,3064,0,0,1,1,0,1,0,3,102,0,0,
1591,0,0,0,0,0,15,3071,0,0,1,1,0,1,0,1,102,0,0,
1610,0,0,0,0,0,78,3072,0,0,1,1,0,1,0,3,102,0,0,
1629,0,0,0,0,0,56,3139,0,0,1,1,0,1,0,3,102,0,0,
1648,0,0,27,133,0,6,3140,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
1679,0,0,0,0,0,13,3171,0,0,17,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,
1762,0,0,0,0,0,15,3329,0,0,1,1,0,1,0,1,102,0,0,
1781,0,0,0,0,0,78,3330,0,0,1,1,0,1,0,3,102,0,0,
1800,0,0,0,0,0,15,3337,0,0,1,1,0,1,0,1,102,0,0,
1819,0,0,0,0,0,78,3338,0,0,1,1,0,1,0,3,102,0,0,
1838,0,0,28,319,0,4,3375,0,0,6,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,
1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/04              [STP]
Add GetDepositBanks				   2013/10/03		   [GOD]
Add system switch for GetBankAccts		   2014/01/10		   [WCS]
Add bank accts log insert                          2014/05/02              [WCS]
Add Bank nature (acct_type)		           2014/05/07              [SWK]
   which only use on create / update baid checking
Add Province handling                              2014/05/09              [SWK]
Add two new function use for sim-card-mgt	   2014/09/
Add is_virtual, bank_acct_source		   2015/01/28		   [WWK]
Add ChkDepositBankAcctsUnique		   	   2015/02/26		   [WMC]
Add ChkNotDepositBankAcctsUnique		   
Add GetDepositBankAccts
Add new fields sub_provider into functions	   2015/02/27		   [WWK]
Change ChkDepositBankAcctsUnique		   2015/02/27              [WMC]
   to ChkNumOfDepositBankAccts                 
Change ChkNotDepositBankAcctsUnique
   to ChkNumOfNotDepositBankAccts
Add GetNotDepositBankAccts			   2015/02/27              [WMC]
Add ChkBankAcctExists
Modify Update
Add new fields bank_acct_short_name_seq
Add GetLatestBankAcctsShortNameSeq
Modify GetBankAccts			   	   2015/03/09              [WMC]
Add new fields key_expired_datetime		   2015/03/12		   [WMC]
Add GetBankAcctTypeByTxnId			   2015/05/11		   [WMC]
Add GetVirtualBankAcctsByCcy			   2016/07/21		   [WWK]
    and Modify Update
Add ChkBankAcctExistsByShort			   2018/02/07		   [WMC]
Add GetBankAcctsDetailByShort		   	   2018/07/18		   [WMC]
Update GetBankAcctsDetailByShort		   2019/03/06		   [WMC]
Add Functions
        GetLastUpdBankAcctsDetails
        GetBankAcctLatestDetails                   2019/08/22              [WMC]
Change GetDepositBankAccts			   2020/06/17		   [WMC]
Add ChkNumOfSmsDepositBankAccts
Change GetDepositBankAccts			   2020/09/04              [WMC]
Reivse ChkNumOfDepositBankAccts to all digits only 2020/10/06              [MIC] 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLBankAccts.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char	cDebug;

void OLBankAccts(char	cdebug)
{
	cDebug = cdebug;
}


int Add(const	hash_t *hOLBankAcct)
{
	char    *csTmp;
	int     iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_bank_acct_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_name;

		/* varchar		hv_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_bank_acct_short_name;

		/* varchar		hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		int		hv_shared_acct;
		/* varchar		hv_received_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_received_datetime;

		/* varchar		hv_received_by[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_received_by;

		int		hv_support_sms_stmt;
		/* varchar		hv_registered_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_registered_mobile;

		/* varchar		hv_status_type[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status_type;

		/* varchar		hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_owner_id[PD_OWNER_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_owner_id;

		/* varchar		hv_owner_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_owner_name;

		/* varchar		hv_branch_code[PD_BRANCH_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_branch_code;

		/* varchar		hv_branch_name[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_branch_name;

		/* varchar		hv_swift_code[PD_SWIFT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_swift_code;

		/* varchar		hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

		/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

                /* varchar		hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar		hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_province;
 
		int		hv_is_virtual;
		/* varchar		hv_bank_acct_source[PD_BANK_ACCT_SOURCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_source;

		/* varchar		hv_sub_provider[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_sub_provider;

		int		hv_bank_acct_short_name_seq;
		/* varchar		hv_key_expired_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_key_expired_datetime;


		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_bank_acct_name = -1;
		short		ind_bank_acct_short_name = -1;
		short  		ind_acct_ccy = -1;
		short		ind_shared_acct = -1;
		short		ind_received_datetime = -1;
		short		ind_received_by = -1;
		short		ind_support_sms_stmt = -1;
		short		ind_registered_mobile = -1;
		short		ind_status_type = -1;
		short		ind_provider_id = -1;
		short		ind_owner_id = -1;
		short		ind_owner_name = -1;
		short		ind_branch_code = -1;
		short		ind_branch_name = -1;
		short		ind_swift_code = -1;
		short		ind_city = -1;
		short		ind_remark = -1;
		short		ind_acct_type = -1;
                short           ind_create_user = -1;
		short		ind_province = -1;
		short		ind_is_virtual = -1;
		short		ind_bank_acct_source = -1;
		short		ind_sub_provider = -1;
		short		ind_bank_acct_short_name_seq = -1;
		short		ind_key_expired_datetime = -1;

                short           hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hOLBankAcct,"bank_code",&csTmp))
        {
                hv_int_bank_code.len = strlen(csTmp);
                strncpy((char *)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
                ind_int_bank_code = 0;
DEBUGLOG(("Add:int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
        }

        if(GetField_CString(hOLBankAcct,"new_acct_num",&csTmp))
        {
                hv_bank_acct_num.len = strlen(csTmp);
                strncpy((char *)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
                ind_bank_acct_num = 0;
DEBUGLOG(("Add:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
        }

        if(GetField_CString(hOLBankAcct,"name",&csTmp))
        {
                hv_bank_acct_name.len = strlen(csTmp);
                strncpy((char *)hv_bank_acct_name.arr, csTmp, hv_bank_acct_name.len);
                ind_bank_acct_name = 0;
DEBUGLOG(("Add:bank_acct_name = [%.*s]\n",hv_bank_acct_name.len,hv_bank_acct_name.arr));
        }

        if(GetField_CString(hOLBankAcct,"short_name",&csTmp))
        {
                hv_bank_acct_short_name.len = strlen(csTmp);
                strncpy((char *)hv_bank_acct_short_name.arr, csTmp, hv_bank_acct_short_name.len);
                ind_bank_acct_short_name = 0;
DEBUGLOG(("Add:bank_acct_short_name = [%.*s]\n",hv_bank_acct_short_name.len,hv_bank_acct_short_name.arr));
        }

        if(GetField_CString(hOLBankAcct,"ccy",&csTmp))
        {
                hv_acct_ccy.len = strlen(csTmp);
                strncpy((char *)hv_acct_ccy.arr, csTmp, hv_acct_ccy.len);
                ind_acct_ccy = 0;
DEBUGLOG(("Add:acct_ccy = [%.*s]\n",hv_acct_ccy.len,hv_acct_ccy.arr));
        }

        if (GetField_Int(hOLBankAcct,"share", &iTmp))
        {
                hv_shared_acct = iTmp;
                ind_shared_acct = 0;
DEBUGLOG(("Add:shared_acct = [%d]\n",hv_shared_acct));
        }

        if(GetField_CString(hOLBankAcct,"rec_datetime",&csTmp))
        {
                hv_received_datetime.len = strlen(csTmp);
                strncpy((char *)hv_received_datetime.arr, csTmp, hv_received_datetime.len);
                ind_received_datetime = 0;
DEBUGLOG(("Add:received_datetime = [%.*s]\n",hv_received_datetime.len,hv_received_datetime.arr));
        }

        if(GetField_CString(hOLBankAcct,"rec_by",&csTmp))
        {
                hv_received_by.len = strlen(csTmp);
                strncpy((char *)hv_received_by.arr, csTmp, hv_received_by.len);
                ind_received_by = 0;
DEBUGLOG(("Add:received_by = [%.*s]\n",hv_received_by.len,hv_received_by.arr));
        }

	if (GetField_Int(hOLBankAcct, "support_sms_stmt", &iTmp))
	{
		hv_support_sms_stmt = iTmp;
		ind_support_sms_stmt = 0;
DEBUGLOG(("Add: suppprt_sms_stmt = [%d]\n", hv_support_sms_stmt));
	}

	if(GetField_CString(hOLBankAcct,"reg_mob_num",&csTmp))
	{
		hv_registered_mobile.len = strlen(csTmp);
		strncpy((char *)hv_registered_mobile.arr, csTmp, hv_registered_mobile.len);
		ind_registered_mobile = 0;
DEBUGLOG(("Add:registered_mobile = [%.*s]\n",hv_registered_mobile.len,hv_registered_mobile.arr));
	}

        if(GetField_CString(hOLBankAcct,"status_type",&csTmp))
        {
                hv_status_type.len = strlen(csTmp);
                strncpy((char *)hv_status_type.arr, csTmp, hv_status_type.len);
                ind_status_type = 0;
DEBUGLOG(("Add:status_type = [%.*s]\n",hv_status_type.len,hv_status_type.arr));
        }

        if(GetField_CString(hOLBankAcct,"prov_id",&csTmp))
        {
                hv_provider_id.len = strlen(csTmp);
                strncpy((char *)hv_provider_id.arr, csTmp, hv_provider_id.len);
                ind_provider_id = 0;
DEBUGLOG(("Add:provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));
        }

        if(GetField_CString(hOLBankAcct,"owner_id",&csTmp))
        {
                hv_owner_id.len = strlen(csTmp);
                strncpy((char *)hv_owner_id.arr, csTmp, hv_owner_id.len);
                ind_owner_id = 0;
DEBUGLOG(("Add:owner_id = [%.*s]\n",hv_owner_id.len,hv_owner_id.arr));
        }

        if(GetField_CString(hOLBankAcct,"owner",&csTmp))
        {
                hv_owner_name.len = strlen(csTmp);
                strncpy((char *)hv_owner_name.arr, csTmp, hv_owner_name.len);
                ind_owner_name = 0;
DEBUGLOG(("Add:owner_name = [%.*s]\n",hv_owner_name.len,hv_owner_name.arr));
        }

        if(GetField_CString(hOLBankAcct,"branch_code",&csTmp))
        {
                hv_branch_code.len = strlen(csTmp);
                strncpy((char *)hv_branch_code.arr, csTmp, hv_branch_code.len);
                ind_branch_code = 0;
DEBUGLOG(("Add:branch_code = [%.*s]\n",hv_branch_code.len,hv_branch_code.arr));
        }

        if(GetField_CString(hOLBankAcct,"branch",&csTmp))
        {
                hv_branch_name.len = strlen(csTmp);
                strncpy((char *)hv_branch_name.arr, csTmp, hv_branch_name.len);
                ind_branch_name = 0;
DEBUGLOG(("Add:branch_name = [%.*s]\n",hv_branch_name.len,hv_branch_name.arr));
        }

        if(GetField_CString(hOLBankAcct,"swift_code",&csTmp))
        {
                hv_swift_code.len = strlen(csTmp);
                strncpy((char *)hv_swift_code.arr, csTmp, hv_swift_code.len);
                ind_swift_code = 0;
DEBUGLOG(("Add:swift_code = [%.*s]\n",hv_swift_code.len,hv_swift_code.arr));
        }

	if(GetField_CString(hOLBankAcct,"city",&csTmp))
	{
		hv_city.len = strlen(csTmp);
		strncpy((char *)hv_city.arr, csTmp, hv_city.len);
		ind_city = 0;
DEBUGLOG(("Add:city = [%.*s]\n",hv_city.len,hv_city.arr));
	}

        if(GetField_CString(hOLBankAcct,"remark",&csTmp))
        {
                hv_remark.len = strlen(csTmp);
                strncpy((char *)hv_remark.arr, csTmp, hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("Add:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

        if(GetField_CString(hOLBankAcct,"acct_type",&csTmp))
        {
                hv_acct_type.len = strlen(csTmp);
                strncpy((char *)hv_acct_type.arr, csTmp, hv_acct_type.len);
                ind_acct_type = 0;
DEBUGLOG(("Add:acct_type= [%.*s]\n",hv_acct_type.len,hv_acct_type.arr));
        }

        if(GetField_CString(hOLBankAcct,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

	if(GetField_CString(hOLBankAcct,"province",&csTmp))
	{
		hv_province.len = strlen(csTmp);
		strncpy((char *)hv_province.arr, csTmp, hv_province.len);
		ind_province = 0;
DEBUGLOG(("Add:province = [%.*s]\n",hv_province.len,hv_province.arr));
	}

	if (GetField_Int(hOLBankAcct, "is_virtual", &iTmp))
	{
		hv_is_virtual = iTmp;
		ind_is_virtual = 0;
DEBUGLOG(("Add: is_virtual = [%d]\n", hv_is_virtual));
	}

	if(GetField_CString(hOLBankAcct,"bank_acct_source",&csTmp))
	{
		hv_bank_acct_source.len = strlen(csTmp);
		strncpy((char *)hv_bank_acct_source.arr, csTmp, hv_bank_acct_source.len);
		ind_bank_acct_source = 0;
DEBUGLOG(("Add:bank_acct_source = [%.*s]\n",hv_bank_acct_source.len,hv_bank_acct_source.arr));
	}

	if(GetField_CString(hOLBankAcct,"sub_provider",&csTmp))
	{
		hv_sub_provider.len = strlen(csTmp);
		strncpy((char *)hv_sub_provider.arr, csTmp, hv_sub_provider.len);
		ind_sub_provider = 0;
DEBUGLOG(("Add:sub_provider = [%.*s]\n",hv_sub_provider.len,hv_sub_provider.arr));
	}
	
        if (GetField_Int(hOLBankAcct, "short_name_seq", &iTmp))
        {
                hv_bank_acct_short_name_seq = iTmp;
                ind_bank_acct_short_name_seq = 0;
DEBUGLOG(("Add: bank_acct_short_name_seq = [%d]\n", hv_bank_acct_short_name_seq));
        }

        if(GetField_CString(hOLBankAcct,"key_expired_datetime",&csTmp))
        {
                hv_key_expired_datetime.len = strlen(csTmp);
                strncpy((char *)hv_key_expired_datetime.arr, csTmp, hv_key_expired_datetime.len);
                ind_key_expired_datetime = 0;
DEBUGLOG(("Add:key_expired_datetime = [%.*s]\n",hv_key_expired_datetime.len,hv_key_expired_datetime.arr));
        }

	/* EXEC SQL EXECUTE
		BEGIN

		:hv_return_value := sp_ol_bank_acct_insert(
					:hv_int_bank_code:ind_int_bank_code,
					:hv_bank_acct_num:ind_bank_acct_num,
					:hv_bank_acct_name:ind_bank_acct_name,
					:hv_bank_acct_short_name:ind_bank_acct_short_name,
					:hv_acct_ccy:ind_acct_ccy,
					:hv_shared_acct:ind_shared_acct,
					:hv_received_datetime:ind_received_datetime,
					:hv_received_by:ind_received_by,
					:hv_support_sms_stmt:ind_support_sms_stmt,
					:hv_registered_mobile:ind_registered_mobile,
					:hv_status_type:ind_status_type,
					:hv_provider_id:ind_provider_id,
					:hv_owner_id:ind_owner_id,
					:hv_owner_name:ind_owner_name,
					:hv_branch_code:ind_branch_code,
					:hv_branch_name:ind_branch_name,
					:hv_swift_code:ind_swift_code,
					:hv_province:ind_province,
					:hv_city:ind_city,
					:hv_remark:ind_remark,
                                        :hv_acct_type:ind_acct_type,
					:hv_is_virtual:ind_is_virtual,
					:hv_bank_acct_source:ind_bank_acct_source,
					:hv_sub_provider:ind_sub_provider,
					:hv_bank_acct_short_name_seq:ind_bank_acct_short_name_seq,
					:hv_key_expired_datetime:ind_key_expired_datetime,
					:hv_create_user:ind_create_user);


		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_bank_acct_insert ( :hv_int_bank_code:ind\
_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_bank_acct_name:in\
d_bank_acct_name , :hv_bank_acct_short_name:ind_bank_acct_short_name , :hv_a\
cct_ccy:ind_acct_ccy , :hv_shared_acct:ind_shared_acct , :hv_received_dateti\
me:ind_received_datetime , :hv_received_by:ind_received_by , :hv_support_sms\
_stmt:ind_support_sms_stmt , :hv_registered_mobile:ind_registered_mobile , :\
hv_status_type:ind_status_type , :hv_provider_id:ind_provider_id , :hv_owner\
_id:ind_owner_id , :hv_owner_name:ind_owner_name , :hv_branch_code:ind_branc\
h_code , :hv_branch_name:ind_branch_name , :hv_swift_code:ind_swift_code , :\
hv_province:ind_province , :hv_city:ind_city , :hv_remark:ind_remark , :hv_a\
cct_type:ind_acct_type , :hv_is_virtual:ind_is_virtual , :hv_bank_acct_sourc\
e:ind_bank_acct_source , :hv_sub_provider:ind_sub_provider , :hv_bank_acct_s\
hort_name_seq:ind_bank_acct_short_name_seq , :hv_key_expired_datetime:ind_ke\
y_expired_datetime , :hv_create_user:ind");
 sqlstm.stmt = "_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_name;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_acct_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_short_name;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_short_name;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_acct_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_shared_acct;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_shared_acct;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_received_datetime;
 sqlstm.sqhstl[7] = (unsigned long )16;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_received_datetime;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_received_by;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_received_by;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_support_sms_stmt;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_support_sms_stmt;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_registered_mobile;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_registered_mobile;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_status_type;
 sqlstm.sqhstl[11] = (unsigned long )4;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_status_type;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[12] = (unsigned long )12;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_provider_id;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_owner_id;
 sqlstm.sqhstl[13] = (unsigned long )22;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_owner_id;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_owner_name;
 sqlstm.sqhstl[14] = (unsigned long )52;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_owner_name;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_branch_code;
 sqlstm.sqhstl[15] = (unsigned long )52;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_branch_code;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_branch_name;
 sqlstm.sqhstl[16] = (unsigned long )152;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_branch_name;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_swift_code;
 sqlstm.sqhstl[17] = (unsigned long )22;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_swift_code;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[18] = (unsigned long )102;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_province;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[19] = (unsigned long )102;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_city;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[20] = (unsigned long )257;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_remark;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[21] = (unsigned long )5;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_acct_type;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_is_virtual;
 sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_is_virtual;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_bank_acct_source;
 sqlstm.sqhstl[23] = (unsigned long )52;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_bank_acct_source;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_sub_provider;
 sqlstm.sqhstl[24] = (unsigned long )12;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_sub_provider;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_bank_acct_short_name_seq;
 sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_bank_acct_short_name_seq;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_key_expired_datetime;
 sqlstm.sqhstl[26] = (unsigned long )16;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_key_expired_datetime;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[27] = (unsigned long )22;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_create_user;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
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
		ERRLOG("OLBankAccts_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("OLBankAccts_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetBankAccts(const char *csIntBankCode,
					const char *csBankAcctNum,
					hash_t *hRec)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbankaccts_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		/* varchar		v_full_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_full_bank_acct_num;

		/* varchar		v_bank_acct_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_name;

		/* varchar		v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

		/* varchar		v_acct_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_ccy;

		int		v_shared_acct;
		/* varchar		v_received_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_received_datetime;

		/* varchar		v_received_by[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_received_by;

		int		v_support_sms_stmt;
		/* varchar		v_registered_mobile[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_registered_mobile;

		/* varchar		v_status_type[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status_type;

		/* varchar		v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

		/* varchar		v_owner_id[PD_OWNER_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_owner_id;

		/* varchar		v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar		v_branch_code[PD_BRANCH_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_branch_code;

		/* varchar		v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

		/* varchar		v_swift_code[PD_SWIFT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_swift_code;

		/* varchar		v_city[PD_CITY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		int		v_sys_switch_enabled;
                /* varchar		v_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_type;

		/* varchar		v_province[PD_PROVINCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		int		v_is_virtual;
		/* varchar		v_bank_acct_source[PD_BANK_ACCT_SOURCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_source;

		/* varchar		v_sub_provider[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_sub_provider;

		int		v_bank_acct_short_name_seq;
		/* varchar		v_key_expired_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_key_expired_datetime;



		short		ind_full_bank_acct_num = -1;
		short		ind_bank_acct_name = -1;
		short		ind_bank_acct_short_name = -1;
		short		ind_acct_ccy = -1;
		short		ind_shared_acct = -1;
		short		ind_received_datetime = -1;
		short		ind_received_by = -1;
		short		ind_support_sms_stmt = -1;
		short		ind_registered_mobile = -1;
		short		ind_status_type = -1;
		short		ind_provider_id = -1;
		short		ind_owner_id = -1;
		short		ind_owner_name = -1;
		short		ind_branch_code = -1;
		short		ind_branch_name = -1;
		short		ind_swift_code = -1;
		short		ind_city = -1;
		short		ind_remark = -1;
		short		ind_sys_switch_enabled = -1;
		short		ind_acct_type = -1;
		short		ind_province = -1;
		short		ind_is_virtual = -1;
		short		ind_bank_acct_source = -1;
		short		ind_sub_provider = -1;
		short		ind_bank_acct_short_name_seq = -1;
		short		ind_key_expired_datetime = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetBankAccts int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetBankAccts bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	/* EXEC SQL DECLARE c_cursor_getbankaccts CURSOR FOR
		select	ob_bank_acct_num,
			ob_bank_acct_name,
			ob_bank_acct_short_name,
			ob_acct_ccy,
			ob_shared_acct,
			to_char(ob_received_datetime, 'YYYYMMDDHH24MISS'),
			ob_received_by,
			ob_support_sms_stmt,
			ob_registered_mobile,
			ob_status_type,
			ob_init_provider_id,
			ob_owner_id,
			ob_owner_name,
			ob_branch_code,
			ob_branch_name,
			ob_swift_code,
			ob_province,
			ob_city,
			ob_remark,
			ob_sys_switch_enabled,
                        ob_acct_type,
			ob_is_virtual,
			ob_bank_acct_source,
			ob_sub_provider,
			ob_bank_acct_short_name_seq,
			to_char(ob_key_expired_datetime, 'YYYYMMDDHH24MISS')
		from	ol_bank_accts
		where	ob_int_bank_code = :hv_int_bank_code
/o
		and	((ob_bank_acct_num = :hv_bank_acct_num) or
			 (ob_bank_acct_num like '%' || substr(:hv_bank_acct_num, -4, 4)));
o/
		and    	ob_bank_acct_num = :hv_bank_acct_num; */ 

		
	/* EXEC SQL OPEN c_cursor_getbankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )132;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto getbankaccts_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getbankaccts
		INTO
			:v_full_bank_acct_num:ind_full_bank_acct_num,
			:v_bank_acct_name:ind_bank_acct_name,
			:v_bank_acct_short_name:ind_bank_acct_short_name,
			:v_acct_ccy:ind_acct_ccy,
			:v_shared_acct:ind_shared_acct,
			:v_received_datetime:ind_received_datetime,
			:v_received_by:ind_received_by,
			:v_support_sms_stmt:ind_support_sms_stmt,
			:v_registered_mobile:ind_registered_mobile,
			:v_status_type:ind_status_type,
			:v_provider_id:ind_provider_id,
			:v_owner_id:ind_owner_id,
			:v_owner_name:ind_owner_name,
			:v_branch_code:ind_branch_code,
			:v_branch_name:ind_branch_name,
			:v_swift_code:ind_swift_code,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_remark:ind_remark,
			:v_sys_switch_enabled:ind_sys_switch_enabled,
			:v_acct_type:ind_acct_type,
			:v_is_virtual:ind_is_virtual,
			:v_bank_acct_source:ind_bank_acct_source,
			:v_sub_provider:ind_sub_provider,
			:v_bank_acct_short_name_seq:ind_bank_acct_short_name_seq,
			:v_key_expired_datetime:ind_key_expired_datetime; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 28;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )155;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_full_bank_acct_num;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_full_bank_acct_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_acct_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_short_name;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_short_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_acct_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_acct_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_shared_acct;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_shared_acct;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_received_datetime;
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_received_datetime;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_received_by;
  sqlstm.sqhstl[6] = (unsigned long )23;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_received_by;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_support_sms_stmt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_support_sms_stmt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_registered_mobile;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_registered_mobile;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_status_type;
  sqlstm.sqhstl[9] = (unsigned long )5;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_status_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_provider_id;
  sqlstm.sqhstl[10] = (unsigned long )13;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_provider_id;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_owner_id;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_owner_id;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[12] = (unsigned long )53;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_owner_name;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_branch_code;
  sqlstm.sqhstl[13] = (unsigned long )53;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_branch_code;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[14] = (unsigned long )153;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_branch_name;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_swift_code;
  sqlstm.sqhstl[15] = (unsigned long )23;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_swift_code;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[16] = (unsigned long )103;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_province;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[17] = (unsigned long )103;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_city;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[18] = (unsigned long )258;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_remark;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_sys_switch_enabled;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_sys_switch_enabled;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_acct_type;
  sqlstm.sqhstl[20] = (unsigned long )6;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_acct_type;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_is_virtual;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_is_virtual;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_bank_acct_source;
  sqlstm.sqhstl[22] = (unsigned long )53;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_bank_acct_source;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_sub_provider;
  sqlstm.sqhstl[23] = (unsigned long )13;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_sub_provider;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_acct_short_name_seq;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_bank_acct_short_name_seq;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_key_expired_datetime;
  sqlstm.sqhstl[25] = (unsigned long )17;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_key_expired_datetime;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getbankaccts_error;
}




		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
DEBUGLOG(("GetBankAccts found record\n"));

		iRet = PD_OK;

/* Full Bank Acct Num */
		if (ind_full_bank_acct_num >= 0) {
			v_full_bank_acct_num.arr[v_full_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "full_bank_acct_num", (const char*)v_full_bank_acct_num.arr);
DEBUGLOG(("GetBankAccts full_bank_acct_num = [%s]\n", v_full_bank_acct_num.arr));
		}


/* Bank Acct Name */
		if (ind_bank_acct_name >= 0) {
			v_bank_acct_name.arr[v_bank_acct_name.len] = '\0';
			PutField_CString(hRec, "bank_acct_name", (const char*)v_bank_acct_name.arr);
DEBUGLOG(("GetBankAccts bank_acct_name = [%s]\n", v_bank_acct_name.arr));
		}

/* Bank Acct Short Name */
		if (ind_bank_acct_short_name >= 0) {
			v_bank_acct_short_name.arr[v_bank_acct_short_name.len] = '\0';
			PutField_CString(hRec, "bank_acct_short_name", (const char*)v_bank_acct_name.arr);
DEBUGLOG(("GetBankAccts bank_acct_short_name = [%s]\n", v_bank_acct_short_name.arr));
		}

/* Acct Ccy */
		if (ind_acct_ccy >= 0) {
			v_acct_ccy.arr[v_acct_ccy.len] = '\0';
			PutField_CString(hRec, "acct_ccy", (const char*)v_acct_ccy.arr);
DEBUGLOG(("GetBankAccts acct_ccy = [%s]\n", v_acct_ccy.arr));
		}

/*  Acct Type */
/*
		if (ind_acct_type >= 0) {
			v_acct_type.arr[v_acct_type.len] = '\0';
			PutField_CString(hRec, "acct_type", (const char*)v_acct_type.arr);
DEBUGLOG(("GetBankAccts acct_type = [%s]\n", v_acct_type.arr));
		}
*/

/* Shared Acct */
		if (ind_shared_acct >= 0) {
                        PutField_Int(hRec,"shared_acct", v_shared_acct);
DEBUGLOG(("GetBankAccts shared_acct = [%d]\n", v_shared_acct));
                }

/* Received DateTime */
		if (ind_received_datetime >= 0) {
			v_received_datetime.arr[v_received_datetime.len] = '\0';
			PutField_CString(hRec, "received_datetime", (const char*)v_received_datetime.arr);
DEBUGLOG(("GetBankAccts received_datetime = [%s]\n", v_received_datetime.arr));
		}

/* Received By */
		if (ind_received_by >= 0) {
			v_received_by.arr[v_received_by.len] = '\0';
			PutField_CString(hRec, "received_by", (const char*)v_received_by.arr);
DEBUGLOG(("GetBankAccts received_by = [%s]\n", v_received_by.arr));
		}

/* Support SMS Stmt */
		if (ind_support_sms_stmt >= 0) {
			PutField_Int(hRec, "support_sms_stmt", v_support_sms_stmt);
DEBUGLOG(("GetBankAccts support_sms_stmt = [%d]\n", v_support_sms_stmt));
		}


/* Registered_mobile */
		if (ind_registered_mobile >= 0) {
			v_registered_mobile.arr[v_registered_mobile.len] = '\0';
			PutField_CString(hRec, "reg_mob_num", (const char*)v_registered_mobile.arr);
DEBUGLOG(("GetBankAccts registered_mobile = [%s]\n", v_registered_mobile.arr));
		}

/* Status Type */
		if (ind_status_type >= 0) {
			v_status_type.arr[v_status_type.len] = '\0';
			PutField_CString(hRec, "status_type", (const char*)v_status_type.arr);
DEBUGLOG(("GetBankAccts status_type = [%s]\n", v_status_type.arr));
		}

/* Provider ID */
		if (ind_provider_id >= 0) {
			v_provider_id.arr[v_provider_id.len] = '\0';
			PutField_CString(hRec, "init_provider_id", (const char*)v_provider_id.arr);
DEBUGLOG(("GetBankAccts provider_id = [%s]\n", v_provider_id.arr));
		}

/* owner ID */
		if (ind_owner_id >= 0) {
			v_owner_id.arr[v_owner_id.len] = '\0';
			PutField_CString(hRec, "owner_id", (const char*)v_owner_id.arr);
DEBUGLOG(("GetBankAccts owner_id = [%s]\n", v_owner_id.arr));
		}

/* owner Name */
		if (ind_owner_name >= 0) {
			v_owner_name.arr[v_owner_name.len] = '\0';
			PutField_CString(hRec, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("GetBankAccts owner_name = [%s]\n", v_owner_name.arr));
		}

/* Branch Code */
		if (ind_branch_code >= 0) {
			v_branch_code.arr[v_branch_code.len] = '\0';
			PutField_CString(hRec, "branch_code", (const char*)v_branch_code.arr);
DEBUGLOG(("GetBankAccts branch_code = [%s]\n", v_branch_code.arr));
		}

/* Branch Name */
		if (ind_branch_name >= 0) {
			v_branch_name.arr[v_branch_name.len] = '\0';
			PutField_CString(hRec, "branch_name", (const char*)v_branch_name.arr);
DEBUGLOG(("GetBankAccts branch_name = [%s]\n", v_branch_name.arr));
		}

/* Swift Code */
		if (ind_swift_code >= 0) {
			v_swift_code.arr[v_swift_code.len] = '\0';
			PutField_CString(hRec, "swift_code", (const char*)v_swift_code.arr);
DEBUGLOG(("GetBankAccts swift_code = [%s]\n", v_swift_code.arr));
		}

/* Province */
		if (ind_province >= 0) {
			v_province.arr[v_province.len] = '\0';
			PutField_CString(hRec, "province", (const char*)v_province.arr);
DEBUGLOG(("GetBankAccts province = [%s]\n", v_province.arr));
		}

/* City */
		if (ind_city >= 0) {
			v_city.arr[v_city.len] = '\0';
			PutField_CString(hRec, "city", (const char*)v_city.arr);
DEBUGLOG(("GetBankAccts city = [%s]\n", v_city.arr));
		}

/* Remark */
		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len] = '\0';
			PutField_CString(hRec, "acct_remark", (const char*)v_remark.arr);
DEBUGLOG(("GetBankAccts remark = [%s]\n", v_remark.arr));
		}

/* Sys Switch Enabled */
                if (ind_sys_switch_enabled >= 0) {
                        PutField_Int(hRec, "sys_switch_enabled", v_sys_switch_enabled);
DEBUGLOG(("GetBankAccts sys_switch_enabled = [%d]\n", v_sys_switch_enabled));
                }

/* Acct Type*/
		if (ind_acct_type >= 0) {
			v_acct_type.arr[v_acct_type.len] = '\0';
			PutField_CString(hRec, "acct_type", (const char*)v_acct_type.arr);
DEBUGLOG(("GetBankAccts acct_type = [%s]\n", v_acct_type.arr));
		}

/* is_virtual */
		if (ind_is_virtual >= 0) {
                        PutField_Int(hRec, "is_virtual", v_is_virtual);
DEBUGLOG(("GetBankAccts is_virtual = [%d]\n", v_is_virtual));
                }

/* bank_acct_source */
		if (ind_bank_acct_source >= 0) {
			v_bank_acct_source.arr[v_bank_acct_source.len] = '\0';
			PutField_CString(hRec, "bank_acct_source", (const char*)v_bank_acct_source.arr);
DEBUGLOG(("GetBankAccts bank_acct_source = [%s]\n", v_bank_acct_source.arr));
		}

/* sub_provider */
		if (ind_sub_provider >= 0) {
			v_sub_provider.arr[v_sub_provider.len] = '\0';
			PutField_CString(hRec, "sub_provider", (const char*)v_sub_provider.arr);
DEBUGLOG(("GetBankAccts sub_provider = [%s]\n", v_sub_provider.arr));
		}

/* Bank Acct Short Name Seq */
                if (ind_bank_acct_short_name_seq >= 0) {
                        PutField_Int(hRec, "bank_acct_short_name_seq", v_bank_acct_short_name_seq);
DEBUGLOG(("GetBankAccts bank_acct_short_name_seq = [%d]\n", v_bank_acct_short_name_seq));
                }

/* Key Expired DateTime */
                if (ind_key_expired_datetime >= 0) {
                        v_key_expired_datetime.arr[v_key_expired_datetime.len] = '\0';
                        PutField_CString(hRec, "key_expired_datetime", (const char*)v_key_expired_datetime.arr);
DEBUGLOG(("GetBankAccts key_expired_datetime = [%s]\n", v_key_expired_datetime.arr));
                }

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )274;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbankaccts_error;
}



DEBUGLOG(("GetBankAccts Normal Exit [%d]\n", iRet));
        return  iRet;

getbankaccts_error:
DEBUGLOG(("getbankaccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_GetBankAccts: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )289;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int Update(const hash_t *hOLBankAcct)
{
	char* csTmp;
	char* csQTmp[1024];
	char* csBankCode;
	char* csNewAcctNum;

	int   iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


		//varchar hv_re_dynstmt[1024];

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int v_cnt;

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "update ol_bank_accts set ob_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hOLBankAcct, "bank_code", &csBankCode);
	hv_int_bank_code.len = strlen(csBankCode);
	strncpy((char*)hv_int_bank_code.arr, csBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("Update: bank_code = [%s]\n", csBankCode));

	GetField_CString(hOLBankAcct, "new_acct_num", &csNewAcctNum);
	hv_bank_acct_num.len = strlen(csNewAcctNum);
	strncpy((char*)hv_bank_acct_num.arr, csNewAcctNum, hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("Update: new_acct_num = [%s]\n", csNewAcctNum));

/* add into log */
	/* EXEC SQL SELECT count(*)
			INTO :v_cnt
			FROM ol_bank_accts_log
			WHERE obl_int_bank_code = :hv_int_bank_code:ind_int_bank_code
			AND obl_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_bank_accts_log WHERE ob\
l_int_bank_code = :b1:b2 AND obl_bank_acct_num = :b3:b4 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )304;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



	if (v_cnt == 0) {
		/* EXEC SQL EXECUTE
			BEGIN
			:hv_return_value := sp_ol_bank_accts_log_insert(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 28;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_log_insert ( :h\
v_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num ) ; E\
ND ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )331;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[2] = (unsigned long )52;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
  if (sqlca.sqlcode < 0) goto update_error;
}



		if (hv_return_value == SP_OK)
		{
DEBUGLOG(("Add Orig Log: Normal Exit\n"));
		}

		if (hv_return_value == SP_OTHER_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
			return PD_OTHER_ERR;
		}

		if (hv_return_value == SP_ERR)
		{
DEBUGLOG(("Add Orig Log: SP_ERR\n"));
			return PD_ERR;
		}
	}

/* name */
	if (GetField_CString(hOLBankAcct, "name", &csTmp)) {
DEBUGLOG(("Update: name = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_bank_acct_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* short name */
	if (GetField_CString(hOLBankAcct, "short_name", &csTmp)) {
DEBUGLOG(("Update: short_name = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_bank_acct_short_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* rec datetime */
	if (GetField_CString(hOLBankAcct, "rec_datetime", &csTmp)) {
DEBUGLOG(("Update: rec_datetime = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_received_datetime = to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* rec by */
	if (GetField_CString(hOLBankAcct, "rec_by", &csTmp)) {
DEBUGLOG(("Update: rec_by = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_received_by = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* support sms stmt */
	if (GetField_Int(hOLBankAcct, "support_sms_stmt", &iTmp)) {
DEBUGLOG(("Update: support_sms_stmt = [%d]\n", iTmp));
                sprintf(csTmp, "%d", iTmp);
			
                strcat((char*)hv_dynstmt.arr, ", ob_support_sms_stmt = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* reg mob num */
	if (GetField_CString(hOLBankAcct, "reg_mob_num", &csTmp)) {
DEBUGLOG(("Update: reg_mob_num = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_registered_mobile = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
DEBUGLOG(("Update: reg_mob_num = null\n"));
		strcat((char*)hv_dynstmt.arr, ", ob_registered_mobile = null");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* status type */
	if (GetField_CString(hOLBankAcct, "status_type", &csTmp)) {
DEBUGLOG(("Update: status_type = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_status_type = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* init_provider_id */
	if (GetField_CString(hOLBankAcct, "init_provider_id", &csTmp)) {
DEBUGLOG(("Update: init_provider_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_init_provider_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* owner id */
	if (GetField_CString(hOLBankAcct, "owner_id", &csTmp)) {
DEBUGLOG(("Update: owner_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_owner_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
DEBUGLOG(("Update: owner_id = null\n"));
		strcat((char*)hv_dynstmt.arr, ", ob_owner_id = null");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* owner */
	if (GetField_CString(hOLBankAcct, "owner", &csTmp)) {
DEBUGLOG(("Update: owner = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_owner_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* branch code */
	if (GetField_CString(hOLBankAcct, "branch_code", &csTmp)) {
DEBUGLOG(("Update: branch_code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_branch_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
DEBUGLOG(("Update: branch_code = null\n"));
		strcat((char*)hv_dynstmt.arr, ", ob_branch_code = null");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* branch */
	if (GetField_CString(hOLBankAcct, "branch", &csTmp)) {
DEBUGLOG(("Update: branch = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_branch_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* swift code */
	if (GetField_CString(hOLBankAcct, "swift_code", &csTmp)) {
DEBUGLOG(("Update: swift_code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_swift_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
DEBUGLOG(("Update: swift_code = null\n"));
		strcat((char*)hv_dynstmt.arr, ", ob_swift_code = null");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* city */
	if (GetField_CString(hOLBankAcct, "city", &csTmp)) {
DEBUGLOG(("Update: city = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_city = ");

		sprintf((char *)csQTmp, (char*)PD_Q_QUOTE_VALUE, csTmp);
DEBUGLOG(("Update: city (q_quote) = [%s]\n", csQTmp));
		csQTmp[strlen(csTmp) + PD_Q_ADD_QUOTE_LEN] = '\0';

		strcat((char*)hv_dynstmt.arr, (char*) csQTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* province */
	if (GetField_CString(hOLBankAcct, "province", &csTmp)) {
DEBUGLOG(("Update: province = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_province = ");

		sprintf((char *)csQTmp, (char*)PD_Q_QUOTE_VALUE, csTmp);
DEBUGLOG(("Update: city (q_quote) = [%s]\n", csQTmp));
		csQTmp[strlen(csTmp) + PD_Q_ADD_QUOTE_LEN] = '\0';


		strcat((char*)hv_dynstmt.arr, (char *) csQTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* remark */
	if (GetField_CString(hOLBankAcct, "remark", &csTmp)) {
DEBUGLOG(("Update: remark = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_remark = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
DEBUGLOG(("Update: remark = null\n"));
		strcat((char*)hv_dynstmt.arr, ", ob_remark = null");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* sys switch*/
	if (GetField_Int(hOLBankAcct, "sys_switch_enabled", &iTmp)) {
DEBUGLOG(("Update: sys_switch_enabled = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

		strcat((char*)hv_dynstmt.arr, ", ob_sys_switch_enabled = ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
 
/* acct_type */
	if (GetField_CString(hOLBankAcct, "acct_type", &csTmp)) {
DEBUGLOG(("Update: acct_type = [%s]\n", csTmp));
		if (!strcmp(csTmp, "NIL")) {
			strcat((char*)hv_dynstmt.arr, ", ob_acct_type = null");
                	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		} else {
			strcat((char*)hv_dynstmt.arr, ", ob_acct_type = '");
			strcat((char*)hv_dynstmt.arr, csTmp);
			strcat((char*)hv_dynstmt.arr, "'");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

/* bank_acct_source */
	if (GetField_CString(hOLBankAcct, "bank_acct_source", &csTmp)) {
DEBUGLOG(("Update: bank_acct_source = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_bank_acct_source = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* sub_provider */
	if (GetField_CString(hOLBankAcct, "sub_provider", &csTmp)) {
DEBUGLOG(("Update: sub_provider = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_sub_provider = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* short_name_seq */
        if (GetField_Int(hOLBankAcct, "short_name_seq", &iTmp)) {
DEBUGLOG(("Update: short_name_seq = [%d]\n", iTmp));
                sprintf(csTmp, "%d", iTmp);

                strcat((char*)hv_dynstmt.arr, ", ob_bank_acct_short_name_seq = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* key_expired_datetime */
        if (GetField_CString(hOLBankAcct, "key_expired_datetime", &csTmp)) {
DEBUGLOG(("Update: key_expired_datetime = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", ob_key_expired_datetime = to_date('");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS')");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* user */
	if (GetField_CString(hOLBankAcct, "update_user", &csTmp)) {
DEBUGLOG(("Update: user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE ob_int_bank_code = '");
	strcat((char*)hv_dynstmt.arr, csBankCode);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, " AND ob_bank_acct_num = '");
	strcat((char*)hv_dynstmt.arr, csNewAcctNum);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

/*
	sprintf((char *)hv_re_dynstmt.arr, "%s%s%s", "q'^", (char*)hv_dynstmt.arr, "^'");
	hv_re_dynstmt.len = strlen((const char*)hv_re_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_re_dynstmt.len, hv_re_dynstmt.arr));
*/

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )358;
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


	/*EXEC SQL PREPARE PS FROM :hv_re_dynstmt;*/
	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )377;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
		:hv_return_value := sp_ol_bank_accts_log_insert(
					:hv_int_bank_code:ind_int_bank_code,
					:hv_bank_acct_num:ind_bank_acct_num);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_log_insert ( :hv\
_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num ) ; EN\
D ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )392;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Update: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
		DEBUGLOG(("Update: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
		DEBUGLOG(("Update: SP_ERR\n"));
		return PD_ERR;
	}

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLBankAccts_Update: SP_INTERNAL_ERR TxnAbort\n");
	//TxnAbort();
	return PD_INTERNAL_ERR;
}

int ChkBankAcctsUnique(const char *csIntBankCode,
                        const char *csBankAcctNum)
{
	int	iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkbankacctunique_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		int		v_no_of_record;
		short		ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkBankAcctsUnique int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkBankAcctsUnique bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	/* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM ol_bank_accts
		WHERE ob_int_bank_code = :hv_int_bank_code
		AND ob_bank_acct_num like '%' || substr(:hv_bank_acct_num, -4, 4); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts WHERE ob_\
int_bank_code = :b2 AND ob_bank_acct_num like '%' || substr ( :b3 , - 4 , 4 )\
 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )419;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto chkbankacctunique_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("ChkBankAcctsUnique FOUND\n"));
			iRet = PD_FOUND;
		}
	}

	if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkBankAcctsUnique NOT FOUND\n"));
	}

        return iRet;

chkbankacctunique_error:
DEBUGLOG(("ChkBankAcctsUnique_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


	return PD_ERR;
}

int UpdateStatus(const hash_t *hOLBankAcct)
{
	char	*csBankCode;
	char	*csAcctNum;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int v_cnt;

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateStatus: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "update ol_bank_accts set ob_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hOLBankAcct, "bank_code", &csBankCode);
	hv_int_bank_code.len = strlen(csBankCode);
	strncpy((char*)hv_int_bank_code.arr, csBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("UpdateStatus: bank_code = [%s]\n", csBankCode));

	GetField_CString(hOLBankAcct, "new_acct_num", &csAcctNum);
	hv_bank_acct_num.len = strlen(csAcctNum);
	strncpy((char*)hv_bank_acct_num.arr, csAcctNum, hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("UpdateStatus: new_acct_num = [%s]\n", csAcctNum));

/* add into log */
	/* EXEC SQL SELECT count(*)
			INTO :v_cnt
			FROM ol_bank_accts_log
			WHERE obl_int_bank_code = :hv_int_bank_code:ind_int_bank_code
			AND obl_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_bank_accts_log WHERE ob\
l_int_bank_code = :b1:b2 AND obl_bank_acct_num = :b3:b4 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )446;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}



	if (v_cnt == 0) {
		/* EXEC SQL EXECUTE
			BEGIN
			:hv_return_value := sp_ol_bank_accts_log_insert(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 28;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_log_insert ( :h\
v_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num ) ; E\
ND ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )473;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[2] = (unsigned long )52;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
  if (sqlca.sqlcode < 0) goto updatestatus_error;
}



		if (hv_return_value == SP_OK)
		{
			DEBUGLOG(("Add Orig Log: Normal Exit\n"));
		}

		if (hv_return_value == SP_OTHER_ERR)
		{
			DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
			return PD_OTHER_ERR;
		}

		if (hv_return_value == SP_ERR)
		{
			DEBUGLOG(("Add Orig Log: SP_ERR\n"));
			return PD_ERR;
		}
	}

/* status type */
	if (GetField_CString(hOLBankAcct, "status_type", &csTmp)) {
DEBUGLOG(("UpdateStatus: status_type = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_status_type = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE ob_int_bank_code = '");
	strcat((char*)hv_dynstmt.arr, csBankCode);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, " AND ob_bank_acct_num = '");
	strcat((char*)hv_dynstmt.arr, csAcctNum);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )500;
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
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )519;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
		:hv_return_value := sp_ol_bank_accts_log_insert(
					:hv_int_bank_code:ind_int_bank_code,
					:hv_bank_acct_num:ind_bank_acct_num);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_log_insert ( :hv\
_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num ) ; EN\
D ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )534;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}



	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("UpdateStatus: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
		DEBUGLOG(("UpdateStatus: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
		DEBUGLOG(("UpdateStatus: SP_ERR\n"));
		return PD_ERR;
	}

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLBankAccts_UpdateStatus: SP_INTERNAL_ERR TxnAbort\n");
        return PD_INTERNAL_ERR;
}


int ChkMobileNumByBank(const char *csIntBankCode,
			const char* csBankAcctNum,
                        const char *csMobileNum)
{
	int     iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkmobilenumbybank_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar         hv_mobile_num[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile_num;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkMobileNumByBank int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkMobileNumByBank bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

        hv_mobile_num.len = strlen(csMobileNum);
        memcpy(hv_mobile_num.arr, csMobileNum, hv_mobile_num.len);
DEBUGLOG(("ChkMobileNumByBank mobile_num = [%.*s]\n", hv_mobile_num.len, hv_mobile_num.arr));

        /* EXEC SQL
                SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM ol_bank_accts
                WHERE ob_int_bank_code = :hv_int_bank_code
		AND ob_bank_acct_num !=  :hv_bank_acct_num
                AND ob_registered_mobile = :hv_mobile_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts WH\
ERE ob_int_bank_code = :b2 AND ob_bank_acct_num != :b3 AND ob_registered_mobi\
le = :b4 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )561;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_mobile_num;
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
        if (sqlca.sqlcode < 0) goto chkmobilenumbybank_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("ChkMobileNumByBank FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkMobileNumByBank NOT FOUND\n"));
        }

        return iRet;

chkmobilenumbybank_error:
DEBUGLOG(("ChkMobileNumByBank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int ChkMobileNum(const char *csMobileNum, const char *csBankAcctNum)
{
	int     iRet = NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkmobilenum_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_mobile_num[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_mobile_num;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		int	v_no_of_record;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_mobile_num.len = strlen(csMobileNum);
	memcpy(hv_mobile_num.arr, csMobileNum, hv_mobile_num.len);
DEBUGLOG(("ChkMobileNum mobile_num = [%.*s]\n", hv_mobile_num.len, hv_mobile_num.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkMobileNumByBank bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	/* EXEC SQL SELECT count(1)
		INTO :v_no_of_record
		FROM ol_bank_accts
		WHERE ob_registered_mobile = :hv_mobile_num
		AND ob_bank_acct_num !=  :hv_bank_acct_num
		AND ob_status_type = 'A'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_bank_accts WHERE ob_reg\
istered_mobile = :b1 AND ob_bank_acct_num != :b2 AND ob_status_type = 'A' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )592;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_mobile_num;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto chkmobilenum_error;
}



	if (v_no_of_record > 0) {
DEBUGLOG(("ChkMobileNum FOUND\n"));
		iRet = FOUND;
	} else {
DEBUGLOG(("ChkMobileNum NOT FOUND\n"));
		iRet = NOT_FOUND;
	}

	return iRet;

chkmobilenum_error:
DEBUGLOG(("ChkMobileNum_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetDepositBanks(const char* csCountryId,
		const char* csTxnCcy,
		recordset_t* myRec)
{
        int     iRet = PD_ERR;
	hash_t	*myHash;
	char*   csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdepositbanks_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;



		short		ind_int_bank_code;
	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"SELECT ob_int_bank_code");
        strcat((char*)hv_dynstmt.arr," FROM ol_bank_accts, def_bank");
        strcat((char*)hv_dynstmt.arr," WHERE db_country  = '");
        strcat((char*)hv_dynstmt.arr,csCountryId);
        strcat((char*)hv_dynstmt.arr,"'");
        strcat((char*)hv_dynstmt.arr," AND ob_acct_ccy  = '");
        strcat((char*)hv_dynstmt.arr,csTxnCcy);
        strcat((char*)hv_dynstmt.arr,"'");
        strcat((char*)hv_dynstmt.arr," AND ob_int_bank_code = db_int_bank_code");
        //strcat((char*)hv_dynstmt.arr," AND ob_acct_type = 'DSI'");
        strcat((char*)hv_dynstmt.arr," AND SP_OL_GET_BANK_ACCT_TYPE (ob_int_bank_code,ob_bank_acct_num) = 'DSI'");
        strcat((char*)hv_dynstmt.arr," AND ob_status_type = 'A'");
        strcat((char*)hv_dynstmt.arr," GROUP by ob_int_bank_code ");

	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);


DEBUGLOG(("[%s]\n",hv_dynstmt.arr));

	FREE_ME(csBuf);
	/* EXEC SQL PREPARE s1 FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )619;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto getdepositbanks_error;
}


	/* EXEC SQL DECLARE c_cursor_getdepositbanks CURSOR FOR s1; */ 



	/* EXEC SQL OPEN c_cursor_getdepositbanks; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )638;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositbanks_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdepositbanks
                INTO
			:v_int_bank_code:ind_int_bank_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 28;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )653;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
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
                if (sqlca.sqlcode < 0) goto getdepositbanks_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iRet = PD_OK;

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

		if (ind_int_bank_code >= 0 ) {
			v_int_bank_code.arr[v_int_bank_code.len] ='\0';
DEBUGLOG(("GetDepositBanks bank code = [%s]\n",v_int_bank_code.arr))
                        PutField_CString(myHash,"int_bank_code",(const char*)v_int_bank_code.arr);
		}

		RecordSet_Add(myRec,myHash);
	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdepositbanks; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )672;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdepositbanks_error;
}




DEBUGLOG(("GetDepositBanks noraml return iRet = [%d]\n",iRet));
	return iRet;
getdepositbanks_error:
DEBUGLOG(("getbankaccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_Getdepositbanks: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdepositbanks; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )687;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdateMobileNum(hash_t *hContext)
{
//	char cAction;
	char* csBankCode;
	char* csBankAcct;
	char* csMobile;
	char* csUpdateUser;

	/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

	/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

	int v_cnt;

	short ind_int_bank_code = -1;
	short ind_bank_acct_num = -1;
	short hv_return_value;

	/* EXEC SQL WHENEVER SQLERROR GOTO associatemobilenum_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


/*Primary Key: bank_code*/
	if (GetField_CString(hContext, "bank_code", &csBankCode)) {
DEBUGLOG(("UpdateMobileNum:bank_code = [%s]\n",csBankCode));
		hv_int_bank_code.len = strlen(csBankCode);
		strncpy((char*)hv_int_bank_code.arr, csBankCode, hv_int_bank_code.len);
		ind_int_bank_code = 0;
	}

/*Primary Key: bank_acct*/
	if (GetField_CString(hContext, "bank_acct", &csBankAcct)) {
DEBUGLOG(("UpdateMobileNum:bank_acct = [%s]\n",csBankAcct));
		hv_bank_acct_num.len = strlen(csBankAcct);
		strncpy((char*)hv_bank_acct_num.arr, csBankAcct, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
	}

/* add into log */
        /* EXEC SQL SELECT count(*)
                        INTO :v_cnt
                        FROM ol_bank_accts_log
                        WHERE obl_int_bank_code = :hv_int_bank_code:ind_int_bank_code
                        AND obl_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_bank_accts_log W\
HERE obl_int_bank_code = :b1:b2 AND obl_bank_acct_num = :b3:b4 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )702;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
        if (sqlca.sqlcode < 0) goto associatemobilenum_error;
}



        if (v_cnt == 0) {
                /* EXEC SQL EXECUTE
                        BEGIN
                        :hv_return_value := sp_ol_bank_accts_log_insert(
                                                :hv_int_bank_code:ind_int_bank_code,
                                                :hv_bank_acct_num:ind_bank_acct_num);
                        END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 28;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_l\
og_insert ( :hv_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_\
acct_num ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )729;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
                sqlstm.sqhstl[2] = (unsigned long )52;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
                if (sqlca.sqlcode < 0) goto associatemobilenum_error;
}



                if (hv_return_value == SP_OK)
                {
DEBUGLOG(("Add Orig Log: Normal Exit\n"));
                }

                if (hv_return_value == SP_OTHER_ERR)
                {
DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
                        return PD_OTHER_ERR;
                }

                if (hv_return_value == SP_ERR)
                {
DEBUGLOG(("Add Orig Log: SP_ERR\n"));
                        return PD_ERR;
                }
        }

/* action */
/*
	if(GetField_Char(hContext, "action", &cAction)) {
DEBUGLOG(("UpdateMobileNum: action = [%c]\n", cAction));
	}
*/

DEBUGLOG(("AssociateMobileNum Begin\n"));
	strcpy((char*)hv_dynstmt.arr, "update ol_bank_accts set ob_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* mobile_num */
	if (GetField_CString(hContext, "mobile", &csMobile)) {
DEBUGLOG(("UpdateMobileNum:mobile_num = [%s]\n",csMobile));
		strcat((char*)hv_dynstmt.arr, ", ob_registered_mobile = '");
		strcat((char*)hv_dynstmt.arr, csMobile);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
		strcat((char*)hv_dynstmt.arr, ", ob_registered_mobile = NULL");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update_user */
	if (GetField_CString(hContext, "update_user", &csUpdateUser)) {
DEBUGLOG(("UpdateMobileNum:update_user = [%s]\n",csUpdateUser));
		strcat((char*)hv_dynstmt.arr, ",ob_update_user = '");
		strcat((char*)hv_dynstmt.arr, csUpdateUser);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE ob_int_bank_code = '");
	strcat((char*)hv_dynstmt.arr, csBankCode);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, " AND ob_bank_acct_num = '");
	strcat((char*)hv_dynstmt.arr, csBankAcct);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )756;
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
 if (sqlca.sqlcode < 0) goto associatemobilenum_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )775;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto associatemobilenum_error;
}



DEBUGLOG(("UpdateMobileNum success\n"));


/*Update bank accts log*/
        /* EXEC SQL EXECUTE
                BEGIN
                :hv_return_value := sp_ol_bank_accts_log_insert(
                                        :hv_int_bank_code:ind_int_bank_code,
                                        :hv_bank_acct_num:ind_bank_acct_num);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_accts_log_inser\
t ( :hv_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num\
 ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )790;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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
        if (sqlca.sqlcode < 0) goto associatemobilenum_error;
}



        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("UpdateStatus: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)
        {
                DEBUGLOG(("UpdateStatus: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)
        {
                DEBUGLOG(("UpdateStatus: SP_ERR\n"));
                return PD_ERR;
        }

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

associatemobilenum_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLSimCards:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int ChkNumOfDepositBankAccts(const char *csIntBankCode,
                        const char *csBankAcctNum)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chknumofdepositbankacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkNumOfDepositBankAccts int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        hv_bank_acct_num.len = strlen(csBankAcctNum);
        memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkNumOfDepositBankAccts bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

        /* EXEC SQL
                SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM ol_bank_accts
                WHERE ob_int_bank_code = :hv_int_bank_code
		AND ob_bank_acct_num = :hv_bank_acct_num
		AND ob_status_type != 'D'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts WH\
ERE ob_int_bank_code = :b2 AND ob_bank_acct_num = :b3 AND ob_status_type != '\
D' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )817;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto chknumofdepositbankacct_error;
}

	
	
        if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
               		iRet = v_no_of_record;
DEBUGLOG(("ChkNumOfDepositBankAccts no_of_record = [%d]\n", v_no_of_record));
		}
        }

        if (iRet <= 0) {
DEBUGLOG(("ChkNumOfDepositBankAccts Not FOUND\n"));
        } else if (iRet == 1) {
DEBUGLOG(("ChkNumOfDepositBankAccts Unique FOUND\n"));
	} else if (iRet > 1) {
DEBUGLOG(("ChkNumOfDepositBankAccts Duplicate FOUND\n"));
	}

        return iRet;

chknumofdepositbankacct_error:
DEBUGLOG(("ChkNumOfDepositBankAccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;
}

int ChkNumOfNotDepositBankAccts(const char *csIntBankCode,
                        const char *csBankAcctNum)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chknumofnotdepositbankacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkNumOfNotDepositBankAccts int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        hv_bank_acct_num.len = strlen(csBankAcctNum);
        memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkNumOfNotDepositBankAccts bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

        /* EXEC SQL
                SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM ol_bank_accts
                WHERE ob_int_bank_code = :hv_int_bank_code
                AND ob_bank_acct_num = :hv_bank_acct_num
		AND ob_status_type != 'D'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts WH\
ERE ob_int_bank_code = :b2 AND ob_bank_acct_num = :b3 AND ob_status_type != '\
D' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )844;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto chknumofnotdepositbankacct_error;
}

	

        if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
               		iRet = v_no_of_record;
DEBUGLOG(("ChkNumOfNotDepositBankAccts no_of_record = [%d]\n", v_no_of_record));
		}
        }

        if (iRet <= 0) {
DEBUGLOG(("ChkNumOfNotDepositBankAccts Not FOUND\n"));
        } else if (iRet == 1) {
DEBUGLOG(("ChkNumOfNotDepositBankAccts Unique FOUND\n"));
        } else if (iRet > 1) {
DEBUGLOG(("ChkNumOfNotDepositBankAccts Duplicate FOUND\n"));
        }

        return iRet;

chknumofnotdepositbankacct_error:
DEBUGLOG(("ChkNumOfNotDepositBankAccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;
}

int GetDepositBankAccts(const char *csIntBankCode,
					const char *csBankAcctNum,
					int iBankAcctNumLen,
					hash_t *hRec)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositbankaccts_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int		hv_bank_acct_num_pos;
		int		hv_bank_acct_num_len;

		/* varchar		v_full_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_full_bank_acct_num;

		/* varchar		v_bank_acct_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_name;

		/* varchar		v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

		/* varchar		v_acct_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_ccy;

		int		v_shared_acct;
		/* varchar		v_received_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_received_datetime;

		/* varchar		v_received_by[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_received_by;

		int		v_support_sms_stmt;
		/* varchar		v_registered_mobile[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_registered_mobile;

		/* varchar		v_status_type[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status_type;

		/* varchar		v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

		/* varchar		v_owner_id[PD_OWNER_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_owner_id;

		/* varchar		v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar		v_branch_code[PD_BRANCH_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_branch_code;

		/* varchar		v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

		/* varchar		v_swift_code[PD_SWIFT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_swift_code;

		/* varchar		v_city[PD_CITY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		int		v_sys_switch_enabled;
                /* varchar		v_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_type;

		/* varchar		v_province[PD_PROVINCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		int		v_is_virtual;
		/* varchar		v_bank_acct_source[PD_BANK_ACCT_SOURCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_source;

		/* varchar		v_sub_provider[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_sub_provider;

		int		v_bank_acct_short_name_seq;
		/* varchar		v_key_expired_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_key_expired_datetime;



		short		ind_full_bank_acct_num = -1;
		short		ind_bank_acct_name = -1;
		short		ind_bank_acct_short_name = -1;
		short		ind_acct_ccy = -1;
		short		ind_shared_acct = -1;
		short		ind_received_datetime = -1;
		short		ind_received_by = -1;
		short		ind_support_sms_stmt = -1;
		short		ind_registered_mobile = -1;
		short		ind_status_type = -1;
		short		ind_provider_id = -1;
		short		ind_owner_id = -1;
		short		ind_owner_name = -1;
		short		ind_branch_code = -1;
		short		ind_branch_name = -1;
		short		ind_swift_code = -1;
		short		ind_city = -1;
		short		ind_remark = -1;
		short		ind_sys_switch_enabled = -1;
		short		ind_acct_type = -1;
		short		ind_province = -1;
		short		ind_is_virtual = -1;
		short		ind_bank_acct_source = -1;
		short		ind_sub_provider = -1;
		short		ind_bank_acct_short_name_seq = -1;
		short		ind_key_expired_datetime = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetDepositBankAccts int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetDepositBankAccts bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	hv_bank_acct_num_pos = (-1)*iBankAcctNumLen;
DEBUGLOG(("GetDepositBankAccts bank_acct_num_pos = [%d]\n", hv_bank_acct_num_pos));	

	hv_bank_acct_num_len = iBankAcctNumLen;
DEBUGLOG(("GetDepositBankAccts bank_acct_num_len = [%d]\n", hv_bank_acct_num_len));      

	/* EXEC SQL DECLARE c_cursor_getdepositbankaccts CURSOR FOR
		select	ob_bank_acct_num,
			ob_bank_acct_name,
			ob_bank_acct_short_name,
			ob_acct_ccy,
			ob_shared_acct,
			to_char(ob_received_datetime, 'YYYYMMDDHH24MISS'),
			ob_received_by,
			ob_support_sms_stmt,
			ob_registered_mobile,
			ob_status_type,
			ob_init_provider_id,
			ob_owner_id,
			ob_owner_name,
			ob_branch_code,
			ob_branch_name,
			ob_swift_code,
			ob_province,
			ob_city,
			ob_remark,
			ob_sys_switch_enabled,
                        ob_acct_type,
			ob_is_virtual,
			ob_bank_acct_source,
			ob_sub_provider,
			ob_bank_acct_short_name_seq,
			to_char(ob_key_expired_datetime, 'YYYYMMDDHH24MISS')
		from	ol_bank_accts
		where	ob_int_bank_code = :hv_int_bank_code
		and	((ob_bank_acct_num = :hv_bank_acct_num) or
			 (ob_acct_type = 'DSI' and (ob_bank_acct_num like '%' || substr(:hv_bank_acct_num, :hv_bank_acct_num_pos, :hv_bank_acct_num_len))))
		order by decode (ob_status_type, 'A', 0, 'D', 2, 1), ob_update_timestamp desc; */ 


	/* EXEC SQL OPEN c_cursor_getdepositbankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )871;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num_pos;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num_len;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getdepositbankaccts_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getdepositbankaccts
		INTO
			:v_full_bank_acct_num:ind_full_bank_acct_num,
			:v_bank_acct_name:ind_bank_acct_name,
			:v_bank_acct_short_name:ind_bank_acct_short_name,
			:v_acct_ccy:ind_acct_ccy,
			:v_shared_acct:ind_shared_acct,
			:v_received_datetime:ind_received_datetime,
			:v_received_by:ind_received_by,
			:v_support_sms_stmt:ind_support_sms_stmt,
			:v_registered_mobile:ind_registered_mobile,
			:v_status_type:ind_status_type,
			:v_provider_id:ind_provider_id,
			:v_owner_id:ind_owner_id,
			:v_owner_name:ind_owner_name,
			:v_branch_code:ind_branch_code,
			:v_branch_name:ind_branch_name,
			:v_swift_code:ind_swift_code,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_remark:ind_remark,
			:v_sys_switch_enabled:ind_sys_switch_enabled,
			:v_acct_type:ind_acct_type,
			:v_is_virtual:ind_is_virtual,
			:v_bank_acct_source:ind_bank_acct_source,
			:v_sub_provider:ind_sub_provider,
			:v_bank_acct_short_name_seq:ind_bank_acct_short_name_seq,
			:v_key_expired_datetime:ind_key_expired_datetime; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 28;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )906;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_full_bank_acct_num;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_full_bank_acct_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_acct_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_short_name;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_short_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_acct_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_acct_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_shared_acct;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_shared_acct;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_received_datetime;
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_received_datetime;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_received_by;
  sqlstm.sqhstl[6] = (unsigned long )23;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_received_by;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_support_sms_stmt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_support_sms_stmt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_registered_mobile;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_registered_mobile;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_status_type;
  sqlstm.sqhstl[9] = (unsigned long )5;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_status_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_provider_id;
  sqlstm.sqhstl[10] = (unsigned long )13;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_provider_id;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_owner_id;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_owner_id;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[12] = (unsigned long )53;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_owner_name;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_branch_code;
  sqlstm.sqhstl[13] = (unsigned long )53;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_branch_code;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[14] = (unsigned long )153;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_branch_name;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_swift_code;
  sqlstm.sqhstl[15] = (unsigned long )23;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_swift_code;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[16] = (unsigned long )103;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_province;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[17] = (unsigned long )103;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_city;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[18] = (unsigned long )258;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_remark;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_sys_switch_enabled;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_sys_switch_enabled;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_acct_type;
  sqlstm.sqhstl[20] = (unsigned long )6;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_acct_type;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_is_virtual;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_is_virtual;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_bank_acct_source;
  sqlstm.sqhstl[22] = (unsigned long )53;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_bank_acct_source;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_sub_provider;
  sqlstm.sqhstl[23] = (unsigned long )13;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_sub_provider;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_acct_short_name_seq;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_bank_acct_short_name_seq;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_key_expired_datetime;
  sqlstm.sqhstl[25] = (unsigned long )17;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_key_expired_datetime;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getdepositbankaccts_error;
}




		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
DEBUGLOG(("GetDepositBankAccts found record\n"));

		iRet = PD_OK;

/* Full Bank Acct Num */
		if (ind_full_bank_acct_num >= 0) {
			v_full_bank_acct_num.arr[v_full_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "full_bank_acct_num", (const char*)v_full_bank_acct_num.arr);
DEBUGLOG(("GetDepositBankAccts full_bank_acct_num = [%s]\n", v_full_bank_acct_num.arr));
		}


/* Bank Acct Name */
		if (ind_bank_acct_name >= 0) {
			v_bank_acct_name.arr[v_bank_acct_name.len] = '\0';
			PutField_CString(hRec, "bank_acct_name", (const char*)v_bank_acct_name.arr);
DEBUGLOG(("GetDepositBankAccts bank_acct_name = [%s]\n", v_bank_acct_name.arr));
		}

/* Bank Acct Short Name */
		if (ind_bank_acct_short_name >= 0) {
			v_bank_acct_short_name.arr[v_bank_acct_short_name.len] = '\0';
			PutField_CString(hRec, "bank_acct_short_name", (const char*)v_bank_acct_name.arr);
DEBUGLOG(("GetDepositBankAccts bank_acct_short_name = [%s]\n", v_bank_acct_short_name.arr));
		}

/* Acct Ccy */
		if (ind_acct_ccy >= 0) {
			v_acct_ccy.arr[v_acct_ccy.len] = '\0';
			PutField_CString(hRec, "acct_ccy", (const char*)v_acct_ccy.arr);
DEBUGLOG(("GetDepositBankAccts acct_ccy = [%s]\n", v_acct_ccy.arr));
		}

/* Shared Acct */
		if (ind_shared_acct >= 0) {
                        PutField_Int(hRec,"shared_acct", v_shared_acct);
DEBUGLOG(("GetDepositBankAccts shared_acct = [%d]\n", v_shared_acct));
                }

/* Received DateTime */
		if (ind_received_datetime >= 0) {
			v_received_datetime.arr[v_received_datetime.len] = '\0';
			PutField_CString(hRec, "received_datetime", (const char*)v_received_datetime.arr);
DEBUGLOG(("GetDepositBankAccts received_datetime = [%s]\n", v_received_datetime.arr));
		}

/* Received By */
		if (ind_received_by >= 0) {
			v_received_by.arr[v_received_by.len] = '\0';
			PutField_CString(hRec, "received_by", (const char*)v_received_by.arr);
DEBUGLOG(("GetDepositBankAccts received_by = [%s]\n", v_received_by.arr));
		}

/* Support SMS Stmt */
		if (ind_support_sms_stmt >= 0) {
			PutField_Int(hRec, "support_sms_stmt", v_support_sms_stmt);
DEBUGLOG(("GetDepositBankAccts support_sms_stmt = [%d]\n", v_support_sms_stmt));
		}


/* Registered_mobile */
		if (ind_registered_mobile >= 0) {
			v_registered_mobile.arr[v_registered_mobile.len] = '\0';
			PutField_CString(hRec, "reg_mob_num", (const char*)v_registered_mobile.arr);
DEBUGLOG(("GetDepositBankAccts registered_mobile = [%s]\n", v_registered_mobile.arr));
		}

/* Status Type */
		if (ind_status_type >= 0) {
			v_status_type.arr[v_status_type.len] = '\0';
			PutField_CString(hRec, "status_type", (const char*)v_status_type.arr);
DEBUGLOG(("GetDepositBankAccts status_type = [%s]\n", v_status_type.arr));
		}

/* Provider ID */
		if (ind_provider_id >= 0) {
			v_provider_id.arr[v_provider_id.len] = '\0';
			PutField_CString(hRec, "init_provider_id", (const char*)v_provider_id.arr);
DEBUGLOG(("GetDepositBankAccts provider_id = [%s]\n", v_provider_id.arr));
		}

/* owner ID */
		if (ind_owner_id >= 0) {
			v_owner_id.arr[v_owner_id.len] = '\0';
			PutField_CString(hRec, "owner_id", (const char*)v_owner_id.arr);
DEBUGLOG(("GetDepositBankAccts owner_id = [%s]\n", v_owner_id.arr));
		}

/* owner Name */
		if (ind_owner_name >= 0) {
			v_owner_name.arr[v_owner_name.len] = '\0';
			PutField_CString(hRec, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("GetDepositBankAccts owner_name = [%s]\n", v_owner_name.arr));
		}

/* Branch Code */
		if (ind_branch_code >= 0) {
			v_branch_code.arr[v_branch_code.len] = '\0';
			PutField_CString(hRec, "branch_code", (const char*)v_branch_code.arr);
DEBUGLOG(("GetDepositBankAccts branch_code = [%s]\n", v_branch_code.arr));
		}

/* Branch Name */
		if (ind_branch_name >= 0) {
			v_branch_name.arr[v_branch_name.len] = '\0';
			PutField_CString(hRec, "branch_name", (const char*)v_branch_name.arr);
DEBUGLOG(("GetDepositBankAccts branch_name = [%s]\n", v_branch_name.arr));
		}

/* Swift Code */
		if (ind_swift_code >= 0) {
			v_swift_code.arr[v_swift_code.len] = '\0';
			PutField_CString(hRec, "swift_code", (const char*)v_swift_code.arr);
DEBUGLOG(("GetDepositBankAccts swift_code = [%s]\n", v_swift_code.arr));
		}

/* Province */
		if (ind_province >= 0) {
			v_province.arr[v_province.len] = '\0';
			PutField_CString(hRec, "province", (const char*)v_province.arr);
DEBUGLOG(("GetDepositBankAccts province = [%s]\n", v_province.arr));
		}

/* City */
		if (ind_city >= 0) {
			v_city.arr[v_city.len] = '\0';
			PutField_CString(hRec, "city", (const char*)v_city.arr);
DEBUGLOG(("GetDepositBankAccts city = [%s]\n", v_city.arr));
		}

/* Remark */
		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len] = '\0';
			PutField_CString(hRec, "acct_remark", (const char*)v_remark.arr);
DEBUGLOG(("GetDepositBankAccts remark = [%s]\n", v_remark.arr));
		}

/* Sys Switch Enabled */
                if (ind_sys_switch_enabled >= 0) {
                        PutField_Int(hRec, "sys_switch_enabled", v_sys_switch_enabled);
DEBUGLOG(("GetDepositBankAccts sys_switch_enabled = [%d]\n", v_sys_switch_enabled));
                }

/* Acct Type */
		if (ind_acct_type >= 0) {
			v_acct_type.arr[v_acct_type.len] = '\0';
			PutField_CString(hRec, "acct_type", (const char*)v_acct_type.arr);
DEBUGLOG(("GetDepositBankAccts acct_type = [%s]\n", v_acct_type.arr));
		}

/* is_virtual */
		if (ind_is_virtual >= 0) {
                        PutField_Int(hRec, "is_virtual", v_is_virtual);
DEBUGLOG(("GetDepositBankAccts is_virtual = [%d]\n", v_is_virtual));
                }

/* bank_acct_source */
		if (ind_bank_acct_source >= 0) {
			v_bank_acct_source.arr[v_bank_acct_source.len] = '\0';
			PutField_CString(hRec, "bank_acct_source", (const char*)v_bank_acct_source.arr);
DEBUGLOG(("GetDepositBankAccts bank_acct_source = [%s]\n", v_bank_acct_source.arr));
		}

/* sub_provider */
		if (ind_sub_provider >= 0) {
			v_sub_provider.arr[v_sub_provider.len] = '\0';
			PutField_CString(hRec, "sub_provider", (const char*)v_sub_provider.arr);
DEBUGLOG(("GetDepositBankAccts bank_sub_provider = [%s]\n", v_sub_provider.arr));
		}

/* Bank Acct Short Name Seq */
                if (ind_bank_acct_short_name_seq >= 0) {
                        PutField_Int(hRec, "bank_acct_short_name_seq", v_bank_acct_short_name_seq);
DEBUGLOG(("GetDepositBankAccts bank_acct_short_name_seq = [%d]\n", v_bank_acct_short_name_seq));
                }

/* Key Expired DateTime */
                if (ind_key_expired_datetime >= 0) {
                        v_key_expired_datetime.arr[v_key_expired_datetime.len] = '\0';
                        PutField_CString(hRec, "key_expired_datetime", (const char*)v_key_expired_datetime.arr);
DEBUGLOG(("GetDepositBankAccts key_expired_datetime = [%s]\n", v_key_expired_datetime.arr));
                }

		break;

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdepositbankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1025;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositbankaccts_error;
}



DEBUGLOG(("GetDepositBankAccts Normal Exit [%d]\n", iRet));
        return  iRet;

getdepositbankaccts_error:
DEBUGLOG(("getdepositbankaccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_GetDepositBankAccts: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdepositbankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1040;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int ChkBankAcctExists(const char *csIntBankCode,
                        const char *csBankAcctNum)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkbankacctexists_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkBankAcctExists int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        hv_bank_acct_num.len = strlen(csBankAcctNum);
        memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkBankAcctExists bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

        /* EXEC SQL
                SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM ol_bank_accts
                WHERE ob_int_bank_code = :hv_int_bank_code
                AND ob_bank_acct_num = :hv_bank_acct_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts WH\
ERE ob_int_bank_code = :b2 AND ob_bank_acct_num = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1055;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto chkbankacctexists_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
                        iRet = v_no_of_record;
DEBUGLOG(("ChkBankAcctExists no_of_record = [%d]\n", v_no_of_record));
                }
        }

        if (iRet <= 0) {
DEBUGLOG(("ChkBankAcctExists NOT FOUND\n"));
        } else if (iRet == 1) {
DEBUGLOG(("ChkBankAcctExists Exists\n"));
        } else if (iRet > 1) {
DEBUGLOG(("ChkBankAcctExists Duplicated\n"));
        }

        return iRet;

chkbankacctexists_error:
DEBUGLOG(("ChkBankAcctExists_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;
}

int GetLatestBankAcctsShortNameSeq(const char *csIntBankCode,
                                        hash_t *hRec)
{
	int iRet = PD_ERR;
	int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlatestshortnameseq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;


		int             v_bank_acct_short_name_seq;
		
		short		ind_bank_acct_short_name_seq = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetLatestBankAcctsShortNameSeq int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	/* EXEC SQL DECLARE c_cursor_getlatestshortnameseq CURSOR FOR
		select  max(ob_bank_acct_short_name_seq)
		from    ol_bank_accts
                where   ob_int_bank_code = :hv_int_bank_code; */ 

		//order by ob_bank_acct_short_name_seq desc;

	/* EXEC SQL OPEN c_cursor_getlatestshortnameseq; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1082;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto getlatestshortnameseq_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_getlatestshortnameseq
                INTO
                        :v_bank_acct_short_name_seq:ind_bank_acct_short_name_seq; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 28;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1101;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_acct_short_name_seq;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_acct_short_name_seq;
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
                if (sqlca.sqlcode < 0) goto getlatestshortnameseq_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
	
		if (iCnt >= 1) {
                        break;
                }

                iCnt++;

/* Bank Acct Short Name Seq */
                if (ind_bank_acct_short_name_seq >= 0) {
                        PutField_Int(hRec, "bank_acct_short_name_seq", v_bank_acct_short_name_seq);
DEBUGLOG(("GetLatestBankAcctsShortNameSeq bank_acct_short_name_seq = [%d]\n", v_bank_acct_short_name_seq));
                } else {
DEBUGLOG(("GetLatestBankAcctsShortNameSeq bank_acct_short_name_seq = [NULL]\n"));
		}

	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getlatestshortnameseq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1120;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlatestshortnameseq_error;
}



	if (iCnt > 0 ) {
                iRet = PD_OK;
DEBUGLOG(("GetLatestBankAcctsShortNameSeq Normal Exit [%d]\n", iRet));
        }

        return  iRet;

getlatestshortnameseq_error:
DEBUGLOG(("getlatestshortnameseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_GetLatestBankAcctsShortNameSeq: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getlatestshortnameseq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1135;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetBankAcctTypeByTxnId(const char* csTxnId, char* csBankAcctType)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbankaccttypebytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;


                /* varchar         v_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_type;


                short           ind_bank_acct_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
	hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetBankAcctTypeByTxnId TxnId = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        /* EXEC SQL
                select  ob_acct_type
                into    :v_bank_acct_type:ind_bank_acct_type
                from    ol_txn_psp_detail,
                        ol_bank_accts
                where   otp_txn_id = :hv_txn_id
                and     otp_bank_code = ob_int_bank_code
		and   	otp_bank_acct_num = ob_bank_acct_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ob_acct_type into :b0:b1 from ol_txn_psp_deta\
il , ol_bank_accts where otp_txn_id = :b2 and otp_bank_code = ob_int_bank_cod\
e and otp_bank_acct_num = ob_bank_acct_num ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1150;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_acct_type;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_bank_acct_type;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )22;
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
        if (sqlca.sqlcode < 0) goto getbankaccttypebytxnid_error;
}



/* bank_acct_type */
        if (ind_bank_acct_type >= 0) {
                v_bank_acct_type.arr[v_bank_acct_type.len] = '\0';
                strcpy((char*)csBankAcctType, (const char*)v_bank_acct_type.arr);
DEBUGLOG(("bank_acct_type = [%s]\n", csBankAcctType));
                iRet = PD_FOUND;
        }

DEBUGLOG(("GetBankAcctTypeByTxnId iRet = [%d]\n", iRet));
        return iRet;

getbankaccttypebytxnid_error:
DEBUGLOG(("getbankaccttypebytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_GetBankAcctTypeByTxnId: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetVirtualBankAcctsByCcy(const char *csCcy, hash_t *hVirtualBankAcct)
{
	int iRet = PD_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getvirtualacct_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_is_virtual;
		/* varchar	hv_ccy[3+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_ccy;


		/* varchar	v_int_bank_code[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_bank_acct_num[50+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;


		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("GetVirtualBankAcctsByCcy ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

	hv_is_virtual = PD_TRUE;

	/* EXEC SQL DECLARE c_cursor_getvirtualacct CURSOR FOR
		SELECT	ob_int_bank_code,
			ob_bank_acct_num
		  FROM	ol_bank_accts
		 WHERE	ob_is_virtual = :hv_is_virtual
		   AND	ob_acct_ccy = :hv_ccy; */ 


	/* EXEC SQL OPEN c_cursor_getvirtualacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1173;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_is_virtual;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[1] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto getvirtualacct_err;
}



	/* EXEC SQL FETCH c_cursor_getvirtualacct
	INTO
		:v_int_bank_code:ind_int_bank_code,
		:v_bank_acct_num:ind_bank_acct_num; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1196;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )53;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto getvirtualacct_err;
}



		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hVirtualBankAcct, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetVirtualBankAcctsByCcy int_bank_code = [%s]\n", v_int_bank_code.arr));
		} else {
			iRet = PD_NOT_FOUND;
DEBUGLOG(("GetVirtualBankAcctsByCcy int_bank_code NOT FOUND!!!\n"));
		}

		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hVirtualBankAcct, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetVirtualBankAcctsByCcy bank_acct_num = [%s]\n",v_bank_acct_num.arr));
		} else {
			iRet = PD_NOT_FOUND;
DEBUGLOG(("GetVirtualBankAcctsByCcy bank_acct_num NOT FOUND!!!\n"));
		}

		/* EXEC SQL CLOSE c_cursor_getvirtualacct; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 28;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1219;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getvirtualacct_err;
}



DEBUGLOG(("GetVirtualBankAcctsByCcy Normal Exit iRet =[%d]\n",iRet));
		return iRet;

getvirtualacct_err:
DEBUGLOG(("getvirtualacct_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getvirtualacct; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1234;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int ChkBankAcctExistsByShort(const char *csAbbrevName,
                             const char *csShortBankAcctNum)
{
        int     iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkbankacctexistsbyshort_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_bank_abbrev_name[PD_EXT_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_abbrev_name;

                /* varchar         hv_short_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_short_bank_acct_num;


		int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_bank_abbrev_name.len = strlen(csAbbrevName);
        memcpy(hv_bank_abbrev_name.arr, csAbbrevName, hv_bank_abbrev_name.len);
DEBUGLOG(("ChkBankAcctExistsByShort hv_bank_abbrev_name = [%.*s]\n", hv_bank_abbrev_name.len, hv_bank_abbrev_name.arr));

        hv_short_bank_acct_num.len = strlen(csShortBankAcctNum);
        memcpy(hv_short_bank_acct_num.arr, csShortBankAcctNum, hv_short_bank_acct_num.len);
DEBUGLOG(("ChkBankAcctExistsByShort hv_short_bank_acct_num = [%.*s]\n", hv_short_bank_acct_num.len, hv_short_bank_acct_num.arr));

        /* EXEC SQL
		SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM 	bank_desc,
     			ol_bank_accts
                WHERE bank_abbrev_name = :hv_bank_abbrev_name
		AND (ob_bank_acct_num like '%' || substr(:hv_short_bank_acct_num, -6, 6))
                AND internal_bank_code = ob_int_bank_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM bank_desc , ol_b\
ank_accts WHERE bank_abbrev_name = :b2 AND ( ob_bank_acct_num like '%' || sub\
str ( :b3 , - 6 , 6 ) ) AND internal_bank_code = ob_int_bank_code ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1249;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_abbrev_name;
        sqlstm.sqhstl[1] = (unsigned long )52;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_short_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto chkbankacctexistsbyshort_error;
}



	if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
                        iRet = PD_FOUND;
DEBUGLOG(("ChkBankAcctExistsByShort no_of_record = [%d]\n", v_no_of_record));
                }
        }

        if (iRet == NOT_FOUND) {
DEBUGLOG(("ChkBankAcctExistsByShort NOT FOUND\n"));
        } else if (iRet == FOUND) {
DEBUGLOG(("ChkBankAcctExistsByShort FOUND\n"));
        } else {
DEBUGLOG(("ChkBankAcctExistsByShort ERROR\n"));
        }

        return iRet;

chkbankacctexistsbyshort_error:
DEBUGLOG(("ChkBankAcctExistsByShort_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;
}

int GetBankAcctsDetailByShort(const char *csAbbrevName,
		       	      const char *csShortBankAcctNum,
		       	      recordset_t* myRec)
{
	int     iRet = NOT_FOUND;
	hash_t  *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailbyshort_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_bank_abbrev_name[PD_EXT_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_abbrev_name;

		/* varchar         hv_short_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_short_bank_acct_num;


		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_type;

		/* varchar         v_status_type[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status_type;

		int             v_sys_switch_enabled;
		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

		/* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_pid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_pid_status;

		/* varchar         v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar         v_client_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_client_status;


		short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
                short           ind_acct_type = -1;
		short           ind_status_type = -1;
		short		ind_sys_switch_enabled = -1;
		short           ind_baid = -1;
		short           ind_baid_status = -1;
		short           ind_psp_id = -1;
		short           ind_pid_status = -1;
		short           ind_client_id = -1;
		short           ind_client_status = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_abbrev_name.len = strlen(csAbbrevName);
	memcpy(hv_bank_abbrev_name.arr, csAbbrevName, hv_bank_abbrev_name.len);
DEBUGLOG(("GetBankAcctsDetailByShort hv_bank_abbrev_name = [%.*s]\n", hv_bank_abbrev_name.len, hv_bank_abbrev_name.arr));

	hv_short_bank_acct_num.len = strlen(csShortBankAcctNum);
	memcpy(hv_short_bank_acct_num.arr, csShortBankAcctNum, hv_short_bank_acct_num.len);
DEBUGLOG(("GetBankAcctsDetailByShort hv_short_bank_acct_num = [%.*s]\n", hv_short_bank_acct_num.len, hv_short_bank_acct_num.arr));

	/* EXEC SQL DECLARE c_cursor_getdetailbyshort CURSOR FOR
		select 	int_bank_code,
       			bank_acct_num,
			acct_type,	
			acct_status,
                        acct_sys_switch_enabled,
			baid,
			baid_status,
			psp_id,
                        pid_status,
			client_id,
			client_status
		from	(select a.ob_int_bank_code as int_bank_code,
       				a.ob_bank_acct_num as bank_acct_num,
				a.ob_acct_type as acct_type,
				a.ob_status_type as acct_status,
				a.ob_sys_switch_enabled as acct_sys_switch_enabled,
				b.obai_baid as baid,
				b.obai_status as baid_status,
                                b.opd_psp_id as psp_id,
                                b.opd_status as pid_status,
       				b.pm_client_id as client_id,
				b.pm_status as client_status
			from	(select     ob_int_bank_code,
                                            ob_bank_acct_num,
					    ob_acct_type,
					    ob_status_type,
					    ob_sys_switch_enabled
                                from        bank_desc,
                                            ol_bank_accts
                                where       (ob_bank_acct_num like '%' || substr(:hv_short_bank_acct_num, -6, 6))
                                and         internal_bank_code = ob_int_bank_code
				and	    bank_abbrev_name = :hv_bank_abbrev_name
				and	    offline_support = 1) a
			left join   (select 	ob_int_bank_code,
                    				ob_bank_acct_num,
						ob_acct_type,
						ob_status_type,
						ob_sys_switch_enabled,
						obai_baid,
						obai_status,
						opd_psp_id,
                                                opd_status,
						pm_client_id,
                                                pm_status
            			    from 	bank_desc,
                				ol_bank_accts,
                				ol_bank_acct_id,
                				ol_psp_detail,
                				psp_master
            			    where 	(ob_bank_acct_num like '%' || substr(:hv_short_bank_acct_num, -6, 6)) 
            			    and 	ob_int_bank_code = obai_int_bank_code
            			    and 	internal_bank_code = ob_int_bank_code
            			    and 	ob_bank_acct_num = obai_bank_acct_num
            			    and 	obai_psp_id = opd_psp_id
            			    and 	opd_client_id = pm_client_id
				    and     	opd_bank_acct_type = ob_acct_type
				    and		offline_support = 1
				    and     	opd_disabled = 0
				    and     	pm_mode_type = 'OFL') b
			on b.ob_int_bank_code = a.ob_int_bank_code
			and b.ob_bank_acct_num = a.ob_bank_acct_num
			)
		group by int_bank_code,
                         bank_acct_num,
                         acct_type,
			 acct_status,
                         acct_sys_switch_enabled,
			 baid,
			 baid_status,
			 psp_id,
                         pid_status,
			 client_id,
                         client_status
		order by int_bank_code,
			 bank_acct_num,
			 acct_type,
			 acct_status,
                         acct_sys_switch_enabled,
			 baid,
			 baid_status,
			 psp_id,
                         pid_status,
			 client_id,
                         client_status; */ 


	/* EXEC SQL OPEN c_cursor_getdetailbyshort; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select int_bank_code , bank_acct_num , acct_type , acct_status , acct_sy\
s_switch_enabled , baid , baid_status , psp_id , pid_status , client_id , cl\
ient_status from ( select a . ob_int_bank_code as int_bank_code , a . ob_ban\
k_acct_num as bank_acct_num , a . ob_acct_type as acct_type , a . ob_status_\
type as acct_status , a . ob_sys_switch_enabled as acct_sys_switch_enabled ,\
 b . obai_baid as baid , b . obai_status as baid_status , b . opd_psp_id as \
psp_id , b . opd_status as pid_status , b . pm_client_id as client_id , b . \
pm_status as client_status from ( select ob_int_bank_code , ob_bank_acct_num\
 , ob_acct_type , ob_status_type , ob_sys_switch_enabled from bank_desc , ol\
_bank_accts where ( ob_bank_acct_num like '%' || substr ( :b0 , - 6 , 6 ) ) \
and internal_bank_code = ob_int_bank_code and bank_abbrev_name = :b1 and off\
line_support = 1 ) a left join ( select ob_int_bank_code , ob_bank_acct_num \
, ob_acct_type , ob_status_type , ob_sys_switch_enabled , obai_baid , obai_s\
tatus , opd_psp_id , opd_status , pm_cli");
 sqlstm.stmt = sq0025;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1276;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_short_bank_acct_num;
 sqlstm.sqhstl[0] = (unsigned long )52;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_abbrev_name;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_short_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto getdetailbyshort_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdetailbyshort
                INTO
			:v_int_bank_code:ind_int_bank_code,
                        :v_bank_acct_num:ind_bank_acct_num,
                        :v_acct_type:ind_acct_type,
                        :v_status_type:ind_status_type,
                        :v_sys_switch_enabled:ind_sys_switch_enabled,
			:v_baid:ind_baid,
			:v_baid_status:ind_baid_status,
			:v_psp_id:ind_psp_id,
			:v_pid_status:ind_pid_status,
			:v_client_id:ind_client_id,
			:v_client_status:ind_client_status; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 28;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1303;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_acct_type;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_acct_type;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status_type;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status_type;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_sys_switch_enabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_sys_switch_enabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_baid;
                sqlstm.sqhstl[5] = (unsigned long )23;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_baid;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_baid_status;
                sqlstm.sqhstl[6] = (unsigned long )5;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_baid_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_psp_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_pid_status;
                sqlstm.sqhstl[8] = (unsigned long )5;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_pid_status;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[9] = (unsigned long )13;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_client_id;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_client_status;
                sqlstm.sqhstl[10] = (unsigned long )5;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_client_status;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getdetailbyshort_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iRet = FOUND;		

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* int_bank_code */
        	if (ind_int_bank_code >= 0) {
                	v_int_bank_code.arr[v_int_bank_code.len]='\0';
                	PutField_CString(myHash,"int_bank_code",(const char*)v_int_bank_code.arr);
DEBUGLOG(("GetBankAcctsDetailByShort int_bank_code = [%s]\n",v_int_bank_code.arr));
        	}

/* bank_acct_num */
        	if (ind_bank_acct_num >= 0) {
                	v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                	PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetBankAcctsDetailByShort bank_acct_num = [%s]\n",v_bank_acct_num.arr));
        	}

/* acct_type */
                if (ind_acct_type >= 0) {
                        v_acct_type.arr[v_acct_type.len]='\0';
                        PutField_CString(myHash,"acct_type",(const char*)v_acct_type.arr);
DEBUGLOG(("GetBankAcctsDetailByShort acct_type = [%s]\n",v_acct_type.arr));
                }

/* acct_status */
                if (ind_status_type >= 0) {
                        v_status_type.arr[v_status_type.len]='\0';
                        PutField_CString(myHash,"status_type",(const char*)v_status_type.arr);
DEBUGLOG(("GetBankAcctsDetailByShort status_type = [%s]\n",v_status_type.arr));
                }

/* sys_switch_enabled */
                if (ind_sys_switch_enabled >= 0) {
                        PutField_Int(myHash, "sys_switch_enabled", v_sys_switch_enabled);
DEBUGLOG(("GetBankAcctsDetailByShort sys_switch_enabled = [%d]\n", v_sys_switch_enabled));
                }

/* baid */
                if (ind_baid >= 0) {
                        v_baid.arr[v_baid.len]='\0';
                        PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG(("GetBankAcctsDetailByShort baid = [%s]\n",v_baid.arr));
                }

/* baid_status */
                if (ind_baid_status >= 0) {
                        v_baid_status.arr[v_baid_status.len]='\0';
                        PutField_CString(myHash,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG(("GetBankAcctsDetailByShort baid_status = [%s]\n",v_baid_status.arr));
		}
	
/* psp_id */
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetBankAcctsDetailByShort psp_id = [%s]\n",v_psp_id.arr));
                }

/* pid_status */
                if (ind_pid_status >= 0) {
                        v_pid_status.arr[v_pid_status.len]='\0';
                        PutField_CString(myHash,"pid_status",(const char*)v_pid_status.arr);
DEBUGLOG(("GetBankAcctsDetailByShort pid_status = [%s]\n",v_pid_status.arr));
		}

/* client_id */
                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len]='\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetBankAcctsDetailByShort client_id = [%s]\n",v_client_id.arr));
                }

/* client_status */
                if (ind_client_status >= 0) {
                        v_client_status.arr[v_client_status.len]='\0';
                        PutField_CString(myHash,"client_status",(const char*)v_client_status.arr);
DEBUGLOG(("GetBankAcctsDetailByShort client_status = [%s]\n",v_client_status.arr));
		}

		RecordSet_Add(myRec,myHash);

        } while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailbyshort; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1362;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetailbyshort_error;
}



	if (iRet == NOT_FOUND) {
DEBUGLOG(("GetBankAcctsDetailByShort NOT FOUND\n"));
	} else if (iRet == FOUND) {
DEBUGLOG(("GetBankAcctsDetailByShort FOUND\n"));
	} else {
DEBUGLOG(("GetBankAcctsDetailByShort ERROR\n"));
	}

	return iRet;

getdetailbyshort_error:
DEBUGLOG(("GetBankAcctsDetailByShort_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAccts_GetBankAcctsDetailByShort: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailbyshort; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1377;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetLastUpdBankAcctsDetails(const char* csReqDatetime, 
			       const char* csIntBankCode,
			       const char* csBankAcctNum,
			       int iMaxBankAcctCnt,
			       recordset_t* myRec)
{
	int iCnt = 0;
	hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlastupdbkacctsdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_req_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_req_datetime;

		/* varchar         hv_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_bank_acct_num;

		int             hv_max_bank_acct_cnt;

                short           hv_return_value;

                /* varchar         v_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_provider_name;

                /* varchar         v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_bank_acct_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_status;

                /* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

                /* varchar         v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

                /* varchar         v_bank_acct_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_nature;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_abbrev_name[PD_EXT_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_abbrev_name;

                /* varchar         v_owner_name[PD_OWNER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

                /* varchar         v_province[PD_PROVINCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

                /* varchar         v_registered_mobile[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_registered_mobile;

                /* varchar         v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_pid_bank_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_pid_bank_nature;

		/* varchar         v_bank_upd_ts[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_bank_upd_ts;

                /* varchar         v_baid_upd_ts[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_baid_upd_ts;

                char         	v_rec_end_ind;

                short           ind_provider_name = -1;
                short           ind_provider_id = -1;
                short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
		short           ind_bank_acct_status = -1;
                short           ind_baid = -1;
                short           ind_baid_status = -1;
                short           ind_bank_acct_nature = -1;
                short           ind_bank_name = -1;
                short           ind_bank_abbrev_name = -1;
                short           ind_owner_name = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_branch_name = -1;
                short           ind_registered_mobile = -1;
                short           ind_bank_acct_short_name = -1;
                short           ind_merchant_id = -1;
                short           ind_pid_bank_nature = -1;
                short           ind_bank_upd_ts = -1;
                short           ind_baid_upd_ts = -1;
                short           ind_rec_end_ind = -1;

                SQL_CURSOR      c_cursor_getlastupdbkacctsdt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetLastUpdBankAcctsDetails: Begin\n"));

        // req_datetime
        hv_req_datetime.len = strlen(csReqDatetime);
        memcpy(hv_req_datetime.arr, csReqDatetime, hv_req_datetime.len);
DEBUGLOG(("req_datetime = [%.*s]\n", hv_req_datetime.len, hv_req_datetime.arr));

	// int_bank_code
	if (csIntBankCode == NULL) {
		hv_int_bank_code.len = 0;
                memcpy(hv_int_bank_code.arr, "\0", hv_int_bank_code.len);
	} else {
	        hv_int_bank_code.len = strlen(csIntBankCode);
	        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	}
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        // bank_acct_num
	if (csBankAcctNum == NULL) {
		hv_bank_acct_num.len = 0;
                memcpy(hv_bank_acct_num.arr, "\0", hv_bank_acct_num.len);
        } else {
	       	hv_bank_acct_num.len = strlen(csBankAcctNum);
       		memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
	}
DEBUGLOG(("bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	// max_bank_acct_cnt
        hv_max_bank_acct_cnt = iMaxBankAcctCnt;
DEBUGLOG(("max_bank_acct_cnt = [%d]\n", hv_max_bank_acct_cnt));

        /* EXEC SQL ALLOCATE       :c_cursor_getlastupdbkacctsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1392;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
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
        if (sqlca.sqlcode < 0) goto getlastupdbkacctsdt_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_last_upd_bk_accts_dt(to_date(:hv_req_datetime, 'YYYYMMDDHH24MISS'),
										   :hv_int_bank_code,
                                                                                   :hv_bank_acct_num,
										   :hv_max_bank_acct_cnt,
                                                                                   :c_cursor_getlastupdbkacctsdt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_last_upd_bk_acct\
s_dt ( to_date ( :hv_req_datetime , 'YYYYMMDDHH24MISS' ) , :hv_int_bank_code \
, :hv_bank_acct_num , :hv_max_bank_acct_cnt , :c_cursor_getlastupdbkacctsdt )\
 ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1411;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_req_datetime;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[2] = (unsigned long )13;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[3] = (unsigned long )53;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_max_bank_acct_cnt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getlastupdbkacctsdt_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                for (;;) {

                        ind_provider_name = -1;
                        ind_provider_id = -1;
                        ind_int_bank_code = -1;
                        ind_bank_acct_num = -1;
			ind_bank_acct_status = -1;
                        ind_baid = -1;
                        ind_baid_status = -1;
                        ind_bank_acct_nature = -1;
                        ind_bank_name = -1;
                        ind_bank_abbrev_name = -1;
                        ind_owner_name = -1;
                        ind_province = -1;
                        ind_city = -1;
                        ind_branch_name = -1;
                        ind_registered_mobile = -1;
                        ind_bank_acct_short_name = -1;
                        ind_merchant_id = -1;
                        ind_pid_bank_nature = -1;
                        ind_bank_upd_ts = -1;
                        ind_baid_upd_ts = -1;
                        ind_rec_end_ind = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getlastupdbkacctsdt

                        INTO
                                :v_provider_name:ind_provider_name,
                                :v_provider_id:ind_provider_id,
                                :v_int_bank_code:ind_int_bank_code,
                                :v_bank_acct_num:ind_bank_acct_num,
				:v_bank_acct_status:ind_bank_acct_status,
                                :v_baid:ind_baid,
                                :v_baid_status:ind_baid_status,
                                :v_bank_acct_nature:ind_bank_acct_nature,
                                :v_bank_name:ind_bank_name,
                                :v_bank_abbrev_name:ind_bank_abbrev_name,
                                :v_owner_name:ind_owner_name,
                                :v_province:ind_province,
                                :v_city:ind_city,
                                :v_branch_name:ind_branch_name,
                                :v_registered_mobile:ind_registered_mobile,
				:v_bank_acct_short_name:ind_bank_acct_short_name,
                                :v_merchant_id:ind_merchant_id,
                                :v_pid_bank_nature:ind_pid_bank_nature,
                                :v_bank_upd_ts:ind_bank_upd_ts,
                                :v_baid_upd_ts:ind_baid_upd_ts,
                                :v_rec_end_ind:ind_rec_end_ind; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 28;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1450;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_name;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_provider_name;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_id;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_provider_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_int_bank_code;
                        sqlstm.sqhstl[3] = (unsigned long )13;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_int_bank_code;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_acct_status;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_bank_acct_status;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_baid;
                        sqlstm.sqhstl[6] = (unsigned long )23;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_baid;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_baid_status;
                        sqlstm.sqhstl[7] = (unsigned long )5;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_baid_status;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_nature;
                        sqlstm.sqhstl[8] = (unsigned long )6;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_acct_nature;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_abbrev_name;
                        sqlstm.sqhstl[10] = (unsigned long )53;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_abbrev_name;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_owner_name;
                        sqlstm.sqhstl[11] = (unsigned long )53;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_owner_name;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[12] = (unsigned long )103;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_province;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[13] = (unsigned long )103;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_city;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_branch_name;
                        sqlstm.sqhstl[14] = (unsigned long )153;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_branch_name;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_registered_mobile;
                        sqlstm.sqhstl[15] = (unsigned long )23;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_registered_mobile;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_bank_acct_short_name;
                        sqlstm.sqhstl[16] = (unsigned long )23;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_bank_acct_short_name;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[17] = (unsigned long )18;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_pid_bank_nature;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_pid_bank_nature;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_bank_upd_ts;
                        sqlstm.sqhstl[19] = (unsigned long )17;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_bank_upd_ts;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_baid_upd_ts;
                        sqlstm.sqhstl[20] = (unsigned long )17;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_baid_upd_ts;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_rec_end_ind;
                        sqlstm.sqhstl[21] = (unsigned long )1;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_rec_end_ind;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getlastupdbkacctsdt_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

			myHash = (hash_t*) malloc (sizeof(hash_t));
                	hash_init(myHash,0);

/* provider_name */
                        if(ind_provider_name>=0){
                                v_provider_name.arr[v_provider_name.len]='\0';
                                PutField_CString(myHash,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG((" [%d]provider_name = [%s]\n",iCnt,v_provider_name.arr));
                        }

/* provider_id */
                        if(ind_provider_id>=0){
                                v_provider_id.arr[v_provider_id.len]='\0';
                                PutField_CString(myHash,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG((" [%d]provider_id = [%s]\n",iCnt,v_provider_id.arr));
                        }

/* int_bank_code */
                        if(ind_int_bank_code>=0){
                                v_int_bank_code.arr[v_int_bank_code.len]='\0';
                                PutField_CString(myHash,"int_bank_code",(const char*)v_int_bank_code.arr);
DEBUGLOG((" [%d]int_bank_code = [%s]\n",iCnt,v_int_bank_code.arr));
                        }

/* bank_acct_num */
                        if(ind_bank_acct_num>=0){
                                v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                                PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" [%d]bank_acct_num = [%s]\n",iCnt,v_bank_acct_num.arr));
                        }

/* bank_acct_status */
                        if(ind_bank_acct_status>=0){
                                v_bank_acct_status.arr[v_bank_acct_status.len]='\0';
                                PutField_CString(myHash,"bank_acct_status",(const char*)v_bank_acct_status.arr);
DEBUGLOG((" [%d]bank_acct_status = [%s]\n",iCnt,v_bank_acct_status.arr));
                        }

/* baid */
                        if(ind_baid>=0){
                                v_baid.arr[v_baid.len]='\0';
                                PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG((" [%d]baid = [%s]\n",iCnt,v_baid.arr));
                        }

/* baid_status */
                        if(ind_baid_status>=0){
                                v_baid_status.arr[v_baid_status.len]='\0';
                                PutField_CString(myHash,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG((" [%d]baid_status = [%s]\n",iCnt,v_baid_status.arr));
                        }

/* bank_acct_nature */
                        if(ind_bank_acct_nature>=0){
                                v_bank_acct_nature.arr[v_bank_acct_nature.len]='\0';
                                PutField_CString(myHash,"bank_acct_nature",(const char*)v_bank_acct_nature.arr);
DEBUGLOG((" [%d]bank_acct_nature = [%s]\n",iCnt,v_bank_acct_nature.arr));
                        }

/* bank_name */
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" [%d]bank_name = [%s]\n",iCnt,v_bank_name.arr));
                        }

/* bank_abbrev_name */
                        if(ind_bank_abbrev_name>=0){
                                v_bank_abbrev_name.arr[v_bank_abbrev_name.len]='\0';
                                PutField_CString(myHash,"bank_abbrev_name",(const char*)v_bank_abbrev_name.arr);
DEBUGLOG((" [%d]bank_abbrev_name = [%s]\n",iCnt,v_bank_abbrev_name.arr));
                        }

/* owner_name */
                        if(ind_owner_name>=0){
                                v_owner_name.arr[v_owner_name.len]='\0';
                                PutField_CString(myHash,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG((" [%d]owner_name = [%s]\n",iCnt,v_owner_name.arr));
                        }

/* province */
                        if(ind_province>=0){
                                v_province.arr[v_province.len]='\0';
                                PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG((" [%d]province = [%s]\n",iCnt,v_province.arr));
                        }

/* city */
                        if(ind_city>=0){
                                v_city.arr[v_city.len]='\0';
                                PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG((" [%d]city = [%s]\n",iCnt,v_city.arr));
                        }

/* branch_name */
                        if(ind_branch_name>=0){
                                v_branch_name.arr[v_branch_name.len]='\0';
                                PutField_CString(myHash,"branch_name",(const char*)v_branch_name.arr);
DEBUGLOG((" [%d]branch_name = [%s]\n",iCnt,v_branch_name.arr));
                        }

/* reg_mob_num */
                        if(ind_registered_mobile>=0){
                                v_registered_mobile.arr[v_registered_mobile.len]='\0';
                                PutField_CString(myHash,"reg_mob_num",(const char*)v_registered_mobile.arr);
DEBUGLOG((" [%d]registered_mobile = [%s]\n",iCnt,v_registered_mobile.arr));
                        }

/* bank_acct_short_name */
                        if(ind_bank_acct_short_name>=0){
                                v_bank_acct_short_name.arr[v_bank_acct_short_name.len]='\0';
                                PutField_CString(myHash,"bank_acct_short_name",(const char*)v_bank_acct_short_name.arr);
DEBUGLOG((" [%d]bank_acct_short_name = [%s]\n",iCnt,v_bank_acct_short_name.arr));
                        }

/* merchant_id */
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG((" [%d]merchant_id = [%s]\n",iCnt,v_merchant_id.arr));
                        }

/* pid_bank_nature */
                        if(ind_pid_bank_nature>=0){
                                v_pid_bank_nature.arr[v_pid_bank_nature.len]='\0';
                                PutField_CString(myHash,"pid_bank_nature",(const char*)v_pid_bank_nature.arr);
DEBUGLOG((" [%d]pid_bank_nature = [%s]\n",iCnt,v_pid_bank_nature.arr));
                        }

/* bank_upd_ts */
                        if(ind_bank_upd_ts>=0){
                                v_bank_upd_ts.arr[v_bank_upd_ts.len]='\0';
                                PutField_CString(myHash,"bank_upd_ts",(const char*)v_bank_upd_ts.arr);
DEBUGLOG((" [%d]bank_upd_ts = [%s]\n",iCnt,v_bank_upd_ts.arr));
                        }

/* baid_upd_ts */
                        if(ind_baid_upd_ts>=0){
                                v_baid_upd_ts.arr[v_baid_upd_ts.len]='\0';
                                PutField_CString(myHash,"baid_upd_ts",(const char*)v_baid_upd_ts.arr);
DEBUGLOG((" [%d]baid_upd_ts = [%s]\n",iCnt,v_baid_upd_ts.arr));
                        }

/* rec_end_ind */
			if(ind_rec_end_ind>=0){
				PutField_Char(myHash,"rec_end_ind",v_rec_end_ind);
DEBUGLOG((" [%d]rec_end_ind = [%c]\n",iCnt,v_rec_end_ind));
			}

			iCnt++;

			RecordSet_Add(myRec,myHash);
                }

DEBUGLOG(("GetLastUpdBankAcctsDetails: Found\n"));
                return PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetLastUpdBankAcctsDetails: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetLastUpdBankAcctsDetails: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetLastUpdBankAcctsDetails: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetLastUpdBankAcctsDetails: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetLastUpdBankAcctsDetails: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getlastupdbkacctsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1553;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
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
        if (sqlca.sqlcode < 0) goto getlastupdbkacctsdt_error;
}


        /* EXEC SQL FREE :c_cursor_getlastupdbkacctsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1572;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
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
        if (sqlca.sqlcode < 0) goto getlastupdbkacctsdt_error;
}



getlastupdbkacctsdt_error:
DEBUGLOG(("getlastupdbkacctsdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getlastupdbkacctsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1591;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
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


        /* EXEC SQL FREE :c_cursor_getlastupdbkacctsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1610;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastupdbkacctsdt;
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

int GetBankAcctLatestDetails(const char* csIntBankCode, 
			     const char* csBankAcctNum, 
			     hash_t* hRec)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getbkacctlatestdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_bank_acct_num;


                short           hv_return_value;

                /* varchar         v_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_provider_name;

                /* varchar         v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

                /* varchar         v_bank_acct_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_status;

                /* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

                /* varchar         v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

                /* varchar         v_bank_acct_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_nature;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_abbrev_name[PD_EXT_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_abbrev_name;

                /* varchar         v_owner_name[PD_OWNER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

                /* varchar         v_province[PD_PROVINCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

                /* varchar         v_registered_mobile[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_registered_mobile;

                /* varchar         v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_pid_bank_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_pid_bank_nature;


                short           ind_provider_name = -1;
                short           ind_provider_id = -1;
                short           ind_bank_acct_status = -1;
                short           ind_baid = -1;
                short           ind_baid_status = -1;
                short           ind_bank_acct_nature = -1;
                short           ind_bank_name = -1;
                short           ind_bank_abbrev_name = -1;
                short           ind_owner_name = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_branch_name = -1;
                short           ind_registered_mobile = -1;
                short           ind_bank_acct_short_name = -1;
                short           ind_merchant_id = -1;
                short           ind_pid_bank_nature = -1;

                SQL_CURSOR      c_cursor_getbkacctlatestdt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetBankAcctLatestDetails: Begin\n"));

        // int_bank_code
        hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        // bank_acct_num
        hv_bank_acct_num.len = strlen(csBankAcctNum);
        memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("bank_cacct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

        /* EXEC SQL ALLOCATE       :c_cursor_getbkacctlatestdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1629;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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
        if (sqlca.sqlcode < 0) goto getbkacctlatestdt_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_bk_acct_latest_dt(:hv_int_bank_code,
                                                                                :hv_bank_acct_num,
                                                                                :c_cursor_getbkacctlatestdt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_bk_acct_latest_d\
t ( :hv_int_bank_code , :hv_bank_acct_num , :c_cursor_getbkacctlatestdt ) ; E\
ND ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1648;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )13;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )53;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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
        if (sqlca.sqlcode < 0) goto getbkacctlatestdt_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                for (;;) {

                        ind_provider_name = -1;
                        ind_provider_id = -1;
                        ind_bank_acct_status = -1;
                        ind_baid = -1;
                        ind_baid_status = -1;
                        ind_bank_acct_nature = -1;
                        ind_bank_name = -1;
                        ind_bank_abbrev_name = -1;
                        ind_owner_name = -1;
                        ind_province = -1;
                        ind_city = -1;
                        ind_branch_name = -1;
                        ind_registered_mobile = -1;
                        ind_bank_acct_short_name = -1;
                        ind_merchant_id = -1;
                        ind_pid_bank_nature = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getbkacctlatestdt

                        INTO
                                :v_provider_name:ind_provider_name,
                                :v_provider_id:ind_provider_id,
                                :v_bank_acct_status:ind_bank_acct_status,
                                :v_baid:ind_baid,
                                :v_baid_status:ind_baid_status,
                                :v_bank_acct_nature:ind_bank_acct_nature,
                                :v_bank_name:ind_bank_name,
                                :v_bank_abbrev_name:ind_bank_abbrev_name,
                                :v_owner_name:ind_owner_name,
                                :v_province:ind_province,
                                :v_city:ind_city,
                                :v_branch_name:ind_branch_name,
                                :v_registered_mobile:ind_registered_mobile,
                                :v_bank_acct_short_name:ind_bank_acct_short_name,
                                :v_merchant_id:ind_merchant_id,
                                :v_pid_bank_nature:ind_pid_bank_nature; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 28;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1679;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_name;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_provider_name;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_id;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_provider_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_status;
                        sqlstm.sqhstl[3] = (unsigned long )5;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_bank_acct_status;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_baid;
                        sqlstm.sqhstl[4] = (unsigned long )23;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_baid;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_baid_status;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_baid_status;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_acct_nature;
                        sqlstm.sqhstl[6] = (unsigned long )6;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_bank_acct_nature;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[7] = (unsigned long )153;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_abbrev_name;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_abbrev_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_owner_name;
                        sqlstm.sqhstl[9] = (unsigned long )53;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_owner_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[10] = (unsigned long )103;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_province;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[11] = (unsigned long )103;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_city;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_branch_name;
                        sqlstm.sqhstl[12] = (unsigned long )153;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_branch_name;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_registered_mobile;
                        sqlstm.sqhstl[13] = (unsigned long )23;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_registered_mobile;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_bank_acct_short_name;
                        sqlstm.sqhstl[14] = (unsigned long )23;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_bank_acct_short_name;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[15] = (unsigned long )18;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_pid_bank_nature;
                        sqlstm.sqhstl[16] = (unsigned long )6;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_pid_bank_nature;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getbkacctlatestdt_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* provider_name */
                        if(ind_provider_name>=0){
                                v_provider_name.arr[v_provider_name.len]='\0';
                                PutField_CString(hRec,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG((" provider_name = [%s]\n",v_provider_name.arr));
                        }

/* provider_id */
                        if(ind_provider_id>=0){
                                v_provider_id.arr[v_provider_id.len]='\0';
                                PutField_CString(hRec,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG((" provider_id = [%s]\n",v_provider_id.arr));
                        }

/* bank_acct_status */
                        if(ind_bank_acct_status>=0){
                                v_bank_acct_status.arr[v_bank_acct_status.len]='\0';
                                PutField_CString(hRec,"bank_acct_status",(const char*)v_bank_acct_status.arr);
DEBUGLOG((" bank_acct_status = [%s]\n",v_bank_acct_status.arr));
                        }

/* baid */
                        if(ind_baid>=0){
                                v_baid.arr[v_baid.len]='\0';
                                PutField_CString(hRec,"baid",(const char*)v_baid.arr);
DEBUGLOG((" baid = [%s]\n",v_baid.arr));
                        }

/* baid_status */
                        if(ind_baid_status>=0){
                                v_baid_status.arr[v_baid_status.len]='\0';
                                PutField_CString(hRec,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG((" baid_status = [%s]\n",v_baid_status.arr));
                        }

/* bank_acct_nature */
                        if(ind_bank_acct_nature>=0){
                                v_bank_acct_nature.arr[v_bank_acct_nature.len]='\0';
                                PutField_CString(hRec,"bank_acct_nature",(const char*)v_bank_acct_nature.arr);
DEBUGLOG((" bank_acct_nature = [%s]\n",v_bank_acct_nature.arr));
                        }

/* bank_name */
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(hRec,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" bank_name = [%s]\n",v_bank_name.arr));
                        }

/* bank_abbrev_name */
                        if(ind_bank_abbrev_name>=0){
                                v_bank_abbrev_name.arr[v_bank_abbrev_name.len]='\0';
                                PutField_CString(hRec,"bank_abbrev_name",(const char*)v_bank_abbrev_name.arr);
DEBUGLOG((" bank_abbrev_name = [%s]\n",v_bank_abbrev_name.arr));
                        }

/* owner_name */
                        if(ind_owner_name>=0){
                                v_owner_name.arr[v_owner_name.len]='\0';
                                PutField_CString(hRec,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG((" owner_name = [%s]\n",v_owner_name.arr));
                        }

/* province */
                        if(ind_province>=0){
                                v_province.arr[v_province.len]='\0';
                                PutField_CString(hRec,"province",(const char*)v_province.arr);
DEBUGLOG((" province = [%s]\n",v_province.arr));
                        }

/* city */
                        if(ind_city>=0){
                                v_city.arr[v_city.len]='\0';
                                PutField_CString(hRec,"city",(const char*)v_city.arr);
DEBUGLOG((" city = [%s]\n",v_city.arr));
                        }

/* branch_name */
                        if(ind_branch_name>=0){
                                v_branch_name.arr[v_branch_name.len]='\0';
                                PutField_CString(hRec,"branch_name",(const char*)v_branch_name.arr);
DEBUGLOG((" branch_name = [%s]\n",v_branch_name.arr));
                        }

/* registered_mobile */
                        if(ind_registered_mobile>=0){
                                v_registered_mobile.arr[v_registered_mobile.len]='\0';
                                PutField_CString(hRec,"reg_mob_num",(const char*)v_registered_mobile.arr);
DEBUGLOG((" registered_mobile = [%s]\n",v_registered_mobile.arr));
                        }

/* bank_acct_short_name */
                        if(ind_bank_acct_short_name>=0){
                                v_bank_acct_short_name.arr[v_bank_acct_short_name.len]='\0';
                                PutField_CString(hRec,"bank_acct_short_name",(const char*)v_bank_acct_short_name.arr);
DEBUGLOG((" bank_acct_short_name = [%s]\n",v_bank_acct_short_name.arr));
                        }

/* merchant_id */
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(hRec,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG((" merchant_id = [%s]\n",v_merchant_id.arr));
                        }

/* pid_bank_nature */
                        if(ind_pid_bank_nature>=0){
                                v_pid_bank_nature.arr[v_pid_bank_nature.len]='\0';
                                PutField_CString(hRec,"pid_bank_nature",(const char*)v_pid_bank_nature.arr);
DEBUGLOG((" pid_bank_nature = [%s]\n",v_pid_bank_nature.arr));
                        }
                }

DEBUGLOG(("GetBankAcctLatestDetails: Found\n"));
                return PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetBankAcctLatestDetails: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetBankAcctLatestDetails: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetBankAcctLatestDetails: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetBankAcctLatestDetails: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetBankAcctLatestDetails: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getbkacctlatestdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1762;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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
        if (sqlca.sqlcode < 0) goto getbkacctlatestdt_error;
}


        /* EXEC SQL FREE :c_cursor_getbkacctlatestdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1781;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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
        if (sqlca.sqlcode < 0) goto getbkacctlatestdt_error;
}



getbkacctlatestdt_error:
DEBUGLOG(("getbkacctlatestdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getbkacctlatestdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1800;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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


        /* EXEC SQL FREE :c_cursor_getbkacctlatestdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1819;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbkacctlatestdt;
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

int ChkNumOfSmsDepositBankAccts(const char *csIntBankCode,
                        	const char *csBankAcctNum,
				int iBankAcctNumLen)
{
        int     iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chknumofsmsdepositbankacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

                /* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int		hv_bank_acct_num_pos;
		int		hv_bank_acct_num_len;

                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_int_bank_code.len = strlen(csIntBankCode);
        memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("ChkNumOfSmsDepositBankAccts int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

        hv_bank_acct_num.len = strlen(csBankAcctNum);
        memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("ChkNumOfSmsDepositBankAccts bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	hv_bank_acct_num_pos = (-1)*iBankAcctNumLen;
DEBUGLOG(("ChkNumOfSmsDepositBankAccts bank_acct_num_pos = [%d]\n", hv_bank_acct_num_pos));

	hv_bank_acct_num_len = iBankAcctNumLen;
DEBUGLOG(("ChkNumOfSmsDepositBankAccts bank_acct_num_len = [%d]\n", hv_bank_acct_num_len));

        /* EXEC SQL
                SELECT count(1)
                INTO :v_no_of_record:ind_no_of_record
                FROM ol_bank_accts,
		     ol_acct_status_action
                WHERE ob_int_bank_code = :hv_int_bank_code
                AND ((ob_acct_type = 'DSI' AND (ob_bank_acct_num like '%' || substr(:hv_bank_acct_num, :hv_bank_acct_num_pos, :hv_bank_acct_num_len)))
                    OR (ob_bank_acct_num = :hv_bank_acct_num))
		AND asa_action = 'SMS_POST'
		AND (asa_status = ob_status_type AND asa_allow_action = 1); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_bank_accts , \
ol_acct_status_action WHERE ob_int_bank_code = :b2 AND ( ( ob_acct_type = 'DS\
I' AND ( ob_bank_acct_num like '%' || substr ( :b3 , :b4 , :b5 ) ) ) OR ( ob_\
bank_acct_num = :b3 ) ) AND asa_action = 'SMS_POST' AND ( asa_status = ob_sta\
tus_type AND asa_allow_action = 1 ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1838;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num_pos;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num_len;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[5] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto chknumofsmsdepositbankacct_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
                        iRet = v_no_of_record;
DEBUGLOG(("ChkNumOfSmsDepositBankAccts no_of_record = [%d]\n", v_no_of_record));
                }
        }

        if (iRet == NOT_FOUND) {
DEBUGLOG(("ChkNumOfSmsDepositBankAccts Not FOUND\n"));
        } else if (iRet == 1) {
DEBUGLOG(("ChkNumOfSmsDepositBankAccts Unique FOUND\n"));
        } else if (iRet > 1) {
DEBUGLOG(("ChkNumOfSmsDepositBankAccts Duplicate FOUND\n"));
        }

        return iRet;

chknumofsmsdepositbankacct_error:
DEBUGLOG(("ChkBankAcctsUnique_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;
}

