#ifndef _PSP_REDIRECT_SETTING_H_
#define _PSP_REDIRECT_SETTING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char *csPspId,
 	 hash_t *myHash);
int GetGlobal(hash_t *myHash);


#ifdef __cplusplus
}
#endif

#endif
