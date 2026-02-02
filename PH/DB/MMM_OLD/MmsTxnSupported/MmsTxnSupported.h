#ifndef _MMS_TXN_SUPPORTED_H_
#define _MMS_TXN_SUPPORTED_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindMmsTxnSupported(const char* csChannelCode,
			const char* csTxnCode);

int IsDoLogging(const char* csChannelCode,
                const char* csTxnCode);

int IsInitTxn(const char* csChannelCode,
                const char* csTxnCode);

#ifdef __cplusplus
}
#endif

#endif
