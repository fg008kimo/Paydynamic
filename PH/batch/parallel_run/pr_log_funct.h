#ifndef	_PR_LOG_FUNCT_H_
#define	_PR_LOG_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Txn_Header_Add(const hash_t *hRls);
int Txn_Header_Update(const hash_t *hRls);
int Header_AddTxnStatusLog(const hash_t *hCon);
int Txn_Detail_AddDetail(const hash_t *hRls);
int Txn_Detail_UpdateDetail(const hash_t *hRls);

int TxnPspDetail_Add(const hash_t *hRls);
int TxnPspDetail_Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif

