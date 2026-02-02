#ifndef _MERCHANT_BAL_ACCT_H_
#define _MERCHANT_BAL_ACCT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckMerchantBalAcct(const char* csMerchantID,
			const char* csCountry,
			const char* csCcy,
			const char* csServiceCode,
			hash_t *hRec);

int UpdateMerchantBalAcctStatus(const hash_t* hRls);

int UpdateMerchantAutoSettlement(const hash_t *hRls);

int Add(const hash_t *hMerchantBalAcct);

int GetAutoSettId(const hash_t *hMerchantBalAcct, int *iSupportAutoSett, int *iAutoSettId);

int GetACRPool(const char* csMerchantID,
                const char* csCountry,
                const char* csCcy,
                const char* csServiceCode,
                char*   csACRPool);
#ifdef __cplusplus
}
#endif

#endif
