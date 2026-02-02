CREATE OR REPLACE FUNCTION sp_check_hand_shake_insert(
	in_party_id		check_hand_shake.ch_party_id%type,
        in_check_count		check_hand_shake.ch_check_count%type,
        in_max_handshake_count	check_hand_shake.ch_max_handshake_count%type,
	in_disabled		check_hand_shake.ch_disabled%type,
	in_start_buffer_period	check_hand_shake.ch_start_buffer_period%type,
	in_min_total		check_hand_shake.ch_min_total%type,
	in_max_init_count	check_hand_shake.ch_max_init_count%type,
	in_create_user		check_hand_shake.ch_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO check_hand_shake(
	ch_party_id,
	ch_cutoff_checking_time,
	ch_check_count,
	ch_max_handshake_count,
	ch_disabled,
	ch_last_checking_time,
	ch_start_buffer_period,
	ch_min_total,
	ch_create_user,
	ch_update_user,
	ch_create_timestamp,
	ch_update_timestamp,
	ch_max_init_count
	)

  VALUES(
	in_party_id,
	sysdate,
        in_check_count,
	in_max_handshake_count,
	in_disabled,
	sysdate,
	in_start_buffer_period,
	in_min_total,
	in_create_user,
	in_create_user,
	sysdate,
	sysdate,
	in_max_init_count
	);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_check_hand_shake_insert;
/
