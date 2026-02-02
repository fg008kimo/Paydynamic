
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "hashkey.pc"
};


static unsigned int sqlctx = 73363;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
//#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"

#include "BOSecurity.h"
#include "common.h"
#define TESTA   "abc"

OBJPTR(BO);
char    cDebug;

#define IDENTITY_ID_LEN 10
#define BUFFER_LEN      1000
#define KEY	"5ebd05cecabb3a81a5a43bfb895605bd"
#define DATA_H	"888000130|3"
//#define DATA_C	"000037|5948522376|123448723164|TW|150"
//#define DATA_C	"000038|5721628731|873121182961|TW|150"
#define DATA_C	"000039|5819717283|298377361938|TW|150"

char    csCharSet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char    csAddSet[26][3]={"1","10","19","28","37","46","55","64","39","73","82","2","11","20","48","29","38","47","56","65","74","83","21","3","12","30"};
char    csIntSet[26][3]={"10","11","12","13","14","15","16","17","34","18","19","20","21","22","35","23","24","25","26","27","28","29","32","30","31","33"};
int     checkAlienID(const char* csID);
int     checkNationalID(const char* csID);


int batch_init(int argc, char* argv[])
{
/*
	if(argc<3)
	{
printf(("Please input enought arguments [key] [data]\n"));
		return FAILURE;
	}
	else  {
		return SUCCESS;
	}
*/
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
/*
	char csData[BUFFER_LEN];
	char csKey[PD_SHA_KEY_LEN+10];
	char csOut[PD_KEY_LEN+1];

	strncpy(csData, argv[1],strlen(argv[1]));
	csData[strlen(argv[1])]='\0';

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMAC");
	if ((unsigned long int)(*BOObjPtr)(KEY,csData,strlen(csData),csOut) == PD_OK){
printf("GenerateMAC(%s,%s,%ld) -> MAC of Header= [%s]\n",KEY,csData,strlen(csData),csOut);
	}
	else {
	}
*/


	if(checkNationalID(argv[1])==-1)
printf("Invalid ID\n");



	return SUCCESS;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int     checkNationalID(const char* csID)
{
	int iRet = SUCCESS;
	int iPos = 0;
	int iSex = 0;
	int iTotalSum = 0;
	int iCheck= 0;

//check 2-10 digits, numeric
	if(iRet == SUCCESS){
		if(is_numeric((char*)&csID[1])!=PD_TRUE)
			iRet = -1;
	}

//check 2nd digit, MALE or FEMALE
	if(iRet == SUCCESS){
		iSex = atoi(&csID[1])/pow(10,8);
		if(!((iSex==1) || (iSex==2)))
			iRet = -1;
	}


//check digit
	if(iRet == SUCCESS){
		for(iPos=0; iPos<26; iPos++){
			if(csID[0] == csCharSet[iPos]){
				iTotalSum += atoi(csAddSet[iPos]);
printf("1st[%c][%d], iTotalSum[%d]\n",csCharSet[iPos],atoi(csAddSet[iPos]),iTotalSum);
			}
		}

		int i;
		int iPow = 0;
		for(i=8;i>0;i--){
			iPow= pow(10,i);
			iTotalSum += (atoi(&csID[IDENTITY_ID_LEN-1-i])/iPow)*i;
printf("%dth[%d][%d], iTotalSum[%d]\n",IDENTITY_ID_LEN-i,atoi(&csID[IDENTITY_ID_LEN-1-i])/iPow,(atoi(&csID[IDENTITY_ID_LEN-1-i])/iPow)*i,iTotalSum);

		}


		iCheck = (10-(iTotalSum%10))%10;
		if(atoi(&csID[9])!= iCheck)
			iRet = -1;

printf("last digit[%d], iCheck[%d]\n",atoi(&csID[9]),iCheck);
	}

	return iRet;
}



int     checkAlienID(const char* csID)
{
	int iRet = SUCCESS;
	int iPos = 0;
        int iTotalSum = 0;
        int iCheck = 0;
        char csTmp[3];
        int iTmp;
        int i;
        char csNumericPart[IDENTITY_ID_LEN-1];


//check 3-10 digits, numeric
        strcpy(csNumericPart,&csID[2]);
        csNumericPart[IDENTITY_ID_LEN-2]='\0';
        if(is_numeric(csNumericPart)!=PD_TRUE)
                iRet = -1;

//check digit
        if(iRet == SUCCESS){
                for(iPos=0;iPos<26;iPos++){
                        if(csID[0] == csCharSet[iPos]){
                                iTmp = atoi(&csIntSet[iPos][1])*9;
                                sprintf(csTmp,"%d",iTmp);
                                iTotalSum += atoi(csIntSet[iPos])/10 + atoi(&csTmp[1]);

printf("1st: [%c][%d+%d]\n",csID[0],atoi(csIntSet[iPos])/10, atoi(&csTmp[1]));
                        
                        }
                        if(csID[1] == csCharSet[iPos]){
                                iTmp = atoi(&csIntSet[iPos][1])*8;
                                sprintf(csTmp,"%d",iTmp);
                                if(iTmp>9){ iTotalSum += atoi(&csTmp[1]);
printf("2nd: [%c][%d]\n",csID[1],atoi(&csTmp[1]));}
				else{	iTotalSum += atoi(csTmp);
printf("2nd: [%c][%d]\n",csID[1],atoi(csTmp));}
                        }
                }

                for(i=7;i>0;i--){
			int iP = pow(10,i);
                        iTmp = (atoi(&csID[IDENTITY_ID_LEN-1-i])/iP)*i;
                        sprintf(csTmp,"%d",iTmp);
                        if(iTmp>9){ iTotalSum += atoi(&csTmp[1]);
printf(": [%s | %d]*[%d] = [%d]\n", &csID[IDENTITY_ID_LEN-1-i],iP,i,atoi(&csTmp[1]));}
			else{ iTotalSum += atoi(csTmp);
printf(": [%s | %d]*[%d] = [%d]\n", &csID[IDENTITY_ID_LEN-1-i],iP,i,atoi(csTmp));}

                }

                sprintf(csTmp,"%d",iTotalSum);
		if(iTotalSum>9) iCheck = 10 - atoi(&csTmp[1]);
		else	iCheck = 10 - atoi(csTmp);
printf("total = [%d] , check = [%d]\n",iTotalSum,iCheck);
                if(iCheck != atoi(&csID[IDENTITY_ID_LEN-1]))
                        iRet = -1;

        }

        return iRet;
}
