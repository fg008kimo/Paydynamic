#ifndef _OLMATCHTIMEINTERVAL_H_
#define _OLMATCHTIMEINTERVAL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


int GetMatchTimeInterval(const char* csIntBankCode,
                                const char* csMerchantId,
                                const char* csBankAcctNum,
                                const char* csCountry,
				const char* csServiceCode,
                                const char* csDate,
                                const char* csTime,
                                recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
