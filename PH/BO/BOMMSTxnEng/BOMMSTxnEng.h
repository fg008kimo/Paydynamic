#ifndef _BOMMSTXNENG_H_
#define _BOMMSTXNENG_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int RemitTxn(hash_t* hContext,const hash_t* hReq);
int RecvTxn(hash_t* hContext,const hash_t* hReq);

int RemoveFromIntransitForRecv(hash_t* hContext,const hash_t* hRequest);

#ifdef __cplusplus
}
#endif

#endif
