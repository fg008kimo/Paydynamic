#ifndef _SERVICE_CONSUMER_URL_H_
#define _SERVICE_CONSUMER_URL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindURL(const unsigned char* csServiceCode,
            const unsigned char* csMerchantId,
            const unsigned char* csCountry,
                unsigned char* csURL);

int GetURLByMerchId(const hash_t* hRls, recordset_t* myRec);

int UpdateURL(const hash_t* hRls);

#ifdef __cplusplus
}
#endif

#endif
