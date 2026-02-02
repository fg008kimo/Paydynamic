#ifndef _OLSTMTFORMAT_H_
#define _OLSTMTFORMAT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetFormat(const char* csIntBankCode, recordset_t* myRec);
int GetTxnCodeKeywords(const char* csIntBankCode, const char* csFormatID, const char* csBankAcctType,
		recordset_t* myRec);
int GetRestrictKeywords(const char* csIntBankCode, const char* csFormatID,
		recordset_t* myRec);

int AddKeywords(const hash_t *hRls);
int UpdateKeywords(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
