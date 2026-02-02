#ifndef _OLSTMTCONVERTSCRIPT_H_
#define _OLSTMTCONVERTSCRIPT_H_

#ifdef __cplusplus
extern "C" {
#endif

int GetConvertInfo(const char* csIntBankCode, const char* csStmtDatetime, char* csScriptName, char* csInFileEncoding, char* csInFilePrefix, char* csInFileCountry);

#ifdef __cplusplus
}
#endif

#endif
