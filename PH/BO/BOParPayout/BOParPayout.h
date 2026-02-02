#ifndef _BOPARPAYOUT_H_
#define _BOPARPAYOUT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int ProcessPayoutTxn(hash_t *hContext,
                hash_t* hRequest,
		hash_t* hResponse);

int GetPayoutRecordsByMode(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse);

int GetPayoutRecords(hash_t* hTxn,
                        hash_t* hContext,
                        hash_t* hRequest);

int UpdateDetail(hash_t *hContext,
                hash_t* hRequest);

int CheckAvalBalance(hash_t *hContext,
                     const hash_t* hRequest);

int GetPayoutFee(hash_t *hContext,
                 hash_t* hRequest);

int GenerateBatchSeq(hash_t* hRequest);

int AddTxnLog(hash_t *hContext, hash_t *hRequest);

int HandlePayoutBalance(hash_t* hContext, hash_t* hRequest);
int UpdateTxnLog(hash_t *hContext);
int UpdateTxnLog_Par(hash_t *hContext);

int HandleCancelUpload(hash_t *hContext, hash_t *hRequest);
int HandleCancelConfirm(hash_t *hContext, hash_t *hRequest);
int HandleCancelGenerate(hash_t* hContext,
                         hash_t* hRequest,
                         hash_t* hResponse);

int isVoidWithFee(hash_t* hTxn);

int     HandleTxnPayoutBalance(hash_t* hContext, hash_t* hRequest);
int handle_PayoutGenerate(hash_t* hContext,hash_t* hRequest,hash_t* hHeader);

int GetPreApproveRecord(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse);
#ifdef __cplusplus
}
#endif

#endif
