
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "reset_check_handshake_ew.pc"
};


static unsigned int sqlctx = 1896351811;


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


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/21              Elvis Wong

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"

#include "tpllib.h"


#define RESET_HANDSHAKE_TPL_PATH "/home/php3dev/src/batch/reset_check_handshake_ew.tpl"
#define MAIL_TITLE "Reset Hand-Shake Checking Cut-off Time"
#define HANDSHAKE_DESCRIPTION "Hand-Shake Checking Cut-off Time Reset"
#define MAIL_TRIGGER "Auto Trigger"


char    cs_merchant_id[PD_MERCHANT_ID_LEN + 1];
//char	cs_user[PD_USER_LEN + 1];
int     i_tpl_type;


int parse_arg(int argc,char **argv);
int process_gen_reset_handshake_tpl(void);


int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
        //printf("batch_init: usage: -m merchant_id -t table_type -u user\n");
        //printf("batch_init: usage: -m merchant_id -t table_type\n");
        return FAILURE;
    }

    else
        return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
		//printf("batch_proc: usage: -m merchant_id -t table_type -u user\n");
		//printf("batch_proc: usage: -m merchant_id -t table_type\n");
	}
	
	if (iRet == SUCCESS) {
		iRet = process_gen_reset_handshake_tpl();
	}

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;

        strcpy(cs_merchant_id,"");	
        //strcpy(cs_user,"");
        i_tpl_type = 0;

        //while ((c = getopt(argc,argv,"m:t:u:")) != EOF) 
        while ((c = getopt(argc,argv,"m:t:")) != EOF) 
	{
//printf("parse_arg: c = %c \n", c);
                switch (c) {
                        case 'm':
//printf("parse_arg: case m, optarg = %s \n", optarg);
                                strcpy(cs_merchant_id, optarg);
                                break;
                        case 't':
//printf("parse_arg: case t, atoi(optarg) = %d \n", atoi(optarg));
                                i_tpl_type = atoi(optarg);
                                break;
                        //case 'u':
//printf("parse_arg: case u, optarg = %s \n", optarg);
                                //strcpy(cs_user, optarg);
                                //break;
                        default:
//printf("parse_arg: Error (Not Option)! \n");
                                return FAILURE;
                }
        }

        //if ((!strcmp(cs_merchant_id,"")) || (!strcmp(cs_user,"")))
        if (!strcmp(cs_merchant_id,""))
                return FAILURE;

        return SUCCESS;
}

int process_gen_reset_handshake_tpl()
{
	tpl_t *tpl = tpl_alloc();
        char *csContent;
	char csTag[PD_TAG_LEN + 1];

        if (tpl_load(tpl, RESET_HANDSHAKE_TPL_PATH) != TPL_OK)
        {
                (void)puts("Error loading template file!");
                return FAILURE;
        }

	// Table (Template type)
//printf("batch_proc: Table(Template type = %d)\n", i_tpl_type);
        {
              	tpl_select_section(tpl, "TABLE_START");
              	sprintf(csTag, "tpl%d", i_tpl_type);
               	tpl_set_field_fmt(tpl, "TPL_NUM", "%s", csTag);
       	        tpl_append_section(tpl);
     	       	tpl_deselect_section(tpl);
       	}

      	// Table (Title)
       	{
//printf("batch_proc: Table(Title)\n");
       		tpl_select_section(tpl, "TITLE");
            	tpl_set_field_fmt(tpl, "tpl_Title", "%s", MAIL_TITLE);
              	tpl_append_section(tpl);
             	tpl_deselect_section(tpl);
     	}

      	// Table (Timestamp)
       	{
//printf("batch_proc: Table(Timestamp)\n");
             	tpl_select_section(tpl, "TIMESTAMP");
              	tpl_set_field_fmt(tpl, "tpl_Timestamp", write_tpl_timestamp_2());
             	tpl_append_section(tpl);
           	tpl_deselect_section(tpl);
      	}

	// Table (ROW)
	{
//printf("batch_proc: Table(Row)\n");
                tpl_select_section(tpl, "ROW");
                tpl_set_field_fmt(tpl, "tpl_Merchant_ID", cs_merchant_id);
                tpl_set_field_fmt(tpl, "tpl_Description", HANDSHAKE_DESCRIPTION);
                tpl_append_section(tpl);
                tpl_deselect_section(tpl);
        }

	// Table (User)
	{
//printf("batch_proc: Table(User)\n");
                tpl_select_section(tpl, "USER");
                //tpl_set_field_fmt(tpl, "tpl_User", cs_user);
                tpl_set_field_fmt(tpl, "tpl_User", MAIL_TRIGGER);
                tpl_append_section(tpl);
                tpl_deselect_section(tpl);
        }
	
	{
                csContent = malloc(tpl_length(tpl) + 1);
                tpl_get_content(tpl, csContent);
                (void)puts(csContent);
                tpl_free(tpl);
	}

	return SUCCESS;
}
