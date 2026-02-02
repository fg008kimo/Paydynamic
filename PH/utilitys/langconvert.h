#ifndef _LANGCONVERT_H_
#define _LANGCONVERT_H_
#include <iconv.h>

#ifdef __cplusplus
extern "C" { 
#endif  

char *code_convert(const char* FROM_CODE,const char* TO_CODE,char *utf8str);

#ifdef __cplusplus
}       
#endif 
#endif

