
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "par_merchant_balance.pc"
};


static unsigned int sqlctx = 646818035;


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


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/01              Virginia Yun
*/

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
#include "par_merchant_balance.h"
#include "ObjPtr.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_TOKEN	'"'

#define	PD_CHAR		0x0D

OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

char    cDebug='Y';


char    cs_inputfile[PD_MAX_FILE_LEN + 1];

int parse_arg(int argc,char **argv);
int verify_file(FILE *fin, hash_t *hContext, hash_t *hRequest, hash_t *hResponse);
int process_txn(char csInList[][IMPORT_FIELD_LEN], hash_t *hContext, hash_t *hRequest, hash_t *hResponse);

int batch_init(int argc, char* argv[])
{

    if (argc < 1) {
    	printf("usage: -f input file\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	FILE	*fin;
	int	iRet;

        hash_t          *hContext, *hRequest, *hResponse;

        hContext = (hash_t *)malloc(sizeof(hash_t));
        hRequest = (hash_t *)malloc(sizeof(hash_t));
        hResponse= (hash_t *)malloc(sizeof(hash_t));

        hash_init(hContext,   0);
        hash_init(hRequest,  0);
        hash_init(hResponse, 0);

	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		printf("*usage: -f input file\n");
		return (iRet);
	}

	fin = fopen(cs_inputfile,"r");
	if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
		return FAILURE;
	}

	ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateContext");
	iRet = (unsigned long)((*ChannelObjPtr)(hContext));

	if (iRet == PD_OK) {
		iRet = verify_file(fin, hContext, hRequest, hResponse);	
	} else {
DEBUGLOG(("Error UpdateContext\n"));
	}


	fclose(fin);

	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
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
                
        return SUCCESS; 
}               


int verify_file(FILE *fin, hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
        int     iRet = FAILURE;

	int	iCount;
        char    cs_input_buf[PD_MAX_BUFFER +1]; /*read buffer*/
	char	*p;
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];

	int	iRowCnt = 0;


/* Header */    
        iCount = 0;
	iRowCnt = 0;
/*

        fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
	iRowCnt++;
*/
/* End of Header */

        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {
		iRowCnt++;

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));

                iCount = 0;

                p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p == NULL)
                        return FAILURE;

		/*
                strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_TOKEN));
                strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
		*/
		strcpy(csList[iCount],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                iCount++;

                while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
			/*
                        strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_TOKEN));
                        strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
			*/
			strcpy(csList[iCount],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                        iCount++;
                }

DEBUGLOG((">>>>>>>>>> File Line[%d] <<<<<<<<<< \n",iRowCnt));

		iRet=process_txn(csList, hContext, hRequest, hResponse);

		if (iRet != SUCCESS) {
			break;
		}	

        }


	return iRet;
}

int process_txn(char csInList[][IMPORT_FIELD_LEN], hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int iRet = SUCCESS;

        recordset_t     *rRecordSet;
        hash_t          *hRec;

        int             iTmpRet = PD_OK;

	char		*csMID;
	int		iPayoutEnable;
	char		*csService;

	char		*csCcy = strdup("");
	char		*csCountry = strdup("");

//	double		dTmp = 0.0;

	char		csPayoutAllow[2];

        char    	csTag[PD_TAG_LEN +1];
	int		iIntError;

	hash_t		*hBalAcct;
	hash_t		*hRuleReserve;
	
	int		iCnt;
	//char		*csTmp;	
	char		*csPayMethod;

        hBalAcct = (hash_t *) malloc (sizeof(hash_t));
	hash_init(hBalAcct, 0);

        hRuleReserve = (hash_t *) malloc (sizeof(hash_t));
	hash_init(hRuleReserve, 0);
	

DEBUGLOG(("MERCHANT_ACCOUNT_NMB=[%s]\n",csInList[IDX_PAR_MERCHANT_ACCOUNT_NMB]));

	// Get PH MID
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet, 0);

DEBUGLOG(("DBParMerchProfile.GetMerchant\n"));
        DBObjPtr = CreateObj(DBPtr, "DBParMerchProfile","GetMerchant");
        iTmpRet = (unsigned long)(*DBObjPtr)(csInList[IDX_PAR_MERCHANT_ACCOUNT_NMB], rRecordSet);

	// must already created	
	if (iTmpRet != PD_OK) {
DEBUGLOG(("DBParMerchProfile.GetMerchant Fail\n"));
		iRet = FAILURE;
	}

	if (iRet == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec, "merchant_id", &csMID)) {
DEBUGLOG(("merhcant record merchant_id = [%s]\n", csMID));
			}

			if (GetField_Int(hRec, "payout_enable", &iPayoutEnable)) {
DEBUGLOG(("merhcant record payout_enable = [%d]\n", iPayoutEnable));
			}

			if (GetField_CString(hRec, "service", &csService)) {
DEBUGLOG(("merhcant record service = [%s]\n", csService));
			}

			hRec = RecordSet_GetNext(rRecordSet);
		}

		if (strcmp(csInList[IDX_PAR_CURRENCY], PD_CCY_ISO_RMB) == 0) {
			strcpy(csCcy, PD_CCY_ISO_CNY);
		}
		else {
			strcpy(csCcy, csInList[IDX_PAR_CURRENCY]);
		}

		DBObjPtr = CreateObj(DBPtr,"DBService","FindCountryByService");
		if((unsigned long)(*DBObjPtr)(csService, csCountry) != FOUND){	
DEBUGLOG(("FindCountryByService Failed\n"));
			iRet = FAILURE;
		}
		else {
DEBUGLOG(("country = [%s]\n", csCountry));
		}

/*
		RecordSet_Destroy(rRecordSet);
		rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(rRecordSet, 0);

		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"ParMerchRuleReverse","GetParMerchRuleReserve");
			iTmpRet = ((unsigned long)(*DBObjPtr)(csMID, csCcy, csService, rRecordSet));
			
			if (iTmpRet != PD_OK && iTmpRet != SQL_NOT_FOUND) {
DEBUGLOG(("ParMerchRuleReserve.GetParMerchRuleReserve Fail\n"));
				iRet = FAILURE;
			}

			if (iTmpRet == SQL_NOT_FOUND) {
				PutField_CString(hRuleReserve, "merchant_id", csMID);
				PutField_CString(hRuleReserve, "ccy", csCcy);
				PutField_CString(hRuleReserve, "service", csService);

				dTmp = atof(csInList[IDX_PAR_RESERVE_RATE]);
				PutField_Double(hRuleReserve, "reserve_rate", dTmp);
				
DEBUGLOG(("Calling ParMerchRuleReserve::Add\n"));
        			DBObjPtr = CreateObj(DBPtr, "DBParMerchRuleReserve","Add");
			        iRet = (unsigned long)(*DBObjPtr)(hRuleReserve);

				if (iRet != PD_OK) {
DEBUGLOG(("Calling ParMerchRuleReserve::Add FAILED!!!!\n"));
				}

			}
		}
*/		


		if (iRet == PD_OK) {

			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalAcct","CheckMerchantBalAcct");
			iTmpRet = ((unsigned long)(*DBObjPtr)(csMID, csCountry, csCcy, csService, hBalAcct));
			
			if (iTmpRet != PD_NOT_FOUND && iTmpRet != PD_FOUND) {
DEBUGLOG(("MerchantBalAcct.CheckMerchantBalAcct Fail\n"));
				iRet = FAILURE;
			}
		}

		if (iTmpRet == PD_NOT_FOUND) {
			PutField_CString(hRequest, "merchant_id", csMID);
			PutField_Int(hContext, "total_cnt", 1);
			PutField_CString(hRequest, "action", "A");

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_ccy_1", PD_DETAIL_TAG);
			PutField_CString(hRequest, csTag, csCcy);

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_payout_1", PD_DETAIL_TAG);

			memset(csPayoutAllow, 0, sizeof(csPayoutAllow));
			sprintf(csPayoutAllow, "%d", iPayoutEnable);
			PutField_CString(hRequest, csTag, csPayoutAllow);

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_service_1", PD_DETAIL_TAG);
			PutField_CString(hRequest, csTag, csService);

			PutField_CString(hRequest, "add_user", PD_UPDATE_USER);


DEBUGLOG(("Calling TxnMgtByUsMBA::Authorize\n"));
			TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsMBA","Authorize");
			iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

			if (iRet == PD_OK) {
				if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("Calling TxnMgtByUsMCR::Authorize Return internal_error [%d]\n", iIntError));
					iRet = FAILURE;
				}
			}
		}
		else {
DEBUGLOG(("MerchantBalAcct Record Already exists, ignore ok\n"));

		}

		// Payment method 
		if (iRet == PD_OK) {
			PutField_CString(hRequest, "merchant_id", csMID);
			PutField_CString(hRequest, "add_user", PD_UPDATE_USER);
			PutField_CString(hRequest, "action", "A");

			RecordSet_Destroy(rRecordSet);
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
			recordset_init(rRecordSet, 0);

			
DEBUGLOG(("DBServicePayMethod.FindPayMethod, Service [%s]\n", csService));
		        DBObjPtr = CreateObj(DBPtr, "DBServicePayMethod","FindPayMethod");
			iRet = (unsigned long)(*DBObjPtr)(csService, rRecordSet);

			if (iRet == SUCCESS) {

				iCnt = 0;

				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_CString(hRec, "pay_method", &csPayMethod)) {
DEBUGLOG(("pay_method [%d][%s]\n", iCnt, csPayMethod));

						memset(csTag, 0, sizeof(csTag));
						sprintf(csTag, "%s_pay_method_%d", PD_DETAIL_TAG, iCnt + 1);
						PutField_CString(hRequest, csTag, csPayMethod);

						memset(csTag, 0, sizeof(csTag));	
						sprintf(csTag, "%s_disabled_%d", PD_DETAIL_TAG, iCnt + 1);
						PutField_CString(hRequest, csTag, "0");

						iCnt++;
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}


				PutField_Int(hContext, "total_cnt", iCnt);

DEBUGLOG(("Calling TxnMgtByUsMPM::Authorize\n"));
				TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsMPM","Authorize");
				iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

				if (iRet == PD_OK) {
					if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("Calling TxnMgtByUsMPM::Authorize Return internal_error [%d]\n", iIntError));
						iRet = FAILURE;
					}
				}
			}
		}	
	}


DEBUGLOG(("par_merchant_balance iRet [%d]\n", iRet));

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	hash_destroy(hBalAcct);
	FREE_ME(hBalAcct);

	FREE_ME(csCcy);
	FREE_ME(csCountry);
		
	return iRet;
}
