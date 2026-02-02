#ifndef _OL_SIM_CARDS_H_
#define _OL_SIM_CARDS_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *hRls);
int Update(const hash_t *hRls);
int DisposeSimCard(const hash_t *hRls);
int GetSimCardStatus(const char* csMobile, char* cStatus);

#ifdef __cplusplus
}
#endif

#endif
