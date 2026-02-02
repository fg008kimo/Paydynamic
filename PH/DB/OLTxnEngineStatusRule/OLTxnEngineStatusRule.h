#ifndef _OL_TXN_ENGINE_STATUS_RULE_H_
#define _OL_TXN_ENGINE_STATUS_RULE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetStatusRule(const int iRuleId, hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
