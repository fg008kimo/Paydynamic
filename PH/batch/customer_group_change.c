
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "customer_group_change.pc"
};


static unsigned int sqlctx = 1262329651;


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
Init Version                                       2013/11/06              LokMan Chow
Remove windows new line char			   2018/01/19		   Dirk Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlca.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_MY_TOKEN	","
#define	MAX_INFO_FIELD	3
#define	PD_CHAR		0x0D

char    c_field_list[MAX_INFO_FIELD][PD_TAG_LEN] = {"customer_tag","from_customer_group","to_customer_group"};

char	cDebug='Y';
char	cs_filename[PD_MAX_FILE_LEN+1];
char	cs_merchant_id[PD_MERCHANT_ID_LEN+1];
char	cs_service_code[PD_SERVICE_CODE_LEN+1];
int	change_historical=1;
//char	cs_date[PD_DATE_LEN+1];

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int get_customer(FILE *fp_list,recordset_t *rRecordSet);
void extract(char* log, hash_t *hTxn);
int change_group(recordset_t *rRecordSet);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int	iRet = parse_arg(argc,argv);
	FILE    *fp_list;

	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	if (iRet != SUCCESS) {
printf("usage: -f filename -m merchant_id -h change_historical [0:No, 1:Yes]\n");
		return FAILURE;
	}
	else{
		fp_list = fopen(cs_filename, "r");
		if (fp_list== NULL){
printf("unable to open file %s\n",cs_filename);
			return FAILURE;
		}
	}

	if(iRet==SUCCESS){
		iRet = get_customer(fp_list,rRecordSet);
	}
	
	if(iRet==SUCCESS){
		iRet = change_group(rRecordSet);
	}

	fclose(fp_list);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char	c;
	strcpy(cs_filename,"");
	strcpy(cs_merchant_id,"");
	change_historical = PD_TRUE;
	
	//strcpy(cs_date,"");

	if (argc < 2) {
		return PD_ERR;
	}

	while ((c = getopt(argc,argv,"m:f:h:")) != EOF) {
		switch (c) {
			case 'm':
				strcpy(cs_merchant_id, optarg);
				break;
			case 'f':
				strcpy(cs_filename, optarg);
				break;
			case 'h':
				change_historical = atoi(optarg);
				break;
			default:
				return PD_ERR;
		}
	}

	if (!strcmp(cs_merchant_id,"")|| !strcmp(cs_filename,""))
                return FAILURE;

	return SUCCESS;
}

int get_customer(FILE *fp_list,recordset_t *rRecordSet)
{
	int iRet = SUCCESS;
	char    cs_cust_buf[PD_TMP_MSG_BUF_LEN];
	hash_t  *hTxn;

	while (fgets(cs_cust_buf, PD_TMP_MSG_BUF_LEN, fp_list) != NULL) {
		if (cs_cust_buf[strlen(cs_cust_buf) - 1] == 0x0A)
			cs_cust_buf[strlen(cs_cust_buf) - 1] = '\0';
		strcpy(cs_cust_buf,TrimAllChar((const unsigned char*)cs_cust_buf,strlen(cs_cust_buf),PD_CHAR));

		hTxn = (hash_t*)  malloc (sizeof(hash_t));
		hash_init(hTxn,0);

		extract(cs_cust_buf,hTxn);
		PutField_CString(hTxn,"merchant_id",cs_merchant_id);
		PutField_Int(hTxn,"is_change_his",change_historical);
		//PutField_CString(hTxn,"service_code",cs_service_code);
		//PutField_CString(hTxn,"txn_country","CN");
		//PutField_CString(hTxn,"txn_ccy","CNY");
		PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
		RecordSet_Add(rRecordSet,hTxn);
	}

	return iRet;
}


void extract(char* log, hash_t *hTxn)
{
        char    *p;
        char*   csTmp;
        char    csGroup[6];
        int     i = 0;

        csTmp = (char*) malloc (strlen(log) + 1);
        strcpy(csTmp,log);
        for (i = 0; i < MAX_INFO_FIELD; i++) {
                if (i == 0)
                        p = mystrtok(csTmp, (char*)PD_MY_TOKEN);
                else
                        p = mystrtok(NULL, (char*)PD_MY_TOKEN);
             
		if(i>0){
			sprintf(csGroup,"GRP_%s",p);
			PutField_CString(hTxn,c_field_list[i],csGroup); 
		}
		else{
			PutField_CString(hTxn,c_field_list[i],p); 
		}
        }
        free(csTmp);
}

int change_group(recordset_t *rRecordSet)
{
	int iRet = SUCCESS;
	char	*csCustTag;
	char	*csFromGrp;
	char	*csToGrp;
	hash_t *hRec;

	hRec = RecordSet_GetFirst(rRecordSet);
	while (hRec) {
		if(GetField_CString(hRec,"customer_tag",&csCustTag) &&
		   GetField_CString(hRec,"from_customer_group",&csFromGrp) &&
		   GetField_CString(hRec,"to_customer_group",&csToGrp)){
DEBUGLOG(("change_group::Call BOCustomerGroup:ChangeGroup Customer[%s] [%s]->[%s]\n",csCustTag,csFromGrp,csToGrp));
			BOObjPtr = CreateObj(BOPtr,"BOCustomerGroup","ChangeGroup");
			if((unsigned long) (*BOObjPtr)(hRec)!=PD_OK){
DEBUGLOG(("change_group::ChangeGroup Failed!!!!\n"));
			}
		}

		hRec = RecordSet_GetNext(rRecordSet);
	}

	return iRet;
}
