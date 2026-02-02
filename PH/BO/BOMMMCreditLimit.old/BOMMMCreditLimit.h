#ifndef _BOMMMCREDITLIMIT_H_
#define _BOMMMCREDITLIMIT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {

int CalCreditLimit(hash_t *hRequest, hash_t *hResponse);

/*
int CalOLPspCostsByParty(hash_t *hRequest, hash_t *hResponse);
int CalOLPspCostsByID(hash_t *hRequest, hash_t *hResponse);
*/

#endif
#ifdef __cplusplus
}
#endif

#endif
