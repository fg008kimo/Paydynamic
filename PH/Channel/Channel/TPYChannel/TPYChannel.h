#ifndef _TPYCHANNEL_H_
#define _TPYCHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int   process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);
#ifdef __cplusplus
}
#endif

#endif
