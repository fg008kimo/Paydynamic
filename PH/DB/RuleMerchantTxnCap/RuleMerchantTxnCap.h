#ifndef _RULE_MERCHANT_TXN_CAP_H_
#define _RULE_MERCHANT_TXN_CAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char* csCountryId,
		const char* csChannelCode,
		const char* csTxnCode,
		const char* csServiceCode,
		const char* csMerchantId,
		const char* csClientId,
		recordset_t* myRec);	
	

#ifdef __cplusplus
}
#endif

#endif
