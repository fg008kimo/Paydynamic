#ifndef _OLMERCHCONFIG_H_
#define _OLMERCHCONFIG_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetACRPool(const char* csMerchantID,
                const char* csCountry,
                const char* csCcy,
                const char* csServiceCode,
                char*   csACRPool);

int CheckConfig(const char* csMerchantID,
                const char* csCountry,
                const char* csCcy,
                const char* csServiceCode);

#ifdef __cplusplus
}
#endif

#endif

