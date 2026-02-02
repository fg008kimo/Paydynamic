
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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
"select mn_merchant_id , case  when (mp_payout_enable=1 or mp_payout_file_up\
load_enable=1) then 1 else 0  end  mp_payout_enable_ind ,mp_service ,mn_count\
ry  from par_def_merch_nmb_map ,par_merch_profile where ((mp_converted=1 and \
mp_merch_acct_nmb=mn_merchant_acct_nmb) and mp_merch_acct_nmb=:b0)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,306,0,9,520,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,523,0,0,4,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
55,0,0,1,0,0,15,562,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,574,0,0,0,0,0,1,0,
85,0,0,2,0,0,32,575,0,0,0,0,0,1,0,
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
#include "../batchcommon.h"
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
int get_merch_info(hash_t *hMerchInfo);
int update_mba_status(char *csMID, char *csCountry, char *csCcy, char *csService, char *csActiveFlag);

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
//        hash_t          *hRec;

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
	
//	int		iCnt;
	//char		*csTmp;	
//	char		*csPayMethod;

        hBalAcct = (hash_t *) malloc (sizeof(hash_t));
	hash_init(hBalAcct, 0);

	hash_t		*hMerchInfo;
	hMerchInfo = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hMerchInfo, 0);

DEBUGLOG(("MERCHANT_ACCOUNT_NMB=[%s]\n",csInList[IDX_PAR_MERCHANT_ACCOUNT_NMB]));

	// Get PH MID
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet, 0);

//DEBUGLOG(("DBParMerchProfile.GetMerchant\n"));
//        DBObjPtr = CreateObj(DBPtr, "DBParMerchProfile","GetMerchant");
//        iTmpRet = (unsigned long)(*DBObjPtr)(csInList[IDX_PAR_MERCHANT_ACCOUNT_NMB], rRecordSet);

	// must already created	
//	if (iTmpRet != PD_OK) {
//DEBUGLOG(("DBParMerchProfile.GetMerchant Fail\n"));
//		iRet = FAILURE;
//	}

	if (iRet == PD_OK) {
		PutField_CString(hMerchInfo, "merch_acct_nmb", csInList[IDX_PAR_MERCHANT_ACCOUNT_NMB]);

		iRet = get_merch_info(hMerchInfo);

		if (iRet == PD_OK) {
			GetField_CString(hMerchInfo, "merchant_id", &csMID);
			GetField_Int(hMerchInfo, "payout_enable", &iPayoutEnable);

			GetField_CString(hMerchInfo, "service", &csService);

			GetField_CString(hMerchInfo, "country", &csCountry);

DEBUGLOG(("merhcant record merchant_id = [%s]\n", csMID));
DEBUGLOG(("merhcant record payout_enable = [%d]\n", iPayoutEnable));
DEBUGLOG(("merhcant record service = [%s]\n", csService));
DEBUGLOG(("merhcant record country = [%s]\n", csCountry));
			
		}

	}

	if (iRet == PD_OK) {

		if (strcmp(csInList[IDX_PAR_CURRENCY], PD_CCY_ISO_RMB) == 0) {
			strcpy(csCcy, PD_CCY_ISO_CNY);
		}
		else {
			strcpy(csCcy, csInList[IDX_PAR_CURRENCY]);
		}

		/*
		if (strcmp(csService, "EC2") == 0) {
			strcpy(csCountry, "TW");
DEBUGLOG(("Country = [%s]\n", csCountry));
		} else if (strcmp(csService, "VNC") == 0)  {
			strcpy(csCountry, "CN");
DEBUGLOG(("Country = [%s]\n", csCountry));
		} else {
DEBUGLOG(("FindCountryByService Failed\n"));
			iRet = FAILURE;
		}
		*/
		

		/*
		DBObjPtr = CreateObj(DBPtr,"DBService","FindCountryByService");
		if((unsigned long)(*DBObjPtr)(csService, csCountry) != FOUND){	
DEBUGLOG(("FindCountryByService Failed\n"));
			iRet = FAILURE;
		}
		else {
DEBUGLOG(("country = [%s]\n", csCountry));
		}
		*/


		if (iRet == PD_OK) {

			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalAcct","CheckMerchantBalAcct");
			iTmpRet = ((unsigned long)(*DBObjPtr)(csMID, csCountry, csCcy, csService, hBalAcct));
			
			if (iTmpRet != PD_NOT_FOUND && iTmpRet != PD_FOUND) {
DEBUGLOG(("MerchantBalAcct.CheckMerchantBalAcct Fail\n"));


				// Check need update active?

				iRet = update_mba_status(csMID, csCountry, csCcy, csService, csInList[IDX_PAR_ACTIVE_FLAG]);
DEBUGLOG(("Need Update Account Status!!!\n"));
				//iRet = FAILURE;
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
			sprintf(csTag, "%s_txn_type_1", PD_DETAIL_TAG);

			memset(csPayoutAllow, 0, sizeof(csPayoutAllow));
			if (iPayoutEnable == 1) {
				sprintf(csPayoutAllow, "A");
			} else {
				sprintf(csPayoutAllow, "D");
			}

			PutField_CString(hRequest, csTag, csPayoutAllow);

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_service_1", PD_DETAIL_TAG);
			PutField_CString(hRequest, csTag, csService);

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_country_1", PD_DETAIL_TAG);
			PutField_CString(hRequest, csTag, csCountry);


			PutField_CString(hRequest, "add_user", PD_UPDATE_USER);

DEBUGLOG(("Set status by active flag!\n"));

			if (!strcmp(csInList[IDX_PAR_ACTIVE_FLAG], "1")) {
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "%s_status_1", PD_DETAIL_TAG);
				PutField_CString(hRequest, csTag, PD_ACC_OPEN);
			} else {
				memset(csTag, 0, sizeof(csTag));
				sprintf(csTag, "%s_status_1", PD_DETAIL_TAG);
				//PutField_CString(hRequest, csTag, PD_ACC_CLOSE_GENERAL);
				PutField_CString(hRequest, csTag, "C");
			}



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
		/*
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
		*/
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

int get_merch_info(hash_t *hMerchInfo)
{
	int	iRet = PD_OK;

	char	*csMerchAcctNmb;

	GetField_CString(hMerchInfo, "merch_acct_nmb", &csMerchAcctNmb);

        /* EXEC SQL WHENEVER SQLERROR GOTO get_merch_info_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merch_acct_nmb[PD_PAR_MERCH_ACCT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merch_acct_nmb;


                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		int		v_payout_enable;
		/* varchar		v_service[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service;

		/* varchar		v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


                short           ind_merchant_id = -1;
                short           ind_payout_enable = -1;
                short           ind_service = -1;
                short           ind_country = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merch_acct_nmb.len = strlen(csMerchAcctNmb);
        memcpy(hv_merch_acct_nmb.arr, csMerchAcctNmb, hv_merch_acct_nmb.len);

DEBUGLOG(("get_merch_info by [%.*s]\n", hv_merch_acct_nmb.len, hv_merch_acct_nmb.arr));

        /* EXEC SQL DECLARE c_cursor_get_merch_info CURSOR FOR
            select mn_merchant_id, 
                   case when ((mp_payout_enable =1) or (mp_payout_file_upload_enable= 1)) 
		   then 1 
                   else 0 end 
                   mp_payout_enable_ind,  
                   mp_service,
                   mn_country
              from par_def_merch_nmb_map, par_merch_profile
             where mp_converted = 1
               and mp_merch_acct_nmb = mn_merchant_acct_nmb
	       and mp_merch_acct_nmb = :hv_merch_acct_nmb; */ 


        /* EXEC SQL OPEN c_cursor_get_merch_info; */ 

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
        if (sqlca.sqlcode < 0) goto get_merch_info_error;
}


	do {

                /* EXEC SQL FETCH c_cursor_get_merch_info
                INTO
			v_merchant_id:ind_merchant_id,
			v_payout_enable:ind_payout_enable,
                        v_service:ind_service,
			v_country:ind_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_payout_enable;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_payout_enable;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_service;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_service;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_country;
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
                if (sqlca.sqlcode < 0) goto get_merch_info_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }

                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] = '\0';
DEBUGLOG(("merchant_id = [%s]\n", v_merchant_id.arr));
                        PutField_CString(hMerchInfo, "merchant_id", (const char*)v_merchant_id.arr);
                }

                if (ind_payout_enable >= 0) {
DEBUGLOG(("payout_enable = [%d]\n", v_payout_enable));
                        PutField_Int(hMerchInfo, "payout_enable", v_payout_enable);
                }

                if (ind_service >= 0) {
                        v_service.arr[v_service.len] = '\0';
DEBUGLOG(("service = [%s]\n", v_service.arr));
                        PutField_CString(hMerchInfo, "service", (const char *)v_service.arr);
                }

		if (ind_country >=0) {
			v_country.arr[v_country.len] = '\0';
DEBUGLOG(("country = [%s]\n", v_country.arr));
			PutField_CString(hMerchInfo, "country", (const char *)v_country.arr);
		}

                break; // expect one record
		
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_merch_info; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_merch_info_error;
}



DEBUGLOG(("get_merch_info return [%d]\n", iRet));

        return  iRet;

get_merch_info_error:
    DEBUGLOG(("get_merch_info error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("par_merchant_balance::get_merch_info sql error %d\n", sqlca.sqlcode);

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_merch_info; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )70;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;

}

int update_mba_status(char *csMID, char *csCountry, char *csCcy, char *csService, char *csActiveFlag)
{
	int	iRet = PD_OK;

        hash_t *hTxn;
        hTxn= (hash_t *)malloc(sizeof(hash_t));

	hash_init(hTxn, 0);
	
	PutField_CString(hTxn, "merchant_id", csMID);
	PutField_CString(hTxn, "country", csCountry);
	PutField_CString(hTxn, "ccy", csCcy);
	
	if (!strcmp(csActiveFlag, "1")) {
		PutField_CString(hTxn, "status", PD_ACC_OPEN);
	} else {
		PutField_CString(hTxn, "status", PD_ACC_CLOSE_GENERAL);
	}

	FREE_ME(hTxn);
	return iRet;
}
