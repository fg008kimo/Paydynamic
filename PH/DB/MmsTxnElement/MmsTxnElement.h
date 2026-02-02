#ifndef _MMS_TXN_ELEMENT_H_
#define _MMS_TXN_ELEMENT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int AddDetail(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
