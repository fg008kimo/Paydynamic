CREATE OR REPLACE FUNCTION sp_psp_poa_file_fmt_map_rpl(
	in_replicate_psp_id     psp_payout_file_format_mapping.ppfgm_psp_id%type,
	in_create_psp_id        psp_payout_file_format_mapping.ppfgm_psp_id%type,
	in_create_user          psp_payout_file_format_mapping.ppfgm_create_user%type
)
RETURN NUMBER IS
	iRecCnt		      	  INTEGER := 0;
BEGIN

	SELECT COUNT(1)
	INTO iRecCnt
	FROM psp_payout_file_format_mapping
	WHERE ppfgm_psp_id = in_replicate_psp_id;

	IF iRecCnt > 1 or iRecCnt = 0
	THEN
		RETURN 2;
	END IF;


  INSERT INTO psp_payout_file_format_mapping(
		ppfgm_psp_id,
		ppfgm_format_code,
		ppfgm_create_timestamp,
		ppfgm_update_timestamp,
		ppfgm_create_user,
		ppfgm_update_user
	)
	SELECT
		in_create_psp_id,
		ppfgm_format_code,
		sysdate,
		sysdate,
		in_create_user,
		in_create_user
	from psp_payout_file_format_mapping
	where ppfgm_psp_id = in_replicate_psp_id;


  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_psp_poa_file_fmt_map_rpl;
/

