#ifndef _OL_TXN_ENGINE_LINKAGE_H_
#define _OL_TXN_ENGINE_LINKAGE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetLinkageRule(const int iRuleId, hash_t* hTxn);

#ifdef __cplusplus
}
#endif

#endif
