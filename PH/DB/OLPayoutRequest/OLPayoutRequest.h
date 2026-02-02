#ifndef _OL_PAYOUT_REQUEST_H_
#define _OL_PAYOUT_REQUEST_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *hRls);

//int Update(const hash_t *hRls);

int GetOLPayoutRequest(const char *csTxnID, hash_t *myHash);

int MatchOLPayoutRequestStatus(const char* csTxnId, const int iStatus);

int MatchOLPayoutRequestStatus_ForUpdate(const char* csTxnId, const int iStatus);

//int GetTxnPspDetailByBAID(const char *csBAID, recordset_t* myRec);
//int GetTxnCountByBankAcct(const char* csBankCode, const char* csBankAcctNum);

int ResumeGeneratedFile(const char* csFileId, const char* csUser);


#ifdef __cplusplus
}
#endif

#endif
