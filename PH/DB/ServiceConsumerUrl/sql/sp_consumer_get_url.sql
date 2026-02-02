CREATE OR REPLACE FUNCTION sp_consumer_get_url(
  in_service_code		service_consumer_url.cu_service_code%type,
  in_merchant_id		service_consumer_url.cu_merchant_id%type,
  in_country			service_consumer_url.cu_country%type,
  in_disabled		        service_consumer_url.cu_disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	service_consumer_url
	  where	cu_service_code=in_service_code
	  and	cu_merchant_id=in_merchant_id
	  and	cu_country=in_country
	  and	cu_disabled=in_disabled
	  and	cu_effect_date=
		(SELECT max(cu_effect_date)
			FROM service_consumer_url
			WHERE cu_service_code=in_service_code
			AND cu_merchant_id=in_merchant_id
			and cu_country=in_country
			AND cu_disabled=in_disabled
			AND cu_effect_date<=sysdate);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	cu_url
		from	service_consumer_url 
		where	cu_service_code=in_service_code
	  	and	cu_merchant_id=in_merchant_id
		and	cu_country=in_country
		and	cu_disabled=in_disabled
	  	and	cu_effect_date=
			(SELECT max(cu_effect_date)
			  FROM service_consumer_url
			  WHERE cu_service_code=in_service_code
			  AND cu_disabled=in_disabled
			  AND cu_merchant_id=in_merchant_id
			  and cu_country=in_country
			  AND cu_effect_date<=sysdate);
		return 1;
	
	else
		select count(*)
		  into	iCnt
		  from	service
		  where	code=in_service_code
		  and	disabled=in_disabled
		  and   route_type in ('FE')
		  and	effect_date=
			(SELECT max(effect_date)
 			FROM service
			WHERE code=in_service_code
			AND disabled=in_disabled
			AND effect_date<=sysdate);


		if iCnt > 0 THEN
			OPEN out_cursor for
			select	url
			from	service 
			where	code=in_service_code
			and     route_type in ('FE')
			and	disabled=in_disabled
			and	effect_date=
				(SELECT max(effect_date)
				 FROM service
				 WHERE code=in_service_code
				 AND disabled=in_disabled
				 AND effect_date<=sysdate);

			return 1;
		else
			return 0;

		end if;
	end if;


exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_consumer_get_url;
/
