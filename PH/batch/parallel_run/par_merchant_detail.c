
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "par_merchant_detail.pc"
};


static unsigned int sqlctx = 323410475;


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
"select mp_merch_acct_nmb ,mp_username ,mp_merch_type_id ,mp_payout_enable ,\
mp_payout_file_upload_enable ,mp_apply_merchant_reserve ,mp_reserve_frequency\
  from par_merch_profile where mp_converted is null            ";

 static char *sq0003 = 
"select cm_client_id ,cm_preset_ph_mid ,cm_preset_ph_mid_name ,cm_preset_ph_\
mid_short_name  from par_client_merch_map where cm_merch_acct_nmb=:b0        \
   ";

 static char *sq0007 = 
"select sp_pay_method  from service_pay_method where sp_service_code=:b0    \
       ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,215,0,9,113,0,0,0,0,0,1,0,
20,0,0,1,0,0,13,115,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,
63,0,0,1,0,0,15,193,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,211,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,212,0,0,0,0,0,1,0,
108,0,0,3,155,0,9,461,0,0,1,1,0,1,0,1,9,0,0,
127,0,0,3,0,0,13,463,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
158,0,0,3,0,0,15,503,0,0,0,0,0,1,0,
173,0,0,3,0,0,15,515,0,0,0,0,0,1,0,
188,0,0,4,0,0,32,516,0,0,0,0,0,1,0,
203,0,0,5,111,0,4,540,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
226,0,0,6,108,0,4,587,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
249,0,0,7,82,0,9,660,0,0,1,1,0,1,0,1,9,0,0,
268,0,0,7,0,0,13,662,0,0,1,0,0,1,0,2,9,0,0,
287,0,0,8,0,0,17,740,0,0,1,1,0,1,0,1,9,0,0,
306,0,0,8,0,0,21,741,0,0,0,0,0,1,0,
};



/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/25              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "../batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "par_merchant_detail.h"
#include "ObjPtr.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_TOKEN	'"'

/*
#define	PD_MY_QS_TOEKN	'	'
#define	PD_MY_QE_TOEKN	'	'
#define	PD_MY_DAY_TOKEN	"-"
*/

#define	PD_CHAR		0x0D

OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

char    cDebug='Y';



int parse_arg(int argc,char **argv);
int process_txn(hash_t *hTxn);
int get_client_merch_info(hash_t *hMerchDetail);
int chk_is_ec2(char *csUserName);
int chk_is_nbx(char *csUserName);
int process_merch_pay_method(hash_t *hTxn);
int process_update_merch_profile(hash_t *hTxn);

int batch_init(int argc, char* argv[])
{
/*

    if (argc < 1) {
    	printf("usage: -f input file\n");
        return FAILURE;
    }
    else
*/
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

	hash_t *	hTxn;
	hTxn = (hash_t *) malloc (sizeof(hash_t));

        /* EXEC SQL WHENEVER SQLERROR GOTO get_merch_profile_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		v_merch_acct_nmb[PD_PAR_MERCH_ACCT_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_acct_nmb;

		/* varchar		v_username[PD_PAR_USERNAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_username;

		int		v_merch_type_id;
		int		v_payout_enable;
		int		v_payout_file_upload_enable;
		int		v_apply_merchant_reserved;
                int		v_reserve_frequency;
        
		short		ind_merch_acct_nmb = -1;
		short		ind_username = -1;
		short		ind_merch_type_id = -1;
		short		ind_payout_enable = -1;
		short		ind_payout_file_upload_enable = -1;
		short		ind_apply_merchant_reserved = -1;
                short		ind_reserve_frequency = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_get_merch_profile CURSOR FOR
		select mp_merch_acct_nmb,
		       mp_username,
                       mp_merch_type_id,
                       mp_payout_enable,
                       mp_payout_file_upload_enable,
                       mp_apply_merchant_reserve,
                       mp_reserve_frequency
		from   par_merch_profile
		where  mp_converted is NULL; */ 


	/* EXEC SQL OPEN c_cursor_get_merch_profile; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
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
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_merch_profile_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_merch_profile
		INTO
			v_merch_acct_nmb:ind_merch_acct_nmb,
			v_username:ind_username,
			v_merch_type_id:ind_merch_type_id,
			v_payout_enable:ind_payout_enable,
			v_payout_file_upload_enable:ind_payout_file_upload_enable,
			v_apply_merchant_reserved:ind_apply_merchant_reserved,
			v_reserve_frequency:ind_reserve_frequency; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merch_acct_nmb;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merch_acct_nmb;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_username;
  sqlstm.sqhstl[1] = (unsigned long )103;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_username;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_merch_type_id;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merch_type_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_payout_enable;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_payout_enable;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_payout_file_upload_enable;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_payout_file_upload_enable;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_apply_merchant_reserved;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_apply_merchant_reserved;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_reserve_frequency;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_reserve_frequency;
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
  if (sqlca.sqlcode < 0) goto get_merch_profile_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		hash_init(hTxn, 0);

DEBUGLOG((">>>>>>>>>>>>>>>>>>>>>>>>\n"));

		if (ind_merch_acct_nmb >= 0) {
			v_merch_acct_nmb.arr[v_merch_acct_nmb.len] = '\0';
DEBUGLOG(("merch_acct_nmb = [%s]\n",v_merch_acct_nmb.arr));
			PutField_CString(hTxn, "merch_acct_nmb", (const char*)v_merch_acct_nmb.arr);
                }

		if (ind_username >= 0) {
			v_username.arr[v_username.len] = '\0';
DEBUGLOG(("username = [%s]\n",v_username.arr));
			PutField_CString(hTxn, "username", (const char*)v_username.arr);
		}
		
		if (ind_merch_type_id >= 0) {
DEBUGLOG(("merch_type_id = [%d]\n",v_merch_type_id)); 
			if ((v_merch_type_id == PD_PAR_MERCHANT_TYPE_NORMAL) || 
			    (v_merch_type_id == PD_PAR_MERCHANT_TYPE_NEW_GAME)) {

DEBUGLOG(("Gaming\n")); 
				PutField_CString(hTxn, "merchant_type", PD_MERCH_TYPE_GAME);  // Game
			} else if (v_merch_type_id == PD_PAR_MERCHANT_TYPE_NON_GAME)  {
DEBUGLOG(("Non-Gaming\n")); 
				PutField_CString(hTxn, "merchant_type", PD_MERCH_TYPE_NONGAME); // NonGame
			} else {
DEBUGLOG(("merch_type_id is offline, skip...\n"));
				continue;	
			}
		}
		
		if (ind_payout_enable >= 0) {
DEBUGLOG(("payout_enable = [%d]\n",v_payout_enable)); 
		}

		if (ind_payout_file_upload_enable >= 0) {
DEBUGLOG(("payout_file_upload_enable = [%d]\n",v_payout_file_upload_enable)); 
		}

		if ((v_payout_enable == PD_TRUE) || (v_payout_file_upload_enable == PD_TRUE)) {
DEBUGLOG(("final payout_enable = [%d]\n",PD_TRUE)); 
			PutField_Int(hTxn, "payout_enable", PD_TRUE);
		} else {
DEBUGLOG(("final payout_enable = [%d]\n",PD_FALSE)); 
			PutField_Int(hTxn, "payout_enable", PD_FALSE);
		}

		if (ind_apply_merchant_reserved >= 0) {
DEBUGLOG(("apply_merchant_reserved = [%d]\n",v_apply_merchant_reserved)); 
			PutField_Int(hTxn, "allow_reserve", v_apply_merchant_reserved);
		}

		if (ind_reserve_frequency >= 0) {
DEBUGLOG(("reserve_frequency = [%d]\n",v_reserve_frequency)); 
			PutField_Int(hTxn, "release_reserve", v_reserve_frequency); 
		}

		iRet = process_txn(hTxn);

		hash_destroy(hTxn);

	} while (PD_TRUE && iRet == PD_OK);

	/* EXEC SQL CLOSE c_cursor_get_merch_profile; */ 

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
 if (sqlca.sqlcode < 0) goto get_merch_profile_error;
}



	if (iRet == PD_OK)  {
		iRet = SUCCESS;
	} else {
DEBUGLOG((">>>>>>>>>>>> RETURN FAILURE <<<<<<<<<<<<<<<<<\n"));
		iRet = FAILURE;
	}

	FREE_ME(hTxn);
        return  iRet;

get_merch_profile_error:
    DEBUGLOG(("get_merch_profile error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("par_merchant_detail::batch_proc sql error %d\n", sqlca.sqlcode);

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_merch_profile; */ 

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


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
/*
        char    c;

        strcpy(cs_inputfile,"");
                        
        while ((c = getopt(argc,argv,"f:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
DEBUGLOG(("[%s]\n",cs_inputfile));
        if (!strcmp(cs_inputfile,""))
                return FAILURE;
*/                
        return SUCCESS; 
}               



int process_txn(hash_t *hTxn)
{
	int iRet = PD_OK;

	char *csMerchAcctNmb;
	char *csUserName;
	char *csTmp;
	int  iTmp;

	char  *csBuf;
	char    csDateTime[PD_DATETIME_LEN +1];
        char    csDate[PD_DATE_LEN +1];
        char    csTime[PD_TIME_LEN +1];

	int  iTmpRet;

	hash_t *hMerchDetail;
	hMerchDetail = (hash_t *) malloc (sizeof(hash_t));

	hash_init(hMerchDetail, 0);

	csBuf = (char *)malloc(PD_TMP_BUF_LEN + 1);

	if (GetField_CString(hTxn, "merch_acct_nmb", &csMerchAcctNmb)) {
DEBUGLOG(("merch_acct_nmb [%s]\n", csMerchAcctNmb));
	}

	if (GetField_CString(hTxn, "username", &csUserName)) {
DEBUGLOG(("username [%s]\n", csUserName));
	}
	

	//Get client_id and preset_ph_mid from par_client_merch_map
	iRet = get_client_merch_info(hTxn);

	if (iRet == PD_OK) {
		// service
		iTmpRet = chk_is_ec2(csUserName);
		if (iTmpRet == PD_FOUND) {
DEBUGLOG(("service [%s]\n", PD_PAR_SERVICE_EC2));
			PutField_CString(hTxn, "service", PD_PAR_SERVICE_EC2);
		} else if (iTmpRet == PD_NOT_FOUND) {

			iTmpRet = chk_is_nbx(csUserName);
			
			if (iTmpRet == PD_FOUND) {
	
DEBUGLOG(("service [%s]\n", PD_PAR_SERVICE_NBX));
				PutField_CString(hTxn, "service", PD_PAR_SERVICE_NBX);
			} else  if (iTmpRet == PD_NOT_FOUND) {
			
DEBUGLOG(("service [%s]\n", PD_PAR_SERVICE_VNC));
				PutField_CString(hTxn, "service", PD_PAR_SERVICE_VNC);
			} else {
				iRet = PD_ERR;
			}
		} else {
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		// assign values into hMerchDetail

		// action
		sprintf(csBuf, "%c", PD_ACTION_ADD);
		PutField_CString(hMerchDetail, "action", csBuf);

		// merchant_id
		GetField_CString(hTxn, "merchant_id", &csTmp);
		PutField_CString(hMerchDetail, "newmid", csTmp);

		// name
		GetField_CString(hTxn, "merchant_name", &csTmp);
		PutField_CString(hMerchDetail, "name", csTmp);

		// short_name
		GetField_CString(hTxn, "merchant_short_name", &csTmp);
		PutField_CString(hMerchDetail, "short_name", csTmp);

		// fee_rate
		PutField_CString(hMerchDetail, "fee_rate", "0");
		// status
		PutField_CString(hMerchDetail, "status", PD_ACC_OPEN);

		// allow_reesrved	
		if (GetField_Int(hTxn, "allow_reserve", &iTmp)) {
			sprintf(csBuf, "%d", iTmp);
		} else {
			sprintf(csBuf, "%d", PD_FALSE);
			
		}
		PutField_CString(hMerchDetail, "allow_reserved", csBuf);


		// release_period
		if (GetField_Int(hTxn, "release_reserve", &iTmp)) {
			sprintf(csBuf, "%d", iTmp);
		}
		else {
			sprintf(csBuf, "%d", PD_DEF_RELEASE_PERIOD);
		}
		PutField_CString(hMerchDetail, "release_period", csBuf);


		// allow_po_dup_merch_ref
		sprintf(csBuf, "%d", PD_FALSE);
		PutField_CString(hMerchDetail, "allow_po_dup_merch_ref", csBuf);

		// sett_proc_period	
		sprintf(csBuf, "%d", 0);
		PutField_CString(hMerchDetail, "sett_proc_period", csBuf);

		// ind_reserve
		sprintf(csBuf, "%d", 0);
		PutField_CString(hMerchDetail, "ind_reserve", csBuf);


		// merchant_type
		//GetField_CString(hTxn, "merchant_type", &csTmp);
		//PutField_CString(hMerchDetail, "type", csTmp);

		// client_id
		GetField_CString(hTxn, "client_id", &csTmp);
		PutField_CString(hMerchDetail, "client_id", csTmp);

		// effect_date
		strcpy(csDateTime,getdatetime());
		memcpy(csDate,&csDateTime[0],PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';

		memcpy(csTime,&csDateTime[PD_DATE_LEN],PD_TIME_LEN);
		csTime[PD_TIME_LEN] = '\0';

		PutField_CString(hMerchDetail, "effect_date", csDate);

		// key_type
		PutField_CString(hMerchDetail, "key_type", PD_PTK_KEY_NAME);
		// add_user
		PutField_CString(hMerchDetail, "add_user", PD_UPDATE_USER);

		sleep(1); // to prevent same key_value as time will affect the random_gen

DEBUGLOG(("Calling TxnMgtByUsMCR::Authorize\n"));
		TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsMCR","Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hMerchDetail,hMerchDetail,hMerchDetail);

DEBUGLOG(("Calling TxnMgtByUsMCR::Authorize Ret [%d]\n", iRet));

	}

/* process on balance acct
	if (iRet == PD_OK) {
		iRet = process_merch_pay_method(hTxn);
	}
*/

	if (iRet == PD_OK) {
		iRet = process_update_merch_profile(hTxn);
	}


	hash_destroy(hMerchDetail);

	FREE_ME(csBuf);
	

	return iRet;
}

int	get_client_merch_info(hash_t *hMerchDetail)
{

	int	iRet = PD_OK;

	char	*csMerchAcctNmb;

	GetField_CString(hMerchDetail, "merch_acct_nmb", &csMerchAcctNmb);
	
        /* EXEC SQL WHENEVER SQLERROR GOTO get_client_merch_info_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merch_acct_nmb[PD_PAR_MERCH_ACCT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merch_acct_nmb;


		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar		v_merchant_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_merchant_short_name;


		short		ind_client_id = -1;
		short		ind_merchant_id = -1;
		short		ind_merchant_name = -1;
		short		ind_merchant_short_name = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merch_acct_nmb.len = strlen(csMerchAcctNmb);
	memcpy(hv_merch_acct_nmb.arr, csMerchAcctNmb, hv_merch_acct_nmb.len);

DEBUGLOG(("get_client_merch_info by [%.*s]\n", hv_merch_acct_nmb.len, hv_merch_acct_nmb.arr));

        /* EXEC SQL DECLARE c_cursor_get_client_merch_info CURSOR FOR
                select cm_client_id,
                       cm_preset_ph_mid, 
                       cm_preset_ph_mid_name,
                       cm_preset_ph_mid_short_name
                from   par_client_merch_map
                where  cm_merch_acct_nmb = :hv_merch_acct_nmb; */ 


        /* EXEC SQL OPEN c_cursor_get_client_merch_info; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )108;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_acct_nmb;
        sqlstm.sqhstl[0] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto get_client_merch_info_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_get_client_merch_info 
                INTO
			v_client_id:ind_client_id,
			v_merchant_id:ind_merchant_id,
			v_merchant_name:ind_merchant_name,
                        v_merchant_short_name:ind_merchant_short_name; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )127;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_client_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_short_name;
                sqlstm.sqhstl[3] = (unsigned long )23;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_merchant_short_name;
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
                if (sqlca.sqlcode < 0) goto get_client_merch_info_error;
}


			
                if (SQLCODE == SQL_NOT_FOUND) {
			iRet = SQL_NOT_FOUND;
                        break;
                }

		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("client_id = [%s]\n", v_client_id.arr));
			PutField_CString(hMerchDetail, "client_id", (const char*)v_client_id.arr);
		}

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
DEBUGLOG(("merchant_id = [%s]\n", v_merchant_id.arr));
			PutField_CString(hMerchDetail, "merchant_id", (const char*)v_merchant_id.arr);
		}

		if (ind_merchant_name >= 0) {
			v_merchant_name.arr[v_merchant_name.len] = '\0';
DEBUGLOG(("merchant_name = [%s]\n", v_merchant_name.arr));
			PutField_CString(hMerchDetail, "merchant_name", (const char*)v_merchant_name.arr);
		}

		if (ind_merchant_short_name >= 0) {
			v_merchant_short_name.arr[v_merchant_short_name.len] = '\0';
DEBUGLOG(("merchant_short_name = [%s]\n", v_merchant_short_name.arr));
			PutField_CString(hMerchDetail, "merchant_short_name", (const char*)v_merchant_short_name.arr);
		}

		break; // expect one record

        } while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get_client_merch_info; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto get_client_merch_info_error;
}



DEBUGLOG(("get_client_merch_info return [%d]\n", iRet));

        return  iRet;

get_client_merch_info_error:
    DEBUGLOG(("get_client_merch_info error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("par_merchant_detail::get_client_merch_info sql error %d\n", sqlca.sqlcode);

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_client_merch_info; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )173;
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
    sqlstm.offset = (unsigned int  )188;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;


}

int	chk_is_ec2(char *csUserName)
{
	int	iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisec2_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_value[PD_SP_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_value;


		int	v_no_of_record;
		short	ind_no_of_record = -1;
	/* EXEC SQL ENd DECLARE SECTION; */ 


        hv_value.len = strlen(csUserName);
        memcpy(hv_value.arr, csUserName, hv_value.len);
DEBUGLOG(("chk_is_ec2 value = [%.*s]\n",hv_value.len,hv_value.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM par_def_misc
                  WHERE pdm_code = 'EC2_TW_EMAIL'
                    and pdm_value = :hv_value
                    and rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(1) into :b0:b1  from par_def_misc where\
 ((pdm_code='EC2_TW_EMAIL' and pdm_value=:b2) and rownum=1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )203;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_value;
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
        if (sqlca.sqlcode < 0) goto chkisec2_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("chk_is_ec2 FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("chk_is_ec2 NOT FOUND\n"));
        }

        return iRet;

chkisec2_error: 
DEBUGLOG(("chkisec2_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int     chk_is_nbx(char *csUserName)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisnbx_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_value[PD_SP_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_value;


                int     v_no_of_record;
                short   ind_no_of_record = -1;
        /* EXEC SQL ENd DECLARE SECTION; */ 


        hv_value.len = strlen(csUserName);
        memcpy(hv_value.arr, csUserName, hv_value.len);
DEBUGLOG(("chk_is_nbx value = [%.*s]\n",hv_value.len,hv_value.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM par_def_misc
                  WHERE pdm_code = 'NBX_EMAIL'
                    and pdm_value = :hv_value
                    and rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(1) into :b0:b1  from par_def_misc where\
 ((pdm_code='NBX_EMAIL' and pdm_value=:b2) and rownum=1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )226;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_value;
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
        if (sqlca.sqlcode < 0) goto chkisnbx_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("chk_is_nbx FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("chk_is_nbx NOT FOUND\n"));
        }

        return iRet;

chkisnbx_error:
DEBUGLOG(("chkisnbx_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int  process_merch_pay_method(hash_t *hTxn)
{
	int	iRet = PD_OK;
	char	*csTmp;

	char	*csService;

	hash_t *hMerchPayMethod;
	hMerchPayMethod = (hash_t *) malloc (sizeof(hash_t));

	hash_init(hMerchPayMethod, 0);

	// merchant_id
	GetField_CString(hTxn, "merchant_id", &csTmp);
	PutField_CString(hMerchPayMethod, "merchant_id", csTmp);

	PutField_CString(hMerchPayMethod, "action", "A");
	PutField_CString(hMerchPayMethod, "add_user", PD_UPDATE_USER);

	GetField_CString(hTxn, "service", &csService);

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_service[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service;


		/* varchar		v_pay_method[PD_PAY_METHOD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_pay_method;

                short           ind_pay_method = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_service.len = strlen(csService);
        memcpy(hv_service.arr, csService, hv_service.len);

DEBUGLOG(("process_merch_pay_method [%.*s]\n", hv_service.len, hv_service.arr));

        /* EXEC SQL WHENEVER SQLERROR GOTO process_merch_pay_method_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL DECLARE c_cursor_merch_pay_method CURSOR FOR
                select sp_pay_method
                from   service_pay_method
                where  sp_service_code = :hv_service; */ 


        /* EXEC SQL OPEN c_cursor_merch_pay_method; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )249;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_service;
        sqlstm.sqhstl[0] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto process_merch_pay_method_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_merch_pay_method
                INTO
                        v_pay_method:ind_pay_method; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )268;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pay_method;
                sqlstm.sqhstl[0] = (unsigned long )7;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pay_method;
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
                if (sqlca.sqlcode < 0) goto process_merch_pay_method_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_pay_method >= 0) {
			v_pay_method.arr[v_pay_method.len] = '\0';
DEBUGLOG(("merch_pay_method = [%s]\n",v_pay_method.arr));
		
			PutField_Int(hMerchPayMethod, "total_cnt", 1);
			PutField_CString(hMerchPayMethod, "dt_pay_method_1", (const char*)v_pay_method.arr);

DEBUGLOG(("Calling TxnMgtByUsMPM::Authorize\n"));
			TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsMPM","Authorize");
			iRet = (unsigned long)(*TxnObjPtr)(hMerchPayMethod,hMerchPayMethod,hMerchPayMethod);
DEBUGLOG(("Calling TxnMgtByUsMPM::Authorize Ret [%d]\n", iRet));

			if (iRet != PD_OK) {
				break;
			}
		}
	} while (PD_TRUE);

	FREE_ME(hMerchPayMethod);

	return iRet;

process_merch_pay_method_error:
DEBUGLOG(("process_merch_pay_method_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("par_merchant_detail:process_merch_pay_method : SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;

}

int	process_update_merch_profile(hash_t *hTxn)
{

	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_merch_profile_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("process_update_merch_profile: Begin\n"));
        //csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update par_merch_profile set mp_update_timestamp  = sysdate");
	strcat((char*)hv_dynstmt.arr, ",mp_converted = 1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (GetField_CString(hTxn, "service", &csTmp)) {
DEBUGLOG(("process_update_merch_profile:service = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mp_service = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	GetField_CString(hTxn, "merch_acct_nmb", &csTmp);
DEBUGLOG(("process_update_merch_profile:merch_acct_nmb= [%s]\n",csTmp));

        strcat((char *)hv_dynstmt.arr, " WHERE mp_merch_acct_nmb = '");
        strcat((char *)hv_dynstmt.arr, csTmp);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )287;
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
        if (sqlca.sqlcode < 0) goto update_merch_profile_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )306;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_merch_profile_error;
}



        //FREE_ME(csBuf);

DEBUGLOG(("process_update_merch_profile Normal Exit\n"));
        return PD_OK;

update_merch_profile_error:
DEBUGLOG(("update_merch_profile_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("par_merchant_detail:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}
