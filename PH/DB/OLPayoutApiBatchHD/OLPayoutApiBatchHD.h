#ifndef _OL_PAYOUT_API_BATCH_HD_H_
#define _OL_PAYOUT_API_BATCH_HD_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int GetHeader(const hash_t *hRec, recordset_t* myRec);
//int GetNextFileId(unsigned long *lFileId);
int GetNextSeq();
int Update(const hash_t *hRec);
//int Delete(const unsigned char* file_id);
//int GetPreGenHeader(const int iStatus, recordset_t* myRec);
//int ResumeFile(const unsigned char* file_id,const int status);
int MatchBatchStatus_ForUpdate(const char* csBatchId, const char* csTxnCode, const char cStatus);
int MatchBatchStatus_ForUpdate_ByBatchId(const char* csBatchId, const char cStatus);

#ifdef __cplusplus
}
#endif

#endif
