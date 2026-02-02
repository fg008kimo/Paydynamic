#ifndef _TXNELEMENTS_H_
#define _TXNELEMENTS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int GetFeeChgDetailByType(const char* csTxnID,
                const char* csElementType,
                const char cPartyType,
                recordset_t* myRec);

int GetAllFeeChgDetail(const char* csTxnID,
                recordset_t* myRec);

int UpdateElement(const hash_t *hRls);
#ifdef __cplusplus
}
#endif

#endif
