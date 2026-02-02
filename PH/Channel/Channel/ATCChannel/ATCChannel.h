#ifndef _ATCCHANNEL_H_
#define _ATCCHANNEL_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

void ATCChannel(char);
int process_txn(hash_t *hContext,
		const hex_t *inMsg,
		hex_t *outMsg);

#ifdef __cplusplus
}
#endif

#endif
