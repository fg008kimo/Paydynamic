#ifndef _MOB_SEGMENT_CTL_H_
#define _MOB_SEGMENT_CTL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Update(const char* csGroup,const hash_t *hRls);

int GetControl(const char* csGroup,
                 hash_t * hTxn);
#ifdef __cplusplus
}
#endif

#endif
