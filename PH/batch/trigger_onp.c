
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
    "trigger_onp.pc"
};


static unsigned int sqlctx = 1321627;


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
//#include "trigger_onp.h"
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
/*	if(argc<2)
	{
		DEBUGLOG(("Please input enought arguments\n"));
		return FAILURE;
	}
	else  {
        	return SUCCESS;
	}
*/
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{

	int     iRet = SUCCESS;
        char    csCmd[PD_MAX_FILE_LEN + 1];

        char    *csBatchId;
        char    *csPspId;
        char    *csChannel;
        hash_t  *hRec;
        hash_t  *hUpd;

        hUpd = (hash_t*) malloc (sizeof(hash_t));

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueHd","GetPayoutQueueHd");
        if ((*DBObjPtr)(PD_INIT,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"batch_id",&csBatchId) &&
                            GetField_CString(hRec,"psp_id",&csPspId)){

				hash_t* hPspDetail;
				hPspDetail = (hash_t*) malloc (sizeof(hash_t));
				hash_init(hPspDetail,0);
				DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
				if ((*DBObjPtr)(csPspId,hPspDetail) == PD_OK) {
					if (GetField_CString(hPspDetail,"psp_channel_code",&csChannel)) {
DEBUGLOG(("BOPsp: GetTxnPsp - channel_code  = [%s]\n",csChannel));
					}
					else {
DEBUGLOG(("BOPsp: GetTxnPsp - channel_code not found\n"));
					}
				}

                                hash_init(hUpd,0);
                                PutField_Char(hUpd,"status",PD_PROCESSING);
                                PutField_CString(hUpd,"batch_id",csBatchId);
DEBUGLOG(("TxnWebByUsONP batch_id = [%s]\n",csBatchId));
                                DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueHd","UpdateStatus");

                                if ((*DBObjPtr)(hUpd) == PD_OK) {
                                        TxnCommit();
                                        if(!strcmp(csChannel,PD_CHANNEL_TWV)){
                                                sprintf(csCmd,"send_twv_payout.sh %s >/dev/null 2>&1",csBatchId);
                                        }
                                        else if(!strcmp(csChannel,PD_CHANNEL_HPAY)){
                                                sprintf(csCmd,"send_hpy_payout.sh %s >/dev/null 2>&1",csBatchId);
                                        }
DEBUGLOG(("TxnWebByUsONP cmd = [%s]\n",csCmd));
                                        system(csCmd);
/*
                                        PutField_Char(hUpd,"status",PD_TO_PSP);
                                        DBObjPtr = CreateObj(DBPtr,"DBPayoutQueueHd","UpdateStatus");
                                        if ((*DBObjPtr)(hUpd) == PD_OK) {
DEBUGLOG(("TxnWebByUsONP DBPayoutQueueHd:UpdateStatus Success\n"));
                                        }
*/
                                }

                                hash_destroy(hUpd);
				hash_destroy(hPspDetail);
				FREE_ME(hPspDetail);
                        }

                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }

        FREE_ME(hUpd);
        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("TxnWebByUsONP Normal Exit() iRet = [%d]\n",iRet));
        return iRet;

}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

