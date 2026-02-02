


--------------------------------------------------
--Update table "MERCH_KEYS" into original settings
--------------------------------------------------
delete merch_keys_bkp
where merchant_id not in ('test001');

insert into merch_keys_bkp 
select  *
from    merch_keys
where merchant_id not in ('test001');
