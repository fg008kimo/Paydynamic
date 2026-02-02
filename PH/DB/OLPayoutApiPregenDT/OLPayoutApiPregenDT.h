#ifndef _OL_PAYOUR_API_PREGEN_DT_H_
#define _OL_PAYOUR_API_PREGEN_DT_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRec);
int GetDetail(const hash_t* hRec,recordset_t* myRec);
int UpdateByBatchId(const hash_t *hRec);
int Delete(const unsigned char* batch_id);
//int GetDetailByTxnId(const char* csBatchId,const char* csTxnId,recordset_t* myRec);
int UpdateByTxnId(const hash_t *hRec);
int GetTxnIdForUpdate(const char* csBatchId,const char* csTxnId);
int GetRecordByRandomWithPara(const hash_t *hTxn,recordset_t* myRec);
int GetExistingPsp(const hash_t *hRec, recordset_t* myRec);
int GetExistingPspOnlineMode(const hash_t *hRec, recordset_t* myRec);
int GetRecordsForPreGen(const hash_t* hRec,recordset_t* myRec);
int GetRecordsForGen(const hash_t* hRec,recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
