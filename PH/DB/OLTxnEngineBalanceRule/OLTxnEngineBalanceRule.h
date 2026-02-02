#ifndef _OL_TXN_ENGINE_BALANCE_RULE_H_
#define _OL_TXN_ENGINE_BALANCE_RULE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBalRule(const int iRuleId, hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
