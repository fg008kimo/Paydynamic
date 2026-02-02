#ifndef _PAYOUR_APPROVE_TMP_H_
#define _PAYOUR_APPROVE_TMP_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetDetailBySelectedTxn(const hash_t *hTxn, recordset_t* myRec);
int GetOrgBatchId(hash_t *hTxn);
#ifdef __cplusplus
}
#endif

#endif
