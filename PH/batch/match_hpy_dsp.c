
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "match_hpy_dsp.pc"
};


static unsigned int sqlctx = 4874763;


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
Init Version                                       2011/03/11              LokMan Chow
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
#include "match_hpy_dsp.h"
#include "ObjPtr.h"
#include "myrecordset.h"

/*******************************************
        usage: -h host file -p psp host
******************************************/

#define  MAX_FIELD_LEN		20 
#define  MAX_FIELD_NO          	7
#define PD_TR           "<tr>"
#define PD_TD           "<td>"
#define PD_TD_STYLE     "<td class=\"format\">"
#define PD_TR_END       "</tr>"
#define PD_TD_END       "</td>"

char    cs_ph_file[PD_MAX_FILE_LEN*2];
char    cs_psp_file[PD_MAX_FILE_LEN*2];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

char   	csPhList[MAX_FIELD_NO][MAX_FIELD_LEN*2];
char    csPspList[MAX_FIELD_NO][MAX_FIELD_LEN*2];

char   	csAlertList[MAX_FIELD_LEN*2][MAX_FIELD_LEN*2];
int	iAlertCnt = 0;

char    cDebug;

OBJPTR(DB);

static int parse_arg(int argc,char **argv);
void extract(char* log, char data[][MAX_FIELD_LEN*2]);
void output(char csPhList[][MAX_FIELD_LEN*2], char csPspList[][MAX_FIELD_LEN*2],char* remark);
void match(char* cs_ph_buf, char* cs_psp_buf, const char* csMatchDate);
int record(char csList[][MAX_FIELD_LEN*2],char* remark);
void add_to_stat(char csList[][MAX_FIELD_LEN*2], const int iMatch);
void alert(char csList[][MAX_FIELD_LEN*2]);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage:  -h host_file -p psp_file -i psp_id -d date\n");
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
//int main(int argc, char* argv[])
{
	FILE	*fp_ph,*fp_psp;
	int     i_read_next = PD_TRUE;
	char    cs_h_key[256], cs_p_key[256];
	char    cs_ph_buf[PD_MAX_BUFFER * 2];
        char    cs_psp_buf[PD_MAX_BUFFER *2];
        int 	i_ret;
	int	iRet;
	
	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("usage:  -h host_file -p psp_file -i psp_id\n");
                return (iRet);
        }
	fp_ph = fopen(cs_ph_file, "r");
    	if (fp_ph == NULL){
		printf("unable to open lms file %s\n",cs_ph_file);
		return FAILURE;
    	}

    	fp_psp = fopen(cs_psp_file, "r");
    	if (fp_psp == NULL){
		printf("unable to open cul file %s\n",cs_psp_file);
		return FAILURE;
    	}
/*        if(iRet==SUCCESS){
DEBUGLOG(("reset stat Start\n"));
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","ResetStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_MERCHANT)==PD_OK) {
DEBUGLOG(("reset stat Success\n"));
                }
        }

        if(iRet==SUCCESS){
DEBUGLOG(("reset stat Start\n"));
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","ResetStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_PSP)==PD_OK) {
DEBUGLOG(("reset stat Success\n"));
                }
        }
*/
	printf("<html><body><table>\n");
	printf("%s%sPH Txn ID%s%sTID%s%sBank Bill No.%s%sTxn Amount%s%sServiceFee%s%sStatus%s%sTxn Date%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	printf("<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");

	while (fgets(cs_psp_buf, PD_MAX_BUF, fp_psp) != NULL) {
		//if(strlen(cs_psp_buf)<5){
		//	break;
		//}
		if (cs_psp_buf[strlen(cs_psp_buf) - 1] == 0x0A)
                	cs_psp_buf[strlen(cs_psp_buf) - 1] = '\0';
        	if (i_read_next == PD_FALSE || fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) != NULL) {
			if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                		cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';
			
                	while (PD_TRUE) {
                     		extract(cs_ph_buf,csPhList); 
                        	extract(cs_psp_buf, csPspList);

				memcpy(cs_h_key, csPhList[IDX_TXN_SEQ],PD_TXN_SEQ_LEN);
				memcpy(cs_p_key, csPspList[IDX_TXN_SEQ],PD_TXN_SEQ_LEN);
				
				i_ret = memcmp(cs_h_key, cs_p_key, PD_TXN_SEQ_LEN);
                       		if (i_ret == 0) {
          				match(cs_ph_buf, cs_psp_buf, cs_date); 
                      			i_read_next = PD_TRUE;
                                	break;
               			}
                        	else if (i_ret < 0) {
                       			extract(cs_ph_buf,csPhList); 
					if(record(csPhList,"PSP")!=PD_TRUE){
              					output(csPhList,NULL,(char*)"No Psp Tx");
					}
                    			if (fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) == NULL) {
						if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                					cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';

                              			extract(cs_psp_buf, csPspList);
						if(record(csPspList,"PH")!=PD_TRUE){
                           				output(NULL, csPspList,(char*)"No Ph Tx");
						}
						add_to_stat(csPspList, PD_FALSE);
                                        	break;
                                	}
					if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A)
                                		cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';
                                	i_read_next = PD_TRUE;
                   		}
                        	else if (i_ret > 0) {
                   			extract(cs_psp_buf, csPspList);
					if(record(csPspList,"PH")!=PD_TRUE){
                    				output(NULL,csPspList,(char*)"No Ph Tx"); 
					}
					add_to_stat(csPspList, PD_FALSE);
                                	i_read_next = PD_FALSE;
                                	break;
                      		}
			}
    		}
		else if(i_read_next == PD_TRUE && fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) == NULL){
                        extract(cs_psp_buf, csPspList); 
			if(record(csPspList,"PH")!=PD_TRUE){
                        	output(NULL,csPspList,(char*)"No Ph Tx");
			}
			add_to_stat(csPspList, PD_FALSE);
                        i_read_next = PD_TRUE;
                }
	}

	if(i_read_next == PD_FALSE){
		if(record(csPhList,"PSP")!=PD_TRUE){
			output(csPhList,NULL,(char*)"NO Psp Tx");
		}
        }    

	while(fgets(cs_ph_buf, PD_MAX_BUF, fp_ph) != NULL){
                if (cs_ph_buf[strlen(cs_ph_buf) - 1] == 0x0A) 
                        cs_ph_buf[strlen(cs_ph_buf) - 1] = '\0';

                extract(cs_ph_buf,csPhList);
		if(record(csPhList,"PSP")!=PD_TRUE){
                	output(csPhList,NULL,(char*)"No Psp Tx");
		}
        }

	if(iAlertCnt>0)
		alert(csAlertList);

	printf("</table></body></html>\n");
    	fclose(fp_psp);
    	fclose(fp_ph);
	return SUCCESS;
}



static int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_ph_file,"");
        strcpy(cs_psp_file,"");
	strcpy(cs_psp_id,"");
	strcpy(cs_date,"");

        //while ((c = getopt(argc,argv,"h:p:")) != EOF && c != 0xff) {
        while ((c = getopt(argc,argv,"h:p:i:d:")) != EOF) {
                switch (c) {
                        case 'h':
                                strcpy(cs_ph_file, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_file, optarg);
                                break;
                        case 'i':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_ph_file,"") || !strcmp(cs_psp_file,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_date,"")) 
                return FAILURE;

        return SUCCESS;
}

void extract(char* log, char data[][MAX_FIELD_LEN*2])
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

void output(char csPhList[][MAX_FIELD_LEN*2], char csPspList[][MAX_FIELD_LEN*2],char* remark)
{
	int	i;
	double	dTmp;

	printf("%s",PD_TR);

	if (csPspList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_TID) || (i==IDX_TXN_SEQ) || (i==IDX_BILL_NO)) 
				printf("%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
			else if (i == IDX_TXN_AMOUNT) {
				dTmp = atof(csPhList[i]);
				printf("%s%.2f%s",PD_TD,dTmp,PD_TD_END);
			}
			else
				printf("%s%s%s",PD_TD,csPhList[i],PD_TD_END);
		}
		printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else if (csPhList == NULL ) {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
			if ((i == IDX_TID) || (i==IDX_TXN_SEQ) || (i==IDX_BILL_NO)) 
				printf("%s%s%s",PD_TD_STYLE,csPspList[i],PD_TD_END);
			else if (i == IDX_TXN_AMOUNT) {
				dTmp = atof(csPspList[i]);
				printf("%s%.2f%s",PD_TD,dTmp,PD_TD_END);
			}
			else
				printf("%s%s%s",PD_TD,csPspList[i],PD_TD_END);
		}
		printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}
	else {
		for (i = 0 ; i < MAX_FIELD_NO; i++) {
                        if ((i == IDX_TID) || (i==IDX_TXN_SEQ) || (i==IDX_BILL_NO)) {
				if (strcmp(csPspList[i],csPhList[i]))
                                	printf("%s*%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
				else
                                	printf("%s%s%s",PD_TD_STYLE,csPhList[i],PD_TD_END);
	
			}
                        else {
				if (strcmp(csPspList[i],csPhList[i])) {
					if (i == IDX_TXN_AMOUNT) {
						dTmp = atof(csPhList[i]);
						printf("%s*%.2f%s",PD_TD,dTmp,PD_TD_END);
					}
					else 
                                		printf("%s*%s%s",PD_TD,csPhList[i],PD_TD_END);
				}
				else {
					if (i == IDX_TXN_AMOUNT) {
						dTmp = atof(csPhList[i]);
						printf("%s%.2f%s",PD_TD,dTmp,PD_TD_END);
					}
					else 
                               			printf("%s%s%s",PD_TD,csPhList[i],PD_TD_END);
				}
			}
                }
                printf("%s%s%s\n",PD_TD,remark,PD_TD_END);
	}

	printf("%s\n",PD_TR_END);
}
void match(char* cs_ph_buf, char* cs_psp_buf, const char* csMatchDate)
{
        int i, i_match = PD_TRUE;
	//char csDate[PD_DATE_LEN+1];
        hash_t  *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        extract(cs_ph_buf, csPhList);
        extract(cs_psp_buf, csPspList);

	//sprintf(csDate,"%.*s",PD_DATE_LEN,csPhList[IDX_TXN_DATE]);
	//csDate[PD_DATE_LEN]='\0';

        for (i = 0; i < MAX_FIELD_NO; i++) {
		if(i!=IDX_SERVICE_FEE && i!=IDX_BILL_NO && i!=IDX_TXN_DATE && i!=IDX_TID){
			if (strcmp(csPhList[i], csPspList[i]) != 0) {
				i_match = PD_FALSE;
			}
		}
        }
        if (i_match == PD_FALSE) {
                output(csPhList, csPspList, (char*)"Tx Mismatched");
		strcpy(csAlertList[iAlertCnt], csPhList[IDX_TXN_SEQ]);
		iAlertCnt++;
        }
	else{
		PutField_Int(hTxn,"match_ind",PD_TRUE);
		PutField_CString(hTxn,"match_date",csMatchDate);
		PutField_CString(hTxn,"txn_seq",csPhList[IDX_TXN_SEQ]);
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
		if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
DEBUGLOG(("match: DBTxnPspDetail:Update Failed [%s]\n",csPhList[IDX_TXN_SEQ]));
		}
		else{
			add_to_stat(csPspList, PD_TRUE);
		}
	}

        FREE_ME(hTxn);
}

int record(char csList[][MAX_FIELD_LEN*2],char* remark)
{
        int iRet = PD_FALSE;
        char *csAbs= strdup("");
        char csDate[PD_DATE_LEN+1];

        hash_t  *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        sprintf(csDate,"%.*s",PD_DATE_LEN,csList[IDX_TXN_DATE]);

        DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","GetDspMismatch");
        if((unsigned long)(DBObjPtr)(csList[IDX_TXN_SEQ],PD_TYPE_PSP,csAbs)!=PD_FOUND){
DEBUGLOG(("record: DBDepositMismatch->GetDspMismatch[%s] Not found\n",csList[IDX_TXN_SEQ]));
                DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","Add");
		if((unsigned long)(DBObjPtr)(csList[IDX_TXN_SEQ],
                                                PD_TYPE_PSP,
                                                cs_psp_id,
                                                csList[IDX_TID],
                                                cs_date,remark)==PD_OK){
DEBUGLOG(("record: DBDepositMismatch->Add[%s] Success\n",csList[IDX_TXN_SEQ]));
                }
                else{
DEBUGLOG(("record: DBDepositMismatch->Add[%s] Failed\n",csList[IDX_TXN_SEQ]));
                }
        }
        else{
                if(strcmp(csAbs,remark)){
DEBUGLOG(("record: DBDepositMismatch->GetDspMismatch[%s] Success\n",csList[IDX_TXN_SEQ]));
                        iRet = PD_TRUE;

                        DBObjPtr = CreateObj(DBPtr,"DBDepositMismatch","MarkDeleted");
                        if((unsigned long)(DBObjPtr)(csList[IDX_TXN_SEQ],PD_TYPE_PSP,cs_date)==PD_OK){
DEBUGLOG(("record: DBDepositMismatch->MarkDeleted[%s] Success\n",csList[IDX_TXN_SEQ]));
                        }
                        else{
DEBUGLOG(("record: DBDepositMismatch->MarkDeleted[%s] Failed\n",csList[IDX_TXN_SEQ]));
                        }

			PutField_Int(hTxn,"match_ind",PD_TRUE);
			PutField_CString(hTxn,"match_date",cs_date);
			PutField_CString(hTxn,"txn_seq",csList[IDX_TXN_SEQ]);
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
			if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
DEBUGLOG(("match: DBTxnPspDetail:Update Failed [%s]\n",csList[IDX_TXN_SEQ]));
			}

                }
        }

        FREE_ME(hTxn);
        FREE_ME(csAbs);
        return iRet;
}

void add_to_stat(char csList[][MAX_FIELD_LEN*2],const int iMatch)
{
        int     iRet = PD_OK;
        char    *csDate;
        char    *csApproveDate;
        char    *csMerchantId;
        char    *csPspId;
        char    *csFromCcy;
        char    *csToCcy;
        char    *csFeeCcy;
        char    csListDate[PD_DATE_LEN+1];
        char    *csMarkupCcy;
        double  dFromAmt = 0.0;
        double  dToAmt = 0.0;
        double  dExRate = 0.0;
	double	dFee=0.0;
	double	dPspFee=0.0;
	double	dMarkupFee=0.0;
	double	dTmp=0.0;
	double	dListToAmt = 0.0;
        recordset_t     *rRecordSet;
        hash_t  *hRec;

        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("add_to_stat start\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        if((unsigned long)(DBObjPtr)(csList[IDX_TXN_SEQ],rRecordSet)==PD_OK){
DEBUGLOG(("GetTxnHeader txn_id[%s]\n",csList[IDX_TXN_SEQ]));
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if(GetField_CString(hRec,"merchant_id",&csMerchantId)){
DEBUGLOG(("GetTxnHeader merchant_id = [%s]\n",csMerchantId));
                        }
			//if(GetField_CString(hRec,"host_posting_date",&csDate)){
//DEBUGLOG(("GetTxnHeader host_posting_date = [%s]\n",csDate));
//			}
			if(GetField_CString(hRec,"approval_date",&csApproveDate)){
DEBUGLOG(("GetTxnHeader approval_date = [%s]\n",csApproveDate));
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
		DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
		if ((unsigned long)(*DBObjPtr)(csList[IDX_TXN_SEQ],PD_ELEMENT_TXN_FEE,PD_TYPE_MERCHANT,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"ccy",&csFeeCcy)) {
DEBUGLOG(("GetFeeChgDetailByType ccy = [%s]\n",csFeeCcy));
				}
				if (GetField_Double(hRec,"amount",&dTmp)) {
DEBUGLOG(("GetFeeChgDetailByType fee = [%lf]\n",dTmp));
					dFee += dTmp;
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}

DEBUGLOG(("GetFeeChgDetailByType service_fee = [%lf]\n",dFee));
		}
	}

	if(iRet==PD_OK){
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
		if ((unsigned long)(*DBObjPtr)(csList[IDX_TXN_SEQ],PD_ELEMENT_MARKUP_AMT,PD_TYPE_CUSTOMER,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"ccy",&csMarkupCcy)) {
DEBUGLOG(("GetFeeChgDetailByType ccy = [%s]\n",csMarkupCcy));
				}
				if (GetField_Double(hRec,"amount",&dTmp)) {
DEBUGLOG(("GetFeeChgDetailByType fee = [%lf]\n",dTmp));
					dMarkupFee += dTmp;
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}

DEBUGLOG(("GetFeeChgDetailByType markup_fee = [%lf]\n",dMarkupFee));
		}
	}

        if(iRet==PD_OK){
		recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if (!(*DBObjPtr)(csList[IDX_TXN_SEQ],rRecordSet)) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){

                                if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("GetTxnPspDetail psp_id = [%s]\n",csPspId));
                                }
                                if (GetField_CString(hRec,"txn_date",&csDate)) {
DEBUGLOG(("GetTxnPspDetail txn_date = [%s]\n",csDate));
                                }
                                if (GetField_CString(hRec,"txn_ccy",&csToCcy)) {
DEBUGLOG(("GetTxnPspDetail to_ccy = [%s]\n",csToCcy));
                                }

                                if (GetField_Double(hRec,"txn_amt",&dToAmt)) {
DEBUGLOG(("GetTxnPspDetail to_amt = [%lf]\n",dToAmt));
                                }

                                if (GetField_Double(hRec,"service_fee",&dPspFee)) {
DEBUGLOG(("GetTxnPspDetail service_fee = [%lf]\n",dPspFee));
                                }

                                 hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
                        iRet=PD_ERR;
DEBUGLOG(("GetTxnPspDetail failed!!!!!!\n"));
                }
        }

        if((iRet==PD_OK) && (iMatch==PD_TRUE)){
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_MERCHANT,
                                csMerchantId,
				PD_TXN_AMT,
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

        if((iRet==PD_OK) && (dFee>0.0) && (iMatch==PD_TRUE)){
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_MERCHANT,
                                csMerchantId,
				PD_ACTUAL_FEE,
                                csFeeCcy,
                                "",
                                dFee,
                                0.0,
                                1.0)==PD_OK) {
DEBUGLOG(("add_to_stat Success\n"));
                }
                else{
                        iRet=PD_ERR;
DEBUGLOG(("add_to_stat Failed!!!!!!\n"));
                }
        }

        if((iRet==PD_OK) && (dMarkupFee>0.0) && (iMatch==PD_TRUE)){
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_MERCHANT,
                                csMerchantId,
				PD_MARKUP_AMT,
                                csMarkupCcy,
                                "",
                                dMarkupFee,
                                0.0,
                                1.0)==PD_OK) {
DEBUGLOG(("add_to_stat Success\n"));
                }
                else{
                        iRet=PD_ERR;
DEBUGLOG(("add_to_stat Failed!!!!!!\n"));
                }
	}

        if((iRet==PD_OK) && (iMatch==PD_FALSE)){
		sprintf(csListDate,"%.*s",PD_DATE_LEN,csList[IDX_TXN_DATE]);
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(cs_date,
                                'T',
                                csMerchantId,
				PD_TXN_AMT,
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
        if(iRet==PD_OK){
		dListToAmt = 0.0;
		sscanf(csList[IDX_TXN_AMOUNT],"%lf",&dListToAmt);
		sprintf(csListDate,"%.*s",PD_DATE_LEN,csList[IDX_TXN_DATE]);
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(cs_date,
                                PD_TYPE_PSP,
                                csPspId,
				PD_TXN_AMT,
                                csToCcy,
                                "",
                                dListToAmt,
                                0.0,
                                1.0)==PD_OK) {
DEBUGLOG(("add_to_stat Success\n"));
                }
                else{
                        iRet=PD_ERR;
DEBUGLOG(("add_to_stat Failed!!!!!!\n"));
                }
        }

/*
        if((iRet==PD_OK) && (dPspFee >0.0)){
                DBObjPtr = CreateObj(DBPtr,"DBDepositMatchStat","UpdateStat");
                if ((*DBObjPtr)(csDate,
                                PD_TYPE_PSP,
                                csPspId,
				PD_PRECAL_FEE,
                                csToCcy,
                                "",
                                dPspFee,
                                0.0,
                                1.0)==PD_OK) {
DEBUGLOG(("add_to_stat Success\n"));
                }
                else{
                        iRet=PD_ERR;
DEBUGLOG(("add_to_stat Failed!!!!!!\n"));
                }
        }
*/
        if(iRet!=PD_OK)
ERRLOG("add_to_stat Failed!!!!!!!\n");

DEBUGLOG(("add_to_stat end\n"));

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
}

void alert(char csList[][MAX_FIELD_LEN*2])
{
	int	i;
	char	csIdList[PD_TMP_MSG_BUF_LEN];

	csIdList[0]='\0';
	if (csList != NULL){
		for (i = 0; i < iAlertCnt; i++) {
			strcat(csIdList,csList[i]);
			if((i+1)<iAlertCnt)
				strcat(csIdList,",");
			else
				csIdList[strlen(csIdList)]='\0';
		}
		char *csCmd=(char*) malloc(PD_MAX_FILE_LEN  +1);
		sprintf(csCmd,"psp_file_matching_error.sh \"%s\" \"%s\"",cs_psp_file,csIdList);
		system(csCmd);
		FREE_ME(csCmd);
	}
}
