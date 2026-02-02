#ifndef _MERCHANT_BUCKET_H_
#define _MERCHANT_BUCKET_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CreditMerchantAmount(const char* csPostingDate,
                        const char* csMerchantID,
                        const char* csCountry,
                        const char* csMerchantCCY,
			const char* csServiceCode,
			const char* csPsp,
			const char* csType,
                        double dMerchantAmount,
			const char* csUser);

int UpdateReleaseDetails(const hash_t *hMerchantBucket);

int UpdateBalanceByType(const hash_t *hMerchantBucket);
double GetBalanceByType(const hash_t *hMerchantBucket);

int DebitMerchantAmount(const char* csPostingDate,
                        const char* csMerchantID,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csServiceCode,
                        const char* csPsp,
                        const char* csType,
                        double dAmount,
                        const char* csUser);

int     GetTotalAFPOFloat(const char* csMerchantId,
                          const char* csCountry,
                          const char* csTxnCcy,
                          const char* csServiceCode,
                          recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
