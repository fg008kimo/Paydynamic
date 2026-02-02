#ifndef _CONV_STORE_MAPPING_H_
#define _CONV_STORE_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif



int i2e(const unsigned char* csChannelCode, const unsigned char* csIntCode, char* csExtCode,char* csExtType);

#ifdef __cplusplus
}
#endif

#endif
