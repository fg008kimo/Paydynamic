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
int DeleteByBatch(const hash_t *hRls);
int MatchRespTxn(const char* csTxnSeq);
int GetReturnDetailByStatus_ForUpdate(const char* csUploadTxnId, const int iStatus,recordset_t* myRec);
int GetInvalidSplitReturn(const int iBatchId, recordset_t* myRec);
int GetGenIdByUploadId(const int iBatchId, const char* csTxnId, recordset_t* myRec);
int DeleteByTxnId(const char* csTxnId);
int GetReturnDetailByStatus_API_ForUpdate(const char* csUploadTxnId, const int iStatus,recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
