#ifndef _BOTXNLIMIT_H_
#define _BOTXNLIMIT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int TxnLimit(hash_t *hContext,
                        const hash_t *hRequest);

#ifdef __cplusplus
}
#endif

#endif
