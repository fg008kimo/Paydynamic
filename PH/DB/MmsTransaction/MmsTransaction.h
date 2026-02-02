#ifndef _MMSTRANSACTION_H_
#define _MMSTRANSACTION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *hRls);
int GetTxnHeader(const char* csTxnID,
                recordset_t* myRec);

int AddDetail(const hash_t *hRls);
int UpdateDetail(const hash_t *hRls);
int GetTxnDetail(const char* csTxnID,
                recordset_t* myRec);

int MatchNodeRef(const char* csNodeID,
                     const char* csNodeRef);
int MatchTxnStatus(const hash_t* hReq);

int ChkTxnCodeExist(const char *csTxnCode);

#ifdef __cplusplus
}
#endif

#endif
