#ifndef _MOB_SEGMENT_THRESHOLD_H_
#define _MOB_SEGMENT_THRESHOLD_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetThreshold(const char* csGroup,
		 hash_t * hTxn);

int Update(const char* csGroup,const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
