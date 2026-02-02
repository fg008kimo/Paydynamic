create or replace function sp_disabled_bank_match (
        in_psp_id                               disabled_bank.db_psp_id%type,
        in_int_bank_code                        disabled_bank.db_int_bank_code%type
)

RETURN NUMBER IS
        iret            Integer :=0;

begin

        select count(*)
          into iret
          from disabled_bank
         where db_psp_id = in_psp_id
           and db_int_bank_code = in_int_bank_code; 

        return iret;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_disabled_bank_match; 
/

