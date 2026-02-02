#ifndef _MERCHANT_APPROVE_QUEUE_HD_H_
#define _MERCHANT_APPROVE_QUEUE_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetWaitingApproveHd(const char cStatus, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
int UpdateSuccCnt(const hash_t *hRls);

int Add(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
