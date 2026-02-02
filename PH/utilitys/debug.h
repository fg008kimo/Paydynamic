#ifndef _DEBUG_H_
#define _DEBUG_H_
#include <stdarg.h>

void errlog(const char *fmt, ...);
void ERRLOG(const char *fmt, ...);
void TXNLOG(const char *fmt, ...);
void acklog(const char *fmt, ...);

extern char _debug_filename[];
extern int _debug_line_no;


#ifdef _LINUX_DEBUG_
#define DEBUGLOG(x)     { 	if ( cDebug == 'Y') {\
				 		strcpy(_debug_filename, __FILE__); \
                                                _debug_line_no = __LINE__;  \
                                                errlog x; }}
#else
#define DEBUGLOG(x) { }
#endif

#ifdef _LINUX_DEBUG_
#define LOGME(x)     { 	strcpy(_debug_filename, __FILE__); \
                                                _debug_line_no = __LINE__;  \
                                                errlog x; }
#else
#define LOGME(x) { }
#endif
#define ACKLOG(x)     { 	if ( cTrace == 'Y') {\
                                                acklog x; }}


#endif
