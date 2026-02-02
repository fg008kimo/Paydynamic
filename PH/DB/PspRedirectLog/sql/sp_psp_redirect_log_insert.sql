CREATE OR REPLACE FUNCTION sp_psp_redirect_log_insert (
   in_txn_id			psp_redirect_log.prl_txn_id%TYPE,
   in_url			psp_redirect_log.prl_url%TYPE,
   in_client_ip			psp_redirect_log.prl_client_ip%TYPE,
   in_rd_timestamp		varchar,
   in_create_user		psp_redirect_log.prl_create_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   UPDATE psp_redirect_log
      SET prl_update_timestamp = sysdate
    WHERE prl_txn_id = in_txn_id;

   IF SQL%ROWCOUNT = 0 THEN

      INSERT INTO psp_redirect_log (prl_txn_id,
				    prl_url,
	                            prl_client_ip,
	                            prl_rd_timestamp,
	                            prl_create_timestamp,
	                            prl_create_user,
	                            prl_update_timestamp,
	                            prl_update_user)
        VALUES (in_txn_id,
                in_url,
                in_client_ip,
                TO_DATE(in_rd_timestamp,'YYYYMMDDHH24MISS'),
                SYSDATE,
                in_create_user,
                SYSDATE,
                in_create_user);

      IF SQL%ROWCOUNT = 0
      THEN
         RETURN 1;
      ELSE
         RETURN 0;
      END IF;

   ELSE
      RETURN 0;
   END IF;


EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_psp_redirect_log_insert;
/

