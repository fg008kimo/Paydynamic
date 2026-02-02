#ifndef _OL_RULE_PAYOUT_PSP_H_
#define _OL_RULE_PAYOUT_PSP_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetRulePayoutPspWithPriority(recordset_t* myRec);
int GetExistingPspId(recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
