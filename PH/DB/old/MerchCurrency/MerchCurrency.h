#ifndef _MERCH_CURRENCY_H_
#define _MERCH_CURRENCY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int Add(const hash_t *);
//int Delete(const char* client_id, const char* merchant_id,const char* name);
int CheckMerchCurrency(const char* csMerchantID,const char* csCcyCode);

#ifdef __cplusplus
}
#endif

#endif
