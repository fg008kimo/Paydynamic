#ifndef _MMS_ENTITY_FX_BAL_H_
#define _MMS_ENTITY_FX_BAL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetFxBal(const hash_t *hRls, hash_t *myHash);
int GetFxBalForUpdate(const hash_t *hRls, hash_t *myHash);

#ifdef __cplusplus
}
#endif

#endif
