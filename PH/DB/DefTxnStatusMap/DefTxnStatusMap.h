#ifndef _DEF_TXN_STATUS_MAP_H_
#define _DEF_TXN_STATUS_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Delete(const hash_t *hRls);


#ifdef __cplusplus
}
#endif

#endif
