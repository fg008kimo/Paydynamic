#ifndef _BOEMAILSETTING_H_
#define _BOEMAILSETTING_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int 	ProcessTpl(hash_t* hContext, hash_t* hRequest, hash_t* hResponse);
int 	ProcessEmailSettingBySettlement(hash_t* hContext, hash_t* hRls, int iSendEmail);

#ifdef __cplusplus
}
#endif

#endif
