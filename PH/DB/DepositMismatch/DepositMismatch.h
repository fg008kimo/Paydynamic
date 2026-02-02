#ifndef _DSP_MISMATCH_H_
#define _DSP_MISMATCH_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const char* csTxnId,
	const char cPartyType,
	const char* csPartyId,
	const char* csTid,
	const char* csTxnDate,
	const char* csAbs);
int MarkDeleted(const unsigned char* csTxnId, const char cPartyType, const unsigned char* csMatchDate);
int MarkDeletedByTid(const unsigned char* csPspTid, const char cPartyType, const unsigned char* csMatchDate);
int GetDspMismatch(const char* csTxnId, const char cPartyType, char* csAbs);
int GetDspMismatchByTid(const char* csPspTid, const char cPartyType, char* csAbs);

#ifdef __cplusplus
}
#endif

#endif
