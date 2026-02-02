/*
Partnerdelight. (c)2010. All rights reserved. No part of this software may be reproduced in any form without written 
permission of an authorized representative of Partnerdelight


Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/08/13              Cody Chan
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include <sys/types.h>
#include <time.h>

#include "common.h"
#include "utilitys.h"
#include "mymd5.h"
#include "private_key.h"
#include "dbuser.h"
#include "dbutility.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "internal.h"
#include "OnlineWTBHaiPay.h"
#include "OnlineWTBHaiPayDB.h"


#include "soapH.h"
#include "BatchServiceSoap12.nsmap"

#include <unistd.h>             /* defines _POSIX_THREADS if pthreads are available */
#if defined(_POSIX_THREADS) || defined(_SC_THREADS)
#include <pthread.h>
#endif

#include <signal.h>
char    cDebug;
int         	return_code;


#define MY_FIELD_TOKEN  "|"
#define PD_HPAY_WTB_SUCC "0000"

int CRYPTO_thread_setup();
void CRYPTO_thread_cleanup();
void sigpipe_handle(int);


int main(int argc, char*argv[])
{
	hash_t *hContext;   
	hash_t *hRequest;   
	int	iRet;


	ConnectDB();

	return_code=batch_init(argc, argv);
        if (return_code == FAILURE) {
DEBUGLOG(("main: section validation error\n"));
		TxnAbort();
                return(FAILURE);
        }
    	else
        {
        	hContext = (hash_t*) malloc (sizeof(hash_t));
        	hRequest = (hash_t*) malloc (sizeof(hash_t));

        	hash_init(hContext,0); 
        	hash_init(hRequest,0); 

                iRet=batch_proc(argc, argv,hContext,hRequest);
DEBUGLOG(("batch_proc = iRet = [%d]\n",iRet));
                if (iRet != PD_OK)
                {
			TxnAbort();
                        return(return_code);
                }
		else {
			iRet = Send2HaiPay(hContext,hRequest);
		}

		if (iRet == PD_OK) {
			iRet = UpdatePreHAIPAYRespTxnLog(hContext,hRequest);
DEBUGLOG(("iRet = [%d]\n",iRet));
		}
		FREE_ME(hContext);
		FREE_ME(hRequest);
		if (iRet == PD_OK)
			return_code = SUCCESS;
        }

DEBUGLOG(("return_code = [%d]\n",return_code));
        if (return_code != SUCCESS) {
		TxnAbort();
DEBUGLOG(("Rollback\n"));
	}
        else {
		TxnCommit();
	}
        return(SUCCESS);
}


int Send2HaiPay(const hash_t *hContext,
                hash_t* hRequest)
{
	int 	iRet = PD_OK;
	int	iTotal = 0,i;
	char	*csPtr,*csAccessKey;
	char	csTag[PD_TAG_LEN + 1];
        char    *csURL;
        char    *csAction;
	//double	dTmp;
	char    *csSign,*csOUT;
	csSign = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);
        csOUT = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);
	csSign[0]='\0';
        csOUT[0]='\0';

	struct soap *soap = soap_new1(SOAP_C_UTFSTRING); /* preserve UTF8 string content */;
  	soap_ssl_init();
  	if (CRYPTO_thread_setup())
  	{ fprintf(stderr, "Cannot setup thread mutex for OpenSSL\n");
    		errlog("Cannot setup thread mutex for OpenSS\n");
		return PD_ERR;
  	}
  	/* Init gSOAP context */
  	soap_init(soap);
 	soap_set_mode(soap, SOAP_C_UTFSTRING);

	if (soap_ssl_client_context(soap,
    		/* SOAP_SSL_NO_AUTHENTICATION, */ /* for encryption w/o authentication */
    		/* SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK, */  /* if we don't want the host name checks since these will change from machine to machine */
    		SOAP_SSL_NO_AUTHENTICATION, /* use SOAP_SSL_DEFAULT in production code */
    		NULL,               /* keyfile (cert+key): required only when client must authenticate to server (see SSL docs to create this file) */
    		NULL,               /* password to read the keyfile */
    		NULL,       /* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
    		NULL,               /* optional capath to directory with trusted certificates */
    		NULL                /* if randfile!=NULL: use a file with random data to seed randomness */
  		))
  		{ soap_print_fault(soap, stderr);
    			errlog("Cannot connect to TWV\n");
			return PD_ERR;
  		}

		soap->connect_timeout = 60;    /* try to connect for 1 minute */
  		soap->send_timeout = soap->recv_timeout = 30;   /* if I/O stalls, then timeout after 30 seconds */


                //struct ns2__WithdrawInitResponse rRes;
                //struct WithdrawInitInfoArray *rReq;
               // struct ns1__WithdrawInitInfo *pp,**pa;

                struct _ns1__BatchInResponse rRes;
                struct _ns1__BatchIn *rReq;

		rReq = soap_malloc(soap,sizeof(struct _ns1__BatchIn));

DEBUGLOG(("Req: WTB\n"));
/* init */      
                
                
/* total */
DEBUGLOG(("Req: iTotal = [%d]\n",iTotal));
		if (GetField_Int(hRequest,"total_record",&iTotal)) {
DEBUGLOG(("Req: iTotal = [%d]\n",iTotal));
                }
                

/* access key */
		if (GetField_CString(hRequest,"access_key",&csPtr)) {
                        csAccessKey = soap_strdup(soap,csPtr);
DEBUGLOG(("Req: access_key = [%s]\n",csAccessKey));
                }

/* URL*/
		if (GetField_CString(hRequest,"URL",&csPtr)) {
                        csURL = soap_strdup(soap,csPtr);
DEBUGLOG(("Req: URL = [%s]\n",csURL));
                }

/*action */
		if (GetField_CString(hRequest,"action",&csPtr)) {
                //        csAction = soap_strdup(soap,csPtr);
			  csAction = soap_strdup(soap,"http://merchant.happycz.com.cn/BatchIn"); 
DEBUGLOG(("Req: ACTION = [%s]\n",csAction));
                }

		for (i = 0; i < iTotal; i++) {
/* merchant_id */  
			sprintf(csTag,"psp_merchant_id_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
				rReq->MERCODE=soap_strdup(soap,csPtr);
				//rReq->MERCODE=soap_strdup(soap,"888000130");
DEBUGLOG(("Req: psp_merchant_id = [%s]\n",rReq->MERCODE));
				strcpy(csSign,csPtr);
			//	strcpy(csSign,"888000130");
                	}
			else {
DEBUGLOG(("*******Req: %s missig\n",csTag));
			}

/*DETAILSID*/
			sprintf(csTag,"txn_seq_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->DETAILSID=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->DETAILSID));
                        }

/*FLAG*/
			rReq->FLAG=1;
			strcat(csSign,"1");
			//strcat(csSign,MY_FIELD_TOKEN);
DEBUGLOG(("Req: FLAG = [%d]\n",rReq->FLAG));

/*NAME*/
			sprintf(csTag,"account_name_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->NAME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->NAME));
                        }

/*IDCARD*/
			sprintf(csTag,"identity_id_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->IDCARD=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->IDCARD));
                        }

/*MOBILEPHONE*/
			sprintf(csTag,"phone_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->MOBILEPHONE=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->MOBILEPHONE));
                        }


/*bank_name */  
			sprintf(csTag,"bank_name_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->BANKNAME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->BANKNAME));
                	}

/*branch_name */
			sprintf(csTag,"branch_name_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->BRANCHBANKNAME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->BRANCHBANKNAME));
                	}

/*account_id */
			sprintf(csTag,"account_id_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->ACCOUNT=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->ACCOUNT));
                	}


			strcat(csSign,csAccessKey);
			//strcat(csSign,MY_FIELD_TOKEN);
/*amount */
			sprintf(csTag,"pay_amount_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->AMOUNT=soap_strdup(soap,csPtr);
				strcat(csSign,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->AMOUNT));
                	}

/*date*/
			sprintf(csTag,"transaction_datetime_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->DCREATETIME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->DCREATETIME));
                	}


/*province*/
			sprintf(csTag,"province_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->PROVINCENAME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->PROVINCENAME));
                	}

/*city*/
			sprintf(csTag,"city_%d",i);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
                                rReq->CITYNAME=soap_strdup(soap,csPtr);
DEBUGLOG(("Req: %s = [%s]\n",csTag,rReq->CITYNAME));
                	}


/*sign*/
DEBUGLOG(("Req: sign data = [%s]\n",csSign));
			md5sum(csSign,strlen(csSign),csOUT);
			csSign[0] = '\0';
			U2L(csOUT,strlen(csOUT),csSign);
			rReq->SIGN=soap_strdup(soap,csSign);
DEBUGLOG(("Req: sign = [%s]\n",rReq->SIGN));


	                if (soap_call___ns2__BatchIn(soap, csURL, csAction, rReq,&rRes) == SOAP_OK) {
				iRet = PD_OK;
DEBUGLOG(("Rsp: from Withdawinit OK\n"));
				
DEBUGLOG(("Result: Count = [%d]\n",rRes.BatchInResult->Count));
DEBUGLOG(("Result: Error Code = [%s]\n",rRes.BatchInResult->ErrCode));
				sprintf(csTag,"response_code_%d",i);
				PutField_CString(hRequest,csTag,rRes.BatchInResult->ErrCode);
				if(strcmp(rRes.BatchInResult->ErrCode,PD_HPAY_WTB_SUCC)==0){

//DEBUGLOG(("Result: Project Id = [%s]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->ProjectId));

/*psp batch id*/
					int iBatchId = atoi(rRes.BatchInResult->ReturnRecords->ReturnRecord->BatchId);
					sprintf(csTag,"psp_batch_id_%d",i);
					PutField_Int(hRequest,csTag,iBatchId);
DEBUGLOG(("Result: Batch Id = [%d]\n",iBatchId));

//DEBUGLOG(("Result: Batch Name = [%s]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->BatchName));
//DEBUGLOG(("Result: Currency = [%s]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->Cr_USCORECode));


DEBUGLOG(("Result: Amounts = [%ld]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->Amounts));
DEBUGLOG(("Result: Pay Amount = [%ld]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->PayAmount));
DEBUGLOG(("Result: Receive Amount = [%ld]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->ReceiveAmount));

/* status */
DEBUGLOG(("Result: Flag = [%s]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->Flag));
					sprintf(csTag,"status_%d",i);
					PutField_CString(hRequest,csTag,rRes.BatchInResult->ReturnRecords->ReturnRecord->Flag);
					

//DEBUGLOG(("Result: Sign = [%s]\n",rRes.BatchInResult->ReturnRecords->ReturnRecord->Sign));

/* txn id */
DEBUGLOG(("Result: Details New = [%s]\n",rRes.BatchInResult->ReturnRecordSubs->ReturnRecordSub->DetailsNew));
					sprintf(csTag,"txn_seq_%d",i);
					PutField_CString(hRequest,csTag,rRes.BatchInResult->ReturnRecordSubs->ReturnRecordSub->DetailsNew);

DEBUGLOG(("Result: Amounts New = [%ld]\n",rRes.BatchInResult->ReturnRecordSubs->ReturnRecordSub->AmountsNew));
DEBUGLOG(("Result: Pay Amount New = [%ld]\n",rRes.BatchInResult->ReturnRecordSubs->ReturnRecordSub->PayAmountNew));
DEBUGLOG(("Result: Receive Amount New = [%ld]\n",rRes.BatchInResult->ReturnRecordSubs->ReturnRecordSub->ReceiveAmountNew));

				}
				else{
DEBUGLOG(("Rsp: Withdawinit Failed\n"));
					sprintf(csTag,"txn_seq_%d",i);
                                	PutField_CString(hRequest,csTag,rReq->DETAILSID);

                                	sprintf(csTag,"status_%d",i);
                                	PutField_CString(hRequest,csTag,"N");
					iRet = PD_ERR;
				}
				
			}
			else{
DEBUGLOG(("Rsp: from Withdawinit Err\n"));
                                soap_print_fault(soap, stderr);
				iRet = PD_ERR;
			}
		}



	FREE_ME(csSign);
        FREE_ME(csOUT);
DEBUGLOG(("try to destory\n"));
	soap_destroy(soap); /* C++ */
DEBUGLOG(("try to end\n"));
  	soap_end(soap);
DEBUGLOG(("try to done\n"));
  	soap_done(soap);
  	CRYPTO_thread_cleanup();

	iRet = PD_OK;
DEBUGLOG(("Send2HaiPay return [%d]\n",iRet));
	return iRet;
}



/******************************************************************************\
 *
 *      OpenSSL
 *
\******************************************************************************/

#ifdef WITH_OPENSSL

#if defined(WIN32)
# define MUTEX_TYPE             HANDLE
# define MUTEX_SETUP(x)         (x) = CreateMutex(NULL, FALSE, NULL)
# define MUTEX_CLEANUP(x)       CloseHandle(x)
# define MUTEX_LOCK(x)          WaitForSingleObject((x), INFINITE)
# define MUTEX_UNLOCK(x)        ReleaseMutex(x)
# define THREAD_ID              GetCurrentThreadId()
#elif defined(_POSIX_THREADS) || defined(_SC_THREADS)
# define MUTEX_TYPE             pthread_mutex_t
# define MUTEX_SETUP(x)         pthread_mutex_init(&(x), NULL)
# define MUTEX_CLEANUP(x)       pthread_mutex_destroy(&(x))
# define MUTEX_LOCK(x)          pthread_mutex_lock(&(x))
# define MUTEX_UNLOCK(x)        pthread_mutex_unlock(&(x))
# define THREAD_ID              pthread_self()
#else
# error "You must define mutex operations appropriate for your platform"
# error "See OpenSSL /threads/th-lock.c on how to implement mutex on your platform"
#endif

struct CRYPTO_dynlock_value
{ MUTEX_TYPE mutex;
};

static MUTEX_TYPE *mutex_buf;

static struct CRYPTO_dynlock_value *dyn_create_function(const char *file, int line)
{ struct CRYPTO_dynlock_value *value;
  value = (struct CRYPTO_dynlock_value*)malloc(sizeof(struct CRYPTO_dynlock_value));
  if (value)
    MUTEX_SETUP(value->mutex);
  return value;
}

static void dyn_lock_function(int mode, struct CRYPTO_dynlock_value *l, const char *file, int line)
{ if (mode & CRYPTO_LOCK)
    MUTEX_LOCK(l->mutex);
  else
    MUTEX_UNLOCK(l->mutex);
}

static void dyn_destroy_function(struct CRYPTO_dynlock_value *l, const char *file, int line)
{ MUTEX_CLEANUP(l->mutex);
  free(l);
}

void locking_function(int mode, int n, const char *file, int line)
{ if (mode & CRYPTO_LOCK)
    MUTEX_LOCK(mutex_buf[n]);
  else
    MUTEX_UNLOCK(mutex_buf[n]);
}

unsigned long id_function()
{ return (unsigned long)THREAD_ID;
}

int CRYPTO_thread_setup()
{ int i;
  mutex_buf = (MUTEX_TYPE*)malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t));
  if (!mutex_buf)
    return SOAP_EOM;
  for (i = 0; i < CRYPTO_num_locks(); i++)
    MUTEX_SETUP(mutex_buf[i]);
  CRYPTO_set_id_callback(id_function);
  CRYPTO_set_locking_callback(locking_function);
  CRYPTO_set_dynlock_create_callback(dyn_create_function);
  CRYPTO_set_dynlock_lock_callback(dyn_lock_function);
  CRYPTO_set_dynlock_destroy_callback(dyn_destroy_function);
  return SOAP_OK;
}

void CRYPTO_thread_cleanup()
{ int i;
  if (!mutex_buf)
    return;
  CRYPTO_set_id_callback(NULL);
  CRYPTO_set_locking_callback(NULL);
  CRYPTO_set_dynlock_create_callback(NULL);
  CRYPTO_set_dynlock_lock_callback(NULL);
  CRYPTO_set_dynlock_destroy_callback(NULL);
  for (i = 0; i < CRYPTO_num_locks(); i++)
    MUTEX_CLEANUP(mutex_buf[i]);
  free(mutex_buf);
  mutex_buf = NULL;
}

#else

/* OpenSSL not used, e.g. GNUTLS is used */

int CRYPTO_thread_setup()
{ return SOAP_OK;
}

void CRYPTO_thread_cleanup()
{ }

#endif

/******************************************************************************\
 *
 *      SIGPIPE
 *
\******************************************************************************/

void sigpipe_handle(int x) { }
