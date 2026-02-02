CREATE OR REPLACE VIEW REPORT_RPT009_VIEW AS
   SELECT merchant_id,
          name,
          sc_desc AS service_code_desc,
          TO_CHAR (th_approval_timestamp, 'YYYYMMDDHH24MISS') AS approval_date,
          td_current_bal,
          td_total_float,
          td_total_reserved_amount,
          td_total_hold,
          td_settlement_in_transit,
          mb_ccy_id AS currency,
          ds_desc AS status
     FROM def_service_code,
          def_status,
          merch_detail,
          merchant_bal_acct,
          (SELECT th_merchant_id,
                  th_approval_timestamp,
                  td_current_bal,
                  td_total_float,
                  td_total_reserved_amount,
                  td_total_hold,
                  td_settlement_in_transit
             FROM txn_detail, txn_header
            WHERE td_txn_id = th_txn_id AND th_ar_ind = 'A')
    WHERE     merchant_id = th_merchant_id
          AND mb_merchant_id = merchant_id
          AND mb_status = ds_type
          AND sc_code = mb_service_code
          AND ROWNUM = 1;
