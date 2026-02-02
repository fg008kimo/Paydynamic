
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "EmailFunctTemplate.pc"
};


static unsigned int sqlctx = 149242659;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
5,0,0,1,249,0,4,78,0,0,9,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,3,0,0,1,9,0,0,
56,0,0,2,137,0,4,267,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/03              Stan Poon
Update						   2014/12/02		   Elvis Wong
Add GetTemplateDetails				   2019/04/29		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "EmailFunctTemplate.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void EmailFunctTemplate(char	cdebug)
{
	cDebug = cdebug;
}

int GetTemplate(hash_t *hRls)
{
	int iRet = FOUND;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettemplate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_funct[PD_EML_FUNCT_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_funct;


		/* varchar	v_source[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_source;

		/* varchar	v_from[PD_EML_FROM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_from;

		//varchar	v_to[PD_EML_TEMPLATE_LEN+1];
		//varchar	v_cc[PD_EML_TEMPLATE_LEN+1];
		//varchar	v_bcc[PD_EML_TEMPLATE_LEN+1];
		/* varchar	v_subject[PD_EML_SUBJECT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_subject;

		/* varchar	v_header[PD_EML_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_header;

		/* varchar	v_css[PD_EML_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_css;

		/* varchar	v_body[PD_EML_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_body;

		/* varchar	v_footer[PD_EML_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_footer;

		//varchar	v_template[PD_EML_TEMPLATE_LEN*4 + 1];
		int	v_next_seq;

		short	ind_source = -1;
		short	ind_from = -1;
		//short	ind_to = -1;
		//short	ind_cc = -1;
		//short	ind_bcc = -1;
		short	ind_subject = -1;
		short	ind_header = -1;
		short	ind_css = -1;
		short	ind_body = -1;
		short	ind_footer = -1;
		//short	ind_template = -1;
		short	ind_next_seq = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"funct",&csTmp)) {
		hv_funct.len = strlen(csTmp);
		strncpy((char*)hv_funct.arr, csTmp, hv_funct.len);
DEBUGLOG(("GetTemplate funct = [%.*s]\n", hv_funct.len, hv_funct.arr));
	}

	/* EXEC SQL
/o
		SELECT	EFT_FROM,
			EFT_SUBJECT,
			ET1.ET_TEMPLATE ||
			ET2.ET_TEMPLATE ||
			ET3.ET_TEMPLATE ||
			ET4.ET_TEMPLATE
		INTO	:v_from:ind_from,
			:v_subject:ind_subject,
			:v_template:ind_template
		FROM	EMAIL_FUNCT_TEMPLATE
		LEFT JOIN EMAIL_TEMPLATE ET1 ON ET1.ET_ID = EFT_HEADER
		LEFT JOIN EMAIL_TEMPLATE ET2 ON ET2.ET_ID = EFT_CSS
		LEFT JOIN EMAIL_TEMPLATE ET3 ON ET3.ET_ID = EFT_BODY
		LEFT JOIN EMAIL_TEMPLATE ET4 ON ET4.ET_ID = EFT_FOOTER
		WHERE	EFT_FUNCT = :hv_funct;
o/

		SELECT	EFT_SOURCE,
			EFT_FROM,
/o
			(SELECT LISTAGG(EL_EMAIL,';') WITHIN GROUP (ORDER BY EL_EMAIL)
			 FROM EMAIL_RECEIVER_LIST, EMAIL_NOTIFY_LIST
			 WHERE ERL_FUNCT = :hv_funct
			 AND EL_ID=ERL_ID
			 AND ERL_TYPE=1),
			(SELECT LISTAGG(EL_EMAIL,';') WITHIN GROUP (ORDER BY EL_EMAIL)
			 FROM EMAIL_RECEIVER_LIST, EMAIL_NOTIFY_LIST
			 WHERE ERL_FUNCT = :hv_funct
			 AND EL_ID=ERL_ID
			 AND ERL_TYPE=2),
			(SELECT LISTAGG(EL_EMAIL,';') WITHIN GROUP (ORDER BY EL_EMAIL)
			 FROM EMAIL_RECEIVER_LIST, EMAIL_NOTIFY_LIST
			 WHERE ERL_FUNCT = :hv_funct 
			 AND EL_ID=ERL_ID
			 AND ERL_TYPE=3),
o/
			EFT_SUBJECT,
			EFT_HEADER,
			EFT_CSS,
			EFT_BODY,
			EFT_FOOTER,
			ALERT_MODULE_SEQ.NEXTVAL
		INTO	:v_source:ind_source,
			:v_from:ind_from,
/o
			:v_to:ind_to,
			:v_cc:ind_cc,
			:v_bcc:ind_bcc,
o/
			:v_subject:ind_subject,
			:v_header:ind_header,
			:v_css:ind_css,
			:v_body:ind_body,
			:v_footer:ind_footer,
			:v_next_seq:ind_next_seq
		FROM	EMAIL_FUNCT_TEMPLATE
		WHERE	EFT_FUNCT = :hv_funct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select EFT_SOURCE , EFT_FROM , EFT_SUBJECT , EFT_HEADER , E\
FT_CSS , EFT_BODY , EFT_FOOTER , ALERT_MODULE_SEQ . NEXTVAL INTO :b0:b1 , :b2\
:b3 , :b4:b5 , :b6:b7 , :b8:b9 , :b10:b11 , :b12:b13 , :b14:b15 FROM EMAIL_FU\
NCT_TEMPLATE WHERE EFT_FUNCT = :b16 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_source;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_source;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_from;
 sqlstm.sqhstl[1] = (unsigned long )53;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_from;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_subject;
 sqlstm.sqhstl[2] = (unsigned long )103;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_subject;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_header;
 sqlstm.sqhstl[3] = (unsigned long )23;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_header;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_css;
 sqlstm.sqhstl[4] = (unsigned long )23;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_css;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_body;
 sqlstm.sqhstl[5] = (unsigned long )23;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_body;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_footer;
 sqlstm.sqhstl[6] = (unsigned long )23;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_footer;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&v_next_seq;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_next_seq;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_funct;
 sqlstm.sqhstl[8] = (unsigned long )17;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettemplate_error;
}



	if (ind_source >= 0) {
		v_source.arr[v_source.len] = '\0';
		PutField_CString(hRls,"mail_source",(char*)v_source.arr);
DEBUGLOG(("GetTemplate() mail_source = [%s]\n",(char*)v_source.arr));
	} else {
		iRet = NOT_FOUND;
	}

	if (ind_from >= 0) {
		v_from.arr[v_from.len]='\0';
		PutField_CString(hRls,"mail_from",(char*)v_from.arr);
DEBUGLOG(("GetTemplate() from = [%s]\n",(char*)v_from.arr));
	} else {
		iRet = NOT_FOUND;
	}

/*
	if (ind_to >= 0) {
		v_to.arr[v_to.len]='\0';
		PutField_CString(hRls,"mail_to",(char*)v_to.arr);
DEBUGLOG(("GetTemplate() to = [%s]\n",(char*)v_to.arr));
	} else {
		iRet = NOT_FOUND;
	}

	if (ind_cc >= 0) {
		v_cc.arr[v_cc.len]='\0';
		PutField_CString(hRls,"mail_cc",(char*)v_cc.arr);
DEBUGLOG(("GetTemplate() cc = [%s]\n",(char*)v_cc.arr));
	}

	if (ind_bcc >= 0) {
		v_bcc.arr[v_bcc.len]='\0';
		PutField_CString(hRls,"mail_bcc",(char*)v_bcc.arr);
DEBUGLOG(("GetTemplate() bcc = [%s]\n",(char*)v_bcc.arr));
	}
*/

	if (ind_subject >= 0) {
		v_subject.arr[v_subject.len]='\0';
		PutField_CString(hRls,"mail_subject",(char*)v_subject.arr);
DEBUGLOG(("GetTemplate() subject = [%s]\n",(char*)v_subject.arr));
	} else {
		iRet = NOT_FOUND;
	}

	if (ind_header >= 0) {
		v_header.arr[v_header.len]='\0';
		PutField_CString(hRls,"mail_header",(char*)v_header.arr);
DEBUGLOG(("GetTemplate() header = [%s]\n",(char*)v_header.arr));
	} else {
		iRet = NOT_FOUND;
	}

	if (ind_css >= 0) {
		v_css.arr[v_css.len]='\0';
		PutField_CString(hRls,"mail_css",(char*)v_css.arr);
DEBUGLOG(("GetTemplate() css = [%s]\n",(char*)v_css.arr));
	} else {
		//iRet = NOT_FOUND;
	}

	if (ind_body >= 0) {
                v_body.arr[v_body.len] = '\0';
                PutField_CString(hRls,"mail_body",(char*)v_body.arr);
DEBUGLOG(("GetTemplate() mail_body = [%s]\n",(char*)v_body.arr));
        } else {
                iRet = NOT_FOUND;
        }

	if (ind_footer >= 0) {
		v_footer.arr[v_footer.len]='\0';
		PutField_CString(hRls,"mail_footer",(char*)v_footer.arr);
DEBUGLOG(("GetTemplate() footer = [%s]\n",(char*)v_footer.arr));
	} else {
		//iRet = NOT_FOUND;
	}

	if (ind_next_seq >= 0) {
		PutField_Int(hRls,"next_seq",v_next_seq);
DEBUGLOG(("GetTemplate() next_seq = [%d]\n",v_next_seq));
	}

/*
	if (ind_template >= 0) {
		v_template.arr[v_template.len]='\0';
		PutField_CString(hRls,"template",(char*)v_template.arr);
DEBUGLOG(("GetTemplate() template =\n%s\n",(char*)v_template.arr));
	} else {
		iRet = NOT_FOUND;
	}
*/


DEBUGLOG(("GetTemplate() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

gettemplate_error:
DEBUGLOG(("gettemplate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetTemplateDetails(hash_t *hRls)
{
	int iRet = FOUND;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettempdt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_funct[PD_EML_FUNCT_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_funct;


		/* varchar	v_desc[PD_DESCRIPTION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_desc;

		/* varchar	v_subject[PD_EML_SUBJECT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_subject;


		short	ind_desc = -1;
		short	ind_subject = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"funct",&csTmp)) {
		hv_funct.len = strlen(csTmp);
		strncpy((char*)hv_funct.arr, csTmp, hv_funct.len);
DEBUGLOG(("GetTemplateDetails funct = [%.*s]\n", hv_funct.len, hv_funct.arr));
	}

	/* EXEC SQL
		SELECT	EF_DESC,
			EFT_SUBJECT
		INTO	:v_desc:ind_desc,
			:v_subject:ind_subject
		FROM	EMAIL_FUNCT,
			EMAIL_FUNCT_TEMPLATE
		WHERE	EF_FUNCT = EFT_FUNCT
		AND	EFT_FUNCT = :hv_funct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select EF_DESC , EFT_SUBJECT INTO :b0:b1 , :b2:b3 FROM EMAI\
L_FUNCT , EMAIL_FUNCT_TEMPLATE WHERE EF_FUNCT = EFT_FUNCT AND EFT_FUNCT = :b4\
 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )56;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_desc;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_subject;
 sqlstm.sqhstl[1] = (unsigned long )103;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_subject;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_funct;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettempdt_error;
}



	if (ind_desc >= 0) {
		v_desc.arr[v_desc.len]='\0';
		PutField_CString(hRls,"desc",(char*)v_desc.arr);
DEBUGLOG(("GetTemplateDetails() desc = [%s]\n",(char*)v_desc.arr));
	}

	if (ind_subject >= 0) {
		v_subject.arr[v_subject.len]='\0';
		PutField_CString(hRls,"mail_subject",(char*)v_subject.arr);
DEBUGLOG(("GetTemplateDetails() subject = [%s]\n",(char*)v_subject.arr));
	} else {
		iRet = NOT_FOUND;
	}

DEBUGLOG(("GetTemplateDetails() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

gettempdt_error:
DEBUGLOG(("gettempdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

