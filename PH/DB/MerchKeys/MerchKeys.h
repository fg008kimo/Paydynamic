#ifndef _MERCH_KEYS_H_
#define _MERCH_KEYS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const char* merchant_id,const char* key);
int GetMerchantKey(const char* csMerchantID,const char* csKey,recordset_t* myRec);
int CheckAvailableForGenSTK(const char* csMerchantID);
int CheckAvailableForGenPOAKey(const char* csMerchantID);
int UpdateKey(const hash_t *hMerchKeys);

#ifdef __cplusplus
}
#endif

#endif
