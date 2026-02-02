#ifndef _CUSTOMER_GROUP_MERCHANT_H_
#define _CUSTOMER_GROUP_MERCHANT_H_

#ifdef __cplusplus
extern "C" {
#endif

int FindMerchant(const char* csMerchantId);

int GetMerchantPhase(const char* csMerchantId);
#ifdef __cplusplus
}
#endif

#endif
