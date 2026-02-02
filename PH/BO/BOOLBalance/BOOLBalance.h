#ifndef _BOOLBALANCE_H_
#define _BOOLBALANCE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int UpdateTxnAmount(hash_t *hContext);

int ProcessHold(hash_t *hContext,const hash_t *hRequest);

int GetAvalPayoutBalance(hash_t *hContext,
                        const hash_t *hRequest,
                        double *dActualBalance,
                        double *dAvalBalance);

int UpdatePayoutAmount(hash_t* hContext);

int UpdateSettlementAmount(hash_t *hContext);
int DebitSebBalance(hash_t *hContext, const hash_t *hRequest);
int RestoreSebBalance(hash_t *hContext, const hash_t *hRequest);
int ProcessFundinPayout(hash_t *hContext);

int ProcessMerchantAdjAmount(hash_t *hContext);

int ProcessTransferAvaPayout(hash_t *hContext);

int UpdateAFPOFloat(hash_t* hContext);

int UpdateAmount(hash_t* hContext);

int ProcessAvaPayout(hash_t *hContext);

int IsUpdatePayoutTempBAIDBal(const char* csBaid);

#ifdef __cplusplus
}
#endif

#endif
