
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
           char  filnam[30];
};
static struct sqlcxp sqlfpn =
{
    29,
    "import_crr_ofl_mi_txn_data.pc"
};


static unsigned int sqlctx = 2088863619;


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
   unsigned char  *sqhstv[19];
   unsigned long  sqhstl[19];
            int   sqhsts[19];
            short *sqindv[19];
            int   sqinds[19];
   unsigned long  sqharm[19];
   unsigned long  *sqharc[19];
   unsigned short  sqadto[19];
   unsigned short  sqtdso[19];
} sqlstm = {12,19};

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
5,0,0,1,567,0,6,385,0,0,19,19,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
96,0,0,2,0,0,17,453,0,0,1,1,0,1,0,1,9,0,0,
115,0,0,2,0,0,21,454,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/12/30              Dirk Wong
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
#include "import_crr_ofl_mi_txn_data.h"
#include "internal.h"

char    cDebug;
char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *fin);
int	InsertTxnData(char csList[][IMPORT_FIELD_LEN]);
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

		iRet = InsertTxnData(csList);

                if (iRet != SUCCESS)
                        break;

        }

DEBUGLOG(("Parsefile ret =[%d]\n",iRet));

        return iRet;
}


int     InsertTxnData(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
        double  dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO insert_txn_data_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

		/* varchar		hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar		hv_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_approval_date;

		/* varchar		hv_entity_id[CRR_MI_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_entity_id;

		/* varchar		hv_party_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_party_type;

		/* varchar		hv_party_id[CRR_MI_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_party_id;

		/* varchar		hv_txn_product[PD_PRODUCT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_product;

		/* varchar		hv_country[PD_COUNTRY_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                double          hv_txn_amt;
                /* varchar         hv_net_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_net_ccy;

                double          hv_net_amt;
                double          hv_intr_amt;
                double          hv_ovpa_amt;
                double          hv_udpa_amt;
                /* varchar         hv_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_fee_ccy;

                double          hv_fee_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_txn_id = -1;
                short           ind_txn_code = -1;
                short           ind_approval_date = -1;
                short           ind_entity_id = -1;
                short           ind_party_type = -1;
                short           ind_party_id = -1;
                short           ind_txn_product = -1;
                short           ind_country = -1;
                short           ind_ccy = -1;
                short           ind_txn_amt = -1;
                short           ind_net_ccy = -1;
                short           ind_net_amt = -1;
                short           ind_intr_amt = -1;
                short           ind_ovpa_amt = -1;
                short           ind_udpa_amt = -1;
                short           ind_fee_ccy = -1;
                short           ind_fee_amt = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert txn data\n"));

/* txn id */
        if (strlen(csList[IDX_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert Data txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* txn code */
        if (strlen(csList[IDX_TXN_CODE]) > 0 ) {
                hv_txn_code.len = strlen(csList[IDX_TXN_CODE]);
                memcpy(hv_txn_code.arr,csList[IDX_TXN_CODE],hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("Insert Data txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

/* approval_date */
        if (strlen(csList[IDX_APPROVAL_DATE]) > 0 ) {
                hv_approval_date.len = strlen(csList[IDX_APPROVAL_DATE]);
                memcpy(hv_approval_date.arr,csList[IDX_APPROVAL_DATE],hv_approval_date.len);
                ind_approval_date = 0;
DEBUGLOG(("Insert Data approval_date = [%.*s]\n",hv_approval_date.len,hv_approval_date.arr));
        }

/* entity_id */
        if (strlen(csList[IDX_ENTITY_ID]) > 0 ) {
                hv_entity_id.len = strlen(csList[IDX_ENTITY_ID]);
                memcpy(hv_entity_id.arr,csList[IDX_ENTITY_ID],hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Insert Data entity_id = [%.*s]\n",hv_entity_id.len,hv_entity_id.arr));
        }

/* party_type */
        if (strlen(csList[IDX_PARTY_TYPE]) > 0 ) {
                hv_party_type.len = strlen(csList[IDX_PARTY_TYPE]);
                memcpy(hv_party_type.arr,csList[IDX_PARTY_TYPE],hv_party_type.len);
                ind_party_type = 0;
DEBUGLOG(("Insert Data party_type = [%.*s]\n",hv_party_type.len,hv_party_type.arr));
        }

/* party_id */
        if (strlen(csList[IDX_PARTY_ID]) > 0 ) {
                hv_party_id.len = strlen(csList[IDX_PARTY_ID]);
                memcpy(hv_party_id.arr,csList[IDX_PARTY_ID],hv_party_id.len);
                ind_party_id = 0;
DEBUGLOG(("Insert Data party_id = [%.*s]\n",hv_party_id.len,hv_party_id.arr));
        }

/* txn_product */
        if (strlen(csList[IDX_TXN_PRODUCT]) > 0 ) {
                hv_txn_product.len = strlen(csList[IDX_TXN_PRODUCT]);
                memcpy(hv_txn_product.arr,csList[IDX_TXN_PRODUCT],hv_txn_product.len);
                ind_txn_product = 0;
DEBUGLOG(("Insert Data txn_product = [%.*s]\n",hv_txn_product.len,hv_txn_product.arr));
        }

/* country */
        if (strlen(csList[IDX_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_COUNTRY]);
                memcpy(hv_country.arr,csList[IDX_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert Data country = [%.*s]\n",hv_country.len,hv_country.arr));
        }


/* ccy */
        if (strlen(csList[IDX_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert Data ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        } else if (strlen(csList[IDX_NET_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_NET_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_NET_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert Data ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

/* txn_amt */
        if (strlen(csList[IDX_TXN_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_TXN_AMT]);
                hv_txn_amt = dTmp;
DEBUGLOG(("Insert Data txn_amt = [%lf]\n",hv_txn_amt));
        }
	else 
		hv_txn_amt = 0.0;
        ind_txn_amt = 0;

/* net_ccy */
        if (strlen(csList[IDX_NET_CCY]) > 0 ) {
                hv_net_ccy.len = strlen(csList[IDX_NET_CCY]);
                memcpy(hv_net_ccy.arr,csList[IDX_NET_CCY],hv_net_ccy.len);
                ind_net_ccy = 0;
DEBUGLOG(("Insert Data net_ccy = [%.*s]\n",hv_net_ccy.len,hv_net_ccy.arr));
        }

/* net_amt */
        if (strlen(csList[IDX_NET_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_NET_AMT]);
                hv_net_amt = dTmp;
DEBUGLOG(("Insert Data net_amt = [%d]\n",hv_net_amt));
        }
	else
		hv_net_amt = 0.0;
        ind_net_amt = 0;

/* intr_amt */
        if (strlen(csList[IDX_INTR_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_INTR_AMT]);
                hv_intr_amt = dTmp;
DEBUGLOG(("Insert Data intr_amt = [%d]\n",hv_intr_amt));
        }
	else 
		hv_intr_amt = 0.0;
        ind_intr_amt = 0;

/* ovpa_amt */
        if (strlen(csList[IDX_OVPA_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_OVPA_AMT]);
                hv_ovpa_amt = dTmp;
DEBUGLOG(("Insert Data ovpa_amt = [%d]\n",hv_ovpa_amt));
        }
	else 
		hv_ovpa_amt = 0.0;
        ind_ovpa_amt = 0;

/* udpa_amt */
        if (strlen(csList[IDX_UDPA_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_UDPA_AMT]);
                hv_udpa_amt = dTmp;
DEBUGLOG(("Insert Data udpa_amt = [%d]\n",hv_udpa_amt));
        }
	else 
		hv_udpa_amt = 0.0;
        ind_udpa_amt = 0;

/* fee_ccy */
        if (strlen(csList[IDX_FEE_CCY]) > 0 ) {
                hv_fee_ccy.len = strlen(csList[IDX_FEE_CCY]);
                memcpy(hv_fee_ccy.arr,csList[IDX_FEE_CCY],hv_fee_ccy.len);
                ind_fee_ccy = 0;
DEBUGLOG(("Insert Data fee_ccy = [%.*s]\n",hv_fee_ccy.len,hv_fee_ccy.arr));
        }

/* net_amt */
        if (strlen(csList[IDX_FEE_AMT]) > 0 ) {
		dTmp = string2double(csList[IDX_FEE_AMT]);
                hv_fee_amt = dTmp;
DEBUGLOG(("Insert Data fee_amt = [%d]\n",hv_fee_amt));
        }
	else
		hv_fee_amt = 0.0;
        ind_fee_amt = 0;

/* create_user */
        hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_crr_mi_txn_data_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_txn_code:ind_txn_code,
                                        :hv_approval_date:ind_approval_date,
                                        :hv_entity_id:ind_entity_id,
                                        :hv_party_type:ind_party_type,
                                        :hv_party_id:ind_party_id,
                                        :hv_txn_product:ind_txn_product,
                                        :hv_country:ind_country,
                                        :hv_ccy:ind_ccy,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_net_ccy:ind_net_ccy,
                                        :hv_net_amt:ind_net_amt,
                                        :hv_intr_amt:ind_intr_amt,
                                        :hv_ovpa_amt:ind_ovpa_amt,
                                        :hv_udpa_amt:ind_udpa_amt,
                                        :hv_fee_ccy:ind_fee_ccy,
                                        :hv_fee_amt:ind_fee_amt,
                                        :hv_create_user:ind_create_user);

                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_crr_mi_txn_data_insert ( :hv_t\
xn_id:ind_txn_id , :hv_txn_code:ind_txn_code , :hv_approval_date:ind_approval\
_date , :hv_entity_id:ind_entity_id , :hv_party_type:ind_party_type , :hv_par\
ty_id:ind_party_id , :hv_txn_product:ind_txn_product , :hv_country:ind_countr\
y , :hv_ccy:ind_ccy , :hv_txn_amt:ind_txn_amt , :hv_net_ccy:ind_net_ccy , :hv\
_net_amt:ind_net_amt , :hv_intr_amt:ind_intr_amt , :hv_ovpa_amt:ind_ovpa_amt \
, :hv_udpa_amt:ind_udpa_amt , :hv_fee_ccy:ind_fee_ccy , :hv_fee_amt:ind_fee_a\
mt , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_entity_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_party_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_party_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_product;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_product;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[8] = (unsigned long )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_country;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_ccy;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_txn_amt;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_net_ccy;
 sqlstm.sqhstl[11] = (unsigned long )5;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_net_ccy;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_net_amt;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_intr_amt;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_intr_amt;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_ovpa_amt;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_ovpa_amt;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_udpa_amt;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_udpa_amt;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_fee_ccy;
 sqlstm.sqhstl[16] = (unsigned long )5;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_fee_ccy;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_fee_amt;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_fee_amt;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[18] = (unsigned long )22;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_create_user;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto insert_txn_data_error;
}




        if (hv_return_value == SP_OK) {
                iRet = SUCCESS;
        }
        else {
DEBUGLOG(("insert_txn_data_error code %d from sp\n", hv_return_value));
                iRet = FAILURE;
        }

DEBUGLOG(("Insert Data iRet = [%d]\n",iRet));
        return iRet;
insert_txn_data_error:
DEBUGLOG(("insert_txn_data_error code %d\n", sqlca.sqlcode));
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

/* delete txn data */
        strcpy((char*)hv_dynstmt.arr,"delete from crr_mi_txn_data where ");

        strcat((char*)hv_dynstmt.arr, "cmtd_approval_date = '");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )96;
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
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )115;
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
