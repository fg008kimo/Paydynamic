DROP FUNCTION sp_rule_payout_exclude_insert;

CREATE OR REPLACE FUNCTION sp_rule_payout_exclude_insert(
	in_client_id		rule_payout_exclude.re_psp_client_id%type,
	in_name			rule_payout_exclude.re_bank_name%type,
	in_create_user		rule_payout_exclude.re_create_user%type)
  RETURN NUMBER IS

  iCnt	integer := 0;

BEGIN

  select count(re_bank_name)
  into	iCnt
  from	rule_payout_exclude
  where	re_psp_client_id = in_client_id
  and	re_bank_name = in_name;

  if iCnt > 0 then
	update	rule_payout_exclude
	set	re_disabled = 0,
		re_update_timestamp = sysdate,
		re_update_user = in_create_user
	where	re_psp_client_id = in_client_id
  	and	re_bank_name = in_name
	and	re_disabled = 1;

  	IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
   		RETURN 0;
  	END IF;
  else
  	INSERT INTO rule_payout_exclude(
		re_psp_client_id,
		re_bank_name,
		re_create_timestamp,
		re_create_user,
        	re_update_timestamp,
        	re_update_user
		)

  	VALUES(
		in_client_id,
		in_name,
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

END sp_rule_payout_exclude_insert;
/

