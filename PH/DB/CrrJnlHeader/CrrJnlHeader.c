
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "CrrJnlHeader.pc"
};


static unsigned int sqlctx = 2411451;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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

 static char *sq0004 = 
"SELECT ACC_YEAR , ACC_MONTH FROM CRR_JNL_HEADER WHERE JNL_ID = :b0:b1      \
      ";

 static char *sq0005 = 
"select cjh . jnl_id from crr_jnl_header cjh , crr_jnl_type cjt where cjh . \
disabled = 0 and cjt . disabled = 0 and ( cjt . post_type = :b0:b1 OR cjt . p\
ost_type = 'N' ) and cjh . txn_date = :b2:b3 and cjh . country_code = :b4:b5 \
and cjh . product_code = :b6:b7 and cjt . prefix = :b8:b9 and cjh . jnl_type_\
id = cjt . jnl_type_id            ";

 static char *sq0006 = 
"select cjh . jnl_id from crr_jnl_header cjh , crr_jnl_type cjt where cjh . \
disabled = 0 and cjt . disabled = 0 and ( cjt . post_type = :b0:b1 OR cjt . p\
ost_type = 'N' ) and cjh . txn_date = :b2:b3 and cjh . country_code = :b4:b5 \
and cjh . product_code = :b6:b7 and cjh . jnl_type_id = cjt . jnl_type_id    \
        ";

 static char *sq0007 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from crr_apl_deposit_view where cr_txn_date = :b0:b1 and cr\
_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0008 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_REC_DEPOSIT_VIEW where cr_txn_date = :b0:b1 and cr\
_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0009 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_VOD_REC_DEPOSIT_VIEW where cr_txn_date = :b0:b1 an\
d cr_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0010 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from crr_deposit_cost_adj_view where cr_txn_date = :b0:b1 a\
nd cr_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0011 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_APL_PAYOUT_VIEW where cr_txn_date = :b0:b1 and cr_\
country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0012 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_GEN_PAYOUT_VIEW where cr_txn_date = :b0:b1 and cr_\
country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0013 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_VOD_APL_PAYOUT_VIEW where cr_txn_date = :b0:b1 and\
 cr_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0014 = 
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from CRR_VOD_GEN_PAYOUT_VIEW where cr_txn_date = :b0:b1 and\
 cr_country = :b2:b3 and cr_product = :b4:b5            ";

 static char *sq0015 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_SETTLE_VIEW where cr_txn_date = :b\
0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id      \
      ";

 static char *sq0016 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_DEL_SETTLE_VIEW where cr_txn_date = :b\
0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id      \
      ";

 static char *sq0017 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_VOID_SETTLE_VIEW where cr_txn_date\
 = :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id \
           ";

 static char *sq0018 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_MBT_VIEW where cr_txn_date = :b0:b\
1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id         \
   ";

 static char *sq0019 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_VOID_MBT_VIEW where cr_txn_date = \
:b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id    \
        ";

 static char *sq0020 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_MBT_2_OFF_VIEW where cr_txn_date =\
 :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id   \
         ";

 static char *sq0021 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_VOID_MBT_2_OFF_VIEW where cr_txn_d\
ate = :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_\
id            ";

 static char *sq0022 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_PBT_VIEW where cr_txn_date = :b0:b\
1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id         \
   ";

 static char *sq0023 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_PBT_2_OFF_VIEW where cr_txn_date =\
 :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id   \
         ";

 static char *sq0024 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_OFF_2_MBT_VIEW where cr_txn_date =\
 :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id   \
         ";

 static char *sq0025 = 
"select th_txn_id , cr_txn_date , cr_country , cr_product , te_party_type , \
party_id , cr_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_\
gl_id , txn_count , cr_amount from CRR_APL_OFF_2_PBT_VIEW where cr_txn_date =\
 :b0:b1 and cr_country = :b2:b3 and cr_product = :b4:b5 order by th_txn_id   \
         ";

 static char *sq0026 = 
"SELECT TXN_DATE , CR_COUNTRY_ID , CR_PRODUCT_CODE , CR_JNL_TYPE_ID , CR_JNL\
_ENTRY_TYPE_ID , CR_PARTY_TYPE , CR_PARTY_ID , CR_CURRENCY_ID , GL_ID , CR_IN\
D , TXN_AMT , TXN_COUNT , TXN_ID FROM TABLE ( CRR_JNL_DATA_PKG . GET_JNL ( :b\
0 , :b1 , :b2 , :b2 ) ) WHERE CR_COUNTRY_ID = :b4 AND CR_PRODUCT_CODE = :b5 O\
RDER BY TXN_ID            ";

 static char *sq0027 = 
"SELECT TXN_DATE , CR_COUNTRY_ID , CR_PRODUCT_CODE , CR_JNL_TYPE_ID , CR_JNL\
_ENTRY_TYPE_ID , CR_PARTY_TYPE , CR_PARTY_ID , CR_CURRENCY_ID , GL_ID , CR_IN\
D , TXN_AMT , TXN_COUNT , TXN_ID FROM TABLE ( CRR_JNL_DATA_PKG . GET_OFL_JNL \
( :b0 , :b1 , :b2 , :b2 ) ) WHERE CR_COUNTRY_ID = :b4 AND CR_PRODUCT_CODE = :\
b5 ORDER BY TXN_ID            ";

 static char *sq0028 = 
"SELECT TXN_DATE , CR_COUNTRY_ID , CR_PRODUCT_CODE , CR_JNL_TYPE_ID , CR_JNL\
_ENTRY_TYPE_ID , CR_PARTY_TYPE , CR_PARTY_ID , CR_CURRENCY_ID , GL_ID , CR_IN\
D , TXN_AMT , TXN_COUNT , TXN_ID FROM TABLE ( CRR_JNL_DATA_PKG . GET_MI_JNL (\
 :b0 , :b1 , :b2 , :b2 ) ) WHERE CR_COUNTRY_ID = :b4 AND CR_PRODUCT_CODE = :b\
5 ORDER BY TXN_ID            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,490,0,6,243,0,0,15,15,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,0,0,
80,0,0,2,0,0,17,461,0,0,1,1,0,1,0,1,9,0,0,
99,0,0,2,0,0,21,462,0,0,0,0,0,1,0,
114,0,0,2,0,0,17,522,0,0,1,1,0,1,0,1,9,0,0,
133,0,0,2,0,0,21,523,0,0,0,0,0,1,0,
148,0,0,2,0,0,17,598,0,0,1,1,0,1,0,1,9,0,0,
167,0,0,2,0,0,21,599,0,0,0,0,0,1,0,
182,0,0,2,0,0,17,672,0,0,1,1,0,1,0,1,9,0,0,
201,0,0,2,0,0,21,673,0,0,0,0,0,1,0,
216,0,0,3,100,0,6,709,0,0,2,2,0,1,0,2,1,0,0,1,9,0,0,
239,0,0,4,81,0,9,770,0,2049,1,1,0,1,0,1,9,0,0,
258,0,0,4,0,0,13,773,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
281,0,0,4,0,0,15,802,0,0,0,0,0,1,0,
296,0,0,5,340,0,9,882,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
331,0,0,5,0,0,13,884,0,0,1,0,0,1,0,2,9,0,0,
350,0,0,5,0,0,15,905,0,0,0,0,0,1,0,
365,0,0,5,0,0,15,914,0,0,0,0,0,1,0,
380,0,0,6,314,0,9,976,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
411,0,0,6,0,0,13,978,0,0,1,0,0,1,0,2,9,0,0,
430,0,0,6,0,0,15,999,0,0,0,0,0,1,0,
445,0,0,6,0,0,15,1008,0,0,0,0,0,1,0,
460,0,0,2,0,0,17,1066,0,0,1,1,0,1,0,1,9,0,0,
479,0,0,2,0,0,21,1067,0,0,0,0,0,1,0,
494,0,0,2,0,0,17,1090,0,0,1,1,0,1,0,1,9,0,0,
513,0,0,2,0,0,21,1091,0,0,0,0,0,1,0,
528,0,0,7,282,0,9,1178,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
555,0,0,7,0,0,13,1182,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
618,0,0,7,0,0,15,1270,0,0,0,0,0,1,0,
633,0,0,7,0,0,15,1279,0,0,0,0,0,1,0,
648,0,0,8,282,0,9,1514,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
675,0,0,8,0,0,13,1516,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
738,0,0,8,0,0,15,1598,0,0,0,0,0,1,0,
753,0,0,8,0,0,15,1607,0,0,0,0,0,1,0,
768,0,0,9,286,0,9,1677,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
795,0,0,9,0,0,13,1679,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
858,0,0,9,0,0,15,1761,0,0,0,0,0,1,0,
873,0,0,9,0,0,15,1770,0,0,0,0,0,1,0,
888,0,0,10,287,0,9,1840,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
915,0,0,10,0,0,13,1842,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
978,0,0,10,0,0,15,1924,0,0,0,0,0,1,0,
993,0,0,10,0,0,15,1933,0,0,0,0,0,1,0,
1008,0,0,11,281,0,9,2003,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1035,0,0,11,0,0,13,2005,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1098,0,0,11,0,0,15,2087,0,0,0,0,0,1,0,
1113,0,0,11,0,0,15,2096,0,0,0,0,0,1,0,
1128,0,0,12,281,0,9,2166,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1155,0,0,12,0,0,13,2168,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1218,0,0,12,0,0,15,2250,0,0,0,0,0,1,0,
1233,0,0,12,0,0,15,2259,0,0,0,0,0,1,0,
1248,0,0,13,285,0,9,2329,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1275,0,0,13,0,0,13,2331,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1338,0,0,13,0,0,15,2413,0,0,0,0,0,1,0,
1353,0,0,13,0,0,15,2422,0,0,0,0,0,1,0,
1368,0,0,14,285,0,9,2492,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1395,0,0,14,0,0,13,2494,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1458,0,0,14,0,0,15,2576,0,0,0,0,0,1,0,
1473,0,0,14,0,0,15,2585,0,0,0,0,0,1,0,
1488,0,0,15,312,0,9,2659,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1515,0,0,15,0,0,13,2661,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1582,0,0,15,0,0,15,2750,0,0,0,0,0,1,0,
1597,0,0,15,0,0,15,2759,0,0,0,0,0,1,0,
1612,0,0,16,312,0,9,2833,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1639,0,0,16,0,0,13,2835,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1706,0,0,16,0,0,15,2924,0,0,0,0,0,1,0,
1721,0,0,16,0,0,15,2933,0,0,0,0,0,1,0,
1736,0,0,17,317,0,9,3008,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1763,0,0,17,0,0,13,3010,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1830,0,0,17,0,0,15,3099,0,0,0,0,0,1,0,
1845,0,0,17,0,0,15,3108,0,0,0,0,0,1,0,
1860,0,0,18,309,0,9,3183,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1887,0,0,18,0,0,13,3185,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
1954,0,0,18,0,0,15,3274,0,0,0,0,0,1,0,
1969,0,0,18,0,0,15,3283,0,0,0,0,0,1,0,
1984,0,0,19,314,0,9,3358,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2011,0,0,19,0,0,13,3360,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2078,0,0,19,0,0,15,3449,0,0,0,0,0,1,0,
2093,0,0,19,0,0,15,3458,0,0,0,0,0,1,0,
2108,0,0,20,315,0,9,3533,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2135,0,0,20,0,0,13,3535,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2202,0,0,20,0,0,15,3624,0,0,0,0,0,1,0,
2217,0,0,20,0,0,15,3633,0,0,0,0,0,1,0,
2232,0,0,21,320,0,9,3708,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2259,0,0,21,0,0,13,3710,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2326,0,0,21,0,0,15,3799,0,0,0,0,0,1,0,
2341,0,0,21,0,0,15,3808,0,0,0,0,0,1,0,
2356,0,0,22,309,0,9,3882,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2383,0,0,22,0,0,13,3884,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2450,0,0,22,0,0,15,3973,0,0,0,0,0,1,0,
2465,0,0,22,0,0,15,3982,0,0,0,0,0,1,0,
2480,0,0,23,315,0,9,4056,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2507,0,0,23,0,0,13,4058,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2574,0,0,23,0,0,15,4147,0,0,0,0,0,1,0,
2589,0,0,23,0,0,15,4156,0,0,0,0,0,1,0,
2604,0,0,24,315,0,9,4230,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2631,0,0,24,0,0,13,4232,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2698,0,0,24,0,0,15,4321,0,0,0,0,0,1,0,
2713,0,0,24,0,0,15,4330,0,0,0,0,0,1,0,
2728,0,0,25,315,0,9,4404,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
2755,0,0,25,0,0,13,4406,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2822,0,0,25,0,0,15,4495,0,0,0,0,0,1,0,
2837,0,0,25,0,0,15,4504,0,0,0,0,0,1,0,
2852,0,0,26,332,0,9,4761,0,2049,6,6,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
2891,0,0,26,0,0,13,4763,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,
2958,0,0,26,0,0,15,4853,0,0,0,0,0,1,0,
2973,0,0,26,0,0,15,4862,0,0,0,0,0,1,0,
2988,0,0,27,336,0,9,4945,0,2049,6,6,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
3027,0,0,27,0,0,13,4947,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,
3094,0,0,27,0,0,15,5037,0,0,0,0,0,1,0,
3109,0,0,27,0,0,15,5046,0,0,0,0,0,1,0,
3124,0,0,28,335,0,9,5129,0,2049,6,6,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
3163,0,0,28,0,0,13,5131,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,
3230,0,0,28,0,0,15,5221,0,0,0,0,0,1,0,
3245,0,0,28,0,0,15,5230,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/19              Simon Fung
Restruture BOCrrJnl and DBJnlHeader                2013/01/29              Stan Poon
PSP SETTLEMENT                                     2013/03/13              Stan Poon
Offline CRR					   2015/03/20		   Dirk Wong
MiniMMM CRR					   2015/12/22		   Dirk Wong
Handle online: Void Merchant Settlement		   2016/05/19		   Dirk Wong
Handle online: Void Merch Bal Transfer to Offline  2016/10/05		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "CrrJnlHeader.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(BO);
OBJPTR(DB);

char    cDebug;
void CrrJnlHeader(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char	*csTmp;
	char  cTmp;
	int		iTmp;

  /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


  short 		hv_return_value;
  /* varchar		hv_jnl_id[PD_JNL_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_jnl_id;
	
	int		hv_jnl_type_id;	
	/* varchar		hv_description[PD_DESCRIPTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_description;
	
	/* varchar		hv_txn_date[PD_TXN_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;
	
	/* varchar		hv_bank_update_date[PD_BANK_UPDATE_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_bank_update_date;
	
	/* varchar		hv_acc_year[PD_ACC_YEAR_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_acc_year;

	/* varchar		hv_acc_month[PD_ACC_MONTH_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_acc_month;

	/* varchar		hv_country_code[PD_COUNTRY_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_code;

	/* varchar		hv_product_code[PD_PRODUCT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_product_code;

	/* varchar		hv_ref_no[PD_REF_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_ref_no;
	
	/* varchar		hv_remarks[PD_REMARKS_LEN]; */ 
struct { unsigned short len; unsigned char arr[300]; } hv_remarks;
	
	char		hv_status;	
	int		hv_disabled;	
	/* varchar		hv_create_user[PD_CREATE_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;
	

	short		ind_jnl_id = -1;
	short		ind_jnl_type_id = -1;
	short		ind_description = -1;
	short		ind_txn_date = -1;
	short		ind_bank_update_date = -1;
	short		ind_acc_year = -1;
	short		ind_acc_month = -1;
	short		ind_country_code = -1;
	short		ind_product_code = -1;
	short		ind_ref_no = -1;
	short		ind_remarks = -1;
	short		ind_status = -1;
	short		ind_disabled = -1;
	short		ind_create_user = -1;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	/* jnl_id */
	if (GetField_CString(hRls,"jnl_id",&csTmp)) {
		hv_jnl_id.len = strlen(csTmp);
		memcpy(hv_jnl_id.arr,csTmp,hv_jnl_id.len);
		ind_jnl_id = 0;
DEBUGLOG(("Add:jnl_id = [%.*s]\n",hv_jnl_id.len,hv_jnl_id.arr));
	} else {
DEBUGLOG(("Add:jnl_id not found\n"));
		return PD_ERR;
	}

	
	/* jnl_type_id */
	if (GetField_Int(hRls,"jnl_type_id",&iTmp)) {
		hv_jnl_type_id = iTmp;
		ind_jnl_type_id = 0;
DEBUGLOG(("Add:jnl_type_id = [%d]\n",hv_jnl_type_id));
	} else {
DEBUGLOG(("Add:jnl_type_id not found\n"));
		return PD_ERR;
	}

	
	/* description */
	if (GetField_CString(hRls,"description",&csTmp)) {
		hv_description.len = strlen(csTmp);
		memcpy(hv_description.arr,csTmp,hv_description.len);
		ind_description = 0;
DEBUGLOG(("Add:description = [%.*s]\n",hv_description.len,hv_description.arr));
	}

	
	/* txn_date */
	if (GetField_CString(hRls,"txn_date",&csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
	} else {
DEBUGLOG(("Add:txn_date not found\n"));
		return PD_ERR;
	}


	
	/* bank_update_date */
	if (GetField_CString(hRls,"bank_update_date",&csTmp)) {
		hv_bank_update_date.len = strlen(csTmp);
		memcpy(hv_bank_update_date.arr,csTmp,hv_bank_update_date.len);
		ind_bank_update_date = 0;
DEBUGLOG(("Add:bank_update_date = [%.*s]\n",hv_bank_update_date.len,hv_bank_update_date.arr));
	}

	
	/* acc_year */
	if (GetField_CString(hRls,"acc_year",&csTmp)) {
		hv_acc_year.len = strlen(csTmp);
		memcpy(hv_acc_year.arr,csTmp,hv_acc_year.len);
		ind_acc_year = 0;
DEBUGLOG(("Add:acc_year = [%.*s]\n",hv_acc_year.len,hv_acc_year.arr));
	} else {
DEBUGLOG(("Add:acc_year not found\n"));
		return PD_ERR;
	}

	
	/* acc_month */
	if (GetField_CString(hRls,"acc_month",&csTmp)) {
		hv_acc_month.len = strlen(csTmp);
		memcpy(hv_acc_month.arr,csTmp,hv_acc_month.len);
		ind_acc_month = 0;
DEBUGLOG(("Add:acc_month = [%.*s]\n",hv_acc_month.len,hv_acc_month.arr));
	} else {
DEBUGLOG(("Add:acc_month not found\n"));
		return PD_ERR;
	}
	
	/* country_code */
	if (GetField_CString(hRls,"country_code",&csTmp)) {
		hv_country_code.len = strlen(csTmp);
		memcpy(hv_country_code.arr,csTmp,hv_country_code.len);
		ind_country_code = 0;
DEBUGLOG(("Add:country_code = [%.*s]\n",hv_country_code.len,hv_country_code.arr));
	} else {
DEBUGLOG(("Add:country_code not found\n"));
		return PD_ERR;
	}

	/* product_code */
	if (GetField_CString(hRls,"product_code",&csTmp)) {
		hv_product_code.len = strlen(csTmp);
		memcpy(hv_product_code.arr,csTmp,hv_product_code.len);
		ind_product_code = 0;
DEBUGLOG(("Add:product_code = [%.*s]\n",hv_product_code.len,hv_product_code.arr));
	} else {
DEBUGLOG(("Add:product_code not found\n"));
		return PD_ERR;
	}
	
	/* ref_no */
	if (GetField_CString(hRls,"ref_no",&csTmp)) {
		hv_ref_no.len = strlen(csTmp);
		memcpy(hv_ref_no.arr,csTmp,hv_ref_no.len);
		ind_ref_no = 0;
DEBUGLOG(("Add:ref_no = [%.*s]\n",hv_ref_no.len,hv_ref_no.arr));
	}

	
	/* remarks */
	if (GetField_CString(hRls,"remarks",&csTmp)) {
		hv_remarks.len = strlen(csTmp);
		memcpy(hv_remarks.arr,csTmp,hv_remarks.len);
		ind_remarks = 0;
DEBUGLOG(("Add:remarks = [%.*s]\n",hv_remarks.len,hv_remarks.arr));
	}

	/* status */ 
	if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
	} else {
DEBUGLOG(("Add:status not found\n"));
		return PD_ERR;
	}

	
	/* disabled */
	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	} else {
		hv_disabled = 0;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled (default) = [%d]\n",hv_disabled));
	}
	
	/* create_user */
	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr,csTmp,hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	} else {
DEBUGLOG(("Add:create_user not found\n"));
		return PD_ERR;
	}
		
	/* EXEC SQL EXECUTE BEGIN
			:hv_return_value := sp_crr_jnl_header_insert(
			:hv_jnl_id:ind_jnl_id,
			:hv_jnl_type_id:ind_jnl_type_id,
			:hv_description:ind_description,
			:hv_txn_date:ind_txn_date,
			:hv_bank_update_date:ind_bank_update_date,
			:hv_acc_year:ind_acc_year,
			:hv_acc_month:ind_acc_month,
			:hv_country_code:ind_country_code,
			:hv_product_code:ind_product_code,			
			:hv_ref_no:ind_ref_no,
			:hv_remarks:ind_remarks,
			:hv_status:ind_status,
			:hv_disabled:ind_disabled,
			:hv_create_user:ind_create_user
					);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_crr_jnl_header_insert ( :hv_jn\
l_id:ind_jnl_id , :hv_jnl_type_id:ind_jnl_type_id , :hv_description:ind_descr\
iption , :hv_txn_date:ind_txn_date , :hv_bank_update_date:ind_bank_update_dat\
e , :hv_acc_year:ind_acc_year , :hv_acc_month:ind_acc_month , :hv_country_cod\
e:ind_country_code , :hv_product_code:ind_product_code , :hv_ref_no:ind_ref_n\
o , :hv_remarks:ind_remarks , :hv_status:ind_status , :hv_disabled:ind_disabl\
ed , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_jnl_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_jnl_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_jnl_type_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_jnl_type_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_description;
 sqlstm.sqhstl[3] = (unsigned long )102;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_description;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[4] = (unsigned long )10;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_date;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_update_date;
 sqlstm.sqhstl[5] = (unsigned long )10;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_update_date;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_acc_year;
 sqlstm.sqhstl[6] = (unsigned long )6;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_acc_year;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_acc_month;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_acc_month;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_country_code;
 sqlstm.sqhstl[8] = (unsigned long )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_country_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_product_code;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_product_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_ref_no;
 sqlstm.sqhstl[10] = (unsigned long )102;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_ref_no;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_remarks;
 sqlstm.sqhstl[11] = (unsigned long )302;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_remarks;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[12] = (unsigned long )1;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_status;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_disabled;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[14] = (unsigned long )22;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_create_user;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
    
  if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
    return PD_OK;
  }

  if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("CrrJnlHeader_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
    return PD_OTHER_ERR;
  }

  if (hv_return_value == SP_ERR)  {
		ERRLOG("CrrJnlHeader_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
    return PD_ERR;
  }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));

  return PD_INTERNAL_ERR;
}

int Update(const hash_t *hRls)
{

	char*	csTmp;
	char	cTmp;
	int	iTmp;
	char*	csBuf;
	char*	csJnlId;
  /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_jnl_header set update_timestamp  = sysdate");

  if (GetField_CString(hRls,"jnl_id",&csJnlId)) {
DEBUGLOG(("Update:jnl_id = [%s]\n",csJnlId));
	} else {
DEBUGLOG(("Update:jnl_id not found\n"));
		return PD_ERR;
	}
				
	/* jnl_type_id  */
	if (GetField_Int(hRls,"jnl_type_id",&iTmp)) {
DEBUGLOG(("Update:jnl_type_id = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",jnl_type_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		//strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* description */
	if (GetField_CString(hRls,"description",&csTmp)) {
DEBUGLOG(("Update:description = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",description = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* txn_date */
	if (GetField_CString(hRls,"txn_date",&csTmp)) {
DEBUGLOG(("Update:txn_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",txn_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* bank_update_date */
	if (GetField_CString(hRls,"bank_update_date",&csTmp)) {
DEBUGLOG(("Update:bank_update_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",bank_update_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* acc_year  */
	if (GetField_CString(hRls,"acc_year",&csTmp)) {
DEBUGLOG(("Update:acc_year = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",acc_year = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* acc_month  */
	if (GetField_CString(hRls,"acc_month",&csTmp)) {
DEBUGLOG(("Update:acc_month = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",acc_month = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	/* country_code  */
	if (GetField_CString(hRls,"country_code",&csTmp)) {
DEBUGLOG(("Update:country_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",country_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	/* product_code  */
	if (GetField_CString(hRls,"product_code",&csTmp)) {
DEBUGLOG(("Update:product_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",product_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}	
	
	/* ref_no */
	if (GetField_CString(hRls,"ref_no",&csTmp)) {
DEBUGLOG(("Update:ref_no = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",ref_no = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* remarks */
	if (GetField_CString(hRls,"remarks",&csTmp)) {
DEBUGLOG(("Update:remarks = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",remarks = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* status */ 
	if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:status = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	/* disabled  */
	if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",disabled = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		//strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	/* update_user */
	if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	// Reset the approval/booked whenever updated
	strcat((char*)hv_dynstmt.arr, ",approve_user = NULL");
	strcat((char*)hv_dynstmt.arr, ",approve_timestamp = NULL");
	strcat((char*)hv_dynstmt.arr, ",book_user = NULL");
	strcat((char*)hv_dynstmt.arr, ",book_timestamp = NULL");
		
	strcat((char *)hv_dynstmt.arr, " WHERE jnl_id = '");
  strcat((char *)hv_dynstmt.arr, csJnlId);
  strcat((char *)hv_dynstmt.arr, "'");
 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )80;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto update_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);
	
DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int Delete(const hash_t *hRls)
{

	char*	csTmp;
	char*	csBuf;
	char*	csJnlId;
  /* EXEC SQL WHENEVER SQLERROR GOTO disable_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_jnl_header set update_timestamp  = sysdate, disabled = 1 ");

  if (GetField_CString(hRls,"jnl_id",&csJnlId)) {
DEBUGLOG(("Delete:jnl_id = [%s]\n",csJnlId));
	} else {
DEBUGLOG(("Delete:jnl_id not found\n"));
		return PD_ERR;
	}
			
	/* update_user */
	if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Delete:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
	} else {
DEBUGLOG(("Delete:update_user not found\n"));
		return PD_ERR;
	}
	
	strcat((char *)hv_dynstmt.arr, " WHERE jnl_id = '");
  strcat((char *)hv_dynstmt.arr, csJnlId);
  strcat((char *)hv_dynstmt.arr, "'");
 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )114;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto disable_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )133;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto disable_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Delete Normal Exit\n"));
	return PD_OK;

disable_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_Delete: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int Approve(const hash_t *hRls)
{

	char*	csTmp;
	char*	csBuf;
	char*	csJnlId;
  /* EXEC SQL WHENEVER SQLERROR GOTO approve_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Approve: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_jnl_header set approve_timestamp  = sysdate");

  if (GetField_CString(hRls,"jnl_id",&csJnlId)) {
DEBUGLOG(("Approve:jnl_id = [%s]\n",csJnlId));
	} else {
DEBUGLOG(("Approve:jnl_id not found\n"));
		return PD_ERR;
	}
			
	/* status to A */ 
DEBUGLOG(("Approve:status = [%c]\n",PD_JNL_APPROVED));
	sprintf(csBuf,"%c",PD_JNL_APPROVED);
	strcat((char*)hv_dynstmt.arr, ",status = '");
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");

	/* approve_user */
	if (GetField_CString(hRls,"approve_user",&csTmp)) {
DEBUGLOG(("Approve:approve_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",approve_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");	
	} else {
DEBUGLOG(("Approve:approve_user not found\n"));
		return PD_ERR;
	}
	
	strcat((char *)hv_dynstmt.arr, " WHERE jnl_id = '");
	strcat((char *)hv_dynstmt.arr, csJnlId);
	strcat((char *)hv_dynstmt.arr, "'");
	// Approve only pending journal
	/*
	sprintf(csBuf,"%c",PD_JNL_PENDING);
	strcat((char*)hv_dynstmt.arr, " AND STATUS = '");
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");	
	*/

	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto approve_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )167;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto approve_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Approve Normal Exit\n"));
	return PD_OK;

approve_error:
DEBUGLOG(("approve_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_Approve: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Approve: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int Release(const hash_t *hRls)
{

	char*	csTmp;
	char*	csBuf;
	char*	csJnlId;
  /* EXEC SQL WHENEVER SQLERROR GOTO release_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Release: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_jnl_header set update_timestamp  = sysdate");

   if (GetField_CString(hRls,"jnl_id",&csJnlId)) {
DEBUGLOG(("Release:jnl_id = [%s]\n",csJnlId));
	} else {
DEBUGLOG(("Release:jnl_id not found\n"));
		return PD_ERR;
	}
			
	/* status to P */ 
DEBUGLOG(("Release:status = [%c]\n",PD_JNL_PENDING));
	sprintf(csBuf,"%c",PD_JNL_PENDING);
	strcat((char*)hv_dynstmt.arr, ",status = '");
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");

	/* update_user */
	if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Release:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");	
	} else {
DEBUGLOG(("Release:update_user not found\n"));
		return PD_ERR;
	}

	// Reset the approval/booked when release
	strcat((char*)hv_dynstmt.arr, ",approve_user = NULL");
	strcat((char*)hv_dynstmt.arr, ",approve_timestamp = NULL");
	strcat((char*)hv_dynstmt.arr, ",book_user = NULL");
	strcat((char*)hv_dynstmt.arr, ",book_timestamp = NULL");
	
	strcat((char *)hv_dynstmt.arr, " WHERE jnl_id = '");
  strcat((char *)hv_dynstmt.arr, csJnlId);
  strcat((char *)hv_dynstmt.arr, "'");
 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )182;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto release_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )201;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto release_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Release Normal Exit\n"));
	return PD_OK;

release_error:
DEBUGLOG(("release_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_Release: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Approve: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int GetJnlStatus(const char* csJnlId, char* cJnlStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO GetJnlStatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar		hv_jnl_id[PD_JNL_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_jnl_id;
	
	char		hv_status;	
	short		ind_status = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetJnlStatus: Begin\n"));
		
	/* jnl_id */
	hv_jnl_id.len = strlen(csJnlId);
	memcpy(hv_jnl_id.arr,csJnlId,hv_jnl_id.len);
DEBUGLOG(("GetJnlStatus:jnl_id = [%.*s]\n",hv_jnl_id.len,hv_jnl_id.arr));

	/* EXEC SQL EXECUTE
		BEGIN
		SELECT STATUS INTO :hv_status:ind_status
			FROM CRR_JNL_HEADER 
			WHERE JNL_ID = :hv_jnl_id;
    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin SELECT STATUS INTO :hv_status:ind_status FROM CRR_JNL\
_HEADER WHERE JNL_ID = :hv_jnl_id ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )216;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_status;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_jnl_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetJnlStatus_error;
}


        	
	if (ind_status == -1) {
		hv_status = ' ';
	}
	
	*cJnlStatus = (char) hv_status;

DEBUGLOG(("GetJnlStatus:status = [%c]\n",hv_status));
	
	return PD_OK;

GetJnlStatus_error:
DEBUGLOG(("GetJnlStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_GetJnlStatus: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int GetJnlAccYearMonth(const char* csJnlId, char* csAccYear, char* csAccMonth)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO GetJnlAccYearMonth_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_jnl_id[PD_JNL_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_jnl_id;

		short		ind_jnl_id = -1;
		
		/* varchar		v_acc_year[PD_ACC_YEAR_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_acc_year;

		short		ind_acc_year = -1;	
		
		/* varchar		v_acc_month[PD_ACC_MONTH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_acc_month;
	
		short		ind_acc_month = -1;	

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetJnlAccYearMonth: Begin\n"));
		
	hv_jnl_id.len = strlen(csJnlId);
	memcpy(hv_jnl_id.arr,csJnlId,hv_jnl_id.len);
DEBUGLOG(("GetJnlAccYearMonth:jnl_id = [%.*s]\n",hv_jnl_id.len,hv_jnl_id.arr));
	ind_jnl_id = 0;

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		SELECT	
			ACC_YEAR,
			ACC_MONTH
		FROM	
			CRR_JNL_HEADER
		WHERE	
			JNL_ID = :hv_jnl_id:ind_jnl_id; */ 


	/* EXEC SQL OPEN c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )239;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_jnl_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_jnl_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetJnlAccYearMonth_error;
}


	
	do {
		/* EXEC SQL FETCH c_cursor_get
			INTO
		:v_acc_year:ind_acc_year,
		:v_acc_month:ind_acc_month; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )258;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_acc_year;
  sqlstm.sqhstl[0] = (unsigned long )7;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_acc_year;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_acc_month;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_acc_month;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto GetJnlAccYearMonth_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if(ind_acc_year>=0) {
			v_acc_year.arr[v_acc_year.len] = '\0';
			strcpy(csAccYear,(const char *)v_acc_year.arr);
DEBUGLOG(("GetJnlAccYearMonth:csAccYear = [%s]\n",csAccYear));
		} else {
DEBUGLOG(("GetJnlAccYearMonth:v_acc_year not found\n"));			
		}

		if(ind_acc_month>=0) {
			v_acc_month.arr[v_acc_month.len] = '\0';
			strcpy(csAccMonth,(const char *)v_acc_month.arr);
DEBUGLOG(("GetJnlAccYearMonth:csAccMonth = [%s]\n",csAccMonth));			
			
		} else {
DEBUGLOG(("GetJnlAccYearMonth:v_acc_month not found\n"));			
		}
		

	} while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )281;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetJnlAccYearMonth_error;
}


DEBUGLOG(("GetJnlAccYearMonth Normal Exit\n")); 
	return PD_OK;

GetJnlAccYearMonth_error:
DEBUGLOG(("GetJnlAccYearMonth_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	//ERRLOG("CrrJnlHeader_GetJnlAccYearMonth: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("GetJnlAccYearMonth: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int GetPostJnl(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct, const char* csJnlType, const char cPostType)
{
	hash_t *myHash;
	
	char csPostType[PD_JNL_TYPE_POST_TYPE_LEN + 1];
	sprintf(csPostType,"%c",cPostType);
	
	/* EXEC SQL WHENEVER SQLERROR GOTO GetPostJnl_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
	/* varchar	v_jnl_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_jnl_id;

	short	ind_jnl_id = -1;

	/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

	short	ind_cr_txn_date = -1;
	
	/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

	short	ind_country = -1;
	
	/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

	short	ind_product = -1;

	/* varchar	v_jnl_type[PD_JNL_TYPE_PREFIX_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_jnl_type;

	short	ind_jnl_type = -1;

	/* varchar	v_post_type[PD_JNL_TYPE_POST_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_post_type;

	short	ind_post_type = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	
	
	v_jnl_type.len = strlen(csJnlType);
	memcpy(v_jnl_type.arr,csJnlType,v_jnl_type.len);
	ind_jnl_type = 0;	

	v_post_type.len = PD_JNL_TYPE_POST_TYPE_LEN;
	memcpy(v_post_type.arr,csPostType,v_post_type.len);
	ind_post_type = 0;	

DEBUGLOG(("GetPostJnl csTxnDate = [%s], csCountry = [%s], csProduct = [%s], csJnlType = [%s], csPostType = [%]\n ",csTxnDate,csCountry,csProduct,csJnlType, csPostType));
	
	/* EXEC SQL DECLARE c_cursor_GetPostJnl CURSOR FOR
		select cjh.jnl_id
		from crr_jnl_header cjh, crr_jnl_type cjt
		where cjh.disabled = 0
		and cjt.disabled = 0
		and (cjt.post_type = :v_post_type:ind_post_type OR
                     cjt.post_type = 'N')
		and cjh.txn_date = :v_cr_txn_date:ind_cr_txn_date 
		and cjh.country_code = :v_country:ind_country 
		and cjh.product_code = :v_product:ind_product
		and cjt.prefix = :v_jnl_type:ind_jnl_type
		and cjh.jnl_type_id = cjt.jnl_type_id; */ 
	
	
	
	/* EXEC SQL OPEN c_cursor_GetPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )296;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_post_type;
 sqlstm.sqhstl[0] = (unsigned long )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_post_type;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[3] = (unsigned long )6;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_product;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_jnl_type;
 sqlstm.sqhstl[4] = (unsigned long )8;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_jnl_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetPostJnl_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetPostJnl
              	INTO			
			:v_jnl_id:ind_jnl_id; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )331;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_jnl_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_jnl_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetPostJnl_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_jnl_id >= 0) {
				v_jnl_id.arr[v_jnl_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_id",(const char*)v_jnl_id.arr);
DEBUGLOG(("GetPostJnl v_jnl_id = [%s]\n",v_jnl_id.arr)); 
			}
		
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )350;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetPostJnl_error;
}



DEBUGLOG(("GetPostJnl Normal Exit\n")); 
	return  PD_OK;

GetPostJnl_error:
DEBUGLOG(("GetPostJnl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )365;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetAllPostJnl(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct, const char cPostType)
{
	hash_t *myHash;
	char csPostType[PD_JNL_TYPE_POST_TYPE_LEN + 1];
	sprintf(csPostType,"%c",cPostType);

	/* EXEC SQL WHENEVER SQLERROR GOTO GetAllPostJnl_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_jnl_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_jnl_id;

		short	ind_jnl_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;

		/* varchar	v_post_type[PD_JNL_TYPE_POST_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_post_type;

		short	ind_post_type = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

	v_post_type.len = PD_JNL_TYPE_POST_TYPE_LEN;
	memcpy(v_post_type.arr,csPostType,v_post_type.len);
	ind_post_type = 0;	

DEBUGLOG(("GetAllPostJnl csTxnDate = [%s], csCountry = [%s], csProduct = [%s], csPostType = [%s]\n ",csTxnDate,csCountry,csProduct,csPostType));
	
	/* EXEC SQL DECLARE c_cursor_GetAllPostJnl CURSOR FOR
		select cjh.jnl_id
		from crr_jnl_header cjh, crr_jnl_type cjt
		where cjh.disabled = 0
		and cjt.disabled = 0
		and (cjt.post_type = :v_post_type:ind_post_type OR
		     cjt.post_type = 'N')
		and cjh.txn_date = :v_cr_txn_date:ind_cr_txn_date 
		and cjh.country_code = :v_country:ind_country 
		and cjh.product_code = :v_product:ind_product
		and cjh.jnl_type_id = cjt.jnl_type_id; */ 
	
	
	
	/* EXEC SQL OPEN c_cursor_GetAllPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )380;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_post_type;
 sqlstm.sqhstl[0] = (unsigned long )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_post_type;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[3] = (unsigned long )6;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_product;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetAllPostJnl_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetAllPostJnl
              	INTO			
			:v_jnl_id:ind_jnl_id; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )411;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_jnl_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_jnl_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetAllPostJnl_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_jnl_id >= 0) {
				v_jnl_id.arr[v_jnl_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_id",(const char*)v_jnl_id.arr);
DEBUGLOG(("GetAllPostJnl v_jnl_id = [%s]\n",v_jnl_id.arr)); 
			}
		
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetAllPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )430;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetAllPostJnl_error;
}



DEBUGLOG(("GetAllPostJnl Normal Exit\n")); 
	return  PD_OK;

GetAllPostJnl_error:
DEBUGLOG(("GetAllPostJnl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetAllPostJnl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )445;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int UpdateMonthEnd(const char* csTbYear, const char* csTbMonth, const char* csBookUser)
{
	char*	csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO monthend_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateMonthEnd: Begin\n"));
	csBuf = (char*) malloc (128);
	
	strcpy((char*)hv_dynstmt.arr,"update crr_jnl_header set book_timestamp  = sysdate");
	//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("UpdateMonthEnd:csTbYear = [%s]\n",csTbYear));
DEBUGLOG(("UpdateMonthEnd:csTbMonth = [%s]\n",csTbMonth));
DEBUGLOG(("UpdateMonthEnd:csBookUser = [%s]\n",csBookUser));	
			
	/* status to PD_JNL_POSTED (B) */
DEBUGLOG(("UpdateMonthEnd:status = [%c]\n",PD_JNL_POSTED));
	sprintf(csBuf,"%c",PD_JNL_POSTED);
	strcat((char*)hv_dynstmt.arr, ",status = '");
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");
	//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* book_user */
DEBUGLOG(("UpdateMonthEnd:book_user = [%s]\n",csBookUser));
	strcat((char*)hv_dynstmt.arr, ",book_user = '");
	strcat((char*)hv_dynstmt.arr, csBookUser);
	strcat((char*)hv_dynstmt.arr, "'");
	//hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " WHERE acc_year = '");
	strcat((char *)hv_dynstmt.arr, csTbYear);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND acc_month = '");
	strcat((char *)hv_dynstmt.arr, csTbMonth);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND status = '");
	sprintf(csBuf,"%c",PD_JNL_APPROVED);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, "'");  
	strcat((char *)hv_dynstmt.arr, " AND disabled = 0");

 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )460;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto monthend_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )479;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto monthend_error;
}



DEBUGLOG(("UpdateMonthEnd: Start to add change log\n"));
	strcpy((char *)hv_dynstmt.arr,"insert into crr_jnl_change_log");
	strcat((char *)hv_dynstmt.arr, " select (select max(jnl_change_log_id)  from crr_jnl_change_log)+rownum jnl_change_log_id,");
	strcat((char *)hv_dynstmt.arr, " jnl_id, null,null, 'Post', status, book_user, sysdate, book_user ");
	strcat((char *)hv_dynstmt.arr, " from crr_jnl_header ");
	strcat((char *)hv_dynstmt.arr, " WHERE acc_year = '");
	strcat((char *)hv_dynstmt.arr, csTbYear);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND acc_month = '");
	strcat((char *)hv_dynstmt.arr, csTbMonth);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND status = '");
	sprintf(csBuf,"%c",PD_JNL_POSTED);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, "'");  
	strcat((char *)hv_dynstmt.arr, " AND disabled = 0");
	
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )494;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto monthend_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )513;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto monthend_error;
}


	
	FREE_ME(csBuf);
	
DEBUGLOG(("UpdateMonthEnd Normal Exit\n"));
	return PD_OK;

monthend_error:
DEBUGLOG(("UpdateMonthEnd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlHeader_UpdateMonthEnd: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateMonthEnd: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}





int GetApprovedDeposit(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetApprovedDeposit_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetApprovedDeposit csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetApprovedDeposit csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetApprovedDeposit csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetApprovedDeposit CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from crr_apl_deposit_view
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


DEBUGLOG(("GetApprovedDeposit opening cursor...\n"));
	/* EXEC SQL OPEN c_cursor_GetApprovedDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )528;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetApprovedDeposit_error;
}


DEBUGLOG(("GetApprovedDeposit cursor opened\n"));
        do {    
DEBUGLOG(("GetApprovedDeposit fetching cursor...\n"));
        	/* EXEC SQL FETCH c_cursor_GetApprovedDeposit
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )555;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetApprovedDeposit_error;
}


DEBUGLOG(("GetApprovedDeposit cursor fetched\n"));

			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

DEBUGLOG(("GetApprovedDeposit allocating hash...\n"));
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);
DEBUGLOG(("GetApprovedDeposit hash allocated\n"));

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedDeposit v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedDeposit v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedDeposit v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedDeposit v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedDeposit v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedDeposit v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedDeposit v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedDeposit v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedDeposit v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedDeposit v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedDeposit v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedDeposit v_txn_amt = [%f]\n",v_txn_amt)); 
			}			

DEBUGLOG(("GetApprovedDeposit adding RecordSet...\n"));
			RecordSet_Add(myRec,myHash);
DEBUGLOG(("GetApprovedDeposit RecordSet added\n"));
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetApprovedDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )618;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetApprovedDeposit_error;
}



DEBUGLOG(("GetApprovedDeposit Normal Exit\n")); 
	return  PD_OK;

GetApprovedDeposit_error:
DEBUGLOG(("GetApprovedDeposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetApprovedDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )633;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

/*
int GetVoidDeposit(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	EXEC SQL WHENEVER SQLERROR GOTO GetVoidDeposit_error;
    EXEC SQL WHENEVER NOTFOUND CONTINUE;		
	
	EXEC SQL BEGIN DECLARE SECTION;		
		varchar	v_cr_txn_date[PD_DATE_LEN + 1];
		short	ind_cr_txn_date = -1;
		
		varchar	v_country[PD_COUNTRY_CODE_LEN + 1];
		short	ind_country = -1;
		
		varchar	v_product[PD_PRODUCT_CODE_LEN + 1];
		short	ind_product = -1;
		
		varchar	v_party_type[PD_PARTY_TYPE_LEN + 1];
		short	ind_party_type = -1;
		
		varchar	v_party_id[PD_PARTY_ID_LEN + 1];
		short	ind_party_id = -1;	
		
		varchar	v_currency[PD_CURRENCY_ID_LEN + 1];
		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1];
		short	ind_jnl_entry_type_id = -1;	
		
		varchar	v_cr_ind[PD_CR_IND_LEN + 1];
		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	EXEC SQL END DECLARE SECTION;

	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidDeposit csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidDeposit csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidDeposit csProduct = [%s]\n",csProduct));
	
	EXEC SQL DECLARE c_cursor_GetVoidDeposit CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_VOD_DEPOSIT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product;

	EXEC SQL OPEN c_cursor_GetVoidDeposit;
        do {    
        	EXEC SQL FETCH c_cursor_GetVoidDeposit
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt;

			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidDeposit v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidDeposit v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidDeposit v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidDeposit v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidDeposit v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidDeposit v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidDeposit v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidDeposit v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidDeposit v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidDeposit v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidDeposit v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidDeposit v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	EXEC SQL CLOSE c_cursor_GetVoidDeposit;

DEBUGLOG(("GetVoidDeposit Normal Exit\n")); 
	return  PD_OK;

GetVoidDeposit_error:
DEBUGLOG(("GetVoidDeposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_GetVoidDeposit;
	return PD_ERR;
}
*/

int GetReconDeposit(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetReconDeposit_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetReconDeposit csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetReconDeposit csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetReconDeposit csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetReconDeposit CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_REC_DEPOSIT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )648;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetReconDeposit_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetReconDeposit
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )675;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetReconDeposit_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetReconDeposit v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetReconDeposit v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetReconDeposit v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetReconDeposit v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetReconDeposit v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetReconDeposit v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetReconDeposit v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetReconDeposit v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetReconDeposit v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetReconDeposit v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetReconDeposit v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetReconDeposit v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )738;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetReconDeposit_error;
}



DEBUGLOG(("GetReconDeposit Normal Exit\n")); 
	return  PD_OK;

GetReconDeposit_error:
DEBUGLOG(("GetReconDeposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )753;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetVoidReconDeposit(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidReconDeposit_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidReconDeposit csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidReconDeposit csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidReconDeposit csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidReconDeposit CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_VOD_REC_DEPOSIT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetVoidReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )768;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidReconDeposit_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidReconDeposit
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )795;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidReconDeposit_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidReconDeposit v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidReconDeposit v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidReconDeposit v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidReconDeposit v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidReconDeposit v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidReconDeposit v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidReconDeposit v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidReconDeposit v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidReconDeposit v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidReconDeposit v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidReconDeposit v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidReconDeposit v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )858;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidReconDeposit_error;
}



DEBUGLOG(("GetVoidReconDeposit Normal Exit\n")); 
	return  PD_OK;

GetVoidReconDeposit_error:
DEBUGLOG(("GetVoidReconDeposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidReconDeposit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )873;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetDepositCostAdj(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetDepositCostAdj_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetDepositCostAdj csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetDepositCostAdj csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetDepositCostAdj csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetDepositCostAdj CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from crr_deposit_cost_adj_view
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetDepositCostAdj; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )888;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetDepositCostAdj_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetDepositCostAdj
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )915;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetDepositCostAdj_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetDepositCostAdj v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetDepositCostAdj v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetDepositCostAdj v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetDepositCostAdj v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetDepositCostAdj v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetDepositCostAdj v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetDepositCostAdj v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetDepositCostAdj v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetDepositCostAdj v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetDepositCostAdj v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetDepositCostAdj v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetDepositCostAdj v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetDepositCostAdj; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )978;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetDepositCostAdj_error;
}



DEBUGLOG(("GetDepositCostAdj Normal Exit\n")); 
	return  PD_OK;

GetDepositCostAdj_error:
DEBUGLOG(("GetDepositCostAdj_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetDepositCostAdj; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )993;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetApprovedPayout(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetApprovedPayout_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetApprovedPayout csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetApprovedPayout csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetApprovedPayout csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetApprovedPayout CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_PAYOUT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1008;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetApprovedPayout_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetApprovedPayout
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1035;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetApprovedPayout_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedPayout v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedPayout v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedPayout v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedPayout v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedPayout v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedPayout v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedPayout v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedPayout v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedPayout v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedPayout v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedPayout v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedPayout v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1098;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetApprovedPayout_error;
}



DEBUGLOG(("GetApprovedPayout Normal Exit\n")); 
	return  PD_OK;

GetApprovedPayout_error:
DEBUGLOG(("GetApprovedPayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1113;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetGeneratedPayout(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetGeneratedPayout_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetGeneratedPayout csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetGeneratedPayout csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetGeneratedPayout csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetGeneratedPayout CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_GEN_PAYOUT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetGeneratedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1128;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetGeneratedPayout_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetGeneratedPayout
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1155;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetGeneratedPayout_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetGeneratedPayout v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetGeneratedPayout v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetGeneratedPayout v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetGeneratedPayout v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetGeneratedPayout v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetGeneratedPayout v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetGeneratedPayout v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetGeneratedPayout v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetGeneratedPayout v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetGeneratedPayout v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetGeneratedPayout v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetGeneratedPayout v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetGeneratedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1218;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetGeneratedPayout_error;
}



DEBUGLOG(("GetGeneratedPayout Normal Exit\n")); 
	return  PD_OK;

GetGeneratedPayout_error:
DEBUGLOG(("GetGeneratedPayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetGeneratedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1233;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetVoidApprovedPayout(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidApprovedPayout_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidApprovedPayout csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidApprovedPayout csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidApprovedPayout csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidApprovedPayout CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_VOD_APL_PAYOUT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetVoidApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1248;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidApprovedPayout_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidApprovedPayout
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1275;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidApprovedPayout_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidApprovedPayout v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidApprovedPayout v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidApprovedPayout v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidApprovedPayout v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidApprovedPayout v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidApprovedPayout v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidApprovedPayout v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidApprovedPayout v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidApprovedPayout v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidApprovedPayout v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidApprovedPayout v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidApprovedPayout v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1338;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidApprovedPayout_error;
}



DEBUGLOG(("GetVoidApprovedPayout Normal Exit\n")); 
	return  PD_OK;

GetVoidApprovedPayout_error:
DEBUGLOG(("GetVoidApprovedPayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidApprovedPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1353;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetVoidGenPayout(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidGenPayout_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
		
		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidGenPayout csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidGenPayout csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidGenPayout csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidGenPayout CURSOR FOR
		select cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_VOD_GEN_PAYOUT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product; */ 


	/* EXEC SQL OPEN c_cursor_GetVoidGenPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0014;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1368;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidGenPayout_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidGenPayout
              	INTO
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1395;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[3] = (unsigned long )4;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_party_type;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[4] = (unsigned long )18;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[5] = (unsigned long )6;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_currency;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[7] = (unsigned long )23;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[8] = (unsigned long )4;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_gl_id;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidGenPayout_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidGenPayout v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidGenPayout v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidGenPayout v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidGenPayout v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidGenPayout v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidGenPayout v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidGenPayout v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidGenPayout v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidGenPayout v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidGenPayout v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidGenPayout v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidGenPayout v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidGenPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1458;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidGenPayout_error;
}



DEBUGLOG(("GetVoidGenPayout Normal Exit\n")); 
	return  PD_OK;

GetVoidGenPayout_error:
DEBUGLOG(("GetVoidGenPayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidGenPayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1473;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetApprovedMst(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetApprovedMst_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetApprovedMst csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetApprovedMst csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetApprovedMst csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetApprovedMst CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_SETTLE_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_GetApprovedMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1488;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetApprovedMst_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetApprovedMst
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1515;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetApprovedMst_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetApprovedMst v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedMst v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedMst v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedMst v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedMst v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedMst v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedMst v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedMst v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedMst v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedMst v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedMst v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedMst v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedMst v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetApprovedMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1582;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetApprovedMst_error;
}



DEBUGLOG(("GetApprovedMst Normal Exit\n")); 
	return  PD_OK;

GetApprovedMst_error:
DEBUGLOG(("GetApprovedMst_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetApprovedMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1597;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetDeliveredMst(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetDeliveredMst_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetDeliveredMst csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetDeliveredMst csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetDeliveredMst csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetDeliveredMst CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_DEL_SETTLE_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_GetDeliveredMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1612;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetDeliveredMst_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetDeliveredMst
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1639;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetDeliveredMst_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetDeliveredMst v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetDeliveredMst v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetDeliveredMst v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetDeliveredMst v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetDeliveredMst v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetDeliveredMst v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetDeliveredMst v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetDeliveredMst v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetDeliveredMst v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetDeliveredMst v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetDeliveredMst v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetDeliveredMst v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetDeliveredMst v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetDeliveredMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1706;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetDeliveredMst_error;
}



DEBUGLOG(("GetDeliveredMst Normal Exit\n")); 
	return  PD_OK;

GetDeliveredMst_error:
DEBUGLOG(("GetDeliveredMst_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetDeliveredMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1721;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetVoidMst(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidMst_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidMst csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidMst csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidMst csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidMst CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_VOID_SETTLE_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_GetVoidMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1736;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidMst_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidMst
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1763;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidMst_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetVoidMst v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidMst v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidMst v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidMst v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidMst v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidMst v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidMst v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidMst v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidMst v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidMst v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidMst v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidMst v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidMst v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1830;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidMst_error;
}



DEBUGLOG(("GetVoidMst Normal Exit\n")); 
	return  PD_OK;

GetVoidMst_error:
DEBUGLOG(("GetVoidMst_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidMst; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1845;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetApprovedMbt(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetApprovedMbt_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetApprovedMbt csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetApprovedMbt csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetApprovedMbt csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetApprovedMbt CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_MBT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetApprovedMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0018;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1860;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetApprovedMbt_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetApprovedMbt
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1887;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetApprovedMbt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetApprovedMbt v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedMbt v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedMbt v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedMbt v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedMbt v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedMbt v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedMbt v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedMbt v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedMbt v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedMbt v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedMbt v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedMbt v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedMbt v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetApprovedMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1954;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetApprovedMbt_error;
}



DEBUGLOG(("GetApprovedMbt Normal Exit\n")); 
	return  PD_OK;

GetApprovedMbt_error:
DEBUGLOG(("GetApprovedMbt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetApprovedMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1969;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetVoidMbt(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidMbt_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidMbt csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidMbt csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidMbt csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidMbt CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_VOID_MBT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetVoidMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1984;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidMbt_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidMbt
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2011;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidMbt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetApprovedMbt v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedMbt v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedMbt v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedMbt v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedMbt v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedMbt v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedMbt v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedMbt v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedMbt v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedMbt v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedMbt v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedMbt v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedMbt v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2078;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidMbt_error;
}



DEBUGLOG(("GetVoidMbt Normal Exit\n")); 
	return  PD_OK;

GetVoidMbt_error:
DEBUGLOG(("GetVoidMbt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidMbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2093;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetMbt2Off(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetMbt2Off_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetMbt2Off csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetMbt2Off csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetMbt2Off csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetMbt2Off CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_MBT_2_OFF_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2108;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetMbt2Off_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetMbt2Off
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2135;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetMbt2Off_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetMbt2Off v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetMbt2Off v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetMbt2Off v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetMbt2Off v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetMbt2Off v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetMbt2Off v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetMbt2Off v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetMbt2Off v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetMbt2Off v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetMbt2Off v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetMbt2Off v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetMbt2Off v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetMbt2Off v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2202;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetMbt2Off_error;
}



DEBUGLOG(("GetMbt2Off Normal Exit\n")); 
	return  PD_OK;

GetMbt2Off_error:
DEBUGLOG(("GetMbt2Off_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2217;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetVoidMbt2Off(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetVoidMbt2Off_error; */ 

    	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int	v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetVoidMbt2Off csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetVoidMbt2Off csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetVoidMbt2Off csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetVoidMbt2Off CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_VOID_MBT_2_OFF_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetVoidMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2232;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetVoidMbt2Off_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetVoidMbt2Off
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2259;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetVoidMbt2Off_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetVoidMbt2Off v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetVoidMbt2Off v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetVoidMbt2Off v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetVoidMbt2Off v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetVoidMbt2Off v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetVoidMbt2Off v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetVoidMbt2Off v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetVoidMbt2Off v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetVoidMbt2Off v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetVoidMbt2Off v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetVoidMbt2Off v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetVoidMbt2Off v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetVoidMbt2Off v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetVoidMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2326;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetVoidMbt2Off_error;
}



DEBUGLOG(("GetVoidMbt2Off Normal Exit\n")); 
	return  PD_OK;

GetVoidMbt2Off_error:
DEBUGLOG(("GetVoidMbt2Off_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetVoidMbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2341;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetApprovedPbt(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetApprovedPbt_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetApprovedPbt csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetApprovedPbt csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetApprovedPbt csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetApprovedPbt CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_PBT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetApprovedPbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0022;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2356;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetApprovedPbt_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetApprovedPbt
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2383;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetApprovedPbt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetApprovedPbt v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetApprovedPbt v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetApprovedPbt v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetApprovedPbt v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetApprovedPbt v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetApprovedPbt v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetApprovedPbt v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetApprovedPbt v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetApprovedPbt v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetApprovedPbt v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetApprovedPbt v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetApprovedPbt v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetApprovedPbt v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetApprovedPbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2450;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetApprovedPbt_error;
}



DEBUGLOG(("GetApprovedPbt Normal Exit\n")); 
	return  PD_OK;

GetApprovedPbt_error:
DEBUGLOG(("GetApprovedPbt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetApprovedPbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2465;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetPbt2Off(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetPbt2Off_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetPbt2Off csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetPbt2Off csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetPbt2Off csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetPbt2Off CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_PBT_2_OFF_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetPbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2480;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetPbt2Off_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetPbt2Off
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2507;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetPbt2Off_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetPbt2Off v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetPbt2Off v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetPbt2Off v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetPbt2Off v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetPbt2Off v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetPbt2Off v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetPbt2Off v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetPbt2Off v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetPbt2Off v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetPbt2Off v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetPbt2Off v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetPbt2Off v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetPbt2Off v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetPbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2574;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetPbt2Off_error;
}



DEBUGLOG(("GetPbt2Off Normal Exit\n")); 
	return  PD_OK;

GetPbt2Off_error:
DEBUGLOG(("GetPbt2Off_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetPbt2Off; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2589;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetOff2Mbt(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetOff2Mbt_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetOff2Mbt csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetOff2Mbt csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetOff2Mbt csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetOff2Mbt CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_OFF_2_MBT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetOff2Mbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0024;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2604;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetOff2Mbt_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetOff2Mbt
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2631;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetOff2Mbt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetOff2Mbt v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetOff2Mbt v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetOff2Mbt v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetOff2Mbt v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetOff2Mbt v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetOff2Mbt v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetOff2Mbt v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetOff2Mbt v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetOff2Mbt v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetOff2Mbt v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetOff2Mbt v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetOff2Mbt v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetOff2Mbt v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetOff2Mbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2698;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetOff2Mbt_error;
}



DEBUGLOG(("GetOff2Mbt Normal Exit\n")); 
	return  PD_OK;

GetOff2Mbt_error:
DEBUGLOG(("GetOff2Mbt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetOff2Mbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2713;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetOff2Pbt(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetOff2Pbt_error; */ 

    /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
		
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;

		short	ind_th_txn_id = -1;

		/* varchar	v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short	ind_cr_txn_date = -1;
		
		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		short	ind_country = -1;
		
		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		short	ind_product = -1;
		
		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		short	ind_party_type = -1;
		
		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		short	ind_party_id = -1;	
		
		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		short	ind_jnl_entry_type_id = -1;	
		
		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	/* EXEC SQL END DECLARE SECTION; */ 


	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetOff2Pbt csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetOff2Pbt csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetOff2Pbt csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetOff2Pbt CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_APL_OFF_2_PBT_VIEW
		where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by th_txn_id; */ 

		
	/* EXEC SQL OPEN c_cursor_GetOff2Pbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0025;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2728;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_product;
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
 if (sqlca.sqlcode < 0) goto GetOff2Pbt_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetOff2Pbt
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2755;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )19;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_cr_txn_date;
         sqlstm.sqhstl[1] = (unsigned long )11;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_cr_txn_date;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[2] = (unsigned long )5;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_country;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[3] = (unsigned long )6;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_product;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[4] = (unsigned long )4;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_party_type;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[5] = (unsigned long )18;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_id;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[6] = (unsigned long )6;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_currency;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[8] = (unsigned long )23;
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_gl_id;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetOff2Pbt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetOff2Pbt v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetOff2Pbt v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetOff2Pbt v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetOff2Pbt v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetOff2Pbt v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetOff2Pbt v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetOff2Pbt v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetOff2Pbt v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetOff2Pbt v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetOff2Pbt v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetOff2Pbt v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetOff2Pbt v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetOff2Pbt v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetOff2Pbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2822;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetOff2Pbt_error;
}



DEBUGLOG(("GetOff2Pbt Normal Exit\n")); 
	return  PD_OK;

GetOff2Pbt_error:
DEBUGLOG(("GetOff2Pbt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetOff2Pbt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2837;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

/*int GetPsp2Mb(recordset_t* myRec, const char* csTxnDate, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	EXEC SQL WHENEVER SQLERROR GOTO GetPsp2Mb_error;
    EXEC SQL WHENEVER NOTFOUND CONTINUE;		
	
	EXEC SQL BEGIN DECLARE SECTION;	
		varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1];
		short	ind_th_txn_id = -1;

		varchar	v_cr_txn_date[PD_DATE_LEN + 1];
		short	ind_cr_txn_date = -1;
		
		varchar	v_country[PD_COUNTRY_CODE_LEN + 1];
		short	ind_country = -1;
		
		varchar	v_product[PD_PRODUCT_CODE_LEN + 1];
		short	ind_product = -1;
		
		varchar	v_party_type[PD_PARTY_TYPE_LEN + 1];
		short	ind_party_type = -1;
		
		varchar	v_party_id[PD_PARTY_ID_LEN + 1];
		short	ind_party_id = -1;	
		
		varchar	v_currency[PD_CURRENCY_ID_LEN + 1];
		short	ind_currency = -1;	
		
		int		v_jnl_type_id;
		short	ind_jnl_type_id = -1;	
		
		varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1];
		short	ind_jnl_entry_type_id = -1;	
		
		varchar	v_cr_ind[PD_CR_IND_LEN + 1];
		short	ind_cr_ind = -1;	
		
		int		v_gl_id;
		short	ind_gl_id = -1;
		
		int		v_txn_cnt;
		short	ind_txn_cnt = -1;	
		
		double	v_txn_amt;
		short	ind_txn_amt = -1;			
	EXEC SQL END DECLARE SECTION;

	v_cr_txn_date.len = strlen(csTxnDate);
	memcpy(v_cr_txn_date.arr,csTxnDate,v_cr_txn_date.len);
	ind_cr_txn_date = 0;

	v_country.len = strlen(csCountry);
	memcpy(v_country.arr,csCountry,v_country.len);
	ind_country = 0;
	
	v_product.len = strlen(csProduct);
	memcpy(v_product.arr,csProduct,v_product.len);
	ind_product = 0;	

DEBUGLOG(("GetPsp2Mb csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetPsp2Mb csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetPsp2Mb csProduct = [%s]\n",csProduct));
	
	EXEC SQL DECLARE c_cursor_GetPsp2Mb CURSOR FOR
		select th_txn_id, cr_txn_date, cr_country, cr_product, te_party_type, party_id, cr_currency, cr_jnl_type_id,
		cr_jnl_entry_type_id, cr_ind, cr_gl_id, txn_count, cr_amount
		from CRR_PSP_2_MB_VIEW
		where TH_APPROVAL_DATE = :v_cr_txn_date:ind_cr_txn_date and cr_country = :v_country:ind_country and cr_product = :v_product:ind_product
		order by cr_txn_date;//
		
	EXEC SQL OPEN c_cursor_GetPsp2Mb;
        do {    
        	EXEC SQL FETCH c_cursor_GetPsp2Mb
              	INTO			
			:v_th_txn_id:ind_th_txn_id,
			:v_cr_txn_date:ind_cr_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_cr_ind:ind_cr_ind,
			:v_gl_id:ind_gl_id,
			:v_txn_cnt:ind_txn_cnt,
			:v_txn_amt:ind_txn_amt;

			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				//PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetPsp2Mb v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}
			if (ind_cr_txn_date >= 0) {
				v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("GetPsp2Mb v_cr_txn_date = [%s]\n",v_cr_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetPsp2Mb v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetPsp2Mb v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetPsp2Mb v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetPsp2Mb v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetPsp2Mb v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetPsp2Mb v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetPsp2Mb v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetPsp2Mb v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetPsp2Mb v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetPsp2Mb v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetPsp2Mb v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	EXEC SQL CLOSE c_cursor_GetPsp2Mb;

DEBUGLOG(("GetPsp2Mb Normal Exit\n")); 
	return  PD_OK;

GetPsp2Mb_error:
DEBUGLOG(("GetPsp2Mb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_GetPsp2Mb;
	return PD_ERR;
}*/

int GetJnlDataPkg(recordset_t* myRec, const char* csTxnDate, int iJnlTypeId, int iGroupId, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetJnlDataPkg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_txn_date;

		int	hv_jnl_type_id;
		int	hv_group_id;
		/* varchar	hv_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_country;

		/* varchar	hv_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_product;


		/* varchar	v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		int	v_jnl_type_id;
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		int	v_gl_id;
		int	v_txn_cnt;
		double	v_txn_amt;
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;


		short	ind_txn_date = -1;
		short	ind_country = -1;
		short	ind_product = -1;
		short	ind_party_type = -1;
		short	ind_party_id = -1;
		short	ind_currency = -1;
		short	ind_jnl_type_id = -1;
		short	ind_jnl_entry_type_id = -1;
		short	ind_cr_ind = -1;
		short	ind_gl_id = -1;
		short	ind_txn_cnt = -1;
		short	ind_txn_amt = -1;
		short	ind_th_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen(csTxnDate);
	memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);

	hv_jnl_type_id = iJnlTypeId;

	hv_group_id = iGroupId;

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
	
	hv_product.len = strlen(csProduct);
	memcpy(hv_product.arr,csProduct,hv_product.len);

DEBUGLOG(("GetJnlDataPkg csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetJnlDataPkg iJnlTypeId= [%d]\n",iJnlTypeId));
DEBUGLOG(("GetJnlDataPkg csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetJnlDataPkg csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetJnlDataPkg CURSOR FOR
		SELECT	TXN_DATE,
			CR_COUNTRY_ID,
			CR_PRODUCT_CODE,
			CR_JNL_TYPE_ID,
			CR_JNL_ENTRY_TYPE_ID,
			CR_PARTY_TYPE,
			CR_PARTY_ID,
			CR_CURRENCY_ID,
			GL_ID,
			CR_IND,
			TXN_AMT,
			TXN_COUNT,
			TXN_ID
		FROM	TABLE(CRR_JNL_DATA_PKG.GET_JNL(:hv_jnl_type_id, :hv_group_id, :hv_txn_date, :hv_txn_date))
		WHERE CR_COUNTRY_ID = :hv_country AND CR_PRODUCT_CODE = :hv_product
		ORDER BY TXN_ID; */ 


	/* EXEC SQL OPEN c_cursor_GetJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0026;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2852;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_jnl_type_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_group_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[2] = (unsigned long )11;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[3] = (unsigned long )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_product;
 sqlstm.sqhstl[5] = (unsigned long )6;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetJnlDataPkg_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetJnlDataPkg
              	INTO
			:v_txn_date:ind_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_gl_id:ind_gl_id,
			:v_cr_ind:ind_cr_ind,
			:v_txn_amt:ind_txn_amt,
			:v_txn_cnt:ind_txn_cnt,
			:v_th_txn_id:ind_th_txn_id; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2891;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[4] = (unsigned long )23;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[5] = (unsigned long )4;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_type;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[6] = (unsigned long )18;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_party_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[7] = (unsigned long )6;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_currency;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_gl_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[12] = (unsigned long )19;
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetJnlDataPkg_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetJnlDataPkg v_txn_date = [%s]\n",v_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetJnlDataPkg v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetJnlDataPkg v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetJnlDataPkg v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetJnlDataPkg v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetJnlDataPkg v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetJnlDataPkg v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetJnlDataPkg v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetJnlDataPkg v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetJnlDataPkg v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetJnlDataPkg v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetJnlDataPkg v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetApprovedMst v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}

			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2958;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetJnlDataPkg_error;
}



DEBUGLOG(("GetJnlDataPkg Normal Exit\n")); 
	return  PD_OK;

GetJnlDataPkg_error:
DEBUGLOG(("GetJnlDataPkg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2973;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetOfflineJnlDataPkg(recordset_t* myRec, const char* csTxnDate, int iJnlTypeId, int iGroupId, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetOflJnlDataPkg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_txn_date;

		int	hv_jnl_type_id;
		int	hv_group_id;
		/* varchar	hv_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_country;

		/* varchar	hv_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_product;


		/* varchar	v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		int	v_jnl_type_id;
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		int	v_gl_id;
		int	v_txn_cnt;
		double	v_txn_amt;
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;


		short	ind_txn_date = -1;
		short	ind_country = -1;
		short	ind_product = -1;
		short	ind_party_type = -1;
		short	ind_party_id = -1;
		short	ind_currency = -1;
		short	ind_jnl_type_id = -1;
		short	ind_jnl_entry_type_id = -1;
		short	ind_cr_ind = -1;
		short	ind_gl_id = -1;
		short	ind_txn_cnt = -1;
		short	ind_txn_amt = -1;
		short	ind_th_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen(csTxnDate);
	memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);

	hv_jnl_type_id = iJnlTypeId;

	hv_group_id = iGroupId;

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
	
	hv_product.len = strlen(csProduct);
	memcpy(hv_product.arr,csProduct,hv_product.len);

DEBUGLOG(("GetOflJnlDataPkg csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetOflJnlDataPkg iJnlTypeId= [%d]\n",iJnlTypeId));
DEBUGLOG(("GetOflJnlDataPkg csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetOflJnlDataPkg csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetOflJnlDataPkg CURSOR FOR
		SELECT	TXN_DATE,
			CR_COUNTRY_ID,
			CR_PRODUCT_CODE,
			CR_JNL_TYPE_ID,
			CR_JNL_ENTRY_TYPE_ID,
			CR_PARTY_TYPE,
			CR_PARTY_ID,
			CR_CURRENCY_ID,
			GL_ID,
			CR_IND,
			TXN_AMT,
			TXN_COUNT,
			TXN_ID
		FROM	TABLE(CRR_JNL_DATA_PKG.GET_OFL_JNL(:hv_jnl_type_id, :hv_group_id, :hv_txn_date, :hv_txn_date))
		WHERE CR_COUNTRY_ID = :hv_country AND CR_PRODUCT_CODE = :hv_product
		ORDER BY TXN_ID; */ 


	/* EXEC SQL OPEN c_cursor_GetOflJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0027;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2988;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_jnl_type_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_group_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[2] = (unsigned long )11;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[3] = (unsigned long )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_product;
 sqlstm.sqhstl[5] = (unsigned long )6;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetOflJnlDataPkg_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetOflJnlDataPkg
              	INTO
			:v_txn_date:ind_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_gl_id:ind_gl_id,
			:v_cr_ind:ind_cr_ind,
			:v_txn_amt:ind_txn_amt,
			:v_txn_cnt:ind_txn_cnt,
			:v_th_txn_id:ind_th_txn_id; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )3027;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[4] = (unsigned long )23;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[5] = (unsigned long )4;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_type;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[6] = (unsigned long )18;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_party_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[7] = (unsigned long )6;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_currency;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_gl_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[12] = (unsigned long )19;
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetOflJnlDataPkg_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetOflJnlDataPkg v_txn_date = [%s]\n",v_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetOflJnlDataPkg v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetOflJnlDataPkg v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetOflJnlDataPkg v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetOflJnlDataPkg v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetOflJnlDataPkg v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetOflJnlDataPkg v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetOflJnlDataPkg v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetOflJnlDataPkg v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetOflJnlDataPkg v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetOflJnlDataPkg v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetOflJnlDataPkg v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetOflJnlDataPkg v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}

			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetOflJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3094;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetOflJnlDataPkg_error;
}



DEBUGLOG(("GetOflJnlDataPkg Normal Exit\n")); 
	return  PD_OK;

GetOflJnlDataPkg_error:
DEBUGLOG(("GetOflJnlDataPkg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetOflJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3109;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetMiJnlDataPkg(recordset_t* myRec, const char* csTxnDate, int iJnlTypeId, int iGroupId, const char* csCountry, const char* csProduct)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO GetMiJnlDataPkg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_txn_date;

		int	hv_jnl_type_id;
		int	hv_group_id;
		/* varchar	hv_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_country;

		/* varchar	hv_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_product;


		/* varchar	v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar	v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		/* varchar	v_party_type[PD_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

		/* varchar	v_party_id[PD_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		/* varchar	v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		int	v_jnl_type_id;
		/* varchar	v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

		/* varchar	v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

		int	v_gl_id;
		int	v_txn_cnt;
		double	v_txn_amt;
		/* varchar	v_th_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_th_txn_id;


		short	ind_txn_date = -1;
		short	ind_country = -1;
		short	ind_product = -1;
		short	ind_party_type = -1;
		short	ind_party_id = -1;
		short	ind_currency = -1;
		short	ind_jnl_type_id = -1;
		short	ind_jnl_entry_type_id = -1;
		short	ind_cr_ind = -1;
		short	ind_gl_id = -1;
		short	ind_txn_cnt = -1;
		short	ind_txn_amt = -1;
		short	ind_th_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen(csTxnDate);
	memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);

	hv_jnl_type_id = iJnlTypeId;

	hv_group_id = iGroupId;

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
	
	hv_product.len = strlen(csProduct);
	memcpy(hv_product.arr,csProduct,hv_product.len);

DEBUGLOG(("GetMiJnlDataPkg csTxnDate = [%s]\n",csTxnDate));
DEBUGLOG(("GetMiJnlDataPkg iJnlTypeId= [%d]\n",iJnlTypeId));
DEBUGLOG(("GetMiJnlDataPkg csCountry = [%s]\n",csCountry));
DEBUGLOG(("GetMiJnlDataPkg csProduct = [%s]\n",csProduct));
	
	/* EXEC SQL DECLARE c_cursor_GetMiJnlDataPkg CURSOR FOR
		SELECT	TXN_DATE,
			CR_COUNTRY_ID,
			CR_PRODUCT_CODE,
			CR_JNL_TYPE_ID,
			CR_JNL_ENTRY_TYPE_ID,
			CR_PARTY_TYPE,
			CR_PARTY_ID,
			CR_CURRENCY_ID,
			GL_ID,
			CR_IND,
			TXN_AMT,
			TXN_COUNT,
			TXN_ID
		FROM	TABLE(CRR_JNL_DATA_PKG.GET_MI_JNL(:hv_jnl_type_id, :hv_group_id, :hv_txn_date, :hv_txn_date))
		WHERE CR_COUNTRY_ID = :hv_country AND CR_PRODUCT_CODE = :hv_product
		ORDER BY TXN_ID; */ 


	/* EXEC SQL OPEN c_cursor_GetMiJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0028;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3124;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_jnl_type_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_group_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[2] = (unsigned long )11;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[3] = (unsigned long )11;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_product;
 sqlstm.sqhstl[5] = (unsigned long )6;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto GetMiJnlDataPkg_error;
}


        do {    
        	/* EXEC SQL FETCH c_cursor_GetMiJnlDataPkg
              	INTO
			:v_txn_date:ind_txn_date,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_jnl_type_id:ind_jnl_type_id,
			:v_jnl_entry_type_id:ind_jnl_entry_type_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_currency:ind_currency,
			:v_gl_id:ind_gl_id,
			:v_cr_ind:ind_cr_ind,
			:v_txn_amt:ind_txn_amt,
			:v_txn_cnt:ind_txn_cnt,
			:v_th_txn_id:ind_th_txn_id; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 15;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )3163;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqfoff = (         int )0;
         sqlstm.sqfmod = (unsigned int )2;
         sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_date;
         sqlstm.sqhstl[0] = (unsigned long )11;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)&ind_txn_date;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
         sqlstm.sqhstl[1] = (unsigned long )5;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_country;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
         sqlstm.sqhstl[2] = (unsigned long )6;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_product;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&v_jnl_type_id;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_jnl_type_id;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&v_jnl_entry_type_id;
         sqlstm.sqhstl[4] = (unsigned long )23;
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_jnl_entry_type_id;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&v_party_type;
         sqlstm.sqhstl[5] = (unsigned long )4;
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_party_type;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&v_party_id;
         sqlstm.sqhstl[6] = (unsigned long )18;
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_party_id;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&v_currency;
         sqlstm.sqhstl[7] = (unsigned long )6;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_currency;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&v_gl_id;
         sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[8] = (         int  )0;
         sqlstm.sqindv[8] = (         short *)&ind_gl_id;
         sqlstm.sqinds[8] = (         int  )0;
         sqlstm.sqharm[8] = (unsigned long )0;
         sqlstm.sqadto[8] = (unsigned short )0;
         sqlstm.sqtdso[8] = (unsigned short )0;
         sqlstm.sqhstv[9] = (unsigned char  *)&v_cr_ind;
         sqlstm.sqhstl[9] = (unsigned long )4;
         sqlstm.sqhsts[9] = (         int  )0;
         sqlstm.sqindv[9] = (         short *)&ind_cr_ind;
         sqlstm.sqinds[9] = (         int  )0;
         sqlstm.sqharm[9] = (unsigned long )0;
         sqlstm.sqadto[9] = (unsigned short )0;
         sqlstm.sqtdso[9] = (unsigned short )0;
         sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_amt;
         sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[10] = (         int  )0;
         sqlstm.sqindv[10] = (         short *)&ind_txn_amt;
         sqlstm.sqinds[10] = (         int  )0;
         sqlstm.sqharm[10] = (unsigned long )0;
         sqlstm.sqadto[10] = (unsigned short )0;
         sqlstm.sqtdso[10] = (unsigned short )0;
         sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_cnt;
         sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[11] = (         int  )0;
         sqlstm.sqindv[11] = (         short *)&ind_txn_cnt;
         sqlstm.sqinds[11] = (         int  )0;
         sqlstm.sqharm[11] = (unsigned long )0;
         sqlstm.sqadto[11] = (unsigned short )0;
         sqlstm.sqtdso[11] = (unsigned short )0;
         sqlstm.sqhstv[12] = (unsigned char  *)&v_th_txn_id;
         sqlstm.sqhstl[12] = (unsigned long )19;
         sqlstm.sqhsts[12] = (         int  )0;
         sqlstm.sqindv[12] = (         short *)&ind_th_txn_id;
         sqlstm.sqinds[12] = (         int  )0;
         sqlstm.sqharm[12] = (unsigned long )0;
         sqlstm.sqadto[12] = (unsigned short )0;
         sqlstm.sqtdso[12] = (unsigned short )0;
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
         if (sqlca.sqlcode < 0) goto GetMiJnlDataPkg_error;
}



			if (SQLCODE == SQL_NOT_FOUND) { 
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] ='\0';
				PutField_CString(myHash,"v_cr_txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetMiJnlDataPkg v_txn_date = [%s]\n",v_txn_date.arr)); 
			}
			if (ind_country >= 0) {
				v_country.arr[v_country.len] ='\0';
				PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("GetMiJnlDataPkg v_country = [%s]\n",v_country.arr)); 
			}
			if (ind_product >= 0) {
				v_product.arr[v_product.len] ='\0';
				PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("GetMiJnlDataPkg v_product = [%s]\n",v_product.arr)); 
			}
			if (ind_jnl_type_id >= 0) {
				PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("GetMiJnlDataPkg v_jnl_type_id = [%d]\n",v_jnl_type_id)); 
			}
			if (ind_jnl_entry_type_id >= 0) {
				v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
				PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("GetMiJnlDataPkg v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr)); 
			}	
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] ='\0';
				PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetMiJnlDataPkg v_party_type = [%s]\n",v_party_type.arr)); 
			}
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] ='\0';
				PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetMiJnlDataPkg v_party_id = [%s]\n",v_party_id.arr)); 
			}		
			if (ind_currency >= 0) {
				v_currency.arr[v_currency.len] ='\0';
				PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("GetMiJnlDataPkg v_currency = [%s]\n",v_currency.arr)); 
			}
			if (ind_gl_id >= 0) {
				PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("GetMiJnlDataPkg v_gl_id = [%d]\n",v_gl_id)); 
			}
			if (ind_cr_ind >= 0) {
				v_cr_ind.arr[v_cr_ind.len] ='\0';
				PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("GetMiJnlDataPkg v_cr_ind = [%s]\n",v_cr_ind.arr)); 
			}
			if (ind_txn_amt >= 0) {
				PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("GetMiJnlDataPkg v_txn_amt = [%f]\n",v_txn_amt)); 
			}			
			if (ind_txn_cnt >= 0) {
				PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("GetMiJnlDataPkg v_txn_cnt = [%d]\n",v_txn_cnt)); 
			}
			if (ind_th_txn_id >= 0) {
				v_th_txn_id.arr[v_th_txn_id.len] ='\0';
				PutField_CString(myHash,"v_th_txn_id",(const char*)v_th_txn_id.arr);
				PutField_CString(myHash,"v_str_cmp",(const char*)v_th_txn_id.arr);
DEBUGLOG(("GetMiJnlDataPkg v_th_txn_id = [%s]\n",v_th_txn_id.arr)); 
			}

			RecordSet_Add(myRec,myHash);
		}
		while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_GetMiJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3230;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto GetMiJnlDataPkg_error;
}



DEBUGLOG(("GetMiJnlDataPkg Normal Exit\n")); 
	return  PD_OK;

GetMiJnlDataPkg_error:
DEBUGLOG(("GetMiJnlDataPkg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_GetMiJnlDataPkg; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3245;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

