#ifndef _EXCHANGE_LIMIT_RATE_H_
#define _EXCHANGE_LIMIT_RATE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetExchangeLimitRate(const char* csFromCcyId, const char* csToCcyId, double* dRate);
#ifdef __cplusplus
}
#endif

#endif
