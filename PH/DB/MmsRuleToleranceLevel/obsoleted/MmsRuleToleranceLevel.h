#ifndef _MMS_RULE_TOLERANCE_LEVEL_H_
#define _MMS_RULE_TOLERANCE_LEVEL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateByTxnCode(const hash_t *hRls);
int DeleteByTxnCode(const hash_t *hRls);
int ChkTxnCodeExist(const char *csTxnCode);

#ifdef __cplusplus
}
#endif

#endif
