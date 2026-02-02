
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
           char  filnam[10];
};
static struct sqlcxp sqlfpn =
{
    9,
    "RuleLB.pc"
};


static unsigned int sqlctx = 41099;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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

 static char *sq0003 = 
"SELECT count ( * ) as cnt FROM ( SELECT rm_psp_id , rpp_limit , nvl ( tc_co\
unter , 0 ) as counter , nvl ( tc_total_counter , 0 ) as total_counter FROM (\
 SELECT rm_psp_id , rpp_limit FROM rule_psp_lb_mapping , psp_detail a , psp_m\
aster b , rule_psp_lb_psp WHERE rm_pool_id = :b0 AND rm_disabled = 0 AND rm_p\
sp_id = a . psp_id AND a . disabled = 0 AND a . online_mode = 'Y' AND a . sta\
tus = 'O' AND a . client_id = b . pm_client_id AND b . pm_status = 'O' AND rm\
_psp_id = rpp_psp_id AND rpp_disabled = 0 ) a LEFT JOIN txn_counters ON rm_ps\
p_id = tc_party_id AND tc_txn_code in ( 'DSI' , 'DSP' ) AND tc_country_id = :\
b1 AND tc_channel_code in ( 'WEB' , 'XPY' ) AND tc_service_code = :b2 AND TC_\
type = :b3 AND tc_category = :b4 AND Tc_party_type = :b5 ) WHERE ( rpp_limit \
>= ( total_counter + :b6 ) or rpp_limit = 0 )            ";

 static char *sq0007 = 
"SELECT count ( * ) FROM rule_psp_lb_criteria where rc_service_code = :b0 an\
d rc_allow_special_region = 1 and rc_disabled = 0            ";

 static char *sq0014 = 
"SELECT count ( * ) FROM rule_psp_lb_criteria , system_parameter where rc_pa\
rty_id = :b0 and rc_ccy = :b1 and rc_channel_code = :b2 and rc_service_code =\
 :b3 and rc_country = :b4 and rc_allow_special_region = 0 and rc_max_transact\
ion_amount >= :b5 and rc_max_transaction_amount > 0 and rc_max_transaction_am\
ount <= sp_val and rc_disabled = 0 and ( 'A' = :b6 or rc_card_type_opt = :b6 \
) and sp_code = 'LB_SMALL_AMT'            ";

 static char *sq0021 = 
"SELECT count ( * ) FROM rule_psp_lb_criteria where rc_party_id = :b0 and rc\
_ccy = :b1 and rc_channel_code = :b2 and rc_service_code = :b3 and rc_country\
 = :b4 and rc_allow_special_region = 1 and rc_disabled = 0 and ( 'A' = :b5 or\
 rc_card_type_opt = :b5 )            ";

 static char *sq0022 = 
"SELECT pool_id , pool_desc , pool_limit , pool_ratio , pool_priority FROM (\
 SELECT pool_id , pool_desc , pool_limit , pool_ratio , pool_priority , pool_\
pid , pid_limit , approved_amt pid_approved_amt FROM ( select pool_id , pool_\
desc , pool_limit , pool_ratio , pool_priority , pool_pid , pid_limit , appro\
ved_amt , sum ( request_amt ) OVER ( PARTITION BY pool_id ) pool_request_amt \
, sum ( approved_amt ) OVER ( PARTITION BY pool_id ) pool_approved_amt from r\
ule_lb_scheme_detail_view where scheme_id = :b0 and int_bank_code = :b1 ) whe\
re ( pool_approved_amt + :b2 <= pool_limit or pool_limit = 0 ) ) WHERE pid_ap\
proved_amt + :b2 <= pid_limit group by pool_id , pool_desc , pool_limit , poo\
l_ratio , pool_priority order by pool_priority desc , pool_ratio desc        \
    ";

 static char *sq0023 = 
"SELECT pool_id , pool_ratio , pool_priority , pool_request_amt , pool_total\
_request_amt , pool_approved_amt , pool_total_approved_amt FROM ( select pool\
_id , pool_ratio , pool_priority , sum ( request_amt ) OVER ( PARTITION BY po\
ol_id ) pool_request_amt , sum ( total_request_amt ) OVER ( PARTITION BY pool\
_id ) pool_total_request_amt , sum ( approved_amt ) OVER ( PARTITION BY pool_\
id ) pool_approved_amt , sum ( total_approved_amt ) OVER ( PARTITION BY pool_\
id ) pool_total_approved_amt from rule_lb_scheme_detail_view where scheme_id \
= :b0 and pool_id = :b1 group by pool_id , pool_ratio , pool_priority , pool_\
pid , approved_amt , total_approved_amt , request_amt , total_request_amt ) g\
roup by pool_id , pool_ratio , pool_priority , pool_approved_amt , pool_total\
_approved_amt , pool_request_amt , pool_total_request_amt            ";

 static char *sq0024 = 
"SELECT pool_id , pool_pid , pool_pid_ratio , pool_pid_priority , request_am\
t , sum ( request_amt ) OVER ( PARTITION BY pool_id ) pool_request_amt , CLIE\
NT_ID , REJ_SMALL_DELTA_AMT from rule_lb_scheme_detail_view , psp_detail wher\
e scheme_id = :b0 and pool_id = :b1 and int_bank_code = :b2 and approved_amt \
+ :b3 <= pid_limit and pool_pid = psp_id and ( ( deposit_card_type = card_typ\
e_opt ) or deposit_card_type = 'A' ) order by pool_pid_priority desc , pool_p\
id_ratio desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,249,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,415,0,6,250,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,3,0,0,2,102,0,0,
87,0,0,0,0,0,13,281,0,0,7,1,0,1,0,1,102,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,9,0,0,
130,0,0,0,0,0,15,332,0,0,1,1,0,1,0,1,102,0,0,
149,0,0,0,0,0,78,333,0,0,1,1,0,1,0,3,102,0,0,
168,0,0,0,0,0,15,338,0,0,1,1,0,1,0,1,102,0,0,
187,0,0,0,0,0,78,339,0,0,1,1,0,1,0,3,102,0,0,
206,0,0,0,0,0,15,345,0,0,1,1,0,1,0,1,102,0,0,
225,0,0,0,0,0,78,346,0,0,1,1,0,1,0,3,102,0,0,
244,0,0,0,0,0,15,354,0,0,1,1,0,1,0,1,102,0,0,
263,0,0,0,0,0,78,355,0,0,1,1,0,1,0,3,102,0,0,
282,0,0,2,0,0,17,430,0,0,1,1,0,1,0,1,9,0,0,
301,0,0,2,0,0,45,434,0,0,0,0,0,1,0,
316,0,0,2,0,0,13,436,0,0,3,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,
343,0,0,2,0,0,15,471,0,0,0,0,0,1,0,
358,0,0,2,0,0,15,478,0,0,0,0,0,1,0,
373,0,0,3,825,0,9,572,0,2049,7,7,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
1,1,0,0,1,4,0,0,
416,0,0,3,0,0,13,574,0,0,1,0,0,1,0,2,3,0,0,
435,0,0,3,0,0,15,594,0,0,0,0,0,1,0,
450,0,0,3,0,0,15,602,0,0,0,0,0,1,0,
465,0,0,4,0,0,17,661,0,0,1,1,0,1,0,1,9,0,0,
484,0,0,4,0,0,45,665,0,0,0,0,0,1,0,
499,0,0,4,0,0,13,667,0,0,1,0,0,1,0,2,3,0,0,
518,0,0,4,0,0,15,684,0,0,0,0,0,1,0,
533,0,0,4,0,0,15,691,0,0,0,0,0,1,0,
548,0,0,4,0,0,17,751,0,0,1,1,0,1,0,1,9,0,0,
567,0,0,4,0,0,45,755,0,0,0,0,0,1,0,
582,0,0,4,0,0,13,757,0,0,1,0,0,1,0,2,3,0,0,
601,0,0,4,0,0,15,774,0,0,0,0,0,1,0,
616,0,0,4,0,0,15,781,0,0,0,0,0,1,0,
631,0,0,0,0,0,56,827,0,0,1,1,0,1,0,3,102,0,0,
650,0,0,5,107,0,6,828,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
677,0,0,0,0,0,13,847,0,0,6,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
4,0,0,
716,0,0,0,0,0,15,891,0,0,1,1,0,1,0,1,102,0,0,
735,0,0,0,0,0,78,892,0,0,1,1,0,1,0,3,102,0,0,
754,0,0,0,0,0,15,901,0,0,1,1,0,1,0,1,102,0,0,
773,0,0,0,0,0,78,902,0,0,1,1,0,1,0,3,102,0,0,
792,0,0,0,0,0,56,959,0,0,1,1,0,1,0,3,102,0,0,
811,0,0,6,124,0,6,960,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
842,0,0,0,0,0,13,981,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,
885,0,0,0,0,0,15,1032,0,0,1,1,0,1,0,1,102,0,0,
904,0,0,0,0,0,78,1033,0,0,1,1,0,1,0,3,102,0,0,
923,0,0,0,0,0,15,1042,0,0,1,1,0,1,0,1,102,0,0,
942,0,0,0,0,0,78,1043,0,0,1,1,0,1,0,3,102,0,0,
961,0,0,7,136,0,9,1075,0,2049,1,1,0,1,0,1,9,0,0,
980,0,0,7,0,0,13,1077,0,0,1,0,0,1,0,2,3,0,0,
999,0,0,7,0,0,15,1096,0,0,0,0,0,1,0,
1014,0,0,7,0,0,15,1104,0,0,0,0,0,1,0,
1029,0,0,0,0,0,56,1155,0,0,1,1,0,1,0,3,102,0,0,
1048,0,0,8,113,0,6,1156,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
1075,0,0,0,0,0,13,1177,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
1122,0,0,0,0,0,15,1234,0,0,1,1,0,1,0,1,102,0,0,
1141,0,0,0,0,0,78,1235,0,0,1,1,0,1,0,3,102,0,0,
1160,0,0,0,0,0,15,1244,0,0,1,1,0,1,0,1,102,0,0,
1179,0,0,0,0,0,78,1245,0,0,1,1,0,1,0,3,102,0,0,
1198,0,0,9,144,0,6,1488,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,9,0,0,
1229,0,0,0,0,0,56,1579,0,0,1,1,0,1,0,3,102,0,0,
1248,0,0,10,191,0,6,1580,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
2,102,0,0,
1287,0,0,0,0,0,13,1596,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
1310,0,0,0,0,0,56,1686,0,0,1,1,0,1,0,3,102,0,0,
1329,0,0,11,138,0,6,1687,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
1360,0,0,0,0,0,13,1709,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
1407,0,0,0,0,0,15,1766,0,0,1,1,0,1,0,1,102,0,0,
1426,0,0,0,0,0,78,1767,0,0,1,1,0,1,0,3,102,0,0,
1445,0,0,0,0,0,15,1776,0,0,1,1,0,1,0,1,102,0,0,
1464,0,0,0,0,0,78,1777,0,0,1,1,0,1,0,3,102,0,0,
1483,0,0,0,0,0,56,1962,0,0,1,1,0,1,0,3,102,0,0,
1502,0,0,12,401,0,6,1963,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
1565,0,0,0,0,0,13,1996,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
1612,0,0,0,0,0,15,2064,0,0,1,1,0,1,0,1,102,0,0,
1631,0,0,0,0,0,78,2065,0,0,1,1,0,1,0,3,102,0,0,
1650,0,0,0,0,0,15,2074,0,0,1,1,0,1,0,1,102,0,0,
1669,0,0,0,0,0,78,2075,0,0,1,1,0,1,0,3,102,0,0,
1688,0,0,0,0,0,56,2147,0,0,1,1,0,1,0,3,102,0,0,
1707,0,0,13,226,0,6,2148,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,2,102,0,0,
1750,0,0,0,0,0,13,2165,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
1773,0,0,14,425,0,9,2272,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,4,0,0,1,1,0,0,1,1,0,0,
1820,0,0,14,0,0,13,2274,0,0,1,0,0,1,0,2,3,0,0,
1839,0,0,14,0,0,15,2293,0,0,0,0,0,1,0,
1854,0,0,14,0,0,15,2302,0,0,0,0,0,1,0,
1869,0,0,0,0,0,56,2472,0,0,1,1,0,1,0,3,102,0,0,
1888,0,0,15,355,0,6,2473,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
1947,0,0,0,0,0,13,2508,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
1994,0,0,0,0,0,15,2576,0,0,1,1,0,1,0,1,102,0,0,
2013,0,0,0,0,0,78,2577,0,0,1,1,0,1,0,3,102,0,0,
2032,0,0,0,0,0,15,2586,0,0,1,1,0,1,0,1,102,0,0,
2051,0,0,0,0,0,78,2587,0,0,1,1,0,1,0,3,102,0,0,
2070,0,0,0,0,0,56,2773,0,0,1,1,0,1,0,3,102,0,0,
2089,0,0,16,402,0,6,2774,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
2152,0,0,0,0,0,13,2805,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
2199,0,0,0,0,0,15,2862,0,0,1,1,0,1,0,1,102,0,0,
2218,0,0,0,0,0,78,2863,0,0,1,1,0,1,0,3,102,0,0,
2237,0,0,0,0,0,15,2872,0,0,1,1,0,1,0,1,102,0,0,
2256,0,0,0,0,0,78,2873,0,0,1,1,0,1,0,3,102,0,0,
2275,0,0,0,0,0,56,3011,0,0,1,1,0,1,0,3,102,0,0,
2294,0,0,17,360,0,6,3012,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,3,0,0,2,102,0,0,
2353,0,0,0,0,0,13,3043,0,0,10,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2408,0,0,0,0,0,15,3112,0,0,1,1,0,1,0,1,102,0,0,
2427,0,0,0,0,0,78,3113,0,0,1,1,0,1,0,3,102,0,0,
2446,0,0,0,0,0,15,3122,0,0,1,1,0,1,0,1,102,0,0,
2465,0,0,0,0,0,78,3123,0,0,1,1,0,1,0,3,102,0,0,
2484,0,0,0,0,0,56,3222,0,0,1,1,0,1,0,3,102,0,0,
2503,0,0,18,256,0,6,3223,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,4,0,0,2,102,0,0,
2550,0,0,0,0,0,13,3251,0,0,10,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2605,0,0,0,0,0,15,3320,0,0,1,1,0,1,0,1,102,0,0,
2624,0,0,0,0,0,78,3321,0,0,1,1,0,1,0,3,102,0,0,
2643,0,0,0,0,0,15,3330,0,0,1,1,0,1,0,1,102,0,0,
2662,0,0,0,0,0,78,3331,0,0,1,1,0,1,0,3,102,0,0,
2681,0,0,19,287,0,4,3366,0,0,6,5,0,1,0,2,4,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,
2720,0,0,0,0,0,56,3517,0,0,1,1,0,1,0,3,102,0,0,
2739,0,0,20,334,0,6,3518,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
2794,0,0,0,0,0,13,3547,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
2841,0,0,0,0,0,15,3604,0,0,1,1,0,1,0,1,102,0,0,
2860,0,0,0,0,0,78,3605,0,0,1,1,0,1,0,3,102,0,0,
2879,0,0,0,0,0,15,3614,0,0,1,1,0,1,0,1,102,0,0,
2898,0,0,0,0,0,78,3615,0,0,1,1,0,1,0,3,102,0,0,
2917,0,0,21,266,0,9,3684,0,2049,7,7,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,1,0,0,1,1,0,0,
2960,0,0,21,0,0,13,3686,0,0,1,0,0,1,0,2,3,0,0,
2979,0,0,21,0,0,15,3705,0,0,0,0,0,1,0,
2994,0,0,21,0,0,15,3714,0,0,0,0,0,1,0,
3009,0,0,22,772,0,9,3804,0,2049,4,4,0,1,0,1,3,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
3040,0,0,22,0,0,13,3806,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
3075,0,0,22,0,0,15,3854,0,0,0,0,0,1,0,
3090,0,0,22,0,0,15,3869,0,0,0,0,0,1,0,
3105,0,0,23,837,0,9,3954,0,2049,2,2,0,1,0,1,3,0,0,1,3,0,0,
3128,0,0,23,0,0,13,3956,0,0,7,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,
3171,0,0,23,0,0,15,4008,0,0,0,0,0,1,0,
3186,0,0,23,0,0,15,4023,0,0,0,0,0,1,0,
3201,0,0,24,485,0,9,4109,0,2049,4,4,0,1,0,1,3,0,0,1,3,0,0,1,9,0,0,1,4,0,0,
3232,0,0,24,0,0,13,4111,0,0,8,0,0,1,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
2,4,0,0,2,9,0,0,2,3,0,0,
3279,0,0,24,0,0,15,4183,0,0,0,0,0,1,0,
3294,0,0,24,0,0,15,4198,0,0,0,0,0,1,0,
3309,0,0,0,0,0,56,4373,0,0,1,1,0,1,0,3,102,0,0,
3328,0,0,25,330,0,6,4377,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
3383,0,0,26,366,0,6,4392,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
3442,0,0,27,329,0,6,4409,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
3497,0,0,28,392,0,6,4425,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
3560,0,0,0,0,0,13,4457,0,0,6,1,0,1,0,1,102,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,
3599,0,0,0,0,0,15,4494,0,0,1,1,0,1,0,1,102,0,0,
3618,0,0,0,0,0,78,4495,0,0,1,1,0,1,0,3,102,0,0,
3637,0,0,0,0,0,15,4500,0,0,1,1,0,1,0,1,102,0,0,
3656,0,0,0,0,0,78,4501,0,0,1,1,0,1,0,3,102,0,0,
3675,0,0,0,0,0,15,4507,0,0,1,1,0,1,0,1,102,0,0,
3694,0,0,0,0,0,78,4508,0,0,1,1,0,1,0,3,102,0,0,
3713,0,0,0,0,0,15,4516,0,0,1,1,0,1,0,1,102,0,0,
3732,0,0,0,0,0,78,4517,0,0,1,1,0,1,0,3,102,0,0,
3751,0,0,0,0,0,56,4612,0,0,1,1,0,1,0,3,102,0,0,
3770,0,0,29,309,0,6,4613,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,1,0,0,1,4,0,0,1,9,0,0,2,102,0,0,
3825,0,0,0,0,0,13,4633,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
3848,0,0,0,0,0,56,4767,0,0,1,1,0,1,0,3,102,0,0,
3867,0,0,30,352,0,6,4768,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,0,1,9,0,0,2,102,0,0,
3926,0,0,0,0,0,13,4789,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
3949,0,0,0,0,0,56,4917,0,0,1,1,0,1,0,3,102,0,0,
3968,0,0,31,321,0,6,4918,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,0,2,102,0,0,
4023,0,0,0,0,0,13,4938,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
4046,0,0,0,0,0,56,5104,0,0,1,1,0,1,0,3,102,0,0,
4065,0,0,32,325,0,6,5105,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,0,2,102,0,0,
4120,0,0,0,0,0,13,5137,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
4183,0,0,0,0,0,15,5220,0,0,1,1,0,1,0,1,102,0,0,
4202,0,0,0,0,0,78,5221,0,0,1,1,0,1,0,3,102,0,0,
4221,0,0,0,0,0,15,5230,0,0,1,1,0,1,0,1,102,0,0,
4240,0,0,0,0,0,78,5231,0,0,1,1,0,1,0,3,102,0,0,
4259,0,0,0,0,0,56,5380,0,0,1,1,0,1,0,3,102,0,0,
4278,0,0,33,404,0,6,5381,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
4341,0,0,0,0,0,13,5413,0,0,9,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
4392,0,0,0,0,0,15,5477,0,0,1,1,0,1,0,1,102,0,0,
4411,0,0,0,0,0,78,5478,0,0,1,1,0,1,0,3,102,0,0,
4430,0,0,0,0,0,15,5487,0,0,1,1,0,1,0,1,102,0,0,
4449,0,0,0,0,0,78,5488,0,0,1,1,0,1,0,3,102,0,0,
4468,0,0,0,0,0,56,5691,0,0,1,1,0,1,0,3,102,0,0,
4487,0,0,34,420,0,6,5692,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
4554,0,0,0,0,0,13,5731,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
4617,0,0,0,0,0,15,5814,0,0,1,1,0,1,0,1,102,0,0,
4636,0,0,0,0,0,78,5815,0,0,1,1,0,1,0,3,102,0,0,
4655,0,0,0,0,0,15,5824,0,0,1,1,0,1,0,1,102,0,0,
4674,0,0,0,0,0,78,5825,0,0,1,1,0,1,0,3,102,0,0,
4693,0,0,0,0,0,56,6007,0,0,1,1,0,1,0,3,102,0,0,
4712,0,0,35,439,0,6,6008,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,2,102,0,0,
4779,0,0,0,0,0,13,6046,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,3,0,0,2,3,0,0,
4826,0,0,0,0,0,15,6114,0,0,1,1,0,1,0,1,102,0,0,
4845,0,0,0,0,0,78,6115,0,0,1,1,0,1,0,3,102,0,0,
4864,0,0,0,0,0,15,6124,0,0,1,1,0,1,0,1,102,0,0,
4883,0,0,0,0,0,78,6125,0,0,1,1,0,1,0,3,102,0,0,
};


/*
PDProTech (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/03              [GOD]
Add customer_tag				   2013/01/29		   [GOD]
GetAvalPspsByPool Check againest with hPsps        2013/03/04		   [GOD]
Check psp limit before bank selection		   2013/03/20		   [STP]
get bank+psp by merchant and txnamt		   2013/07/04		   [MSN]
Add functions for mobile segment		   2015/02/25		   [MSN]
Update functions for card type option
	1. GetBankPspForSARIP
	2. GetBankPspByMerchNCcyNGrp
	3. GetBankPspForPromoCustomer
	4. HaveDefineSmallAmtRule
Add function for card type option
	1. GetBankPspByOtherMerch		   2016/10/05              [MSN]
	2. MatchCriteria_Mode
	3. HaveDefineRestrictedIPRule
	4. FindPotentialPool
	5. FindPoolDetail
	6. FindPoolPspDetail
	7. GetCustomerGroup_CardType
	8. GetPromoteCustomerGroup_CardType
	9. FindRuleWithoutVirtualPID
Update functions for QR Payment
	1. GetMobileBankByMerchNCcyNGrp		   2016/11/30		   [MSN]
	2. GetMobileBankDefault			   2016/12/12
Add function for NBXA Mobile
	1. GetBankPspByOtherMerchDefault	   2017/07/13		   [WMC]
Fix for serch scheme with merhcant txn amount
	1. FallBack change for NBXA Mobile
	2. Update MatchCriteria_Mode		   2017/09/07		   [MSN]
Add function for NBXA
	1. GetNGBankDefault	   		   2017/10/12		   [WMC]
	2. GetBankPspByOtherMerchDefault
Add function for Vmobile New Phase		   2017/11/24		   [WMC]
	1. GetMobileBankByMerchNCcyNGrpNew	
	2. GetBankPspByMerchNCcyNGrpNew
Update function for Vmobile New Phase
	1. MatchCriteria_Mode
Add ip_region_code in the functions		   2021/01/18              [WMC]
	1. GetMobileBankByMerchNCcyNGrpNew
	2. GetBankPspByMerchNCcyNGrpNew
	3. GetNGBankDefault
	4. GetBankPspByOtherMerchDefault
	5. GetBankPspByOtherMerch
	6. GetBankPspForSARIP
	7. GetBankPspByMerchNCcyNGrp                    
	8. GetBankPspForPromoCustomer
Add cust_id in the functions			   2021/03/18		   [MIC]
	1. GetBankPspByMerchNCcyNGrp
	2. GetMobileBankByMerchNCcyNGrpNew
	3. GetBankPspByMerchNCcyNGrpNew
	4. GetBankPspForSARIP
	5. GetBankPspForPromoCustomer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "RuleLB.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void RuleLB(char    cdebug)
{
        cDebug = cdebug;
}


int MatchCriteria(const hash_t *hRec,
			recordset_t* myRec)
{

	int iRet = PD_NOT_FOUND;
	int	iCnt = 0;
	char	*csPtr;
	char	cPtr;
	int	iPtr;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO match_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		short	hv_return_value;
		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_payment_method[PD_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_payment_method;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		char	hv_business_type;
		/* varchar	hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

		int	hv_restricted_ip;

		//int	v_txn_amount_tier;
		double  v_min_txn_amount;
		double  v_max_txn_amount;
		int	v_criteria_pool_id;
		int	v_scheduler_id;
		int	v_priority;
		/* varchar	v_out_customer_tag[PD_CUSTOMER_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_out_customer_tag;

		
		short	ind_channel_code = -1;
		short	ind_service_code = -1;
		short	ind_payment_method = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_merchant_id = -1;
		short	ind_client_id = -1;
		short	ind_business_type = -1;
		short	ind_customer_tag = -1;
		short	ind_restricted_ip = -1;

		//short	ind_txn_amount_tier = -1;
		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		short	ind_pool_id = -1;
		short	ind_scheduler_id = -1;
		short	ind_priority = -1;
		short	ind_out_customer_tag = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel code */
	if (GetField_CString(hRec,"channel_code",&csPtr)) {
		hv_channel_code.len = strlen(csPtr);
		memcpy(hv_channel_code.arr,csPtr,hv_channel_code.len);
		ind_channel_code = 0;
DEBUGLOG(("MatchCriteria: channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: channel_code is missing!!!\n"));
	}

/* service code */
	if (GetField_CString(hRec,"service_code",&csPtr)) {
		hv_service_code.len = strlen(csPtr);
		memcpy(hv_service_code.arr,csPtr,hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("MatchCriteria: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: service_code is missing!!!\n"));
	}

/*payment method */
	if (GetField_CString(hRec,"pay_method",&csPtr)) {
		hv_payment_method.len = strlen(csPtr);
		memcpy(hv_payment_method.arr,csPtr,hv_payment_method.len);
		ind_payment_method = 0;
DEBUGLOG(("MatchCriteria: payment_method = [%.*s]\n",hv_payment_method.len,hv_payment_method.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: pay_method is missing!!!\n"));
	}

/*txn_country */
	if (GetField_CString(hRec,"txn_country",&csPtr)) {
		hv_txn_country.len = strlen(csPtr);
		memcpy(hv_txn_country.arr,csPtr,hv_txn_country.len);
		ind_txn_country = 0;
DEBUGLOG(("MatchCriteria: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: txn_country is missing!!!\n"));
	}

/*txn_ccy */
	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
		hv_txn_ccy.len = strlen(csPtr);
		memcpy(hv_txn_ccy.arr,csPtr,hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("MatchCriteria: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: txn_ccy is missing!!!\n"));
	}


/*merchant_id */
	if (GetField_CString(hRec,"merchant_id",&csPtr)) {
		hv_merchant_id.len = strlen(csPtr);
		memcpy(hv_merchant_id.arr,csPtr,hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("MatchCriteria: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: merchant_id is missing!!!\n"));
	}

/*client_id */
	if (GetField_CString(hRec,"client_id",&csPtr)) {
		hv_client_id.len = strlen(csPtr);
		memcpy(hv_client_id.arr,csPtr,hv_client_id.len);
		ind_client_id = 0;
DEBUGLOG(("MatchCriteria: client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
	}
	else {
DEBUGLOG(("MatchCriteria: client_id is missing!!!\n"));
	}


/*business_type */
	if (GetField_Char(hRec,"business_type",&cPtr)) {
		hv_business_type = cPtr;
		ind_business_type = 0;
DEBUGLOG(("MatchCriteria: business_type = [%c]\n",hv_business_type));
	}
	else {
DEBUGLOG(("MatchCriteria: business_type is missing!!!\n"));
	}

/*customer_tag */
	if (GetField_CString(hRec,"customer_tag",&csPtr)) {
		hv_customer_tag.len = strlen(csPtr);
		memcpy(hv_customer_tag.arr,csPtr,hv_customer_tag.len);
		ind_customer_tag = 0;
DEBUGLOG(("MatchCriteria: customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));
	}

/*restricted_ip*/
	if (GetField_Int(hRec,"restricted_ip",&iPtr)) {
		hv_restricted_ip = iPtr;
		ind_restricted_ip = 0;
DEBUGLOG(("MatchCriteria: restricted_ip = [%d]\n",hv_restricted_ip));
	}
	else {
DEBUGLOG(("MatchCriteria: restricted_ip is missing!!!\n"));
	}

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_match(:hv_channel_code:ind_channel_code,
								:hv_service_code:ind_service_code,
								:hv_payment_method:ind_payment_method,
								:hv_txn_country:ind_txn_country,
								:hv_txn_ccy:ind_txn_ccy,
								:hv_merchant_id:ind_merchant_id,
								:hv_client_id:ind_client_id,
								:hv_business_type:ind_business_type,
								:hv_customer_tag:ind_customer_tag,
								:hv_restricted_ip:ind_restricted_ip,
								:c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_match ( :hv_cha\
nnel_code:ind_channel_code , :hv_service_code:ind_service_code , :hv_payment_\
method:ind_payment_method , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind\
_txn_ccy , :hv_merchant_id:ind_merchant_id , :hv_client_id:ind_client_id , :h\
v_business_type:ind_business_type , :hv_customer_tag:ind_customer_tag , :hv_r\
estricted_ip:ind_restricted_ip , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_channel_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_payment_method;
        sqlstm.sqhstl[3] = (unsigned long )6;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_payment_method;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[6] = (unsigned long )17;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_client_id;
        sqlstm.sqhstl[7] = (unsigned long )12;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_client_id;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_business_type;
        sqlstm.sqhstl[8] = (unsigned long )1;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_business_type;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_customer_tag;
        sqlstm.sqhstl[9] = (unsigned long )12;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_customer_tag;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto match_error;
}



	if (hv_return_value > 0 ) {
DEBUGLOG(("MatchCriteria: Found!\n"));
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			//ind_txn_amount_tier = -1;
			ind_min_txn_amount = -1;
			ind_max_txn_amount = -1;
			ind_pool_id = -1;
			ind_scheduler_id = -1;
			ind_priority = -1;
			ind_out_customer_tag = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_min_txn_amount:ind_min_txn_amount,
				:v_max_txn_amount:ind_max_txn_amount,
				:v_criteria_pool_id:ind_pool_id,
				:v_scheduler_id:ind_scheduler_id,
				:v_priority:ind_priority,
				:v_out_customer_tag:ind_out_customer_tag; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )87;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_min_txn_amount;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_min_txn_amount;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_max_txn_amount;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_max_txn_amount;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_criteria_pool_id;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_pool_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_scheduler_id;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_scheduler_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_priority;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_priority;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_out_customer_tag;
   sqlstm.sqhstl[6] = (unsigned long )13;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_out_customer_tag;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto match_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			/*
			if (ind_txn_amount_tier >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]txn_amount_tier = [%d]\n",iCnt,v_txn_amount_tier));
				PutField_Int(myHash,"amount_tier_id",v_txn_amount_tier);
			}
			*/

			if (ind_min_txn_amount >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]min_txn_amount = [%lf]\n",iCnt,v_min_txn_amount));
				PutField_Double(myHash,"min_txn_amount",v_min_txn_amount);
			}
			if (ind_max_txn_amount >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]max_txn_amount = [%lf]\n",iCnt,v_max_txn_amount));
				PutField_Double(myHash,"max_txn_amount",v_max_txn_amount);
			}
	
			if (ind_pool_id >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]criteria_pool_id = [%d]\n",iCnt,v_criteria_pool_id));
				PutField_Int(myHash,"criteria_pool_id",v_criteria_pool_id);
			}
			if (ind_scheduler_id >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_priority >= 0) {
DEBUGLOG(("MatchCriteria: [%03d]priority = [%d]\n",iCnt,v_priority));
				PutField_Int(myHash,"priority",v_priority);
			}

			if (ind_out_customer_tag>= 0) {
				v_out_customer_tag.arr[v_out_customer_tag.len] = '\0';
DEBUGLOG(("MatchCriteria: [%03d]out_customer_tag = [%s]\n",iCnt,v_out_customer_tag.arr));
				PutField_CString(myHash,"out_customer_tag",(const char*)v_out_customer_tag.arr);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )130;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )149;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_error;
}


DEBUGLOG(("MatchCriteria: exit with ok\n"));
		return PD_FOUND;
	}
	else {
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )168;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )187;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_error;
}


DEBUGLOG(("MatchCriteria: exit with error\n"));
		return PD_NOT_FOUND;
	}


	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )206;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )225;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
	return iRet;

match_error:
DEBUGLOG(("match_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )244;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )263;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    return PD_NOT_FOUND;
}

int GetAvalPspsByPool(hash_t* hPsp,
			int iPoolId,
			recordset_t* myRec)
{

	int iRet = PD_OK;
	char*	csBuf;
	char	csTag[PD_TAG_LEN +1];
	char*	csPtr;
	int	iPtr;
	int 	i;

	hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getavalpspsbypool_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* varchar         hv_dynstmt[1024*4]; */ 
struct { unsigned short len; unsigned char arr[4096]; } hv_dynstmt;


	int	hv_pool_id;

	/* varchar	v_psp_id[PD_PSP_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

	int	v_ratio;
	int	v_priority;
	

	short	ind_psp_id = -1;
	short	ind_ratio = -1;
	short	ind_priority = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_pool_id = iPoolId;
DEBUGLOG(("GetAvalPspsByPool pool id = [%d]\n",hv_pool_id));

	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"SELECT rm_psp_id,");
	strcat((char*)hv_dynstmt.arr,"rm_ratio,");
	strcat((char*)hv_dynstmt.arr,"rm_priority");
	strcat((char*)hv_dynstmt.arr," FROM rule_psp_lb_mapping");
	strcat((char*)hv_dynstmt.arr," WHERE rm_pool_id  = ");
/* insert pool */
	sprintf(csBuf,"%d",iPoolId);
	strcat((char*)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr," AND rm_psp_id in (");
/* insert psps */
	if (GetField_Int(hPsp,"psp_id_cnt",&iPtr)) {
DEBUGLOG(("GetAvalPspsByPool = [%d]\n",iPtr));
        }
	else 
		iPtr = 0;
	for (i= 0 ; i < iPtr; i++) {
		sprintf(csTag,"psp_id_%d",i);
		if (GetField_CString(hPsp,csTag,&csPtr)) {
DEBUGLOG(("GetAvalPspsByPool [%s] =  [%s]\n",csTag,csPtr));
			if (i != 0 ) 
				strcat((char*)hv_dynstmt.arr, ",");
			strcat((char*)hv_dynstmt.arr, "'");
			strcat((char*)hv_dynstmt.arr, csPtr);
			strcat((char*)hv_dynstmt.arr, "'");
		}
	}

	strcat((char*)hv_dynstmt.arr,")");
	strcat((char*)hv_dynstmt.arr," AND rm_disabled = 0");
	strcat((char*)hv_dynstmt.arr," order by rm_priority desc, rm_ratio desc");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	FREE_ME(csBuf);

DEBUGLOG(("GetAvalPspsByPool:[%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
	/* EXEC SQL PREPARE s1 FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )282;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )4098;
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
 if (sqlca.sqlcode < 0) goto getavalpspsbypool_error;
}

  
	/* EXEC SQL DECLARE c_cursor_getavalpspsbypool CURSOR FOR s1; */ 

  	

	/* EXEC SQL OPEN c_cursor_getavalpspsbypool; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )301;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getavalpspsbypool_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getavalpspsbypool
                INTO
			:v_psp_id:ind_psp_id,
			:v_ratio:ind_ratio,
			:v_priority:ind_priority; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )316;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_ratio;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_ratio;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_priority;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_priority;
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
  if (sqlca.sqlcode < 0) goto getavalpspsbypool_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }	

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);	

		if  (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetAvalPspsByPool PSP ID = [%s]\n",v_psp_id.arr));
			PutField_CString(myHash,"psp_id",(char*)v_psp_id.arr);
		}

		if  (ind_ratio < 0) {
			v_ratio = 0;
		}
DEBUGLOG(("GetAvalPspsByPool ratio = [%d]\n",v_ratio));
		PutField_Int(myHash,"pool_psp_ratio",v_ratio);

		if  (ind_priority < 0) {
			v_priority = 0;
		}
DEBUGLOG(("GetAvalPspsByPool priority = [%d]\n",v_priority));
		PutField_Int(myHash,"pool_psp_priority",v_priority);


		RecordSet_Add(myRec,myHash);
	}while (PD_TRUE);	

	/* EXEC SQL CLOSE c_cursor_getavalpspsbypool; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )343;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getavalpspsbypool_error;
}


	return iRet;

getavalpspsbypool_error:
DEBUGLOG(("getavalpspsbypool_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getavalpspsbypool; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )358;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}



int FindAvalPsp(int     iPoolId,
                const char* csServiceCode,
                const char* csTxnCountry,
                double dTxnAmt)
{
        int iRet = PD_ERR;

DEBUGLOG(("FindAvalPsp()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO findavalpsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_pool_id;
                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_category[PD_CATEGORY_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_category;

                char    hv_type;
                char    hv_party_type;
                double  hv_txn_amt;

                int     v_counter;

                short   ind_counter = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_pool_id = iPoolId;
DEBUGLOG(("FindAvalPsp: pool id  = [%d]\n",iPoolId));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindAvalPsp: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

        hv_txn_country.len = strlen(csTxnCountry);
        memcpy(hv_txn_country.arr,csTxnCountry,hv_txn_country.len);
DEBUGLOG(("FindAvalPsp: txn_country = [%.*s][%d]\n",hv_txn_country.len,hv_txn_country.arr,hv_txn_country.len));

        hv_type = PD_DAILY;
DEBUGLOG(("FindAvalPsp: type = [%c]\n",hv_type));


        hv_category.len = strlen(PD_VALUE_TYPE_AMT);
        memcpy(hv_category.arr,PD_VALUE_TYPE_AMT,hv_category.len);
DEBUGLOG(("FindAvalPsp: category = [%.*s][%d]\n",hv_category.len,hv_category.arr,hv_category.len));

        hv_party_type = PD_TYPE_PSP;
DEBUGLOG(("FindAvalPsp: party_type = [%c]\n",hv_party_type));

        hv_txn_amt = dTxnAmt;
DEBUGLOG(("FindAvalPsp: txn amt = [%f]\n",hv_txn_amt));


        /* EXEC SQL DECLARE c_cursor_findavalpsp CURSOR FOR
		SELECT count(*) as cnt
		  FROM (SELECT rm_psp_id,
         		       rpp_limit,
         		       nvl(tc_counter,0) as counter,
         		       nvl(tc_total_counter,0) as total_counter
   			  FROM (SELECT rm_psp_id,
                                       rpp_limit
                                  FROM rule_psp_lb_mapping,
                               	       psp_detail a,
                               	       psp_master b,
                               	       rule_psp_lb_psp
                         	 WHERE rm_pool_id = :hv_pool_id
                           	   AND rm_disabled = 0
                           	   AND rm_psp_id = a.psp_id
                           	   AND a.disabled = 0
                           	   AND a.online_mode = 'Y'
                           	   AND a.status = 'O'
                           	   AND a.client_id = b.pm_client_id
                           	   AND b.pm_status = 'O'
                           	   AND rm_psp_id = rpp_psp_id
                           	   AND rpp_disabled = 0) a
    		         LEFT JOIN txn_counters
    			   ON rm_psp_id = tc_party_id
    			  AND tc_txn_code in ('DSI','DSP')
                          AND tc_country_id = :hv_txn_country
                          AND tc_channel_code in ('WEB','XPY')
                          AND tc_service_code = :hv_service_code
                          AND TC_type = :hv_type
                          AND tc_category = :hv_category
                          AND Tc_party_type = :hv_party_type) 
    		  WHERE (rpp_limit >= (total_counter + :hv_txn_amt) or rpp_limit = 0); */ 

              	



        /* EXEC SQL OPEN c_cursor_findavalpsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )373;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_pool_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[1] = (unsigned long )4;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_type;
        sqlstm.sqhstl[3] = (unsigned long )1;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_category;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_amt;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
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
        if (sqlca.sqlcode < 0) goto findavalpsp_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_findavalpsp
                  INTO
                        :v_counter:ind_counter; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )416;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_counter;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_counter;
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
                if (sqlca.sqlcode < 0) goto findavalpsp_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("FindAvalPsp  found\n"));
                if (ind_counter >= 0 ) {
DEBUGLOG(("FindAvalPsp  counter = [%d]\n",v_counter));
                        if (v_counter >0 )  {
                                iRet = PD_OK;
                        }
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_findavalpsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )435;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto findavalpsp_error;
}



DEBUGLOG(("FindAvalPsp Counter iRet = [%d]\n",iRet));
        return iRet;
findavalpsp_error:
DEBUGLOG(("findavalpsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_findavalpsp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )450;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}
int FindAvalPspForPool(int iPoolId,
			hash_t* hRec)
{
        int 	iRet = PD_ERR;
	int	iPspCnt;
	char*	csBuf;
	char*	csPtr;

DEBUGLOG(("FindAvalPspForPool()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO findavalpspforpool_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	int	v_cnt;
	/* varchar hv_dynstmt[1024*4]; */ 
struct { unsigned short len; unsigned char arr[4096]; } hv_dynstmt;


	short	ind_cnt = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);

	strcpy((char*)hv_dynstmt.arr,"select count(*) as cnt ");
	strcat((char*)hv_dynstmt.arr,"from rule_psp_lb_mapping,rule_psp_lb_psp ");
	strcat((char*)hv_dynstmt.arr,"where rm_disabled = 0 ");

/* pool id */
	strcat((char*)hv_dynstmt.arr,"and rm_pool_id = ");
	sprintf(csBuf,"%d",iPoolId);
	strcat((char*)hv_dynstmt.arr,csBuf);
	strcat((char*)hv_dynstmt.arr," ");

	strcat((char*)hv_dynstmt.arr,"and rm_psp_id = rpp_psp_id ");
	strcat((char*)hv_dynstmt.arr,"and rpp_disabled = 0 ");
	strcat((char*)hv_dynstmt.arr,"and rpp_psp_id in (");
	
	if (GetField_Int(hRec,"psp_id_cnt",&iPspCnt)) {
DEBUGLOG(("FindAvalPspForPool: psp_id_cnt = [%d]\n",iPspCnt));
		int i = 0;
		char	csTag[PD_TAG_LEN +1];
		for (i = 0; i < iPspCnt; i++) {
			sprintf(csTag,"psp_id_%d",i);
			if (GetField_CString(hRec,csTag,&csPtr)) {
DEBUGLOG(("FindAvalPspForPool: [%s] = [%s]\n",csTag,csPtr));
				if (i == 0)
					sprintf(csBuf,"'%s'",csPtr);
				else 
					sprintf(csBuf,",'%s'",csPtr);
				strcat((char*)hv_dynstmt.arr,csBuf);
			}
		}
        }
	strcat((char*)hv_dynstmt.arr,")");

        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )465;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )4098;
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
 if (sqlca.sqlcode < 0) goto findavalpspforpool_error;
}


	/* EXEC SQL DECLARE c_cursor_getavalpsp CURSOR FOR PS; */ 

	FREE_ME(csBuf);

	/* EXEC SQL OPEN c_cursor_getavalpsp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )484;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findavalpspforpool_error;
}


        do {	
		/* EXEC SQL FETCH c_cursor_getavalpsp
                INTO
			:v_cnt:ind_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )499;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_cnt;
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
  if (sqlca.sqlcode < 0) goto findavalpspforpool_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		if (ind_cnt >= 0 ) {
			if (v_cnt > 0) {
DEBUGLOG(("FindAvalPspForPool: cnt = [%d]\n",v_cnt));
				iRet = PD_OK;
			}
		}
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getavalpsp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )518;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findavalpspforpool_error;
}


DEBUGLOG(("FindAvalPspForPool iRet = [%d]\n",iRet));
        return iRet;
findavalpspforpool_error:
DEBUGLOG(("findavalpspforpool_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getavalpsp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )533;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int FindAvalPspSchudler(int iPoolId,
			hash_t* hRec)
{
        int 	iRet = PD_ERR;
	int	iPspCnt;
	char*	csBuf;
	char*	csPtr;

DEBUGLOG(("FindAvalPspSchudler()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO findavalpspschudler_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	int	v_cnt;
	/* varchar hv_dynstmt[1024*4]; */ 
struct { unsigned short len; unsigned char arr[4096]; } hv_dynstmt;


	short	ind_cnt = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);

	strcpy((char*)hv_dynstmt.arr,"select count(*) as cnt ");
	strcat((char*)hv_dynstmt.arr,"from rule_psp_lb_mapping,rule_psp_lb_psp ");
	strcat((char*)hv_dynstmt.arr,"where rm_disabled = 0 ");

/* pool id */
	strcat((char*)hv_dynstmt.arr,"and rm_pool_id = ");
	sprintf(csBuf,"%d",iPoolId);
	strcat((char*)hv_dynstmt.arr,csBuf);
	strcat((char*)hv_dynstmt.arr," ");

	strcat((char*)hv_dynstmt.arr,"and rm_psp_id = rpp_psp_id ");
	strcat((char*)hv_dynstmt.arr,"and rpp_disabled = 0 ");
	strcat((char*)hv_dynstmt.arr,"and rpp_psp_id in (");
	
	if (GetField_Int(hRec,"psp_id_cnt",&iPspCnt)) {
DEBUGLOG(("FindAvalPspSchudler: psp_id_cnt = [%d]\n",iPspCnt));
		int i = 0;
		char	csTag[PD_TAG_LEN +1];
		for (i = 0; i < iPspCnt; i++) {
			sprintf(csTag,"psp_id_%d",i);
			if (GetField_CString(hRec,csTag,&csPtr)) {
DEBUGLOG(("FindAvalPspForPool: [%s] = [%s]\n",csTag,csPtr));
				if (i == 0)
					sprintf(csBuf,"'%s'",csPtr);
				else 
					sprintf(csBuf,",'%s'",csPtr);
				strcat((char*)hv_dynstmt.arr,csBuf);
			}
		}
        }
	strcat((char*)hv_dynstmt.arr,")");

        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )548;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )4098;
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
 if (sqlca.sqlcode < 0) goto findavalpspschudler_error;
}


	/* EXEC SQL DECLARE c_cursor_getavalpspschudler CURSOR FOR PS; */ 

	FREE_ME(csBuf);

	/* EXEC SQL OPEN c_cursor_getavalpspschudler; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )567;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findavalpspschudler_error;
}


        do {	
		/* EXEC SQL FETCH c_cursor_getavalpspschudler
                INTO
			:v_cnt:ind_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )582;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_cnt;
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
  if (sqlca.sqlcode < 0) goto findavalpspschudler_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		if (ind_cnt >= 0 ) {
			if (v_cnt > 0) {
DEBUGLOG(("FindAvalPspSchudler: cnt = [%d]\n",v_cnt));
				iRet = PD_OK;
			}
		}
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getavalpspschudler; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )601;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findavalpspschudler_error;
}


DEBUGLOG(("FindAvalPspSchudler iRet = [%d]\n",iRet));
        return iRet;
findavalpspschudler_error:
DEBUGLOG(("findavalpspschduler code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getavalpspschudler; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )616;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int GetAllPspByMerch(const char* csMerchantId,
			recordset_t* myRec)
{

	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_name[PD_PSP_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_psp_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		double v_limit;
		double v_remaining_limit;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		short	hv_return_value;

		short	ind_psp_name = -1;
		short	ind_psp_id = -1;
		short	ind_ccy = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;

		short	ind_merchant_id = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetAllPspByMerch: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )631;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_all_psp_get(:hv_merchant_id:ind_merchant_id,
								:c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_all_psp_get ( :\
hv_merchant_id:ind_merchant_id , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )650;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto get_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_name = -1;
			ind_psp_id = -1;
			ind_ccy = -1;
			ind_limit = -1;
			ind_remaining_limit = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_psp_name:ind_psp_name,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_limit:ind_limit,
				:v_remaining_limit:ind_remaining_limit; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )677;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_name;
   sqlstm.sqhstl[1] = (unsigned long )52;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_psp_name;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_psp_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_limit;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_limit;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto get_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_psp_name >= 0) {
				v_psp_name.arr[v_psp_name.len] = '\0';
DEBUGLOG(("GetAllPspByMerch: [%03d]psp_name = [%s]\n",iCnt,v_psp_name.arr));
				PutField_CString(myHash,"psp_name",(const char*)v_psp_name.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetAllPspByMerch: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetAllPspByMerch: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}

			if (ind_limit >= 0) {
DEBUGLOG(("GetAllPspByMerch: [%03d]limit = [%lf]\n",iCnt,v_limit));
				PutField_Double(myHash,"psp_limit",v_limit);
			}

			if (ind_remaining_limit >= 0) {
DEBUGLOG(("GetAllPspByMerch: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"psp_remaining_limit",v_remaining_limit);
			}
	
			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )716;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )735;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


DEBUGLOG(("GetAllPspByMerch: Finished\n"));

	return iRet;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )754;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )773;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


int GetAllPspByMerchBank(const char* csMerchantId,
			const char* csBank,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO mbget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_name[PD_PSP_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_psp_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		double v_limit;
		double v_remaining_limit;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank;


		short	hv_return_value;

		short	ind_psp_name = -1;
		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;

		short	ind_merchant_id = -1;
		short	ind_bank= -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetAllPspByMerchBank: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* bank_code */
	hv_bank.len = strlen(csBank);
	memcpy(hv_bank.arr,csBank,hv_bank.len);
	ind_bank= 0;
DEBUGLOG(("GetAllPspByMerchBank: bank_code = [%.*s]\n",hv_bank.len,hv_bank.arr));

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )792;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mbget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_mbgetpsp(:hv_merchant_id:ind_merchant_id,
								:hv_bank:ind_bank,
								:c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_mbgetpsp ( :hv_\
merchant_id:ind_merchant_id , :hv_bank:ind_bank , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )811;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_bank;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto mbget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_name = -1;
			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_limit = -1;
			ind_remaining_limit = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_psp_name:ind_psp_name,
				:v_psp_id:ind_psp_id,
				:v_client_id:ind_client_id,
				:v_ccy:ind_ccy,
				:v_limit:ind_limit,
				:v_remaining_limit:ind_remaining_limit; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )842;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_name;
   sqlstm.sqhstl[1] = (unsigned long )52;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_psp_name;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_psp_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_client_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_remaining_limit;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto mbget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_psp_name >= 0) {
				v_psp_name.arr[v_psp_name.len] = '\0';
DEBUGLOG(("GetAllPspByMerchBank: [%03d]psp_name = [%s]\n",iCnt,v_psp_name.arr));
				PutField_CString(myHash,"psp_name",(const char*)v_psp_name.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetAllPspByMerchBank: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetAllPspByMerchBank: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetAllPspByMerchBank: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}

			if (ind_limit >= 0) {
DEBUGLOG(("GetAllPspByMerchBank: [%03d]limit = [%lf]\n",iCnt,v_limit));
				PutField_Double(myHash,"psp_limit",v_limit);
			}

			if (ind_remaining_limit >= 0) {
DEBUGLOG(("GetAllPspByMerchBank: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"psp_remaining_limit",v_remaining_limit);
			}
	
			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )885;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mbget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )904;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mbget_error;
}


DEBUGLOG(("GetAllPspByMerchBank: Finished\n"));

	return iRet;

mbget_error:
DEBUGLOG(("mbget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )923;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )942;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int HaveDefineRuleByService(const char* csServiceCode)
{
        int iRet = PD_NOT_FOUND;

DEBUGLOG(("HaveDefineRuleByService()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO byservice_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                int     v_count;

                short   ind_count= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("HaveDefineRuleByService: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

        /* EXEC SQL DECLARE c_cursor_byservice CURSOR FOR
		SELECT	count(*) 
              	FROM	rule_psp_lb_criteria
		where	rc_service_code = :hv_service_code
		and	rc_allow_special_region = 1
		and	rc_disabled = 0; */ 


        /* EXEC SQL OPEN c_cursor_byservice; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )961;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[0] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto byservice_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_byservice
                  INTO
                        :v_count:ind_count; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )980;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_count;
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
                if (sqlca.sqlcode < 0) goto byservice_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("HaveDefineRuleByService  found\n"));
                if (ind_count>= 0 ) {
DEBUGLOG(("HaveDefineRuleByService  count = [%d]\n",v_count));
                        if (v_count>0 )  {
                                iRet = PD_FOUND;
                        }
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_byservice; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )999;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto byservice_error;
}



DEBUGLOG(("HaveDefineRuleByService iRet = [%d]\n",iRet));
        return iRet;
byservice_error:
DEBUGLOG(("byservice_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_byservice; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1014;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int GetBankPspByMerch(const char* csMerchantId,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO maget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_scheduler_id;
		int	v_note_id;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_scheduler_id = -1;
		short	ind_note_id = -1;

		short	ind_merchant_id = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByMerch: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));


	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1029;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_merch_get_pspbank( :hv_merchant_id:ind_merchant_id,
									  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_merch_get_pspba\
nk ( :hv_merchant_id:ind_merchant_id , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1048;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto maget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_scheduler_id = -1;
			ind_note_id = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_scheduler_id:ind_scheduler_id,
				:v_note_id:ind_note_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1075;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_scheduler_id;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_scheduler_id;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_note_id;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_note_id;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto maget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByMerch: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerch: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerch: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByMerch: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByMerch: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_scheduler_id>= 0) {
DEBUGLOG(("GetBankPspByMerch: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_note_id>= 0) {
DEBUGLOG(("GetBankPspByMerch: [%03d]note_id = [%d]\n",iCnt,v_note_id));
				PutField_Int(myHash,"note_id",v_note_id);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1122;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1141;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maget_error;
}


DEBUGLOG(("GetBankPspByMerch: Finished\n"));

	return iRet;

maget_error:
DEBUGLOG(("maget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1160;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1179;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

/*
int GetDstCcyWithLBRule(const char* csMerchantId,
			const char* csServiceCode,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        EXEC SQL WHENEVER SQLERROR GOTO getccy_lb_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

		varchar v_ccy[PD_CCY_ID_LEN];

		varchar	hv_merchant_id[PD_MERCHANT_ID_LEN];
		varchar	hv_service_code[PD_SERVICE_CODE_LEN];

		short	hv_return_value;

		short	ind_ccy = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;

		SQL_CURSOR      c_cursor_id;

        EXEC SQL END DECLARE SECTION;

// merchant_id 
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetDstCcyWithLBRule: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

// service_code 
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetDstCcyWithLBRule: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_get_dstccy(:hv_merchant_id:ind_merchant_id,
								  :hv_service_code:ind_service_code,
								  :c_cursor_id);
                END;
        END-EXEC;

	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_ccy = -1;

			EXEC SQL WHENEVER NOTFOUND DO break;
			EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_ccy:ind_ccy;

			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetDstCcyWithLBRule: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			RecordSet_Add(myRec,myHash);
			iCnt++;
			break; ////only one record
		}
	}

	EXEC SQL CLOSE :c_cursor_id;
	EXEC SQL FREE :c_cursor_id;

	if(iCnt==0)
		iRet = PD_ERR;

DEBUGLOG(("GetDstCcyWithLBRule: Finished iRet = [%d]\n",iRet));

	return iRet;

getccy_lb_error:
DEBUGLOG(("getccy_lb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    EXEC SQL CLOSE :c_cursor_id;
    EXEC SQL FREE :c_cursor_id;
    return PD_ERR;
}

int GetDstCcyWithoutLBRule(const char* csMerchantId,
			const char* csServiceCode,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        EXEC SQL WHENEVER SQLERROR GOTO getccy_wolb_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

		varchar v_ccy[PD_CCY_ID_LEN];

		varchar	hv_merchant_id[PD_MERCHANT_ID_LEN];
		varchar	hv_service_code[PD_SERVICE_CODE_LEN];

		short	hv_return_value;

		short	ind_ccy = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;

		SQL_CURSOR      c_cursor_id;

        EXEC SQL END DECLARE SECTION;

// merchant_id
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetDstCcyWithoutLBRule: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

// service_code 
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetDstCcyWithoutLBRule: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_no_lbrule_get_dstccy(:hv_merchant_id:ind_merchant_id,
								  :hv_service_code:ind_service_code,
								  :c_cursor_id);
                END;
        END-EXEC;

	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_ccy = -1;

			EXEC SQL WHENEVER NOTFOUND DO break;
			EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_ccy:ind_ccy;

			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetDstCcyWithoutLBRule: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			RecordSet_Add(myRec,myHash);
			iCnt++;
			break; ////only one record
		}
	}

	EXEC SQL CLOSE :c_cursor_id;
	EXEC SQL FREE :c_cursor_id;

	if(iCnt==0)
		iRet = PD_ERR;

DEBUGLOG(("GetDstCcyWithoutLBRule: Finished iRet = [%d]\n",iRet));

	return iRet;

getccy_wolb_error:
DEBUGLOG(("getccy_wolb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    EXEC SQL CLOSE :c_cursor_id;
    EXEC SQL FREE :c_cursor_id;
    return PD_ERR;
}
*/

int GetDstCcyWithoutRule(const char* csMerchantId,
			const char* csServiceCode,
			hash_t * hTxn)
{
	int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getccy_wor_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;


		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		short	hv_return_value;

		short	ind_ccy = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetDstCcyWithoutRule: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetDstCcyWithoutRule: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_no_rule_get_dstccy(:hv_merchant_id:ind_merchant_id,
								  :hv_service_code:ind_service_code,
								  :v_ccy:ind_ccy);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_no_rule_get_dstccy ( :h\
v_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , :v_ccy:in\
d_ccy ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1198;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&v_ccy;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy;
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
        if (sqlca.sqlcode < 0) goto getccy_wor_error;
}



	if (hv_return_value == 0 ) {
		if (ind_ccy>= 0) {
			v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetDstCcyWithoutRule: ccy = [%s]\n",v_ccy.arr));
			PutField_CString(hTxn,"psp_ccy",(const char*)v_ccy.arr);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetDstCcyWithoutRule  Failed\n"));
	}


DEBUGLOG(("GetDstCcyWithoutRule: Finished iRet = [%d]\n",iRet));

	return iRet;

getccy_wor_error:
DEBUGLOG(("getccy_wor_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int GetCustomerGroup(const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCcy,
                     const char* csBankCode,
                     hash_t * hTxn)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


		/* varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


		short	hv_return_value;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_bank_code  = -1;

		short	ind_group = -1;

		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetCustomerGroup: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetCustomerGroup: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/*ccy*/
	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
	ind_ccy = 0;
DEBUGLOG(("GetCustomerGroup: ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

/* bank_code */
	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
	ind_bank_code = 0;
DEBUGLOG(("GetCustomerGroup: bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));


	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1229;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getgrp_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_get_custgrp(:hv_merchant_id:ind_merchant_id,
								  :hv_service_code:ind_service_code,
								  :hv_ccy:ind_ccy,
								  :hv_bank_code:ind_bank_code,
								  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_get_custgrp ( :\
hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , :hv_ccy:\
ind_ccy , :hv_bank_code:ind_bank_code , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1248;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[4] = (unsigned long )12;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_bank_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getgrp_error;
}



	PutField_Int(hTxn,"group_cnt",iCnt);
	if (hv_return_value == 0 ) {
		for (;;) {
			ind_group = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_group:ind_group; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1287;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto getgrp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_group>= 0) {
				v_group.arr[v_group.len] = '\0';
DEBUGLOG(("GetCustomerGroup: [%03d]group = [%s]\n",iCnt,v_group.arr));
				sprintf(csTag,"customer_group_%d",iCnt);
				PutField_CString(hTxn,csTag,(const char*)v_group.arr);
			}
	
			iCnt++;
			PutField_Int(hTxn,"group_cnt",iCnt);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetCustomerGroup  Failed!!!\n"));
	}

DEBUGLOG(("GetCustomerGroup: Finished iRet = [%d]\n",iRet));
	return iRet;

getgrp_error:
DEBUGLOG(("getgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetBankPspByMerchNCcy(const char* csMerchantId,
			const char* csCcy,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO maccyget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_scheduler_id;
		int	v_note_id;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;


		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_scheduler_id = -1;
		short	ind_note_id = -1;

		short	ind_merchant_id = -1;
		short	ind_txn_ccy = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByMerchNCcy: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspByMerchNCcy: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));


	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1310;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccyget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_mccy_get_pspbank( :hv_merchant_id:ind_merchant_id,
									     :hv_txn_ccy:ind_txn_ccy,
									     :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_mccy_get_pspban\
k ( :hv_merchant_id:ind_merchant_id , :hv_txn_ccy:ind_txn_ccy , :c_cursor_id \
) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1329;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto maccyget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_scheduler_id = -1;
			ind_note_id = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_scheduler_id:ind_scheduler_id,
				:v_note_id:ind_note_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1360;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_scheduler_id;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_scheduler_id;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_note_id;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_note_id;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto maccyget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_scheduler_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_note_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcy: [%03d]note_id = [%d]\n",iCnt,v_note_id));
				PutField_Int(myHash,"note_id",v_note_id);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1407;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccyget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1426;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccyget_error;
}


DEBUGLOG(("GetBankPspByMerchNCcy: Finished\n"));

	return iRet;

maccyget_error:
DEBUGLOG(("maccyget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1445;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1464;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int GetBankPspByMerchNCcyNGrp( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
			const char* csCcy,
			const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO maccygrpget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		/* varchar hv_cust_id[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_id;

		double	hv_amount;
		int	hv_restricted_ip;

		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_customer_group = -1;
		short	ind_ip_region_code = -1;
		short	ind_cust_id = -1;
		short	ind_amount = -1;
		short	ind_restricted_ip = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy */
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* cust_id */
	if(csCustId == NULL){
		hv_cust_id.len = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: cust_id = NULL\n"));
	}
	else{
		hv_cust_id.len = strlen(csCustId);
		memcpy(hv_cust_id.arr,csCustId,hv_cust_id.len);
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: cust_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}
	ind_cust_id = 0;


/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/* restricted_ip */
	hv_restricted_ip = iRestrictedIP;
	ind_restricted_ip  = 0;

/* customer_group */
	if(csCustomerGroup!=NULL){
		hv_customer_group.len = strlen(csCustomerGroup);
		memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
		ind_customer_group = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
	}


/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_mcgrp_get_pspbank( :hv_merchant_id:ind_merchant_id,
									     :hv_txn_ccy:ind_txn_ccy,
									     :hv_customer_group:ind_customer_group,
									     :hv_amount:ind_amount,
									     :c_cursor_id);
                END;
        END-EXEC;

*/

/*
 	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mcgrp_cardtype_get( :hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_customer_group:ind_customer_group,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amount:ind_amount,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mcgrp_cardtp_get(:hv_merchant_id:ind_merchant_id,
								     :hv_channel:ind_channel,
								     :hv_service_code:ind_service_code,
								     :hv_txn_country:ind_txn_country,
								     :hv_txn_ccy:ind_txn_ccy,
								     :hv_customer_group:ind_customer_group,
								     :hv_ip_region_code:ind_ip_region_code,
								     :hv_restricted_ip:ind_restricted_ip,
								     :hv_amount:ind_amount,
								     :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1483;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_get_mcgrp_cardtp(:hv_merchant_id:ind_merchant_id,
								     :hv_channel:ind_channel,
								     :hv_service_code:ind_service_code,
								     :hv_txn_country:ind_txn_country,
								     :hv_txn_ccy:ind_txn_ccy,
								     :hv_customer_group:ind_customer_group,
								     :hv_ip_region_code:ind_ip_region_code,
								     :hv_cust_id:ind_cust_id,
								     :hv_restricted_ip:ind_restricted_ip,
								     :hv_amount:ind_amount,
								     :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_get_mcgrp_cardtp\
 ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_co\
de:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_c\
cy , :hv_customer_group:ind_customer_group , :hv_ip_region_code:ind_ip_region\
_code , :hv_cust_id:ind_cust_id , :hv_restricted_ip:ind_restricted_ip , :hv_a\
mount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1502;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_cust_id;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_cust_id;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_amount;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto maccygrpget_error;
}






	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1565;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_credit_option;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_debit_option;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto maccygrpget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

/*
			if (ind_scheduler_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_note_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrp: [%03d]note_id = [%d]\n",iCnt,v_note_id));
				PutField_Int(myHash,"note_id",v_note_id);
			}
*/
			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1612;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1631;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpget_error;
}


DEBUGLOG(("GetBankPspByMerchNCcyNGrp: Finished\n"));

	return iRet;

maccygrpget_error:
DEBUGLOG(("maccygrpget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1650;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1669;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int GetPromoteCustomerGroup(const char* csMerchantId,
                     const char* csServiceCode,
                     const char* csCcy,
                     const char* csBankCode,
                     const char* csFromGroup,
                     hash_t * hTxn)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getpmgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar	hv_from_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_from_group;


		/* varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


		short	hv_return_value;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_bank_code  = -1;
		short	ind_from_group = -1;

		short	ind_group = -1;

		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetPromoteCustomerGroup: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetPromoteCustomerGroup: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/*ccy*/
	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
	ind_ccy = 0;
DEBUGLOG(("GetPromoteCustomerGroup: ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

/* bank_code */
	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
	ind_bank_code = 0;
DEBUGLOG(("GetPromoteCustomerGroup: bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

/* from_group */
	hv_from_group.len = strlen(csFromGroup);
	memcpy(hv_from_group.arr,csFromGroup,hv_from_group.len);
	ind_from_group = 0;
DEBUGLOG(("GetPromoteCustomerGroup: from_group = [%.*s]\n",hv_from_group.len,hv_from_group.arr));


	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1688;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getpmgrp_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_get_pm_custgrp(:hv_merchant_id:ind_merchant_id,
								  :hv_service_code:ind_service_code,
								  :hv_ccy:ind_ccy,
								  :hv_bank_code:ind_bank_code,
								  :hv_from_group:ind_from_group,
								  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_lb_get_pm_custgrp \
( :hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , :hv_c\
cy:ind_ccy , :hv_bank_code:ind_bank_code , :hv_from_group:ind_from_group , :c\
_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1707;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[4] = (unsigned long )12;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_bank_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_from_group;
        sqlstm.sqhstl[5] = (unsigned long )12;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_from_group;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getpmgrp_error;
}



	PutField_Int(hTxn,"group_cnt",iCnt);
	if (hv_return_value == 0 ) {
		for (;;) {
			ind_group = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_group:ind_group; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1750;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto getpmgrp_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_group>= 0) {
				v_group.arr[v_group.len] = '\0';
DEBUGLOG(("GetPromoteCustomerGroup: [%03d]group = [%s]\n",iCnt,v_group.arr));
				sprintf(csTag,"customer_group_%d",iCnt);
				PutField_CString(hTxn,csTag,(const char*)v_group.arr);
			}
	
			iCnt++;
			PutField_Int(hTxn,"group_cnt",iCnt);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetPromoteCustomerGroup  Failed!!!\n"));
	}

DEBUGLOG(("GetPromoteCustomerGroup: Finished iRet = [%d]\n",iRet));
	return iRet;

getpmgrp_error:
DEBUGLOG(("getpmgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int HaveDefineSmallAmtRule(const char* csChannel,
			   const char* csMerchantId,
			   const char* csServiceCode,
			   const char* csCountry,
			   const char* csCcy, 
			   char	cCardType,
			   const double dAmt)
{
        int iRet = PD_NOT_FOUND;

DEBUGLOG(("HaveDefineSmallAmtRule()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sarip_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		char	hv_card_type;
		double	hv_amt;

                int     v_count;

                short   ind_count= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("HaveDefineSmallAmtRule: merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

        hv_channel.len = strlen(csChannel);
        memcpy(hv_channel.arr,csChannel,hv_channel.len);
DEBUGLOG(("HaveDefineSmallAmtRule: channel = [%.*s][%d]\n",hv_channel.len,hv_channel.arr,hv_channel.len));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("HaveDefineSmallAmtRule: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

        hv_txn_country.len = strlen(csCountry);
        memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
DEBUGLOG(("HaveDefineSmallAmtRule: txn_country = [%.*s][%d]\n",hv_txn_country.len,hv_txn_country.arr,hv_txn_country.len));

        hv_ccy.len = strlen(csCcy);
        memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("HaveDefineSmallAmtRule: ccy = [%.*s][%d]\n",hv_ccy.len,hv_ccy.arr,hv_ccy.len));

	hv_card_type = cCardType;
DEBUGLOG(("HaveDefineSmallAmtRule: card type = [%c]\n", hv_card_type));

	hv_amt = dAmt;
DEBUGLOG(("HaveDefineSmallAmtRule: amount = [%lf]\n",hv_amt));

        /* EXEC SQL DECLARE c_cursor_sarip CURSOR FOR
		SELECT	count(*) 
              	FROM	rule_psp_lb_criteria,
			system_parameter
		where	rc_party_id = :hv_merchant_id
		and	rc_ccy = :hv_ccy
		and	rc_channel_code = :hv_channel
		and	rc_service_code = :hv_service_code
		and	rc_country = :hv_txn_country
		and	rc_allow_special_region = 0 
		and	rc_max_transaction_amount >= :hv_amt
		and	rc_max_transaction_amount >0
		and	rc_max_transaction_amount <= sp_val
		and	rc_disabled = 0
		and	('A' = :hv_card_type  or rc_card_type_opt = :hv_card_type)
		and	sp_code = 'LB_SMALL_AMT'; */ 


        /* EXEC SQL OPEN c_cursor_sarip; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0014;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1773;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto sarip_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_sarip
                  INTO
                        :v_count:ind_count; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1820;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_count;
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
                if (sqlca.sqlcode < 0) goto sarip_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("HaveDefineSmallAmtRule  found\n"));
                if (ind_count>= 0 ) {
DEBUGLOG(("HaveDefineSmallAmtRule  count = [%d]\n",v_count));
                        if (v_count>0 )  {
                                iRet = PD_FOUND;
                        }
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_sarip; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1839;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sarip_error;
}



DEBUGLOG(("HaveDefineSmallAmtRule iRet = [%d]\n",iRet));
        return iRet;

sarip_error:
DEBUGLOG(("sarip_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_sarip; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1854;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int GetBankPspForSARIP( const char* csChannel,
			const char* csMerchantId,
			const char* csServiceCode,
			const char* csCountry,
			const char* csCcy,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getsarip_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		/* varchar hv_cust_id[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_id;

		double	hv_amt;
		int	hv_restricted_ip;

		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option= -1;
		short	ind_debit_option= -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_ip_region_code = -1;
		short	ind_cust_id = -1;
		short	ind_amt = -1;
		short	ind_restricted_ip = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 



/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetBankPspForSARIP: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspForSARIP: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetBankPspForSARIP: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetBankPspForSARIP: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy */
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspForSARIP: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspForSARIP: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));
	
	/* cust_id */
	if(csCustId == NULL){
		hv_cust_id.len = 0;
DEBUGLOG(("GetBankPspForSARIP: cust_id = NULL\n"));
	}
	else{
		hv_cust_id.len = strlen(csCustId);
		memcpy(hv_cust_id.arr,csCustId,hv_cust_id.len);
DEBUGLOG(("GetBankPspForSARIP: cust_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}
	ind_cust_id = 0;

/*amt*/
	hv_amt = dAmt;
	ind_amt = 0;
DEBUGLOG(("GetBankPspForSARIP: amt = [%lf]\n",hv_amt));

/* restricted_ip */
	hv_restricted_ip = iRestrictedIP;
	ind_restricted_ip  = 0;

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_sarip_get_pspbank( :hv_merchant_id:ind_merchant_id,
									     :hv_txn_ccy:ind_txn_ccy,
									     :hv_amt:ind_amt,
									     :c_cursor_id);
                END;
        END-EXEC;
*/

/*	
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_sarip_cardtype_get( :hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amt:ind_amt,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_sarip_cardtp_get(:hv_merchant_id:ind_merchant_id,
								     :hv_channel:ind_channel,
								     :hv_service_code:ind_service_code,
							   	     :hv_txn_country:ind_txn_country,
								     :hv_txn_ccy:ind_txn_ccy,
								     :hv_ip_region_code:ind_ip_region_code,
								     :hv_restricted_ip:ind_restricted_ip,
								     :hv_amt:ind_amt,
							 	     :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1869;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getsarip_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_get_sarip_cardtp(:hv_merchant_id:ind_merchant_id,
								     :hv_channel:ind_channel,
								     :hv_service_code:ind_service_code,
							   	     :hv_txn_country:ind_txn_country,
								     :hv_txn_ccy:ind_txn_ccy,
								     :hv_ip_region_code:ind_ip_region_code,
								     :hv_cust_id:ind_cust_id,
								     :hv_restricted_ip:ind_restricted_ip,
								     :hv_amt:ind_amt,
							 	     :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_get_sarip_cardtp\
 ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_co\
de:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_c\
cy , :hv_ip_region_code:ind_ip_region_code , :hv_cust_id:ind_cust_id , :hv_re\
stricted_ip:ind_restricted_ip , :hv_amt:ind_amt , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1888;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_cust_id;
        sqlstm.sqhstl[7] = (unsigned long )12;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_cust_id;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_amt;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getsarip_error;
}







	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;
			//ind_scheduler_id = -1;
			//ind_note_id = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1947;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_credit_option;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_debit_option;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto getsarip_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspForSARIP: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspForSARIP: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspForSARIP: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspForSARIP: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspForSARIP: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspForSARIP: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspForSARIP: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

/*
			if (ind_scheduler_id>= 0) {
DEBUGLOG(("GetBankPspForSARIP: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_note_id>= 0) {
DEBUGLOG(("GetBankPspForSARIP: [%03d]note_id = [%d]\n",iCnt,v_note_id));
				PutField_Int(myHash,"note_id",v_note_id);
			}
*/
			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1994;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getsarip_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2013;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getsarip_error;
}


DEBUGLOG(("GetBankPspForSARIP: Finished\n"));

	return iRet;

getsarip_error:
DEBUGLOG(("getsarip_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2032;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2051;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int GetBankPspForPromoCustomer( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec)
				
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO newphaseget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		/* varchar hv_cust_id[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_id;

		double	hv_amount;
		int	hv_restricted_ip;

		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option= -1;
		short	ind_debit_option= -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_customer_group = -1;
		short   ind_ip_region_code = -1;
		short	ind_cust_id = -1;
		short	ind_amount = -1;
		short	ind_restricted_ip = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

// merchant_id
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

// txn_ccy
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/* restricted_ip */
	hv_restricted_ip = iRestrictedIP;
	ind_restricted_ip  = 0;

/* customer_group */
	if(csCustomerGroup!=NULL){
		hv_customer_group.len = strlen(csCustomerGroup);
		memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
		ind_customer_group = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
	}

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));


/* cust_id */
	if(csCustId == NULL){
		hv_cust_id.len = 0;
DEBUGLOG(("GetBankPspForPromoCustomer: cust_id = NULL\n"));
	}
	else{
		hv_cust_id.len = strlen(csCustId);
		memcpy(hv_cust_id.arr,csCustId,hv_cust_id.len);
DEBUGLOG(("GetBankPspForPromoCustomer: cust_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}
	ind_cust_id = 0;



/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_pmcust_get_pspbank(:hv_merchant_id:ind_merchant_id,
									     :hv_txn_ccy:ind_txn_ccy,
									     :hv_customer_group:ind_customer_group,
									     :hv_amount:ind_amount,
									     :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_pmcust_cardtype_get(:hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_customer_group:ind_customer_group,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amount:ind_amount,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_pmcust_cardtp_get(:hv_merchant_id:ind_merchant_id,
								      :hv_channel:ind_channel,
								      :hv_service_code:ind_service_code,
								      :hv_txn_country:ind_txn_country,
								      :hv_txn_ccy:ind_txn_ccy,
								      :hv_customer_group:ind_customer_group,
								      :hv_ip_region_code:ind_ip_region_code,	
								      :hv_restricted_ip:ind_restricted_ip,
								      :hv_amount:ind_amount,
								      :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2070;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto newphaseget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_get_pmcust_cardtp(:hv_merchant_id:ind_merchant_id,
								      :hv_channel:ind_channel,
								      :hv_service_code:ind_service_code,
								      :hv_txn_country:ind_txn_country,
								      :hv_txn_ccy:ind_txn_ccy,
								      :hv_customer_group:ind_customer_group,
								      :hv_ip_region_code:ind_ip_region_code,	
								      :hv_cust_id:ind_cust_id,
								      :hv_restricted_ip:ind_restricted_ip,
								      :hv_amount:ind_amount,
								      :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_get_pmcust_cardt\
p ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_c\
ode:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_\
ccy , :hv_customer_group:ind_customer_group , :hv_ip_region_code:ind_ip_regio\
n_code , :hv_cust_id:ind_cust_id , :hv_restricted_ip:ind_restricted_ip , :hv_\
amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2089;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_cust_id;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_cust_id;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_amount;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto newphaseget_error;
}



		
	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option= -1;
			ind_debit_option= -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2152;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_credit_option;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_debit_option;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto newphaseget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspForPromoCustomer: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2199;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto newphaseget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2218;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto newphaseget_error;
}


DEBUGLOG(("GetBankPspForPromoCustomer: Finished\n"));

	return iRet;

newphaseget_error:
DEBUGLOG(("newphaseget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2237;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2256;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int GetMobileBankByMerchNCcyNGrp(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csCustomerGroup,
			const char* csUnionGroup,
			const double dAmt,
			int iIsNewCust,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO mobccygrpget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_customer_grp[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_grp;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;
		int	v_is_all_child_outage;
		int	v_is_child_outage;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar	hv_union_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_union_group;

		double	hv_amount;
		int	hv_new_cust;

		short	hv_return_value;

		short	ind_customer_grp = -1;
		short	ind_psp_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;
		short	ind_is_all_child_outage = -1;
		short	ind_is_child_outage = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_customer_group = -1;
		short	ind_union_group = -1;
		short	ind_amount = -1;
		short	ind_new_cust = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/* is new customer */
	hv_new_cust = iIsNewCust;
	ind_new_cust = 0;

/* customer_group */
	if(csCustomerGroup!=NULL){
		hv_customer_group.len = strlen(csCustomerGroup);
		memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
		ind_customer_group = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
	}

/* union_group */
	if(csUnionGroup!=NULL){
		hv_union_group.len = strlen(csUnionGroup);
		memcpy(hv_union_group.arr,csUnionGroup,hv_union_group.len);
		ind_union_group = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: union_group = [%.*s]\n",hv_union_group.len,hv_union_group.arr));
	}

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_lb_mcgrp_get_mobbank( :hv_merchant_id:ind_merchant_id,
									     :hv_txn_ccy:ind_txn_ccy,
									     :hv_customer_group:ind_customer_group,
									     :hv_amount:ind_amount,
									     :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2275;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobccygrpget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mcgrp_get_mobbank( :hv_merchant_id:ind_merchant_id,
									     :hv_channel:ind_channel,
									     :hv_service_code:ind_service_code,
									     :hv_txn_country:ind_txn_country,
									     :hv_txn_ccy:ind_txn_ccy,
									     :hv_customer_group:ind_customer_group,
									     :hv_union_group:ind_union_group,
									     :hv_amount:ind_amount,
									     :hv_new_cust:ind_new_cust,
									     :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_mcgrp_get_mobban\
k ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_c\
ode:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_\
ccy , :hv_customer_group:ind_customer_group , :hv_union_group:ind_union_group\
 , :hv_amount:ind_amount , :hv_new_cust:ind_new_cust , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2294;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_union_group;
        sqlstm.sqhstl[7] = (unsigned long )12;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_union_group;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_amount;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_new_cust;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_new_cust;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto mobccygrpget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_customer_grp = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;
			ind_psp_id = -1;
			ind_is_all_child_outage = -1;
			ind_is_child_outage = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_is_all_child_outage:ind_is_all_child_outage,
				:v_is_child_outage:ind_is_child_outage,
				:v_customer_grp:ind_customer_grp,
				:v_ccy:ind_ccy,
				:v_psp_id:ind_psp_id,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2353;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_is_all_child_outage;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_is_all_child_outage;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_is_child_outage;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_is_child_outage;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_customer_grp;
   sqlstm.sqhstl[4] = (unsigned long )13;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_customer_grp;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[5] = (unsigned long )5;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_ccy;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[6] = (unsigned long )12;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_psp_id;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_credit_option;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_debit_option;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto mobccygrpget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_is_all_child_outage >= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]is_all_child_outage = [%d]\n",iCnt,v_is_all_child_outage));
				PutField_Int(myHash,"is_all_child_outage",v_is_all_child_outage);
			}

			if (ind_is_child_outage >= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]is_child_outage = [%d]\n",iCnt,v_is_child_outage));
				PutField_Int(myHash,"is_child_outage",v_is_child_outage);
			}

			if (ind_customer_grp>= 0) {
				v_customer_grp.arr[v_customer_grp.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]customer_grp = [%s]\n",iCnt,v_customer_grp.arr));
				PutField_CString(myHash,"customer_grp",(const char*)v_customer_grp.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2408;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobccygrpget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2427;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobccygrpget_error;
}


DEBUGLOG(("GetMobileBankByMerchNCcyNGrp: Finished\n"));

	return iRet;

mobccygrpget_error:
DEBUGLOG(("mobccygrpget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2446;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2465;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


int GetMobileBankDefault(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO mobdefaultget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 



		/* varchar	v_customer_grp[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_grp;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;
		int	v_is_all_child_outage;
		int	v_is_child_outage;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		double	hv_amount;

		short	hv_return_value;


		short	ind_customer_grp = -1;
		short	ind_psp_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;
		short	ind_is_all_child_outage = -1;
		short	ind_is_child_outage = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_amount = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetMobileBankDefault: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetMobileBankDefault: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetMobileBankDefault: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetMobileBankDefault: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetMobileBankDefault: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2484;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobdefaultget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_def_get_mobbank( :hv_merchant_id:ind_merchant_id,
								       :hv_channel:ind_channel,
								       :hv_service_code:ind_service_code,
								       :hv_txn_country:ind_txn_country,
								       :hv_txn_ccy:ind_txn_ccy,
								       :hv_amount:ind_amount,
								       :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_def_get_mobbank \
( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_cod\
e:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_cc\
y , :hv_amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2503;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_amount;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto mobdefaultget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_customer_grp = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;
			ind_psp_id = -1;
			ind_is_all_child_outage = -1;
			ind_is_child_outage = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_is_all_child_outage:ind_is_all_child_outage,
				:v_is_child_outage:ind_is_child_outage,
				:v_customer_grp:ind_customer_grp,
				:v_ccy:ind_ccy,
				:v_psp_id:ind_psp_id,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2550;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_is_all_child_outage;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_is_all_child_outage;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_is_child_outage;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_is_child_outage;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_customer_grp;
   sqlstm.sqhstl[4] = (unsigned long )13;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_customer_grp;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[5] = (unsigned long )5;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_ccy;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[6] = (unsigned long )12;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_psp_id;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_credit_option;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_debit_option;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto mobdefaultget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetMobileBankDefault: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_is_all_child_outage >= 0) {
DEBUGLOG(("GetMobileBankDefault: [%03d]is_all_child_outage = [%d]\n",iCnt,v_is_all_child_outage));
				PutField_Int(myHash,"is_all_child_outage",v_is_all_child_outage);
			}

			if (ind_is_child_outage >= 0) {
DEBUGLOG(("GetMobileBankDefault: [%03d]is_child_outage = [%d]\n",iCnt,v_is_child_outage));
				PutField_Int(myHash,"is_child_outage",v_is_child_outage);
			}

			if (ind_customer_grp>= 0) {
				v_customer_grp.arr[v_customer_grp.len] = '\0';
DEBUGLOG(("GetMobileBankDefault: [%03d]customer_grp = [%s]\n",iCnt,v_customer_grp.arr));
				PutField_CString(myHash,"customer_grp",(const char*)v_customer_grp.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetMobileBankDefault: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetMobileBankDefault: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetMobileBankDefault: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetMobileBankDefault: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetMobileBankDefault: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2605;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobdefaultget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2624;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobdefaultget_error;
}


DEBUGLOG(("GetMobileBankDefault: Finished\n"));

	return iRet;

mobdefaultget_error:
DEBUGLOG(("mobdefaultget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2643;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2662;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int GetRemainCapForMobSegment(const char* csMerchantId,const char* csGroup, const double dAmt, double *dRemain)
{
        int iRet = PD_OK;
	*dRemain = 0.0;

DEBUGLOG(("GetRemainCapForMobSegment()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO remain_mob_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_group;

		double	hv_amt;

                double	v_remain;

                short   ind_remain = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetRemainCapForMobSegment: merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

        hv_group.len = strlen(csGroup);
        memcpy(hv_group.arr,csGroup,hv_group.len);
DEBUGLOG(("GetRemainCapForMobSegment: group = [%.*s][%d]\n",hv_group.len,hv_group.arr,hv_group.len));

	hv_amt = dAmt;
DEBUGLOG(("GetRemainCapForMobSegment: amount = [%lf]\n",hv_amt));

        /* EXEC SQL 
		select	sum(remaining_limit)
		into	:v_remain:ind_remain
		from	PSP_LIMIT_MERCHANT_VIEW
		where	merchant_id = :hv_merchant_id
		and	customer_segment = :hv_group
		AND	min_transaction_amount <= :hv_amt
		and	((max_transaction_amount >= :hv_amt 
				and max_transaction_amount> 0) 
			or max_transaction_amount = 0)
		and	remaining_limit >= :hv_amt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select sum ( remaining_limit ) into :b0:b1 from PSP_\
LIMIT_MERCHANT_VIEW where merchant_id = :b2 and customer_segment = :b3 AND mi\
n_transaction_amount <= :b4 and ( ( max_transaction_amount >= :b4 and max_tra\
nsaction_amount > 0 ) or max_transaction_amount = 0 ) and remaining_limit >= \
:b4 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2681;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_remain;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_remain;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_group;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
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
        if (sqlca.sqlcode < 0) goto remain_mob_error;
}




	if (ind_remain>= 0 ) {
		*dRemain = v_remain;
DEBUGLOG(("GetRemainCapForMobSegment remain capacity = [%lf]\n",v_remain));
	}

DEBUGLOG(("GetRemainCapForMobSegment iRet = [%d]\n",iRet));
        return iRet;

remain_mob_error:
DEBUGLOG(("remain_mob_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}



int GetBankPspByOtherMerch( const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
			const char* csCcy,
			const char* csIpRegionCode,
			const int   iRestrictedIP,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO othermerchget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		double	hv_amount;
		int	hv_restricted_ip;

		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short   ind_ip_region_code = -1;
		short	ind_amount = -1;
		short	ind_restricted_ip = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetBankPspByOtherMerch: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByOtherMerch: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetBankPspByOtherMerch: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetBankPspByOtherMerch: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspByOtherMerch: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspByOtherMerch: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/* restricted_ip */
	hv_restricted_ip = iRestrictedIP;
	ind_restricted_ip  = 0;


/*
        EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mccy_cardtype_get( :hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amount:ind_amount,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2720;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto othermerchget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mccy_cardtp_get(:hv_merchant_id:ind_merchant_id,
								    :hv_channel:ind_channel,
								    :hv_service_code:ind_service_code,
								    :hv_txn_country:ind_txn_country,
								    :hv_txn_ccy:ind_txn_ccy,
								    :hv_ip_region_code:ind_ip_region_code,	
								    :hv_restricted_ip:ind_restricted_ip,
								    :hv_amount:ind_amount,
							   	    :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_mccy_cardtp_get \
( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_cod\
e:ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_cc\
y , :hv_ip_region_code:ind_ip_region_code , :hv_restricted_ip:ind_restricted_\
ip , :hv_amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2739;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_amount;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto othermerchget_error;
}




	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )2794;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_credit_option;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_debit_option;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto othermerchget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspByOtherMerch: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2841;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto othermerchget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2860;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto othermerchget_error;
}


DEBUGLOG(("GetBankPspByOtherMerch: Finished\n"));

	return iRet;

othermerchget_error:
DEBUGLOG(("othermerchget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2879;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2898;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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




int HaveDefineRestrictedIPRule(const char* csChannel,
			   const char* csMerchantId,
			   const char* csServiceCode,
			   const char* csCountry,
			   const char* csCcy, 
			   char	cCardType)
{
        int iRet = PD_NOT_FOUND;

DEBUGLOG(("HaveDefineRestrictedIPRule()\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO riprule_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		char	hv_card_type;

                int     v_count;

                short   ind_count= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("HaveDefineRestrictedIPRule: merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));

        hv_channel.len = strlen(csChannel);
        memcpy(hv_channel.arr,csChannel,hv_channel.len);
DEBUGLOG(("HaveDefineRestrictedIPRule: channel = [%.*s][%d]\n",hv_channel.len,hv_channel.arr,hv_channel.len));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("HaveDefineRestrictedIPRule: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));

        hv_txn_country.len = strlen(csCountry);
        memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
DEBUGLOG(("HaveDefineRestrictedIPRule: txn_country = [%.*s][%d]\n",hv_txn_country.len,hv_txn_country.arr,hv_txn_country.len));

        hv_ccy.len = strlen(csCcy);
        memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("HaveDefineRestrictedIPRule: ccy = [%.*s][%d]\n",hv_ccy.len,hv_ccy.arr,hv_ccy.len));

	hv_card_type = cCardType;
DEBUGLOG(("HaveDefineRestrictedIPRule: card type = [%c]\n", hv_card_type));

        /* EXEC SQL DECLARE c_cursor_riprule CURSOR FOR
		SELECT	count(*) 
              	FROM	rule_psp_lb_criteria
		where	rc_party_id = :hv_merchant_id
		and	rc_ccy = :hv_ccy
		and	rc_channel_code = :hv_channel
		and	rc_service_code = :hv_service_code
		and	rc_country = :hv_txn_country
		and	rc_allow_special_region = 1 
		and	rc_disabled = 0
		and	('A' = :hv_card_type  or rc_card_type_opt = :hv_card_type); */ 


        /* EXEC SQL OPEN c_cursor_riprule; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0021;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2917;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[6] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto riprule_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_riprule
                  INTO
                        :v_count:ind_count; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )2960;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_count;
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
                if (sqlca.sqlcode < 0) goto riprule_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("HaveDefineRestrictedIPRule  found\n"));
                if (ind_count>= 0 ) {
DEBUGLOG(("HaveDefineRestrictedIPRule  count = [%d]\n",v_count));
                        if (v_count>0 )  {
                                iRet = PD_FOUND;
                        }
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_riprule; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )2979;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto riprule_error;
}



DEBUGLOG(("HaveDefineRestrictedIPRule iRet = [%d]\n",iRet));
        return iRet;

riprule_error:
DEBUGLOG(("riprule_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_riprule; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2994;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int FindPotentialPool(hash_t *hIn,
		      recordset_t* myRec)
{

        int     iCnt = 0;
	int	iTmp = 0;
	double	dTmp = 0.0;
	char	*csTmp = NULL;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO potentialpool_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                int     hv_id;
                /* varchar	hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		double	hv_amt;

                int     v_pool_id;
                /* varchar v_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

                double  v_pool_limit;
                int     v_ratio;
                int     v_priority;

                short   ind_pool_id = -1;
                short   ind_desc = -1;
                short   ind_pool_limit = -1;
                short   ind_ratio = -1;
                short   ind_priority = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_Int(hIn, "criteria_pool_id", &iTmp)){
        	hv_id = iTmp;
DEBUGLOG(("FindPotentialPool: Scheme ID = [%d]\n",hv_id));
	}

	if(GetField_CString(hIn, "bank_code", &csTmp)){
        	hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
DEBUGLOG(("FindPotentialPool: Bank Code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
	}

	if(GetField_Double(hIn, "psp_amt", &dTmp)){
        	hv_amt = dTmp;
DEBUGLOG(("FindPotentialPool: PSP Amount = [%lf]\n",hv_amt));
	}

        /* EXEC SQL DECLARE c_cursor_potentialpool CURSOR FOR
	   SELECT
		    pool_id,
		    pool_desc,
		    pool_limit,
		    pool_ratio,
		    pool_priority
	   FROM
                (SELECT pool_id,
			pool_desc,
			pool_limit,
			pool_ratio,
			pool_priority,
			pool_pid,pid_limit,approved_amt pid_approved_amt
                  FROM ( select pool_id,
				pool_desc,
				pool_limit,
				pool_ratio,
				pool_priority,
				pool_pid,pid_limit,approved_amt,
				sum(request_amt) OVER (PARTITION BY pool_id) pool_request_amt,
				sum(approved_amt) OVER (PARTITION BY pool_id) pool_approved_amt
			 from rule_lb_scheme_detail_view
			 where scheme_id = :hv_id
			 and int_bank_code = :hv_bank_code
		       )
		  where (pool_approved_amt + :hv_amt <= pool_limit
			  or pool_limit = 0))
	   WHERE pid_approved_amt + :hv_amt <= pid_limit
	   group by pool_id,
		    pool_desc,
		    pool_limit,
		    pool_ratio,
		    pool_priority
	   order by pool_priority desc, pool_ratio desc; */ 
 

        /* EXEC SQL OPEN c_cursor_potentialpool; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0022;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3009;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
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
        if (sqlca.sqlcode < 0) goto potentialpool_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_potentialpool
                INTO
                        :v_pool_id:ind_pool_id,
                        :v_desc:ind_desc,
                        :v_pool_limit:ind_pool_limit,
                        :v_ratio:ind_ratio,
                        :v_priority:ind_priority; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3040;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pool_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pool_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_desc;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_desc;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_pool_limit;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_pool_limit;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_ratio;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ratio;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_priority;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_priority;
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
                if (sqlca.sqlcode < 0) goto potentialpool_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
                iCnt++;
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* pool_id */
                if (ind_pool_id >= 0) {
DEBUGLOG(("FindPotentialPool: pool_id = [%d]\n",v_pool_id));
                        PutField_Int(myHash,"pool_id",v_pool_id);
                }
/* desc */
                if (ind_desc >= 0 ) {
                        v_desc.arr[v_desc.len] = '\0';
DEBUGLOG(("FindPotentialPool: desc = [%s]\n",(char*)v_desc.arr));
                        PutField_CString(myHash,"desc",(char*)v_desc.arr);
                }


/* pool limit */
                if (ind_pool_limit >= 0) {
DEBUGLOG(("FindPotentialPool: pool_limit = [%lf]\n",v_pool_limit));
                        PutField_Double(myHash,"pool_limit",v_pool_limit);
                }

/* ratio */
                if (ind_ratio >= 0) {
DEBUGLOG(("FindPotentialPool: ratio = [%d]\n",v_ratio));
                        PutField_Int(myHash,"ratio",v_ratio);
                }
/* priority */
                if (ind_priority >= 0) {
DEBUGLOG(("FindPotentialPool: priority = [%d]\n",v_priority));
                        PutField_Int(myHash,"priority",v_priority);
                }
                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_potentialpool; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3075;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto potentialpool_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("FindPotentialPool Normal Exit\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("FindPotentialPool Normal Exit, Not Found\n"));
                return PD_NOT_FOUND;
        }

potentialpool_error:
DEBUGLOG(("potentialpool_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_potentialpool; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3090;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_NOT_FOUND;
}


int FindPoolDetail(hash_t *hIn,
		      hash_t *hOut)
{

        int     iCnt = 0;
	int	iTmp = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO pooldt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                int     hv_id;
                int     hv_pool_id;

                int     v_pool_id;
                int     v_ratio;
                int     v_priority;
                double  v_req_amt;
                double  v_total_req_amt;
                double  v_app_amt;
                double  v_total_app_amt;

                short   ind_pool_id = -1;
                short   ind_ratio = -1;
                short   ind_priority = -1;
                short   ind_req_amt = -1;
                short   ind_total_req_amt = -1;
                short   ind_app_amt = -1;
                short   ind_total_app_amt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_Int(hIn, "criteria_pool_id", &iTmp)){
        	hv_id = iTmp;
DEBUGLOG(("FindPoolDetail: Scheme ID = [%d]\n",hv_id));
	}

	if(GetField_Int(hIn, "pool_id", &iTmp)){
        	hv_pool_id = iTmp;
DEBUGLOG(("FindPoolDetail: Pool ID = [%d]\n",hv_pool_id));
	}


        /* EXEC SQL DECLARE c_cursor_pooldt CURSOR FOR
                SELECT  pool_id,
			pool_ratio,
			pool_priority,
			pool_request_amt,
			pool_total_request_amt,
			pool_approved_amt,
			pool_total_approved_amt
                  FROM ( select pool_id,
				pool_ratio,
				pool_priority,
				sum(request_amt) OVER (PARTITION BY pool_id) pool_request_amt,
				sum(total_request_amt) OVER (PARTITION BY pool_id) pool_total_request_amt,
				sum(approved_amt) OVER (PARTITION BY pool_id) pool_approved_amt,
				sum(total_approved_amt) OVER (PARTITION BY pool_id) pool_total_approved_amt
			 from rule_lb_scheme_detail_view
			 where scheme_id = :hv_id
			 and pool_id= :hv_pool_id
			 group by pool_id,
				  pool_ratio,
				  pool_priority,
				  pool_pid,
				  approved_amt,
				  total_approved_amt,
				  request_amt,
				  total_request_amt
		  	  ) 
		  group by pool_id,
			   pool_ratio,
			   pool_priority,
			   pool_approved_amt,
			   pool_total_approved_amt,
			   pool_request_amt,
			   pool_total_request_amt; */ 

		   

        /* EXEC SQL OPEN c_cursor_pooldt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0023;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3105;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_pool_id;
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
        if (sqlca.sqlcode < 0) goto pooldt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_pooldt
                INTO
                        :v_pool_id:ind_pool_id,
                        :v_ratio:ind_ratio,
                        :v_priority:ind_priority,
			:v_req_amt:ind_req_amt,
			:v_total_req_amt:ind_total_req_amt,
			:v_app_amt:ind_app_amt,
			:v_total_app_amt:ind_total_app_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3128;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pool_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pool_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_ratio;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_ratio;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_priority;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_priority;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_req_amt;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_req_amt;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_req_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_req_amt;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_app_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_app_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_app_amt;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_app_amt;
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
                if (sqlca.sqlcode < 0) goto pooldt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
                iCnt++;
/* pool_id */
                if (ind_pool_id >= 0) {
DEBUGLOG(("FindPoolDetail: pool_id = [%d]\n",v_pool_id));
                        PutField_Int(hOut,"pool_id",v_pool_id);
                }
/* ratio */
                if (ind_ratio >= 0) {
DEBUGLOG(("FindPoolDetail: ratio = [%d]\n",v_ratio));
                        PutField_Int(hOut,"ratio",v_ratio);
                }
/* priority */
                if (ind_priority >= 0) {
DEBUGLOG(("FindPoolDetail: priority = [%d]\n",v_priority));
                        PutField_Int(hOut,"priority",v_priority);
                }

		if(ind_req_amt >= 0){
DEBUGLOG(("FindPoolDetail: req_amt = [%lf]\n",v_req_amt));
                        PutField_Double(hOut,"req_amt",v_req_amt);
		}

		if(ind_total_req_amt >= 0){
DEBUGLOG(("FindPoolDetail: total_req_amt = [%lf]\n",v_total_req_amt));
                        PutField_Double(hOut,"total_req_amt",v_total_req_amt);
		}

		if(ind_app_amt >= 0){
DEBUGLOG(("FindPoolDetail: app_amt = [%lf]\n",v_app_amt));
                        PutField_Double(hOut,"app_amt",v_app_amt);
		}

		if(ind_total_app_amt >= 0){
DEBUGLOG(("FindPoolDetail: total_app_amt = [%lf]\n",v_total_app_amt));
                        PutField_Double(hOut,"total_app_amt",v_total_app_amt);
		}
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_pooldt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3171;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto pooldt_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("FindPoolDetail Normal Exit\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("FindPoolDetail Normal Exit, Not Found\n"));
                return PD_NOT_FOUND;
        }

pooldt_error:
DEBUGLOG(("pooldt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_pooldt; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3186;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_NOT_FOUND;
}




int FindPoolPspDetail(hash_t *hIn,
		      recordset_t* myRec)
{

        int     iCnt = 0;
	int	iTmp = 0;
	double	dTmp = 0.0;
	char	*csTmp = NULL;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO poolpspdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                int     hv_id;
                int     hv_pool_id;
                /* varchar	hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		double	hv_amt;

                int     v_pool_id;
                /* varchar v_psp_id[PD_PSP_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                int     v_ratio;
                int     v_priority;
                double  v_req_amt;
                double  v_pool_req_amt;
                /* varchar v_client[PD_CLIENT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client;

                int     v_rej_delta_amt;

		short   ind_pool_id = -1;
                short   ind_psp_id = -1;
                short   ind_ratio = -1;
                short   ind_priority = -1;
                short   ind_req_amt = -1;
                short   ind_pool_req_amt = -1;
                short   ind_client = -1;
                short   ind_rej_delta_amt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_Int(hIn, "criteria_pool_id", &iTmp)){
        	hv_id = iTmp;
DEBUGLOG(("FindPoolPspDetail: Scheme ID = [%d]\n",hv_id));
	}

	if(GetField_Int(hIn, "pool_id", &iTmp)){
        	hv_pool_id = iTmp;
DEBUGLOG(("FindPoolPspDetail: Pool ID = [%d]\n",hv_pool_id));
	}

	if(GetField_CString(hIn, "bank_code", &csTmp)){
        	hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
DEBUGLOG(("FindPoolPspDetail: Bank Code = [%s]\n",hv_bank_code.arr));
	}

	if(GetField_Double(hIn, "psp_amt", &dTmp)){
        	hv_amt = dTmp;
DEBUGLOG(("FindPoolPspDetail: PSP Amount = [%lf]\n",hv_amt));
	}
	
	/* EXEC SQL DECLARE c_cursor_poolpspdt CURSOR FOR
                SELECT  pool_id,
                        pool_pid,
                        pool_pid_ratio,
                        pool_pid_priority,
                        request_amt,
                        sum(request_amt) OVER (PARTITION BY pool_id) pool_request_amt,
                        CLIENT_ID,
                        REJ_SMALL_DELTA_AMT
                from rule_lb_scheme_detail_view,psp_detail
                where scheme_id = :hv_id
                and   pool_id = :hv_pool_id
                and   int_bank_code = :hv_bank_code
                and   approved_amt + :hv_amt <= pid_limit
                and   pool_pid = psp_id
                and   ((deposit_card_type = card_type_opt) or deposit_card_type = 'A')
                order by pool_pid_priority desc, pool_pid_ratio desc; */ 


        /* EXEC SQL OPEN c_cursor_poolpspdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0024;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3201;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_pool_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
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
        if (sqlca.sqlcode < 0) goto poolpspdt_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_poolpspdt
                INTO
                        :v_pool_id:ind_pool_id,
                        :v_psp_id:ind_psp_id,
                        :v_ratio:ind_ratio,
                        :v_priority:ind_priority,
                        :v_req_amt:ind_req_amt,
                        :v_pool_req_amt:ind_pool_req_amt,
                        :v_client:ind_client,
                        :v_rej_delta_amt:ind_rej_delta_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )3232;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pool_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pool_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ratio;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ratio;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_priority;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_priority;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_req_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_req_amt;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_pool_req_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_pool_req_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_client;
                sqlstm.sqhstl[6] = (unsigned long )13;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_client;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_rej_delta_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_rej_delta_amt;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto poolpspdt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
                iCnt++;
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* pool_id */
                if (ind_pool_id >= 0) {
DEBUGLOG(("FindPoolPspDetail: pool_id = [%d]\n",v_pool_id));
                        PutField_Int(myHash,"pool_id",v_pool_id);
                }

/* psp_id */
                if (ind_psp_id >= 0 ) {
                        v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("FindPoolPspDetail: psp_id = [%s]\n",(char*)v_psp_id.arr));
                        PutField_CString(myHash,"psp_id",(char*)v_psp_id.arr);
                }

/* client */
                if (ind_client >= 0 ) {
                        v_client.arr[v_client.len] = '\0';
DEBUGLOG(("FindPoolPspDetail: client = [%s]\n",(char*)v_client.arr));
                        PutField_CString(myHash,"client",(char*)v_client.arr);
                }

/* rej_delta_amt */
                if (ind_rej_delta_amt >= 0) {
DEBUGLOG(("FindPoolPspDetail: rej_delta_amt = [%d]\n",v_rej_delta_amt));
                        PutField_Int(myHash,"rej_delta_amt",v_rej_delta_amt);
                }

/* ratio */
                if (ind_ratio >= 0) {
DEBUGLOG(("FindPoolPspDetail: ratio = [%d]\n",v_ratio));
                        PutField_Int(myHash,"psp_ratio",v_ratio);
                }

/* priority */
                if (ind_priority >= 0) {
DEBUGLOG(("FindPoolPspDetail: priority = [%d]\n",v_priority));
                        PutField_Int(myHash,"psp_priority",v_priority);
                }

/* req_amt */
                if (ind_req_amt >= 0) {
DEBUGLOG(("FindPoolPspDetail: req_amt = [%lf]\n",v_req_amt));
                        PutField_Double(myHash,"req_amt",v_req_amt);
                }

/* pool_req_amt */
                if (ind_pool_req_amt >= 0) {
DEBUGLOG(("FindPoolPspDetail: pool_req_amt = [%lf]\n",v_pool_req_amt));
                        PutField_Double(myHash,"pool_req_amt",v_pool_req_amt);
                }

                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_poolpspdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3279;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto poolpspdt_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("FindPoolPspDetail Normal Exit\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("FindPoolPspDetail Normal Exit, Not Found\n"));
                return PD_NOT_FOUND;
        }

poolpspdt_error:
DEBUGLOG(("poolpspdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_poolpspdt; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3294;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_NOT_FOUND;
}



int MatchCriteria_Mode(const hash_t *hRec,
			recordset_t* myRec)
{

	int iRet = PD_NOT_FOUND;
	int	iCnt = 0;
	char	*csPtr;
	char	cPtr;
	int	iPtr = 0;
	double	dPtr = 0.0;
	char	*csMode = NULL;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO match_mode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		short	hv_return_value = -1;
		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

		int	hv_sarip;
		int	hv_restricted_ip;
		char	hv_card_type;
		double	hv_amount;

		double  v_min_txn_amount;
		double  v_max_txn_amount;
		int	v_criteria_pool_id;
		int	v_scheduler_id;
		int	v_priority;
		
		short	ind_channel_code = -1;
		short	ind_service_code = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_merchant_id = -1;
		short	ind_customer_tag = -1;
		short	ind_sarip = -1;
		short	ind_restricted_ip = -1;
		short	ind_card_type = -1;
		short	ind_amount = -1;

		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		short	ind_pool_id = -1;
		short	ind_scheduler_id = -1;
		short	ind_priority = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* match_mode */
	if (GetField_CString(hRec,"match_mode",&csMode)) {
DEBUGLOG(("MatchCriteria_Mode: mode = [%s]\n",csMode));
        }

/* channel code */
	if (GetField_CString(hRec,"channel_code",&csPtr)) {
		hv_channel_code.len = strlen(csPtr);
		memcpy(hv_channel_code.arr,csPtr,hv_channel_code.len);
		ind_channel_code = 0;
DEBUGLOG(("MatchCriteria_Mode: channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: channel_code is missing!!!\n"));
	}

/* service code */
	if (GetField_CString(hRec,"service_code",&csPtr)) {
		hv_service_code.len = strlen(csPtr);
		memcpy(hv_service_code.arr,csPtr,hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("MatchCriteria_Mode: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: service_code is missing!!!\n"));
	}

/*txn_country */
	if (GetField_CString(hRec,"txn_country",&csPtr)) {
		hv_txn_country.len = strlen(csPtr);
		memcpy(hv_txn_country.arr,csPtr,hv_txn_country.len);
		ind_txn_country = 0;
DEBUGLOG(("MatchCriteria_Mode: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: txn_country is missing!!!\n"));
	}

/*txn_ccy */
	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
		hv_txn_ccy.len = strlen(csPtr);
		memcpy(hv_txn_ccy.arr,csPtr,hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("MatchCriteria_Mode: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: txn_ccy is missing!!!\n"));
	}


/*merchant_id */
	if (GetField_CString(hRec,"merchant_id",&csPtr)) {
		hv_merchant_id.len = strlen(csPtr);
		memcpy(hv_merchant_id.arr,csPtr,hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("MatchCriteria_Mode: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: merchant_id is missing!!!\n"));
	}

/*customer_tag */
	if (GetField_CString(hRec,"customer_segment",&csPtr)) {
		hv_customer_tag.len = strlen(csPtr);
		memcpy(hv_customer_tag.arr,csPtr,hv_customer_tag.len);
		ind_customer_tag = 0;
DEBUGLOG(("MatchCriteria_Mode: customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));
	}

/*sarip*/
	if(!strcmp(csMode,PD_MODE_MOBILE_SEGMENT_NEW)){
        	if (GetField_Int(hRec,"sarip",&iPtr)) {
                	hv_sarip = iPtr;
                	ind_sarip = 0;
DEBUGLOG(("MatchCriteria_Mode: sarip = [%d]\n",hv_sarip));
        	}
		else {
DEBUGLOG(("MatchCriteria_Mode: sarip is missing!!!\n"));
		}
	}

/*restricted_ip*/
	if (GetField_Int(hRec,"restricted_ip",&iPtr)) {
		hv_restricted_ip = iPtr;
		ind_restricted_ip = 0;
DEBUGLOG(("MatchCriteria_Mode: restricted_ip = [%d]\n",hv_restricted_ip));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: restricted_ip is missing!!!\n"));
	}

/*card_type*/
	if (GetField_Char(hRec,"card_type",&cPtr)) {
		hv_card_type = cPtr;
		ind_card_type = 0;
DEBUGLOG(("MatchCriteria_Mode: card_type = [%c]\n",hv_card_type));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode:  is missing!!!\n"));
	}

/* amount */
	if (GetField_Double(hRec,"txn_amt",&dPtr)) {
		hv_amount = dPtr;
		ind_amount = 0;
DEBUGLOG(("MatchCriteria_Mode: amount = [%lf]\n",hv_amount));
	}
	else {
DEBUGLOG(("MatchCriteria_Mode: amount is missing!!!\n"));
	}

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3309;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_mode_error;
}




	if(!strcmp(csMode,PD_MODE_SARIP)){
            /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_match_sarip(:hv_channel_code:ind_channel_code,
								:hv_service_code:ind_service_code,
								:hv_txn_country:ind_txn_country,
								:hv_txn_ccy:ind_txn_ccy,
								:hv_merchant_id:ind_merchant_id,
								:hv_card_type:ind_card_type,
								:hv_restricted_ip:ind_restricted_ip,
								:hv_amount:ind_amount,
								:c_cursor_id);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 12;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_rulelb_match_sarip \
( :hv_channel_code:ind_channel_code , :hv_service_code:ind_service_code , :hv\
_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_merchant_id:ind_\
merchant_id , :hv_card_type:ind_card_type , :hv_restricted_ip:ind_restricted_\
ip , :hv_amount:ind_amount , :c_cursor_id ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3328;
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
            sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
            sqlstm.sqhstl[1] = (unsigned long )5;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&ind_channel_code;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
            sqlstm.sqhstl[2] = (unsigned long )5;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&ind_service_code;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
            sqlstm.sqhstl[3] = (unsigned long )4;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&ind_txn_country;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
            sqlstm.sqhstl[4] = (unsigned long )5;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&hv_card_type;
            sqlstm.sqhstl[6] = (unsigned long )1;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&ind_card_type;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&hv_restricted_ip;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)&ind_restricted_ip;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&ind_amount;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
            if (sqlca.sqlcode < 0) goto match_mode_error;
}


	}
	else if(!strcmp(csMode,PD_MODE_SEGMENT_MERCH)){
            /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_match_mcgrp(:hv_channel_code:ind_channel_code,
								:hv_service_code:ind_service_code,
								:hv_txn_country:ind_txn_country,
								:hv_txn_ccy:ind_txn_ccy,
								:hv_merchant_id:ind_merchant_id,
								:hv_customer_tag:ind_customer_tag,
								:hv_card_type:ind_card_type,
								:hv_restricted_ip:ind_restricted_ip,
								:hv_amount:ind_amount,
								:c_cursor_id);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 12;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_rulelb_match_mcgrp \
( :hv_channel_code:ind_channel_code , :hv_service_code:ind_service_code , :hv\
_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_merchant_id:ind_\
merchant_id , :hv_customer_tag:ind_customer_tag , :hv_card_type:ind_card_type\
 , :hv_restricted_ip:ind_restricted_ip , :hv_amount:ind_amount , :c_cursor_id\
 ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3383;
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
            sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
            sqlstm.sqhstl[1] = (unsigned long )5;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&ind_channel_code;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
            sqlstm.sqhstl[2] = (unsigned long )5;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&ind_service_code;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
            sqlstm.sqhstl[3] = (unsigned long )4;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&ind_txn_country;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
            sqlstm.sqhstl[4] = (unsigned long )5;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_tag;
            sqlstm.sqhstl[6] = (unsigned long )12;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&ind_customer_tag;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&hv_card_type;
            sqlstm.sqhstl[7] = (unsigned long )1;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)&ind_card_type;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&hv_restricted_ip;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&ind_restricted_ip;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&hv_amount;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)&ind_amount;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&c_cursor_id;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
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
            if (sqlca.sqlcode < 0) goto match_mode_error;
}



	}
	else if(!strcmp(csMode,PD_MODE_OTHER_MERCH)){
            /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_match_mccy(:hv_channel_code:ind_channel_code,
								:hv_service_code:ind_service_code,
								:hv_txn_country:ind_txn_country,
								:hv_txn_ccy:ind_txn_ccy,
								:hv_merchant_id:ind_merchant_id,
								:hv_card_type:ind_card_type,
								:hv_restricted_ip:ind_restricted_ip,
								:hv_amount:ind_amount,
								:c_cursor_id);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 12;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_rulelb_match_mccy (\
 :hv_channel_code:ind_channel_code , :hv_service_code:ind_service_code , :hv_\
txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_merchant_id:ind_m\
erchant_id , :hv_card_type:ind_card_type , :hv_restricted_ip:ind_restricted_i\
p , :hv_amount:ind_amount , :c_cursor_id ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3442;
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
            sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
            sqlstm.sqhstl[1] = (unsigned long )5;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&ind_channel_code;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
            sqlstm.sqhstl[2] = (unsigned long )5;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&ind_service_code;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
            sqlstm.sqhstl[3] = (unsigned long )4;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&ind_txn_country;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
            sqlstm.sqhstl[4] = (unsigned long )5;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&hv_card_type;
            sqlstm.sqhstl[6] = (unsigned long )1;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&ind_card_type;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&hv_restricted_ip;
            sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)&ind_restricted_ip;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&ind_amount;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
            if (sqlca.sqlcode < 0) goto match_mode_error;
}



	}
	else if(!strcmp(csMode,PD_MODE_MOBILE_SEGMENT_NEW)){
            /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_match_mobgrpnew(:hv_channel_code:ind_channel_code,
                                                                :hv_service_code:ind_service_code,
                                                                :hv_txn_country:ind_txn_country,
                                                                :hv_txn_ccy:ind_txn_ccy,
                                                                :hv_merchant_id:ind_merchant_id,
                                                                :hv_customer_tag:ind_customer_tag,
                                                                :hv_card_type:ind_card_type,
                                                                :hv_sarip:ind_sarip,
                                                                :hv_restricted_ip:ind_restricted_ip,
                                                                :hv_amount:ind_amount,
                                                                :c_cursor_id);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 12;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_rulelb_match_mobgrp\
new ( :hv_channel_code:ind_channel_code , :hv_service_code:ind_service_code ,\
 :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_merchant_id:\
ind_merchant_id , :hv_customer_tag:ind_customer_tag , :hv_card_type:ind_card_\
type , :hv_sarip:ind_sarip , :hv_restricted_ip:ind_restricted_ip , :hv_amount\
:ind_amount , :c_cursor_id ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3497;
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
            sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
            sqlstm.sqhstl[1] = (unsigned long )5;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&ind_channel_code;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
            sqlstm.sqhstl[2] = (unsigned long )5;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&ind_service_code;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
            sqlstm.sqhstl[3] = (unsigned long )4;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&ind_txn_country;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
            sqlstm.sqhstl[4] = (unsigned long )5;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned long )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
            sqlstm.sqhstl[5] = (unsigned long )17;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned long )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_tag;
            sqlstm.sqhstl[6] = (unsigned long )12;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         short *)&ind_customer_tag;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned long )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (unsigned char  *)&hv_card_type;
            sqlstm.sqhstl[7] = (unsigned long )1;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         short *)&ind_card_type;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned long )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (unsigned char  *)&hv_sarip;
            sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         short *)&ind_sarip;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned long )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (unsigned char  *)&hv_restricted_ip;
            sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         short *)&ind_restricted_ip;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned long )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (unsigned char  *)&hv_amount;
            sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         short *)&ind_amount;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned long )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_id;
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
            if (sqlca.sqlcode < 0) goto match_mode_error;
}



        }


	if (hv_return_value > 0 ) {
DEBUGLOG(("MatchCriteria_Mode: Found!\n"));
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_min_txn_amount = -1;
			ind_max_txn_amount = -1;
			ind_pool_id = -1;
			ind_scheduler_id = -1;
			ind_priority = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_min_txn_amount:ind_min_txn_amount,
				:v_max_txn_amount:ind_max_txn_amount,
				:v_criteria_pool_id:ind_pool_id,
				:v_scheduler_id:ind_scheduler_id,
				:v_priority:ind_priority; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3560;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_min_txn_amount;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_min_txn_amount;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_max_txn_amount;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_max_txn_amount;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_criteria_pool_id;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_pool_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_scheduler_id;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_scheduler_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_priority;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_priority;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto match_mode_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_min_txn_amount >= 0) {
DEBUGLOG(("MatchCriteria_Mode: [%03d]min_txn_amount = [%lf]\n",iCnt,v_min_txn_amount));
				PutField_Double(myHash,"min_txn_amount",v_min_txn_amount);
			}
			if (ind_max_txn_amount >= 0) {
DEBUGLOG(("MatchCriteria_Mode: [%03d]max_txn_amount = [%lf]\n",iCnt,v_max_txn_amount));
				PutField_Double(myHash,"max_txn_amount",v_max_txn_amount);
			}
	
			if (ind_pool_id >= 0) {
DEBUGLOG(("MatchCriteria_Mode: [%03d]criteria_pool_id = [%d]\n",iCnt,v_criteria_pool_id));
				PutField_Int(myHash,"criteria_pool_id",v_criteria_pool_id);
			}
			if (ind_scheduler_id >= 0) {
DEBUGLOG(("MatchCriteria_Mode: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_priority >= 0) {
DEBUGLOG(("MatchCriteria_Mode: [%03d]priority = [%d]\n",iCnt,v_priority));
				PutField_Int(myHash,"priority",v_priority);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3599;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_mode_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3618;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_mode_error;
}


DEBUGLOG(("MatchCriteria_Mode: exit with ok\n"));
		return PD_FOUND;
	}
	else {
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3637;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_mode_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3656;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto match_mode_error;
}


DEBUGLOG(("MatchCriteria_Mode: exit with error\n"));
		return PD_NOT_FOUND;
	}


	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3675;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_mode_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3694;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto match_mode_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
	return iRet;

match_mode_error:
DEBUGLOG(("match_mode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3713;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )3732;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    return PD_NOT_FOUND;
}


int GetCustomerGroup_CardType(const char* csChannel,
		     const char* csMerchantId,
                     const char* csServiceCode,
		     const char* csCountry,
                     const char* csCcy,
		     char cCardType,
		     const double dAmt,
                     const char* csBankCode,
                     hash_t * hTxn)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getgrp_card_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		char	hv_card_type;
		double	hv_amount;

		/* varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


		short	hv_return_value;

		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_bank_code  = -1;
		short	ind_card_type = -1;
		short	ind_amount = -1;

		short	ind_group = -1;

		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetCustomerGroup_CardType: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetCustomerGroup_CardType: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetCustomerGroup_CardType: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetCustomerGroup_CardType: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/*ccy*/
	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
	ind_ccy = 0;
DEBUGLOG(("GetCustomerGroup_CardType: ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

/* bank_code */
	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
	ind_bank_code = 0;
DEBUGLOG(("GetCustomerGroup_CardType: bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

	hv_card_type = cCardType;
	ind_card_type = 0;
DEBUGLOG(("GetCustomerGroup_CardType: card_type = [%c]\n",hv_card_type));

	hv_amount = dAmt;
	ind_amount = 0;
DEBUGLOG(("GetCustomerGroup_CardType: amount = [%lf]\n",hv_amount));

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3751;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getgrp_card_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_custgrp_cardtype(:hv_merchant_id:ind_merchant_id,
								  :hv_channel:ind_channel,
								  :hv_service_code:ind_service_code,
								  :hv_txn_country:ind_txn_country,
								  :hv_ccy:ind_ccy,
								  :hv_card_type:ind_card_type,
								  :hv_amount:ind_amount,
								  :hv_bank_code:ind_bank_code,
								  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_custgrp_cardtype\
 ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_co\
de:ind_service_code , :hv_txn_country:ind_txn_country , :hv_ccy:ind_ccy , :hv\
_card_type:ind_card_type , :hv_amount:ind_amount , :hv_bank_code:ind_bank_cod\
e , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3770;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_card_type;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_amount;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_bank_code;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getgrp_card_error;
}



	PutField_Int(hTxn,"group_cnt",iCnt);
	if (hv_return_value == 0 ) {
		for (;;) {
			ind_group = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_group:ind_group; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3825;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto getgrp_card_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_group>= 0) {
				v_group.arr[v_group.len] = '\0';
DEBUGLOG(("GetCustomerGroup_CardType: [%03d]group = [%s]\n",iCnt,v_group.arr));
				sprintf(csTag,"customer_group_%d",iCnt);
				PutField_CString(hTxn,csTag,(const char*)v_group.arr);
			}
	
			iCnt++;
			PutField_Int(hTxn,"group_cnt",iCnt);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetCustomerGroup_CardType  Failed!!!\n"));
	}

DEBUGLOG(("GetCustomerGroup_CardType: Finished iRet = [%d]\n",iRet));
	return iRet;

getgrp_card_error:
DEBUGLOG(("getgrp_card_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetPromoteCustomerGroup_CardType(const char* csChannel,
		     const char* csMerchantId,
                     const char* csServiceCode,
		     const char* csCountry,
                     const char* csCcy,
		     const char* csCustomerGroup,
		     char cCardType,
		     const double dAmt,
                     const char* csBankCode,
                     hash_t * hTxn)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getpmgrp_card_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		char	hv_card_type;
		double	hv_amount;

		/* varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


		short	hv_return_value;

		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_bank_code  = -1;
		short	ind_card_type = -1;
		short	ind_customer_group = -1;
		short	ind_amount = -1;

		short	ind_group = -1;

		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/*ccy*/
	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
	ind_ccy = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

/* customer_group */
	hv_customer_group.len = strlen(csCustomerGroup);
	memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
	ind_customer_group = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));

/* bank_code */
	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);
	ind_bank_code = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

	hv_card_type = cCardType;
	ind_card_type = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: card_type = [%c]\n",hv_card_type));

	hv_amount = dAmt;
	ind_amount = 0;
DEBUGLOG(("GetPromoteCustomerGroup_CardType: amount = [%lf]\n",hv_amount));

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3848;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getpmgrp_card_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_pm_custgrp_cardtype(:hv_merchant_id:ind_merchant_id,
								  :hv_channel:ind_channel,
								  :hv_service_code:ind_service_code,
								  :hv_txn_country:ind_txn_country,
								  :hv_ccy:ind_ccy,
								  :hv_customer_group:ind_customer_group,
								  :hv_card_type:ind_card_type,
								  :hv_amount:ind_amount,
								  :hv_bank_code:ind_bank_code,
								  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_pm_custgrp_cardt\
ype ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service\
_code:ind_service_code , :hv_txn_country:ind_txn_country , :hv_ccy:ind_ccy , \
:hv_customer_group:ind_customer_group , :hv_card_type:ind_card_type , :hv_amo\
unt:ind_amount , :hv_bank_code:ind_bank_code , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3867;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_card_type;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_amount;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[9] = (unsigned long )12;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_bank_code;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getpmgrp_card_error;
}



	PutField_Int(hTxn,"group_cnt",iCnt);
	if (hv_return_value == 0 ) {
		for (;;) {
			ind_group = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_group:ind_group; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )3926;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto getpmgrp_card_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_group>= 0) {
				v_group.arr[v_group.len] = '\0';
DEBUGLOG(("GetPromoteCustomerGroup_CardType: [%03d]group = [%s]\n",iCnt,v_group.arr));
				sprintf(csTag,"customer_group_%d",iCnt);
				PutField_CString(hTxn,csTag,(const char*)v_group.arr);
			}
	
			iCnt++;
			PutField_Int(hTxn,"group_cnt",iCnt);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("GetPromoteCustomerGroup_CardType  Failed!!!\n"));
	}

DEBUGLOG(("GetPromoteCustomerGroup_CardType: Finished iRet = [%d]\n",iRet));
	return iRet;

getpmgrp_card_error:
DEBUGLOG(("getpmgrp_card_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}




int FindRuleWithoutVirtualPID(const char* csChannel,
		     const char* csMerchantId,
                     const char* csServiceCode,
		     const char* csCountry,
                     const char* csCcy,
		     const char* csCustomerGroup,
		     char cCardType,
		     const double dAmt,
                     hash_t * hTxn)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO rule_wo_vrtpid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		char	hv_card_type;
		double	hv_amount;

		/* varchar	v_group[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_group;


		short	hv_return_value;

		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_card_type = -1;
		short	ind_customer_group = -1;
		short	ind_amount = -1;

		short	ind_group = -1;

		SQL_CURSOR      c_cursor_id;
        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/*ccy*/
	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
	ind_ccy = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

/* customer_group */
	hv_customer_group.len = strlen(csCustomerGroup);
	memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
	ind_customer_group = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));

	hv_card_type = cCardType;
	ind_card_type = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: card_type = [%c]\n",hv_card_type));

	hv_amount = dAmt;
	ind_amount = 0;
DEBUGLOG(("FindRuleWithoutVirtualPID: amount = [%lf]\n",hv_amount));


	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3949;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto rule_wo_vrtpid_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_without_virtualpid(:hv_merchant_id:ind_merchant_id,
								  :hv_channel:ind_channel,
								  :hv_service_code:ind_service_code,
								  :hv_txn_country:ind_txn_country,
								  :hv_ccy:ind_ccy,
								  :hv_customer_group:ind_customer_group,
								  :hv_card_type:ind_card_type,
								  :hv_amount:ind_amount,
								  :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_without_virtualp\
id ( :hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_\
code:ind_service_code , :hv_txn_country:ind_txn_country , :hv_ccy:ind_ccy , :\
hv_customer_group:ind_customer_group , :hv_card_type:ind_card_type , :hv_amou\
nt:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )3968;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_card_type;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_card_type;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_amount;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto rule_wo_vrtpid_error;
}



	PutField_Int(hTxn,"group_cnt",iCnt);
	if (hv_return_value == 0 ) {
		for (;;) {
			ind_group = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	
				:v_group:ind_group; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4023;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto rule_wo_vrtpid_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_group>= 0) {
				v_group.arr[v_group.len] = '\0';
DEBUGLOG(("FindRuleWithoutVirtualPID: [%03d]group = [%s]\n",iCnt,v_group.arr));
				sprintf(csTag,"customer_group_%d",iCnt);
				PutField_CString(hTxn,csTag,(const char*)v_group.arr);
			}
	
			iCnt++;
			PutField_Int(hTxn,"group_cnt",iCnt);
		}
	}
	else{
		iRet = PD_ERR;
DEBUGLOG(("FindRuleWithoutVirtualPID  Failed!!!\n"));
	}

DEBUGLOG(("FindRuleWithoutVirtualPID: Finished iRet = [%d]\n",iRet));
	return iRet;

rule_wo_vrtpid_error:
DEBUGLOG(("rule_wo_vrtpid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetNGBankDefault(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csIpRegionCode,
			char cDeviceType,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO ngdefaultget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 



		/* varchar	v_customer_grp[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_grp;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank_group[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank_group;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		/* varchar	v_select_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_select_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;
		int	v_is_all_child_outage;
		int	v_is_child_outage;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

                /* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		char	hv_device_type;	
		double	hv_amount;

		short	hv_return_value;


		short	ind_customer_grp = -1;
		short	ind_psp_id = -1;
		short	ind_ccy = -1;
		short	ind_bank_group= -1;
		short	ind_bank= -1;
		short	ind_select_bank = -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;
		short	ind_is_all_child_outage = -1;
		short	ind_is_child_outage = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_ip_region_code = -1;
		short	ind_device_type = -1;
		short	ind_amount = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetNGBankDefault: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetNGBankDefault: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetNGBankDefault: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetNGBankDefault: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetNGBankDefault: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code*/
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetNGBankDefault: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* device_type */
	hv_device_type = cDeviceType;
        ind_device_type = 0;
DEBUGLOG(("GetNGBankDefault: device_type = [%c]\n",hv_device_type));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_def_get_ngbank( :hv_merchant_id:ind_merchant_id,
                                                                       :hv_channel:ind_channel,
                                                                       :hv_service_code:ind_service_code,
                                                                       :hv_txn_country:ind_txn_country,
                                                                       :hv_txn_ccy:ind_txn_ccy,
                                                                       :hv_device_type:ind_device_type,
                                                                       :hv_amount:ind_amount,
                                                                       :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4046;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto ngdefaultget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_ng_def_get(:hv_merchant_id:ind_merchant_id,
								 :hv_channel:ind_channel,
								 :hv_service_code:ind_service_code,
								 :hv_txn_country:ind_txn_country,
								 :hv_txn_ccy:ind_txn_ccy,
								 :hv_ip_region_code:ind_ip_region_code,
								 :hv_device_type:ind_device_type,
								 :hv_amount:ind_amount,
								 :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_ng_def_get ( :hv\
_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_code:ind\
_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy , :\
hv_ip_region_code:ind_ip_region_code , :hv_device_type:ind_device_type , :hv_\
amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4065;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_device_type;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_device_type;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_amount;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto ngdefaultget_error;
}



	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_customer_grp = -1;
			ind_ccy = -1;
			ind_bank_group = -1;
			ind_bank = -1;
			ind_select_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;
			ind_psp_id = -1;
			ind_is_all_child_outage = -1;
			ind_is_child_outage = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank_group:ind_bank_group,
				:v_bank:ind_bank,
				:v_select_bank:ind_select_bank,
				:v_is_all_child_outage:ind_is_all_child_outage,
				:v_is_child_outage:ind_is_child_outage,
				:v_customer_grp:ind_customer_grp,
				:v_ccy:ind_ccy,
				:v_psp_id:ind_psp_id,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4120;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_group;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank_group;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_bank;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_select_bank;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_select_bank;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_is_all_child_outage;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_is_all_child_outage;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_is_child_outage;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_is_child_outage;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_customer_grp;
   sqlstm.sqhstl[6] = (unsigned long )13;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_customer_grp;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[7] = (unsigned long )5;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_ccy;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[8] = (unsigned long )12;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_psp_id;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_credit_option;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_debit_option;
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
   if (sqlca.sqlcode < 0) goto ngdefaultget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}
			
			if (ind_bank_group >= 0) {
                                v_bank_group.arr[v_bank_group.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]bank_group = [%s]\n",iCnt,v_bank_group.arr));
                                PutField_CString(myHash,"bank_group",(const char*)v_bank_group.arr);
                        }

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				//PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_select_bank >= 0) {
                                v_select_bank.arr[v_select_bank.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]select_bank = [%s]\n",iCnt,v_select_bank.arr));
                                PutField_CString(myHash,"bank_code",(const char*)v_select_bank.arr);
                        }

			if (ind_is_all_child_outage >= 0) {
DEBUGLOG(("GetNGBankDefault: [%03d]is_all_child_outage = [%d]\n",iCnt,v_is_all_child_outage));
				PutField_Int(myHash,"is_all_child_outage",v_is_all_child_outage);
			}

			if (ind_is_child_outage >= 0) {
DEBUGLOG(("GetNGBankDefault: [%03d]is_child_outage = [%d]\n",iCnt,v_is_child_outage));
				PutField_Int(myHash,"is_child_outage",v_is_child_outage);
			}

			if (ind_customer_grp>= 0) {
				v_customer_grp.arr[v_customer_grp.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]customer_grp = [%s]\n",iCnt,v_customer_grp.arr));
				PutField_CString(myHash,"customer_grp",(const char*)v_customer_grp.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetNGBankDefault: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetNGBankDefault: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetNGBankDefault: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetNGBankDefault: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4183;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto ngdefaultget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4202;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto ngdefaultget_error;
}


DEBUGLOG(("GetNGBankDefault: Finished\n"));

	return iRet;

ngdefaultget_error:
DEBUGLOG(("ngdefaultget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4221;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4240;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


int GetBankPspByOtherMerchDefault(const char* csOptionBank,
                        const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csIpRegionCode,
                        char  cDeviceType,
                        const int   iRestrictedIP,
                        const double dAmt,
                        recordset_t* myRec)
{
        int iRet = PD_OK;
        int     iCnt = 0;

        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO othermerchdefget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

                /* varchar v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

                /* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

                /* varchar v_bank_group[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank_group;

                /* varchar v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

                double  v_remaining_limit;
                int     v_credit_option;
                int     v_debit_option;

                /* varchar hv_option_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_option_bank;

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

                char    hv_device_type;
		double  hv_amount;
                int     hv_restricted_ip;

                short   hv_return_value;

                short   ind_psp_id = -1;
                short   ind_client_id = -1;
                short   ind_ccy = -1;
                short   ind_bank_group= -1;
                short   ind_bank= -1;
                short   ind_remaining_limit = -1;
                short   ind_credit_option = -1;
                short   ind_debit_option = -1;

                short   ind_option_bank = -1;
                short   ind_merchant_id = -1;
		short   ind_service_code = -1;
                short   ind_channel = -1;
                short   ind_txn_country = -1;
                short   ind_txn_ccy = -1;
                short   ind_ip_region_code = -1;
		short   ind_device_type = -1;
                short   ind_amount = -1;
                short   ind_restricted_ip = -1;

                SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* option_bank */
        hv_option_bank.len = strlen(csOptionBank);
        memcpy(hv_option_bank.arr,csOptionBank,hv_option_bank.len);
        ind_option_bank = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: option_bank = [%.*s]\n",hv_option_bank.len,hv_option_bank.arr));

/* channel */
        hv_channel.len = strlen(csChannel);
        memcpy(hv_channel.arr,csChannel,hv_channel.len);
        ind_channel = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
        hv_txn_country.len = strlen(csCountry);
        memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
        ind_txn_country = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy */
        hv_txn_ccy.len = strlen(csCcy);
        memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* device_type */
        hv_device_type = cDeviceType;
        ind_device_type = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: device_type = [%c]\n",hv_device_type));

/* amount*/
        hv_amount = dAmt;
        ind_amount = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: amount = [%.2f]\n",dAmt));

/* restricted_ip */
        hv_restricted_ip = iRestrictedIP;
        ind_restricted_ip  = 0;
DEBUGLOG(("GetBankPspByOtherMerchDefault: restricted_ip = [%d]\n",iRestrictedIP));


/*
        EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_def_cardtype_get( :hv_option_bank:ind_option_bank,
                                                                             :hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_device_type:ind_device_type,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amount:ind_amount,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

        /* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4259;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto othermerchdefget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_ng_def_cardtp_get(:hv_option_bank:ind_option_bank,
                                                                      :hv_merchant_id:ind_merchant_id,
                                                                      :hv_channel:ind_channel,
                                                                      :hv_service_code:ind_service_code,
                                                                      :hv_txn_country:ind_txn_country,
                                                                      :hv_txn_ccy:ind_txn_ccy,
                                                                      :hv_ip_region_code:ind_ip_region_code,
								      :hv_device_type:ind_device_type,
                                                                      :hv_restricted_ip:ind_restricted_ip,
                                                                      :hv_amount:ind_amount,
                                                                      :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_ng_def_cardtp_ge\
t ( :hv_option_bank:ind_option_bank , :hv_merchant_id:ind_merchant_id , :hv_c\
hannel:ind_channel , :hv_service_code:ind_service_code , :hv_txn_country:ind_\
txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_ip_region_code:ind_ip_region_code\
 , :hv_device_type:ind_device_type , :hv_restricted_ip:ind_restricted_ip , :h\
v_amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4278;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_option_bank;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_option_bank;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_channel;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_service_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[5] = (unsigned long )4;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_country;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_device_type;
        sqlstm.sqhstl[8] = (unsigned long )1;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_device_type;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_amount;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto othermerchdefget_error;
}




        if (hv_return_value == 0 ) {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_psp_id = -1;
                        ind_client_id = -1;
                        ind_ccy = -1;
                        ind_bank_group = -1;
                        ind_bank = -1;
                        ind_remaining_limit = -1;
                        ind_credit_option = -1;
                        ind_debit_option = -1;
		
			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO    :v_bank_group:ind_bank_group,
				:v_bank:ind_bank,
                                :v_client_id:ind_client_id,
                                :v_psp_id:ind_psp_id,
                                :v_ccy:ind_ccy,
                                :v_remaining_limit:ind_remaining_limit,
                                :v_credit_option:ind_credit_option,
                                :v_debit_option:ind_debit_option; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 12;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )4341;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_group;
                        sqlstm.sqhstl[1] = (unsigned long )12;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_bank_group;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_bank;
                        sqlstm.sqhstl[2] = (unsigned long )12;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_bank;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                        sqlstm.sqhstl[3] = (unsigned long )12;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_client_id;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[4] = (unsigned long )12;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_ccy;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_remaining_limit;
                        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_remaining_limit;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_credit_option;
                        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_credit_option;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_debit_option;
                        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_debit_option;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto othermerchdefget_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

			if (ind_bank_group >= 0) {
                                v_bank_group.arr[v_bank_group.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]bank_group = [%s]\n",iCnt,v_bank_group.arr));
                                PutField_CString(myHash,"bank_group",(const char*)v_bank_group.arr);
                        }

                        if (ind_bank >= 0) {
                                v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
                                PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
                        }

                        if (ind_psp_id >= 0) {
                                v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
                                PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
                        }

                        if (ind_client_id >= 0) {
                                v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
                                PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
                        }

                        if (ind_ccy>= 0) {
                                v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
                                PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
                        }

                        if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
                                PutField_Double(myHash,"remaining_limit",v_remaining_limit);
                        }

                        if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
                                PutField_Int(myHash,"credit_option",v_credit_option);
                        }

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspByOtherMerchDefault: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
                                PutField_Int(myHash,"debit_option",v_debit_option);
                        }

                        RecordSet_Add(myRec,myHash);
                        iCnt++;
                }
        }

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4392;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto othermerchdefget_error;
}


        /* EXEC SQL FREE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4411;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto othermerchdefget_error;
}


DEBUGLOG(("GetBankPspByOtherMerchDefault: Finished\n"));

        return iRet;

othermerchdefget_error:
DEBUGLOG(("othermerchdefget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4430;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4449;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


int GetMobileBankByMerchNCcyNGrpNew(const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
                        const char* csCcy,
			const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,			
			char cDeviceType,
			const int iSARIP,
			const int iRestrictedIP,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO mobnewccygrpget_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 



		/* varchar	v_customer_grp[PD_CUSTOMER_GROUP_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_grp;

		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank_group[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank_group;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		/* varchar	v_select_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_select_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;
		int	v_is_all_child_outage;
		int	v_is_child_outage;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

                /* varchar hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

                /* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		/* varchar hv_cust_id[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_id;

		char	hv_device_type;	
		int     hv_sarip;
		int     hv_restricted_ip;
		double	hv_amount;

		short	hv_return_value;


		short	ind_customer_grp = -1;
		short	ind_psp_id = -1;
		short	ind_ccy = -1;
		short	ind_bank_group= -1;
		short	ind_bank= -1;
		short	ind_select_bank = -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;
		short	ind_is_all_child_outage = -1;
		short	ind_is_child_outage = -1;

		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_customer_group = -1;
		short	ind_ip_region_code = -1;
		short	ind_cust_id = -1;
		short	ind_device_type = -1;
		short	ind_sarip = -1;
		short	ind_restricted_ip = -1;
		short	ind_amount = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* txn_ccy*/
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* customer_group */
        if(csCustomerGroup!=NULL){
                hv_customer_group.len = strlen(csCustomerGroup);
                memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
                ind_customer_group = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
        }

/* ip_region_code*/
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* cust_id */
	if(csCustId == NULL){
		hv_cust_id.len = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: cust_id = NULL\n"));
	}
	else{
		hv_cust_id.len = strlen(csCustId);
		memcpy(hv_cust_id.arr,csCustId,hv_cust_id.len);
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: cust_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}
	ind_cust_id = 0;


/* device_type */
	hv_device_type = cDeviceType;
        ind_device_type = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: device_type = [%c]\n",hv_device_type));

/* sarip */
        hv_sarip = iSARIP;
        ind_sarip  = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: sarip = [%d]\n",hv_sarip));

/* restricted_ip */
        hv_restricted_ip = iRestrictedIP;
        ind_restricted_ip  = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: restricted_ip = [%d]\n",hv_restricted_ip));

/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: amount = [%lf]\n",hv_amount));

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mcgrp_get_mob_new( :hv_merchant_id:ind_merchant_id,
                                                                       :hv_channel:ind_channel,
                                                                       :hv_service_code:ind_service_code,
                                                                       :hv_txn_country:ind_txn_country,
                                                                       :hv_txn_ccy:ind_txn_ccy,
                                                                       :hv_customer_group:ind_customer_group,
                                                                       //:hv_device_type:ind_device_type,
                                                                       :hv_sarip:ind_sarip,
                                                                       :hv_restricted_ip:ind_restricted_ip,
                                                                       :hv_amount:ind_amount,
                                                                       :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mob_mcgrp_get(:hv_merchant_id:ind_merchant_id,
								    :hv_channel:ind_channel,
								    :hv_service_code:ind_service_code,
								    :hv_txn_country:ind_txn_country,
								    :hv_txn_ccy:ind_txn_ccy,
								    :hv_customer_group:ind_customer_group,
								    :hv_ip_region_code:ind_ip_region_code,
								    //:hv_device_type:ind_device_type,
								    :hv_sarip:ind_sarip,
								    :hv_restricted_ip:ind_restricted_ip,
								    :hv_amount:ind_amount,
								    :c_cursor_id);
                END;
        END-EXEC;
*/

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4468;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobnewccygrpget_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_get_mob_mcgrp(:hv_merchant_id:ind_merchant_id,
								    :hv_channel:ind_channel,
								    :hv_service_code:ind_service_code,
								    :hv_txn_country:ind_txn_country,
								    :hv_txn_ccy:ind_txn_ccy,
								    :hv_customer_group:ind_customer_group,
								    :hv_ip_region_code:ind_ip_region_code,
								    :hv_cust_id:ind_cust_id,
								    //:hv_device_type:ind_device_type,
								    :hv_sarip:ind_sarip,
								    :hv_restricted_ip:ind_restricted_ip,
								    :hv_amount:ind_amount,
								    :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_get_mob_mcgrp ( \
:hv_merchant_id:ind_merchant_id , :hv_channel:ind_channel , :hv_service_code:\
ind_service_code , :hv_txn_country:ind_txn_country , :hv_txn_ccy:ind_txn_ccy \
, :hv_customer_group:ind_customer_group , :hv_ip_region_code:ind_ip_region_co\
de , :hv_cust_id:ind_cust_id , :hv_sarip:ind_sarip , :hv_restricted_ip:ind_re\
stricted_ip , :hv_amount:ind_amount , :c_cursor_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4487;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_channel;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_country;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_customer_group;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_cust_id;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_cust_id;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_sarip;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_sarip;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_amount;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto mobnewccygrpget_error;
}






	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_customer_grp = -1;
			ind_ccy = -1;
			ind_bank_group = -1;
			ind_bank = -1;
			ind_select_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;
			ind_psp_id = -1;
			ind_is_all_child_outage = -1;
			ind_is_child_outage = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank_group:ind_bank_group,
				:v_bank:ind_bank,
				:v_select_bank:ind_select_bank,
				:v_is_all_child_outage:ind_is_all_child_outage,
				:v_is_child_outage:ind_is_child_outage,
				:v_customer_grp:ind_customer_grp,
				:v_ccy:ind_ccy,
				:v_psp_id:ind_psp_id,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4554;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_group;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank_group;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_bank;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_select_bank;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_select_bank;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_is_all_child_outage;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_is_all_child_outage;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_is_child_outage;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_is_child_outage;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_customer_grp;
   sqlstm.sqhstl[6] = (unsigned long )13;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_customer_grp;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[7] = (unsigned long )5;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_ccy;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[8] = (unsigned long )12;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_psp_id;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_credit_option;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_debit_option;
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
   if (sqlca.sqlcode < 0) goto mobnewccygrpget_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}
			
			if (ind_bank_group >= 0) {
                                v_bank_group.arr[v_bank_group.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]bank_group = [%s]\n",iCnt,v_bank_group.arr));
                                PutField_CString(myHash,"bank_code",(const char*)v_bank_group.arr);
                        }

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				//PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_select_bank >= 0) {
                                v_select_bank.arr[v_select_bank.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]select_bank = [%s]\n",iCnt,v_select_bank.arr));
                                //PutField_CString(myHash,"bank_code",(const char*)v_select_bank.arr);
                        }

			if (ind_is_all_child_outage >= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]is_all_child_outage = [%d]\n",iCnt,v_is_all_child_outage));
				PutField_Int(myHash,"is_all_child_outage",v_is_all_child_outage);
			}

			if (ind_is_child_outage >= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]is_child_outage = [%d]\n",iCnt,v_is_child_outage));
				PutField_Int(myHash,"is_child_outage",v_is_child_outage);
			}

			if (ind_customer_grp>= 0) {
				v_customer_grp.arr[v_customer_grp.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]customer_grp = [%s]\n",iCnt,v_customer_grp.arr));
				PutField_CString(myHash,"customer_grp",(const char*)v_customer_grp.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4617;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobnewccygrpget_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4636;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto mobnewccygrpget_error;
}


DEBUGLOG(("GetMobileBankByMerchNCcyNGrpNew: Finished\n"));

	return iRet;

mobnewccygrpget_error:
DEBUGLOG(("mobnewccygrpget_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4655;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4674;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


int GetBankPspByMerchNCcyNGrpNew( const char* csOptionBank,
			const char* csChannel,
                        const char* csMerchantId,
                        const char* csServiceCode,
                        const char* csCountry,
			const char* csCcy,
			const char* csCustomerGroup,
			const char* csIpRegionCode,
			const char* csCustId,
			const int   iRestrictedIP,
			const double dAmt,
			recordset_t* myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO maccygrpgetnew_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_client_id;

		/* varchar v_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ccy;

		/* varchar	v_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank;

		double	v_remaining_limit;
		int	v_credit_option;
		int	v_debit_option;

		/* varchar hv_option_bank[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_option_bank;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		/* varchar hv_ip_region_code[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_ip_region_code;

		/* varchar hv_cust_id[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_id;

		double	hv_amount;
		int	hv_restricted_ip;

		short	hv_return_value;

		short	ind_psp_id = -1;
		short	ind_client_id = -1;
		short	ind_ccy = -1;
		short	ind_bank= -1;
		short	ind_remaining_limit = -1;
		short	ind_credit_option = -1;
		short	ind_debit_option = -1;

		short   ind_option_bank = -1;
		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_channel = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_customer_group = -1;
		short	ind_ip_region_code = -1;
		short	ind_cust_id = -1;
		short	ind_amount = -1;
		short	ind_restricted_ip = -1;

		SQL_CURSOR      c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


/* option_bank */
        hv_option_bank.len = strlen(csOptionBank);
        memcpy(hv_option_bank.arr,csOptionBank,hv_option_bank.len);
        ind_option_bank = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: option_bank = [%.*s]\n",hv_option_bank.len,hv_option_bank.arr));

/* channel */
	hv_channel.len = strlen(csChannel);
	memcpy(hv_channel.arr,csChannel,hv_channel.len);
	ind_channel = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: channel = [%.*s]\n",hv_channel.len,hv_channel.arr));

/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
	ind_txn_country = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy */
	hv_txn_ccy.len = strlen(csCcy);
	memcpy(hv_txn_ccy.arr,csCcy,hv_txn_ccy.len);
	ind_txn_ccy = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* ip_region_code */
        hv_ip_region_code.len = strlen(csIpRegionCode);
        memcpy(hv_ip_region_code.arr,csIpRegionCode,hv_ip_region_code.len);
        ind_ip_region_code = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: ip_region_code = [%.*s]\n",hv_ip_region_code.len,hv_ip_region_code.arr));

/* cust_id */
	if(csCustId == NULL){
		hv_cust_id.len = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: cust_id = NULL\n"));
	}
	else{
		hv_cust_id.len = strlen(csCustId);
		memcpy(hv_cust_id.arr,csCustId,hv_cust_id.len);
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: cust_id = [%.*s]\n",hv_cust_id.len,hv_cust_id.arr));
	}
	ind_cust_id = 0;


/* amount*/
	hv_amount = dAmt;
	ind_amount = 0;

/* restricted_ip */
	hv_restricted_ip = iRestrictedIP;
	ind_restricted_ip  = 0;

/* customer_group */
	if(csCustomerGroup!=NULL){
		hv_customer_group.len = strlen(csCustomerGroup);
		memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
		ind_customer_group = 0;
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
	}


/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mcgrp_card_get_new( :hv_option_bank:ind_option_bank,
                                                                             :hv_merchant_id:ind_merchant_id,
                                                                             :hv_channel:ind_channel,
                                                                             :hv_service_code:ind_service_code,
                                                                             :hv_txn_country:ind_txn_country,
                                                                             :hv_txn_ccy:ind_txn_ccy,
                                                                             :hv_customer_group:ind_customer_group,
                                                                             :hv_restricted_ip:ind_restricted_ip,
                                                                             :hv_amount:ind_amount,
                                                                             :c_cursor_id);
                END;
        END-EXEC;
*/

/*
	EXEC SQL ALLOCATE       :c_cursor_id;
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_mob_mcgrp_cardtp_get(:hv_option_bank:ind_option_bank,
									 :hv_merchant_id:ind_merchant_id,
									 :hv_channel:ind_channel,
									 :hv_service_code:ind_service_code,
									 :hv_txn_country:ind_txn_country,
									 :hv_txn_ccy:ind_txn_ccy,
									 :hv_customer_group:ind_customer_group,
									 :hv_ip_region_code:ind_ip_region_code,
									 :hv_restricted_ip:ind_restricted_ip,
									 :hv_amount:ind_amount,
									 :c_cursor_id);
                END;
        END-EXEC;
*/
	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4693;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpgetnew_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rulelb_get_mob_mcgrp_cardtp(:hv_option_bank:ind_option_bank,
									 :hv_merchant_id:ind_merchant_id,
									 :hv_channel:ind_channel,
									 :hv_service_code:ind_service_code,
									 :hv_txn_country:ind_txn_country,
									 :hv_txn_ccy:ind_txn_ccy,
									 :hv_customer_group:ind_customer_group,
									 :hv_ip_region_code:ind_ip_region_code,
									 :hv_cust_id:ind_cust_id,
									 :hv_restricted_ip:ind_restricted_ip,
									 :hv_amount:ind_amount,
									 :c_cursor_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rulelb_get_mob_mcgrp_ca\
rdtp ( :hv_option_bank:ind_option_bank , :hv_merchant_id:ind_merchant_id , :h\
v_channel:ind_channel , :hv_service_code:ind_service_code , :hv_txn_country:i\
nd_txn_country , :hv_txn_ccy:ind_txn_ccy , :hv_customer_group:ind_customer_gr\
oup , :hv_ip_region_code:ind_ip_region_code , :hv_cust_id:ind_cust_id , :hv_r\
estricted_ip:ind_restricted_ip , :hv_amount:ind_amount , :c_cursor_id ) ; END\
 ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )4712;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_option_bank;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_option_bank;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_channel;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_service_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[5] = (unsigned long )4;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_country;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[7] = (unsigned long )12;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_customer_group;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_ip_region_code;
        sqlstm.sqhstl[8] = (unsigned long )4;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_ip_region_code;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_cust_id;
        sqlstm.sqhstl[9] = (unsigned long )12;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_cust_id;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_restricted_ip;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_restricted_ip;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_amount;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&c_cursor_id;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto maccygrpgetnew_error;
}










	if (hv_return_value == 0 ) {
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);	

			ind_psp_id = -1;
			ind_client_id = -1;
			ind_ccy = -1;
			ind_bank = -1;
			ind_remaining_limit = -1;
			ind_credit_option = -1;
			ind_debit_option = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_id
			INTO	:v_bank:ind_bank,
				:v_client_id:ind_client_id,
				:v_psp_id:ind_psp_id,
				:v_ccy:ind_ccy,
				:v_remaining_limit:ind_remaining_limit,
				:v_credit_option:ind_credit_option,
				:v_debit_option:ind_debit_option; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )4779;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_bank;
   sqlstm.sqhstl[1] = (unsigned long )12;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_bank;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
   sqlstm.sqhstl[2] = (unsigned long )12;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_client_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[3] = (unsigned long )12;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_psp_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_remaining_limit;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_credit_option;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_credit_option;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_debit_option;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_debit_option;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto maccygrpgetnew_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_bank >= 0) {
				v_bank.arr[v_bank.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]bank = [%s]\n",iCnt,v_bank.arr));
				PutField_CString(myHash,"bank_code",(const char*)v_bank.arr);
			}

			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]psp_id = [%s]\n",iCnt,v_psp_id.arr));
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
			}

			if (ind_client_id >= 0) {
				v_client_id.arr[v_client_id.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]client_id = [%s]\n",iCnt,v_client_id.arr));
				PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
			}

			if (ind_ccy>= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]ccy = [%s]\n",iCnt,v_ccy.arr));
				PutField_CString(myHash,"psp_ccy",(const char*)v_ccy.arr);
			}
	
			if (ind_remaining_limit>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]remaining_limit = [%lf]\n",iCnt,v_remaining_limit));
				PutField_Double(myHash,"remaining_limit",v_remaining_limit);
			}

			if (ind_credit_option>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]credit_option = [%d]\n",iCnt,v_credit_option));
				PutField_Int(myHash,"credit_option",v_credit_option);
			}

			if (ind_debit_option>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]debit_option = [%d]\n",iCnt,v_debit_option));
				PutField_Int(myHash,"debit_option",v_debit_option);
			}

/*
			if (ind_scheduler_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]scheduler_id = [%d]\n",iCnt,v_scheduler_id));
				PutField_Int(myHash,"scheduler_id",v_scheduler_id);
			}

			if (ind_note_id>= 0) {
DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: [%03d]note_id = [%d]\n",iCnt,v_note_id));
				PutField_Int(myHash,"note_id",v_note_id);
			}
*/
			RecordSet_Add(myRec,myHash);
			iCnt++;
		}
	}

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4826;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpgetnew_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )4845;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto maccygrpgetnew_error;
}


DEBUGLOG(("GetBankPspByMerchNCcyNGrpNew: Finished\n"));

	return iRet;

maccygrpgetnew_error:
DEBUGLOG(("maccygrpgetnew_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4864;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


    /* EXEC SQL FREE :c_cursor_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )4883;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

