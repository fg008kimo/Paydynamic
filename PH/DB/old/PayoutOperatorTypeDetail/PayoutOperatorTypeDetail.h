#ifndef _PAYOUT_OPR_TYPE_DETAIL_H_
#define _PAYOUT_OPR_TYPE_DETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetPayoutOperatorTypeDetail(const char* csOprType,
				recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
