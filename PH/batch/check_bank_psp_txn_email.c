
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "check_bank_psp_txn_email.pc"
};


static unsigned int sqlctx = 700903787;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
" PC . COUNTRY AND BM_DISABLED = 0 ) \
AND EXISTS ( SELECT * FROM PSP_PAY_METHOD , SERVICE_PAY_METHOD , BANK_SERVICE\
_MAPPING WHERE PP_COUNTRY = PC . COUNTRY AND PP_PSP_ID = PD . PSP_ID AND PP_D\
ISABLED = 0 AND PP_PAY_METHOD = SP_PAY_METHOD AND SP_DISABLED = 0 AND BS_SERV\
ICE_CODE = SP_SERVICE_CODE AND BS_INT_BANK_CODE = :b0 AND BS_DISABLED = 0 ) )\
 PD , BANK_TXN_CHECK BC , BANK_DESC BD WHERE BC . BC_DISABLED = 0 AND BC . BC\
_BANK_CODE = :b0 AND ( BC . BC_PARTY_ID = PD . PSP_ID OR ( BC . BC_PARTY_ID =\
 '000' AND NOT EXISTS ( SELECT * FROM BANK_TXN_CHECK BC2 WHERE BC2 . BC_BANK_\
CODE = :b0 AND BC2 . BC_PARTY_ID = PD . PSP_ID ) ) ) AND EXISTS ( SELECT 1 FR\
OM txn_psp_detail WHERE TP_PSP_ID = PD . PSP_ID AND TP_CREATE_TIMESTAMP > sys\
date - 1 ) AND BD . INTERNAL_BANK_CODE = :b0 ORDER BY BD . INTERNAL_BANK_CODE\
 , PD . PSP_ID ASC            ";

 static char *sq0003 = 
"SELECT COUNT ( 1 ) , TH_STATUS , TH_AR_IND FROM ( SELECT TH_TXN_ID , TH_STA\
TUS , TH_AR_IND , TH_CREATE_TIMESTAMP FROM ( SELECT TH_TXN_ID , TH_STATUS , T\
H_AR_IND , TH_CREATE_TIMESTAMP FROM TXN_HEADER WHERE TH_TXN_CODE IN ( 'DSI' )\
 AND TH_CLIENT_ID NOT IN ( select epm_party_id from email_check_party_map whe\
re epm_name = 'CHECK_BANK_PSP' and epm_group = 'EXCLUDE' and epm_party_type =\
 'C' and epm_support_multi_entry = 1 ) AND TH_CREATE_TIMESTAMP BETWEEN TO_DAT\
E ( :b0 , 'YYYYMMDDHH24MISS' ) AND SYSDATE - :b1 / 1440 AND EXISTS ( SELECT 1\
 FROM TXN_DETAIL WHERE TD_TXN_ID = TH_TXN_ID AND TD_BANK_CODE = :b2 ) AND EXI\
STS ( SELECT 1 FROM TXN_PSP_DETAIL WHERE TP_TXN_ID = TH_TXN_ID AND TP_PSP_ID \
= :b3 ) ORDER BY TH_CREATE_TIMESTAMP DESC ) WHERE ROWNUM <= :b4 ) GROUP BY TH\
_STATUS , TH_AR_IND            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1860,0,9,227,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,1,0,0,13,229,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
103,0,0,1,0,0,15,309,0,0,0,0,0,1,0,
118,0,0,1,0,0,15,322,0,0,0,0,0,1,0,
133,0,0,2,0,0,32,323,0,0,0,0,0,1,0,
148,0,0,3,799,0,9,488,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
183,0,0,3,0,0,13,491,0,0,3,0,0,1,0,2,3,0,0,2,1,0,0,2,1,0,0,
210,0,0,3,0,0,15,543,0,0,0,0,0,1,0,
225,0,0,3,0,0,15,624,0,0,0,0,0,1,0,
240,0,0,4,0,0,32,625,0,0,0,0,0,1,0,
255,0,0,5,222,0,5,653,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
282,0,0,6,0,0,32,669,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/10              Stan Poon
Restructure					   2013/09/30		   Stan Poon
Add additional part                                2016/08/04              David Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cs_party_id[PD_PSP_ID_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_psp_name[PD_PSP_NAME_LEN + 1];
char    cs_bank_code[PD_BANK_CODE_LEN + 1];
char    cs_bank_name[PD_AC_BANK_NAME_LEN + 1];
char    cs_count[PD_DATE_LEN + 1];
char    cs_min_succ[PD_DATE_LEN + 1];
char    cs_min_total[PD_DATE_LEN + 1];
char	cs_cutoff_time[PD_DATETIME_LEN+1];
char	cs_buffer_period[PD_DATE_LEN + 1];
char	cs_from_time[PD_TIMESTAMP_LEN + 1];
char	cs_to_time[PD_TIMESTAMP_LEN + 1];
char	cDebug;
int	i_rpt_gen_id = 0;
char	cs_rpt_gen_datetime[PD_DATETIME_LEN + 1];
char	cs_rpt_type[PD_PSP_REPORT_TYPE_LEN + 1];
int	i_seq = 0;

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_txn(const char* csPspId, const char* csPspName,
		const char* csBankCode, const char* csBankName,
		const char* csCount, const char* csMinCnt);
int find_checking_parameters_with_psp_id(const char* csBankCode);
int update_last_checking(const char* csPspId, const char* csBankCode);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int     iRet;

	iRet = parse_arg(argc,argv);

	if(iRet != SUCCESS)
printf("usage: -b bank_code -i rpt_gen_id -d rpt_gen_datetime -t rpt_type -s seq\n");

	if(iRet == SUCCESS)
		iRet = find_checking_parameters_with_psp_id(cs_bank_code);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	if (argc < 11) {
		return PD_ERR;
	}

	char    c;
	strcpy(cs_bank_code,"");
	strcpy(cs_rpt_gen_datetime, "");
	strcpy(cs_rpt_type, "");

	while ((c = getopt(argc,argv,"b:i:d:t:s:")) != EOF) {
		switch (c) {
			case 'b':
				strcpy(cs_bank_code, optarg);
				break;
			case 'i':
				i_rpt_gen_id = atoi(optarg);
				break;
			case 'd':
				strcpy(cs_rpt_gen_datetime, optarg);
				break;
			case 't':
				strcpy(cs_rpt_type, optarg);
				break;
			case 's':
				i_seq = atoi(optarg);
				break;
			default:
				return PD_ERR;
		}
	}

	if (!strcmp(cs_bank_code,"") || (i_rpt_gen_id == 0) || !strcmp(cs_rpt_gen_datetime,"") || !strcmp(cs_rpt_type,"") || (i_seq != 0))
		return PD_ERR;

	return SUCCESS;
}

int find_checking_parameters_with_psp_id(const char* csBankCode)
{
	int     iRet = SUCCESS, iTmpRet = SUCCESS;
	int	iGlobal = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


		/* varchar v_party_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_party_id;

		/* varchar v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		int	v_count;
		int	v_min_succ;
		int	v_min_total;
		int	v_buffer_period;
		/* varchar	v_cutoff_time[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cutoff_time;

		/* varchar	v_from_time[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_from_time;

		/* varchar	v_to_time[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_to_time;


		short	ind_party_id = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_bank_code = -1;
		short	ind_bank_name = -1;
		short	ind_count = -1;
		short	ind_min_succ = -1;
		short	ind_min_total = -1;
		short	ind_buffer_period = -1;
		short	ind_cutoff_time = -1;
		short	ind_from_time = -1;
		short	ind_to_time = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_code.len = strlen((char*)csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	/* EXEC SQL DECLARE c_cursor_get_check CURSOR FOR
		SELECT	BC.BC_PARTY_ID,
			PD.PSP_ID,
			PD.PSP_NAME,
			BD.INTERNAL_BANK_CODE,
			BD.BANK_NAME,
			bc_check_count,
			bc_min_success_count,
			bc_min_total,
			bc_start_buffer_period,
			to_char(case when sysdate-1/2 - bc_cutoff_checking_time >= 0 then
				sysdate-1/2
			else
				bc_cutoff_checking_time
			end,'YYYYMMDDHH24MISS') bc_new_cutoff_checking_time,
			to_char(case when sysdate-1/2 - bc_cutoff_checking_time >= 0 then
				sysdate-1/2
			else
				bc_cutoff_checking_time
			end,'DD-MON-YYYY HH24:MI:SS') from_time,
			to_char(sysdate-bc_start_buffer_period/1440,'DD-MON-YYYY HH24:MI:SS') to_time
		FROM	(SELECT	PD.PSP_ID,
				PD.PSP_NAME
			FROM    PSP_MASTER,
				PSP_DETAIL PD,
				PSP_COUNTRY PC
			WHERE   PM_CLIENT_ID = PD.CLIENT_ID
			AND     PM_STATUS = 'O'
			AND     PD.ONLINE_MODE = 'Y'
			AND     PD.STATUS = 'O'
			AND     PD.DISABLED = 0
			AND     PD.PSP_ID = PC.PSP_ID
			AND     EXISTS (SELECT *
				FROM    BANK_MAPPING
				WHERE   BM_PSP_CHANNEL_ID = NVL(PD.OVERRIDED_BANK_CODE_CHANNEL, PD.PSP_CHANNEL_CODE)
				AND     BM_INT_BANK_CODE = :hv_bank_code
				AND     BM_COUNTRY = PC.COUNTRY
				AND     BM_DISABLED = 0)
			AND     EXISTS (SELECT *
				FROM    PSP_PAY_METHOD, SERVICE_PAY_METHOD, BANK_SERVICE_MAPPING
				WHERE   PP_COUNTRY = PC.COUNTRY
				AND     PP_PSP_ID = PD.PSP_ID
				AND     PP_DISABLED = 0
				AND     PP_PAY_METHOD = SP_PAY_METHOD
				AND     SP_DISABLED = 0
				AND     BS_SERVICE_CODE = SP_SERVICE_CODE
				AND     BS_INT_BANK_CODE = :hv_bank_code
				AND     BS_DISABLED = 0)) PD,
			BANK_TXN_CHECK BC,
			BANK_DESC BD
		WHERE	BC.BC_DISABLED = 0
		AND	BC.BC_BANK_CODE = :hv_bank_code
		AND	(BC.BC_PARTY_ID = PD.PSP_ID
			OR
			(BC.BC_PARTY_ID = '000' AND NOT EXISTS (
			SELECT	*
			FROM	BANK_TXN_CHECK BC2
			WHERE	/oBC2.BC_DISABLED = 0 --neglect 000 no matter enabled or disabled
			ANDo/	BC2.BC_BANK_CODE = :hv_bank_code
			AND	BC2.BC_PARTY_ID = PD.PSP_ID)))
		AND     EXISTS (SELECT 1
			FROM txn_psp_detail
			WHERE TP_PSP_ID = PD.PSP_ID
			AND TP_CREATE_TIMESTAMP > sysdate - 1)
		AND	BD.INTERNAL_BANK_CODE = :hv_bank_code
		ORDER BY BD.INTERNAL_BANK_CODE, PD.PSP_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_get_check; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT BC . BC_PARTY_ID , PD . PSP_ID , PD . PSP_NAME , BD . INTERNAL_BA\
NK_CODE , BD . BANK_NAME , bc_check_count , bc_min_success_count , bc_min_to\
tal , bc_start_buffer_period , to_char ( case when sysdate - 1 / 2 - bc_cuto\
ff_checking_time >= 0 then sysdate - 1 / 2 else bc_cutoff_checking_time end \
, 'YYYYMMDDHH24MISS' ) bc_new_cutoff_checking_time , to_char ( case when sys\
date - 1 / 2 - bc_cutoff_checking_time >= 0 then sysdate - 1 / 2 else bc_cut\
off_checking_time end , 'DD-MON-YYYY HH24:MI:SS' ) from_time , to_char ( sys\
date - bc_start_buffer_period / 1440 , 'DD-MON-YYYY HH24:MI:SS' ) to_time FR\
OM ( SELECT PD . PSP_ID , PD . PSP_NAME FROM PSP_MASTER , PSP_DETAIL PD , PS\
P_COUNTRY PC WHERE PM_CLIENT_ID = PD . CLIENT_ID AND PM_STATUS = 'O' AND PD \
. ONLINE_MODE = 'Y' AND PD . STATUS = 'O' AND PD . DISABLED = 0 AND PD . PSP\
_ID = PC . PSP_ID AND EXISTS ( SELECT * FROM BANK_MAPPING WHERE BM_PSP_CHANN\
EL_ID = NVL ( PD . OVERRIDED_BANK_CODE_CHANNEL , PD . PSP_CHANNEL_CODE ) AND\
 BM_INT_BANK_CODE = :b0 AND BM_COUNTRY =");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_cursor_get_check
		INTO
			:v_party_id:ind_party_id,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_bank_code:ind_bank_code,
			:v_bank_name:ind_bank_name,
			:v_count:ind_count,
			:v_min_succ:ind_min_succ,
			:v_min_total:ind_min_total,
			:v_buffer_period:ind_buffer_period,
			:v_cutoff_time:ind_cutoff_time,
			:v_from_time:ind_from_time,
			:v_to_time:ind_to_time; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )40;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_party_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_psp_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[3] = (unsigned long )13;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[4] = (unsigned long )153;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_bank_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_count;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_succ;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_min_succ;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_min_total;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_min_total;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_buffer_period;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_buffer_period;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cutoff_time;
  sqlstm.sqhstl[9] = (unsigned long )17;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cutoff_time;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_from_time;
  sqlstm.sqhstl[10] = (unsigned long )23;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_from_time;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_to_time;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_to_time;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_party_id >= 0) {
			sprintf(cs_party_id,"%.*s",v_party_id.len,v_party_id.arr);
		}

		if (ind_psp_id >= 0) {
			sprintf(cs_psp_id,"%.*s",v_psp_id.len,v_psp_id.arr);
		}

		if (ind_psp_name >= 0) {
			sprintf(cs_psp_name,"%.*s",v_psp_name.len,v_psp_name.arr);
		}

		if (ind_bank_code >= 0) {
			sprintf(cs_bank_code,"%.*s",v_bank_code.len,v_bank_code.arr);
		}

		if (ind_bank_name >= 0) {
			sprintf(cs_bank_name,"%.*s",v_bank_name.len,v_bank_name.arr);
		}

		if (ind_count < 0)
			v_count = 0;
		sprintf(cs_count,"%d",v_count);

		if (ind_min_succ < 0)
			v_min_succ = 0;
		sprintf(cs_min_succ,"%d",v_min_succ);

		if (ind_min_total < 0)
			v_min_total = 0;
		sprintf(cs_min_total,"%d",v_min_total);

		if (ind_buffer_period < 0)
			v_buffer_period = 0;
		sprintf(cs_buffer_period,"%d",v_buffer_period);

		if (ind_cutoff_time >= 0) {
			sprintf(cs_cutoff_time,"%.*s",v_cutoff_time.len,v_cutoff_time.arr);
		}

		if (ind_from_time >= 0) {
			sprintf(cs_from_time,"%.*s",v_from_time.len,v_from_time.arr);
		}

		if (ind_to_time >= 0) {
			sprintf(cs_to_time,"%.*s",v_to_time.len,v_to_time.arr);
		}

//DEBUGLOG(("find() %s;%s;%s;%s;%s;%s;%s;\n",cs_psp_id,cs_bank_code,cs_count,cs_min_succ,cs_min_total,cs_buffer_period,cs_cutoff_time));

		iTmpRet = process_txn(cs_psp_id,cs_psp_name,cs_bank_code,cs_bank_name,cs_count,cs_min_succ);
		if (iTmpRet != SUCCESS) {
			iRet = FAILURE;
		}

		if (strcmp(cs_party_id,"000")) {
			iTmpRet = update_last_checking(cs_psp_id, csBankCode);
		} else {
			iGlobal++;
		}
	}
	/* EXEC SQL CLOSE c_cursor_get_check; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )103;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



	if (iGlobal > 0) {
		iTmpRet = update_last_checking(cs_party_id, csBankCode);
	}

//DEBUGLOG(("find() iRet = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_checking_parameters error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_check; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )118;
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )133;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int process_txn(const char* csPspId, const char* csPspName,
		const char* csBankCode, const char* csBankName,
		const char* csCount, const char* csMinCnt)
{	       
 
	int     iRet = SUCCESS;
	int	iTmpRet = PD_OK;
	int     iChk = 0;
	int	iPending=0;
	int	iAccept=0;
	int	iReject=0;
	int	iTotal=0;
	int	iOthers=0;
	int	iCnt = atoi((char*)csCount);
	int	iMinCnt = atoi((char*)csMinCnt);
	int	iMinTotal = atoi((char*)cs_min_total);
	double	dRate=0.0;	
	double	dSuccRate=0.0;	
	hash_t	*hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

//DEBUGLOG(("find::process_txn() start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar	hv_cutoff_time[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_time;

		/* varchar	hv_buffer_period[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_buffer_period;

		int	hv_cnt;

		char	v_status;
		char	v_ar_ind;
		int	v_cnt;

		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_cnt = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_bank_code.len = strlen((char*)csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
	memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

	hv_buffer_period.len = strlen((char*)cs_buffer_period);
	memcpy(hv_buffer_period.arr,cs_buffer_period,hv_buffer_period.len);

	hv_cnt=iCnt;

//DEBUGLOG(("find::process_txn() select start\n"));
	/* EXEC SQL DECLARE c_cursor_gettxn1 CURSOR FOR
		SELECT	COUNT(1),
			TH_STATUS,
			TH_AR_IND
		FROM	(SELECT	TH_TXN_ID,
				TH_STATUS,
				TH_AR_IND,
				TH_CREATE_TIMESTAMP
			FROM	(SELECT	TH_TXN_ID,
					TH_STATUS,
					TH_AR_IND,
					TH_CREATE_TIMESTAMP
				FROM	TXN_HEADER
				WHERE	TH_TXN_CODE IN ('DSI')
				AND	TH_CLIENT_ID NOT IN (
						select  epm_party_id 
						from email_check_party_map
						where epm_name = 'CHECK_BANK_PSP'
						and epm_group = 'EXCLUDE'
						and epm_party_type = 'C'
						and epm_support_multi_entry = 1
						/o'C1000002','C1000013'o/)
				AND	TH_CREATE_TIMESTAMP BETWEEN TO_DATE (:hv_cutoff_time,'YYYYMMDDHH24MISS')
					AND SYSDATE - :hv_buffer_period/ 1440
				AND	EXISTS (SELECT	1
						FROM	TXN_DETAIL
						WHERE	TD_TXN_ID = TH_TXN_ID
						AND	TD_BANK_CODE = :hv_bank_code)
				AND	EXISTS (SELECT	1
						FROM	TXN_PSP_DETAIL
						WHERE	TP_TXN_ID = TH_TXN_ID
						AND	TP_PSP_ID = :hv_psp_id)
				ORDER BY TH_CREATE_TIMESTAMP DESC)
		WHERE ROWNUM <= :hv_cnt)
		GROUP BY TH_STATUS, TH_AR_IND; */ 

/*
		SELECT COUNT (th_txn_id),
			 th_status,
			 th_ar_ind
                    FROM (  SELECT th_txn_id, th_status, th_ar_ind
                              FROM (  SELECT th_txn_id,
                                             th_status,
                                             th_ar_ind,
                                             th_create_timestamp
                                        FROM txn_header
                                       WHERE     th_txn_code IN ('DSI')
                                             AND th_client_id NOT IN ('C1000002','C1000013')
                                             AND th_create_timestamp BETWEEN TO_DATE (
                                                                                :hv_cutoff_time,
                                                                                'YYYYMMDDHH24MISS')
                                                                         AND SYSDATE - :hv_buffer_period/ 1440
                                    ORDER BY th_txn_id),
                                   (  SELECT td_txn_id
                                        FROM txn_detail
                                       WHERE     td_bank_code = :hv_bank_code
                                             AND td_create_timestamp BETWEEN TO_DATE (
                                                                                :hv_cutoff_time,
                                                                                'YYYYMMDDHH24MISS')
                                                                         AND SYSDATE - :hv_buffer_period/ 1440
                                    ORDER BY td_txn_id),
                                   (  SELECT tp_txn_id
                                        FROM txn_psp_detail
                                       WHERE     tp_psp_id = :hv_psp_id
                                             AND tp_create_timestamp BETWEEN TO_DATE (
                                                                                :hv_cutoff_time,
                                                                                'YYYYMMDDHH24MISS')
                                                                         AND SYSDATE - :hv_buffer_period/ 1440
                                    ORDER BY tp_txn_id)
                             WHERE th_txn_id = td_txn_id AND th_txn_id = tp_txn_id
                          ORDER BY th_create_timestamp DESC)
                   WHERE ROWNUM <= :hv_cnt
                GROUP BY th_status, th_ar_ind;
		select  count(*),
	 		th_status,
	 		th_ar_ind,
			to_char(sysdate,'DD-MON-YYYY HH24:MI:SS'),
			to_char(sysdate - (:hv_buffer_period/1440) ,'DD-MON-YYYY HH24:MI:SS'),
			to_char(to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS'),'DD-MON-YYYY HH24:MI:SS')
		from 	(select th_txn_id,
				th_status,
				th_ar_ind,
				th_create_timestamp
			 from	txn_header,
				txn_detail,
				txn_psp_detail
    			 where	th_txn_id = td_txn_id
			 and	th_txn_id = tp_txn_id
			 and	tp_psp_id = :hv_psp_id
			 and	td_bank_code  = :hv_bank_code
			 and	th_txn_code in ('DSP','MSI','DSI')
			 and	th_client_id not in ('C1000002')
			 order by th_create_timestamp DESC)
		where	th_create_timestamp between to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS') and sysdate-(:hv_buffer_period/1440)
		and	rownum <= :hv_cnt
		group by th_ar_ind,
			 th_status;
*/
//DEBUGLOG(("find::process_txn() select end\n"));
		
//DEBUGLOG(("find::process_txn() cursor open\n"));
	/* EXEC SQL OPEN c_cursor_gettxn1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_cutoff_time;
 sqlstm.sqhstl[0] = (unsigned long )16;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_buffer_period;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_cnt;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
//DEBUGLOG(("find::process_txn() cursor [%d] start\n",iChk));
		/* EXEC SQL FETCH c_cursor_gettxn1
		INTO
		 	:v_cnt:ind_cnt,
	 		:v_status:ind_status,
	 		:v_ar_ind:ind_ar_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )183;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_status;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ar_ind;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}


//DEBUGLOG(("find::process_txn() cursor [%d] end\n",iChk));

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iChk ++;

//printf("status:[%c] ind:[%c] cnt:[%d]\n",v_status,v_ar_ind,v_cnt);

		if(ind_status>=0){
			if(v_status==PD_COMPLETE){
				if(ind_ar_ind>=0){
					if(v_ar_ind==PD_ACCEPT){
						if(ind_cnt>=0)
							iAccept += v_cnt;
//printf("Accept\n");
					}
					else if(v_ar_ind==PD_REJECT){
						if(ind_cnt>=0)
							iReject += v_cnt;
//printf("Reject\n");
					}
				}
				else{
					v_ar_ind=' ';
//printf("Not Count\n");
				}
			}
			else if(v_status==PD_TO_PSP){
				v_ar_ind=' ';
				if(ind_cnt>=0)
					iPending += v_cnt;
//printf("Pending\n");
			}
			else{
				if(ind_ar_ind<0){
					v_ar_ind=' ';
				}
				if(ind_cnt>=0)
					iOthers += v_cnt;
//printf("Other\n");
			}
		}

 	}
	while(PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_gettxn1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )210;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


//DEBUGLOG(("find::process_txn() cursor close\n"));

	if (iChk > 0) {
//printf("iAccept:[%d] iReject:[%d] iPending:[%d] iOthers:[%d]\n",iAccept,iReject,iPending,iOthers);

		iTotal = iAccept+iReject+iPending+iOthers;
		dRate = (double)iMinCnt/(double)iCnt;
		if(iTotal>iMinTotal){
			dSuccRate = (double)(iAccept+iReject)/(double)iTotal;
			if(iTotal<iCnt){
				if(dSuccRate<dRate){
//printf("<tr><td>-</td><td>Successful rate is low: %.2f (Threshold: %.2f)</td></tr>",dSuccRate*100,dRate*100);
					iRet = FAILURE;
				}
			}
			else{
				if((iPending==iTotal) || ((iAccept+iReject) == 0)){
//printf("<tr><td>-</td><td>All pending!!!!</td></tr>");
					iRet = FAILURE;
				}
				else{
					if((iAccept+iReject)<iMinCnt){
//printf("<tr><td>-</td><td>Success rate is low: %.2f (Threshold: %.2f)</td></tr>",((double)iAccept/(double)iTotal)*100,dRate*100);
						iRet = FAILURE;
					}
				}

			}
			if(iRet == FAILURE){
printf("<tr><td><b>%s</b>(%s)</td>\n",csPspName,csPspId);
printf("<td>%s</td>\n",csBankName);
printf("<td>%d</td>\n",iAccept+iReject);
printf("<td>%d</td>\n",iPending);
printf("<td>%d</td>\n",iTotal);
printf("<td>%.2f%%</td>\n",dSuccRate*100);
printf("<td>%.2f%%</td></tr>\n",dRate*100);
printf("<tr><td></td><td colspan='6'>Duration:%s to %s</td></tr>\n",cs_from_time,cs_to_time);
			}
		}
//DEBUGLOG(("find::process_txn() %d/%d = [%.2f] [%.2f]\n",iAccept+iReject,iTotal,dSuccRate,dRate));

		if(iRet == FAILURE){
			// insert into psp_txn_check_rpt_log
			PutField_Int(hRec, "rpt_gen_id", i_rpt_gen_id);
			PutField_CString(hRec, "rpt_gen_datetime", cs_rpt_gen_datetime);
			PutField_CString(hRec, "rpt_type", cs_rpt_type);
			PutField_Int(hRec, "seq", i_seq);
			PutField_Char(hRec, "party_type", PD_TYPE_PSP);
			PutField_CString(hRec, "party_id", (const char*)csPspId);
			PutField_CString(hRec, "party_name", (const char*)csPspName);
			PutField_CString(hRec, "bank_code", (const char*)csBankCode);
			PutField_CString(hRec, "bank_name", (const char*)csBankName);
			PutField_CString(hRec, "dur_start", (const char*)cs_from_time);
			PutField_CString(hRec, "dur_end", (const char*)cs_to_time);
			PutField_Int(hRec, "succ_cnt", iAccept+iReject);
			PutField_Int(hRec, "pend_cnt", iPending);
			PutField_Int(hRec, "total_cnt", iTotal);
			PutField_CString(hRec, "create_user", PD_UPDATE_USER);

//DEBUGLOG(("process_txn:: Call DBPspTxnCheckReportLog:: Add\n"));
			DBObjPtr = CreateObj(DBPtr, "DBPspTxnCheckReportLog", "Add");
			iTmpRet = (unsigned long)(*DBObjPtr)(hRec);
			if (iTmpRet != PD_OK) {
				iRet = PD_ERR;
//DEBUGLOG(("process_txn:: Call DBPspTxnCheckReportLog:: Add Error!!!\n"));
ERRLOG("check_bank_psp_txn_email:: process_txn:: Call DBPspTxnCheckReportLog:: Add Error!!!\n");
			}
		}
	}

//DEBUGLOG(("find::process_txn() iRet = [%d]\n",iRet));

	hash_destroy(hRec);
	FREE_ME(hRec);

	return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn1; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )225;
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )240;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int update_last_checking(const char* csPspId, const char* csBankCode)
{
//DEBUGLOG(("find::update_last_checking() party_id=[%s] bank_code=[%s]\n",csPspId,csBankCode));
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar	hv_cutoff_time[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_time;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_bank_code.len = strlen((char*)csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
	memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

       	/* EXEC SQL
		UPDATE	bank_txn_check
		SET	bc_cutoff_checking_time = TO_DATE(:hv_cutoff_time,'YYYYMMDDHH24MISS'),
 			bc_last_checking_time = sysdate,
			bc_update_timestamp = sysdate
 		WHERE	bc_disabled = 0
		AND	bc_party_id = :hv_psp_id
		AND	bc_bank_code = :hv_bank_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update bank_txn_check SET bc_cutoff_checking_time = \
TO_DATE ( :b0 , 'YYYYMMDDHH24MISS' ) , bc_last_checking_time = sysdate , bc_u\
pdate_timestamp = sysdate WHERE bc_disabled = 0 AND bc_party_id = :b1 AND bc_\
bank_code = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )255;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[0] = (unsigned long )16;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


	
//DEBUGLOG(("find::update_last_checking() iRet = [%d]\n",iRet));
	return iRet;

update_error:
DEBUGLOG(("update_last_check error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )282;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

