#ifndef _INPUT_FILE_H
#define _INPUT_FILE_H
#include "common.h"

//#define IMPORT_FILE_NAME	"/home/cphdev/src/batch/data.csv"
//#define IMPORT_FILE_NAME	"/home/cphdev/src/batch/NA2PROCHUB201010141.csv"
#define IMPORT_FILE_NAME	"/home/cphdev/src/batch/NA2PROCHUB20101018109.csv"

#define MAX_DATA	15
#define MAX_LEN		101
#define BUFFER_LEN	1000
#define AMOUNT_LEN	12

#define VALID_ID	1
#define INVALID_ID	0
#define IDENTITY_ID_LEN 10
#define DATE_LEN	8
#define	REJECT		-100
#define	INVALID_AMOUNT	1
#define VALID_AMOUNT  0

#ifdef __cplusplus
extern "C" {
#endif
typedef struct rData{
  char csSeqNum[PD_SEQ_NUM_LEN+1];
  char csMerchRef[PD_MERCHANT_REF_LEN+1];
  char csCountry[PD_COUNTRY_LEN+1];
  char csIdNo[IDENTITY_ID_LEN+1];
  char csAccountNum[PD_AC_NO_LEN+1];
  char csAccountName[PD_ACC_NAME_LEN+1];
  char csBankName[PD_BANK_NAME_LEN+1];
  char csBankCode[PD_BANK_CODE_LEN+1];
  char csBranch[PD_BANK_BRANCH_LEN+1];
  char csMobileNo[PD_MOBILE_NO_LEN+1];
  char csProvince[PD_PROVINCE_LEN+1];
  char csCity[PD_CITY_LEN+1];
  char csAmount[AMOUNT_LEN+1];
  char csPayoutCurr[PD_CCY_ID_LEN+1];
  char csDestCurr[PD_CCY_ID_LEN+1];
  char csChecksum[PD_CHECKSUM_LEN+1];

  char csHeaderChecksum[PD_CHECKSUM_LEN+1];
  char csMerchId[PD_MERCHANT_ID_LEN+1];
  char csBatchId[PD_MERCHANT_ID_LEN+1];
  char csDate[DATE_LEN+1];
  int  iNumOfRec;

  char csShaKey[PD_SHA_KEY_LEN+1];

}rData;

#ifdef __cplusplus
}
#endif


#endif
