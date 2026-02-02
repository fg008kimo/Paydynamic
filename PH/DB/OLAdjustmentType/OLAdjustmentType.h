#ifndef _OLADJUSTMENTTYPE_H_
#define _OLADJUSTMENTTYPE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetMaxCode(const char cPartyType,
		int *csMaxCodeInNum);

int Add(const hash_t *hRls);

int GetAdjustmentTypeRec(const char cPartyType,
				const char *csCode,
				recordset_t *myRec);

int Update(const hash_t *hRls);

int Delete(const hash_t *hRls);

#ifdef __cplusplus
}
#endif

#endif
