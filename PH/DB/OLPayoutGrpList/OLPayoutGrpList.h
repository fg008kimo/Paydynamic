#ifndef _OL_PAYPUT_GRP_LIST_H_
#define _OL_PAYPUT_GRP_LIST_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *hRls);
int Delete(const hash_t *hRls);
int MatchRecord(hash_t *hRls);
#ifdef __cplusplus
}
#endif

#endif
