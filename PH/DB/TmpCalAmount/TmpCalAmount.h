#ifndef _TMP_CAL_AMT_H_
#define _TMP_CAL_AMT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetTmpCalAmount(const char* csTxnID,
                    hash_t* myHash);
#ifdef __cplusplus
}
#endif

#endif
