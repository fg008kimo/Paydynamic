
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
           char  filnam[30];
};
static struct sqlcxp sqlfpn =
{
    29,
    "OLMerchantUploadFileDetail.pc"
};


static unsigned int sqlctx = 1515639253;


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
   unsigned char  *sqhstv[39];
   unsigned long  sqhstl[39];
            int   sqhsts[39];
            short *sqindv[39];
            int   sqinds[39];
   unsigned long  sqharm[39];
   unsigned long  *sqharc[39];
   unsigned short  sqadto[39];
   unsigned short  sqtdso[39];
} sqlstm = {12,39};

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

 static char *sq0002 = 
"select oud_seq_num , oud_txn_id , oud_aux_txn_id , oud_merchant_ref , oud_c\
ountry , oud_identity_id , oud_account_num , oud_account_name , oud_bank_name\
 , oud_bank_code , oud_branch , oud_phone_num , oud_province , oud_city , oud\
_payout_amount , oud_request_amount , oud_payout_currency , oud_request_curre\
ncy , oud_member_fee_ccy , oud_member_fee , oud_merchant_fee_ccy , oud_mercha\
nt_fee , oud_markup_ccy , oud_markup_amt , oud_exchange_rate , oud_status , o\
ud_response_code , oud_remark , oud_batch_mode , oud_generated_file_name , ou\
d_psp_batch_id , oud_fundout_date , oud_service_fee , oud_psp_id , oud_genera\
ted_file_id , oud_approve_id from ol_merchant_upload_file_detail where oud_ba\
tch_id = :b0 and oud_disabled = :b1 order by oud_seq_num            ";

 static char *sq0003 = 
"select oud_batch_id , oud_seq_num , oud_aux_txn_id , oud_merchant_ref , oud\
_country , oud_identity_id , oud_account_num , oud_account_name , oud_bank_na\
me , oud_bank_code , oud_branch , oud_phone_num , oud_province , oud_city , o\
ud_payout_amount , oud_request_amount , oud_payout_currency , oud_request_cur\
rency , oud_member_fee_ccy , oud_member_fee , oud_merchant_fee_ccy , oud_merc\
hant_fee , oud_markup_ccy , oud_markup_amt , oud_exchange_rate , oud_status ,\
 oud_response_code , oud_remark , oud_batch_mode , oud_generated_file_name , \
oud_psp_batch_id , oud_fundout_date , oud_service_fee , oud_psp_id , oud_gene\
rated_file_id , oud_approve_id from ol_merchant_upload_file_detail where oud_\
txn_id = :b0 and oud_disabled = :b1 order by oud_seq_num            ";

 static char *sq0005 = 
"SELECT UNIQUE oud_psp_id FROM ol_merchant_upload_file_detail , ol_merchant_\
upload_file_header WHERE oud_status = :b0 and oud_disabled = :b1 and oud_batc\
h_id = ouh_batch_id and ouh_merchant_id = :b2 and oud_batch_mode = :b3 and ou\
d_psp_id IS NOT NULL            ";

 static char *sq0006 = 
"SELECT UNIQUE oud_psp_id FROM ol_merchant_upload_file_detail WHERE oud_stat\
us = :b0 and oud_disabled = :b1 and oud_batch_mode = :b2 and oud_psp_id IS NO\
T NULL            ";

 static char *sq0007 = 
"SELECT UNIQUE oud_pregen_psp_id , oud_pregen_bank_code FROM ol_merchant_upl\
oad_file_detail , ol_merchant_upload_file_header WHERE oud_status = :b0 and o\
ud_disabled = :b1 and oud_batch_id = ouh_batch_id and ouh_merchant_id = :b2 a\
nd oud_batch_mode = :b3 and oud_pregen_psp_id IS NOT NULL and oud_pregen_bank\
_code IS NOT NULL            ";

 static char *sq0008 = 
"SELECT UNIQUE oud_pregen_psp_id , oud_pregen_bank_code FROM ol_merchant_upl\
oad_file_detail WHERE oud_status = :b0 and oud_disabled = :b1 and oud_batch_m\
ode = :b2 and oud_pregen_psp_id IS NOT NULL and oud_pregen_bank_code IS NOT N\
ULL            ";

 static char *sq0009 = 
"SELECT UNIQUE oud_pregen_file_id FROM ol_merchant_upload_file_detail , ol_p\
ayout_generated_file_hd WHERE oud_status = :b0 and oud_disabled = :b1 and oud\
_batch_mode = :b2 and ofh_file_id = oud_pregen_file_id and ofh_status = :b3 a\
nd oud_pregen_file_id IS NOT NULL            ";

 static char *sq0010 = 
"SELECT oud_batch_id , oud_seq_num , oud_txn_id , oud_merchant_ref , oud_ide\
ntity_id , oud_account_name , oud_account_num , oud_bank_name , oud_branch , \
oud_phone_num , oud_province , oud_city , oud_payout_amount , oud_request_amo\
unt , oud_remark , oud_pregen_psp_id , oud_pregen_bank_code , oud_country , o\
ud_payout_currency , oud_request_currency , oud_merchant_fee_ccy , oud_mercha\
nt_fee , oud_member_fee_ccy , oud_member_fee , oud_markup_amt , oud_markup_cc\
y FROM ol_merchant_upload_file_detail , ol_merchant_upload_file_header WHERE \
oud_status = :b0 and oud_disabled = :b1 and oud_batch_id = ouh_batch_id and o\
uh_merchant_id = :b2 and oud_batch_mode = :b3 and oud_pregen_psp_id IS NOT NU\
LL order by oud_batch_id , oud_seq_num            ";

 static char *sq0011 = 
"SELECT oud_batch_id , oud_seq_num , oud_txn_id , oud_merchant_ref , oud_ide\
ntity_id , oud_account_name , oud_account_num , oud_bank_name , oud_branch , \
oud_phone_num , oud_province , oud_city , oud_request_amount , oud_payout_amo\
unt , oud_remark , oud_pregen_psp_id , oud_pregen_bank_code , oud_country , o\
ud_request_currency , oud_payout_currency FROM ol_merchant_upload_file_detail\
 WHERE oud_status = :b0 and oud_disabled = :b1 and oud_batch_mode = :b2 and o\
ud_pregen_psp_id IS NOT NULL order by oud_batch_id , oud_seq_num            ";

 static char *sq0012 = 
"select oud_txn_id , oud_batch_id , oud_seq_num , oud_aux_txn_id , oud_merch\
ant_ref , oud_country , oud_identity_id , oud_account_num , oud_account_name \
, oud_bank_name , oud_branch , oud_phone_num , oud_province , oud_city , oud_\
payout_amount , oud_request_amount , oud_payout_currency , oud_request_curren\
cy , oud_member_fee_ccy , oud_member_fee , oud_merchant_fee_ccy , oud_merchan\
t_fee , oud_markup_ccy , oud_markup_amt , oud_exchange_rate , oud_response_co\
de , oud_remark , oud_batch_mode , oud_generated_file_name , oud_psp_batch_id\
 , oud_fundout_date , oud_service_fee from ( SELECT * FROM ol_merchant_upload\
_file_detail ORDER BY dbms_random . value ) , ol_merchant_upload_file_header \
where oud_status = :b0 and oud_disabled = :b1 and oud_batch_mode = :b2 and ou\
d_batch_id = ouh_batch_id and oud_disabled = ouh_disabled and oud_pregen_psp_\
id IS NULL            ";

 static char *sq0019 = 
"select oud_seq_num , oud_txn_id , oud_merchant_ref , oud_country , oud_iden\
tity_id , oud_account_num , oud_account_name , oud_bank_name , oud_bank_code \
, oud_branch , oud_phone_num , oud_province , oud_city , oud_payout_amount , \
oud_request_amount , oud_payout_currency , oud_request_currency , oud_member_\
fee_ccy , oud_member_fee , oud_merchant_fee_ccy , oud_merchant_fee , oud_mark\
up_ccy , oud_markup_amt , oud_exchange_rate , oud_status , oud_response_code \
, oud_remark , oud_batch_mode , oud_generated_file_name , oud_psp_batch_id , \
oud_fundout_date , oud_service_fee , oud_psp_id , oud_generated_file_id from \
ol_merchant_upload_file_detail where oud_batch_id = :b0 and oud_disabled = :b\
1 and oud_aux_txn_id is NULL and oud_status not in ( :b2 , :b3 ) order by oud\
_seq_num            ";

 static char *sq0031 = 
"SELECT oud_batch_id , oud_seq_num , oud_txn_id , oud_merchant_ref , oud_ide\
ntity_id , oud_account_name , oud_account_num , oud_bank_name , oud_bank_code\
 , oud_branch , oud_phone_num , oud_province , oud_city , oud_request_amount \
, oud_payout_amount , oud_remark , opt_psp_id , oud_country , oud_request_cur\
rency , oud_payout_currency , opt_bank_code , ouh_merchant_id FROM ol_merchan\
t_upload_file_detail , ol_merchant_upload_file_header , ol_payout_generated_t\
mp WHERE oud_status = :b0 and oud_disabled = :b1 and oud_batch_mode = :b2 and\
 oud_txn_id = opt_txn_id and opt_id = :b3 and ouh_batch_id = oud_batch_id ord\
er by opt_psp_id , oud_batch_id , oud_seq_num for update ";

 static char *sq0032 = 
"SELECT unique oud_batch_id FROM ol_merchant_upload_file_detail , ol_merchan\
t_upload_file_header WHERE oud_status = :b0 and oud_disabled = :b1 and oud_ba\
tch_mode = :b2 and ouh_batch_id = oud_batch_id and ouh_merchant_id = :b3 and \
oud_psp_payout_grp = :b4            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,17,325,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,326,0,0,0,0,0,1,0,
39,0,0,1,0,0,17,553,0,0,1,1,0,1,0,1,9,0,0,
58,0,0,1,0,0,21,554,0,0,0,0,0,1,0,
73,0,0,2,759,0,9,710,0,2049,2,2,0,1,0,1,68,0,0,1,3,0,0,
96,0,0,2,0,0,13,712,0,0,36,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,
0,2,3,0,0,
255,0,0,2,0,0,15,1004,0,0,0,0,0,1,0,
270,0,0,2,0,0,15,1014,0,0,0,0,0,1,0,
285,0,0,3,759,0,9,1157,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
308,0,0,3,0,0,13,1159,0,0,36,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,
0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,
467,0,0,3,0,0,15,1453,0,0,0,0,0,1,0,
482,0,0,3,0,0,15,1463,0,0,0,0,0,1,0,
497,0,0,4,120,0,4,1490,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
524,0,0,5,261,0,9,1565,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
555,0,0,5,0,0,13,1567,0,0,1,0,0,1,0,2,9,0,0,
574,0,0,5,0,0,15,1591,0,0,0,0,0,1,0,
589,0,0,6,170,0,9,1603,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
616,0,0,6,0,0,13,1605,0,0,1,0,0,1,0,2,9,0,0,
635,0,0,6,0,0,15,1629,0,0,0,0,0,1,0,
650,0,0,6,0,0,15,1645,0,0,0,0,0,1,0,
665,0,0,5,0,0,15,1646,0,0,0,0,0,1,0,
680,0,0,7,335,0,9,1705,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
711,0,0,7,0,0,13,1707,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
734,0,0,7,0,0,15,1738,0,0,0,0,0,1,0,
749,0,0,8,244,0,9,1752,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
776,0,0,8,0,0,13,1754,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
799,0,0,8,0,0,15,1786,0,0,0,0,0,1,0,
814,0,0,8,0,0,15,1802,0,0,0,0,0,1,0,
829,0,0,7,0,0,15,1803,0,0,0,0,0,1,0,
844,0,0,9,274,0,9,1899,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,1,3,0,0,
875,0,0,9,0,0,13,1901,0,0,1,0,0,1,0,2,9,0,0,
894,0,0,9,0,0,15,1925,0,0,0,0,0,1,0,
909,0,0,9,0,0,15,1941,0,0,0,0,0,1,0,
924,0,0,10,741,0,9,2075,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
955,0,0,10,0,0,13,2077,0,0,26,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,
1074,0,0,10,0,0,15,2306,0,0,0,0,0,1,0,
1089,0,0,11,536,0,9,2339,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
1116,0,0,11,0,0,13,2341,0,0,20,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1211,0,0,11,0,0,15,2522,0,0,0,0,0,1,0,
1226,0,0,10,0,0,15,2538,0,0,0,0,0,1,0,
1241,0,0,11,0,0,15,2539,0,0,0,0,0,1,0,
1256,0,0,12,867,0,9,2676,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
1283,0,0,12,0,0,13,2678,0,0,32,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
1426,0,0,12,0,0,15,2948,0,0,0,0,0,1,0,
1441,0,0,12,0,0,15,2958,0,0,0,0,0,1,0,
1456,0,0,13,122,0,4,2992,0,0,3,2,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,
1483,0,0,14,122,0,4,2998,0,0,3,2,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,
1510,0,0,15,94,0,4,3004,0,0,2,1,0,1,0,2,3,0,0,1,68,0,0,
1533,0,0,1,0,0,17,3060,0,0,1,1,0,1,0,1,9,0,0,
1552,0,0,1,0,0,21,3061,0,0,0,0,0,1,0,
1567,0,0,1,0,0,17,3103,0,0,1,1,0,1,0,1,9,0,0,
1586,0,0,1,0,0,21,3104,0,0,0,0,0,1,0,
1601,0,0,1,0,0,17,3150,0,0,1,1,0,1,0,1,9,0,0,
1620,0,0,1,0,0,21,3151,0,0,0,0,0,1,0,
1635,0,0,0,0,0,56,3280,0,0,1,1,0,1,0,3,102,0,0,
1654,0,0,16,192,0,6,3283,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,3,0,0,
2,102,0,0,
1693,0,0,17,160,0,6,3295,0,0,5,5,0,1,0,2,3,0,0,1,1,0,0,1,3,0,0,1,3,0,0,2,102,0,
0,
1728,0,0,0,0,0,13,3351,0,0,36,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,9,0,0,
1887,0,0,0,0,0,15,3634,0,0,1,1,0,1,0,1,102,0,0,
1906,0,0,0,0,0,78,3635,0,0,1,1,0,1,0,3,102,0,0,
1925,0,0,0,0,0,15,3645,0,0,1,1,0,1,0,1,102,0,0,
1944,0,0,0,0,0,78,3646,0,0,1,1,0,1,0,3,102,0,0,
1963,0,0,18,1012,0,6,3985,0,0,31,31,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
2102,0,0,19,788,0,9,4190,0,2049,4,4,0,1,0,1,68,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
2133,0,0,19,0,0,13,4192,0,0,34,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,3,
0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
2284,0,0,19,0,0,15,4468,0,0,0,0,0,1,0,
2299,0,0,19,0,0,15,4478,0,0,0,0,0,1,0,
2314,0,0,0,0,0,56,4647,0,0,1,1,0,1,0,3,102,0,0,
2333,0,0,20,280,0,6,4649,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,3,0,0,
1,4,0,0,1,4,0,0,1,9,0,0,2,102,0,0,
2384,0,0,0,0,0,13,4713,0,0,39,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
2555,0,0,0,0,0,15,5016,0,0,1,1,0,1,0,1,102,0,0,
2574,0,0,0,0,0,78,5017,0,0,1,1,0,1,0,3,102,0,0,
2593,0,0,0,0,0,15,5027,0,0,1,1,0,1,0,1,102,0,0,
2612,0,0,0,0,0,78,5028,0,0,1,1,0,1,0,3,102,0,0,
2631,0,0,21,111,0,4,5047,0,0,1,0,0,1,0,2,3,0,0,
2650,0,0,22,117,0,4,5085,0,0,1,0,0,1,0,2,3,0,0,
2669,0,0,1,0,0,17,5138,0,0,1,1,0,1,0,1,9,0,0,
2688,0,0,1,0,0,21,5139,0,0,0,0,0,1,0,
2703,0,0,0,0,0,56,5264,0,0,1,1,0,1,0,3,102,0,0,
2722,0,0,23,157,0,6,5266,0,0,4,4,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,2,102,0,0,
2753,0,0,0,0,0,13,5325,0,0,39,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
2924,0,0,0,0,0,15,5628,0,0,1,1,0,1,0,1,102,0,0,
2943,0,0,0,0,0,78,5629,0,0,1,1,0,1,0,3,102,0,0,
2962,0,0,0,0,0,15,5639,0,0,1,1,0,1,0,1,102,0,0,
2981,0,0,0,0,0,78,5640,0,0,1,1,0,1,0,3,102,0,0,
3000,0,0,1,0,0,17,5682,0,0,1,1,0,1,0,1,9,0,0,
3019,0,0,1,0,0,21,5683,0,0,0,0,0,1,0,
3034,0,0,0,0,0,56,5871,0,0,1,1,0,1,0,3,102,0,0,
3053,0,0,24,324,0,6,5873,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,1,0,0,1,1,0,0,1,1,0,0,2,102,0,0,
3104,0,0,0,0,0,13,5930,0,0,35,1,0,1,0,1,102,0,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,1,0,0,
2,1,0,0,
3259,0,0,0,0,0,15,6214,0,0,1,1,0,1,0,1,102,0,0,
3278,0,0,0,0,0,78,6215,0,0,1,1,0,1,0,3,102,0,0,
3297,0,0,0,0,0,15,6225,0,0,1,1,0,1,0,1,102,0,0,
3316,0,0,0,0,0,78,6226,0,0,1,1,0,1,0,3,102,0,0,
3335,0,0,25,279,0,4,6260,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
3362,0,0,26,327,0,4,6337,0,0,5,4,0,1,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
3397,0,0,27,79,0,6,6387,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
3420,0,0,0,0,0,56,6480,0,0,1,1,0,1,0,3,102,0,0,
3439,0,0,28,155,0,6,6482,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,2,102,0,0,
3470,0,0,0,0,0,13,6511,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,
3533,0,0,0,0,0,15,6611,0,0,1,1,0,1,0,1,102,0,0,
3552,0,0,0,0,0,78,6612,0,0,1,1,0,1,0,3,102,0,0,
3571,0,0,0,0,0,15,6622,0,0,1,1,0,1,0,1,102,0,0,
3590,0,0,0,0,0,78,6623,0,0,1,1,0,1,0,3,102,0,0,
3609,0,0,29,122,0,4,6650,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
3636,0,0,0,0,0,56,6796,0,0,1,1,0,1,0,3,102,0,0,
3655,0,0,30,413,0,6,6798,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,
0,1,1,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,3,0,0,1,9,0,0,2,102,0,0,
3718,0,0,0,0,0,13,6825,0,0,3,1,0,1,0,1,102,0,0,2,9,0,0,2,4,0,0,
3745,0,0,0,0,0,15,6853,0,0,1,1,0,1,0,1,102,0,0,
3764,0,0,0,0,0,78,6854,0,0,1,1,0,1,0,3,102,0,0,
3783,0,0,0,0,0,15,6864,0,0,1,1,0,1,0,1,102,0,0,
3802,0,0,0,0,0,78,6865,0,0,1,1,0,1,0,3,102,0,0,
3821,0,0,31,671,0,9,6980,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,1,3,0,0,
3852,0,0,31,0,0,13,6982,0,0,22,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
3955,0,0,31,0,0,15,7177,0,0,0,0,0,1,0,
3970,0,0,31,0,0,15,7192,0,0,0,0,0,1,0,
3985,0,0,1,0,0,17,7228,0,0,1,1,0,1,0,1,9,0,0,
4004,0,0,1,0,0,21,7229,0,0,0,0,0,1,0,
4019,0,0,32,265,0,9,7292,0,2049,5,5,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,1,9,0,0,1,1,
0,0,
4054,0,0,32,0,0,13,7294,0,0,1,0,0,1,0,2,9,0,0,
4073,0,0,32,0,0,15,7317,0,0,0,0,0,1,0,
4088,0,0,32,0,0,15,7332,0,0,0,0,0,1,0,
4103,0,0,0,0,0,56,7391,0,0,1,1,0,1,0,3,102,0,0,
4122,0,0,33,155,0,6,7393,0,0,4,4,0,1,0,2,3,0,0,1,68,0,0,1,1,0,0,2,102,0,0,
4153,0,0,0,0,0,13,7422,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,
4216,0,0,0,0,0,15,7522,0,0,1,1,0,1,0,1,102,0,0,
4235,0,0,0,0,0,78,7523,0,0,1,1,0,1,0,3,102,0,0,
4254,0,0,0,0,0,15,7533,0,0,1,1,0,1,0,1,102,0,0,
4273,0,0,0,0,0,78,7534,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/08              LokMan Chow
bug fix for payout group generate		   2015/06/05		   LokMan Chow
Add GetDetailForPayoutGrpByBatchId		   2016/04/28		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMerchantUploadFileDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLMerchantUploadFileDetail(char    cdebug)
{
        cDebug = cdebug;
}


int UpdateDetailByBatchId(const char* csBatchId, const int iSeqNum, const hash_t *hRls)
{
	char*   csBuf;
	char*	csRespCode;
	char*	csSeqNum;
	double	dTmp;
	char	cTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatedetailbybatch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateDetailByBatchId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
DEBUGLOG(("UpdateDetailByBatchId:batch_id = [%s]\n",csBatchId));

        csSeqNum = (char*) malloc (128);
	sprintf(csSeqNum,"%d",iSeqNum);
DEBUGLOG(("UpdateDetailByBatchId:seq_num = [%s]\n",csSeqNum));

        if(GetField_Double(hRls,"payout_amt",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: payout_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_payout_amount =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"member_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: member_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_member_fee =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"txn_country",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: txn_country = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_country = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"identity_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: identity_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_identity_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"bank_code",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: pregen_psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_pregen_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"member_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: member_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_member_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"merchant_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: merchant_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_fee =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"merchant_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: merchant_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"markup_amt",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: markup_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_markup_amt =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"markup_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: markup_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_markup_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"ex_rate",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: ex_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_exchange_rate =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRls,"batch_mode",&cTmp)){
DEBUGLOG(("UpdateDetailByBatchId: batch_mode = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_batch_mode = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_CString(hRls,"resp_code",&csRespCode)){
DEBUGLOG(("UpdateDetailByBatchId: resp_code = [%s]\n",csRespCode));
                strcat((char*)hv_dynstmt.arr, ",oud_response_code = '");
                strcat((char*)hv_dynstmt.arr, csRespCode);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"remark",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: remark = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_remark= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"aux_txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: aux_txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_aux_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_batch_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: psp_batch_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_psp_batch_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"fundout_date",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: fundout_date = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_fundout_date= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"service_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: service_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_service_fee=");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"generated_file_name",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: generated_file_name = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_generated_file_name= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_file_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: pregen_file_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_pregen_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"file_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: generated_file_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_generated_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_approve_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"pre_approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: pre_approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_preapprove_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRls,"merchant_group",&cTmp)){
DEBUGLOG(("UpdateDetailByBatchId: merchant_group = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_payout_grp = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRls,"psp_group",&cTmp)){
DEBUGLOG(("UpdateDetailByBatchId: psp_group = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_psp_payout_grp = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_bank_code",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: pregen_bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_pregen_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"update_user",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_update_user= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE oud_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        strcat((char*)hv_dynstmt.arr, " AND oud_seq_num = ");
        strcat((char*)hv_dynstmt.arr, csSeqNum);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 if (sqlca.sqlcode < 0) goto updatedetailbybatch_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatedetailbybatch_error;
}



	FREE_ME(csBuf);
	FREE_ME(csSeqNum);

DEBUGLOG(("UpdateDetailByBatchId Normal Exit\n"));
        return PD_OK;

updatedetailbybatch_error:
DEBUGLOG(("updatedetailbybatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_UpdateDetailByBatchId: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int UpdateDetailByTxnId(const char* csTxnId, const hash_t *hRls)
{
	char*   csBuf;
	char*	csRespCode;
	double	dTmp;
	int	iTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatedetailbytxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateDetailByTxnId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
DEBUGLOG(("UpdateDetailByTxnId:txn_id = [%s]\n",csTxnId));
        
        if(GetField_CString(hRls,"psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"aux_txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: aux_txn_seq = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_aux_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"member_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: member_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_member_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
	if (GetField_Double(hRls,"member_fee",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:member_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_member_fee = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"merchant_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: merchant_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"merchant_fee",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:merchant_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_fee = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"markup_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: markup_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_markup_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"markup_amt",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:markup_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_markup_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"ex_rate",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:ex_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_exchange_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"payout_txn_num",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: payout_txn_num = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_payout_txn_num= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateDetailByTxnId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_CString(hRls,"resp_code",&csRespCode)){
DEBUGLOG(("UpdateDetailByTxnId: resp_code = [%s]\n",csRespCode));
                strcat((char*)hv_dynstmt.arr, ",oud_response_code = '");
                strcat((char*)hv_dynstmt.arr, csRespCode);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"remark",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: remark = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_remark= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_batch_id",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: psp_batch_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_psp_batch_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"tid",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: tid = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_tid= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"fundout_date",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: fundout_date = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_fundout_date= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"service_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByTxnId: service_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_service_fee=");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByTxnId: approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_approve_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_Char(hRls,"merchant_group",&cTmp)){
DEBUGLOG(("UpdateDetailByTxnId: merchant_group = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_merchant_payout_grp = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRls,"psp_group",&cTmp)){
DEBUGLOG(("UpdateDetailByTxnId: psp_group = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oud_psp_payout_grp = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_bank_code",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: pregen_bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_pregen_bank_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"update_user",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oud_update_user= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE oud_txn_id = '");
        strcat((char*)hv_dynstmt.arr, csTxnId);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
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
 if (sqlca.sqlcode < 0) goto updatedetailbytxn_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )58;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatedetailbytxn_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateDetailByTxnId Normal Exit\n"));
        return PD_OK;

updatedetailbytxn_error:
DEBUGLOG(("updatedetailbytxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_UpdateDetailByTxnId: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int GetDetail(const unsigned long lBatchId, recordset_t* myRec)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getpayout_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_batch_id;
		int		hv_disabled;
		//varchar		hv_batch_id[PD_TXN_SEQ_LEN];

		int	        v_seq_num;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		int		v_status;
		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;
		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int		v_approve_id;


		short           ind_seq_num = -1;
		short           ind_txn_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short		ind_status = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_file_id = -1;
		short           ind_approve_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = lBatchId;
DEBUGLOG(("GetDetail batch_id = [%ld]\n",hv_batch_id));

	hv_disabled = 0;

/*	hv_batch_id.len = strlen(iBatchId);
	memcpy(hv_batch_id.arr,iBatchId,hv_batch_id.len);
DEBUGLOG(("GetDetail batch_id = [%s]\n",hv_batch_id.arr));
*/

	/* EXEC SQL DECLARE c_cursor_getpayout CURSOR FOR
		select	oud_seq_num,
			oud_txn_id,
			oud_aux_txn_id,
			oud_merchant_ref,
			oud_country,
			oud_identity_id,
			oud_account_num,
			oud_account_name,
			oud_bank_name,
			oud_bank_code,
			oud_branch,
			oud_phone_num,
			oud_province,
			oud_city,
			oud_payout_amount,
			oud_request_amount,
			oud_payout_currency,
			oud_request_currency,
			oud_member_fee_ccy,
			oud_member_fee,
			oud_merchant_fee_ccy,
			oud_merchant_fee,
			oud_markup_ccy,
			oud_markup_amt,
			oud_exchange_rate,
			oud_status,
			oud_response_code,
			oud_remark,
			oud_batch_mode,
			oud_generated_file_name,
			oud_psp_batch_id,
			oud_fundout_date,
			oud_service_fee,
			oud_psp_id,
			oud_generated_file_id,
			oud_approve_id
		from	ol_merchant_upload_file_detail
		where	oud_batch_id =:hv_batch_id
		and	oud_disabled = :hv_disabled
		order by oud_seq_num; */ 


	/* EXEC SQL OPEN  c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getpayout_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getpayout
		INTO
			:v_seq_num:ind_seq_num,
			:v_txn_id:ind_txn_id,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_branch:ind_branch,
			:v_phone_num:ind_phone_num,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_payout_amount:ind_payout_amount,
			:v_request_amount:ind_request_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_request_ccy:ind_request_ccy,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_ex_rate:ind_ex_rate,
			:v_status:ind_status,
			:v_resp_code:ind_resp_code,
			:v_remark:ind_remark,
			:v_batch_mode:ind_batch_mode,
			:v_file_name:ind_file_name,
			:v_psp_batch_id:ind_psp_batch_id,
			:v_fundout_date:ind_fundout_date,
			:v_service_fee:ind_service_fee,
			:v_psp_id:ind_psp_id,
			:v_file_id:ind_file_id,
			:v_approve_id:ind_approve_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )96;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_aux_txn_seq;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_aux_txn_seq;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_country;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_identity_id;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_identity_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[6] = (unsigned long )28;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_account_num;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[7] = (unsigned long )103;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_account_name;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[8] = (unsigned long )153;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bank_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_bank_code;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
  sqlstm.sqhstl[10] = (unsigned long )153;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_branch;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
  sqlstm.sqhstl[11] = (unsigned long )28;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_phone_num;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[12] = (unsigned long )103;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_province;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[13] = (unsigned long )103;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_city;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_request_amount;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_member_fee_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_member_fee_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_member_fee;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_fee_ccy;
  sqlstm.sqhstl[20] = (unsigned long )6;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[22] = (unsigned long )6;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_status;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[26] = (unsigned long )13;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_resp_code;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[27] = (unsigned long )258;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_remark;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[28] = (unsigned long )1;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[29] = (unsigned long )53;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_file_name;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[30] = (unsigned long )23;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[31] = (unsigned long )17;
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&ind_service_fee;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[33] = (unsigned long )13;
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&ind_psp_id;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&v_file_id;
  sqlstm.sqhstl[34] = (unsigned long )19;
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)&ind_file_id;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&v_approve_id;
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)&ind_approve_id;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getpayout_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetail seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetail txn_id=[%s]\n",v_txn_id.arr));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetail aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetail merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetail country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetail identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetail account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetail account_name= [%s]\n",v_account_name.arr));
		}

/*bank_name*/
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len]='\0';
			PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetail bank_name= [%s]\n",v_bank_name.arr));
	}

/*bank_code*/
		if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len]='\0';
			PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetail bank_code= [%s]\n",v_bank_code.arr));
		}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetail branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetail phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetail province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetail city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetail payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetail request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetail payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetail request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetail member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetail member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetail merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetail merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetail markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetail markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetail ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetail resp_code= [%s]\n",v_resp_code.arr));
		}

/*status*/
		if(ind_status>=0){
			PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetail status= [%d]\n",v_status));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetail remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetail batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetail file_name= [%s]\n",v_file_name.arr));
		}

/*file_id*/
		if(ind_file_id>=0){
			v_file_id.arr[v_file_id.len]='\0';
			PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetDetail file_id=[%s]\n",v_file_id.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetail psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetail fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetail service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetail psp_id= [%s]\n",v_psp_id.arr));
		}

/*approve_id*/
		if(ind_approve_id>=0){
			PutField_Int(myHash,"approve_id",v_approve_id);
DEBUGLOG(("GetDetail approve_id = [%d]\n",v_approve_id));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )255;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayout_error;
}



DEBUGLOG(("GetDetail Normal Exit\n"));
	return  PD_OK;

getpayout_error:
DEBUGLOG(("getpayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )270;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int GetDetailByTxnId(const char* csTxnId, recordset_t* myRec)
{
	hash_t *myHash;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		unsigned long   v_batch_id;
		int	        v_seq_num;
		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		int		v_status;
		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		double		v_service_fee;
		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int		v_approve_id;

		short           ind_seq_num = -1;
		short           ind_batch_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short		ind_status = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_psp_id = -1;
		short           ind_file_id = -1;
		short           ind_approve_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_disabled = 0;

	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetDetailByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));


	/* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR
		select	oud_batch_id,
			oud_seq_num,
			oud_aux_txn_id,
			oud_merchant_ref,
			oud_country,
			oud_identity_id,
			oud_account_num,
			oud_account_name,
			oud_bank_name,
			oud_bank_code,
			oud_branch,
			oud_phone_num,
			oud_province,
			oud_city,
			oud_payout_amount,
			oud_request_amount,
			oud_payout_currency,
			oud_request_currency,
			oud_member_fee_ccy,
			oud_member_fee,
			oud_merchant_fee_ccy,
			oud_merchant_fee,
			oud_markup_ccy,
			oud_markup_amt,
			oud_exchange_rate,
			oud_status,
			oud_response_code,
			oud_remark,
			oud_batch_mode,
			oud_generated_file_name,
			oud_psp_batch_id,
			oud_fundout_date,
			oud_service_fee,
			oud_psp_id,
			oud_generated_file_id,
			oud_approve_id
		from	ol_merchant_upload_file_detail
		where	oud_txn_id =:hv_txn_id
		and	oud_disabled = :hv_disabled
		order by oud_seq_num; */ 


	/* EXEC SQL OPEN  c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )285;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getdetail
		INTO
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_branch:ind_branch,
			:v_phone_num:ind_phone_num,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_payout_amount:ind_payout_amount,
			:v_request_amount:ind_request_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_request_ccy:ind_request_ccy,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_ex_rate:ind_ex_rate,
			:v_status:ind_status,
			:v_resp_code:ind_resp_code,
			:v_remark:ind_remark,
			:v_batch_mode:ind_batch_mode,
			:v_file_name:ind_file_name,
			:v_psp_batch_id:ind_psp_batch_id,
			:v_fundout_date:ind_fundout_date,
			:v_service_fee:ind_service_fee,
			:v_psp_id:ind_psp_id,
			:v_file_id:ind_file_id,
			:v_approve_id:ind_approve_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )308;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_seq_num;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_aux_txn_seq;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_aux_txn_seq;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_country;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_identity_id;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_identity_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[6] = (unsigned long )28;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_account_num;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[7] = (unsigned long )103;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_account_name;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[8] = (unsigned long )153;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bank_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[9] = (unsigned long )13;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_bank_code;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
  sqlstm.sqhstl[10] = (unsigned long )153;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_branch;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
  sqlstm.sqhstl[11] = (unsigned long )28;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_phone_num;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[12] = (unsigned long )103;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_province;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[13] = (unsigned long )103;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_city;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_request_amount;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_member_fee_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_member_fee_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_member_fee;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_fee_ccy;
  sqlstm.sqhstl[20] = (unsigned long )6;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[22] = (unsigned long )6;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_status;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[26] = (unsigned long )13;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_resp_code;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[27] = (unsigned long )258;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_remark;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[28] = (unsigned long )1;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[29] = (unsigned long )53;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_file_name;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[30] = (unsigned long )23;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[31] = (unsigned long )17;
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&ind_service_fee;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[33] = (unsigned long )13;
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&ind_psp_id;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&v_file_id;
  sqlstm.sqhstl[34] = (unsigned long )19;
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)&ind_file_id;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&v_approve_id;
  sqlstm.sqhstl[35] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)&ind_approve_id;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*batch_id*/
		if(ind_batch_id>=0){
			//PutField_ULong(myHash,"batch_id",v_batch_id);
			sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetDetailByTxnId batch_id=[%ld]\n",v_batch_id));
			PutField_CString(myHash,"batch_id",csBatchId);
		}

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByTxnId seq_num=[%d]\n",v_seq_num));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByTxnId aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByTxnId merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByTxnId country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByTxnId identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByTxnId account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByTxnId account_name= [%s]\n",v_account_name.arr));
		}

/*bank_name*/
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len]='\0';
			PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByTxnId bank_name= [%s]\n",v_bank_name.arr));
	}

/*bank_code*/
		if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len]='\0';
			PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetailByTxnId bank_code= [%s]\n",v_bank_code.arr));
		}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByTxnId branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByTxnId phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByTxnId province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByTxnId city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByTxnId payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByTxnId request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByTxnId payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByTxnId request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByTxnId member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByTxnId member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByTxnId merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByTxnId merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByTxnId markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByTxnId markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByTxnId ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByTxnId resp_code= [%s]\n",v_resp_code.arr));
		}

/*status*/
		if(ind_status>=0){
			PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetailByTxnId status= [%d]\n",v_status));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByTxnId remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByTxnId batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByTxnId file_name= [%s]\n",v_file_name.arr));
		}

/*file_id*/
		if(ind_file_id>=0){
			v_file_id.arr[v_file_id.len]='\0';
			PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetDetailByTxnId file_id=[%s]\n",v_file_id.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByTxnId psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByTxnId fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByTxnId service_fee= [%lf]\n",v_service_fee));
		}


/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetail psp_id= [%s]\n",v_psp_id.arr));
		}

/*approve_id*/
		if(ind_approve_id>=0){
			PutField_Int(myHash,"approve_id",v_approve_id);
DEBUGLOG(("GetDetail approve_id = [%d]\n",v_approve_id));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )467;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetail_error;
}



DEBUGLOG(("GetDetailByTxnId Normal Exit\n"));
	return  PD_OK;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_GetByTxnId: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )482;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int MatchRespTxn(const char* csTxnSeq,
                 const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int             hv_status;

		short		v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchRespTxn status = [%d]\n",hv_status));

        /* EXEC SQL SELECT nvl(COUNT(*),0)
                INTO    :v_cnt
                FROM    ol_merchant_upload_file_detail
                WHERE   oud_txn_id = :hv_txn_id
                and     oud_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM ol_merc\
hant_upload_file_detail WHERE oud_txn_id = :b1 and oud_status = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )497;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto MatchRespTxn_error;
}




	if(v_cnt>0){
DEBUGLOG(("MatchRespTxn Found\n"));
		return PD_FOUND;
        }
	else {
DEBUGLOG(("MatchRespTxn Not Found\n"));
		return PD_NOT_FOUND;
	}


MatchRespTxn_error:
DEBUGLOG(("MatchRespTxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetExistingPsp(hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	int	iCnt = 0;
	char*	csMerchantId;
	char	cMode;
        /* EXEC SQL WHENEVER SQLERROR GOTO epsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int		hv_status;
                int             hv_disabled;
                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		char		hv_batch_mode;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                short           ind_psp_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetExistingPsp status = [%d]\n",hv_status));

        hv_disabled = 0;

	if(GetField_Char(hTxn,"batch_mode",&cMode)){
		hv_batch_mode = cMode;
	}
	else{
		hv_batch_mode = PD_OFFLINE;
	}

	if(GetField_CString(hTxn,"merchant_id",&csMerchantId)){
		
        	hv_merchant_id.len = strlen(csMerchantId);
        	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetExistingPsp merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


        	/* EXEC SQL DECLARE c_cursor_epspm CURSOR FOR
                	SELECT UNIQUE oud_psp_id
                	FROM    ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_id=ouh_batch_id
			and	ouh_merchant_id=:hv_merchant_id
			and	oud_batch_mode=:hv_batch_mode
			and     oud_psp_id IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_epspm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0005;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )524;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
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
  if (sqlca.sqlcode < 0) goto epsp_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_epspm
				INTO
				:v_psp_id:ind_psp_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[0] = (unsigned long )13;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_psp_id;
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
   if (sqlca.sqlcode < 0) goto epsp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*psp_id*/
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetExistingPsp psp_id= [%s]\n",v_psp_id.arr));

				iCnt++;
			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_epspm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )574;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto epsp_error;
}



	}
	else{
        	/* EXEC SQL DECLARE c_cursor_epsp CURSOR FOR
                	SELECT UNIQUE oud_psp_id
                	FROM    ol_merchant_upload_file_detail
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_mode=:hv_batch_mode
			and     oud_psp_id IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_epsp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0006;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )589;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[2] = (unsigned long )1;
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
  if (sqlca.sqlcode < 0) goto epsp_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_epsp
				INTO
				:v_psp_id:ind_psp_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )616;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[0] = (unsigned long )13;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_psp_id;
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
   if (sqlca.sqlcode < 0) goto epsp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*psp_id*/
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetExistingPsp psp_id= [%s]\n",v_psp_id.arr));

				iCnt++;
			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_epsp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )635;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto epsp_error;
}


	}

	if(iCnt>0){
DEBUGLOG(("GetExistingPsp Normal Exit\n"));
		return  PD_OK;
	}
	else{
DEBUGLOG(("GetExistingPsp Normal Exit, No Record\n"));
		return  PD_ERR;
	}

epsp_error:
DEBUGLOG(("GetExistingPsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_epsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )650;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL CLOSE c_cursor_epspm; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )665;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetPreAssignedPsp(hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	int	iCnt = 0;
	char*	csMerchantId;
	char	cMode;
        /* EXEC SQL WHENEVER SQLERROR GOTO gpap_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int		hv_status;
                int             hv_disabled;
                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		char		hv_batch_mode;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                short           ind_psp_id = -1;
                short           ind_bank_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetPreAssignedPsp status = [%d]\n",hv_status));

        hv_disabled = 0;

	if(GetField_Char(hTxn,"batch_mode",&cMode)){
		hv_batch_mode = cMode;
	}
	else{
		hv_batch_mode = PD_OFFLINE;
	}

	if(GetField_CString(hTxn,"merchant_id",&csMerchantId)){
		
        	hv_merchant_id.len = strlen(csMerchantId);
        	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetPreAssignedPsp merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


        	/* EXEC SQL DECLARE c_cursor_gpapm CURSOR FOR
                	SELECT UNIQUE oud_pregen_psp_id,
				      oud_pregen_bank_code
                	FROM    ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_id=ouh_batch_id
			and	ouh_merchant_id=:hv_merchant_id
			and	oud_batch_mode=:hv_batch_mode
			and     oud_pregen_psp_id IS NOT NULL
			and	oud_pregen_bank_code IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_gpapm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0007;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )680;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
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
  if (sqlca.sqlcode < 0) goto gpap_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_gpapm
				INTO
				:v_psp_id:ind_psp_id,
				:v_bank_code:ind_bank_code; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )711;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[0] = (unsigned long )13;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_psp_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_code;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank_code;
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
   if (sqlca.sqlcode < 0) goto gpap_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*psp_id*/
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPreAssignedPsp psp_id= [%s]\n",v_psp_id.arr));
				iCnt++;
			}
/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetPreAssignedPsp bank_code= [%s]\n",v_bank_code.arr));

			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_gpapm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )734;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto gpap_error;
}



	}
	else{
        	/* EXEC SQL DECLARE c_cursor_gpap CURSOR FOR
                	SELECT UNIQUE oud_pregen_psp_id,
				      oud_pregen_bank_code
                	FROM    ol_merchant_upload_file_detail
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_mode=:hv_batch_mode
			and     oud_pregen_psp_id IS NOT NULL
			and	oud_pregen_bank_code IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_gpap; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0008;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )749;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[2] = (unsigned long )1;
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
  if (sqlca.sqlcode < 0) goto gpap_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_gpap
				INTO
				:v_psp_id:ind_psp_id,
				:v_bank_code:ind_bank_code; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )776;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[0] = (unsigned long )13;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_psp_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_code;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank_code;
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
   if (sqlca.sqlcode < 0) goto gpap_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*psp_id*/
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPreAssignedPsp psp_id= [%s]\n",v_psp_id.arr));

				iCnt++;
			}
/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetPreAssignedPsp bank_code= [%s]\n",v_bank_code.arr));

			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_gpap; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )799;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto gpap_error;
}


	}

	if(iCnt>0){
DEBUGLOG(("GetPreAssignedPsp Normal Exit\n"));
		return  PD_OK;
	}
	else{
DEBUGLOG(("GetPreAssignedPsp Normal Exit, No Record\n"));
		return  PD_ERR;
	}

gpap_error:
DEBUGLOG(("GetPreAssignedPsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gpap; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )814;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL CLOSE c_cursor_gpapm; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )829;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetPreGeneratedFileId(hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	int	iCnt = 0;
	//char*	csMerchantId;
        /* EXEC SQL WHENEVER SQLERROR GOTO prefile_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int		hv_status;
                int		hv_ofh_status;
                int             hv_disabled;
                //varchar         hv_merchant_id[PD_MERCHANT_ID_LEN];
		char		hv_batch_mode;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                short           ind_file_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetPreGeneratedFileId status = [%d]\n",hv_status));

        hv_disabled = 0;
	hv_batch_mode = PD_OFFLINE;
	hv_ofh_status = PD_PAYOUTFILE_PRE_GENERATED;

/*
	if(GetField_CString(hTxn,"merchant_id",&csMerchantId)){
		
        	hv_merchant_id.len = strlen(csMerchantId);
        	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetPreGeneratedFileId merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


        	EXEC SQL DECLARE c_cursor_prefilem CURSOR FOR
                	SELECT UNIQUE oud_pregen_file_id
                	FROM    ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header,
				ol_payout_generated_file_hd
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_id=ouh_batch_id
			and	ouh_merchant_id=:hv_merchant_id
			and	oud_batch_mode=:hv_batch_mode
			and	ofh_file_id = oud_pregen_file_id
			and	ofh_status = :hv_ofh_status
			and     oud_pregen_file_id IS NOT NULL;

		EXEC SQL OPEN  c_cursor_prefilem;
		do{
			EXEC SQL FETCH c_cursor_prefilem
				INTO
				:v_file_id:ind_file_id;

			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

///file_id
			if(ind_file_id>=0){
				v_file_id.arr[v_file_id.len]='\0';
				PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetPreGeneratedFileId file_id= [%s]\n",v_file_id.arr));

				iCnt++;
			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		EXEC SQL CLOSE c_cursor_prefilem;

	}
	else{
*/
        	/* EXEC SQL DECLARE c_cursor_prefile CURSOR FOR
                	SELECT UNIQUE oud_pregen_file_id
                	FROM    ol_merchant_upload_file_detail,
				ol_payout_generated_file_hd
                	WHERE   oud_status= :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_mode=:hv_batch_mode
			and	ofh_file_id = oud_pregen_file_id
			and	ofh_status = :hv_ofh_status
			and     oud_pregen_file_id IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_prefile; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0009;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )844;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ofh_status;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
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
  if (sqlca.sqlcode < 0) goto prefile_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_prefile
				INTO
				:v_file_id:ind_file_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )875;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
   sqlstm.sqhstl[0] = (unsigned long )19;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_file_id;
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
   if (sqlca.sqlcode < 0) goto prefile_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*file_id*/
			if(ind_file_id>=0){
				v_file_id.arr[v_file_id.len]='\0';
				PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetPreGeneratedFileId file_id= [%s]\n",v_file_id.arr));

				iCnt++;
			}

			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_prefile; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )894;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto prefile_error;
}


//	}

	if(iCnt>0){
DEBUGLOG(("GetPreGeneratedFileId Normal Exit\n"));
		return  PD_OK;
	}
	else{
DEBUGLOG(("GetPreGeneratedFileId Normal Exit, No Record\n"));
		return  PD_ERR;
	}

prefile_error:
DEBUGLOG(("GetPreGeneratedFileId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_prefile; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )909;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        //EXEC SQL CLOSE c_cursor_prefilem;
        return PD_ERR;
}


int GetPspAssignedTxn(hash_t* hTxn, recordset_t* myRec)
{
	hash_t	*myHash;
	int	iCnt = 0;
	char	csBatchId[PD_TXN_SEQ_LEN+1];
	char*	csMerchantId;
	char	cMode;

        /* EXEC SQL WHENEVER SQLERROR GOTO psp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		int		hv_status;
		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		char		hv_batch_mode;

		unsigned long	v_batch_id;
		int		v_seq_num;
		/* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		double		v_payout_amount;
		double		v_request_amount;
		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar		v_txn_country[PD_COUNTRY_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar		v_payout_ccy[PD_CURRENCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CURRENCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_markup_amt;
		double		v_member_fee;
		double		v_merchant_fee;
		/* varchar         v_pre_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pre_bank_code;


		short		ind_txn_id = -1;
		short		ind_psp_id = -1;
		short		ind_seq_num = -1;
		short		ind_batch_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_amount = -1;
		short		ind_remark = -1;
		short		ind_txn_country = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short		ind_markup_amt= -1;
		short		ind_markup_ccy= -1;
		short           ind_pre_bank_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetPspAssignedTxn status = [%d]\n",hv_status));

	hv_disabled = 0;
	
	if(GetField_Char(hTxn,"batch_mode",&cMode)){
		hv_batch_mode = cMode;
	}
	else{
		hv_batch_mode=PD_OFFLINE;
	}
DEBUGLOG(("GetPspAssignedTxn batch_mode = [%c]\n",hv_batch_mode));

	if(GetField_CString(hTxn,"merchant_id",&csMerchantId)){
        	hv_merchant_id.len = strlen(csMerchantId);
        	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetPspAssignedTxn merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

		/* EXEC SQL DECLARE c_cursor_pspm CURSOR FOR
        		SELECT	oud_batch_id,
				oud_seq_num,
				oud_txn_id,
				oud_merchant_ref,
				oud_identity_id,
				oud_account_name,
				oud_account_num,
				oud_bank_name,
				oud_branch,
				oud_phone_num,
				oud_province,
				oud_city,
				oud_payout_amount,
				oud_request_amount,
				oud_remark,
				oud_pregen_psp_id,
				oud_pregen_bank_code,
				oud_country,
				oud_payout_currency,
				oud_request_currency,
				oud_merchant_fee_ccy,
				oud_merchant_fee,
				oud_member_fee_ccy,
				oud_member_fee,
				oud_markup_amt,
				oud_markup_ccy
			FROM    ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header
                	WHERE   oud_status = :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_id=ouh_batch_id
			and	ouh_merchant_id = :hv_merchant_id
			and	oud_batch_mode=:hv_batch_mode
			and     oud_pregen_psp_id IS NOT NULL
			order by oud_batch_id, oud_seq_num; */ 


		/* EXEC SQL OPEN  c_cursor_pspm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0010;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )924;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
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
  if (sqlca.sqlcode < 0) goto psp_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_pspm
				INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_identity_id:ind_identity_id,
				:v_account_name:ind_account_name,
				:v_account_num:ind_account_num,
				:v_bank_name:ind_bank_name,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_remark:ind_remark,
				:v_psp_id:ind_psp_id,
				:v_pre_bank_code:ind_pre_bank_code,
				:v_txn_country:ind_txn_country,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_merchant_fee_ccy:ind_merchant_fee_ccy,
				:v_merchant_fee:ind_merchant_fee,
				:v_member_fee_ccy:ind_member_fee_ccy,
				:v_member_fee:ind_member_fee,
				:v_markup_amt:ind_markup_amt,
				:v_markup_ccy:ind_markup_ccy; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )955;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_batch_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_seq_num;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
   sqlstm.sqhstl[2] = (unsigned long )19;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_txn_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
   sqlstm.sqhstl[3] = (unsigned long )53;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_identity_id;
   sqlstm.sqhstl[4] = (unsigned long )28;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_identity_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_account_name;
   sqlstm.sqhstl[5] = (unsigned long )103;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_account_name;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
   sqlstm.sqhstl[6] = (unsigned long )28;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_account_num;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
   sqlstm.sqhstl[7] = (unsigned long )153;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_bank_name;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_branch;
   sqlstm.sqhstl[8] = (unsigned long )153;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_branch;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_phone_num;
   sqlstm.sqhstl[9] = (unsigned long )28;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_phone_num;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
   sqlstm.sqhstl[10] = (unsigned long )103;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_province;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
   sqlstm.sqhstl[11] = (unsigned long )103;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_city;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_payout_amount;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_payout_amount;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_request_amount;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_request_amount;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_remark;
   sqlstm.sqhstl[14] = (unsigned long )258;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_remark;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[15] = (unsigned long )13;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_psp_id;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_pre_bank_code;
   sqlstm.sqhstl[16] = (unsigned long )13;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_pre_bank_code;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_country;
   sqlstm.sqhstl[17] = (unsigned long )5;
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_txn_country;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_payout_ccy;
   sqlstm.sqhstl[18] = (unsigned long )6;
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_payout_ccy;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (unsigned char  *)&v_request_ccy;
   sqlstm.sqhstl[19] = (unsigned long )6;
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         short *)&ind_request_ccy;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned long )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
   sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_fee_ccy;
   sqlstm.sqhstl[20] = (unsigned long )6;
   sqlstm.sqhsts[20] = (         int  )0;
   sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
   sqlstm.sqinds[20] = (         int  )0;
   sqlstm.sqharm[20] = (unsigned long )0;
   sqlstm.sqadto[20] = (unsigned short )0;
   sqlstm.sqtdso[20] = (unsigned short )0;
   sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee;
   sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[21] = (         int  )0;
   sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned long )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqhstv[22] = (unsigned char  *)&v_member_fee_ccy;
   sqlstm.sqhstl[22] = (unsigned long )6;
   sqlstm.sqhsts[22] = (         int  )0;
   sqlstm.sqindv[22] = (         short *)&ind_member_fee_ccy;
   sqlstm.sqinds[22] = (         int  )0;
   sqlstm.sqharm[22] = (unsigned long )0;
   sqlstm.sqadto[22] = (unsigned short )0;
   sqlstm.sqtdso[22] = (unsigned short )0;
   sqlstm.sqhstv[23] = (unsigned char  *)&v_member_fee;
   sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[23] = (         int  )0;
   sqlstm.sqindv[23] = (         short *)&ind_member_fee;
   sqlstm.sqinds[23] = (         int  )0;
   sqlstm.sqharm[23] = (unsigned long )0;
   sqlstm.sqadto[23] = (unsigned short )0;
   sqlstm.sqtdso[23] = (unsigned short )0;
   sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_amt;
   sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[24] = (         int  )0;
   sqlstm.sqindv[24] = (         short *)&ind_markup_amt;
   sqlstm.sqinds[24] = (         int  )0;
   sqlstm.sqharm[24] = (unsigned long )0;
   sqlstm.sqadto[24] = (unsigned short )0;
   sqlstm.sqtdso[24] = (unsigned short )0;
   sqlstm.sqhstv[25] = (unsigned char  *)&v_markup_ccy;
   sqlstm.sqhstl[25] = (unsigned long )6;
   sqlstm.sqhsts[25] = (         int  )0;
   sqlstm.sqindv[25] = (         short *)&ind_markup_ccy;
   sqlstm.sqinds[25] = (         int  )0;
   sqlstm.sqharm[25] = (unsigned long )0;
   sqlstm.sqadto[25] = (unsigned short )0;
   sqlstm.sqtdso[25] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto psp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*txn_id*/	
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetPspAssignedTxn txn_id= [%s]\n",v_txn_id.arr));

			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPspAssignedTxn psp_id= [%s]\n",v_psp_id.arr));

			}

/*pre_bank_code*/	
			if(ind_pre_bank_code>=0){
				v_pre_bank_code.arr[v_pre_bank_code.len]='\0';
				PutField_CString(myHash,"pregen_bank_code",(const char*)v_pre_bank_code.arr);
DEBUGLOG(("GetPspAssignedTxn pregen_bank_code = [%s]\n",v_pre_bank_code.arr));

			}

/*txn_country*/	
			if(ind_txn_country>=0){
				v_txn_country.arr[v_txn_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetPspAssignedTxn txn_country= [%s]\n",v_txn_country.arr));

			}

/*batch_id*/
			if(ind_batch_id>=0){
				sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetPspAssignedTxn batch_id=[%ld]\n",v_batch_id));
				PutField_CString(myHash,"batch_id",csBatchId);
			}


/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetPspAssignedTxn seq_num=[%d]\n",v_seq_num));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetPspAssignedTxn merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetPspAssignedTxn identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetPspAssignedTxn account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetPspAssignedTxn account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetPspAssignedTxn bank_name= [%s]\n",v_bank_name.arr));
			}


/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetPspAssignedTxn branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetPspAssignedTxn phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetPspAssignedTxn province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetPspAssignedTxn city= [%s]\n",v_city.arr));
			}

/*request_ccy*/	
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn request_ccy= [%s]\n",v_request_ccy.arr));

			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetPspAssignedTxn request_amount = [%lf]\n",v_request_amount));
			}

/*payout_ccy*/	
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn payout_ccy= [%s]\n",v_payout_ccy.arr));

			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetPspAssignedTxn payout_amount = [%lf]\n",v_payout_amount));
			}

/*merchant_fee_ccy*/	
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));

			}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetPspAssignedTxn merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*member_fee_ccy*/	
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));

			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetPspAssignedTxn member_fee = [%lf]\n",v_member_fee));
			}

/*markup_ccy*/	
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn markup_ccy= [%s]\n",v_markup_ccy.arr));

			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetPspAssignedTxn markup_amt = [%lf]\n",v_markup_amt));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetPspAssignedTxn remark= [%s]\n",v_remark.arr));
			}

			iCnt ++;
			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_pspm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1074;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto psp_error;
}



	}
	else{
DEBUGLOG(("GetPspAssignedTxn select without merchant_id\n"));
		/* EXEC SQL DECLARE c_cursor_pspwom CURSOR FOR
        		SELECT	oud_batch_id,
				oud_seq_num,
				oud_txn_id,
				oud_merchant_ref,
				oud_identity_id,
				oud_account_name,
				oud_account_num,
				oud_bank_name,
				oud_branch,
				oud_phone_num,
				oud_province,
				oud_city,
				oud_request_amount,
				oud_payout_amount,
				oud_remark,
				oud_pregen_psp_id,
				oud_pregen_bank_code,
				oud_country,
				oud_request_currency,
				oud_payout_currency
         	       FROM    ol_merchant_upload_file_detail
                	WHERE   oud_status = :hv_status
                	and     oud_disabled = :hv_disabled
			and	oud_batch_mode=:hv_batch_mode
			and     oud_pregen_psp_id IS NOT NULL
			order by oud_batch_id, oud_seq_num; */ 


		/* EXEC SQL OPEN  c_cursor_pspwom; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0011;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1089;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
  sqlstm.sqhstl[2] = (unsigned long )1;
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
  if (sqlca.sqlcode < 0) goto psp_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_pspwom
			INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_identity_id:ind_identity_id,
				:v_account_name:ind_account_name,
				:v_account_num:ind_account_num,
				:v_bank_name:ind_bank_name,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_request_amount:ind_request_amount,
				:v_payout_amount:ind_payout_amount,
				:v_remark:ind_remark,
				:v_psp_id:ind_psp_id,
				:v_pre_bank_code:ind_pre_bank_code,
				:v_txn_country:ind_txn_country,
				:v_request_ccy:ind_request_ccy,
				:v_payout_ccy:ind_payout_ccy; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1116;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_batch_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_seq_num;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
   sqlstm.sqhstl[2] = (unsigned long )19;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_txn_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
   sqlstm.sqhstl[3] = (unsigned long )53;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_identity_id;
   sqlstm.sqhstl[4] = (unsigned long )28;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_identity_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_account_name;
   sqlstm.sqhstl[5] = (unsigned long )103;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_account_name;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
   sqlstm.sqhstl[6] = (unsigned long )28;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_account_num;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
   sqlstm.sqhstl[7] = (unsigned long )153;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_bank_name;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_branch;
   sqlstm.sqhstl[8] = (unsigned long )153;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_branch;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_phone_num;
   sqlstm.sqhstl[9] = (unsigned long )28;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_phone_num;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
   sqlstm.sqhstl[10] = (unsigned long )103;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_province;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
   sqlstm.sqhstl[11] = (unsigned long )103;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_city;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_request_amount;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_request_amount;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_payout_amount;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_payout_amount;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_remark;
   sqlstm.sqhstl[14] = (unsigned long )258;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_remark;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[15] = (unsigned long )13;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_psp_id;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_pre_bank_code;
   sqlstm.sqhstl[16] = (unsigned long )13;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_pre_bank_code;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_country;
   sqlstm.sqhstl[17] = (unsigned long )5;
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_txn_country;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
   sqlstm.sqhstl[18] = (unsigned long )6;
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (unsigned char  *)&v_payout_ccy;
   sqlstm.sqhstl[19] = (unsigned long )6;
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         short *)&ind_payout_ccy;
   sqlstm.sqinds[19] = (         int  )0;
   sqlstm.sqharm[19] = (unsigned long )0;
   sqlstm.sqadto[19] = (unsigned short )0;
   sqlstm.sqtdso[19] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto psp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/*txn_id*/	
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetPspAssignedTxn txn_id= [%s]\n",v_txn_id.arr));

			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPspAssignedTxn psp_id= [%s]\n",v_psp_id.arr));

			}

/*pre_bank_code*/	
			if(ind_pre_bank_code>=0){
				v_pre_bank_code.arr[v_pre_bank_code.len]='\0';
				PutField_CString(myHash,"pregen_bank_code",(const char*)v_pre_bank_code.arr);
DEBUGLOG(("GetPspAssignedTxn pregen_bank_code = [%s]\n",v_pre_bank_code.arr));

			}

/*txn_country*/	
			if(ind_txn_country>=0){
				v_txn_country.arr[v_txn_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetPspAssignedTxn txn_country= [%s]\n",v_txn_country.arr));

			}

/*batch_id*/
			if(ind_batch_id>=0){
				sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetPspAssignedTxn batch_id=[%ld]\n",v_batch_id));
				PutField_CString(myHash,"batch_id",csBatchId);
			}


/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetPspAssignedTxn seq_num=[%d]\n",v_seq_num));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetPspAssignedTxn merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetPspAssignedTxn identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetPspAssignedTxn account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetPspAssignedTxn account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetPspAssignedTxn bank_name= [%s]\n",v_bank_name.arr));
			}


/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetPspAssignedTxn branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetPspAssignedTxn phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetPspAssignedTxn province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetPspAssignedTxn city= [%s]\n",v_city.arr));
			}

/*request_ccy*/	
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn request_ccy= [%s]\n",v_request_ccy.arr));

			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetPspAssignedTxn request_amount = [%lf]\n",v_request_amount));
			}

/*payout_ccy*/	
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetPspAssignedTxn payout_ccy= [%s]\n",v_payout_ccy.arr));

			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetPspAssignedTxn payout_amount = [%lf]\n",v_payout_amount));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetPspAssignedTxn remark= [%s]\n",v_remark.arr));
			}

			iCnt ++;
			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_pspwom; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1211;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto psp_error;
}


	}
	
	if(iCnt>0){
DEBUGLOG(("GetPspAssignedTxn Normal Exit\n"));
		return  PD_OK;
	}
	else{
DEBUGLOG(("GetPspAssignedTxn Normal Exit, No Record\n"));
		return  PD_ERR;
	}

psp_error:
DEBUGLOG(("GetPspAssignedTxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_pspm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL CLOSE c_cursor_pspwom; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1241;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetDetailByRandom(recordset_t* myRec)
{
	hash_t *myHash;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailr_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		int		hv_status;
		char		hv_batch_mode;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		unsigned long   v_batch_id;
		int	        v_seq_num;
		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		double		v_service_fee;
		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;



		short           ind_txn_id = -1;
		short           ind_seq_num = -1;
		short           ind_batch_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short		ind_bank_name = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_psp_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_disabled = 0;
	hv_batch_mode = PD_OFFLINE;

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetDetailByRandom status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getdetailr CURSOR FOR
		select	oud_txn_id,
			oud_batch_id,
			oud_seq_num,
			oud_aux_txn_id,
			oud_merchant_ref,
			oud_country,
			oud_identity_id,
			oud_account_num,
			oud_account_name,
			oud_bank_name,
			oud_branch,
			oud_phone_num,
			oud_province,
			oud_city,
			oud_payout_amount,
			oud_request_amount,
			oud_payout_currency,
			oud_request_currency,
			oud_member_fee_ccy,
			oud_member_fee,
			oud_merchant_fee_ccy,
			oud_merchant_fee,
			oud_markup_ccy,
			oud_markup_amt,
			oud_exchange_rate,
			oud_response_code,
			oud_remark,
			oud_batch_mode,
			oud_generated_file_name,
			oud_psp_batch_id,
			oud_fundout_date,
			oud_service_fee
		from	(SELECT * FROM ol_merchant_upload_file_detail ORDER BY dbms_random.value),
			ol_merchant_upload_file_header
		where	oud_status = :hv_status
		and	oud_disabled = :hv_disabled
		and	oud_batch_mode=:hv_batch_mode
		and	oud_batch_id = ouh_batch_id
		and	oud_disabled = ouh_disabled
		and	oud_pregen_psp_id IS NULL; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1256;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto getdetailr_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getdetailr
		INTO	:v_txn_id:ind_txn_id,
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_branch:ind_branch,
			:v_phone_num:ind_phone_num,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_payout_amount:ind_payout_amount,
			:v_request_amount:ind_request_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_request_ccy:ind_request_ccy,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_ex_rate:ind_ex_rate,
			:v_resp_code:ind_resp_code,
			:v_remark:ind_remark,
			:v_batch_mode:ind_batch_mode,
			:v_file_name:ind_file_name,
			:v_psp_batch_id:ind_psp_batch_id,
			:v_fundout_date:ind_fundout_date,
			:v_service_fee:ind_service_fee; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1283;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_batch_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_seq_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_aux_txn_seq;
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_aux_txn_seq;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_country;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
  sqlstm.sqhstl[6] = (unsigned long )28;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_identity_id;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[7] = (unsigned long )28;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_account_num;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[8] = (unsigned long )103;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_account_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[9] = (unsigned long )153;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_bank_name;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
  sqlstm.sqhstl[10] = (unsigned long )153;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_branch;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
  sqlstm.sqhstl[11] = (unsigned long )28;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_phone_num;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[12] = (unsigned long )103;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_province;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[13] = (unsigned long )103;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_city;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_request_amount;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_member_fee_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_member_fee_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_member_fee;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_fee_ccy;
  sqlstm.sqhstl[20] = (unsigned long )6;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[22] = (unsigned long )6;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[25] = (unsigned long )13;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_resp_code;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[26] = (unsigned long )258;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_remark;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[27] = (unsigned long )1;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[28] = (unsigned long )53;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_file_name;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[29] = (unsigned long )23;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[30] = (unsigned long )17;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&ind_service_fee;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getdetailr_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*batch_id*/
		if(ind_batch_id>=0){
			//PutField_ULong(myHash,"batch_id",v_batch_id);
			sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetDetailByRandom batch_id=[%ld]\n",v_batch_id));
			PutField_CString(myHash,"batch_id",csBatchId);
		}

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByRandom seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByRandom txn_id=[%s]\n",v_txn_id.arr));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByRandom aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByRandom merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByRandom country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByRandom identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByRandom account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByRandom account_name= [%s]\n",v_account_name.arr));
		}

/*bank_name*/
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len]='\0';
			PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByRandom bank_name= [%s]\n",v_bank_name.arr));
	}


/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByRandom branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByRandom phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByRandom province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByRandom city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByRandom payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByRandom request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByRandom payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByRandom request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandom member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByRandom member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandom merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByRandom merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByRandom markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByRandom markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByRandom ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByRandom resp_code= [%s]\n",v_resp_code.arr));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByRandom remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByRandom batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByRandom file_name= [%s]\n",v_file_name.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByRandom psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByRandom fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByRandom service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByRandom psp_id= [%s]\n",v_psp_id.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1426;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetailr_error;
}



DEBUGLOG(("GetDetailByRandom Normal Exit\n"));
	return  PD_OK;

getdetailr_error:
DEBUGLOG(("getdetailr_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_GetWithBankByRandom: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1441;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}



int MatchCount(const unsigned long lBatchId,const int iStatus)
{
	int iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO check_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;
		int		hv_status;
		int		hv_void_status;

		short		v_cnt;
		short		v_void_cnt;
		short		v_org_cnt;

		short		ind_org_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id = lBatchId;
DEBUGLOG(("MatchCount batch_id= [%ld]\n",hv_batch_id));

	hv_void_status = PAYOUT_MASTER_TRANSACTION_REVERSED;

	hv_status = iStatus;
DEBUGLOG(("MatchCount status= [%d]\n",hv_status));

        /* EXEC SQL SELECT nvl(COUNT(*),0)
                INTO    :v_cnt
                FROM    ol_merchant_upload_file_detail
                WHERE   oud_batch_id = :hv_batch_id
                and     oud_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM ol_merc\
hant_upload_file_detail WHERE oud_batch_id = :b1 and oud_status = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1456;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto check_error;
}



        /* EXEC SQL SELECT nvl(COUNT(*),0)
                INTO    :v_void_cnt
                FROM    ol_merchant_upload_file_detail
                WHERE   oud_batch_id = :hv_batch_id
                and     oud_status = :hv_void_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM ol_merc\
hant_upload_file_detail WHERE oud_batch_id = :b1 and oud_status = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1483;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_void_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_void_status;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto check_error;
}



        /* EXEC SQL SELECT	ouh_txn_count
                INTO    :v_org_cnt:ind_org_cnt
                FROM    ol_merchant_upload_file_header
                WHERE   ouh_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ouh_txn_count INTO :b0:b1 FROM ol_merchant_up\
load_file_header WHERE ouh_batch_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1510;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_org_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_org_cnt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto check_error;
}



	if(ind_org_cnt>=0){
		if((v_cnt+v_void_cnt)==v_org_cnt){
DEBUGLOG(("MatchCount Matched[%d][%d][%d]\n",v_cnt,v_void_cnt,v_org_cnt));
			iRet = PD_TRUE;
		}
		else{
DEBUGLOG(("MatchCount Not Matched[%d][%d][%d]\n",v_cnt,v_void_cnt,v_org_cnt));
		}
        }
	else{
		iRet = PD_NOT_FOUND;
DEBUGLOG(("MatchCount Not Found in header\n"));
	}


	return iRet;

check_error:
DEBUGLOG(("check_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int ResumeAssignedPsp()
{
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO resume_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeAssignedPsp: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_psp_id ='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        

        strcat((char*)hv_dynstmt.arr, " WHERE oud_status = 65 and oud_batch_mode = 'F' and oud_psp_id IS NOT NULL");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1533;
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
 if (sqlca.sqlcode < 0) goto resume_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1552;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto resume_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("ResumeAssignedPsp Normal Exit\n"));
        return PD_OK;

resume_error:
DEBUGLOG(("resume_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_ResumeAssignedPsp: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}



int ResumePreGenFile(const char*csFileId)
{
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO resumefile_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumePreGenFile: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_pregen_psp_id ='', oud_pregen_file_id='', oud_pregen_bank_code='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);        

        strcat((char*)hv_dynstmt.arr, " WHERE oud_pregen_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1567;
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
 if (sqlca.sqlcode < 0) goto resumefile_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1586;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto resumefile_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("ResumePreGenFile Normal Exit\n"));
        return PD_OK;

resumefile_error:
DEBUGLOG(("resumefile_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_ResumePreGenFile: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int ResumeGeneratedFile(const char* csFileId, const char* csUser)
{
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO resumegfile_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeGeneratedFile: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_psp_id ='',oud_generated_file_name='', oud_generated_file_id='', oud_pregen_psp_id ='',oud_pregen_file_id='', oud_pregen_bank_code='', oud_status = 65 , oud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, ",oud_update_user= '");
	strcat((char*)hv_dynstmt.arr, csUser);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, " WHERE oud_generated_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        strcat((char*)hv_dynstmt.arr, " AND oud_status = 70");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1601;
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
 if (sqlca.sqlcode < 0) goto resumegfile_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1620;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto resumegfile_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("ResumeGeneratedFile Normal Exit\n"));
        return PD_OK;

resumegfile_error:
DEBUGLOG(("resumefile_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_ResumeGeneratedFile: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int GetOnlineBatchRecord(hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	char	*csTmp;
	int	iMerch = PD_FALSE;
	int	iRet = PD_NOT_FOUND;
	/* EXEC SQL WHENEVER SQLERROR GOTO getonpayout_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		int		hv_status;
		char		hv_batch_mode;
		int		hv_disabled;
		/* varchar		hv_merchant[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant;


		SQL_CURSOR      c_cursor_urldt;

		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int	        v_seq_num;
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_id = -1;
		short           ind_service_code = -1;
		short           ind_txn_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_status= -1;
		short           ind_batch_mode= -1;
		short           ind_disabled= -1;
		short           ind_merchant= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_disabled = 0;
	ind_disabled = 0;
	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
	ind_status = 0;
	hv_batch_mode = PD_ONLINE;
	ind_batch_mode = 0;

	if(GetField_CString(hTxn,"merchant_id",&csTmp)){
        	hv_merchant.len = strlen(csTmp);
        	memcpy(hv_merchant.arr,csTmp,hv_merchant.len);
DEBUGLOG(("GetOnlineBatchRecord merchant_id = [%.*s]\n",hv_merchant.len,hv_merchant.arr));
		ind_merchant = 0;
		iMerch = PD_TRUE;
	}

	
	/* EXEC SQL ALLOCATE       :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1635;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getonpayout_error;
}



	if(iMerch==PD_TRUE){
        	/* EXEC SQL EXECUTE
                	BEGIN
                        	:hv_return_value := sp_ol_get_online_batch_mid(
								:hv_merchant:ind_merchant,
								:hv_batch_mode:ind_batch_mode,
								:hv_status:ind_status,
								:hv_disabled:ind_disabled,
								:c_cursor_urldt);
                	END;
        	END-EXEC; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 36;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "begin :hv_return_value := sp_ol_get_online_batch_mi\
d ( :hv_merchant:ind_merchant , :hv_batch_mode:ind_batch_mode , :hv_status:in\
d_status , :hv_disabled:ind_disabled , :c_cursor_urldt ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1654;
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
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant;
         sqlstm.sqhstl[1] = (unsigned long )17;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_merchant;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
         sqlstm.sqhstl[2] = (unsigned long )1;
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_batch_mode;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_status;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
         sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_disabled;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_urldt;
         sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
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
         if (sqlca.sqlcode < 0) goto getonpayout_error;
}


	}
	else{
        	/* EXEC SQL EXECUTE
                	BEGIN
                        	:hv_return_value := sp_ol_get_online_batch(
								:hv_batch_mode:ind_batch_mode,
								:hv_status:ind_status,
								:hv_disabled:ind_disabled,
								:c_cursor_urldt);
                	END;
        	END-EXEC; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 36;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "begin :hv_return_value := sp_ol_get_online_batch ( \
:hv_batch_mode:ind_batch_mode , :hv_status:ind_status , :hv_disabled:ind_disa\
bled , :c_cursor_urldt ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1693;
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
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_mode;
         sqlstm.sqhstl[1] = (unsigned long )1;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_batch_mode;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_status;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_disabled;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_urldt;
         sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getonpayout_error;
}


	}


	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
		iRet = PD_FOUND;
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_batch_id = -1;
			ind_seq_num = -1;
			ind_merchant_id = -1;
			ind_service_code = -1;
			ind_txn_id = -1;
			ind_aux_txn_seq = -1;
			ind_merchant_ref = -1;
			ind_country = -1;
			ind_identity_id = -1;
			ind_account_num = -1;
			ind_account_name = -1;
			ind_bank_name = -1;
			ind_bank_code = -1;
			ind_branch = -1;
			ind_phone_num = -1;
			ind_province = -1;
			ind_city = -1;
			ind_payout_ccy = -1;
			ind_request_ccy = -1;
			ind_member_fee_ccy = -1;
			ind_merchant_fee_ccy = -1;
			ind_markup_ccy = -1;
			ind_payout_amount = -1;
			ind_request_amount = -1;
			ind_member_fee = -1;
			ind_merchant_fee = -1;
			ind_markup_amt = -1;
			ind_ex_rate = -1;
			ind_resp_code = -1;
			ind_remark = -1;
			ind_file_name = -1;
			ind_psp_batch_id = -1;
			ind_psp_id = -1;
			ind_fundout_date = -1;
			ind_service_fee = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_urldt
                        INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_merchant_id:ind_merchant_id,
				:v_service_code:ind_service_code,
				:v_txn_id:ind_txn_id,
				:v_aux_txn_seq:ind_aux_txn_seq,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_member_fee_ccy:ind_member_fee_ccy,
				:v_member_fee:ind_member_fee,
				:v_merchant_fee_ccy:ind_merchant_fee_ccy,
				:v_merchant_fee:ind_merchant_fee,
				:v_markup_ccy:ind_markup_ccy,
				:v_markup_amt:ind_markup_amt,
				:v_ex_rate:ind_ex_rate,
				:v_resp_code:ind_resp_code,
				:v_remark:ind_remark,
				:v_file_name:ind_file_name,
				:v_psp_batch_id:ind_psp_batch_id,
				:v_fundout_date:ind_fundout_date,
				:v_service_fee:ind_service_fee,
				:v_psp_id:ind_psp_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 36;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1728;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[3] = (unsigned long )18;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[4] = (unsigned long )6;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_service_code;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[5] = (unsigned long )19;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_aux_txn_seq;
                        sqlstm.sqhstl[6] = (unsigned long )19;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_aux_txn_seq;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[8] = (unsigned long )5;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_country;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[9] = (unsigned long )28;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[10] = (unsigned long )28;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_account_num;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[11] = (unsigned long )103;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_account_name;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[12] = (unsigned long )153;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[13] = (unsigned long )13;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[14] = (unsigned long )153;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_branch;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[15] = (unsigned long )28;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[16] = (unsigned long )103;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_province;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[17] = (unsigned long )103;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_city;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[20] = (unsigned long )6;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_member_fee_ccy;
                        sqlstm.sqhstl[22] = (unsigned long )6;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_member_fee_ccy;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_member_fee;
                        sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_member_fee;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[24] = (unsigned long )6;
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_markup_ccy;
                        sqlstm.sqhstl[26] = (unsigned long )6;
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_markup_ccy;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_resp_code;
                        sqlstm.sqhstl[29] = (unsigned long )13;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_resp_code;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[30] = (unsigned long )258;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_remark;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[31] = (unsigned long )53;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_file_name;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_psp_batch_id;
                        sqlstm.sqhstl[32] = (unsigned long )23;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_psp_batch_id;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_fundout_date;
                        sqlstm.sqhstl[33] = (unsigned long )17;
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_fundout_date;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
                        sqlstm.sqhstv[34] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[34] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[34] = (         int  )0;
                        sqlstm.sqindv[34] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[34] = (         int  )0;
                        sqlstm.sqharm[34] = (unsigned long )0;
                        sqlstm.sqadto[34] = (unsigned short )0;
                        sqlstm.sqtdso[34] = (unsigned short )0;
                        sqlstm.sqhstv[35] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[35] = (unsigned long )13;
                        sqlstm.sqhsts[35] = (         int  )0;
                        sqlstm.sqindv[35] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[35] = (         int  )0;
                        sqlstm.sqharm[35] = (unsigned long )0;
                        sqlstm.sqadto[35] = (unsigned short )0;
                        sqlstm.sqtdso[35] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getonpayout_error;
}





/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetOnlineBatchRecord seq_num=[%d]\n",v_seq_num));
			}

/*batch_id*/
			if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetOnlineBatchRecord batch_id=[%s]\n",v_batch_id.arr));
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
				PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetOnlineBatchRecord merchant_id=[%s]\n",v_merchant_id.arr));
			}

/*service_code*/
			if(ind_service_code>=0){
				v_service_code.arr[v_service_code.len]='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetOnlineBatchRecord service_code=[%s]\n",v_service_code.arr));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetOnlineBatchRecord txn_id=[%s]\n",v_txn_id.arr));
			}

/*aux_txn_seq*/
			if(ind_aux_txn_seq>=0){
				v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
				PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetOnlineBatchRecord aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetOnlineBatchRecord merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*country*/
			if(ind_country>=0){
				v_country.arr[v_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetOnlineBatchRecord country= [%s]\n",v_country.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetOnlineBatchRecord identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetOnlineBatchRecord account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetOnlineBatchRecord account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetOnlineBatchRecord bank_name= [%s]\n",v_bank_name.arr));
			}

/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetOnlineBatchRecord bank_code= [%s]\n",v_bank_code.arr));
			}

/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetOnlineBatchRecord branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetOnlineBatchRecord phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetOnlineBatchRecord province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetOnlineBatchRecord city= [%s]\n",v_city.arr));
			}

/*payout_currency*/
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetOnlineBatchRecord payout_ccy= [%s]\n",v_payout_ccy.arr));
			}

/*request_currency*/
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetOnlineBatchRecord request_ccy= [%s]\n",v_request_ccy.arr));
			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetOnlineBatchRecord payout_amount = [%lf]\n",v_payout_amount));
			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetOnlineBatchRecord request_amount = [%lf]\n",v_request_amount));
			}

/*member_fee_ccy*/
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetOnlineBatchRecord member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetOnlineBatchRecord member_fee = [%lf]\n",v_member_fee));
			}

/*merchant_fee_ccy*/
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetOnlineBatchRecord merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
			}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetOnlineBatchRecord merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*markup_ccy*/
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetOnlineBatchRecord markup_ccy= [%s]\n",v_markup_ccy.arr));
			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetOnlineBatchRecord markup_amt = [%lf]\n",v_markup_amt));
			}

/*ex_rate*/
			if(ind_ex_rate>=0){
				PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetOnlineBatchRecord ex_rate = [%lf]\n",v_ex_rate));
			}

/*resp_code*/
			if(ind_resp_code>=0){
				v_resp_code.arr[v_resp_code.len]='\0';
				PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetOnlineBatchRecord resp_code= [%s]\n",v_resp_code.arr));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetOnlineBatchRecord remark= [%s]\n",v_remark.arr));
			}

/*file_name*/
			if(ind_file_name>=0){
				v_file_name.arr[v_file_name.len]='\0';
				PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetOnlineBatchRecord file_name= [%s]\n",v_file_name.arr));
			}

/*psp_batch_id*/	
			if(ind_psp_batch_id>=0){
				v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
				PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetOnlineBatchRecord psp_batch_id= [%s]\n",v_psp_batch_id.arr));
			}

/*fundout_date*/
			if(ind_fundout_date>=0){
				v_fundout_date.arr[v_fundout_date.len]='\0';
				PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetOnlineBatchRecord fundout_date= [%s]\n",v_fundout_date.arr));
			}

/*service_fee*/
			if(ind_service_fee>=0){
				PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetOnlineBatchRecord service_fee= [%lf]\n",v_service_fee));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetOnlineBatchRecord psp_id= [%s]\n",v_psp_id.arr));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1887;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getonpayout_error;
}


	/* EXEC SQL FREE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1906;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getonpayout_error;
}



DEBUGLOG(("GetOnlineBatchRecord Normal Exit [%d]\n",iRet));
	return  iRet;

getonpayout_error:
DEBUGLOG(("getonpayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DBOLMerchantUploadFileDetail GetOnlineBatchRecord: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1925;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	/* EXEC SQL FREE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1944;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;

}




int	Add(const hash_t *hRls)
{
	char            *csTmp;
	char            cTmp;
	int             iTmp;
	double          dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar         hv_aux_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_aux_txn_id;

		int             hv_seq_num;
		/* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar         hv_identity_id[PD_IDENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_identity_id;

		/* varchar         hv_account_num[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_num;

		/* varchar         hv_account_name[PD_ACC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_account_name;

		/* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		/* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar         hv_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_branch;

		/* varchar         hv_phone_num[PD_MOBILE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_phone_num;

		/* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_province;

		/* varchar         hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

		/* varchar         hv_payout_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_currency;

		/* varchar         hv_request_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_request_currency;

		double		hv_payout_amount;
		double          hv_request_amount;
		/* varchar         hv_merchant_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_merchant_fee_ccy;

		/* varchar         hv_member_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_member_fee_ccy;

		double		hv_merchant_fee;
		double          hv_member_fee;
		/* varchar         hv_markup_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_markup_ccy;

		double		hv_markup_amt;
		double		hv_ex_rate;
		int		hv_status;
		/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar		hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;

		char		hv_merchant_grp;

		short           ind_batch_id= -1;
		short           ind_txn_id= -1;
		short           ind_aux_txn_id= -1;
		short           ind_seq_num = -1;
		short           ind_merchant_ref = -1;
		short           ind_country = -1;
		short           ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short           ind_branch = -1;
		short           ind_phone_num = -1;
		short           ind_province = -1;
		short           ind_city = -1;
		short           ind_payout_currency = -1;
		short           ind_request_currency = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee = -1;
		short           ind_member_fee = -1;
		short           ind_markup_ccy = -1;
		short           ind_markup_amt = -1;
		short           ind_ex_rate = -1;
		short           ind_status = -1;
		short           ind_remark = -1;
		short           ind_user = -1;
		short           ind_merchant_grp = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/*batch_id*/
	if(GetField_CString(hRls,"batch_id",&csTmp)){
		hv_batch_id.len = strlen(csTmp);
		memcpy(hv_batch_id.arr, csTmp, hv_batch_id.len);
		ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
	}

/*txn_id*/
	if(GetField_CString(hRls,"txn_id",&csTmp)){
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

/*aux_txn_id*/
	if(GetField_CString(hRls,"aux_txn_id",&csTmp)){
		hv_aux_txn_id.len = strlen(csTmp);
		memcpy(hv_aux_txn_id.arr, csTmp, hv_aux_txn_id.len);
		ind_aux_txn_id= 0;
DEBUGLOG(("Add:aux_txn_id= [%.*s]\n",hv_aux_txn_id.len,hv_aux_txn_id.arr));
	}

/*seq_num*/
        if(GetField_Int(hRls,"seq_num",&iTmp)){
                hv_seq_num = iTmp;
                ind_seq_num = 0;
DEBUGLOG(("Add:seq_num = [%d]\n",hv_seq_num));
        }

/*merchant ref no*/
        if(GetField_CString(hRls,"merchant_ref",&csTmp)){
                hv_merchant_ref.len = strlen(csTmp);
                memcpy(hv_merchant_ref.arr, csTmp, hv_merchant_ref.len);
                ind_merchant_ref = 0;
DEBUGLOG(("Add:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }

/*country*/
        if(GetField_CString(hRls,"country",&csTmp)){
                hv_country.len = strlen(csTmp);
                memcpy(hv_country.arr, csTmp, hv_country.len);
                ind_country = 0;
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

/*identity id no*/
        if(GetField_CString(hRls,"identity_id",&csTmp)){
                hv_identity_id.len = strlen(csTmp);
                memcpy(hv_identity_id.arr, csTmp, hv_identity_id.len);
                ind_identity_id = 0;
DEBUGLOG(("Add:identity_id = [%.*s]\n",hv_identity_id.len,hv_identity_id.arr));
        }

/*account_num*/
        if(GetField_CString(hRls,"account_num",&csTmp)){
                hv_account_num.len = strlen(csTmp);
                memcpy(hv_account_num.arr, csTmp, hv_account_num.len);
                ind_account_num = 0;
DEBUGLOG(("Add:account_num = [%.*s]\n",hv_account_num.len,hv_account_num.arr));
        }

/*account name*/
        if(GetField_CString(hRls,"account_name",&csTmp)){
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr, csTmp, hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
        }

/*bank_name*/
        if(GetField_CString(hRls,"bank_name",&csTmp)){
                hv_bank_name.len = strlen(csTmp);
                memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
        }

/*bank_code*/
        if(GetField_CString(hRls,"bank_code",&csTmp)){
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code= 0;
DEBUGLOG(("Add:bank_code= [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
        }

/*branch*/
        if(GetField_CString(hRls,"branch",&csTmp)){
                hv_branch.len = strlen(csTmp);
                memcpy(hv_branch.arr, csTmp, hv_branch.len);
                ind_branch = 0;
DEBUGLOG(("Add:branch = [%.*s]\n",hv_branch.len,hv_branch.arr));
        }

/*phone_num*/
        if(GetField_CString(hRls,"phone_num",&csTmp)){
                hv_phone_num.len = strlen(csTmp);
                memcpy(hv_phone_num.arr, csTmp, hv_phone_num.len);
                ind_phone_num = 0;
DEBUGLOG(("Add:phone_num = [%.*s]\n",hv_phone_num.len,hv_phone_num.arr));
        }

/*province*/
        if(GetField_CString(hRls,"province",&csTmp)){
                hv_province.len = strlen(csTmp);
                memcpy(hv_province.arr, csTmp, hv_province.len);
                ind_province = 0;
DEBUGLOG(("Add:province = [%.*s]\n",hv_province.len,hv_province.arr));
        }

/*city*/
        if(GetField_CString(hRls,"city",&csTmp)){
                hv_city.len = strlen(csTmp);
                memcpy(hv_city.arr, csTmp, hv_city.len);
                ind_city = 0;
DEBUGLOG(("Add:city = [%.*s]\n",hv_city.len,hv_city.arr));
        }

/*payout currency*/
        if(GetField_CString(hRls,"payout_currency",&csTmp)){
                hv_payout_currency.len = strlen(csTmp);
                memcpy(hv_payout_currency.arr, csTmp, hv_payout_currency.len);
                ind_payout_currency = 0;
DEBUGLOG(("Add:payout_currency = [%.*s]\n",hv_payout_currency.len,hv_payout_currency.arr));
        }

/*payout_amount*/
        if (GetField_Double(hRls,"payout_amount",&dTmp)) {
                hv_payout_amount = dTmp;
                ind_payout_amount = 0;
DEBUGLOG(("Add:payout_amount = [%lf]\n",hv_payout_amount));
        }
	else{
                hv_payout_amount = 0.0;
                ind_payout_amount = 0;
	}

/*request currency*/
        if(GetField_CString(hRls,"request_currency",&csTmp)){
                hv_request_currency.len = strlen(csTmp);
                memcpy(hv_request_currency.arr, csTmp, hv_request_currency.len);
                ind_request_currency = 0;
DEBUGLOG(("Add:request_currency = [%.*s]\n",hv_request_currency.len,hv_request_currency.arr));
        }

/*request amount*/
        if (GetField_Double(hRls,"request_amount",&dTmp)) {
                hv_request_amount = dTmp;
                ind_request_amount = 0;
DEBUGLOG(("Add:request_amount = [%lf]\n",hv_request_amount));
        }
	else{
                hv_request_amount = 0.0;
                ind_request_amount = 0;
	}

/*merchant_fee_ccy*/
        if(GetField_CString(hRls,"merchant_fee_ccy",&csTmp)){
                hv_merchant_fee_ccy.len = strlen(csTmp);
                memcpy(hv_merchant_fee_ccy.arr, csTmp, hv_merchant_fee_ccy.len);
                ind_merchant_fee_ccy= 0;
DEBUGLOG(("Add:merchant_fee_ccy = [%.*s]\n",hv_merchant_fee_ccy.len,hv_merchant_fee_ccy.arr));
        }

/*merchant_fee*/
        if (GetField_Double(hRls,"merchant_fee",&dTmp)) {
                hv_merchant_fee = dTmp;
                ind_merchant_fee = 0;
DEBUGLOG(("Add:merchant_fee = [%lf]\n",hv_merchant_fee));
        }
	else{
                hv_merchant_fee = 0.0;
                ind_merchant_fee = 0;
	}

/*member_fee_ccy*/
        if(GetField_CString(hRls,"member_fee_ccy",&csTmp)){
                hv_member_fee_ccy.len = strlen(csTmp);
                memcpy(hv_member_fee_ccy.arr, csTmp, hv_member_fee_ccy.len);
                ind_member_fee_ccy= 0;
DEBUGLOG(("Add:member_fee_ccy = [%.*s]\n",hv_member_fee_ccy.len,hv_member_fee_ccy.arr));
        }

/*member_fee*/
        if (GetField_Double(hRls,"member_fee",&dTmp)) {
                hv_member_fee= dTmp;
                ind_member_fee= 0;
DEBUGLOG(("Add:member_fee = [%lf]\n",hv_member_fee));
        }
	else{
                hv_member_fee = 0.0;
                ind_member_fee = 0;
	}

/*markup_ccy*/
        if(GetField_CString(hRls,"markup_ccy",&csTmp)){
                hv_markup_ccy.len = strlen(csTmp);
                memcpy(hv_markup_ccy.arr, csTmp, hv_markup_ccy.len);
                ind_markup_ccy= 0;
DEBUGLOG(("Add:markup_ccy = [%.*s]\n",hv_markup_ccy.len,hv_markup_ccy.arr));
        }

/*markup_amt*/
        if (GetField_Double(hRls,"markup_amt",&dTmp)) {
                hv_markup_amt= dTmp;
                ind_markup_amt= 0;
DEBUGLOG(("Add:markup_amt = [%lf]\n",hv_markup_amt));
        }
	else{
                hv_markup_amt = 0.0;
		ind_markup_amt = 0;
	}

/*ex_rate*/
        if (GetField_Double(hRls,"ex_rate",&dTmp)) {
                hv_ex_rate= dTmp;
                ind_ex_rate= 0;
DEBUGLOG(("Add:ex_rate = [%lf]\n",hv_ex_rate));
        }

/*status*/
        if(GetField_Int(hRls,"status",&iTmp)){
                hv_status = iTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%i]\n",hv_status));
        }

/*remark*/
        if(GetField_CString(hRls,"remark",&csTmp)){
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr, csTmp, hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("Add:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

	if(GetField_Char(hRls,"merchant_group",&cTmp)){
		hv_merchant_grp = cTmp;
		ind_merchant_grp = 0;
DEBUGLOG(("Add: merchant_group = [%c]\n",hv_merchant_grp));
        }


/*user*/
        if(GetField_CString(hRls,"add_user",&csTmp)){
                hv_user.len = strlen(csTmp);
                memcpy(hv_user.arr, csTmp, hv_user.len);
                ind_user = 0;
DEBUGLOG(("Add:user = [%.*s]\n",hv_user.len,hv_user.arr));
        }

        FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_merch_upload_dt_insert(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_seq_num:ind_seq_num,
                                        :hv_txn_id:ind_txn_id,
                                        :hv_aux_txn_id:ind_aux_txn_id,
                                        :hv_merchant_ref:ind_merchant_ref,
                                        :hv_country:ind_country,
                                        :hv_identity_id:ind_identity_id,
                                        :hv_account_num:ind_account_num,
                                        :hv_account_name:ind_account_name,
                                        :hv_bank_name:ind_bank_name,
                                        :hv_bank_code:ind_bank_code,
                                        :hv_branch:ind_branch,
                                        :hv_phone_num:ind_phone_num,
                                        :hv_province:ind_province,
                                        :hv_city:ind_city,
                                        :hv_payout_currency:ind_payout_currency,
                                        :hv_payout_amount:ind_payout_amount,
                                        :hv_request_currency:ind_request_currency,
                                        :hv_request_amount:ind_request_amount,
                                        :hv_merchant_fee_ccy:ind_merchant_fee_ccy,
                                        :hv_merchant_fee:ind_merchant_fee,
                                        :hv_member_fee_ccy:ind_member_fee_ccy,
                                        :hv_member_fee:ind_member_fee,
                                        :hv_markup_ccy:ind_markup_ccy,
                                        :hv_markup_amt:ind_markup_amt,
                                        :hv_ex_rate:ind_ex_rate,
                                        :hv_status:ind_status,
					:hv_remark:ind_remark,
					:hv_merchant_grp:ind_merchant_grp,
					:hv_user:ind_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_insert ( :h\
v_batch_id:ind_batch_id , :hv_seq_num:ind_seq_num , :hv_txn_id:ind_txn_id , :\
hv_aux_txn_id:ind_aux_txn_id , :hv_merchant_ref:ind_merchant_ref , :hv_countr\
y:ind_country , :hv_identity_id:ind_identity_id , :hv_account_num:ind_account\
_num , :hv_account_name:ind_account_name , :hv_bank_name:ind_bank_name , :hv_\
bank_code:ind_bank_code , :hv_branch:ind_branch , :hv_phone_num:ind_phone_num\
 , :hv_province:ind_province , :hv_city:ind_city , :hv_payout_currency:ind_pa\
yout_currency , :hv_payout_amount:ind_payout_amount , :hv_request_currency:in\
d_request_currency , :hv_request_amount:ind_request_amount , :hv_merchant_fee\
_ccy:ind_merchant_fee_ccy , :hv_merchant_fee:ind_merchant_fee , :hv_member_fe\
e_ccy:ind_member_fee_ccy , :hv_member_fee:ind_member_fee , :hv_markup_ccy:ind\
_markup_ccy , :hv_markup_amt:ind_markup_amt , :hv_ex_rate:ind_ex_rate , :hv_s\
tatus:ind_status , :hv_remark:ind_remark , :hv_merchant_grp:ind_merchant_grp \
, :hv_user:ind_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1963;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq_num;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_aux_txn_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_aux_txn_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[6] = (unsigned long )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_country;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_identity_id;
 sqlstm.sqhstl[7] = (unsigned long )27;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_identity_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_num;
 sqlstm.sqhstl[8] = (unsigned long )27;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_account_num;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[9] = (unsigned long )102;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_account_name;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[10] = (unsigned long )152;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_bank_name;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[11] = (unsigned long )12;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_bank_code;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_branch;
 sqlstm.sqhstl[12] = (unsigned long )152;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_branch;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_phone_num;
 sqlstm.sqhstl[13] = (unsigned long )27;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_phone_num;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[14] = (unsigned long )102;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_province;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[15] = (unsigned long )102;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_city;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_payout_currency;
 sqlstm.sqhstl[16] = (unsigned long )5;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_payout_currency;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_payout_amount;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_payout_amount;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_request_currency;
 sqlstm.sqhstl[18] = (unsigned long )5;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_request_currency;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_request_amount;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_request_amount;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_merchant_fee_ccy;
 sqlstm.sqhstl[20] = (unsigned long )5;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_merchant_fee;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_member_fee_ccy;
 sqlstm.sqhstl[22] = (unsigned long )5;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_member_fee_ccy;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_member_fee;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_member_fee;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_markup_ccy;
 sqlstm.sqhstl[24] = (unsigned long )5;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_markup_ccy;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_markup_amt;
 sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_markup_amt;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_ex_rate;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_ex_rate;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_status;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[28] = (unsigned long )257;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_remark;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_merchant_grp;
 sqlstm.sqhstl[29] = (unsigned long )1;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_merchant_grp;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[30] = (unsigned long )22;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_user;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
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
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLMerchantUploadFileDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantUploadFileDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_Add: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetUnvoidedDetail(const unsigned long lBatchId, recordset_t* myRec)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getuvpayout_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_batch_id;
		int		hv_disabled;
		int		hv_status_c;
		int		hv_status_r;
		//varchar		hv_batch_id[PD_TXN_SEQ_LEN];

		int	        v_seq_num;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		int		v_status;
		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;
		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;



		short           ind_seq_num = -1;
		short           ind_txn_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short		ind_status = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_file_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = lBatchId;
DEBUGLOG(("GetDetail batch_id = [%ld]\n",hv_batch_id));

	hv_disabled = 0;
	hv_status_c = PAYOUT_MASTER_TRANSACTION_CANCELLED;
	hv_status_r = PAYOUT_MASTER_TRANSACTION_REVERSED;

/*	hv_batch_id.len = strlen(iBatchId);
	memcpy(hv_batch_id.arr,iBatchId,hv_batch_id.len);
DEBUGLOG(("GetDetail batch_id = [%s]\n",hv_batch_id.arr));
*/

	/* EXEC SQL DECLARE c_cursor_getuvpayout CURSOR FOR
		select	oud_seq_num,
			oud_txn_id,
			oud_merchant_ref,
			oud_country,
			oud_identity_id,
			oud_account_num,
			oud_account_name,
			oud_bank_name,
			oud_bank_code,
			oud_branch,
			oud_phone_num,
			oud_province,
			oud_city,
			oud_payout_amount,
			oud_request_amount,
			oud_payout_currency,
			oud_request_currency,
			oud_member_fee_ccy,
			oud_member_fee,
			oud_merchant_fee_ccy,
			oud_merchant_fee,
			oud_markup_ccy,
			oud_markup_amt,
			oud_exchange_rate,
			oud_status,
			oud_response_code,
			oud_remark,
			oud_batch_mode,
			oud_generated_file_name,
			oud_psp_batch_id,
			oud_fundout_date,
			oud_service_fee,
			oud_psp_id,
			oud_generated_file_id
		from	ol_merchant_upload_file_detail
		where	oud_batch_id =:hv_batch_id
		and	oud_disabled = :hv_disabled
		and	oud_aux_txn_id is NULL
		and	oud_status not in (:hv_status_c,:hv_status_r)
		order by oud_seq_num; */ 


	/* EXEC SQL OPEN  c_cursor_getuvpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2102;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status_c;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status_r;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getuvpayout_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getuvpayout
		INTO
			:v_seq_num:ind_seq_num,
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_branch:ind_branch,
			:v_phone_num:ind_phone_num,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_payout_amount:ind_payout_amount,
			:v_request_amount:ind_request_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_request_ccy:ind_request_ccy,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_ex_rate:ind_ex_rate,
			:v_status:ind_status,
			:v_resp_code:ind_resp_code,
			:v_remark:ind_remark,
			:v_batch_mode:ind_batch_mode,
			:v_file_name:ind_file_name,
			:v_psp_batch_id:ind_psp_batch_id,
			:v_fundout_date:ind_fundout_date,
			:v_service_fee:ind_service_fee,
			:v_psp_id:ind_psp_id,
			:v_file_id:ind_file_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2133;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_country;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_identity_id;
  sqlstm.sqhstl[4] = (unsigned long )28;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_identity_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_account_num;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_account_num;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_account_name;
  sqlstm.sqhstl[6] = (unsigned long )103;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_account_name;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[7] = (unsigned long )153;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_name;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[8] = (unsigned long )13;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bank_code;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_branch;
  sqlstm.sqhstl[9] = (unsigned long )153;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_branch;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_phone_num;
  sqlstm.sqhstl[10] = (unsigned long )28;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_phone_num;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_province;
  sqlstm.sqhstl[11] = (unsigned long )103;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_province;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[12] = (unsigned long )103;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_city;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_payout_amount;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_payout_amount;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_request_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_request_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_ccy;
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_payout_ccy;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_request_ccy;
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_request_ccy;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_member_fee_ccy;
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_member_fee_ccy;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_member_fee;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_member_fee;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_merchant_fee_ccy;
  sqlstm.sqhstl[19] = (unsigned long )6;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_merchant_fee_ccy;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_fee;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_merchant_fee;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[21] = (unsigned long )6;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_status;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[25] = (unsigned long )13;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_resp_code;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[26] = (unsigned long )258;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_remark;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[27] = (unsigned long )1;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[28] = (unsigned long )53;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_file_name;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[29] = (unsigned long )23;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[30] = (unsigned long )17;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[31] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&ind_service_fee;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[32] = (unsigned long )13;
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&ind_psp_id;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&v_file_id;
  sqlstm.sqhstl[33] = (unsigned long )19;
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&ind_file_id;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getuvpayout_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetail seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetail txn_id=[%s]\n",v_txn_id.arr));
		}

/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetail merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetail country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetail identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetail account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetail account_name= [%s]\n",v_account_name.arr));
		}

/*bank_name*/
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len]='\0';
			PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetail bank_name= [%s]\n",v_bank_name.arr));
	}

/*bank_code*/
		if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len]='\0';
			PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetail bank_code= [%s]\n",v_bank_code.arr));
		}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetail branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetail phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetail province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetail city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetail payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetail request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetail payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetail request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetail member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetail member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetail merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetail merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetail markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetail markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetail ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetail resp_code= [%s]\n",v_resp_code.arr));
		}

/*status*/
		if(ind_status>=0){
			PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetail status= [%d]\n",v_status));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetail remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetail batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetail file_name= [%s]\n",v_file_name.arr));
		}

/*file_id*/
		if(ind_file_id>=0){
			v_file_id.arr[v_file_id.len]='\0';
			PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetDetail file_id=[%s]\n",v_file_id.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetail psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetail fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetail service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetail psp_id= [%s]\n",v_psp_id.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getuvpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2284;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getuvpayout_error;
}



DEBUGLOG(("GetDetail Normal Exit\n"));
	return  PD_OK;

getuvpayout_error:
DEBUGLOG(("getuvpayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getuvpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2299;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}



int GetDetailByCondition(hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	char	*csTmp;
	int	iTmp;
	double	dTmp;
	int	iRet = PD_NOT_FOUND;
	/* EXEC SQL WHENEVER SQLERROR GOTO getdt_con_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		/* varchar		hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq_num;
		int		hv_status;
		double		hv_min_amt;
		double		hv_max_amt;
		
		SQL_CURSOR      c_cursor_dtcon;

		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int	        v_seq_num;
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		int		v_status;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;
		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int	        v_approve_id;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_id = -1;
		short           ind_service_code = -1;
		short           ind_txn_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_status = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_file_id = -1;
		short           ind_approve_id = -1;

		short           ind_in_status= -1;
		short           ind_in_batch_id= -1;
		short           ind_in_seq_num= -1;
		short           ind_in_bank_name= -1;
		short           ind_in_file_id = -1;
		short           ind_min_amt= -1;
		short           ind_max_amt= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"bank_name",&csTmp)){
		char    csBank[strlen(csTmp)+3];
        	hv_bank_name.len = strlen(csTmp)+2;
		strcpy(csBank,"%");
		strcat(csBank,csTmp);
		strcat(csBank,"%");
		csBank[strlen(csTmp)+2]='\0';
        	memcpy(hv_bank_name.arr,csBank,hv_bank_name.len);
DEBUGLOG(("GetDetailByCondition bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
		ind_in_bank_name= 0;
	}

	if(GetField_CString(hTxn,"batch_id",&csTmp)){
        	hv_batch_id.len = strlen(csTmp);
        	memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
DEBUGLOG(("GetDetailByCondition batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
		ind_in_batch_id= 0;
	}

	if(GetField_Int(hTxn,"seq_num",&iTmp)){
        	hv_seq_num = iTmp;
DEBUGLOG(("GetDetailByCondition seq_num = [%d]\n",hv_seq_num));
		ind_in_seq_num= 0;
	}

	if(GetField_Int(hTxn,"status",&iTmp)){
        	hv_status= iTmp;
DEBUGLOG(("GetDetailByCondition status = [%d]\n",hv_status));
		ind_in_status= 0;
	}

	if(GetField_Double(hTxn,"min_amt",&dTmp)){
        	hv_min_amt= dTmp;
DEBUGLOG(("GetDetailByCondition min_amt = [%lf]\n",hv_min_amt));
		ind_min_amt= 0;
	}

	if(GetField_Double(hTxn,"max_amt",&dTmp)){
        	hv_max_amt= dTmp;
DEBUGLOG(("GetDetailByCondition max_amt = [%lf]\n",hv_max_amt));
		ind_max_amt= 0;
	}
	
	if(GetField_CString(hTxn,"file_id",&csTmp)){
        	hv_file_id.len = strlen(csTmp);
        	memcpy(hv_file_id.arr,csTmp,hv_file_id.len);
DEBUGLOG(("GetDetailByCondition file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));
		ind_in_file_id= 0;
	}

	/* EXEC SQL ALLOCATE       :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2314;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}



        	/* EXEC SQL EXECUTE
                	BEGIN
                        	:hv_return_value := sp_ol_merch_upload_dt_get(
								:hv_batch_id:ind_in_batch_id,
								:hv_seq_num:ind_in_seq_num,
								:hv_bank_name:ind_in_bank_name,
								:hv_status:ind_in_status,
								:hv_min_amt:ind_min_amt,
								:hv_max_amt:ind_max_amt,
								:hv_file_id:ind_in_file_id,
								:c_cursor_dtcon);
                	END;
        	END-EXEC; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 36;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_get\
 ( :hv_batch_id:ind_in_batch_id , :hv_seq_num:ind_in_seq_num , :hv_bank_name:\
ind_in_bank_name , :hv_status:ind_in_status , :hv_min_amt:ind_min_amt , :hv_m\
ax_amt:ind_max_amt , :hv_file_id:ind_in_file_id , :c_cursor_dtcon ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2333;
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
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
         sqlstm.sqhstl[1] = (unsigned long )18;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_in_batch_id;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq_num;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_in_seq_num;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_name;
         sqlstm.sqhstl[3] = (unsigned long )152;
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)&ind_in_bank_name;
         sqlstm.sqinds[3] = (         int  )0;
         sqlstm.sqharm[3] = (unsigned long )0;
         sqlstm.sqadto[3] = (unsigned short )0;
         sqlstm.sqtdso[3] = (unsigned short )0;
         sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
         sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[4] = (         int  )0;
         sqlstm.sqindv[4] = (         short *)&ind_in_status;
         sqlstm.sqinds[4] = (         int  )0;
         sqlstm.sqharm[4] = (unsigned long )0;
         sqlstm.sqadto[4] = (unsigned short )0;
         sqlstm.sqtdso[4] = (unsigned short )0;
         sqlstm.sqhstv[5] = (unsigned char  *)&hv_min_amt;
         sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[5] = (         int  )0;
         sqlstm.sqindv[5] = (         short *)&ind_min_amt;
         sqlstm.sqinds[5] = (         int  )0;
         sqlstm.sqharm[5] = (unsigned long )0;
         sqlstm.sqadto[5] = (unsigned short )0;
         sqlstm.sqtdso[5] = (unsigned short )0;
         sqlstm.sqhstv[6] = (unsigned char  *)&hv_max_amt;
         sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
         sqlstm.sqhsts[6] = (         int  )0;
         sqlstm.sqindv[6] = (         short *)&ind_max_amt;
         sqlstm.sqinds[6] = (         int  )0;
         sqlstm.sqharm[6] = (unsigned long )0;
         sqlstm.sqadto[6] = (unsigned short )0;
         sqlstm.sqtdso[6] = (unsigned short )0;
         sqlstm.sqhstv[7] = (unsigned char  *)&hv_file_id;
         sqlstm.sqhstl[7] = (unsigned long )18;
         sqlstm.sqhsts[7] = (         int  )0;
         sqlstm.sqindv[7] = (         short *)&ind_in_file_id;
         sqlstm.sqinds[7] = (         int  )0;
         sqlstm.sqharm[7] = (unsigned long )0;
         sqlstm.sqadto[7] = (unsigned short )0;
         sqlstm.sqtdso[7] = (unsigned short )0;
         sqlstm.sqhstv[8] = (unsigned char  *)&c_cursor_dtcon;
         sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
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
         if (sqlca.sqlcode < 0) goto getdt_con_error;
}






	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
		iRet = PD_FOUND;
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_batch_id = -1;
			ind_seq_num = -1;
			ind_merchant_id = -1;
			ind_service_code= -1;
			ind_txn_id = -1;
			ind_merchant_ref = -1;
			ind_country = -1;
			ind_identity_id = -1;
			ind_account_num = -1;
			ind_account_name = -1;
			ind_bank_name = -1;
			ind_bank_code = -1;
			ind_branch = -1;
			ind_phone_num = -1;
			ind_province = -1;
			ind_city = -1;
			ind_payout_ccy = -1;
			ind_request_ccy = -1;
			ind_member_fee_ccy = -1;
			ind_merchant_fee_ccy = -1;
			ind_markup_ccy = -1;
			ind_payout_amount = -1;
			ind_request_amount = -1;
			ind_member_fee = -1;
			ind_merchant_fee = -1;
			ind_markup_amt = -1;
			ind_ex_rate = -1;
			ind_status = -1;
			ind_resp_code = -1;
			ind_remark = -1;
			ind_batch_mode = -1;
			ind_file_name = -1;
			ind_psp_batch_id = -1;
			ind_psp_id = -1;
			ind_fundout_date = -1;
			ind_service_fee = -1;
			ind_file_id = -1;
			ind_approve_id = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dtcon
                        INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_member_fee_ccy:ind_member_fee_ccy,
				:v_member_fee:ind_member_fee,
				:v_merchant_fee_ccy:ind_merchant_fee_ccy,
				:v_merchant_fee:ind_merchant_fee,
				:v_markup_ccy:ind_markup_ccy,
				:v_markup_amt:ind_markup_amt,
				:v_ex_rate:ind_ex_rate,
				:v_status:ind_status,
				:v_resp_code:ind_resp_code,
				:v_remark:ind_remark,
				:v_batch_mode:ind_batch_mode,
				:v_file_name:ind_file_name,
				:v_psp_batch_id:ind_psp_batch_id,
				:v_fundout_date:ind_fundout_date,
				:v_service_fee:ind_service_fee,
				:v_psp_id:ind_psp_id,
				:v_file_id:ind_file_id,
				:v_approve_id:ind_approve_id,
				:v_merchant_id:ind_merchant_id,
				:v_service_code:ind_service_code; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )2384;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[3] = (unsigned long )19;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_country;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[7] = (unsigned long )28;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_account_num;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[8] = (unsigned long )103;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_account_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[10] = (unsigned long )13;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[11] = (unsigned long )153;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_branch;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[12] = (unsigned long )28;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[13] = (unsigned long )103;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_province;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[14] = (unsigned long )103;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_city;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[17] = (unsigned long )6;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_member_fee_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_member_fee;
                        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_member_fee;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_ccy;
                        sqlstm.sqhstl[23] = (unsigned long )6;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_markup_ccy;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_status;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_resp_code;
                        sqlstm.sqhstl[27] = (unsigned long )13;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_resp_code;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[28] = (unsigned long )258;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_remark;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[29] = (unsigned long )1;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[30] = (unsigned long )53;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_file_name;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_psp_batch_id;
                        sqlstm.sqhstl[31] = (unsigned long )23;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_psp_batch_id;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_fundout_date;
                        sqlstm.sqhstl[32] = (unsigned long )17;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_fundout_date;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
                        sqlstm.sqhstv[34] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[34] = (unsigned long )13;
                        sqlstm.sqhsts[34] = (         int  )0;
                        sqlstm.sqindv[34] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[34] = (         int  )0;
                        sqlstm.sqharm[34] = (unsigned long )0;
                        sqlstm.sqadto[34] = (unsigned short )0;
                        sqlstm.sqtdso[34] = (unsigned short )0;
                        sqlstm.sqhstv[35] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[35] = (unsigned long )19;
                        sqlstm.sqhsts[35] = (         int  )0;
                        sqlstm.sqindv[35] = (         short *)&ind_file_id;
                        sqlstm.sqinds[35] = (         int  )0;
                        sqlstm.sqharm[35] = (unsigned long )0;
                        sqlstm.sqadto[35] = (unsigned short )0;
                        sqlstm.sqtdso[35] = (unsigned short )0;
                        sqlstm.sqhstv[36] = (unsigned char  *)&v_approve_id;
                        sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[36] = (         int  )0;
                        sqlstm.sqindv[36] = (         short *)&ind_approve_id;
                        sqlstm.sqinds[36] = (         int  )0;
                        sqlstm.sqharm[36] = (unsigned long )0;
                        sqlstm.sqadto[36] = (unsigned short )0;
                        sqlstm.sqtdso[36] = (unsigned short )0;
                        sqlstm.sqhstv[37] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[37] = (unsigned long )18;
                        sqlstm.sqhsts[37] = (         int  )0;
                        sqlstm.sqindv[37] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[37] = (         int  )0;
                        sqlstm.sqharm[37] = (unsigned long )0;
                        sqlstm.sqadto[37] = (unsigned short )0;
                        sqlstm.sqtdso[37] = (unsigned short )0;
                        sqlstm.sqhstv[38] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[38] = (unsigned long )6;
                        sqlstm.sqhsts[38] = (         int  )0;
                        sqlstm.sqindv[38] = (         short *)&ind_service_code;
                        sqlstm.sqinds[38] = (         int  )0;
                        sqlstm.sqharm[38] = (unsigned long )0;
                        sqlstm.sqadto[38] = (unsigned short )0;
                        sqlstm.sqtdso[38] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdt_con_error;
}





/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByCondition seq_num=[%d]\n",v_seq_num));
			}

/*batch_id*/
			if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetDetailByCondition batch_id=[%s]\n",v_batch_id.arr));
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
				PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
//DEBUGLOG(("GetDetailByCondition merchant_id=[%s]\n",v_merchant_id.arr));
			}

/*service_code*/
			if(ind_service_code>=0){
				v_service_code.arr[v_service_code.len]='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
//DEBUGLOG(("GetDetailByCondition service_code=[%s]\n",v_service_code.arr));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByCondition txn_id=[%s]\n",v_txn_id.arr));
			}

/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
//DEBUGLOG(("GetDetailByCondition merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*country*/
			if(ind_country>=0){
				v_country.arr[v_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByCondition country= [%s]\n",v_country.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
//DEBUGLOG(("GetDetailByCondition identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
//DEBUGLOG(("GetDetailByCondition account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
//DEBUGLOG(("GetDetailByCondition account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
//DEBUGLOG(("GetDetailByCondition bank_name= [%s]\n",v_bank_name.arr));
			}

/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
//DEBUGLOG(("GetDetailByCondition bank_code= [%s]\n",v_bank_code.arr));
			}

/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
//DEBUGLOG(("GetDetailByCondition branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
//DEBUGLOG(("GetDetailByCondition phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
//DEBUGLOG(("GetDetailByCondition province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
//DEBUGLOG(("GetDetailByCondition city= [%s]\n",v_city.arr));
			}

/*payout_currency*/
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
//DEBUGLOG(("GetDetailByCondition payout_ccy= [%s]\n",v_payout_ccy.arr));
			}

/*request_currency*/
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
//DEBUGLOG(("GetDetailByCondition request_ccy= [%s]\n",v_request_ccy.arr));
			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
//DEBUGLOG(("GetDetailByCondition payout_amount = [%lf]\n",v_payout_amount));
			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByCondition request_amount = [%lf]\n",v_request_amount));
			}

/*member_fee_ccy*/
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
//DEBUGLOG(("GetDetailByCondition member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
//DEBUGLOG(("GetDetailByCondition member_fee = [%lf]\n",v_member_fee));
			}

/*merchant_fee_ccy*/
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
//DEBUGLOG(("GetDetailByCondition merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
			}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
//DEBUGLOG(("GetDetailByCondition merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*markup_ccy*/
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
//DEBUGLOG(("GetDetailByCondition markup_ccy= [%s]\n",v_markup_ccy.arr));
			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
//DEBUGLOG(("GetDetailByCondition markup_amt = [%lf]\n",v_markup_amt));
			}

/*ex_rate*/
			if(ind_ex_rate>=0){
				PutField_Double(myHash,"ex_rate",v_ex_rate);
//DEBUGLOG(("GetDetailByCondition ex_rate = [%lf]\n",v_ex_rate));
			}

/*status*/
			if(ind_status>=0){
				PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetailByCondition status = [%d]\n",v_status));
			}

/*resp_code*/
			if(ind_resp_code>=0){
				v_resp_code.arr[v_resp_code.len]='\0';
				PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
//DEBUGLOG(("GetDetailByCondition resp_code= [%s]\n",v_resp_code.arr));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
//DEBUGLOG(("GetDetailByCondition remark= [%s]\n",v_remark.arr));
			}

/*file_name*/
			if(ind_file_name>=0){
				v_file_name.arr[v_file_name.len]='\0';
				PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
//DEBUGLOG(("GetDetailByCondition file_name= [%s]\n",v_file_name.arr));
			}

/*psp_batch_id*/	
			if(ind_psp_batch_id>=0){
				v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
				PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
//DEBUGLOG(("GetDetailByCondition psp_batch_id= [%s]\n",v_psp_batch_id.arr));
			}

/*fundout_date*/
			if(ind_fundout_date>=0){
				v_fundout_date.arr[v_fundout_date.len]='\0';
				PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
//DEBUGLOG(("GetDetailByCondition fundout_date= [%s]\n",v_fundout_date.arr));
			}

/*service_fee*/
			if(ind_service_fee>=0){
				PutField_Double(myHash,"service_fee",v_service_fee);
//DEBUGLOG(("GetDetailByCondition service_fee= [%lf]\n",v_service_fee));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
//DEBUGLOG(("GetDetailByCondition psp_id= [%s]\n",v_psp_id.arr));
			}

/*file_id*/	
			if(ind_file_id>=0){
				v_file_id.arr[v_file_id.len]='\0';
				PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
//DEBUGLOG(("GetDetailByCondition file_id= [%s]\n",v_file_id.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
//DEBUGLOG(("GetDetailByCondition batch_mode= [%c]\n",v_batch_mode));
			}

/*approve_id*/
			if(ind_approve_id>=0){
				PutField_Int(myHash,"approve_id",v_approve_id);
//DEBUGLOG(("GetDetailByCondition approve_id= [%lf]\n",v_approve_id));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2555;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}


	/* EXEC SQL FREE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2574;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}



DEBUGLOG(("GetDetailByCondition Normal Exit [%d]\n",iRet));
	return  iRet;

getdt_con_error:
DEBUGLOG(("getdt_con_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DBOLMerchantUploadFileDetail GetDetailByCondition: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2593;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	/* EXEC SQL FREE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2612;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;
}

int GetNextApproveId(int *iApproveId)
{
        int iRet = PD_OK;
        *iApproveId = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO GetNextApproveId_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             v_app_id;

                short           ind_app_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT max(oud_approve_id)
                INTO    :v_app_id:ind_app_id
                FROM    ol_merchant_upload_file_detail
		WHERE	oud_approve_id is NOT NULL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max ( oud_approve_id ) INTO :b0:b1 FROM ol_me\
rchant_upload_file_detail WHERE oud_approve_id is NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2631;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_app_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_app_id;
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
        if (sqlca.sqlcode < 0) goto GetNextApproveId_error;
}



        if(ind_app_id>=0){
                *iApproveId = v_app_id+1;
DEBUGLOG(("GetNextApproveId Found [%d]\n",*iApproveId));
        }
        else {
DEBUGLOG(("GetNextApproveId Start by 1\n"));
                *iApproveId = 1;
        }

        return iRet;

GetNextApproveId_error:
DEBUGLOG(("GetNextApproveId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetNextPreApproveId(int *iApproveId)
{
        int iRet = PD_OK;
        *iApproveId = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO GetNextPreApproveId_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             v_app_id;

                short           ind_app_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT max(oud_preapprove_id)
                INTO    :v_app_id:ind_app_id
                FROM    ol_merchant_upload_file_detail
		WHERE	oud_preapprove_id is NOT NULL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max ( oud_preapprove_id ) INTO :b0:b1 FROM ol\
_merchant_upload_file_detail WHERE oud_preapprove_id is NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2650;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_app_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_app_id;
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
        if (sqlca.sqlcode < 0) goto GetNextPreApproveId_error;
}



        if(ind_app_id>=0){
                *iApproveId = v_app_id+1;
DEBUGLOG(("GetNextPreApproveId Found [%d]\n",*iApproveId));
        }
        else {
DEBUGLOG(("GetNextPreApproveId Start by 1\n"));
                *iApproveId = 1;
        }

        return iRet;

GetNextPreApproveId_error:
DEBUGLOG(("GetNextPreApproveId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int	ResumeUnusedPreApproveId(const int iApproveId)
{
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO resume_pre_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeUnusedPreApproveId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_preapprove_id ='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
        strcat((char*)hv_dynstmt.arr, " WHERE oud_status = 69 and oud_batch_mode = 'F' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("ResumeUnusedPreApproveId: pre_approve_id < [%d]\n",iApproveId));
	sprintf(csBuf,"%d",iApproveId);
	strcat((char*)hv_dynstmt.arr, "and oud_preapprove_id < ");
	strcat((char*)hv_dynstmt.arr, csBuf);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2669;
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
 if (sqlca.sqlcode < 0) goto resume_pre_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2688;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto resume_pre_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("ResumeUnusedPreApproveId Normal Exit\n"));
        return PD_OK;

resume_pre_error:
DEBUGLOG(("resume_pre_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_ResumeUnusedPreApproveId: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int GetDetailByPreApproveId(const int iPreApproveId, recordset_t* myRec)
{
	hash_t *myHash;
	//char	*csTmp;
	//int	iTmp;
	//double	dTmp;
	int	iRet = PD_NOT_FOUND;
	/* EXEC SQL WHENEVER SQLERROR GOTO getdt_con_pre_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		int		hv_in_status;
		int		hv_pre_approve_id;
		
		SQL_CURSOR      c_cursor_dtcon_pre;

		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int	        v_seq_num;
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		int		v_status;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;
		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int	        v_approve_id;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_id = -1;
		short           ind_service_code = -1;
		short           ind_txn_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_status = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_file_id = -1;
		short           ind_approve_id = -1;

		short           ind_in_status= -1;
		short           ind_pre_approve_id= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        hv_pre_approve_id = iPreApproveId;
	ind_pre_approve_id= 0;
DEBUGLOG(("GetDetailByPreApproveId pre_approve_id = [%d]\n",hv_pre_approve_id));

        hv_in_status= PAYOUT_MASTER_TRANSACTION_CONFIRMED;
	ind_in_status= 0;
DEBUGLOG(("GetDetailByPreApproveId status = [%d]\n",hv_in_status));

	/* EXEC SQL ALLOCATE       :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2703;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_pre_error;
}



        	/* EXEC SQL EXECUTE
                	BEGIN
                        	:hv_return_value := sp_ol_merch_upload_get_pre_ap(
								:hv_pre_approve_id:ind_pre_approve_id,
								:hv_in_status:ind_in_status,
								:c_cursor_dtcon_pre);
                	END;
        	END-EXEC; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 39;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_get_pr\
e_ap ( :hv_pre_approve_id:ind_pre_approve_id , :hv_in_status:ind_in_status , \
:c_cursor_dtcon_pre ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2722;
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
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_pre_approve_id;
         sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_pre_approve_id;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_in_status;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_in_status;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_dtcon_pre;
         sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[3] = (         int  )0;
         sqlstm.sqindv[3] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getdt_con_pre_error;
}






	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
		iRet = PD_FOUND;
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_batch_id = -1;
			ind_seq_num = -1;
			ind_merchant_id = -1;
			ind_service_code= -1;
			ind_txn_id = -1;
			ind_merchant_ref = -1;
			ind_country = -1;
			ind_identity_id = -1;
			ind_account_num = -1;
			ind_account_name = -1;
			ind_bank_name = -1;
			ind_bank_code = -1;
			ind_branch = -1;
			ind_phone_num = -1;
			ind_province = -1;
			ind_city = -1;
			ind_payout_ccy = -1;
			ind_request_ccy = -1;
			ind_member_fee_ccy = -1;
			ind_merchant_fee_ccy = -1;
			ind_markup_ccy = -1;
			ind_payout_amount = -1;
			ind_request_amount = -1;
			ind_member_fee = -1;
			ind_merchant_fee = -1;
			ind_markup_amt = -1;
			ind_ex_rate = -1;
			ind_status = -1;
			ind_resp_code = -1;
			ind_remark = -1;
			ind_batch_mode = -1;
			ind_file_name = -1;
			ind_psp_batch_id = -1;
			ind_psp_id = -1;
			ind_fundout_date = -1;
			ind_service_fee = -1;
			ind_file_id = -1;
			ind_approve_id = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dtcon_pre
                        INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_member_fee_ccy:ind_member_fee_ccy,
				:v_member_fee:ind_member_fee,
				:v_merchant_fee_ccy:ind_merchant_fee_ccy,
				:v_merchant_fee:ind_merchant_fee,
				:v_markup_ccy:ind_markup_ccy,
				:v_markup_amt:ind_markup_amt,
				:v_ex_rate:ind_ex_rate,
				:v_status:ind_status,
				:v_resp_code:ind_resp_code,
				:v_remark:ind_remark,
				:v_batch_mode:ind_batch_mode,
				:v_file_name:ind_file_name,
				:v_psp_batch_id:ind_psp_batch_id,
				:v_fundout_date:ind_fundout_date,
				:v_service_fee:ind_service_fee,
				:v_psp_id:ind_psp_id,
				:v_file_id:ind_file_id,
				:v_approve_id:ind_approve_id,
				:v_merchant_id:ind_merchant_id,
				:v_service_code:ind_service_code; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )2753;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[3] = (unsigned long )19;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_country;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[7] = (unsigned long )28;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_account_num;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[8] = (unsigned long )103;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_account_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[10] = (unsigned long )13;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[11] = (unsigned long )153;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_branch;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[12] = (unsigned long )28;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[13] = (unsigned long )103;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_province;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[14] = (unsigned long )103;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_city;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[17] = (unsigned long )6;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_member_fee_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_member_fee;
                        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_member_fee;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_ccy;
                        sqlstm.sqhstl[23] = (unsigned long )6;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_markup_ccy;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_status;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_resp_code;
                        sqlstm.sqhstl[27] = (unsigned long )13;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_resp_code;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[28] = (unsigned long )258;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_remark;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[29] = (unsigned long )1;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[30] = (unsigned long )53;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_file_name;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_psp_batch_id;
                        sqlstm.sqhstl[31] = (unsigned long )23;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_psp_batch_id;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_fundout_date;
                        sqlstm.sqhstl[32] = (unsigned long )17;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_fundout_date;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
                        sqlstm.sqhstv[34] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[34] = (unsigned long )13;
                        sqlstm.sqhsts[34] = (         int  )0;
                        sqlstm.sqindv[34] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[34] = (         int  )0;
                        sqlstm.sqharm[34] = (unsigned long )0;
                        sqlstm.sqadto[34] = (unsigned short )0;
                        sqlstm.sqtdso[34] = (unsigned short )0;
                        sqlstm.sqhstv[35] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[35] = (unsigned long )19;
                        sqlstm.sqhsts[35] = (         int  )0;
                        sqlstm.sqindv[35] = (         short *)&ind_file_id;
                        sqlstm.sqinds[35] = (         int  )0;
                        sqlstm.sqharm[35] = (unsigned long )0;
                        sqlstm.sqadto[35] = (unsigned short )0;
                        sqlstm.sqtdso[35] = (unsigned short )0;
                        sqlstm.sqhstv[36] = (unsigned char  *)&v_approve_id;
                        sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[36] = (         int  )0;
                        sqlstm.sqindv[36] = (         short *)&ind_approve_id;
                        sqlstm.sqinds[36] = (         int  )0;
                        sqlstm.sqharm[36] = (unsigned long )0;
                        sqlstm.sqadto[36] = (unsigned short )0;
                        sqlstm.sqtdso[36] = (unsigned short )0;
                        sqlstm.sqhstv[37] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[37] = (unsigned long )18;
                        sqlstm.sqhsts[37] = (         int  )0;
                        sqlstm.sqindv[37] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[37] = (         int  )0;
                        sqlstm.sqharm[37] = (unsigned long )0;
                        sqlstm.sqadto[37] = (unsigned short )0;
                        sqlstm.sqtdso[37] = (unsigned short )0;
                        sqlstm.sqhstv[38] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[38] = (unsigned long )6;
                        sqlstm.sqhsts[38] = (         int  )0;
                        sqlstm.sqindv[38] = (         short *)&ind_service_code;
                        sqlstm.sqinds[38] = (         int  )0;
                        sqlstm.sqharm[38] = (unsigned long )0;
                        sqlstm.sqadto[38] = (unsigned short )0;
                        sqlstm.sqtdso[38] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdt_con_pre_error;
}





/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByPreApproveId seq_num=[%d]\n",v_seq_num));
			}

/*batch_id*/
			if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetDetailByPreApproveId batch_id=[%s]\n",v_batch_id.arr));
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
				PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
//DEBUGLOG(("GetDetailByPreApproveId merchant_id=[%s]\n",v_merchant_id.arr));
			}

/*service_code*/
			if(ind_service_code>=0){
				v_service_code.arr[v_service_code.len]='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
//DEBUGLOG(("GetDetailByPreApproveId service_code=[%s]\n",v_service_code.arr));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByPreApproveId txn_id=[%s]\n",v_txn_id.arr));
			}

/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
//DEBUGLOG(("GetDetailByPreApproveId merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*country*/
			if(ind_country>=0){
				v_country.arr[v_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
//DEBUGLOG(("GetDetailByPreApproveId country= [%s]\n",v_country.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
//DEBUGLOG(("GetDetailByPreApproveId identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
//DEBUGLOG(("GetDetailByPreApproveId account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
//DEBUGLOG(("GetDetailByPreApproveId account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
//DEBUGLOG(("GetDetailByPreApproveId bank_name= [%s]\n",v_bank_name.arr));
			}

/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
//DEBUGLOG(("GetDetailByPreApproveId bank_code= [%s]\n",v_bank_code.arr));
			}

/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
//DEBUGLOG(("GetDetailByPreApproveId branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
//DEBUGLOG(("GetDetailByPreApproveId phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
//DEBUGLOG(("GetDetailByPreApproveId province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
//DEBUGLOG(("GetDetailByPreApproveId city= [%s]\n",v_city.arr));
			}

/*payout_currency*/
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
//DEBUGLOG(("GetDetailByPreApproveId payout_ccy= [%s]\n",v_payout_ccy.arr));
			}

/*request_currency*/
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
//DEBUGLOG(("GetDetailByPreApproveId request_ccy= [%s]\n",v_request_ccy.arr));
			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
//DEBUGLOG(("GetDetailByPreApproveId payout_amount = [%lf]\n",v_payout_amount));
			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByPreApproveId request_amount = [%lf]\n",v_request_amount));
			}

/*member_fee_ccy*/
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
//DEBUGLOG(("GetDetailByPreApproveId member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
//DEBUGLOG(("GetDetailByPreApproveId member_fee = [%lf]\n",v_member_fee));
			}

/*merchant_fee_ccy*/
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
//DEBUGLOG(("GetDetailByPreApproveId merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
			}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
//DEBUGLOG(("GetDetailByPreApproveId merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*markup_ccy*/
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
//DEBUGLOG(("GetDetailByPreApproveId markup_ccy= [%s]\n",v_markup_ccy.arr));
			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
//DEBUGLOG(("GetDetailByPreApproveId markup_amt = [%lf]\n",v_markup_amt));
			}

/*ex_rate*/
			if(ind_ex_rate>=0){
				PutField_Double(myHash,"ex_rate",v_ex_rate);
//DEBUGLOG(("GetDetailByPreApproveId ex_rate = [%lf]\n",v_ex_rate));
			}

/*status*/
			if(ind_status>=0){
				PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetailByPreApproveId status = [%d]\n",v_status));
			}

/*resp_code*/
			if(ind_resp_code>=0){
				v_resp_code.arr[v_resp_code.len]='\0';
				PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
//DEBUGLOG(("GetDetailByPreApproveId resp_code= [%s]\n",v_resp_code.arr));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
//DEBUGLOG(("GetDetailByPreApproveId remark= [%s]\n",v_remark.arr));
			}

/*file_name*/
			if(ind_file_name>=0){
				v_file_name.arr[v_file_name.len]='\0';
				PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
//DEBUGLOG(("GetDetailByPreApproveId file_name= [%s]\n",v_file_name.arr));
			}

/*psp_batch_id*/	
			if(ind_psp_batch_id>=0){
				v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
				PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
//DEBUGLOG(("GetDetailByPreApproveId psp_batch_id= [%s]\n",v_psp_batch_id.arr));
			}

/*fundout_date*/
			if(ind_fundout_date>=0){
				v_fundout_date.arr[v_fundout_date.len]='\0';
				PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
//DEBUGLOG(("GetDetailByPreApproveId fundout_date= [%s]\n",v_fundout_date.arr));
			}

/*service_fee*/
			if(ind_service_fee>=0){
				PutField_Double(myHash,"service_fee",v_service_fee);
//DEBUGLOG(("GetDetailByPreApproveId service_fee= [%lf]\n",v_service_fee));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
//DEBUGLOG(("GetDetailByPreApproveId psp_id= [%s]\n",v_psp_id.arr));
			}

/*file_id*/	
			if(ind_file_id>=0){
				v_file_id.arr[v_file_id.len]='\0';
				PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
//DEBUGLOG(("GetDetailByPreApproveId file_id= [%s]\n",v_file_id.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
//DEBUGLOG(("GetDetailByPreApproveId batch_mode= [%c]\n",v_batch_mode));
			}

/*approve_id*/
			if(ind_approve_id>=0){
				PutField_Int(myHash,"approve_id",v_approve_id);
//DEBUGLOG(("GetDetailByPreApproveId approve_id= [%lf]\n",v_approve_id));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2924;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_pre_error;
}


	/* EXEC SQL FREE :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2943;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdt_con_pre_error;
}



DEBUGLOG(("GetDetailByPreApproveId Normal Exit [%d]\n",iRet));
	return  iRet;

getdt_con_pre_error:
DEBUGLOG(("getdt_con_pre_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DBOLMerchantUploadFileDetail GetDetailByPreApproveId: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2962;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	/* EXEC SQL FREE :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2981;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon_pre;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;
}

int UpdateFileNameByFileId(const hash_t *hRls)
{
	char*   csBuf;
	char*	csFileId;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatefilenamebyid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateFileNameByFileId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
        if(GetField_CString(hRls,"file_id",&csFileId)){
DEBUGLOG(("UpdateFileNameByFileId: generated_file_id = [%s]\n",csFileId));
        }

        if(GetField_CString(hRls,"generated_file_name",&csBuf)){
DEBUGLOG(("UpdateFileNameByFileId: generated_file_name = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, " oud_generated_file_name = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE oud_generated_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3000;
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
 if (sqlca.sqlcode < 0) goto updatefilenamebyid_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3019;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatefilenamebyid_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateFileNameByFileId Normal Exit\n"));
        return PD_OK;

updatefilenamebyid_error:
DEBUGLOG(("updatefilenamebyid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_UpdateFileNameByFileId: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int GetDetailByRandomWithPara(const hash_t *hTxn,recordset_t* myRec)
{
	hash_t	*myHash;
	char	*csTmp;
	char	csTag[PD_TAG_LEN+1];
	char	csBatchId[PD_TXN_SEQ_LEN+1];
	int	i = 0;
	int	iBatchCnt = 0;
	char	cTmp;
	int	iTmp = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailwp_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;
		
		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_batch_id_list[2048]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_batch_id_list;

		/* varchar		hv_in_bank_name[PD_BANK_NAME_LEN+3]; */ 
struct { unsigned short len; unsigned char arr[153]; } hv_in_bank_name;

		int		hv_status;
		char		hv_in_batch_mode;
		char		hv_in_psp_grp;
		char		hv_in_merch_grp;

		short           ind_merchant_id= -1;
		short           ind_batch_id_list= -1;
		short           ind_in_bank_name= -1;
		short           ind_status= -1;
		short           ind_in_batch_mode= -1;
		short           ind_in_psp_grp= -1;
		short           ind_in_merch_grp= -1;

		SQL_CURSOR      c_cursor_dt_random;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		unsigned long   v_batch_id;
		int	        v_seq_num;
		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		double		v_service_fee;
		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		char		v_merch_grp;
		char		v_psp_grp;

		short           ind_txn_id = -1;
		short           ind_seq_num = -1;
		short           ind_batch_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short		ind_bank_name = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode = -1;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_psp_id = -1;
		short           ind_merch_grp = -1;
		short           ind_psp_grp = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_in_batch_mode = PD_OFFLINE;
	ind_in_batch_mode = 0;

	if(GetField_Int(hTxn,"status",&iTmp)){
		hv_status = iTmp;
	}
	else{
		hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
	}
	ind_status = 0;
DEBUGLOG(("GetDetailByRandomWithPara status = [%d]\n",hv_status));

	if(GetField_CString(hTxn,"merchant_id",&csTmp)){
        	hv_merchant_id.len = strlen(csTmp);
        	memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
		ind_merchant_id= 0;
DEBUGLOG(("GetDetailByRandomWithPara merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hTxn,"bank_name",&csTmp)){
		char    csTmpBank[strlen(csTmp)+3];
		hv_in_bank_name.len = strlen(csTmp)+2;
		strcpy(csTmpBank,"%");
		strcat(csTmpBank,csTmp);
		strcat(csTmpBank,"%");
		csTmpBank[strlen(csTmp)+2]='\0';
		memcpy(hv_in_bank_name.arr,csTmpBank,hv_in_bank_name.len);
		ind_in_bank_name= 0;
DEBUGLOG(("GetDetailByRandomWithPara bank_name = [%.*s]\n",hv_in_bank_name.len,hv_in_bank_name.arr));
	}

	if(GetField_Char(hTxn,"merchant_group",&cTmp)){
        	hv_in_merch_grp = cTmp;
		ind_in_merch_grp= 0;
DEBUGLOG(("GetDetailByRandomWithPara merchant_group = [%c]\n",hv_in_merch_grp));
	}

	if(GetField_Char(hTxn,"psp_group",&cTmp)){
        	hv_in_psp_grp = cTmp;
		ind_in_psp_grp= 0;
DEBUGLOG(("GetDetailByRandomWithPara psp_group = [%c]\n",hv_in_psp_grp));
	}

	if(GetField_Int(hTxn,"batch_cnt",&iBatchCnt)){
DEBUGLOG(("GetDetailByRandomWithPara batch_cnt = [%d]\n",iBatchCnt));
	}

	hv_batch_id_list.arr[0] = '\0';
	hv_batch_id_list.len = 0;

	for(i=0; i<iBatchCnt; i++){
		sprintf(csTag,"batch_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(i>0) strcat((char*)hv_batch_id_list.arr, ",");
			strcat((char*)hv_batch_id_list.arr, csTmp);
			hv_batch_id_list.len = strlen((const char*)hv_batch_id_list.arr);
			ind_batch_id_list = 0;
		}
	}

	if(iBatchCnt>0){
DEBUGLOG(("GetDetailByRandomWithPara batch_id_list = [%.*s]\n",hv_batch_id_list.len,hv_batch_id_list.arr));
	}

	/* EXEC SQL ALLOCATE       :c_cursor_dt_random; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3034;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailwp_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_merch_upload_dt_random(
                                                                :hv_merchant_id:ind_merchant_id,
                                                                :hv_batch_id_list:ind_batch_id_list,
                                                                :hv_in_bank_name:ind_in_bank_name,
                                                                :hv_status:ind_status,
                                                                :hv_in_batch_mode:ind_in_batch_mode,
                                                                :hv_in_merch_grp:ind_in_merch_grp,
                                                                :hv_in_psp_grp:ind_in_psp_grp,
                                                                :c_cursor_dt_random);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_random ( :h\
v_merchant_id:ind_merchant_id , :hv_batch_id_list:ind_batch_id_list , :hv_in_\
bank_name:ind_in_bank_name , :hv_status:ind_status , :hv_in_batch_mode:ind_in\
_batch_mode , :hv_in_merch_grp:ind_in_merch_grp , :hv_in_psp_grp:ind_in_psp_g\
rp , :c_cursor_dt_random ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3053;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id_list;
 sqlstm.sqhstl[2] = (unsigned long )2050;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_batch_id_list;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_in_bank_name;
 sqlstm.sqhstl[3] = (unsigned long )155;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_in_bank_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_status;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_in_batch_mode;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_in_batch_mode;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_in_merch_grp;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_in_merch_grp;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_in_psp_grp;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_in_psp_grp;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&c_cursor_dt_random;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailwp_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_batch_id = -1;
                        ind_seq_num = -1;
                        ind_merchant_id = -1;
                        ind_txn_id = -1;
                        ind_aux_txn_seq = -1;
                        ind_merchant_ref = -1;
                        ind_country = -1;
                        ind_identity_id = -1;
                        ind_account_num = -1;
                        ind_account_name = -1;
                        ind_bank_name = -1;
                        ind_branch = -1;
                        ind_phone_num = -1;
                        ind_province = -1;
                        ind_city = -1;
                        ind_payout_ccy = -1;
                        ind_request_ccy = -1;
                        ind_member_fee_ccy = -1;
                        ind_merchant_fee_ccy = -1;
                        ind_markup_ccy = -1;
                        ind_payout_amount = -1;
                        ind_request_amount = -1;
                        ind_member_fee = -1;
                        ind_merchant_fee = -1;
                        ind_markup_amt = -1;
                        ind_ex_rate = -1;
                        ind_resp_code = -1;
			ind_remark = -1;
                        ind_file_name = -1;
                        ind_psp_batch_id = -1;
                        ind_psp_id = -1;
                        ind_fundout_date = -1;
                        ind_service_fee = -1;
                        ind_merch_grp = -1;
                        ind_psp_grp = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dt_random
                        INTO

			:v_txn_id:ind_txn_id,
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_branch:ind_branch,
			:v_phone_num:ind_phone_num,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_payout_amount:ind_payout_amount,
			:v_request_amount:ind_request_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_request_ccy:ind_request_ccy,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_ex_rate:ind_ex_rate,
			:v_resp_code:ind_resp_code,
			:v_remark:ind_remark,
			:v_batch_mode:ind_batch_mode,
			:v_file_name:ind_file_name,
			:v_psp_batch_id:ind_psp_batch_id,
			:v_fundout_date:ind_fundout_date,
			:v_service_fee:ind_service_fee,
			:v_merch_grp:ind_merch_grp,
			:v_psp_grp:ind_psp_grp; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )3104;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_aux_txn_seq;
                        sqlstm.sqhstl[4] = (unsigned long )19;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_aux_txn_seq;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[6] = (unsigned long )5;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_country;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[7] = (unsigned long )28;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[8] = (unsigned long )28;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_account_num;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[9] = (unsigned long )103;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_account_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[10] = (unsigned long )153;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[11] = (unsigned long )153;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_branch;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[12] = (unsigned long )28;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[13] = (unsigned long )103;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_province;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[14] = (unsigned long )103;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_city;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[17] = (unsigned long )6;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_member_fee_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_member_fee;
                        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_member_fee;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_ccy;
                        sqlstm.sqhstl[23] = (unsigned long )6;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_markup_ccy;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_resp_code;
                        sqlstm.sqhstl[26] = (unsigned long )13;
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_resp_code;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[27] = (unsigned long )258;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_remark;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[28] = (unsigned long )1;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[29] = (unsigned long )53;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_file_name;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_psp_batch_id;
                        sqlstm.sqhstl[30] = (unsigned long )23;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_psp_batch_id;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_fundout_date;
                        sqlstm.sqhstl[31] = (unsigned long )17;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_fundout_date;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_merch_grp;
                        sqlstm.sqhstl[33] = (unsigned long )1;
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_merch_grp;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
                        sqlstm.sqhstv[34] = (unsigned char  *)&v_psp_grp;
                        sqlstm.sqhstl[34] = (unsigned long )1;
                        sqlstm.sqhsts[34] = (         int  )0;
                        sqlstm.sqindv[34] = (         short *)&ind_psp_grp;
                        sqlstm.sqinds[34] = (         int  )0;
                        sqlstm.sqharm[34] = (unsigned long )0;
                        sqlstm.sqadto[34] = (unsigned short )0;
                        sqlstm.sqtdso[34] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdetailwp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}


/*batch_id*/
			if(ind_batch_id>=0){
				sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetDetailByRandomWithPara batch_id=[%ld]\n",v_batch_id));
				PutField_CString(myHash,"batch_id",csBatchId);
			}

/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByRandomWithPara seq_num=[%d]\n",v_seq_num));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByRandomWithPara txn_id=[%s]\n",v_txn_id.arr));
			}

/*aux_txn_seq*/
			if(ind_aux_txn_seq>=0){
				v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
				PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByRandomWithPara aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByRandomWithPara merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*country*/
			if(ind_country>=0){
				v_country.arr[v_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByRandomWithPara country= [%s]\n",v_country.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByRandomWithPara identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByRandomWithPara account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByRandomWithPara account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByRandomWithPara bank_name= [%s]\n",v_bank_name.arr));
			}


/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByRandomWithPara branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByRandomWithPara phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByRandomWithPara province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByRandomWithPara city= [%s]\n",v_city.arr));
			}

/*payout_currency*/
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithPara payout_ccy= [%s]\n",v_payout_ccy.arr));
			}

/*request_currency*/
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithPara request_ccy= [%s]\n",v_request_ccy.arr));
			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByRandomWithPara payout_amount = [%lf]\n",v_payout_amount));
			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByRandomWithPara request_amount = [%lf]\n",v_request_amount));
			}

/*member_fee_ccy*/
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithPara member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByRandomWithPara member_fee = [%lf]\n",v_member_fee));
			}

/*merchant_fee_ccy*/
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithPara merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByRandomWithPara merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*markup_ccy*/
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithPara markup_ccy= [%s]\n",v_markup_ccy.arr));
			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByRandomWithPara markup_amt = [%lf]\n",v_markup_amt));
			}

/*ex_rate*/
			if(ind_ex_rate>=0){
				PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByRandomWithPara ex_rate = [%lf]\n",v_ex_rate));
			}

/*resp_code*/
			if(ind_resp_code>=0){
				v_resp_code.arr[v_resp_code.len]='\0';
				PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByRandomWithPara resp_code= [%s]\n",v_resp_code.arr));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByRandomWithPara remark= [%s]\n",v_remark.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByRandomWithPara batch_mode= [%c]\n",v_batch_mode));
			}

/*file_name*/
			if(ind_file_name>=0){
				v_file_name.arr[v_file_name.len]='\0';
				PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByRandomWithPara file_name= [%s]\n",v_file_name.arr));
			}

/*psp_batch_id*/	
			if(ind_psp_batch_id>=0){
				v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
				PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByRandomWithPara psp_batch_id= [%s]\n",v_psp_batch_id.arr));
			}

/*fundout_date*/
			if(ind_fundout_date>=0){
				v_fundout_date.arr[v_fundout_date.len]='\0';
				PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByRandomWithPara fundout_date= [%s]\n",v_fundout_date.arr));
			}

/*service_fee*/
			if(ind_service_fee>=0){
				PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByRandomWithPara service_fee= [%lf]\n",v_service_fee));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByRandomWithPara psp_id= [%s]\n",v_psp_id.arr));
			}

/*merchant_group*/
			if(ind_merch_grp>=0){
				PutField_Char(myHash,"merchant_group",v_merch_grp);
DEBUGLOG(("GetDetailByRandomWithPara merchant_group= [%c]\n",v_merch_grp));
			}

/*psp_group*/
			if(ind_psp_grp>=0){
				PutField_Char(myHash,"psp_group",v_psp_grp);
DEBUGLOG(("GetDetailByRandomWithPara psp_group= [%c]\n",v_psp_grp));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dt_random; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3259;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailwp_error;
}


        /* EXEC SQL FREE :c_cursor_dt_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3278;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getdetailwp_error;
}



DEBUGLOG(("GetDetailByRandomWithPara Normal Exit\n"));
	return  PD_OK;

getdetailwp_error:
DEBUGLOG(("getdetailwp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_GetWithBankByRandomWithPara: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dt_random; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3297;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        /* EXEC SQL FREE :c_cursor_dt_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3316;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;

}


int	MatchUploadTxn(const hash_t *hRls)
{
	char            *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO matchup_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;


		int		v_cnt;
		short		ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hRls,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
DEBUGLOG(("MatchUploadTxn:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

        if(GetField_CString(hRls,"merchant_ref",&csTmp)){
                hv_merchant_ref.len = strlen(csTmp);
                memcpy(hv_merchant_ref.arr, csTmp, hv_merchant_ref.len);
DEBUGLOG(("MatchUploadTxn:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }

        /* EXEC SQL SELECT nvl(COUNT(*),0)
                INTO    :v_cnt:ind_cnt
                FROM    ol_merchant_upload_file_detail,
			ol_merchant_upload_file_header
                WHERE   ouh_merchant_id = :hv_merchant_id
                and     oud_merchant_ref = :hv_merchant_ref
		and	ouh_batch_id = oud_batch_id
		and	ouh_disabled = 0
		and	oud_disabled = 0
                and     oud_status not in ('67', '68'); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0:b1 FROM ol_m\
erchant_upload_file_detail , ol_merchant_upload_file_header WHERE ouh_merchan\
t_id = :b2 and oud_merchant_ref = :b3 and ouh_batch_id = oud_batch_id and ouh\
_disabled = 0 and oud_disabled = 0 and oud_status not in ( '67' , '68' ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3335;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cnt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto matchup_error;
}




	if(ind_cnt<0)
		v_cnt = 0;

	if(v_cnt>0){
DEBUGLOG(("MatchUploadTxn Found\n"));
		return PD_FOUND;
        }
	else {
DEBUGLOG(("MatchUploadTxn Not Found\n"));
		return PD_NOT_FOUND;
	}


matchup_error:
DEBUGLOG(("matchup_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetPendingApproveRequestAmout(const hash_t *hRls, double* dAmt)
{
	int	iRet = PD_OK;
	*dAmt	= 0.0;
	char	*csTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO req_amt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;


		double		v_amt;
		short		ind_amt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hRls,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
DEBUGLOG(("GetPendingApproveRequestAmout:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

        if(GetField_CString(hRls,"service_code",&csTmp)){
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr, csTmp, hv_service_code.len);
DEBUGLOG(("GetPendingApproveRequestAmout:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

        if(GetField_CString(hRls,"txn_ccy",&csTmp)){
                hv_ccy.len = strlen(csTmp);
                memcpy(hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("GetPendingApproveRequestAmout:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

        if(GetField_CString(hRls,"txn_country",&csTmp)){
                hv_country.len = strlen(csTmp);
                memcpy(hv_country.arr, csTmp, hv_country.len);
DEBUGLOG(("GetPendingApproveRequestAmout:country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

        /* EXEC SQL SELECT sum(oud_request_amount)
                INTO    :v_amt:ind_amt
                FROM    ol_merchant_upload_file_detail,
			ol_merchant_upload_file_header
                WHERE   ouh_merchant_id = :hv_merchant_id
                and     ouh_service_code = :hv_service_code
		and	oud_country = :hv_country
		and	oud_request_currency = :hv_ccy
		and	ouh_batch_id = oud_batch_id
		and	ouh_disabled = 0
		and	oud_disabled = 0
		and	oud_status in (75, 69); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select sum ( oud_request_amount ) INTO :b0:b1 FROM o\
l_merchant_upload_file_detail , ol_merchant_upload_file_header WHERE ouh_merc\
hant_id = :b2 and ouh_service_code = :b3 and oud_country = :b4 and oud_reques\
t_currency = :b5 and ouh_batch_id = oud_batch_id and ouh_disabled = 0 and oud\
_disabled = 0 and oud_status in ( 75 , 69 ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3362;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_amt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto req_amt_error;
}



	if(ind_amt<0)
		v_amt = 0.0;

	if(v_amt>0.0){
		*dAmt = v_amt;
DEBUGLOG(("GetPendingApproveRequestAmout Amount = [%lf]\n",*dAmt));
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetPendingApproveRequestAmout Amount Not Found\n"));
	}

	return iRet;

req_amt_error:
DEBUGLOG(("req_amt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
		
}

int Delete(const unsigned char* batch_id)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id.len = strlen((const char*)batch_id);
        memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);
DEBUGLOG(("Delete: batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_merch_upload_dt_delete(
                                :hv_batch_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_dele\
te ( :hv_batch_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3397;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLMerchantUploadFileDetail_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }
        if (hv_return_value == SP_ERR)  {
ERRLOG("OLMerchantUploadFileDetail_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetDetailForPayoutGrp(const hash_t *hTxn,recordset_t* myRec)
{
	hash_t	*myHash;
	char	*csTmp;
	char    csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailpg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;
		
		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		char		hv_in_batch_mode;

		short           ind_merchant_id= -1;
		short           ind_in_batch_mode= -1;

		SQL_CURSOR      c_cursor_dt_grp;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		unsigned long   v_batch_id;
		int	        v_seq_num;
		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		char		v_batch_mode;
		char		v_merch_payout_grp;

		short           ind_txn_id = -1;
		short           ind_seq_num = -1;
		short           ind_batch_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short		ind_bank_name = -1;
		short		ind_branch = -1;
		short		ind_batch_mode = -1;
		short		ind_merch_payout_grp= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_in_batch_mode = PD_OFFLINE;
	ind_in_batch_mode = 0;


	if(GetField_CString(hTxn,"merchant_id",&csTmp)){
        	hv_merchant_id.len = strlen(csTmp);
        	memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
		ind_merchant_id= 0;
DEBUGLOG(("GetDetailForPayoutGrp merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	/* EXEC SQL ALLOCATE       :c_cursor_dt_grp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3420;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailpg_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_merch_upload_dt_po_grp(
                                                                :hv_merchant_id:ind_merchant_id,
                                                                :hv_in_batch_mode:ind_in_batch_mode,
                                                                :c_cursor_dt_grp);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_po_grp ( :h\
v_merchant_id:ind_merchant_id , :hv_in_batch_mode:ind_in_batch_mode , :c_curs\
or_dt_grp ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3439;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_in_batch_mode;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_in_batch_mode;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_dt_grp;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getdetailpg_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_batch_id = -1;
                        ind_seq_num = -1;
                        ind_merchant_id = -1;
                        ind_txn_id = -1;
                        ind_aux_txn_seq = -1;
                        ind_merchant_ref = -1;
                        ind_account_num = -1;
                        ind_account_name = -1;
                        ind_bank_name = -1;
                        ind_branch = -1;
			ind_batch_mode = -1;
			ind_merch_payout_grp = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dt_grp
                        INTO

			:v_txn_id:ind_txn_id,
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_branch:ind_branch,
			:v_batch_mode:ind_batch_mode,
			:v_merch_payout_grp:ind_merch_payout_grp; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )3470;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_aux_txn_seq;
                        sqlstm.sqhstl[4] = (unsigned long )19;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_aux_txn_seq;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_account_num;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[7] = (unsigned long )103;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_account_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[8] = (unsigned long )153;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_branch;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[10] = (unsigned long )1;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_merch_payout_grp;
                        sqlstm.sqhstl[11] = (unsigned long )1;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_merch_payout_grp;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdetailpg_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

/*batch_id*/
			if(ind_batch_id>=0){
				sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetDetailForPayoutGrp batch_id=[%ld]\n",v_batch_id));
				PutField_CString(myHash,"batch_id",csBatchId);
			}

/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailForPayoutGrp seq_num=[%d]\n",v_seq_num));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailForPayoutGrp txn_id=[%s]\n",v_txn_id.arr));
			}

/*aux_txn_seq*/
			if(ind_aux_txn_seq>=0){
				v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
				PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailForPayoutGrp aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailForPayoutGrp merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailForPayoutGrp account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailForPayoutGrp account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailForPayoutGrp bank_name= [%s]\n",v_bank_name.arr));
			}


/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailForPayoutGrp branch= [%s]\n",v_branch.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailForPayoutGrp batch_mode= [%c]\n",v_batch_mode));
			}

/*merch_payout_grp*/
			if(ind_merch_payout_grp>=0){
				PutField_Char(myHash,"merch_payout_grp",v_merch_payout_grp);
DEBUGLOG(("GetDetailForPayoutGrp merch_payout_grp= [%c]\n",v_merch_payout_grp));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dt_grp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3533;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailpg_error;
}


        /* EXEC SQL FREE :c_cursor_dt_grp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3552;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getdetailpg_error;
}



DEBUGLOG(("GetDetailForPayoutGrp Normal Exit\n"));
	return  PD_OK;

getdetailpg_error:
DEBUGLOG(("getdetailpg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_GetDetailForPayoutGrp: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dt_grp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3571;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        /* EXEC SQL FREE :c_cursor_dt_grp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3590;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;

}

int MatchRespTxn_ForUpdate(const char* csTxnSeq,
                 const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_ForUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int             hv_status;

                int             v_seq_num;
                short           ind_seq_num = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn_ForUpdate txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchRespTxn_ForUpdate status = [%d]\n",hv_status));

        /* EXEC SQL SELECT oud_seq_num
                INTO    :v_seq_num:ind_seq_num
                FROM    ol_merchant_upload_file_detail
                WHERE   oud_txn_id = :hv_txn_id
                and     oud_status = :hv_status
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oud_seq_num INTO :b0:b1 FROM ol_merchant_uplo\
ad_file_detail WHERE oud_txn_id = :b2 and oud_status = :b3 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3609;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_seq_num;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto MatchRespTxn_ForUpdate_error;
}




        if(ind_seq_num<0)
                v_seq_num = 0;

        if(v_seq_num>0){
DEBUGLOG(("MatchRespTxn_ForUpdate Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxn_ForUpdate Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchRespTxn_ForUpdate_error:
DEBUGLOG(("MatchRespTxn_ForUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetRecordByRandomWithPara(const hash_t *hTxn,recordset_t* myRec)
{
        hash_t  *myHash;
        char    *csTmp;
        char    cTmp;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrecwp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_batch_id_list[2048]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_batch_id_list;

                /* varchar         hv_in_bank_name[PD_BANK_NAME_LEN+3]; */ 
struct { unsigned short len; unsigned char arr[153]; } hv_in_bank_name;

                int             hv_status;
                char            hv_in_batch_mode;
                /* varchar         hv_payout_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_ccy;

                int             hv_pregen_id;
                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		char		hv_in_psp_grp;
		char		hv_in_merch_grp;

                short           ind_merchant_id= -1;
                short           ind_batch_id_list= -1;
                short           ind_in_bank_name= -1;
                short           ind_status= -1;
                short           ind_in_batch_mode= -1;
                short           ind_payout_ccy= -1;
                short           ind_pregen_id= -1;
                short           ind_psp_id= -1;
		short           ind_in_psp_grp= -1;
		short           ind_in_merch_grp= -1;

                SQL_CURSOR      c_cursor_rec_random;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                double          v_payout_amount;
                short           ind_txn_id = -1;
                short           ind_payout_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_Char(hTxn,"batch_mode",&cTmp)){
                hv_in_batch_mode = cTmp;
        }
        else{
                hv_in_batch_mode = PD_OFFLINE;
        }
        ind_in_batch_mode = 0;

        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
        ind_status = 0;
DEBUGLOG(("GetRecordByRandomWithPara status = [%d]\n",hv_status));

        if(GetField_CString(hTxn,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
                ind_merchant_id= 0;
DEBUGLOG(("GetRecordByRandomWithPara merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

        if(GetField_Int(hTxn,"bank_present",&iTmp)){
                if(iTmp){
                        if(GetField_CString(hTxn,"bank_name",&csTmp)){
                                char    csTmpBank[strlen(csTmp)+3];
                                hv_in_bank_name.len = strlen(csTmp)+2;
                                strcpy(csTmpBank,"%");
                                strcat(csTmpBank,csTmp);
                                strcat(csTmpBank,"%");
                                csTmpBank[strlen(csTmp)+2]='\0';
                                memcpy(hv_in_bank_name.arr,csTmpBank,hv_in_bank_name.len);
                                ind_in_bank_name= 0;
DEBUGLOG(("GetRecordByRandomWithPara bank_name = [%.*s]\n",hv_in_bank_name.len,hv_in_bank_name.arr));
                        }
                }
        }

        if(GetField_CString(hTxn,"batch_list",&csTmp)){
                hv_batch_id_list.len = strlen(csTmp);
                memcpy(hv_batch_id_list.arr,csTmp,hv_batch_id_list.len);
                ind_batch_id_list = 0;
DEBUGLOG(("GetRecordByRandomWithPara batch_list = [%s]\n",csTmp));
        }

        if(GetField_CString(hTxn,"payout_ccy",&csTmp)){
                hv_payout_ccy.len = strlen(csTmp);
                memcpy(hv_payout_ccy.arr,csTmp,hv_payout_ccy.len);
                ind_payout_ccy= 0;
DEBUGLOG(("GetRecordByRandomWithPara payout_ccy = [%s]\n",csTmp));
        }

	if(GetField_Char(hTxn,"merchant_group",&cTmp)){
        	hv_in_merch_grp = cTmp;
		ind_in_merch_grp= 0;
DEBUGLOG(("GetRecordByRandomWithPara merchant_group = [%c]\n",hv_in_merch_grp));
	}

	if(GetField_Char(hTxn,"psp_group",&cTmp)){
        	hv_in_psp_grp = cTmp;
		ind_in_psp_grp= 0;
DEBUGLOG(("GetRecordByRandomWithPara psp_group = [%c]\n",hv_in_psp_grp));
	}

        if(GetField_Int(hTxn,"pregen_id",&iTmp)){
                hv_pregen_id = iTmp;
                ind_pregen_id = 0;
DEBUGLOG(("GetRecordByRandomWithPara pregen_id = [%d]\n",iTmp));
        }

        if(GetField_CString(hTxn,"psp_id",&csTmp)){
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id= 0;
DEBUGLOG(("GetRecordByRandomWithPara psp_id = [%s]\n",csTmp));
        }

        /* EXEC SQL ALLOCATE       :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3636;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_merch_upload_dt_rand_rec(
                                                :hv_merchant_id:ind_merchant_id,
                                                :hv_batch_id_list:ind_batch_id_list,
                                                :hv_in_bank_name:ind_in_bank_name,
                                                :hv_status:ind_status,
                                                :hv_in_batch_mode:ind_in_batch_mode,
                                                :hv_payout_ccy:ind_payout_ccy,
						:hv_in_merch_grp:ind_in_merch_grp,
						:hv_in_psp_grp:ind_in_psp_grp,
                                                :hv_pregen_id:ind_pregen_id,
                                                :hv_psp_id:ind_psp_id,
                                                :c_cursor_rec_random);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_rand\
_rec ( :hv_merchant_id:ind_merchant_id , :hv_batch_id_list:ind_batch_id_list \
, :hv_in_bank_name:ind_in_bank_name , :hv_status:ind_status , :hv_in_batch_mo\
de:ind_in_batch_mode , :hv_payout_ccy:ind_payout_ccy , :hv_in_merch_grp:ind_i\
n_merch_grp , :hv_in_psp_grp:ind_in_psp_grp , :hv_pregen_id:ind_pregen_id , :\
hv_psp_id:ind_psp_id , :c_cursor_rec_random ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3655;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id_list;
        sqlstm.sqhstl[2] = (unsigned long )2050;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_batch_id_list;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_in_bank_name;
        sqlstm.sqhstl[3] = (unsigned long )155;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_in_bank_name;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_status;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_in_batch_mode;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_in_batch_mode;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_payout_ccy;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_payout_ccy;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_in_merch_grp;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_in_merch_grp;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_in_psp_grp;
        sqlstm.sqhstl[8] = (unsigned long )1;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_in_psp_grp;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_pregen_id;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_pregen_id;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[10] = (unsigned long )12;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_psp_id;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



        if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_txn_id = -1;
                        ind_payout_amount = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_rec_random
                        INTO

                        :v_txn_id:ind_txn_id,
                        :v_payout_amount:ind_payout_amount; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )3718;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_payout_amount;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/*txn_id*/
                        if(ind_txn_id>=0){
                                v_txn_id.arr[v_txn_id.len]='\0';
                                PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetRecordByRandomWithPara txn_id=[%s]\n",v_txn_id.arr));
                        }

/*payout_amount*/
                        if(ind_payout_amount>=0){
                                PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetRecordByRandomWithPara payout_amount = [%lf]\n",v_payout_amount));
                        }

                        RecordSet_Add(myRec,myHash);

                }
        }

        /* EXEC SQL CLOSE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3745;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}


        /* EXEC SQL FREE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3764;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



DEBUGLOG(("GetRecordByRandomWithPara Normal Exit\n"));
        return  PD_OK;

getrecwp_error:
DEBUGLOG(("getrecwp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_GetWithBankByRandomWithPara: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3783;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        /* EXEC SQL FREE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3802;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        return PD_ERR;

}

int GetPregeneratedRecords(const int iGenId, char cBatchMode, recordset_t* myRec)
{
        hash_t  *myHash;
        int     iCnt = 0;
        //char  cMode;
        char    csBatchId[PD_TXN_SEQ_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO genpsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             hv_disabled;
                int             hv_status;
                int             hv_gen_id;
                char            hv_batch_mode;

                unsigned long   v_batch_id;
                int             v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                double          v_payout_amount;
                double          v_request_amount;
                /* varchar         v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

                /* varchar         v_txn_country[PD_COUNTRY_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_payout_ccy[PD_CURRENCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CURRENCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                /* varchar         v_to_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_to_bank_code;


                short           ind_txn_id = -1;
                short           ind_psp_id = -1;
                short           ind_seq_num = -1;
                short           ind_batch_id = -1;
                short           ind_merchant_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_amount = -1;
                short           ind_remark = -1;
                short           ind_txn_country = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_request_amount = -1;
                short           ind_to_bank_code = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_gen_id = iGenId;
DEBUGLOG(("GetPregeneratedRecords gen_id = [%d]\n",hv_gen_id));

        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetPregeneratedRecords status = [%d]\n",hv_status));

        hv_disabled = 0;
        hv_batch_mode=cBatchMode;
DEBUGLOG(("GetPregeneratedRecords batch_mode = [%c]\n",hv_batch_mode));

                /* EXEC SQL DECLARE c_cursor_genpsp CURSOR FOR
                        SELECT  oud_batch_id,
                                oud_seq_num,
                                oud_txn_id,
                                oud_merchant_ref,
                                oud_identity_id,
                                oud_account_name,
                                oud_account_num,
                                oud_bank_name,
                                oud_bank_code,
                                oud_branch,
                                oud_phone_num,
                                oud_province,
                                oud_city,
                                oud_request_amount,
                                oud_payout_amount,
                                oud_remark,
                                opt_psp_id,
                                oud_country,
                                oud_request_currency,
                                oud_payout_currency,
				opt_bank_code,
				ouh_merchant_id
                       FROM     ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header,
                                ol_payout_generated_tmp
                        WHERE   oud_status = :hv_status
                        and     oud_disabled = :hv_disabled
                        and     oud_batch_mode=:hv_batch_mode
                        and     oud_txn_id = opt_txn_id
                        and     opt_id = :hv_gen_id
			and	ouh_batch_id = oud_batch_id
                        order by opt_psp_id, oud_batch_id, oud_seq_num
                        for update; */ 


                /* EXEC SQL OPEN  c_cursor_genpsp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 39;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = sq0031;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3821;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqcmod = (unsigned int )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_gen_id;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
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
                if (sqlca.sqlcode < 0) goto genpsp_error;
}


                do{
                        /* EXEC SQL FETCH c_cursor_genpsp
                        INTO
                                :v_batch_id:ind_batch_id,
                                :v_seq_num:ind_seq_num,
                                :v_txn_id:ind_txn_id,
                                :v_merchant_ref:ind_merchant_ref,
                                :v_identity_id:ind_identity_id,
                                :v_account_name:ind_account_name,
                                :v_account_num:ind_account_num,
                                :v_bank_name:ind_bank_name,
                                :v_bank_code:ind_bank_code,
                                :v_branch:ind_branch,
                                :v_phone_num:ind_phone_num,
                                :v_province:ind_province,
                                :v_city:ind_city,
                                :v_request_amount:ind_request_amount,
                                :v_payout_amount:ind_payout_amount,
                                :v_remark:ind_remark,
                                :v_psp_id:ind_psp_id,
                                :v_txn_country:ind_txn_country,
                                :v_request_ccy:ind_request_ccy,
                                :v_payout_ccy:ind_payout_ccy,
                                :v_to_bank_code:ind_to_bank_code,
                                :v_merchant_id:ind_merchant_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )3852;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[3] = (unsigned long )53;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[4] = (unsigned long )28;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[5] = (unsigned long )103;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_account_name;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_account_num;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[7] = (unsigned long )153;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[8] = (unsigned long )13;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_branch;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[10] = (unsigned long )28;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[11] = (unsigned long )103;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_province;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[12] = (unsigned long )103;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_city;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[15] = (unsigned long )258;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_remark;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[16] = (unsigned long )13;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_country;
                        sqlstm.sqhstl[17] = (unsigned long )5;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_txn_country;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_to_bank_code;
                        sqlstm.sqhstl[20] = (unsigned long )13;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_to_bank_code;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[21] = (unsigned long )18;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto genpsp_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

/*txn_id*/
                        if(ind_txn_id>=0){
                                v_txn_id.arr[v_txn_id.len]='\0';
                                PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetPregeneratedRecords txn_id= [%s]\n",v_txn_id.arr));

                        }

/*psp_id*/
                        if(ind_psp_id>=0){
                                v_psp_id.arr[v_psp_id.len]='\0';
                                PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPregeneratedRecords psp_id= [%s]\n",v_psp_id.arr));

                        }

/*txn_country*/
                        if(ind_txn_country>=0){
                                v_txn_country.arr[v_txn_country.len]='\0';
                                PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetPregeneratedRecords txn_country= [%s]\n",v_txn_country.arr));

                        }

/*batch_id*/
                        if(ind_batch_id>=0){
                                sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetPregeneratedRecords batch_id=[%ld]\n",v_batch_id));
                                PutField_CString(myHash,"batch_id",csBatchId);
                        }


/*seq_num*/
                        if(ind_seq_num>=0){
                                PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetPregeneratedRecords seq_num=[%d]\n",v_seq_num));
                        }


/*merchant_id*/
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetPregeneratedRecords merchant_id= [%s]\n",v_merchant_id.arr));
                        }

/*merchant_ref*/
                        if(ind_merchant_ref>=0){
                                v_merchant_ref.arr[v_merchant_ref.len]='\0';
                                PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetPregeneratedRecords merchant_ref= [%s]\n",v_merchant_ref.arr));
                        }

/*identity_id*/
                        if(ind_identity_id>=0){
                                v_identity_id.arr[v_identity_id.len]='\0';
                                PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetPregeneratedRecords identity_id= [%s]\n",v_identity_id.arr));
                        }

/*account_num*/
                        if(ind_account_num>=0){
                                v_account_num.arr[v_account_num.len]='\0';
                                PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetPregeneratedRecords account_num= [%s]\n",v_account_num.arr));
                        }

/*account_name*/
                        if(ind_account_name>=0){
                                v_account_name.arr[v_account_name.len]='\0';
                                PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetPregeneratedRecords account_name= [%s]\n",v_account_name.arr));
                        }

/*bank_name*/
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetPregeneratedRecords bank_name= [%s]\n",v_bank_name.arr));
                        }

/*bank_code*/
                        if(ind_bank_code>=0){
                                v_bank_code.arr[v_bank_code.len]='\0';
                                PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetPregeneratedRecords bank_code= [%s]\n",v_bank_code.arr));
                        }

/*branch*/
                        if(ind_branch>=0){
                                v_branch.arr[v_branch.len]='\0';
                                PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetPregeneratedRecords branch= [%s]\n",v_branch.arr));
                        }

/*phone_num*/
                        if(ind_phone_num>=0){
                                v_phone_num.arr[v_phone_num.len]='\0';
                                PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetPregeneratedRecords phone_num= [%s]\n",v_phone_num.arr));
                        }

/*province*/
                        if(ind_province>=0){
                                v_province.arr[v_province.len]='\0';
                                PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetPregeneratedRecords province= [%s]\n",v_province.arr));
                        }

/*city*/
                        if(ind_city>=0){
                                v_city.arr[v_city.len]='\0';
                                PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetPregeneratedRecords city= [%s]\n",v_city.arr));
                        }

/*request_ccy*/
                        if(ind_request_ccy>=0){
                                v_request_ccy.arr[v_request_ccy.len]='\0';
                                PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetPregeneratedRecords request_ccy= [%s]\n",v_request_ccy.arr));

                        }

/*request_amount*/
                        if(ind_request_amount>=0){
                                PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetPregeneratedRecords request_amount = [%lf]\n",v_request_amount));
                        }

/*payout_ccy*/
                        if(ind_payout_ccy>=0){
                                v_payout_ccy.arr[v_payout_ccy.len]='\0';
                                PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetPregeneratedRecords payout_ccy= [%s]\n",v_payout_ccy.arr));

                        }

/*payout_amount*/
                        if(ind_payout_amount>=0){
                                PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetPregeneratedRecords payout_amount = [%lf]\n",v_payout_amount));
                        }

/*remark*/
                        if(ind_remark>=0){
                                v_remark.arr[v_remark.len]='\0';
                                PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetPregeneratedRecords remark= [%s]\n",v_remark.arr));
                        }

/*to_bank_code*/
                        if(ind_to_bank_code>=0){
                                v_to_bank_code.arr[v_to_bank_code.len]='\0';
                                PutField_CString(myHash,"to_bank_code",(const char*)v_to_bank_code.arr);
DEBUGLOG(("GetPregeneratedRecords to_bank_code= [%s]\n",v_to_bank_code.arr));
                        }

                        iCnt ++;
                        RecordSet_Add(myRec,myHash);

                }while(PD_TRUE);

                /* EXEC SQL CLOSE c_cursor_genpsp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 39;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3955;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                if (sqlca.sqlcode < 0) goto genpsp_error;
}



        if(iCnt>0){
DEBUGLOG(("GetPregeneratedRecords Normal Exit\n"));
                return  PD_OK;
        }
        else{
DEBUGLOG(("GetPregeneratedRecords Normal Exit, No Record\n"));
                return  PD_ERR;
        }

genpsp_error:
DEBUGLOG(("GetPregeneratedRecords_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_genpsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3970;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int ResumeGeneratedTxn(const char* csTxnId, const char* csUser)
{
        char*   csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO resumegtxn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeGeneratedTxn: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_upload_file_detail set oud_psp_id ='',oud_generated_file_name='', oud_generated_file_id='', oud_pregen_psp_id ='',oud_pregen_file_id='', oud_status = 65 , oud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, ",oud_update_user= '");
        strcat((char*)hv_dynstmt.arr, csUser);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, " WHERE oud_txn_id = '");
        strcat((char*)hv_dynstmt.arr, csTxnId);
        strcat((char*)hv_dynstmt.arr, "'");
        strcat((char*)hv_dynstmt.arr, " AND oud_status = 70");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3985;
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
        if (sqlca.sqlcode < 0) goto resumegtxn_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4004;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto resumegtxn_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("ResumeGeneratedTxn Normal Exit\n"));
        return PD_OK;

resumegtxn_error:
DEBUGLOG(("resumefile_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_ResumeGeneratedTxn: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int GetBatchIdByPayouyGrp(const char* csMerchantId, const char cPayoutGrp, recordset_t* myRec)
{
        hash_t  *myHash;
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbid_grp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int             hv_disabled;
                int             hv_status;
                char            hv_batch_mode;
		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		char		hv_psp_grp;

                /* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;


                short           ind_batch_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


       	hv_merchant_id.len = strlen(csMerchantId);
       	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetBatchIdByPayouyGrp merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


       	hv_psp_grp = cPayoutGrp;
DEBUGLOG(("GetBatchIdByPayouyGrp psp_group = [%c]\n",hv_psp_grp));

        hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetBatchIdByPayouyGrp status = [%d]\n",hv_status));

        hv_disabled = 0;
        hv_batch_mode = PD_OFFLINE;
DEBUGLOG(("GetBatchIdByPayouyGrp batch_mode = [%c]\n",hv_batch_mode));

                /* EXEC SQL DECLARE c_cursor_getbid_grp CURSOR FOR
                        SELECT  unique oud_batch_id
                       FROM     ol_merchant_upload_file_detail,
				ol_merchant_upload_file_header
                        WHERE   oud_status = :hv_status
                        and     oud_disabled = :hv_disabled
                        and     oud_batch_mode=:hv_batch_mode
			and	ouh_batch_id = oud_batch_id
			and	ouh_merchant_id = :hv_merchant_id
			and	oud_psp_payout_grp = :hv_psp_grp; */ 


                /* EXEC SQL OPEN  c_cursor_getbid_grp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 39;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = sq0032;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )4019;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqcmod = (unsigned int )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)0;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_mode;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)0;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[3] = (unsigned long )17;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)0;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_psp_grp;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)0;
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
                if (sqlca.sqlcode < 0) goto getbid_grp_error;
}


                do{
                        /* EXEC SQL FETCH c_cursor_getbid_grp
                        INTO
                                :v_batch_id:ind_batch_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )4054;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[0] = (unsigned long )19;
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
                        if (sqlca.sqlcode < 0) goto getbid_grp_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

/*batch_id*/
                        if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len] = '\0';
DEBUGLOG(("GetBatchIdByPayouyGrp batch_id = [%s]\n",v_batch_id.arr));
                                PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
                        }

                        iCnt ++;
                        RecordSet_Add(myRec,myHash);

                }while(PD_TRUE);

                /* EXEC SQL CLOSE c_cursor_getbid_grp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 39;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )4073;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                if (sqlca.sqlcode < 0) goto getbid_grp_error;
}



        if(iCnt>0){
DEBUGLOG(("GetBatchIdByPayouyGrp Normal Exit\n"));
                return  PD_OK;
        }
        else{
DEBUGLOG(("GetBatchIdByPayouyGrp Normal Exit, No Record\n"));
                return  PD_ERR;
        }

getbid_grp_error:
DEBUGLOG(("GetBatchIdByPayouyGrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbid_grp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4088;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetDetailForPayoutGrpByBatchId(const hash_t *hTxn,recordset_t* myRec)
{
	hash_t	*myHash;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailpgbatch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;
		
		unsigned long   hv_batch_id;
		char		hv_in_batch_mode;

		short           ind_batch_id= -1;
		short           ind_in_batch_mode= -1;

		SQL_CURSOR      c_cursor_dt_grp_batch;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_merchant_id;

		int	        v_seq_num;
		/* varchar		v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		char		v_batch_mode;
		char		v_merch_payout_grp;

		short           ind_txn_id = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_id = -1;
		short           ind_aux_txn_seq = -1;
		short           ind_merchant_ref = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short		ind_bank_name = -1;
		short		ind_branch = -1;
		short		ind_batch_mode = -1;
		short		ind_merch_payout_grp= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_in_batch_mode = PD_OFFLINE;
	ind_in_batch_mode = 0;


	if (GetField_CString(hTxn,"batch_id",&csTmp)) {
                hv_batch_id = string2double((const unsigned char *)csTmp);
                ind_batch_id = 0;
DEBUGLOG(("GetDetailForPayoutGrpByBatchId batch_id = [%lf]\n",hv_batch_id));
	}

	/* EXEC SQL ALLOCATE       :c_cursor_dt_grp_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4103;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailpgbatch_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_merch_upload_dt_pog_bh(
                                                                :hv_batch_id:ind_batch_id,
                                                                :hv_in_batch_mode:ind_in_batch_mode,
                                                                :c_cursor_dt_grp_batch);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_upload_dt_pog_bh ( :h\
v_batch_id:ind_batch_id , :hv_in_batch_mode:ind_in_batch_mode , :c_cursor_dt_\
grp_batch ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4122;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_in_batch_mode;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_in_batch_mode;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_dt_grp_batch;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getdetailpgbatch_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_merchant_id = -1;
                        ind_seq_num = -1;
                        ind_batch_id = -1;
                        ind_txn_id = -1;
                        ind_aux_txn_seq = -1;
                        ind_merchant_ref = -1;
                        ind_account_num = -1;
                        ind_account_name = -1;
                        ind_bank_name = -1;
                        ind_branch = -1;
			ind_batch_mode = -1;
			ind_merch_payout_grp = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dt_grp_batch
                        INTO

			:v_txn_id:ind_txn_id,
			:v_merchant_id:ind_merchant_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
			:v_bank_name:ind_bank_name,
			:v_branch:ind_branch,
			:v_batch_mode:ind_batch_mode,
			:v_merch_payout_grp:ind_merch_payout_grp; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )4153;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[2] = (unsigned long )17;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_aux_txn_seq;
                        sqlstm.sqhstl[4] = (unsigned long )19;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_aux_txn_seq;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_account_num;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[7] = (unsigned long )103;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_account_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[8] = (unsigned long )153;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_branch;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[10] = (unsigned long )1;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_merch_payout_grp;
                        sqlstm.sqhstl[11] = (unsigned long )1;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_merch_payout_grp;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdetailpgbatch_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId merchant_id=[%s]\n",v_merchant_id.arr));
			}

/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId seq_num=[%d]\n",v_seq_num));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId txn_id=[%s]\n",v_txn_id.arr));
			}

/*aux_txn_seq*/
			if(ind_aux_txn_seq>=0){
				v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
				PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
			}


/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId bank_name= [%s]\n",v_bank_name.arr));
			}


/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId branch= [%s]\n",v_branch.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId batch_mode= [%c]\n",v_batch_mode));
			}

/*merch_payout_grp*/
			if(ind_merch_payout_grp>=0){
				PutField_Char(myHash,"merch_payout_grp",v_merch_payout_grp);
DEBUGLOG(("GetDetailForPayoutGrpByBatchId merch_payout_grp= [%c]\n",v_merch_payout_grp));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dt_grp_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4216;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailpgbatch_error;
}


        /* EXEC SQL FREE :c_cursor_dt_grp_batch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4235;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getdetailpgbatch_error;
}



DEBUGLOG(("GetDetailForPayoutGrpByBatchId Normal Exit\n"));
	return  PD_OK;

getdetailpgbatch_error:
DEBUGLOG(("getdetailpgbatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantUploadFileDetail_GetDetailForPayoutGrpByBatchId: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dt_grp_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4254;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        /* EXEC SQL FREE :c_cursor_dt_grp_batch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4273;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dt_grp_batch;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;

}

