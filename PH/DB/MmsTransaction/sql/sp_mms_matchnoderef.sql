CREATE OR REPLACE FUNCTION sp_mms_txn_matchnoderef (
  in_node_id            	mms_txn_header.mth_node_id%Type,
  in_node_ref              	mms_txn_header.mth_node_ref%type)

RETURN NUMBER Is
        iret                                        Integer := 0;
Begin

      select Count(*)
        into iret
        from mms_txn_header
       where  mth_node_id = in_node_id
	 and mth_node_ref = in_node_ref;

         RETURN iret;

 exception
   WHEN OTHERS THEN
     RETURN 1;
END sp_mms_txn_matchnoderef;
/

