#ifndef _BOOIASECURITY_H_
#define _BOOIASECURITY_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int VerifyMac(hash_t *hContext,
                const hash_t* hRequest);

int GenerateMac(hash_t *hContext,
                hash_t* hOut);

#ifdef __cplusplus
}
#endif

#endif
