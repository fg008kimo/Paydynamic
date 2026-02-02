#ifndef _OL_AUTO_UPLOAD_BANK_DETAIL_H_
#define _OL_AUTO_UPLOAD_BANK_DETAIL_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetAutoUploadBankAccts(const hash_t* hRec, recordset_t* myRec);
int UpdateDisabled(const hash_t* hDisabled);
	
#ifdef __cplusplus
}
#endif

#endif
