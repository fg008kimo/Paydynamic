#ifndef _MIOLADJUSTMENTTYPE_H
#define _MIOLADJUSTMENTTYPE_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMaxCode(const char *csEntityType,
                     int *csMaxCodeInNum);
int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int GetMiOLAdjustmentTypeRec(const char *csEntityType,
                             const char *csCode ,
                             recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
