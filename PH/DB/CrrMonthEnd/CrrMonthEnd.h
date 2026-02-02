#ifndef _CRR_MONTH_END_H_
#define _CRR_MONTH_END_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int Add(const char* csTbYear, const char* csTbMonth, const int iClosed, const int iDisabled, const char* csCreateUser);
int Update(const char* csTbYear, const char* csTbMonth, const int iClosed, const int iDisabled, const char* csUpdateUser);
int Delete(const char* csTbYear, const char* csTbMonth, const char* csUpdateUser);
int Get(const char* csTbYear, const char* csTbMonth, hash_t* hRec);

#ifdef __cplusplus
}
#endif

#endif
