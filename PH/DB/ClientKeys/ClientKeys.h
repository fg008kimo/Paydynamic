#ifndef _CLIENT_KEYS_H_
#define _CLIENT_KEYS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetClientKey(const char* csClientID,const char* csKey,recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
