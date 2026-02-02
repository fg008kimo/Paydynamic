#ifndef _MATCH_DSP_STAT_H_
#define _MATCH_DSP_STAT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int UpdateStat(const char* csTxnDate,
	   const char  cType,
	   const char* csPartyId,
	   const char* csFromCcy,
	   const char* csToCcy,
	   double	dFromAmt,
	   double	dToAmt,
	   double	dExRate);


int ResetStat(const char* csTxnDate,
	   const char  cType);
#ifdef __cplusplus
}
#endif

#endif
