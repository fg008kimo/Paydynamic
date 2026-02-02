#ifndef _BOADJUSTMENT_H_
#define _BOADJUSTMENT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int	GetCurrentCode(hash_t *hRec);
int     ValidateProcess(hash_t* hInRec);
int     ProcessPartyBalance(hash_t* hInRec);


#ifdef __cplusplus
}
#endif

#endif
