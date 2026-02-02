#ifndef _BORESERVE_H_
#define _BORESERVE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetReserveAmount(hash_t *hContext, const hash_t *hRequest);

int HandleReserveAmount(hash_t *hContext);

#ifdef __cplusplus
}
#endif

#endif
