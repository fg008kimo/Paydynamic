#ifndef _MMS_ADJUSTMENTTYPEENTITY_H_
#define _MMS_ADJUSTMENTTYPEENTITY_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);
int Find(hash_t* hRls);
int FindEntityType(const hash_t* hRls, recordset_t* rRecordSet);
int GetAdjustmentTypeEntityRec (const char *csCode, recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
