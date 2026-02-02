#ifndef _RULE_AMT_H_
#define _RULE_AMT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls,
	int *iAmtId);

int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
