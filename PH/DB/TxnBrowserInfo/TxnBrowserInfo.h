#ifndef _TXN_BROWSER_INFO_H_
#define _TXN_BROWSER_INFO_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int AddTxnBrowserInfo(const hash_t *);

int UpdateDeviceType(const char* csTxnId, char cDeviceType);

#ifdef __cplusplus
}
#endif

#endif
