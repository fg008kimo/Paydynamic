#ifndef _MMSREVERSERETRY_H_
#define _MMSREVERSERETRY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t* hRls);
int GetPendingReverse(const int iMaxTry,
                recordset_t* myRec);
int CounterReset(const hash_t *hRls);
int FindMaxDtlID(const char *csTxnId, char *csDtlTxnId);

#ifdef __cplusplus
}
#endif

#endif
