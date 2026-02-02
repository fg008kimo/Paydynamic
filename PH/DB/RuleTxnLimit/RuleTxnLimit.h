#ifndef _RULE_TXN_LIMIT_H_
#define _RULE_TXN_LIMIT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Find(const char* csTxnCode,
	const char* csCountryId,
	const char* csChannelCode,
        const char* csServicecode,
        const char* csPayMethod,
	const char* csCcy,
        const char* csPartyId,
	const char* csClientId,
	recordset_t *myRec);


#ifdef __cplusplus
}
#endif

#endif
