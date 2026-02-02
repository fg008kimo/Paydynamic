#ifndef _BOMMSTRANSACTION_H_
#define _BOMMSTRANSACTION_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest);
int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);

int     UpdateTxnHd(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);
int UpdateRelatedTxnSubStatus(char cMode,const char* csTxnId,double dRemainingAmt);

int GetTxnInfo(const char* csTxnId, hash_t* hRsp);

#ifdef __cplusplus
}
#endif

#endif
