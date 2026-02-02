create or replace function sp_acr_tolerance_insert(
       in_compare_with			acr_tolerance.at_compare_with%type,
       in_bank_ccy			acr_tolerance.at_bank_ccy%type,
       in_tolerance			acr_tolerance.at_tolerance%type,	
       in_create_user                   acr_tolerance.at_create_user%type
)
  RETURN NUMBER IS
Begin
        insert into acr_tolerance
                     (at_compare_with,
		      at_bank_ccy,
		      at_tolerance,
                      at_create_user,
                      at_create_timestamp,
                      at_update_user,
                      at_update_timestamp)
          values(in_compare_with,
		     in_bank_ccy,
                     in_tolerance,
                     in_create_user,
                     sysdate,
                     in_create_user,
                     sysdate);

          IF SQL%ROWCOUNT = 0 THEN
             RETURN 1;
          ELSE
             RETURN 0;
          END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_acr_tolerance_insert;
/
