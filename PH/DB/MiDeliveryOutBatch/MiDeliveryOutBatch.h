#ifndef _MIDELIVERYOUTBATCH_H_
#define _MIDELIVERYOUTBATCH_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetDetailByBatchId(const char* csBatchId, recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
