#ifndef _MERCH_DETAIL_H_
#define _MERCH_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const char* merchant_id,const char* url);
int GetMerchUrl(const char* csMerchantID, recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
