


CREATE OR REPLACE FUNCTION sp_mob_bank_check_nbxa_grp (
   in_psp_id	     psp_detail.psp_id%TYPE)

RETURN NUMBER IS
	iCnt    integer := 0;

BEGIN

   SELECT count(*)
   INTO iCnt
   FROM mob_bank_map,
        (SELECT nbxa_pid_group,
	        bm_int_bank_code
        FROM psp_detail, bank_mapping
        WHERE psp_id = in_psp_id
        AND ((overrided_bank_code_channel IS NOT NULL and overrided_bank_code_channel = bm_psp_channel_id)
             OR (overrided_bank_code_channel IS NULL and psp_channel_code = bm_psp_channel_id))
        AND bm_disabled = 0)
   WHERE mbm_bank_code = bm_int_bank_code
   AND mbm_group = nbxa_pid_group
   AND mbm_disabled = 0
   AND mbm_is_default = 0
   AND mbm_is_fe_use = 0
   AND mbm_is_ng_qr = 0;

   IF iCnt > 0 THEN
	RETURN 1;
   END IF;

   RETURN 0;

EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mob_bank_check_nbxa_grp;
/
