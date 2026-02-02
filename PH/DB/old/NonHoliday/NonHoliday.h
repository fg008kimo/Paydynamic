#ifndef _NON_HOLIDAY_H_
#define _NON_HOLIDAY_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const unsigned char* country, const unsigned char* date);
int UpdateDesc(const hash_t *hHoliday);

#ifdef __cplusplus
}
#endif

#endif
