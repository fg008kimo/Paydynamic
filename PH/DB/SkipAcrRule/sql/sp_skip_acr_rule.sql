CREATE OR REPLACE FUNCTION sp_skip_acr_rule (
  in_txn_code            	skip_acr_rule.sar_txn_code%Type,
  in_service_code		service.code%type,
  in_merchant_id            	merch_detail.merchant_id%Type)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin
	select count(*)
	  into iCnt
    	from skip_acr_rule
       where sar_party_type = 'M'
         and sar_txn_code = in_txn_code
         and sar_party_id = in_merchant_id
	 and sar_disabled = 0;

	if iCnt > 0 THEN

		RETURN 1;
	else
		select count(*)
		  into iCnt
		from skip_acr_rule
	       where sar_party_type = 'S'
		 and sar_txn_code = in_txn_code
		 and sar_party_id = in_service_code
		 and sar_disabled = 0;

		if iCnt > 0  then
			RETURN 1;
		else
			RETURN 0;

                end if;
	end if;


 exception
   WHEN OTHERS THEN
     RETURN 9;
END sp_skip_acr_rule;
/

