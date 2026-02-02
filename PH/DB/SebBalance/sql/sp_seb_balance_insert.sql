create or replace function sp_seb_balance_insert(
       in_from_ccy			seb_balance.s_from_ccy%type,
       in_bank_ccy			seb_balance.s_bank_ccy%type,
       in_bank_bal			seb_balance.s_bank_bal%type,	
       in_dsp_bal			seb_balance.s_dsp_bal%type,	
       in_rate				seb_balance.s_rate%type,
       in_ratio				seb_balance.s_ratio%type,
       in_create_user                   seb_balance.s_create_user%type
)
  RETURN NUMBER IS
Begin
     Update seb_balance
            Set	  s_bank_bal = in_bank_bal,
		  s_dsp_bal = in_dsp_bal,
		  s_rate = in_rate,
		  s_ratio = in_ratio,
		  s_update_timestamp = sysdate
      Where s_from_ccy = in_from_ccy
	and s_bank_ccy = in_bank_ccy;

     IF SQL%ROWCOUNT = 0 THEN
        insert into seb_balance
                     (s_from_ccy,
		      s_bank_ccy,
		      s_bank_bal,
                      s_dsp_bal,
		      s_rate,
                      s_ratio,
                      s_create_user,
                      s_create_timestamp,
                      s_update_user,
                      s_update_timestamp)
          values(in_from_ccy,
		     in_bank_ccy,
                     in_bank_bal,
		     in_dsp_bal,
		     in_rate,
		     in_ratio,
                     in_create_user,
                     sysdate,
                     in_create_user,
                     sysdate);

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;
      Else
          Return 0;
       End If;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_seb_balance_insert;
/
