#ifndef _BODEPOSITTRACE_H_
#define _BODEPOSITTRACE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int CheckTxnStatus(hash_t *hContext);

int CheckTraceStatus(hash_t *hContext);

#ifdef __cplusplus
}
#endif

#endif
