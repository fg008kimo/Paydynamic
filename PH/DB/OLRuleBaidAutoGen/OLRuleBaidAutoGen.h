#ifndef _OL_RULE_BAID_AUTO_GEN_H_
#define _OL_RULE_BAID_AUTO_GEN_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetCatTypeByAcctType(const char* csBankAcctType, recordset_t* rsCatType);

#ifdef __cplusplus
}
#endif

#endif
