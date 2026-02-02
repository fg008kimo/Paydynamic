
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "import_crr_ofl_txn_data.pc"
};


static unsigned int sqlctx = 797988739;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
5,0,0,1,259,0,6,264,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,288,0,6,397,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,4,0,0,1,9,0,0,
99,0,0,3,515,0,6,619,0,0,17,17,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,1,9,0,0,
182,0,0,4,0,0,17,687,0,0,1,1,0,1,0,1,9,0,0,
201,0,0,4,0,0,21,688,0,0,0,0,0,1,0,
216,0,0,4,0,0,17,702,0,0,1,1,0,1,0,1,9,0,0,
235,0,0,4,0,0,21,703,0,0,0,0,0,1,0,
250,0,0,4,0,0,17,715,0,0,1,1,0,1,0,1,9,0,0,
269,0,0,4,0,0,21,716,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/03/31              Cody Chan
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "batchcommon.h"
#include "TxnSeq.h"
#include "import_crr_ofl_txn_data.h"
#include "internal.h"

char    cDebug;
char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *fin);
int	InsertTxnHeader(char csList[][IMPORT_FIELD_LEN]);
int	InsertTxnDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertTxnPspDetail(char csList[][IMPORT_FIELD_LEN]);
int	DeleteRecordByDate(const char* csDate);


int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
        printf("usage:  -f inputfile -d Date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
        FILE    *fin;
        int     iRet;
        
        iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS){
		printf("usage:  -f inputfile -d Date\n");
                return (iRet);
	}

        fin = fopen(cs_inputfile,"r");
        
        if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
                return FAILURE;
        }

	iRet =  DeleteRecordByDate(cs_date);
	if (iRet == SUCCESS) {
        	iRet = parse_file(fin);
	}
        fclose(fin);

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
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"f:d:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_inputfile,"") || !strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}


int     parse_file(FILE *fin)
{
        int     iRet = SUCCESS;
        char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
        char*   p;
        int     iCount;


while (fgets(cs_input_buf,PD_MAX_BUFFER,fin) != NULL)
        {
                iCount = 0;
                if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
                cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
DEBUGLOG(("*[%s]\n",cs_input_buf));
                p = mystrtok(cs_input_buf,",");
                if (p == NULL)  {
                        return FAILURE;
                }

                if (strlen(p) > 0) {

                        if(p[strlen(p) - 1] == 0x0D)
                                p[strlen(p) - 1] = '\0';
                        strcpy(csList[iCount],p);
                }
                else {
                        csList[iCount][0] ='\0';
                }
                iCount++;

                while ( (p = mystrtok(NULL,",")) != NULL) {
                        if(p[strlen(p) - 1] == 0x0D)
                                p[strlen(p) - 1] = '\0';
                        strcpy(csList[iCount],p);
                        iCount++;
                }
		
		if (strcmp(cs_date,csList[IDX_APPROVAL_DATE])) {
DEBUGLOG(("Parse file [%s] != record date [%s], now break....\n",cs_date,csList[IDX_APPROVAL_DATE]));
			iRet = FAILURE;
			break;
		}

		iRet = InsertTxnHeader(csList);
		if (iRet == SUCCESS) {
                	if (strlen(csList[IDX_MERCHANT_ID]) >0 ) {
				iRet = InsertTxnDetail(csList);

				if (!strcmp(csList[IDX_TXN_TYPE],"ODI") ||
				    !strcmp(csList[IDX_TXN_TYPE],"OAE") ||
				    !strcmp(csList[IDX_TXN_TYPE],"MRN") ) {
					iRet = InsertTxnPspDetail(csList);
				}
                	}
			else {
				iRet = InsertTxnPspDetail(csList);
			}
		}

                if (iRet != SUCCESS)
                        break;

        }

DEBUGLOG(("Parsefile ret =[%d]\n",iRet));

        return iRet;
}


int     InsertTxnDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO insert_txn_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

                /* varchar         hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_client_id = -1;
                short           ind_merchant_id = -1;
                short           ind_service_code = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert detail\n"));

/* txn id */
        if (strlen(csList[IDX_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert detail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* merchant_ref */
        if (strlen(csList[IDX_MERCHANT_REF]) > 0 ) {
                hv_merchant_ref.len = strlen(csList[IDX_MERCHANT_REF]);
                memcpy(hv_merchant_ref.arr,csList[IDX_MERCHANT_REF],hv_merchant_ref.len);
                ind_merchant_ref = 0;
DEBUGLOG(("Insert detail merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }

/* merchant_client_id */
        if (strlen(csList[IDX_MERCHANT_CLIENT_ID]) > 0 ) {
                hv_client_id.len = strlen(csList[IDX_MERCHANT_CLIENT_ID]);
                memcpy(hv_client_id.arr,csList[IDX_MERCHANT_CLIENT_ID],hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Insert detail client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
	}

/* merchant_id */
        if (strlen(csList[IDX_MERCHANT_ID]) > 0 ) {
                hv_merchant_id.len = strlen(csList[IDX_MERCHANT_ID]);
                memcpy(hv_merchant_id.arr,csList[IDX_MERCHANT_ID],hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Insert detail merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }


/* service_code */
        if (strlen(csList[IDX_SERVICE_CODE]) > 0 ) {
                hv_service_code.len = strlen(csList[IDX_SERVICE_CODE]);
                memcpy(hv_service_code.arr,csList[IDX_SERVICE_CODE],hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("Insert detail service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }


/* create_user */
                hv_create_user.len = strlen(PD_UPDATE_USER);
                memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_crr_ofl_txn_data_dt_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_merchant_ref:ind_merchant_ref,
                                                :hv_client_id:ind_client_id,
                                                :hv_merchant_id:ind_merchant_id,
                                                :hv_service_code:ind_service_code,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_crr_ofl_txn_data_dt_ins\
ert ( :hv_txn_id:ind_txn_id , :hv_merchant_ref:ind_merchant_ref , :hv_client_\
id:ind_client_id , :hv_merchant_id:ind_merchant_id , :hv_service_code:ind_ser\
vice_code , :hv_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_client_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_client_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_service_code;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
        if (sqlca.sqlcode < 0) goto insert_txn_detail_error;
}



        if (hv_return_value == SP_OK) {
                iRet = SUCCESS;
        }
        else {
DEBUGLOG(("insert_txn_detail code %d from sp\n", hv_return_value));
                iRet = FAILURE;
        }


        return iRet;
insert_txn_detail_error:
DEBUGLOG(("insert_txn_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

int     InsertTxnPspDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
        double  dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO insert_txn_psp_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;

                /* varchar         hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar         hv_baid_category[CRR_BAID_CATEGORY_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_baid_category;

                /* varchar         hv_psp_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_psp_ccy;

                double          hv_psp_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_txn_id = -1;
                short           ind_client_id = -1;
                short           ind_psp_id = -1;
                short           ind_baid = -1;
                short           ind_baid_category = -1;
                short           ind_psp_ccy = -1;
                short           ind_psp_amt = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert PSP detail\n"));


/* txn_id */
	if (strlen(csList[IDX_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert PSP detail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* client_id */
        if (strlen(csList[IDX_PSP_CLIENT_ID]) > 0 ) {
                hv_client_id.len = strlen(csList[IDX_PSP_CLIENT_ID]);
                memcpy(hv_client_id.arr,csList[IDX_PSP_CLIENT_ID],hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Insert PSP detail client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }

/* psp_id */
        if (strlen(csList[IDX_PSP_ID]) > 0 ) {
                hv_psp_id.len = strlen(csList[IDX_PSP_ID]);
                memcpy(hv_psp_id.arr,csList[IDX_PSP_ID],hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("Insert PSP detail psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        }

/* baid */
        if (strlen(csList[IDX_BAID]) > 0 ) {
                hv_baid.len = strlen(csList[IDX_BAID]);
                memcpy(hv_baid.arr,csList[IDX_BAID],hv_baid.len);
                ind_baid = 0;
DEBUGLOG(("Insert PSP detail baid = [%.*s]\n",hv_baid.len,hv_baid.arr));
        }

/* baid_category */
        if (strlen(csList[IDX_BAID_CATEGORY]) > 0 ) {
                hv_baid_category.len = strlen(csList[IDX_BAID_CATEGORY]);
                memcpy(hv_baid_category.arr,csList[IDX_BAID_CATEGORY],hv_baid_category.len);
                ind_baid_category = 0;
DEBUGLOG(("Insert PSP detail baid_category = [%.*s]\n",hv_baid_category.len,hv_baid_category.arr));
        }

/* psp_ccy */
        if (strlen(csList[IDX_PSP_CCY]) > 0 ) {
                hv_psp_ccy.len = strlen(csList[IDX_PSP_CCY]);
                memcpy(hv_psp_ccy.arr,csList[IDX_PSP_CCY],hv_psp_ccy.len);
                ind_psp_ccy = 0;
DEBUGLOG(("Insert PSP detail psp_ccy = [%.*s]\n",hv_psp_ccy.len,hv_psp_ccy.arr));
        }
	else if (strlen(csList[IDX_NET_CCY]) > 0) {
                hv_psp_ccy.len = strlen(csList[IDX_NET_CCY]);
                memcpy(hv_psp_ccy.arr,csList[IDX_NET_CCY],hv_psp_ccy.len);
                ind_psp_ccy = 0;
DEBUGLOG(("Insert PSP detail psp_ccy = [%.*s]\n",hv_psp_ccy.len,hv_psp_ccy.arr));
        }
/* psp_amt */
        if (strlen(csList[IDX_PSP_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_PSP_AMT]);
                hv_psp_amt = dTmp;
DEBUGLOG(("Insert PSP detail psp_amt = [%d]\n",hv_psp_amt));
        }
	else {
		hv_psp_amt = 0.0;
	}
        ind_psp_amt = 0;

/* create_user */
                hv_create_user.len = strlen(PD_UPDATE_USER);
                memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_crr_ofl_txn_data_pdt_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_client_id:ind_client_id,
                                                :hv_psp_id:ind_psp_id,
                                                :hv_baid:ind_baid,
                                                :hv_baid_category:ind_baid_category,
                                                :hv_psp_ccy:ind_psp_ccy,
                                                :hv_psp_amt:ind_psp_amt,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_crr_ofl_txn_data_pdt_insert ( \
:hv_txn_id:ind_txn_id , :hv_client_id:ind_client_id , :hv_psp_id:ind_psp_id ,\
 :hv_baid:ind_baid , :hv_baid_category:ind_baid_category , :hv_psp_ccy:ind_ps\
p_ccy , :hv_psp_amt:ind_psp_amt , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )48;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_client_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_psp_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_baid;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_baid_category;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_baid_category;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_psp_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_psp_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_psp_amt;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_psp_amt;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto insert_txn_psp_detail_error;
}




        if (hv_return_value == SP_OK) {
                iRet = SUCCESS;
        }
        else {
DEBUGLOG(("insert_txn_psp_detail_error code %d from sp\n", hv_return_value));
                iRet = FAILURE;
        }

        return iRet;
insert_txn_psp_detail_error:
DEBUGLOG(("insert_txn_psp_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

int     InsertTxnHeader(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
        double  dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO insert_txn_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

		/* varchar		hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar		hv_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_approval_date;

		/* varchar		hv_country[PD_COUNTRY_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                double          hv_txn_amt;
		/* varchar		hv_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_fee_ccy;

		double          hv_fee;
                /* varchar         hv_net_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_net_ccy;

                double          hv_net_amt;
                /* varchar         hv_markup_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_markup_ccy;

                double          hv_markup_amt;
                /* varchar         hv_deli_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_deli_ccy;

                double          hv_deli_amt;
                /* varchar         hv_related_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_related_txn_id;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_txn_id = -1;
                short           ind_txn_code = -1;
                short           ind_approval_date = -1;
                short           ind_country = -1;
                short           ind_ccy = -1;
                short           ind_txn_amt = -1;
                short           ind_fee_ccy = -1;
                short           ind_fee = -1;
                short           ind_net_ccy = -1;
                short           ind_net_amt = -1;
                short           ind_markup_ccy = -1;
                short           ind_markup_amt = -1;
                short           ind_deli_ccy = -1;
                short           ind_deli_amt = -1;
                short           ind_related_txn_id = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert header\n"));

/* txn id */
        if (strlen(csList[IDX_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert Header txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* txn type */
        if (strlen(csList[IDX_TXN_TYPE]) > 0 ) {
                hv_txn_code.len = strlen(csList[IDX_TXN_TYPE]);
                memcpy(hv_txn_code.arr,csList[IDX_TXN_TYPE],hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("Insert Header txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

/* approval_date */
        if (strlen(csList[IDX_APPROVAL_DATE]) > 0 ) {
                hv_approval_date.len = strlen(csList[IDX_APPROVAL_DATE]);
                memcpy(hv_approval_date.arr,csList[IDX_APPROVAL_DATE],hv_approval_date.len);
                ind_approval_date = 0;
DEBUGLOG(("Insert Header approval_date = [%.*s]\n",hv_approval_date.len,hv_approval_date.arr));
        }

/* country */
        if (strlen(csList[IDX_COUNTRY_CODE]) > 0 ) {
                hv_country.len = strlen(csList[IDX_COUNTRY_CODE]);
                memcpy(hv_country.arr,csList[IDX_COUNTRY_CODE],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert Header country = [%.*s]\n",hv_country.len,hv_country.arr));
        }


/* ccy */
        if (strlen(csList[IDX_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert Header ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        } else if (strlen(csList[IDX_NET_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_NET_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_NET_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert Header ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

/* txn_amt */
        if (strlen(csList[IDX_TXN_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_TXN_AMT]);
                hv_txn_amt = dTmp;
DEBUGLOG(("Insert Header txn_amt = [%lf]\n",hv_txn_amt));
        }
	else 
		hv_txn_amt = 0.0;
        ind_txn_amt = 0;

/* fee_ccy */
        if (strlen(csList[IDX_FEE_CCY]) > 0 ) {
                hv_fee_ccy.len = strlen(csList[IDX_FEE_CCY]);
                memcpy(hv_fee_ccy.arr,csList[IDX_FEE_CCY],hv_fee_ccy.len);
                ind_fee_ccy = 0;
DEBUGLOG(("Insert Header fee_ccy = [%.*s]\n",hv_fee_ccy.len,hv_fee_ccy.arr));
        }

/* fee */
        if (strlen(csList[IDX_FEE_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_FEE_AMT]);
                hv_fee = dTmp;
DEBUGLOG(("Insert Header fee = [%d]\n",hv_fee));
        }
	else 
		hv_fee = 0.0;
       	ind_fee = 0;

/* net_ccy */
        if (strlen(csList[IDX_NET_CCY]) > 0 ) {
                hv_net_ccy.len = strlen(csList[IDX_NET_CCY]);
                memcpy(hv_net_ccy.arr,csList[IDX_NET_CCY],hv_net_ccy.len);
                ind_net_ccy = 0;
DEBUGLOG(("Insert Header net_ccy = [%.*s]\n",hv_net_ccy.len,hv_net_ccy.arr));
        }

/* net_amt */
        if (strlen(csList[IDX_NET_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_NET_AMT]);
                hv_net_amt = dTmp;
DEBUGLOG(("Insert Header net_amt = [%d]\n",hv_net_amt));
        }
	else
		hv_net_amt = 0.0;
        ind_net_amt = 0;

/* markup_ccy */
        if (strlen(csList[IDX_MARKUP_CCY]) > 0 ) {
                hv_markup_ccy.len = strlen(csList[IDX_MARKUP_CCY]);
                memcpy(hv_markup_ccy.arr,csList[IDX_MARKUP_CCY],hv_markup_ccy.len);
                ind_markup_ccy = 0;
DEBUGLOG(("Insert Header markup_ccy = [%.*s]\n",hv_markup_ccy.len,hv_markup_ccy.arr));
        }

/* markup_amt */
        if (strlen(csList[IDX_MARKUP_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_MARKUP_AMT]);
                hv_markup_amt = dTmp;
DEBUGLOG(("Insert Header markup_amt = [%d]\n",hv_markup_amt));
        }
	else 
		hv_markup_amt = 0.0;
        ind_markup_amt = 0;

/* deli_ccy */
        if (strlen(csList[IDX_DELI_CCY]) > 0 ) {
                hv_deli_ccy.len = strlen(csList[IDX_DELI_CCY]);
                memcpy(hv_deli_ccy.arr,csList[IDX_DELI_CCY],hv_deli_ccy.len);
                ind_deli_ccy = 0;
DEBUGLOG(("Insert Header deli_ccy = [%.*s]\n",hv_deli_ccy.len,hv_deli_ccy.arr));
        }

/* deli_amt */
        if (strlen(csList[IDX_DELI_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_DELI_AMT]);
                hv_deli_amt = dTmp;
DEBUGLOG(("Insert Header deli_amt = [%d]\n",hv_deli_amt));
        }
	else 
		hv_deli_amt = 0.0;
        ind_deli_amt = 0;

/* related_txn_id */
        if (strlen(csList[IDX_RELATED_TXN_ID]) > 0 ) {
                hv_related_txn_id.len = strlen(csList[IDX_RELATED_TXN_ID]);
                memcpy(hv_related_txn_id.arr,csList[IDX_RELATED_TXN_ID],hv_related_txn_id.len);
                ind_related_txn_id = 0;
DEBUGLOG(("Insert Header related_txn_id = [%.*s]\n",hv_related_txn_id.len,hv_related_txn_id.arr));
        }

/* create_user */
        hv_create_user.len = strlen(PD_UPDATE_USER);
        memcpy(hv_approval_date.arr,csList[IDX_APPROVAL_DATE],hv_approval_date.len);
        ind_approval_date = 0;
DEBUGLOG(("Insert Header approval_date = [%.*s]\n",hv_approval_date.len,hv_approval_date.arr));
	
	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_crr_ofl_txn_data_hd_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_txn_code:ind_txn_code,
                                        :hv_approval_date:ind_approval_date,
                                        :hv_country:ind_country,
                                        :hv_ccy:ind_ccy,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_fee_ccy:ind_fee_ccy,
                                        :hv_fee:ind_fee,
                                        :hv_net_ccy:ind_net_ccy,
                                        :hv_net_amt:ind_net_amt,
                                        :hv_markup_ccy:ind_markup_ccy,
                                        :hv_markup_amt:ind_markup_amt,
                                        :hv_deli_ccy:ind_deli_ccy,
                                        :hv_deli_amt:ind_deli_amt,
                                        :hv_related_txn_id:ind_related_txn_id,
                                        :hv_create_user:ind_create_user);

                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_crr_ofl_txn_data_hd_insert ( :\
hv_txn_id:ind_txn_id , :hv_txn_code:ind_txn_code , :hv_approval_date:ind_appr\
oval_date , :hv_country:ind_country , :hv_ccy:ind_ccy , :hv_txn_amt:ind_txn_a\
mt , :hv_fee_ccy:ind_fee_ccy , :hv_fee:ind_fee , :hv_net_ccy:ind_net_ccy , :h\
v_net_amt:ind_net_amt , :hv_markup_ccy:ind_markup_ccy , :hv_markup_amt:ind_ma\
rkup_amt , :hv_deli_ccy:ind_deli_ccy , :hv_deli_amt:ind_deli_amt , :hv_relate\
d_txn_id:ind_related_txn_id , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_approval_date;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_approval_date;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[4] = (unsigned long )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_country;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_amt;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_fee_ccy;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_fee_ccy;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_fee;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_fee;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_net_ccy;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_net_ccy;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_net_amt;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_markup_ccy;
 sqlstm.sqhstl[11] = (unsigned long )5;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_markup_ccy;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_markup_amt;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_markup_amt;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_deli_ccy;
 sqlstm.sqhstl[13] = (unsigned long )5;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_deli_ccy;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_deli_amt;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_deli_amt;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_related_txn_id;
 sqlstm.sqhstl[15] = (unsigned long )22;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_related_txn_id;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[16] = (unsigned long )22;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_create_user;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto insert_txn_header_error;
}




        if (hv_return_value == SP_OK) {
                iRet = SUCCESS;
        }
        else {
DEBUGLOG(("insert_txn_header_error code %d from sp\n", hv_return_value));
                iRet = FAILURE;
        }

DEBUGLOG(("Insert Header iRet = [%d]\n",iRet));
        return iRet;
insert_txn_header_error:
DEBUGLOG(("insert_txn_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

int	DeleteRecordByDate(const char* csDate)
{
	char	*csBuf;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteRcordByDate: to Delete date [%s]\n",csDate));
	csBuf = (char*) malloc (PD_TMP_BUF_LEN);
/* delete psp txn detail */
        strcpy((char*)hv_dynstmt.arr,"delete from crr_ofl_txn_data_psp_detail where ");

        strcat((char*)hv_dynstmt.arr, "cotp_txn_id in (");
        strcat((char*)hv_dynstmt.arr, "select coth_txn_id from crr_ofl_txn_data_header where ");
        strcat((char*)hv_dynstmt.arr, "coth_approval_date = '");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "'");
        strcat((char*)hv_dynstmt.arr, ")");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )182;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )201;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto delete_error;
}



/* delete txn detail */
        strcpy((char*)hv_dynstmt.arr,"delete from crr_ofl_txn_data_detail where ");

        strcat((char*)hv_dynstmt.arr, "cotd_txn_id in (");
        strcat((char*)hv_dynstmt.arr, "select coth_txn_id from crr_ofl_txn_data_header where ");
        strcat((char*)hv_dynstmt.arr, "coth_approval_date = '");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "'");
        strcat((char*)hv_dynstmt.arr, ")");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )216;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )235;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto delete_error;
}




/* delete txn header */
        strcpy((char*)hv_dynstmt.arr,"delete from crr_ofl_txn_data_header where ");

        strcat((char*)hv_dynstmt.arr, "coth_approval_date = '");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )250;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )269;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto delete_error;
}



	return SUCCESS;
delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;

}
