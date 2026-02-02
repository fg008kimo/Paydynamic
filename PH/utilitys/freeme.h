#ifndef _FREEME_H_
#define _FREEME_H_
#include <stdlib.h>

#define FREE_ME(x) { if (x != NULL) { \
						free((void *) x);	\
						x = NULL; } }
#endif
