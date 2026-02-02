#ifndef _MI_ACR_INOUT_HISTORY_H_
#define _MI_ACR_INOUT_HISTORY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t* hRls);
int GetOverviewByBatchId(const char *csBatchId, recordset_t* myRec);
int IsLastBatchInOverview(const char *csBatchId);
int GetOverviewHistory(const char *csFromCcy, const char *csBankCcy, const int iPeriod, recordset_t* myRec);
int IsLastBatchInOverviewByCcy(const char *csBatchId, const char *csFromCcy, const char *csBankCcy);

#ifdef __cplusplus
}
#endif

#endif
