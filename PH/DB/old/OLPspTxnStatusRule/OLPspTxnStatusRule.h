#ifndef _OL_PSP_TXN_STATUS_RULE_H_
#define _OL_PSP_TXN_STATUS_RULE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetStatusRule(const int iRuleId, hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
