//#include "SystemControl.h"
#include "/home/cphdev/include/common.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("please input the code for serching\n");
		return -1;
	}
	
	char *pCode;

	int i = 0;
	int nMax = argc-2;
	for(i = 1; i< nMax; i++)
	{
		strcpy(pCode, argv[i]);
		if(!pCode)
		{
			printf("strcpy(pCode, argv[%d]) failed\n", i);
			return -1;
		}

		unsigned char *pValue;
		int nRc = FindCode(pCode, pValue);
		
		if(nRc!=NOT_FOUND)
			printf("Search pCode[%s] in DB. Result[%d], pValue[%s]\n", pCode, nRc, pValue);
		else
			printf("Search pCode[%s] in DB. Result Not Found\n");
	}

	return 0;
}
