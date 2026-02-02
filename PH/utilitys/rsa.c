
#include <stdio.h>
#include <string.h>
#include <error.h>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/pkcs12.h>
#include <openssl/ocsp.h>
#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/objects.h>
#include "utilitys.h"
#include "internal.h"
#include "common.h"
#include "rsa.h"

int padding = RSA_PKCS1_PADDING;
char	cDebug;


RSA * createRSA(unsigned char * key,int public);

int myRSA_public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted)
{
    RSA * rsa = createRSA(key,1);
    int result = RSA_public_encrypt(data_len,data,encrypted,rsa,padding);
    return result;
}
int myRSA_private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted)
{
    RSA * rsa = createRSA(key,0);
    int  result = RSA_private_decrypt(data_len,enc_data,decrypted,rsa,padding);
    return result;
}


int myRSA_public_encrypt_with_mode(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, int padding)
{
    RSA * rsa = createRSA(key,1);
    int result = RSA_public_encrypt(data_len,data,encrypted,rsa,padding);
    return result;
}
int myRSA_private_decrypt_with_mode(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted, int padding)
{
    RSA * rsa = createRSA(key,0);
    int  result = RSA_private_decrypt(data_len,enc_data,decrypted,rsa,padding);
    return result;
}


int myRSA_private_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted)
{
    RSA * rsa = createRSA(key,0);
    int result = RSA_private_encrypt(data_len,data,encrypted,rsa,padding);
    return result;
}
int myRSA_public_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted)
{
    RSA * rsa = createRSA(key,1);
    int  result = RSA_public_decrypt(data_len,enc_data,decrypted,rsa,padding);
    return result;
}


int myRSA_private_encrypt_with_mode(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, int padding)
{
    RSA * rsa = createRSA(key,0);
    int result = RSA_private_encrypt(data_len,data,encrypted,rsa,padding);
    return result;
}
int myRSA_public_decrypt_with_mode(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted, int padding)
{
    RSA * rsa = createRSA(key,1);
    int  result = RSA_public_decrypt(data_len,enc_data,decrypted,rsa,padding);
    return result;
}


RSA * createRSA(unsigned char * key,int public)
{
    RSA *rsa= NULL;
    BIO *keybio ;

    keybio = BIO_new_mem_buf(key, -1);
    if (keybio==NULL)
    {
        return 0;
    }
    if(public)
    {
        rsa = PEM_read_bio_RSA_PUBKEY(keybio, &rsa,NULL, NULL);
    }
    else
    {
        rsa = PEM_read_bio_RSAPrivateKey(keybio, &rsa,NULL, NULL);
    }
    if(rsa == NULL)
    {
	    char buffer[500];
	    ERR_error_string(ERR_get_error(), buffer);
    }

    return rsa;
}

int myRSA_sign(unsigned char* csData,int iDataLen,unsigned char* csPrivateKey,unsigned char* csSign, unsigned int *iSignLen)
{
	unsigned char* signature;
	RSA *private_key;
        BIO *priv_bio;

	priv_bio = BIO_new_mem_buf(csPrivateKey, -1);
   	if(priv_bio == NULL) {
      		ERR_print_errors_fp(stdout);
      		return PD_ERR;
   	}	
	private_key = PEM_read_bio_RSAPrivateKey(priv_bio, NULL, NULL, NULL);
   	if(private_key == NULL) {
      		ERR_print_errors_fp(stdout);
		return PD_ERR;
   	}

	signature = (unsigned char*) malloc(RSA_size(private_key));
        if(RSA_sign(NID_md5, csData, iDataLen, signature, iSignLen, private_key) != 1) {
                ERR_print_errors_fp(stdout);
		return PD_ERR;
        }
	else {
		memcpy(csSign,signature,*iSignLen);
	}

	return PD_OK;
}

int myRSA_verify(unsigned char* csData,int iDataLen,unsigned char* csPublicKey,unsigned char* csSign, unsigned int iSignLen)
{
	RSA *public_key;
        BIO *pub_bio;

	pub_bio = BIO_new_mem_buf(csPublicKey, -1);
        if(pub_bio == NULL) {
                ERR_print_errors_fp(stdout);
		return PD_ERR;
        }
	public_key = PEM_read_bio_RSA_PUBKEY(pub_bio, NULL, NULL, NULL);
   	if(public_key == NULL) {
      		ERR_print_errors_fp(stdout);
		return PD_ERR;
   	}

	if (RSA_verify(NID_md5, csData, iDataLen, csSign, iSignLen, public_key) == 1) {
		return PD_OK;
	}
	else {
		return PD_ERR;
	}
}

/*
int myRSA_ECB_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted, unsigned int * encrypted_len)
{
	EVP_PKEY_CTX *ctx;
	//unsigned char *out;
	size_t outlen;
	int rc;

	BIO *pub_bio = BIO_new_mem_buf(key, -1);
	if(pub_bio == NULL)
	{
		return PD_ERR;
	}

	RSA *cipher;
	cipher = PEM_read_bio_RSA_PUBKEY(pub_bio, NULL, NULL, NULL);
	if(cipher == NULL){
		return PD_ERR;
	}
	EVP_PKEY *pkey  = EVP_PKEY_new();
	EVP_PKEY_set1_RSA(pkey, cipher);

	ctx = EVP_PKEY_CTX_new(pkey, NULL);
	if (!ctx) {
		return PD_ERR;
	}


	if (EVP_PKEY_encrypt_init(ctx) <= 0) {
		return PD_ERR;
	}
	if ((rc = EVP_PKEY_CTX_set_rsa_padding(ctx, padding)) <= 0) {
		return PD_ERR;
	}
	/// Determine buffer length
	if ((rc = EVP_PKEY_encrypt(ctx, NULL, &outlen, data, data_len)) <= 0) {
		return PD_ERR;
	}
	//out = OPENSSL_malloc(outlen);
	if ((rc = EVP_PKEY_encrypt(ctx, encrypted, &outlen, data, data_len)) <= 0) {
		return PD_ERR;
	}

	*encrypted_len = outlen;
	//strcpy((char*)encrypted,(const char*)out);

	//OPENSSL_free(out);
	EVP_PKEY_CTX_free(ctx);
	EVP_PKEY_free(pkey);
	return PD_OK;
}
*/


int md5rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *privkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	privkey = EVP_PKEY_new();
	if (privkey == 0) {
ERRLOG("md5rsa_sign: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("md5rsa_sign: Couldn't open RSA priv key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		privkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
		if (privkey == 0) {
ERRLOG("md5rsa_sign: Couldn't use RSA priv key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("md5rsa_sign: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignInit(ctx, NULL, EVP_md5(), NULL, privkey) == 0) {
ERRLOG("md5rsa_sign: Couldn't exec EVP_DigestSignInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("md5rsa_sign: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	unsigned int iTmp = 0;
	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, NULL, (size_t *)&iTmp) == 0) {
ERRLOG("md5rsa_sign: Couldn't calculate signature length.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	} 

	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, csSignData, (size_t *)&iTmp) == 0) {
ERRLOG("md5rsa_sign: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		} else {
			*iLen = iTmp;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(privkey);
	ERR_free_strings();
	return iRet;
}


int md5rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *pubkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	pubkey = EVP_PKEY_new();
	if (pubkey == 0) {
ERRLOG("md5rsa_verify: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("md5rsa_verify: Couldn't open RSA pub key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		pubkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
		if (pubkey == 0) {
ERRLOG("md5rsa_verify: Couldn't use RSA pub key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("md5rsa_verify: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyInit(ctx, NULL, EVP_md5(), NULL, pubkey) == 0) {
ERRLOG("md5rsa_verify: Couldn't exec EVP_DigestVerifyInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("md5rsa_verify: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyFinal(ctx, (unsigned char*)csSignData, iLen) == 0) {
ERRLOG("md5rsa_verify: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(pubkey);
	ERR_free_strings();
	return iRet;
}


int sha1rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *privkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	privkey = EVP_PKEY_new();
	if (privkey == 0) {
ERRLOG("sha1rsa_sign: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("sha1rsa_sign: Couldn't open RSA priv key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		privkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
		if (privkey == 0) {
ERRLOG("sha1rsa_sign: Couldn't use RSA priv key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("sha1rsa_sign: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignInit(ctx, NULL, EVP_sha1(), NULL, privkey) == 0) {
ERRLOG("sha1rsa_sign: Couldn't exec EVP_DigestSignInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("sha1rsa_sign: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	unsigned int iTmp = 0;
	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, NULL, (size_t *)&iTmp) == 0) {
ERRLOG("sha1rsa_sign: Couldn't calculate signature length.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	} 

	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, csSignData, (size_t *)&iTmp) == 0) {
ERRLOG("sha1rsa_sign: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		} else {
			*iLen = iTmp;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(privkey);
	ERR_free_strings();
	return iRet;
}


int sha1rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *pubkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	pubkey = EVP_PKEY_new();
	if (pubkey == 0) {
ERRLOG("sha1rsa_verify: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("sha1rsa_verify: Couldn't open RSA pub key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		pubkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
		if (pubkey == 0) {
ERRLOG("sha1rsa_verify: Couldn't use RSA pub key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("sha1rsa_verify: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyInit(ctx, NULL, EVP_sha1(), NULL, pubkey) == 0) {
ERRLOG("sha1rsa_verify: Couldn't exec EVP_DigestVerifyInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("sha1rsa_verify: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyFinal(ctx, (unsigned char*)csSignData, iLen) == 0) {
ERRLOG("sha1rsa_verify: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(pubkey);
	ERR_free_strings();
	return iRet;
}


int sha256rsa_sign_new(char *csRsaPem, char *csData, unsigned char *csSignData, unsigned int *iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *privkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	privkey = EVP_PKEY_new();
	if (privkey == 0) {
ERRLOG("sha256rsa_sign: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("sha256rsa_sign: Couldn't open RSA priv key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		privkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
		if (privkey == 0) {
ERRLOG("sha256rsa_sign: Couldn't use RSA priv key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("sha256rsa_sign: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privkey) == 0) {
ERRLOG("sha256rsa_sign: Couldn't exec EVP_DigestSignInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestSignUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("sha256rsa_sign: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	unsigned int iTmp = 0;
	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, NULL, (size_t *)&iTmp) == 0) {
ERRLOG("sha256rsa_sign: Couldn't calculate signature length.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	} 

	if (iRet == PD_OK) {
		if (EVP_DigestSignFinal(ctx, csSignData, (size_t *)&iTmp) == 0) {
ERRLOG("sha256rsa_sign: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		} else {
			*iLen = iTmp;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(privkey);
	ERR_free_strings();
	return iRet;
}


int sha256rsa_verify_new(char *csRsaPem, const char *csData, const unsigned char *csSignData, int iLen)
{
	int iRet = PD_OK;
	SSL_load_error_strings();

	OpenSSL_add_all_algorithms();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();

	EVP_PKEY *pubkey = 0;
	FILE *fp;
	EVP_MD_CTX *ctx = 0;

	pubkey = EVP_PKEY_new();
	if (pubkey == 0) {
ERRLOG("sha256rsa_verify: Couldn't create new EVP_PKEY object.\n");
		unsigned long sslErr = ERR_get_error();
		if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		fp = fopen(csRsaPem, "r");
		if (fp == 0) {
ERRLOG("sha256rsa_verify: Couldn't open RSA pub key file: '%s'. %s\n", csRsaPem, strerror(errno));
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		pubkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
		if (pubkey == 0) {
ERRLOG("sha256rsa_verify: Couldn't use RSA pub key file.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		ctx = EVP_MD_CTX_create();
		if (ctx == 0) {
ERRLOG("sha256rsa_verify: Couldn't create EVP context.\n" );
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, pubkey) == 0) {
ERRLOG("sha256rsa_verify: Couldn't exec EVP_DigestVerifyInit.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyUpdate(ctx, csData, strlen(csData)) == 0) {
ERRLOG("sha256rsa_verify: Couldn't calculate hash of message.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (EVP_DigestVerifyFinal(ctx, (unsigned char*)csSignData, iLen) == 0) {
ERRLOG("sha256rsa_verify: Couldn't calculate signature.\n");
			unsigned long sslErr = ERR_get_error();
			if (sslErr) {
ERRLOG("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
		}
	}

	fclose(fp);
	EVP_MD_CTX_destroy(ctx);
	EVP_PKEY_free(pubkey);
	ERR_free_strings();
	return iRet;
}

