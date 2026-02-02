#ifndef _LANGUAGE_H_
#define _LANGUAGE_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Delete(const unsigned char* lang_code);
int FindLanguage(const char* lang_code, char * active_ind);
#ifdef __cplusplus
}
#endif

#endif
