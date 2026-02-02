#ifndef _OL_BATCH_TXN_RELATION_H_
#define _OL_BATCH_TXN_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetTxnId(const hash_t* hRls, recordset_t* rRecordSet);
int GetBatchId(const hash_t* hRls, recordset_t* rRecordSet);
int GetNumOfBatchId(hash_t* hRls);
int CheckIsHoldDepositBatch(const char *csBatchId);
int CheckIsPSPSettlementBatch(const char *csBatchId);
int CheckIsProviderChargeBatch(const char *csBatchId);
int CheckIsInputTxnId(const hash_t* hRls);
int CheckIsRegenTxnId(const hash_t* hRls);
int GetBatchTypeInfo(hash_t* hRls);
int GetBatchIdByRTAscOrder(const hash_t* hRls, recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
