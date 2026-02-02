
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "par_hpy_dsp_report.pc"
};


static unsigned int sqlctx = 162107835;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,70,0,4,327,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
28,0,0,2,66,0,4,342,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/05              LokMan Chow
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
#include "par_hpy_dsp_report.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_DATE_DELIMITOR "-"
#define PD_TIME_DELIMITOR ":"
#define	PD_MY_DELIMITOR	","
#define	PD_MY_QS_TOEKN	'['
#define	PD_MY_QE_TOEKN	']'

#define	PD_CHAR		0x0D

char    cDebug='Y';

char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
int parse_arg(int argc,char **argv);
int verify_file(FILE *fin,FILE *fout);
int process_file(FILE *fin);
void FormatDate(char *csInDate, char *csOutDate);
void FormatTime(char *csInTime, char *csOutTime);
char* ConvertTxnId(const char* csOldTxnId, const char* csTID);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
    	printf("usage: -f input file -o ouputfile\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	FILE	*fin,*fout;
	int	iRet;
	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		printf("*usage: -f input file -o ouputfile\n");
		return (iRet);
	}

	fin = fopen(cs_inputfile,"r");
	if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
		return FAILURE;
	}

	fout = fopen(cs_outputfile,"w");
	if (fout == NULL) {
DEBUGLOG(("Error Opefing file = [%s] for writ\n",cs_outputfile));
		fclose(fin);
		return FAILURE;
	}

DEBUGLOG(("Opened file = [%s] for writ\n",cs_outputfile));

	iRet = verify_file(fin,fout);


	fclose(fin);
	fclose(fout);

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
        strcpy(cs_outputfile,"");
                        
        while ((c = getopt(argc,argv,"f:o:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
DEBUGLOG(("[%s][%s]\n",cs_inputfile,cs_outputfile));
        if (!strcmp(cs_inputfile,"") ||!strcmp(cs_outputfile,""))
                return FAILURE;
                
        return SUCCESS; 
}               


int verify_file(FILE *fin,FILE *fout)
{
        int     iRet = FAILURE;
	int	iCount;
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
	char	*p;
	char	csTmp[PD_MAX_BUFFER +1];
	char    csDate[PD_DATE_LEN + 1];
	char    csTime[PD_DATE_LEN + 1];
	char    csFundinTime[PD_MAX_BUFFER];
	char    csPHTxnId[PD_TXN_SEQ_LEN+1];
	char    csAmount[PD_TXN_SEQ_LEN+1];
	double	dAmount = 0.0;

/* Header */    
        iCount = 0;
        fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));

//DEBUGLOG(("%s\n",cs_input_buf));
/*
        p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
        if (p == NULL)
                return FAILURE;
        strcpy(csList[iCount],p);
        iCount++;

        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                strcpy(csList[iCount],p);
                iCount++;
        }

*/

        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
                iCount = 0;

                p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p == NULL)
                        return FAILURE;
                strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_QS_TOEKN));
                strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
                iCount++;

                while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                        strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_QS_TOEKN));
                        strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
                        iCount++;
                }

DEBUGLOG(("TID=[%s]\n",csList[IDX_TID]));
DEBUGLOG(("TXN_STATUS=[%s]\n",csList[IDX_TXN_STATUS]));
DEBUGLOG(("TXN_SEQ=[%s]\n",csList[IDX_TXN_SEQ]));

		strcpy(csPHTxnId,(const char *)ConvertTxnId(csList[IDX_TXN_SEQ], csList[IDX_TID]));
		csPHTxnId[PD_TXN_SEQ_LEN]='\0';
DEBUGLOG(("PH TXN_SEQ=[%s]\n",csPHTxnId));

DEBUGLOG(("TXN_AMOUNT=[%s]\n",csList[IDX_TXN_AMOUNT]));
DEBUGLOG(("BANK_BILL_NO=[%s]\n",csList[IDX_BILL_NO]));
DEBUGLOG(("FUNDIN_DATE=[%s][%d]\n",csList[IDX_FUNDIN_DATE],strlen(csList[IDX_FUNDIN_DATE])));
		strcpy(csFundinTime, &csList[IDX_FUNDIN_DATE][strlen(csList[IDX_FUNDIN_DATE])-PD_YYYYMM_LEN-2]);
		csFundinTime[strlen(csFundinTime)]='\0';
		
		FormatTime(csFundinTime, csTime);
DEBUGLOG(("FORMATTED TIME =[%s]\n",csTime));

		memset(csDate, 0, sizeof(csDate));
		FormatDate(csList[IDX_FUNDIN_DATE], csDate);
DEBUGLOG(("FORMATTED DATE =[%s]\n",csDate));

/* Field #0 tid */
		fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TID]),csList[IDX_TID],PD_MY_DELIMITOR);

/* Field #1 txn_seq */
		if(strlen(csPHTxnId)>0)
			fprintf(fout,"%.*s%s",PD_TXN_SEQ_LEN,csPHTxnId,PD_MY_DELIMITOR);
		else
			fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_SEQ]),csList[IDX_TXN_SEQ],PD_MY_DELIMITOR);

/* Field #2 bank_bill_no */
		fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_BILL_NO]),csList[IDX_BILL_NO],PD_MY_DELIMITOR);

/* Field #3 txn_amount */
		if(is_numeric(csList[IDX_TXN_AMOUNT])){
			sprintf(csAmount, "%s.00",csList[IDX_TXN_AMOUNT]);
			fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_AMOUNT])+3,csAmount,PD_MY_DELIMITOR);
		}
		else{
			sscanf(csList[IDX_TXN_AMOUNT],"%lf",&dAmount);
			fprintf(fout,"%.2f%s",dAmount,PD_MY_DELIMITOR);
			//fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_AMOUNT]),csList[IDX_TXN_AMOUNT],PD_MY_DELIMITOR);
		}
/* Field #4 service_fee */
                fprintf(fout,"0.00%s",PD_MY_DELIMITOR);

/* Field #5 status */
	  	//fprintf(fout,"%.*s",(int)strlen(csList[IDX_TXN_STATUS]),csList[IDX_TXN_STATUS]);
		fprintf(fout,"Success%s",PD_MY_DELIMITOR);

/* Field #6 fundin date */
		fprintf(fout, "%s%s", csDate,csTime);

		fprintf(fout,"\n");
		memset(cs_input_buf,0,sizeof(cs_input_buf));
		iRet = SUCCESS;
        }


	return iRet;
}


void FormatDate(char *csInDate, char *csOutDate)
{
        char *tokenptr;
        char *dateptr;

        char  cs_date_buf[PD_MAX_BUFFER +1];
        int   iCnt = 0;

        int   csDateList[IMPORT_MAX_FIELD];

        memset(cs_date_buf, 0, sizeof(cs_date_buf));
        memset(csDateList, 0, sizeof(csDateList));

        tokenptr = mystrtok(csInDate, " ");
        strcpy(cs_date_buf, tokenptr);

        dateptr = mystrtok(cs_date_buf, PD_DATE_DELIMITOR);
        csDateList[iCnt] = atoi(dateptr);

        while ( (dateptr = mystrtok(NULL,PD_DATE_DELIMITOR)) != NULL) {
                iCnt ++;
                csDateList[iCnt] = atoi(dateptr);
        }

        sprintf(csOutDate, "%04d%02d%02d", csDateList[IDX_YEAR],csDateList[IDX_MONTH],csDateList[IDX_DAY]);

}


void FormatTime(char *csInTime, char *csOutTime)
{
        char *timeptr;

        int   iCnt = 0;

        int   csTimeList[IMPORT_MAX_FIELD];

        memset(csTimeList, 0, sizeof(csTimeList));

        timeptr = mystrtok(csInTime, PD_TIME_DELIMITOR);
        csTimeList[iCnt] = atoi(timeptr);
        while ((timeptr = mystrtok(NULL,PD_TIME_DELIMITOR)) != NULL) {
                iCnt ++;
                csTimeList[iCnt] = atoi(timeptr);
        }

        sprintf(csOutTime, "%02d%02d00", csTimeList[0],csTimeList[1]);

}

char* ConvertTxnId(const char* csOldTxnId, const char* csTID)
{
	char	csFormatedId[PD_TXN_SEQ_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO convert_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_old_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_old_txn_seq;

                /* varchar hv_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_tid;


                /* varchar v_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_seq;


                short   ind_txn_seq =  -1;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("ConvertTxnId()\n"));
	sprintf(csFormatedId,"%c%s",csOldTxnId[3],&csOldTxnId[strlen(csOldTxnId)-7]);

	hv_old_txn_seq.len = strlen(csFormatedId);
	memcpy(hv_old_txn_seq.arr,csFormatedId,hv_old_txn_seq.len);
DEBUGLOG(("ConvertTxnId:old_txn_seq = [%.*s]\n",hv_old_txn_seq.len,hv_old_txn_seq.arr));

        /* EXEC SQL SELECT	th_txn_id
		 INTO	:v_txn_seq:ind_txn_seq
                 FROM	txn_header
		 WHERE  th_vnc_ref_num = :hv_old_txn_seq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select th_txn_id into :b0:b1  from txn_header where \
th_vnc_ref_num=:b2";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_seq;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_seq;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_old_txn_seq;
        sqlstm.sqhstl[1] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto convert_error;
}



        if (ind_txn_seq>= 0)  {
                v_txn_seq.arr[v_txn_seq.len] = '\0';
DEBUGLOG(("ConvertTxnId:ph_txn_seq = [%.*s]\n",v_txn_seq.len,v_txn_seq.arr));
                return strdup((const char *) v_txn_seq.arr);
        }
        else{
		hv_tid.len = strlen(csTID);
		memcpy(hv_tid.arr,csTID,hv_tid.len);
DEBUGLOG(("ConvertTxnId:tid = [%.*s]\n",hv_tid.len,hv_tid.arr));

		/* EXEC SQL SELECT tp_txn_id
			INTO   :v_txn_seq:ind_txn_seq
			FROM   txn_psp_detail
			WHERE  tp_tid = :hv_tid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select tp_txn_id into :b0:b1  from txn_psp_detail where tp\
_tid=:b2";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_seq;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_tid;
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
  if (sqlca.sqlcode < 0) goto convert_error;
}



		if (ind_txn_seq>= 0)  {
			v_txn_seq.arr[v_txn_seq.len] = '\0';
DEBUGLOG(("ConvertTxnId:ph_txn_seq = [%.*s]\n",v_txn_seq.len,v_txn_seq.arr));
			return strdup((const char *) v_txn_seq.arr);
		}
		else{
DEBUGLOG(("ConvertTxnId:(same) ph_txn_seq = [%s]\n",csOldTxnId));
                	return strdup(csOldTxnId);
		}
	}

convert_error:
DEBUGLOG(("convert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}
