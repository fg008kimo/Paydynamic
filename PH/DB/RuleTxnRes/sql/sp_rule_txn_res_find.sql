CREATE OR REPLACE FUNCTION sp_rule_txn_res_find (
  in_party_id            	rule_txn_reserve.rs_party_id%Type,
  in_party_client_id           	rule_txn_reserve.rs_party_id%Type,
  out_type		out	rule_amount.ra_type%type,
  out_value		out	rule_amount.ra_value%type)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	out_type := '';
	out_value := 0;
	select count(*)
	  into iCnt
    	from rule_txn_reserve,
             rule_amount
       where rs_amount_id = ra_id
         and rs_party_id = in_party_id
	 and RS_PARTY_TYPE = 'M'
         and rs_disabled = 0;

	if iCnt = 0 THEN
		select count(*)
	  	  into iCnt
    	          from rule_txn_reserve,
             	       rule_amount
                 where rs_amount_id = ra_id
		   and rs_party_type = 'C'
                   and rs_party_id = in_party_client_id
         	   and rs_disabled = 0;
		if iCnt > 0 THEN
			select ra_type, ra_value
	  	  	  into out_type,out_value
    	                  from rule_txn_reserve,
             	       	       rule_amount
                         where rs_amount_id = ra_id
		   	   and rs_party_type = 'C'
                           and rs_party_id = in_party_client_id
         	   	   and rs_disabled = 0;
			RETURN 1;
		else 
			 select count(*)
                  	   into iCnt
                  	   from rule_txn_reserve,
                       		rule_amount
                 	  where rs_amount_id = ra_id
                   	    and rs_party_type = 'G'
         	   	    and rs_disabled = 0;
                	if iCnt > 0 THEN
                        	select ra_type, ra_value
                          	  into out_type,out_value
                          	  from rule_txn_reserve,
                               	       rule_amount
                                 where rs_amount_id = ra_id
                           	   and rs_party_type = 'G'
         	   	           and rs_disabled = 0;
				RETURN 1;
		        else
				RETURN 0;
			end if;
			
		end if;
	else 
		select ra_type, ra_value
	  	  into out_type,out_value
    	          from rule_txn_reserve,
                       rule_amount
                 where rs_amount_id = ra_id
                   and rs_party_id = in_party_id
		   and rs_party_type = 'M'
    	 	   and rs_disabled = 0;
		RETURN 1;
	end if;


	RETURN 0;


 exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_rule_txn_res_find;
/

