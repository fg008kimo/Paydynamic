#ifndef _MMS_ADJUSTMENTTYPE_H_
#define _MMS_ADJUSTMENTTYPE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int Find(hash_t* hRls);
int GetAdjustmentTypeRec(const char *csCode , hash_t *hRec);
int GetMaxCode(int *iMaxCodeInNum);

#ifdef __cplusplus
}
#endif

#endif
