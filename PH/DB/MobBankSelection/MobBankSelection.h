#ifndef _MOB_BANK_SELECTION_H_
#define _MOB_BANK_SELECTION_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetDefSegment(const char* csMerchantId,
                     hash_t * hTxn);

int GetAllMobileSegments(const char* csMerchantId,
                         recordset_t* myRec);

int GetOverflowGroup(const char* csGroup,
                       hash_t* myHash);

int CheckGroupTransfer(const char* csFrGroup, 
		       const char* csToGroup, 
		       int *iCanTrf);

int GetAllMobileSegmentsInfo(const char* csMerchantId,
                         recordset_t* myRec);
#ifdef __cplusplus
}
#endif

#endif
