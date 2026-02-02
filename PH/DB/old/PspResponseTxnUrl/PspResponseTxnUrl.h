#ifndef _PSP_URL_H_
#define _PSP_URL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const unsigned char* psp_id, const unsigned char* txn_code);
int GetPspResponseTxnUrl(const char* csPspId,const char* csTxnCode, hash_t* hRec);
#ifdef __cplusplus
}
#endif

#endif
