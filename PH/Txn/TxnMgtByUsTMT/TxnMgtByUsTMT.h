#ifndef _TXNMGTBYUSTMT_H_
#define _TXNMGTBYUSTMT_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse);
int AddTaskLog(hash_t *hITTLog, int iLogBatchSeq, char *csTaskAction, char cActionType, char *csObject, char *csKey, char *csField, char *csValue, char *csOldValue);
int IsValidRange(char *csValue, int *iValue);

#ifdef __cplusplus
}

#endif
#endif
