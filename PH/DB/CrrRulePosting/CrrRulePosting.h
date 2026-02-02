#ifndef _CRR_RULE_POSTING_H_
#define _CRR_RULE_POSTING_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetRule(const hash_t* hReq,
		hash_t *hRsp);
		
#ifdef __cplusplus
}
#endif

#endif
