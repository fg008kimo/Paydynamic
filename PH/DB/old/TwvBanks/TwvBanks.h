#ifndef _TWV_BANKS_H_
#define _TWV_BANKS_H_

#ifdef __cplusplus
extern "C" {
#endif

//int Add(const hash_t *);
//int Delete(const unsigned char* psp_id, const unsigned char* url);
int GetBankName_CH(const char* csBankCode, char* csBankName);
int GetBankCode_CH(const char* csBankName, char *csBankCode);
#ifdef __cplusplus
}
#endif

#endif
