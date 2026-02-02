#ifndef _MMSENTITYBALANCE_H
#define _MMSENTITYBALANCE_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Update(const hash_t *hRec);
int GetNatureBalance(const hash_t *hRec, hash_t *myHash);
int GetNatureBalanceForUpdate(const hash_t *hRec, hash_t *myHash);
int InitBalance(const hash_t *hRec, hash_t *myHash);

#ifdef __cplusplus
}
#endif

#endif
