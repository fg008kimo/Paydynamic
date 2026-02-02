#ifndef _RSA_H_
#define _RSA_H_

int myRSA_public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted);
int myRSA_private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted);
int myRSA_public_encrypt_with_mode(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, int padding);
int myRSA_private_decrypt_with_mode(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted, int padding);
int myRSA_private_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted);
int myRSA_public_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted);
int myRSA_private_encrypt_with_mode(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, int padding);
int myRSA_public_decrypt_with_mode(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted, int padding);

int myRSA_sign(unsigned char* csData,int iDataLen,unsigned char* csPrivateKey,unsigned char* csSign, unsigned int *iSignLen);
int myRSA_verify(unsigned char* csData,int iDataLen,unsigned char* csPublicKey,unsigned char* csSign, unsigned int iSignLen);

int myRSA_ECB_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, unsigned int * encrypted_len);

int md5rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen);
int md5rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen);

int sha1rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen);
int sha1rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen);

int sha256rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen);
int sha256rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen);

#endif
