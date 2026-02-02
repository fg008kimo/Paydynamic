#ifndef _BOIPREGION_H_
#define _BOIPREGION_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ConvertIp(const char* csIpAddr, hash_t* hRec);
int IsSupportPspIp(const char* csPspId, const char* csIpAddr);

#ifdef __cplusplus
}
#endif

#endif
