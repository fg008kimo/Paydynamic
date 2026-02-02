#ifndef _BOCRRPOST_H_
#define _BOCRRPOST_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int  PostPHTxn(recordset_t* myRec);
int  PostOffSysTxn(recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
