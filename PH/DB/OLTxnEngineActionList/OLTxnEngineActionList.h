#ifndef _OL_TXN_ENGINE_ACTION_LIST_H_
#define _OL_TXN_ENGINE_ACTION_LIST_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetTxnEngineActionList(const int iActionDetailId, hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
