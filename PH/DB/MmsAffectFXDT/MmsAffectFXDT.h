#ifndef _MMS_AFFECT_FX_DT_H_
#define _MMS_AFFECT_FX_DT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetAffectFXDT(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
