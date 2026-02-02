CREATE OR REPLACE FUNCTION sp_service_psp_geturl(
  in_service_code		service_psp_url.pu_service_code%type,
  in_psp_id			service_psp_url.pu_psp_id%type,
  in_disabled		        service_psp_url.pu_disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	service_psp_url
	  where	pu_service_code=in_service_code
	  and	pu_psp_id=in_psp_id
	  and	pu_disabled=in_disabled
	  and	pu_effect_date=
		(SELECT max(pu_effect_date)
			FROM service_psp_url
			WHERE pu_service_code=in_service_code
			AND pu_psp_id=in_psp_id
			AND pu_disabled=in_disabled
			AND pu_effect_date<=sysdate);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	pu_url
		from	service_psp_url
		where	pu_service_code=in_service_code
	  	and	pu_psp_id=in_psp_id
		and	pu_disabled=in_disabled
	  	and	pu_effect_date=
			(SELECT max(pu_effect_date)
			  FROM service_psp_url
			  WHERE pu_service_code=in_service_code
			  AND pu_disabled=in_disabled
			  AND pu_psp_id=in_psp_id
			  AND pu_effect_date<=sysdate);
		return 1;
	
	else
		select count(*)
		  into	iCnt
		  from	service
		  where	code=in_service_code
		  and	disabled=in_disabled
		  and   route_type in ('BE')
		  and	effect_date=
			(SELECT max(effect_date)
 			FROM service
			WHERE code=in_service_code
			AND route_type in ('BE') 
			AND disabled=in_disabled
			AND effect_date<=sysdate);


		if iCnt > 0 THEN
			OPEN out_cursor for
			select	url
			from	service 
			where	code=in_service_code
			and     route_type in ('BE')
			and	disabled=in_disabled
			and	effect_date=
				(SELECT max(effect_date)
				 FROM service
				 WHERE code=in_service_code
				 AND route_type in ('BE') 
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
END sp_service_psp_geturl;
/
