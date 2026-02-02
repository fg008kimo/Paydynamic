


-----------------------------------------------
--Update table "MERCH_KEYS" into dummy settings
-----------------------------------------------
update merch_keys_bkp
set key_value = '1234567890'
where merchant_id not in ('test001');
