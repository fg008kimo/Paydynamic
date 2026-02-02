#ifndef _OLBAIDTXN_H_
#define _OLBAIDTXN_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int GetBaidTxn(const char *csBaidTxnId,
				hash_t *hRec);
int Update(const hash_t *hRls);
int UpdateByDstTxnSeq(const hash_t *hRls);
int MatchRespTxn(const char* csTxnSeq,
                     const char cStatus);
int MatchRespTxnByDstTxnSeq(const char* csTxnSeq,
					const char cStatus);

int CheckUnknownBaidTxn(const hash_t* hRls);
int GetTxnIdForUpdate(const char* csTxnId);

int GetBaidTxnIdByStatTxnId(const char* csStatTxnId, char* csBaidTxnId);

int GetCountByBAID(const char* csBAID);

int GetPayoutReconBaidTxn(const hash_t* hRls, recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
