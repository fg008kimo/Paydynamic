#ifndef _DEF_PRODUCT_H_
#define _DEF_PRODUCT_H_

#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int GetAllProduct(recordset_t *myRec);
int FindProduct(char *csProduct);

#ifdef __cplusplus
}

#endif
#endif
