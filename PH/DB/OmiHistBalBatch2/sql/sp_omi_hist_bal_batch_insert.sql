create or replace function sp_omihistbalbatch_insert(
       in_batch_id                              omi_hist_bal_batch_2.omi_batch_id%type,
       in_start_ts                              varchar,
       in_end_ts                                varchar,
       in_disabled                              omi_hist_bal_batch_2.omi_disabled%type,
       in_create_ts                             varchar,
       in_create_user				omi_hist_bal_batch_2.omi_create_user%type)

  RETURN NUMBER IS
begin

  insert into omi_hist_bal_batch_2
               (omi_batch_id,
		omi_start_date,
		omi_end_date,
		omi_disabled,
		omi_create_timestamp,
		omi_create_user)
         values(in_batch_id,
		to_date(in_start_ts,'YYYYMMDDHH24MISS'),
		to_date(in_end_ts,'YYYYMMDDHH24MISS'),
		in_disabled,
		to_date(in_create_ts,'YYYYMMDDHH24MISS'),
		in_create_user);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end  sp_omihistbalbatch_insert;
/
