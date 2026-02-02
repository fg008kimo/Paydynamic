#ifndef _TXN_FE_URL_H_
#define _TXN_FE_URL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


int GetFeUrl(const char* csTxnCode,
                const char* csServiceCode,
                const char* csMerchantId,
                const char* csCountry,
                const char* csLanguage,
                char cDirection,
		recordset_t* myRec);

int GetFeUrl_NewUI(const char* csTxnCode,
                const char* csServiceCode,
                const char* csMerchantId,
                const char* csCountry,
                const char* csLanguage,
                char cDirection,
		recordset_t* myRec);

int GetFeUrl_wBL(const char* csTxnCode,
                const char* csServiceCode,
                const char* csMerchantId,
                const char* csCountry,
                const char* csLanguage,
                char cDirection,
		recordset_t* myRec);

int GetFeUrl_NewUI_wBL(const char* csTxnCode,
                const char* csServiceCode,
                const char* csMerchantId,
                const char* csCountry,
                const char* csLanguage,
                char cDirection,
		recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
