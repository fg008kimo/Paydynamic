create or replace function sp_seb_balance_update_bal(
       in_from_ccy			seb_balance.s_from_ccy%type,
       in_bank_ccy			seb_balance.s_bank_ccy%type,
       in_bank_bal			seb_balance.s_bank_bal%type
)
  RETURN NUMBER IS
Begin
     Update seb_balance
            Set	  s_bank_bal = in_bank_bal,
		  s_update_timestamp = sysdate
      Where s_from_ccy = in_from_ccy
	and s_bank_ccy = in_bank_ccy;

     IF SQL%ROWCOUNT = 0 THEN
	RETURN 1;
     ELSE
        Return 0;
     End If;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_seb_balance_update_bal;
/
