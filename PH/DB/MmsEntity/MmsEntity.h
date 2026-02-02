#ifndef _MMS_ENTITY_H_
#define _MMS_ENTITY_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetEntityId(char* csEntityId,
                hash_t* hRec);
int GetACRType(const char* csEntityId, char* csType);

#ifdef __cplusplus
}
#endif

#endif
