#ifndef _CRR_JNL_H_
#define _CRR_JNL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetJnlTxn(const char* csFunctionName,
                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
