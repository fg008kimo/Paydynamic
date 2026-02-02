#ifndef _MMS_INSTANT_PM_ACCT_DT_H_
#define _MMS_INSTANT_PM_ACCT_DT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);

int GetSingleDetail(const char cPartyType,
                        const char cBusinessType,
                        const char *csPartyId,
                        hash_t *hContext);

int Delete (const char cPartyType,
                const char cBusinessType);

int GetNextPartyId(const hash_t *hRec,
                char *csNextPartyId);

int GetDetailbyRange(const hash_t *hRec,
                     recordset_t *myRec);


#ifdef __cplusplus
}
#endif

#endif
