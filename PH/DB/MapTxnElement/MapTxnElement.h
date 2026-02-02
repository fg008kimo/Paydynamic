#ifndef _MAP_TXN_ELEMENT_H_
#define _MAP_TXN_ELEMENT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Delete (const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
