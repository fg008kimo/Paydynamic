#ifndef _CRR_JNL_DETAIL_H_
#define _CRR_JNL_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int GetNextLineNo(const char* csJnlId);

#ifdef __cplusplus
}
#endif

#endif
