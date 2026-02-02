CREATE OR REPLACE FUNCTION sp_last_auto_settle_dt(
	in_merchant_id	 	AUTO_SETTLEMENT_EXEC_LOG.AL_MERCHANT_ID%type,
	in_service_code	 	AUTO_SETTLEMENT_EXEC_LOG.AL_SERVICE_CODE%type,
	in_country	 	AUTO_SETTLEMENT_EXEC_LOG.AL_COUNTRY%type,
	in_ccy		 	AUTO_SETTLEMENT_EXEC_LOG.AL_CCY_ID%type,
	in_rule_type	 	AUTO_SETTLEMENT_EXEC_LOG.AL_RULE_TYPE%type,
	out_cursor	out	sys_refcursor)
  RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	select count(*)
	  into iCnt
	  from	AUTO_SETTLEMENT_EXEC_LOG
	  where	AL_MERCHANT_ID = in_merchant_id
	  and	AL_SERVICE_CODE = in_service_code
	  and	AL_COUNTRY = in_country
	  and	AL_CCY_ID = in_ccy
	  and	AL_RULE_TYPE = in_rule_type
	  and	al_last_settlement_date = 
		(select max(al_last_settlement_date)
		 from   AUTO_SETTLEMENT_EXEC_LOG
		 where  AL_MERCHANT_ID = in_merchant_id
		 and    AL_SERVICE_CODE = in_service_code
		 and    AL_COUNTRY = in_country
		 and    AL_CCY_ID = in_ccy
		 and	AL_RULE_TYPE = in_rule_type);

	if iCnt > 0 THEN
              OPEN out_cursor for
		select al_last_settlement_date,
		       al_txn_id,
		       al_status
		 from	AUTO_SETTLEMENT_EXEC_LOG
		 where	AL_MERCHANT_ID = in_merchant_id
		 and	AL_SERVICE_CODE = in_service_code
		 and	AL_COUNTRY = in_country
		 and	AL_CCY_ID = in_ccy
		 and	AL_RULE_TYPE = in_rule_type
		 and	al_last_settlement_date = 
			(select max(al_last_settlement_date)
			 from   AUTO_SETTLEMENT_EXEC_LOG
			 where  AL_MERCHANT_ID = in_merchant_id
			 and    AL_SERVICE_CODE = in_service_code
			 and    AL_COUNTRY = in_country
			 and    AL_CCY_ID = in_ccy
			and	AL_RULE_TYPE = in_rule_type);

		RETURN 1;
  	ELSE
  		RETURN 0;
  	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_last_auto_settle_dt;
/
