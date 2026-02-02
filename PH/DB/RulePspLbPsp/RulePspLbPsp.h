#ifndef _RULE_PSP_LB_PSP_H_
#define _RULE_PSP_LB_PSP_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


int GetPsp(const char* csPspId,
        hash_t  *myHash);

int GetPspLimit(const char* csId,
                  const char* csServiceCode,
                  const char* csTxnCountry,
                  const char* csTxnCcy,
                  const char* csPayMethod,
                  double *dCurr,
                  double *dTotalCurr,
                  double *dReqCurr,
                  double *dTotalReqCurr);

int GetPspLBScheduler(const char* csPspId);

#ifdef __cplusplus
}
#endif

#endif
