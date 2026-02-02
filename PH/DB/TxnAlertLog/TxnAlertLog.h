#ifndef _TXN_ALERT_LOG_H
#define _TXN_ALERT_LOG_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
