#ifndef _BOPARBALANCE_H_
#define _BOPARBALANCE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int UpdateTxnAmount( hash_t *hContext, const hash_t *hRequest);
int UpdatePayoutAmount(hash_t *hContext);
int UpdateSettlementAmount(hash_t *hContext);

int GetAvalBalanceForUpdate(const char* csTxnCountry,
                        const char* csTxnCcy,
                        const char* csService,
                        const char* csMerchantId,
                        double  *dBalance);
int GetTotalReverseForUpdate(hash_t* hContext,
			const char* csTxnCountry,
                        const char* csTxnCcy,
                        const char* csService,
                        const char* csMerchantId,
                        double  *dBalance);

int UpdatetMerchantAvalAmt(const char* csCountry,
                        const char* csServiceCode,
                        const char* csMerchantCCY,
                        const char* csMerchantID,
                        double dTxnAmt,
                        double dNetAmt);

int GetAvalPayoutBalance(hash_t *hContext, const hash_t *hRequest, double *dActualBalance, double *dAvalBalance);

int DebitMerchantAvalAmount(hash_t *hContext, const hash_t *hRequest);
int CreditMerchantAvalAmount(hash_t *hContext, const hash_t *hRequest);

int TransferPspBalance(hash_t *hContext, const hash_t *hRequest);
int ProcessHold(hash_t *hContext,const hash_t *hRequest);
int ReleaseMerchantResAmount(const char* csMerchantID,
                                const char* csCountry,
                                const char* csMerchantCCY,
                                const char* csServiceCode,
                                double  dAmount);

int ProcessHold(hash_t *hContext,
                const hash_t *hRequest);

int ProcessMerchantAdjAmount(hash_t *hContext);

int  ProcessFundinPayout(hash_t *hContext);


#ifdef __cplusplus
}
#endif

#endif
