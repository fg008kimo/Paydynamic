load data
infile 'header.txt'
append
into table ol_payout_generated_file_hd_pd
fields terminated by '|'
(OFH_FILE_ID,
 OFH_FILE_DATE,
 OFH_FILE_PID,
 OFH_FILE_BANK_CODE,
 OFH_SEQ_NUM,
 OFH_FILENAME,
 OFH_STATUS,
 OFH_TXN_COUNT,
 OFH_TOTAL_TXN_AMT,
 OFH_CCY_ID,
 OFH_CREATE_TIMESTAMP  SYSDATE,
 OFH_UPDATE_TIMESTAMP  SYSDATE
)
