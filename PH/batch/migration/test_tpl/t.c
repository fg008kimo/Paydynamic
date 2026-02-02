#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define	DL	"&"
#define	VL	"txn_url"
char	csResult[] ="process_type=0208&process_code=200002&status=0&txn_url=aHR0cHM6Ly9kZXYuNzI0MTY4Lm5ldC9mZS9jbG4vZy8/c2Vzc2lvbmlkPTU0NzZCQUNCRkQ0NUE0RDlBMTgxNEMxQTA2QjA1NTFF&mer_ref=303322013053111371369971475855048492&mer_id=K000000001&enctype=1&signature=66a472ffc491b832411aed51c25fb88f";

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

void main(void) 
{
	char *p;
	char *csReturn;
	char *result = NULL;
	result = strtok( csResult, DL );
	while( result != NULL ) {
		if ((p = strstr(result,VL)) != NULL) {
			csReturn = (char*) malloc (strlen(p) +1);
			memcpy(csReturn,&p[strlen(VL)] +1, strlen(p) - strlen(VL) - 1);
			csReturn[strlen(p) - strlen(VL) - 1] = '\0'; 
printf("result = [%s]\n",decode(csReturn));
			break;
		}
    		result = strtok( NULL, DL );
	}
}
