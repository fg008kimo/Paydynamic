CREATE OR REPLACE FUNCTION sp_rule_txn_cap_find (
  in_country_id            	rule_merchant_txn_cap.rm_country%Type,
  in_channel_code		rule_merchant_txn_cap.rm_channel_code%type,
  in_service_code		rule_merchant_txn_cap.rm_service_code%type,
  in_txn_code            	rule_merchant_txn_cap.rm_txn_code%Type,
  in_party_id            	rule_merchant_txn_cap.rm_party_id%Type,
  in_party_client_id           	rule_merchant_txn_cap.rm_party_id%Type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from rule_merchant_txn_cap
       where rm_country = in_country_id
         and rm_channel_code = in_channel_code
	 and rm_service_code = in_service_code
         and rm_txn_code = in_txn_code
	 and rm_party_type = 'M'
         and rm_party_id = in_party_id
	 and rm_disabled = 0; 

	if iCnt > 0 THEN
	      OPEN out_cursor for
	      select rm_counter_type,
                     rm_counter_category,
		     rm_value
    		from rule_merchant_txn_cap
               where rm_country = in_country_id
                 and rm_channel_code = in_channel_code
	         and rm_service_code = in_service_code
                 and rm_txn_code = in_txn_code
	         and rm_party_type = 'M'
                 and rm_party_id = in_party_id
	 	 and rm_disabled = 0;

		 RETURN 1;
	else
		select count(*)
	  	  into iCnt
    	          from rule_merchant_txn_cap
         	 where rm_country = in_country_id
         	   and rm_channel_code = in_channel_code
	 	   and rm_service_code = in_service_code
         	   and rm_txn_code = in_txn_code
	 	   and rm_party_type = 'C'
         	   and rm_party_id = in_party_client_id
	 	   and rm_disabled = 0;

		if iCnt > 0  then
	          OPEN out_cursor for
		  select rm_counter_type,
                         rm_counter_category,
		         rm_value
    	            from rule_merchant_txn_cap
         	   where rm_country = in_country_id
         	     and rm_channel_code = in_channel_code
	 	     and rm_service_code = in_service_code
         	     and rm_txn_code = in_txn_code
	 	     and rm_party_type = 'C'
         	     and rm_party_id = in_party_client_id
	 	     and rm_disabled = 0;

		     RETURN 1;
		else
			select count(*)
	  	  	  into iCnt
    	                  from rule_merchant_txn_cap
         	         where rm_country = in_country_id
         	           and rm_channel_code = in_channel_code
	 	           and rm_service_code = in_service_code
         	           and rm_txn_code = in_txn_code
	 	           and rm_party_type = 'G'
	 	           and rm_disabled = 0;

			if iCnt > 0 then
	          	      OPEN out_cursor for
			      select rm_counter_type,
                         	     rm_counter_category,
		                     rm_value
    	                        from rule_merchant_txn_cap
         	               where rm_country = in_country_id
         	                 and rm_channel_code = in_channel_code
	 	                 and rm_service_code = in_service_code
         	                 and rm_txn_code = in_txn_code
	 	                 and rm_party_type = 'G'
	 	                 and rm_disabled = 0;

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
END sp_rule_txn_cap_find;
/

