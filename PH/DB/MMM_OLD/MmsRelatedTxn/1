#ifndef _MMSRELATEDTXN_H_
#define _MMSRELATEDTXN_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetPrevId(const char *csTxnID,
	      const char *csDtlTxnID,
	      recordset_t* myRec);

int GetNextId(const char *csTxnID,
	      const char *csDtlTxnID,
	      recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
