#ifndef _MYSTRINGS_H_
#define _MYSTRINGS_H_

#ifdef __cplusplus
extern "C" {
#endif

char* ora_ESC_string(const char* buffer);
char* ESC_string(const char* buffer);
char* strmov(register char* dst, register const char* src);

#ifdef __cplusplus
}
#endif
#endif
