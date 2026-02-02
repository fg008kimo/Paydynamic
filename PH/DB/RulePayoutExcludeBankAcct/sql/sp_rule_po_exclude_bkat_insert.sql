DROP FUNCTION sp_rule_po_exclude_bkat_insert;

CREATE OR REPLACE FUNCTION sp_rule_po_exclude_bkat_insert(
	in_client_id		rule_payout_exclude_bk_acct.re_psp_client_id%type,
	in_name			rule_payout_exclude_bk_acct.re_acct_name%type,
	in_num			rule_payout_exclude_bk_acct.re_acct_num%type,
	in_create_user		rule_payout_exclude_bk_acct.re_create_user%type)
  RETURN NUMBER IS

  iCnt	integer := 0;

BEGIN

  select count(re_acct_num)
  into	iCnt
  from	rule_payout_exclude_bk_acct
  where	re_psp_client_id = in_client_id
  and	re_acct_name = in_name
  and	re_acct_num = in_num;

  if iCnt > 0 then
	update	rule_payout_exclude_bk_acct
	set	re_disabled = 0,
		re_update_timestamp = sysdate,
		re_update_user = in_create_user
	where	re_psp_client_id = in_client_id
  	and	re_acct_name = in_name
  	and	re_acct_num = in_num
	and	re_disabled = 1;

  	IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
   		RETURN 0;
  	END IF;
  else
  	INSERT INTO rule_payout_exclude_bk_acct(
		re_psp_client_id,
		re_acct_name,
		re_acct_num,
		re_create_timestamp,
		re_create_user,
        	re_update_timestamp,
        	re_update_user
		)

  	VALUES(
		in_client_id,
		in_name,
		in_num,
		sysdate,
		in_create_user,
        	sysdate,
        	in_create_user
		);

  	IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
   		RETURN 0;
  	END IF;
  end if;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_rule_po_exclude_bkat_insert;
/

