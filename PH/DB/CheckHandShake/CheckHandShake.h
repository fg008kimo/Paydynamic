#ifndef _CHECK_HAND_SHAKE_H_
#define _CHECK_HAND_SHAKE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetThresholdByMID(const char *csMerchantId, recordset_t *rRec);
int UpdateThresholdByMID(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
