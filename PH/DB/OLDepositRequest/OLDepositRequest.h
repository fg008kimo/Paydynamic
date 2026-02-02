#ifndef _OLDEPOSITREQUEST_H_
#define _OLDEPOSITREQUEST_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckUploadedMerchantRef(const char *csMerchantID, const char *csMerchRef);
int GetDepositHeaderForUpdate(const char *csFileId, hash_t *myHash);
int GetDepositHeader(const char *csFileId, hash_t *myHash);
int GetDepositDetail(const char *csFileId, recordset_t *myRec);
int GetNextFileId(char *csFileId);
int CheckFileExist(const char* csMerchantId, const char* csFilename);
int AddHeader(const hash_t *hRls);
int UpdateHeader(const hash_t *hRls);
int AddDetail(hash_t *hRls);
int UpdateDetail(const hash_t *hRls);
int GetBankCode(const char *csBankName,
			char *csBankCode);
int GetDepositBankCode(const char *csBankName,
                        char *csBankCode);


#ifdef __cplusplus
}
#endif

#endif
