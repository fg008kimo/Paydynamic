#ifndef _TXNACKRETRY_H_
#define _TXNACKRETRY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t* hRls);
int GetPendingAck(const int iMaxTry,
                recordset_t* myRec);
int CounterReset(const hash_t *hRls);
int FindMaxBatchID(const char *csTxnId, char *csBatchTxnId);
int GetResendCount(const char *csTxnId, int *iResendCnt);

#ifdef __cplusplus
}
#endif

#endif
