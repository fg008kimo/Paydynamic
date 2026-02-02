CREATE OR REPLACE FUNCTION sp_txn_be_url_geturl(
  in_txn_code            	txn_be_url.txn_code%type,
  in_service_code		service.code%type,
  in_psp_id			service_psp_url.pu_psp_id%type,
  in_route_type		        service.route_type%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;

Begin

	select count(*)
	  into	iCnt
	  from	txn_be_url a,
	  	service_psp_url b
	  where	a.txn_code=in_txn_code
	  and	a.service_code=in_service_code
	  and	a.service_code=b.pu_service_code
	  and	b.pu_psp_id=in_psp_id
	  and	b.pu_psp_id=a.psp_id
	  and	a.disabled=0
	  and	b.pu_disabled=0
	  and	b.pu_effect_date=
		(SELECT max(pu_effect_date)
			FROM service_psp_url
			WHERE pu_service_code=in_service_code
			AND pu_psp_id=in_psp_id
			AND pu_disabled=0
			AND pu_effect_date<=sysdate)
	and	a.effect_date=
		(SELECT max(effect_date)
			FROM txn_be_url
			WHERE txn_code=in_txn_code
			AND service_code=in_service_code
			AND psp_id=in_psp_id
			AND disabled=0
			AND effect_date<=sysdate);

	if iCnt > 0 THEN
		OPEN out_cursor for
		select	b.pu_url,
			a.path
		from	txn_be_url a,
			service_psp_url b
		where	a.txn_code=in_txn_code
		and	a.service_code=in_service_code
		and	a.service_code=b.pu_service_code
		and	b.pu_psp_id=in_psp_id
		and	b.pu_psp_id=a.psp_id
		and	a.disabled=0
		and	b.pu_disabled=0
	  	and	b.pu_effect_date=
			(SELECT max(pu_effect_date)
				FROM service_psp_url
				WHERE pu_service_code=in_service_code
				AND pu_psp_id=in_psp_id
				AND pu_disabled=0
				AND pu_effect_date<=sysdate)
		and	a.effect_date=
			(SELECT max(effect_date)
				FROM txn_be_url
				WHERE txn_code=in_txn_code
				AND service_code=in_service_code
				AND psp_id=in_psp_id
				AND disabled=0
				AND effect_date<=sysdate);
		return 1;
	
	else
		select count(*)
		  into	iCnt
		  from	txn_be_url a,
		  	service b
		  where	a.txn_code=in_txn_code
		  and	a.service_code=in_service_code
		  and	a.service_code=b.code
		  and	a.psp_id=in_psp_id
	  	  and   b.route_type=in_route_type
		  and	a.disabled=0
		  and	b.disabled=0
		  and	b.effect_date=
			  (SELECT max(effect_date)
			   FROM service
			   WHERE code=in_service_code
	  		   and route_type=in_route_type
			   AND disabled=0
			   AND effect_date<=sysdate)
		  and	a.effect_date=
			  (SELECT max(effect_date)
			   FROM txn_be_url
			   WHERE txn_code=in_txn_code
			   AND service_code=in_service_code
			   AND psp_id=in_psp_id
			   AND disabled=0
			   AND effect_date<=sysdate);

		if iCnt > 0 THEN
			OPEN out_cursor for
			select	b.url,
				a.path
			  from	txn_be_url a,
		  		service b
			  where	a.txn_code=in_txn_code
			  and	a.service_code=in_service_code
		  	  and	a.service_code=b.code
			  and	a.psp_id=in_psp_id
	  		  and   b.route_type=in_route_type
			  and	a.disabled=0
			  and	b.disabled=0
			  and	b.effect_date=
			  	  (SELECT max(effect_date)
				   FROM service
				   WHERE code=in_service_code
	  			   and route_type=in_route_type
				   AND disabled=0
				   AND effect_date<=sysdate)
			  and	a.effect_date=
				  (SELECT max(effect_date)
				   FROM txn_be_url
				   WHERE txn_code=in_txn_code
				   AND service_code=in_service_code
				   AND psp_id=in_psp_id
				   AND disabled=0
				   AND effect_date<=sysdate);

			return 1;
		else
			
			return 0;

		end if;
	end if;

	return 0;

exception
   WHEN OTHERS THEN
     RETURN 0;
END sp_txn_be_url_geturl;
/
