#ifndef _DEF_SERVICECODE_H_
#define _DEF_SERVICECODE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetServiceCodeDetail(const char* csServiceCode,recordset_t* myRec);
int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
