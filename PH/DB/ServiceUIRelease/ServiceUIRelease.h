#ifndef _SERVICE_UI_RELEASE_H_
#define _SERVICE_UI_RELEASE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int IsUseNewUI(const unsigned char* csServiceCode,
               const unsigned char* csMerchantId,
	       const unsigned char* csCountry);

#ifdef __cplusplus
}
#endif

#endif
