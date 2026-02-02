#ifndef _BOMMSENTITYBALACCT_H_
#define _BOMMSENTITYBALACCT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int CheckEntityBalAcct(hash_t* hContext,
                const hash_t* hReq);

int AddRecord(hash_t* hData);

#ifdef __cplusplus
}
#endif

#endif
