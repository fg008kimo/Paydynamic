#ifndef _OLSEMIAUTORECONTRIGGERLOG_H_
#define _OLSEMIAUTORECONTRIGGERLOG_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckConflict(const hash_t *hRls);
int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
