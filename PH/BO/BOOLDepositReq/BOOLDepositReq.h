#ifndef _BOOLDEPOSITREQ_H_
#define _BOOLDEPOSITREQ_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ProcessDepositReq(hash_t *hContext, hash_t *hRequest);
int EditDepositReq(hash_t *hContext);

#ifdef __cplusplus
}
#endif

#endif
