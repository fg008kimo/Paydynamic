#ifndef _MERCHANT_SETT_FLOAT_H_
#define _MERCHANT_SETT_FLOAT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *hRec);

int GetNextId(unsigned long *lId);


#ifdef __cplusplus
}
#endif

#endif
