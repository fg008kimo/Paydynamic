#ifndef _PAYOUT_QUEUE_HD_H_
#define _PAYOUT_QUEUE_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetPayoutQueueHd(const char cStatus, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
#ifdef __cplusplus
}
#endif

#endif
