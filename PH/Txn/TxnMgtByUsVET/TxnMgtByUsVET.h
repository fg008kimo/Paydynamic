#ifndef _TXNMGTBYUSVET_H_
#define _TXNMGTBYUSVET_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int   Authorize(hash_t* hContext,
                const hash_t* hRequest,
                hash_t* hResponse);


int GetTxnInfo(const unsigned char *csTxnSeq,
                hash_t * hContext);
#ifdef __cplusplus
}
#endif

#endif
