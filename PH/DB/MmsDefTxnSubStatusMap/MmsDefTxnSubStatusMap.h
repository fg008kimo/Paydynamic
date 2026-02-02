#ifndef _MMS_DEF_TXN_SUB_STATUS_MAP_H_
#define _MMS_DEF_TXN_SUB_STATUS_MAP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Delete(const hash_t *hRls);
int ChkTxnCodeExist(const char *csTxnCode);


#ifdef __cplusplus
}
#endif

#endif
