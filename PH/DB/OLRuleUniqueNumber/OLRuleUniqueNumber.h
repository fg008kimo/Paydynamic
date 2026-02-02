#ifndef _OL_RULE_UNIQUE_AMT_H_
#define _OL_RULE_UNIQUE_AMT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetOLRuleUniqueNumber(const char* csTxnCode,
                          const char* csPartyType,
                          const char* csPartyId,
                          hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
