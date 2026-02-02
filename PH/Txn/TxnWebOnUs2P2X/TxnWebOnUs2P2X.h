#ifndef _TXNWEBONUS2P2X_H_
#define _TXNWEBONUS2P2X_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int   Encrypt(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse);
int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
