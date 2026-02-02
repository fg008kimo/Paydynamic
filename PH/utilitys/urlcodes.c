/*
 * Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of Partnerdelight.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                       2012/05/18              Cody Chan
 *
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "urlcodes.h"
#include "debug.h"


int urldecode(const unsigned char* csSrc, int iLen,unsigned char* csDst, int *oLen)
{
	int i,j;

        i = 0;
        j = 0;
        for (;i < iLen;) {
                if( csSrc[i] == '%' ){
                        int c1, c2;
                        c1 = csSrc[i+1];
                        c2 = csSrc[i+2];

                        if( isxdigit(c1) && isxdigit(c2) ){

                                /* Valid %HH sequence found. */

                                c1 = tolower(c1);
                                c2 = tolower(c2);

                                if( c1 <= '9' )
                                        c1 = c1 - '0';
                                else
                                        c1 = c1 - 'a' + 10;
                                if( c2 <= '9' )
                                        c2 = c2 - '0';
                                else
                                        c2 = c2 - 'a' + 10;

                                csDst[j] = ( 16 * c1 + c2 );
                                j++;
                                i = i+3;

                        } else {

                                i++;
                                /* Invalid or incomplete sequence. */
                                csDst[j] = '%';
                                j++;
                        }

                } else if( csSrc[i] == '+' ){
                        i++;
                        csDst[j] = ' ';
                        j++;

                } else {
                        csDst[j] = csSrc[i];
                        i++;
                        j++;

                }
        }
	
	csDst[j] = '\0';
	*oLen = j;
	return 0;
}

char to_hex(char code) {
	static char hex[] = "0123456789abcdef";
  	return hex[code & 15];
}

char *url_encode(char *str) {
	char *pstr = str, *buf = malloc(strlen(str) * 3 + 1), *pbuf = buf;
  	while (*pstr) {
    		if (isalnum(*pstr) || *pstr == '-' || *pstr == '_' || *pstr == '.' || *pstr == '~') 
      			*pbuf++ = *pstr;
    		else if (*pstr == ' ') 
      			*pbuf++ = '+';
    		else 
      			*pbuf++ = '%', *pbuf++ = to_hex(*pstr >> 4), *pbuf++ = to_hex(*pstr & 15);
    		pstr++;
  	}
  	*pbuf = '\0';
  	return buf;
}
