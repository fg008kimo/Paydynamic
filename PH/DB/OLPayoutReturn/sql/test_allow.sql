declare	
	v_txn_id VARCHAR2(20) := '&1';

        v_recon_cnt   NUMBER := 0;
        v_unrecon_cnt NUMBER := 0;
        v_level       NUMBER := 0;

	lRtn NUMBER;
begin


	lRtn := sp_ol_payout_rtn_allow_chk(v_txn_id, v_recon_cnt, v_unrecon_cnt, v_level);

	if lRtn = 0 then
            dbms_output.put_line('ALLOW');
            dbms_output.put_line('txn_id = [' || v_txn_id || ']');
            dbms_output.put_line('recon_cnt = [' || v_recon_cnt || ']');
            dbms_output.put_line('unrecon_cnt = [' || v_unrecon_cnt || ']');
            dbms_output.put_line('level = [' || v_level || ']');
        else 
            dbms_output.put_line('NOT ALLOW');
        end if;
end;
/
