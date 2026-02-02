#ifndef _CCTTXN_H_
#define _CCTTXN_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int FindPayMethodByMerchantRef(const unsigned char* MerchantRef, unsigned char* PayMethod);
int GetTxnId(const char* csMerchantId,
                const char* csMerchantRef,
                recordset_t* myRec);
int GetApprovated(const char* csMerchantId,
                const char* csMerchantRef);

#ifdef __cplusplus
}
#endif

#endif
