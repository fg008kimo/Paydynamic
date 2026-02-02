#ifndef _OL_BATCH_RELATION_H_
#define _OL_BATCH_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetOrgBatchIdByBatchId(const char* csBatchId, recordset_t* rRecordSet);
int GetBatchIdByOrgBatchId(const char* csOrgBatchId, recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
