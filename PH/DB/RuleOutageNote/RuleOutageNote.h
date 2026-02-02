#ifndef _RULEOUTAGENOTE_H_
#define _RULEOUTAGENOTE_H_

#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif


int Add(hash_t *hRls);
int Update(const hash_t *hRls);
int Delete(const hash_t *hRls);


#ifdef __cplusplus
}
#endif

#endif
