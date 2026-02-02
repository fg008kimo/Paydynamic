#ifndef _MMS_ENTITY_PSP_H_
#define _MMS_ENTITY_PSP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Sync(const hash_t *hRls);
int GetPspEntityId(const char* csNodeId,
                const char* csClientId,
                const char* csPspId,
                const char* csBAID,
                char* csEntityId,
		char* csNatureId);
int UpdateNatureIdByEntityId(const hash_t* hRls); 

int GetPspEntityIdInfo( char* csEntityId,hash_t* hRsp);

#ifdef __cplusplus
}
#endif

#endif
