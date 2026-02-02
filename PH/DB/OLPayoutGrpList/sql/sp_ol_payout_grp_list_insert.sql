CREATE OR REPLACE FUNCTION sp_ol_payout_grp_list_insert(
	in_group		ol_payout_grp_list.ogl_group%type,
	in_bank_acct_num	ol_payout_grp_list.ogl_bank_acct_num%type,
	in_bank_acct_name	ol_payout_grp_list.ogl_bank_acct_name%type,
	in_posting_date		ol_payout_grp_list.ogl_posting_date%type,
	in_user			ol_payout_grp_list.ogl_create_user%type
)
  RETURN NUMBER IS

	 iCnt INTEGER := 0;

BEGIN

  select count(*)
  into iCnt
  from ol_payout_grp_list
  where ogl_bank_acct_num = in_bank_acct_num
  and	ogl_bank_acct_name = in_bank_acct_name
  and	ogl_group = in_group;

  if iCnt=0
  then 
    INSERT INTO ol_payout_grp_list(
	ogl_group,
	ogl_bank_acct_num,
	ogl_bank_acct_name,
	ogl_posting_date,
	ogl_create_timestamp,
        ogl_update_timestamp,
        ogl_create_user,
        ogl_update_user
	)

    VALUES(
	in_group,
	in_bank_acct_num,
	in_bank_acct_name,
	in_posting_date,
	sysdate,
        sysdate,
        in_user,
        in_user
	);

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;

  else
    update ol_payout_grp_list
    set    ogl_disabled = 0,
	   ogl_posting_date = in_posting_date,
	   ogl_update_timestamp = sysdate,
	   ogl_update_user = in_user
    where  ogl_bank_acct_num = in_bank_acct_num
    and    ogl_bank_acct_name = in_bank_acct_name
    and    ogl_group = in_group;

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       return 0;
    end if;
  end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_payout_grp_list_insert;
/
