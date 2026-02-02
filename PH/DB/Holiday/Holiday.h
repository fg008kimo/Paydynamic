#ifndef _HOLIDAY_H_
#define _HOLIDAY_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const unsigned char* country, const unsigned char* service_code, const unsigned char* date, 
	const unsigned char* User);
int UpdateDesc(const hash_t *hHoliday);
int ChkHolidayExists(const unsigned char* country, const unsigned char* service_code, const unsigned char* date);

int     AddHolidayLog(char cAtion, hash_t *hHoliday);

#ifdef __cplusplus
}
#endif

#endif
