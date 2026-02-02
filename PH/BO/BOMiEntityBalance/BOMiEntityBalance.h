#ifndef _BOMIENTITYBALANCE_H_
#define _BOMIENTITYBALANCE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetEntityBalance(const hash_t *hRequest, hash_t* hResponse);
int GetEntityBalanceForUpdate(const hash_t *hRequest, hash_t* hResponse);

int UpdateEntityBalance(hash_t* hContext, const hash_t* hReq);

int CreditAcctBal(hash_t* hContext, const hash_t* hReq);
int DebitAcctBal(hash_t* hContext, const hash_t* hReq);
int CreditIntransit(hash_t* hContext, const hash_t* hReq);
int DebitIntransit(hash_t* hContext, const hash_t* hReq);
int CreditArBal(hash_t* hContext, const hash_t* hReq);
int DebitArBal(hash_t* hContext, const hash_t* hReq);


#ifdef __cplusplus
}
#endif

#endif
