
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
           char  filnam[41];
};
static struct sqlcxp sqlfpn =
{
    40,
    "import_crr_ofl_merch_product_code_map.pc"
};


static unsigned int sqlctx = 72684043;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
5,0,0,1,263,0,6,247,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,0,0,17,289,0,0,1,1,0,1,0,1,9,0,0,
67,0,0,2,0,0,21,290,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/03/31              Cody Chan
Modify for product code map			   2015/03/31		   Dirk Wong 
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
#include "import_crr_ofl_merch_product_code_map.h"
#include "internal.h"

char    cDebug;
char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char	cs_mode[PD_DESC_LEN + 1];

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *fin);

int	InsertOflMerchProductCodeMap(char csList[][IMPORT_FIELD_LEN]);
int     DeleteRecord();


int batch_init(int argc, char* argv[])
{
    if (argc < 4) {
        printf("usage:  -f inputfile -d Date -m Mode(FULL/DELTA)\n");
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
		printf("usage:  -f inputfile -d Date -m Mode(FULL/DELTA)\n");
                return (iRet);
	}

        fin = fopen(cs_inputfile,"r");
        
        if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
                return FAILURE;
        }

	if (!strcmp(cs_mode,"FULL")) {
		iRet = DeleteRecord();
	}

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

        while ((c = getopt(argc,argv,"f:d:m:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
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

        if (!strcmp(cs_inputfile,"") || !strcmp(cs_date,"") || !strcmp(cs_mode,""))
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

		iRet = InsertOflMerchProductCodeMap(csList);
                if (iRet != SUCCESS)
                        break;

        }

DEBUGLOG(("Parsefile ret =[%d]\n",iRet));

        return iRet;
}

int     InsertOflMerchProductCodeMap(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO insert_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

                /* varchar		hv_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merch_id;

                /* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar		hv_effective_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effective_date;

                /* varchar         hv_product_code[PD_PRODUCT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_product_code;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_merch_id = -1;
                short           ind_service_code = -1;
		short		ind_country = -1;
                short           ind_effective_date = -1;
                short           ind_product_code = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert\n"));

//merch_id
        if (strlen(csList[IDX_MERCH_ID]) > 0 ) {
                hv_merch_id.len = strlen(csList[IDX_MERCH_ID]);
                memcpy(hv_merch_id.arr,csList[IDX_MERCH_ID],hv_merch_id.len);
                ind_merch_id = 0;
DEBUGLOG(("Insert merch_id = [%.*s]\n",hv_merch_id.len,hv_merch_id.arr));
        }

//service_code
        if (strlen(csList[IDX_SERVICE_CODE]) > 0 ) {
                hv_service_code.len = strlen(csList[IDX_SERVICE_CODE]);
		memcpy(hv_service_code.arr,csList[IDX_SERVICE_CODE],hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("Insert service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

//country
        if (strlen(csList[IDX_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_COUNTRY]);
		memcpy(hv_country.arr,csList[IDX_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

//effective_date
        if (strlen(csList[IDX_EFFECTIVE_DATE]) > 0 ) {
                hv_effective_date.len = strlen(csList[IDX_EFFECTIVE_DATE]);
                memcpy(hv_effective_date.arr,csList[IDX_EFFECTIVE_DATE],hv_effective_date.len);
                ind_effective_date = 0;
DEBUGLOG(("Insert effective_date = [%.*s]\n",hv_effective_date.len,hv_effective_date.arr));
	}

//product_code
        if (strlen(csList[IDX_PRODUCT_CODE]) > 0 ) {
                hv_product_code.len = strlen(csList[IDX_PRODUCT_CODE]);
                memcpy(hv_product_code.arr,csList[IDX_PRODUCT_CODE],hv_product_code.len);
                ind_product_code = 0;
DEBUGLOG(("Insert product_code = [%.*s]\n",hv_product_code.len,hv_product_code.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_crr_ofl_merch_map_insert(
                                                :hv_merch_id:ind_merch_id,
						:hv_service_code:ind_service_code,
						:hv_country:ind_country,
						:hv_effective_date:ind_effective_date,
                                                :hv_product_code:ind_product_code,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_crr_ofl_merch_map_inser\
t ( :hv_merch_id:ind_merch_id , :hv_service_code:ind_service_code , :hv_count\
ry:ind_country , :hv_effective_date:ind_effective_date , :hv_product_code:ind\
_product_code , :hv_create_user:ind_create_user ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merch_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_country;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_effective_date;
        sqlstm.sqhstl[4] = (unsigned long )10;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_effective_date;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_product_code;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_product_code;
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
        if (sqlca.sqlcode < 0) goto insert_error;
}



        return iRet;
insert_error:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     DeleteRecord()
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteRcord Start\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete crr_ofl_merch_product_code_map */
        strcpy((char*)hv_dynstmt.arr,"delete from crr_ofl_merch_product_code_map where 1=1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )48;
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
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )67;
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
