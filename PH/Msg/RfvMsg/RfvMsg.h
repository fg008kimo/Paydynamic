#ifndef _RFVMSG_H
#define	_RFVMSG_H

#include "myhash.h"

#define	MY_RFV_TOKEN		"&"
#define	MY_RFV_FIELD_TOKEN	"="

#define PD_P0_CMD		"Buy"
#define PD_P5_PID		"PAY"
#define PD_PA_FRPID_EC          "Nocard_H5"
#define PD_PA_FRPID_VNET        "OnlinePay"

#ifdef __cplusplus
extern "C" {
#endif

int FormatMsg(const hash_t *table, unsigned char *outMsg, int *outLen);
int BreakDownMsg(hash_t *table, const unsigned char *inMsg, int inLen);
int initReplyFromRequest(const hash_t *, hash_t *);
int BuildAuthData(hash_t *hIn);
int BuildRspAuthData(hash_t *hIn);

#ifdef __cplusplus
}
#endif

#endif
