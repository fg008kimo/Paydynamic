#ifndef _EMAILSETTINGHISTORY_H_
#define _EMAILSETTINGHOSTORY_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetLatestLogSeq(hash_t *hRls);
int AddLog(hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
