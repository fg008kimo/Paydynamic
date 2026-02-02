#ifndef _MD5_H_
#define _MD5_H_

#include <openssl/md5.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" { 
#endif  

void md5sum(const char* in, const int length_in, char* out);
void
hmac_md5 (unsigned char*,int, unsigned char*,int, unsigned char*);

#ifdef __cplusplus
}       
#endif 

#endif 
