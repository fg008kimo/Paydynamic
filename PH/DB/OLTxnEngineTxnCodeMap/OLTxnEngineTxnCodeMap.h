#ifndef _OL_TXN_ENGINE_TXNCODE_MAP_H_
#define _OL_TXN_ENGINE_TXNCODE_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int GetNewTxnCode(const int iActionDetailId, const char *csOrgTxnCode, hash_t* hRec);
int GetNewTxnCode(const int iActionDetailId, 
		  const char *csFromAcctType, 
		  const char *csToAcctType, 
		  const char *csOrgTxnCode, 
		  hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
