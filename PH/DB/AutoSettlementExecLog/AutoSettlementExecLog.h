#ifndef _AUTO_SETTLEMENT_EXEC_LOG_H_
#define _AUTO_SETTLEMENT_EXEC_LOG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);

int GetLastSettlementDetail(hash_t* hTxn);
int MatchLastSettlementDetail(hash_t* hTxn);
#ifdef __cplusplus
}
#endif

#endif
