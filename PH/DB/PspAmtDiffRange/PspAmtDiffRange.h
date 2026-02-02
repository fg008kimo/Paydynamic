#ifndef _PSP_AMT_DIFF_RANGE_H_
#define _PSP_AMT_DIFF_RANGE_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Find(const char *csPspId, hash_t *hRec);
int Update(const hash_t *hIn);

#ifdef __cplusplus
}

#endif
#endif
