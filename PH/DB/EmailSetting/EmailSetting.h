#ifndef _EMAILSETTING_H_
#define _EMAILSETTING_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetNotifyList(const hash_t *hRls, recordset_t *myRec);

int CheckEmailSettingRecord(hash_t *hRls);
int DisableEmailSettingRecord(const hash_t *hRls);

int AddOriginal(const hash_t *hRls);
int Add(const hash_t *hRls);
int Update(const hash_t *hRls);

int GetEmailId(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
