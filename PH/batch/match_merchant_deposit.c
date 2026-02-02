
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
           char  filnam[26];
};
static struct sqlcxp sqlfpn =
{
    25,
    "match_merchant_deposit.pc"
};


static unsigned int sqlctx = 1800554517;


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
Init Version                                       2010/10/25              Cody Chan
generate table by html                             2010/11/12              LokMan Chow
Add output pending file                            2010/11/16              LokMan Chow
hendle mismatch STATUS				   2011/01/26		   LokMan Chow
add to mismatch table				   2012/03/21		   LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"
#include "internal.h"
#include "match_merchant_deposit.h"
#include "ObjPtr.h"
#include "myrecordset.h"

/*******************************************
        usage: -h host file -m merchant host -p pending file
******************************************/

#define  MAX_FIELD_LEN		50 
#define  MAX_FIELD_NO          	6
#define PD_TR           "<tr>"
#define PD_TD           "<td>"
#define PD_TD_STYLE     "<td class=\"format\">"
#define PD_TR_END       "</tr>"
#define PD_TD_END       "</td>"

OBJPTR(DB);
char cDebug = 'Y';

char    cs_ph_file[PD_MAX_FILE_LEN + 1];
char    cs_merch_file[PD_MAX_FILE_LEN + 1];
char    cs_pending_file[PD_MAX_FILE_LEN + 1];
//char    cs_merchant_id[PD_MERCHANT_ID_LEN + 1];

char   	csPhList[MAX_FIELD_NO][MAX_FIELD_LEN+1];
char    csMerchList[MAX_FIELD_NO][MAX_FIELD_LEN+1];

static int parse_arg(int argc,char **argv);
void extract(char* log, char data[][MAX_FIELD_LEN+1]);
void output(char csPhList[][MAX_FIELD_LEN + 1], char csMerchList[][MAX_FIELD_LEN + 1],char* remark);
void output_pending(FILE *fp,char csPhList[][MAX_FIELD_LEN + 1], char csMerchList[][MAX_FIELD_LEN + 1],char* remark);
void match(char* cs_ph_buf, char* cs_merch_buf);
int record(char csList[][MAX_FIELD_LEN + 1],char* remark);
void add_to_stat(const char* csTxnId);


int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
        printf("usage:  -h host_file -m merchant_file -p pending_file\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	FILE	*fp_ph,*fp_psp,*fp_pend;
	int     i_read_next = PD_TRUE;
	char    cs_h_key[256], cs_m_key[256];
	char    cs_ph_buf[PD_MAX_BUFFER + 1];
        char    cs_merch_buf[PD_MAX_BUFFER + 1];
        int 	i_ret;
	int	iRet;
	
	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("parse arg error\n");
                return (iRet);
        }
	fp_ph = fopen(cs_ph_file, "r");
    	if (fp_ph == NULL){
		printf("unable to open lms file %s\n",cs_ph_file);
		return FAILURE;
    	}

    	fp_psp = fopen(cs_merch_file, "r");
    	if (fp_psp == NULL){
		printf("unable to open cul file %s\n",cs_merch_file);
		return FAILURE;
    	}

	fp_pend = fopen(cs_pending_file, "w");
	if(fp_pend == NULL){
		printf("unable to open pending file %s\n",cs_pending_file);
		return FAILURE;
	}
	
	fprintf(fp_pend,"<html><body><table>\n");
	printf("<html><body><table>\n");

	fprintf(fp_pend,"%s%sMerchant Ref%s%sTxn Date%s%sStatus%s%sTxn Amount%s%sPH Txn ID%s%sResult%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	printf("%s%sMerchant Ref%s%sTxn Date%s%sStatus%s%sTxn Amount%s%sPH Txn ID%s%sResult%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);

	fprintf(fp_pend,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");
	printf("<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");

	while (fgets(cs_merch_buf, PD_MAX_BUF, fp_psp) != NULL) {
		if (cs_merch_buf[strlen(cs_merch_buf) - 1] == 0x0A)
                	cs_merch_buf[strlen(cs_merch_buf) - 1] = '\0';
        	if (i_read_next == PD_FALSE || fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) != NULL) {
			if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                		cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';
			
                	while (PD_TRUE) {
				if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                                cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';

                     		extract(cs_ph_buf,csPhList); 
                        	extract(cs_merch_buf, csMerchList);
				memcpy(cs_h_key, csPhList[IDX_MERCH_REF],PD_MERCHANT_REF_LEN);
				memcpy(cs_m_key, csMerchList[IDX_MERCH_REF],PD_MERCHANT_REF_LEN);
				//memcpy(&cs_h_key[PD_MERCHANT_REF_LEN], csPhList[IDX_TXN_DATE],TXN_DATE_LEN);
				//memcpy(&cs_m_key[PD_MERCHANT_REF_LEN], csMerchList[IDX_TXN_DATE],TXN_DATE_LEN);
				
				i_ret = memcmp(cs_h_key, cs_m_key, PD_MERCHANT_REF_LEN);

                       		if (i_ret == 0) {
          				match(cs_ph_buf, cs_merch_buf); 
                      			i_read_next = PD_TRUE;
                                	break;
               			}
                        	else if (i_ret < 0) {
                       			extract(cs_ph_buf,csPhList);
					if(strcmp(csMerchList[IDX_STATUS],"PENDING")){
						if(record(csPhList,"MERCHANT")!=PD_TRUE){
              						output(csPhList,NULL,(char*)"NO Merchant Tx");
						}
					}
					else{
						output_pending(fp_pend,csPhList,NULL,(char*)"NO Merchant Tx");
					}
                    			if (fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) == NULL) {
						if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                					cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';
                              			extract(cs_merch_buf, csMerchList);
						if(strcmp(csMerchList[IDX_STATUS],"PENDING")){
							if(record(csMerchList,"PH")!=PD_TRUE){
                           					output(NULL, csMerchList,(char*)"No Ph Tx");
							}
						}
						else{
							output_pending(fp_pend,NULL,csMerchList,(char*)"No Ph Tx");
						}
                                        	break;
                                	}
                                	i_read_next = PD_TRUE;
                   		}
                        	else if (i_ret > 0) {
                   			extract(cs_merch_buf, csMerchList);
					if(strcmp(csMerchList[IDX_STATUS],"PENDING")){
						if(record(csMerchList,"PH")!=PD_TRUE)
                    					output(NULL,csMerchList,(char*)"No Ph Tx");
					}
					else{
						output_pending(fp_pend,NULL,csMerchList,(char*)"No Ph Tx"); 
					}
                                	i_read_next = PD_FALSE;
                                	break;
                      		}
			}
    		}
		else if(i_read_next == PD_TRUE && fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) == NULL){
			extract(cs_merch_buf, csMerchList);
			if(strcmp(csMerchList[IDX_STATUS],"PENDING")){
				if(record(csMerchList,"PH")!=PD_TRUE)
					output(NULL,csMerchList,(char*)"No Ph Tx");
			}
			else{
				output_pending(fp_pend,NULL,csMerchList,(char*)"No Ph Tx");
			}
			i_read_next = PD_TRUE;
		}
	}

	if(i_read_next == PD_FALSE){
		if(strcmp(csPhList[IDX_STATUS],"PENDING")){
			if(record(csPhList,"MERCHANT")!=PD_TRUE)
                        	output(csPhList,NULL,(char*)"NO Merchant Tx");
		}
                else{
                        output_pending(fp_pend,csPhList,NULL,(char*)"NO Merchant Tx");
		}
	}

	while(fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) != NULL){
		if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
			cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';

		extract(cs_ph_buf,csPhList);
		if(strcmp(csPhList[IDX_STATUS],"PENDING")){
			if(record(csPhList,"MERCHANT")!=PD_TRUE)
				output(csPhList,NULL,(char*)"NO Merchant Tx");
		}
		else{
			output_pending(fp_pend,csPhList,NULL,(char*)"NO Merchant Tx");
		}
	}

	printf("</table></body></html>\n");
	fprintf(fp_pend,"</table></body></html>\n");

    	fclose(fp_psp);
    	fclose(fp_ph);
    	fclose(fp_pend);
	return SUCCESS;
}



static int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_ph_file,"");
        strcpy(cs_merch_file,"");
        strcpy(cs_pending_file,"");
        //strcpy(cs_merchant_id,"");

        //while ((c = getopt(argc,argv,"h:m:")) != EOF && c != 0xff) {
        while ((c = getopt(argc,argv,"h:m:p:")) != EOF) {
                switch (c) {
                        case 'h':
                                strcpy(cs_ph_file, optarg);
                                break;
                        case 'm':
                                strcpy(cs_merch_file, optarg);
                                break;
                        case 'p':
                                strcpy(cs_pending_file, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_ph_file,"") || !strcmp(cs_merch_file,"") || !strcmp(cs_pending_file,"")) 
                return FAILURE;

        return SUCCESS;
}

void extract(char* log, char data[][MAX_FIELD_LEN+1])
{       
        char    *p; 
	char*	csTmp;
        int 	i = 0;

	csTmp = (char*) malloc (strlen(log) + 1);
	strcpy(csTmp,log);
	for (i = 0; i < MAX_FIELD_NO; i++) {
                if (i == 0)
                        p = mystrtok(csTmp, (char*)PD_MATCH_TOKEN);
                else
                        p = mystrtok(NULL, (char*)PD_MATCH_TOKEN);
                strcpy(data[i], p);
        }
	free(csTmp);
}     

void output(char csPhList[][MAX_FIELD_LEN + 1], char csMerchList[][MAX_FIELD_LEN + 1],char* remark)
{
	int	i;
	//double	dTmp;

	printf("%s",PD_TR);

	if (csMerchList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_MERCH_REF) || (i==IDX_TXN_ID) || (i==IDX_MERCHANT_ID)) 
				printf("%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
			else
				printf("%s%s%s",PD_TD,csPhList[i],PD_TD_END);
		}

		printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else if (csPhList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_MERCH_REF) || (i==IDX_TXN_ID)|| (i==IDX_MERCHANT_ID)) 
				printf("%s%s%s",PD_TD_STYLE,csMerchList[i],PD_TD_END);
			else
				printf("%s%s%s",PD_TD,csMerchList[i],PD_TD_END);
		}
		printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if (strcmp(csMerchList[i],csPhList[i])){
				if (i == IDX_MERCH_REF)
                                	printf("%s*%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else if((i==IDX_TXN_ID) || (i==IDX_TXN_DATE))
					printf("%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else
					printf("%s*%s%s",PD_TD,csPhList[i],PD_TD_END);
				}
			else{
				if(i == IDX_MERCH_REF)
					printf("%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else
                               		printf("%s%s%s",PD_TD,csPhList[i],PD_TD_END);
			}
                }
                printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}

	printf("%s\n",PD_TR_END);
}

void match(char* cs_ph_buf, char* cs_merch_buf)
{
        int i, i_match = PD_TRUE;
	//char *csTmp;

        extract(cs_ph_buf, csPhList);
        extract(cs_merch_buf, csMerchList);

        for (i = 0; i < MAX_FIELD_NO; i++) {
		if((i!=IDX_TXN_ID) && (i!=IDX_TXN_DATE)){

			//if(i==IDX_TXN_AMOUNT){
			//	strcpy(csTmp,TrimAllChar(csMerchList[i],strlen(csMerchList[i]),PD_RPT_DELIMITOR));
			//	if (strcmp(csPhList[i], csTmp) != 0) {
			//		i_match = PD_FALSE;
			//	}
			//}
			//else{
        		
			if (strcmp(csPhList[i], csMerchList[i]) != 0) {
				if(i==IDX_STATUS){
					if((strcmp(csPhList[i],"REJECTED")==0) && (strcmp(csMerchList[i],"PENDING")==0)){
						i_match = PD_TRUE;
					}
					else
						i_match = PD_FALSE;
				}
				else
					i_match = PD_FALSE;
			}
			
			//}
		}
        }
        if (i_match == PD_FALSE) {
                output(csPhList, csMerchList, (char*)"Tx Mismatched");
        }
	else{
		if(!strcmp(csPhList[IDX_STATUS],"APPROVED")){
			add_to_stat(csPhList[IDX_TXN_ID]);
		}
	}
}

void output_pending(FILE *fp, char csPhList[][MAX_FIELD_LEN + 1], char csMerchList[][MAX_FIELD_LEN + 1],char* remark)
{
	int	i;

	fprintf(fp,"%s",PD_TR);

	if (csMerchList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_MERCH_REF) || (i==IDX_TXN_ID) || (i==IDX_MERCHANT_ID)) 
				fprintf(fp,"%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
			else
				fprintf(fp,"%s%s%s",PD_TD,csPhList[i],PD_TD_END);
		}

		fprintf(fp,"%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else if (csPhList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_MERCH_REF) || (i==IDX_TXN_ID)|| (i==IDX_MERCHANT_ID)) 
				fprintf(fp,"%s%s%s",PD_TD_STYLE,csMerchList[i],PD_TD_END);
			else
				fprintf(fp,"%s%s%s",PD_TD,csMerchList[i],PD_TD_END);
		}
		fprintf(fp,"%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else {
/*
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if (strcmp(csMerchList[i],csPhList[i])){
				if (i == IDX_MERCH_REF)
                                	fprintf(fp,"%s*%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else if(i==IDX_TXN_ID)
					fprintf(fp,"%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else
					fprintf(fp,"%s*%s%s",PD_TD,csPhList[i],PD_TD_END);
				}
			else{
				if(i == IDX_MERCH_REF)
					fprintf(fp,"%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else
                               		fprintf(fp,"%s%s%s",PD_TD,csPhList[i],PD_TD_END);
			}
                }
                fprintf("%s%s%s\n",PD_TD,remark,PD_TD_END);
*/
	}

	fprintf(fp,"%s\n",PD_TR_END);
}


int record(char csList[][MAX_FIELD_LEN + 1],char* remark)
{
        int iRet = PD_FALSE;
        char *csAbs= strdup("");
        char *csTxnId= strdup(" ");
        char csDate[PD_DATE_LEN+1];

        sprintf(csDate,"%.*s%.*s%.*s",PD_YYYY_LEN,&csList[IDX_TXN_DATE][PD_YYYY_LEN+2],PD_MM_LEN,csList[IDX_TXN_DATE],PD_DD_LEN,&csList[IDX_TXN_DATE][PD_MM_LEN+1]);

	if(strlen(csList[IDX_TXN_ID])>0)
		strcpy(csTxnId,csList[IDX_TXN_ID]);

        DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","GetDspMismatch");
        if((unsigned long)(DBObjPtr)(csList[IDX_MERCH_REF],PD_TYPE_MERCHANT,csAbs)!=PD_FOUND){
DEBUGLOG(("record: DBDepositMismatch->GetDspMismatch[%s] Not found\n",csList[IDX_MERCH_REF]));
                DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","Add");
                if((unsigned long)(DBObjPtr)(csTxnId,
                                                PD_TYPE_MERCHANT,
                                                csList[IDX_MERCHANT_ID],
                                                csList[IDX_MERCH_REF],
                                                csDate,remark)==PD_OK){
DEBUGLOG(("record: DBDepositMismatch->Add[%s][%s] Success\n",csList[IDX_TXN_ID],csList[IDX_MERCH_REF]));
                }
                else{
DEBUGLOG(("record: DBDepositMismatch->Add[%s][%s] Failed\n",csList[IDX_TXN_ID],csList[IDX_MERCH_REF]));
                }
        }
        else{
                if(strcmp(csAbs,remark)){
DEBUGLOG(("record: DBDepositMismatch->GetDspMismatch[%s][%s] Success\n",csList[IDX_TXN_ID],csList[IDX_MERCH_REF]));
                        iRet = PD_TRUE;

                        DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","MarkDeleted");
                        if((unsigned long)(DBObjPtr)(csList[IDX_MERCH_REF],PD_TYPE_MERCHANT,remark)==PD_OK){
DEBUGLOG(("record: DBDepositMismatch->MarkDeleted[%s][%s] Success\n",csList[IDX_TXN_ID],csList[IDX_MERCH_REF]));
                        }
                        else{
DEBUGLOG(("record: DBDepositMismatch->MarkDeleted[%s][%s] Failed\n",csList[IDX_TXN_ID],csList[IDX_MERCH_REF]));
                        }
                }
        }

        FREE_ME(csAbs);
        FREE_ME(csTxnId);
        return iRet;
}

void add_to_stat(const char* csTxnId)
{
	int	iRet = PD_OK;
        char	*csDate;
        char	*csMerchantId;
        char	*csFromCcy;
        char	*csToCcy;
	double	dFromAmt = 0.0;
	double	dToAmt = 0.0;
	double	dExRate = 0.0;
	recordset_t     *rRecordSet;
	hash_t	*hRec;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("add_to_stat start\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        if((unsigned long)(DBObjPtr)(csTxnId,rRecordSet)==PD_OK){
DEBUGLOG(("GetTxnHeader txn_id[%s]\n",csTxnId));
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if(GetField_CString(hRec,"merchant_id",&csMerchantId)){
DEBUGLOG(("GetTxnHeader merchant_id = [%s]\n",csMerchantId));
			}
			if(GetField_CString(hRec,"host_posting_date",&csDate)){
DEBUGLOG(("GetTxnHeader host_posting_date = [%s]\n",csDate));
			}
			if(GetField_CString(hRec,"net_ccy",&csFromCcy)){
DEBUGLOG(("GetTxnHeader from_ccy = [%s]\n",csFromCcy));
			}
			if(GetField_Double(hRec,"txn_amt",&dFromAmt)){
DEBUGLOG(("GetTxnHeader from_amt = [%lf]\n",dFromAmt));
			}
			if(GetField_Double(hRec,"ex_rate",&dExRate)){
DEBUGLOG(("GetTxnHeader ex_rate = [%lf]\n",dExRate));
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
        }
	else{
		iRet=PD_ERR;
DEBUGLOG(("GetTxnHeader failed!!!!!!\n"));
	}

	if(iRet==PD_OK){
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		if (!(*DBObjPtr)(csTxnId,rRecordSet)) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){

				if (GetField_CString(hRec,"txn_ccy",&csToCcy)) {
DEBUGLOG(("GetTxnPspDetail to_ccy = [%s]\n",csToCcy));
				}

				if (GetField_Double(hRec,"txn_amt",&dToAmt)) {
DEBUGLOG(("GetTxnPspDetail to_amt = [%lf]\n",dToAmt));
				}

                                 hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
			iRet=PD_ERR;
DEBUGLOG(("GetTxnPspDetail failed!!!!!!\n"));
                }
	}


	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMatchDepositStat","UpdateStat");
		if ((*DBObjPtr)(csDate,
				PD_TYPE_MERCHANT,
				csMerchantId,
				csFromCcy,
				csToCcy,
				dFromAmt,
				dToAmt,
				dExRate)==PD_OK) {
DEBUGLOG(("add_to_stat Success\n"));
		}
		else{
			iRet=PD_ERR;
DEBUGLOG(("add_to_stat Failed!!!!!!\n"));
		}
	}

	if(iRet!=PD_OK)
ERRLOG("add_to_stat Failed!!!!!!!\n");

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
}
