#ifndef	_PR_PAR_FUNCT_2_H_
#define	_PR_PAR_FUNCT_2_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif

int     AssignTxnRecordDetail(hash_t *hMyHash) ;
int     GetPSPRelatedInfo(hash_t *hMyHash);
int     prpar2_GetPOGTxnIDByVOATxnID(const char *csVOATxnID, hash_t *hTxn);
/*int     prpar2_GetReversedFileDetail(const hash_t *hTxn, recordset_t *myRec);*/

#ifdef __cplusplus
}
#endif

#endif

