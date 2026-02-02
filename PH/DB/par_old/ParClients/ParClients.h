#ifndef _PAR_CLIENTS_H_
#define _PAR_CLIENTS_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

#define PD_COMPANY_LEN                  400
#define PD_DEF_CLIENT_GROUP_LEN		5

int Add(const hash_t *);
int GetClientID(const char* csCompanyName, recordset_t* myRec);


#ifdef __cplusplus
}
#endif

#endif
