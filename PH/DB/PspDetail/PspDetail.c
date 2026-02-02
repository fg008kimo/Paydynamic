
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "PspDetail.pc"
};


static unsigned int sqlctx = 325675;


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
   unsigned char  *sqhstv[19];
   unsigned long  sqhstl[19];
            int   sqhsts[19];
            short *sqindv[19];
            int   sqinds[19];
   unsigned long  sqharm[19];
   unsigned long  *sqharc[19];
   unsigned short  sqadto[19];
   unsigned short  sqtdso[19];
} sqlstm = {12,19};

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

 static char *sq0004 = 
"select psp_name , psp_merchant_id , psp_channel_code , client_id , txn_type\
 , currency_id , status , payout_split_limit , rej_small_delta_amt , override\
d_bank_code_channel , pid_group , nbxa_pid_group , psp_type , deposit_card_ty\
pe , deposit_ret_merch_succ_url , pd_allow_amt_diff , pd_restrict_deposit_ip \
, pd_daily_succ_txn_threshold , pd_psp_replicate_en from psp_detail where psp\
_id = :b0 and disabled = :b1            ";

 static char *sq0006 = 
"select psp_id , psp_name , psp_merchant_id , psp_channel_code , client_id ,\
 txn_type , status from psp_detail where disabled = :b0 and online_mode = :b1\
 and psp_type = :b2            ";

 static char *sq0007 = 
"select psp_detail . psp_id from psp_detail , psp_country , psp_master , ban\
k_mapping where psp_detail . disabled = :b0 and psp_detail . online_mode = :b\
1 and psp_detail . txn_type in ( 'A' , 'D' ) and psp_detail . psp_id = psp_co\
untry . psp_id and psp_detail . client_id = psp_master . pm_client_id and psp\
_country . country = :b2 and psp_detail . status = 'O' and psp_master . pm_st\
atus = 'O' and bm_psp_channel_id = NVL ( psp_detail . overrided_bank_code_cha\
nnel , psp_detail . psp_channel_code ) and bm_int_bank_code = :b3 and bm_disa\
bled = 0 order by psp_detail . psp_id            ";

 static char *sq0008 = 
"select payout_split_limit from psp_detail where psp_id = :b0 and disabled =\
 :b1 and txn_type in ( 'A' , 'P' ) and status = 'O'            ";

 static char *sq0009 = 
"select psp_id , psp_name , client_id , txn_type , currency_id , status , pa\
yout_split_limit , rej_small_delta_amt , overrided_bank_code_channel , pid_gr\
oup , nbxa_pid_group , psp_type , deposit_card_type from psp_detail where psp\
_channel_code = :b0 and psp_merchant_id = :b1 and disabled = :b2            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,341,0,6,166,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,
52,0,0,2,418,0,6,363,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,1,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
119,0,0,3,85,0,6,436,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
146,0,0,4,423,0,9,590,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
169,0,0,4,0,0,13,592,0,0,19,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
260,0,0,4,0,0,15,768,0,0,0,0,0,1,0,
275,0,0,4,0,0,15,779,0,0,0,0,0,1,0,
290,0,0,5,0,0,17,1052,0,0,1,1,0,1,0,1,9,0,0,
309,0,0,5,0,0,21,1053,0,0,0,0,0,1,0,
324,0,0,6,183,0,9,1130,0,2049,3,3,0,1,0,1,3,0,0,1,1,0,0,1,1,0,0,
351,0,0,6,0,0,13,1132,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
1,0,0,2,9,0,0,
394,0,0,6,0,0,15,1206,0,0,0,0,0,1,0,
409,0,0,6,0,0,15,1224,0,0,0,0,0,1,0,
424,0,0,7,586,0,9,1282,0,2049,4,4,0,1,0,1,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
455,0,0,7,0,0,13,1284,0,0,1,0,0,1,0,2,9,0,0,
474,0,0,7,0,0,15,1309,0,0,0,0,0,1,0,
489,0,0,7,0,0,15,1327,0,0,0,0,0,1,0,
504,0,0,8,138,0,9,1363,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
527,0,0,8,0,0,13,1365,0,0,1,0,0,1,0,2,4,0,0,
546,0,0,8,0,0,15,1386,0,0,0,0,0,1,0,
561,0,0,8,0,0,15,1397,0,0,0,0,0,1,0,
576,0,0,5,0,0,17,1444,0,0,1,1,0,1,0,1,9,0,0,
595,0,0,5,0,0,21,1445,0,0,0,0,0,1,0,
610,0,0,9,305,0,9,1533,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,
637,0,0,9,0,0,13,1535,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,
704,0,0,9,0,0,15,1647,0,0,0,0,0,1,0,
719,0,0,9,0,0,15,1658,0,0,0,0,0,1,0,
734,0,0,5,0,0,17,1706,0,0,1,1,0,1,0,1,9,0,0,
753,0,0,5,0,0,21,1707,0,0,0,0,0,1,0,
768,0,0,5,0,0,17,1767,0,0,1,1,0,1,0,1,9,0,0,
787,0,0,5,0,0,21,1768,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/02              [GOD]
Add Primary Key client_id, delete key		   2011/01/07		   [MSN]
Add GetPspDetailByType                             2011/11/21              [SWK]
Add support_delta_amt & rej_small_delta_amt	   2013/03/19		   [WCS]
Delete support_delta_amt			   2013/04/15		   [MSN]
Add rej_small_delta_amt				   2013/04/16		   [STP]
Add psp_remark					   2013/06/13		   [SWK]
Add overrided_bank_code_channel			   2013/06/14		   [GOD]
Add processor_name                                 2013/09/02              [SWK]
Add pid_group					   2013/10/29		   [MSN]
Add MOB_CHANNEL_FE_DISPLAY                         2015/08/26              [MSN]
Add UpdateRemark2NULL				   2015/12/14		   [WMC]
Amend Update to handle				   2016/09/29              [WMC]
        update card_type
Amend GetPspDetail to handle
        get card_type
Add UpdateNBXAPIDGroup2NULL                        2017/07/17              [WMC]
Amend GetPspDetail,
      GetPspDetailByChannelMerchId,
      Update
Add UpdatePIDGroup2NULL                            2017/07/17              [WWK]
PRD151 add 5 fields for PSP Account Update         2018/09/11              [TNY]
PRD281 add a field settle_prd_str		   2020/08/06              [ANC]
Add deposit_ret_merch_succ_url in		   2020/10/15		   [WMC]
	Update()
	GetPspDetail()
PRD290 add field allow_amt_diff in		   2020/11/18		   [ANC] 
	Update(), 
	GetPspDetail()
PRD021 add field restrict_deposit_ip in 
	- Update
	- GetPspDetail                             2021/01/18              [ZBL]
PRD304 Add field Enable Daily Success Txn Threshold		   2021/03/18         [ANC]
	Update(), 
	GetPspDetail()
PRD332 add field psp_merchant_id in Update         2021/07/29              [ZBL]
       Add Replicate                               2021/07/29              [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PspDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define MAX_MAX_DEPOSIT_LEN 18
#define MAX_TXN_AMT_LMT_LEN 12

static char    cDebug;

void PspDetail(char    cdebug)
{
        cDebug = cdebug;
}




int Replicate(const hash_t *hPspDetail)
{
	char            *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO replicate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_replicate_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_replicate_psp_id;

		/* varchar		hv_create_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_create_psp_id;

		/* varchar		hv_psp_name[PD_PSP_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_name;

		/* varchar		hv_processor_name[PD_PROCESSOR_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_processor_name;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar		hv_psp_merchant_id[PD_PSP_MID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_merchant_id;

		/* varchar		hv_overrided_bank_code_channel[PD_OVERRIDED_BANK_CODE_CHANNEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_overrided_bank_code_channel;


		short		ind_replicate_psp_id = -1;
		short		ind_create_psp_id = -1;
		short		ind_psp_name = -1;
		short		ind_processor_name = -1;
		short		ind_create_user = -1;
		short		ind_psp_merchant_id = -1;
		short		ind_oride_bank_code_channel = -1;
		
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Replicate: Begin\n"));

	if(GetField_CString(hPspDetail,"replicate_psp_id",&csTmp))
	{
		hv_replicate_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_replicate_psp_id.arr, csTmp, hv_replicate_psp_id.len);
		ind_replicate_psp_id = 0;
	}
DEBUGLOG(("Replicate:replicate_psp_id = [%.*s]\n",hv_replicate_psp_id.len,hv_replicate_psp_id.arr));

	if(GetField_CString(hPspDetail,"create_psp_id",&csTmp))
	{
		hv_create_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_create_psp_id.arr, csTmp, hv_create_psp_id.len);
		ind_create_psp_id = 0;
	}
DEBUGLOG(("Replicate:create_psp_id = [%.*s]\n",hv_create_psp_id.len,hv_create_psp_id.arr));


	if(GetField_CString(hPspDetail,"psp_name",&csTmp))
	{
		hv_psp_name.len = strlen(csTmp);
		strncpy((char*)hv_psp_name.arr, csTmp, hv_psp_name.len);
		ind_psp_name = 0;
	}
DEBUGLOG(("Replicate:psp_name = [%.*s]\n",hv_psp_name.len,hv_psp_name.arr));


	if(GetField_CString(hPspDetail,"processor_name",&csTmp))
	{
		hv_processor_name.len = strlen(csTmp);
		strncpy((char*)hv_processor_name.arr, csTmp, hv_processor_name.len);
DEBUGLOG(("Replicate:processor_name = [%.*s]\n",hv_processor_name.len,hv_processor_name.arr));
		ind_processor_name = 0;
	}
	
	
	if(GetField_CString(hPspDetail,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Replicate:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	if(GetField_CString(hPspDetail,"psp_merchant_id",&csTmp))
	{
		hv_psp_merchant_id.len = strlen(csTmp);
		strncpy((char*)hv_psp_merchant_id.arr, csTmp, hv_psp_merchant_id.len);
		ind_psp_merchant_id= 0;
DEBUGLOG(("Replicate:psp_merchant_id = [%.*s]\n",hv_psp_merchant_id.len,hv_psp_merchant_id.arr));
	}

	if(GetField_CString(hPspDetail,"oride_bank_code_channel",&csTmp))
	{
		hv_overrided_bank_code_channel.len = strlen(csTmp);
		strncpy((char*)hv_overrided_bank_code_channel.arr, csTmp, hv_overrided_bank_code_channel.len);
		ind_oride_bank_code_channel= 0;
DEBUGLOG(("Replicate:oride_bank_code_channel = [%.*s]\n",hv_overrided_bank_code_channel.len,hv_overrided_bank_code_channel.arr));
	}

	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_psp_detail_rpl(
				:hv_replicate_psp_id:ind_replicate_psp_id,
				:hv_create_psp_id:ind_create_psp_id,
				:hv_psp_name:ind_psp_name,
				:hv_processor_name:ind_processor_name,
				:hv_create_user:ind_create_user,
				:hv_psp_merchant_id:ind_psp_merchant_id,
				:hv_overrided_bank_code_channel:ind_oride_bank_code_channel
				);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_detail_rpl ( :hv_replicate\
_psp_id:ind_replicate_psp_id , :hv_create_psp_id:ind_create_psp_id , :hv_psp_\
name:ind_psp_name , :hv_processor_name:ind_processor_name , :hv_create_user:i\
nd_create_user , :hv_psp_merchant_id:ind_psp_merchant_id , :hv_overrided_bank\
_code_channel:ind_oride_bank_code_channel ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_replicate_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_replicate_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_create_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_create_psp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_name;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_psp_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_processor_name;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_processor_name;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_create_user;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_psp_merchant_id;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_psp_merchant_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_overrided_bank_code_channel;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_oride_bank_code_channel;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto replicate_error;
}




	DEBUGLOG(("Replicate:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Replicate:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspDetail_Replicate: SP_OTHER_ERR \n");
		DEBUGLOG(("Replicate: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspDetail_Replicate: SP_ERR \n");
		DEBUGLOG(("Replicate: SP_ERR \n"));
		return PD_ERR;
	}

	if (hv_return_value == SP_NOT_FOUND)  {
		ERRLOG("PspDetail_Replicate: SP_NOT_FOUND \n");
		DEBUGLOG(("Replicate: SP_NOT_FOUND \n"));
		return PD_NOT_FOUND;
	}

replicate_error:
DEBUGLOG(("replicate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Replicate: SP_INTERNAL_ERR \n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}





int Add(const hash_t *hPspDetail)
{
	char            *csTmp;
	char		cTmp;
	int		iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_psp_name[PD_PSP_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_name;

		char		hv_psp_type;
		char		hv_online_mode;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_psp_merchant_id[PD_PSP_MID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_merchant_id;

		/* varchar		hv_psp_channel_code[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_channel_code;

		int		hv_disabled;
		char		hv_txn_type;
		/* varchar		hv_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;


		short		ind_psp_id = -1;
		short		ind_psp_name = -1;
		short		ind_psp_type = -1;
		short		ind_online_mode = -1;
		short		ind_create_user = -1;
		short		ind_client_id= -1;
		short		ind_psp_merchant_id = -1;
		short		ind_psp_channel_code = -1;
		short		ind_txn_type = -1;
		short		ind_status = -1;
		short		ind_ccy = -1;
		short		ind_disabled = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hPspDetail,"psp_id",&csTmp))
	{
		hv_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
	}
DEBUGLOG(("Add:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));


	if(GetField_CString(hPspDetail,"psp_name",&csTmp))
	{
		hv_psp_name.len = strlen(csTmp);
		strncpy((char*)hv_psp_name.arr, csTmp, hv_psp_name.len);
		ind_psp_name = 0;
	}
DEBUGLOG(("Add:psp_name = [%.*s]\n",hv_psp_name.len,hv_psp_name.arr));

	if(GetField_CString(hPspDetail,"ccy",&csTmp))
	{
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
		ind_ccy= 0;
	}
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

	if(GetField_Char(hPspDetail,"psp_type",&cTmp))
	{
		hv_psp_type = cTmp;
		ind_psp_type = 0;
DEBUGLOG(("Add:psp_type = [%c]\n",hv_psp_type));
	}

	if(GetField_Char(hPspDetail,"txn_type",&cTmp))
	{
		hv_txn_type = cTmp;
		ind_txn_type = 0;
DEBUGLOG(("Add:txn_type = [%c]\n",hv_txn_type));
	}

	if(GetField_Char(hPspDetail,"online",&cTmp))
	{
		hv_online_mode = cTmp;
		ind_online_mode = 0;
	}

DEBUGLOG(("Add:online = [%c]\n",hv_online_mode));

	if(GetField_CString(hPspDetail,"status",&csTmp))
	{
		hv_status.len = strlen(csTmp);
		strncpy((char*)hv_status.arr, csTmp, hv_status.len);
		ind_status= 0;
	}
DEBUGLOG(("Add:status= [%.*s]\n",hv_status.len,hv_status.arr));

	if(GetField_CString(hPspDetail,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	if(GetField_CString(hPspDetail,"client_id",&csTmp))
	{
		hv_client_id.len = strlen(csTmp);
		strncpy((char*)hv_client_id.arr, csTmp, hv_client_id.len);
		ind_client_id= 0;
	}
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));

	if(GetField_CString(hPspDetail,"psp_merchant_id",&csTmp))
	{
		hv_psp_merchant_id.len = strlen(csTmp);
		strncpy((char*)hv_psp_merchant_id.arr, csTmp, hv_psp_merchant_id.len);
		ind_psp_merchant_id= 0;
DEBUGLOG(("Add:psp_merchant_id = [%.*s]\n",hv_psp_merchant_id.len,hv_psp_merchant_id.arr));
	}

	if(GetField_CString(hPspDetail,"psp_channel_code",&csTmp))
	{
		hv_psp_channel_code.len = strlen(csTmp);
		strncpy((char*)hv_psp_channel_code.arr, csTmp, hv_psp_channel_code.len);
		ind_psp_channel_code= 0;
	}
DEBUGLOG(("Add:psp_channel_code = [%.*s]\n",hv_psp_channel_code.len,hv_psp_channel_code.arr));

	if(GetField_Int(hPspDetail,"disabled",&iTmp))
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));


	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_psp_detail_insert(
				:hv_psp_id:ind_psp_id,
				:hv_psp_name:ind_psp_name,
				:hv_disabled:ind_disabled,
				:hv_online_mode:ind_online_mode,
				:hv_psp_type:ind_psp_type,
				:hv_create_user:ind_create_user,
				:hv_client_id:ind_client_id,
				:hv_psp_merchant_id:ind_psp_merchant_id,
				:hv_psp_channel_code:ind_psp_channel_code,
				:hv_txn_type:ind_txn_type,
				:hv_ccy:ind_ccy,
				:hv_status:ind_status);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_detail_insert ( :hv_psp_id\
:ind_psp_id , :hv_psp_name:ind_psp_name , :hv_disabled:ind_disabled , :hv_onl\
ine_mode:ind_online_mode , :hv_psp_type:ind_psp_type , :hv_create_user:ind_cr\
eate_user , :hv_client_id:ind_client_id , :hv_psp_merchant_id:ind_psp_merchan\
t_id , :hv_psp_channel_code:ind_psp_channel_code , :hv_txn_type:ind_txn_type \
, :hv_ccy:ind_ccy , :hv_status:ind_status ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )52;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_name;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_psp_name;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_online_mode;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_online_mode;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_psp_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[7] = (unsigned long )12;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_client_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_psp_merchant_id;
 sqlstm.sqhstl[8] = (unsigned long )52;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_psp_merchant_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_psp_channel_code;
 sqlstm.sqhstl[9] = (unsigned long )12;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_psp_channel_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[10] = (unsigned long )1;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_txn_type;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[11] = (unsigned long )5;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_ccy;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[12] = (unsigned long )4;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_status;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
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
		ERRLOG("PspDetail_Add: SP_OTHER_ERR \n");
		DEBUGLOG(("Add: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspDetail_Add: SP_ERR \n");
		DEBUGLOG(("Add: SP_ERR \n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Add: SP_INTERNAL_ERR \n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}



int Delete(const unsigned char* psp_id, const unsigned char* client_id)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;


		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((const char*)psp_id);
	memcpy(hv_psp_id.arr,psp_id,hv_psp_id.len);
DEBUGLOG(("Delete: psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	hv_client_id.len = strlen((const char*)client_id);
	memcpy(hv_client_id.arr,client_id,hv_client_id.len);
DEBUGLOG(("Delete: client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));

	/* EXEC SQL EXECUTE
	    BEGIN
		
		:hv_return_value := sp_psp_detail_delete(
				:hv_psp_id,
				:hv_client_id);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_psp_detail_delete ( :hv_psp_id\
 , :hv_client_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )119;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




	DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Delete:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspDetail_Delete: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspDetail_Delete: SP_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Delete: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int GetPspDetail(const char* csPspId,
                hash_t* hRec)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO getpspdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                int             hv_disabled;
		//char		hv_online_mode;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

                /* varchar         v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

                /* varchar         v_psp_merchant_id[PD_PSP_MID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_merchant_id;

                /* varchar         v_psp_channel_code[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_channel_code;

                /* varchar         v_client_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                /* varchar         v_overrided_bank_code_channel[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_overrided_bank_code_channel;

/*
		int             v_precal_fee;
                char            v_precal_type;
                double          v_precal_value;
                double          v_precal_additional_value;
*/
		char		v_txn_type;
		char		v_psp_type;
		/* varchar		v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double          v_payout_split_limit;
		//int		v_support_delta_amt;
		int		v_rej_small_delta_amt;
                /* varchar         v_pid_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_group;

                /* varchar         v_nbxa_pid_group[PD_NBXA_PID_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_nbxa_pid_group;

		char            v_card_type;
		int		v_ret_merch_succ_url;
		int		v_allow_amt_diff;	
		/* PRD021 Non-China IP */
		int		v_restrict_deposit_ip;
		/* End - PRD021 Non-China IP */
		/* PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
		int		v_daily_succ_txn_threshold;
		/* End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
		int		v_pd_psp_replicate_en;
		
		
		short		ind_status = -1;
                short           ind_name = -1;
		short		ind_psp_merchant_id = -1;
		short		ind_psp_channel_code = -1;
                short           ind_client_id = -1;
                short         	ind_overrided_bank_code_channel = -1;
/*
		short           ind_precal_fee = -1;
                short           ind_precal_type = -1;
                short           ind_precal_value = -1;
                short           ind_precal_additional_value = -1;
*/
		short		ind_txn_type = -1;
		short		ind_psp_type = -1;
		short		ind_ccy = -1;
		short           ind_payout_split_limit = -1;
		//short		ind_support_delta_amt = -1;
		short		ind_rej_small_delta_amt = -1;
                short           ind_pid_group = -1;
                short           ind_nbxa_pid_group = -1;
		short		ind_card_type;
		short		ind_ret_merch_succ_url = -1;
                short           ind_allow_amt_diff = -1;
		/* PRD021 Non-China IP */
		short		ind_restrict_deposit_ip = -1;
		/* End - PRD021 Non-China IP */
		/* PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
		short		ind_daily_succ_txn_threshold = -1;
		/* End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
		short		ind_pd_psp_replicate_en = -1;
		
		
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetPspDetail psp_id = [%d][%.*s]\n",hv_psp_id.len,hv_psp_id.len,hv_psp_id.arr));

	hv_disabled = 0;
	//hv_online_mode = PD_ONLINE_MODE;

        /* EXEC SQL DECLARE c_cursor_getpspdetail CURSOR FOR
                select psp_name,
		       psp_merchant_id,
		       psp_channel_code,
		       client_id,
		       txn_type,
		       currency_id,
		       status,
		       payout_split_limit,
		       //support_delta_amt,
		       rej_small_delta_amt,
		       overrided_bank_code_channel,
		       pid_group,
		       nbxa_pid_group,
		       psp_type,
		       deposit_card_type,
		       deposit_ret_merch_succ_url,
		       pd_allow_amt_diff, 
		       /o PRD021 Non-China IP o/
		       pd_restrict_deposit_ip,
		       /o End - PRD021 Non-China IP o/
			   /o PRD304 Assign PID Based on PID Daily Threshold and Customer ID o/
			   pd_daily_succ_txn_threshold,
			   /o End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID o/
               pd_psp_replicate_en
                  from psp_detail
                 where psp_id = :hv_psp_id
		 and   disabled = :hv_disabled; */ 

		 //and   online_mode = :hv_online_mode;

        /* EXEC SQL OPEN c_cursor_getpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )146;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
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
        if (sqlca.sqlcode < 0) goto getpspdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpspdetail
                INTO
                        :v_name:ind_name,
			:v_psp_merchant_id:ind_psp_merchant_id,
			:v_psp_channel_code:ind_psp_channel_code,
			:v_client_id:ind_client_id,
			:v_txn_type:ind_txn_type,
			:v_ccy:ind_ccy,
			:v_status:ind_status,
			:v_payout_split_limit:ind_payout_split_limit,
			//:v_support_delta_amt:ind_support_delta_amt,
			:v_rej_small_delta_amt:ind_rej_small_delta_amt,
			:v_overrided_bank_code_channel:ind_overrided_bank_code_channel,
			:v_pid_group:ind_pid_group,
			:v_nbxa_pid_group:ind_nbxa_pid_group,
			:v_psp_type:ind_psp_type,
			:v_card_type:ind_card_type,
			:v_ret_merch_succ_url:ind_ret_merch_succ_url,
                        :v_allow_amt_diff:ind_allow_amt_diff, 
			/o PRD021 Non-China IP o/
			:v_restrict_deposit_ip:ind_restrict_deposit_ip,
			/o End - PRD021 Non-China IP o/
			/o PRD304 Assign PID Based on PID Daily Threshold and Customer ID o/
			:v_daily_succ_txn_threshold:ind_daily_succ_txn_threshold,
			/o End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID o/
			:v_pd_psp_replicate_en:ind_pd_psp_replicate_en
			; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )169;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_name;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_channel_code;
                sqlstm.sqhstl[2] = (unsigned long )13;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_psp_channel_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_type;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ccy;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[6] = (unsigned long )5;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_payout_split_limit;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_payout_split_limit;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_rej_small_delta_amt;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_rej_small_delta_amt;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_overrided_bank_code_channel;
                sqlstm.sqhstl[9] = (unsigned long )13;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_overrided_bank_code_channel;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_pid_group;
                sqlstm.sqhstl[10] = (unsigned long )13;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_pid_group;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_nbxa_pid_group;
                sqlstm.sqhstl[11] = (unsigned long )23;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_nbxa_pid_group;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_psp_type;
                sqlstm.sqhstl[12] = (unsigned long )1;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_psp_type;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_card_type;
                sqlstm.sqhstl[13] = (unsigned long )1;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_card_type;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_ret_merch_succ_url;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_ret_merch_succ_url;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_allow_amt_diff;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_allow_amt_diff;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_restrict_deposit_ip;
                sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_restrict_deposit_ip;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_daily_succ_txn_threshold;
                sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_daily_succ_txn_threshold;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_pd_psp_replicate_en;
                sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_pd_psp_replicate_en;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getpspdetail_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


DEBUGLOG(("GetPspDetail found record\n"));

/* psp name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(hRec,"psp_name",(const char*)v_name.arr);
DEBUGLOG(("GetPspDetail psp_name = [%s]\n",v_name.arr));
                }


/* psp merchant id */
                if (ind_psp_merchant_id >= 0) {
                        v_psp_merchant_id.arr[v_psp_merchant_id.len] = '\0';
                        PutField_CString(hRec,"psp_merchant_id",(const char*)v_psp_merchant_id.arr);
DEBUGLOG(("GetPspDetail psp_merchant_id = [%s]\n",v_psp_merchant_id.arr));
                }

/* psp channel code */
                if (ind_psp_channel_code >= 0) {
                        v_psp_channel_code.arr[v_psp_channel_code.len] = '\0';
                        PutField_CString(hRec,"psp_channel_code",(const char*)v_psp_channel_code.arr);
DEBUGLOG(("GetPspDetail psp_channel_code = [%s]\n",v_psp_channel_code.arr));
                }

/* client_id*/
                if (ind_client_id>= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(hRec,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetPspDetail client_id = [%s]\n",v_client_id.arr));
                }

/* txn_type */
                if (ind_txn_type>= 0) {
                        PutField_Char(hRec,"txn_type",v_txn_type);
DEBUGLOG(("GetPspDetail txn_type = [%c]\n",v_txn_type));
                }
/* ccy*/
                if (ind_ccy>= 0) {
                        v_ccy.arr[v_ccy.len] = '\0';
                        PutField_CString(hRec,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetPspDetail ccy = [%s]\n",v_ccy.arr));
                }

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(hRec,"status",(const char*)v_status.arr);
DEBUGLOG(("GetPspDetail status = [%s]\n",v_status.arr));
                }

/* payout_split_limit */
                if (ind_payout_split_limit < 0)
                        v_payout_split_limit = 0.0;
                PutField_Double(hRec,"payout_split_limit",v_payout_split_limit);
DEBUGLOG(("GetPspDetail payout_split_limit = [%lf]\n",v_payout_split_limit));

/* support_delta_amt */
/*
		if (ind_support_delta_amt >= 0) {
			PutField_Int(hRec,"support_delta_amt",v_support_delta_amt);
DEBUGLOG(("GetPspDetail support_delta_amt = [%d]\n",v_support_delta_amt));
		}
*/

/* rej_small_delta_amt */
		if (ind_rej_small_delta_amt >= 0) {
			PutField_Int(hRec,"rej_small_delta_amt",v_rej_small_delta_amt);
DEBUGLOG(("GetPspDetail rej_small_delta_amt = [%d]\n",v_rej_small_delta_amt));
		}

/* overrided bank code channel code */
                if (ind_overrided_bank_code_channel >= 0) {
                        v_overrided_bank_code_channel.arr[v_overrided_bank_code_channel.len] = '\0';
                        PutField_CString(hRec,"overrided_bank_code_channel",(const char*)v_overrided_bank_code_channel.arr);
DEBUGLOG(("GetPspDetail overrided_bank_code_channel = [%s]\n",v_overrided_bank_code_channel.arr));
                }

/* pid_group */
                if (ind_pid_group>= 0) {
                        v_pid_group.arr[v_pid_group.len] = '\0';
                        PutField_CString(hRec,"pid_group",(const char*)v_pid_group.arr);
DEBUGLOG(("GetPspDetail pid_group = [%s]\n",v_pid_group.arr));
                }

/* nbxa_pid_group */
                if (ind_nbxa_pid_group>= 0) {
                        v_nbxa_pid_group.arr[v_nbxa_pid_group.len] = '\0';
                        PutField_CString(hRec,"nbxa_pid_group",(const char*)v_nbxa_pid_group.arr);
DEBUGLOG(("GetPspDetail nbxa_pid_group = [%s]\n",v_nbxa_pid_group.arr));
                }

/* psp_type */
                if (ind_psp_type>= 0) {
                        PutField_Char(hRec,"psp_type",v_psp_type);
DEBUGLOG(("GetPspDetail psp_type = [%c]\n",v_psp_type));
                }

/* card_type */
                if (ind_card_type>= 0) {
                        PutField_Char(hRec,"card_type",v_card_type);
DEBUGLOG(("GetPspDetail card_type = [%c]\n",v_card_type));
                }

/* ret_merch_succ_url */
		if (ind_ret_merch_succ_url >= 0) {
                        PutField_Int(hRec,"ret_merch_succ_url",v_ret_merch_succ_url);
DEBUGLOG(("GetPspDetail ret_merch_succ_url = [%d]\n",v_ret_merch_succ_url));
                }

/* allow_amt_diff */
		if (ind_allow_amt_diff >= 0) {
                        PutField_Int(hRec,"allow_amt_diff",v_allow_amt_diff);
DEBUGLOG(("GetPspDetail allow_amt_diff = [%d]\n",v_allow_amt_diff));
                }

/* PRD021 Non-China IP */
/* restrict_deposit_ip */
		if (ind_restrict_deposit_ip >= 0)
		{
			PutField_Int(hRec, "restrict_deposit_ip", v_restrict_deposit_ip);
DEBUGLOG(("GetPspDetail restrict_deposit_ip = [%d]\n", v_restrict_deposit_ip));
		}
/* End - PRD021 Non-China IP */
/* PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
/* daily_succ_txn_threshold */
		if (ind_daily_succ_txn_threshold >= 0) {
			PutField_Int(hRec, "daily_succ_txn_threshold", v_daily_succ_txn_threshold);
DEBUGLOG(("GetPspDetail daily_succ_txn_threshold = [%d]\n", v_daily_succ_txn_threshold));
		}
/* End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID */


/* psp_replicate_en */
		if (ind_pd_psp_replicate_en >= 0) {
			PutField_Int(hRec, "psp_replicate_en", v_pd_psp_replicate_en);
DEBUGLOG(("GetPspDetail psp_replicate_en = [%d]\n", v_pd_psp_replicate_en));
		}


        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )260;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspdetail_error;
}




DEBUGLOG(("GetPspDetail Normal Exit\n"));
        return  PD_OK;

getpspdetail_error:
DEBUGLOG(("getpspdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )275;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int Update(const hash_t *hRls)
{
        char*   csTmp; 
        char*   csPspId;
	char	cTmp;
	int	iTmp;
	long	lTmp;
	double  dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

        
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	csTmp = (char*)malloc(PD_TMP_BUF_LEN);

        strcpy((char*)hv_dynstmt.arr, "update psp_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls, "psp_id", &csPspId);
DEBUGLOG(("Update:psp_id = [%s]\n", csPspId));
        

/* Status */
        if (GetField_CString(hRls, "status", &csTmp)) {
DEBUGLOG(("Update:status = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", status = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* psp_name*/
        if (GetField_CString(hRls, "psp_name", &csTmp)) {
DEBUGLOG(("Update:psp_name = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", psp_name = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_type */
        if (GetField_CString(hRls, "txn_type" ,&csTmp)) {
DEBUGLOG(("Update:txn_type = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", txn_type = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* payout_split_limit */
	if (GetField_Int(hRls, "payout_split_limit", &iTmp)) {
DEBUGLOG(("Update:payout_split_limit = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

                strcat((char*)hv_dynstmt.arr, ", payout_split_limit = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* rej_small_delta_amt */
	if (GetField_Int(hRls, "rej_small_delta_amt", &iTmp)) {
DEBUGLOG(("Update:rej_small_delta_amt = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

                strcat((char*)hv_dynstmt.arr, ", rej_small_delta_amt = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* psp_remark */
	if (GetField_CString(hRls, "psp_remark", &csTmp)) {
DEBUGLOG(("Update:psp_remark = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", psp_remark = '");
                /* strcat((char*)hv_dynstmt.arr, csTmp); */
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* processor_name */
	if (GetField_CString(hRls, "processor_name", &csTmp)) {
DEBUGLOG(("Update:processor_name = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ", processor_name = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
/* pid_group */
	if (GetField_CString(hRls, "pid_group", &csTmp)) {
DEBUGLOG(("Update:pid_group = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ", pid_group = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
/* mob_channel_fe_display */
	if (GetField_CString(hRls, "mob_channel_fe_display", &csTmp)) {
DEBUGLOG(("Update:mob_channel_fe_display = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", mob_channel_fe_display = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
/* card_type */
        if (GetField_Char(hRls, "card_type", &cTmp)) {
DEBUGLOG(("Update:card_type = [%c]\n", cTmp));
                sprintf(csTmp, "%c", cTmp);

                strcat((char*)hv_dynstmt.arr, ", deposit_card_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* nbxa_pid_group */
        if (GetField_CString(hRls, "nbxa_pid_group", &csTmp)) {
DEBUGLOG(("Update:nbxa_pid_group = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ", nbxa_pid_group = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", update_user = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* PRD151 PSP Account Update */
/*backend*/
        if (GetField_CString(hRls, "backend", &csTmp)) {
DEBUGLOG(("Update:backend = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", pd_backend = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*txn_amt_lmt*/
        if (GetField_Long(hRls, "txn_amt_lmt", &lTmp)) {
DEBUGLOG(("Update:txn_amt_lmt = [%ld]\n", lTmp));
		ltoc(lTmp, MAX_TXN_AMT_LMT_LEN, (unsigned char *)csTmp);

                strcat((char*)hv_dynstmt.arr, ", pd_txn_amt_lmt = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*settle_prd*/
        if (GetField_CString(hRls, "settle_prd", &csTmp)) {
DEBUGLOG(("Update:settle_prd = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", pd_settle_period = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*add_cost*/
        if (GetField_Double(hRls, "add_cost", &dTmp)) {
DEBUGLOG(("Update:add_cost = [%.2f]\n", dTmp));
		sprintf(csTmp, "%.2f", dTmp);

                strcat((char*)hv_dynstmt.arr, ", pd_add_cost = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*max_deposit*/
        if (GetField_Long(hRls, "max_deposit", &lTmp)) {
DEBUGLOG(("Update:max_deposit = [%ld]\n", lTmp));
		ltoc(lTmp, MAX_MAX_DEPOSIT_LEN, (unsigned char *)csTmp);

                strcat((char*)hv_dynstmt.arr, ", pd_max_deposit = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* End - PRD151 PSP Account Update */

/* PRD281 PSP Account Settlement Period Setting Enhancement */
/*settle_prd_str*/
        if (GetField_CString(hRls, "settle_prd_str", &csTmp)) {
DEBUGLOG(("Update:settle_prd_str = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ", pd_settle_period_str = '");
                strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* End - PRD281 PSP Account Settlement Period Setting Enhancement */

/* ret_merch_succ_url */
	if (GetField_Int(hRls, "ret_merch_succ_url", &iTmp)) {
DEBUGLOG(("Update:ret_merch_succ_url = [%d]\n", iTmp));
                sprintf(csTmp, "%d", iTmp);

                strcat((char*)hv_dynstmt.arr, ", deposit_ret_merch_succ_url = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* allow_amt_diff */
        if (GetField_Int(hRls, "allow_amt_diff", &iTmp)) {
DEBUGLOG(("Update:allow_amt_diff = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);
				
                strcat((char*)hv_dynstmt.arr, ", pd_allow_amt_diff = ");
                strcat((char*)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* PRD021 Non-China IP */
/* restrict_deposit_ip */
	if (GetField_Int(hRls, "restrict_deposit_ip", &iTmp))
	{
DEBUGLOG(("Update:restrict_deposit_ip = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

		strcat((char*)hv_dynstmt.arr, ", pd_restrict_deposit_ip = ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* End - PRD021 Non-China IP */

/* PRD304 Assign PID Based on PID Daily Threshold and Customer ID */
/* daily_succ_txn_threshold */
	if (GetField_Int(hRls, "daily_succ_txn_threshold", &iTmp))
	{
DEBUGLOG(("Update:daily_succ_txn_threshold = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

		strcat((char*)hv_dynstmt.arr, ", pd_daily_succ_txn_threshold = ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* End - PRD304 Assign PID Based on PID Daily Threshold and Customer ID */

/* PRD332 Create Online PID */
/* psp_merchant_id */
	if (GetField_CString(hRls, "psp_merchant_id", &csTmp))
	{
DEBUGLOG(("Update:psp_merchant_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", psp_merchant_id = '");
		strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* End - PRD332 Create Online PID */

        strcat((char*)hv_dynstmt.arr, " WHERE psp_id = '");
        strcat((char*)hv_dynstmt.arr, ESC_string(csPspId));
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )290;
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
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )309;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csTmp);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("PspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;       
}


int GetPspDetailByType(const char cType,
	               recordset_t *myRec)	
{
	int	iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getpspdetailbytype_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             hv_disabled;
		char		hv_online_mode;
                char            hv_type;
		//varchar		hv_st_psp_id[PD_PSP_ID_LEN + 1];

                /* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

                /* varchar         v_psp_merchant_id[PD_PSP_MID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_merchant_id;

                /* varchar         v_psp_channel_code[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_channel_code;

                /* varchar         v_client_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		char		v_txn_type;
		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;


                short           ind_psp_id = -1; 
                short           ind_name = -1;
		short		ind_psp_merchant_id = -1;
		short		ind_psp_channel_code = -1;
                short           ind_client_id = -1;
		short		ind_txn_type = -1;
		short		ind_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_type = cType;
DEBUGLOG(("GetPspDetailByType type = [%c]\n",hv_type));

	hv_disabled = 0;
	hv_online_mode = PD_ONLINE_MODE;
DEBUGLOG(("GetPspDetailByType hv_online_mode [%c]\n", hv_online_mode));

/*
        hv_st_psp_id.len = strlen(csPspId);
        memcpy(hv_st_psp_id.arr,csPspId,hv_st_psp_id.len);
DEBUGLOG(("GetPspDetailByType st_psp_id = [%d][%.*s]\n",hv_st_psp_id.len,hv_st_psp_id.len,hv_st_psp_id.arr));
*/

	/* EXEC SQL DECLARE c_cursor_getpspdetailbytype CURSOR FOR
		select psp_id,
			psp_name,
			psp_merchant_id,
			psp_channel_code,
			client_id,
			txn_type,
			status
		from	psp_detail
		where	disabled = :hv_disabled
		and	online_mode = :hv_online_mode
		and	psp_type = :hv_type; */ 

			
        /* EXEC SQL OPEN c_cursor_getpspdetailbytype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )324;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_online_mode;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto getpspdetailbytype_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpspdetailbytype
                INTO
			:v_psp_id:ind_psp_id,
                        :v_name:ind_name,
			:v_psp_merchant_id:ind_psp_merchant_id,
			:v_psp_channel_code:ind_psp_channel_code,
			:v_client_id:ind_client_id,
			:v_txn_type:ind_txn_type,
			:v_status:ind_status; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )351;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_merchant_id;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_psp_merchant_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_channel_code;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_psp_channel_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[4] = (unsigned long )13;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_client_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[5] = (unsigned long )1;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[6] = (unsigned long )5;
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
                if (sqlca.sqlcode < 0) goto getpspdetailbytype_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		myHash = (hash_t*) malloc(sizeof(hash_t));
		hash_init(myHash, 0);


/* psp id */
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPspDetailByType psp_id = [%s]\n",v_psp_id.arr));
                }
/* psp name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(myHash,"psp_name",(const char*)v_name.arr);
DEBUGLOG(("GetPspDetailByType psp_name = [%s]\n",v_name.arr));
                }


/* psp merchant id */
                if (ind_psp_merchant_id >= 0) {
                        v_psp_merchant_id.arr[v_psp_merchant_id.len] = '\0';
                        PutField_CString(myHash,"psp_merchant_id",(const char*)v_psp_merchant_id.arr);
DEBUGLOG(("GetPspDetailByType psp_merchant_id = [%s]\n",v_psp_merchant_id.arr));
                }

/* psp channel code */
                if (ind_psp_channel_code >= 0) {
                        v_psp_channel_code.arr[v_psp_channel_code.len] = '\0';
                        PutField_CString(myHash,"psp_channel_code",(const char*)v_psp_channel_code.arr);
DEBUGLOG(("GetPspDetailbyType psp_channel_code = [%s]\n",v_psp_channel_code.arr));
                }

/* client_id*/
                if (ind_client_id>= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetPspDetailByType client_id = [%s]\n",v_client_id.arr));
                }


/* txn_type */
                if (ind_txn_type>= 0) {
                        PutField_Char(myHash,"txn_type",v_txn_type);
DEBUGLOG(("GetPspDetailByType txn_type = [%c]\n",v_txn_type));
                }

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetPspDetailByType status = [%s]\n",v_status.arr));
                }

		RecordSet_Add(myRec, myHash);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpspdetailbytype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )394;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspdetailbytype_error;
}




	if (iCnt > 0) {
DEBUGLOG(("GetPspDetailByType Normal Exit\n"));
	        return  PD_OK;
	}
	else {
DEBUGLOG(("GetPspDetailByType Normal Exit, Not Found\n"));
	        /*return  PD_ERR;*/
	        return  PD_OK;
	}

getpspdetailbytype_error:
DEBUGLOG(("getpspdetailbytype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpspdetailbytype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )409;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetDepositPspList(const char *csTxnCountry,
		      const char *csBank,
	               recordset_t *myRec)	
{
	int	iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdsppsp_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             hv_disabled;
		char		hv_online_mode;
		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank;


                /* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


                short           ind_psp_id = -1; 

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_disabled = 0;
	hv_online_mode = PD_ONLINE_MODE;
DEBUGLOG(("GetDepositPspList: hv_online_mode = [%c]\n", hv_online_mode));

        hv_country.len = strlen(csTxnCountry);
        memcpy(hv_country.arr,csTxnCountry,hv_country.len);
DEBUGLOG(("GetDepositPspList: txn_country = [%.*s]\n",hv_country.len,hv_country.arr));

        hv_bank.len = strlen(csBank);
        memcpy(hv_bank.arr,csBank,hv_bank.len);
DEBUGLOG(("GetDepositPspList: bank_code = [%.*s]\n",hv_bank.len,hv_bank.arr));

	/* EXEC SQL DECLARE c_cursor_getdsppsp CURSOR FOR
		select psp_detail.psp_id
		from	psp_detail,
			psp_country,
			psp_master,
			bank_mapping
		where	psp_detail.disabled = :hv_disabled
		and	psp_detail.online_mode = :hv_online_mode
		and	psp_detail.txn_type in ('A', 'D')
		and	psp_detail.psp_id = psp_country.psp_id
		and	psp_detail.client_id = psp_master.pm_client_id
		and	psp_country.country= :hv_country
		and	psp_detail.status = 'O'
		and	psp_master.pm_status = 'O'
		and     bm_psp_channel_id  =  NVL(psp_detail.overrided_bank_code_channel, psp_detail.psp_channel_code)
		and	bm_int_bank_code = :hv_bank
		and	bm_disabled = 0
		order by psp_detail.psp_id; */ 

			
        /* EXEC SQL OPEN c_cursor_getdsppsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )424;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_online_mode;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank;
        sqlstm.sqhstl[3] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto getdsppsp_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdsppsp
                INTO
			:v_psp_id:ind_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )455;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
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
                if (sqlca.sqlcode < 0) goto getdsppsp_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		myHash = (hash_t*) malloc(sizeof(hash_t));
		hash_init(myHash, 0);

/* psp id */
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDepositPspList psp_id = [%s]\n",v_psp_id.arr));
                }

		RecordSet_Add(myRec, myHash);

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdsppsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )474;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdsppsp_error;
}




	if (iCnt > 0) {
DEBUGLOG(("GetDepositPspList Normal Exit\n"));
	        return  PD_OK;
	}
	else {
DEBUGLOG(("GetDepositPspList Normal Exit, Not Found\n"));
	        /*return  PD_ERR;*/
	        return  PD_OK;
	}

getdsppsp_error:
DEBUGLOG(("getdsppsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_GetDepositPspList: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdsppsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )489;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetPspPayoutSplitAmt(const char* csPspId,
                hash_t* hRec)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO getsplit_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                int             hv_disabled;

		double          v_payout_split_limit;

		short           ind_payout_split_limit = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetPspPayoutSplitAmt psp_id = [%d][%.*s]\n",hv_psp_id.len,hv_psp_id.len,hv_psp_id.arr));

	hv_disabled = 0;

        /* EXEC SQL DECLARE c_cursor_getsplit CURSOR FOR
                select 
		       payout_split_limit
                  from psp_detail
                 where psp_id = :hv_psp_id
		 and   disabled = :hv_disabled
		 and   txn_type in ('A','P')
		 and   status = 'O'; */ 


        /* EXEC SQL OPEN c_cursor_getsplit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )504;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
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
        if (sqlca.sqlcode < 0) goto getsplit_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsplit
                INTO
			:v_payout_split_limit:ind_payout_split_limit; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )527;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_payout_split_limit;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_payout_split_limit;
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
                if (sqlca.sqlcode < 0) goto getsplit_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


DEBUGLOG(("GetPspPayoutSplitAmt found record\n"));

/* payout_split_limit */
                if (ind_payout_split_limit < 0)
                        v_payout_split_limit = 0.0;
                PutField_Double(hRec,"payout_split_limit",v_payout_split_limit);
DEBUGLOG(("GetPspPayoutSplitAmt payout_split_limit = [%lf]\n",v_payout_split_limit));


        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsplit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )546;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsplit_error;
}




DEBUGLOG(("GetPspPayoutSplitAmt Normal Exit\n"));
        return  PD_OK;

getsplit_error:
DEBUGLOG(("getsplit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsplit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )561;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdateRemark2NULL(const hash_t *hRls)
{       
        char*   csPspId;
	char*	csTmp;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO updateremark_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

        
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        strcpy((char*)hv_dynstmt.arr,"update psp_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

// psp_id
        GetField_CString(hRls,"psp_id",&csPspId);
DEBUGLOG(("Update:psp_id = [%s]\n",csPspId));
        

/* psp_remark */
DEBUGLOG(("Update:psp_remark = [%s]\n",csTmp));
      	strcat((char*)hv_dynstmt.arr, ",psp_remark = NULL");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE psp_id = '");
        strcat((char *)hv_dynstmt.arr, csPspId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )576;
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
        if (sqlca.sqlcode < 0) goto updateremark_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )595;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updateremark_error;
}




DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updateremark_error:
DEBUGLOG(("updateremark_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("PspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetPspDetailByChannelMerchId(const char* csPspChannelCode,
		const char* csPspMerchantId,
		hash_t* hRec)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO getpspdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_channel_code[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_channel_code;

		/* varchar		hv_psp_merchant_id[PD_PSP_MID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_merchant_id;

		int		hv_disabled;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		/* varchar		v_name[PD_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_overrided_bank_code_channel[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_overrided_bank_code_channel;

		char		v_txn_type;
		char		v_psp_type;
		/* varchar		v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double		v_payout_split_limit;
		int		v_rej_small_delta_amt;
		/* varchar		v_pid_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_group;

		/* varchar		v_nbxa_pid_group[PD_NBXA_PID_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_nbxa_pid_group;

		char		v_card_type;

		short		ind_psp_id = -1;
		short		ind_status = -1;
		short		ind_name = -1;
		short		ind_client_id = -1;
		short		ind_overrided_bank_code_channel = -1;
		short		ind_txn_type = -1;
		short		ind_psp_type = -1;
		short		ind_ccy = -1;
		short		ind_payout_split_limit = -1;
		short		ind_rej_small_delta_amt = -1;
		short		ind_pid_group = -1;
		short		ind_nbxa_pid_group = -1;
		short		ind_card_type = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_channel_code.len = strlen(csPspChannelCode);
	memcpy(hv_psp_channel_code.arr, csPspChannelCode, hv_psp_channel_code.len);
DEBUGLOG(("GetPspDetail psp_channel_code = [%d][%.*s]\n", hv_psp_channel_code.len, hv_psp_channel_code.len, hv_psp_channel_code.arr));

	hv_psp_merchant_id.len = strlen(csPspMerchantId);
	memcpy(hv_psp_merchant_id.arr, csPspMerchantId, hv_psp_merchant_id.len);
DEBUGLOG(("GetPspDetail psp_merchant_id = [%d][%.*s]\n", hv_psp_merchant_id.len, hv_psp_merchant_id.len, hv_psp_merchant_id.arr));

	hv_disabled = 0;

        /* EXEC SQL DECLARE c_cursor_getdtlbychannelmerch CURSOR FOR
                select psp_id,
		       psp_name,
		       client_id,
		       txn_type,
		       currency_id,
		       status,
		       payout_split_limit,
		       rej_small_delta_amt,
		       overrided_bank_code_channel,
		       pid_group,
		       nbxa_pid_group,
		       psp_type,
		       deposit_card_type	
                  from psp_detail
                 where psp_channel_code = :hv_psp_channel_code
		 and   psp_merchant_id = :hv_psp_merchant_id
		 and   disabled = :hv_disabled; */ 


        /* EXEC SQL OPEN c_cursor_getdtlbychannelmerch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )610;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_channel_code;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )52;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
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
        if (sqlca.sqlcode < 0) goto getpspdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdtlbychannelmerch
                INTO
                        :v_psp_id:ind_psp_id,
                        :v_name:ind_name,
			:v_client_id:ind_client_id,
			:v_txn_type:ind_txn_type,
			:v_ccy:ind_ccy,
			:v_status:ind_status,
			:v_payout_split_limit:ind_payout_split_limit,
			:v_rej_small_delta_amt:ind_rej_small_delta_amt,
			:v_overrided_bank_code_channel:ind_overrided_bank_code_channel,
			:v_pid_group:ind_pid_group,
			:v_nbxa_pid_group:ind_nbxa_pid_group,
			:v_psp_type:ind_psp_type,
			:v_card_type:ind_card_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )637;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[2] = (unsigned long )13;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_client_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_type;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_ccy;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_status;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_payout_split_limit;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_payout_split_limit;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_rej_small_delta_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_rej_small_delta_amt;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_overrided_bank_code_channel;
                sqlstm.sqhstl[8] = (unsigned long )13;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_overrided_bank_code_channel;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_pid_group;
                sqlstm.sqhstl[9] = (unsigned long )13;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_pid_group;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_nbxa_pid_group;
                sqlstm.sqhstl[10] = (unsigned long )23;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_nbxa_pid_group;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_psp_type;
                sqlstm.sqhstl[11] = (unsigned long )1;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_psp_type;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_card_type;
                sqlstm.sqhstl[12] = (unsigned long )1;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_card_type;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getpspdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


DEBUGLOG(("GetPspDetail found record\n"));

/* psp id */
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(hRec,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPspDetail psp_id = [%s]\n",v_psp_id.arr));
		}

/* psp name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(hRec,"psp_name",(const char*)v_name.arr);
DEBUGLOG(("GetPspDetail psp_name = [%s]\n",v_name.arr));
                }

/* client_id*/
                if (ind_client_id>= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(hRec,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetPspDetail client_id = [%s]\n",v_client_id.arr));
                }

/* txn_type */
                if (ind_txn_type>= 0) {
                        PutField_Char(hRec,"txn_type",v_txn_type);
DEBUGLOG(("GetPspDetail txn_type = [%c]\n",v_txn_type));
                }

/* ccy*/
                if (ind_ccy>= 0) {
                        v_ccy.arr[v_ccy.len] = '\0';
                        PutField_CString(hRec,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetPspDetail ccy = [%s]\n",v_ccy.arr));
                }

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(hRec,"status",(const char*)v_status.arr);
DEBUGLOG(("GetPspDetail status = [%s]\n",v_status.arr));
                }

/* payout_split_limit */
                if (ind_payout_split_limit < 0)
                        v_payout_split_limit = 0.0;
                PutField_Double(hRec,"payout_split_limit",v_payout_split_limit);
DEBUGLOG(("GetPspDetail payout_split_limit = [%lf]\n",v_payout_split_limit));

/* rej_small_delta_amt */
		if (ind_rej_small_delta_amt >= 0) {
			PutField_Int(hRec,"rej_small_delta_amt",v_rej_small_delta_amt);
DEBUGLOG(("GetPspDetail rej_small_delta_amt = [%d]\n",v_rej_small_delta_amt));
		}

/* overrided bank code channel code */
                if (ind_overrided_bank_code_channel >= 0) {
                        v_overrided_bank_code_channel.arr[v_overrided_bank_code_channel.len] = '\0';
                        PutField_CString(hRec,"overrided_bank_code_channel",(const char*)v_overrided_bank_code_channel.arr);
DEBUGLOG(("GetPspDetail overrided_bank_code_channel = [%s]\n",v_overrided_bank_code_channel.arr));
                }

/* pid_group */
                if (ind_pid_group>= 0) {
                        v_pid_group.arr[v_pid_group.len] = '\0';
                        PutField_CString(hRec,"pid_group",(const char*)v_pid_group.arr);
DEBUGLOG(("GetPspDetail pid_group = [%s]\n",v_pid_group.arr));
                }

/* nbxa_pid_group */
                if (ind_nbxa_pid_group>= 0) {
                        v_nbxa_pid_group.arr[v_nbxa_pid_group.len] = '\0';
                        PutField_CString(hRec,"nbxa_pid_group",(const char*)v_nbxa_pid_group.arr);
DEBUGLOG(("GetPspDetail nbxa_pid_group = [%s]\n",v_nbxa_pid_group.arr));
                }

/* psp_type */
                if (ind_psp_type>= 0) {
                        PutField_Char(hRec,"psp_type",v_psp_type);
DEBUGLOG(("GetPspDetail psp_type = [%c]\n",v_psp_type));
                }

/* card_type */
                if (ind_card_type>= 0) {
                        PutField_Char(hRec,"card_type",v_card_type);
DEBUGLOG(("GetPspDetail card_type = [%c]\n",v_card_type));
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdtlbychannelmerch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )704;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspdetail_error;
}




DEBUGLOG(("GetPspDetail Normal Exit\n"));
        return  PD_OK;

getpspdetail_error:
DEBUGLOG(("getpspdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdtlbychannelmerch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )719;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdateNBXAPIDGroup2NULL(const hash_t *hRls)
{
        char*   csPspId;
        char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatenbxapidgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        strcpy((char*)hv_dynstmt.arr,"update psp_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

// psp_id
        GetField_CString(hRls,"psp_id",&csPspId);
DEBUGLOG(("Update:psp_id = [%s]\n",csPspId));


/* nbxa_pid_group */
DEBUGLOG(("Update:nbxa_pid_group = [%s]\n",csTmp));
        strcat((char*)hv_dynstmt.arr, ",nbxa_pid_group = NULL");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE psp_id = '");
        strcat((char *)hv_dynstmt.arr, csPspId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )734;
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
        if (sqlca.sqlcode < 0) goto updatenbxapidgrp_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )753;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatenbxapidgrp_error;
}




DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updatenbxapidgrp_error:
DEBUGLOG(("updatenbxapidgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("PspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int UpdatePIDGroup2NULL(const hash_t *hRls)
{
        char*   csPspId;
        char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatepidgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        strcpy((char*)hv_dynstmt.arr,"update psp_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

// psp_id
        GetField_CString(hRls,"psp_id",&csPspId);
DEBUGLOG(("Update:psp_id = [%s]\n",csPspId));


/* pid_group */
DEBUGLOG(("Update:pid_group = [%s]\n",csTmp));
        strcat((char*)hv_dynstmt.arr, ",pid_group = NULL");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE psp_id = '");
        strcat((char *)hv_dynstmt.arr, csPspId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )768;
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
        if (sqlca.sqlcode < 0) goto updatepidgrp_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )787;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatepidgrp_error;
}




DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updatepidgrp_error:
DEBUGLOG(("updatepidgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("PspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

