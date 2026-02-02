CREATE OR REPLACE FUNCTION sp_ol_get_bank_acct_type (
    in_int_bank_code              ol_bank_accts.ob_int_bank_code%type,
    in_bank_acct_num              ol_bank_accts.ob_bank_acct_num%type)
  RETURN VARCHAR2 IS

    v_bank_acct_type              ol_psp_detail.opd_bank_acct_type%type;

BEGIN

    v_bank_acct_type := '000';

    BEGIN
        select opd_bank_acct_type
        into v_bank_acct_type
        from ol_psp_detail, ol_bank_acct_id, ol_bank_accts
        where ob_int_bank_code = in_int_bank_code
        and ob_bank_acct_num = in_bank_acct_num
        and ob_int_bank_code = obai_int_bank_code
        and ob_bank_acct_num = obai_bank_acct_num
        and obai_status = 'O'
        and obai_psp_id = opd_psp_id
        and opd_disabled = 0;
   EXCEPTION
      when no_data_found then
          v_bank_acct_type := '000';
      when too_many_rows then
          v_bank_acct_type := '000';
   END;

   return v_bank_acct_type;

EXCEPTION
  WHEN OTHERS THEN
     RETURN '000';

END sp_ol_get_bank_acct_type;
/

