#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/cmac.h>
#include "common.h"
#include "utilitys.h"
#include <openssl/evp.h>

char    cDebug;

int myAES_encrypt(const unsigned char* csText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen)
{
	unsigned char iv[AES_BLOCK_SIZE];
	memset(iv, 0x00, AES_BLOCK_SIZE);

	char	Text[strlen((const char*)csText)];
	char	Key[strlen((const char*)csKey)];
	strcpy(Text,(const char*)csText);
	strcpy(Key,(const char*)csKey);
	AES_KEY enc_key;
	AES_set_encrypt_key((const unsigned char*)Key, sizeof(Key)*8, &enc_key);
	//AES_cbc_encrypt((const unsigned char*)Text, csOut, sizeof(Text), &enc_key, iv, AES_ENCRYPT);
	AES_ecb_encrypt((const unsigned char*)Text, csOut, &enc_key, AES_ENCRYPT);

	*iOutLen = sizeof(csOut);
	if (*iOutLen >0) 
		return PD_OK;
	else
		return PD_ERR;
}

int myAES_decrypt(const unsigned char* csEncText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen)
{
	unsigned char iv[AES_BLOCK_SIZE];
	memset(iv, 0x00, AES_BLOCK_SIZE);

	AES_KEY dec_key;
	AES_set_decrypt_key(csKey, sizeof(csKey)*8, &dec_key);
	AES_cbc_encrypt(csEncText, csOut, sizeof(csEncText), &dec_key, iv, AES_DECRYPT);
	*iOutLen = sizeof(csOut);
	if (iOutLen >0) 
		return PD_OK;
	else
		return PD_ERR;
}


int myAES_ECB_encrypt(const unsigned char* csText, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen)
{
	//unsigned char outbuf[PD_TMP_MSG_BUF_LEN];
	int outlen, tmplen;

	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	EVP_CIPHER_CTX_set_padding(&ctx, 1);

	EVP_EncryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, csKey, NULL);
	if(!EVP_EncryptUpdate(&ctx, csOut, &outlen, csText, strlen((const char*)csText))) {
//DEBUGLOG(("EVP_EncryptUpdate Error\n"));
		return PD_ERR;
	}
/* Buffer passed to EVP_EncryptFinal() must be after data just
 * encrypted to avoid overwriting it.
 */
	if(!EVP_EncryptFinal_ex(&ctx, csOut + outlen , &tmplen))
	{
//DEBUGLOG(("EVP_EncryptFinal_ex Error\n"));
		return PD_ERR;
	}
	outlen += tmplen;
	*iOutLen = outlen;
	EVP_CIPHER_CTX_cleanup(&ctx);

	//base64_encode(outbuf,outlen, (char*)csOut,PD_TMP_MSG_BUF_LEN);

	return PD_OK;

}

int myAES_ECB_decrypt(const unsigned char* csText, const int iTextLen, const unsigned char* csKey,unsigned char* csOut, unsigned int *iOutLen)
{
	int outlen, tmplen;

	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	EVP_CIPHER_CTX_set_padding(&ctx, 1);

	EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, csKey, NULL);
	if(!EVP_DecryptUpdate(&ctx, csOut, &outlen, csText, iTextLen)) {
		return PD_ERR;
	}
/* Buffer passed to EVP_EncryptFinal() must be after data just
 * encrypted to avoid overwriting it.
 */
	if(!EVP_DecryptFinal_ex(&ctx, csOut + outlen , &tmplen))
	{
		return PD_ERR;
	}
	outlen += tmplen;
	*iOutLen = outlen;
	EVP_CIPHER_CTX_cleanup(&ctx);


	return PD_OK;

}

void AES_CMAC ( unsigned char *key, unsigned char *input, int length,
                  unsigned char *mac , long unsigned *iMacLen)
{

	*iMacLen = 0;
        CMAC_CTX *ctx;
        ctx = CMAC_CTX_new();
        unsigned char csPackedKey[32];

        Ascii2Hex((char*)csPackedKey,(char*)key,strlen((const char*)key));
	switch (strlen((const char*)key)) {
    		case 32:
        		//CMAC_Init(ctx, key, 16, EVP_aes_128_cbc(), NULL);
        		CMAC_Init(ctx, csPackedKey, 16, EVP_aes_128_cbc(), NULL);
      			break;
    		case 64:
        		//CMAC_Init(ctx, key, 32, EVP_aes_256_cbc(), NULL);
        		CMAC_Init(ctx, csPackedKey, 32, EVP_aes_256_cbc(), NULL);
      			break;
    		default:
      			return;
	}

        CMAC_Update(ctx, input, strlen((const char*)input));
        CMAC_Final(ctx, mac, iMacLen);
        return;
}
