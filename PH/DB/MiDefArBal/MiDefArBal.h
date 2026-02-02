#ifndef _MI_DEF_AR_BAL_H_
#define _MI_DEF_AR_BAL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetArBalParameter(const char* csCode, hash_t* hRec);
int GetArBalParameterByTxnCode(const char* csTxnCode, hash_t* hRec);



#ifdef __cplusplus
}
#endif

#endif
