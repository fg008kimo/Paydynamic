#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <htmlstreamparser.h>



int	NP = 10;
int 	counter = 0;
char	PThread[50];
#define         RET_STRING      "[Succeed]"


#define DL      "&"
#define VL      "txn_url"
//char    csResult[] ="process_type=0208&process_code=200002&status=0&txn_url=aHR0cHM6Ly9kZXYuNzI0MTY4Lm5ldC9mZS9jbG4vZy8/c2Vzc2lvbmlkPTU0NzZCQUNCRkQ0NUE0RDlBMTgxNEMxQTA2QjA1NTFF&mer_ref=303322013053111371369971475855048492&mer_id=K000000001&enctype=1&signature=66a472ffc491b832411aed51c25fb88f";


int SendStep2(char* csUrl, char* csArg,char* csStep3Url,char* csStepArgs);
int SendStep3(char* csUrl, char* csArg);

char* decode(char *inString)
{
        char csCmd[1024];

        sprintf(csCmd,"echo %s | base64 -d",inString);
        FILE *fp = popen(csCmd, "r");
        char *ln = NULL;
        size_t len = 0;

        char    *csResult;
        while (getline(&ln, &len, fp) != -1)
        csResult = (char*) malloc (len +1);
        strcpy(csResult,ln);

        free(ln);
        pclose(fp);
        return csResult;
}

char* decode_url(char* InString)
{
        char *p;
	char  *ptr = NULL;
        char *csReturn;
        char *result = NULL;
        result = strtok( InString, DL );
        while( result != NULL ) {
                if ((p = strstr(result,VL)) != NULL) {
                        csReturn = (char*) malloc (strlen(p) +1);
                        memcpy(csReturn,&p[strlen(VL)] +1, strlen(p) - strlen(VL) - 1);
                        csReturn[strlen(p) - strlen(VL) - 1] = '\0';
			ptr = decode(csReturn);
                        break;
                }
                result = strtok( NULL, DL );
        }
	return ptr;
}
char* GetTxn(void)
{
	char	csCmd[1024];
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	unsigned int time_msec = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
	srand(time_msec);

	int iNum = rand()%50000+100;

	sprintf(csCmd,"gentxn.sh %d",iNum);

        FILE *fp = popen(csCmd, "r");
        char *ln = NULL;
        size_t len = 0;

	char    *csResult;
        while (getline(&ln, &len, fp) != -1)
        //        fputs(ln, stdout);
	csResult = (char*) malloc (len +1);
	strcpy(csResult,ln);

        free(ln);
	pclose(fp);
	return csResult;
}

char* GetBankCode(void)
{
        FILE *fp = popen("randombankcode.sh", "r");
        char *ln = NULL;
        size_t len = 0;

	char    *csResult;
        while (getline(&ln, &len, fp) != -1)
        //        fputs(ln, stdout);
	csResult = (char*) malloc (len +1);
	strcpy(csResult,ln);
	csResult[strlen(csResult)-1]= '\0';

        free(ln);
	pclose(fp);
	return csResult;
}

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
        int     iRet = 0;
	int	n =0;
        char    *csBuf;
        char    *csBankCode;

        CURL    *curl;

	char	csStep3Url[256];
	char	csStep3Args[1024];

        curl = curl_easy_init();
	struct arg_struct args;
	strcpy(args.url,"https://dev.724168.net/fe/def/DSP.php");

	
        if (argc < 2) {
                fprintf(stderr, "Usage : stresstest -n # of txn -p pthread num\n");
                exit(1);
        }

	if (parse_arg(argc, argv) != 0) {
                exit(1);
        }



        if (curl) {

		struct string sBuffer;
                init_string(&sBuffer);
/* try to set */
                curl_easy_setopt(curl,CURLOPT_URL,args.url);
printf("url set to [%s]\n",args.url);
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
			char *p;
			char *pUrl;
			char *pArg;
			char csTmp[2048];
			char csUrl[2048];
                	init_string(&sBuffer);
			csBuf = GetTxn();
			csBankCode = GetBankCode();
printf("txn [%d] try to send....\n",n);
                	curl_easy_setopt(curl,CURLOPT_URL,args.url);
printf("URL = [%s]\n",args.url);
                	curl_easy_setopt(curl,CURLOPT_POSTFIELDS,csBuf);
printf("csBuf = [%s]\n",csBuf);
                	iRet = curl_easy_perform(curl);
printf("txn [%d] Send DATA  Result = [%d]\n", n,iRet);
                	if (iRet == 0) {
printf("txn [%d] Recv DATA  Result = [%s] len =[%d]\n", n,sBuffer.ptr,sBuffer.len);
			 	p = decode_url(sBuffer.ptr);
				if (p != NULL) {
				pUrl = strtok(p,"?");
				strcpy(csUrl,pUrl);
				strcat(csUrl,"?");
					if (pUrl != NULL) {
printf("p = [%s]\n",csUrl);
						pArg = strtok(NULL,"?");
						strcpy(csTmp,pArg);
						strcat(csTmp,"&");
						strcat(csTmp,"process_type=0200&process_code=200002&verno=1&Submit=Submit");
						strcat(csTmp,"&bank_code=");
						strcat(csTmp,csBankCode);
printf("out = [%s]\n",csTmp);
						iRet = SendStep2(csUrl,csTmp,csStep3Url,csStep3Args);
						if (iRet == 0) {
printf("step2 sent\n");
printf("Step3 URL = [%s]\n",csStep3Url);
printf("Step3 Arg = [%s]\n",csStep3Args);
							iRet = SendStep3(csStep3Url,csStep3Args);
							if (iRet == 0) {
								printf("step3 sent\n");
							}
							else {
								printf("send to psp error\n");
							}
						}
						else {
printf("send submit bank error\n");
						}
					}
					else {
printf("url error!!!\n");
					}
				}else {
printf("decode url error\n");
				}
                	}
			else {
printf("txn [%d] Recv DATA  error!!!\n",n);
			}
			free(csBuf);
			free(sBuffer.ptr);
		}
                curl_easy_cleanup(curl);
        }
	return 0;

}



static int parse_arg(int argc,char **argv)
{               
        unsigned char   c;
        int             i;
                        
        while ((i = getopt(argc,argv,"n:p:")) != EOF && c != 0xff) {
                c = i;
                switch (c) {
                        case 'n':
				NP = atoi(optarg);
                                break;
                        case 'p':
				strcpy(PThread,optarg);
				PThread[strlen(PThread)]='\0';
                                break;
                        default:
                                return 1;
                }
        }
        
        return 0;
}       

int SendStep2(char* csUrl, char* csArg,char* csStep3Url,char* csStep3Args)
{
        int     iRet = 0;
	int	n =0;

        CURL    *curl;
        curl = curl_easy_init();



        if (curl) {

		struct string sBuffer;
                init_string(&sBuffer);
/* try to set */
                curl_easy_setopt(curl,CURLOPT_URL,csUrl);
printf("url set to [%s]\n",csUrl);
               	curl_easy_setopt(curl,CURLOPT_POSTFIELDS,csArg);
printf("postfileds set to [%s]\n",csArg);
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
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
#endif
/* set post data */
printf("txn [%d] try to send....\n",n);
               	iRet = curl_easy_perform(curl);
printf("txn [%d] Send DATA  Result = [%d]\n", n,iRet);
               	if (iRet == 0) {
//printf("txn [%d] Recv DATA  Result = [%s] len =[%d]\n", n,sBuffer.ptr,(int)sBuffer.len);
		
			size_t p;
			HTMLSTREAMPARSER *hsp;
			char tag[4], attr[4], val[128];


			hsp = html_parser_init();
			html_parser_set_tag_to_lower(hsp, 1);
        		html_parser_set_attr_to_lower(hsp, 1);

        		html_parser_set_tag_buffer(hsp, tag, sizeof(tag));
        		html_parser_set_attr_buffer(hsp, attr, sizeof(attr));
        		html_parser_set_val_buffer(hsp, val, sizeof(val)-1);

			csStep3Args[0]='\0';
			for (p = 0; p < sBuffer.len; p++) {
    				html_parser_char_parse(hsp, ((char *)sBuffer.ptr)[p]);
				if (html_parser_cmp_tag(hsp, "form", 4))
                                        if (html_parser_cmp_attr(hsp, "acti", 4))
                                                if (html_parser_is_in(hsp, HTML_VALUE_ENDED)) {
                                                        val[html_parser_val_length(hsp)] = '\0';
							strcpy(csStep3Url,val);
                                                }

				if (html_parser_cmp_tag(hsp, "input",4)) {
                        		if (html_parser_cmp_attr(hsp, "name", 4)) 
                                		if (html_parser_is_in(hsp, HTML_VALUE_ENDED)) {
                                        		val[html_parser_val_length(hsp)] = '\0';
							strcat(csStep3Args,val);
							strcat(csStep3Args,"=");
                                        		//printf("%s", val);
                                		}
                        		if (html_parser_cmp_attr(hsp, "value", 4))
                                		if (html_parser_is_in(hsp, HTML_VALUE_ENDED)) {
                                        		val[html_parser_val_length(hsp)] = '\0';
							strcat(csStep3Args,val);
                                        		//printf("=%s\n", val);
							strcat(csStep3Args,"&");
                                		}
				}

  			}
/*
			char    cs_outfile_name[50];
			sprintf(cs_outfile_name, "Thread%s_send.html",PThread);

			FILE    *fp;
			fp = fopen(cs_outfile_name,"w");
			if (fp != NULL) {
				fprintf(fp,"%s",sBuffer.ptr);
			}
			fclose(fp);
*/
			
			//char csCmd[100];
			//sprintf(csCmd,"links %s &",cs_outfile_name);
			//system(csCmd);

		}
		else {
printf("send step 2 error\n");
		}
                curl_easy_cleanup(curl);
        }
	return 0;

}

int SendStep3(char* csUrl, char* csArg)
{
        int     iRet = 0;
	int	n =0;

        CURL    *curl;
        curl = curl_easy_init();



        if (curl) {

		struct string sBuffer;
                init_string(&sBuffer);
/* try to set */
                curl_easy_setopt(curl,CURLOPT_URL,csUrl);
printf("url set to [%s]\n",csUrl);
               	curl_easy_setopt(curl,CURLOPT_POSTFIELDS,csArg);
printf("postfileds set to [%s]\n",csArg);
                //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
                //curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sBuffer);
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
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
#endif
/* set post data */
printf("txn [%d] try to send....\n",n);
               	iRet = curl_easy_perform(curl);
printf("txn [%d] Send DATA  Result = [%d]\n", n,iRet);
               	if (iRet == 0) {
printf("txn [%d] Recv DATA  Result = [%s] len =[%d]\n", n,sBuffer.ptr,(int)sBuffer.len);
		}
		else {
printf("send step 3 error\n");
		}
                curl_easy_cleanup(curl);
        }
	return 0;

}

