CREATE OR REPLACE FUNCTION sp_ol_batch_eng_act_log_insert(
	in_batch_id		ol_batch_engine_action_log.obel_batch_id%type,
	in_action_id		ol_batch_engine_action_log.obel_action_id%type,
	in_use_pf		ol_batch_engine_action_log.obel_use_pending_fund%type,
	in_input_bank_charge	ol_batch_engine_action_log.obel_input_bank_charge%type,
	in_input_interest	ol_batch_engine_action_log.obel_input_interest%type,
	in_create_user		ol_batch_engine_action_log.obel_create_user%type)
  RETURN NUMBER IS
    iCnt    integer := 0;
BEGIN

  select count(*)
  into iCnt
  from ol_batch_engine_action_log 
  where obel_batch_id = in_batch_id  
  and   obel_action_id= in_action_id;

  if iCnt = 0 then

	INSERT INTO OL_BATCH_ENGINE_ACTION_LOG(
		obel_batch_id,
		obel_action_id,
                obel_use_pending_fund,
                obel_input_bank_charge,
                obel_input_interest,
		obel_create_timestamp,
		obel_create_user,
		obel_update_timestamp,
		obel_update_user
		)
	VALUES (
		in_batch_id,
		in_action_id,
                in_use_pf,
                in_input_bank_charge,
                in_input_interest,
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

  else
	return 0;
  end if;

EXCEPTION
	WHEN OTHERS THEN	
		RETURN 9;

END sp_ol_batch_eng_act_log_insert;
/
