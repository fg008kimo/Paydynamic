CREATE OR REPLACE FUNCTION sp_ol_payout_grp_list_delete(
	in_group		ol_payout_grp_list.ogl_group%type,
	in_bank_acct_num	ol_payout_grp_list.ogl_bank_acct_num%type,
	in_bank_acct_name	ol_payout_grp_list.ogl_bank_acct_name%type
)
  RETURN NUMBER IS

         iCnt INTEGER := 0;

BEGIN

  select count(*)
  into iCnt
  from ol_payout_grp_list
  where ogl_group = in_group
  and   ogl_bank_acct_num = in_bank_acct_num
  and   ogl_bank_acct_name = in_bank_acct_name
  and   ogl_disabled = 0;

  if iCnt>0
  then
    	update ol_payout_grp_list
	set   ogl_disabled = 1,
	      ogl_update_timestamp = sysdate
	where ogl_group = in_group
	and   ogl_bank_acct_num = in_bank_acct_num
	and   ogl_bank_acct_name = in_bank_acct_name;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;

  else
       RETURN 0;
  end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_grp_list_delete;
/
