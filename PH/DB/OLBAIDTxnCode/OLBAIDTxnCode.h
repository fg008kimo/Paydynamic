#ifndef _OLBAID_TXN_CODE_H_
#define _OLBAID_TXN_CODE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetDetail(const char* csTxnCode, const char* csBankAcctType, hash_t* myHash);
int IsVoidable(const unsigned char* csTxnCode);
int GetBAIDTxnCodeDtl(const char* csTxnCode, hash_t* myHash);
int IsUnknownTxn(const unsigned char* csTxnCode);


#ifdef __cplusplus
}
#endif

#endif
