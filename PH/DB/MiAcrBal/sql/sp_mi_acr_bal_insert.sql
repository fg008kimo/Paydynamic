create or replace function sp_mi_acr_bal_insert(
       in_from_ccy			mi_acr_bal.ma_from_ccy%type,
       in_bank_ccy			mi_acr_bal.ma_bank_ccy%type,
       in_bank_bal			mi_acr_bal.ma_bank_bal%type,	
       in_rate				mi_acr_bal.ma_rate%type,
       in_create_user                   mi_acr_bal.ma_create_user%type
)
  RETURN NUMBER IS
Begin
     Update mi_acr_bal
            Set	  ma_bank_bal = in_bank_bal,
		  ma_rate = in_rate,
		  ma_update_user = in_create_user,
		  ma_update_timestamp = sysdate
      Where ma_from_ccy = in_from_ccy
	and ma_bank_ccy = in_bank_ccy;

     IF SQL%ROWCOUNT = 0 THEN
        insert into mi_acr_bal
                     (ma_from_ccy,
		      ma_bank_ccy,
		      ma_bank_bal,
		      ma_rate,
                      ma_create_user,
                      ma_create_timestamp,
                      ma_update_user,
                      ma_update_timestamp)
          values(in_from_ccy,
		     in_bank_ccy,
                     in_bank_bal,
		     in_rate,
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
end sp_mi_acr_bal_insert;
/
