CREATE OR REPLACE FUNCTION sp_exchange_rate_ers_ins(
	in_from_ccy_id		exchange_rate_ers.exe_from_ccy_id%type,
	in_to_ccy_id		exchange_rate_ers.exe_to_ccy_id%type,
	in_rate			exchange_rate_ers.exe_rate%type,
	in_bid			exchange_rate_ers.exe_bid%type,
	in_max_ask		exchange_rate_ers.exe_max_ask%type,
	in_med_ask		exchange_rate_ers.exe_med_ask%type,
	in_min_ask		exchange_rate_ers.exe_min_ask%type,
	in_max_bid		exchange_rate_ers.exe_max_bid%type,
	in_med_bid		exchange_rate_ers.exe_med_bid%type,
	in_min_bid		exchange_rate_ers.exe_min_bid%type,
	in_meanminmax		exchange_rate_ers.exe_meanminmax_src2dst%type,
	in_minmax		exchange_rate_ers.exe_minmax_src2dst%type,
	in_effect_date		varchar,
	in_create_user		exchange_rate_ers.exe_create_user%type)
  RETURN NUMBER IS

BEGIN
  INSERT INTO exchange_rate_ers(
	exe_from_ccy_id,
	exe_to_ccy_id,
	exe_rate,
	exe_bid,
	exe_max_ask,
	exe_med_ask,
	exe_min_ask,
	exe_max_bid,
	exe_med_bid,
	exe_min_bid,
	exe_meanminmax_src2dst,
	exe_minmax_src2dst,
	exe_effect_date,
	exe_create_date,
	exe_create_user
	)

  VALUES(
	in_from_ccy_id,
	in_to_ccy_id,
	in_rate,
	in_bid,
	in_max_ask,
	in_med_ask,
	in_min_ask,
	in_max_bid,
	in_med_bid,
	in_min_bid,
	in_meanminmax,
	in_minmax,
	to_date(in_effect_date, 'YYYYMMDDHH24:MI:SS'),
	sysdate,
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

END sp_exchange_rate_ers_ins;
/
