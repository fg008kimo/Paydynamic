#ifndef _BOMMSENTITYBALANCE_H_
#define _BOMMSENTITYBALANCE_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int SelectEntityBalanceForUpdate(hash_t *hContext, const hash_t* hReq);
int SelectNatureBalanceForUpdate(hash_t *hContext);

int CreditPrepaid(hash_t* hContext, const hash_t* hReq);
int DebitPrepaid(hash_t* hContext, const hash_t* hReq);

int CreditIntransit(hash_t* hContext, const hash_t* hReq);
int DebitIntransit(hash_t* hContext, const hash_t* hReq);

int CreditAcctBal(hash_t* hContext, const hash_t* hReq);
int DebitAcctBal(hash_t* hContext, const hash_t* hReq);

int CreditLien(hash_t* hContext, const hash_t* hReq);
int DebitLien(hash_t* hContext, const hash_t* hReq);

int UpdateNatureBalance(hash_t* hContext,const hash_t* hReq);
int GetNatureBalance(const hash_t* hContext, hash_t* hOut);


#ifdef __cplusplus
}
#endif

#endif
