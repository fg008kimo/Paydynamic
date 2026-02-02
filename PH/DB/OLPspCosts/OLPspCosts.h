#ifndef _OL_PSP_COSTS_H_
#define _OL_PSP_COSTS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetOLPspCostsByParty(const hash_t *hRls, hash_t *myHash);
int GetOLPspCostsByID(const hash_t *hRls, hash_t* hResponse);
int GetGroupingTypeById(int iRuleId, char *cGroupingType);

int Add(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
