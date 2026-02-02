#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindURL(const unsigned char* ServiceCode,
	    const unsigned char* PspId,
		unsigned char* URL);

int FindCountryByService(const unsigned char* ServiceCode, char* TxnCountry);


int FindDomain(const unsigned char* ServiceCode,
                const unsigned char* RouteType,
                unsigned char* URL);

int IsCardTypeEnabled(const unsigned char* ServiceCode);
#ifdef __cplusplus
}
#endif

#endif
