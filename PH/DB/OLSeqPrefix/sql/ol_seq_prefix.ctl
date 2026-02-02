load data
infile *
append
into table ol_seq_prefix
fields terminated by '|'
(
  osp_prefix,
  osp_desc,
  osp_val           ,
  osp_create_timestamp SYSDATE,
  osp_update_timestamp SYSDATE,
  osp_create_user         ,
  osp_update_user
)
BEGINDATA
N|OLN Channel|OLN_PREFIX|SYSTEM|SYSTEM|
T|OMT Channel|OMT_PREFIX|SYSTEM|SYSTEM|
C|Stmt Txn|STMT_PREFIX|SYSTEM|SYSTEM|
S|Stmt Ref|STMT_REF_PREFIX|SYSTEM|SYSTEM|
A|BAID Txn|BAID_PREFIX|SYSTEM|SYSTEM|
Y|Merchant Payout Txn|MERCH_PO_PREFIX|SYSTEM|SYSTEM|
U|PSP Payout Txn|PSP_PO_PREFIX|SYSTEM|SYSTEM|
