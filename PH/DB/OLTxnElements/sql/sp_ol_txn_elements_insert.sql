CREATE OR REPLACE function sp_ol_txn_elements_insert(
       	in_txn_id                               ol_txn_elements.ote_txn_id%type,
       	in_txn_element_type                     ol_txn_elements.ote_txn_element_type%type,
	in_party_type				ol_txn_elements.ote_party_type%type,
       	in_amount                     		ol_txn_elements.ote_amount%type,
       	in_ccy                     		ol_txn_elements.ote_ccy%type,
       	in_amt_type                     	ol_txn_elements.ote_amt_type%type,
	in_rate					ol_txn_elements.ote_rate%type,
       	in_create_user                          ol_txn_elements.ote_create_user%type)
  RETURN NUMBER IS
	iCnt integer := 0;
begin
	SELECT nvl(max(ote_exec_seq),0)
	  INTO iCnt
          FROM ol_txn_elements
         WHERE ote_txn_id = in_txn_id;

	iCnt := iCnt + 1;

	        INSERT into ol_txn_elements
                        (ote_txn_id,
			ote_txn_element_type,
			ote_party_type,
			ote_exec_seq,
			ote_amount,
			ote_ccy,
			ote_amt_type,
			ote_rate,
                        ote_create_user,
                        ote_create_timestamp,
                        ote_update_user,
                        ote_update_timestamp)
                 values(in_txn_id,
			in_txn_element_type,
			in_party_type,
			iCnt,
			in_amount,
			in_ccy,
			in_amt_type,
			in_rate,
                        in_create_user,
                        sysdate,
                        in_create_user,
                        sysdate);

		IF SQL%ROWCOUNT = 0 THEN
                        RETURN 1;
                ELSE
                        RETURN 0;
                END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_ol_txn_elements_insert;
/

