#ifndef _MERCHANT_PAY_METHOD_H_
#define _MERCHANT_PAY_METHOD_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindMerchantPayMethod(const char* csMerchantId,
			const char* csPayMethod);
			

#ifdef __cplusplus
}
#endif

#endif
