#ifndef _OLSMSFORMAT_H_
#define _OLSMSFORMAT_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int CheckBank(const char* csText);

int CheckSender(const char* csSender);

int GetFormat(const char* csSender, const char* csText, recordset_t* rRecordSet);

int GetParam(const char* csFormatId, recordset_t* rRecordSet);

#ifdef __cplusplus
}
#endif

#endif
