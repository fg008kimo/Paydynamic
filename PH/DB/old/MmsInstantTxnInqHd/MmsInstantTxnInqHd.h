#ifndef _MMS_INSTANT_TXN_INQ_HD_H_
#define _MMS_INSTANT_TXN_INQ_HD_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *hRls);

/*
int ChkValidHeader(const hash_t *hRls);
*/

#ifdef __cplusplus
}
#endif

#endif
