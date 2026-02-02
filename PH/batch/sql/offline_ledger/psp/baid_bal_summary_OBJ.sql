CREATE OR REPLACE
TYPE BAID_BAL_SUMMARY_OBJ is object (
  obai_baid             varchar(20),
  OBAI_BAID_NAME        varchar(50),
  psp_id                varchar(10),
  txn_code              char(3),
  txn_code_desc         varchar(50),
  txn_element_type      char(4),
  txn_element_type_desc varchar(50),
  amount                number,
  txn_ccy               char(3),
  amt_type              char(2),
  party_type            char(1),
  txn_cnt               integer)
/
