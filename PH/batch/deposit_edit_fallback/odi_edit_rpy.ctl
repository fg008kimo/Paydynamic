load data
infile 'ALL_RPY.tmp.5'
append
into table tmp_ol_odi_edit_rpy
fields terminated by ','
(
  REC_DATE,
  REC_NO,
  TXN_ID,
  ERROR_CODE
)
