#ifndef _OLSTATEMENT_H_
#define _OLSTATEMENT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetLastBalance(hash_t *hRls);
int GetExistingPastRecords(const hash_t* hRls, recordset_t* myRec, int* iRec);
int CheckFileExist(const char* csFilename);
int CheckBankStmtRecord(const hash_t* hRls);

int AddHeader(const hash_t *hRls);
int UpdateHeader(const hash_t *hRls);
int AddDetail(const hash_t *hRls);

int UpdateTxnId(const hash_t *hRls);
int AddSmsDetail(const hash_t *hTxn, const hash_t *hText);
int UpdateSmsDetail(const hash_t *hRls);
int MatchStmt(hash_t *hRls);

int GetUnallocatedRecords(const hash_t* hContext, recordset_t* rRecordSet);
int GetStmtDtl(const char* csStmtRef, hash_t* hStmtDtl);

#ifdef __cplusplus
}
#endif

#endif
