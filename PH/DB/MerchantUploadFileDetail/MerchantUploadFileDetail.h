#ifndef _MERCHANT_UPLOAD_FILE_DETAIL_H_
#define _MERCHANT_UPLOAD_FILE_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetDetail(const unsigned long BatchId, recordset_t* myRec);
int GetDetailByTxnId(const char* csTxnId, recordset_t* myRec);
int UpdateDetailByBatchId(const char* csBatchId, const int iSeqNum, const hash_t *hRls);
int UpdateDetailByTxnId(const char* csTxnId, const hash_t *hRls);

int GetDetailByRandomWithBankMerchant(const char* csBankName, const char* csMerchantId, recordset_t* myRec);
int GetDetailByRandomWithBank(const char* csBankName, recordset_t* myRec);
int GetDetailByRandomWithMerchant(const char* csMerchantId, recordset_t* myRec);
int GetDetailByRandom(recordset_t* myRec);

int MatchRespTxn(const char* csTxnSeq,
                 const int iStatus);

int GetExistingPsp(hash_t* hTxn,recordset_t* myRec);
int GetExistingPid(hash_t* hTxn,recordset_t* myRec);
int GetPspAssignedTxn(hash_t* hTxn,recordset_t* myRec);
int MatchCount(const unsigned long lBatchId,const int iStatus);
int ResumeAssignedPsp();
int ResumePreGenFile(const char*csFileId);
int ResumeGeneratedFile(const char*csFileId, const char* csUser);

int GetOnlineBatchRecord(hash_t *hTxn, recordset_t* myRec);
int GetUnvoidedDetail(const unsigned long lBatchId, recordset_t* myRec);


int GetDetailByCondition(hash_t *hTxn, recordset_t* myRec);
int GetNextApproveId(int *iApproveId);
int GetPreAssignedPsp(hash_t *hTxn, recordset_t* myRec);
int GetNextPreApproveId(int *iApproveId);
int ResumeUnusedPreApproveId(const int iApproveId);
int GetDetailByPreApproveId(const int iPreApproveId, recordset_t* myRec);
int UpdateFileNameByFileId(const hash_t *hRls);

int GetDetailByRandomWithPara(const hash_t *hTxn,recordset_t* myRec);
int MatchUploadTxn(const hash_t *hRls);

int MatchRespTxn_ForUpdate(const char* csTxnSeq,
                 const int iStatus);
int Delete(const unsigned char* batch_id);

int GetRecordByRandomWithPara(const hash_t *hTxn,recordset_t* myRec);
int GetPregeneratedRecords(const int iGenId, char cBatchMode, recordset_t* myRec);
int ResumeGeneratedTxn(const char* csTxnId, const char* csUser);
int GetPregenSummary(const int iGenId, recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
