#ifndef _OL_TXN_ENGINE_SPC_ACTION_H_
#define _OL_TXN_ENGINE_SPC_ACTION_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetTxnEngineSpcAction(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
