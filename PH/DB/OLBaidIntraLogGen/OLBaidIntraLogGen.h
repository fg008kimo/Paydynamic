#ifndef _OL_BAID_INTRA_LOG_GEN_H_
#define _OL_BAID_INTRA_LOG_GEN_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int GetDetailByBatchId(const unsigned long lBatchId, recordset_t *rRec);
int GetDetailByTxnId(hash_t *hRec);
int UpdateByStmtTxnId(const hash_t *hIn);
int UpdateByTxnTxnId(const hash_t *hIn);

#ifdef __cplusplus
}

#endif
#endif
