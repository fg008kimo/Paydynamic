
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "langconvert.h"
#include "common.h"
#include "debug.h"

#define MAX_UTF8_CHAR 	512
#define MAX_LOCAL_CHAR 	512
#define	MB_LEN_MAX 	3
char	cDebug;
//#define	MB_CUR_MAX	2
char errorstr[MAX_LOCAL_CHAR * 2]=" ";

char *code_convert(const char* FROM_CODE,const char* TO_CODE, char *utf8str)
{
	iconv_t cd;
	const char *inbuf;
   	char *outbuf;
	size_t inbytesleft, outbytesleft;

	cd = iconv_open(TO_CODE, FROM_CODE);
        if (cd == (iconv_t)-1) {
//DEBUGLOG(("not able to open\n"));
             return " ";
        }	
	inbuf = utf8str; inbytesleft = strlen(utf8str); 
//DEBUGLOG(("inbuf = [%s][%d]\n",inbuf,inbytesleft));
   	outbuf = errorstr; outbytesleft = sizeof(errorstr);	

	if (iconv(cd, (char**)&inbuf, &inbytesleft, &outbuf, &outbytesleft) == -1) 
       	{
//DEBUGLOG(("not able to convert[%d]\n",errno));
         	iconv_close(cd);
               	return utf8str;
        }
   	else 
      	{
//DEBUGLOG(("converted\n"));
              	iconv_close(cd);
//DEBUGLOG(("value = [%s][%d]\n",errorstr,sizeof(errorstr) - outbytesleft));
		errorstr[sizeof(errorstr) - outbytesleft] = '\0';
          	return errorstr;
      	}
}

