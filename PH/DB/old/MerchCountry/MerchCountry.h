#ifndef _MERCH_COUNTRY_H_
#define _MERCH_COUNTRY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int Add(const hash_t *);
//int Delete(const char* client_id, const char* merchant_id,const char* name);
int CheckMerchCountry(const char* csMerchantID,const char* csCountry);

#ifdef __cplusplus
}
#endif

#endif
