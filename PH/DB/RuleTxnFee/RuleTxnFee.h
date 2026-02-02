#ifndef _RULE_TXN_FEE_H_
#define _RULE_TXN_FEE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char* csType,
		     const char* csCountryId,
		     const char* csChannelCode,
                     const char* csServiceCode,
		     const char* csTxnCode,
		     const char* csCcy,
		     const char* csMerchantId,
		     const char* csMerchantClientId,
  		     const char* csPayMethod,
		     recordset_t*);
#ifdef __cplusplus
}
#endif

#endif
