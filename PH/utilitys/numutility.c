#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#include "utilitys.h"
#include "common.h"
#include "comutil.h"


int hex2int(unsigned char *datain, int numbyte)
{
	int i;
	int x=1, out=0;
	for(i=numbyte-1;i>=0;i--)
	{
		out += (datain[i]* x);
		x = x * 256;
	}
	return out;
}

void int2hex(int source, unsigned char *target, int targetlen)
{
      int i=0;
      for (i=targetlen-1; i>=0; i--)
      {
        target [i] = source % 256;
		source = source / 256;
      }
}

long hex2long(unsigned char *datain, int numbyte)
{
	int i;
	long x=1, out=0;
	for(i=numbyte-1;i>=0;i--)
	{
		out += (datain[i]* x);
		x = x * 256;
	}
	return out;
}

void long2hex(long source, unsigned char *target, int targetlen)
{
      int i=0;
      for (i=targetlen-1; i>=0; i--)
      {
        target [i] = source % 256;
		source = source / 256;
      }
}


short ctos(const unsigned char *data, int len)
{
        int     i;
        short   res;

        res = 0;
        for (i = 0; i < len; i++)
                res = res * 10 + data[i] - '0';
        return res;
}
long ctol(const unsigned char *data, int len)
{
        int     i;
        long res;

        res = 0;
        for (i = 0; i < len; i++)
                res = res * 10 + data[i] - '0';
        return res;
}
void stoc(const short data, int len, unsigned char *buf)
{
        unsigned char *tmp;
        tmp = (unsigned char *) malloc (len + 1);
        if (tmp != NULL) {
                sprintf((char *) tmp,"%0*hd",len,data);
                memcpy(buf, tmp, len);
                buf[len] = '\0';
                free (tmp);
                tmp = NULL;
        }
}       

void ltoc(const long data, int len, unsigned char *buf)
{       
        unsigned char *tmp; 
        tmp = (unsigned char *) malloc (len + 1);
        if (tmp != NULL) {
                sprintf((char *) tmp,"%0*ld",len,data);
                memcpy(buf, tmp, len);
                buf[len] = '\0';
                free (tmp); 
                tmp = NULL;
        }
}    
void dtoc(const double data, int digit, int decimal, unsigned char *buf)
{
        unsigned char *csTmp;
        csTmp = (unsigned char *) malloc (digit + decimal + 1);
        if (csTmp != NULL) {
                sprintf((char *) csTmp,"%0*.0f",digit+decimal,data);
                memcpy(buf, csTmp, digit + decimal);
                buf[digit + decimal] = '\0';
                free ((void*)csTmp);
                csTmp = NULL;
        }
}   

double ctod(const unsigned char *data, int digit, int decimal)
{
        int i;
        double res;
        res = 0.0;
        for (i = 0; i < digit + decimal; i++) {
                res = data[i] - '0' + res * 10.0;
        }
        return res;
}


double newtrunc(double amt, int dec)
{
        char    temp[128];
        double  db;
        int     i;
		char	*p;

        sprintf(temp, "%f", amt);

        p = (char*)strchr(temp, '.');

        if (p == NULL) /* No decimal point */
                return amt;

        /* Find the first dec+1 digit after the decimal point */
        for (i = 0; i < dec + 1; i++) {
                p++;
                if (p == NULL && i <= dec) /* Within dec decimal points */
                        return amt;
        }

        /* Now at the dec + 1 digits */
        *p = '\0';
        sscanf(temp, "%lf", &db);
        return db;
}

double newround(double amt, int dec)
{
        char    temp[128];
        char    *p;
        double  db, rounding;
        int             i;
        char    sign;

        sprintf(temp, "%f", amt);
        sign = *temp;

        p = (char*)strchr(temp, '.');
        if (p == NULL) /* No decimal point */
                return amt;

        /* Find the first dec+1 digit after the decimal point */
        for (i = 0; i < dec + 1; i++) {
                p++;
                if (p == NULL && i <= dec) /* Within dec decimal points */
                        return amt;
        }

        /* Now at the dec + 1 digits */
        if (*p >= '5') {
                *p = '\0';
                sscanf(temp, "%lf", &db);
                rounding = 1;
                for (i = 0; i < dec; i++)
                        rounding = rounding * 0.1;
                if (sign == '-')
                        db = db - rounding;
                else
                        db = db + rounding;
        }
        else {
                *p = '\0';
				 sscanf(temp, "%lf", &db);
        }
        return db;
}



double newceling(double amt, int dec)
{
        char    temp[128];
        char    csRemain[64];
        char    *p;
        double  db, rounding;
        int             i;
        char    sign;
        long lRemain;

        sprintf(temp, "%f", amt);
        sign = *temp;

        p = (char*)strchr(temp, '.');

        if (p == NULL) /* No decimal point */
                return amt;

        /* Find the first dec+1 digit after the decimal point */
        for (i = 0; i < dec + 1; i++) {
                p++;
                if (p == NULL && i <= dec) /* Within dec decimal points */
                        return amt;
        }
        memcpy(csRemain,p,strlen(p));
        csRemain[strlen(p)] = '\0';
//        printf("remain = [%s]\n",csRemain);

        if (p != NULL )
                sscanf(csRemain, "%ld",&lRemain);

        /* Now at the dec + 1 digits */
        if (lRemain > 0) {
                *p = '\0';
                sscanf(temp, "%lf", &db);
                rounding = 1;
                for (i = 0; i < dec; i++)
                        rounding = rounding * 0.1;
                if (sign == '-')
                        db = db - rounding;
                else
                        db = db + rounding;
        }
        else {
                *p = '\0';
                                 sscanf(temp, "%lf", &db);
        }
        return db;
}
void mydtoc(const double data, int digit, int decimal, unsigned char *buf)
{
        unsigned char *tmp;
        tmp = (unsigned char *) malloc (digit + decimal + 1);
        if (tmp != NULL) {
                sprintf((char *) tmp,"%0*.0f",digit+decimal,data * pow(10, decimal));
                strcpy((char*)buf, (const char*)tmp);
                free (tmp);
                tmp = NULL;
        }
}
double myctod(const unsigned char *data, int digit, int decimal)
{
        int i;
        double res;
        res = 0.0;
        for (i = 0; i < digit + decimal; i++) {
                res = data[i] - '0' + res * 10.0;
        }
        res = res / (pow(10, decimal));
        return res;
}
long	double2long(double dValue) 
{

	long lVal;

	lVal = (dValue * 200 +1) /2;

	return lVal;
}

double string2double(const unsigned char *data)
{
	char    *p;
	double	dTmp=0.0;

	p = (char*)strchr((const char *)data, '.');
	if (p == NULL){
		if(is_numeric((char*)data)!=PD_FALSE){
			if(sscanf((const char *)data,"%lf",&dTmp)==1){
				return dTmp;
			}
		}
	}
	else{
		if(sscanf((const char *)data,"%lf",&dTmp)==1){
			return dTmp;
		}
	}

	return dTmp;
}


double string2doublewithsign(const unsigned char *data)
{
	char csTmp[PD_TMP_BUF_LEN];
	int iLen = strlen((const char *)data);

	if (data[0] != '-')
	{
		return string2double(data);
	} else {
		memcpy(csTmp, &data[1], iLen-1);

		csTmp[iLen-1] = '\0';
		return (string2double((const unsigned char *)csTmp) * (-1.0));
	}
}


char *commaprint(unsigned long n)
{
        static int comma = '\0';
        static char retbuf[30];
        char *p = &retbuf[sizeof(retbuf)-1];
        int i = 0;

        if(comma == '\0') {
                struct lconv *lcp = localeconv();
                if(lcp != NULL) {
                        if(lcp->thousands_sep != NULL &&
                                *lcp->thousands_sep != '\0')
                                comma = *lcp->thousands_sep;
                        else    comma = ',';
                }
        }

        *p = '\0';

        do {
                if(i%3 == 0 && i != 0)
                        *--p = comma;
                *--p = '0' + n % 10;
                n /= 10;
                i++;
        } while(n != 0);

        return p;
}

char *commaprintdouble(double d,int dLen)
{
        char    csTmp[30];
        static char retbuf[30];
        char *p = &retbuf[sizeof(retbuf)-1];
        unsigned long n = d ;

        double dLeft = d - (double)n;
        sprintf(csTmp,"%.*f",dLen,dLeft);
        sprintf(p,"%s%s",commaprint(n),&csTmp[1]);

	return p;
}

int num_of_decimal_places(const char *data)
{
        int i = 0, j = 0;
	int go = 0;

        while (*data) {
                if (*data >= '0' && *data <= '9' && go == 1) {
                        if (*data == '0') {
                                j++;
                        } else {
                                i += j + 1;
                                j = 0;
                        }
                } else if (go == 0) {
                        if (*data == '.') {
                                go = 1;
                        }
                } else {
                        return i;
                }
                data++;
        }

        return i;
}

