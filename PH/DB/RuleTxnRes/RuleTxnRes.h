#ifndef _RULE_TXN_RES_H_
#define _RULE_TXN_RES_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char* csMerchantId,
         const char* csMerchantClientId,
         char   *cType, 
         double *dValue);

int FindById(char cPartyType,
	const char* csId,
	int* iAmtId);

int Add(const hash_t* hRls);

int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
