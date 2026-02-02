#ifndef _TXN_SET_CONTRIBUTORS_H_
#define _TXN_SET_CONTRIBUTORS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetContributors(const char* csTxnID, recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
