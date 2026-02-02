#ifndef _OL_PAYOUT_RETURN_BATCH_HD_H_
#define _OL_PAYOUT_RETURN_BATCH_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int Update(const hash_t *hRls);
int GetNextBatchId(int *iBatchId);
#ifdef __cplusplus
}
#endif

#endif
