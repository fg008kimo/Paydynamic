#ifndef _BOOLDEPOSITMATCH_H_
#define _BOOLDEPOSITMATCH_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
int GetUnallocatedStmt(hash_t* hContext, recordset_t* rRecordSet);
*/

int HandleDepositMatchPair(const char* csStmtTxnId,
                        const char* csTxnSeq,
                        const char cMatchingType,
                        const char* csAddUser);

int ProcessMatching(const hash_t* hContext);

int CompleteMatching(const char* csStmtTxnId,
			const char* csTxnSeq,
			const int iOverrideAmt,
			const char cMatchingType,
			const char* csAddUser);

#ifdef __cplusplus
}
#endif

#endif
