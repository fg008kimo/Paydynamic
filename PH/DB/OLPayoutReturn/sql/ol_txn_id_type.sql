DROP TYPE OL_TXN_ID_TAB;

DROP TYPE OL_TXN_ID_OBJ;

CREATE OR REPLACE TYPE ol_txn_id_obj is object (
        txn_id       varchar(16),
        txn_code     char(3),
        txn_status   char(1),
        txn_ar_ind   char(1),
        txn_recon_status char(1) 

)
/

CREATE OR REPLACE TYPE ol_txn_id_tab is table of ol_txn_id_obj
/
