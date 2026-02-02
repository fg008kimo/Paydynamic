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


int main(int argc, char **argv)
{

	
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
      		pthread_create( &thread_id[i], NULL, thread_function,NULL);
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
	char	csCmd[100];
   	printf("Thread number %ld\n",pthread_self());
   	pthread_mutex_lock( &mutex1 );
   	counter++;

	sprintf(csCmd,"strsend -n %d -p %ld",NP,pthread_self());
	system(csCmd);

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
