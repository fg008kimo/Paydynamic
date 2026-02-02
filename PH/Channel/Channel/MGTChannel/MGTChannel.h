#ifndef _MGTCHANNEL_H_
#define _MGTCHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int   process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);
int     AddTxnFeeChgLog(hash_t* hContext);
int     UpdateContext(hash_t* hContext);
int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest);
int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);
int     UpdateTxnDetailLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);

int     AddRemarkLog(const hash_t *hContext, 
                     const hash_t *hRequest);

#ifdef __cplusplus
}
#endif

#endif
