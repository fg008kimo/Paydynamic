CREATE OR REPLACE FUNCTION sp_ol_intra_log_gen_chk_exists(
	in_txn_id		OL_BAID_INTRA_LOG_GEN.OALG_GEN_TXN_ID_FR%TYPE)
RETURN NUMBER IS
	v_cnt    		integer := 0;
BEGIN

	select 	count(*)
	into 	v_cnt
	from  	ol_baid_intra_log_gen
       	where  	(oalg_gen_txn_id_fr = in_txn_id or oalg_gen_txn_id_to = in_txn_id)
       	and  	oalg_ret_code = 0;

	IF v_cnt = 0 THEN
		return 2;
	ELSE
		select  count(*)
             	into    v_cnt
              	from    ol_baid_intra_log_gen
               	where   (oalg_gen_txn_id_fr = in_txn_id or oalg_gen_txn_id_to = in_txn_id)
        	and	oalg_status = 'A'
              	and     oalg_ret_code = 0;

		IF v_cnt = 1 THEN
                   	return 0;
		ELSE
			return 1;
		END IF;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;

END sp_ol_intra_log_gen_chk_exists;
/
