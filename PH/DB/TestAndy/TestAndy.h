#ifndef _TEST_ANDY_H_
#define _TEST_ANDY_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Add(const hash_t * hRls);
int GetByBankCode(const char * csBankCode, hash_t * hRec);
int GetByType(const char cType, recordset_t * myRec);
int Update(const hash_t * hRls);

#ifdef __cplusplus
}

#endif
#endif
