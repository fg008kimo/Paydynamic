CREATE OR REPLACE FUNCTION sp_ol_payout_request_insert (
   in_txn_id			ol_payout_request.opr_txn_id%TYPE,
   in_aux_txn_id		ol_payout_request.opr_aux_txn_id%TYPE,
   in_merchant_payout_group	ol_payout_request.opr_merchant_payout_grp%TYPE,
   in_psp_payout_grp		ol_payout_request.opr_psp_payout_grp%TYPE,
   in_request_currency		ol_payout_request.opr_request_currency%TYPE,
   in_request_amount		ol_payout_request.opr_request_amount%TYPE,
   in_payout_currency		ol_payout_request.opr_payout_currency%TYPE,
   in_payout_amount		ol_payout_request.opr_payout_amount%TYPE,
   in_member_fee_ccy		ol_payout_request.opr_member_fee_ccy%TYPE,
   in_member_fee		ol_payout_request.opr_member_fee%TYPE,
   in_merchant_fee_ccy		ol_payout_request.opr_merchant_fee_ccy%TYPE,
   in_merchant_fee		ol_payout_request.opr_merchant_fee%TYPE,
   in_markup_ccy		ol_payout_request.opr_markup_ccy%TYPE,
   in_markup_amt		ol_payout_request.opr_markup_amt%TYPE,
   in_status			ol_payout_request.opr_status%TYPE,
   in_generated_file_id		ol_payout_request.opr_generated_file_id%TYPE,
   in_psp_id			ol_payout_request.opr_psp_id%TYPE,
   in_update_user		ol_payout_request.opr_update_user%TYPE)
   RETURN NUMBER
IS
BEGIN
   INSERT INTO ol_payout_request (opr_txn_id,
				  opr_aux_txn_id,
				  opr_merchant_payout_grp,
				  opr_psp_payout_grp,
				  opr_request_currency,
				  opr_request_amount,
				  opr_payout_currency,
				  opr_payout_amount,
				  opr_member_fee_ccy,
				  opr_member_fee,
				  opr_merchant_fee_ccy,
				  opr_merchant_fee,
				  opr_markup_ccy,
				  opr_markup_amt,
				  opr_status,
				  opr_generated_file_id,
                                  opr_psp_id,
                                  opr_create_user,
                                  opr_create_timestamp,
                                  opr_update_user,
                                  opr_update_timestamp)
        VALUES (in_txn_id,
		in_aux_txn_id,
		in_merchant_payout_group,
		in_psp_payout_grp,
		in_request_currency,
		in_request_amount,
		in_payout_currency,
		in_payout_amount,
		in_member_fee_ccy,
		in_member_fee,
		in_merchant_fee_ccy,
		in_merchant_fee,
		in_markup_ccy,
		in_markup_amt,
		in_status,
		in_generated_file_id,
                in_psp_id,
                in_update_user,
                SYSDATE,
                in_update_user,
                SYSDATE);

   IF SQL%ROWCOUNT = 0
   THEN
      RETURN 1;
   ELSE
      RETURN 0;
   END IF;
EXCEPTION
   WHEN OTHERS
   THEN
      RETURN 9;
END sp_ol_payout_request_insert;
/

