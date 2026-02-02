#ifndef _MERCHANT_LIEN_BUCKET_H_
#define _MERCHANT_LIEN_BUCKET_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateLienAmount(const char* csMerchantID,
                     const char* csCountry,
		     const char* csMerchantCCY,
		     const char* csServiceCode,
		     double dAmount);

int GetLienAmount(const char* csMerchantId,
                  const char* csCountry,
                  const char* csTxnCcy,
                  const char* csServiceCode,
                  double *dAmt);

#ifdef __cplusplus
}
#endif

#endif
