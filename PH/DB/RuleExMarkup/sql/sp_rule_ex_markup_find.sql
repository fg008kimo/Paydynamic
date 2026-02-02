CREATE OR REPLACE FUNCTION sp_rule_ex_markup_find (
  in_country_id            	rule_ex_markup.rx_country%Type,
  in_channel_code		rule_ex_markup.rx_channel_code%type,  
  in_service_code		rule_ex_markup.rx_service_code%type,  
  in_txn_code            	rule_ex_markup.rx_txn_code%Type,
  in_party_id            	rule_ex_markup.rx_party_id%Type,
  in_party_client_id           	rule_ex_markup.rx_party_id%Type,
  out_rate		out	rule_ex_markup.rx_rate%type,
  out_restricted_rate	out	rule_ex_markup.rx_restricted_rate%type)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	out_rate := 0;
	out_restricted_rate := 0;
	select count(*)
	  into iCnt
    	from rule_ex_markup
       where rx_country = in_country_id
         and rx_channel_code = in_channel_code
	 and rx_service_code = in_service_code
         and rx_txn_code = in_txn_code
	 and rx_party_type = 'M'
         and rx_party_id = in_party_id
	 and rx_disabled = 0;

	if iCnt > 0 THEN
	      select rx_rate,
                     rx_restricted_rate
	  	into out_rate,
		     out_restricted_rate
    		from rule_ex_markup
               where rx_country = in_country_id
                 and rx_channel_code = in_channel_code
	         and rx_service_code = in_service_code
                 and rx_txn_code = in_txn_code
	         and rx_party_type = 'M'
                 and rx_party_id = in_party_id
	 	 and rx_disabled = 0;

		 RETURN 1;
	else 
		select count(*)
	  	  into iCnt
    	          from rule_ex_markup
       	         where rx_country = in_country_id
         	   and rx_channel_code = in_channel_code
	 	   and rx_service_code = in_service_code
         	   and rx_txn_code = in_txn_code
	 	   and rx_party_type = 'C'
         	   and rx_party_id = in_party_client_id
	 	   and rx_disabled = 0;

		if iCnt > 0  then
		  select rx_rate,
                         rx_restricted_rate
	  	    into out_rate,
                         out_restricted_rate
    	            from rule_ex_markup
       	           where rx_country = in_country_id
         	     and rx_channel_code = in_channel_code
	 	     and rx_service_code = in_service_code
         	     and rx_txn_code = in_txn_code
	 	     and rx_party_type = 'C'
         	     and rx_party_id = in_party_client_id
	 	     and rx_disabled = 0;
		     RETURN 1;
		else
			select count(*)
	  	  	  into iCnt
    	                  from rule_ex_markup
       	                 where rx_country = in_country_id
         	           and rx_channel_code = in_channel_code
	 	           and rx_service_code = in_service_code
         	           and rx_txn_code = in_txn_code
	 	           and rx_party_type = 'G'
	 	           and rx_disabled = 0;
			if iCnt > 0 then
			      select rx_rate,
                                     rx_restricted_rate
	  	  	  	into out_rate,
                                     out_restricted_rate
    	                        from rule_ex_markup
       	                       where rx_country = in_country_id
         	                 and rx_channel_code = in_channel_code
	 	                 and rx_service_code = in_service_code
         	                 and rx_txn_code = in_txn_code
	 	                 and rx_party_type = 'G'
	 	                 and rx_disabled = 0;
				
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
END sp_rule_ex_markup_find;
/

