#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "numutility.h"
#include "batchcommon.h"
#include "internal.h"

char    cs_file[PD_MAX_FILE_LEN + 1];
char	cs_num[10];

int parse_arg(int argc,char **argv);
int process_txn(FILE * fp, const int iNumOfRecord);

int main(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	FILE	*pFile;
	int iNumOfRecord=0;

	iRet = parse_arg(argc,argv);
	if (iRet != SUCCESS) {
printf("usage: -n Num of record -o Output file\n");
		return (iRet);
	}

	pFile = fopen(cs_file, "w");
	if (pFile == NULL){
                printf("unable to open file %s\n",cs_file);
                return FAILURE;
        }

	iNumOfRecord = atoi(cs_num);

	iRet = process_txn(pFile,iNumOfRecord);
	fclose(pFile);
	
	return iRet;
}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_file,"");
        strcpy(cs_num,"");

        while ((c = getopt(argc,argv,"o:n:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_file, optarg);
                                break;
                        case 'n':
                                strcpy(cs_num, optarg);
                                break; 
                        default:
                                return FAILURE;
                }       
        }       

        if (!strcmp(cs_file,"") || !strcmp(cs_num,""))
                return FAILURE;
                        
        return SUCCESS;
}

int process_txn(FILE * fp, const int iNumOfRecord)
{
	int i;
	int iRet = SUCCESS;
	char	csAccNum[13];
	char	csDate[15];
//getdatetime

	fprintf(fp,"888000130,%d,CBA619FD708265A2\n",iNumOfRecord);
	strcpy(csDate,getdatetime());
	csDate[14]='\0';

	for(i=0;i<iNumOfRecord;i++){

		sprintf(csAccNum,"%04d%s",i,&csDate[6]);
		csAccNum[12]='\0';

		fprintf(fp,"%06d,%s,TW,B122306585,%s%d,006,劉力豪,合作金庫銀行,慈文分行,,,,%d00,901,901,E30CF51A9E24F0B2\n",i+1,csAccNum,&csDate[6],i,i+1);
	}

	return iRet;
}
