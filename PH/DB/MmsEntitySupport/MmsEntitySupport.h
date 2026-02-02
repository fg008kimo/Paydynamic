#ifndef _MMS_ENTITY_SUPPORT_H_
#define _MMS_ENTITY_SUPPORT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetEntitySupport(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
