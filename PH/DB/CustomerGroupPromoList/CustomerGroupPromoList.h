#ifndef _CUSTOMER_GROUP_PM_LIST_H_
#define _CUSTOMER_GROUP_PM_LIST_H_
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int FindPromoCustomer(const char* csMerchantId,
		      const char* csCustomerTag); 

int Add(const hash_t *hRec);
int UpdatePromteCustomer(const hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
