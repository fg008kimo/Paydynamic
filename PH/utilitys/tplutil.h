#ifndef	_TPLUTIL_H_
#define	_TPLUTIL_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C" { 
#endif  

int set_tpl_dyn_int(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,int csValue);
int set_tpl_dyn_double(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,double csValue);
int set_tpl_dyn_cstring(hash_t *hContext,int iDynCnt,const char *csTagName,const char *csType,const char *csVSec,const char *csValue);

#ifdef __cplusplus
}       
#endif  
#endif

