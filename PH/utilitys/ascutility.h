#ifndef	_ASCUTILITY_H_
#define	_ASCUTILITY_H_

#include "myhash.h"

#ifdef __cplusplus
extern "C" { 
#endif  


void  leading_zero(char* pDest, const char* pSrc, short format_len);

void right_pad_space(char* pDest, const char* pSrc, short format_len);

void  trim_leading_space(char* pDest, const char* pSrc);
void trim_leading_zero(char* pDest, const char* pSrc);

char  *TrimLeft(const unsigned char *p, int length);
char  *TrimRight(const unsigned char *p, int length);
char  *TrimAll(const unsigned char *p, int length);
char  *TrimLeftChar(const unsigned char *p, int length,char c);
char  *TrimRightChar(const unsigned char *p, int length,char c);
char  *TrimAllChar(const unsigned char *p, int length,char c);
char  *TrimLeftCR(const unsigned char *p, int length);
char  *TrimRightCR(const unsigned char *p, int length);
char  *TrimAllCR(const unsigned char *p, int length);


void Hex2Ascii(char *outstr, unsigned char *instr, int len);
int htoa(char c);
void Ascii2Hex(char *result,char *cp,int cnt);
void Octets2Ascii(char *outstr, unsigned instr[], int len);

unsigned char B2b(unsigned char B);
unsigned char b2B(unsigned char b);
void bcdpack(const unsigned char *src, unsigned char *dest, int len);
void bcdunpack(const unsigned char *src, unsigned char *dest, int len);
void binxor(unsigned char *buf, const unsigned char *mask, int len);
char *mystrtok(char *str, char *delstr);
char    *SwapOE(const unsigned char *p, int length);
char* GetField(const unsigned char *inMsg,const char* fName,const char* DL, const char* FD);
void L2U(const char* in, const int length_in, char* out);
void U2L(const char* in, const int length_in, char* out);
char* deleteCharacters(char * str, char * charSet);
char* ParseMyField(const char* inMsg,const char* fName,const char* FD);
int Str2Cls(hash_t* hOut,const char* inMsg, const char* DL, const char*  FD);
void uxencode(char *outstr, unsigned char* instr, int len);
void uxdecode(char* outstr, unsigned char* instr,int iLen);
char*   random_gen(int iLen);
char* GetXmlField(char* inStr, const char* inTag, const char inCloseTag);
char* stringLwr(char *s);
char* stringUpr(char *s);

#ifdef __cplusplus
}       
#endif
#endif

