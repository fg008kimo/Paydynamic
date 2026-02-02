#ifndef _MMS_ENTITYNATUREMAP_H_
#define _MMS_ENTITYNATUREMAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const recordset_t* rRecordSet);
int Find(const recordset_t* rRecordSet, char* csNatureId);

#ifdef __cplusplus
}
#endif

#endif
