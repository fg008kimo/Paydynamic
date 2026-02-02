load data
infile 'ALL_MER_REF.tmp.4'
append
into table tmp_ol_odi_edit_mer_ref
fields terminated by ','
(
  TXN_ID,
  MERCH_REF
)
