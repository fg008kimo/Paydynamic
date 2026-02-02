#ifndef _OPKCHANNEL_H_
#define _OPKCHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

void OPKChannel(char);

int   process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);

#ifdef __cplusplus
}
#endif

#endif
