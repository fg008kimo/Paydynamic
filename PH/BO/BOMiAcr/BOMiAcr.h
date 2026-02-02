#ifndef _BOMIACR_H_
#define _BOMIACR_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetACRBal(const hash_t* hIn, hash_t* hOut);
int GetACRBalForUpdate(const hash_t* hIn, hash_t* hOut);
int CalculateACR(const hash_t* hIn);

#ifdef __cplusplus
}
#endif

#endif
