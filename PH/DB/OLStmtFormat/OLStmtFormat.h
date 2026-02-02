#ifndef _OLSTMTFORMAT_H_
#define _OLSTMTFORMAT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetFormat(const char* csIntBankCode, recordset_t* myRec);
int GetByFormatId(const char* csFormatId, recordset_t* myRec);
int GetTxnCodeKeywords(const hash_t* hContext, recordset_t* myRec);
int GetTxnCodeKeywordsSingle(const hash_t* hContext, recordset_t* myRec);
int GetTxnCodeKeywordsAll(const hash_t* hContext, recordset_t* myRec);
int AddKeywords(hash_t *hRls);
int UpdateKeywords(hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
