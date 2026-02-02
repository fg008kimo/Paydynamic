


---------------------------------------------------------------
--Copy Data into table "MERCH_KEYS_BKP" from table "MERCH_KEYS"
---------------------------------------------------------------
insert into merch_keys_bkp
select  *
from    merch_keys;

/*
insert into merch_keys_bkp 
(
    merchant_id, key, key_value, effect_date,
    create_timestamp, update_timestamp, create_user, update_user
)
select  merchant_id,
        key,
        key_value,
        effect_date,
        create_timestamp,
        update_timestamp,
        create_user,
        update_user
from    merch_keys;   
*/

