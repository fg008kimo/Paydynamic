#ifndef _OL_PRE_GEN_DAILY_REPORT_H_
#define _OL_PRE_GEN_DAILY_REPORT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int ChkExist(const hash_t *hRls);
int UpdateStatus(const hash_t *hRls);
int HkRecord(hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
