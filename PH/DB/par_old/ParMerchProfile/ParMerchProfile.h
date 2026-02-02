#ifndef _PAR_MERCH_PROFILE_H_
#define _PAR_MERCH_PROFILE_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

#define PD_MERCH_ACCOUNT_NMB_LEN	50
#define PD_COMPANY_LEN                  400
#define PD_USERNAME_LEN			100
#define PD_API_MERCH_ID_LEN		30
#define PD_ACK_URL_LEN			200

int Add(const hash_t *);
int GetParMerchProfile(const char* csMerchAccNmb, recordset_t* myRec);


#ifdef __cplusplus
}
#endif

#endif
