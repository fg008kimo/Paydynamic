#ifndef _MMS_ENTITY_FX_BAL_HISTORY_H_
#define _MMS_ENTITY_FX_BAL_HISTORY_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetFXBalHistory(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
