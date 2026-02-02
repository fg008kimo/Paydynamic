#ifndef _PSP_H_
#define _PSP_H_

#include "myhash.h"
#include "myrecordset.h"

#ifdef __cplusplus
extern "C" {
#endif
int GetCountryPsp(const char* csCountryCode,
                 recordset_t* myRec);

#ifdef __cplusplus
}
#endif

#endif
