#ifndef _ACR_THRESHOLD_H_
#define _ACR_THRESHOLD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *);
int Update(const hash_t *);
int FindTolerance(const char* csCompWith,const char* csBankCcy,double* dTol);

#ifdef __cplusplus
}
#endif

#endif
