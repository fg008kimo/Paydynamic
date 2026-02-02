#ifndef _PAYOUT_RETURN_BATCH_DT_H_
#define _PAYOUT_RETURN_BATCH_DT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetPayoutRecord(const int iBatchId, const int iSeq, recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
