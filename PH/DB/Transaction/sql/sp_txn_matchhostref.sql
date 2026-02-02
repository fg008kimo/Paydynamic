CREATE OR REPLACE FUNCTION sp_txn_matchhostref(
  in_channel_code            	txn_header.th_input_channel%Type,
  in_host_ref              	txn_detail.td_remark%type)

RETURN NUMBER Is
        iret                                        Integer := 0;
Begin

      select Count(*)
        into iret
        from txn_header,
	     txn_detail
       where th_input_channel = in_channel_code
	and  td_txn_id = th_txn_id
	and  td_remark = in_host_ref
	and  th_org_txn_id is null
	and  th_status = 'C'
	and  th_ar_ind = 'A';

         RETURN iret;

 exception
   WHEN OTHERS THEN
     RETURN 1;
END sp_txn_matchhostref;
/

