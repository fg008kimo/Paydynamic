#ifndef _CUSTOMER_GROUPS_OFFSET_LOG_H_
#define _CUSTOMER_GROUPS_OFFSET_LOG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const char* csCode,
                const char* csCountry,
		const char* csChannelCode,
		const char* csServiceCode,
                const char* csCcy,
                double  dAdjValue,
                const char* csUser);

#ifdef __cplusplus
}
#endif

#endif
