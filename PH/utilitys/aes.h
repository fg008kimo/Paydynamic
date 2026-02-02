#ifndef _AES_H_
#define _AES_H_

int myAES_encrypt(const unsigned char* csText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen);
int myAES_decrypt(const unsigned char* csEncText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen);

int myAES_ECB_encrypt(const unsigned char* csText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen);
int myAES_ECB_decrypt(const unsigned char* csText, const int iTextLen, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen);

void AES_CMAC ( unsigned char *key, unsigned char *input, int length, unsigned char *mac , long unsigned *iMacLen);
#endif
