#ifndef _OFFSET_TXN_TYPE_H_
#define _OFFSET_TXN_TYPE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int GetOffsetTxnTypeRec(const char cPartyType,
                                const char *csTxnCode ,
                                recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
