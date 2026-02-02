CREATE OR REPLACE FUNCTION sp_rule_running_disable_bypsp (
  in_channel			rule_disabled_bank.rb_channel_code%type,
  in_psp_id			rule_disabled_bank.rb_party_id%type,
  in_bank_code			rule_disabled_bank.rb_bank_code%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from rule_disabled_bank,
	       rule_scheduler_header,
	       psp_detail
	 where RULE_SCHEDULE_PKG.InRunningPeriod (rb_scheduler_id) = 1
	 and rb_disabled = 0
	 and rs_disabled = 0
	 and disabled = 0
	 and status = 'O'
	 and ((psp_id = rb_party_id and rb_type = 'P')
	   or (client_id = rb_party_id and rb_type = 'C'))
	 and rb_scheduler_id = rs_scheduler_id
	 and rb_channel_code = in_channel
	 and psp_id = in_psp_id
	 and rb_bank_code = in_bank_code;

        if iCnt > 0 THEN
              OPEN out_cursor for

	      select rb_scheduler_id, rb_note_id
	      from(
		select rb_scheduler_id, rb_note_id, rs_effect_datetime
		from rule_disabled_bank,
		     rule_scheduler_header,
		     psp_detail
		where RULE_SCHEDULE_PKG.InRunningPeriod (rb_scheduler_id) = 1
		and rb_disabled = 0
		and rs_disabled = 0
		and disabled = 0
		and status = 'O'
		and ((psp_id = rb_party_id and rb_type = 'P')
		  or (client_id = rb_party_id and rb_type = 'C'))
		and rb_scheduler_id = rs_scheduler_id
		and rb_channel_code = in_channel
		and psp_id = in_psp_id
		and rb_bank_code = in_bank_code
		group by rb_scheduler_id, rb_note_id, rs_effect_datetime
		order by rs_effect_datetime desc)
	      where rownum = 1;

              RETURN 1;

	end if;

	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_rule_running_disable_bypsp;
/
