CREATE OR REPLACE TYPE RPT009_OBJ is object (
	merchant_id	varchar(15),
	merchant_name	varchar(50),
	service_code_desc varchar(50),
	approval_date	varchar(14),
	float_bal	number(14,2),
	fundin_payout	number(14,2),
	current_bal	number(14,2),
	reserved_bal	number(14,2),
	holdback_bal	number(14,2),
	merchant_bal	number(14,2),
	currency	varchar(3),
	status		varchar(50))
/

