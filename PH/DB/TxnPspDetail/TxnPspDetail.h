#ifndef _TXNPSPDETAIL_H_
#define _TXNPSPDETAIL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *hRls);
int GetTxnPspDetail(const char* csTxnID,
                recordset_t* myRec);

int GetTxnPspDetailForRecon(const char* csPspId,
                            const char* csTxnCcy,
                            const char* csDate,
                            recordset_t* myRec);

int GetTxnPspDetailForReconUpdate(const char* csPspId,
                            const char* csTxnCcy,
                            const char* csDate,
                            recordset_t* myRec);

int GetTxnPspDetailByDlvId(const unsigned char* csDlvId,
                                recordset_t* myRec);

int GetTxnDateSettleDate(const char *csTxnId, hash_t* hRls);

int PspBalNullInTxnPspDtByAprvDate(const char *csAprvDate, recordset_t* myRec);

int PspBalInTxnPspDetail(const char* csTxnSeq);

#ifdef __cplusplus
}
#endif

#endif
