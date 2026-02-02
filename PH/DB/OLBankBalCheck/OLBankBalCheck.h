#ifndef _OL_BANK_BAL_CHECK_H_
#define _OL_BANK_BAL_CHECK_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckSendAlert(const char* csIntBankCode,
		const double dBal,
		int *iSendAlert);

#ifdef __cplusplus
}
#endif

#endif
