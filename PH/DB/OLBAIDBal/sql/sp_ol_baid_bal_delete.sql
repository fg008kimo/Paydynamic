CREATE OR REPLACE FUNCTION sp_ol_baid_bal_delete(
	in_baid		ol_baid_bal.obab_baid%type,
	in_country	ol_baid_bal.obab_country_id%type,
	in_ccy		ol_baid_bal.obab_currency_id%type
	)
RETURN NUMBER IS

BEGIN
	DELETE FROM ol_baid_bal
	WHERE obab_baid = in_baid
	AND obab_country_id = in_country
	AND obab_currency_id = in_ccy;

	IF SQL%ROWCOUNT = 0 THEN
		RETURN 1;
	ELSE
		RETURN 0;
	END IF;

EXCEPTION
	WHEN OTHERS THEN
		RETURN 9;
END sp_ol_baid_bal_delete;
/
