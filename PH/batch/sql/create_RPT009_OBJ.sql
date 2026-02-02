CREATE OR REPLACE TYPE RPT009_OBJ is object (
	merchant_id	varchar(15),
	merchant_name	varchar(50),
	service_code_desc varchar(50),
	approval_date	varchar(14),
	current_bal	number(14,2),
	total_float	number(14,2),
	reserved_amount	number(14,2),
	total_hold	number(14,2),
	settlement_in	number(14,2),
	currency	varchar(3),
	status		varchar(50))
/

