DROP TYPE MERCHANT_RPT_TXN_TAB;

@create_merchant_rpt_txn_OBJ.sql;

CREATE OR REPLACE TYPE merchant_rpt_txn_tab IS TABLE OF merchant_rpt_txn_obj
/

@create_merchant_rpt_txn_pkg.sql;

commit;
