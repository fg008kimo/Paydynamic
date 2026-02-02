#ifndef _TXNMGTBYUSCFR_H_
#define _TXNMGTBYUSCFR_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int   Authorize(hash_t* hContext,
                const hash_t* hRequest,
                hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
