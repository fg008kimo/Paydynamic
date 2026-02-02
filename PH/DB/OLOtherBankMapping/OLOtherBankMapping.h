#ifndef _OLOTHERBANKMAPPING_H_
#define _OLOTHERBANKMAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetOtherBankList(const char* csMerchantId,
                        const char* csCountry,
                        const char* csAcctCcy,
			const char* csServiceCode,
			const char* csAction,
                        hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
