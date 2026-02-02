create or replace function sp_update_reconed_txn_psp_dt(
       in_psp_id				txn_psp_detail.tp_psp_id%type,
       in_txn_ccy				txn_psp_detail.tp_txn_ccy%type,
       in_txn_date				txn_psp_detail.tp_txn_date%type,
       in_recon_date				txn_psp_detail.tp_recon_date%type,
       in_report_date				txn_psp_detail.tp_report_date%type)
  RETURN NUMBER IS
begin

	update  txn_psp_detail
	set     tp_recon_ind = 1,
		tp_recon_date = in_recon_date,
		tp_report_date = in_report_date
	where   tp_psp_id = in_psp_id
	and     tp_txn_ccy = in_txn_ccy
	and     tp_match_date = in_txn_date
	and     tp_match_ind = 1
	and     tp_recon_ind = 0;

  	IF SQL%ROWCOUNT = 0 THEN
     		RETURN 1;
  	ELSE
    		RETURN 0;
  	END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_update_reconed_txn_psp_dt;
/
