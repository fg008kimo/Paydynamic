#ifndef _BOMMSENTITY_H_
#define _BOMMSENTITY_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetPspEntityId(hash_t* hContext,
                const hash_t* hData);
int GetEntityId(const char* csEntityId,hash_t* hReq);

int AddRecord(hash_t* hData);
int UpdateRecord(hash_t* hData);

#ifdef __cplusplus
}
#endif

#endif

