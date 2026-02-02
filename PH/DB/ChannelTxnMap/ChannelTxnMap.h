#ifndef _CHANNEL_TXN_MAP_H_
#define _CHANNEL_TXN_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add (const hash_t *hRls);

int Update(const hash_t *hRls);

int Delete (const hash_t *hRls);

int GetTxnCodeByApplyMode(const char* csMode, recordset_t* myRec);
int IsApplyUniqueNum(const char* csChannel, const char* csTxnCode, int* iApplyMerch, int* iApplyPsp);
#ifdef __cplusplus
}
#endif

#endif
