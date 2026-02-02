#ifndef _TXN_QR_REQUEST_LOG_H_
#define _TXN_QR_REQUEST_LOG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add	(const hash_t* hRec);

int GetByTxnId (const char* csTxnId,
                hash_t* myHash);

#ifdef __cplusplus
}
#endif

#endif
