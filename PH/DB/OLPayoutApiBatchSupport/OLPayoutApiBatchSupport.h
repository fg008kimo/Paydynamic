#ifndef _OL_PAYOUT_API_BATCH_SUPPORT_H_
#define _OL_PAYOUT_API_BATCH_SUPPORT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int Get(const char *csTxnCode, hash_t *hRec);
int Update(const hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
