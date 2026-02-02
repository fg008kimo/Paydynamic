CREATE OR REPLACE FUNCTION sp_bank_mapping_rpl(
		in_replicate_psp_id          bank_mapping.bm_psp_channel_id%type,
		in_create_psp_id             bank_mapping.bm_psp_channel_id%type,
		in_create_user               bank_mapping.bm_create_user%type
)
  RETURN NUMBER IS
  	iRecCnt		      	  INTEGER := 0;
BEGIN
	

	SELECT COUNT(1)
	INTO iRecCnt
	FROM bank_mapping
	WHERE bm_psp_channel_id = in_replicate_psp_id;

	IF iRecCnt = 0
	THEN
		RETURN 2;
	END IF;
	
	INSERT INTO bank_mapping ( 
	 bm_psp_channel_id, 
	 bm_country, 
	 bm_int_bank_code, 
	 bm_ext_bank_code, 
	 bm_effect_date,
	 bm_disabled, 
	 bm_create_user ,
	 bm_create_timestamp,
	 bm_update_user,
	 bm_update_timestamp 
	)
	SELECT 
		in_create_psp_id, 
		bm_country, 
		bm_int_bank_code, 
		bm_ext_bank_code, 
		sysdate, 
		0,
		in_create_user, 
		sysdate, 
		in_create_user, 
		sysdate
	FROM bank_mapping 
	WHERE bm_psp_channel_id = in_replicate_psp_id;  



	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_bank_mapping_rpl;
/
