#ifndef _PAYOUT_QUEUE_DT_H_
#define _PAYOUT_QUEUE_DT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetPayoutRecord(const char* csBatchId, const char* csSeq, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
#ifdef __cplusplus
}
#endif

#endif
