CREATE OR REPLACE function sp_psp_recon_history_insert(
       in_txn_id                                psp_recon_history.pr_id%type,
       in_psp_id                                psp_recon_history.pr_psp_id%type,
       in_txn_ccy                               psp_recon_history.pr_txn_ccy%type,
       in_txn_country                           psp_recon_history.pr_txn_country%type,
       in_psp_txn_date                          psp_recon_history.pr_psp_txn_date%type,
       in_recon_date                 		psp_recon_history.pr_recon_date%type,
       in_txn_count			        psp_recon_history.pr_txn_count%type,
       in_input_count			        psp_recon_history.pr_input_count%type,
       in_txn_amount                       	psp_recon_history.pr_txn_amount%type,
       in_paid_amount                       	psp_recon_history.pr_paid_amount%type,
       in_input_amount                          psp_recon_history.pr_input_amount%type,
       in_txn_fee                       	psp_recon_history.pr_txn_fee%type,
       in_input_fee 	                        psp_recon_history.pr_input_fee%type,
       in_report_date                 		psp_recon_history.pr_report_date%type,
       in_create_user                           psp_recon_history.pr_create_user%type)

  RETURN NUMBER IS
begin

  insert into psp_recon_history
              (pr_id,
		pr_psp_id,
		pr_txn_ccy,
		pr_txn_country,
                pr_psp_txn_date,
                pr_recon_date,
		pr_txn_count,
		pr_input_count,
                pr_txn_amount,
                pr_paid_amount,
                pr_input_amount,
                pr_txn_fee,
                pr_input_fee,
                pr_report_date,
                pr_create_user,
                pr_create_timestamp,
                pr_update_user,
                pr_update_timestamp)
         values(in_txn_id,
		in_psp_id,
		in_txn_ccy,
		in_txn_country,
                in_psp_txn_date,
                in_recon_date,
		in_txn_count,
		in_input_count,
                in_txn_amount,
                in_paid_amount,
                in_input_amount,
		in_txn_fee,
		in_input_fee,
                in_report_date,
                in_create_user,
                sysdate,
                in_create_user,
                sysdate);

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;
end sp_psp_recon_history_insert;
/

