#ifndef _OL_PAYOUT_TXN_ACK_LOG_H_
#define _OL_PAYOUT_TXN_ACK_LOG_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int GetAckLog(const unsigned char *csTxnSeq, recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
