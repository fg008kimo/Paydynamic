#ifndef _PAYOUT_RETURN_BATCH_HD_H_
#define _PAYOUT_RETURN_BATCH_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetPayoutReturnBatchHd(const int iBatchId, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
int GetNextBatchId(unsigned long *lBatchId);
#ifdef __cplusplus
}
#endif

#endif
