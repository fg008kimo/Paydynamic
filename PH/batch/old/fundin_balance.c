
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
    "fundin_balance.pc"
};


static unsigned int sqlctx = 9832691;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"select f_fundin_ccy ,f_bank_ccy ,f_fundin_amount ,f_bank_amount ,f_approval\
_timestamp ,f_approval_user ,f_calculation_timestamp ,f_calculation_user  fro\
m funds_in where f_fundin_date=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,197,0,9,151,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,153,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,
71,0,0,1,0,0,15,230,0,0,0,0,0,1,0,
86,0,0,1,0,0,15,245,0,0,0,0,0,1,0,
101,0,0,2,0,0,32,246,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/11              LokMan Chow
add FindAllBalance				   2011/04/14		   LokMan Chow
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
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_fundin_date[PD_DATE_LEN + 1];
char    cDebug;

#define PD_TMP_TAG_LEN  25
#define PD_ROUND_UP_DEC 5

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_fundin(unsigned char* csFundInDate, hash_t* hFundIn);
int process_balance(hash_t* hFundIn);
int UpdateRateRatio(const hash_t* hFundIn);
int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage:  -d fundin_date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage:  -d fundin_date\n");
                return (iRet);
        }

	hash_t *hFundIn;
	hFundIn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hFundIn,0);

        iRet = process_fundin(cs_fundin_date, hFundIn);


	if(iRet==SUCCESS){
		iRet = process_balance(hFundIn);
	}


DEBUGLOG(("iRet = [%d]\n",iRet));

	FREE_ME(hFundIn);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_fundin(unsigned char* csFundInDate, hash_t*	hFundIn)
{               
 
        int     iRet = SUCCESS;
	int	iCnt = 0;
	char    csTag[PD_TMP_TAG_LEN +1];
	double	dTotalFundIn = 0;

DEBUGLOG(("*****Process FundIn Start*****\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_fundin_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_fundin_date;


		/* varchar	v_fundin_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundin_ccy;

		/* varchar	v_bank_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

		double	v_fundin_amount;
		double	v_bank_amount;
		/* varchar	v_approval_datetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_datetime;

		/* varchar v_approval_user[PD_USER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_user;

		/* varchar	v_cal_datetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cal_datetime;

		/* varchar v_cal_user[PD_USER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_cal_user;


		short	ind_fundin_ccy = -1;
		short	ind_bank_ccy = -1;
		short	ind_fundin_amount = -1;
		short	ind_bank_amount = -1;
		short	ind_approval_datetime = -1;
		short	ind_approval_user = -1;
		short	ind_cal_datetime = -1;
		short	ind_cal_user = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_fundin_date.len = strlen(csFundInDate);
        memcpy(hv_fundin_date.arr,csFundInDate,hv_fundin_date.len);


        /* EXEC SQL DECLARE c_cursor_get_fundin CURSOR FOR
		select 	f_fundin_ccy,
         		f_bank_ccy,
         		f_fundin_amount,
         		f_bank_amount,
			f_approval_timestamp,
			f_approval_user,
			f_calculation_timestamp,
			f_calculation_user
		  from 	funds_in
		 where	f_fundin_date = :hv_fundin_date; */ 

		
                
        /* EXEC SQL OPEN c_cursor_get_fundin; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_fundin_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_fundin
                INTO
         		v_fundin_ccy:ind_fundin_ccy,
         		v_bank_ccy:ind_bank_ccy,
         		v_fundin_amount:ind_fundin_amount,
         		v_bank_amount:ind_bank_amount,
         		v_approval_datetime:ind_approval_datetime,
			v_approval_user:ind_approval_user,
         		v_cal_datetime:ind_cal_datetime,
			v_cal_user:ind_cal_user; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundin_ccy;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundin_ccy;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_fundin_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_fundin_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_amount;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_amount;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_approval_datetime;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_approval_datetime;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_approval_user;
                sqlstm.sqhstl[5] = (unsigned long )23;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_approval_user;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_cal_datetime;
                sqlstm.sqhstl[6] = (unsigned long )17;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_cal_datetime;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_cal_user;
                sqlstm.sqhstl[7] = (unsigned long )23;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_cal_user;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* approval and calculation user + time*/
		if ((ind_cal_datetime < 0) && (ind_cal_user < 0) && (ind_approval_datetime >= 0) && (ind_approval_user >= 0)){

/* fundin_date*/
			//sprintf(csTag,"fundin_date_%d",iCnt);
			PutField_CString(hFundIn,"fundin_date",csFundInDate);
DEBUGLOG(("Process FundIn: fundin_date =[%s]\n",csFundInDate));
		
/* fundin_ccy */
			if (ind_fundin_ccy >= 0){
				sprintf(csTag,"fundin_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,v_fundin_ccy.arr);
DEBUGLOG(("Process FundIn: %s =[%.*s]\n",csTag,v_fundin_ccy.len,v_fundin_ccy.arr));
			}

/* bank_ccy */
			if (ind_bank_ccy >= 0 ){
				sprintf(csTag,"bank_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,v_bank_ccy.arr);
DEBUGLOG(("Process FundIn: %s =[%.*s]\n",csTag,v_bank_ccy.len,v_bank_ccy.arr));
			}

/* fundin_amount */
			if (ind_fundin_amount < 0 ){
DEBUGLOG(("Process FundIn: fundin_amount missing!!\n"));
				iRet = FAILURE;
			}
			else{
				sprintf(csTag,"fundin_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_fundin_amount);
DEBUGLOG(("Process FundIn: %s =[%f]\n",csTag,v_fundin_amount));

				dTotalFundIn +=v_fundin_amount;
			}

/* bank_amount */
			if (ind_bank_amount < 0 ){
DEBUGLOG(("Process FundIn: bank_amount missing!!\n"));
				iRet = FAILURE;
			}
			else{
				sprintf(csTag,"bank_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_bank_amount);
DEBUGLOG(("Process FundIn: %s =[%f]\n",csTag,v_bank_amount));
			}

			iCnt ++;
		}
 	}
        while(PD_TRUE && iRet == SUCCESS);


	if(iCnt!=0){
		PutField_Int(hFundIn,"total_record",iCnt);
DEBUGLOG(("Process FundIn: total_record=[%d]\n",iCnt));

	}
	else{
		iRet = PD_NOT_FOUND;
DEBUGLOG(("No Record Found\n"));
	}

        /* EXEC SQL CLOSE c_cursor_get_fundin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )71;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if(iRet==SUCCESS){
DEBUGLOG(("Process FundIn Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process FundIn Error\n"));
	}
        return iRet;

sql_error:
    DEBUGLOG(("process_fundin error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("fundin_balance sql error %d\n",sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_fundin; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )86;
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
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_balance(hash_t* hFundIn)
{
	int	iRet = PD_ERR;
	int	iTotal = 0;
	int	i,j, iCnt = 0;
	double	dFundInAmt = 0;
	double	dBankAmt = 0;
	double	dOrgBankAmt = 0;
	double	dOrgRate= 0;
	double	dOrgRatio= 0;
	double	dOrgDspBal= 0;
	char	*csFromCcy;
	char	*csBankCcy;
	char	*csTmp = strdup("");
	char	*csBuf = strdup("");
	char	csTag[PD_TAG_LEN +1];

	double	dRate_N = 0;
	double	dRate_D = 0;
	double	dRatio_N = 0;
	double	dRatio_D = 0;

	hash_t  *hRec;

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);


DEBUGLOG(("*****Process Balance Start*****\n"));

	if(GetField_Int(hFundIn,"total_record",&iTotal)){
DEBUGLOG(("Process Balance: total_record = [%d]\n", iTotal));
	}

	for(i=0; i<iTotal; i++){

////fundin_ccy////
		sprintf(csTag,"fundin_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csFromCcy)){
DEBUGLOG(("Process Balance: fundin_ccy = [%s]\n", csFromCcy));
		}

////fundin_amt////
		sprintf(csTag,"fundin_amount_%d",i);
		if(GetField_Double(hFundIn,csTag,&dFundInAmt)){
			dRate_N = dFundInAmt;
DEBUGLOG(("Process Balance: fundin_amt = [%f]\n", dFundInAmt));
		}

////bank_ccy////
		sprintf(csTag,"bank_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csBankCcy)){
DEBUGLOG(("Process Balance: bank_ccy = [%s]\n", csBankCcy));
		}

////bank_amt////
		sprintf(csTag,"bank_amount_%d",i);
		if(GetField_Double(hFundIn,csTag,&dBankAmt)){
			dRate_D = dBankAmt;
			dRatio_N = dBankAmt;
			dRatio_D += dBankAmt;
DEBUGLOG(("Process Balance: bank_amt = [%f]\n", dBankAmt));
		}


		DBObjPtr = CreateObj(DBPtr,"DBSebBalance","FindBalanceByCcy");
		if ((unsigned long)(*DBObjPtr)(csFromCcy,csBankCcy,rRecordSet) == PD_FOUND) {

DEBUGLOG(("Process Balance -> FindBalanceByCcy : SUCCESS\n"));

			strcpy(csTmp,csFromCcy);
			strcat(csTmp,csBankCcy);
			csTmp[strlen(csTmp)]='\0';
			sprintf(csTag,"have_ccy_%d",iCnt);
			PutField_CString(hFundIn,csTag,csTmp);
			iCnt++;

			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_Double(hRec,"bank_bal",&dOrgBankAmt)) {
					sprintf(csTag,"org_bank_amt_%d",i);
					PutField_Double(hFundIn,csTag,dOrgBankAmt);
DEBUGLOG(("FindBalanceByCcy : org_bank_amt = [%f]\n", dOrgBankAmt));
				}

				if (GetField_Double(hRec,"dsp_bal",&dOrgDspBal)) {
					sprintf(csTag,"org_dsp_bal_%d",i);
					PutField_Double(hFundIn,csTag,dOrgDspBal);
DEBUGLOG(("FindBalanceByCcy : org_dsp_bal = [%f]\n", dOrgDspBal));
				}

				if (GetField_Double(hRec,"rate",&dOrgRate)) {
					sprintf(csTag,"org_rate_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRate);
DEBUGLOG(("FindBalanceByCcy : org_rate = [%f]\n", dOrgRate));
				}

				if (GetField_Double(hRec,"ratio",&dOrgRatio)) {
					sprintf(csTag,"org_ratio_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRatio);
DEBUGLOG(("FindBalanceByCcy : org_ratio = [%f]\n", dOrgRatio));
				}

				dRate_N += (dOrgBankAmt*dOrgRate);
				dRate_D += dOrgBankAmt;
				dRatio_N += dOrgBankAmt;
				dRatio_D += dOrgBankAmt;

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		sprintf(csTag,"cal_rate_n_%d",i);
		PutField_Double(hFundIn,csTag,dRate_N);
DEBUGLOG(("Process Balance : cal_rate_n = [%f]\n", dRate_N));

		sprintf(csTag,"cal_rate_d_%d",i);
		PutField_Double(hFundIn,csTag,dRate_D);
DEBUGLOG(("Process Balance : cal_rate_d = [%f]\n", dRate_D));

		sprintf(csTag,"cal_ratio_n_%d",i);
		PutField_Double(hFundIn,csTag,dRatio_N);
DEBUGLOG(("Process Balance : cal_ratio_n = [%f]\n", dRatio_N));

		dRate_N=0;
		dRate_D=0;
		dRatio_N=0;

		RecordSet_Destroy(rRecordSet);
	}

///////////////////////////////

	DBObjPtr = CreateObj(DBPtr,"DBSebBalance","FindAllBalance");
	if ((unsigned long)(*DBObjPtr)(rRecordSet) == PD_FOUND) {

DEBUGLOG(("Process Balance -> FindAllBalance : SUCCESS\n"));

		i = iTotal;
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec){
			iRet = PD_OK;
			if(GetField_CString(hRec,"from_ccy",&csFromCcy)){
				strcpy(csBuf,csFromCcy);
				sprintf(csTag,"fundin_ccy_%d",i);
				PutField_CString(hFundIn,csTag,csFromCcy);
DEBUGLOG(("FindAllBalance : from_ccy = [%s]\n",csFromCcy));
			}
			if(GetField_CString(hRec,"bank_ccy",&csBankCcy)){
				strcat(csBuf,csBankCcy);
				sprintf(csTag,"bank_ccy_%d",i);
				PutField_CString(hFundIn,csTag,csBankCcy);
DEBUGLOG(("FindAllBalance : bank_ccy = [%s]\n",csBankCcy));
			}
			csBuf[strlen(csBuf)]='\0';

			for(j=0;j<iCnt;j++){
				sprintf(csTag,"have_ccy_%d",j);
				if(GetField_CString(hFundIn,csTag,&csTmp)){
					if(strcmp(csTmp,csBuf)==0){
						iRet = PD_FOUND;
					}
				}
			}

			if(iRet==PD_FOUND){
DEBUGLOG(("FindAllBalance : Record already processed, ignore\n"));
			}
			else{			

				if (GetField_Double(hRec,"bank_bal",&dOrgBankAmt)) {
					sprintf(csTag,"org_bank_amt_%d",i);
					PutField_Double(hFundIn,csTag,dOrgBankAmt);
DEBUGLOG(("FindAllBalance : org_bank_amt = [%f]\n", dOrgBankAmt));
				}
	
				if (GetField_Double(hRec,"rate",&dOrgRate)) {
					sprintf(csTag,"org_rate_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRate);
DEBUGLOG(("FindAllBalance : org_rate = [%f]\n", dOrgRate));
				}
	
				if (GetField_Double(hRec,"ratio",&dOrgRatio)) {
					sprintf(csTag,"org_ratio_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRatio);
DEBUGLOG(("FindAllBalance : org_ratio = [%f]\n", dOrgRatio));
				}

				dRate_N += (dOrgBankAmt*dOrgRate);
				dRate_D += dOrgBankAmt;
				dRatio_N += dOrgBankAmt;
				dRatio_D += dOrgBankAmt;
			
				sprintf(csTag,"cal_rate_n_%d",i);
				PutField_Double(hFundIn,csTag,dRate_N);
DEBUGLOG(("Process Balance : cal_rate_n = [%f]\n", dRate_N));

				sprintf(csTag,"cal_rate_d_%d",i);
				PutField_Double(hFundIn,csTag,dRate_D);
DEBUGLOG(("Process Balance : cal_rate_d = [%f]\n", dRate_D));

				sprintf(csTag,"cal_ratio_n_%d",i);
				PutField_Double(hFundIn,csTag,dRatio_N);
DEBUGLOG(("Process Balance : cal_ratio_n = [%f]\n", dRatio_N));

				dRate_N=0;
				dRate_D=0;
				dRatio_N=0;

				i++;
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

///////////////////////////////

	PutField_Double(hFundIn,"cal_ratio_d",dRatio_D);
DEBUGLOG(("Process Balance: cal_ratio_d = [%f]\n", dRatio_D));

	PutField_Int(hFundIn,"total_record",i);
DEBUGLOG(("Process Balance: total_record = [%d]\n", i));

	iRet = UpdateRateRatio(hFundIn);


	if(iRet==PD_OK){
DEBUGLOG(("Process Balance Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process Balance Error [%d]\n",iRet));
ERRLOG("fundin_balance::Process Balance Error [%d]\n",iRet);
	}

	FREE_ME(csTmp);
	FREE_ME(csBuf);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;


}


int UpdateRateRatio(const hash_t* hFundIn)
{
	int	iRet = PD_OK;
	
	double	dNumerator;
	double	dDenominator;
	double	dRate;
	double	dRatio;
	double	dOrgRate=0;
	double	dOrgRatio=0;
	double	dOrgDspBal;
	double	dDspBal;
	double	dTmp, dFundinAmt;
	double	dBankAmt;
	int	iTotal=0;
	int	i;
	char	*csTmp;
	char	csTag[PD_TAG_LEN +1];

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
	
DEBUGLOG(("*****Update Rate/Ratio Start*****\n"));

	if(GetField_Int(hFundIn,"total_record",&iTotal)){
DEBUGLOG(("Update RateRatio: total_record = [%d]\n", iTotal));
	}

	for(i=0; i<iTotal; i++){

DEBUGLOG(("Update RateRatio: process record[%d]\n", i));

////fundin_date////
		//sprintf(csTag,"fundin_date_%d",i);
                if(GetField_CString(hFundIn,"fundin_date",&csTmp)){
			PutField_CString(hTxn,"fundin_date",csTmp);
DEBUGLOG(("Update RateRatio: fundin_date = [%s]\n", csTmp));
                }

////fundin_ccy////
		sprintf(csTag,"fundin_ccy_%d",i);
                if(GetField_CString(hFundIn,csTag,&csTmp)){
			PutField_CString(hTxn,"from_ccy",csTmp);
			PutField_CString(hTxn,"fundin_ccy",csTmp);
DEBUGLOG(("Update RateRatio: fundin_ccy = [%s]\n", csTmp));
		}

////fundin_amt////
		sprintf(csTag,"fundin_amount_%d",i);
		if(!GetField_Double(hFundIn,csTag,&dFundinAmt)){
			dFundinAmt = 0;
		}
		PutField_Double(hTxn,"fundin_amt",dFundinAmt);
DEBUGLOG(("Update RateRatio: fundin_amt = [%f]\n", dFundinAmt));

////bank_ccy////
		sprintf(csTag,"bank_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csTmp)){
			PutField_CString(hTxn,"bank_ccy",csTmp);
DEBUGLOG(("Update RateRatio: bank_ccy = [%s]\n", csTmp));
		}

////bank_amt////
		sprintf(csTag,"bank_amount_%d",i);
		if(!GetField_Double(hFundIn,csTag,&dBankAmt)){
			dBankAmt = 0;
		}
		PutField_Double(hTxn,"bank_amt",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_amt = [%f] (new)\n", dBankAmt));

////org_dsp_bal////
		sprintf(csTag,"org_dsp_bal_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgDspBal)){
DEBUGLOG(("Update RateRatio: org_dsp_bal = [%f]\n", dOrgDspBal));
			dDspBal = dBankAmt + dOrgDspBal;
			PutField_Double(hTxn,"dsp_bal",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_bal = [%f] (total)\n", dDspBal));
		}

		sprintf(csTag,"org_bank_amt_%d",i);
                if(GetField_Double(hFundIn,csTag,&dTmp)){
                        dBankAmt += dTmp;
DEBUGLOG(("Update RateRatio: bank_amt = [%f] (org)\n", dTmp));
                }
		PutField_Double(hTxn,"bank_bal",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_bal = [%f] (total)\n", dBankAmt));


////org_rate////
		sprintf(csTag,"org_rate_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgRate)){
                        PutField_Double(hTxn,"org_rate",dOrgRate);
DEBUGLOG(("Update RateRatio: org_rate = [%f]\n", dOrgRate));
                }

////org_ratio////
		sprintf(csTag,"org_ratio_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgRatio)){
                        PutField_Double(hTxn,"org_ratio",dOrgRatio);
DEBUGLOG(("Update RateRatio: org_ratio = [%f]\n", dOrgRatio));
                }


////rate////
		sprintf(csTag,"cal_rate_n_%d",i);
                if(GetField_Double(hFundIn,csTag,&dNumerator)){
			if(dNumerator!=0){
				sprintf(csTag,"cal_rate_d_%d",i);
                		if(!GetField_Double(hFundIn,csTag,&dDenominator)){
DEBUGLOG(("Failed to calculate rate!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate rate!!!!\n");
					iRet = PD_ERR;
				}
			}
			
		}
		else{
DEBUGLOG(("Failed to calculate rate!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate rate!!!!\n");
			iRet = PD_ERR;
		}


		if(iRet==PD_OK){
			if((dNumerator==0)||(dNumerator==0)){
				dRate = 0;
			}
			else{
				dRate = newround((dNumerator/dDenominator),PD_ROUND_UP_DEC);
			}

			if(dRate<0){
DEBUGLOG(("Calculate rate Error!!!!\n"));
ERRLOG("fundin_balance::Calculate rate Error!!!!\n");
				iRet = PD_ERR;
			}
			else{
				PutField_Double(hTxn,"rate",dRate);
DEBUGLOG(("Update RateRatio: rate = [%f]\n", dRate));
			}
		}

////ratio////
		sprintf(csTag,"cal_ratio_n_%d",i);
                if(GetField_Double(hFundIn,csTag,&dNumerator)){
			if(!GetField_Double(hFundIn,"cal_ratio_d",&dDenominator)){
DEBUGLOG(("Failed to calculate ratio!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate ratio!!!!\n");
				iRet = PD_ERR;
			}
		}
		else{
DEBUGLOG(("Failed to calculate ratio!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate ratio!!!!\n");
			iRet = PD_ERR;
		}

		if(iRet==PD_OK){
			dRatio = newround((dNumerator/dDenominator),PD_ROUND_UP_DEC);
			if(dRatio<0){
DEBUGLOG(("Calculate ratio Error!!!!\n"));
ERRLOG("fundin_balance::Calculate ratio Error!!!!\n");
				iRet = PD_ERR;
			}
			else{
				PutField_Double(hTxn,"ratio",dRatio);
DEBUGLOG(("Update RateRatio: ratio = [%f]\n", dRatio));
			}
		}

		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
		PutField_CString(hTxn,"cal_user",PD_UPDATE_USER);

		if(iRet==PD_OK){
DEBUGLOG(("*****Update SebBalance table*****\n"));
			DBObjPtr = CreateObj(DBPtr,"DBSebBalance","Add");
			iRet = (unsigned long)(*DBObjPtr)(hTxn);
                }

		if(iRet==PD_OK){
			if(dFundinAmt!=0){
DEBUGLOG(("*****Update FundsIn table*****\n"));
				DBObjPtr = CreateObj(DBPtr,"DBFundsIn","UpdateCal");
				iRet = (unsigned long)(*DBObjPtr)(hTxn);
			}
		}

		if(iRet==PD_OK){
DEBUGLOG(("*****Update FundsIn History table*****\n"));
			DBObjPtr = CreateObj(DBPtr,"DBFundsInHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hTxn);
		}
	}



	if(iRet==PD_OK){
DEBUGLOG(("Update RateRatio Normal Exit\n"));
	}
	else{
DEBUGLOG(("Update RateRatio Error [%d]\n",iRet));
ERRLOG("fundin_balance::Update RateRatio Error [%d]\n",iRet);
	}

	FREE_ME(hTxn);
	return iRet;
}



int parse_arg(int argc,char **argv)
{
        char    c;
	strcpy(cs_fundin_date,"");

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_fundin_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_fundin_date,"")) 
                return FAILURE;

        return SUCCESS;
}
