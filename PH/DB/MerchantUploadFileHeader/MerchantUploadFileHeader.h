#ifndef _MERCHANT_UPLOAD_FILE_HEADER_H_
#define _MERCHANT_UPLOAD_FILE_HEADER_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int GetHeader(const unsigned long lBatchId, recordset_t* myRec);
int UpdateHeader(const hash_t *hRls);


int     Add(const hash_t *hRls);
int GenBatchId(char *csBatchId);
int MatchBatchStatus_ForUpdate(const char* csBatchId,
                               const int iStatus);

int Delete(const unsigned char* batch_id);
#ifdef __cplusplus
}
#endif

#endif
