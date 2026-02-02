#ifndef _RULE_OPR_TYPE_DETAIL_H_
#define _RULE_OPR_TYPE_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetRuleOperatorTypeDetail(const char* csOprType,
				recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
