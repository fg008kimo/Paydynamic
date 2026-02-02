#ifndef _MMS_KEYS_H_
#define _MMS_KEYS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMmsKey(const unsigned char *csNodeId,
		const unsigned char* csKeyName,
              hash_t *myHash);


#ifdef __cplusplus
}
#endif

#endif
