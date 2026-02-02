#ifndef _MMSTRANSACTION_H_
#define _MMSTRANSACTION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int AddHeader(const hash_t *);
int UpdateHeader(const hash_t *hRls);
int AddDetail(hash_t *hRls);
int UpdateDetail(const hash_t *hRls);

int GetMaxDetailSeq(const char *csTxnSeq,
                    char *csDtlTxnSeq);

int  CheckTxnPending(const char *csTxnSeq, const char *csDtlTxnSeq);
#ifdef __cplusplus
}
#endif

#endif
