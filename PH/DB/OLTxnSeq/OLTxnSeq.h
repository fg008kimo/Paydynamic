#ifndef _OLTXNSEQ_H_
#define _OLTXNSEQ_H_

#ifdef __cplusplus
extern "C" {
#endif
char* GetNextOlnTxnSeq();
char* GetNextOmtTxnSeq();
char* GetNextStmtTxnSeq();
char* GetNextStmtRef();
char* GetNextBaidTxnSeq();
char* GetNextOdiFileSeq();
char* GetNextActionBatchSeq();
char* GetNextPfiFileSeq();
char* GetNextOiaTxnSeq();
#ifdef __cplusplus
}
#endif

#endif
