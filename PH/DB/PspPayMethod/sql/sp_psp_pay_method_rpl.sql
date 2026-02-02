CREATE OR REPLACE FUNCTION sp_psp_pay_method_rpl (
	in_replicate_psp_id    IN	  psp_pay_method.pp_psp_id%TYPE,
	in_create_psp_id       IN	  psp_pay_method.pp_psp_id%TYPE,
	in_create_user         IN	  psp_pay_method.pp_create_user%TYPE
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
	
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM psp_pay_method
	WHERE pp_psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;
  
  
	INSERT INTO psp_pay_method (
		pp_country,
		pp_psp_id,
		pp_pay_method,
		pp_disabled,
		pp_create_user,
		pp_update_user,
		pp_create_timestamp,
		pp_update_timestamp
	)
	SELECT 'CN', 
			in_create_psp_id, 
			pp_pay_method,
			0,
			in_create_user,
			in_create_user,
			sysdate,
			sysdate
	from psp_pay_method
	where pp_psp_id = in_replicate_psp_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_pay_method_rpl;
/
