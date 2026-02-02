#ifndef _PAY_SELECTION_H_
#define _PAY_SELECTION_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
//int Delete(const char* batch_id, const char* merchant_ref);

//int GetPayoutRecord(const char* csBatchId, const char* csMerchId, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
