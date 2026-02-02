#ifndef _BOFEE_H_
#define _BOFEE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetTxnFee(hash_t *hContext, const hash_t *hRequest);
//int GetDstTxnFee(hash_t *hContext, const hash_t *hRequest);
int UpdateAmt(hash_t *hContext, const hash_t *hRequest);
#ifdef __cplusplus
}
#endif

#endif
