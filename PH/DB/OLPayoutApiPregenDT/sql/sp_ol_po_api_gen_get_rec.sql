CREATE OR REPLACE FUNCTION sp_ol_po_api_gen_get_rec(
  in_action_id		ol_payout_api_pregen_hd.oap_action_id%type,
  out_cursor            out     sys_refcursor)

RETURN NUMBER IS
        iCnt    integer := 0;

BEGIN

   select count(*)
   into iCnt
   from    ol_payout_api_pregen_hd,
           ol_payout_api_pregen_dt,
	   ol_payout_request
   where   oap_action_id = in_action_id
   and     oap_batch_id = oag_batch_id
   and     oag_txn_id = opr_txn_id
   and     (opr_psp_payout_grp = oap_payout_group or opr_psp_payout_grp is NULL) 
   and	   oap_status = 'V'
   and     opr_status = 65		
   and     oap_pregen_ret_code = 0
   and     oap_gen_ret_code is NULL
   and     oag_psp_id is not NULL
   and     oag_bank_code is not NULL;

   IF iCnt > 0 THEN
        OPEN out_cursor FOR
	select
            	oag_batch_id,
             	oap_payout_group,
             	oap_pregen_ret_code,
             	oap_gen_ret_code,
               	oag_seq,
              	oag_txn_id,
               	oag_psp_id,
               	oag_bank_code,
              	oag_file_id,
		opr_merchant_payout_grp,
                opr_psp_payout_grp,
                opr_request_currency,
                opr_request_amount,
                opr_payout_currency,
                opr_payout_amount,
                opr_merchant_fee_ccy,
                opr_merchant_fee,
                opr_status,
                oth_merchant_id,
                oth_merchant_ref,
                oth_service_code,
                otd_txn_country,
                otd_identity_id,
                otd_bank_name,
                otd_bank_code,
                otd_branch_name,
                otd_bank_acct_num,
                otd_account_name,
                otd_account_id,
                otd_remark,
                otd_province,
                otd_phone_no,
                otd_city
       	from    ol_payout_api_pregen_hd,
                ol_payout_api_pregen_dt,
		ol_payout_request,
		ol_txn_header,
                ol_txn_detail
       	where   oap_action_id = in_action_id
     	and     oap_batch_id = oag_batch_id
 	and     oag_txn_id = opr_txn_id
	and     opr_txn_id = oth_txn_id 
    	and     oth_txn_id = otd_txn_id  
   	and     (opr_psp_payout_grp = oap_payout_group or opr_psp_payout_grp is NULL)
   	and	oap_status = 'V'	
	and     opr_status = 65
	and     oap_pregen_ret_code = 0
        and     oap_gen_ret_code is NULL
        and     oag_psp_id is not NULL
      	and     oag_bank_code is not NULL
       	order by oag_batch_id, oag_seq;

        RETURN 1;
   ELSE
        RETURN 0;
   END IF;

   RETURN 0;

EXCEPTION
   WHEN OTHERS 
   THEN
     RETURN 9;

END sp_ol_po_api_gen_get_rec;
/
