#ifndef _PSP_URL_H_
#define _PSP_URL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
//int Add(const hash_t *);
//int Delete(const unsigned char* psp_id, const unsigned char* txn_code);
int GetPspRequestTxnUrl(const char* csPspId,const char* csTxnCode, const char* csPayMethod, hash_t* hRec);
int UpdatePspRequestTxnUrl(const hash_t* hPspRTUrl);

#ifdef __cplusplus
}
#endif

#endif
