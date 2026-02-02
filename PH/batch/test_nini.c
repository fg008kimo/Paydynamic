
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "test_nini.pc"
};


static unsigned int sqlctx = 328419;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
5,0,0,1,135,0,4,417,0,0,4,2,0,1,0,2,3,0,0,2,9,0,0,1,9,0,0,1,1,0,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sqlca.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char	cDebug = 'Y';
char		csFunc[PD_TAG_LEN] = "";
char		csTxnCode[PD_TXN_CODE_LEN];
char		csServiceCode[PD_SERVICE_CODE_LEN] = "";
char		csDesc[PD_DESC_LEN+1] = "";
double		dDailyLimit = 0.0;
int		iSysSupport = -1;
int         	bUpdateDailyLimit=0;
char		csPspChannel[PD_PSP_CHANNEL_CODE_LEN];
hash_t		*argHash;


OBJPTR(DB);

static int parse_arg_test_nini(int argc, char ** argv);

static int parse_arg_psp_param_check(int argc, char ** argv);

static int parse_arg_txn_balance_log(int argc, char ** argv);

int batch_proc_test_nini(int argc, char * argv[]);

int batch_proc_psp_param_check(int argc, char * argv[]);

int batch_proc_txn_balance_log(int argc, char * argv[]);

void printDetailOfTestNini(hash_t*  myHash);

void printDetailOfPspParamCheck(hash_t*  myHash);

int checkFunction (const char *func);

static int parse_arg(int argc, char ** argv)
{
	return parse_arg_txn_balance_log(argc,argv);
}

int batch_init(int argc, char * argv[])
{
       	argHash = (hash_t *)malloc(sizeof(hash_t));
        hash_init(argHash, 0);
        
	return SUCCESS;
}

int batch_proc(int argc, char * argv[])
{
	if (parse_arg(argc, argv) != PD_OK)
	{
		exit(1);
	}

printf("batch_proc end\n");
	return batch_proc_txn_balance_log(argc,argv);
}


void printDetailOfTestNini(hash_t*  myHash){
        char	* csTmp = NULL;
        double	dTmp = 0.0;
        int	iTmp = 0;
        
printf("================================\n");
        printf("TxnCode [%s]\n", csTxnCode);
	if (GetField_CString(myHash, "service_code", &csTmp))
printf("ServiceCode = [%s]\n", csTmp);
	else{
        	printf("ServiceCode [%s]\n", csServiceCode);
	}
	if (GetField_CString(myHash, "desc", &csTmp))
printf("Desc = [%s]\n", csTmp);

	if (GetField_Int(myHash, "sys_support", &iTmp))
printf("SysSupport = [%d]\n", iTmp);

	if (GetField_Double(myHash, "daily_limit", &dTmp))
printf("DailyLimit = [%lf]\n", dTmp);

}
	
int  getDetailOfTestNini(){

        int iRet = PD_OK;
        hash_t  * myHash;
        myHash = (hash_t *)malloc(sizeof(hash_t));
        hash_init(myHash, 0);
        
	DBObjPtr = CreateObj(DBPtr, "DBTestNini", "GetDetail");
        iRet =(unsigned long)(DBObjPtr)(csTxnCode,csServiceCode,myHash);
	
	printDetailOfTestNini(myHash);
	return iRet;

}

static int parse_arg_test_nini(int argc, char ** argv)
{

printf("Usage: %s -t <TxnCode> -s <ServiceCode> -d <Desc> -l <DailyLimit> -p <SysSupport> -f <FUNCTION>\n", argv[0]);
	char c;

	while ((c = getopt(argc, argv, "t:s:d:l:p:f:")) != EOF)
	{
		switch (c)
		{
			case 't':
				strcpy(csTxnCode, optarg);
				break;

			case 's':
				strcpy(csServiceCode, optarg);
				break;

			case 'd':
				strcpy(csDesc, optarg);
				break;

			case 'l':
				sscanf(optarg, "%lf", &dDailyLimit);
				bUpdateDailyLimit=1;
				break;
			case 'p':
				iSysSupport = atoi(optarg);
				break;
			case 'f':
				strcpy(csFunc, optarg);
				break;

			default:
				return PD_ERR;
		}
	}
    if(!strcmp(csFunc, "")){
printf("Fail in parsing arguments\n");
		return PD_ERR;
    }
    if(!strcmp(csFunc, "Add")){
        if ( !strcmp(csTxnCode, "")  || !strcmp(csServiceCode, "")  || !strcmp(csDesc, "") || (dDailyLimit < 0.0)|| (iSysSupport < 0) || !strcmp(csFunc, "")){
    printf("Fail in parsing arguments\n");
            return PD_ERR;
        }
    }
    if(!strcmp(csFunc, "GetDetail")|| !strcmp(csFunc, "Update")){
            if ( (!strcmp(csTxnCode, "") || !strcmp(csServiceCode, "") )){
printf("Fail in parsing arguments\n");
                return PD_ERR;
            }
    }
    if(!strcmp(csFunc, "GetDetailByTxnCode")){
            if ( !strcmp(csTxnCode, "") ){
printf("Fail in parsing arguments\n");
                return PD_ERR;
            }
    }
printf("TxnCode: %s , ServiceCode: %s, Desc: %s, DailyLimit: %lf , SysSupport: %d, FUNCTION: %s\n", csTxnCode, csServiceCode, csDesc, dDailyLimit,iSysSupport, csFunc);
	return PD_OK;
}


void printDetailOfPspParamCheck(hash_t*  myHash){
        int	iTmp = 1;
        
printf("================================\n");

	if (GetField_Int(myHash, "verify_sign", &iTmp))
printf("VerifySign = [%d]\n", iTmp);

	if (GetField_Int(myHash, "amt_in_dec", &iTmp))
printf("AmtInDecimal = [%d]\n", iTmp);

	if (GetField_Int(myHash, "txn_date_present", &iTmp))
printf("TxnDatePresent = [%d]\n", iTmp);


}
	
int  getDetailOfPspParamCheck(){

        int iRet = PD_OK;
        hash_t  * myHash;
        myHash = (hash_t *)malloc(sizeof(hash_t));
        hash_init(myHash, 0);
        
	DBObjPtr = CreateObj(DBPtr, "DBPspParamCheck", "GetDetail");
        iRet =(unsigned long)(DBObjPtr)(csPspChannel,myHash);
	
	if(iRet == PD_FOUND){
		printDetailOfPspParamCheck(myHash);
	}

	FREE_ME(myHash);
	
	return iRet;

}

static int parse_arg_txn_balance_log(int argc, char ** argv)
{

printf("Usage: %s -d <TxnAprvDate> -p <PARTY_TYPE> -c <IS_COMPLETED> -u <UPDATE_USER>-f <FUNCTION>\n", argv[0]);
	char 	c;
	char	csTxnDate[PD_TXN_DATE_LEN] = "";
	char	cPartyType;
	int  	iTmp;
	char 	csUser[PD_UPDATE_USER_LEN]="";
	int 	iRet = PD_OK;	
	
	memset(csTxnDate, '\0', sizeof(csTxnDate)); 
	memset(csUser, '\0', sizeof(csUser)); 
	
	while ((c = getopt(argc, argv, "d:p:c:u:f:")) != EOF)
        {       
                switch (c)
                {
                        
                        case 'd':
				strcpy(csTxnDate, optarg);
                                PutField_CString(argHash,"txn_aprv_date",csTxnDate);
                                break;
                        case 'p':
				cPartyType =optarg[0];
                                PutField_Char(argHash,"party_type",cPartyType);
                                break;
                        case 'c':
				iTmp = atoi(optarg);
                                PutField_Int(argHash,"is_completed",iTmp);
                                break;
                        case 'u':
				strcpy(csUser, optarg);
                                PutField_CString(argHash,"update_user",csUser);
                                break;
                        
                        case 'f':
                                strcpy(csFunc, optarg);
                                break;
                        
                        default:
                                return PD_ERR;
                }
        }

	if(checkFunction("UpdateBalLog") == PD_ERR && checkFunction("IsCompleted")){
		return PD_ERR;
	}

	if(!strcmp("UpdateBalLog",csFunc)){
	
		if(!GetField_Int(argHash,"is_completed",&iTmp)){
			iRet = PD_ERR;
		}
printf("is_completed [%i]\n",iTmp);

		if( !strcmp(csUser,"")){
			iRet = PD_ERR;
		}

	}
	if( !strcmp(csTxnDate,"")){
		iRet = PD_ERR;
	}
printf("txn_aprv_date :[%s] \n",csTxnDate);

	if(! GetField_Char(argHash,"party_type",&cPartyType)){
		iRet = PD_ERR;
	}
printf("party_type [%c]\n",cPartyType);



	if(iRet != PD_OK){
printf("Fail in parsing arguments\n");
	}



	return iRet;

}
static int parse_arg_psp_param_check(int argc, char ** argv)
{

printf("Usage: %s -c <PspChannel> -f <FUNCTION>\n", argv[0]);
	char c;

	while ((c = getopt(argc, argv, "c:f:")) != EOF)
	{
		switch (c)
		{
			case 'c':
				strcpy(csPspChannel, optarg);
				break;

			case 'f':
				strcpy(csFunc, optarg);
				break;

			default:
				return PD_ERR;
		}
	}
	if(!strcmp(csFunc, "")){
printf("Fail in parsing arguments\n");
		return PD_ERR;
	}
	if(!strcmp(csFunc, "GetDetail")){
        	if ( !strcmp(csPspChannel, "")){
printf("Fail in parsing arguments\n");
        		return PD_ERR;
        	}
	}else{

printf("Invalid Function!!\n");
	return PD_ERR;
	}

printf("PspChannel: %s , FUNCTION: %s\n", csPspChannel, csFunc);

	return PD_OK;
}

int checkFunction(const char *funcName){
	if(!strcmp(csFunc, "")){
printf("!! Missing Function !!\n");
		return PD_ERR;
	}
	if(!strcmp(csFunc, funcName)){
printf("FUNCTION: %s\n", csFunc);
		return PD_OK;
	}else{
printf("Invalid Function!!\n");
		return PD_ERR;
	}

}


int batch_proc_txn_balance_log(int argc, char * argv[]){

	int iRet = PD_OK;
	char 	*csTxnDate = NULL;
	char	cPartyType;
	
	
	if( GetField_CString(argHash,"txn_aprv_date",&csTxnDate)){
printf("####select from txn_balance_log where txn_aprv_date = %s and",csTxnDate);

	}

	if( GetField_Char(argHash,"party_type",&cPartyType)){
printf("  party_type = %c \n",cPartyType);
	}

	DBObjPtr = CreateObj(DBPtr, "DBTxnBalanceLog", csFunc);
	if(!strcmp("UpdateBalLog",csFunc))
	{
	
        	iRet =(unsigned long)(DBObjPtr)(argHash);
	
		if(iRet != PD_OK){
printf("DBTxnBalanceLog_UpdateBalLog Failed!");
			iRet = PD_ERR;
		}
	}

	if(!strcmp("IsCompleted",csFunc))
	{
		
        	iRet =(unsigned long)(DBObjPtr)(csTxnDate,cPartyType);
	
		if(iRet == PD_TRUE)
		{
printf("DBTxnBalanceLog_IsCompleted True!\n");
			iRet = PD_OK;
		}else
		{
		printf("DBTxnBalanceLog_IsCompleted False!\n");
		iRet = PD_OK;
		
		}

	}

	
	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		char		hv_party_type;
		int		v_is_completed;
		/* varchar		v_update_user[PD_UPDATE_USER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_update_user;

		short		ind_is_completed = -1;
		short		ind_update_user = -1;
		/* EXEC SQL END DECLARE SECTION; */ 

	
		hv_txn_date.len = strlen(csTxnDate);
		memcpy(hv_txn_date.arr, csTxnDate, hv_txn_date.len);
		hv_party_type = cPartyType;

		/* EXEC SQL SELECT	tb_is_completed,tb_update_user 
			INTO	: v_is_completed: ind_is_completed,
				: v_update_user: ind_update_user
			FROM TXN_BALANCE_LOG
			WHERE tb_txn_aprv_date = :hv_txn_date
			AND	tb_party_type = :hv_party_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select tb_is_completed , tb_update_user INTO :b0:b1 , :b2:\
b3 FROM TXN_BALANCE_LOG WHERE tb_txn_aprv_date = :b4 AND tb_party_type = :b5 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_is_completed;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_is_completed;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_update_user;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_update_user;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
  sqlstm.sqhstl[2] = (unsigned long )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_type;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto get_error;
}




		if(ind_update_user>=0){
			v_update_user.arr[v_update_user.len] = '\0';
printf("####Result: update_user = %s  ",v_update_user.arr);
		}
		if(ind_is_completed >=0 ){
printf("  is_completed = %d\n",v_is_completed);
		}
		
	

	return iRet;
get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;	

}
int batch_proc_psp_param_check(int argc, char * argv[])
{
	int	iRet = PD_OK;
	hash_t	* hIn;

	hIn = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hIn, 0);

	if(strcmp(csPspChannel, "")){
		PutField_CString(hIn, "psp_channel", csPspChannel);
	}

	if(!strcmp(csFunc,"GetDetail")){
		iRet = getDetailOfPspParamCheck();
	}

printf("PspParamCheck: %s iRet = [%d]\n", csFunc, iRet);

	FREE_ME(hIn);

	return iRet;
}

int batch_proc_test_nini(int argc, char * argv[])
{
	int iRet = PD_OK;

	hash_t	* hIn;
	hIn = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hIn, 0);

	if(strcmp(csTxnCode, "")){
		PutField_CString(hIn, "txn_code", csTxnCode);
	}
	if(strcmp(csServiceCode, "")){
		PutField_CString(hIn, "service_code", csServiceCode);
	}
	if(strcmp(csDesc, "")){
		PutField_CString(hIn, "desc", csDesc);
	}
	if(strcmp(csTxnCode, "")){
		PutField_CString(hIn, "txn_code", csTxnCode);
	}
	if(strcmp(csServiceCode, "")){
		PutField_CString(hIn, "service_code", csServiceCode);
	}
	if(strcmp(csDesc, "")){
		PutField_CString(hIn, "desc", csDesc);
	}
	if(iSysSupport>=0){
		PutField_Int(hIn, "sys_support", iSysSupport);
	}
	if(dDailyLimit>=0 && bUpdateDailyLimit){
		PutField_Double(hIn, "daily_limit", dDailyLimit);
	}
	PutField_CString(hIn, "add_user", PD_UPDATE_USER);
	PutField_CString(hIn, "update_user", PD_UPDATE_USER);


	if (!strcmp(csFunc, "Add") ){
printf("Call TestNini: %s\n", csFunc);
		DBObjPtr = CreateObj(DBPtr, "DBTestNini", csFunc);
		iRet = (unsigned long)(DBObjPtr)(hIn);
		getDetailOfTestNini();
	}
	else if (!strcmp(csFunc, "Update")){
printf("Call TestNini: %s\n", csFunc);
		DBObjPtr = CreateObj(DBPtr, "DBTestNini", csFunc);
		iRet = (unsigned long)(DBObjPtr)(hIn);
		getDetailOfTestNini();
	}
	else if(!strcmp(csFunc,"GetDetail")){
		iRet = getDetailOfTestNini();
	}
	else if(!strcmp(csFunc,"GetDetailByTxnCode")){
		recordset_t     * rInfoSet;

		rInfoSet = (recordset_t *)malloc(sizeof(recordset_t));
		recordset_init(rInfoSet, 0);

		DBObjPtr = CreateObj(DBPtr, "DBTestNini", csFunc);
        	iRet = (unsigned long)(DBObjPtr)(csTxnCode,rInfoSet);
		if (iRet == PD_FOUND)
                {
			hash_t*  hRec;	
                        hRec = RecordSet_GetFirst(rInfoSet);

                        while (hRec)
                        {
				printDetailOfTestNini(hRec);
				hRec = RecordSet_GetNext(rInfoSet);
			}
		}
		RecordSet_Destroy(rInfoSet);
                FREE_ME(rInfoSet);

	}
	else
	{
		iRet = PD_ERR;
printf("Invalid Function!!\n");
	}

printf("TestNini: %s iRet = [%d]\n", csFunc, iRet);

	FREE_ME(hIn);

printf("batch_proc end\n");
	return iRet;
}


int batch_terminate(int argc, char * argv[])
{
	FREE_ME(argHash);	
	return SUCCESS;
}

