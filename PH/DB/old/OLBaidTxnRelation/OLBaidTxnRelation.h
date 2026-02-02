#ifndef _OL_BAID_TXN_RELATION_H_
#define _OL_BAID_TXN_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hReconRelation);

int GetRelationByTxn(const char *csTxnID,
                recordset_t *myRec);

int GetRelationByBaidTxn(const char *csBaidTxnID,
                recordset_t *myRec);


#ifdef __cplusplus
}
#endif

#endif
