#ifndef _BOUNIQUE_NUM_H_
#define _BOUNIQUE_NUM_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetUniqueAmt(hash_t *hContext,
                const hash_t* hRequest,
                hash_t* hResponse);

#ifdef __cplusplus
}
#endif

#endif
