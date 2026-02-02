#ifndef _MI_ENTITY_PIT_H_
#define _MI_ENTITY_PIT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetPITInfoByEntityId(const char* csEntityId, 
			 hash_t* hRec);
int GetPITAcctInfoByEntityId(const char* csEntityId, 
			     recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
