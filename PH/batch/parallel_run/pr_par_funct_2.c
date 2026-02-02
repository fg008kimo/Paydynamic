
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "pr_par_funct_2.pc"
};


static unsigned int sqlctx = 10750043;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
"select fd_upload_txn_id ,fd_txn_id  from payout_generated_file_dt ,merchant\
_upload_file_detail where (ud_aux_txn_id=:b0 and fd_upload_txn_id=ud_txn_id) \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,162,0,9,298,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,300,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
47,0,0,1,0,0,15,322,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,336,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/04              Virginia Yun

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "../batchcommon.h"
#include "pr_par_funct_2.h"
#include "pr_par_funct.h"
#include "pr_bo_funct.h"
#include "ObjPtr.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);


int     AssignTxnRecordDetail(hash_t *hMyHash) 
{
	int		iRet = SUCCESS;

	int		iTmpRet =PD_NOT_FOUND;

	char		*csMerchNmb = NULL;
	char		*csVNCRefNum = NULL;
//	char    	csCountry [PD_COUNTRY_LEN + 1];
	int		iRecExists = PD_FALSE;
	char		*csService = NULL;

	char		*csTmp;
	char		cTmp;

	recordset_t     *rRecordSet;
	hash_t		*hRec;

	hash_t		*hTxn;

DEBUGLOG(("pr_par_funct_2::AsssignTxnRecordDetal: START!\n"));

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
	hTxn = (hash_t *)malloc(sizeof(hash_t));


	if (GetField_CString(hMyHash, "txn_merch_nmb", &csMerchNmb)) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:txn_merch_nmb [%s]\n", csMerchNmb));
	}
	else {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:txn_merch_nmb missing\n"));
		iRet = FAILURE;
	}

	// Chk PH MID
	recordset_init(rRecordSet, 0);
	if (iRet == SUCCESS) {
		if (ParMerchProfile_GetMerchant(csMerchNmb, rRecordSet) != PD_OK) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:call ParMerchProfile_GetMerchant FAILED!\n"));

                } else {

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
                                if (GetField_CString(hRec, "service", &csService)) {
//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: service [%s]!\n", csService));
					PutField_CString(hMyHash, "service", csService);
				}

                                if (GetField_CString(hRec, "merchant_id", &csTmp)) {
//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: merchant_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_id", csTmp);
				}

				if (GetField_CString(hRec, "client_id", &csTmp)) {
//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: client_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_client_id", csTmp);
				}

				if (GetField_CString(hRec, "country", &csTmp)) {
//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: country [%s]!\n", csTmp));
					PutField_CString(hMyHash, "country", csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
                }
	}
	RecordSet_Destroy(rRecordSet);


	// Country
/*
	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "service", &csService)) {
			csCountry[0] = '\0';

			if (Service_FindCountryByService((const unsigned char*) csService, csCountry) != FOUND) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:Call Service_FindCountryByService FAILED!\n"));
				iRet = FAILURE;
			} else {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: country [%s]!\n", csCountry));
                                PutField_CString(hMyHash, "country", csCountry);
                        }
		}
	}
*/

//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: prepare to pay method!\n"));

	
	// Payment method
	recordset_init(rRecordSet, 0);
	if (iRet == SUCCESS) {


		if (ServicePayMethod_FindPayMethod(csService, rRecordSet) != PD_OK) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:Call ServicePayMethod_FindPayMethod FAILED!\n")); 
		} else {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "pay_method", &csTmp)) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: pay_method [%s]!\n", csTmp)); 
					PutField_CString(hMyHash, "pay_method", csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}
	RecordSet_Destroy(rRecordSet);

	
	// Chk if exists in txn_header
	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum)) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: txn_nmb [%s]\n", csVNCRefNum));
		}
		else {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: txn_nmb not found!\n"));
			iRet = FAILURE;
		}	
	}

	if (iRet == SUCCESS) {

		iTmpRet = ParTxnData_ChkExist(csVNCRefNum);

		if (iTmpRet == PD_FOUND) {
			iRecExists = PD_TRUE;

//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: call ParTxnData_ChkExist (record_exists)!\n"));
                        PutField_Int(hMyHash, "record_exists", PD_TRUE);

		} else if (iTmpRet == PD_NOT_FOUND) {
			iRecExists = PD_FALSE;

//DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:call ParTxnData_ChkExist (record not exists)!\n"));

                        PutField_Int(hMyHash, "record_exists", PD_FALSE);

                } else {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail:ParTxnData_ChkExist FAILED!\n")); 
                        iRet = FAILURE;
                }

	}

	if (iRet == SUCCESS) {
		hash_init(hTxn, 0);
		
		GetField_Int(hMyHash, "record_exists", &iRecExists);
		if (iRecExists == PD_TRUE) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: Call GetOrgTxnID!\n")); 
			iRet = GetOrgTxnID(hMyHash, hTxn);

			if (iRet == SUCCESS) {

				if (GetField_CString(hTxn, "txn_id", &csTmp)) {
DEBUGLOG(("pr_par_funct_2::AssignTxnRecordDetail: org_txn_id [%s]!\n", csTmp)); 
					PutField_CString(hMyHash, "org_txn_id", csTmp);
				}

				if (GetField_Char(hTxn, "status", &cTmp)) {
					PutField_Char(hMyHash, "org_status", cTmp);	
				}

				if (GetField_Char(hTxn, "ar_ind", &cTmp)) {
					PutField_Char(hMyHash, "org_ar_ind", cTmp);	
				}

				if (GetField_CString(hTxn, "sub_status", &csTmp)) {
					PutField_CString(hMyHash, "org_sub_status", csTmp);	
				}

				if (GetField_CString(hTxn, "txn_code", &csTmp)) {
					PutField_CString(hMyHash, "org_txn_code", csTmp);	
				}
			}
		}

		hash_destroy(hTxn);
	}

	FREE_ME(hTxn);
	FREE_ME(rRecordSet);

DEBUGLOG(("pr_par_funct_2::AsssignTxnRecordDetal: Return [%d]\n", iRet));

	return iRet;

}

int     GetPSPRelatedInfo(hash_t *hMyHash)
{
        int     iRet = SUCCESS;

        char    *csPspTypeCode;
        char    *csTmp;
        char    *csGateID;

        if (GetField_CString(hMyHash, "psp_type_code", &csPspTypeCode)) {
DEBUGLOG(("pr_par_funct_2::GetPSPRelatedInfo: GetPSPRelatedInfo [%s]\n", csPspTypeCode));

                if (ParPspClientMap_GetPspID(hMyHash) == FOUND) {
                        if (GetField_CString(hMyHash, "psp_id", &csTmp)) {
DEBUGLOG(("pr_par_funct_2::GetPSPRelatedInfo: psp_id [%s]\n", csTmp));
                        }

                        if (GetField_CString(hMyHash, "psp_country", &csTmp)) {
//DEBUGLOG(("pr_par_funct_2::GetPSPRelatedInfo: psp_country [%s]\n", csTmp));
                        }

			if (GetField_CString(hMyHash, "psp_channel_code", &csTmp)) {
DEBUGLOG(("pr_par_funct_2::GetPSPRelatedInfo: psp_channel_code [%s]\n", csTmp));
			}
                }
                else {
DEBUGLOG(("pr_par_funct_2::GetPSPRelatedInfo: DBParPspClientMap.GetPspID FAIL!\n"));
                        iRet = FAILURE;
                }

        }

        // Get Bank Code
        if ((GetField_CString(hMyHash, "psp_type_code", &csPspTypeCode)) &&
            (GetField_CString(hMyHash, "gate_id", &csGateID))) {

                if (ParPspClientMap_GetBankCode(hMyHash) == FOUND) {
                        if (GetField_CString(hMyHash, "int_bank_code", &csTmp)) {
DEBUGLOG(("GetPSPRelatedInfo: DBParPspClientMap.GetBankCode [%s]\n", csTmp));
                        }
                }
        }

        return iRet;
}

int	prpar2_GetPOGTxnIDByVOATxnID(const char *csVOATxnID, hash_t *hTxn)
{
	int	iRet = SUCCESS;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_pog_txn_id_by_voa; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_voa_txn_id [PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_voa_txn_id;


                /* varchar		v_poa_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_poa_txn_id;

                /* varchar		v_pog_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_pog_txn_id;


		short		ind_poa_txn_id = -1;
                short           ind_pog_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_voa_txn_id.len = strlen(csVOATxnID);
	memcpy(hv_voa_txn_id.arr, csVOATxnID, hv_voa_txn_id.len);
DEBUGLOG(("prpar2_GetPOGTxnIDByVOATxnID voa_txn_id = [%s]\n", hv_voa_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_get_pog_txn_id CURSOR FOR
		select fd_upload_txn_id, fd_txn_id
		from payout_generated_file_dt, merchant_upload_file_detail 
		where ud_aux_txn_id = :hv_voa_txn_id 
		and fd_upload_txn_id = ud_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_get_pog_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_voa_txn_id;
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
 if (sqlca.sqlcode < 0) goto get_pog_txn_id_by_voa;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_pog_txn_id
		INTO	:v_poa_txn_id:ind_poa_txn_id,
			:v_pog_txn_id:ind_pog_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_poa_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_poa_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_pog_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_pog_txn_id;
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
  if (sqlca.sqlcode < 0) goto get_pog_txn_id_by_voa;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_poa_txn_id >= 0) {
                        v_poa_txn_id.arr[v_poa_txn_id.len]='\0';
			PutField_CString(hTxn, "poa_txn_id", (const char*) v_poa_txn_id.arr);
		}

		if (ind_pog_txn_id >= 0) {
                        v_pog_txn_id.arr[v_pog_txn_id.len]='\0';
			PutField_CString(hTxn, "pog_txn_id", (const char*) v_pog_txn_id.arr);
		}
		break;
	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_get_pog_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )47;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_pog_txn_id_by_voa;
}



	if (iCnt == 0) {
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("prpar2_GetPOGTxnIDByVOATxnID Exit Ret [%d]\n", iRet));
	return iRet;

get_pog_txn_id_by_voa:
DEBUGLOG(("get_pog_txn_id_by_voa code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("prpar2_GetPOGTxnIDByVOATxnID : SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_pog_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )62;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

