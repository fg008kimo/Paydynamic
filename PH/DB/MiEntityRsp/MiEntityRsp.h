#ifndef _MI_ENTITY_RSP_H_
#define _MI_ENTITY_RSP_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetRSPInfoByEntityId(const char* csEntityId, 
			hash_t* hRec);
int GetRSPAcctInfoByEntityId(const char* csEntityId, 
			     recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
