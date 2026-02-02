#ifndef _RULE_EX_MARKUP_H_
#define _RULE_EX_MARKUP_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find( const char* csCountryId,
		     const char* csChannelCode,
                     const char* csServiceCode,
		     const char* csTxnCode,
		     const char* csMerchantId,
		     const char* csMerchantClientId,
		     double	*dValue,
		     double	*dResValue);
#ifdef __cplusplus
}
#endif

#endif
