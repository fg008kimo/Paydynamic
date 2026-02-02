#ifndef _BOOLTXNELEMENTS_H_
#define _BOOLTXNELEMENTS_H_
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int     AddTxnAmtElement(hash_t* hContext);
int     AddTxnFeeElements(hash_t* hContext);
int     AddReserveAmtElement(hash_t* hContext);
int     AddMarkupAmtElement(hash_t* hContext);
int	VoidOrgTxnElements(const hash_t  *hContext, const hash_t *hRequest);
int	AddHoldAmtElement(hash_t* hContext);
int     AddTransferAmtElement(hash_t* hContext);
int     AddTransferAvaPOElement(hash_t *hContext);
int     AddPspTxnElement(hash_t* hRequest);
int     AddTransferAvaPOElement(hash_t *hContext);

#ifdef __cplusplus
}
#endif

#endif
