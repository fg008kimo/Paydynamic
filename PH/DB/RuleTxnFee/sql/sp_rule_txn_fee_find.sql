CREATE OR REPLACE FUNCTION sp_rule_txn_fee_find (
  in_type			rule_txn_fee.rf_type%type,
  in_country_id            	rule_txn_fee.rf_country%Type,
  in_channel_code		rule_txn_fee.rf_channel_code%type,
  in_service_code		rule_txn_fee.rf_service_code%type,
  in_txn_code            	rule_txn_fee.rf_txn_code%Type,
  in_ccy		        rule_txn_fee.rf_ccy%type,
  in_party_id            	rule_txn_fee.rf_party_id%Type,
  in_party_client_id           	rule_txn_fee.rf_party_id%Type,
  in_pay_method			rule_txn_fee.rf_pay_method%Type,
  out_cursor		out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from rule_txn_fee,
             rule_txn_fee_def
       where rf_type = in_type
         and rf_rule_fee_id = rtd_id
         and rf_country = in_country_id
         and rf_channel_code = in_channel_code
	 and rf_service_code = in_service_code
         and rf_txn_code = in_txn_code
	 and rf_ccy = in_ccy
	 and rf_party_type = 'M'
         and rf_party_id = in_party_id
	 and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 and rf_disabled = 0 
         and rf_effect_date = (
		select max(rf_effect_date)
                  from rule_txn_fee,
                       rule_txn_fee_def
                 where rf_type = in_type
                   and rf_rule_fee_id = rtd_id
                   and rf_country = in_country_id
                   and rf_channel_code = in_channel_code
                   and rf_service_code = in_service_code
                   and rf_txn_code = in_txn_code
                   and rf_ccy = in_ccy
                   and rf_party_type = 'M'
                   and rf_party_id = in_party_id
                   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                   and rf_disabled = 0 
                   and rf_effect_date < sysdate);

	if iCnt > 0 THEN
	      OPEN out_cursor for
	      select rtd_id,
                     rf_min_value,
                     rf_max_value,
                     rf_custom_tag,
		     rf_custom_value
    		from rule_txn_fee,
             	     rule_txn_fee_def
               where rf_type = in_type
                 and rf_rule_fee_id = rtd_id
                 and rf_country = in_country_id
                 and rf_channel_code = in_channel_code
	         and rf_service_code = in_service_code
                 and rf_txn_code = in_txn_code
		 and rf_ccy = in_ccy
	         and rf_party_type = 'M'
                 and rf_party_id = in_party_id
	 	 and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 	 and rf_disabled = 0
		 and rf_effect_date = (
			select max(rf_effect_date)
                	  from rule_txn_fee,
                     	  	rule_txn_fee_def
               		 where rf_type = in_type
                 	   and rf_rule_fee_id = rtd_id
                 	   and rf_country = in_country_id
                 	   and rf_channel_code = in_channel_code
                 	   and rf_service_code = in_service_code
                 	   and rf_txn_code = in_txn_code
                 	   and rf_ccy = in_ccy
                 	   and rf_party_type = 'M'
                  	   and rf_party_id = in_party_id
                 	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                 	   and rf_disabled = 0
                           and rf_effect_date < sysdate);

		 RETURN 1;
	else
		select count(*)
	  	  into iCnt
    	          from rule_txn_fee,
             	       rule_txn_fee_def
       	         where rf_type = in_type
         	   and rf_rule_fee_id = rtd_id
         	   and rf_country = in_country_id
         	   and rf_channel_code = in_channel_code
	 	   and rf_service_code = in_service_code
         	   and rf_txn_code = in_txn_code
		   and rf_ccy = in_ccy
	 	   and rf_party_type = 'C'
         	   and rf_party_id = in_party_client_id
	 	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 	   and rf_disabled = 0
                   and rf_effect_date = (
			select max(rf_effect_date)
                  	  from rule_txn_fee,
                       		rule_txn_fee_def
                 	 where rf_type = in_type
                   	   and rf_rule_fee_id = rtd_id
                   	   and rf_country = in_country_id
                   	   and rf_channel_code = in_channel_code
                   	   and rf_service_code = in_service_code
                   	   and rf_txn_code = in_txn_code
                   	   and rf_ccy = in_ccy
                   	   and rf_party_type = 'C'
                   	   and rf_party_id = in_party_client_id
                   	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                   	   and rf_disabled = 0
                           and rf_effect_date < sysdate);

		if iCnt > 0  then
	          OPEN out_cursor for
		  select rtd_id,
                         rf_min_value,
                         rf_max_value,
                     	 rf_custom_tag,
		         rf_custom_value
    	            from rule_txn_fee,
             	         rule_txn_fee_def
       	           where rf_type = in_type
         	     and rf_rule_fee_id = rtd_id
         	     and rf_country = in_country_id
         	     and rf_channel_code = in_channel_code
	 	     and rf_service_code = in_service_code
         	     and rf_txn_code = in_txn_code
		     and rf_ccy = in_ccy
	 	     and rf_party_type = 'C'
         	     and rf_party_id = in_party_client_id
	 	     and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 	     and rf_disabled = 0
                     and rf_effect_date = (
			select max(rf_effect_date)
                    	  from rule_txn_fee,
                               rule_txn_fee_def
                   	 where rf_type = in_type
                     	   and rf_rule_fee_id = rtd_id
                     	   and rf_country = in_country_id
                           and rf_channel_code = in_channel_code
                           and rf_service_code = in_service_code
                           and rf_txn_code = in_txn_code
                           and rf_ccy = in_ccy
                           and rf_party_type = 'C'
                           and rf_party_id = in_party_client_id
                           and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                           and rf_disabled = 0
                           and rf_effect_date  < sysdate);

		     RETURN 1;
		else
			select count(*)
	  	  	  into iCnt
    	                  from rule_txn_fee,
             	               rule_txn_fee_def
       	                 where rf_type = in_type
         	           and rf_rule_fee_id = rtd_id
         	           and rf_country = in_country_id
         	           and rf_channel_code = in_channel_code
	 	           and rf_service_code = in_service_code
         	           and rf_txn_code = in_txn_code
		           and rf_ccy = in_ccy
	 	           and rf_party_type = 'G'
	 	     	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 	           and rf_disabled = 0
			   and rf_effect_date = (
				select max(rf_effect_date)
                          	  from rule_txn_fee,
                               		rule_txn_fee_def
                         	 where rf_type = in_type
                           	   and rf_rule_fee_id = rtd_id
                           	   and rf_country = in_country_id
                           	   and rf_channel_code = in_channel_code
                           	   and rf_service_code = in_service_code
                           	   and rf_txn_code = in_txn_code
                           	   and rf_ccy = in_ccy
                           	   and rf_party_type = 'G'
                           	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                           	   and rf_disabled = 0
				   and rf_effect_date < sysdate);
			if iCnt > 0 then
	          	      OPEN out_cursor for
			      select rtd_id,
                         	     rf_min_value,
                         	     rf_max_value,
                     		     rf_custom_tag,
		                     rf_custom_value
    	                        from rule_txn_fee,
             	                     rule_txn_fee_def
       	                       where rf_type = in_type
         	                 and rf_rule_fee_id = rtd_id
         	                 and rf_country = in_country_id
         	                 and rf_channel_code = in_channel_code
	 	                 and rf_service_code = in_service_code
         	                 and rf_txn_code = in_txn_code
		                 and rf_ccy = in_ccy
	 	                 and rf_party_type = 'G'
	 	     	   	 and (rf_pay_method = in_pay_method or rf_pay_method = '000')
	 	                 and rf_disabled = 0
				 and rf_effect_date = (
					select max(rf_effect_date)
                                	  from rule_txn_fee,
                                     		rule_txn_fee_def
                               	 	 where rf_type = in_type
                                 	   and rf_rule_fee_id = rtd_id
                                 	   and rf_country = in_country_id
                                 	   and rf_channel_code = in_channel_code
                                 	   and rf_service_code = in_service_code
                                 	   and rf_txn_code = in_txn_code
                                 	   and rf_ccy = in_ccy
                                 	   and rf_party_type = 'G'
                                 	   and (rf_pay_method = in_pay_method or rf_pay_method = '000')
                                 	   and rf_disabled = 0
					   and rf_effect_date < sysdate);

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
END sp_rule_txn_fee_find;
/

