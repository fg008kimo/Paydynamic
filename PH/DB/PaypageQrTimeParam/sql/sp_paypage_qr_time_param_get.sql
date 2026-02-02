CREATE OR REPLACE FUNCTION sp_paypage_qr_time_param_get (
  in_service_code			paypage_qr_time_param.pqtp_service_code%type,
  in_psp_id     		       	paypage_qr_time_param.pqtp_party_id%Type,
  out_cursor			out	sys_refcursor)

RETURN NUMBER Is
	iCnt	integer := 0;
Begin

	/*Check PID Level*/
	SELECT count(*)
	  INTO iCnt
	  FROM paypage_qr_time_param
	 WHERE pqtp_service_code = in_service_code
	   AND pqtp_party_id = in_psp_id
	   AND pqtp_party_type = 'P'
	   AND pqtp_disabled = 0;

	if iCnt = 0 THEN

		/*Check Channel (Override bank code channel) Level*/
		SELECT count(*)
		  INTO iCnt
		  FROM paypage_qr_time_param
		 WHERE pqtp_service_code = in_service_code
		   AND pqtp_party_id = (SELECT nvl(overrided_bank_code_channel,psp_channel_code) FROM psp_detail WHERE psp_id = in_psp_id)
		   AND pqtp_party_type = 'C'
		   AND pqtp_disabled = 0;

		if iCnt > 0 THEN

			/*Get Channel (Override bank code channel) Level*/
			OPEN out_cursor FOR
			SELECT	pqtp_expiry,
				pqtp_enable_button,
				pqtp_auto_check_txn_status,
				pqtp_redirect
			  FROM	paypage_qr_time_param
			 WHERE	pqtp_service_code = in_service_code
			   AND	pqtp_party_id = (SELECT nvl(overrided_bank_code_channel,psp_channel_code) FROM psp_detail WHERE psp_id = in_psp_id)
			   AND	pqtp_party_type = 'C'
			   AND	pqtp_disabled = 0;

			RETURN 1;

		else

			/*Check Globale Level*/
			SELECT count(*)
			  INTO iCnt
			  FROM paypage_qr_time_param
			 WHERE pqtp_service_code = in_service_code
			   AND pqtp_party_type = 'G'
			   AND pqtp_disabled = 0;

			if iCnt > 0 THEN

				/*Get Global Level*/
				OPEN out_cursor FOR
				SELECT	pqtp_expiry,
					pqtp_enable_button,
					pqtp_auto_check_txn_status,
					pqtp_redirect
				  FROM	paypage_qr_time_param
				 WHERE	pqtp_service_code = in_service_code
				   AND	pqtp_party_type = 'G'
				   AND	pqtp_disabled = 0;

				RETURN 1;
			else
				RETURN 0;
			end if;

		end if;

	else

		/*Get PID Level*/
		OPEN out_cursor FOR
		SELECT	pqtp_expiry,
			pqtp_enable_button,
			pqtp_auto_check_txn_status,
			pqtp_redirect
		  FROM	paypage_qr_time_param
		 WHERE	pqtp_service_code = in_service_code
		   AND	pqtp_party_id = in_psp_id
		   AND	pqtp_party_type = 'P'
		   AND	pqtp_disabled = 0;

		RETURN 1;

	end if;

	RETURN 0;

exception
  WHEN OTHERS THEN
    RETURN 9;

END sp_paypage_qr_time_param_get;
/

