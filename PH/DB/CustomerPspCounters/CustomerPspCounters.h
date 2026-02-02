#ifndef _CUSTOMER_PSP_COUNTERS_H_
#define _CUSTOMER_PSP_COUNTERS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CounterCreate(const char *csCustId,
			const char *csPspId,
			const char *csDate,
			const char *csCategory,
			double dCounter,
			const char *csUser);

int ChkCustomerPspCounters(const char *csPspId, const char *csCustTag);

#ifdef __cplusplus
}
#endif

#endif
