#ifndef _BOMERCHANT_H_
#define _BOMERCHANT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int GetMerchantDetail(hash_t *hContext,
                const hash_t* hRequest);
int GetMerchantTxnInfo(hash_t *hContext,
                const hash_t* hRequest);
int GetMerchantReservedAmt(hash_t *hContext,
                           const hash_t* hRequest,
                           hash_t* hResponse);

#ifdef __cplusplus
}
#endif

#endif
