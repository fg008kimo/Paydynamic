
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "OfflineWTDTest.pc"
};


static unsigned int sqlctx = 9854731;


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
   unsigned char  *sqhstv[16];
   unsigned long  sqhstl[16];
            int   sqhsts[16];
            short *sqindv[16];
            int   sqinds[16];
   unsigned long  sqharm[16];
   unsigned long  *sqharc[16];
   unsigned short  sqadto[16];
   unsigned short  sqtdso[16];
} sqlstm = {12,16};

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

 static char *sq0001 = 
"select batch_id ,merchant_id ,txn_date  from payout_header where status=:b0\
           ";

 static char *sq0003 = 
"select status ,merchant_ref ,country ,identity_id ,account_name ,account_nu\
m ,bank_name ,bank_code ,branch ,phone_num ,province ,city ,amount ,payout_cu\
rrency ,dest_currency ,checksum  from payout_record where (merchant_id=:b0 an\
d batch_id=:b1)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,86,0,9,88,0,0,1,1,0,1,0,1,1,0,0,
24,0,0,1,0,0,13,91,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
51,0,0,1,0,0,15,141,0,0,0,0,0,1,0,
66,0,0,2,0,0,32,142,0,0,0,0,0,1,0,
81,0,0,3,255,0,9,237,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
104,0,0,3,0,0,13,239,0,0,16,0,0,1,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,
183,0,0,3,0,0,15,402,0,0,0,0,0,1,0,
198,0,0,3,0,0,15,408,0,0,0,0,0,1,0,
213,0,0,4,0,0,32,409,0,0,0,0,0,1,0,
};


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
#include "queue_utility.h"

OBJPTR(DB);
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_TMP_TAG_LEN	25
char    cDebug;
#define MY_TMP_TOKEN            "&"
#define MY_TMP_FIELD_TOKEN      "="

int process_header();
int process_txn(const char* csBatchId, const char* csMerchId, const char* csDate);
int BatchOnelineWithdrawAll(hash_t* hReq) ;

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{

        int     iRet;

	iRet = process_header();

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;	

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int process_header()
{
	int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO head_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char    hv_status;
		
		/* varchar v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_txn_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;


		//varchar	hv_dynstmt[1024];

		short   ind_merchant_id = -1;
		short   ind_batch_id = -1;
		short   ind_txn_date= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PD_INIT_STATE;
DEBUGLOG(("process_header::status = [%c]\n",hv_status));


	/* EXEC SQL DECLARE c_cursor_getheader CURSOR FOR
		select	batch_id,
			merchant_id,
			txn_date
		from	payout_header
		where	status = :hv_status; */ 


	/* EXEC SQL OPEN c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[0] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto head_error;
}



	do{
		/* EXEC SQL FETCH c_cursor_getheader
		INTO
			:v_batch_id:ind_batch_id,
			:v_merchant_id:ind_merchant_id,
			:v_txn_date:ind_txn_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_date;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_date;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto head_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		if(ind_batch_id>=0)
			v_batch_id.arr[v_batch_id.len]='\0';
		
		if(ind_merchant_id>=0)
			v_merchant_id.arr[v_merchant_id.len]='\0';

		if(ind_txn_date>=0)
			v_txn_date.arr[v_txn_date.len]='\0';

		if((ind_batch_id>=0) &&(ind_merchant_id>=0)){

			//search record details
			iRet = process_txn((const char*)v_batch_id.arr, (const char*)v_merchant_id.arr, (const char*)v_txn_date.arr);

				// update header status to 'W'
				hash_t *hSuc;
				hSuc = (hash_t*) malloc (sizeof(hash_t));
				hash_init(hSuc,0);
				PutField_Char(hSuc,"status",PD_SENT);
				PutField_CString(hSuc,"batch_id",(const char*)v_batch_id.arr);
				PutField_CString(hSuc,"txn_date",(const char*)v_txn_date.arr);
				DBObjPtr = CreateObj(DBPtr,"DBPayoutHeader","UpdateStatus");
				if((unsigned long int)(*DBObjPtr)(hSuc) == SUCCESS){
DEBUGLOG(("Update Payout Header Status Success [%s] [%s] [%c]\n",v_batch_id.arr,v_txn_date.arr,PD_SENT));
					iRet = SUCCESS;
				}
				else{
DEBUGLOG(("Update Payout Header Status Failed [%s] [%s]\n",v_batch_id.arr,v_txn_date.arr));
				}
				FREE_ME(hSuc);	
		}
	
	}while(PD_TRUE);

	return iRet;

head_error:
    DEBUGLOG(("process_header error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getheader; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )51;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )66;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;

}

int process_txn(const char* csBatchId, const char* csMerchId, const char* csDate)
{               
	hash_t *hReq;
        hReq = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hReq,0); 
        int     iRet = SUCCESS;
	int	iTotalCnt = 0;
	int	iErrCnt = 0;
	char	*csCcyCode =  strdup("");
	//char	*csTmp;
	char	csTag[PD_TMP_TAG_LEN +1];
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		char	v_status;
	
		/* varchar	hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_merchant_ref;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar	v_account_num[PD_ACCOUNT_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_account_num;

		/* varchar	v_account_name[PD_ACCOUNT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_account_name;

		/* varchar	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar	v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar	v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_branch;

		/* varchar	v_phone[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone;

		/* varchar	v_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_province;

		/* varchar	v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_city;

		/* varchar	v_amount[PD_AMOUNT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amount;

		/* varchar	v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar	v_dest_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_dest_ccy;

		/* varchar	v_checksum[PD_CHECKSUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_checksum;


		short   ind_merchant_ref = -1;
		short   ind_country = -1;
		short	ind_identity_id = -1;
		short	ind_account_num	= -1;
		short	ind_account_name = -1;
		short	ind_bank_name = -1;
		short	ind_bank_code = -1;
		short	ind_branch = -1;
		short	ind_phone= -1;
		short	ind_city = -1;
		short	ind_province = -1;
		short	ind_amount = -1;
		short   ind_payout_ccy = -1;
		short   ind_dest_ccy = -1;
		short	ind_checksum = -1;
		short	ind_status = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	strncpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("process_txn::batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));


	hv_merchant_id.len = strlen(csMerchId);
	strncpy(hv_merchant_id.arr, csMerchId, hv_merchant_id.len);
DEBUGLOG(("process_txn::hv_merchant_id= [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

DEBUGLOG(("process_txn:: date= [%s]\n",csDate));
       
	/* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select 	status,
         		merchant_ref,
         		country,
         		identity_id,
         		account_name,
         		account_num,
         		bank_name,
         		bank_code,
         		branch,
         		phone_num,
         		province,
         		city,
         		amount,
         		payout_currency,
         		dest_currency,
         		checksum
  		   from payout_record
		  where merchant_id = :hv_merchant_id
		  and	batch_id = :hv_batch_id; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )81;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO	:v_status:ind_status,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_name:ind_account_name,
			:v_account_num:ind_account_num,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_branch:ind_branch,
			:v_phone:ind_phone,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_amount:ind_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_dest_ccy:ind_dest_ccy,
			:v_checksum:ind_checksum; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 16;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )104;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_status;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[1] = (unsigned long )28;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_identity_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[4] = (unsigned long )33;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_account_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[5] = (unsigned long )19;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_account_num;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_bank_name;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bank_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[8] = (unsigned long )28;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_branch;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_phone;
                sqlstm.sqhstl[9] = (unsigned long )28;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_phone;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[10] = (unsigned long )22;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_province;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[11] = (unsigned long )23;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_city;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[12] = (unsigned long )15;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_amount;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[13] = (unsigned long )6;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_dest_ccy;
                sqlstm.sqhstl[14] = (unsigned long )6;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_dest_ccy;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_checksum;
                sqlstm.sqhstl[15] = (unsigned long )19;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_checksum;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		if(v_status!=PD_INIT_STATE){
DEBUGLOG(("Invalid record status [%c], request not sent [%s] [%.*s]\n", v_status, csBatchId,v_merchant_ref.len,v_merchant_ref.arr));
			iErrCnt ++;
			continue;
		}


/*  process_type */
		PutField_CString(hReq,"process_type","0200");

/*  process_code */
		PutField_CString(hReq,"process_code","220001");

/* merchant_id */
		sprintf(csTag,"merchant_id_%d",iTotalCnt);	
		PutField_CString(hReq,csTag,csMerchId);

/* merchant_ref */
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			sprintf(csTag,"reference_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_merchant_ref.arr);
		}

/* transaction_datetime */
		sprintf(csTag,"transaction_datetime_%d",iTotalCnt);	
		PutField_CString(hReq,csTag,csDate);

/* pay_amount */
		if(ind_amount>=0){
			v_amount.arr[v_amount.len] = '\0';
			sprintf(csTag,"pay_amount_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_amount.arr);
		}

/* currency_code */
		sprintf(csTag,"currency_code_%d",iTotalCnt);	
		PutField_CString(hReq,csTag,"TWD");
/*
		if(ind_dest_ccy>=0){
			v_dest_ccy.arr[v_dest_ccy.len] = '\0';
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","GetCcyIdByNum");
			if((unsigned long int)(*DBObjPtr)((const char*)v_dest_ccy.arr, csTmp) == SUCCESS){
				strcpy(csCcyCode,csTmp);
				sprintf(csTag,"currency_code_%d",iTotalCnt);	
				PutField_CString(hReq,csTag,csCcyCode);
			}
		}
		
*/

/* country */
		if(ind_country>=0){
			v_country.arr[v_country.len] = '\0';
			sprintf(csTag,"country_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_country.arr);
		}

/* bank_code */
		if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len] = '\0';
			sprintf(csTag,"bank_code_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_bank_code.arr);
		}

/* branch */
		if(ind_branch>=0){
			v_branch.arr[v_branch.len] = '\0';
			sprintf(csTag,"branch_name_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_branch.arr);
		}

/* account_id */
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len] = '\0';
			sprintf(csTag,"account_id_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_account_num.arr);
		}

/* account_name */
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len] = '\0';
			sprintf(csTag,"account_name_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_account_name.arr);
		}

/* identity_id */
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len] = '\0';
			sprintf(csTag,"identity_id_%d",iTotalCnt);	
			PutField_CString(hReq,csTag,(const char*)v_identity_id.arr);
		}

/* batch_id */
		sprintf(csTag,"batch_id_%d",iTotalCnt);	
		PutField_CString(hReq,csTag,csBatchId);

/* mac */
		sprintf(csTag,"mac_%d",iTotalCnt);	
		PutField_CString(hReq,csTag,"1");

/*

		if(iRet != PD_ERR){
			hash_t *hUpd;
			hUpd = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hUpd,0);
			PutField_Char(hUpd,"status",PD_SENT);
			PutField_CString(hUpd,"merchant_ref",(const char*)v_merchant_ref.arr);
			PutField_CString(hUpd,"batch_id",csBatchId);
			DBObjPtr = CreateObj(DBPtr,"DBPayoutRecord","UpdateStatus");
			if((unsigned long int)(*DBObjPtr)(hUpd) == SUCCESS){
DEBUGLOG(("Update Payout Record Status Success [%s] [%s] [%c]\n",csBatchId,v_merchant_ref.arr,PD_SENT));
			}                       
			else{           
DEBUGLOG(("Update Payout Record Status Failed [%s] [%s]\n",csBatchId,v_merchant_ref.arr));
			}

			hash_destroy(hUpd);
			FREE_ME(hUpd);
		}
		else{
			iErrCnt ++;
		}
		
*/
		iTotalCnt++;

	}while(PD_TRUE);

	PutField_Int(hReq,"total_record",iTotalCnt);

DEBUGLOG(("send BatchOnelineWithdrawAll [%d]\n",iTotalCnt));
	iRet = BatchOnelineWithdrawAll(hReq);
DEBUGLOG(("BatchOnelineWithdrawAll RET = [%d]\n",iRet));

        FREE_ME(hReq);


	FREE_ME(csCcyCode);
	
	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )183;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 16;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )198;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 16;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )213;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int BatchOnelineWithdrawAll(hash_t* hReq) 
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	csTag[25 +1];


	int	iTotal,i;

	GetField_Int(hReq,"total_record",&iTotal);
/* process_type */      


	for (i = 0 ; i < iTotal; i++) {
/* merchant_id */
		sprintf(csTag,"merchant_id_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* merchant_ref */
		sprintf(csTag,"reference_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}
/* transaction_datetime */
		sprintf(csTag,"transaction_datetime_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}


/* pay_amount */
		sprintf(csTag,"pay_amount_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* currency_code */
		sprintf(csTag,"currency_code_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* country */
		sprintf(csTag,"country_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* bank_code */
		sprintf(csTag,"bank_code_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}


/* branch_name */
		sprintf(csTag,"branch_name_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* account_id */
		sprintf(csTag,"account_id_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* account_name */
		sprintf(csTag,"account_name_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}


/* identity_id */
		sprintf(csTag,"identity_id_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}

/* batch_id */
		sprintf(csTag,"batch_id_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}
/* mac */
		sprintf(csTag,"mac_%d",i);
		if (GetField_CString(hReq,csTag,&csPtr)) {
DEBUGLOG(("BatchOnelineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
		}
	}

        if (iRet == PD_OK) {
	}
	return iRet;
}

