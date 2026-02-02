
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
    "OLPayoutReturnBatchDt.pc"
};


static unsigned int sqlctx = 1306585403;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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

 static char *sq0003 = 
"select prd_txn_id , prd_account_name , prd_account_num , prd_amount , prd_r\
eason , prd_is_valid , prd_status from ol_payout_return_batch_dt , ol_payout_\
return_batch_hd where prd_batch_id = :b0 and prd_seq = :b1            ";

 static char *sq0006 = 
"select prd_batch_id , prd_seq , prd_txn_id , prd_account_name , prd_account\
_num , prd_amount , prd_reason , oud_country , oud_request_currency from ol_p\
ayout_return_batch_dt , ol_merchant_upload_file_detail where prd_upload_txn_i\
d = :b0 and prd_status = :b1 and prd_is_valid = 1 and prd_upload_txn_id = oud\
_txn_id for update ";

 static char *sq0007 = 
"SELECT prd_upload_txn_id FROM ( SELECT prd_upload_txn_id , retcnt , COUNT (\
 ofd_txn_id ) gencnt FROM ol_payout_generated_file_dt , ( SELECT prd_upload_t\
xn_id , retcnt FROM ( SELECT prd_upload_txn_id , COUNT ( prd_txn_id ) retcnt \
FROM ol_payout_return_batch_dt WHERE prd_batch_id = :b0 GROUP BY prd_upload_t\
xn_id ) ) WHERE prd_upload_txn_id = ofd_upload_txn_id AND ofd_status = 70 GRO\
UP BY prd_upload_txn_id , retcnt ) WHERE retcnt <> gencnt            ";

 static char *sq0008 = 
"select prd_txn_id from ol_payout_return_batch_dt where prd_batch_id = :b0 a\
nd prd_upload_txn_id = :b1 and prd_status = :b2            ";

 static char *sq0010 = 
"select prd_batch_id , prd_seq , prd_txn_id , prd_account_name , prd_account\
_num , prd_amount , prd_reason , otd_txn_country , opr_request_currency from \
ol_payout_return_batch_dt , ol_payout_request , ol_txn_detail where prd_uploa\
d_txn_id = :b0 and prd_upload_txn_id = otd_txn_id and prd_upload_txn_id = opr\
_txn_id and prd_status = :b1 and prd_is_valid = 1 for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,546,0,6,216,0,0,18,18,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,3,0,0,1,9,0,0,
92,0,0,2,0,0,17,404,0,0,1,1,0,1,0,1,9,0,0,
111,0,0,2,0,0,21,405,0,0,0,0,0,1,0,
126,0,0,3,222,0,9,469,0,2049,2,2,0,1,0,1,3,0,0,1,3,0,0,
149,0,0,3,0,0,13,471,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,3,
0,0,2,3,0,0,
192,0,0,3,0,0,15,538,0,0,0,0,0,1,0,
207,0,0,3,0,0,15,548,0,0,0,0,0,1,0,
222,0,0,4,85,0,6,574,0,0,1,1,0,1,0,1,3,0,0,
241,0,0,5,94,0,4,611,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
264,0,0,6,325,0,9,694,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
287,0,0,6,0,0,13,696,0,0,9,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
338,0,0,6,0,0,15,779,0,0,0,0,0,1,0,
353,0,0,6,0,0,15,789,0,0,0,0,0,1,0,
368,0,0,7,452,0,9,827,0,2049,1,1,0,1,0,1,3,0,0,
387,0,0,7,0,0,13,829,0,0,1,0,0,1,0,2,9,0,0,
406,0,0,7,0,0,15,853,0,0,0,0,0,1,0,
421,0,0,7,0,0,15,863,0,0,0,0,0,1,0,
436,0,0,8,134,0,9,904,0,2049,3,3,0,1,0,1,3,0,0,1,9,0,0,1,3,0,0,
463,0,0,8,0,0,13,906,0,0,1,0,0,1,0,2,9,0,0,
482,0,0,8,0,0,15,930,0,0,0,0,0,1,0,
497,0,0,8,0,0,15,940,0,0,0,0,0,1,0,
512,0,0,9,81,0,6,963,0,0,1,1,0,1,0,1,9,0,0,
531,0,0,10,367,0,9,1047,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
554,0,0,10,0,0,13,1049,0,0,9,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
605,0,0,10,0,0,15,1132,0,0,0,0,0,1,0,
620,0,0,10,0,0,15,1142,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/21              Elvis Wong
Schema changed					   2014/08/26		   LokMan Chow
Add GetReturnDetailByStatus_API_ForUpdate	   2017/05/04		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPayoutReturnBatchDt.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLPayoutReturnBatchDt(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char		*csTmp;
	int		iTmp;
	double		dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int         	hv_batch_id;
		int	        hv_seq;
		/* varchar         hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar         hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		/* varchar         hv_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_branch;

		/* varchar         hv_account_name[PD_ACC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_account_name;

		/* varchar         hv_account_num[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_num;

		double		hv_amount;
		/* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_province;

		/* varchar         hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

		/* varchar		hv_reason[PD_REASON_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_reason;

		/* varchar         hv_process_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_process_bank_name;

		int		hv_is_valid;
		int		hv_status;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short           ind_batch_id= -1;
		short           ind_seq = -1;
		short           ind_txn_date = -1;
		short           ind_upload_txn_id = -1;
		short           ind_txn_id = -1;
		short           ind_bank_name = -1;
		short           ind_branch = -1;
		short           ind_account_name = -1;
		short           ind_account_num = -1;
		short		ind_amount = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_reason = -1;
		short           ind_process_bank_name = -1;
		short		ind_is_valid = -1;
		short		ind_status= -1;
		short		ind_add_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/*batch_id*/
	if(GetField_Int(hRls,"batch_id",&iTmp)){
		hv_batch_id = iTmp;
		ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%d]\n",hv_batch_id));
	}

/*seq*/
	if(GetField_Int(hRls,"seq",&iTmp)){
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("Add:seq = [%d]\n",hv_seq));
	}

/*txn_date*/
	if(GetField_CString(hRls,"txn_date",&csTmp)){
		hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date= 0;
DEBUGLOG(("Add:txn_date= [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
	}

/*upload_txn_id*/
	if(GetField_CString(hRls,"upload_txn_id",&csTmp)){
		hv_upload_txn_id.len = strlen(csTmp);
		memcpy(hv_upload_txn_id.arr, csTmp, hv_upload_txn_id.len);
		ind_upload_txn_id= 0;
DEBUGLOG(("Add:upload_txn_id= [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));
	}

/*txn_id*/
	if(GetField_CString(hRls,"txn_id",&csTmp)){
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

/*bank_name*/
	if(GetField_CString(hRls,"bank_name",&csTmp)){
		hv_bank_name.len = strlen(csTmp);
		memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
		ind_bank_name= 0;
DEBUGLOG(("Add:bank_name= [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
	}

/*branch*/
	if(GetField_CString(hRls,"branch",&csTmp)){
		hv_branch.len = strlen(csTmp);
		memcpy(hv_branch.arr, csTmp, hv_branch.len);
		ind_branch= 0;
DEBUGLOG(("Add:branch= [%.*s]\n",hv_branch.len,hv_branch.arr));
	}

/*account name*/
	if(GetField_CString(hRls,"account_name",&csTmp)){
		hv_account_name.len = strlen(csTmp);
		memcpy(hv_account_name.arr, csTmp, hv_account_name.len);
		ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
	}

/*account_num*/
	if(GetField_CString(hRls,"account_num",&csTmp)){
		hv_account_num.len = strlen(csTmp);
		memcpy(hv_account_num.arr, csTmp, hv_account_num.len);
		ind_account_num = 0;
DEBUGLOG(("Add:account_num = [%.*s]\n",hv_account_num.len,hv_account_num.arr));
	}

/*amount*/
	if (GetField_Double(hRls,"amount",&dTmp)) {
		hv_amount = dTmp;
		ind_amount = 0;
DEBUGLOG(("Add:amount = [%lf]\n",hv_amount));
	}

/*province*/
	if(GetField_CString(hRls,"province",&csTmp)){
		hv_province.len = strlen(csTmp);
		memcpy(hv_province.arr, csTmp, hv_province.len);
		ind_province= 0;
DEBUGLOG(("Add:province= [%.*s]\n",hv_province.len,hv_province.arr));
	}

/*city*/
	if(GetField_CString(hRls,"city",&csTmp)){
		hv_city.len = strlen(csTmp);
		memcpy(hv_city.arr, csTmp, hv_city.len);
		ind_city= 0;
DEBUGLOG(("Add:city= [%.*s]\n",hv_city.len,hv_city.arr));
	}

/*reason*/
	if(GetField_CString(hRls,"reason",&csTmp)){
		hv_reason.len = strlen(csTmp);
		memcpy(hv_reason.arr, csTmp, hv_reason.len);
		ind_reason = 0;
DEBUGLOG(("Add:reason = [%.*s]\n",hv_reason.len,hv_reason.arr));
	}

/*process_bank_name*/
	if(GetField_CString(hRls,"process_bank_name",&csTmp)){
		hv_process_bank_name.len = strlen(csTmp);
		memcpy(hv_process_bank_name.arr, csTmp, hv_process_bank_name.len);
		ind_process_bank_name= 0;
DEBUGLOG(("Add:process_bank_name= [%.*s]\n",hv_process_bank_name.len,hv_process_bank_name.arr));
	}

/*is_valid*/
	if(GetField_Int(hRls,"is_valid",&iTmp)){
		hv_is_valid = iTmp;
		ind_is_valid = 0;
DEBUGLOG(("Add:is_valid = [%d]\n",hv_is_valid));
	}

/*status*/
	if(GetField_Int(hRls,"status",&iTmp)){
		hv_status = iTmp;
		ind_status = 0;
DEBUGLOG(("Add:status = [%d]\n",hv_status));
	}

/*add_user*/
	if (GetField_CString(hRls, "add_user", &csTmp)) {
                hv_add_user.len = strlen(csTmp);
                strncpy((char *)hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n", hv_add_user.len, hv_add_user.arr));
	}

	//FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_po_ret_batch_dt_insert(
					:hv_batch_id:ind_batch_id,
					:hv_seq:ind_seq,
					:hv_txn_date:ind_txn_date,
					:hv_upload_txn_id:ind_upload_txn_id,
					:hv_txn_id:ind_txn_id,
					:hv_bank_name:ind_bank_name,
					:hv_branch:ind_branch,
					:hv_account_name:ind_account_name,
					:hv_account_num:ind_account_num,
					:hv_amount:ind_amount,
					:hv_province:ind_province,
					:hv_city:ind_city,
					:hv_reason:ind_reason,
					:hv_process_bank_name:ind_process_bank_name,
					:hv_is_valid:ind_is_valid,
					:hv_status:ind_status,
					:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_po_ret_batch_dt_insert ( :h\
v_batch_id:ind_batch_id , :hv_seq:ind_seq , :hv_txn_date:ind_txn_date , :hv_u\
pload_txn_id:ind_upload_txn_id , :hv_txn_id:ind_txn_id , :hv_bank_name:ind_ba\
nk_name , :hv_branch:ind_branch , :hv_account_name:ind_account_name , :hv_acc\
ount_num:ind_account_num , :hv_amount:ind_amount , :hv_province:ind_province \
, :hv_city:ind_city , :hv_reason:ind_reason , :hv_process_bank_name:ind_proce\
ss_bank_name , :hv_is_valid:ind_is_valid , :hv_status:ind_status , :hv_add_us\
er:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_date;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_upload_txn_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[5] = (unsigned long )18;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[6] = (unsigned long )152;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bank_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_branch;
 sqlstm.sqhstl[7] = (unsigned long )152;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_branch;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[8] = (unsigned long )102;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_account_name;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_account_num;
 sqlstm.sqhstl[9] = (unsigned long )27;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_account_num;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_amount;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[11] = (unsigned long )102;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_province;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[12] = (unsigned long )102;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_city;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_reason;
 sqlstm.sqhstl[13] = (unsigned long )257;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_reason;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_process_bank_name;
 sqlstm.sqhstl[14] = (unsigned long )152;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_process_bank_name;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_is_valid;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_is_valid;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_status;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[17] = (unsigned long )22;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_add_user;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
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
ERRLOG("OLPayoutReturnBatchDt_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutReturnBatchDt_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR; 
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_Add: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}



int Update(const hash_t *hRls)
{
        int	iBatchId;
        char    *csBatchId = NULL;
	int	iSeq;
        char    *csSeq = NULL;
        char    *csTxnId = NULL;
        char    *csAccountName = NULL;
        char    *csAccountNum = NULL;
        double  dAmount;
        char    *csReason = NULL;
        int	iIsValid;
        int	iStatus;
	char	*csUpdateUser = NULL;
	char	*csTmp= NULL;

        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char *)malloc(128);
        csBatchId = (char *)malloc(128);
        csSeq = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update ol_payout_return_batch_dt set prd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*txn_id*/
	if (GetField_CString(hRls,"txn_id",&csTxnId)) {
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));
                strcat((char*)hv_dynstmt.arr, ",prd_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTxnId);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*account_name*/
	if (GetField_CString(hRls,"account_name",&csAccountName)) {
DEBUGLOG(("Update:account_name = [%s]\n",csAccountName));
                strcat((char*)hv_dynstmt.arr, ",prd_account_name = '");
                strcat((char*)hv_dynstmt.arr, csAccountName);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*account_num*/
        if (GetField_CString(hRls,"account_num",&csAccountNum)) {
DEBUGLOG(("Update:account_num = [%s]\n",csAccountNum));
                strcat((char*)hv_dynstmt.arr, ",prd_account_num = '");
                strcat((char*)hv_dynstmt.arr, csAccountNum);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*amount*/
        if (GetField_Double(hRls,"amount",&dAmount)) {
DEBUGLOG(("Update:amount = [%lf]\n",dAmount));
                sprintf(csBuf,"%lf",dAmount);
                strcat((char*)hv_dynstmt.arr, ",prd_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*reason*/
	if (GetField_CString(hRls,"reason",&csReason)) {
DEBUGLOG(("Update:update_reason = [%s]\n",csReason));
                strcat((char*)hv_dynstmt.arr, ",prd_reason = '");
                strcat((char*)hv_dynstmt.arr, csReason);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*is_valid*/
	if (GetField_Int(hRls,"is_valid",&iIsValid)) {
DEBUGLOG(("Update:is_valid = [%d]\n",iIsValid));
                sprintf(csBuf,"%d",iIsValid);
                strcat((char*)hv_dynstmt.arr, ",prd_is_valid= ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*status*/
	if (GetField_Int(hRls,"status",&iStatus)) {
DEBUGLOG(("Update:status = [%d]\n",iStatus));
                sprintf(csBuf,"%d",iStatus);
                strcat((char*)hv_dynstmt.arr, ",prd_status= ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*desc*/
	if (GetField_CString(hRls,"desc",&csTmp)) {
DEBUGLOG(("Update:update_desc = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",prd_desc = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csUpdateUser)) {
DEBUGLOG(("Update:update_user = [%s]\n",csUpdateUser));
                strcat((char*)hv_dynstmt.arr, ",prd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csUpdateUser);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Primary Key: batch_id*/
        GetField_Int(hRls,"batch_id",&iBatchId);
        sprintf(csBatchId,"%d",iBatchId);
DEBUGLOG(("Update: batch_id = [%s]\n", csBatchId));

/*Primary Key: seq*/
        GetField_Int(hRls,"seq",&iSeq);
        sprintf(csSeq,"%d",iSeq);
DEBUGLOG(("Update: seq = [%s]\n", csSeq));

        strcat((char*)hv_dynstmt.arr, " WHERE prd_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        strcat((char*)hv_dynstmt.arr, " AND prd_seq = ");
        strcat((char*)hv_dynstmt.arr, csSeq);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )92;
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
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )111;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);
        FREE_ME(csBatchId);
        FREE_ME(csSeq);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLPayoutReturnBatchDt:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}



int GetOLPayoutReturnBatchDt(const int iBatchId, const int iSeq, recordset_t* myRec)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getpayout_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_batch_id;
		int		hv_seq;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		double		v_amount;
		/* varchar		v_reason[PD_REASON_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } v_reason;

		int		v_is_valid;
		int		v_status;

		short           ind_txn_id = -1;
		short           ind_account_name = -1;
		short           ind_account_num = -1;
		short		ind_amount = -1;
		short		ind_reason = -1;
		short		ind_is_valid = -1;
		short		ind_status= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = iBatchId;
DEBUGLOG(("GetOLPayoutReturnBatchDt batch_id = [%d]\n",hv_batch_id));

	/* EXEC SQL DECLARE c_cursor_getpayout CURSOR FOR
		select	prd_txn_id,
			prd_account_name,
			prd_account_num,
			prd_amount,
			prd_reason,
			prd_is_valid,
			prd_status
		from	ol_payout_return_batch_dt,
			ol_payout_return_batch_hd
		where	prd_batch_id =:hv_batch_id
		and	prd_seq =:hv_seq; */ 


	/* EXEC SQL OPEN  c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )126;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq;
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
 if (sqlca.sqlcode < 0) goto getpayout_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getpayout
		INTO
			:v_txn_id:ind_txn_id,
			:v_account_name:ind_account_name,
			:v_account_num:ind_account_num,
			:v_amount:ind_amount,
			:v_reason:ind_reason,
			:v_is_valid:ind_is_valid,
			:v_status:ind_status; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )149;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[1] = (unsigned long )103;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_account_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[2] = (unsigned long )28;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_account_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_amount;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_reason;
  sqlstm.sqhstl[4] = (unsigned long )257;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_reason;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_is_valid;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_is_valid;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_status;
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
  if (sqlca.sqlcode < 0) goto getpayout_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetOLPayoutReturnBatchDt txn_id= [%s]\n",v_txn_id.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetOLPayoutReturnBatchDt account_name= [%s]\n",v_account_name.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetOLPayoutReturnBatchDt account_num= [%s]\n",v_account_num.arr));
		}

/*amount*/
		if(ind_amount>=0){
			PutField_Double(myHash,"amount",v_amount);
DEBUGLOG(("GetOLPayoutReturnBatchDt amount = [%lf]\n",v_amount));
		}

/*reason*/
		if(ind_reason>=0){
			v_reason.arr[v_reason.len]='\0';
			PutField_CString(myHash,"reason",(const char*)v_reason.arr);
DEBUGLOG(("GetOLPayoutReturnBatchDt reason= [%s]\n",v_reason.arr));
		}

/*is_valid*/
		if(ind_is_valid>=0){
			PutField_Int(myHash,"is_valid",v_is_valid);
DEBUGLOG(("GetOLPayoutReturnBatchDt is_valid=[%d]\n",v_is_valid));
		}

/*status*/
		if(ind_status>=0){
			PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetOLPayoutReturnBatchDt status=[%d]\n",v_status));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )192;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayout_error;
}



DEBUGLOG(("GetOLPayoutReturnBatchDt Normal Exit\n"));
	return  PD_OK;

getpayout_error:
DEBUGLOG(("getpayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )207;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int DeleteByBatch(const hash_t *hRls)
{
	int		iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO deletebybatch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int         	hv_batch_id;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteByBatch: Begin\n"));

/*batch_id*/
	if(GetField_Int(hRls,"batch_id",&iTmp)){
		hv_batch_id = iTmp;
DEBUGLOG(("DeleteByBatch:batch_id= [%d]\n",hv_batch_id));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			delete 
			from	OL_PAYOUT_RETURN_BATCH_DT
			where	PRD_BATCH_ID = :hv_batch_id;

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin delete from OL_PAYOUT_RETURN_BATCH_DT where PRD_BATCH\
_ID = :hv_batch_id ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )222;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
 if (sqlca.sqlcode < 0) goto deletebybatch_error;
}



DEBUGLOG(("DeleteByBatch: Finished\n"));
	return PD_OK;

deletebybatch_error:
DEBUGLOG(("deletebybatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_DeleteByBatch: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchRespTxn(const char* csTxnSeq)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                short           v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));


        /* EXEC SQL SELECT nvl(COUNT(*),0)
                INTO    :v_cnt
                FROM    ol_payout_return_batch_dt
                WHERE   prd_txn_id = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM ol_payo\
ut_return_batch_dt WHERE prd_txn_id = :b1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )241;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto MatchRespTxn_error;
}




        if(v_cnt>0){
DEBUGLOG(("MatchRespTxn Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxn Not Found\n"));
                return PD_NOT_FOUND;
        }

MatchRespTxn_error:
DEBUGLOG(("MatchRespTxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetReturnDetailByStatus_ForUpdate(const char* csUploadTxnId, const int iStatus,recordset_t* myRec)
{
	int iRet = PD_OK;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getpayout_forupd_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

		int		hv_status;

		int		v_batch_id;
		int		v_seq;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		double		v_amount;
		/* varchar		v_reason[PD_REASON_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_reason;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar		v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;


		short           ind_batch_id = -1;
		short           ind_seq = -1;
		short           ind_txn_id = -1;
		short           ind_account_name = -1;
		short           ind_account_num = -1;
		short		ind_amount = -1;
		short		ind_reason = -1;
		short		ind_country = -1;
		short		ind_ccy = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_upload_txn_id.len = strlen(csUploadTxnId);
        memcpy(hv_upload_txn_id.arr,csUploadTxnId,hv_upload_txn_id.len);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));

	hv_status= iStatus;
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getpayout_forupd CURSOR FOR
		select	
			prd_batch_id,
			prd_seq,
			prd_txn_id,
			prd_account_name,
			prd_account_num,
			prd_amount,
			prd_reason,
			oud_country,
			oud_request_currency
		from	ol_payout_return_batch_dt,
			ol_merchant_upload_file_detail
		where	prd_upload_txn_id = :hv_upload_txn_id
		and	prd_status =:hv_status
		and	prd_is_valid = 1
		and	prd_upload_txn_id = oud_txn_id
		for update; */ 


	/* EXEC SQL OPEN  c_cursor_getpayout_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )264;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
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
 if (sqlca.sqlcode < 0) goto getpayout_forupd_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getpayout_forupd
		INTO
			:v_batch_id:ind_batch_id,
			:v_seq:ind_seq,
			:v_txn_id:ind_txn_id,
			:v_account_name:ind_account_name,
			:v_account_num:ind_account_num,
			:v_amount:ind_amount,
			:v_reason:ind_reason,
			:v_country:ind_country,
			:v_ccy:ind_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )287;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[3] = (unsigned long )103;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_account_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[4] = (unsigned long )28;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_account_num;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_amount;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_reason;
  sqlstm.sqhstl[6] = (unsigned long )258;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_reason;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_country;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_ccy;
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
  if (sqlca.sqlcode < 0) goto getpayout_forupd_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*batch_id*/
		if(ind_batch_id>=0){
			PutField_Int(myHash,"batch_id",v_batch_id);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate batch_id = [%d]\n",v_batch_id));
		}

/*seq*/
		if(ind_seq>=0){
			PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate seq = [%d]\n",v_seq));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate txn_id= [%s]\n",v_txn_id.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate account_name= [%s]\n",v_account_name.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate account_num= [%s]\n",v_account_num.arr));
		}

/*amount*/
		if(ind_amount>=0){
			PutField_Double(myHash,"amount",v_amount);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate amount = [%lf]\n",v_amount));
		}

/*reason*/
		if(ind_reason>=0){
			v_reason.arr[v_reason.len]='\0';
			PutField_CString(myHash,"reason",(const char*)v_reason.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate reason= [%s]\n",v_reason.arr));
		}

/*currency*/
		if(ind_ccy>=0){
			v_ccy.arr[v_ccy.len]='\0';
			PutField_CString(myHash,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate ccy = [%s]\n",v_ccy.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("GetReturnDetailByStatus_ForUpdate country = [%s]\n",v_country.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpayout_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )338;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayout_forupd_error;
}



DEBUGLOG(("GetReturnDetailByStatus_ForUpdate Normal Exit\n"));
	return  iRet;

getpayout_forupd_error:
DEBUGLOG(("getpayout_forupd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_GetReturnDetailByStatus_ForUpdate: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpayout_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )353;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int GetInvalidSplitReturn(const int iBatchId, recordset_t* myRec)
{
	int	iRet = PD_NOT_FOUND;
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO get_invsplit_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_batch_id;

		/* varchar		v_upload_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_upload_txn_id;


		short           ind_upload_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = iBatchId;
DEBUGLOG(("GetInvalidSplitReturn batch_id = [%d]\n",hv_batch_id));

	/* EXEC SQL DECLARE c_cursor_get_invsplit_error CURSOR FOR
		SELECT	prd_upload_txn_id
		FROM	(  SELECT prd_upload_txn_id, retcnt, COUNT (ofd_txn_id) gencnt
            		   FROM ol_payout_generated_file_dt,
                 		(SELECT prd_upload_txn_id, retcnt
                    		 FROM (  SELECT prd_upload_txn_id, COUNT (prd_txn_id) retcnt
                              		 FROM ol_payout_return_batch_dt
                             		 WHERE prd_batch_id = :hv_batch_id
                          		 GROUP BY prd_upload_txn_id))
           			 WHERE prd_upload_txn_id = ofd_upload_txn_id AND ofd_status = 70
        		   GROUP BY prd_upload_txn_id, retcnt)
 		WHERE retcnt <> gencnt; */ 


	/* EXEC SQL OPEN  c_cursor_get_invsplit_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )368;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
 if (sqlca.sqlcode < 0) goto get_invsplit_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_get_invsplit_error
		INTO
			:v_upload_txn_id:ind_upload_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )387;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_upload_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_upload_txn_id;
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
  if (sqlca.sqlcode < 0) goto get_invsplit_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*upload_txn_id*/
		if(ind_upload_txn_id>=0){
			v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
			PutField_CString(myHash,"upload_txn_id",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetInvalidSplitReturn upload_txn_id= [%s]\n",v_upload_txn_id.arr));

			iRet = PD_FOUND;
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_invsplit_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )406;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_invsplit_error;
}



DEBUGLOG(("GetInvalidSplitReturn Normal Exit [%d]\n",iRet));
	return  iRet;

get_invsplit_error:
DEBUGLOG(("get_invsplit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get_invsplit_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )421;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}



int GetGenIdByUploadId(const int iBatchId, const char* csTxnId, recordset_t* myRec)
{
	int	iRet = PD_NOT_FOUND;
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO get_genidbyupid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_batch_id;
		/* varchar		hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

		int		hv_status;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short           ind_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_status= PAYOUT_MASTER_TRANSACTION_UPLOADED;

	hv_batch_id = iBatchId;
DEBUGLOG(("GetGenIdByUploadId batch_id = [%d]\n",hv_batch_id));

	hv_upload_txn_id.len = strlen(csTxnId);
        memcpy(hv_upload_txn_id.arr,csTxnId,hv_upload_txn_id.len);
DEBUGLOG(("GetGenIdByUploadId upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_get_genidbyupid_error CURSOR FOR
		select	prd_txn_id
		from	ol_payout_return_batch_dt
		where	prd_batch_id = :hv_batch_id
		and	prd_upload_txn_id = :hv_upload_txn_id
		and	prd_status = :hv_status; */ 


	/* EXEC SQL OPEN  c_cursor_get_genidbyupid_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )436;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto get_genidbyupid_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_get_genidbyupid_error
		INTO
			:v_txn_id:ind_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )463;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
  if (sqlca.sqlcode < 0) goto get_genidbyupid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetGenIdByUploadId txn_id= [%s]\n",v_txn_id.arr));

			iRet = PD_FOUND;
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_genidbyupid_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )482;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_genidbyupid_error;
}



DEBUGLOG(("GetGenIdByUploadId Normal Exit [%d]\n",iRet));
	return  iRet;

get_genidbyupid_error:
DEBUGLOG(("get_genidbyupid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get_genidbyupid_error; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )497;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}



int DeleteByTxnId(const char* csTxnId)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO deletebytxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar        	hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteByTxnId: Begin\n"));

/*txn_id*/
	hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("DeleteByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			delete 
			from	OL_PAYOUT_RETURN_BATCH_DT
			where	PRD_TXN_ID = :hv_txn_id;

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin delete from OL_PAYOUT_RETURN_BATCH_DT where PRD_TXN_I\
D = :hv_txn_id ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )512;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto deletebytxnid_error;
}



DEBUGLOG(("DeleteByTxnId: Finished\n"));
	return PD_OK;

deletebytxnid_error:
DEBUGLOG(("deletebytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_DeleteByTxnId: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}




int GetReturnDetailByStatus_API_ForUpdate(const char* csUploadTxnId, const int iStatus,recordset_t* myRec)
{
	int iRet = PD_OK;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getpayoutapi_forupd_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

		int		hv_status;

		int		v_batch_id;
		int		v_seq;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		double		v_amount;
		/* varchar		v_reason[PD_REASON_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_reason;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar		v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;


		short           ind_batch_id = -1;
		short           ind_seq = -1;
		short           ind_txn_id = -1;
		short           ind_account_name = -1;
		short           ind_account_num = -1;
		short		ind_amount = -1;
		short		ind_reason = -1;
		short		ind_country = -1;
		short		ind_ccy = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_upload_txn_id.len = strlen(csUploadTxnId);
        memcpy(hv_upload_txn_id.arr,csUploadTxnId,hv_upload_txn_id.len);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));

	hv_status= iStatus;
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getpayoutapi_forupd CURSOR FOR
		select	
			prd_batch_id,
			prd_seq,
			prd_txn_id,
			prd_account_name,
			prd_account_num,
			prd_amount,
			prd_reason,
			otd_txn_country,
			opr_request_currency
		from	ol_payout_return_batch_dt,
			ol_payout_request, ol_txn_detail
		where	prd_upload_txn_id = :hv_upload_txn_id
		and	prd_upload_txn_id = otd_txn_id
		and	prd_upload_txn_id = opr_txn_id 
		and	prd_status =:hv_status
		and	prd_is_valid = 1
		for update; */ 


	/* EXEC SQL OPEN  c_cursor_getpayoutapi_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )531;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
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
 if (sqlca.sqlcode < 0) goto getpayoutapi_forupd_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getpayoutapi_forupd
		INTO
			:v_batch_id:ind_batch_id,
			:v_seq:ind_seq,
			:v_txn_id:ind_txn_id,
			:v_account_name:ind_account_name,
			:v_account_num:ind_account_num,
			:v_amount:ind_amount,
			:v_reason:ind_reason,
			:v_country:ind_country,
			:v_ccy:ind_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )554;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[3] = (unsigned long )103;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_account_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[4] = (unsigned long )28;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_account_num;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_amount;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_reason;
  sqlstm.sqhstl[6] = (unsigned long )258;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_reason;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_country;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_ccy;
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
  if (sqlca.sqlcode < 0) goto getpayoutapi_forupd_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*batch_id*/
		if(ind_batch_id>=0){
			PutField_Int(myHash,"batch_id",v_batch_id);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate batch_id = [%d]\n",v_batch_id));
		}

/*seq*/
		if(ind_seq>=0){
			PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate seq = [%d]\n",v_seq));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate txn_id= [%s]\n",v_txn_id.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate account_name= [%s]\n",v_account_name.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate account_num= [%s]\n",v_account_num.arr));
		}

/*amount*/
		if(ind_amount>=0){
			PutField_Double(myHash,"amount",v_amount);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate amount = [%lf]\n",v_amount));
		}

/*reason*/
		if(ind_reason>=0){
			v_reason.arr[v_reason.len]='\0';
			PutField_CString(myHash,"reason",(const char*)v_reason.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate reason= [%s]\n",v_reason.arr));
		}

/*currency*/
		if(ind_ccy>=0){
			v_ccy.arr[v_ccy.len]='\0';
			PutField_CString(myHash,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate ccy = [%s]\n",v_ccy.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate country = [%s]\n",v_country.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpayoutapi_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )605;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayoutapi_forupd_error;
}



DEBUGLOG(("GetReturnDetailByStatus_API_ForUpdate Normal Exit\n"));
	return  iRet;

getpayoutapi_forupd_error:
DEBUGLOG(("getpayoutapi_forupd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturnBatchDt_GetReturnDetailByStatus_API_ForUpdate: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpayoutapi_forupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )620;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}
