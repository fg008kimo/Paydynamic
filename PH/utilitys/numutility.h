#ifndef	_NUMUTILITY_H_
#define	_NUMUTILITY_H_


#ifdef __cplusplus
extern "C" { 
#endif  

int hex2int(unsigned char *datain, int numbyte);

void int2hex(int source, unsigned char *target, int targetlen);

long hex2long(unsigned char *datain, int numbyte);

void long2hex(long source, unsigned char *target, int targetlen);


short ctos(const unsigned char *data, int len);

long  ctol(const unsigned char *data, int len);

void  stoc(const short data, int len, unsigned char *buf);

void  ltoc(const long data, int len, unsigned char *buf);

void dtoc(const double data, int digit, int decimal, unsigned char *buf);
double ctod(const unsigned char *data, int digit, int decimal);

double newtrunc(double amt, int dec);
double newround(double amt, int dec);
double newceling(double amt, int dec);
void mydtoc(const double data, int digit, int decimal, unsigned char *buf);
double myctod(const unsigned char *data, int digit, int decimal);
long	double2long(double dVal);
double string2double(const unsigned char *data);
double string2doublewithsign(const unsigned char *data);

char *commaprint(unsigned long n);
char *commaprintdouble(double d,int dLen);

int num_of_decimal_places(const char *data);

#ifdef __cplusplus
}       
#endif  
#endif

