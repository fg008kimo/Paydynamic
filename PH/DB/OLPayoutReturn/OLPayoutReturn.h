#ifndef _OL_PAYOUT_RETURN_H_
#define _OL_PAYOUT_RETURN_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckPayoutRtnAllow(const char* csTxnSeq,
			hash_t *hRls);

int GetPayoutRtnList(const char* csTxnSeq,
                     recordset_t *myRec);

int CheckPayoutReconMulti(const char* csTxnSeq);

int GetReconPattern(hash_t *hTxn, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
