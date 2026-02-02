#ifndef _MIADJUSTMENTTYPE_H
#define _MIADJUSTMENTTYPE_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMaxCode(const char *csEntityType,
                     int *csMaxCodeInNum);
int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int GetMiAdjustmentTypeRec(const char *csEntityType,
                         const char *csCode ,
                         recordset_t *myRec);

int IsByProrata(const char *csEntityType,
		const char *csCode);
#ifdef __cplusplus
}
#endif

#endif
