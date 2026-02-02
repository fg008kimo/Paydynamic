CREATE OR REPLACE FUNCTION sp_rule_effect_disabled_bank (
  in_channel			rule_disabled_bank.rb_channel_code%type,
  in_country			def_bank.db_country%type,
  in_party_type			rule_disabled_bank.rb_type%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from rule_disabled_bank,
	       def_bank
	 where db_country = in_country
	 and   rb_type = in_party_type
	 and   rb_channel_code = in_channel
	 and   rb_type = 'G'
	 and   rb_bank_code = db_int_bank_code
	 and   rb_disabled = 0
	 and   rule_schedule_pkg.InEffectivePeriod ( rb_scheduler_id) = 1
	 and   rule_schedule_pkg.InRunningPeriod ( rb_scheduler_id) = 0;

        if iCnt > 0 THEN
              OPEN out_cursor for
	       select rb_bank_code,
		      rb_channel_code,
		      rb_party_id,
		      rb_scheduler_id,
		      rb_note_id
  	  	 from rule_disabled_bank,
		      def_bank,
		      bank_desc
	 	where db_country = in_country
		and   rb_type = in_party_type
		and   rb_channel_code = in_channel
		and   rb_bank_code = db_int_bank_code
		and   rb_bank_code = internal_bank_code
		and   rb_disabled = 0
		and   rule_schedule_pkg.InEffectivePeriod ( rb_scheduler_id) = 1
		and   rule_schedule_pkg.InRunningPeriod ( rb_scheduler_id) = 0
		order by fe_display_order;
                RETURN 1;


	else
		select count(*)
          	into iCnt
          	from rule_disabled_bank,
               	     def_bank
         	where db_country = in_country
         	and   rb_type = in_party_type
         	and   rb_bank_code = db_int_bank_code
         	and   rb_disabled = 0
		and   rule_schedule_pkg.InEffectivePeriod ( rb_scheduler_id) = 1
		and   rule_schedule_pkg.InRunningPeriod ( rb_scheduler_id) = 0;
	
		if iCnt > 0 THEN
			OPEN out_cursor for
			select	rb_bank_code,
                      		rb_channel_code,
                      		rb_party_id,
                      		rb_scheduler_id,
				rb_note_id
                 	from rule_disabled_bank,
                      	     def_bank,
			     bank_desc
                 	where db_country = in_country
                	and   rb_type = in_party_type
                	and   rb_bank_code = db_int_bank_code
			and   rb_bank_code = internal_bank_code
                	and   rb_disabled = 0
			and   rule_schedule_pkg.InEffectivePeriod ( rb_scheduler_id) = 1
			and   rule_schedule_pkg.InRunningPeriod ( rb_scheduler_id) = 0
                	order by fe_display_order;
                	RETURN 1;

		end if;

	end if;

	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_rule_effect_disabled_bank;
/
