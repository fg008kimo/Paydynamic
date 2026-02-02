#ifndef _BOCUSTOMER_GROUP_H_
#define _BOCUSTOMER_GROUP_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int CreateCustomerGroup(hash_t* hContext,
                hash_t *hRequest,
                hash_t *hResponse);

int ChangeGroup(hash_t* hTxn);

int GetAavailableMobSegment(const char* csMerchantId, hash_t* hTxn);

int HandleMobSegmentThreshold(const hash_t* hTxn);

int ConvertCustomerGroup(hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
