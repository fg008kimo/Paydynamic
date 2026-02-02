#ifndef _TXNFEECHG_H_
#define _TXNFEECHG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetFeeChgDetailByType(const char* csTxnID,
                const char cPartyType,
                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
