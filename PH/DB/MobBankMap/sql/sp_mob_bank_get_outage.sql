DROP FUNCTION sp_mob_bank_get_outage;

CREATE OR REPLACE FUNCTION sp_mob_bank_get_outage (
   in_group             customer_group_detail.cgd_code%TYPE,
   out_cursor        OUT SYS_REFCURSOR)
   RETURN NUMBER
IS
BEGIN
   OPEN out_cursor FOR

SELECT mbm_bank_code, rb_scheduler_id, rb_note_id
  FROM (SELECT mbm_group, mbm_bank_code
          FROM mob_bank_map
         WHERE     mbm_is_default = 1
               AND mbm_group = in_group
               AND mbm_disabled = 0)
       LEFT JOIN
       (SELECT rb_bank_code,
               rb_type,
               rb_party_id,
               rb_scheduler_id,
               rb_note_id
          FROM rule_disabled_bank
         WHERE     rb_disabled = 0
               AND rb_channel_code = 'WEB'
               AND rb_type IN ('G')
	       AND RULE_SCHEDULE_PKG.INRUNNINGPERIOD (rb_scheduler_id) = 1
       )
          ON rb_bank_code = mbm_bank_code;

   RETURN 0;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_mob_bank_get_outage;
/
