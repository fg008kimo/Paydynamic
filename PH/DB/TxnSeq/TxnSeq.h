#ifndef _TXNSEQ_H_
#define _TXNSEQ_H_

#ifdef __cplusplus
extern "C" {
#endif
char* GetNextPspIdSeq(char* csPrefix);
char* GetNextTxnSeq();
char* GetNextBatchTxnSeq();
char* GetNextMmmTxnSeq();
char* GetNextMgtTxnSeq();
char* GetNextPayoutTxnSeq();
char* GetNextMiActionBatchSeq();
#ifdef __cplusplus
}
#endif

#endif
