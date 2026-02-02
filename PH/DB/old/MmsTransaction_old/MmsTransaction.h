#ifndef _MMSTRANSACTION_H_
#define _MMSTRANSACTION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int AddHeader(const hash_t *);
int UpdateHeader(const hash_t *hRls);

int AddDetail(const hash_t *hRls);
int UpdateDetail(const hash_t *hRls);

int GetMmsTxnHeader(const char* csTxnID,
                    recordset_t* myRec);

int GetTxnDetail(const char* csTxnID,
                 recordset_t* myRec);


#ifdef __cplusplus
}
#endif

#endif
