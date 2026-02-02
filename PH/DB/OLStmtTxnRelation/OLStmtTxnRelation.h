#ifndef _OL_STMT_TXN_RELATION_H_
#define _OL_STMT_TXN_RELATION_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetStmtTxnIdByTxnId(const unsigned char* csTxnId, unsigned char* csStmtTxnId);
int GetTxnIdByStmtTxnId(const unsigned char* csStmtTxnId, unsigned char* csTxnId);
int GetMultiTxnIdByStmtTxnId(const unsigned char* csStmtTxnId, recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
