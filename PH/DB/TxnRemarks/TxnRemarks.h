#ifndef _TXNREMARKS_H_
#define _TXNREMARKS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Get(const char* csTxnId, int iSeq, hash_t* hRls);
int UpdateRemark(hash_t* hRls);

#ifdef __cplusplus
}
#endif

#endif
