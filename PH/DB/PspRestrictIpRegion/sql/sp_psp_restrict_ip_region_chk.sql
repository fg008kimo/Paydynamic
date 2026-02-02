CREATE OR REPLACE FUNCTION sp_psp_restrict_ip_region_chk (
	in_psp_id	IN	psp_restrict_ip_region.pir_psp_id%TYPE, 
	in_region_code	IN	psp_restrict_ip_region.pir_region_code%TYPE)
RETURN NUMBER IS
	iCnt Integer := 0;
BEGIN
	SELECT	COUNT(*)
   	INTO   	iCnt
   	FROM  	PSP_DETAIL
	WHERE	PSP_ID = in_psp_id
	AND	PD_RESTRICT_DEPOSIT_IP = 1
	AND	DISABLED = 0;

	IF iCnt > 0 THEN
		SELECT 	COUNT(*)
		INTO   	iCnt	
        	FROM    PSP_RESTRICT_IP_REGION
        	WHERE   PIR_PSP_ID = in_psp_id 
		AND	PIR_REGION_CODE = in_region_code
		AND	PIR_DISABLED = 0;
	
		IF iCnt > 0 THEN
                	RETURN 0;
        	ELSE
                	RETURN 2;
        	END IF;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_psp_restrict_ip_region_chk;
/
