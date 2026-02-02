set serverout on

declare
	cursor c1 is 
    select '50029' as merch_txn_nmb, 'A' as merch_txn_type from dual union
    select '50064' as merch_txn_nmb, 'A' as merch_txn_type from dual union
    select '50034' as merch_txn_nmb, 'A' as merch_txn_type from dual union
    select '50075' as merch_txn_nmb, 'A' as merch_txn_type from dual union
    select '50080' as merch_txn_nmb, 'A' as merch_txn_type from dual union
    select '50094' as merch_txn_nmb, 'D' as merch_txn_type from dual union
    select '50028VNC' as merch_txn_nmb, 'D' as merch_txn_type from dual union
    select '50028EC2' as merch_txn_nmb, 'D' as merch_txn_type from dual;
    
  v_merchant_id par_def_merch_nmb_map.mn_merchant_id%type;
	    
begin
  for i in c1 loop
      select mn_merchant_id 
      into   v_merchant_id
      from par_def_merch_nmb_map 
      where mn_merchant_acct_nmb = i.merch_txn_nmb;
  
      update merchant_bal_acct
      set mb_txn_type = i.merch_txn_type
      where mb_merchant_id =  v_merchant_id;
  
  end loop;

  commit;
  dbms_output.put_line('complete!');

exception
  rollback;
  dbms_output.put_line('error!'); 
end;
/
