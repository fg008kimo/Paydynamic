#ifndef _CUSTOMER_TXN_HIST_H_
#define _CUSTOMER_TXN_HIST_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int AddHist(const char* csDate,
            const char* csMerchantId,
	    const char* csCustId,
	    const char* csCode,
	    double  dAmount,
	    const char* csUser);

#ifdef __cplusplus
}
#endif

#endif
