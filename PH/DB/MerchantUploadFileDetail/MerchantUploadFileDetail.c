
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
    "MerchantUploadFileDetail.pc"
};


static unsigned int sqlctx = 1437150763;


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
"select ud_seq_num , ud_txn_id , ud_aux_txn_id , ud_merchant_ref , ud_countr\
y , ud_identity_id , ud_account_num , ud_account_name , ud_bank_name , ud_ban\
k_code , ud_branch , ud_phone_num , ud_province , ud_city , ud_payout_amount \
, ud_request_amount , ud_payout_currency , ud_request_currency , ud_member_fe\
e_ccy , ud_member_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy\
 , ud_markup_amt , ud_exchange_rate , ud_status , ud_response_code , ud_remar\
k , ud_batch_mode , ud_generated_file_name , ud_psp_batch_id , ud_fundout_dat\
e , ud_service_fee , ud_psp_id , ud_generated_file_id , ud_approve_id from me\
rchant_upload_file_detail where ud_batch_id = :b0 and ud_disabled = :b1 order\
 by ud_seq_num            ";

 static char *sq0003 = 
"select ud_batch_id , ud_seq_num , ud_aux_txn_id , ud_merchant_ref , ud_coun\
try , ud_identity_id , ud_account_num , ud_account_name , ud_bank_name , ud_b\
ank_code , ud_branch , ud_phone_num , ud_province , ud_city , ud_payout_amoun\
t , ud_request_amount , ud_payout_currency , ud_request_currency , ud_member_\
fee_ccy , ud_member_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_c\
cy , ud_markup_amt , ud_exchange_rate , ud_status , ud_response_code , ud_rem\
ark , ud_batch_mode , ud_generated_file_name , ud_psp_batch_id , ud_fundout_d\
ate , ud_service_fee , ud_psp_id , ud_generated_file_id , ud_approve_id from \
merchant_upload_file_detail where ud_txn_id = :b0 and ud_disabled = :b1 order\
 by ud_seq_num            ";

 static char *sq0005 = 
"SELECT UNIQUE ud_psp_id FROM merchant_upload_file_detail , merchant_upload_\
file_header WHERE ud_status = :b0 and ud_disabled = :b1 and ud_batch_id = uh_\
batch_id and uh_merchant_id = :b2 and ud_batch_mode = :b3 and ud_psp_id IS NO\
T NULL            ";

 static char *sq0006 = 
"SELECT UNIQUE ud_psp_id FROM merchant_upload_file_detail WHERE ud_status = \
:b0 and ud_disabled = :b1 and ud_batch_mode = :b2 and ud_psp_id IS NOT NULL  \
          ";

 static char *sq0007 = 
"SELECT UNIQUE ud_pregen_psp_id FROM merchant_upload_file_detail , merchant_\
upload_file_header WHERE ud_status = :b0 and ud_disabled = :b1 and ud_batch_i\
d = uh_batch_id and uh_merchant_id = :b2 and ud_batch_mode = :b3 and ud_prege\
n_psp_id IS NOT NULL            ";

 static char *sq0008 = 
"SELECT UNIQUE ud_pregen_psp_id FROM merchant_upload_file_detail WHERE ud_st\
atus = :b0 and ud_disabled = :b1 and ud_batch_mode = :b2 and ud_pregen_psp_id\
 IS NOT NULL            ";

 static char *sq0009 = 
"SELECT UNIQUE ud_pregen_file_id FROM merchant_upload_file_detail , payout_g\
enerated_file_hd WHERE ud_status = :b0 and ud_disabled = :b1 and ud_batch_mod\
e = :b2 and fh_file_id = ud_pregen_file_id and fh_status = :b3 and ud_pregen_\
file_id IS NOT NULL            ";

 static char *sq0010 = 
"SELECT ud_batch_id , ud_seq_num , ud_txn_id , ud_merchant_ref , ud_identity\
_id , ud_account_name , ud_account_num , ud_bank_name , ud_branch , ud_phone_\
num , ud_province , ud_city , ud_payout_amount , ud_request_amount , ud_remar\
k , ud_pregen_psp_id , ud_country , ud_payout_currency , ud_request_currency \
, ud_merchant_fee_ccy , ud_merchant_fee , ud_member_fee_ccy , ud_member_fee ,\
 ud_markup_amt , ud_markup_ccy FROM merchant_upload_file_detail , merchant_up\
load_file_header WHERE ud_status = :b0 and ud_disabled = :b1 and ud_batch_id \
= uh_batch_id and uh_merchant_id = :b2 and ud_batch_mode = :b3 and ud_pregen_\
psp_id IS NOT NULL order by ud_batch_id , ud_seq_num            ";

 static char *sq0011 = 
"SELECT ud_batch_id , ud_seq_num , ud_txn_id , ud_merchant_ref , ud_identity\
_id , ud_account_name , ud_account_num , ud_bank_name , ud_branch , ud_phone_\
num , ud_province , ud_city , ud_request_amount , ud_payout_amount , ud_remar\
k , ud_pregen_psp_id , ud_country , ud_request_currency , ud_payout_currency \
FROM merchant_upload_file_detail WHERE ud_status = :b0 and ud_disabled = :b1 \
and ud_batch_mode = :b2 and ud_pregen_psp_id IS NOT NULL order by ud_batch_id\
 , ud_seq_num            ";

 static char *sq0012 = 
"select ud_txn_id , ud_batch_id , ud_seq_num , ud_aux_txn_id , ud_merchant_r\
ef , ud_country , ud_identity_id , ud_account_num , ud_account_name , ud_bran\
ch , ud_phone_num , ud_province , ud_city , ud_payout_amount , ud_request_amo\
unt , ud_payout_currency , ud_request_currency , ud_member_fee_ccy , ud_membe\
r_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy , ud_markup_amt\
 , ud_exchange_rate , ud_response_code , ud_remark , ud_batch_mode , ud_gener\
ated_file_name , ud_psp_batch_id , ud_fundout_date , ud_service_fee from ( SE\
LECT * FROM merchant_upload_file_detail ORDER BY dbms_random . value ) , merc\
hant_upload_file_header where ud_bank_name like :b0 and ud_status = :b1 and u\
d_disabled = :b2 and uh_merchant_id = :b3 and uh_batch_id = ud_batch_id and u\
d_batch_mode = :b4 and ud_disabled = uh_disabled and ud_pregen_psp_id IS NULL\
            ";

 static char *sq0013 = 
"select ud_txn_id , ud_batch_id , ud_seq_num , ud_aux_txn_id , ud_merchant_r\
ef , ud_country , ud_identity_id , ud_account_num , ud_account_name , ud_bran\
ch , ud_phone_num , ud_province , ud_city , ud_payout_amount , ud_request_amo\
unt , ud_payout_currency , ud_request_currency , ud_member_fee_ccy , ud_membe\
r_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy , ud_markup_amt\
 , ud_exchange_rate , ud_response_code , ud_remark , ud_batch_mode , ud_gener\
ated_file_name , ud_psp_batch_id , ud_fundout_date , ud_service_fee from ( SE\
LECT * FROM merchant_upload_file_detail ORDER BY dbms_random . value ) , merc\
hant_upload_file_header where ud_bank_name like :b0 and ud_status = :b1 and u\
d_disabled = :b2 and ud_batch_mode = :b3 and ud_batch_id = uh_batch_id and ud\
_disabled = uh_disabled and ud_pregen_psp_id IS NULL            ";

 static char *sq0014 = 
"select ud_txn_id , ud_batch_id , ud_seq_num , ud_aux_txn_id , ud_merchant_r\
ef , ud_country , ud_identity_id , ud_account_num , ud_account_name , ud_bank\
_name , ud_branch , ud_phone_num , ud_province , ud_city , ud_payout_amount ,\
 ud_request_amount , ud_payout_currency , ud_request_currency , ud_member_fee\
_ccy , ud_member_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy \
, ud_markup_amt , ud_exchange_rate , ud_response_code , ud_remark , ud_batch_\
mode , ud_generated_file_name , ud_psp_batch_id , ud_fundout_date , ud_servic\
e_fee from ( SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random .\
 value ) , merchant_upload_file_header where ud_status = :b0 and ud_disabled \
= :b1 and uh_merchant_id = :b2 and uh_batch_id = ud_batch_id and uh_disabled \
= ud_disabled and ud_batch_mode = :b3 and ud_pregen_psp_id IS NULL           \
 ";

 static char *sq0015 = 
"select ud_txn_id , ud_batch_id , ud_seq_num , ud_aux_txn_id , ud_merchant_r\
ef , ud_country , ud_identity_id , ud_account_num , ud_account_name , ud_bank\
_name , ud_branch , ud_phone_num , ud_province , ud_city , ud_payout_amount ,\
 ud_request_amount , ud_payout_currency , ud_request_currency , ud_member_fee\
_ccy , ud_member_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy \
, ud_markup_amt , ud_exchange_rate , ud_response_code , ud_remark , ud_batch_\
mode , ud_generated_file_name , ud_psp_batch_id , ud_fundout_date , ud_servic\
e_fee from ( SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random .\
 value ) , merchant_upload_file_header where ud_status = :b0 and ud_disabled \
= :b1 and ud_batch_mode = :b2 and ud_batch_id = uh_batch_id and ud_disabled =\
 uh_disabled and ud_pregen_psp_id IS NULL            ";

 static char *sq0022 = 
"select ud_seq_num , ud_txn_id , ud_merchant_ref , ud_country , ud_identity_\
id , ud_account_num , ud_account_name , ud_bank_name , ud_bank_code , ud_bran\
ch , ud_phone_num , ud_province , ud_city , ud_payout_amount , ud_request_amo\
unt , ud_payout_currency , ud_request_currency , ud_member_fee_ccy , ud_membe\
r_fee , ud_merchant_fee_ccy , ud_merchant_fee , ud_markup_ccy , ud_markup_amt\
 , ud_exchange_rate , ud_status , ud_response_code , ud_remark , ud_batch_mod\
e , ud_generated_file_name , ud_psp_batch_id , ud_fundout_date , ud_service_f\
ee , ud_psp_id , ud_generated_file_id from merchant_upload_file_detail where \
ud_batch_id = :b0 and ud_disabled = :b1 and ud_aux_txn_id is NULL and ud_stat\
us not in ( :b2 , :b3 ) order by ud_seq_num            ";

 static char *sq0032 = 
"SELECT ud_batch_id , ud_seq_num , ud_txn_id , ud_merchant_ref , ud_identity\
_id , ud_account_name , ud_account_num , ud_bank_name , ud_bank_code , ud_bra\
nch , ud_phone_num , ud_province , ud_city , ud_request_amount , ud_payout_am\
ount , ud_remark , pt_psp_id , ud_country , ud_request_currency , ud_payout_c\
urrency FROM merchant_upload_file_detail , payout_generated_tmp WHERE ud_stat\
us = :b0 and ud_disabled = :b1 and ud_batch_mode = :b2 and ud_txn_id = pt_txn\
_id and pt_id = :b3 order by pt_psp_id , ud_batch_id , ud_seq_num for update ";

 static char *sq0033 = 
"SELECT uh_batch_id , fd_file_id , uh_merchant_id , uh_service_code , pt_psp\
_id , count ( fd_txn_id ) FROM merchant_upload_file_header , payout_generated\
_tmp , payout_generated_file_dt WHERE pt_txn_id = fd_upload_txn_id and fd_bat\
ch_id = uh_batch_id and uh_disabled = :b0 and pt_id = :b1 group by uh_batch_i\
d , fd_file_id , uh_merchant_id , uh_service_code , pt_psp_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,17,296,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,297,0,0,0,0,0,1,0,
39,0,0,1,0,0,17,498,0,0,1,1,0,1,0,1,9,0,0,
58,0,0,1,0,0,21,499,0,0,0,0,0,1,0,
73,0,0,2,717,0,9,655,0,2049,2,2,0,1,0,1,68,0,0,1,3,0,0,
96,0,0,2,0,0,13,657,0,0,36,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,
0,2,3,0,0,
255,0,0,2,0,0,15,949,0,0,0,0,0,1,0,
270,0,0,2,0,0,15,959,0,0,0,0,0,1,0,
285,0,0,3,717,0,9,1102,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
308,0,0,3,0,0,13,1104,0,0,36,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,
0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,
467,0,0,3,0,0,15,1398,0,0,0,0,0,1,0,
482,0,0,3,0,0,15,1408,0,0,0,0,0,1,0,
497,0,0,4,115,0,4,1435,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
524,0,0,5,247,0,9,1510,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
555,0,0,5,0,0,13,1512,0,0,1,0,0,1,0,2,9,0,0,
574,0,0,5,0,0,15,1536,0,0,0,0,0,1,0,
589,0,0,6,162,0,9,1548,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
616,0,0,6,0,0,13,1550,0,0,1,0,0,1,0,2,9,0,0,
635,0,0,6,0,0,15,1574,0,0,0,0,0,1,0,
650,0,0,6,0,0,15,1590,0,0,0,0,0,1,0,
665,0,0,5,0,0,15,1591,0,0,0,0,0,1,0,
680,0,0,7,261,0,9,1646,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
711,0,0,7,0,0,13,1648,0,0,1,0,0,1,0,2,9,0,0,
730,0,0,7,0,0,15,1672,0,0,0,0,0,1,0,
745,0,0,8,176,0,9,1684,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
772,0,0,8,0,0,13,1686,0,0,1,0,0,1,0,2,9,0,0,
791,0,0,8,0,0,15,1710,0,0,0,0,0,1,0,
806,0,0,8,0,0,15,1726,0,0,0,0,0,1,0,
821,0,0,7,0,0,15,1727,0,0,0,0,0,1,0,
836,0,0,9,260,0,9,1823,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,1,3,0,0,
867,0,0,9,0,0,13,1825,0,0,1,0,0,1,0,2,9,0,0,
886,0,0,9,0,0,15,1849,0,0,0,0,0,1,0,
901,0,0,9,0,0,15,1865,0,0,0,0,0,1,0,
916,0,0,10,678,0,9,1996,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
947,0,0,10,0,0,13,1998,0,0,25,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,
1062,0,0,10,0,0,15,2218,0,0,0,0,0,1,0,
1077,0,0,11,485,0,9,2250,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
1104,0,0,11,0,0,13,2252,0,0,19,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1195,0,0,11,0,0,15,2424,0,0,0,0,0,1,0,
1210,0,0,10,0,0,15,2440,0,0,0,0,0,1,0,
1225,0,0,11,0,0,15,2441,0,0,0,0,0,1,0,
1240,0,0,12,857,0,9,2592,0,2049,5,5,0,1,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,
0,0,
1275,0,0,12,0,0,13,2594,0,0,31,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,
9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
1414,0,0,12,0,0,15,2855,0,0,0,0,0,1,0,
1429,0,0,12,0,0,15,2865,0,0,0,0,0,1,0,
1444,0,0,13,832,0,9,3017,0,2049,4,4,0,1,0,1,9,0,0,1,3,0,0,1,3,0,0,1,1,0,0,
1475,0,0,13,0,0,13,3019,0,0,31,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,
9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
1614,0,0,13,0,0,15,3280,0,0,0,0,0,1,0,
1629,0,0,13,0,0,15,3290,0,0,0,0,0,1,0,
1644,0,0,14,846,0,9,3434,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
1675,0,0,14,0,0,13,3436,0,0,32,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
1818,0,0,14,0,0,15,3705,0,0,0,0,0,1,0,
1833,0,0,14,0,0,15,3715,0,0,0,0,0,1,0,
1848,0,0,15,821,0,9,3852,0,2049,3,3,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,
1875,0,0,15,0,0,13,3854,0,0,32,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2018,0,0,15,0,0,15,4124,0,0,0,0,0,1,0,
2033,0,0,15,0,0,15,4134,0,0,0,0,0,1,0,
2048,0,0,16,117,0,4,4168,0,0,3,2,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,
2075,0,0,17,117,0,4,4174,0,0,3,2,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,
2102,0,0,18,89,0,4,4180,0,0,2,1,0,1,0,2,3,0,0,1,68,0,0,
2125,0,0,1,0,0,17,4236,0,0,1,1,0,1,0,1,9,0,0,
2144,0,0,1,0,0,21,4237,0,0,0,0,0,1,0,
2159,0,0,1,0,0,17,4281,0,0,1,1,0,1,0,1,9,0,0,
2178,0,0,1,0,0,21,4282,0,0,0,0,0,1,0,
2193,0,0,1,0,0,17,4328,0,0,1,1,0,1,0,1,9,0,0,
2212,0,0,1,0,0,21,4329,0,0,0,0,0,1,0,
2227,0,0,1,0,0,17,4376,0,0,1,1,0,1,0,1,9,0,0,
2246,0,0,1,0,0,21,4377,0,0,0,0,0,1,0,
2261,0,0,0,0,0,56,4507,0,0,1,1,0,1,0,3,102,0,0,
2280,0,0,19,189,0,6,4510,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,3,0,0,
2,102,0,0,
2319,0,0,20,157,0,6,4522,0,0,5,5,0,1,0,2,3,0,0,1,1,0,0,1,3,0,0,1,3,0,0,2,102,0,
0,
2354,0,0,0,0,0,13,4578,0,0,36,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,9,0,0,
2513,0,0,0,0,0,15,4861,0,0,1,1,0,1,0,1,102,0,0,
2532,0,0,0,0,0,78,4862,0,0,1,1,0,1,0,3,102,0,0,
2551,0,0,0,0,0,15,4872,0,0,1,1,0,1,0,1,102,0,0,
2570,0,0,0,0,0,78,4873,0,0,1,1,0,1,0,3,102,0,0,
2589,0,0,21,973,0,6,5203,0,0,30,30,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
2724,0,0,22,746,0,9,5407,0,2049,4,4,0,1,0,1,68,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
2755,0,0,22,0,0,13,5409,0,0,34,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,3,
0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
2906,0,0,22,0,0,15,5685,0,0,0,0,0,1,0,
2921,0,0,22,0,0,15,5695,0,0,0,0,0,1,0,
2936,0,0,0,0,0,56,5864,0,0,1,1,0,1,0,3,102,0,0,
2955,0,0,23,277,0,6,5866,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,3,0,0,
1,4,0,0,1,4,0,0,1,9,0,0,2,102,0,0,
3006,0,0,0,0,0,13,5930,0,0,39,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
3177,0,0,0,0,0,15,6233,0,0,1,1,0,1,0,1,102,0,0,
3196,0,0,0,0,0,78,6234,0,0,1,1,0,1,0,3,102,0,0,
3215,0,0,0,0,0,15,6244,0,0,1,1,0,1,0,1,102,0,0,
3234,0,0,0,0,0,78,6245,0,0,1,1,0,1,0,3,102,0,0,
3253,0,0,24,106,0,4,6264,0,0,1,0,0,1,0,2,3,0,0,
3272,0,0,25,112,0,4,6302,0,0,1,0,0,1,0,2,3,0,0,
3291,0,0,1,0,0,17,6355,0,0,1,1,0,1,0,1,9,0,0,
3310,0,0,1,0,0,21,6356,0,0,0,0,0,1,0,
3325,0,0,0,0,0,56,6481,0,0,1,1,0,1,0,3,102,0,0,
3344,0,0,26,154,0,6,6483,0,0,4,4,0,1,0,2,3,0,0,1,3,0,0,1,3,0,0,2,102,0,0,
3375,0,0,0,0,0,13,6542,0,0,39,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
3546,0,0,0,0,0,15,6845,0,0,1,1,0,1,0,1,102,0,0,
3565,0,0,0,0,0,78,6846,0,0,1,1,0,1,0,3,102,0,0,
3584,0,0,0,0,0,15,6856,0,0,1,1,0,1,0,1,102,0,0,
3603,0,0,0,0,0,78,6857,0,0,1,1,0,1,0,3,102,0,0,
3622,0,0,1,0,0,17,6899,0,0,1,1,0,1,0,1,9,0,0,
3641,0,0,1,0,0,21,6900,0,0,0,0,0,1,0,
3656,0,0,0,0,0,56,7062,0,0,1,1,0,1,0,3,102,0,0,
3675,0,0,27,253,0,6,7064,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,1,0,0,2,102,0,0,
3718,0,0,0,0,0,13,7117,0,0,33,1,0,1,0,1,102,0,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
3865,0,0,0,0,0,15,7387,0,0,1,1,0,1,0,1,102,0,0,
3884,0,0,0,0,0,78,7388,0,0,1,1,0,1,0,3,102,0,0,
3903,0,0,0,0,0,15,7398,0,0,1,1,0,1,0,1,102,0,0,
3922,0,0,0,0,0,78,7399,0,0,1,1,0,1,0,3,102,0,0,
3941,0,0,28,266,0,4,7433,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
3968,0,0,29,116,0,4,7489,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
3995,0,0,30,76,0,6,7533,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
4018,0,0,0,0,0,56,7674,0,0,1,1,0,1,0,3,102,0,0,
4037,0,0,31,344,0,6,7676,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,
0,1,1,0,0,1,9,0,0,1,3,0,0,1,9,0,0,2,102,0,0,
4092,0,0,0,0,0,13,7701,0,0,3,1,0,1,0,1,102,0,0,2,9,0,0,2,4,0,0,
4119,0,0,0,0,0,15,7729,0,0,1,1,0,1,0,1,102,0,0,
4138,0,0,0,0,0,78,7730,0,0,1,1,0,1,0,3,102,0,0,
4157,0,0,0,0,0,15,7740,0,0,1,1,0,1,0,1,102,0,0,
4176,0,0,0,0,0,78,7741,0,0,1,1,0,1,0,3,102,0,0,
4195,0,0,32,537,0,9,7861,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,1,0,0,1,3,0,0,
4226,0,0,32,0,0,13,7863,0,0,20,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
4321,0,0,32,0,0,15,8043,0,0,0,0,0,1,0,
4336,0,0,32,0,0,15,8058,0,0,0,0,0,1,0,
4351,0,0,33,379,0,9,8115,0,2049,2,2,0,1,0,1,3,0,0,1,3,0,0,
4374,0,0,33,0,0,13,8117,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,
4413,0,0,33,0,0,15,8179,0,0,0,0,0,1,0,
4428,0,0,33,0,0,15,2,1,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchantUploadFileDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchantUploadFileDetail(char    cdebug)
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
DEBUGLOG(("UpdateDetailByBatchId:batch_id = [%s]\n",csBatchId));

        csSeqNum = (char*) malloc (128);
	sprintf(csSeqNum,"%d",iSeqNum);
DEBUGLOG(("UpdateDetailByBatchId:seq_num = [%s]\n",csSeqNum));

        if(GetField_Double(hRls,"payout_amt",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: payout_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_payout_amount =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"member_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: member_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_member_fee =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"txn_country",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: txn_country = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_country = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"identity_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: identity_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_identity_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"bank_code",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: pregen_psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_pregen_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"member_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: member_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_member_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"merchant_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: merchant_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_merchant_fee =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"merchant_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: merchant_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_merchant_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"markup_amt",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: markup_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_markup_amt =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"markup_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: markup_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_markup_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"ex_rate",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: ex_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_exchange_rate =");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRls,"batch_mode",&cTmp)){
DEBUGLOG(("UpdateDetailByBatchId: batch_mode = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_batch_mode = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_CString(hRls,"resp_code",&csRespCode)){
DEBUGLOG(("UpdateDetailByBatchId: resp_code = [%s]\n",csRespCode));
                strcat((char*)hv_dynstmt.arr, ",ud_response_code = '");
                strcat((char*)hv_dynstmt.arr, csRespCode);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"remark",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: remark = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_remark= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"aux_txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: aux_txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_aux_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_batch_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: psp_batch_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_psp_batch_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"fundout_date",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: fundout_date = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_fundout_date= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"service_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByBatchId: service_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_service_fee=");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"generated_file_name",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: generated_file_name = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_generated_file_name= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"pregen_file_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: pregen_file_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_pregen_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"file_id",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: generated_file_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_generated_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_approve_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"pre_approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByBatchId: pre_approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_preapprove_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"update_user",&csBuf)){
DEBUGLOG(("UpdateDetailByBatchId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_update_user= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE ud_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        strcat((char*)hv_dynstmt.arr, " AND ud_seq_num = ");
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
ERRLOG("MerchantUploadFileDetail_UpdateDetailByBatchId: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int UpdateDetailByTxnId(const char* csTxnId, const hash_t *hRls)
{
	char*   csBuf;
	char*	csRespCode;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatedetailbytxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateDetailByTxnId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
DEBUGLOG(("UpdateDetailByTxnId:txn_id = [%s]\n",csTxnId));
        
        if(GetField_CString(hRls,"psp_id",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"aux_txn_seq",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: aux_txn_seq = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_aux_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"member_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: member_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_member_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
	if (GetField_Double(hRls,"member_fee",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:member_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_member_fee = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"merchant_fee_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: merchant_fee_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_merchant_fee_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"merchant_fee",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:merchant_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_merchant_fee = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"markup_ccy",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: markup_ccy = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_markup_ccy= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"markup_amt",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:markup_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_markup_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_Double(hRls,"ex_rate",&dTmp)) {
DEBUGLOG(("UpdateDetailByTxnId:ex_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_exchange_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        if(GetField_CString(hRls,"payout_txn_num",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: payout_txn_num = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_payout_txn_num= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateDetailByTxnId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        if(GetField_CString(hRls,"resp_code",&csRespCode)){
DEBUGLOG(("UpdateDetailByTxnId: resp_code = [%s]\n",csRespCode));
                strcat((char*)hv_dynstmt.arr, ",ud_response_code = '");
                strcat((char*)hv_dynstmt.arr, csRespCode);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"remark",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: remark = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_remark= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"psp_batch_id",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: psp_batch_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_psp_batch_id= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"tid",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: tid = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_tid= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"fundout_date",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: fundout_date = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_fundout_date= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Double(hRls,"service_fee",&dTmp)){
DEBUGLOG(("UpdateDetailByTxnId: service_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_service_fee=");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRls,"approve_id",&iTmp)){
DEBUGLOG(("UpdateDetailByTxnId: approve_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_approve_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"update_user",&csBuf)){
DEBUGLOG(("UpdateDetailByTxnId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_update_user= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE ud_txn_id = '");
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
ERRLOG("MerchantUploadFileDetail_UpdateDetailByTxnId: SP_ERR TxnAbort\n");
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
		select	ud_seq_num,
			ud_txn_id,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_bank_name,
			ud_bank_code,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_status,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee,
			ud_psp_id,
			ud_generated_file_id,
			ud_approve_id
		from	merchant_upload_file_detail
		where	ud_batch_id =:hv_batch_id
		and	ud_disabled = :hv_disabled
		order by ud_seq_num; */ 


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
ERRLOG("MerchantUploadFileDetail_Get: SP_ERR\n");
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
		select	ud_batch_id,
			ud_seq_num,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_bank_name,
			ud_bank_code,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_status,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee,
			ud_psp_id,
			ud_generated_file_id,
			ud_approve_id
		from	merchant_upload_file_detail
		where	ud_txn_id =:hv_txn_id
		and	ud_disabled = :hv_disabled
		order by ud_seq_num; */ 


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
ERRLOG("MerchantUploadFileDetail_GetByTxnId: SP_ERR\n");
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
                FROM    merchant_upload_file_detail
                WHERE   ud_txn_id = :hv_txn_id
                and     ud_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM merchan\
t_upload_file_detail WHERE ud_txn_id = :b1 and ud_status = :b2 ";
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
                	SELECT UNIQUE ud_psp_id
                	FROM    merchant_upload_file_detail,
				merchant_upload_file_header
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_id=uh_batch_id
			and	uh_merchant_id=:hv_merchant_id
			and	ud_batch_mode=:hv_batch_mode
			and     ud_psp_id IS NOT NULL; */ 


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
                	SELECT UNIQUE ud_psp_id
                	FROM    merchant_upload_file_detail
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_mode=:hv_batch_mode
			and     ud_psp_id IS NOT NULL; */ 


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

                short           ind_psp_id = -1;

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
                	SELECT UNIQUE ud_pregen_psp_id
                	FROM    merchant_upload_file_detail,
				merchant_upload_file_header
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_id=uh_batch_id
			and	uh_merchant_id=:hv_merchant_id
			and	ud_batch_mode=:hv_batch_mode
			and     ud_pregen_psp_id IS NOT NULL; */ 


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
				:v_psp_id:ind_psp_id; */ 

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
  sqlstm.offset = (unsigned int  )730;
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
                	SELECT UNIQUE ud_pregen_psp_id
                	FROM    merchant_upload_file_detail
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_mode=:hv_batch_mode
			and     ud_pregen_psp_id IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_gpap; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0008;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )745;
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
				:v_psp_id:ind_psp_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )772;
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
  sqlstm.offset = (unsigned int  )791;
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
        sqlstm.offset = (unsigned int  )806;
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
        sqlstm.offset = (unsigned int  )821;
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
                int		hv_fh_status;
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
	hv_fh_status = PD_PAYOUTFILE_PRE_GENERATED;

/*
	if(GetField_CString(hTxn,"merchant_id",&csMerchantId)){
		
        	hv_merchant_id.len = strlen(csMerchantId);
        	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetPreGeneratedFileId merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


        	EXEC SQL DECLARE c_cursor_prefilem CURSOR FOR
                	SELECT UNIQUE ud_pregen_file_id
                	FROM    merchant_upload_file_detail,
				merchant_upload_file_header,
				payout_generated_file_hd
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_id=uh_batch_id
			and	uh_merchant_id=:hv_merchant_id
			and	ud_batch_mode=:hv_batch_mode
			and	fh_file_id = ud_pregen_file_id
			and	fh_status = :hv_fh_status
			and     ud_pregen_file_id IS NOT NULL;

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
                	SELECT UNIQUE ud_pregen_file_id
                	FROM    merchant_upload_file_detail,
				payout_generated_file_hd
                	WHERE   ud_status= :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_mode=:hv_batch_mode
			and	fh_file_id = ud_pregen_file_id
			and	fh_status = :hv_fh_status
			and     ud_pregen_file_id IS NOT NULL; */ 


		/* EXEC SQL OPEN  c_cursor_prefile; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0009;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )836;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_fh_status;
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
   sqlstm.offset = (unsigned int  )867;
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
  sqlstm.offset = (unsigned int  )886;
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
        sqlstm.offset = (unsigned int  )901;
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
        		SELECT	ud_batch_id,
				ud_seq_num,
				ud_txn_id,
				ud_merchant_ref,
				ud_identity_id,
				ud_account_name,
				ud_account_num,
				ud_bank_name,
				ud_branch,
				ud_phone_num,
				ud_province,
				ud_city,
				ud_payout_amount,
				ud_request_amount,
				ud_remark,
				ud_pregen_psp_id,
				ud_country,
				ud_payout_currency,
				ud_request_currency,
				ud_merchant_fee_ccy,
				ud_merchant_fee,
				ud_member_fee_ccy,
				ud_member_fee,
				ud_markup_amt,
				ud_markup_ccy
			FROM    merchant_upload_file_detail,
				merchant_upload_file_header
                	WHERE   ud_status = :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_id=uh_batch_id
			and	uh_merchant_id = :hv_merchant_id
			and	ud_batch_mode=:hv_batch_mode
			and     ud_pregen_psp_id IS NOT NULL
			order by ud_batch_id, ud_seq_num; */ 


		/* EXEC SQL OPEN  c_cursor_pspm; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0010;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )916;
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
   sqlstm.offset = (unsigned int  )947;
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
   sqlstm.sqhstv[16] = (unsigned char  *)&v_txn_country;
   sqlstm.sqhstl[16] = (unsigned long )5;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_txn_country;
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
   sqlstm.sqhstv[21] = (unsigned char  *)&v_member_fee_ccy;
   sqlstm.sqhstl[21] = (unsigned long )6;
   sqlstm.sqhsts[21] = (         int  )0;
   sqlstm.sqindv[21] = (         short *)&ind_member_fee_ccy;
   sqlstm.sqinds[21] = (         int  )0;
   sqlstm.sqharm[21] = (unsigned long )0;
   sqlstm.sqadto[21] = (unsigned short )0;
   sqlstm.sqtdso[21] = (unsigned short )0;
   sqlstm.sqhstv[22] = (unsigned char  *)&v_member_fee;
   sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[22] = (         int  )0;
   sqlstm.sqindv[22] = (         short *)&ind_member_fee;
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
   sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_ccy;
   sqlstm.sqhstl[24] = (unsigned long )6;
   sqlstm.sqhsts[24] = (         int  )0;
   sqlstm.sqindv[24] = (         short *)&ind_markup_ccy;
   sqlstm.sqinds[24] = (         int  )0;
   sqlstm.sqharm[24] = (unsigned long )0;
   sqlstm.sqadto[24] = (unsigned short )0;
   sqlstm.sqtdso[24] = (unsigned short )0;
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
  sqlstm.offset = (unsigned int  )1062;
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
        		SELECT	ud_batch_id,
				ud_seq_num,
				ud_txn_id,
				ud_merchant_ref,
				ud_identity_id,
				ud_account_name,
				ud_account_num,
				ud_bank_name,
				ud_branch,
				ud_phone_num,
				ud_province,
				ud_city,
				ud_request_amount,
				ud_payout_amount,
				ud_remark,
				ud_pregen_psp_id,
				ud_country,
				ud_request_currency,
				ud_payout_currency
         	       FROM    merchant_upload_file_detail
                	WHERE   ud_status = :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_mode=:hv_batch_mode
			and     ud_pregen_psp_id IS NOT NULL
			order by ud_batch_id, ud_seq_num; */ 


		/* EXEC SQL OPEN  c_cursor_pspwom; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0011;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1077;
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
   sqlstm.offset = (unsigned int  )1104;
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
   sqlstm.sqhstv[16] = (unsigned char  *)&v_txn_country;
   sqlstm.sqhstl[16] = (unsigned long )5;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_txn_country;
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
   sqlstm.sqhstv[18] = (unsigned char  *)&v_payout_ccy;
   sqlstm.sqhstl[18] = (unsigned long )6;
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_payout_ccy;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
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
  sqlstm.offset = (unsigned int  )1195;
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
 sqlstm.offset = (unsigned int  )1210;
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
 sqlstm.offset = (unsigned int  )1225;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetDetailByRandomWithBankMerchant(const char* csBankName, const char* csMerchantId, recordset_t* myRec)
{
	hash_t *myHash;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailrbm_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		/* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

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
	hv_batch_mode=PD_OFFLINE;

	char	csTmp[strlen(csBankName)+3];
	hv_bank_name.len = strlen(csBankName)+2;
	strcpy(csTmp,"%");
	strcat(csTmp,csBankName);
	strcat(csTmp,"%");
	csTmp[strlen(csBankName)+2]='\0';
	memcpy(hv_bank_name.arr,csTmp,hv_bank_name.len);
DEBUGLOG(("GetDetailByRandomWithBankMerchant bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetDetailByRandomWithBankMerchant merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetDetailByRandomWithBankMerchant status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getdetailrbm CURSOR FOR
		select	ud_txn_id,
			ud_batch_id,
			ud_seq_num,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee
		from	(SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random.value),
			merchant_upload_file_header
		where	ud_bank_name like :hv_bank_name
		and	ud_status = :hv_status
		and	ud_disabled = :hv_disabled
		and	uh_merchant_id = :hv_merchant_id
		and	uh_batch_id = ud_batch_id
		and	ud_batch_mode=:hv_batch_mode
                and     ud_disabled = uh_disabled
		and	ud_pregen_psp_id IS NULL; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailrbm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0012;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1240;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[0] = (unsigned long )152;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_batch_mode;
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
 if (sqlca.sqlcode < 0) goto getdetailrbm_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getdetailrbm
		INTO	:v_txn_id:ind_txn_id,
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
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
  sqlstm.offset = (unsigned int  )1275;
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
  sqlstm.sqhstv[24] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[24] = (unsigned long )13;
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_resp_code;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[25] = (unsigned long )258;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_remark;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[26] = (unsigned long )1;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[27] = (unsigned long )53;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_file_name;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[28] = (unsigned long )23;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[29] = (unsigned long )17;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_service_fee;
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
  if (sqlca.sqlcode < 0) goto getdetailrbm_error;
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
DEBUGLOG(("GetDetailByRandomWithBankMerchant batch_id=[%ld]\n",v_batch_id));
			PutField_CString(myHash,"batch_id",csBatchId);
		}

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByRandomWithBankMerchant seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant txn_id=[%s]\n",v_txn_id.arr));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant account_name= [%s]\n",v_account_name.arr));
		}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByRandomWithBankMerchant payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByRandomWithBankMerchant request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByRandomWithBankMerchant member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByRandomWithBankMerchant merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByRandomWithBankMerchant markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByRandomWithBankMerchant ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant resp_code= [%s]\n",v_resp_code.arr));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByRandomWithBankMerchant batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant file_name= [%s]\n",v_file_name.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByRandomWithBankMerchant service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByRandomWithBankMerchant psp_id= [%s]\n",v_psp_id.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailrbm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1414;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetailrbm_error;
}



DEBUGLOG(("GetDetailByRandomWithBankMerchant Normal Exit\n"));
	return  PD_OK;

getdetailrbm_error:
DEBUGLOG(("getdetailrbm_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_GetWithBankMerchantByRandom: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailrbm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1429;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int GetDetailByRandomWithBank(const char* csBankName, recordset_t* myRec)
{
	hash_t *myHash;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailrb_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		/* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

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


	char    csTmp[strlen(csBankName)+3];
        hv_bank_name.len = strlen(csBankName)+2;
        strcpy(csTmp,"%");
        strcat(csTmp,csBankName);
        strcat(csTmp,"%");
        csTmp[strlen(csBankName)+2]='\0';
        memcpy(hv_bank_name.arr,csTmp,hv_bank_name.len);

	/*
	hv_bank_name.len = strlen(csBankName);
	memcpy(hv_bank_name.arr,csBankName,hv_bank_name.len);
	*/
DEBUGLOG(("GetDetailByRandomWithBank bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetDetailByRandomWithBank status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getdetailrb CURSOR FOR
		select	ud_txn_id,
			ud_batch_id,
			ud_seq_num,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee
		from	(SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random.value),
			merchant_upload_file_header
		where	ud_bank_name like :hv_bank_name
		and	ud_status = :hv_status
		and	ud_disabled = :hv_disabled
		and	ud_batch_mode=:hv_batch_mode
		and     ud_batch_id = uh_batch_id
                and     ud_disabled = uh_disabled
		and	ud_pregen_psp_id IS NULL; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailrb; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1444;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[0] = (unsigned long )152;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetailrb_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getdetailrb
		INTO	:v_txn_id:ind_txn_id,
			:v_batch_id:ind_batch_id,
			:v_seq_num:ind_seq_num,
			:v_aux_txn_seq:ind_aux_txn_seq,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_num:ind_account_num,
			:v_account_name:ind_account_name,
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
  sqlstm.offset = (unsigned int  )1475;
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
  sqlstm.sqhstv[24] = (unsigned char  *)&v_resp_code;
  sqlstm.sqhstl[24] = (unsigned long )13;
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_resp_code;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[25] = (unsigned long )258;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_remark;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_batch_mode;
  sqlstm.sqhstl[26] = (unsigned long )1;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_batch_mode;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_file_name;
  sqlstm.sqhstl[27] = (unsigned long )53;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_file_name;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_psp_batch_id;
  sqlstm.sqhstl[28] = (unsigned long )23;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_psp_batch_id;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_fundout_date;
  sqlstm.sqhstl[29] = (unsigned long )17;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_fundout_date;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_service_fee;
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
  if (sqlca.sqlcode < 0) goto getdetailrb_error;
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
DEBUGLOG(("GetDetailByRandomWithBank batch_id=[%ld]\n",v_batch_id));
			PutField_CString(myHash,"batch_id",csBatchId);
		}

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByRandomWithBank seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByRandomWithBank txn_id=[%s]\n",v_txn_id.arr));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByRandomWithBank aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByRandomWithBank merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByRandomWithBank country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByRandomWithBank identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByRandomWithBank account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByRandomWithBank account_name= [%s]\n",v_account_name.arr));
		}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByRandomWithBank branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByRandomWithBank phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByRandomWithBank province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByRandomWithBank city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBank payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBank request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByRandomWithBank payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByRandomWithBank request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBank member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByRandomWithBank member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBank merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByRandomWithBank merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithBank markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByRandomWithBank markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByRandomWithBank ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByRandomWithBank resp_code= [%s]\n",v_resp_code.arr));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByRandomWithBank remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByRandomWithBank batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByRandomWithBank file_name= [%s]\n",v_file_name.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByRandomWithBank psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByRandomWithBank fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByRandomWithBank service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByRandomWithBank psp_id= [%s]\n",v_psp_id.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailrb; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1614;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetailrb_error;
}



DEBUGLOG(("GetDetailByRandomWithBank Normal Exit\n"));
	return  PD_OK;

getdetailrb_error:
DEBUGLOG(("getdetailrb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_GetWithBankByRandom: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailrb; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1629;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int GetDetailByRandomWithMerchant(const char* csMerchantId, recordset_t* myRec)
{
	hash_t *myHash;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetailrm_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

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
		short           ind_bank_name = -1;
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

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetDetailByRandomWithMerchant merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetDetailByRandomWithMerchant status = [%d]\n",hv_status));

	/* EXEC SQL DECLARE c_cursor_getdetailrm CURSOR FOR
		select	ud_txn_id,
			ud_batch_id,
			ud_seq_num,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_bank_name,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee
		from	(SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random.value),
			merchant_upload_file_header
		where	ud_status = :hv_status
		and	ud_disabled = :hv_disabled
		and	uh_merchant_id = :hv_merchant_id
		and	uh_batch_id = ud_batch_id
		and	uh_disabled = ud_disabled
		and	ud_batch_mode=:hv_batch_mode
		and	ud_pregen_psp_id IS NULL; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailrm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0014;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1644;
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
 if (sqlca.sqlcode < 0) goto getdetailrm_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getdetailrm
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
  sqlstm.offset = (unsigned int  )1675;
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
  if (sqlca.sqlcode < 0) goto getdetailrm_error;
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
DEBUGLOG(("GetDetailByRandomWithMerchant batch_id=[%ld]\n",v_batch_id));
			PutField_CString(myHash,"batch_id",csBatchId);
		}

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByRandomWithMerchant seq_num=[%d]\n",v_seq_num));
		}

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant txn_id=[%s]\n",v_txn_id.arr));
		}

/*aux_txn_seq*/
		if(ind_aux_txn_seq>=0){
			v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
			PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
		}


/*merchant_ref*/
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len]='\0';
			PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant merchant_ref= [%s]\n",v_merchant_ref.arr));
		}

/*country*/
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant country= [%s]\n",v_country.arr));
		}

/*identity_id*/
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len]='\0';
			PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant identity_id= [%s]\n",v_identity_id.arr));
		}

/*account_num*/
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len]='\0';
			PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant account_num= [%s]\n",v_account_num.arr));
		}

/*account_name*/
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len]='\0';
			PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant account_name= [%s]\n",v_account_name.arr));
		}

/*bank_name*/
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len]='\0';
			PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant bank_name= [%s]\n",v_bank_name.arr));
	}

/*branch*/
		if(ind_branch>=0){
			v_branch.arr[v_branch.len]='\0';
			PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant branch= [%s]\n",v_branch.arr));
		}

/*phone_num*/
		if(ind_phone_num>=0){
			v_phone_num.arr[v_phone_num.len]='\0';
			PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant phone_num= [%s]\n",v_phone_num.arr));
		}

/*province*/
		if(ind_province>=0){
		v_province.arr[v_province.len]='\0';
		PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant province= [%s]\n",v_province.arr));
	}

/*city*/
		if(ind_city>=0){
			v_city.arr[v_city.len]='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant city= [%s]\n",v_city.arr));
		}

/*payout_currency*/
		if(ind_payout_ccy>=0){
			v_payout_ccy.arr[v_payout_ccy.len]='\0';
			PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant payout_ccy= [%s]\n",v_payout_ccy.arr));
		}

/*request_currency*/
		if(ind_request_ccy>=0){
			v_request_ccy.arr[v_request_ccy.len]='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant request_ccy= [%s]\n",v_request_ccy.arr));
		}

/*payout_amount*/
		if(ind_payout_amount>=0){
			PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByRandomWithMerchant payout_amount = [%lf]\n",v_payout_amount));
	}

/*request_amount*/
		if(ind_request_amount>=0){
			PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByRandomWithMerchant request_amount = [%lf]\n",v_request_amount));
	}

/*member_fee_ccy*/
		if(ind_member_fee_ccy>=0){
			v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
			PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
		}

/*member_fee*/
		if(ind_member_fee>=0){
			PutField_Double(myHash,"member_fee",v_member_fee);
DEBUGLOG(("GetDetailByRandomWithMerchant member_fee = [%lf]\n",v_member_fee));
		}

/*merchant_fee_ccy*/
		if(ind_merchant_fee_ccy>=0){
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
			PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
		}

/*merchant_fee*/
		if(ind_merchant_fee>=0){
			PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetDetailByRandomWithMerchant merchant_fee = [%lf]\n",v_merchant_fee));
		}

/*markup_ccy*/
		if(ind_markup_ccy>=0){
			v_markup_ccy.arr[v_markup_ccy.len]='\0';
			PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant markup_ccy= [%s]\n",v_markup_ccy.arr));
		}

/*markup_amt*/
		if(ind_markup_amt>=0){
			PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetDetailByRandomWithMerchant markup_amt = [%lf]\n",v_markup_amt));
		}

/*ex_rate*/
		if(ind_ex_rate>=0){
			PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetDetailByRandomWithMerchant ex_rate = [%lf]\n",v_ex_rate));
		}

/*resp_code*/
		if(ind_resp_code>=0){
			v_resp_code.arr[v_resp_code.len]='\0';
			PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant resp_code= [%s]\n",v_resp_code.arr));
		}

/*remark*/
		if(ind_remark>=0){
			v_remark.arr[v_remark.len]='\0';
			PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant remark= [%s]\n",v_remark.arr));
		}

/*batch_mode*/
		if(ind_batch_mode>=0){
			PutField_Char(myHash,"batch_mode",v_batch_mode);
DEBUGLOG(("GetDetailByRandomWithMerchant batch_mode= [%c]\n",v_batch_mode));
		}

/*file_name*/
		if(ind_file_name>=0){
			v_file_name.arr[v_file_name.len]='\0';
			PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant file_name= [%s]\n",v_file_name.arr));
		}

/*psp_batch_id*/	
		if(ind_psp_batch_id>=0){
			v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
			PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant psp_batch_id= [%s]\n",v_psp_batch_id.arr));
		}

/*fundout_date*/
		if(ind_fundout_date>=0){
			v_fundout_date.arr[v_fundout_date.len]='\0';
			PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant fundout_date= [%s]\n",v_fundout_date.arr));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetDetailByRandomWithMerchant service_fee= [%lf]\n",v_service_fee));
		}

/*psp_id*/	
		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByRandomWithMerchant psp_id= [%s]\n",v_psp_id.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailrm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1818;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetailrm_error;
}



DEBUGLOG(("GetDetailByRandomWithMerchant Normal Exit\n"));
	return  PD_OK;

getdetailrm_error:
DEBUGLOG(("getdetailrm_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_GetWithMerchantByRandom: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailrm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1833;
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
		select	ud_txn_id,
			ud_batch_id,
			ud_seq_num,
			ud_aux_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_bank_name,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee
		from	(SELECT * FROM merchant_upload_file_detail ORDER BY dbms_random.value),
			merchant_upload_file_header
		where	ud_status = :hv_status
		and	ud_disabled = :hv_disabled
		and	ud_batch_mode=:hv_batch_mode
		and	ud_batch_id = uh_batch_id
		and	ud_disabled = uh_disabled
		and	ud_pregen_psp_id IS NULL; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1848;
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
  sqlstm.offset = (unsigned int  )1875;
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
 sqlstm.offset = (unsigned int  )2018;
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
ERRLOG("MerchantUploadFileDetail_GetWithBankByRandom: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdetailr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2033;
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
                FROM    merchant_upload_file_detail
                WHERE   ud_batch_id = :hv_batch_id
                and     ud_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM merchan\
t_upload_file_detail WHERE ud_batch_id = :b1 and ud_status = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2048;
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
                FROM    merchant_upload_file_detail
                WHERE   ud_batch_id = :hv_batch_id
                and     ud_status = :hv_void_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0 FROM merchan\
t_upload_file_detail WHERE ud_batch_id = :b1 and ud_status = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2075;
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



        /* EXEC SQL SELECT	uh_txn_count
                INTO    :v_org_cnt:ind_org_cnt
                FROM    merchant_upload_file_header
                WHERE   uh_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select uh_txn_count INTO :b0:b1 FROM merchant_upload\
_file_header WHERE uh_batch_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2102;
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_psp_id ='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        

        strcat((char*)hv_dynstmt.arr, " WHERE ud_status = 65 and ud_batch_mode = 'F' and ud_psp_id IS NOT NULL");
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
 sqlstm.offset = (unsigned int  )2125;
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
 sqlstm.offset = (unsigned int  )2144;
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
ERRLOG("MerchantUploadFileDetail_ResumeAssignedPsp: SP_ERR TxnAbort\n");
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_pregen_psp_id ='', ud_pregen_file_id='' ");
        //strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_psp_id ='',ud_generated_file_name='', ud_generated_file_id='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);        

        strcat((char*)hv_dynstmt.arr, " WHERE ud_pregen_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        strcat((char*)hv_dynstmt.arr, " and ud_batch_mode <> 'O'");
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
 sqlstm.offset = (unsigned int  )2159;
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
 sqlstm.offset = (unsigned int  )2178;
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
ERRLOG("MerchantUploadFileDetail_ResumePreGenFile: SP_ERR TxnAbort\n");
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_psp_id ='',ud_generated_file_name='', ud_generated_file_id='', ud_pregen_psp_id ='',ud_pregen_file_id='', ud_status = 65 , ud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, ",ud_update_user= '");
	strcat((char*)hv_dynstmt.arr, csUser);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, " WHERE ud_generated_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        strcat((char*)hv_dynstmt.arr, " AND ud_status = 70");
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
 sqlstm.offset = (unsigned int  )2193;
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
 sqlstm.offset = (unsigned int  )2212;
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
ERRLOG("MerchantUploadFileDetail_ResumeGeneratedFile: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int ResumeGeneratedTxn(const char* csTxnId, const char* csUser)
{
	char*   csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO resumegtxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeGeneratedTxn: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_psp_id ='',ud_generated_file_name='', ud_generated_file_id='', ud_pregen_psp_id ='',ud_pregen_file_id='', ud_status = 65 , ud_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, ",ud_update_user= '");
	strcat((char*)hv_dynstmt.arr, csUser);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, " WHERE ud_txn_id = '");
        strcat((char*)hv_dynstmt.arr, csTxnId);
        strcat((char*)hv_dynstmt.arr, "'");
        strcat((char*)hv_dynstmt.arr, " AND ud_status = 70");
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
 sqlstm.offset = (unsigned int  )2227;
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
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2246;
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
 sqlstm.offset = (unsigned int  )2261;
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
                        	:hv_return_value := sp_get_online_batch_mid(
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
         sqlstm.stmt = "begin :hv_return_value := sp_get_online_batch_mid (\
 :hv_merchant:ind_merchant , :hv_batch_mode:ind_batch_mode , :hv_status:ind_s\
tatus , :hv_disabled:ind_disabled , :c_cursor_urldt ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2280;
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
                        	:hv_return_value := sp_get_online_batch(
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
         sqlstm.stmt = "begin :hv_return_value := sp_get_online_batch ( :hv\
_batch_mode:ind_batch_mode , :hv_status:ind_status , :hv_disabled:ind_disable\
d , :c_cursor_urldt ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2319;
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
                        sqlstm.offset = (unsigned int  )2354;
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
 sqlstm.offset = (unsigned int  )2513;
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
 sqlstm.offset = (unsigned int  )2532;
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
ERRLOG("DBMerchantUploadFileDetail GetOnlineBatchRecord: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2551;
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
 sqlstm.offset = (unsigned int  )2570;
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
	//char            cTmp;
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
                        :hv_return_value := sp_merch_upload_dt_insert(
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
					:hv_user:ind_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_insert ( :hv_b\
atch_id:ind_batch_id , :hv_seq_num:ind_seq_num , :hv_txn_id:ind_txn_id , :hv_\
aux_txn_id:ind_aux_txn_id , :hv_merchant_ref:ind_merchant_ref , :hv_country:i\
nd_country , :hv_identity_id:ind_identity_id , :hv_account_num:ind_account_nu\
m , :hv_account_name:ind_account_name , :hv_bank_name:ind_bank_name , :hv_ban\
k_code:ind_bank_code , :hv_branch:ind_branch , :hv_phone_num:ind_phone_num , \
:hv_province:ind_province , :hv_city:ind_city , :hv_payout_currency:ind_payou\
t_currency , :hv_payout_amount:ind_payout_amount , :hv_request_currency:ind_r\
equest_currency , :hv_request_amount:ind_request_amount , :hv_merchant_fee_cc\
y:ind_merchant_fee_ccy , :hv_merchant_fee:ind_merchant_fee , :hv_member_fee_c\
cy:ind_member_fee_ccy , :hv_member_fee:ind_member_fee , :hv_markup_ccy:ind_ma\
rkup_ccy , :hv_markup_amt:ind_markup_amt , :hv_ex_rate:ind_ex_rate , :hv_stat\
us:ind_status , :hv_remark:ind_remark , :hv_user:ind_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2589;
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
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[29] = (unsigned long )22;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_user;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
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
ERRLOG("MerchantUploadFileDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantUploadFileDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileDetail_Add: SP_ERR\n");
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
		select	ud_seq_num,
			ud_txn_id,
			ud_merchant_ref,
			ud_country,
			ud_identity_id,
			ud_account_num,
			ud_account_name,
			ud_bank_name,
			ud_bank_code,
			ud_branch,
			ud_phone_num,
			ud_province,
			ud_city,
			ud_payout_amount,
			ud_request_amount,
			ud_payout_currency,
			ud_request_currency,
			ud_member_fee_ccy,
			ud_member_fee,
			ud_merchant_fee_ccy,
			ud_merchant_fee,
			ud_markup_ccy,
			ud_markup_amt,
			ud_exchange_rate,
			ud_status,
			ud_response_code,
			ud_remark,
			ud_batch_mode,
			ud_generated_file_name,
			ud_psp_batch_id,
			ud_fundout_date,
			ud_service_fee,
			ud_psp_id,
			ud_generated_file_id
		from	merchant_upload_file_detail
		where	ud_batch_id =:hv_batch_id
		and	ud_disabled = :hv_disabled
		and	ud_aux_txn_id is NULL
		and	ud_status not in (:hv_status_c,:hv_status_r)
		order by ud_seq_num; */ 


	/* EXEC SQL OPEN  c_cursor_getuvpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0022;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2724;
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
  sqlstm.offset = (unsigned int  )2755;
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
 sqlstm.offset = (unsigned int  )2906;
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
ERRLOG("MerchantUploadFileDetail_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getuvpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2921;
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
 sqlstm.offset = (unsigned int  )2936;
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
                        	:hv_return_value := sp_merch_upload_dt_get(
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
         sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_get ( \
:hv_batch_id:ind_in_batch_id , :hv_seq_num:ind_in_seq_num , :hv_bank_name:ind\
_in_bank_name , :hv_status:ind_in_status , :hv_min_amt:ind_min_amt , :hv_max_\
amt:ind_max_amt , :hv_file_id:ind_in_file_id , :c_cursor_dtcon ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )2955;
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
                        sqlstm.offset = (unsigned int  )3006;
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
 sqlstm.offset = (unsigned int  )3177;
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
 sqlstm.offset = (unsigned int  )3196;
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
ERRLOG("DBMerchantUploadFileDetail GetDetailByCondition: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3215;
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
 sqlstm.offset = (unsigned int  )3234;
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


        /* EXEC SQL SELECT max(ud_approve_id)
                INTO    :v_app_id:ind_app_id
                FROM    merchant_upload_file_detail
		WHERE	ud_approve_id is NOT NULL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max ( ud_approve_id ) INTO :b0:b1 FROM mercha\
nt_upload_file_detail WHERE ud_approve_id is NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3253;
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


        /* EXEC SQL SELECT max(ud_preapprove_id)
                INTO    :v_app_id:ind_app_id
                FROM    merchant_upload_file_detail
		WHERE	ud_preapprove_id is NOT NULL; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max ( ud_preapprove_id ) INTO :b0:b1 FROM mer\
chant_upload_file_detail WHERE ud_preapprove_id is NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3272;
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_preapprove_id ='' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
        strcat((char*)hv_dynstmt.arr, " WHERE ud_status = 69 and ud_batch_mode = 'F' ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("ResumeUnusedPreApproveId: pre_approve_id < [%d]\n",iApproveId));
	sprintf(csBuf,"%d",iApproveId);
	strcat((char*)hv_dynstmt.arr, "and ud_preapprove_id < ");
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
 sqlstm.offset = (unsigned int  )3291;
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
 sqlstm.offset = (unsigned int  )3310;
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
ERRLOG("MerchantUploadFileDetail_ResumeUnusedPreApproveId: SP_ERR\n");
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
 sqlstm.offset = (unsigned int  )3325;
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
                        	:hv_return_value := sp_merch_upload_get_pre_ap(
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
         sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_get_pre_a\
p ( :hv_pre_approve_id:ind_pre_approve_id , :hv_in_status:ind_in_status , :c_\
cursor_dtcon_pre ) ; END ;";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )3344;
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
                        sqlstm.offset = (unsigned int  )3375;
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
 sqlstm.offset = (unsigned int  )3546;
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
 sqlstm.offset = (unsigned int  )3565;
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
ERRLOG("DBMerchantUploadFileDetail GetDetailByPreApproveId: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dtcon_pre; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3584;
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
 sqlstm.offset = (unsigned int  )3603;
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
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
        if(GetField_CString(hRls,"file_id",&csFileId)){
DEBUGLOG(("UpdateFileNameByFileId: generated_file_id = [%s]\n",csFileId));
        }

        if(GetField_CString(hRls,"generated_file_name",&csBuf)){
DEBUGLOG(("UpdateFileNameByFileId: generated_file_name = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, " ud_generated_file_name = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE ud_generated_file_id = ");
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
 sqlstm.offset = (unsigned int  )3622;
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
 sqlstm.offset = (unsigned int  )3641;
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
ERRLOG("MerchantUploadFileDetail_UpdateFileNameByFileId: SP_ERR TxnAbort\n");
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

		short           ind_merchant_id= -1;
		short           ind_batch_id_list= -1;
		short           ind_in_bank_name= -1;
		short           ind_status= -1;
		short           ind_in_batch_mode= -1;

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


	hv_in_batch_mode = PD_OFFLINE;
	ind_in_batch_mode = 0;

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
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
 sqlstm.offset = (unsigned int  )3656;
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
			:hv_return_value := sp_merch_upload_dt_random(
                                                                :hv_merchant_id:ind_merchant_id,
                                                                :hv_batch_id_list:ind_batch_id_list,
                                                                :hv_in_bank_name:ind_in_bank_name,
                                                                :hv_status:ind_status,
                                                                :hv_in_batch_mode:ind_in_batch_mode,
                                                                :c_cursor_dt_random);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_random ( :hv_m\
erchant_id:ind_merchant_id , :hv_batch_id_list:ind_batch_id_list , :hv_in_ban\
k_name:ind_in_bank_name , :hv_status:ind_status , :hv_in_batch_mode:ind_in_ba\
tch_mode , :c_cursor_dt_random ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3675;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_dt_random;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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
			:v_service_fee:ind_service_fee; */ 

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
 sqlstm.offset = (unsigned int  )3865;
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
        sqlstm.offset = (unsigned int  )3884;
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
ERRLOG("MerchantUploadFileDetail_GetWithBankByRandomWithPara: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dt_random; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3903;
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
        sqlstm.offset = (unsigned int  )3922;
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
                FROM    merchant_upload_file_detail,
			merchant_upload_file_header
                WHERE   uh_merchant_id = :hv_merchant_id
                and     ud_merchant_ref = :hv_merchant_ref
		and	uh_batch_id = ud_batch_id
		and	uh_disabled = 0
		and	ud_disabled = 0
                and     ud_status not in ('67', '68'); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( COUNT ( * ) , 0 ) INTO :b0:b1 FROM merc\
hant_upload_file_detail , merchant_upload_file_header WHERE uh_merchant_id = \
:b2 and ud_merchant_ref = :b3 and uh_batch_id = ud_batch_id and uh_disabled =\
 0 and ud_disabled = 0 and ud_status not in ( '67' , '68' ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3941;
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


int MatchRespTxn_ForUpdate(const char* csTxnSeq,
                 const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_ForUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int             hv_status;
	
		int	        v_seq_num;
		short		ind_seq_num = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn_ForUpdate txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchRespTxn_ForUpdate status = [%d]\n",hv_status));

        /* EXEC SQL SELECT ud_seq_num
                INTO    :v_seq_num:ind_seq_num
                FROM    merchant_upload_file_detail
                WHERE   ud_txn_id = :hv_txn_id
                and     ud_status = :hv_status
		for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ud_seq_num INTO :b0:b1 FROM merchant_upload_f\
ile_detail WHERE ud_txn_id = :b2 and ud_status = :b3 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3968;
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

                :hv_return_value := sp_merch_upload_dt_delete(
                                :hv_batch_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 39;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_delete \
( :hv_batch_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3995;
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



int GetRecordByRandomWithPara(const hash_t *hTxn,recordset_t* myRec)
{
	hash_t	*myHash;
	char	*csTmp;
	char	cTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getrecwp_error; */ 

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
		/* varchar		hv_payout_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_ccy;

		int		hv_pregen_id;
		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		short           ind_merchant_id= -1;
		short           ind_batch_id_list= -1;
		short           ind_in_bank_name= -1;
		short           ind_status= -1;
		short           ind_in_batch_mode= -1;
		short           ind_payout_ccy= -1;
		short           ind_pregen_id= -1;
		short           ind_psp_id= -1;

		SQL_CURSOR      c_cursor_rec_random;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double		v_payout_amount;

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
 sqlstm.offset = (unsigned int  )4018;
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
			:hv_return_value := sp_merch_upload_dt_random_rec(
						:hv_merchant_id:ind_merchant_id,
						:hv_batch_id_list:ind_batch_id_list,
						:hv_in_bank_name:ind_in_bank_name,
						:hv_status:ind_status,
						:hv_in_batch_mode:ind_in_batch_mode,
						:hv_payout_ccy:ind_payout_ccy,
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
 sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_random_rec ( :\
hv_merchant_id:ind_merchant_id , :hv_batch_id_list:ind_batch_id_list , :hv_in\
_bank_name:ind_in_bank_name , :hv_status:ind_status , :hv_in_batch_mode:ind_i\
n_batch_mode , :hv_payout_ccy:ind_payout_ccy , :hv_pregen_id:ind_pregen_id , \
:hv_psp_id:ind_psp_id , :c_cursor_rec_random ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4037;
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
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_pregen_id;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_pregen_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[8] = (unsigned long )12;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_psp_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_rec_random;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
                        sqlstm.offset = (unsigned int  )4092;
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
 sqlstm.offset = (unsigned int  )4119;
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
        sqlstm.offset = (unsigned int  )4138;
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
 sqlstm.offset = (unsigned int  )4157;
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
        sqlstm.offset = (unsigned int  )4176;
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
	hash_t	*myHash;
	int	iCnt = 0;
	//char	cMode;
	char	csBatchId[PD_TXN_SEQ_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO genpsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		int		hv_status;
		int		hv_gen_id;
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

		/*varchar	v_member_fee_ccy[PD_CCY_ID_LEN+1];
		varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1];
		varchar		v_markup_ccy[PD_CCY_ID_LEN+1];
		double		v_markup_amt;
		double		v_member_fee;
		double		v_merchant_fee;*/

		short		ind_txn_id = -1;
		short		ind_psp_id = -1;
		short		ind_seq_num = -1;
		short		ind_batch_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_amount = -1;
		short		ind_remark = -1;
		short		ind_txn_country = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_request_amount = -1;
		/*short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short		ind_markup_amt= -1;
		short		ind_markup_ccy= -1;
		*/

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_gen_id = iGenId;
DEBUGLOG(("GetPregeneratedRecords gen_id = [%d]\n",hv_gen_id));

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
DEBUGLOG(("GetPregeneratedRecords status = [%d]\n",hv_status));

	hv_disabled = 0;
	hv_batch_mode=cBatchMode;
DEBUGLOG(("GetPregeneratedRecords batch_mode = [%c]\n",hv_batch_mode));

		/* EXEC SQL DECLARE c_cursor_genpsp CURSOR FOR
        		SELECT	ud_batch_id,
				ud_seq_num,
				ud_txn_id,
				ud_merchant_ref,
				ud_identity_id,
				ud_account_name,
				ud_account_num,
				ud_bank_name,
				ud_bank_code,
				ud_branch,
				ud_phone_num,
				ud_province,
				ud_city,
				ud_request_amount,
				ud_payout_amount,
				ud_remark,
				pt_psp_id,
				ud_country,
				ud_request_currency,
				ud_payout_currency
         	       FROM	merchant_upload_file_detail,
				payout_generated_tmp
                	WHERE   ud_status = :hv_status
                	and     ud_disabled = :hv_disabled
			and	ud_batch_mode=:hv_batch_mode
			and     ud_txn_id = pt_txn_id
			and	pt_id = :hv_gen_id
			order by pt_psp_id, ud_batch_id, ud_seq_num
			for update; */ 


		/* EXEC SQL OPEN  c_cursor_genpsp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 39;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0032;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4195;
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
				:v_payout_ccy:ind_payout_ccy; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 39;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4226;
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
  sqlstm.offset = (unsigned int  )4321;
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
 sqlstm.offset = (unsigned int  )4336;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetPregenSummary(const int iGenId, recordset_t* myRec)
{
	hash_t	*myHash;
	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO genpspsum_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_disabled;
		int		hv_gen_id;

		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		/* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar         v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		int		v_count;

		short		ind_batch_id = -1;
		short		ind_file_id = -1;
		short		ind_psp_id = -1;
		short           ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_count = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_gen_id = iGenId;
DEBUGLOG(("GetPregenSummary gen_id = [%d]\n",hv_gen_id));

	hv_disabled = 0;

		/* EXEC SQL DECLARE c_cursor_genpspsum CURSOR FOR
        		SELECT	uh_batch_id,
				fd_file_id,
				uh_merchant_id,
				uh_service_code,
				pt_psp_id,
				count(fd_txn_id)
         	       FROM	merchant_upload_file_header,
				payout_generated_tmp,
				payout_generated_file_dt
                	WHERE   pt_txn_id = fd_upload_txn_id
			and	fd_batch_id = uh_batch_id
                	and     uh_disabled = :hv_disabled
			and	pt_id = :hv_gen_id
			group by  uh_batch_id,
				  fd_file_id,
                                  uh_merchant_id,
                                  uh_service_code,
                                  pt_psp_id; */ 


		/* EXEC SQL OPEN  c_cursor_genpspsum; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 39;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0033;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4351;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_disabled;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_gen_id;
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
  if (sqlca.sqlcode < 0) goto genpspsum_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_genpspsum
			INTO
				:v_batch_id:ind_batch_id,
				:v_file_id:ind_file_id,
				:v_merchant_id:ind_merchant_id,
				:v_service_code:ind_service_code,
				:v_psp_id:ind_psp_id,
				:v_count:ind_count; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 39;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4374;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&v_file_id;
   sqlstm.sqhstl[1] = (unsigned long )19;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_file_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_id;
   sqlstm.sqhstl[2] = (unsigned long )18;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
   sqlstm.sqhstl[3] = (unsigned long )6;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_service_code;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[4] = (unsigned long )13;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_psp_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_count;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_count;
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
   if (sqlca.sqlcode < 0) goto genpspsum_error;
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
DEBUGLOG(("GetPregenSummary file_id= [%s]\n",v_file_id.arr));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPregenSummary psp_id= [%s]\n",v_psp_id.arr));
			}

/*batch_id*/
			if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetPregenSummary batch_id= [%s]\n",v_batch_id.arr));
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
				PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetPregenSummary merchant_id= [%s]\n",v_merchant_id.arr));
			}

/*service_code*/
			if(ind_service_code>=0){
				v_service_code.arr[v_service_code.len]='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetPregenSummary service_code= [%s]\n",v_service_code.arr));
			}

/*count*/
			if(ind_count>=0){
				PutField_Int(myHash,"count",v_count);
DEBUGLOG(("GetPregenSummary count= [%d]\n",v_count));
			}

			iCnt ++;
			RecordSet_Add(myRec,myHash);

		}while(PD_TRUE);

		/* EXEC SQL CLOSE c_cursor_genpspsum; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 39;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )4413;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto genpspsum_error;
}


	
	if(iCnt>0){
DEBUGLOG(("GetPregenSummary Normal Exit\n"));
		return  PD_OK;
	}
	else{
DEBUGLOG(("GetPregenSummary Normal Exit, No Record\n"));
		return  PD_ERR;
	}

genpspsum_error:
DEBUGLOG(("GetPregenSummary_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_genpspsum; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4428;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
