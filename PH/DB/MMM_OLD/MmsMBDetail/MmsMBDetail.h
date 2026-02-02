#ifndef _MMS_MB_DETAIL_H_
#define _MMS_MB_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMBDetail(const char* csMBId,
               hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
