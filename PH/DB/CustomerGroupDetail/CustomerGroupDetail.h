#ifndef _CUSTOMER_GROUP_DETAIL_H_
#define _CUSTOMER_GROUP_DETAIL_H_
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int FindGroup(const char* csMerchantId,
                const char* csCustomerTag,
                char*   csCustomerGroup);
int Add(const hash_t *hRec);
int UpdateGroup(const hash_t *hRec);

int MatchRecord(const char* csMerchantId,
                const char* csCustomerTag,
                const char* csCustomerGroup);

int GetMerchantDetailByCust(const char* csMerchantId,
                const char* csCustomerTag,
                hash_t* hTxn);

int GetCustomerCntBySegment(const char* csMerchantId,
                const char* csCustomerGroup);

int GetCustomerCntBySegmentForAllMerchant(const char* csCustomerGroup, recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
