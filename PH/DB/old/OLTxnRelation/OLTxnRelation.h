#ifndef _OL_TXN_RELATION_H_
#define _OL_TXN_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hTxnRelation);

int GetTxnRelation(const char *csTxnID,
                const char *csPartyType,
                const char *csGetDirection,
                recordset_t *myRec);


#ifdef __cplusplus
}
#endif

#endif
