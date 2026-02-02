#ifndef _BANKNAME_MAPPING_H_
#define _BANKNAME_MAPPING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif



int BankNameConvert(const unsigned char* csPspChannel,
                    const unsigned char* csInputBank,
                    char* csOutputBank);
#ifdef __cplusplus
}
#endif

#endif
