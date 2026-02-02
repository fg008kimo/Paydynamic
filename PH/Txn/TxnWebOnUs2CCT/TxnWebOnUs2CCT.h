#ifndef _TXNWEBONUS2CCT_H_
#define _TXNWEBONUS2CCT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif
int     Request(hash_t* hContext,
                        unsigned char* inBuf,
                        int iLen,
                        unsigned char* outBuf,
                        int *Len);
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
