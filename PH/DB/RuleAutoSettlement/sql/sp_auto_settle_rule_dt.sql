CREATE OR REPLACE FUNCTION sp_auto_settle_rule_dt(
	in_merchant_id	 	AUTO_SETTLEMENT_EXEC_LOG.AL_MERCHANT_ID%type,
	in_service_code	 	AUTO_SETTLEMENT_EXEC_LOG.AL_SERVICE_CODE%type,
	in_country	 	AUTO_SETTLEMENT_EXEC_LOG.AL_COUNTRY%type,
	in_ccy		 	AUTO_SETTLEMENT_EXEC_LOG.AL_CCY_ID%type,
	in_rule_id	 	rule_auto_settlement.rs_id%type,
	out_cursor	out	sys_refcursor)
  RETURN NUMBER IS
	iCnt    integer := 0;
BEGIN

	select count(*)
	  into iCnt
	  from ((select rs_value,
		       rs_type,
		       rs_min_amount
		from   rule_auto_settlement
		where  rs_id = in_rule_id
		and    rs_disabled = 0)
		left join
		(select max(al_last_settlement_date) last_date,
			al_rule_type
		 from	AUTO_SETTLEMENT_EXEC_LOG
		 where	AL_MERCHANT_ID = in_merchant_id
		 and	AL_SERVICE_CODE = in_service_code
		 and	AL_COUNTRY = in_country
		 and	AL_CCY_ID = in_ccy
		 group by al_rule_type)
		on rs_type = al_rule_type);

	if iCnt > 0 THEN
              OPEN out_cursor for
		select last_date,
		       rs_value,
		       rs_min_amount,
		       rs_type,
		       al_status
	  	from ((select rs_value,
			     rs_type,
			     rs_min_amount
		      from   rule_auto_settlement,
			     def_auto_settlement_type
		      where  rs_id = in_rule_id
		      and    rs_disabled = 0
		      and    da_type = rs_type
		      order by da_is_default_rule
		      )
		      left join
		      (select max(al_last_settlement_date) last_date,
			      al_rule_type
		 	from	AUTO_SETTLEMENT_EXEC_LOG
	  	 	where	AL_MERCHANT_ID = in_merchant_id
	  	 	and	AL_SERVICE_CODE = in_service_code
	  	 	and	AL_COUNTRY = in_country
	  	 	and	AL_CCY_ID = in_ccy
			group by al_rule_type)
		       on rs_type = al_rule_type
		       left join
			(select al_last_settlement_date,
				al_rule_type b_rule_type,
				al_status
			 from   AUTO_SETTLEMENT_EXEC_LOG
			 where  AL_MERCHANT_ID = in_merchant_id
			 and    AL_SERVICE_CODE = in_service_code
			 and    AL_COUNTRY = in_country
			 and    AL_CCY_ID = in_ccy)
		       on b_rule_type = al_rule_type and al_last_settlement_date = last_date);

		RETURN 1;
  	ELSE
  		RETURN 0;
  	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_auto_settle_rule_dt;
/
