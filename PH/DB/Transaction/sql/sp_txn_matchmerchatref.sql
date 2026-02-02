CREATE OR REPLACE FUNCTION sp_transaction_matchmref (
  in_merchant_id            	txn_header.th_merchant_id%Type,
  in_merchant_ref              	txn_header.th_merchant_ref%type)

RETURN NUMBER Is
        iret                                        Integer := 0;
Begin

      select Count(*)
        into iret
        from txn_header
       where  th_merchant_id = in_merchant_id
	 and th_merchant_ref = in_merchant_ref;

         RETURN iret;

 exception
   WHEN OTHERS THEN
     RETURN 1;
END sp_transaction_matchmref;
/

