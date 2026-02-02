#ifndef _CLIENT_MAGIC_GP_STATUS_H_
#define _CLIENT_MAGIC_GP_STATUS_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);

int GetStatus(const char* csClientId,
              const int iTxnGpId,
                char *cStatus);

int ChkGpRecExists(const char* csClientId,
                      const int iTxnGpId);

#ifdef __cplusplus
}
#endif

#endif
