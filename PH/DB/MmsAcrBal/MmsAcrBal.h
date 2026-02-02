#ifndef _MMSACRBAL_H
#define _MMSACRBAL_H

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Update(const hash_t *hRec);
int GetOwnAcrBal(const hash_t *hRec, hash_t *hBal);
int GetOwnAcrBalForUpdate(const hash_t *hRec, hash_t *hBal);
int GetAllAcrBalByCcy(const char* csEntityId, const char* csCcy,recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
