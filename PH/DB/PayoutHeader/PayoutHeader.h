#ifndef _PAYOUT_HEADER_H_
#define _PAYOUT_HEADER_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetPayoutHeader(const char* csMerchId, const char *csTxnDate, recordset_t* myRec);
int UpdateStatus(const hash_t *hRls);
#ifdef __cplusplus
}
#endif

#endif
