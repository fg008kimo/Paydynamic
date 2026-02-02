#ifndef _OL_PSP_TXN_BAL_RULE_H_
#define _OL_PSP_TXN_BAL_RULE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBalRule(const int iRuleId, hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
