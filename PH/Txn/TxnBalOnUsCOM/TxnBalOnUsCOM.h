#ifndef _TXNBALONUSCOM_H_
#define _TXNBALONUSCOM_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int	Authorize(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse);
int	SendToQueue(hash_t *hMsg);
int     DoLogging(hash_t *hIn);

#ifdef __cplusplus
}
#endif

#endif
