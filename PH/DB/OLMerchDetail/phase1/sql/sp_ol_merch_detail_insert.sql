CREATE OR REPLACE FUNCTION sp_ol_merch_detail_insert(
    in_merchant_id                ol_merch_detail.md_merchant_id%type, 
    in_name                       ol_merch_detail.md_name%type,
    in_short_name                 ol_merch_detail.md_short_name%type,
    in_brand_name                 ol_merch_detail.md_brand_name%type,
    in_disabled                   ol_merch_detail.md_disabled%type,
    in_client_id                  ol_merch_detail.md_client_id%type,
    in_approximate_fee_rate       ol_merch_detail.md_approximate_fee_rate%type,
    in_status                     ol_merch_detail.md_status%type,
    in_allow_payout_dup_merch_ref ol_merch_detail.md_allow_payout_dup_merch_ref%type,
    in_settlement_process_period  ol_merch_detail.md_settlement_process_period%type,
    in_ignore_nack                ol_merch_detail.md_ignore_nack%type,
    in_payout_fe_display          ol_merch_detail.md_payout_fe_display%type,
    in_deposit_request_ver        ol_merch_detail.md_deposit_request_ver%type,
    in_display_other_bank         ol_merch_detail.md_display_other_bank%type,
    in_is_more_restricted         ol_merch_detail.md_is_more_restricted%type,
    in_support_payout_grp	  ol_merch_detail.md_support_payout_grp%type,
    in_txn_auto_expired_days      ol_merch_detail.md_txn_auto_expired_days%type,
    in_txn_auto_expired_mins      ol_merch_detail.md_txn_auto_expired_mins%type,
    in_stmt_auto_expired_days     ol_merch_detail.md_stmt_auto_expired_days%type,
    in_stmt_auto_expired_mins     ol_merch_detail.md_stmt_auto_expired_mins%type,
    in_po_checksum		  ol_merch_detail.md_payout_checksum%type,
    in_address			  ol_merch_detail.md_address%type,
    in_create_user                ol_merch_detail.md_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO ol_merch_detail(
    md_merchant_id,
    md_name,
    md_short_name,
    md_brand_name,
    md_disabled,
    md_client_id,
    md_approximate_fee_rate,
    md_status,
    md_allow_payout_dup_merch_ref,
    md_settlement_process_period,
    md_ignore_nack,
    md_payout_fe_display,
    md_deposit_request_ver,
    md_display_other_bank,
    md_is_more_restricted,
    md_support_payout_grp,
    md_txn_auto_expired_days,
    md_txn_auto_expired_mins,
    md_stmt_auto_expired_days,
    md_stmt_auto_expired_mins,
    md_payout_checksum,
    md_address,
    md_create_timestamp,
    md_update_timestamp,
    md_create_user,
    md_update_user
  )
  VALUES (
    in_merchant_id,
    in_name,
    in_short_name,
    in_brand_name,
    in_disabled,
    in_client_id,
    in_approximate_fee_rate,
    in_status,
    in_allow_payout_dup_merch_ref,
    in_settlement_process_period,
    in_ignore_nack,
    in_payout_fe_display,
    in_deposit_request_ver,
    in_display_other_bank,
    in_is_more_restricted,
    in_support_payout_grp,
    in_txn_auto_expired_days,
    in_txn_auto_expired_mins,
    in_stmt_auto_expired_days,
    in_stmt_auto_expired_mins,
    in_po_checksum,
    in_address,
    sysdate,
    sysdate,
    in_create_user,
    in_create_user
  );

  IF SQL%ROWCOUNT = 0 THEN
     RETURN 1;
  ELSE
     RETURN 0;
  END IF;

EXCEPTION
  WHEN OTHERS THEN
     RETURN 9;

END sp_ol_merch_detail_insert;
/

