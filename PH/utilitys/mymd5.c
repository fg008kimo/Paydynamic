/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/07/30              Cody Chan
add hmacmd5					   2011/11/22		   Cody Chan
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymd5.h"
#include "common.h"
#include "utilitys.h"
char	cDebug;

void md5sum(const char* in, const int length_in, char* out)
{
        MD5_CTX c;
        unsigned char buf[PD_MD5_SUM_LEN *2 +1];

        MD5_Init(&c);
        MD5_Update(&c, in, length_in);
        MD5_Final(buf, &c);

        Hex2Ascii(out,buf,PD_MD5_SUM_LEN /2 );
	out[PD_MD5_SUM_LEN] = '\0';
}

void
hmac_md5 (text, text_len, key, key_len, digest)
	unsigned char  *text;                /* pointer to data stream */
  	int             text_len;            /* length of data stream */
  	unsigned char  *key;                 /* pointer to authentication key */
  	int             key_len;             /* length of authentication key */
  	unsigned char  *digest;              /* caller digest to be filled in */
{

        unsigned char buf[PD_MD5_SUM_LEN *2 +1];

	MD5_CTX       context;
  	unsigned char k_ipad[65];    /* inner padding -
                                * key XORd with ipad
                                *                                 */
  	unsigned char k_opad[65];    /* outer padding -
                                * key XORd with opad
                                *                                 */
  	unsigned char tk[16];
  	int           i;


  	/* if key is longer than 64 bytes reset it to key=MD5(key) */
  	if (key_len > 64) {

    		MD5_CTX      tctx;

    		MD5_Init (&tctx);
    		MD5_Update (&tctx, key, key_len);
    		MD5_Final (tk, &tctx);

    		key     = tk;
    		key_len = 16;
  	}

  	/* start out by storing key in pads */
  	memset (k_ipad, '\0', sizeof (k_ipad));
  	memset (k_opad, '\0', sizeof (k_opad));
  	memcpy (k_ipad, key, key_len);
  	memcpy (k_opad, key, key_len);

  	/* XOR key with ipad and opad values */
  	for (i = 0; i < 64; i++) {
    		k_ipad[i] ^= 0x36;
    		k_opad[i] ^= 0x5c;
  	}

/*
 * perform inner MD5
 */
	MD5_Init (&context);                   /* init context for 1st
                                         * pass */
  	MD5_Update (&context, k_ipad, 64);     /* start with inner pad */
  	MD5_Update (&context, text, text_len); /* then text of datagram */
  	MD5_Final (buf, &context);          /* finish up 1st pass */
/*
 * perform outer MD5
 */
	MD5_Init (&context);                   /* init context for 2nd
                                         * pass */
  	MD5_Update (&context, k_opad, 64);     /* start with outer pad */
  	MD5_Update (&context, buf, 16);     /* then results of 1st
                                         * hash */
  	MD5_Final (buf, &context);          /* finish up 2nd pass */

        Hex2Ascii((char*)digest,buf,PD_MD5_SUM_LEN /2 );
	digest[PD_MD5_SUM_LEN] = '\0';
}

