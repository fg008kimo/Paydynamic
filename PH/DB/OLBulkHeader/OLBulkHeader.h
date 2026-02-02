#ifndef _OLBULKHEADER_H_
#define _OLBULKHEADER_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Get(const char* csBatchId, const char* csTxnCode, hash_t* hRec);
int Update(const hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
