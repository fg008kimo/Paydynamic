#ifndef _MI_BATCH_HEADER_H_
#define _MI_BATCH_HEADER_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetBatchHeader(const char* csBatchId, hash_t* hRec);
int Update(const hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
