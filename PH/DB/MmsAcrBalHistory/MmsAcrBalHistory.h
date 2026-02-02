#ifndef _MMSACRBALHISTORY_H_
#define _MMSACRBALHISTORY_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


int Add(const hash_t *hRec);
int GetAcrBalHistory(const hash_t *hRls, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
