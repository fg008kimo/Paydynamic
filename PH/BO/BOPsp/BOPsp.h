#ifndef _BOPSP_H_
#define _BOPSP_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetTxnPsp(hash_t *hContext,
                const hash_t* hRequest);

int GetTxnPspByPspId(hash_t *hContext,
                const hash_t* hRequest,
		const char* csPspId,
		const char* csTxnCode);

int CalPspFee(hash_t *hContext,
               const hash_t* hRequest);

int GetPspReconTxnDetail(hash_t *hContext,
			const hash_t *hRequest,
                        hash_t *hResponse);

int GetAvalPspBalanceForPO(hash_t *hContext,
                const hash_t* hRequest);

int CheckPspStatus(const char* csPspId);

#ifdef __cplusplus
}
#endif

#endif
