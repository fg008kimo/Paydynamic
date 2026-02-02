#ifndef _CUSTOMER_BLACK_LIST_H_
#define _CUSTOMER_BLACK_LIST_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int IsBlacklisted(const unsigned char* csMerchantId,
		  const unsigned char* csCustomerTag);
		  
int GetMerchBlklstCtl(const unsigned char* csMerchantId);

int CustBlklstAdd(const hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
