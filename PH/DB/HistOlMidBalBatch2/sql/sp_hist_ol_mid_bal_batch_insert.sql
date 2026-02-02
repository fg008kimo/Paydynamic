create or replace function sp_histolmidbalbatch_insert(
       in_batch_id                              hist_ol_mid_bal_batch_2.hb_batch_id%type,
       in_start_ts                              varchar,
       in_end_ts                                varchar,
       in_disabled                              hist_ol_mid_bal_batch_2.hb_disabled%type,
       in_create_ts                             varchar,
       in_create_user				hist_ol_mid_bal_batch_2.hb_create_user%type)

  RETURN NUMBER IS
begin

  insert into hist_ol_mid_bal_batch_2
               (hb_batch_id,
		hb_start_date,
		hb_end_date,
		hb_disabled,
		hb_create_timestamp,
		hb_create_user)
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
end  sp_histolmidbalbatch_insert;
/
