CREATE OR REPLACE FUNCTION sp_rule_psp_rel_per_rpl (
	in_replicate_psp_id     IN   rule_psp_release_period.rp_psp_id%TYPE,
	in_create_psp_id        IN   rule_psp_release_period.rp_psp_id%TYPE,
	in_create_user          IN   rule_psp_release_period.rp_create_user%TYPE
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
	
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM rule_psp_release_period
	WHERE rp_psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;
  
  
  
	INSERT INTO rule_psp_release_period (
		rp_country_id,
		rp_psp_id,
		rp_disabled,
		rp_period,
		rp_create_timestamp,
		rp_create_user,
		rp_update_timestamp,
		rp_update_user		
	)
	SELECT 'CN', 
			in_create_psp_id, 
			0,
			rp_period,
			sysdate,
			in_create_user,
			sysdate,
			in_create_user
	from rule_psp_release_period
	where rp_psp_id = in_replicate_psp_id;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_rule_psp_rel_per_rpl;
/
