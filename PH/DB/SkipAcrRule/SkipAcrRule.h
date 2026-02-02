#ifndef _SKIP_ACR_RULE_H_
#define _SKIP_ACR_RULE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int IsSkipRule(const char* csTxnCode,
		const char* csServiceCode,
		const char* csMerchantId);

#ifdef __cplusplus
}
#endif

#endif
