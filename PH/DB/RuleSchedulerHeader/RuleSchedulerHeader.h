#ifndef _RULE_SCHEDULER_HEADER_H_
#define _RULE_SCHEDULER_HEADER_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetIdDetail(int iId, recordset_t* myRec);

int FindMostUpdatedSchedule(hash_t* hRls);

#ifdef __cplusplus
}
#endif

#endif
