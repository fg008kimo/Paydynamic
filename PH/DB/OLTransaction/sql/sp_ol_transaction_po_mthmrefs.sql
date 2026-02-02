CREATE OR REPLACE FUNCTION sp_ol_transaction_po_mthmrefs (
    in_txn_id	       ol_txn_header.oth_txn_id%TYPE,
    in_merchant_id     ol_txn_header.oth_merchant_id%TYPE,
    in_merchant_ref    ol_txn_header.oth_merchant_ref%TYPE)
    RETURN NUMBER
IS
    iret   INTEGER := 0;
BEGIN
    SELECT COUNT (*)
      INTO iret
      FROM ol_txn_header
     WHERE     oth_merchant_id = in_merchant_id
           AND oth_merchant_ref = in_merchant_ref
	   AND oth_txn_id != in_txn_id
           AND NOT (oth_txn_code = 'OPI'
                    AND oth_status = 'C' AND oth_status IS NOT NULL
                    AND oth_ar_ind = 'R' AND oth_ar_ind IS NOT NULL
                    AND oth_sub_status = 150 AND oth_sub_status IS NOT NULL);

    RETURN iret;
EXCEPTION
    WHEN OTHERS
    THEN
        RETURN 1;
END sp_ol_transaction_po_mthmrefs;
/
