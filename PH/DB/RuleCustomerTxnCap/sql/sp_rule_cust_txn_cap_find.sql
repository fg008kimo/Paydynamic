CREATE OR REPLACE FUNCTION sp_rule_cust_txn_cap_find (
  in_country_id            	rule_customer_txn_cap.rc_country%Type,
  in_channel_code		rule_customer_txn_cap.rc_channel_code%type,
  in_service_code		rule_customer_txn_cap.rc_service_code%type,
  in_txn_code            	rule_customer_txn_cap.rc_txn_code%Type,
  in_party_id            	rule_customer_txn_cap.rc_party_id%Type,
  in_party_client_id           	rule_customer_txn_cap.rc_party_id%Type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from rule_customer_txn_cap
       where rc_country = in_country_id
         and rc_channel_code = in_channel_code
	 and rc_service_code = in_service_code
         and rc_txn_code = in_txn_code
	 and rc_party_type = 'M'
         and rc_party_id = in_party_id
	 and rc_disabled = 0;

	if iCnt > 0 THEN
	      OPEN out_cursor for
	      select rc_counter_category,
                     rc_duration,
		     rc_value
    		from rule_customer_txn_cap
               where rc_country = in_country_id
                 and rc_channel_code = in_channel_code
	         and rc_service_code = in_service_code
                 and rc_txn_code = in_txn_code
	         and rc_party_type = 'M'
                 and rc_party_id = in_party_id
	 	 and rc_disabled = 0;

		 RETURN 1;
	else
		select count(*)
	  	  into iCnt
    	          from rule_customer_txn_cap
         	 where rc_country = in_country_id
         	   and rc_channel_code = in_channel_code
	 	   and rc_service_code = in_service_code
         	   and rc_txn_code = in_txn_code
	 	   and rc_party_type = 'C'
         	   and rc_party_id = in_party_client_id
	 	   and rc_disabled = 0;

		if iCnt > 0  then
	          OPEN out_cursor for
		  select rc_counter_category,
                         rc_duration,
		         rc_value
    	            from rule_customer_txn_cap
         	   where rc_country = in_country_id
         	     and rc_channel_code = in_channel_code
	 	     and rc_service_code = in_service_code
         	     and rc_txn_code = in_txn_code
	 	     and rc_party_type = 'C'
         	     and rc_party_id = in_party_client_id
	 	     and rc_disabled = 0;

		     RETURN 1;
		else
			select count(*)
	  	  	  into iCnt
    	                  from rule_customer_txn_cap
         	         where rc_country = in_country_id
         	           and rc_channel_code = in_channel_code
	 	           and rc_service_code = in_service_code
         	           and rc_txn_code = in_txn_code
	 	           and rc_party_type = 'G'
	 	           and rc_disabled = 0;

			if iCnt > 0 then
	          	      OPEN out_cursor for
			      select rc_counter_category,
                                     rc_duration,
		                     rc_value
    	                        from rule_customer_txn_cap
         	               where rc_country = in_country_id
         	                 and rc_channel_code = in_channel_code
	 	                 and rc_service_code = in_service_code
         	                 and rc_txn_code = in_txn_code
	 	                 and rc_party_type = 'G'
	 	                 and rc_disabled = 0;

				 RETURN 1;

			ELSE
				RETURN 0;
			END If;

                end if;
	end if;


	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_rule_cust_txn_cap_find;
/

