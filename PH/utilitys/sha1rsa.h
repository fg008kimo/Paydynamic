#ifndef _SHA1RSA_H_
#define _SHA1RSA_H_

int sha1rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen);
int sha1rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen);

int public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted);
int private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted);
int private_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted);
int public_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted);

int MyRsa_Sign(FILE * privateKeyFP, char *inStr, char* outStr);
int MyRsa_Verify(FILE * publicKeyFP, char* inStr, int iLen, char* inSig);

int md5rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen);
int md5rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen);


int sha256rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen);
int sha256rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen);

void sha256sum(const char* in, const int length_in, char* out);
#endif
