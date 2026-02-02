#ifndef _MERCHANT_APPROVE_QUEUE_DT_H_
#define _MERCHANT_APPROVE_QUEUE_DT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetWaitingApproveDt(const int iApproveId, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
int Add(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
