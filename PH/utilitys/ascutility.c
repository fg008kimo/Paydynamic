#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include "ascutility.h"
#include "common.h"
#include "debug.h"
#include "dates.h"

char cDebug;


void leading_zero(char* pDest, const char* pSrc, short format_len)
{
	int field_len;
        field_len = strlen(pSrc);

	if (format_len >= field_len) {
        	memset(pDest, '0', format_len);
               		memcpy(&pDest[format_len - field_len], pSrc, field_len);
                        pDest[format_len] = '\0';
                } else {
                        memcpy(pDest, pSrc, format_len);
                        pDest[format_len] = '\0';
                }
}

void right_pad_space(char* pDest, const char* pSrc, short format_len)
{
    int field_len;
    field_len = strlen(pSrc);

	memset(pDest,' ',format_len);
	memcpy(&pDest[0],pSrc,field_len);
}


void trim_leading_zero(char* pDest, const char* pSrc)
{
                int i, j, srclen;

                srclen = strlen(pSrc);
                j=0;
                for(i=0; i<srclen; i++) {
                        if (memcmp(&pSrc[i], "0", 1) == 0) {
                                j++;
                        }
                        else
                                break;
                }
                memset(pDest, '0', j);
                memcpy(pDest, &pSrc[j], srclen - j);
                pDest[srclen - j] = '\0';
}

// Trim left
char    *TrimLeft(const unsigned char *p, int length)
{
        char *pTrim;

        short    org_len;

        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (*pTrim == ' ' || *pTrim == 0x00)) {
                        pTrim++;
                        org_len--;
                }
        }
        //pTrim[org_len] = '\0';

        return pTrim;
}

// Trim Right
char    *TrimRight(const unsigned char *p, int length)
{
        char    *pTrim;
        short   org_len;

        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (pTrim[org_len - 1] == ' ' || pTrim[org_len -1] == 0x00))
                        org_len--;
        }
        pTrim[org_len] = '\0';

        return pTrim;
}

// Trim Both sides
char    *TrimAll(const unsigned char *p, int length)
{
        char    *pTrim;

        pTrim = TrimLeft(p, length);
        pTrim = TrimRight((const unsigned char*)pTrim, strlen(pTrim));
        
        return pTrim;
}


// Trim left
char    *TrimLeftChar(const unsigned char *p, int length, char c)
{
        char *pTrim;

        short    org_len;

        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (*pTrim == c || *pTrim == 0x00)) {
                        pTrim++;
                        org_len--;
                }
        }
        //pTrim[org_len] = '\0';

        return pTrim;
}

// Trim Right
char    *TrimRightChar(const unsigned char *p, int length, char c)
{
        char    *pTrim;
        short   org_len;

        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (pTrim[org_len - 1] == c || pTrim[org_len -1] == 0x00))
                        org_len--;
        }
        pTrim[org_len] = '\0';

        return pTrim;
}

// Trim Both sides
char    *TrimAllChar(const unsigned char *p, int length,char c)
{
        char    *pTrim;

        pTrim = TrimLeftChar(p, length,c);
        pTrim = TrimRightChar((const unsigned char*)pTrim, strlen(pTrim),c);

        return pTrim;
}
unsigned char B2b(unsigned char B)
{
        if (B >= '0' && B <= '9')
                return B - '0';
        else
                return B - 'A' + 0xa;
}

unsigned char b2B(unsigned char b)
{
        if (b <= 9)
                return b + '0';
        else
                return b - 0xa + 'A';
}

void bcdpack(const unsigned char *src, unsigned char *dest, int len)
{
        int i,j;
        j = 0;
        for (i = 0; i < len; i+=2) {
                dest[j] = (B2b(src[i]) << 4) | (i+1 >= len ? 0 : B2b(src[i+1]) & 0x0f);
                j++;
        }
}

void bcdunpack(const unsigned char *src, unsigned char *dest, int len)
{
        int i;

        for (i = 0; i < len; i++) {
                dest[2 * i] = b2B((src[i] >> 4) & 0x0f);
                dest[2 * i + 1] = b2B(src[i] & 0x0f);
        }
}

void binxor(unsigned char *buf, const unsigned char *mask, int len)
{
        int     i;
        for (i = 0; i < len; i++) {
                buf[i] ^= mask[i];
        }
}



void Hex2Ascii(char *outstr, unsigned char *instr, int len)
{
	int i;

	for (i=0; i<len; i++)
		sprintf(outstr+(2*i), "%02X", *(instr+i));
}


int
htoa(char c)
{
	if(c >= '0' && c <= '9')
		return c - '0';
    if(c >= 'a' && c <= 'f')
		return 10 + c - 'a';
    if(c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    return -1;
}

void
Ascii2Hex(char *result,char *cp,int cnt)
{
	while(cnt-- != 0){
		*result = htoa(*cp++) << 4;
        *result++ |= htoa(*cp++);
    }
}

void Octets2Ascii(char *outstr, unsigned instr[], int len)
{
	int i;

	for (i=0; i<len; i++) {
		sprintf(outstr+(8*i), "%08X", instr[i]);
	}
}

static char *nextdelimit(char * start, char * delstr);
static int isdelimit(char c, char *delstr);

char *mystrtok(char *str, char *delstr)
{
        static  char *lastp = NULL;
        char    *rp;

        if (str != NULL) {
                rp = str;
        }
        else {
                if (lastp == NULL)
                        return NULL;
                rp = lastp + 1;
        }
        lastp = nextdelimit(rp, delstr);
        return rp;
}

static char *nextdelimit(char * start, char * delstr)
{
        char *p;

        p = start;
        while (*p != 0x00 && !isdelimit(*p, delstr)) {
                p++;
	}
        if (*p == 0x00)
                return NULL;
        else {
                *p = 0x00;
                return p;
        }
}

static int isdelimit(char c, char *delstr)
{
        if (strchr(delstr,c) != NULL)
                return 1;
        else
                return 0;
}

// SwapOE
char    *SwapOE(const unsigned char *p, int length)
{
        char    *csTmp;
        int     i;
	csTmp = (char*) malloc (length +1);
        for (i = 0; i < length; i++) {
                if (i%2 ==0 )
                        csTmp[i] = p[i+1];
                else
                        csTmp[i] = p[i-1];
        }
        return csTmp;
}

char* GetField(const unsigned char *inMsg,const char* fName,const char* DL, const char* FD)
{

        char*   csRet = NULL;
        char    *csBuf;

        char    *p;

        csBuf = (char*) malloc (4096 +1);

        strcpy(csBuf,(const char*)inMsg);

        p = strtok(csBuf,DL);
        if (p != NULL)
        {
                csRet = ParseMyField(p,fName,FD);
        }

        while (((p = strtok(NULL,DL)) != NULL) && csRet == NULL) {
                csRet = ParseMyField(p,fName,FD);

        }

        free(csBuf);
        csBuf = NULL;
        return  csRet;
}


char* ParseMyField(const char* inMsg,const char* fName,const char* FD)
{
        char    *csTag;
        char    *csValue;
        char    *csTmp;

        char    *p;


        csTmp = (char*) malloc(4096 +1);
        strcpy(csTmp,inMsg);

        p = strstr(csTmp,FD);
	if (p) {
        	if (strlen(p) > strlen(FD)) {
               		csTag = (char*) malloc (1024 +1);

                	csValue = strdup(p+1);
                	memcpy(csTag,inMsg,strlen(inMsg) - strlen(p));
                	csTag[strlen(inMsg) - strlen(p)] = '\0';

                	if (!strcmp(csTag,fName)) {
                       		free(csTmp);
                        	csTag = NULL;
                        	free(csTag);
                        	csTag = NULL;
                        	return csValue;
                	}
        		free(csTag);
        		csTag = NULL;
        	}
	}
        free(csTmp);
        csTmp = NULL;
        return NULL;
}
void U2L(const char* in, const int length_in, char* out)
{
	int counter = 0;
	while (in[counter])
	{
		out[counter]=tolower(in[counter]);
		counter++;
	}
	out[length_in] = '\0';
	
}

void L2U(const char* in, const int length_in, char* out)
{
	int counter = 0;
	while (in[counter])
	{
		out[counter]=toupper(in[counter]);
		counter++;
	}
	out[length_in] = '\0';
}

char* deleteCharacters(char * str, char * charSet)
{
	int hash [256];
	int i;
	if(NULL == charSet)
		return str;

	for(i = 0; i < 256; i++) {
		hash[i] = 0;
	}

	for(i = 0; i < strlen(charSet); i++)
		hash[(int)charSet[i]] = 1;

	int currentIndex = 0;
	for(i = 0; i < strlen(str); i++)
	{
		if(!hash[(int)str[i]])
		str[currentIndex++] = str[i];
	}
	str[currentIndex] = '\0';
	return str;
}
void Insert2Cls(hash_t* hOut,const char* inMsg,const char* FD)
{
        char    *csTag;
        char    *csValue;
        char    *csTmp;

        char    *p;


        csTmp = (char*) malloc(PD_TMP_MSG_BUF_LEN   +1);
        strcpy(csTmp,inMsg);

//DEBUGLOG(("whole inMsg = [%s]\n",csTmp));
        p = strstr(csTmp,FD);
        if (p) {
//DEBUGLOG(("p = [%s]\n",p));
        	if (strlen(p) > strlen(FD)) {
                	csTag = (char*) malloc (PD_TMP_MSG_BUF_LEN  +1);
                	csValue = strdup(p+1);
                	memcpy(csTag,inMsg,strlen(inMsg) - strlen(p));
                	csTag[strlen(inMsg) - strlen(p)] = '\0';
//DEBUGLOG(("Tag = [%s], Value = [%s]\n",csTag,csValue));
			PutField_CString(hOut,csTag,csValue);
//DEBUGLOG(("[%s] = [%s]\n",csTag,csValue));
			free(csTag);
			csTag = NULL;
			free(csValue);
			csValue = NULL;
        	}
        }
        free(csTmp);
        csTmp = NULL;
        //free(csTag);
        csTag = NULL;
}

int Str2Cls(hash_t* hOut,const char* inMsg, const char* DL, const char*  FD)
{
	char	*csBuf;
	char	*p;

	int inLen = strlen(inMsg);
	csBuf = (char*) malloc (inLen + 1);
	memcpy(csBuf,inMsg,inLen);
	csBuf[inLen] = '\0';

	p = strtok(csBuf,DL);
	if (p != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d) {
				p[strlen(p) -1] = '\0';
			}
			else
				p[strlen(p)] = '\0';
			Insert2Cls(hOut,p,FD);
		}
	}

	while ((p =strtok(NULL,DL)) != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d) {
				p[strlen(p) -1] = '\0';
			}
			else
				p[strlen(p)] = '\0';
			Insert2Cls(hOut,p,FD);
		}
        }

	free(csBuf);
	csBuf = NULL;
	return 0;
}
// Trim left
char    *TrimLeftCR(const unsigned char *p, int length)
{
        char *pTrim;

        short    org_len;

        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (*pTrim == 0x00 || *pTrim == 0x0d || *pTrim == 0x0a)) {
                        pTrim++;
                        org_len--;
                }
        }

        return pTrim;
}
// Trim Right
char    *TrimRightCR(const unsigned char *p, int length)
{       
        char    *pTrim;
        short   org_len; 
        
        pTrim = (char *) p;
        org_len = length;

        if (pTrim != NULL) {
                while (org_len > 0 && (pTrim[org_len -1] == 0x00 || pTrim[org_len -1] == 0x0d || pTrim[org_len -1] == 0x0a))
                        org_len--;
        }       
        pTrim[org_len] = '\0';

        return pTrim;
}

// Trim Both sides
char    *TrimAllCR(const unsigned char *p, int length)
{       
        char    *pTrim;
        
        pTrim = TrimLeftCR(p, length);
        pTrim = TrimRightCR((const unsigned char*)pTrim, strlen(pTrim));

        return pTrim;
}
void uxencode(char *outstr, unsigned char* instr, int len)
{
        int j=0;
        int i= 0;
        for(i = 0; i < len; i++)
        {
            outstr[j++] = (unsigned char)((instr[i] & 0xf) + 97);
            outstr[j++] = (unsigned char)(((unsigned int)instr[i] >> 4 & 0xf) + 97);
        }
}

void uxdecode(char* outstr, unsigned char* instr,int iLen)
{
        int len = iLen / 2;
        int i = 0;
        int j = 0;
        char    c;
        for(; i < len; i++)
        {
            c = ((instr[j++] - 97) & 0xf);
            c |= ((instr[j++] - 97) & 0xf) << 4;
            outstr[i] = c;
        }

}
char*	random_gen(int iLen) 
{
	int i;
	char 	*csResult;
	char	csList[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
	csResult = (char*) malloc (iLen +1);
	srand((unsigned)time(NULL)); 

	for ( i = 0; i < iLen; i++) {
                strncpy(&csResult[i],csList + (rand()%(strlen(csList))), 1);
        }

	return csResult;
}

char* GetXmlField(char* inStr, const char* inTag, const char inCloseTag)
{
	char* p;
        p = strstr(inStr, inTag);
        p += strlen(inTag);
        char *p2 = strchr(p,inCloseTag);
        p[strlen(p) - strlen(p2)] = '\0';

	return p;
}

char* stringLwr(char *s)
{
        char    *csTmp;
        int     i=0;
        int     cnt = 0;
        csTmp = (char*) malloc (strlen(s) +1);
        while(s[i]!='\0')
        {
                if(s[i]>='A' && s[i]<='Z'){
                        csTmp[i]=s[i]+32;
                        cnt ++;
                }
                ++i;
        }
        csTmp[cnt]='\0';
        return csTmp;
}

char* stringUpr(char *s)
{
        int i=0;
        char    *csTmp;
        int     cnt = 0;
        csTmp = (char*) malloc (strlen(s) +1);
        while(s[i]!='\0')
        {
                if(s[i]>='a' && s[i]<='z'){
                        csTmp[i]=s[i]-32;
                }
                ++i;
        }
        csTmp[cnt]='\0';
        return csTmp;
}
