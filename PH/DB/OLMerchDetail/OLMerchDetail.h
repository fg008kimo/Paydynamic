#ifndef _OLMERCH_DETAIL_H_
#define _OLMERCH_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const char* merchant_id); 
int GetMerchant(const char* csMerchantID,
                recordset_t* myRec);
int GetDepositRequestVer(const char* csMerchantID,
				hash_t* hRls);
int Update(const hash_t *hRls);

int     ChkOLMerchIDExist(const char *csMID);
int GetMerchByShortName(const char* csMerchName, hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
