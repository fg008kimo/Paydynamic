#ifndef _TXN_CONTROL_H_
#define _TXN_CONTROL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindTxnControl(const char* csChannelCode,
			const char* csTxnCode,
			const char* csCountryId,
			const char* csCcy,
			double* dAmt);
			

#ifdef __cplusplus
}
#endif

#endif
