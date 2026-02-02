load data
infile 'tmp.txt'
append
into table ol_payout_generated_tmp
fields terminated by '|'
(
 OPT_ID,
 OPT_TXN_ID,
 OPT_PSP_ID,
 OPT_BANK_CODE,
 OPT_DISABLED
 OPT_CREATE_TIMESTAMP  SYSDATE,
 OPT_UPDATE_TIMESTAMP  SYSDATE
)
