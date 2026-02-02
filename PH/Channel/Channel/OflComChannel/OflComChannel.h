#ifndef _OFLCOMCHANNEL_H_
#define _OFLCOMCHANNEL_H_
#include "myhash.h"
#include "dbutility.h"

#ifdef __cplusplus
extern "C" {
#endif

int     doResponse(hash_t *hContext, hex_t *outMsg);
int     enBlock( hash_t *hContext,const hash_t *hResponse, hex_t *outMsg);
int     deBlock( hash_t *hContext, hash_t *hRequest, hash_t *hResponse,const char *inMsg, int inLen);
int     AddTxnReqRef(const hash_t *hContext, const hash_t* hRequest);
int     UpdateTxnReqRef(const hash_t *hContext, const hash_t *hRequest);
int     AddNonTxnMsgLog(const hash_t *hContext, const hash_t* hRequest);
int     UpdateNonTxnMsgLog(const hash_t *hContext, const hash_t *hRequest, hash_t* hResponse);
int     AddTxnLog(const hash_t *hContext, const hash_t *hRequest);
int     UpdateTxnLog(const hash_t *hContext, const hash_t* hRequest, hash_t* hResponse);
int     UpdateContext(hash_t* hContext);

#ifdef __cplusplus
}
#endif

#endif
