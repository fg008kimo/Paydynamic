load data
infile 'ALL_REQ.tmp.5'
append
into table tmp_ol_odi_edit_req
fields terminated by ','
(
  REC_DATE,
  REC_NO,
  REC_TIME,
  TXN_ID,
  DEPOSIT_AMT,
  CUST_DEPOSIT_DATETIME,
  BANK_CODE, 
  BANK_ACCT_NUM,
  DEPOSIT_REF,
  DEPOSIT_BANK
)
