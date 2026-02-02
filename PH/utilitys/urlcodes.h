#ifndef _URLCODES_H_
#define _URLCODES_H_

int urldecode(const unsigned char* csSrc, int iLen,unsigned char* csDst, int *oLen);
char *url_encode(char *str);
#endif

