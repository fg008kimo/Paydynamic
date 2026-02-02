#ifndef _BOMIOLADJUSTMENT_H_
#define _BOMIOLADJUSTMENT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int	GetCurrentCode(hash_t *hRec);
int     ValidateProcess(hash_t* hInRec);
int	ProcessPartyBalance(hash_t* hInRec);


#ifdef __cplusplus
}
#endif

#endif
