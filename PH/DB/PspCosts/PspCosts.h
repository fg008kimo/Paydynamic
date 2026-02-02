#ifndef _PSP_COSTS_H_
#define _PSP_COSTS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int GetPspCosts(const char* csPspId,
                const char  cType,
                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
