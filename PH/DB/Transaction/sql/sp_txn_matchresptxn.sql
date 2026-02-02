CREATE OR REPLACE FUNCTION sp_txn_matchresptxn (
  in_txn_id            		txn_header.th_txn_id%Type,
  in_status              	txn_header.th_status%type)

RETURN NUMBER Is
        iret                                        Integer := 0;
Begin

      select Count(*)
        into iret
        from txn_header
       where  th_txn_id = in_txn_id
	 and th_status = in_status;

         RETURN iret;

 exception
   WHEN OTHERS THEN
     RETURN 1;
END sp_txn_matchresptxn;
/

