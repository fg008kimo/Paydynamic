create or replace view CRRJNL_VIEW as 
SELECT th_txn_id
 FROM txn_header
WHERE 
    ROWNUM = 1
/
