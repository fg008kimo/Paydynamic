#ifndef _RULE_RELEASE_PERIOD_H_
#define _RULE_RELEASE_PERIOD_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Replicate(const hash_t *hRec);
int Find(const char* csCountryId,
	const char* csPspId,
	int	*iPeriod);
#ifdef __cplusplus
}
#endif

#endif
