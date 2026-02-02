#ifndef _OL_CHANNEL_KEYS_H_
#define _OL_CHANNEL_KEYS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetChannelKey(const char* csChannel, const char *csEncType, const char* csKeyVersion, hash_t *hOut);

#ifdef __cplusplus
}
#endif

#endif
