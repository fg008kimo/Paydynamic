#ifndef _OL_TXN_ENGINE_H_
#define _OL_TXN_ENGINE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetTxnEngine(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
