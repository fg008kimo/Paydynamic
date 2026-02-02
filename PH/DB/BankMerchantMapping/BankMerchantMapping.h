#ifndef _BANK_MAPPING_H_
#define _BANK_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


/*
int i2eBankCodeMapping(const unsigned char* csInputBankCode, const unsigned char* csChannelId,
                const unsigned char* csCountry, char* csOutputBankCode);
*/
int e2iBankCodeMapping(const unsigned char* csInputBankCode, const unsigned char* csMapId,
                const unsigned char* csCountry, char* csOutputBankCode);


#ifdef __cplusplus
}
#endif

#endif
