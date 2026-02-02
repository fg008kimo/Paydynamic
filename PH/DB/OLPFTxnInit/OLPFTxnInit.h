#ifndef _OL_PF_TXN_INIT_H_
#define _OL_PF_TXN_INIT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetHeader(const char *csFileId, hash_t *myHash);
int GetDetail(const char *csFileId, recordset_t *myRec);
//int GetNextFileId(char *csFileId);
//int GetNextErrorId(char *csErrorId);
int CheckFileExist(const char* csFilename);
int AddHeader(const hash_t *hRls);
int UpdateHeader(const hash_t *hRls);
int AddDetail(hash_t *hRls);
int UpdateDetail(const hash_t *hRls);
int AddError(const hash_t *hRls);
int GetHeaderStatusForUpdate(const char *csFileId, const char cStatus);

#ifdef __cplusplus
}
#endif

#endif
