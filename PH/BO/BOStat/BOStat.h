#ifndef _BOSTAT_H_
#define _BOSTAT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int UpdateDspStat(hash_t *hContext,
			const hash_t *hRequest,
			const hash_t *hResponse);
int UpdateDspMerchantStat(hash_t *hContext,
			const hash_t *hRequest,
			const hash_t *hResponse);

int UpdateCustomerGroupCounter(hash_t *hContext,
                        const hash_t *hRequest);

int UpdateCustomerPspCounter(hash_t *hContext,
                        const hash_t *hRequest);

#ifdef __cplusplus
}
#endif

#endif
