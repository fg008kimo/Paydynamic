#ifndef _MERCHANT_BUCKET_PREVIEW_H_
#define _MERCHANT_BUCKET_PREVIEW_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int AddPreviewAmount(const char* csPostingDate,
                        const char* csMerchantID,
                        const char* csCountry,
                        const char* csMerchantCCY,
			const char* csServiceCode,
			const char* csPsp,
			const char* csType,
                        double dMerchantAmount,
			const char* csUser);

int DelAll(void);
#ifdef __cplusplus
}
#endif

#endif
