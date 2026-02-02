/*
 * PDProtech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PayDynamic.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                       2018/05/11              Cody Chan
 *
 *  */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#include "utilitys.h"

char* ora_ESC_string(const char* buffer){
        int i,j;
        int l = strlen(buffer) + 1;
        char esc_char[]= {'\''};
        char essc_str[]= {'\''};
        char* dest  =  (char*)calloc( l*2,sizeof(char));
        char* ptr=dest;
        for(i=0;i<l;i++){
                for(j=0; j< 1 ;j++){
                        if( buffer[i]==esc_char[j] ){
                                *ptr++ = '\'';
                                *ptr++ = essc_str[j];
                                break;
                        }
                }
                if(j == 1 )
                *ptr++ = buffer[i];
        }
        *ptr='\0';
        return dest;
}
char* ESC_string(const char* buffer){
        int i,j;
        int l = strlen(buffer) + 1;
        char esc_char[]= { '\a','\b','\f','\n','\r','\t','\v','\\'};
        char essc_str[]= {  'a', 'b', 'f', 'n', 'r', 't', 'v','\\'};
        char* dest  =  (char*)calloc( l*2,sizeof(char));
        char* ptr=dest;
        for(i=0;i<l;i++){
                for(j=0; j< 8 ;j++){
                        if( buffer[i]==esc_char[j] ){
                                *ptr++ = '\\';
                                *ptr++ = essc_str[j];
                                break;
                        }
                }
                if(j == 8 )
                *ptr++ = buffer[i];
        }
        *ptr='\0';
	return ora_ESC_string(dest);
}

char *strmov(register char *dst, register const char *src)
{
        while ((*dst++ = *src++)) ;
                return dst-1;
}
