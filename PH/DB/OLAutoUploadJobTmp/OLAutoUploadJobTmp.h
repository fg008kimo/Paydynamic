#ifndef _OL_AUTO_UPLOAD_JOB_TMP_H_
#define _OL_AUTO_UPLOAD_JOB_TMP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(int iJobSeq);
int Delete(int iJobSeq);
int LockJobTmpStatus(int iJobSeq);	

#ifdef __cplusplus
}
#endif

#endif
