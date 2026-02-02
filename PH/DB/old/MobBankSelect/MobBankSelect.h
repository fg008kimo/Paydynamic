#ifndef _MOB_BANK_SELECT_H_
#define _MOB_BANK_SELECT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMobileSegment(const char* csMerchantId,
                     const char* csBankCode,
                     hash_t * hTxn);

int PickGroup(const char* csMerchantId,
                     hash_t * hTxn);

int GetMobileBankByPsp(const char* csChannelId,
                       hash_t* myHash);
#ifdef __cplusplus
}
#endif

#endif
