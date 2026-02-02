#ifndef _EMAIL_H_
#define _EMAIL_H_


#ifdef __cplusplus
extern "C" { 
#endif  


int CovertStingToEmailBody(const char* DATA,int iLen,char** payload_text,int *iIdx);

#ifdef __cplusplus
}       
#endif 
#endif

