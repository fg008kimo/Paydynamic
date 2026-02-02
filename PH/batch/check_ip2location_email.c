
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
    "check_ip2location_email.pc"
};


static unsigned int sqlctx = 353527147;


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
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/10/09              [WMC]
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
#include "internal.h"
#include "check_ip2location_email.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_email_func[PD_EML_FUNCT_LEN+1];
char cs_server[PD_TMP_BUF_LEN+1];
int i_ret_code;
char cs_file_date[PD_TMP_BUF_LEN+1];
char cs_file_time[PD_TMP_BUF_LEN+1];
char cs_file_size[PD_TMP_BUF_LEN+1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int DownloadIp2LocTpl(hash_t *hData);
int UpdateIp2LocTpl(hash_t *hData);
int MapStringRetCode(int iRetCode, char *csRetCode);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	int     iDtlRet = PD_ERR;

	hash_t  *hData = NULL;
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

DEBUGLOG(("batch_proc: Start\n"));

	iRet = parse_arg(argc,argv);
	if (iRet == SUCCESS) {
DEBUGLOG((" Email Func = [%s][%d]\n",cs_email_func,strlen(cs_email_func)));
DEBUGLOG((" Server = [%s][%d]\n",cs_server,strlen(cs_server)));
DEBUGLOG((" Ret Code = [%d]\n",i_ret_code));
DEBUGLOG((" File Date = [%s][%d]\n",cs_file_date,strlen(cs_file_date)));
DEBUGLOG((" File Time = [%s][%d]\n",cs_file_time,strlen(cs_file_time)));
DEBUGLOG((" File Size = [%s][%d]\n",cs_file_size,strlen(cs_file_size)));
	} else {
		printf("*usage: -f EMAIL_FUNC -h SERVER -r RESULT -d FILE_DATE -t FILE_TIME -s FILE_SIZE\n");
		return FAILURE;
	}

	// Create Alert Email Template
	if (iRet == SUCCESS) { 

		// Alert Email Funct
                PutField_CString(hData, "funct", cs_email_func);

		// Ret Code
		PutField_Int(hData, "ret_code", i_ret_code);

		if (!strcmp(cs_email_func, PD_EML_FUNCT_DL_IP2LOC_SUCC)) {

			// File Date
                       	PutField_CString(hData, "file_date", cs_file_date);

			// File Time
                       	PutField_CString(hData, "file_time", cs_file_time);

                     	// File Size
                      	PutField_CString(hData, "file_size", cs_file_size);

			iDtlRet = DownloadIp2LocTpl(hData);
                        if (iDtlRet != PD_OK) {
                                iRet = FAILURE;
                        }

		} else if (!strcmp(cs_email_func, PD_EML_FUNCT_DL_IP2LOC_FAIL)) {

			iDtlRet = DownloadIp2LocTpl(hData);
                	if (iDtlRet != PD_OK) {
                	        iRet = FAILURE;
                	}

		} else if (!strcmp(cs_email_func, PD_EML_FUNCT_UPD_IP2LOCATION)) {

			// Server
                	PutField_CString(hData, "server", cs_server);

			iDtlRet = UpdateIp2LocTpl(hData);
                	if (iDtlRet != PD_OK) {
                        	iRet = FAILURE;
                	}
		}
	}
	
	hash_destroy(hData);
        FREE_ME(hData);

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_email_func,"");
	strcpy(cs_server,"");
	i_ret_code = 0;
	strcpy(cs_file_date,"");
	strcpy(cs_file_time,"");
	strcpy(cs_file_size,"");

	if (argc < 10) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"f:h:r:d:t:s:")) != EOF) {
		switch (c) {
			case 'f':
                                strcpy(cs_email_func, optarg);
                                break;
			case 'h':
                                strcpy(cs_server, optarg);
                                break;
			case 'r':
				if(is_numeric(optarg)){
                                        i_ret_code = atoi(optarg);
                                }
                                break;
			case 'd':
                                strcpy(cs_file_date, optarg);
                                break;
			case 't':
                                strcpy(cs_file_time, optarg);
                                break;
			case 's':
				strcpy(cs_file_size, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if ((!strcmp(cs_email_func,"")) || (!strcmp(cs_server,"")) || (!strcmp(cs_file_date,"")) || (!strcmp(cs_file_time,"")) || (!strcmp(cs_file_size,"")))
		return FAILURE;

        return SUCCESS;
}


int DownloadIp2LocTpl(hash_t *hData)
{
	int iRet = PD_OK;

	int iDynCnt = 0;
	int iRetCode = 0;

	char *csFunct = NULL;
	char *csFileDate = NULL;
	char *csFileTime = NULL;
	char *csFileSize = NULL;
	char *csTmp = NULL;

        char csAlertDateTime[PD_TIMESTAMP_LEN + 1];
        char csStatus[PD_TMP_BUF_LEN + 1];
	char csFileDateTime[PD_TIMESTAMP_LEN + 1];
	char csRetCode[PD_TMP_BUF_LEN + 1];
        char csPtr[PD_TMP_BUF_LEN + 1];

        time_t  tNow = time(NULL);
        struct  tm tStruct = *localtime(&tNow);

        hash_t *hTemplate;
        hTemplate = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTemplate,0);
	
DEBUGLOG(("DownloadIp2LocTpl: Start\n"));

	memset(csAlertDateTime, 0, sizeof(csAlertDateTime));
        memset(csStatus, 0, sizeof(csStatus));

/* funct */
      	if (GetField_CString(hData,"funct",&csFunct)) {
DEBUGLOG((" funct = [%s]\n",csFunct));
             	PutField_CString(hTemplate, "funct", csFunct);
     	} else {
DEBUGLOG((" funct not exists\n"));
           	iRet = INT_ERR;
     	}

/* ret_code */
	if (iRet == PD_OK) {
                if (GetField_Int(hData,"ret_code",&iRetCode)) {
//DEBUGLOG((" ret_code = [%d]\n",iRetCode));
                } else {
DEBUGLOG((" ret_code not exists\n"));
                        iRet = INT_ERR;
                }
        }

/* file_date */
	if ((iRet == PD_OK) && (iRetCode == PD_RET_CODE_SUCCESS)) {
                if (GetField_CString(hData,"file_date",&csFileDate)) {
//DEBUGLOG((" file_date = [%s]\n",csFileDate));
		} else {
DEBUGLOG((" file_date not exists\n"));
                        iRet = INT_ERR;
                }
        }

/* file_time */
        if ((iRet == PD_OK) && (iRetCode == PD_RET_CODE_SUCCESS)) {
                if (GetField_CString(hData,"file_time",&csFileTime)) {
//DEBUGLOG((" file_time = [%s]\n",csFileTime));
		} else {
DEBUGLOG((" file_time not exists\n"));
                        iRet = INT_ERR;
                }
	}

/* file_size */
        if ((iRet == PD_OK) && (iRetCode == PD_RET_CODE_SUCCESS)) {
                if (GetField_CString(hData,"file_size",&csFileSize)) {
//DEBUGLOG((" file_size = [%s]\n",csFileSize));
		} else {
DEBUGLOG((" file_size not exists\n"));
                        iRet = INT_ERR;
                }
        }

	// Alert Date Time
        if (iRet == PD_OK) {
                strftime(csAlertDateTime, sizeof(csAlertDateTime), PD_ALERT_DATETIME_FORMAT, &tStruct);
DEBUGLOG((" alert_datetime = [%s]\n",csAlertDateTime));

                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stimestamp-0", "SEC", "stimestamp-0", 0);
                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", csAlertDateTime);
                //iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", write_tpl_timestamp());
        }

	// Get Desc
        if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr, "DBEmailFunct", "Get");
                if ((unsigned long)(DBObjPtr)(hTemplate) == FOUND) {
//DEBUGLOG((" DBEmailFunct:Get Found\n"));

/* desc */
                        if (GetField_CString(hTemplate,"desc",&csTmp)) {
DEBUGLOG((" desc = [%s]\n",csTmp));
                                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sdescription-0", "SEC", "sdescription-0", 0);
                                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fdescription-0", "STR", "sdescription-0", csTmp);
                        } else {
DEBUGLOG((" desc not exists\n"));
                                iRet = INT_ERR;
                        }

                } else {
DEBUGLOG((" DBEmailFunct:Get Not Found\n"));
                        iRet = INT_ERR;
                }
        }

	// Status
	if (iRet == PD_OK) {
		if (iRetCode == PD_RET_CODE_SUCCESS) {
                     	sprintf(csStatus, PD_RET_STATUS_SUCCESS);
              	} else {
                     	sprintf(csStatus, PD_RET_STATUS_FAILURE);
            	}
DEBUGLOG((" status = [%s]\n",csStatus));

		iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"STATUS","GLO","STR",csStatus);

              	iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sstatus-0", "SEC", "sstatus-0", 0);
             	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fstatus-0", "STR", "sstatus-0", csStatus);
	}

	// File Date Time
	if ((iRet == PD_OK) && (iRetCode == PD_RET_CODE_SUCCESS)) {
		sprintf(csFileDateTime, "%s %s", csFileDate, csFileTime);
DEBUGLOG((" file_datetime = [%s]\n",csFileDateTime));

                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sip_db_timestamp-0", "SEC", "sip_db_timestamp-0", 0);
                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fip_db_timestamp-0", "STR", "sip_db_timestamp-0", csFileDateTime);
        }

	// File Size
	if ((iRet == PD_OK) && (iRetCode == PD_RET_CODE_SUCCESS)) {	
DEBUGLOG((" file_size = [%s]\n",csFileSize));				

		sprintf(csPtr, "%s KB", csFileSize);
		iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sip_db_size-0", "SEC", "sip_db_size-0", 0);
                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fip_db_size-0", "STR", "sip_db_size-0", csPtr);	
	}

	// Error Message
	if ((iRet == PD_OK) && (iRetCode != PD_RET_CODE_SUCCESS)) {

		iRet = MapStringRetCode(iRetCode, csRetCode);
		if (iRet == PD_OK) {
DEBUGLOG((" error_message = [%s]\n",csRetCode));
			
			iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "serror_message-0", "SEC", "serror_message-0", 0);
                       	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ferror_message-0", "STR", "serror_message-0", csRetCode);
		}
	}

	// Process Alert Email Template
	if (iRet == PD_OK) {
    		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
    		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hTemplate));
            	if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success!!\n"));
		} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failure!!\n"));
                   	PutField_Int(hTemplate, "internal_error", iRet);
            	}	
	}

	hash_destroy(hTemplate);
      	FREE_ME(hTemplate);

DEBUGLOG(("DownloadIp2LocTpl: iRet = [%d]\n", iRet));
	return iRet;
}


int UpdateIp2LocTpl(hash_t *hData)
{
	int iRet = PD_OK;

	int iDynCnt = 0;
	int iRetCode = 0;

	char *csFunct = NULL;
	char *csServer = NULL;
	char *csTmp = NULL;

        char csAlertDateTime[PD_TIMESTAMP_LEN + 1];
        char csStatus[PD_TMP_BUF_LEN + 1];
	char csRetCode[PD_TMP_BUF_LEN + 1];	
	
        time_t  tNow = time(NULL);
        struct  tm tStruct = *localtime(&tNow);

        hash_t *hTemplate;
        hTemplate = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTemplate,0);
	
DEBUGLOG(("UpdateIp2LocTpl: Start\n"));

	memset(csAlertDateTime, 0, sizeof(csAlertDateTime));
        memset(csStatus, 0, sizeof(csStatus));

/* funct */
      	if (GetField_CString(hData,"funct",&csFunct)) {
DEBUGLOG((" funct = [%s]\n",csFunct));
             	PutField_CString(hTemplate, "funct", csFunct);
     	} else {
DEBUGLOG((" funct not exists\n"));
           	iRet = INT_ERR;
     	}

/* server */
	if (iRet == PD_OK) {
        	if (GetField_CString(hData,"server",&csServer)) {
//DEBUGLOG((" server = [%s]\n",csServer));
        	} else {
DEBUGLOG((" server not exists\n"));
        	        iRet = INT_ERR;
        	}
	}

/* ret_code */
	if (iRet == PD_OK) {
                if (GetField_Int(hData,"ret_code",&iRetCode)) {
//DEBUGLOG((" ret_code = [%s]\n",iRetCode));
                } else {
DEBUGLOG((" ret_code not exists\n"));
                        iRet = INT_ERR;
                }
        }

	// Alert Date Time
        if (iRet == PD_OK) {
                strftime(csAlertDateTime, sizeof(csAlertDateTime), PD_ALERT_DATETIME_FORMAT, &tStruct);
DEBUGLOG((" alert_datetime = [%s]\n",csAlertDateTime));

                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stimestamp-0", "SEC", "stimestamp-0", 0);
                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", csAlertDateTime);
                //iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", write_tpl_timestamp());
        }

	// Get Desc
        if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr, "DBEmailFunct", "Get");
                if ((unsigned long)(DBObjPtr)(hTemplate) == FOUND) {
//DEBUGLOG((" DBEmailFunct:Get Found\n"));

/* desc */
                        if (GetField_CString(hTemplate,"desc",&csTmp)) {
DEBUGLOG((" desc = [%s]\n",csTmp));
                                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sdescription-0", "SEC", "sdescription-0", 0);
                                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fdescription-0", "STR", "sdescription-0", csTmp);
                        } else {
DEBUGLOG((" desc not exists\n"));
                                iRet = INT_ERR;
                        }

                } else {
DEBUGLOG((" DBEmailFunct:Get Not Found\n"));
                        iRet = INT_ERR;
                }
        }

	// Server
	if (iRet == PD_OK) {
DEBUGLOG((" server = [%s]\n",csServer));

                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sserver-0", "SEC", "sserver-0", 0);
                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fserver-0", "STR", "sserver-0", csServer);
        }
	
	// Status
	if (iRet == PD_OK) {
		if (iRetCode == PD_RET_CODE_SUCCESS) {
                     	sprintf(csStatus, PD_RET_STATUS_SUCCESS);
              	} else {
                     	sprintf(csStatus, PD_RET_STATUS_FAILURE);
            	}
DEBUGLOG((" status = [%s]\n",csStatus));

          	iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"STATUS","GLO","STR",csStatus);

              	iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sstatus-0", "SEC", "sstatus-0", 0);
             	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fstatus-0", "STR", "sstatus-0", csStatus);
	}

	// Error Message
        if ((iRet == PD_OK) && (iRetCode != PD_RET_CODE_SUCCESS)) {

                iRet = MapStringRetCode(iRetCode, csRetCode);
                if (iRet == PD_OK) {
DEBUGLOG((" error_message = [%s]\n",csRetCode));

                        iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "serror_message-0", "SEC", "serror_message-0", 0);
                        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ferror_message-0", "STR", "serror_message-0", csRetCode);
                }
        }

	// Process Alert Email Template
	if (iRet == PD_OK) {
    		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
    		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hTemplate));
            	if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success!!\n"));
		} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failure!!\n"));
                   	PutField_Int(hTemplate, "internal_error", iRet);
            	}	
	}

	hash_destroy(hTemplate);
      	FREE_ME(hTemplate);

DEBUGLOG(("UpdateIp2LocTpl: iRet = [%d]\n", iRet));
	return iRet;
}

int MapStringRetCode(int iRetCode, char *csRetCode)
{
        int iRet = PD_OK;

        if (iRetCode == PD_RET_CODE_DOWNLOAD_FILE_FAILURE) {
                //sprintf(csRetCode, "Download file failure!");
                sprintf(csRetCode, "Connect to IP2Locaion Failure!");
        } else if (iRetCode == PD_RET_CODE_ZIP_FILE_NOT_FOUND) {
                //sprintf(csRetCode, "Zip file not found!");
                sprintf(csRetCode, "IP2Locaion DB file is not completely downloaded!");
	} else if (iRetCode == PD_RET_CODE_UNZIP_FILE_FAILURE) {
                //sprintf(csRetCode, "Unzip file failure!");
                sprintf(csRetCode, "IP2Locaion DB file is not completely downloaded!");
	} else if (iRetCode == PD_RET_CODE_BIN_FILE_NOT_FOUND) {
                //sprintf(csRetCode, "Bin file not found!");
                sprintf(csRetCode, "IP2Locaion DB file is not completely downloaded!");
	} else if (iRetCode == PD_RET_CODE_BIN_FILE_NOT_SYNC) {
                //sprintf(csRetCode, "Bin file not sync!");
                sprintf(csRetCode, "IP2Locaion DB file cannot not sync. to ALL CORE servers!");
        } else {
                iRet = INT_ERR;
        }

        return iRet;
}

