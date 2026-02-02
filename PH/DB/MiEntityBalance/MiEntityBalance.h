#ifndef _MIENTITYBALANCE_H
#define _MIENTITYBALANCE_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Update(const hash_t *hRec);
int GetEntityBalanceForUpdate(const hash_t *hRec, hash_t *myHash);
int GetEntityBalance(const hash_t *hRec, hash_t *myHash);

#ifdef __cplusplus
}
#endif

#endif
