
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "extract_psp_data.pc"
};


static unsigned int sqlctx = 40132483;


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
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/07/30              [GOD]
Group all psp					   2013/05/13		   [MSN]
Include YPY Channel                                2013/07/03              [SWK]
Include TPM Channel                                2015/04/15              [WMC]
Include RPY Channel                                2015/04/16              [WMC]
Include YPM Channel                                2015/09/02              [WMC]
Include YSE Channel				   2016/07/05		   [MSN]
Include ECM Channel				   2016/11/29		   [WMC]
Include WCP Channel				   2017/02/03		   [WMC]
Include NTP Channel				   2017/02/03		   [WMC]
Include AWC Channel				   2017/02/21		   [MSN]
Include XJP Channel				   2017/02/23		   [WMC]
Include NTW Channel				   2017/06/06		   [WCS]
Include XJM, XJW Channel			   2017/07/24		   [WWK]
Include UNW Channel                                2017/09/11              [WMC]
Include Dinpay Channel				   2017/11/06		   [WWK]
Include COP Channel				   2017/11/16		   [WWK]
Include DPQ Channel				   2017/11/21		   [WWK]
Include XJE Channel				   2017/12/04		   [WWK]
Include RFE Channel				   2017/12/22		   [WWK]
Include SKE Channel				   2018/01/18		   [WWK]
Include SKQ Channel				   2018/01/19		   [WWK]
Include SKV Channel				   2018/01/26		   [WWK]
Include OPP Channel				   2018/02/13		   [SWK]
Include SFE Channel				   2018/02/15		   [MSN]
Include SME Channel				   2018/03/08		   [WCS]
Include RFQ Channel				   2018/03/26		   [WWK]
Include RFV Channel				   2018/04/11		   [WWK]
Include SFQ Channel				   2018/04/12		   [WMC]
Include BFV Channel				   2018/04/19		   [WMC]
Include BFQ Channel				   2018/04/26		   [MSN]
Include OUP Channel				   2018/04/26		   [WMC]
Include ZPE Channel				   2018/05/02		   [MSN]
Include COQ Channel				   2018/05/08		   [MSN]
Include NEP Channel				   2018/05/10		   [MSN]
Include ESQ Channel				   2018/05/16		   [MSN]
Include GPV Channel				   2018/05/21		   [WWK]
Include GPE Channel				   2018/05/24		   [WWK]
Include TTP Channel				   2018/05/31		   [WWK]
Include TTQ Channel				   2018/06/01		   [WWK]
Include ZPQ Channel				   2018/07/24		   [WCS]
Include WPY Channel				   2018/08/13		   [WCS]
Include XDB Channel				   2018/08/22		   [WCS]
Include SPQ Channel				   2018/09/26		   [WMC]
Include XPV Channel				   2018/09/28		   [WMC]
Include TPE Channel				   2018/10/10		   [WMC]
Include DFQ Channel				   2018/12/07		   [WMC]
Include XDQ Channel				   2018/12/31		   [WCS]
Include XJC Channel				   2019/01/22		   [WCS]
Include XJR Channel				   2019/03/22		   [WCS]
Include NEQ Channel				   2019/03/29		   [WCS]
Include UNQ Channel				   2019/07/05		   [WCS]
Include TPQ Channel				   2019/07/12		   [WCS]
Include XYE Channel				   2019/07/19		   [WCS]
Include XYQ Channel				   2019/07/22		   [WCS]
Include HDV Channel				   2019/10/16		   [WMC]
Include OUQ Channel				   2019/12/20		   [WCS]
Include APV Channel				   2020/09/24		   [WMC]
Include WPE Channel				   2020/09/28		   [WMC]
Include WPQ Channel				   2020/03/03		   [WMC]
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

#define	PD_MY_DELIMITOR	','

OBJPTR(BO);

#define	f1 1
#define	f3 0
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_psp_channel[PD_PSP_CHANNEL_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
static char cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_txn(const unsigned char* csPspId,
		const unsigned char* csPspChannel,
		const unsigned char* csTxnDate,
                FILE *fp);
int print_TWV_file(FILE *fp,hash_t* hTxn);
int print_ALP_file(FILE *fp,hash_t* hTxn);
int print_HPY_file(FILE *fp,hash_t* hTxn);
int print_ESKY_file(FILE *fp,hash_t* hTxn);
int print_FEP_file(FILE *fp,hash_t* hTxn);
int print_PFT_file(FILE *fp,hash_t* hTxn);
int print_UNI_file(FILE *fp,hash_t* hTxn);
int print_RPY_file(FILE *fp,hash_t* hTxn);
int print_YPM_file(FILE *fp,hash_t* hTxn);
int print_ECM_file(FILE *fp,hash_t* hTxn);
int print_SPQ_file(FILE *fp,hash_t* hTxn);

int batch_init(int argc, char* argv[])
{

    if (argc < 5) {
        printf("usage:  -o ouputfile -d Date -p PSP ID -c PSP Channel\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
        FILE    *fp;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage:  -o ouputfile -d Date -p PSP ID -c PSP Channel\n");
                return (iRet);
        }

        sprintf(cs_outfile_name, "%s/%s_%s.dat", getenv("REPORT_DATA"),cs_outputfile,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }
        
        iRet = process_txn((unsigned char*)cs_psp_id,(unsigned char*)cs_psp_channel,(unsigned char*)cs_date,fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(const unsigned char* csPspId,
		const unsigned char* csPspChannel,
		const unsigned char* csTxnDate,
                FILE *fp)
{               
 
        int     iRet = SUCCESS;
	hash_t  *hRec;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        BOObjPtr = CreateObj(BOPtr,"BOReport","GetPspDepositTxn");
        if((unsigned long)(*BOObjPtr)(csPspId,csTxnDate,rRecordSet)==PD_OK){
                hRec = RecordSet_GetFirst(rRecordSet);
                while(hRec){        

			if(!strcmp((const char*)csPspChannel,PD_CHANNEL_TWV)){
				print_TWV_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_ALLINPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_AIPWECHAT)){
				print_ALP_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_HPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_GOPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_HPAY_CNP) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_HAIPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_LKPAY) ||
                                !strcmp((const char*)csPspChannel,PD_CHANNEL_YEEPAY)
				){
				print_HPY_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_ESKY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_EPLUTUS) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_BAOFOO) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_NOW2PAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_WECHATPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJP) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_N2P_AIPWECHAT) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_MOBILE) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_CHWECHAT) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_DINPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_CLOUD123PAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_DINPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJE) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_RFPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_STAR_KKPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_STAR_KKPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_STAR_KKPAY_VNET) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_OPENEPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_SHANFU_EC) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_SHANFU_QR) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_RFPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_RFPAY_VNET) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_BFBAO_VNET) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_BFBAO_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ZPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ZPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_C123PAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_NOW3PAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ESKY_QR) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_GOLDENPAY_VNET) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_GOLDENPAY_EC) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TTPAY) || 
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TTPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_WELLPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_DBAO) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TRUSTPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_DF_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_DBAO_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_CH) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XJ_CH_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_NOW3PAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TRUSTPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ZXPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ZXPAY_QR) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_HANDPAY_VNET) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_ALIPAY_VNET) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_WPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_WPAY_QR)
				){
				print_ESKY_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_51EPAY)){
				print_FEP_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_PFTTOM) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_HNAPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TENPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_TENMOBPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_YSEPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_HEEPAY)
				){
				print_PFT_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_UNIPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_UNIPAY_WECHAT) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_UNIPAY_QR)
				){
				print_UNI_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_REAPAY) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_SAMOPAY_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_OUP_EC) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_XPAY_VNET) ||
				!strcmp((const char*)csPspChannel,PD_CHANNEL_OUP_QR)
				){
				print_RPY_file(fp,hRec);
			}
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_YEEPAYMOBILE)){
                                print_YPM_file(fp,hRec);
                        }
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_ECPSSMOBILE)){
                                print_ECM_file(fp,hRec);
                        }
			else if(!strcmp((const char*)csPspChannel,PD_CHANNEL_SWIFTPAY_QR)){
                                print_SPQ_file(fp,hRec);
                        }

			hRec = RecordSet_GetNext(rRecordSet);
		}

 	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        return iRet;
}


int	print_TWV_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	long	lTmp=0l;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);
/* Field #1 txn_date */
	fprintf(fp,"%s%c",cs_date,PD_MY_DELIMITOR);

/* Field #2 status */
	fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 payment mode */
	fprintf(fp,"WebATM%c",PD_MY_DELIMITOR);

/* Field #5 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%ld",&lTmp);
	fprintf(fp,"%ld%c",lTmp,PD_MY_DELIMITOR);

/* Field #6 fundin_date */
	if (GetField_CString(hTxn,"fundin_date",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 service_fee */
	if (GetField_Double(hTxn,"service_fee",&dTmp))
		fprintf(fp,"%ld",(long)dTmp);

	fprintf(fp,"\n");

	return	iRet;
}


int	print_ALP_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #3 service_fee */
	if (GetField_Double(hTxn,"service_fee",&dTmp))
		fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 txn_date */
	fprintf(fp,"%s",cs_date);

	fprintf(fp,"\n");

	return	iRet;
}


int	print_HPY_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 bank bill no*/
	if (GetField_CString(hTxn,"bank_bill_no",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #4 service_fee */
	if (GetField_Double(hTxn,"service_fee",&dTmp))
		fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 status */
	fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #6 fundin date*/
	if (GetField_CString(hTxn,"fundin_date",&csTmp)){
		if(strlen(csTmp)==PD_DATETIME_LEN)
			fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
		else if(strlen(csTmp)==PD_DATE_LEN)
			fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
		else
			fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
	}

	fprintf(fp,"\n");

	return	iRet;
}


int	print_ESKY_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #3 service_fee */
	if (GetField_Double(hTxn,"service_fee",&dTmp))
		fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 status */
	fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #5 fundin date*/
	if (GetField_CString(hTxn,"fundin_date",&csTmp)){
		if(strlen(csTmp)==PD_DATETIME_LEN)
			fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
		else if(strlen(csTmp)==PD_DATE_LEN)
			fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
		else
			fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
	}

	fprintf(fp,"\n");

	return	iRet;
}


int	print_FEP_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 bank bill no*/
	if (GetField_CString(hTxn,"bank_bill_no",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #4 service_fee */
	if (GetField_Double(hTxn,"service_fee",&dTmp))
		fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 status */
	fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #6 fundin date*/
	if (GetField_CString(hTxn,"fundin_date",&csTmp)){
		if(strlen(csTmp)==PD_DATETIME_LEN)
			fprintf(fp,"%.*s00%c",(int)strlen(csTmp)-2,csTmp,PD_MY_DELIMITOR);
		else if(strlen(csTmp)==PD_DATE_LEN)
			fprintf(fp,"%.*s000000%c",(int)strlen(csTmp),csTmp,PD_MY_DELIMITOR);
		else
			fprintf(fp,"%.*s%c",(int)strlen(csTmp),csTmp,PD_MY_DELIMITOR);
	}

/* Field #7 customer tel*/
	if (GetField_CString(hTxn,"customer_tel",&csTmp))
		fprintf(fp,"%s",csTmp);

	fprintf(fp,"\n");

	return	iRet;
}



int	print_PFT_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
	if (GetField_CString(hTxn,"tid",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);


/* Field #3 fundin date*/
	if (GetField_CString(hTxn,"fundin_date",&csTmp)){
		if(strlen(csTmp)==PD_DATETIME_LEN)
			fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
		else if(strlen(csTmp)==PD_DATE_LEN)
			fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
		else
			fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
	}

	fprintf(fp,"\n");

	return	iRet;
}


int	print_UNI_file(FILE *fp,
		       hash_t* hTxn)
{
	int	iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;

/* Field #0 txn_seq */
	if (GetField_CString(hTxn,"txn_id",&csTmp))
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
	else
		fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
	if (GetField_CString(hTxn,"amount",&csTmp))
		sscanf(csTmp,"%lf",&dTmp);
	fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);


/* Field #3 txn_date */
	fprintf(fp,"%s",cs_date);

	fprintf(fp,"\n");

	return	iRet;
}


int     print_RPY_file(FILE *fp,
                       hash_t* hTxn)
{
        int     iRet = SUCCESS;
        double  dTmp=0.0;
        char    *csTmp;

/* Field #0 txn_seq */
        if (GetField_CString(hTxn,"txn_id",&csTmp))
                fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
        if (GetField_CString(hTxn,"tid",&csTmp))
                fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
        if (GetField_CString(hTxn,"amount",&csTmp))
                sscanf(csTmp,"%lf",&dTmp);
        fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #3 status */
        fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #4 fundin date*/
        if (GetField_CString(hTxn,"fundin_date",&csTmp)){
                if(strlen(csTmp)==PD_DATETIME_LEN)
                        fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
                else if(strlen(csTmp)==PD_DATE_LEN)
                        fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
                else
                        fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
        }

        fprintf(fp,"\n");

        return  iRet;
}


int     print_YPM_file(FILE *fp,
                       hash_t* hTxn)
{
        int     iRet = SUCCESS;
        double  dTmp=0.0;
        char    *csTmp;

/* Field #0 txn_seq */
        if (GetField_CString(hTxn,"txn_id",&csTmp))
                fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 txn_amount */
        if (GetField_CString(hTxn,"amount",&csTmp))
                sscanf(csTmp,"%lf",&dTmp);
        fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #3 fundin_date */
        if (GetField_CString(hTxn,"fundin_date",&csTmp)){
                if(strlen(csTmp)==PD_DATETIME_LEN)
                        fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
                else if(strlen(csTmp)==PD_DATE_LEN)
                        fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
                else
                        fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
        }

        fprintf(fp,"\n");

        return  iRet;
}

int     print_ECM_file(FILE *fp,
                       hash_t* hTxn)
{
        int     iRet = SUCCESS;
        double  dTmp=0.0;
        char    *csTmp;

/* Field #0 txn_seq */
        if (GetField_CString(hTxn,"txn_id",&csTmp))
                fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 txn_amount */
        if (GetField_CString(hTxn,"amount",&csTmp))
                sscanf(csTmp,"%lf",&dTmp);
        fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #2 service_fee */
        if (GetField_Double(hTxn,"service_fee",&dTmp))
                fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 fundin date*/
        if (GetField_CString(hTxn,"fundin_date",&csTmp)){
                if(strlen(csTmp)==PD_DATETIME_LEN)
                        fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
                else if(strlen(csTmp)==PD_DATE_LEN)
                        fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
                else
                        fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
        }

        fprintf(fp,"\n");

        return  iRet;
}

int     print_SPQ_file(FILE *fp,
                       hash_t* hTxn)
{
        int     iRet = SUCCESS;
        double  dTmp=0.0;
        char    *csTmp;

/* Field #0 txn_seq */
        if (GetField_CString(hTxn,"txn_id",&csTmp))
                fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
        else
                fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 txn_amount */
        if (GetField_CString(hTxn,"amount",&csTmp))
                sscanf(csTmp,"%lf",&dTmp);
        fprintf(fp,"%.2f%c",dTmp,PD_MY_DELIMITOR);

/* Field #2 status */
        fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #3 fundin_date */
        if (GetField_CString(hTxn,"fundin_date",&csTmp)){
                if(strlen(csTmp)==PD_DATETIME_LEN)
                        fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
                else if(strlen(csTmp)==PD_DATE_LEN)
                        fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
                else
                        fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
        }

        fprintf(fp,"\n");

        return  iRet;
}

int parse_arg(int argc,char **argv)
{
	char    c;
	strcpy(cs_outputfile,"");
	strcpy(cs_psp_id,"");
	strcpy(cs_psp_channel,"");
	strcpy(cs_date,"");

	while ((c = getopt(argc,argv,"o:p:d:c:")) != EOF) {
		switch (c) {
			case 'o':
				strcpy(cs_outputfile, optarg);
				break;
			case 'p':
				strcpy(cs_psp_id, optarg);
				break;
			case 'c':
				strcpy(cs_psp_channel, optarg);
				break;
			case 'd':
				strcpy(cs_date, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_outputfile,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_psp_channel,"")|| !strcmp(cs_date,""))
		return FAILURE;

	return SUCCESS;
}
