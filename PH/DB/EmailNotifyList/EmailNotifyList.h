#ifndef _EMAILNOTIFYLIST_H_
#define _EMAILNOTIFYLIST_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetEmailAddress(hash_t *hRls);
int GetLatestEmailId(hash_t *hRls);
int CheckEmailAddressRecord(hash_t *hRls);
int CheckEmailIdRecord(hash_t *hRls);

int Add(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
