#include <stdio.h>
#include <string.h>


/*
int main(void)
{
 char search_string[]="s:120:\"MerId=111&url=https://www.x.com\"";
  char *array[50];
  int loop;

  array[0]=strtok(search_string,":");
  if(array[0]==NULL)
   {
    printf("No test to search.\n");
    exit(0);
   }

  for(loop=1;loop<50;loop++)
   {
    array[loop]=strtok(NULL,":");
    if(array[loop]==NULL)
      break;
   }

  for(loop=0;loop<50;loop++)
   {
    if(array[loop]==NULL)
      break;
    printf("Item #%d is %s.\n",loop,array[loop]);
   }

  return 0;

}
*/
int main(void)
{
 char search_string[]="s:120:\"MerId=111&url=https://www.x.com\"";
 char *array[50];
 char *p;
 char csTmp[1024];

  p=strtok(search_string,":");
  if(p==NULL)
   {
    printf("No test to search.\n");
    exit(0);
   }

    p=strtok(NULL,":");
    if(p==NULL)
	printf("err\n");

printf("[1] = [%s]\n",p);
memset(csTmp,0,1024);
	int i = atoi(p);
	int l = strlen(p) + 2;
	memcpy(csTmp,&search_string[l+2],i);
csTmp[i-1] ='\0';	
printf("[2] = [%i][%s]=[%i][%i]\n",strlen(csTmp),csTmp,i,l);

  return 0;

}
