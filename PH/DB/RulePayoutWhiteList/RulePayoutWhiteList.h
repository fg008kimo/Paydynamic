#ifndef _OL_SIM_CARDS_H_
#define _OL_SIM_CARDS_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Delete(const char *csMerchName, const char *csAcctName, const char *csUser);
int InWhiteList(const char *csMerchName, const char *csAcctName);


#ifdef __cplusplus
}
#endif

#endif
