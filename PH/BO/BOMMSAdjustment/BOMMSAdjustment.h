#ifndef _BOMMSADJUSTMENT_H_
#define _BOMMSADJUSTMENT_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetCurrentCode(hash_t *hRec);
int ValidateProcess(hash_t* hRec);
int AddAdjustmentType (hash_t* hContext, hash_t* hData);
int UpdateAdjustmentType (hash_t* hContext, hash_t* hData);
int DeleteAdjustmentType (hash_t* hContext, hash_t* hData);

int ProcessEntityNatureBalance(hash_t* hContext, hash_t* hData);	
int ProcessFxBalance(hash_t* hContext, hash_t* hData);
int CheckCreditLimit(hash_t* hContext, hash_t* hData);

#ifdef __cplusplus
}
#endif

#endif

