#ifndef _CCTCHANNEL_H_
#define _CCTCHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

void CCTChannel(char);

int   process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);
int     process_psp_resp_txn(hash_t *hContext,
                                const hex_t* inMsg,
                                hex_t *outMsg);

int     UpdateRespTxnLog(hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
