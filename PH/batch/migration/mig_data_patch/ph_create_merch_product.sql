set serveroutput on;

declare
    cursor c1 is
	select mb_merchant_id, mb_country, mb_service_code, a.cm_preset_product
	from par_client_merch_map a, merchant_bal_acct b
	where B.MB_MERCHANT_ID = A.CM_PRESET_PH_MID 
	and not exists (
        	select 1
	        from crr_product_code_map c
		where c.pm_merchant_id = b.mb_merchant_id
		and c.pm_service_code = b.mb_service_code
		and c.pm_country = b.mb_country)
	group by mb_merchant_id, mb_country, mb_service_code, a.cm_preset_product;
begin

    for i in c1 loop
dbms_output.put_line('----');
dbms_output.put_line('merchant_id [' || i.mb_merchant_id || ']');
	insert into crr_product_code_map (pm_merchant_id, pm_service_code, pm_country, pm_product_code, 
                                          pm_disabled, pm_create_user, pm_create_timestamp, pm_update_user, pm_update_timestamp)
	values (i.mb_merchant_id, i.mb_service_code, i.mb_country, i.cm_preset_product,
                0, 'SYSTEM', sysdate, 'SYSTEM', sysdate);
    end loop;

    commit;

exception
    when others then
	dbms_output.put_line('error.... sqlerrm ' || sqlerrm);
        rollback;
end;
/
