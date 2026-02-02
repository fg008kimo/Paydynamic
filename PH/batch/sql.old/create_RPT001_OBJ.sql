DROP TYPE PHUSER.RPT001_OBJ;

CREATE OR REPLACE TYPE PHUSER.RPT001_OBJ is object (txn_id varchar(16),
					     merchant_ref varchar(50),
                                             txn_code char(3),
                                             txn_code_desc varchar(50),
                                             open_bal number,
                                             current_bal number,
                                             txn_element_type char(4),
                                             txn_element_type_desc varchar(50),
                                             exec_seq         integer,
                                             amount           number,
                                             txn_ccy          char(3),
                                             amt_type         char(2),
                                             bal              number,
                                             approval_date    timestamp(6))
/

