#ifndef	_EOD_GLUTILITY_H
#define	_EOD_GLUTILITY_H
#include "myhash.h"


typedef struct NODE {
 char*  txncode;
 char*  country;
 char*	id;
 char*  service;
 char*  txntype;
 char	type;
 char*  ccy;
 double amt;
 struct NODE *next;
} NODE;


typedef struct data_t {
	char	*type;
	char	*ccyname;
	char	*amtname;
	char	*chargetype;
	char	custtype;
} data_t;
 
 
typedef struct rDATA_t {
	int total_count;
	struct data_t **data;
} rDATA_T;

#ifdef __cplusplus
extern "C" {
#endif

int GenSQL(const char* csTxnDate,
		data_t *,
                unsigned char* csSQL);

int GroupRecs(NODE *Nptr,
		const char* csTxnCode,
		const char* csCountry,
		const char* csMerchantId,
		const char* csPspId,
		const char* csService,
		const char* csTxnType,
		const char* csCcy,
		double	dAmt);
void insert_node(NODE *Nptr, const char* csTxnCode, const char* csCountry,const char* csId, const char* csService,const char* csTxnType,const char cType,const char* csCcy,double dAmt);
		
#ifdef __cplusplus
}
#endif


#endif
