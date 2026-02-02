#ifndef _RULE_AUTO_SETT_H_
#define _RULE_AUTO_SETT_H_

#include "myhash.h"
#include "myrecordset.h"
#ifdef __cplusplus
extern "C" {
#endif

//int GetIdDetail(int iId, recordset_t* myRec);
int Add(hash_t *hRls);
int Update(const hash_t *hRls, char cDefType, int isDefType);
int FindRule(int iAutoSettId, char cType, int isType);
int GetRulesDetail(hash_t* hTxn, recordset_t *myRec);

#ifdef __cplusplus
}
#endif

#endif
