#ifndef _CRR_PSP_PRODUCT_CODE_MAP_H_
#define _CRR_PSP_PRODUCT_CODE_MAP_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int Add(const hash_t *hCrrPspProductCodeMap);

int GetPSPProductCode(const hash_t *hRec,
			hash_t *myHash);

#ifdef __cplusplus
}
#endif

#endif
