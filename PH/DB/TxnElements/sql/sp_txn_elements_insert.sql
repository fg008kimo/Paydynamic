CREATE OR REPLACE function sp_txn_elements_insert(
       	in_txn_id                               txn_elements.te_txn_id%type,
       	in_txn_element_type                     txn_elements.te_txn_element_type%type,
	in_party_type				txn_elements.te_party_type%type,
       	in_amount                     		txn_elements.te_amount%type,
       	in_ccy                     		txn_elements.te_ccy%type,
       	in_amt_type                     	txn_elements.te_amt_type%type,
	in_rate					txn_elements.te_rate%type,
       	in_create_user                          txn_elements.te_create_user%type)
  RETURN NUMBER IS
	iCnt integer := 0;
begin

	select count(1)
	into   iCnt
	from   txn_elements
	where  te_txn_id = in_txn_id
        and    te_txn_element_type = in_txn_element_type
        and    te_party_type = in_party_type
        and    te_ccy = in_ccy
        and    te_amt_type = in_amt_type;

	if iCnt > 0 THEN

	update txn_elements
	set    te_amount = in_amount,
	       te_rate = in_rate
	where  te_txn_id = in_txn_id
	and    te_txn_element_type = in_txn_element_type
	and    te_party_type = in_party_type
	and    te_ccy = in_ccy
	and    te_amt_type = in_amt_type;

	ELSE
	--IF SQL%ROWCOUNT = 0 THEN

		SELECT nvl(max(te_exec_seq),0)
		  INTO iCnt
        	  FROM txn_elements
        	 WHERE te_txn_id = in_txn_id;

		iCnt := iCnt + 1;

	        INSERT into txn_elements
                        (te_txn_id,
			te_txn_element_type,
			te_party_type,
			te_exec_seq,
			te_amount,
			te_ccy,
			te_amt_type,
			te_rate,
                        te_create_user,
                        te_create_timestamp,
                        te_update_user,
                        te_update_timestamp)
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

	END IF;
	RETURN 0;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_txn_elements_insert;
/

