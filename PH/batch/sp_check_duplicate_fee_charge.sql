CREATE OR REPLACE FUNCTION sp_check_duplicate_fee_charge(
	out_cursor            out     sys_refcursor)
RETURN NUMBER Is
	iCnt    integer := 0;
Begin

  select count(1)
  into iCnt
         FROM (  SELECT te_txn_id,
                           te_txn_element_type,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           te_party_type,
                           COUNT (1) AS ele_cnt
                      FROM txn_elements
                     WHERE     te_create_timestamp > SYSDATE - 1
                           AND te_party_type = 'M'
                           AND te_txn_element_type IN ('TFEE')
                  GROUP BY te_txn_id,
                           te_txn_element_type,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           te_party_type)
           WHERE ele_cnt > 1
  
  if iCnt > 0 THEN
  OPEN out_cursor for
  SELECT te_txn_id,
         te_txn_element_type,
         te_amount,
	 te_ccy,
	 te_amt_type,
	 te_party_type,
         ele_cnt
            FROM (  SELECT te_txn_id,
                           te_txn_element_type,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           te_party_type,
                           COUNT (1) AS ele_cnt
                      FROM txn_elements
                     WHERE     te_create_timestamp > SYSDATE - 1
                           AND te_party_type = 'M'
                           AND te_txn_element_type IN ('TFEE')
                  GROUP BY te_txn_id,
                           te_txn_element_type,
                           te_amount,
                           te_ccy,
                           te_amt_type,
                           te_party_type)
           WHERE ele_cnt > 1
ORDER BY te_txn_id;
 
 return 1;

else
	return 0;
end if;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_check_duplicate_fee_charge;
/
