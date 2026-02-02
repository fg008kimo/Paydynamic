#ifndef _SERVICE_FEE_MAPPING_H_
#define _SERVICE_FEE_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetFeeType(const hash_t *hRec, char* csOutputFeeType);

#ifdef __cplusplus
}
#endif

#endif
