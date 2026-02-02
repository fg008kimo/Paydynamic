/*  gcc ./openssl_sign.c -lssl */

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

char csPrivatePassPhrase[1024];
char	cDebug = 'Y';

int pass_cb( char *buf, int size, int rwflag, void *u )
{
  	if ( rwflag == 1 ) {
    		/* What does this really means? */
  	}

  	int len;
  	len = strlen( csPrivatePassPhrase );

  	if ( len <= 0 ) return 0;
  	if ( len > size ) len = size;

  	memset( buf, '\0', size );
  	memcpy( buf, csPrivatePassPhrase, len );
  	return len;
}


RSA* getRsaFp( const char* rsaprivKeyPath, const char* csPassPhrase )
{
	int	iRet = PD_OK;
  	RSA *rsa = 0;
	FILE* fp;
  	fp = fopen( rsaprivKeyPath, "r" );
  	if ( fp == 0 ) {
ERRLOG("sha1rsa:getRsaFp Couldn't open RSA priv key: '%s'. %s\n",
       	   	rsaprivKeyPath, strerror(errno) );
		iRet = PD_ERR;
 	}

  	rsa = RSA_new();
	if (iRet == PD_OK) {
  		if ( rsa == 0 ) {
ERRLOG("sha1rsa:getRsaFp: Couldn't create new RSA priv key obj.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha1rsa:getRsaFp %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		strcpy(csPrivatePassPhrase,csPassPhrase);
  		rsa = PEM_read_RSAPrivateKey(fp, 0, pass_cb, (char*)rsaprivKeyPath);
  		if ( rsa == 0 ) {
ERRLOG("sha1rsa:getRsaFp Couldn't use RSA priv keyfile.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha1rsa:getRsaFp %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}
 	fclose( fp );
  	return rsa;
}



int sha1rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen)
{

	int	iRet = PD_OK;
	SSL_load_error_strings();

  	OpenSSL_add_all_algorithms();
  	OpenSSL_add_all_ciphers();
  	OpenSSL_add_all_digests();


  	EVP_PKEY *evpKey = 0;
  	EVP_MD_CTX* ctx = 0;
  	RSA *rsa = 0;

  	evpKey = EVP_PKEY_new();
  	if ( evpKey == 0 ) {
ERRLOG("sha1rsa_sign:Couldn't create new EVP_PKEY object.\n" );
    		unsigned long sslErr = ERR_get_error();
    		if ( sslErr )  {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
  	}

	if (iRet == PD_OK) {
  		rsa = getRsaFp( csRsaPem,csPassPhrase );

  		if ( EVP_PKEY_set1_RSA( evpKey, rsa ) == 0 ) {
ERRLOG("sha1rsa_sign:Couldn't set EVP_PKEY to RSA key.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("sha1rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		ctx = EVP_MD_CTX_create();
  		if ( ctx == 0 ) {
ERRLOG("sha1rsa_sign:Couldn't create EVP context.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha1rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignInit_ex( ctx, EVP_sha1(), 0 ) == 0 ) {
ERRLOG("sha1rsa_sign:Couldn't exec EVP_SignInit.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha1rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
ERRLOG("sha1rsa_sign: Couldn't calculate hash of message.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
ERRLOG("sha1rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK ) {
		unsigned int 	iTmp = 0;
  		if ( EVP_SignFinal( ctx, csSignData, &iTmp, evpKey ) == 0 ) {
ERRLOG("sha1rsa_sign:Couldn't calculate signature.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("sha1rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
		else {
			*iLen = iTmp;
		}

	}


  	EVP_MD_CTX_destroy( ctx );
  	RSA_free( rsa );
  	EVP_PKEY_free( evpKey );
  	ERR_free_strings();
  	return iRet;
}

int GetPublicKey(EVP_PKEY **pubKey, const X509* x509)
{
	EVP_PKEY *pkey = NULL;
	if (x509 == NULL)
		return INT_ERR;
  	pkey = X509_get_pubkey((X509*)x509);
        *pubKey = pkey;
        return PD_OK; 
}
int sha1rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen)
{
	int	iRet = PD_OK;
	EVP_MD_CTX  *ctx;
  	EVP_PKEY* pkey = NULL;
	X509	*x;

	BIO *Bio = BIO_new_file(csRsaPem,"r");

        if(!Bio) {
DEBUGLOG(("sha1rsa_verify:read pem public key file error.\n"));
                iRet = INT_ERR;
        }

 	x = PEM_read_bio_X509(Bio, NULL, 0, NULL);
 	if (x == NULL)
        {
DEBUGLOG(("sha1rsa_verify: read cert error\n"));
		iRet = INT_ERR;
        }

	if (iRet == PD_OK) {
		if(GetPublicKey(&pkey, x) != PD_OK) {
DEBUGLOG(("sha1rsa_verify could not get public key\n"));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
		}
	}
	if (iRet == PD_OK) {
                ctx = EVP_MD_CTX_create();
                if ( ctx == 0 ) {
ERRLOG("sha1rsa_verify:Couldn't create EVP context.\n" );
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
ERRLOG("sha1rsa_verify:%s\n", ERR_error_string(sslErr, 0));
                        }
                        iRet = PD_ERR;
                }
        }
	if (iRet == PD_OK) {
		if ( EVP_VerifyInit_ex( ctx, EVP_sha1(), 0 ) == 0 ) {
DEBUGLOG(("sha1rsa_verify:Couldn't exec EVP_SignInit.\n" ));
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
DEBUGLOG(("sha1rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
                        }
                        iRet = PD_ERR;
                }
	}

	if (iRet == PD_OK) {
  		if ( EVP_VerifyUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
DEBUGLOG(("sha1rsa_verify: Couldn't calculate hash of message.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("sha1rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	
	}
	if (iRet == PD_OK) {
  		if ( EVP_VerifyFinal( ctx, csSigData, iSigLen, pkey ) == 0 ) {
DEBUGLOG(("sha1rsa_verify:Couldn't calculate signature.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
DEBUGLOG(("sha1rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	}
  	EVP_MD_CTX_destroy( ctx );
  	X509_free( x );
  	BIO_free( Bio );
  	EVP_PKEY_free( pkey );
  	ERR_free_strings();
	return iRet;
}

int MyRsa_Sign(FILE * privateKeyFP, char *inStr, char* outStr)
{
        RSA *rsa_pkey = NULL;
        EVP_PKEY *pkey = EVP_PKEY_new();
        EVP_MD_CTX ctx;
        size_t len;
        unsigned char *sig;
        unsigned int siglen;

        if (!PEM_read_RSAPrivateKey(privateKeyFP, &rsa_pkey, NULL, NULL)) {
                fprintf(stderr, "Error loading RSA Private Key File.\n");
                return 2;
        }

        if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey)) {
                fprintf(stderr, "EVP_PKEY_assign_RSA: failed.\n");
                return 3;
        }

        EVP_MD_CTX_init(&ctx);

        if (!EVP_SignInit(&ctx, EVP_sha1())) {
                fprintf(stderr, "EVP_SignInit: failed.\n");
                EVP_PKEY_free(pkey);
                return 3;
        }

        len = strlen(inStr);
        if (!EVP_SignUpdate(&ctx, inStr, len)) {
            fprintf(stderr, "EVP_SignUpdate: failed.\n");
            EVP_PKEY_free(pkey);
            return 3;
        }


        sig = malloc(EVP_PKEY_size(pkey));
        if (!EVP_SignFinal(&ctx, sig, &siglen, pkey)) {
                fprintf(stderr, "EVP_SignFinal: failed.\n");
                free(sig);
                EVP_PKEY_free(pkey);
                return 3;
        }

        base64_encode(sig,siglen,outStr,PD_TMP_MSG_BUF_LEN);
        free(sig);
        EVP_PKEY_free(pkey);
        return PD_OK;
}

int MyRsa_Verify(FILE * publicKeyFP, char* inStr, int iLen, char* inSig)
{
	RSA *rsa_pkey = NULL;
	EVP_PKEY *pkey;
	EVP_MD_CTX ctx;
	unsigned char *sig;
	unsigned int siglen;

    	if (!PEM_read_RSA_PUBKEY(publicKeyFP, &rsa_pkey, NULL, NULL)) {
       		fprintf(stderr, "Error loading RSA public Key File.\n");
        	return 2;
    	}
    	pkey = EVP_PKEY_new();

    	if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey)) {
        	fprintf(stderr, "EVP_PKEY_assign_RSA: failed.\n");
        	return 3;
    	}

    	sig = (unsigned char *)malloc(PD_TMP_MSG_BUF_LEN + 1);
    	siglen = base64_decode(inSig,sig,PD_TMP_MSG_BUF_LEN);


	EVP_MD_CTX_init(&ctx);

    	if (!EVP_VerifyInit(&ctx, EVP_sha1())) {
        	fprintf(stderr, "EVP_SignInit: failed.\n");
        	EVP_PKEY_free(pkey);
        	return 7;
    	}

        if (!EVP_VerifyUpdate(&ctx, inStr, iLen)) {
            fprintf(stderr, "EVP_SignUpdate: failed.\n");
            EVP_PKEY_free(pkey);
            return 8;
        }

    	if (!EVP_VerifyFinal(&ctx, sig, siglen, pkey)) {
        	fprintf(stderr, "EVP_VerifyFinal: failed.\n");
        	free(sig);
        	EVP_PKEY_free(pkey);
        	return 10;
    	}

    	free(sig);
    	EVP_PKEY_free(pkey);
    	return PD_OK;
}




int md5rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen)
{

	int	iRet = PD_OK;
	SSL_load_error_strings();

  	OpenSSL_add_all_algorithms();
  	OpenSSL_add_all_ciphers();
  	OpenSSL_add_all_digests();


  	EVP_PKEY *evpKey = 0;
  	EVP_MD_CTX* ctx = 0;
  	RSA *rsa = 0;

  	evpKey = EVP_PKEY_new();
  	if ( evpKey == 0 ) {
ERRLOG("md5rsa_sign:Couldn't create new EVP_PKEY object.\n" );
    		unsigned long sslErr = ERR_get_error();
    		if ( sslErr )  {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
  	}

	if (iRet == PD_OK) {
  		rsa = getRsaFp( csRsaPem,csPassPhrase );

  		if ( EVP_PKEY_set1_RSA( evpKey, rsa ) == 0 ) {
ERRLOG("md5rsa_sign:Couldn't set EVP_PKEY to RSA key.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("md5rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		ctx = EVP_MD_CTX_create();
  		if ( ctx == 0 ) {
ERRLOG("md5rsa_sign:Couldn't create EVP context.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("md5rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignInit_ex( ctx, EVP_md5(), 0 ) == 0 ) {
ERRLOG("md5rsa_sign:Couldn't exec EVP_SignInit.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("md5rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
ERRLOG("md5rsa_sign: Couldn't calculate hash of message.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
ERRLOG("md5rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK ) {
		unsigned int 	iTmp = 0;
  		if ( EVP_SignFinal( ctx, csSignData, &iTmp, evpKey ) == 0 ) {
ERRLOG("md5rsa_sign:Couldn't calculate signature.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("md5rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
		else {
			*iLen = iTmp;
		}

	}


  	EVP_MD_CTX_destroy( ctx );
  	RSA_free( rsa );
  	EVP_PKEY_free( evpKey );
  	ERR_free_strings();
  	return iRet;
}


int md5rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen)
{
	int	iRet = PD_OK;
	EVP_MD_CTX  *ctx;
  	EVP_PKEY* pkey = NULL;
	X509	*x;

	BIO *Bio = BIO_new_file(csRsaPem,"r");

        if(!Bio) {
DEBUGLOG(("md5rsa_verify:read pem public key file error.\n"));
                iRet = INT_ERR;
        }

 	x = PEM_read_bio_X509(Bio, NULL, 0, NULL);
 	if (x == NULL)
        {
DEBUGLOG(("md5rsa_verify: read cert error\n"));
		iRet = INT_ERR;
        }

	if (iRet == PD_OK) {
		if(GetPublicKey(&pkey, x) != PD_OK) {
DEBUGLOG(("md5rsa_verify could not get public key\n"));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
		}
	}
	if (iRet == PD_OK) {
                ctx = EVP_MD_CTX_create();
                if ( ctx == 0 ) {
ERRLOG("md5rsa_verify:Couldn't create EVP context.\n" );
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
ERRLOG("md5rsa_verify:%s\n", ERR_error_string(sslErr, 0));
                        }
                        iRet = PD_ERR;
                }
        }
	if (iRet == PD_OK) {
		if ( EVP_VerifyInit_ex( ctx, EVP_md5(), 0 ) == 0 ) {
DEBUGLOG(("md5rsa_verify:Couldn't exec EVP_SignInit.\n" ));
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
DEBUGLOG(("md5rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
                        }
                        iRet = PD_ERR;
                }
	}

	if (iRet == PD_OK) {
  		if ( EVP_VerifyUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
DEBUGLOG(("md5rsa_verify: Couldn't calculate hash of message.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("md5rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	
	}
	if (iRet == PD_OK) {
  		if ( EVP_VerifyFinal( ctx, csSigData, iSigLen, pkey ) == 0 ) {
DEBUGLOG(("md5rsa_verify:Couldn't calculate signature.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
DEBUGLOG(("md5rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	}
  	EVP_MD_CTX_destroy( ctx );
  	X509_free( x );
  	BIO_free( Bio );
  	EVP_PKEY_free( pkey );
  	ERR_free_strings();
	return iRet;
}

int sha256rsa_sign(char* csRsaPem,char* csPassPhrase,char* csData, unsigned char* csSignData, unsigned int *iLen)
{

	int	iRet = PD_OK;
	SSL_load_error_strings();

  	OpenSSL_add_all_algorithms();
  	OpenSSL_add_all_ciphers();
  	OpenSSL_add_all_digests();


  	EVP_PKEY *evpKey = 0;
  	EVP_MD_CTX* ctx = 0;
  	RSA *rsa = 0;

  	evpKey = EVP_PKEY_new();
  	if ( evpKey == 0 ) {
ERRLOG("sha256rsa_sign:Couldn't create new EVP_PKEY object.\n" );
    		unsigned long sslErr = ERR_get_error();
    		if ( sslErr )  {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
		}
		iRet = INT_ERR;
  	}

	if (iRet == PD_OK) {
  		rsa = getRsaFp( csRsaPem,csPassPhrase );

  		if ( EVP_PKEY_set1_RSA( evpKey, rsa ) == 0 ) {
ERRLOG("sha256rsa_sign:Couldn't set EVP_PKEY to RSA key.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("sha256rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = INT_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		ctx = EVP_MD_CTX_create();
  		if ( ctx == 0 ) {
ERRLOG("sha256rsa_sign:Couldn't create EVP context.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha256rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignInit_ex( ctx, EVP_sha256(), 0 ) == 0 ) {
ERRLOG("sha256rsa_sign:Couldn't exec EVP_SignInit.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) {
ERRLOG("sha256rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK) {
  		if ( EVP_SignUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
ERRLOG("sha256rsa_sign: Couldn't calculate hash of message.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
ERRLOG("sha256rsa_sign: %s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
	}

	if (iRet == PD_OK ) {
		unsigned int 	iTmp = 0;
  		if ( EVP_SignFinal( ctx, csSignData, &iTmp, evpKey ) == 0 ) {
ERRLOG("sha256rsa_sign:Couldn't calculate signature.\n" );
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
ERRLOG("sha256rsa_sign:%s\n", ERR_error_string(sslErr, 0));
			}
			iRet = PD_ERR;
  		}
		else {
			*iLen = iTmp;
		}

	}


  	EVP_MD_CTX_destroy( ctx );
  	RSA_free( rsa );
  	EVP_PKEY_free( evpKey );
  	ERR_free_strings();
  	return iRet;
}


int sha256rsa_verify(char* csRsaPem,const char* csData,const unsigned char* csSigData, int iSigLen)
{
	int	iRet = PD_OK;
	EVP_MD_CTX  *ctx;
  	EVP_PKEY* pkey = NULL;
	X509	*x;

	BIO *Bio = BIO_new_file(csRsaPem,"r");

        if(!Bio) {
DEBUGLOG(("sha256rsa_verify:read pem public key file error.\n"));
                iRet = INT_ERR;
        }

 	x = PEM_read_bio_X509(Bio, NULL, 0, NULL);
 	if (x == NULL)
        {
DEBUGLOG(("sha256rsa_verify: read cert error\n"));
		iRet = INT_ERR;
        }

	if (iRet == PD_OK) {
		if(GetPublicKey(&pkey, x) != PD_OK) {
DEBUGLOG(("sha256rsa_verify could not get public key\n"));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
		}
	}
	if (iRet == PD_OK) {
                ctx = EVP_MD_CTX_create();
                if ( ctx == 0 ) {
ERRLOG("sha256rsa_verify:Couldn't create EVP context.\n" );
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
ERRLOG("sha256rsa_verify:%s\n", ERR_error_string(sslErr, 0));
                        }
                        iRet = PD_ERR;
                }
        }
	if (iRet == PD_OK) {
		if ( EVP_VerifyInit_ex( ctx, EVP_sha256(), 0 ) == 0 ) {
DEBUGLOG(("sha256rsa_verify:Couldn't exec EVP_SignInit.\n" ));
                        unsigned long sslErr = ERR_get_error();
                        if ( sslErr ) {
DEBUGLOG(("sha256rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
                        }
                        iRet = PD_ERR;
                }
	}

	if (iRet == PD_OK) {
  		if ( EVP_VerifyUpdate( ctx, csData, strlen( csData ) ) == 0 ) {
DEBUGLOG(("sha256rsa_verify: Couldn't calculate hash of message.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr )  {
DEBUGLOG(("sha256rsa_verify: %s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	
	}
	if (iRet == PD_OK) {
  		if ( EVP_VerifyFinal( ctx, csSigData, iSigLen, pkey ) == 0 ) {
DEBUGLOG(("sha256rsa_verify:Couldn't calculate signature.\n" ));
    			unsigned long sslErr = ERR_get_error();
    			if ( sslErr ) { 
DEBUGLOG(("sha256rsa_verify:%s\n", ERR_error_string(sslErr, 0)));
			}
			iRet = PD_ERR;
  		}
	}
  	EVP_MD_CTX_destroy( ctx );
  	X509_free( x );
  	BIO_free( Bio );
  	EVP_PKEY_free( pkey );
  	ERR_free_strings();
	return iRet;
}


void sha256sum(const char* in, const int length_in, char* out)
{
	SHA256_CTX c;
	unsigned char buf[SHA256_DIGEST_LENGTH * 2 + 1];

	SHA256_Init(&c);
	SHA256_Update(&c, in, length_in);
	SHA256_Final(buf, &c);

	Hex2Ascii(out, buf, SHA256_DIGEST_LENGTH);
	out[SHA256_DIGEST_LENGTH * 2] = '\0';
}

