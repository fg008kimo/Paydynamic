#ifndef _LOGMSG_H_
#define _LOGMSG_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void logmsg(char *fmt, ...);
void dumphex(unsigned char *hexdata, long len);

#ifdef __cplusplus
}
#endif

#endif
