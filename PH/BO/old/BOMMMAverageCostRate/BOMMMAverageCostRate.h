#ifndef _BOMMSACR_H_
#define _BOMMSACR_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int GetEntityFxBal(const hash_t* hIn, hash_t* hOut);
int GetEntityFxBalForUpdate(const hash_t* hIn, hash_t* hOut);
int GetACRBal(const hash_t* hIn, hash_t* hOut);
int GetACRBalForUpdate(const hash_t* hIn, hash_t* hOut);
int RecordAffectFXDT(const hash_t* hIn);
int CalculateAffectFXDT(const hash_t* hIn);
int VoidAffectFx(const hash_t* hIn);

#ifdef __cplusplus
}
#endif

#endif
