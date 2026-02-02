#ifndef _RULE_PSP_LB_POOLS_H_
#define _RULE_PSP_LB_POOLS_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetDetailById(int iId,
			recordset_t*);
	
int GetPspPoolsTotal(int iId,
                  const char* csServiceCode,
                  const char* csTxnCountry,
                  const char* csTxnCcy,
                  const char* csPayMethod,
                  double *dCurr,
                  double *dTotalCurr,
                  double *dReqCurr,
                  double *dTotalReqCurr);

#ifdef __cplusplus
}
#endif

#endif
