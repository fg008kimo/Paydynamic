#ifndef _DSP_MATCH_STAT_H_
#define _DSP_MATCH_STAT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
#define	PD_TXN_AMT	"TAMT"
#define	PD_ACTUAL_FEE	"TFEE"
#define	PD_PRECAL_FEE	"PFEE"
*/

int UpdateStat(const char* csTxnDate,
	   const char  cType,
	   const char* csPartyId,
	   const char* csAmtType,
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
