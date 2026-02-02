#ifndef _PSP_URL_H_
#define _PSP_URL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int Add(const hash_t* hPspUrl);
int Delete(const unsigned char* psp_id, const unsigned char* url);
int GetPspUrl(const char* csPspId, hash_t* hRec);
int IsRedirectURL(const char* csPspId);
int UpdatePspUrl(const hash_t* hPspUrl);

#ifdef __cplusplus
}
#endif

#endif
