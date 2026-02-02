#ifndef _OL_AUTO_UPLOAD_JOB_STATUS_H_
#define _OL_AUTO_UPLOAD_JOB_STATUS_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int UpdateStatus(const hash_t *hRls);
int GetStatus(hash_t *hRls);
int CheckAllJobFinish(int iJobSeq);
int GetNextJobSeq(int *iJobSeq);
	
#ifdef __cplusplus
}
#endif

#endif
