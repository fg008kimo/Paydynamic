#ifndef _OLTXNELEMENTS_H_
#define _OLTXNELEMENTS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int Add(const hash_t *);
int Add(const hash_t *hRls);
int GetFeeChgDetailByType(const char* csTxnID,
                const char* csElementType,
                const char cPartyType,
                recordset_t* myRec);

int GetAllFeeChgDetail(const char* csTxnID,
                recordset_t* myRec);

int UpdateElement(const hash_t *hRls);


int GetElementTypeByAmt(const char* csTxnID,
                const double dAmt,
                hash_t* hTxn);
#ifdef __cplusplus
}
#endif

#endif
