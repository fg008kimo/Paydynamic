#ifndef _MMSENTITYBALACCT_H
#define _MMSENTITYBALACCT_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif
int Add(const hash_t *hRec);
int Update(const hash_t *hRec);
int GetEntityBalAcct(const hash_t *hRec, hash_t *myHash);

#ifdef __cplusplus
}
#endif

#endif
