CREATE OR REPLACE FUNCTION sp_service_geturl(
  in_service_code		service.code%type,
  in_psp_id			service.psp_id%type,
  in_disabled		        service.disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	service
	  where	code=in_service_code
	  and	psp_id=in_psp_id
	  and	disabled=in_disabled
	  and   route_type in ('BE','FE')
	  and	effect_date=
		(SELECT max(effect_date)
			FROM service
			WHERE code=in_service_code
			AND psp_id=in_psp_id
			AND disabled=in_disabled
			AND effect_date<=sysdate);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	url
		from	service 
		where	code=in_service_code
	  	and	psp_id=in_psp_id
	  	and     route_type in ('BE','FE')
		and	disabled=in_disabled
	  	and	effect_date=
			(SELECT max(effect_date)
			  FROM service
			  WHERE code=in_service_code
			  AND disabled=in_disabled
			  AND psp_id=in_psp_id
			  AND effect_date<=sysdate);
		return 1;
	
	else
		select count(*)
		  into	iCnt
		  from	service
		  where	code=in_service_code
		  and	psp_id='000'
		  and	disabled=in_disabled
		  and   route_type in ('BE','FE')
		  and	effect_date=
			(SELECT max(effect_date)
 			FROM service
			WHERE code=in_service_code
			AND psp_id='000'
			AND disabled=in_disabled
			AND effect_date<=sysdate);


		if iCnt > 0 THEN
			OPEN out_cursor for
			select	url
			from	service 
			where	code=in_service_code
			and	psp_id='000'
			and     route_type in ('BE','FE')
			and	disabled=in_disabled
			and	effect_date=
				(SELECT max(effect_date)
				 FROM service
				 WHERE code=in_service_code
				 AND disabled=in_disabled
				 AND psp_id='000'
				 AND effect_date<=sysdate);

			return 1;
		else
			return 0;

		end if;
	end if;


exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_service_geturl;
/
