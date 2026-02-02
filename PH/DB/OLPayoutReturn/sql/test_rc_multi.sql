declare	
	v_txn_id VARCHAR2(20) := '&1';

	lRtn NUMBER;
begin


	lRtn := sp_ol_payout_rtn_rc_multi_chk(v_txn_id);

	if lRtn = 0 then
            dbms_output.put_line('PASS');
            dbms_output.put_line('txn_id = [' || v_txn_id || ']');
        else 
            dbms_output.put_line('NOT PASS');
        end if;
end;
/
