#ifndef _OIACHANNEL_H_
#define _OIACHANNEL_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

void OIAChannel(char);

int   process_txn(hash_t *hContext,
                 	const hex_t* inMsg,
                        hex_t *outMsg);
#ifdef __cplusplus
}
#endif

#endif
