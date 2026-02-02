CREATE OR REPLACE FUNCTION sp_rule_disable_schedule (
  in_channel			rule_disabled_bank.rb_channel_code%type,
  in_party_type			rule_disabled_bank.rb_type%type,
  in_party_id			rule_disabled_bank.rb_party_id%type,
  in_bank_code			rule_disabled_bank.rb_bank_code%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from rule_disabled_bank
	 where rb_type = in_party_type
	 and   rb_type = 'G'
	 and   rb_bank_code = in_bank_code 
	 and   rb_disabled = 0;

        if iCnt > 0 THEN
              OPEN out_cursor for
	       select 
		      rb_scheduler_id,
		      rb_note_id
  	  	 from rule_disabled_bank
		where rb_type = in_party_type
		and   rb_party_id = in_party_id
		and   rb_channel_code = in_channel
		and   rb_bank_code = in_bank_code
		and   rb_disabled = 0
		order by rb_bank_code;
                RETURN 1;


	else
		select count(*)
          	into iCnt
          	from rule_disabled_bank
         	where rb_type = in_party_type
		and   rb_party_id = in_party_id
         	and   rb_bank_code = in_bank_code
         	and   rb_disabled = 0;
	
		if iCnt > 0 THEN
			OPEN out_cursor for
			select	
                      		rb_scheduler_id,
				rb_note_id
                 	from rule_disabled_bank
                	where rb_type = in_party_type
                	and   rb_party_id= in_party_id
                	and   rb_bank_code = in_bank_code
                	and   rb_disabled = 0
                	order by rb_bank_code;
                	RETURN 1;

		end if;

	end if;

	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_rule_disable_schedule;
/
