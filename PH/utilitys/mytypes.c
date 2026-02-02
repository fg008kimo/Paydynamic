/*
PDProtech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProtech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/03/30              Cody Chan

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#include "utilitys.h"


void my_bytes_cat(char *srcString,my_bytes_t *dst)
{
	my_bytes_t	t;
	t = my_cstring_bytes(srcString);
        my_bytes_append(&t,dst);
}

void my_bytes_append(my_bytes_t *src, my_bytes_t *dst)
{
	char	*p;

  	dst->bytes = realloc(dst->bytes,dst->len + src->len +1);
//TXNLOG("my_bytes_append [%d] = [%d] + [%d] +1\n",dst->len + src->len, dst->len, src->len);
  	if (dst->bytes != NULL) {
		p = (char*) dst->bytes;
		memset(&p[dst->len],0,src->len);
    		memcpy(&p[dst->len], src->bytes, src->len);
		dst->len += src->len;
		p[dst->len] = '\0';
//dumphex(dst->bytes, dst->len);
  	}
	else {
ERRLOG("FETAIL ERROR: my_bytes_append failed\n");
ERRLOG("my_bytes_append [%d] = [%d] + [%d] +1\n",dst->len + src->len, dst->len, src->len);
	}
}


void my_bytes_dup(my_bytes_t src, my_bytes_t dst)
{

  	dst.bytes = malloc (src.len +1);
  	if (dst.bytes != NULL) {
		memset((char*)dst.bytes,0,sizeof(dst.bytes));
    		memcpy(dst.bytes, src.bytes, src.len);
		dst.len = src.len;
  	}
}

my_bytes_t *my_bytes_malloc_dup(my_bytes_t *src)
{

	my_bytes_t *dst;
	dst = malloc (sizeof(my_bytes_t*));
        dst->bytes = malloc (src->len +1);
        if (dst->bytes != NULL) {
		memset((char*)dst->bytes,0,sizeof(dst->bytes));
                memcpy(dst->bytes, src->bytes, src->len);
                dst->len = src->len;
        }
	return dst;
}

void my_bytes_msg_dup(my_bytes_t src,int iHeaderLen, my_bytes_t *dst)
{

	char	*p;
  	dst->bytes = malloc (src.len - iHeaderLen +1);
  	if (dst->bytes != NULL) {
		memset((char*) dst->bytes, 0, sizeof(dst->bytes));	
		p = src.bytes;
    		memcpy(dst->bytes, &p[iHeaderLen], dst->len);
		dst->len = src.len - iHeaderLen;
		p = dst->bytes;
		p[dst->len] = '\0';
  	}
}

my_bytes_t my_cstring_bytes(char const *cstr)
{
	my_bytes_t result;
  	result.len = strlen(cstr);
  	result.bytes = (void *) cstr;
  	return result;
}

/*

void my_bytes_malloc_append(my_bytes_t src, my_bytes_t dst)
{
	char	*t;

	t = (char*) malloc (src.len + dst.len + 1);
	
	if (t != NULL) {	
		memcpy(t, dst.bytes, dst.len);
		memcpy(&t[dst.len], src.bytes, src.len);

  		dst.bytes = realloc(dst.bytes,dst.len + src.len +1);
  		if (dst.bytes != NULL) {
    			memcpy(dst.bytes, t, src.len + dst.len);
			FREE_ME(t);
  		}
	}
}

*/

my_bytes_t* MyBytes_init()
{
        my_bytes_t * myBytes;
        myBytes = (my_bytes_t*) malloc (sizeof(my_bytes_t));
        myBytes->len = 0;
        myBytes->bytes = malloc (myBytes->len +1);
	memset(myBytes->bytes,0,myBytes->len);

        return myBytes;
}
