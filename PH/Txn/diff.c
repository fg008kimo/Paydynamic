7,9c7
< Init Version                                       2011/07/18              LokMan Chow
< Call BOTxnElements and get open_bal		   2012/02/03		   LokMan Chow
< Not allow to reverse after recon		   2012/04/10		   Virginia Yun
---
> Init Version                                       2012/12/05              LokMan Chow
19c17
< #include "TxnMgtByUsVDS.h"
---
> #include "TxnMgtByUsVDR.h"
29c27
< void TxnMgtByUsVDS(char    cdebug)
---
> void TxnMgtByUsVDR(char    cdebug)
61d58
< 	int	iReturnMerchFee = PD_FALSE;
73c70
< DEBUGLOG(("TxnMgtByUsVDS: Authroize()\n"));
---
> DEBUGLOG(("TxnMgtByUsVDR: Authroize()\n"));
154c151
< ERRLOG("TxnMgtByUsVDS:Authorize::GetTxnHeader::not found record!!\n");
---
> ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnHeader::not found record!!\n");
207c204
< ERRLOG("TxnMgtByUsVDS:Authorize::GetTxnDetail:: not found record!!\n");
---
> ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnDetail:: not found record!!\n");
286c283
< ERRLOG("TxnMgtByUsVDS:Authorize::GetTxnDetail:: not found record!!\n");
---
> ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnDetail:: not found record!!\n");
302c299
< 	if (iRet == PD_OK && iReturnMerchFee == PD_TRUE) {
---
> 	if (iRet == PD_OK) {
321a319
> 		PutField_CString(hContext,"txn_code",PD_VOID_TXN_CODE);
332,333c330
< 				if(iReturnMerchFee == PD_TRUE){
< 					PutField_Double(hContext,"net_amt",(dTmp-dPreFee));
---
> 				PutField_Double(hContext,"net_amt",(dTmp-dPreFee));
335c332
< 				}
---
> 				
346c343
< ERRLOG("TxnMgtByUsVDS:Authorize::BOFee:GetTxnFee Error\n");
---
> ERRLOG("TxnMgtByUsVDR:Authorize::BOFee:GetTxnFee Error\n");
360,365c357,362
< 		if(iReturnPspFee==PD_FALSE){
< 			dServiceFee = 0.0;
< 		}
< 		else{
< 			char	csRemark[PD_REMARK_LEN+1];
< 			if (GetField_Double(hContext,"actual_psp_fee",&dServiceFee)) {
---
>                 if(iReturnPspFee==PD_FALSE){
>                         dServiceFee = 0.0;
>                 }
>                 else{
> 			char    csRemark[PD_REMARK_LEN+1];
>                         if (GetField_Double(hContext,"actual_psp_fee",&dServiceFee)) {
368,373c365,370
< 				PutField_CString(hContext,"remark",csRemark);
< 			}
< 		}
< 		PutField_Double(hContext,"precal_fee",dServiceFee);
< 		PutField_Double(hContext,"service_fee",dServiceFee);
< 	}
---
>                                 PutField_CString(hContext,"remark",csRemark);
>                         }
>                 }
>                 PutField_Double(hContext,"precal_fee",dServiceFee);
>                 PutField_Double(hContext,"service_fee",dServiceFee);
>         }
424c421
< 		PutField_CString(hContext,"desc","Void Deposit");
---
> 		PutField_CString(hContext,"desc","Void Deposit with merchant fee");
