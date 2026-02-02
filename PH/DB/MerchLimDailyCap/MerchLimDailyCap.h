#ifndef _MERCH_LIM_DAILY_CAP_H_
#define _MERCH_LIM_DAILY_CAP_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int CheckRecord(const hash_t* hRls);
int Add(const hash_t *);
int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
