#ifndef _TXNEXDETAIL_H_
#define _TXNEXDETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Get(const char *csTxnId, hash_t *hRec);

#ifdef __cplusplus
}
#endif

#endif
