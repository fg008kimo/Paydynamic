#ifndef _CRR_JNL_CHANGE_LOG_H_
#define _CRR_JNL_CHANGE_LOG_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetNextCrrJnlChangeLogID();

#ifdef __cplusplus
}
#endif

#endif
