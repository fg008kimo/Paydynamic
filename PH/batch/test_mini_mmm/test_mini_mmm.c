
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
    "test_mini_mmm.pc"
};


static unsigned int sqlctx = 5257907;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug = 'Y';

OBJPTR(DB);

int parse_arg(int argc, char **argv);
int process_main();

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		return (iRet);
	}

	iRet = process_main();

DEBUGLOG(("iRet = [%d]\n", iRet));

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_main()
{
	int iRet = SUCCESS;

	int iTmp = 0;
	double dTmp = 0.0;
	char *csTmp = NULL;

	char    csBatchId[PD_TXN_SEQ_LEN + 1];

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	hash_t  *hRec = NULL;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("process_main\n"));

#if 0
	// GetMiModeTxnCtl
	if (iRet == SUCCESS) {
		char *csType = NULL;	
	
		csType = (char*) malloc (128);		

		sprintf(csType, "%s", "PSP_SETTLE");

DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl: type = [%s]\n", csType));
              	DBObjPtr = CreateObj(DBPtr,"DBMiModeTxnCtl","GetMiModeTxnCtl");
            	iRet = (unsigned long)(*DBObjPtr)(csType, hRequest);
         	if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl:SUCCESS\n"));
	
			if (GetField_CString(hRequest,"void_process_type",&csTmp)) {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl: void_process_type = [%s]\n", csTmp));
        		}	

			if (GetField_Int(hRequest,"is_void_process",&iTmp)) {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl: is_void_process = [%d]\n", iTmp));
                        }
	
			if (GetField_Int(hRequest,"mi_support",&iTmp)) {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl: mi_support = [%d]\n", iTmp));
                        }

			if (GetField_Int(hRequest,"exit_if_org_not_mi",&iTmp)) {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl: exit_if_org_not_mi = [%d]\n", iTmp));
                        }
		} else {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl:ERROR\n"));
		}

		FREE_ME(csType);
	}

	// GetArBalParameter
	if (iRet == SUCCESS) {
		char *csCode = NULL;

                csCode = (char*) malloc (128);

                sprintf(csCode, "%s", "UNDERPAID");

DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter: code = [%s]\n", csCode));
                DBObjPtr = CreateObj(DBPtr,"DBMiDefArBal","GetArBalParameter");
                iRet = (unsigned long)(*DBObjPtr)(csCode, hRequest);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter:SUCCESS\n"));

                        if (GetField_CString(hRequest,"desc",&csTmp)) {
DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter: desc = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"txn_code_map",&csTmp)) {
DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter: txn_code_map = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"element_code",&csTmp)) {
DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter: element_code = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"amt_type",&csTmp)) {
DEBUGLOG(("process_main::Call MiDefArBal:GetArBalParameter: amt_type = [%s]\n", csTmp));
                        }
                } else {
DEBUGLOG(("process_main::Call MiModeTxnCtl:GetMiModeTxnCtl:ERROR\n"));
                }		

		FREE_ME(csCode);
	}

	// GetOPBInfoByEntityId
	if (iRet == SUCCESS) {
		char *csEntityId = NULL;

                csEntityId = (char*) malloc (128);

                sprintf(csEntityId, "%s", "E000000015");

DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: entity_id = [%s]\n", csEntityId));
                DBObjPtr = CreateObj(DBPtr,"DBMiEntityOpb","GetOPBInfoByEntityId");
                iRet = (unsigned long)(*DBObjPtr)(csEntityId, hRequest);
		if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId:SUCCESS\n"));
		
			if (GetField_CString(hRequest,"bank_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: bank_id = [%s]\n", csTmp));
                        }		
		
			if (GetField_CString(hRequest,"bank_name",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: bank_name = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"base_ccy",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: base_ccy = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: status = [%s]\n", csTmp));
                        }

			if (GetField_CString(hRequest,"bal_status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: bal_status = [%s]\n", csTmp));
                        }

			if (GetField_Int(hRequest,"is_acr_bank",&iTmp)) {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId: is_acr_bank = [%d]\n", iTmp));
                        }			
		} else {
DEBUGLOG(("process_main::Call MiEntityOpb:GetOPBInfoByEntityId:ERROR\n"));
		}

		FREE_ME(csEntityId);
	}

	// GetPITInfoByPitId
	if (iRet == SUCCESS) {
		int iCnt = 0;

		char *csPitId = NULL;

                csPitId = (char*) malloc (128);

                sprintf(csPitId, "%s", "PIT0000010");	
	
		recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: pit_id = [%s]\n", csPitId));
                DBObjPtr = CreateObj(DBPtr, "DBMiEntityPit", "GetPITInfoByPitId");
                iRet = (unsigned long)(*DBObjPtr)(csPitId, rRecordSet);
		if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId:SUCCESS\n"));    
           
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
		
				iCnt++;

				if (GetField_CString(hRec,"pit_name",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_pit_name = [%s]\n", iCnt, csTmp));
                        	}

				if (GetField_CString(hRec,"entity_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_entity_id = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"ccy",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_ccy = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"bal_status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_bal_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"product_code",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId: %d_product_code = [%s]\n", iCnt, csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByPitId:ERROR\n"));                
		}		

		RecordSet_Destroy(rRecordSet);

		FREE_ME(csPitId);
	}

	// GetPITInfoByEntityId
	if (iRet == SUCCESS) {
		int iCnt = 0;

                char *csEntityId = NULL;

                csEntityId = (char*) malloc (128);

                sprintf(csEntityId, "%s", "E000000005");

                recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: entity_id = [%s]\n", csEntityId));
                DBObjPtr = CreateObj(DBPtr, "DBMiEntityPit", "GetPITInfoByEntityId");
                iRet = (unsigned long)(*DBObjPtr)(csEntityId, rRecordSet);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId:SUCCESS\n"));

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

				iCnt++;

				if (GetField_CString(hRec,"pit_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_pit_id = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"pit_name",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_pit_name = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"ccy",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_ccy = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"bal_status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_bal_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"product_code",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId: %d_product_code = [%s]\n", iCnt, csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call MiEntityPit:GetPITInfoByEntityId:ERROR\n"));
                }

                RecordSet_Destroy(rRecordSet);

                FREE_ME(csEntityId);
        }

	// GetRSPInfoByRspId
        if (iRet == SUCCESS) {
		int iCnt = 0;

                char *csRspId = NULL;

                csRspId = (char*) malloc (128);

                sprintf(csRspId, "%s", "RSP0000018");

                recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: rsp_id = [%s]\n", csRspId));
                DBObjPtr = CreateObj(DBPtr, "DBMiEntityRsp", "GetRSPInfoByRspId");
                iRet = (unsigned long)(*DBObjPtr)(csRspId, rRecordSet);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId:SUCCESS\n"));

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
			
				iCnt++;
	
				if (GetField_CString(hRec,"rsp_name",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_rsp_name = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"entity_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_entity_id = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"ccy",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_ccy = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"bal_status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_bal_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"node_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId: %d_node_id = [%s]\n", iCnt, csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByRspId:ERROR\n"));
                }

                RecordSet_Destroy(rRecordSet);

                FREE_ME(csRspId);
        }

	// GetRSPInfoByEntityId
        if (iRet == SUCCESS) {
		int iCnt = 0;

                char *csEntityId = NULL;

                csEntityId = (char*) malloc (128);

                sprintf(csEntityId, "%s", "E000000004");

                recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: entity_id = [%s]\n", csEntityId));
                DBObjPtr = CreateObj(DBPtr, "DBMiEntityRsp", "GetRSPInfoByEntityId");
                iRet = (unsigned long)(*DBObjPtr)(csEntityId, rRecordSet);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId:SUCCESS\n"));

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
	
				iCnt++;

				if (GetField_CString(hRec,"rsp_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_rsp_id = [%s]\n", iCnt, csTmp));
                                }
			
				if (GetField_CString(hRec,"rsp_name",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_rsp_name = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"ccy",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_ccy = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"bal_status",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_bal_status = [%s]\n", iCnt, csTmp));
                                }

				if (GetField_CString(hRec,"node_id",&csTmp)) {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId: %d_node_id = [%s]\n", iCnt, csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call MiEntityRsp:GetRSPInfoByEntityId:ERROR\n"));
                }

                RecordSet_Destroy(rRecordSet);

                FREE_ME(csEntityId);
        }

	// AddMiTxnLog
        if (iRet == SUCCESS) {
		char *csTxnId = NULL;

                csTxnId = (char*) malloc (128);

                sprintf(csTxnId, "%s", "G000015078763115");

DEBUGLOG(("process_main::Call Transaction:AddMiTxnLog: txn_id = [%s]\n", csTxnId));
                DBObjPtr = CreateObj(DBPtr, "DBTransaction", "AddMiTxnLog");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call Transaction:AddMiTxnLog:SUCCESS\n"));
		} else {
DEBUGLOG(("process_main::Call Transaction:AddMiTxnLog:ERROR\n"));
		}

		FREE_ME(csTxnId);
	}

	// AddMiOLTxnLog
	if (iRet == SUCCESS) {
                char *csTxnId = NULL;

                csTxnId = (char*) malloc (128);

                sprintf(csTxnId, "%s", "T000000000102424");

DEBUGLOG(("process_main::Call OLTransaction:AddMiOLTxnLog: txn_id = [%s]\n", csTxnId));
                DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "AddMiOLTxnLog");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call OLTransaction:AddMiOLTxnLog:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call OLTransaction:AddMiOLTxnLog:ERROR\n"));
                }

                FREE_ME(csTxnId);
        }

	// AddTxnMiDetail
	if (iRet == SUCCESS) {
		hash_t *hRec;
        	hRec = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hRec, 0);

		PutField_CString(hRec,"txn_seq","0000000002222222");	
		PutField_CString(hRec,"entity_id","E000000002");	
		PutField_CString(hRec,"party_type","RSP");	
		PutField_CString(hRec,"party_id","RSP0000022");	
		PutField_CString(hRec,"txn_ccy","CNY");	
		PutField_CString(hRec,"txn_country","CN");	
		PutField_CString(hRec,"txn_product","HBD");	
		PutField_Double(hRec,"open_acct_bal",100000);	
		PutField_Double(hRec,"acct_bal",100000);	
		PutField_Double(hRec,"open_intransit",5000);	
		PutField_Double(hRec,"intransit",5000);	
		PutField_Double(hRec,"open_ar_bal",8000);	
		PutField_Double(hRec,"ar_bal",8000);	
		PutField_CString(hRec,"txn_date","20151106");	
		PutField_CString(hRec,"report_date","20151104");	
		PutField_Double(hRec,"cost_rate",1.8);	
		PutField_Double(hRec,"actual_cost",10);	
		PutField_CString(hRec,"remittance_slip_date","20151102");	
		PutField_CString(hRec,"converted_ccy","HKD");	
		PutField_Double(hRec,"converted_amount",50);	
		PutField_CString(hRec,"remark","TEST");	
		PutField_CString(hRec,"prev_grp_txn_id","0000000001111111");	
		PutField_CString(hRec,"next_grp_txn_id","");	
		PutField_Int(hRec,"acr_prorata",1);	
		PutField_CString(hRec,"add_user","test.t");	

DEBUGLOG(("process_main::Call TxnMiDetail:Add \n"));
                DBObjPtr = CreateObj(DBPtr, "DBTxnMiDetail", "Add");
                iRet = (unsigned long)(*DBObjPtr)(hRec);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call TxnMiDetail:Add:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call TxnMiDetail:Add:ERROR\n"));
                }

		FREE_ME(hRec);
        }

	// UpdateTxnMiDetail
        if (iRet == SUCCESS) {
                hash_t *hRec;
                hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec, 0);

                PutField_CString(hRec,"txn_seq","0000000002222222");
                PutField_Double(hRec,"open_intransit",4000);
                PutField_Double(hRec,"intransit",4000);
                PutField_CString(hRec,"report_date","20151105");
                PutField_Double(hRec,"cost_rate",1.1);
                PutField_Double(hRec,"actual_cost",20);
                PutField_CString(hRec,"converted_ccy","GBP");
                PutField_Double(hRec,"converted_amount",40);
                PutField_CString(hRec,"remark","TESTING");
                PutField_CString(hRec,"prev_grp_txn_id","0000000001111111");
                PutField_CString(hRec,"next_grp_txn_id","0000000003333333");
               	PutField_Int(hRec,"acr_prorata",0);
                PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call TxnMiDetail:Update \n"));
                DBObjPtr = CreateObj(DBPtr, "DBTxnMiDetail", "Update");
                iRet = (unsigned long)(*DBObjPtr)(hRec);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call TxnMiDetail:Update:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call TxnMiDetail:Update:ERROR\n"));
                }

                FREE_ME(hRec);
        }

	// GetTxnMiDetail 
	if (iRet == SUCCESS) {
                int iCnt = 0;

                char *csTxnId = NULL;

                csTxnId = (char*) malloc (128);

                sprintf(csTxnId, "%s", "0000000002222222");

                recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: txn_id = [%s]\n", csTxnId));
                DBObjPtr = CreateObj(DBPtr, "DBTxnMiDetail", "GetTxnMiDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId, rRecordSet);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail:SUCCESS\n"));

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

                                iCnt++;

				if (GetField_CString(hRec,"entity_id",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: entity_id = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"party_type",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: party_type = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"party_id",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: party_id = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: txn_ccy = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"txn_country",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: txn_country = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"txn_product",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: txn_product = [%s]\n", csTmp));
                                }

				if (GetField_Double(hRec,"open_acct_bal",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: entity_id = [%f]\n", dTmp));
                                }

				if (GetField_Double(hRec,"acct_bal",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: acct_bal = [%f]\n", dTmp));
                                }

				if (GetField_Double(hRec,"open_intransit",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: open_intransit = [%f]\n", dTmp));
                                }
				
				if (GetField_Double(hRec,"intransit",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: intransit = [%f]\n", dTmp));
                                }

				if (GetField_Double(hRec,"open_ar_bal",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: open_ar_bal = [%f]\n", dTmp));
                                }

				if (GetField_Double(hRec,"ar_bal",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: ar_bal = [%f]\n", dTmp));
                                }

				if (GetField_CString(hRec,"txn_date",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: txn_date = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"report_date",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: report_date = [%s]\n", csTmp));
                                }

				if (GetField_Double(hRec,"cost_rate",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: cost_rate = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"actual_cost",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: actual_cost = [%f]\n", dTmp));
                                }

				if (GetField_CString(hRec,"remittance_slip_date",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: remittance_slip_date = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"converted_ccy",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: converted_ccy = [%s]\n", csTmp));
                                }

				if (GetField_Double(hRec,"converted_amount",&dTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: converted_amount = [%f]\n", dTmp));
                                }

				if (GetField_CString(hRec,"remark",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: remark = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"prev_grp_txn_id",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: prev_grp_txn_id = [%s]\n", csTmp));
                                }

				if (GetField_CString(hRec,"next_grp_txn_id",&csTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: next_grp_txn_id = [%s]\n", csTmp));
                                }

				if (GetField_Int(hRec,"acr_prorata",&iTmp)) {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail: acr_prorata = [%d]\n", iTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call TxnMiDetail:GetTxnMiDetail:ERROR\n"));
                }

                RecordSet_Destroy(rRecordSet);

                FREE_ME(csTxnId);
        }

	// AddOLTxnMiDetail
       	if (iRet == SUCCESS) {
           	hash_t *hRec;
              	hRec = (hash_t*) malloc (sizeof(hash_t));
             	hash_init(hRec, 0);

             	PutField_CString(hRec,"txn_seq","0000000008888888");
              	PutField_CString(hRec,"entity_id","E000000008");
             	PutField_CString(hRec,"party_type","OPB");
            	PutField_CString(hRec,"party_id","OPB0000088");
           	PutField_CString(hRec,"txn_ccy","CNY");
              	PutField_CString(hRec,"txn_country","CN");
            	PutField_CString(hRec,"txn_product","GTY");
              	PutField_Double(hRec,"open_acct_bal",200000);
             	PutField_Double(hRec,"acct_bal",200000);
          	PutField_Double(hRec,"open_intransit",9000);
              	PutField_Double(hRec,"intransit",9000);
             	PutField_Double(hRec,"open_ar_bal",700);
             	PutField_Double(hRec,"ar_bal",700);
            	PutField_CString(hRec,"txn_date","20151020");
              	PutField_CString(hRec,"report_date","20151021");
             	PutField_Double(hRec,"cost_rate",0.8);
             	PutField_Double(hRec,"actual_cost",80);
             	PutField_CString(hRec,"remittance_slip_date","20151022");
              	PutField_CString(hRec,"converted_ccy","HKD");
               	PutField_Double(hRec,"converted_amount",90);
             	PutField_CString(hRec,"remark","TEST");
              	PutField_CString(hRec,"prev_grp_txn_id","0000000007777777");
             	PutField_CString(hRec,"next_grp_txn_id","");
             	PutField_Int(hRec,"acr_prorata",0);
              	PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call OLTxnMiDetail:Add \n"));
              	DBObjPtr = CreateObj(DBPtr, "DBOLTxnMiDetail", "Add");
               	iRet = (unsigned long)(*DBObjPtr)(hRec);
             	if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:Add:SUCCESS\n"));
            	} else {
DEBUGLOG(("process_main::Call OLTxnMiDetail:Add:ERROR\n"));
              	}

             	FREE_ME(hRec);
      	}

	// UpdateOLTxnMiDetail
      	if (iRet == SUCCESS) {
             	hash_t *hRec;
              	hRec = (hash_t*) malloc (sizeof(hash_t));
             	hash_init(hRec, 0);

             	PutField_CString(hRec,"txn_seq","0000000008888888");
            	PutField_Double(hRec,"open_ar_bal",300);
            	PutField_Double(hRec,"ar_bal",300);
            	PutField_CString(hRec,"txn_date","20151025");
             	PutField_Double(hRec,"cost_rate",0.1);
            	PutField_Double(hRec,"actual_cost",10);
            	PutField_CString(hRec,"converted_ccy","GBP");
             	PutField_Double(hRec,"converted_amount",20);
             	PutField_CString(hRec,"remark","TESTING");
          	PutField_CString(hRec,"prev_grp_txn_id","0000000007777777");
               	PutField_CString(hRec,"next_grp_txn_id","0000000009999999");
             	PutField_Int(hRec,"acr_prorata",1);
              	PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call OLTxnMiDetail:Update \n"));
            	DBObjPtr = CreateObj(DBPtr, "DBOLTxnMiDetail", "Update");
               	iRet = (unsigned long)(*DBObjPtr)(hRec);
               	if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:Update:SUCCESS\n"));
              	} else {
DEBUGLOG(("process_main::Call OLTxnMiDetail:Update:ERROR\n"));
             	}

              	FREE_ME(hRec);
     	}	

	// GetOLTxnMiDetail
        if (iRet == SUCCESS) {
                int iCnt = 0;

                char *csTxnId = NULL;

                csTxnId = (char*) malloc (128);

                sprintf(csTxnId, "%s", "0000000008888888");

                recordset_init(rRecordSet,0);

DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: txn_id = [%s]\n", csTxnId));
                DBObjPtr = CreateObj(DBPtr, "DBOLTxnMiDetail", "GetOLTxnMiDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId, rRecordSet);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail:SUCCESS\n"));

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

                                iCnt++;

                                if (GetField_CString(hRec,"entity_id",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: entity_id = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"party_type",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: party_type = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"party_id",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: party_id = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: txn_ccy = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"txn_country",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: txn_country = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"txn_product",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: txn_product = [%s]\n", csTmp));
                                }

                                if (GetField_Double(hRec,"open_acct_bal",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: entity_id = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"acct_bal",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: acct_bal = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"open_intransit",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: open_intransit = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"intransit",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: intransit = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"open_ar_bal",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: open_ar_bal = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"ar_bal",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: ar_bal = [%f]\n", dTmp));
                                }

                                if (GetField_CString(hRec,"txn_date",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: txn_date = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"report_date",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: report_date = [%s]\n", csTmp));
                                }

                                if (GetField_Double(hRec,"cost_rate",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: cost_rate = [%f]\n", dTmp));
                                }

                                if (GetField_Double(hRec,"actual_cost",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: actual_cost = [%f]\n", dTmp));
                                }

                                if (GetField_CString(hRec,"remittance_slip_date",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: remittance_slip_date = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"converted_ccy",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: converted_ccy = [%s]\n", csTmp));
                                }

                                if (GetField_Double(hRec,"converted_amount",&dTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: converted_amount = [%f]\n", dTmp));
                                }

                                if (GetField_CString(hRec,"remark",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: remark = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"prev_grp_txn_id",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: prev_grp_txn_id = [%s]\n", csTmp));
                                }

                                if (GetField_CString(hRec,"next_grp_txn_id",&csTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: next_grp_txn_id = [%s]\n", csTmp));
                                }

                                if (GetField_Int(hRec,"acr_prorata",&iTmp)) {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail: acr_prorata = [%d]\n", iTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                } else {
DEBUGLOG(("process_main::Call OLTxnMiDetail:GetOLTxnMiDetail:ERROR\n"));
                }

                RecordSet_Destroy(rRecordSet);

                FREE_ME(csTxnId);
        }
#endif

	// AddMiBatchHeader
        if (iRet == SUCCESS) {
                hash_t *hRec;
                hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec, 0);

DEBUGLOG(("process_main: Call TxnSeq:GetNextMiActionBatchSeq\n"));
              	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMiActionBatchSeq");
		strcpy(csBatchId, (*DBObjPtr)());
DEBUGLOG(("process_main: Call TxnSeq:GenerateBatchId: [%s]\n",csBatchId));
                
		PutField_CString(hRec,"batch_id",csBatchId);
                PutField_CString(hRec,"process_type","PSP_SETTLE");
                PutField_Char(hRec,"status",'N');
                PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call MiBatchHeader:Add \n"));
                DBObjPtr = CreateObj(DBPtr, "DBMiBatchHeader", "Add");
                iRet = (unsigned long)(*DBObjPtr)(hRec);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiBatchHeader:Add:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call MiBatchHeader:Add:ERROR\n"));
                }

                FREE_ME(hRec);
        }

	// AddMiBatchDetail
        if (iRet == SUCCESS) {
                hash_t *hRec;
                hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec, 0);

		PutField_CString(hRec,"batch_id",csBatchId);
                //PutField_CString(hRec,"batch_id","E000000000000001");
                PutField_Int(hRec,"seq",1);
		PutField_CString(hRec,"entity_id","E000000011");
                PutField_CString(hRec,"party_type","RSP");
                PutField_CString(hRec,"party_id","RSP0000111");
              	PutField_CString(hRec,"txn_id","0000000000001111");
                PutField_Char(hRec,"txn_oper_ind",'I');
                PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call MiBatchDetail:Add \n"));
                DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
                iRet = (unsigned long)(*DBObjPtr)(hRec);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiBatchDetail:Add:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call MiBatchDetail:Add:ERROR\n"));
                }

                FREE_ME(hRec);
        }

	// AddMiBatchRelation
        if (iRet == SUCCESS) {
                hash_t *hRec;
                hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec, 0);

		PutField_CString(hRec,"batch_id","E000000000000001");
                PutField_CString(hRec,"org_batch_id","E000000000000002");
                PutField_Char(hRec,"relation_type",'L');
                PutField_CString(hRec,"add_user","test.t");

DEBUGLOG(("process_main::Call MiBatchRelation:Add \n"));
                DBObjPtr = CreateObj(DBPtr, "DBMiBatchRelation", "Add");
                iRet = (unsigned long)(*DBObjPtr)(hRec);
                if (iRet == PD_OK) {
DEBUGLOG(("process_main::Call MiBatchRelation:Add:SUCCESS\n"));
                } else {
DEBUGLOG(("process_main::Call MiBatchRelation:Add:ERROR\n"));
                }

                FREE_ME(hRec);
        }

	FREE_ME(hRequest);

	FREE_ME(rRecordSet);

	return iRet;
}

int parse_arg(int argc, char **argv)
{
	return SUCCESS;
}

