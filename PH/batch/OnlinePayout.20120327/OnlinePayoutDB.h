#ifndef	_OFFLINEWTBDB_H_
#define	_OFFLINEWTBDB_H_


#ifdef __cplusplus
extern "C" {
#endif


int batch_init(int argc, char** argv);
int batch_proc(int argc, char** argv,hash_t *hContext, hash_t *hRequest);
int batch_terminate(int argc, char** argv);
int     UpdatePreTWVRespTxnLog(hash_t *hContext,
                        hash_t* hResponse);

#ifdef __cplusplus
}
#endif


#endif
