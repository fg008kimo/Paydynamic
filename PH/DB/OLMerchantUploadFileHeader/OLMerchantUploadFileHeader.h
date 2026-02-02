#ifndef _OL_MERCHANT_UPLOAD_FILE_HEADER_H_
#define _OL_MERCHANT_UPLOAD_FILE_HEADER_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetHeader(const unsigned long lBatchId, recordset_t* myRec);
int UpdateHeader(const hash_t *hRls);

int Add(const hash_t *hRls);
int GenBatchId(char *csBatchId);
int Delete(const unsigned char* batch_id);

int MatchBatchStatus_ForUpdate(const char* csBatchId,
                               const int iStatus);
int CheckDuplicateFileName(const char* csFileName,
			   const char* csMerchantId);

#ifdef __cplusplus
}
#endif

#endif
