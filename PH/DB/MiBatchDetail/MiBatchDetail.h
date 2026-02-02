#ifndef _MI_BATCH_DT_H_
#define _MI_BATCH_DT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetOrgBatchIdByTxnId(const char* csTxnId, char cOperInd, hash_t* hDtl);
int GetAllDetailByTxnId(hash_t* myHash, recordset_t* myRec);
int GetSingleDetailByTxnId(hash_t* myHash, recordset_t* myRec);
int GetLastBatchIdByTxnId(const char* csTxnId, hash_t* hDtl);
int GetAllDetailByBatchId(const char* csBatchId, recordset_t* myRec);
int GetInitBatchDtByTxnId(const char* csTxnId, hash_t* hDtl);

#ifdef __cplusplus
}
#endif

#endif
