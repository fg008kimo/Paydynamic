CREATE OR REPLACE FUNCTION sp_rule_disabled_bank_info (
  in_bank			rule_disabled_bank.rb_bank_code%type,
  in_type			rule_disabled_bank.rb_type%type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
          into iCnt    
  	  from rule_disabled_bank
	 where  rb_bank_code = in_bank
	 and	rb_type in ('P', 'C')
	 and	rb_disabled = 0;

        if iCnt > 0 THEN
              OPEN out_cursor for
	       select rb_channel_code,
		      rb_type,
		      rb_party_id,
		      rb_scheduler_id
               from ( select rb_channel_code,
		             rb_type,
       		             rb_party_id,
		             rb_scheduler_id
  	  	      from rule_disabled_bank
		      where rb_type = in_type  -- 'P'
		      and   rb_bank_code = in_bank
		      and   rb_disabled = 0
                      union
                      select rb_channel_code,
                             'P' as rb_type,
                             psp_id as rb_party_id,
                             rb_scheduler_id
                      from psp_master, psp_detail, rule_disabled_bank
                      where rb_type = 'C'
                      and rb_bank_code = in_bank
                      and rb_disabled = 0
                      and rb_party_id = pm_client_id
                      and client_id = pm_client_id
                      and rb_disabled = 0
                      and status = 'O'
                      and pm_status = 'O'
                     )
		order by rb_party_id;

                RETURN 1;

	end if;
	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_rule_disabled_bank_info;
/
