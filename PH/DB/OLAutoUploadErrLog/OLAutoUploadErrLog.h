#ifndef _OL_AUTO_UPLOAD_ERR_LOG_H_
#define _OL_AUTO_UPLOAD_ERR_LOG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetErrorLog(int iJobSeq, const char *csNature, const char *csProviderId, recordset_t* myRec);
	
#ifdef __cplusplus
}
#endif

#endif
