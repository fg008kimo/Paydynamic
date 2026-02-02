#ifndef _MMS_ENTITY_OPB_H_
#define _MMS_ENTITY_OPB_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int FindRecordExists(hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
