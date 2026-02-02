
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
    "check_payout_resp.pc"
};


static unsigned int sqlctx = 72722411;


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
#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "dbutility.h"

//#include "ExchangeRate.h"
#include "SystemParameter.h"

OBJPTR(DB);
char    cDebug = 'Y';



int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{

	int     iRet = SUCCESS;

        char    *csBatchId;
        char    *csSeq;
        char    *csGenTxnId;
        char    *csTmp;
        hash_t  *hRec;
        hash_t  *hDtl;
        hash_t  *hTmp;
        hash_t  *hUpd;
	int	iRetCnt = 0;
	int	iTotalCnt = 0;
	int	iTmp = 0;
	char	cStatus;

        hUpd = (hash_t*) malloc (sizeof(hash_t));

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        recordset_t     *rDetailSet;
        rDetailSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rDetailSet,0);

        recordset_t     *rTmpSet;
        rTmpSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rTmpSet,0);

        DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueHd","GetPayoutQueueHd");
        if ((*DBObjPtr)(PD_TO_PSP,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
			iRetCnt = 0;
			iTotalCnt = 0;
			hash_init(hUpd,0);
                        if (GetField_CString(hRec,"batch_id",&csBatchId)){ 
                                PutField_CString(hUpd,"batch_id",csBatchId);
DEBUGLOG(("batch_id = [%s]\n",csBatchId));
			}
                        if (GetField_CString(hRec,"queue_seq",&csSeq)){ 
                                PutField_CString(hUpd,"queue_seq",csSeq);
DEBUGLOG(("queue_seq = [%s]\n",csSeq));
			}
			if(GetField_Int(hRec,"num_of_record",&iTotalCnt)){
DEBUGLOG(("num_of_record = [%d]\n",iTotalCnt));
			}

			recordset_init(rDetailSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueDt","GetPayoutQueueDt");
			if ((*DBObjPtr)(csBatchId,csSeq,rDetailSet) == PD_OK) {
				hDtl = RecordSet_GetFirst(rDetailSet);
				while (hDtl) {
					if(GetField_Int(hDtl,"seq_num",&iTmp)){
DEBUGLOG(("seq_num = [%d]\n",iTmp));
					}
					if(GetField_CString(hDtl,"txn_id",&csGenTxnId)){
DEBUGLOG(("txn_id = [%s]\n",csGenTxnId));
					}
					if(GetField_Char(hDtl,"status",&cStatus)){
						if((cStatus==PD_ACCEPT) || (cStatus==PD_REJECT)){
							iRetCnt ++;
						}
DEBUGLOG(("status = [%c]\n",cStatus));
					}
					hDtl = RecordSet_GetNext(rDetailSet);
				}
			}
			if(iRetCnt==iTotalCnt){
				PutField_Char(hUpd,"status",PD_COMPLETE);
				DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueHd","UpdateStatus");
				if ((*DBObjPtr)(hUpd) == PD_OK) {
DEBUGLOG(("DBPayoutQueueHd:UpdateStatus Success\n"));
				}


DEBUGLOG(("Call DBPayoutGeneratedFileDT:GetDetailByGenId\n"));
				recordset_init(rTmpSet,0);
				DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileDT","GetDetailByGenId");
				if((unsigned long)(*DBObjPtr)(csGenTxnId,rTmpSet)==PD_OK) {
					hTmp = RecordSet_GetFirst(rTmpSet);
					while (hTmp) {
						if(GetField_CString(hTmp,"file_id",&csTmp)){
							PutField_CString(hUpd,"file_id",csTmp);
DEBUGLOG(("GetDetailByGenId: file_id = [%s]\n",csTmp));
						}
						hTmp = RecordSet_GetNext(rTmpSet);
					}
				}
				PutField_Int(hUpd,"status",PD_PAYOUTFILE_APPROVE_BY_PSP);
				DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","Update");
				iRet = (unsigned long)(*DBObjPtr)(hUpd);
			}
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }

        FREE_ME(hUpd);
        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        RecordSet_Destroy(rDetailSet);
        FREE_ME(rDetailSet);
        RecordSet_Destroy(rTmpSet);
        FREE_ME(rTmpSet);

DEBUGLOG(("Normal Exit() iRet = [%d]\n",iRet));
        return iRet;

}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

