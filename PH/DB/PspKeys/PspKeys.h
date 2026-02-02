#ifndef _PSP_KEYS_H_
#define _PSP_KEYS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int Add(const hash_t* hPspKeys);
int Delete(const char* psp_id,const char* key);
int GetPspKey(const char* csPspID,const char* csKey,recordset_t* myRec);
int UpdatePspKey(const hash_t* hPspKeys);

#ifdef __cplusplus
}
#endif

#endif
