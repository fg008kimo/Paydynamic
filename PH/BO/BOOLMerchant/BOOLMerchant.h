#ifndef _BOOLMERCHANT_H_
#define _BOOLMERCHANT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetMerchantDetail(hash_t *hContext,
                const hash_t* hRequest);
int GetMerchantTxnInfo(hash_t *hContext,
                const hash_t* hRequest);

int GetDepositBankAcct(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse);

#ifdef __cplusplus
}
#endif

#endif
