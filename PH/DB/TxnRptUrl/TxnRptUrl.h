#ifndef _TXN_RPT_URL_H_
#define _TXN_RPT_URL_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int GetRptUrl(const char* csTxnCode,
             const char* csServiceCode,
             const char* csLanguage,
             const char* csPayMethod ,
             recordset_t* myRec);


#ifdef __cplusplus
}
#endif

#endif
