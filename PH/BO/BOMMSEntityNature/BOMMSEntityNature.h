#ifndef _BOMMSENTITYNATURE_H_
#define _BOMMSENTITY_NATUREH_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int FindEntityNatureId(hash_t* hContext);
int NewEntityNatureId(recordset_t* rRec, char* csNatureId);

#ifdef __cplusplus
}
#endif

#endif
