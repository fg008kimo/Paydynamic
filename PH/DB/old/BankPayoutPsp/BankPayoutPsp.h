#ifndef _BANK_PAYOUT_PSP_H_
#define _BANK_PAYOUT_PSP_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetBankPayoutPsp(const char* csBankName,
		     recordset_t* myRec);

int GetBankPayoutPspWithPriority(recordset_t* myRec);
int GetExistingPspId(recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
