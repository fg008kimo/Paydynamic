#ifndef _SYSTEM_EX_RULES_H_
#define _SYSTEM_EX_RULES_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindCode(const unsigned char* csTxnCode,recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
