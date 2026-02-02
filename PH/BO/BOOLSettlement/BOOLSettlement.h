#ifndef _BOOLSETTLEMENT_H_
#define _BOOLSETTLEMENT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ProcessSettlementTxn(hash_t *hContext,
                hash_t* hRequest,
		hash_t* hResponse);

#ifdef __cplusplus
}
#endif

#endif
