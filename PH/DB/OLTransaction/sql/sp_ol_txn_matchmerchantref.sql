CREATE OR REPLACE FUNCTION sp_ol_transaction_matchmref (
  in_merchant_id                ol_txn_header.oth_merchant_id%Type,
  in_merchant_ref               ol_txn_header.oth_merchant_ref%type)

RETURN NUMBER Is
        iret                                        Integer := 0;
Begin

      select Count(*)
        into iret
        from ol_txn_header
       where  oth_merchant_id = in_merchant_id
         and oth_merchant_ref = in_merchant_ref;

         RETURN iret;

 exception
   WHEN OTHERS THEN
     RETURN 1;
END sp_ol_transaction_matchmref;
/

