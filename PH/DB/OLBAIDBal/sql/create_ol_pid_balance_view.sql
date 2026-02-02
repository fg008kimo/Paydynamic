DROP VIEW OL_PID_BALANCE_VIEW;

CREATE OR REPLACE FORCE VIEW OL_PID_BALANCE_VIEW
(
   PSP_ID,
   CURRENCY_ID,
   COUNTRY_ID,
   AVA_BALANCE,
   ACCT_BALANCE,
   LIEN,
   IN_TRANSIT
)
AS
     SELECT obai_psp_id,
            obab_currency_id,
            obab_country_id,
            SUM (obab_bal - obab_total_hold) AS ava_balance,
            SUM (obab_bal - obab_total_hold) AS acct_balance,
            SUM (obab_total_hold) AS lien,
            SUM (obab_in_transit) AS in_transit
       FROM ol_bank_acct_id, ol_baid_bal, ol_def_baid_category
      WHERE obai_baid = obab_baid
	AND obai_category = bc_type
        AND bc_in_balance = 1
   GROUP BY obai_psp_id, obab_country_id, obab_currency_id;

