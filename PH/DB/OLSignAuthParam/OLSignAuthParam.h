#ifndef _OL_SIGN_AUTH_PARAM_H_
#define _OL_SIGN_AUTH_PARAM_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetParam(const char* csChannelCode,
             const char* csTxnCode,
	     const char* csVer,
	     const char cDirection,
             recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
