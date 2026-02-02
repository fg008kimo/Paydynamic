#ifndef _MMMCHANNEL_H_
#define _MMMCHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int	process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);

int	process_input_txn(hash_t *hContext,
                                const hash_t *hRequest,
                                hash_t *hResponse);

int     UpdateContext(hash_t* hContext);

#ifdef __cplusplus
}
#endif

#endif
