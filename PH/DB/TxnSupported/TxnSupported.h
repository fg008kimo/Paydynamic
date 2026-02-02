#ifndef _TXN_SUPPORTED_H_
#define _TXN_SUPPORTED_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindTxnSupported(const char* csChannelCode,
			const char* csTxnCode);

int IsDoLogging(const char* csChannelCode,
                const char* csTxnCode);

int IsToMmsHost(const char* csChannelCode,
                const char* csTxnCode);
			

#ifdef __cplusplus
}
#endif

#endif
