#ifndef _MERCH_STAT_H_
#define _MERCH_STAT_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int AddByTxnId(const char *csTxnId);

#ifdef __cplusplus
}
#endif

#endif
