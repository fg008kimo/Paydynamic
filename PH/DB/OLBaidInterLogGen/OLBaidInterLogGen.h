#ifndef _OL_BAID_INTER_LOG_GEN_H_
#define _OL_BAID_INTER_LOG_GEN_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetDetail(const unsigned long lBatchId, recordset_t* myRec);
int UpdateByStmtTxnId(const hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
