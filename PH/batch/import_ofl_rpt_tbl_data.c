
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
    "import_ofl_rpt_tbl_data.pc"
};


static unsigned int sqlctx = 799320451;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
5,0,0,1,381,0,6,347,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
64,0,0,2,335,0,6,487,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
119,0,0,3,0,0,17,546,0,0,1,1,0,1,0,1,9,0,0,
138,0,0,3,0,0,21,547,0,0,0,0,0,1,0,
153,0,0,3,0,0,17,581,0,0,1,1,0,1,0,1,9,0,0,
172,0,0,3,0,0,21,582,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/06/20              Dirk Wong
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
#include "import_ofl_rpt_tbl_data.h"
#include "internal.h"

#define TBL_CLIENTS	1
#define	TBL_MIRSP	2

char	cs_table[PD_CODE_LEN + 1];
char	cs_mode[PD_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

char    cDebug = 'Y';

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *file1, int iFileNum);

int	InsertOLClients(char csList[][IMPORT_FIELD_LEN]);
int	InsertMiOLEntityRsp(char csList[][IMPORT_FIELD_LEN]);

int	Delete_CLIENTS();
int	Delete_MIRSP();

int batch_init(int argc, char* argv[])
{
    if (argc < 4) {
        printf("usage:  -t Table -d Date -m Mode\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
	char	cs_file1[PD_MAX_FILE_LEN + 1];
        FILE    *file1;
        int     iRet;

        iRet = parse_arg(argc,argv);
 
        if (iRet != SUCCESS){
		printf("usage:  -t Table -d Date -m Mode\n");
                return (iRet);
	}

	char	cs_yyyy[PD_YYYY_LEN+1];
	char	cs_yyyymm[PD_YYYYMM_LEN+1];

	memset(cs_yyyy,0,PD_YYYY_LEN+1);
	memset(cs_yyyymm,0,PD_YYYYMM_LEN+1);
	strncpy(cs_yyyy,cs_date,4);
	strncpy(cs_yyyymm,cs_date,6);


//OL_CLIENTS
	if ((!strcmp(cs_table,PD_TBL_CLIENTS)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		if (!strcmp(cs_mode,PD_MODE_FULL)) {
			iRet = Delete_CLIENTS();
			sprintf(cs_file1, "%s/%s/%s/%s/full_clients_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		} else {
			sprintf(cs_file1, "%s/%s/%s/%s/clients_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		}

		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_CLIENTS);
		}
		fclose(file1);

	}

//MI_OL_ENTITY_RSP
	if ((!strcmp(cs_table,PD_TBL_MIRSP)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		if (!strcmp(cs_mode,PD_MODE_FULL)) {
			iRet = Delete_MIRSP();
			sprintf(cs_file1, "%s/%s/%s/%s/full_mi_entity_rsp_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		} else {
			sprintf(cs_file1, "%s/%s/%s/%s/mi_entity_rsp_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		}

		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_MIRSP);
		}
		fclose(file1);

	}


DEBUGLOG(("===== Finished!, iRet [%d] =====\n",iRet));

        return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}



int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_table,"");
        strcpy(cs_mode,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"t:d:m:")) != EOF) {
                switch (c) {
                        case 't':
                                strcpy(cs_table, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        case 'm':
                                strcpy(cs_mode, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if ( (!strcmp(cs_date,"")) || (!strcmp(cs_date,"")) || (!strcmp(cs_mode,"")) )
                return FAILURE;


        return SUCCESS;
}


int     parse_file(FILE *file1, int iFileNum)
{
        int     iRet = SUCCESS;
        char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];
        char*   p;
        int     iCount;


	while (fgets(cs_input_buf,PD_MAX_BUFFER,file1) != NULL)
        {
                iCount = 0;
                if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
                cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
DEBUGLOG(("*[%s]\n",cs_input_buf));
                p = mystrtok(cs_input_buf,"|");
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

                while ( (p = mystrtok(NULL,"|")) != NULL) {
                        if(p[strlen(p) - 1] == 0x0D)
                                p[strlen(p) - 1] = '\0';
                        strcpy(csList[iCount],p);
                        iCount++;
                }

		switch (iFileNum) {

			case 1:
				iRet = InsertOLClients(csList);
				break;
			case 2:
				iRet = InsertMiOLEntityRsp(csList);
				break;

		}

                if (iRet != SUCCESS)
                        break;

        }

DEBUGLOG(("Parsefile ret =[%d]\n",iRet));

        return iRet;
}



int     InsertOLClients(char csList[][IMPORT_FIELD_LEN])
{
	int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO errorolclients; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar		hv_client_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar		hv_update_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_update_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

                /* varchar         hv_client_name[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

                /* varchar         hv_status[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;

		char		hv_business_type;
		/* varchar		hv_company_name[100]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_company_name;

		/* varchar		hv_company_addr[200]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_company_addr;


		short           ind_client_id = -1;
                short           ind_create_ts = -1;
                short           ind_update_ts = -1;
                short           ind_create_user = -1;
                short           ind_update_user = -1;
                short           ind_client_name = -1;
                short           ind_status = -1;
                short           ind_business_type = -1;
                short           ind_company_name = -1;
                short           ind_company_addr = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert OLClients2\n"));

//client_id
        if (strlen(csList[IDX_CLIENTS_ID]) > 0 ) {
                hv_client_id.len = strlen(csList[IDX_CLIENTS_ID]);
                memcpy(hv_client_id.arr,csList[IDX_CLIENTS_ID],hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Insert client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }

//create_timestamp
        if (strlen(csList[IDX_CLIENTS_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_CLIENTS_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_CLIENTS_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//update_timestamp
        if (strlen(csList[IDX_CLIENTS_UPDATE_TS]) > 0 ) {
                hv_update_ts.len = strlen(csList[IDX_CLIENTS_UPDATE_TS]);
                memcpy(hv_update_ts.arr,csList[IDX_CLIENTS_UPDATE_TS],hv_update_ts.len);
                ind_update_ts = 0;
DEBUGLOG(("Insert update_ts = [%.*s]\n",hv_update_ts.len,hv_update_ts.arr));
        }

//create_user
        if (strlen(csList[IDX_CLIENTS_CREATE_USER]) > 0 ) {
                hv_create_user.len = strlen(csList[IDX_CLIENTS_CREATE_USER]);
                memcpy(hv_create_user.arr,csList[IDX_CLIENTS_CREATE_USER],hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Insert create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

//update_user
        if (strlen(csList[IDX_CLIENTS_UPDATE_USER]) > 0 ) {
                hv_update_user.len = strlen(csList[IDX_CLIENTS_UPDATE_USER]);
                memcpy(hv_update_user.arr,csList[IDX_CLIENTS_UPDATE_USER],hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("Insert update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        }

//client_name
        if (strlen(csList[IDX_CLIENTS_NAME]) > 0 ) {
                hv_client_name.len = strlen(csList[IDX_CLIENTS_NAME]);
                memcpy(hv_client_name.arr,csList[IDX_CLIENTS_NAME],hv_client_name.len);
                ind_client_name = 0;
DEBUGLOG(("Insert client_name = [%.*s]\n",hv_client_name.len,hv_client_name));
        }

//status
        if (strlen(csList[IDX_CLIENTS_STATUS]) > 0 ) {
                hv_status.len = strlen(csList[IDX_CLIENTS_STATUS]);
                memcpy(hv_status.arr,csList[IDX_CLIENTS_STATUS],hv_status.len);
                ind_status = 0;
DEBUGLOG(("Insert status = [%.*s]\n",hv_status.len,hv_status.arr));
        }

//business_type
	if (strlen(csList[IDX_CLIENTS_BUSINESS_TYPE]) > 0 ) {
		hv_business_type = csList[IDX_CLIENTS_BUSINESS_TYPE][0];
		ind_business_type = 0;
DEBUGLOG(("Insert business_type = [%d]\n",hv_business_type));
	}

//company_name
        if (strlen(csList[IDX_CLIENTS_COMPANY_NAME]) > 0 ) {
                hv_company_name.len = strlen(csList[IDX_CLIENTS_COMPANY_NAME]);
                memcpy(hv_company_name.arr,csList[IDX_CLIENTS_COMPANY_NAME],hv_company_name.len);
                ind_company_name = 0;
DEBUGLOG(("Insert company_name = [%.*s]\n",hv_company_name.len,hv_company_name.arr));
        }

//company_addr
        if (strlen(csList[IDX_CLIENTS_COMPANY_ADDR]) > 0 ) {
                hv_company_addr.len = strlen(csList[IDX_CLIENTS_COMPANY_ADDR]);
                memcpy(hv_company_addr.arr,csList[IDX_CLIENTS_COMPANY_ADDR],hv_company_addr.len);
                ind_company_addr = 0;
DEBUGLOG(("Insert company_addr = [%.*s]\n",hv_company_addr.len,hv_company_addr.arr));
        }


/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_olclients_insert(
                                                :hv_client_id:ind_client_id,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_update_ts:ind_update_ts,
                                                :hv_create_user:ind_create_user,
                                                :hv_update_user:ind_update_user,
                                                :hv_client_name:ind_client_name,
                                                :hv_status:ind_status,
                                                :hv_business_type:ind_business_type,
                                                :hv_company_name:ind_company_name,
                                                :hv_company_addr:ind_company_addr);
                END;
        END-EXEC; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 11;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "begin :hv_return_value := sp_olclients_insert ( :hv_client_i\
d:ind_client_id , :hv_create_ts:ind_create_ts , :hv_update_ts:ind_update_ts ,\
 :hv_create_user:ind_create_user , :hv_update_user:ind_update_user , :hv_clie\
nt_name:ind_client_name , :hv_status:ind_status , :hv_business_type:ind_busin\
ess_type , :hv_company_name:ind_company_name , :hv_company_addr:ind_company_a\
ddr ) ; END ;";
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
sqlstm.sqhstv[1] = (unsigned char  *)&hv_client_id;
sqlstm.sqhstl[1] = (unsigned long )12;
sqlstm.sqhsts[1] = (         int  )0;
sqlstm.sqindv[1] = (         short *)&ind_client_id;
sqlstm.sqinds[1] = (         int  )0;
sqlstm.sqharm[1] = (unsigned long )0;
sqlstm.sqadto[1] = (unsigned short )0;
sqlstm.sqtdso[1] = (unsigned short )0;
sqlstm.sqhstv[2] = (unsigned char  *)&hv_create_ts;
sqlstm.sqhstl[2] = (unsigned long )16;
sqlstm.sqhsts[2] = (         int  )0;
sqlstm.sqindv[2] = (         short *)&ind_create_ts;
sqlstm.sqinds[2] = (         int  )0;
sqlstm.sqharm[2] = (unsigned long )0;
sqlstm.sqadto[2] = (unsigned short )0;
sqlstm.sqtdso[2] = (unsigned short )0;
sqlstm.sqhstv[3] = (unsigned char  *)&hv_update_ts;
sqlstm.sqhstl[3] = (unsigned long )16;
sqlstm.sqhsts[3] = (         int  )0;
sqlstm.sqindv[3] = (         short *)&ind_update_ts;
sqlstm.sqinds[3] = (         int  )0;
sqlstm.sqharm[3] = (unsigned long )0;
sqlstm.sqadto[3] = (unsigned short )0;
sqlstm.sqtdso[3] = (unsigned short )0;
sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
sqlstm.sqhstl[4] = (unsigned long )22;
sqlstm.sqhsts[4] = (         int  )0;
sqlstm.sqindv[4] = (         short *)&ind_create_user;
sqlstm.sqinds[4] = (         int  )0;
sqlstm.sqharm[4] = (unsigned long )0;
sqlstm.sqadto[4] = (unsigned short )0;
sqlstm.sqtdso[4] = (unsigned short )0;
sqlstm.sqhstv[5] = (unsigned char  *)&hv_update_user;
sqlstm.sqhstl[5] = (unsigned long )22;
sqlstm.sqhsts[5] = (         int  )0;
sqlstm.sqindv[5] = (         short *)&ind_update_user;
sqlstm.sqinds[5] = (         int  )0;
sqlstm.sqharm[5] = (unsigned long )0;
sqlstm.sqadto[5] = (unsigned short )0;
sqlstm.sqtdso[5] = (unsigned short )0;
sqlstm.sqhstv[6] = (unsigned char  *)&hv_client_name;
sqlstm.sqhstl[6] = (unsigned long )52;
sqlstm.sqhsts[6] = (         int  )0;
sqlstm.sqindv[6] = (         short *)&ind_client_name;
sqlstm.sqinds[6] = (         int  )0;
sqlstm.sqharm[6] = (unsigned long )0;
sqlstm.sqadto[6] = (unsigned short )0;
sqlstm.sqtdso[6] = (unsigned short )0;
sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
sqlstm.sqhstl[7] = (unsigned long )4;
sqlstm.sqhsts[7] = (         int  )0;
sqlstm.sqindv[7] = (         short *)&ind_status;
sqlstm.sqinds[7] = (         int  )0;
sqlstm.sqharm[7] = (unsigned long )0;
sqlstm.sqadto[7] = (unsigned short )0;
sqlstm.sqtdso[7] = (unsigned short )0;
sqlstm.sqhstv[8] = (unsigned char  *)&hv_business_type;
sqlstm.sqhstl[8] = (unsigned long )1;
sqlstm.sqhsts[8] = (         int  )0;
sqlstm.sqindv[8] = (         short *)&ind_business_type;
sqlstm.sqinds[8] = (         int  )0;
sqlstm.sqharm[8] = (unsigned long )0;
sqlstm.sqadto[8] = (unsigned short )0;
sqlstm.sqtdso[8] = (unsigned short )0;
sqlstm.sqhstv[9] = (unsigned char  *)&hv_company_name;
sqlstm.sqhstl[9] = (unsigned long )102;
sqlstm.sqhsts[9] = (         int  )0;
sqlstm.sqindv[9] = (         short *)&ind_company_name;
sqlstm.sqinds[9] = (         int  )0;
sqlstm.sqharm[9] = (unsigned long )0;
sqlstm.sqadto[9] = (unsigned short )0;
sqlstm.sqtdso[9] = (unsigned short )0;
sqlstm.sqhstv[10] = (unsigned char  *)&hv_company_addr;
sqlstm.sqhstl[10] = (unsigned long )202;
sqlstm.sqhsts[10] = (         int  )0;
sqlstm.sqindv[10] = (         short *)&ind_company_addr;
sqlstm.sqinds[10] = (         int  )0;
sqlstm.sqharm[10] = (unsigned long )0;
sqlstm.sqadto[10] = (unsigned short )0;
sqlstm.sqtdso[10] = (unsigned short )0;
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
if (sqlca.sqlcode < 0) goto errorolclients;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errorolclients:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertMiOLEntityRsp(char csList[][IMPORT_FIELD_LEN])
{
	int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO errormiolentityrsp; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar		hv_entity_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_entity_id;

                /* varchar		hv_rsp_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_rsp_id;

                /* varchar		hv_rsp_name[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_rsp_name;

                /* varchar		hv_rsp_node_id[5]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_rsp_node_id;

                /* varchar		hv_rsp_status[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_rsp_status;

                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar		hv_update_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_update_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short           ind_entity_id = -1;
		short           ind_rsp_id = -1;
		short           ind_rsp_name = -1;
		short           ind_rsp_node_id = -1;
		short           ind_rsp_status = -1;
                short           ind_create_ts = -1;
                short           ind_update_ts = -1;
                short           ind_create_user = -1;
                short           ind_update_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert MiOLEntityRsp2\n"));

//entity_id
        if (strlen(csList[IDX_MIRSP_ENTITY_ID]) > 0 ) {
                hv_entity_id.len = strlen(csList[IDX_MIRSP_ENTITY_ID]);
                memcpy(hv_entity_id.arr,csList[IDX_MIRSP_ENTITY_ID],hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Insert entity_id = [%.*s]\n",hv_entity_id.len,hv_entity_id.arr));
        }

//rsp_id
        if (strlen(csList[IDX_MIRSP_RSP_ID]) > 0 ) {
                hv_rsp_id.len = strlen(csList[IDX_MIRSP_RSP_ID]);
                memcpy(hv_rsp_id.arr,csList[IDX_MIRSP_RSP_ID],hv_rsp_id.len);
                ind_rsp_id = 0;
DEBUGLOG(("Insert rsp_id = [%.*s]\n",hv_rsp_id.len,hv_rsp_id.arr));
        }

//rsp_name
        if (strlen(csList[IDX_MIRSP_RSP_NAME]) > 0 ) {
                hv_rsp_name.len = strlen(csList[IDX_MIRSP_RSP_NAME]);
                memcpy(hv_rsp_name.arr,csList[IDX_MIRSP_RSP_NAME],hv_rsp_name.len);
                ind_rsp_name = 0;
DEBUGLOG(("Insert rsp_name = [%.*s]\n",hv_rsp_name.len,hv_rsp_name.arr));
        }

//rsp_node_id
        if (strlen(csList[IDX_MIRSP_RSP_NODE_ID]) > 0 ) {
                hv_rsp_node_id.len = strlen(csList[IDX_MIRSP_RSP_NODE_ID]);
                memcpy(hv_rsp_node_id.arr,csList[IDX_MIRSP_RSP_NODE_ID],hv_rsp_node_id.len);
                ind_rsp_node_id = 0;
DEBUGLOG(("Insert rsp_node_id = [%.*s]\n",hv_rsp_node_id.len,hv_rsp_node_id.arr));
        }

//rsp_status
        if (strlen(csList[IDX_MIRSP_RSP_STATUS]) > 0 ) {
                hv_rsp_status.len = strlen(csList[IDX_MIRSP_RSP_STATUS]);
                memcpy(hv_rsp_status.arr,csList[IDX_MIRSP_RSP_STATUS],hv_rsp_status.len);
                ind_rsp_status = 0;
DEBUGLOG(("Insert rsp_status = [%.*s]\n",hv_rsp_status.len,hv_rsp_status.arr));
        }

//create_timestamp
        if (strlen(csList[IDX_MIRSP_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_MIRSP_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_MIRSP_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//update_timestamp
        if (strlen(csList[IDX_MIRSP_UPDATE_TS]) > 0 ) {
                hv_update_ts.len = strlen(csList[IDX_MIRSP_UPDATE_TS]);
                memcpy(hv_update_ts.arr,csList[IDX_MIRSP_UPDATE_TS],hv_update_ts.len);
                ind_update_ts = 0;
DEBUGLOG(("Insert update_ts = [%.*s]\n",hv_update_ts.len,hv_update_ts.arr));
        }

//create_user
        if (strlen(csList[IDX_MIRSP_CREATE_USER]) > 0 ) {
                hv_create_user.len = strlen(csList[IDX_MIRSP_CREATE_USER]);
                memcpy(hv_create_user.arr,csList[IDX_MIRSP_CREATE_USER],hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Insert create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

//update_user
        if (strlen(csList[IDX_MIRSP_UPDATE_USER]) > 0 ) {
                hv_update_user.len = strlen(csList[IDX_MIRSP_UPDATE_USER]);
                memcpy(hv_update_user.arr,csList[IDX_MIRSP_UPDATE_USER],hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("Insert update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        }

/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_miolentityrsp_insert(
                                                :hv_entity_id:ind_entity_id,
                                                :hv_rsp_id:ind_rsp_id,
                                                :hv_rsp_name:ind_rsp_name,
                                                :hv_rsp_node_id:ind_rsp_node_id,
                                                :hv_rsp_status:ind_rsp_status,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_update_ts:ind_update_ts,
                                                :hv_create_user:ind_create_user,
                                                :hv_update_user:ind_update_user);
                END;
        END-EXEC; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 11;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "begin :hv_return_value := sp_miolentityrsp_insert ( :hv_enti\
ty_id:ind_entity_id , :hv_rsp_id:ind_rsp_id , :hv_rsp_name:ind_rsp_name , :hv\
_rsp_node_id:ind_rsp_node_id , :hv_rsp_status:ind_rsp_status , :hv_create_ts:\
ind_create_ts , :hv_update_ts:ind_update_ts , :hv_create_user:ind_create_user\
 , :hv_update_user:ind_update_user ) ; END ;";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )64;
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
sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_id;
sqlstm.sqhstl[1] = (unsigned long )12;
sqlstm.sqhsts[1] = (         int  )0;
sqlstm.sqindv[1] = (         short *)&ind_entity_id;
sqlstm.sqinds[1] = (         int  )0;
sqlstm.sqharm[1] = (unsigned long )0;
sqlstm.sqadto[1] = (unsigned short )0;
sqlstm.sqtdso[1] = (unsigned short )0;
sqlstm.sqhstv[2] = (unsigned char  *)&hv_rsp_id;
sqlstm.sqhstl[2] = (unsigned long )12;
sqlstm.sqhsts[2] = (         int  )0;
sqlstm.sqindv[2] = (         short *)&ind_rsp_id;
sqlstm.sqinds[2] = (         int  )0;
sqlstm.sqharm[2] = (unsigned long )0;
sqlstm.sqadto[2] = (unsigned short )0;
sqlstm.sqtdso[2] = (unsigned short )0;
sqlstm.sqhstv[3] = (unsigned char  *)&hv_rsp_name;
sqlstm.sqhstl[3] = (unsigned long )52;
sqlstm.sqhsts[3] = (         int  )0;
sqlstm.sqindv[3] = (         short *)&ind_rsp_name;
sqlstm.sqinds[3] = (         int  )0;
sqlstm.sqharm[3] = (unsigned long )0;
sqlstm.sqadto[3] = (unsigned short )0;
sqlstm.sqtdso[3] = (unsigned short )0;
sqlstm.sqhstv[4] = (unsigned char  *)&hv_rsp_node_id;
sqlstm.sqhstl[4] = (unsigned long )7;
sqlstm.sqhsts[4] = (         int  )0;
sqlstm.sqindv[4] = (         short *)&ind_rsp_node_id;
sqlstm.sqinds[4] = (         int  )0;
sqlstm.sqharm[4] = (unsigned long )0;
sqlstm.sqadto[4] = (unsigned short )0;
sqlstm.sqtdso[4] = (unsigned short )0;
sqlstm.sqhstv[5] = (unsigned char  *)&hv_rsp_status;
sqlstm.sqhstl[5] = (unsigned long )4;
sqlstm.sqhsts[5] = (         int  )0;
sqlstm.sqindv[5] = (         short *)&ind_rsp_status;
sqlstm.sqinds[5] = (         int  )0;
sqlstm.sqharm[5] = (unsigned long )0;
sqlstm.sqadto[5] = (unsigned short )0;
sqlstm.sqtdso[5] = (unsigned short )0;
sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_ts;
sqlstm.sqhstl[6] = (unsigned long )16;
sqlstm.sqhsts[6] = (         int  )0;
sqlstm.sqindv[6] = (         short *)&ind_create_ts;
sqlstm.sqinds[6] = (         int  )0;
sqlstm.sqharm[6] = (unsigned long )0;
sqlstm.sqadto[6] = (unsigned short )0;
sqlstm.sqtdso[6] = (unsigned short )0;
sqlstm.sqhstv[7] = (unsigned char  *)&hv_update_ts;
sqlstm.sqhstl[7] = (unsigned long )16;
sqlstm.sqhsts[7] = (         int  )0;
sqlstm.sqindv[7] = (         short *)&ind_update_ts;
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
sqlstm.sqhstv[9] = (unsigned char  *)&hv_update_user;
sqlstm.sqhstl[9] = (unsigned long )22;
sqlstm.sqhsts[9] = (         int  )0;
sqlstm.sqindv[9] = (         short *)&ind_update_user;
sqlstm.sqinds[9] = (         int  )0;
sqlstm.sqharm[9] = (unsigned long )0;
sqlstm.sqadto[9] = (unsigned short )0;
sqlstm.sqtdso[9] = (unsigned short )0;
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
if (sqlca.sqlcode < 0) goto errormiolentityrsp;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errormiolentityrsp:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}




int     Delete_CLIENTS()
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_clients_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_CLIENTS Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete ol_clients_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from ol_clients_2 where ");

        strcat((char*)hv_dynstmt.arr, "1=1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )119;
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
        if (sqlca.sqlcode < 0) goto del_clients_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )138;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_clients_error;
}




del_clients_error:
DEBUGLOG(("del_clients_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_MIRSP()
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_mirsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_MIRSP Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete mi_ol_entity_rsp_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from mi_ol_entity_rsp_2 where ");

        strcat((char*)hv_dynstmt.arr, "1=1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )153;
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
        if (sqlca.sqlcode < 0) goto del_mirsp_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )172;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_mirsp_error;
}




del_mirsp_error:
DEBUGLOG(("del_mirsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

