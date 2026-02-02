#ifndef _OL_MERCH_SETTLEMENT_DETAIL_H_
#define _OL_MERCH_SETTLEMENT_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t* hRls);
int Update(const hash_t* hRls);
int GetSettlementDetail(const char* csTxnID,
		recordset_t* myRec);
int GetRemark(const char* csTxnID, hash_t* hRls);
int UpdateRemark(hash_t* hRls);

#ifdef __cplusplus
}
#endif

#endif
