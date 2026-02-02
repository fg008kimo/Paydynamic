#ifndef _RULE_TXN_RES_H_
#define _RULE_TXN_RES_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char* csCountryId,
	 const char* csChannelCode,
         const char* csServiceCode,
         const char* csTxnCode,
         const char* csMerchantId,
         const char* csMerchantClientId,
         char   *cType, 
         double *dValue);
#ifdef __cplusplus
}
#endif

#endif
