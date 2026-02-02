#ifndef _TXNWEBONUS2TPY_H_
#define _TXNWEBONUS2TPY_H_
#include "myhash.h"
#define	PD_OK_STATUS	"OK"

#ifdef __cplusplus
extern "C" {
#endif
int   Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
