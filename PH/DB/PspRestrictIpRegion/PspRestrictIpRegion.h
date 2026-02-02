#ifndef _PSP_RESTRICT_IP_REGION_H_
#define _PSP_RESTRICT_IP_REGION_H_

#include "myrecordset.h"

#ifdef __cplusplus
extern "C"
{
#endif

int Update(const hash_t * hIn);
int UpdateByPspId(const hash_t * hIn);
int IsSupportIpRegion(const char * csPspId, const char * csRegionCode);

#ifdef __cplusplus
}

#endif
#endif
