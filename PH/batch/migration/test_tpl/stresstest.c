#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#include "common.h"
#include "utilitys.h"
#include "mydb.h"
#include "mq_db.h"
#include "gw_db.h"
#include "gateway.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "queue_utility.h"


char cDebug = 'Y';



int 	NTHREADS=10;
int	NP = 10;
void *thread_function(void *ptr);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;
#define         RET_STRING      "[Succeed]"


static int parse_arg(int argc,char **argv);

struct arg_struct {
    char url[512 +1];
    char message[2048 +1];
};


struct string
{
        char *ptr;
        size_t len;
};

void init_string(struct string *s)
{
        s->len = 0;
        s->ptr = malloc(s->len+1);
        if (s->ptr == NULL)
        {
                fprintf(stderr, "malloc() failed\n");
                exit(EXIT_FAILURE);
        }
        s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
        size_t new_len = s->len + size*nmemb;
        s->ptr = realloc(s->ptr, new_len+1);
        if (s->ptr == NULL)
        {
                fprintf(stderr, "realloc() failed\n");
                exit(EXIT_FAILURE);
        }
        memcpy(s->ptr+s->len, ptr, size*nmemb);
        s->ptr[new_len] = '\0';
        s->len = new_len;

        return size*nmemb;
}
int main(int argc, char **argv)
{
	struct arg_struct args;
	strcpy(args.url,"http://abctest.1-pay.com/vnetcard/papi/p04/s2s/");
	strcpy(args.message,"MERID=8000000102&ENCTYPE=01&DATA=MDAwMDAwMDAwMDIwODE5MXwxMDA2MDAxMDIwMDAzNjI0fDIwMTEwOTE5fDExMDkwMzc1NzAwMDA0NzJ8MjAxMTA5MTkxNTEyMTR8MTB8MTAwfEdCfDB8&SIGN=6d62beb4bb3e901f543124a1bfedde1f");



	
        if (argc < 2) {
                fprintf(stderr, "Usage : stresstest -n # of txn -t # of threads\n");
                exit(1);
        }

	if (parse_arg(argc, argv) != PD_OK) {
                exit(1);
        }

   	pthread_t thread_id[NTHREADS];
   	int i, j;

   	for(i=0; i < NTHREADS; i++)
   	{
      		pthread_create( &thread_id[i], NULL, thread_function,(void*)&args);
   	}

   	for(j=0; j < NTHREADS; j++)
	{
      		pthread_join( thread_id[j], NULL); 
   	}
  
   /* Now that all threads are complete I can print the final result.     */
   /* Without the join I could be printing a value before all the threads */
   /* have been completed.                                                */

   	//printf("Final counter value: %d\n", counter);
	return 0;
}

void *thread_function(void *ptr)
{
	int	n=0;
	struct arg_struct *args = (struct arg_struct *)ptr;

   	printf("Thread number %ld\n",pthread_self());
   	pthread_mutex_lock( &mutex1 );
   	counter++;

        int     iRet = PD_OK;
        char    csBuf[MAX_MSG_SIZE + 1];

        CURL    *curl;

        curl = curl_easy_init();

        if (curl) {

		strcpy(csBuf,args->message);
//DEBUGLOG(("DATA = [%s]\n",csBuf));
		struct string sBuffer;
                init_string(&sBuffer);
/* try to set */
                curl_easy_setopt(curl,CURLOPT_URL,args->url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sBuffer);
#ifdef SKIP_PEER_VERIFICATION
    /*
     * If you want to connect to a site who isn't using a certificate that is
     * signed by one of the certs in the CA bundle you have, you can skip the
     * verification of the server's certificate. This makes the connection
     * A LOT LESS SECURE.
     *  
     * If you have a CA cert for the server stored someplace else than in the
     * default bundle, then the CURLOPT_CAPATH option might come handy for
     * you.     
     */ 
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

#endif                  
                        
#ifdef SKIP_HOSTNAME_VERFICATION
    /*
     * If the site you're connecting to uses a different host name that what
     * they have mentioned in their server certificate's commonName (or
     * subjectAltName) fields, libcurl will refuse to connect. You can skip
     * this check, but this will make the connection less secure.
     */
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
#endif
/* set post data */
		for ( n = 1 ; n <= NP; n++) {
                	init_string(&sBuffer);
DEBUGLOG(("TN %ld txn [%d] try to send....\n", pthread_self(),n));
                	curl_easy_setopt(curl,CURLOPT_POSTFIELDS,csBuf);
                	iRet = curl_easy_perform(curl);
DEBUGLOG(("TN %ld txn [%d] Send DATA  Result = [%d]\n", pthread_self(),n,iRet));
                	if (iRet == PD_OK) {

DEBUGLOG(("TN %ld txn [%d] Send DATA  Result = [%s] len =[%d]\n", pthread_self() , n,sBuffer.ptr,sBuffer.len));
//                        	char    *p;
                        //	p = mystrtok(sBuffer.ptr,RET_STRING);
                        //	if (!p) {
//DEBUGLOG(("TN %ld txn [%d] Send DATA  Result = [%s] len =[%d]\n", pthread_self() , n,sBuffer.ptr,sBuffer.len));
 //                               	iRet = PD_ERR;
  //                      	}
                	}
			FREE_ME(sBuffer.ptr);
		}
                curl_easy_cleanup(curl);
        }

  	pthread_mutex_unlock( &mutex1 );
}



static int parse_arg(int argc,char **argv)
{               
        unsigned char   c;
        int             i;
                        
        while ((i = getopt(argc,argv,"n:t:")) != EOF && c != 0xff) {
                c = i;
                switch (c) {
                        case 'n':
				NP = atoi(optarg);
                                break;
                        case 't':
				NTHREADS = atoi(optarg);
                                break;
                        default:
                                return PD_ERR;
                }
        }
        
        return PD_OK;
}       
