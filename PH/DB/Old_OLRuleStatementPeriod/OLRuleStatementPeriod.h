#ifndef _OLRULESTATEMENTPERIOD_H_
#define _OLRULESTATEMENTPERIOD_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetStatementPeriod(const char* csIntBankCode,
			const char* csBankAcctNum,
			int* iBFHour,
			int* iAFHour,
			int* iHolidayBFHour,
			int* iHolidayAFHour);

#ifdef __cplusplus
}
#endif

#endif
