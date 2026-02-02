#ifndef _SYSCALL_H_
#define _SYSCALL_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C" {
#endif

int systemcall(char **argv, int dTimeout);
void execute(char **argv);

#ifdef __cplusplus
}
#endif

#endif
