#ifndef _CLIENT_MAGIC_H_
#define _CLIENT_MAGIC_H_

#include "myhash.h"
#ifdef __cplusplus
extern "C" {
#endif

int Add(const hash_t *);
int Update(const hash_t *hRls);
int Delete(const hash_t *);
int GetCustomerIdByMagic(const char* csClientId,
			 const char* csMagicNumber,
			 const char* csMagicWord,
			 unsigned char* csCustomerId);
int GetMagicNumById(const char* csClientId, 
			 const char* csCustomerId,
			 char* csMagicNum);

int GetTotalMatchRec(const hash_t *hClientMagic,  
                     int *iTotalCount);

int GetClientMagic(const char* csClientId,
                        const char* csMagicNumber,
                        const char* csMagicWord,
                        hash_t *hClientMagic);

#ifdef __cplusplus
}
#endif

#endif
