#ifndef _OL_TXN_RELATION_H_
#define _OL_TXN_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetP1TxnId(const hash_t* hRls, recordset_t* rRecordSet);
int GetP2TxnId(const hash_t* hRls, recordset_t* rRecordSet);
int GetTxnRelationByBatchId(const hash_t* hRls, recordset_t* rRecordSet);
int FindVoidTxnCount(const hash_t* hRls);
int CheckIsBalTransBatch(const char *csBatchId);
int GetRelatedTxnId(const hash_t* hRls, recordset_t* rRecordSet);
int GetVoidTxnId(const hash_t* hRls, recordset_t* rRecordSet);
int CheckIsBalTransP1TxnId(const hash_t* hRls);
int CheckIsBalTransP2TxnId(const hash_t* hRls);
int CheckIsP1VoidTxnId(const hash_t* hRls);
int CheckIsP2VoidedTxnId(const hash_t* hRls);

#ifdef __cplusplus
}
#endif

#endif
