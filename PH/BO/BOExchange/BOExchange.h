#ifndef _BOEXCHANGE_H_
#define _BOEXCHANGE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetExchangeInfo(hash_t *hContext,
                const hash_t* hRequest);
int GetExternalExchangeRate(const char* csFromCcy,
                const char* csToCcy,
                double  dTxnAmt,
                double  *dExRate,
                double  *dExAmt);
                
int GetExternalExchangeRateByDate(const char* csEffectDate,
		const char* csFromCcy,
                const char* csToCcy,
                double  dTxnAmt,
                double  *dExRate,
                double  *dExAmt);

int GetExchangeInfoByDate(hash_t *hContext,
                    const hash_t* hRequest);
#ifdef __cplusplus
}
#endif

#endif
