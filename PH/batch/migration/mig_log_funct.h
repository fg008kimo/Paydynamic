#ifndef	_MIG_LOG_FUNCT_H_
#define	_MIG_LOG_FUNCT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int ml_Txn_Header_Add(const hash_t *hRls);
int ml_Txn_Header_Update(const hash_t *hRls);
int ml_Header_AddTxnStatusLog(const hash_t *hCon);
int ml_Header_AddTxnBrowserInfo(const hash_t *hCon);
int ml_Txn_Detail_AddDetail(const hash_t *hRls);
int ml_Txn_Detail_UpdateDetail(const hash_t *hRls);

int ml_TxnPspDetail_Add(const hash_t *hRls);
int ml_TxnPspDetail_Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif

