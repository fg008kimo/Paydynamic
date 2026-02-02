#ifndef _GET_DATA_COMPARE_H
#define _GET_DATA_COMPARE_H
#include "common.h"

#define DATA_FROM_DB		"/home/cphdev/src/batch/DataCompare2Web.csv"
#define DATA_FORMAT		"TID,DATE,AR_IND,TXN_ID,PAY_METHOD,AMOUNT,BANK,BRANCH,ACCOUNT_NAME,ACCOUNT_NUM,ERROR_CODE,DATE,SERVICE_FEE,BATCH_ID\n"
//#define DOWNLOAD_FILE_NAME	"DepositList-20101005_145643.csv"

#define LIST_MAX	5000
#define BUFFER_LEN	1000
#define MAX_DATA	14
#define MAX_LEN		100
#define AMOUNT_LEN	12
#define DATE_LEN	strlen("yyyymmdd")

#ifdef __cplusplus
extern "C" {
#endif
typedef struct rData{

char csTid[PD_MERCHANT_REF_LEN+1];
char csTxnId[PD_TXN_SEQ_LEN+1];
char csAmount[AMOUNT_LEN+1];
char csTranTime[PD_DATETIME_LEN+1];
char csServiceFee[AMOUNT_LEN+1];
char csBatchId[PD_BATCH_LEN+1];

}rData;

#ifdef __cplusplus
}
#endif


#endif
