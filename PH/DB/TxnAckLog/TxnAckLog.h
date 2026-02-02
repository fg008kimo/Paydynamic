#ifndef _TXNACKLOG_H_
#define _TXNACKLOG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t* hRls);

int GetAckLog(const unsigned char *csBatchTxnSeq,
             recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
