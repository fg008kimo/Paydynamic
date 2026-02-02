DROP TYPE psp_ledger_OBJ;

CREATE OR REPLACE TYPE psp_ledger_OBJ is object (txn_id varchar(16),
                                             tid varchar(50),
                                             txn_code char(3),
                                             txn_code_desc varchar(50),
                                             open_bal number,
                                             amt_type         char(2),
                                             amount           number,
                                             bal              number,
                                             txn_element_type char(4),
                                             txn_element_type_desc varchar(50),
                                             exec_seq         integer,
                                             txn_ccy          char(3),
                                             approval_timestamp    timestamp(6),
                                             approval_date    varchar(8),
					     report_date      varchar(8),
					     void_txn_id      varchar(16),
					     party_type         char(1));
/
