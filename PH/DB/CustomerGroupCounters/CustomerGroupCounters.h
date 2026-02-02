#ifndef _CUSTOMER_GROUPS_COUNTERS_H_
#define _CUSTOMER_GROUPS_COUNTERS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CounterCreate(const char* csCode,
                const char* csCountry,
		const char* csChannelCode,
		const char* csServiceCode,
                const char* csCcy,
		const char* csDate,
                double  dCounter,
                const char* csUser);

int ChangeGroupDelta(const char* csCountry,
                const char* csChannelCode,
                const char* csServiceCode,
                const char* csCcy,
                const char* csFromCode,
                const char* csToCode,
                const char* csDate,
                double  dDelta,
                const char* csUser);
#ifdef __cplusplus
}
#endif

#endif
