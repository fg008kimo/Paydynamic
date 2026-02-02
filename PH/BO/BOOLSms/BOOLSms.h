#ifndef _BOOLSMS_H_
#define _BOOLSMS_H_
#include "myrecordset.h"
#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

//int TrimAmount(const char *p, char *pTrim);

int ValidateAmount(const char* csAmt, char* csTrimAmt);

int CheckWholeAmount(const char* csAmt);

int ValidateField(const char* csDesc, char* csValue, recordset_t* rRecordParam);

int ProcessSmsText(const hash_t* hTxn, hash_t* hText);

#ifdef __cplusplus
}
#endif

#endif
