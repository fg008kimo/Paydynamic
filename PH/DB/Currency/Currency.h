#ifndef _CURRENCY_H_
#define _CURRENCY_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int FindCurrency(const char* currency_id);
int GetCcyIdByNum(const char* currency_num, char * currency_id);

int FindBundledCurrency(const char* currency_id, char* bundled_ccy);
int IsRestricted(const char* currency_id);
int IsSupportDecimal(const char* currency_id);

int FindAllCurrency(recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
