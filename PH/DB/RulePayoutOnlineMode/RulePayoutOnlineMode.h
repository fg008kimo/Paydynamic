#ifndef _RULE_PAYOUT_ONLINE_MODE_H_
#define _RULE_PAYOUT_ONLINE_MODE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int ChkRuleExists(const unsigned char* csMerchantId,
		 const unsigned char* csServiceCode);

int ChkRuleExistsByMerchant(const unsigned char* csMerchantId);

int FindPsp(const unsigned char* csMerchantId,
            const unsigned char* csServiceCode,
            unsigned char* csPspId);

int FindPspInfo(const unsigned char* csMerchantId,
            const unsigned char* csServiceCode,
            hash_t *hTxn);
#ifdef __cplusplus
}
#endif

#endif
