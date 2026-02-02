CREATE OR REPLACE FUNCTION sp_service_getdomain(
  in_service_code		service.code%type,
  in_route_type			service.route_type%type,
  in_disabled		        service.disabled%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	service
	  where	code=in_service_code
	  and	route_type=in_route_type
	  and	disabled=in_disabled
	  --and   route_type in ('BE','FE')
	  and	effect_date=
		(SELECT max(effect_date)
			FROM service
			WHERE code=in_service_code
			AND route_type=in_route_type
			AND disabled=in_disabled
			AND effect_date<=sysdate);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	url
		from	service 
		where	code=in_service_code
	  	and	route_type=in_route_type
	  	--and     route_type in ('BE','FE')
		and	disabled=in_disabled
	  	and	effect_date=
			(SELECT max(effect_date)
			  FROM service
			  WHERE code=in_service_code
			  AND disabled=in_disabled
			  AND route_type=in_route_type
			  AND effect_date<=sysdate);
		return 1;
	
	else
		return 0;

	end if;


exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_service_getdomain;
/
