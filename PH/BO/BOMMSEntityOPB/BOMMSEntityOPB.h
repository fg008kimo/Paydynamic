#ifndef _BOMMSENTITYOPB_H_
#define _BOMMSENTITYOPB_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int AddRecord (hash_t* hData);
int UpdateRecord (hash_t* hData);
int FindRecordExists (hash_t* hData);

#ifdef __cplusplus
}
#endif

#endif

