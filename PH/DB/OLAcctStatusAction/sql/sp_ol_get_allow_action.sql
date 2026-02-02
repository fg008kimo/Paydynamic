CREATE OR REPLACE FUNCTION sp_ol_get_allow_action(
  in_bank_code      ol_bank_accts.ob_int_bank_code%type,
  in_bank_acct_num  ol_bank_accts.ob_bank_acct_num%type,
  in_action         ol_acct_status_action.asa_action%type)
RETURN NUMBER Is
  i_allow_action    ol_acct_status_action.asa_allow_action%type;
Begin

  i_allow_action := 0;  --Not Allow

  begin
    select asa_allow_action
    into i_allow_action
    from ol_acct_status_action, ol_bank_accts
    where ob_int_bank_code = in_bank_code
    and ob_bank_acct_num = in_bank_acct_num
    and ob_status_type = asa_status
    and asa_action = in_action;
  exception
    when no_data_found then
      i_allow_action := 0;        
  end;

  return i_allow_action;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_ol_get_allow_action;
/

