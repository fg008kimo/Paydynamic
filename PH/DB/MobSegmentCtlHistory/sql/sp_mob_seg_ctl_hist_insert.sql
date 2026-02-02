CREATE OR REPLACE FUNCTION sp_mob_seg_ctl_hist_insert(
	in_group		mob_segment_ctl_history.msh_group%type,
	in_enable_new_cust	mob_segment_ctl_history.msh_enable_new_cust%type,
	in_update_user		mob_segment_ctl_history.msh_update_user%type)
  RETURN NUMBER IS

BEGIN

    INSERT INTO mob_segment_ctl_history (
	msh_group,
	msh_enable_new_cust,
	msh_update_timestamp,
	msh_update_user
	)

    VALUES(
	in_group,
	in_enable_new_cust,
	sysdate,
	in_update_user
	);

    IF SQL%ROWCOUNT = 0 THEN
       RETURN 1;
    ELSE
       RETURN 0;
    END IF;



EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_mob_seg_ctl_hist_insert;
/
