#ifndef _BOCRRMONTHEND_H_
#define _BOCRRMONTHEND_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int PostJournal(hash_t *hContext, const hash_t *hRequest);

#ifdef __cplusplus
}
#endif

#endif
