DROP FUNCTION sp_mob_bank_get_grp_by_pid;

CREATE OR REPLACE FUNCTION sp_mob_bank_get_grp_by_pid (
   in_psp_id	     psp_detail.psp_id%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

select	mbm_group
from 
	bank_mapping, mob_bank_map, mob_bank_selection
where bm_psp_channel_id =
	(select nvl(overrided_bank_code_channel,psp_channel_code)
		from psp_detail
		where psp_id = in_psp_id)
and bm_disabled = 0
and bm_int_bank_code = mbm_bank_code
and mbm_disabled = 0
and mbm_is_default = 1
and mbm_group = mbs_group
and mbs_disabled = 0;


   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mob_bank_get_grp_by_pid;
/
