#ifndef _MI_ENTITY_OPB_H_
#define _MI_ENTITY_OPB_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetOPBInfoByBankId(const char* csBankId,
                hash_t* hRec);
int GetOPBInfoByEntityId(const char* csEntityId, 
		hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
