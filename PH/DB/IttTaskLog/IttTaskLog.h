#ifndef _ITTTASKLOG_H_
#define _ITTTASKLOG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hIttTaskLog);

int UpdateRetCodeByBatch(const hash_t *hIttTaskLog);

int UpdateRetCodeBySeq(const hash_t *hIttTaskLog);

char* GetNextITTTaskBatchSeq();

#ifdef __cplusplus
}
#endif

#endif
