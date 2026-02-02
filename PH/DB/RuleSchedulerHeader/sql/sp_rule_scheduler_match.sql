CREATE OR REPLACE FUNCTION sp_rule_scheduler_match (
  in_scheduler_id		rule_scheduler_header.rs_scheduler_id%type,
  in_transmission_datetime	rule_schedule_recur.rr_start_datetime%type,
  in_day_of_week		rule_recur_type.rt_1%type,
  out_cursor              out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from rule_scheduler_header,
	       rule_schedule_once
	 where rs_scheduler_id = in_scheduler_id
	 and   rs_scheduler_id = ro_scheduler_id
	 and   rs_schedule_mode in ('O','M')
	 and   rs_effect_datetime <= sysdate
	 and   ro_start_datetime <= in_transmission_datetime
	 and   ro_end_datetime >= in_transmission_datetime
	 and   ro_disabled = 0
	 and   rs_disabled = 0;

        if iCnt > 0 THEN
              OPEN out_cursor for
	       select rs_schedule_mode,
                      ro_start_datetime,
		      ro_end_datetime
  	  	 from rule_scheduler_header,
		      rule_schedule_once
	 	where rs_scheduler_id = in_scheduler_id
    	   	  and rs_scheduler_id = ro_scheduler_id
		  and rs_schedule_mode in ('O','M')
		  and rs_effect_datetime <= sysdate
		  and ro_start_datetime <= in_transmission_datetime
		  and ro_end_datetime >= in_transmission_datetime
		  and ro_disabled = 0
		  and rs_disabled = 0;

		return 1;

	else
		EXECUTE IMMEDIATE 'select count(*)
		from rule_scheduler_header,
		     rule_schedule_recur,
	     	     rule_recur_type
		where rs_scheduler_id = '''||in_scheduler_id||'''
		and rs_scheduler_id = rr_scheduler_id
		and rs_schedule_mode in (''R'',''M'')
		and rs_effect_datetime <= sysdate 
		and rr_start_datetime <= '''||in_transmission_datetime||'''
		and rr_end_datetime >= '''||in_transmission_datetime||'''
		and rt_id = rr_recurring_id
		and rt_disabled = 0
		and rr_disabled = 0
		and rs_disabled = 0
		and rt_' || in_day_of_week || '= 1'  INTO  iCnt;

        	if iCnt > 0 THEN
			OPEN out_cursor for 'select rs_schedule_mode,
				rr_start_datetime,
				rr_end_datetime
			from rule_scheduler_header,
		 	     rule_schedule_recur,
			     rule_recur_type 
			where	rs_scheduler_id = '''||in_scheduler_id||'''
			and rs_scheduler_id = rr_scheduler_id
			and rs_schedule_mode in (''R'',''M'')
			and rs_effect_datetime <= sysdate
			and rr_start_datetime <= '''||in_transmission_datetime||'''
			and rr_end_datetime >= '''||in_transmission_datetime||'''
			and rt_id = rr_recurring_id
			and rt_disabled = 0
			and rr_disabled = 0
			and rs_disabled = 0
			and rt_' || in_day_of_week || '= 1';
        
		RETURN 1;
		end if;
	end if;

	return 0;

 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_rule_scheduler_match;
/
